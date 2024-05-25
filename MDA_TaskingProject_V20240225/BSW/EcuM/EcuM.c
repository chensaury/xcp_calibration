/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  EcuM.c
 *        \brief  MICROSAR ECU State Manager
 *
 *      \details  The ECU State Manager is responsible for
 *                  - initialization of some BSW Modules which are needed to start the OS
 *                  - configuration of the entire ECU for sleep mode
 *                  - fast and systematic wakeup behavior
 *                  - shutdown of the ECU
 *
 *                To be very independent of different system designs e.g. different Modules to initialize,
 *                external/internal Watchdog, etc., the ECU State Manager provides over a mechanism named "callouts"
 *                a way to adapt the startup and shutdown behavior. The system designer must fill the proper code into
 *                the callouts.
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the module's header file.
 * 
 *  FILE VERSION
 *  -------------------------------------------------------------------------------------------------------------------
 *  Refer to the VERSION CHECK below.
 *********************************************************************************************************************/

#define ECUM_SOURCE
#define ECUM_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "EcuM.h"

#define ECUM_PRIVATE_CFG_INCLUDE
#include "EcuM_PrivateCfg.h"
#undef ECUM_PRIVATE_CFG_INCLUDE /* PRQA S 0841 */ /* MD_MSR_Undef */

#include "BswM.h"
#include "BswM_EcuM.h"

#include "Rte_EcuM.h"
#include "Rte_Main.h"
#include "SchM_EcuM.h"

#if((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) ||(ECUM_PNCOFCOMMPNCS == STD_ON) || (ECUM_SUPPORT_COMM == STD_ON)) /* COV_ECUM_PNCOFCOMMPNCS_QM */
# include "ComM.h"
# include "ComM_EcuMBswM.h"
#endif

#include "EcuM_Error.h"

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/
/* vendor specific version information is BCD coded */
#if (  (ECUM_SW_MAJOR_VERSION != (0x10u)) \
    || (ECUM_SW_MINOR_VERSION != (0x00u)) \
    || (ECUM_SW_PATCH_VERSION != (0x00u)) )
# error "Vendor specific version numbers of EcuM.c and EcuM.h are inconsistent"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if (  (ECUM_AR_RELEASE_MAJOR_VERSION    != (0x04u)) \
    || (ECUM_AR_RELEASE_MINOR_VERSION    != (0x00u)) \
    || (ECUM_AR_RELEASE_REVISION_VERSION != (0x03u)) )
# error "AUTOSAR Specification Version numbers of EcuM.c and EcuM.h are inconsistent!"
#endif

/* vendor specific version information is BCD coded */
#if (  (ECUM_CBK_SW_MAJOR_VERSION != (0x10u)) \
    || (ECUM_CBK_SW_MINOR_VERSION != (0x00u)) \
    || (ECUM_CBK_SW_PATCH_VERSION != (0x00u)) )
# error "Vendor specific version numbers of EcuM.c and EcuM_Cbk.h are inconsistent"
#endif

/* AUTOSAR version information check has to match definition in the Callback header file */
#if (  (ECUM_CBK_AR_RELEASE_MAJOR_VERSION    != (0x04u)) \
    || (ECUM_CBK_AR_RELEASE_MINOR_VERSION    != (0x00u)) \
    || (ECUM_CBK_AR_RELEASE_REVISION_VERSION != (0x03u)) )
# error "AUTOSAR Specification Version numbers of EcuM.c and EcuM_Cbk.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  PRE-COMPILE CHECKS
 *********************************************************************************************************************/
#if (ECUM_NUMBER_OF_CORES > 1u)
# if (ECUM_NUMBER_OF_CORES != EcuM_GetSizeOfCoreStatus())
#  error "Number of cores is not equal to the Core status array."
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
/* Define that indicates that no timeout is active for a wakeup source */
#define ECUM_NO_VALIDATION_TIMEOUT        (0x00u)

/* MAGIC Numbers to determine whether the restart was intended or not */
#define ECUM_MAGIC_ONE                    (0x5Au)
#define ECUM_MAGIC_TWO                    (0xA5u)

/* Defines used as parameters for the routine EcuM_EnterSleep */
#define ECUM_ENTER_HALT                   (uint8)0x00u
#define ECUM_ENTER_POLL                   (uint8)0x01u

/* Defines to indicate the current status of one core */
#define ECUM_CORESTATUS_RUN               (0x00u)
#define ECUM_CORESTATUS_SLEEP             (0x01u)
#define ECUM_CORESTATUS_OFF               (0x02u)

#if ((ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON) || (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON))
# define ECUM_TIMEOUTOFWAKEUPSOURCELIST   STD_ON
#else
# define ECUM_TIMEOUTOFWAKEUPSOURCELIST   STD_OFF
#endif

#if ((ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON) && (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON))
# define ECUM_COMBINEDPENDINGWAKEUPS      ((EcuM_PendingWakeups) | (EcuM_PendingCheckWakeups))
#elif (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
# define ECUM_COMBINEDPENDINGWAKEUPS      (EcuM_PendingWakeups)
#elif (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
# define ECUM_COMBINEDPENDINGWAKEUPS      (EcuM_PendingCheckWakeups)
#endif

#if ((ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON) || (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON))
# define ECUM_COMBINEDWAKEUPS             ((ECUM_COMBINEDPENDINGWAKEUPS) | (EcuM_ValidatedWakeups))
#else
# define ECUM_COMBINEDWAKEUPS             (EcuM_ValidatedWakeups)
#endif

#if(ECUM_FIXED_BEHAVIOR == STD_ON)

# define ECUM_TIMER_NOT_SET               (0xFFFFu)
# define ECUM_TIMER_EXPIRED               (0x00u)

# if(ECUM_SUPPORT_DEM == STD_ON)
#  define ECUM_DEM_SHUT_DOWN               (0x00u)
#  define ECUM_DEM_INITIALIZED             (0x01u)
# endif
#endif

#if(ECUM_FIXED_BEHAVIOR == STD_ON || ECUM_MODE_HANDLING == STD_ON)
/* Defines for RUN/POST RUN request handling  */
# define ECUM_USER_REQUEST_RUN_MASK       (0x01u)
# define ECUM_USER_REQUEST_POST_RUN_MASK  (0x02u)
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/
#define EcuM_EnterCriticalArea_0()        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_0()   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#define EcuM_LeaveCriticalArea_0()        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_0()    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

#if(ECUM_NUMBER_OF_CORES > 1)
# define EcuM_EnterCriticalArea_1()        SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_1()   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define EcuM_LeaveCriticalArea_1()        SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_1()    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)

# define ECUM_ALARM_NOT_ACTIVE             (0xFFFFFFFFu)

# if(ECUM_ATOMIC_VARIABLE_ACCESS < 32u)
#  define EcuM_EnterCriticalArea_2()       SchM_Enter_EcuM_ECUM_EXCLUSIVE_AREA_2()   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  define EcuM_LeaveCriticalArea_2()       SchM_Exit_EcuM_ECUM_EXCLUSIVE_AREA_2()    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  define EcuM_EnterCriticalArea_2()
#  define EcuM_LeaveCriticalArea_2()
# endif
#endif

/* Only in case that access on a 32bit variable is non atomic and a critical area is needed to access such variables */
#if(ECUM_ATOMIC_VARIABLE_ACCESS < 32u)
# define EcuM_EnterAtomicAccess_0()       EcuM_EnterCriticalArea_0()                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define EcuM_LeaveAtomicAccess_0()       EcuM_LeaveCriticalArea_0()                /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#else
# define EcuM_EnterAtomicAccess_0()
# define EcuM_LeaveAtomicAccess_0()
#endif

/* Calling Macros to avoid "unreferenced parameter" compiler error, if compiled without DEV_ERROR_DETECT */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
# define ECUM_FUNC_CALL_REQUEST_RUN(ApiId, User, mask)        (EcuM_InternalRequestRUN((ApiId), (User), (mask))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define ECUM_FUNC_CALL_RELEASE_RUN(ApiId, User, mask)        (EcuM_InternalReleaseRUN((ApiId), (User), (mask))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#else
# define ECUM_FUNC_CALL_REQUEST_RUN(ApiId, User, mask)        (EcuM_InternalRequestRUN((User), (mask)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# define ECUM_FUNC_CALL_RELEASE_RUN(ApiId, User, mask)        (EcuM_InternalReleaseRUN((User), (mask)))  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#endif

#if((ECUM_NUMBER_OF_CORES > 1u) && (ECUM_CORERESOURCE == STD_ON))
# define ECUM_SLEEP_RESOURCE                                  EcuM_GetCoreResource(ECUM_CORE_ID_BSW)
#else
# define ECUM_SLEEP_RESOURCE                                  ECUM_OS_RESOURCE
#endif

#if(ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
# define ECUM_GLOBAL_CFG_PTR                                  EcuM_GlobalPBConfig_Ptr
#elif(ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON)
# define ECUM_GLOBAL_CFG_PTR                                  EcuM_GlobalPCConfig_Ptr
#endif

#if ((ECUM_INCLUDE_NVRAM_MGR == STD_ON) && (ECUM_FIXED_BEHAVIOR == STD_ON))
# define ECUM_NVM_WRITEALL_IDLE                               (0x00u)
# define ECUM_NVM_WRITEALL_REQUIRED                           (0x01u)
# define ECUM_NVM_WRITEALL_STARTED                            (0x02u)
# define ECUM_NVM_WRITEALL_CANCELED                           (0x03u)
#endif

#define ECUM_DRIVERINITLIST_ZERO                              EcuM_AL_DriverInitZero
#define ECUM_DRIVERINITLIST_ONE                               EcuM_GetFunctionOfDriverInitOne(0u)
#define ECUM_DRIVERRESTART_LIST                               EcuM_GetFunctionOfDriverRestartList(0u)

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
# define ECUM_DRIVERINITLIST_TWO                              EcuM_GetFunctionOfDriverInitTwo(0u)
# define ECUM_DRIVERINITLIST_THREE                            EcuM_GetFunctionOfDriverInitThree(0u)
#endif

#if (((ECUM_FIXED_BEHAVIOR == STD_ON) && (ECUM_SUPPORT_RTE_MODE_SWITCH == STD_ON)) || ECUM_MODE_HANDLING == STD_ON)
# define ECUM_RTE_SWITCH(MODE)                                (void)Rte_Switch_currentMode_currentMode((MODE)) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#else
# define ECUM_RTE_SWITCH(MODE)
#endif

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

#if !defined (ECUM_LOCAL) /* COV_ECUM_LOCAL */
# define ECUM_LOCAL static
#endif

#if !defined (ECUM_LOCAL_INLINE) /* COV_ECUM_LOCAL_INLINE */
# define ECUM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#define ECUM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Selected sleep/reset for shutdown phase */
ECUM_LOCAL VAR(uint8, ECUM_VAR_NOINIT) EcuM_CurrentShutdownMode;

/* Selected shutdown target for shutdown phase */
ECUM_LOCAL VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_CurrentShutdownTarget;

/* Selected shutdown target for shutdown phase */
ECUM_LOCAL VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_LastShutdownTarget; /* PRQA S 3218 */ /* MD_EcuM_3218 */

/* Get the last sleep/reset shutdownmode */
ECUM_LOCAL VAR(uint8, ECUM_VAR_NOINIT) EcuM_LastShutdownMode; /* PRQA S 3218 */ /* MD_EcuM_3218 */

#if (ECUM_SHUTDOWNCAUSECOUNT != 0u)
/* Selected shutdown cause for next shutdown */
ECUM_LOCAL VAR(uint8, ECUM_VAR_NOINIT) EcuM_ShutdownCause;
#endif

#if (ECUM_MODE_HANDLING == STD_ON)
/* Current Rte State to notify during MainFunction */
ECUM_LOCAL VAR(Rte_ModeType_EcuM_Mode, ECUM_VAR_NOINIT) EcuM_RteStateBuffer;
#endif

/* Select the BootTarget for the next BootSequence */
ECUM_LOCAL VAR(EcuM_BootTargetType, ECUM_VAR_NOINIT) EcuM_CurrentBootTarget;

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/* Two variables to indicate the reason of a restart */
ECUM_LOCAL VAR(uint8, ECUM_VAR_NOINIT) EcuM_IntendedRestartID_One;
ECUM_LOCAL VAR(uint8, ECUM_VAR_NOINIT) EcuM_IntendedRestartID_Two;
#endif

#define ECUM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define ECUM_START_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Variable to store the validated wakeup event which was responsible for wakeup up the ECU */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ValidatedWakeups;

#if(ECUM_SLEEPMODELIST == STD_ON)
/* Variable which stores information about enabled wakeup interrupts */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_EnabledWakeups;
#endif

/* Variable to store wakeups that occur during the startup before BswM is initialized */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_BswM_BufferedWakeups;

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)

/* Saves all wakeup events which are not validated yet */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_PendingWakeups;

/* Variable to store the cleared wakeup event with still active wakeup sources */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ClearedPendingWakeups;

#endif

#if (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)

/* Saves all wakeup events where the validation is expired */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ExpiredWakeups;

#endif

#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)

/* Saves all wakeup events which are occurred asynchronous */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_PendingCheckWakeups;

# if(ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ExpiredCheckWakeups;
# endif

#endif

#if((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) || (ECUM_PNCOFCOMMPNCS == STD_ON)) /* COV_ECUM_PNCOFCOMMPNCS_QM */

/* Variable to store wakeups that occur during the startup before ComM is initialized */
ECUM_LOCAL VAR(EcuM_WakeupSourceType, ECUM_VAR_NOINIT) EcuM_ComM_BufferedWakeups;

#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/* This is the absolute time since the battery connect */
ECUM_LOCAL VAR(uint32, ECUM_VAR_NOINIT) EcuM_Clock;

/* This is the time of the next occurring alarm timer */
ECUM_LOCAL VAR(uint32, ECUM_VAR_NOINIT) EcuM_MasterAlarm;
#endif

#define ECUM_STOP_SEC_VAR_NOINIT_32BIT
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* configuration pointer of the module */
#if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))

# define ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if(ECUM_USE_INIT_POINTER == STD_ON)
P2CONST(EcuM_PbConfigType, ECUM_VAR_NOINIT, ECUM_PBCFG) EcuM_ConfigDataPtr; /* PRQA S 1514 */ /* MD_EcuM_1514 */
# endif

# if (ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
P2CONST(EcuM_GlobalConfigType, ECUM_VAR_NOINIT, ECUM_PBCFG) EcuM_GlobalPBConfig_Ptr;
#  if(ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON)
P2CONST(EcuM_GlobalPCConfigType, ECUM_VAR_NOINIT, ECUM_CONST) EcuM_GlobalPCConfig_Ptr;
#  endif
# else
P2CONST(EcuM_GlobalConfigType, ECUM_VAR_NOINIT, ECUM_CONST) EcuM_GlobalPCConfig_Ptr;
# endif

# define ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#define ECUM_START_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EcuM_GetShiftCount
 **********************************************************************************************************************/
/*! \brief      Calculates an array position.
 *  \details    Transforms the bit position of the passed wakeup source to a numerical value which can be used as an
 *              index to access an array.
 *  \param[in]  Wakeup source parameter.
 *  \return     Bit position of the wakeup source bitmask.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  TRUE
 *  \note       The method expects that exactly one bit of the parameter is set.
 *              In the case that more than one bit is set, the source with the lowest id will be returned.
 *              In the case that no bit is set, 32u will be returned. The caller has to ensure that this will not lead
 *              to an access out of bounds.
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(uint8, ECUM_CODE) EcuM_GetShiftCount(VAR(EcuM_WakeupSourceType, AUTOMATIC) x);

#if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON || ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalWakeupValidation
 **********************************************************************************************************************/
/*! \brief      Handles the wakeup validation protocol.
 *  \details    Handles the wakeup validation and is invoked by the EcuM_MainFunction. Each configured wake-up source
 *              is checked inside this function for necessary validation.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalWakeupValidation(void);
#endif

#if(ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON || ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
/***********************************************************************************************************************
 *  EcuM_InternalComMNotifications
 **********************************************************************************************************************/
/*! \brief      Handles ComM PNC wakeup notifications.
 *  \details    Notifies the ComM about valid wakeup events of PNC wakeup sources.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalComMNotifications(void);
#endif

#if(ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
/***********************************************************************************************************************
 *  EcuM_InternalComMPNCNotification
 **********************************************************************************************************************/
/*! \brief      Handles buffered ComM notifications.
 *  \details    Notifies the ComM about valid wakeup events during the early startup phase, where the ComM is not
 *              initialized.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_InternalComMPNCNotification(uint8_least sourceIDx);
#endif

#if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalBswMNotifications
 **********************************************************************************************************************/
/*! \brief      Handles buffered BswM notifications.
 *  \details    Notifies the BswM about deferred wakeup events.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalBswMNotifications(void);
#endif

#if (ECUM_PARTITIONINIT == STD_ON)
/**********************************************************************************************************************
 *  EcuM_InternalGetPartitionIdx()
 **********************************************************************************************************************/
/*! \brief      Return the current partition index.
 *  \details    Determine which EcuM / BswM partition instance corresponds to the current OS application.
 *  \return     Index of the EcuM / BswM partition instance.
 *  \pre        -
 *  \context    ANY
 *  \reentrant  TRUE
 *  \note       The method returns the size of EcuM_GetPartitionIdx in case that no partition was found.
 **********************************************************************************************************************/
ECUM_LOCAL FUNC(EcuM_SizeOfPartitionInitType, ECUM_CODE) EcuM_InternalGetPartitionIdx(void);
#endif

#if (ECUM_SLEEPMODELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_EnterSleep
 **********************************************************************************************************************/
/*! \brief      Initiate the sleep phase.
 *  \details    Prepares the ECU for the upcoming sleep phase and invokes either the polling sleep mode or the halt
 *              mode, depending on the parameter SuspendMode.
 *  \param[in]  SuspendMode             Can be either ECUM_ENTER_POLL or ECUM_ENTER_HALT.
 *  \return     E_NOT_OK - error
 *  \return     E_OK     - success
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL FUNC(Std_ReturnType, ECUM_CODE) EcuM_EnterSleep(VAR(uint8, AUTOMATIC) SuspendMode);

/**********************************************************************************************************************
 *  EcuM_InternalEnterHaltMode()
 **********************************************************************************************************************/
/*! \brief      Enter a halt sleep mode.
 *  \details    Sets the ECU in a halt mode during a sleep phase.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalEnterHaltMode(void);

# if(ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
/**********************************************************************************************************************
 *  EcuM_InternalEnterPollingMode()
 **********************************************************************************************************************/
/*! \brief      Enter a polling sleep mode.
 *  \details    Sets the ECU in a sleep mode which polls cyclically for occurred wake-up events.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalEnterPollingMode(void);
# endif

# if(ECUM_NUMBER_OF_CORES > 1u)
/***********************************************************************************************************************
 *  EcuM_EnterSleepOnSlave
 **********************************************************************************************************************/
/*! \brief      Set a slave core to sleep.
 *  \details    Sets a slave core to sleep and signals it to the master core.
 *  \param[in]  CoreID                  ID of the current running core
 *  \return     E_NOT_OK - error
 *  \return     E_OK     - success
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(Std_ReturnType, ECUM_CODE) EcuM_EnterSleepOnSlave(CoreIdType CoreID);
# endif
#endif

#if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  EcuM_ShutdownSynchronization
 **********************************************************************************************************************/
/*! \brief      Synchronizes all EcuM instances during shutdown.
 *  \details    The EcuM master instance which handles the shutdown waits for all other EcuM instances till they
                reached the state shutdown.
 *  \param[in]  ShutdownState           Target state which shall be reached by all instances.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_ShutdownSynchronization(EcuM_CoreStatusType ShutdownState);
#endif

#if((ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON) || (ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE))
/**********************************************************************************************************************
 *  EcuM_InternalDeterminePbConfiguration()
 **********************************************************************************************************************/
/*! \brief      Determine the configuration pointer.
 *  \details    Determines the current configuration pointer and performs some validity checks.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalDeterminePbConfiguration(void);
#endif

/**********************************************************************************************************************
 *  EcuM_InternalClearWakeupEvent()
 **********************************************************************************************************************/
/*! \brief      Clear wake-up events.
 *  \details    Clears the passed wakeup source(s) in the EcuM_ValidatedWakeups, EcuM_PendingWakeups,
 *              EcuM_PendingCheckWakeups and EcuM_ExpiredWakeups variables.
 *  \param[in]  WakeupSource            Wakeup event(s) which should be cleared.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalClearWakeupEvent(
VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/**********************************************************************************************************************
 *  EcuM_InternalClearAlarms()
 **********************************************************************************************************************/
/*! \brief      Clear all wake-up alarms.
 *  \details    Clears the wake-up alarm of each configured alarmclock user.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalClearAlarms(void);

/***********************************************************************************************************************
 *  EcuM_UpdateMasterAlarm
 **********************************************************************************************************************/
/*! \brief      Updates the master alarm with next wake-up alarm.
 *  \details    Determines which users alarm time is the next and uses it for the master alarm.
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 **********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_UpdateMasterAlarm(void);
#endif

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
/**********************************************************************************************************************
 *  EcuM_ActEnterRun()
 **********************************************************************************************************************/
/*! \brief      Actions on transition to RUN state.
 *  \details    Called in the transition to the RUN state and performs all the necessary actions.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_ActEnterRun(void);

/**********************************************************************************************************************
 *  EcuM_Statemachine()
 **********************************************************************************************************************/
/*! \brief      Triggers the EcuM Statemachine.
 *  \details    Triggers the EcuM Statemachine and performs necessary actions.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_Statemachine(void);

/**********************************************************************************************************************
 *  EcuM_InternalGoDown()
 **********************************************************************************************************************/
/*! \brief      Initiates the shutdown process.
 *  \details    Initiates the shutdown process. It de-initializes the SchM, BswM and shuts down the OS.
 *  \return     E_NOT_OK - error
 *  \return     E_OK     - success
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalGoDown(void);

/**********************************************************************************************************************
 *  EcuM_InternalKillAllRequests()
 **********************************************************************************************************************/
/*! \brief      Kills all RUN or POST_RUN requests.
 *  \details    Kills RUN or POST_RUN requests, requested by any user. The aim of this function is to
 *              enforce a fast shutdown.
 *  \param[in]  mask                    ECUM_USER_REQUEST_POST_RUN_MASK or ECUM_USER_REQUEST_RUN_MASK
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_InternalKillAllRequests(uint8 mask);

# if(ECUM_SUPPORT_COMM == STD_ON)
/**********************************************************************************************************************
 *  EcuM_QryComMRunRequest()
 **********************************************************************************************************************/
/*! \brief      Polls the state of all ComM Channels.
 *  \details    Polls the state of all ComM channels and returns true if at least on channel still needs
 *              communication.
 *  \return     TRUE - At least one channel needs communication
 *  \return     FALSE - No channel needs communication
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(boolean, ECUM_CODE) EcuM_QryComMRunRequest(void);
# endif

# if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
#  if (ECUM_SLEEPMODELIST == STD_ON)
/**********************************************************************************************************************
 *  EcuM_WaitOnNvMCancelWriteAll()
 **********************************************************************************************************************/
/*! \brief      Monitors the status of the NvM write.
 *  \details    Triggers the NvM_CancelWriteAll and monitors the corresponding timer. If the timer
 *              expires the API NvM_KillWriteAll is invoked.
 *  \return     TRUE - stay in current state
 *  \return     FALSE - switch to the next state
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE boolean EcuM_WaitOnNvMCancelWriteAll(void);
#  endif

/**********************************************************************************************************************
 *  EcuM_WaitOnNvMWriteAll()
 **********************************************************************************************************************/
/*! \brief      Monitors the status of the NvM write.
 *  \details    Triggers the NvM_WriteAll and monitors the corresponding timer. If the timer expires the
 *              callout to signal a NvM timeout is invoked.
 *  \return     TRUE - stay in current state
 *  \return     FALSE - switch to the next state
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL boolean EcuM_WaitOnNvMWriteAll(void);
# endif
#endif

#if((ECUM_FIXED_BEHAVIOR == STD_ON) ||(ECUM_MODE_HANDLING == STD_ON))
/**********************************************************************************************************************
 *  EcuM_InternalRequestRUN()
 **********************************************************************************************************************/
/*! \brief      Requests RUN or POST_RUN.
 *  \details    Requests RUN or POST_RUN requests, requested by a specific user.
 *  \param[in]  ApiId                   Parameter can be either ECUM_SID_REQUEST_POST_RUN or ECUM_SID_REQUEST_RUN.
 *  \param[in]  User                    The user which wants to request RUN or POST_RUN.
 *  \param[in]  mask                    ECUM_USER_REQUEST_POST_RUN_MASK or ECUM_USER_REQUEST_RUN_MASK
 *  \return     E_NOT_OK - error
 *  \return     E_OK     - success
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalRequestRUN(uint8 ApiId, EcuM_UserType User, uint8 mask);

/**********************************************************************************************************************
 *  EcuM_InternalReleaseRUN()
 **********************************************************************************************************************/
/*! \brief      Releases RUN or POST_RUN.
 *  \details    Releases RUN or POST_RUN requests, requested by a specific user.
 *  \param[in]  ApiId                   Parameter can be either ECUM_SID_RELEASE_POST_RUN or ECUM_SID_RELEASE_RUN
 *  \param[in]  User                    The user which wants to release RUN or POST_RUN.
 *  \param[in]  mask                    ECUM_USER_REQUEST_POST_RUN_MASK or ECUM_USER_REQUEST_RUN_MASK
 *  \return     E_NOT_OK - error
 *  \return     E_OK     - success
 *  \pre        -
 *  \context    TASK|ISR
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalReleaseRUN(uint8 ApiId, EcuM_UserType User, uint8 mask);
#endif

#if(ECUM_MODE_HANDLING == STD_ON)
/**********************************************************************************************************************
 *  EcuM_InternalRteFeedbackCheck()
 **********************************************************************************************************************/
/*! \brief      Checks the Rte acknowledge.
 *  \details    Checks if the Rte has acknowledged the last mode switch.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalRteFeedbackCheck(void);
#endif

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  EcuM_GetShiftCount()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
ECUM_LOCAL FUNC(uint8, ECUM_CODE) EcuM_GetShiftCount(EcuM_WakeupSourceType x)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 retval = 0;
  EcuM_WakeupSourceType xlocal = x;

  /* ----- Implementation ----------------------------------------------- */
  xlocal = xlocal - (EcuM_WakeupSourceType) 1u;

  /* #30 Shift the passed parameter in single steps till the LSB of the passed parameter is set (1). The iteration steps
   * represent the wanted shiftcount. */
  while ((xlocal & 1u) != 0u)
  {
    retval++;
    /* Right shift with unsigned value is handled as a logical shift in ISO C99 - 0 is inserted as MSB. */
    xlocal >>= 1u;
  }

  return retval;
} /* End of EcuM_GetShiftCount() */

#if (ECUM_SLEEPMODELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_EnterSleep()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(Std_ReturnType, ECUM_CODE) EcuM_EnterSleep(VAR(uint8, AUTOMATIC) SuspendMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;

# if (ECUM_POLLINGOFSLEEPMODELIST == STD_OFF)
  ECUM_DUMMY_STATEMENT(SuspendMode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  /* ----- Implementation ----------------------------------------------- */
  /* #30 Check if Shutdown Target is set correctly (ECUM_STATE_SLEEP). */
  if (EcuM_CurrentShutdownTarget == ECUM_STATE_SLEEP)
  {
# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
    EcuM_SetModuleState(ECUM_STATE_GO_SLEEP);
# endif

    /* #31 If the Alarm Clock Feature is enabled, activate the GPT EnableWakeup feature, start the timer and set the GPT Mode to Sleep. */
# if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
    EcuM_GptSetSleep((Gpt_ChannelType)EcuM_GetGptChannel(), GPT_MODE_SLEEP);
# endif

# if (ECUM_ISDEF_WAKEUPSOURCEOFSLEEPMODELIST == STD_OFF)
    /* #32 Disable wakeup sources which are not active during this sleep mode and are still active from last sleepmode. */
    if ((EcuM_EnabledWakeups & (~EcuM_GetWakeupSourceOfSleepModeList(EcuM_CurrentShutdownMode))) != 0u)
    {
      EcuM_DisableWakeupSources(EcuM_EnabledWakeups & (~EcuM_GetWakeupSourceOfSleepModeList(EcuM_CurrentShutdownMode)));
    }
# endif

    /* #33 Enable the wakeup sources of the current sleep mode for the upcoming sleep phase. */

    /*  The wakeup sources can be derived from the EcuM_SleepModeList, the correct entry of the list is
     *  selected by the currently configured EcuM_ShutdownMode. */

    EcuM_EnableWakeupSources(EcuM_GetWakeupSourceOfSleepModeList(EcuM_CurrentShutdownMode) & (~EcuM_EnabledWakeups));
    EcuM_EnabledWakeups = EcuM_GetWakeupSourceOfSleepModeList(EcuM_CurrentShutdownMode);

    /* #34 Notify the BswM about the enabled wakeup sources. */
    BswM_EcuM_CurrentWakeup(EcuM_EnabledWakeups, ECUM_WKSTATUS_ENABLED);

    /* #35 Block the scheduler to avoid interruption of the sleep phase by other tasks. */
    (void)GetResource(ECUM_SLEEP_RESOURCE);

    /* #36 In case of a multicore Ecu set the core status of the BSW core to sleep and wait till all other slave cores
     *  are also in sleep. */
# if (ECUM_SLAVE_CORE_HANDLING == STD_ON)
    EcuM_SetCoreStatusValue(ECUM_CORE_ID_BSW, ECUM_CORESTATUS_SLEEP); /* SBSW_SETCORESTATUS_BSWCOREID */
    EcuM_ShutdownSynchronization(ECUM_CORESTATUS_SLEEP);
# endif

    /* #37 Suspend all interrupts here to do not miss an interrupt till the call of Mcu_SetMode. The interrupts will be unlocked again by
     *     the Mcu during entering of the sleep mode. */
    EcuM_GlobalSuspend();

    /* #38 Check for occurrence of wakeup events in the EnterSleep sequence before interrupts have been locked. */
    if (ECUM_COMBINEDWAKEUPS == (EcuM_WakeupSourceType) ECUM_WKSOURCE_NONE)
    {
# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
      /* #40 In case of no occurred wakeup event, continue the sleep handling. */
      EcuM_SetModuleState(ECUM_STATE_SLEEP);
# endif

      /* Store the LastShutdownTarget and LastShutdownMode. */
      EcuM_LastShutdownTarget = EcuM_CurrentShutdownTarget;
      EcuM_LastShutdownMode = EcuM_CurrentShutdownMode;

# if(ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
      /* Check if EcuM_EnterSleep is called by EcuM_GoPoll or EcuM_GoHalt. */
      if (SuspendMode == ECUM_ENTER_POLL)
      {
        EcuM_InternalEnterPollingMode();
      }
      else
# endif
      {
        EcuM_InternalEnterHaltMode();
      }
    }
    else
    {
      /* #39 In case of an occurred wakeup event, continue with the wakeup restart sequence. */
      EcuM_GlobalRestore();
    }
# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
    EcuM_SetModuleState(ECUM_STATE_WAKEUP_ONE);
# endif

    /* #41 Restore the Mcu normal mode with suspended interrupts (requirement of the Mcu_SetMode API). */
    EcuM_GlobalSuspend();

    EcuM_McuSetMode((Mcu_ModeType) EcuM_GetNormalMcuMode());

    EcuM_GlobalRestore();

    /* #42 In case the Alarm Clock Feature is enabled, activate the GPT EnableNotification feature and set the
     *      GPT Mode to Normal. */
# if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)

    EcuM_GptSetNormal((Gpt_ChannelType)EcuM_GetGptChannel(), GPT_MODE_NORMAL);

    /* #43 Clear all further User Alarms. */
    EcuM_InternalClearAlarms();

# endif

    /* #50 Transit to RUN if at least one source is already validated. */
# if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    if (EcuM_ValidatedWakeups != 0u)
# endif
    {
      /* #51 Disable all sources that were active during the current sleepmode.
       *     Notify all sources which are not validated yet to the BswM as ECUM_WKSTATUS_NONE. */
      EcuM_DisableWakeupSources(EcuM_EnabledWakeups);

      BswM_EcuM_CurrentWakeup((EcuM_EnabledWakeups & (~ECUM_COMBINEDWAKEUPS)), ECUM_WKSTATUS_NONE);

      /* #52 If the BswM deferred notification is active, notify the validated wakeup events to BswM here. */
# if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
      EcuM_BswM_BufferedWakeups = 0u;
      BswM_EcuM_CurrentWakeup(EcuM_ValidatedWakeups, ECUM_WKSTATUS_VALIDATED);
# endif

      EcuM_EnabledWakeups = 0u;

# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
      /* Transit the EcuM state to run */
      EcuM_SetModuleState(ECUM_STATE_RUN);
# endif
    }
# if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* #55 Transit to WAKEUP_VALIDATION if no wakeup source is validated. */
    else
    {
      EcuM_EnterCriticalArea_0();

      if((EcuM_EnabledWakeups & EcuM_PendingWakeups) != 0u )
      {
        /* #56 Disable only sources which where enabled and a wake-up event occurred, but leave the other sources
         * armed for later wakeups. */
        EcuM_DisableWakeupSources((EcuM_WakeupSourceType)(EcuM_EnabledWakeups & EcuM_PendingWakeups));
        EcuM_EnabledWakeups &= (~EcuM_PendingWakeups);
      }

      EcuM_LeaveCriticalArea_0();

      /* #57 If the BswM deferred notification is active, notify the pending wakeup events to BswM here. */
#  if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
      BswM_EcuM_CurrentWakeup(EcuM_PendingWakeups, ECUM_WKSTATUS_PENDING);
#  endif
#  if(ECUM_FIXED_BEHAVIOR == STD_OFF)
      EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
# endif
    }
# endif

    /* #60 Re-initialize necessary modules (EcuM_AL_DriverRestartList()). */
    ECUM_DRIVERRESTART_LIST(); /* SBSW_ECUM_FUNCTIONPOINTER_CALL */

    /* #61 Unlock the scheduler to continue task scheduling. */
    (void)ReleaseResource(ECUM_SLEEP_RESOURCE);

    /* #62 In case of a multicore Ecu set the core status of the BSW core to run again to continue running of the slave cores. */
# if (ECUM_SLAVE_CORE_HANDLING == STD_ON)
    EcuM_EnterCriticalArea_1();

    EcuM_SetCoreStatusValue(ECUM_CORE_ID_BSW, ECUM_CORESTATUS_RUN); /* SBSW_SETCORESTATUS_BSWCOREID */

    EcuM_LeaveCriticalArea_1();
# endif

    retval = E_OK;
  }
  else
  {
    retval = E_NOT_OK;
  }

  return retval;

} /* PRQA S 6050 */ /* MD_MSR_STCAL */

# if (ECUM_NUMBER_OF_CORES > 1u)
/***********************************************************************************************************************
 *  EcuM_EnterSleepOnSlave()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(Std_ReturnType, ECUM_CODE) EcuM_EnterSleepOnSlave(CoreIdType CoreID)
{
#  if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
  boolean WaitOnMaster = TRUE;
#  endif

#  if(ECUM_CORERESOURCE == STD_ON)
  /* #60 Block the scheduler to avoid interruption of the sleep phase by other tasks. */
  (void)GetResource(EcuM_GetCoreResource(CoreID));
#  endif

#  if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
  /* #30 Set the status of this slave core to sleep for synchronization with the BSW core. */
  EcuM_EnterCriticalArea_1();
  EcuM_SetCoreStatusValue(CoreID, ECUM_CORESTATUS_SLEEP); /* SBSW_SETCORESTATUS_OSCOREID */
  EcuM_LeaveCriticalArea_1();
#  endif

  EcuM_GlobalSuspend();

  /* #31 Suspend all interrupts here to do not miss an interrupt till the call of Mcu_SetMode. The interrupts will be unlocked again by
   *     the Mcu during entering of the sleep mode.
   *     Because the Mcu does potentially not use the OS functionality to lock interrupts it is necessary to restore the interrupts
   *     after returning from Mcu_SetMode to bring the interrupt setting of the OS in a consistent state.
   
   *     Mcu_SetMode is called in a loop till at least one wakeup source is set. This is done to prevent waking up caused by
   *     unwanted events e.g. EMC spikes. */
  do
  {

    EcuM_McuSetMode(EcuM_GetMcuModeOfSleepModeList(EcuM_CurrentShutdownMode));

    /* Do a GlobalRestore followed by a GlobalSuspend, to be in a defined interrupt state for the new call of Mcu_SetMode. */
    EcuM_GlobalRestore();

    EcuM_GlobalSuspend();

  }
  while (ECUM_COMBINEDWAKEUPS == (EcuM_WakeupSourceType) ECUM_WKSOURCE_NONE );

  EcuM_GlobalRestore();

#  if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
  /* #32 Wait till the Master Core has switched back to Run. */
  do
  {
    EcuM_EnterCriticalArea_1();

    if (EcuM_GetCoreStatusValue(ECUM_CORE_ID_BSW) == ECUM_CORESTATUS_RUN)
    {
      WaitOnMaster = FALSE;
    }
    EcuM_LeaveCriticalArea_1();
  }
  while (WaitOnMaster == TRUE);
#  endif

#  if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
  EcuM_SetCoreStatusValue(CoreID, ECUM_CORESTATUS_RUN); /* SBSW_SETCORESTATUS_OSCOREID */
#  endif

  /* #40 Restore the Mcu Normal Mode. */
  EcuM_GlobalSuspend();

  EcuM_McuSetMode((Mcu_ModeType) EcuM_GetNormalMcuMode());

  EcuM_GlobalRestore();

#  if(ECUM_CORERESOURCE == STD_ON)
  /* #61 Unlock the scheduler to continue task scheduling. */
  (void)ReleaseResource(EcuM_GetCoreResource(CoreID));
#  endif

#if ((ECUM_CORERESOURCE == STD_OFF) && (ECUM_SLAVE_CORE_HANDLING == STD_OFF))
  ECUM_DUMMY_STATEMENT(CoreID); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */
# endif
#endif

#if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  EcuM_ShutdownSynchronization()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_ShutdownSynchronization(EcuM_CoreStatusType ShutdownState)
{
  uint8_least loopCount;
  boolean EcuMWaitForSlaves;

  /* #30 Wait till all Slave Cores have switched back to the requested state. */
  do
  {
    EcuM_WaitForSlaveCores();

    EcuMWaitForSlaves = FALSE;

    EcuM_EnterCriticalArea_1();

    /* #31 Iterate over all cores and check for each core if it has reached the requested state. */
    for (loopCount = 0u; loopCount < ECUM_NUMBER_OF_CORES; loopCount++)
    {
      if (EcuM_GetCoreStatusValue(loopCount) != ShutdownState)
      {
        EcuMWaitForSlaves = TRUE;
        break;
      }
    }

    EcuM_LeaveCriticalArea_1();

  }
  while (EcuMWaitForSlaves == TRUE);
}
#endif

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/***********************************************************************************************************************
 *  EcuM_UpdateMasterAlarm()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_UpdateMasterAlarm(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least loopCount;

  /* ----- Implementation ----------------------------------------------- */
  /* Set the MasterAlarm to ECUM_ALARM_NOT_ACTIVE at beginning to mark it as not active. */
  EcuM_MasterAlarm = ECUM_ALARM_NOT_ACTIVE;

  /* #31 Iterate over all users and check if one users alarm is smaller than the current MasterAlarm. If smaller, update
   *     the current MasterAlarm. */
  for (loopCount = 0u; loopCount < EcuM_GetSizeOfAlarmClockTimeOut(); loopCount++)
  {
    if ((EcuM_GetAlarmClockTimeOut(loopCount) > EcuM_Clock)
        && (EcuM_GetAlarmClockTimeOut(loopCount) < EcuM_MasterAlarm))
    {
      EcuM_MasterAlarm = EcuM_GetAlarmClockTimeOut(loopCount);
    }
  }

}

/***********************************************************************************************************************
 *  EcuM_InternalClearAlarms()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalClearAlarms(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least loopCount;

  /* ----- Implementation ----------------------------------------------- */
  /* #30 Clear all user alarm clocks. */
  for (loopCount = 0u; loopCount < EcuM_GetSizeOfAlarmClockTimeOut(); loopCount++)
  {
    EcuM_SetAlarmClockTimeOut(loopCount, 0u); /* SBSW_ECUM_ACCESSALARMCLOCK */
  }

}

#endif

#if(ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON || ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
/***********************************************************************************************************************
 *  EcuM_InternalComMNotifications()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalComMNotifications(void)
{
  /* Store the init status of the ComM in the variable ComMStatus */
  ComM_InitStatusType ComMStatus;
  (void) ComM_GetStatus(&ComMStatus); /* SBSW_ECUM_ADRESSPARAMETER_TOCOMM */

  /* #20 If the ComM is initialized. */
  if (ComMStatus == COMM_INIT)
  {
    /* ----- Local Variables ---------------------------------------------- */
    uint8_least sourceID;

    /* ----- Implementation ----------------------------------------------- */
    /**
     * Iteration over wakeup sources starts with the highest ID because normally the ASR standard sources with the
     * lower IDs have no reference to a ComM channel.
     * Initialization of the variable with ECUM_MAX_WAKEUP_SOURCES and decrement at the beginning of the loop is
     * to prevent an overflow of the loopCounter.
     */

    sourceID = EcuM_GetSizeOfWakeupSourceList();

    /* #30 Check if there are buffered wakeups for notifying the ComM about validated wakeup sources. */
    while ((EcuM_ComM_BufferedWakeups != 0u) && (sourceID > 0u)) /* COV_ECUM_01 */
    {
      sourceID--;

      /* #31 Notify all buffered wakeup sources to ComM. */
      if ((((EcuM_WakeupSourceType)1u << (EcuM_WakeupSourceType)sourceID) & EcuM_ComM_BufferedWakeups) != 0u) /* COV_ECUM_04 */
      {
# if (ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM_DEPENDENCY */
#  if (ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
        if(EcuM_GetChannelOfWakeupSourceList(sourceID) != 0xFFu)
#  endif
        {
          ComM_EcuM_WakeUpIndication(EcuM_GetChannelOfWakeupSourceList(sourceID));
        }
# endif

# if (ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
        if(EcuM_GetComMPNCsStartIdxOfWakeupSourceList(sourceID) != ECUM_NO_COMMPNCSSTARTIDXOFWAKEUPSOURCELIST)
        {
          EcuM_InternalComMPNCNotification(sourceID);
        }
# endif

        EcuM_ComM_BufferedWakeups &= (EcuM_WakeupSourceType) (~((EcuM_WakeupSourceType)1u << (EcuM_WakeupSourceType)sourceID));
      }
    }
  }
}

# if(ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
/***********************************************************************************************************************
 *  EcuM_InternalComMPNCNotification()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_InternalComMPNCNotification(uint8_least sourceIDx)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least i;

  /* ----- Implementation ----------------------------------------------- */
  /* #30 Notify all PNCs which belong to a wakeup source to ComM. */
  for(i = EcuM_GetComMPNCsStartIdxOfWakeupSourceList(sourceIDx); i < EcuM_GetComMPNCsEndIdxOfWakeupSourceList(sourceIDx); i++)
  {
    ComM_EcuM_PNCWakeUpIndication(EcuM_GetPNCOfComMPNCs(i));
  }
}
# endif
#endif

#if(ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalBswMNotifications()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalBswMNotifications(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  EcuM_WakeupSourceType bufferedWupSource;

  /* #30 Check for buffered / deferred BswM notifications and if existent, notify them to BswM. */
  EcuM_EnterCriticalArea_0();
  bufferedWupSource = EcuM_BswM_BufferedWakeups;
  EcuM_BswM_BufferedWakeups = ECUM_WKSOURCE_NONE;
  EcuM_LeaveCriticalArea_0();

  /* ----- Implementation ----------------------------------------------- */

    /* #31 First notify expired and pending checkwakeups, then pending wakeups to consider changes of validated wakeups caused by an interrupt */
# if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
    if ((bufferedWupSource & EcuM_ExpiredCheckWakeups) != 0u)
    {
      BswM_EcuM_CurrentWakeup(bufferedWupSource & EcuM_ExpiredCheckWakeups, ECUM_WKSTATUS_EXPIRED);
    }
    if ((bufferedWupSource & EcuM_PendingCheckWakeups) != 0u)
    {
      BswM_EcuM_CurrentWakeup(bufferedWupSource & EcuM_PendingCheckWakeups, ECUM_WKSTATUS_CHECKWAKEUP);
    }
# endif

# if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    if ((bufferedWupSource & EcuM_PendingWakeups) != 0u)
    {
      BswM_EcuM_CurrentWakeup(bufferedWupSource & EcuM_PendingWakeups, ECUM_WKSTATUS_PENDING);
    }
# endif

    if ((bufferedWupSource & EcuM_ValidatedWakeups) != 0u)
    {
      BswM_EcuM_CurrentWakeup(bufferedWupSource & EcuM_ValidatedWakeups, ECUM_WKSTATUS_VALIDATED);
    }

}
#endif

#if (ECUM_PARTITIONINIT == STD_ON)
/**********************************************************************************************************************
 *  EcuM_InternalGetPartitionIdx()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(EcuM_SizeOfPartitionInitType, ECUM_CODE) EcuM_InternalGetPartitionIdx(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  EcuM_SizeOfPartitionInitType partitionIndex = EcuM_GetSizeOfPartitionInit();
  ApplicationType applicationId = GetCurrentApplicationID();

    /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the returned applicationId is a valid one. */
  if (applicationId >= EcuM_GetSizeOfPartitionInit())
  {
    EcuM_ErrorHook(ECUM_E_HOOK_INVALID_APPLICATIONID);
  }
  else
  {
  /* ----- Implementation ----------------------------------------------- */
    /* #21 Iterate over all EcuM instances and return the partition index of the one which fits to the current application. */
    for(partitionIndex = 0u; partitionIndex < EcuM_GetSizeOfPartitionInit(); partitionIndex++) /* COV_ECUM_PARTITIONID */
    {
      if(applicationId == EcuM_GetApplicationOfPartitionInit(partitionIndex))
      {
        break;
      }
    }
  }
  /* #22 Return EcuM_GetSizeOfPartitionInit() in case that no partition was found, if the partition was found, return the partitionIndex. */
  return partitionIndex;
}
#endif

#if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON || ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalWakeupValidation()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalWakeupValidation(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  /* Variable for shifting of the single wake-up sources */
  EcuM_WakeupSourceType WupSource = 32u;
  uint8_least loopCount;

  /* ----- Implementation ----------------------------------------------- */
  EcuM_EnterCriticalArea_0();
  /* #30 Iterate over all pending wakeup sources. */
  for (loopCount = 5u; loopCount < EcuM_GetSizeOfWakeupSourceList(); loopCount++)
  {

# if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* Check if the current iterated source needs validation caused by a pending event. */
    if ((WupSource & (EcuM_PendingWakeups)) != 0u)
    {
      /* Check if the current iterated source is not already started. */
      if ( EcuM_GetValidationTimeoutTable(loopCount) > 0u)
      {
        /* #33 Decrement the sources timeout value. */
        EcuM_DecValidationTimeoutTable(loopCount); /* SBSW_ECUM_ACCESSVALTABLE */

        /* In the context of EcuM_CheckValidation, an API could be called which also uses this CriticalArea. */
        EcuM_LeaveCriticalArea_0();

        /* #35 Execute user-specific code to initiate a wakeup validation for this source (EcuM_CheckValidation()). */
        EcuM_CheckValidation(WupSource);

        EcuM_EnterCriticalArea_0();

        /* #36 Check if no Timeout occurred after the decrement, and the source is not validated in context of check validation. */
        if ((EcuM_GetValidationTimeoutTable(loopCount) == 0u) && ((WupSource & EcuM_PendingWakeups) != 0u))
        {
          /* Timeout occurred for the current source */

          /* #37 Mark this source as an expired wakeup source. */
          EcuM_ExpiredWakeups |= WupSource;

          /* #38 Remove this source from the pending wakeup sources list. */
          EcuM_PendingWakeups &= (~WupSource);

          /* #39 Report this source as an expired source to the BswM. */
          BswM_EcuM_CurrentWakeup(WupSource, ECUM_WKSTATUS_EXPIRED);

          EcuM_LeaveCriticalArea_0();

          /* #40 Execute user-specific code to stop the sources wakeup validation (EcuM_StopWakeupSources()). */
          EcuM_StopWakeupSources(WupSource);

          EcuM_EnterCriticalArea_0();
        }

      }
      /* This wake-up source is not started yet. */
      else
      {
#  if(ECUM_SLEEPMODELIST == STD_ON)

        if((EcuM_EnabledWakeups & WupSource) != 0u) /* COV_ECUM_05 */
        {
          /* #41 Disable a source which is still enabled from last sleep mode. */
          EcuM_DisableWakeupSources(WupSource);
          EcuM_EnabledWakeups &= ~(WupSource);
        }
#  endif

        /* #42 Set the configured timeout for the current source. */
        EcuM_SetValidationTimeoutTable(loopCount, EcuM_GetValidationTimeOfWakeupSourceList(loopCount)); /* SBSW_ECUM_ACCESSVALTABLE */

        EcuM_LeaveCriticalArea_0();

        /* #43 Execute user-specific code to start the sources wakeup validation (EcuM_StartWakeupSources()). */
        EcuM_StartWakeupSources(WupSource);

        /* #36 Check if no Timeout occurred after the decrement, and the source is not validated in context of check validation. */
        EcuM_CheckValidation(WupSource);

        EcuM_EnterCriticalArea_0();
      }
    }
    /* #44 Check if a wakeup source was cleared during validation by EcuM_ClearWakeupEvents. */
    else if ((WupSource & (EcuM_ClearedPendingWakeups)) != 0u)
    {
      /* #45 Remove this source from the cleared pending wakeup sources list. */
      EcuM_ClearedPendingWakeups &= ~(WupSource);

      EcuM_LeaveCriticalArea_0();

      /* #40 Execute user-specific code to stop the sources wakeup validation (EcuM_StopWakeupSources()). */
      EcuM_StopWakeupSources(WupSource);

      EcuM_EnterCriticalArea_0();
    }
    else
# endif

# if(ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* #46 Iterate over all pending check wakeup sources. */
    if ((WupSource & (EcuM_PendingCheckWakeups)) != 0u)
    {
      /* #47 Check if the timeout of the current iterated source is already started. */
      if (EcuM_GetValidationTimeoutTable(loopCount) > 0u)
      {
        /* #48 Decrement the current validation timeout value. */
        EcuM_DecValidationTimeoutTable(loopCount); /* SBSW_ECUM_ACCESSVALTABLE */

        /* #49 Check if the current sources check wakeup timeout has occurred. */
        if (EcuM_GetValidationTimeoutTable(loopCount) == 0u)
        {
          /* #50 Remove the source from the pending check wakeup variable and add it to the expired variable. */
          EcuM_PendingCheckWakeups &= (~WupSource);

          EcuM_ExpiredWakeups |= WupSource;

          /* #39 Report this source as an expired source to the BswM. */
          BswM_EcuM_CurrentWakeup(WupSource, ECUM_WKSTATUS_EXPIRED);

        }
      }
      else
      {
        /* #51 Set the configured check wakeup timeout for the current source to the ValidationTimeoutTable. */
        EcuM_SetValidationTimeoutTable(loopCount, EcuM_GetCheckWakeupTimeOfWakeupSourceList(loopCount)); /* SBSW_ECUM_ACCESSVALTABLE */
      }
    }
    else
# endif
    {
      /* Source is neither a pending wakeup source nor a pending check wakeup source */
    }

    /* Are there any other pending wake-ups? */
# if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    if ( (ECUM_COMBINEDPENDINGWAKEUPS | EcuM_ClearedPendingWakeups) == 0u )
# else
    if (ECUM_COMBINEDPENDINGWAKEUPS == 0u )
# endif
    {
      /* No, leave loop */
      break; /* PRQA S 0771 */ /* MD_EcuM_0771 */
    }

    /* Calculate the Id of the wakeup source. The current index marks the bit-position. */
    WupSource <<= 1u;

  }
  EcuM_LeaveCriticalArea_0();
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (ECUM_SLEEPMODELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalEnterHaltMode()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalEnterHaltMode(void)
{

  /* #30 Create a RamHash via the Callout routine, this is used after wakeup for validation of Ram data. */
  EcuM_GenerateRamHash();

  do
  {
    /* #31 Set the McuMode for the current sleep phase, in this function call the Ecu is not executing code any more. */
    /* #32 After an occurred Interrupt the Mcu starts again and control goes back to the EcuM. */
    EcuM_McuSetMode(EcuM_GetMcuModeOfSleepModeList(EcuM_CurrentShutdownMode));

    /* #33 Do a global restore to be in a defined status after Mcu_SetMode. */
    EcuM_GlobalRestore();

    /* #34 GlobalSuspend is needed for the new call of Mcu_SetMode. It is called at this place to do not miss any wakeup events. */
    EcuM_GlobalSuspend();

    /* #35 If no pending or validated wakeup is stored, the EcuM transits back to sleep again. */
  }
  while (ECUM_COMBINEDWAKEUPS == ECUM_WKSOURCE_NONE);

  /* #36 Else check the former generated RamHash and call the EcuM_ErrorHook in case of an error. */
  if ( EcuM_CheckRamHash() == 0u)
  {
    /* Dem is not called because of the possibility of writing into damaged NVRAM blocks */
    EcuM_ErrorHook(ECUM_E_HOOK_RAM_CHECK_FAILED);
  }

  EcuM_GlobalRestore();
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

# if(ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalEnterPollingMode()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalEnterPollingMode(void)
{
  uint8_least loopCount;

  /* #20 Set the McuMode for the current sleep phase */
  EcuM_McuSetMode(EcuM_GetMcuModeOfSleepModeList(EcuM_CurrentShutdownMode));

  EcuM_GlobalRestore();

  /* #30 Do the following cyclically as long as no wakeup source is pending or validated:*/

  while (ECUM_COMBINEDWAKEUPS == ECUM_WKSOURCE_NONE)
  {
    /* #31 Call of EcuM_SleepActivity to control the polling sleep phase. */
    EcuM_SleepActivity();

    for (loopCount = 0u; loopCount < EcuM_GetSizeOfWakeupSourceList(); loopCount++)
    {

      if ((((EcuM_WakeupSourceType)1u << (EcuM_WakeupSourceType)loopCount) &
           (EcuM_GetWakeupSourceOfSleepModeList(EcuM_CurrentShutdownMode))) != 0u)
      {
        /*  #32 Call CheckWakeup for sources which are active during this sleep phase and configured as polling
         *      wakeup sources. */
        if (EcuM_IsPollingOfWakeupSourceList(loopCount))
        {
          EcuM_CheckWakeup(((EcuM_WakeupSourceType)1u << (EcuM_WakeupSourceType)loopCount));
        }
      }
    }
  }
}

# endif
#endif

#if((ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON) || (ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE))
/***********************************************************************************************************************
 *  EcuM_InternalDeterminePbConfiguration()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalDeterminePbConfiguration(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 ecumErrorId = ECUM_NO_BSWERROR;

# if(ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)
  /* Get the pointer to initialization structure of the EcuM */
  EcuM_GlobalPBConfig_Ptr = (P2CONST(EcuM_GlobalConfigType, AUTOMATIC, ECUM_PBCFG))EcuM_DeterminePbConfiguration();

# else
  EcuM_GlobalPCConfig_Ptr = EcuM_DeterminePbConfiguration();
# endif
  /* ----- Development Error Checks ------------------------------------- */
  /* #31 Check the global config pointer for NullPointer. */
  if (NULL_PTR == ECUM_GLOBAL_CFG_PTR)
  {
    errorId = ECUM_E_NULL_POINTER;
  }
# if(ECUM_USE_INIT_POINTER == STD_ON)
  else
  {
    EcuM_ConfigDataPtr = ECUM_GLOBAL_CFG_PTR->CfgPtr_EcuM_Init;
    /* #32 Check the EcuM configuration for NullPointer. */
    if (EcuM_ConfigDataPtr == NULL_PTR)
    {
#  if (ECUM_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
      ecumErrorId = ECUM_BSWERROR_NULLPTR;
#  else
      errorId = ECUM_E_NULL_POINTER;
#  endif
    }
    else
    {

#  if(ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE)

      /* #40 Check consistency of Postbuild-Loadable configuration data. */
      if((EcuM_GetEcuM_CRCHash_Lower() != ECUM_PRECOMPILE_CRC_HASH_LOWER) ||
          (EcuM_GetEcuM_CRCHash_Upper() != ECUM_PRECOMPILE_CRC_HASH_UPPER))
      {
        /* #41 In case of an inconsistent configuration, the user has to choose the modality how the ECU is stopped (Via EcuM_ErrorHook). */
        EcuM_ErrorHook(ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT);
      }

#   if(ECUM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) /* COV_ECUM_02 */
      /* #42 Check the modules generator version and notify a fail (call of EcuM_BswErrorHook). */
      if(EcuM_GetGeneratorCompatibilityVersion() != ECUM_GENERATOR_COMPATIBILITY_VERSION)
      {
        ecumErrorId = ECUM_BSWERROR_COMPATIBILITYVERSION;
      }

      /* #43 Check the modules magic number and notify a fail (call of EcuM_BswErrorHook). */
      if(EcuM_GetFinalMagicNumber() != ECUM_FINAL_MAGIC_NUMBER)
      {
        ecumErrorId = ECUM_BSWERROR_MAGICNUMBER;
      }
#   endif /* (ECUM_USE_ECUM_BSW_ERROR_HOOK == STD_ON) */
#   if(ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON)
      EcuM_GlobalPCConfig_Ptr = &EcuM_GlobalPcConfig[EcuM_GlobalPBConfig_Ptr->EcuM_GlobalConfig_Index];
#   endif
#  endif /* (ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) */
    }
  }
# endif

# if (ECUM_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
  if(ecumErrorId != ECUM_NO_BSWERROR)
  {
    EcuM_BswErrorHook(ECUM_MODULE_ID, ecumErrorId);
  }
# else
  ECUM_DUMMY_STATEMENT(ecumErrorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

# if (ECUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_INIT, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

}
#endif

/***********************************************************************************************************************
 *  EcuM_InternalClearWakeupEvent()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalClearWakeupEvent(
    VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
  /* Clear the passed source in the validated wakeups variable. */
  EcuM_ValidatedWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

  /* Clear the passed source in the buffered BswM wakeups variable. */
  EcuM_BswM_BufferedWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
  /* Clear the passed source in the pending wakeups variable. - If wakeup validation is configured. */
  EcuM_PendingWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);
#endif

#if (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)
  /* Clear the passed source in the expired wakeups variable. - If wakeup validation is configured. */
  EcuM_ExpiredWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);
#endif

#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
  /* Clear the passed source in the pending checkwakeups variable. - If checkwakeup validation is configured. */
  EcuM_PendingCheckWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

# if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
  EcuM_ExpiredCheckWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);
# endif

#endif

#if(ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON)
  /* Clear the passed source in the buffered ComM wakeups variable. - If a source with relation to a ComM Channel is configured. */
  EcuM_ComM_BufferedWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);
#endif

}

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
/***********************************************************************************************************************
 *  EcuM_ActEnterRun()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_ActEnterRun(void)
{
  /* ----- Local Variables ---------------------------------------------- */
# if(ECUM_COMM_COMALLOWEDLIST == STD_ON)
  uint8_least loopCount;
# endif

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Set the EcuM State to ECUM_STATE_APP_RUN. */
  EcuM_SetModuleState(ECUM_STATE_APP_RUN);

  /* #21 Execute user-specific code during transition to Run (EcuM_OnEnterRun()). */
  EcuM_OnEnterRun();

# if(ECUM_COMM_COMALLOWEDLIST == STD_ON)
  /* #22 Set communication of all configured ComM channels to allowed when enter run state. */
  for (loopCount = 0u; loopCount < EcuM_GetSizeOfComM_ComAllowedList(); loopCount++)
  {
    ComM_CommunicationAllowed(EcuM_GetComM_ComAllowedList(loopCount), TRUE);
  }
# endif

  /* #23 Set the self run request timer. */
  EcuM_SetTimer((uint16)EcuM_GetSelfRunRequestTimeout());

  /* #24 Notify the state ECUM_STATE_APP_RUN to BswM. */
  BswM_EcuM_CurrentState( ECUM_STATE_APP_RUN);

  /* #25 Trigger the RTE Mode Switch to RUN. */
  ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_RUN);
}

# if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
/***********************************************************************************************************************
 *  EcuM_WaitOnNvMWriteAll()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL boolean EcuM_WaitOnNvMWriteAll(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #30 In case the WriteAll Status is Idle: */
  if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_IDLE)
  {
    /* #31 NvM_WriteAll has already finished - Stop timer. */
    EcuM_SetTimer(ECUM_TIMER_NOT_SET);
  }
  /* #40 In case the WriteAll Status is Required: */
  else if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_REQUIRED)
  {
    /* #41 Set the WriteAll Status to started.*/
    EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_STARTED);
    /* #42 Set the internal timer to monitor a WriteAll timeout. */
    EcuM_SetTimer(EcuM_GetNvMWriteAllTimeout());
    /* #43 Trigger the NvM_WriteAll(). */
    NvM_WriteAll();
    retVal = TRUE;
  }
  /* #50 In case the WriteAll Status is Expired: */
  else if ( EcuM_GetTimer() == ECUM_TIMER_EXPIRED)
  {
    /* #51 Execute user-specific code to react on a failed WriteAll (EcuM_OnFailedNvmWriteAllJobReaction()). */
    EcuM_OnFailedNvmWriteAllJobReaction();
    /* #52 Stop the internal timer to monitor a timeout. */
    EcuM_SetTimer(ECUM_TIMER_NOT_SET);
    /* #53 Set the WriteAll Status to Idle. */
    EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_IDLE);
  }
  /* #60 In case the WriteAll Status is Expired: */
  else
  {
    /* #61 WriteAll is still in progress and timer not expired - Wait for NvM job end notification. */
    retVal = TRUE;
  }
  return retVal;
}

#  if(ECUM_SLEEPMODELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_WaitOnNvMCancelWriteAll()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE boolean EcuM_WaitOnNvMCancelWriteAll(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean retVal = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  /* #30 In case the WriteAll Status is Idle: */
  if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_IDLE)
  {
    /* #31 NvM_WriteAll has already finished - Stop timer. */
    EcuM_SetTimer(ECUM_TIMER_NOT_SET);
  }
  /* #40 In case the WriteAll Status is Started: */
  else
#   if(ECUM_NVMCANCELWRITEALLTIMEOUT == STD_ON)
  if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_STARTED)
#   endif
  {
    /* #41 Set the WriteAll Status to canceled. */
    EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_CANCELED);

    /* #42 Set the internal timer to monitor a CancelWriteAll timeout. */
#   if(ECUM_NVMCANCELWRITEALLTIMEOUT == STD_ON)
    EcuM_SetTimer(EcuM_GetNvMCancelWriteAllTimeout());
    retVal = TRUE;
#   else
    EcuM_SetTimer(ECUM_TIMER_NOT_SET);
#   endif

    /* #43 Trigger the NvM_CancelWriteAll(). */
    NvM_CancelWriteAll();
  }
  /* #50 In case the WriteAll Status is Expired: */
#   if(ECUM_NVMCANCELWRITEALLTIMEOUT == STD_ON)
  else if ( EcuM_GetTimer() == ECUM_TIMER_EXPIRED)
  {
    /* #51 EcuM shall call the KillWriteAll(MICROSAR extension) API to force an abort of the job. */
    NvM_KillWriteAll();
    /* #52 Stop the internal timer to monitor a timeout. */
    EcuM_SetTimer(ECUM_TIMER_NOT_SET);
    /* #53 Set the WriteAll Status to required, to re-trigger a WriteAll for the next shutdown. */
    EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_REQUIRED);
  }
  /* #60 In case the WriteAll Status is Canceled: */
  else if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_CANCELED)
  {
    /* #61 NvM has not finished yet, remain in this state. */
    retVal = TRUE;
  }
  else
  {
    /* Nothing to do */
  }
#   endif
  return retVal;
}
#  endif
# endif

# if(ECUM_SUPPORT_COMM == STD_ON)
/***********************************************************************************************************************
 *  EcuM_QryComMRunRequest()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
ECUM_LOCAL FUNC(boolean, ECUM_CODE) EcuM_QryComMRunRequest(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8_least loopCount;
  boolean retVal = FALSE;
  ComM_StateType currentState;

  /* ----- Implementation ----------------------------------------------- */
  /* Iterate over all configured ComM Channels. */
  for (loopCount = 0u; loopCount < EcuM_GetSizeOfComMChannels(); loopCount++)
  {
    /*  Get the state of every channel and check if the request was successful (E_OK). */
    if (E_OK == ComM_GetState((NetworkHandleType) EcuM_GetComMChannels(loopCount), &currentState)) /* SBSW_ECUM_ADRESSPARAMETER_TOCOMM */
    {
      /* If at least one channel is not COMM_NO_COM_NO_PENDING_REQUEST the function returns and EcuM has to stay in Run State. */
      if (currentState != COMM_NO_COM_NO_PENDING_REQUEST)
      {
        retVal = TRUE;
        break;
      }
    }
  }
  return retVal;
}
# endif

/***********************************************************************************************************************
 *  EcuM_Statemachine
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_Statemachine(void)
{
# if(ECUM_COMM_COMALLOWEDLIST == STD_ON)
  uint8_least loopCount;
# endif

  switch ( EcuM_GetModuleState())
  {
    /*******************************************************************************************************************
     *  ECUM_STATE_STARTUP
     ******************************************************************************************************************/
    case ECUM_STATE_STARTUP_TWO:
# if ( ECUM_SUPPORT_RTE_MODE_SWITCH_ACK == STD_ON )
    if (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
# endif
    {
      if (EcuM_ValidatedWakeups != 0u)
      {
        EcuM_ActEnterRun();
      }
      else
      {
        /* no validated wake up event notified, change to wakeup validation */
        EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
        BswM_EcuM_CurrentState( ECUM_STATE_WAKEUP_VALIDATION);
        ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_SLEEP);
      }
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_RUN
     ******************************************************************************************************************/
    case ECUM_STATE_APP_RUN:

      /*
       * Critical section is necessary to prevent interruption between polling of ComM channel state and clearing of
       * wakeup events. An interruption could cause losing of wakeup events.
       * \trace DSGN-EcuM2048
       */
      EcuM_EnterCriticalArea_0();

    /* PRQA S 3415 6 */ /* MD_EcuM_3415 */
    if ((EcuM_GetRunRequestCounter() == 0u)
# if (ECUM_SUPPORT_RTE_MODE_SWITCH_ACK == STD_ON )
        && (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
# endif
# if(ECUM_SUPPORT_COMM == STD_ON)
        && (EcuM_QryComMRunRequest() == FALSE)
# endif
# if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST)
        && (EcuM_PendingWakeups == 0u)
# endif
        && (EcuM_GetTimer() == 0u))
    {
      /* No pending wakeup is present - wakeups can be cleared */
      EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);

      EcuM_LeaveCriticalArea_0();

# if(ECUM_COMM_COMALLOWEDLIST== STD_ON)
      /* Set communication of all ComM channels to not allowed when leaving run state */
      for (loopCount = 0u; loopCount < EcuM_GetSizeOfComM_ComAllowedList(); loopCount++)
      {
        ComM_CommunicationAllowed(EcuM_GetComM_ComAllowedList(loopCount), FALSE);
      }
# endif

      EcuM_OnExitRun();

      /* Transit to PostRun */
      EcuM_SetModuleState(ECUM_STATE_APP_POST_RUN);

      BswM_EcuM_CurrentState( ECUM_STATE_APP_POST_RUN);
      ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_POST_RUN);
    }
    else
    {
      EcuM_LeaveCriticalArea_0();
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_POST_RUN
     ******************************************************************************************************************/
    case ECUM_STATE_APP_POST_RUN:

# if ( ECUM_SUPPORT_RTE_MODE_SWITCH_ACK == STD_ON )
    if (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
# endif
    {
      /* PRQA S 3415 3 */ /* MD_EcuM_3415 */
      if ((EcuM_ValidatedWakeups != 0u)
# if(ECUM_SUPPORT_COMM == STD_ON)
          || (EcuM_QryComMRunRequest() == TRUE)
# endif
          || (EcuM_GetRunRequestCounter() != 0u))
      {
        /* Transit to Run */
        EcuM_ActEnterRun();
      }
      else if ( EcuM_GetPostRunRequestCounter() == 0u)
      {
        /* Transit to PrepShutdown */
        EcuM_OnExitPostRun();

# if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
        /* Mark that NvM_WriteAll must be performed, caused by pending data */
        EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_REQUIRED);
# endif
        /* Transit to Prep Shutdown */
        EcuM_SetModuleState(ECUM_STATE_PREP_SHUTDOWN);

        BswM_EcuM_CurrentState( ECUM_STATE_PREP_SHUTDOWN);
      }
      else
      {
        /* Nothing to do */
      }
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_PREP_SHUTDOWN
     ******************************************************************************************************************/
    case ECUM_STATE_PREP_SHUTDOWN:

    EcuM_OnPrepShutdown();
# if (ECUM_SUPPORT_DEM == STD_ON)
    Dem_Shutdown();
    EcuM_SetDemStatus(ECUM_DEM_SHUT_DOWN);
# endif
# if (ECUM_SLEEPMODELIST == STD_ON)
    if (EcuM_CurrentShutdownTarget == ECUM_STATE_SLEEP)
    {
      /* Transit to Go Sleep */
      EcuM_SetModuleState(ECUM_STATE_GO_SLEEP);
      EcuM_OnGoSleep();
      BswM_EcuM_CurrentState( ECUM_STATE_GO_SLEEP);
      ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_SLEEP);
    }
    else /* target is ECUM_STATE_OFF or ECUM_STATE_RESET */
# endif
    {
      /* Transit to Go Off */
      EcuM_SetModuleState(ECUM_STATE_GO_OFF_ONE);
      EcuM_OnGoOffOne();
      BswM_EcuM_CurrentState( ECUM_STATE_GO_OFF_ONE);
      ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_SHUTDOWN);
    }
    break;
# if (ECUM_SLEEPMODELIST == STD_ON)
    /*******************************************************************************************************************
     *  ECUM_STATE_GO_SLEEP
     ******************************************************************************************************************/
    case ECUM_STATE_GO_SLEEP:

#  if (ECUM_SUPPORT_RTE_MODE_SWITCH_ACK == STD_ON )
    if (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
#  endif
    {
      if (ECUM_COMBINEDWAKEUPS != ECUM_WKSOURCE_NONE)
      {
#  if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
        (void) EcuM_WaitOnNvMCancelWriteAll();
#  endif

        /* Transit to wakeup Validation */
        EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
        BswM_EcuM_CurrentState( ECUM_STATE_WAKEUP_VALIDATION);
      }
#  if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
      else if (EcuM_WaitOnNvMWriteAll() == TRUE)
      {
        /* Wait for Write All */
      }
#  endif
      else
      {
        /* Transit to Sleep */
        EcuM_SetModuleState(ECUM_STATE_SLEEP);
        BswM_EcuM_CurrentState( ECUM_STATE_SLEEP);
      }
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_SLEEP
     ******************************************************************************************************************/
    case ECUM_STATE_SLEEP:

    EcuM_SetKillAllInProgress(0u);

#  if (ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
    if(EcuM_IsPollingOfSleepModeList(EcuM_CurrentShutdownMode))
    {
      (void)EcuM_EnterSleep(ECUM_ENTER_POLL);
    }
    else
#  endif
    {
      (void) EcuM_EnterSleep( ECUM_ENTER_HALT);
    }

    /* Transit to wakeup validation */
    EcuM_SetModuleState(ECUM_STATE_WAKEUP_VALIDATION);
    BswM_EcuM_CurrentState( ECUM_STATE_WAKEUP_VALIDATION);

    break;
# endif /* (ECUM_SLEEPMODELIST == STD_ON) */

    /*******************************************************************************************************************
     *  ECUM_STATE_WAKEUP_VALIDATION
     ******************************************************************************************************************/
    case ECUM_STATE_WAKEUP_VALIDATION:

# if(ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)
    if ((EcuM_ValidatedWakeups != 0u) || (ECUM_COMBINEDPENDINGWAKEUPS == 0u))
# endif
    {
      /* Transit to wakeup reaction */
      EcuM_SetModuleState(ECUM_STATE_WAKEUP_REACTION);
      EcuM_OnWakeupReaction();
      BswM_EcuM_CurrentState( ECUM_STATE_WAKEUP_REACTION);
    }
# if ( (ECUM_INCLUDE_NVRAM_MGR == STD_ON) && (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON) && (ECUM_NVMCANCELWRITEALLTIMEOUT == STD_ON))
    else
    {
      (void) EcuM_WaitOnNvMCancelWriteAll();
    }
# endif
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_WAKEUP_REACTION
     ******************************************************************************************************************/
    case ECUM_STATE_WAKEUP_REACTION:

# if ((ECUM_INCLUDE_NVRAM_MGR == STD_ON) && (ECUM_NVMCANCELWRITEALLTIMEOUT == STD_ON))
    if (EcuM_WaitOnNvMCancelWriteAll() == TRUE)
    {
      /* Wait for Cancel WriteAll */
    }
    else
# endif
    {
      if (EcuM_ValidatedWakeups != 0u)
      {
# if (ECUM_SLEEPMODELIST == STD_ON)
#  if (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)

        /* Disable all sources that were active during the last sleepmode */
        EcuM_DisableWakeupSources(EcuM_EnabledWakeups);

        BswM_EcuM_CurrentWakeup(EcuM_EnabledWakeups & (~ECUM_COMBINEDWAKEUPS), ECUM_WKSTATUS_NONE);
        EcuM_EnabledWakeups = 0u;

#  endif /* (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON) */
# endif /* (ECUM_SLEEPMODELIST == STD_ON) */

# if (ECUM_SUPPORT_DEM == STD_ON)
        Dem_Init( ECUM_DEM_CONFIG_POINTER); /* SBSW_ECUM_DEM_FUNCTIONCALL_POINTER */
        EcuM_SetDemStatus(ECUM_DEM_INITIALIZED);
# endif

        EcuM_ActEnterRun();
      }
      else
      {
        /* Transit to Wake Sleep */
        EcuM_SetModuleState(ECUM_STATE_WAKEUP_WAKESLEEP);
        BswM_EcuM_CurrentState( ECUM_STATE_WAKEUP_WAKESLEEP);
        ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_WAKE_SLEEP);

# if (ECUM_SUPPORT_DEM == STD_ON)
        if ( EcuM_GetDemStatus() == ECUM_DEM_INITIALIZED)
        {
          Dem_Shutdown();
          EcuM_SetDemStatus(ECUM_DEM_SHUT_DOWN);
        }
# endif
      }
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_WAKE_SLEEP
     ******************************************************************************************************************/
    case ECUM_STATE_WAKEUP_WAKESLEEP:

# if (ECUM_SUPPORT_RTE_MODE_SWITCH_ACK == STD_ON )
    if (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
# endif
    {

# if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
      EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_REQUIRED);
# endif

# if (ECUM_SLEEPMODELIST == STD_ON)
      if (EcuM_CurrentShutdownTarget == ECUM_STATE_SLEEP)
      {
        /* Transit to Go Sleep */
        EcuM_SetModuleState(ECUM_STATE_GO_SLEEP);
        EcuM_OnGoSleep();
        BswM_EcuM_CurrentState( ECUM_STATE_GO_SLEEP);
        ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_SLEEP);
      }
      else
# endif
      { /* target is ECUM_STATE_OFF or ECUM_STATE_RESET */
        /* Transit to Go Off One */
        EcuM_SetModuleState(ECUM_STATE_GO_OFF_ONE);
        EcuM_OnGoOffOne();
        BswM_EcuM_CurrentState( ECUM_STATE_GO_OFF_ONE);
        ECUM_RTE_SWITCH(RTE_MODE_EcuM_Mode_SHUTDOWN);
      }
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_GO_OFF_ONE
     ******************************************************************************************************************/
    case ECUM_STATE_GO_OFF_ONE:

    /* Do not cancel GoOff in state machine -> EcuM will perform reset in case of wakeup */
# if ( ECUM_SUPPORT_RTE_MODE_SWITCH_ACK == STD_ON )
    if (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
# endif
    {
# if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
      if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_REQUIRED)
# endif
      {
# if(ECUM_SUPPORT_RTE == STD_ON)
        (void) Rte_Stop();
# endif

# if(ECUM_SUPPORT_COMM == STD_ON)
        ComM_DeInit();
# endif
      }

# if (ECUM_INCLUDE_NVRAM_MGR == STD_ON)
      if (EcuM_WaitOnNvMWriteAll() == FALSE)
# endif
      {
        (void) EcuM_InternalGoDown();

        /* Transit to Error State, if EcuM_GoDown returns */
        EcuM_SetModuleState(ECUM_STATE_ERROR);
      }
    }
    break;

    /*******************************************************************************************************************
     *  ECUM_STATE_ERROR
     ******************************************************************************************************************/
    default:
    /* error - unknown case */
    EcuM_ErrorHook(ECUM_E_HOOK_WRONG_ECUM_USAGE);
    break;
  }
} /* PRQA S 6030, 6050 */ /* MD_MSR_STCYC, MD_MSR_STCAL */

/***********************************************************************************************************************
 *  EcuM_InternalKillAllRequests
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(void, ECUM_CODE) EcuM_InternalKillAllRequests(uint8 mask)
{
  /* ----- Local Variables ---------------------------------------------- */
  EcuM_UserTableIterType user;

  /* ----- Implementation ----------------------------------------------- */
  /* #30 Set the internal flag-variable to indicate that KillAll is in progress. */
  EcuM_SetKillAllInProgress((EcuM_KillAllInProgressType)(EcuM_GetKillAllInProgress() | mask));

  /* #31 Remove the run request flags for each user. */
  for (user = 0u; user < EcuM_GetSizeOfUserTable(); user++)
  {
    EcuM_SetUserTable(user, (EcuM_UserType)(EcuM_GetUserTable(user) & (EcuM_UserType)(~mask))); /* SBSW_ECUM_ACCESSUSERTABLE */
  }

  if (mask == ECUM_USER_REQUEST_RUN_MASK)
  {
    EcuM_SetRunRequestCounter(0u);

    /* #33 Clear all wake-up events which are relevant to keep the ECU awake. */
    EcuM_InternalClearWakeupEvent( ECUM_WKSOURCE_ALL_SOURCES);

    if ( EcuM_GetModuleState() == ECUM_STATE_APP_RUN)
    {
      /* #35 In case of EcuM in state run, stop the EcuM self run request timeout. */
      EcuM_SetTimer((uint16)ECUM_TIMER_EXPIRED);
    }

    /* #40 Report to the Dem that all RunRequests are killed - If the corresponding Dem event is configured. */
# if defined(ECUM_E_ALL_RUN_REQUESTS_KILLED)
    Dem_ReportErrorStatus(ECUM_E_ALL_RUN_REQUESTS_KILLED, DEM_EVENT_STATUS_FAILED);
# endif
  }
  else
  {
    EcuM_SetPostRunRequestCounter(0u);
  }

}
#endif

#if((ECUM_MODE_HANDLING == STD_ON) || (ECUM_FIXED_BEHAVIOR == STD_ON))
/***********************************************************************************************************************
 *  EcuM_InternalRequestRUN
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalRequestRUN(uint8 ApiId, EcuM_UserType User, uint8 mask)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_INVALID_PAR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check the EcuM state and if the passed user parameter is valid. */
# if(ECUM_USERTABLE == STD_ON)
#  if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (EcuM_GetModuleState() <= ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else if (User >= EcuM_GetSizeOfUserTable())
  {
    /* error ECUM_E_INVALID_PAR is already set during initialization */
  }
  else
#  endif
  {
    /* #21 Check if the user has already RUN state requested. */
    if ((EcuM_GetUserTable(User) & (EcuM_UserType) mask) != (EcuM_UserType) 0u)
    {
      /* User has already request run: report error over DET */
      errorId = ECUM_E_MULTIPLE_RUN_REQUESTS;
    }

#  if(ECUM_FIXED_BEHAVIOR == STD_ON)
    /* #22 Check if KillAll is in progress. */
    else if ((EcuM_GetKillAllInProgress() & mask) != 0u)
    {
      /* killall is in progress, don't allow new RUN requests */
    }
#  endif

    else
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Set the users run requested flag and increment the counter. */
      EcuM_SetUserTable(User, (EcuM_UserType)(EcuM_GetUserTable(User) | (EcuM_UserType)mask)); /* SBSW_ECUM_ACCESSUSERTABLE */

      if ((mask & (uint8) ECUM_USER_REQUEST_RUN_MASK) != 0u)
      {
#  if(ECUM_MODE_HANDLING == STD_ON)
        if(EcuM_GetRunRequestCounter() == 0u)
        {
          /* In case of no run request was active before, notify the BswM about the requested run state. */
          BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN, ECUM_RUNSTATUS_REQUESTED);
        }
#  endif

        EcuM_IncRunRequestCounter();
      }
      else
      {
#  if(ECUM_MODE_HANDLING == STD_ON)
        if(EcuM_GetPostRunRequestCounter() == 0u)
        {
          /* In case of no post run request was active before, notify the BswM about the requested post run state. */
          BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN, ECUM_RUNSTATUS_REQUESTED);
        }
# endif

        EcuM_IncPostRunRequestCounter();
      }
      retval = E_OK;
      errorId = ECUM_E_NO_ERROR;
    }
  }
# else
  ECUM_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ECUM_DUMMY_STATEMENT(User); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ECUM_DUMMY_STATEMENT(mask); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  /* ----- Development Error Report --------------------------------------- */
# if (ECUM_DEV_ERROR_REPORT == STD_ON)
#  if(ECUM_USERTABLE == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
#  endif
  {
    EcuM_Det_ReportError(ApiId, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ECUM_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/***********************************************************************************************************************
 *  EcuM_InternalReleaseRUN
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ECUM_LOCAL FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalReleaseRUN(uint8 ApiId, EcuM_UserType User, uint8 mask)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_INVALID_PAR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check the EcuM state and if the passed user parameter is valid. */
# if(ECUM_USERTABLE == STD_ON)
#  if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (EcuM_GetModuleState() <= ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }

  else if (User >= EcuM_GetSizeOfUserTable())
  {
    /* error ECUM_E_INVALID_PAR is already set during initialization */
  }
  else
#  endif
  {
    /* #21 Check that the user has not already RUN state requested. */
    if ((EcuM_GetUserTable(User) & (EcuM_UserType) mask) == (EcuM_UserType) 0u)
    {
      /* User has not request run: report error over DET */
      errorId = ECUM_E_MISMATCHED_RUN_RELEASE;
    }
    else
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Clear the users run requested flag and decrement the counter. */
      EcuM_SetUserTable(User, (EcuM_UserType)(EcuM_GetUserTable(User) & (EcuM_UserType)(~mask))); /* SBSW_ECUM_ACCESSUSERTABLE */

      if ((mask & (uint8) ECUM_USER_REQUEST_RUN_MASK) != 0u)
      {
#  if(ECUM_MODE_HANDLING == STD_ON)
        if(EcuM_GetRunRequestCounter() == 1u)
        {
          /* In case that the last run request was released, notify the BswM about the released run state. */
          BswM_EcuM_RequestedState(ECUM_STATE_APP_RUN, ECUM_RUNSTATUS_RELEASED);
        }
#  endif
        EcuM_DecRunRequestCounter();
      }
      else
      {
#  if(ECUM_MODE_HANDLING == STD_ON)
        if(EcuM_GetPostRunRequestCounter() == 1u)
        {
          /* In case that the last post run request was released, notify the BswM about the released post run state. */
          BswM_EcuM_RequestedState(ECUM_STATE_APP_POST_RUN, ECUM_RUNSTATUS_RELEASED);
        }
#  endif
        EcuM_DecPostRunRequestCounter();
      }
      retval = E_OK;
      errorId = ECUM_E_NO_ERROR;
    }
  }
# else
  ECUM_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ECUM_DUMMY_STATEMENT(User); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ECUM_DUMMY_STATEMENT(mask); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  /* ----- Development Error Report --------------------------------------- */
# if (ECUM_DEV_ERROR_REPORT == STD_ON)
#  if(ECUM_USERTABLE == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
#  endif
  {
    EcuM_Det_ReportError(ApiId, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  ECUM_DUMMY_STATEMENT(ApiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if(ECUM_MODE_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  EcuM_InternalRteFeedbackCheck
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
ECUM_LOCAL_INLINE FUNC(void, ECUM_CODE) EcuM_InternalRteFeedbackCheck(void)
{
  if(EcuM_RteStateBuffer != RTE_TRANSITION_EcuM_Mode)
  {
    ECUM_RTE_SWITCH(EcuM_RteStateBuffer);
    EcuM_RteStateBuffer = RTE_TRANSITION_EcuM_Mode;
  }

  if (Rte_SwitchAck_EcuM_currentMode_currentMode() != RTE_E_NO_DATA)
  {
    EcuM_SetBswMCurrentModuleState(EcuM_GetBswMRequestedModuleState());
    BswM_EcuM_CurrentState(EcuM_GetBswMCurrentModuleState());
  }
}
#endif

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
#if((ECUM_MODE_HANDLING == STD_ON) || (ECUM_FIXED_BEHAVIOR == STD_ON))
/***********************************************************************************************************************
 *  EcuM_RequestRUN
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN(EcuM_UserType User) /* PRQA S 1330 */ /* MD_EcuM_1330 */
{
  return EcuM_InternalRequestRUN( ECUM_SID_REQUEST_RUN, User, ECUM_USER_REQUEST_RUN_MASK);
} /* End of EcuM_RequestRUN() */

/***********************************************************************************************************************
 *  EcuM_ReleaseRUN
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN(EcuM_UserType User) /* PRQA S 1330 */ /* MD_EcuM_1330 */
{
  return EcuM_InternalReleaseRUN( ECUM_SID_RELEASE_RUN, User, ECUM_USER_REQUEST_RUN_MASK);
} /* End of EcuM_ReleaseRUN() */

/***********************************************************************************************************************
 *  EcuM_RequestPOST_RUN
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN(EcuM_UserType User) /* PRQA S 1330 */ /* MD_EcuM_1330 */
{
  return EcuM_InternalRequestRUN( ECUM_SID_REQUEST_POST_RUN, User, ECUM_USER_REQUEST_POST_RUN_MASK);
} /* End of EcuM_RequestPOST_RUN() */

/***********************************************************************************************************************
 *  EcuM_ReleasePOST_RUN
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN(EcuM_UserType User) /* PRQA S 1330 */ /* MD_EcuM_1330 */
{
  return EcuM_InternalReleaseRUN( ECUM_SID_RELEASE_POST_RUN, User, ECUM_USER_REQUEST_POST_RUN_MASK);
} /* End of EcuM_ReleasePOST_RUN() */
#endif /* ((ECUM_MODE_HANDLING == STD_ON) || (ECUM_FIXED_BEHAVIOR == STD_ON)) */

#if(ECUM_MODE_HANDLING == STD_ON)
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_SetState(EcuM_StateType state)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  Rte_ModeType_EcuM_Mode mode = 0;

  /* ----- Development Error Checks ------------------------------------- */
  /* Check the EcuM state. */
# if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (EcuM_GetModuleState() <= ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else if ((EcuM_GetBswMCurrentModuleState() != EcuM_GetBswMRequestedModuleState())
        && (state != EcuM_GetBswMRequestedModuleState()))
  {
    errorId = ECUM_E_INVALID_STATEREQUEST;
  }
  else
# endif
  {
    /* #21 Check if the passed parameter state is in a valid range and map it to the corresponding mode.
     *     In case of passed parameter ECUM_STATE_SHUTDOWN or ECUM_STATE_SLEEP the mode which fits to the current
     *     shutdown target is used as mode parameter. */
    switch (state)
    {
      case ECUM_STATE_STARTUP:
      mode = RTE_MODE_EcuM_Mode_STARTUP;
      break;

      case ECUM_STATE_APP_RUN:
      mode = RTE_MODE_EcuM_Mode_RUN;
      break;

      case ECUM_STATE_APP_POST_RUN:
      mode = RTE_MODE_EcuM_Mode_POST_RUN;
      break;

      case ECUM_STATE_SHUTDOWN:
        /* Fall through because SHUTDOWN and SLEEP are handled in the same way. */

      case ECUM_STATE_SLEEP:
      if(EcuM_CurrentShutdownTarget == ECUM_STATE_SLEEP)
      {
        mode = RTE_MODE_EcuM_Mode_SLEEP;
      }
      else
      {
        mode = RTE_MODE_EcuM_Mode_SHUTDOWN;
      }
      break;

      default:
      errorId = ECUM_E_STATE_PAR_OUT_OF_RANGE;
      ECUM_DUMMY_STATEMENT(mode); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
      break;
    }
    if (errorId == ECUM_E_NO_ERROR)
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Store the passed mode to notify the Rte during next MainFunction about the mode switch. */
      EcuM_RteStateBuffer = mode;

      
      EcuM_SetBswMRequestedModuleState(state);
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_SET_STATE, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* PRQA S 6030 */ /* MD_MSR_STCYC */
#endif

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
/***********************************************************************************************************************
 *  EcuM_KillAllRUNRequests
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_KillAllRUNRequests(void)
{
  EcuM_InternalKillAllRequests(ECUM_USER_REQUEST_RUN_MASK);
}

/***********************************************************************************************************************
 *  EcuM_KillAllPostRUNRequests
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_KillAllPostRUNRequests(void)
{
  EcuM_InternalKillAllRequests(ECUM_USER_REQUEST_POST_RUN_MASK);
}
#endif /* ECUM_FIXED_BEHAVIOR == STD_ON */

/***********************************************************************************************************************
 *  EcuM_MainFunction
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_MainFunction(void)
{
  /* ----- Local Variables ---------------------------------------------- */
#if(ECUM_FIXED_BEHAVIOR == STD_ON)
  EcuM_StateType lastState;
#endif

#if(ECUM_NUMBER_OF_CORES > 1u)
  CoreIdType coreID = GetCoreID();

# if(ECUM_PARTITIONINIT == STD_ON)
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
  EcuM_SizeOfPartitionInitType applicationIdx = EcuM_InternalGetPartitionIdx();
#  endif
# endif

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 In case of a multi core ECU: Check if the returned coreId is invalid. If it is invalid, call the EcuM_ErrorHook. */
# if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (coreID >= EcuM_GetSizeOfCoreStatus())
  {
    EcuM_ErrorHook(ECUM_E_HOOK_INVALID_COREID);
  }
  else
# endif

    /* ----- Implementation ----------------------------------------------- */

    if ((coreID == ECUM_CORE_ID_BSW)
# if(ECUM_PARTITIONINIT == STD_ON)
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
      && (applicationIdx < EcuM_GetSizeOfPartitionInit())
      && (EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
#  endif
# endif
      )
    {
#endif

#if(ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON || ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
      /* #30 Check for buffered ComM notifications and if existent, notify them to ComM. */
      if (EcuM_ComM_BufferedWakeups != 0u)
      {
        EcuM_InternalComMNotifications();
      }
#endif

#if ( ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON )
      /* #31 Check for occurred wakeup events and if existent, perform the wakeup validation procedure. */
      if ((ECUM_COMBINEDPENDINGWAKEUPS != ECUM_WKSOURCE_NONE)
# if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
          || (EcuM_ClearedPendingWakeups != ECUM_WKSOURCE_NONE)
# endif
      )
      {
        EcuM_InternalWakeupValidation();
      }

#endif

#if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON) || (ECUM_SLEEPMODELIST == STD_ON)

# if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
      if(EcuM_BswM_BufferedWakeups != 0u)

      {
        EcuM_InternalBswMNotifications();
      }
# endif

# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
#  if (ECUM_SLEEPMODELIST == STD_ON)
#   if (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)

      /* #40 Only in case of EcuM Flex: Check if the module is in state WAKEUP_VALIDATION. */
      if ( EcuM_GetModuleState() == ECUM_STATE_WAKEUP_VALIDATION)
      {
        if (EcuM_ValidatedWakeups != 0u)
        {
          /* #42 Disable all sources that were active during the last sleepmode. */
          EcuM_DisableWakeupSources(EcuM_EnabledWakeups);

          /* #43 Notify the BswM about the disabling of wakeup sources (ECUM_WKSTATUS_NONE). */
          BswM_EcuM_CurrentWakeup(EcuM_EnabledWakeups & (~ECUM_COMBINEDWAKEUPS), ECUM_WKSTATUS_NONE);
          EcuM_EnabledWakeups = 0u;

          /* #44 Set the EcuM Flex module state to APP_RUN. */
          EcuM_SetModuleState(ECUM_STATE_RUN);
        }

        /* In case that the EcuM has detected an expired wakeup source, the BswM is responsible to set the EcuM in a
         * sleep mode again */
      }

#   endif /* (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON) */
#  endif /* (ECUM_SLEEPMODELIST == STD_ON) */
# endif /* (ECUM_FIXED_BEHAVIOR != STD_ON) */
#endif

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
      /* #51 Decrement the EcuM_Timer in each MainFunction. EcuM_Timer is used for NvM or for Self Run Request Timeout. */
      if ((EcuM_GetTimer() != ECUM_TIMER_NOT_SET) && (EcuM_GetTimer() > ECUM_TIMER_EXPIRED))
      {
        EcuM_DecTimer();
      }

      /* #52 Call the state machine as long as a state change is performed. */
      do
      {
        lastState = EcuM_GetModuleState();
        EcuM_Statemachine();
      }
      while (lastState != EcuM_GetModuleState());
#endif

#if(ECUM_MODE_HANDLING == STD_ON)
      if(EcuM_GetBswMCurrentModuleState() != EcuM_GetBswMRequestedModuleState())
      {
        EcuM_InternalRteFeedbackCheck();
      }
#endif

#if(ECUM_NUMBER_OF_CORES > 1u) 
    } /* (GetCoreID() >= ECUM_CORE_ID_BSW) */
    else
    {
# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
      if ((EcuM_GetModuleState() == ECUM_STATE_GO_OFF_ONE)
#  if(ECUM_SLEEPMODELIST == STD_ON)
          || (EcuM_GetModuleState() == ECUM_STATE_GO_SLEEP)
#  endif
      )
# elif (ECUM_SLEEPMODELIST == STD_ON)
    if ((EcuM_GetModuleState() == ECUM_STATE_GO_SLEEP)
        || (EcuM_GetModuleState() == ECUM_STATE_SLEEP))
# endif
      {
# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
        /* #60 In case of EcuM Flex: Handle the complete shutdown process for a slave core. */
        (void) EcuM_GoToSelectedShutdownTarget();
# elif (ECUM_SLEEPMODELIST == STD_ON)
        /* #61 In case of EcuM Fixed: Handle the sleep sequence for a slave core. */
        (void)EcuM_EnterSleepOnSlave(coreID);
# endif
      }
    }
#endif
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/***********************************************************************************************************************
 *  EcuM_Init
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_Init(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;

#if(ECUM_NUMBER_OF_CORES > 1u)
  CoreIdType coreID = GetCoreID();
#endif

#if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
  /* Only call GetCoreID in the case of a multicore System */
# if(ECUM_NUMBER_OF_CORES > 1u)
  if (coreID == ECUM_CORE_ID_STARTUP)
# endif
  {
    /* #20 Initialize the global config pointer prior the call of EcuM_DeterminePbConfiguration for usage in DriverInitZero. */
    ECUM_GLOBAL_CFG_PTR = ECUM_FIRST_CONFIG_STRUCTURE;
  }
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if(ECUM_NUMBER_OF_CORES > 1u)
  /* #21 Check if the returned coreId is a valid one. */
# if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (coreID >= EcuM_GetSizeOfCoreStatus())
  {
    EcuM_ErrorHook(ECUM_E_HOOK_INVALID_COREID);
  }
  /* Runtime check that configured Bsw Core Id fits into CoreStatus Array */
  else if (ECUM_CORE_ID_BSW >= EcuM_GetSizeOfCoreStatus())
  {
    errorId = ECUM_E_INVALID_GEN_DATA;
  }
  else
# endif
#endif
  {
  /* ----- Implementation ----------------------------------------------- */
#if(ECUM_NUMBER_OF_CORES > 1u)
    if (coreID == ECUM_CORE_ID_BSW)
#endif
    {
#if ((ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON) || (ECUM_REASONOFWAKEUPSOURCELIST == STD_ON) \
  || (ECUM_FIXED_BEHAVIOR == STD_ON) || (ECUM_MODE_HANDLING == STD_ON))
      uint8_least loopCount;
#endif

      /* Set the current state of the EcuM to STARTUP */
      EcuM_SetModuleState(ECUM_STATE_STARTUP);

      /* #30 Set the interrupts on ECUs with programmable interrupts (EcuM_AL_SetProgrammableInterrupts). */
      EcuM_AL_SetProgrammableInterrupts();

      /* #31 Initialize BSW that do not use PostBuild parameters (DriverInitListZero). */
      ECUM_DRIVERINITLIST_ZERO();

#if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
      /* #32 Determine the current configuration variant and set the global config pointer. */
# if(ECUM_NUMBER_OF_CORES > 1u)
      if(coreID == ECUM_CORE_ID_STARTUP) /* PRQA S 2991, 2992, 2995, 2996 */ /* MD_EcuM_2991_2992_2995_2996 */ /* COV_ECUM_COREID_STARTUP */
# endif
      {
        EcuM_InternalDeterminePbConfiguration(); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      }
#endif /* ((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON)) */

      /* Clear wakeups from all sources */
      EcuM_InternalClearWakeupEvent( ECUM_WKSOURCE_ALL_SOURCES);

#if(ECUM_SLEEPMODELIST == STD_ON)
      EcuM_EnabledWakeups = 0u;
#endif

#if (ECUM_SHUTDOWNCAUSECOUNT != 0u)
      EcuM_ShutdownCause = EcuMConf_EcuMShutdownCause_ECUM_CAUSE_UNKNOWN;
#endif

      EcuM_CurrentBootTarget = ECUM_BOOT_TARGET_OEM_BOOTLOADER;

#if (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)

# if(ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
      /* Clear also all ClearedPendingWakeups in case of active WakeupValidationList */
      EcuM_ClearedPendingWakeups = 0u;
# endif

      /* Reset all wakeup validation timeouts */
      for (loopCount = 0u; loopCount < EcuM_GetSizeOfWakeupSourceList(); loopCount++)
      {
        EcuM_SetValidationTimeoutTable(loopCount, ECUM_NO_VALIDATION_TIMEOUT); /* SBSW_ECUM_ACCESSVALTABLE */
      }
#endif

      /* Set the current state of the EcuM */
      EcuM_SetModuleState(ECUM_STATE_STARTUP_ONE);

#if (ECUM_FIXED_BEHAVIOR == STD_ON)
      EcuM_SetTimer(ECUM_TIMER_NOT_SET);

      EcuM_SetKillAllInProgress(0u);

# if(ECUM_SUPPORT_DEM == STD_ON)
      EcuM_SetDemStatus(ECUM_DEM_INITIALIZED);
# endif

# if(ECUM_INCLUDE_NVRAM_MGR == STD_ON)
      EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_IDLE);
# endif
#endif

#if ((ECUM_FIXED_BEHAVIOR == STD_ON) || (ECUM_MODE_HANDLING == STD_ON))
      EcuM_SetRunRequestCounter(0u);
      EcuM_SetPostRunRequestCounter(0u);
# if(ECUM_USERTABLE == STD_ON)
      for (loopCount = 0u; loopCount < EcuM_GetSizeOfUserTable(); loopCount++)
      {
        EcuM_SetUserTable(loopCount, 0u); /* SBSW_ECUM_ACCESSUSERTABLE */
      }
# endif
#endif

#if(ECUM_MODE_HANDLING == STD_ON)
      /* Initialize the Requested state with shutdown to be different to the requested state. */
      EcuM_SetBswMCurrentModuleState(ECUM_STATE_SHUTDOWN);
      /* Initialize the Requested state with startup to begin RTE synchronization directly after initialization. */
      EcuM_SetBswMRequestedModuleState(ECUM_STATE_STARTUP);
      /* Initialize the RteStateBuffer state with RTE_TRANSITION_EcuM_Mode to begin RTE synchronization directly after initialization. */
      EcuM_RteStateBuffer = RTE_TRANSITION_EcuM_Mode;
#endif


      /* #34 Initialize BSW that use PostBuild parameters (DriverInitListOne). */
      ECUM_DRIVERINITLIST_ONE(); /* SBSW_ECUM_FUNCTIONPOINTER_CALL */

      /* Reset all AlarmClocks if the Feature is enabled */
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)

      /* Initialize the Clock only in the case that RAM content is not available after startup */
      if ((EcuM_IntendedRestartID_One != ECUM_MAGIC_ONE) || (EcuM_IntendedRestartID_Two != ECUM_MAGIC_TWO)) /* COV_ECUM_RESTARTID */
      {
        EcuM_Clock = 0u;
      }

      EcuM_InternalClearAlarms();

      /* Initialize the EcuM_MasterAlarm that stores the information about the next alarm clock time */
      EcuM_MasterAlarm = 0xFFFFFFFFu;

#endif /* #if(ECUM_ALARM_CLOCK_PRESENT == STD_ON) */

#if(ECUM_REASONOFWAKEUPSOURCELIST == STD_ON)
      /* #50 Map the Mcu reset reason from the last occurred shutdown. */
      {
        VAR(Mcu_ResetType, AUTOMATIC) resetReason;

        resetReason = Mcu_GetResetReason();

        for (loopCount = 0u; loopCount < EcuM_GetSizeOfWakeupSourceList(); loopCount++)
        {
          /* Determine a wakeup source that fits to the MCU wakeup source that is responsible for the reset */
          if ((EcuM_GetReasonOfWakeupSourceList(loopCount)) == resetReason)
          {
            /* Set this wakeup source as a validated wakeup event */
            EcuM_ValidatedWakeups |= (((EcuM_WakeupSourceType)1u << (EcuM_WakeupSourceType)loopCount));

            /* Store this source in the BufferedWakeups to validate it at the end of EcuM_StartupTwo */
            EcuM_BswM_BufferedWakeups |= (((EcuM_WakeupSourceType)1u << (EcuM_WakeupSourceType)loopCount));
            break;
          }
          /* If Hardware can not detect a specific wakeup source, the source ECUM_WKSOURCE_RESET shall be reported. */
          if (loopCount == (EcuM_GetSizeOfWakeupSourceList() - 1u))
          {
            EcuM_ValidatedWakeups |= ECUM_WKSOURCE_RESET;

            /* Store this source in the BufferedWakeups to validate it at the end of EcuM_StartupTwo */
            EcuM_BswM_BufferedWakeups |= ECUM_WKSOURCE_RESET;
          }
        }
      }

#else
      EcuM_ValidatedWakeups |= ECUM_WKSOURCE_RESET;

      /* Store this source in the BufferedWakeups to validate it at the end of EcuM_StartupTwo */
      EcuM_BswM_BufferedWakeups |= ECUM_WKSOURCE_RESET;
#endif

      /* Select the shutdown target to the configured default shutdowntarget
       The current state is not a legal state for the API EcuM_SelectShutdownTarget. To avoid errors at the uninit check,
       the global variables must be set directly at this place. */

      EcuM_CurrentShutdownTarget = EcuM_GetDefaultShutdownTarget();
      EcuM_CurrentShutdownMode = EcuM_GetDefaultShutdownMode();
    }
#if (ECUM_NUMBER_OF_CORES > 1u)
    else
    {
      /* #40 Call DriverInitListZero also on a slave core to initialize BSW that do not use PostBuild parameters. */
      ECUM_DRIVERINITLIST_ZERO();

# if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
      if(coreID == ECUM_CORE_ID_STARTUP) /* PRQA S 2992, 2996 */ /* MD_EcuM_2991_2992_2995_2996 */ /* COV_ECUM_COREID_STARTUP */ 
      {
        EcuM_InternalDeterminePbConfiguration(); /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      }
# endif /* ((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON)) */
      /* #41 Call DriverInitListOne also on a slave core to initialize BSW that use PostBuild parameters.  */
      ECUM_DRIVERINITLIST_ONE(); /* SBSW_ECUM_FUNCTIONPOINTER_CALL */
    }
#endif

#if (ECUM_SLAVE_CORE_HANDLING == STD_ON)
    EcuM_SetCoreStatusValue(coreID, ECUM_CORESTATUS_RUN); /* SBSW_SETCORESTATUS_OSCOREID */
#endif

    /* #51 Start the AUTOSAR OS with the corresponding default appMode. */
    EcuM_StartOS( EcuM_GetDefaultAppMode());
  }

  /* ----- Development Error Report --------------------------------------- */
#if((ECUM_DEV_ERROR_REPORT == STD_ON) && (ECUM_NUMBER_OF_CORES > 1u))
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_INIT, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/***********************************************************************************************************************
 *  EcuM_Shutdown
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_Shutdown(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if(ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() != ECUM_STATE_GO_OFF_ONE)
  {
    errorId = ECUM_E_MODULE_NOT_IN_PREPSHUTDOWN;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set the current state of the EcuM to ECUM_STATE_GO_OFF_TWO. */
    EcuM_SetModuleState(ECUM_STATE_GO_OFF_TWO);

    /* #21 Execute user-specific code shortly before shutdown (EcuM_OnGoOffTwo()). */
    EcuM_OnGoOffTwo();

    /* #22 Save the value of the current shutdown target for usage after a restart. */
    EcuM_LastShutdownTarget = EcuM_CurrentShutdownTarget;
    EcuM_LastShutdownMode = EcuM_CurrentShutdownMode;

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
    /* #23 Set an internal variable to indicate after a restart that RAM content is still available. */
    EcuM_IntendedRestartID_One = (uint8) ECUM_MAGIC_ONE;
    EcuM_IntendedRestartID_Two = (uint8) ECUM_MAGIC_TWO;
#endif

    /* #30 Differ between shutdown targets. */
    switch (EcuM_CurrentShutdownTarget)
    {
      case ECUM_STATE_RESET:
        /* #31 Call EcuM_AL_Reset in case of shutdown Target ECUM_STATE_RESET. */
        EcuM_AL_Reset(EcuM_CurrentShutdownMode);
        break;

      case ECUM_STATE_OFF:
        /* #32 Call EcuM_AL_SwitchOff in case of shutdown Target ECUM_STATE_OFF. */
        EcuM_AL_SwitchOff();
        break;

      default: /* COV_ECUM_03 */
        /* #33 Call the Det in the case of ECUM_STATE_SLEEP or any else wrong parameter. */
        errorId = ECUM_E_STATE_PAR_OUT_OF_RANGE;
        break;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_SHUTDOWN, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/***********************************************************************************************************************
 *  EcuM_SelectShutdownTarget
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget(VAR(EcuM_StateType, AUTOMATIC) targetState,
VAR(EcuM_ModeType, AUTOMATIC) resetSleepMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  Std_ReturnType retval;

  /* ----- Development Error Checks ------------------------------------- */
  /* #21 Check the current state of the EcuM. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ((EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO) || (EcuM_GetModuleState() > ECUM_STATE_APP_RUN))
  {
    errorId = ECUM_E_MODULE_NOT_IN_RUN_STATE;
    retval = E_NOT_OK;
  }
  else
  /* #22 Check if the parameters targetState and resetSleepMode are in a valid range.  */
  /* if (STATE == RESET AND ResetMode in Range) OR
   *     STATE == SLEEP AND SleepMode in Range) OR
   *     STATE == OFF)
   */
#endif
  if (
      /* Check for a valid state parameter */
      ((targetState != (EcuM_StateType) ECUM_STATE_OFF) && (targetState != (EcuM_StateType) ECUM_STATE_RESET)
          && (targetState != (EcuM_StateType) ECUM_STATE_SLEEP))
#if(ECUM_RESETMODECOUNT != 0u)
      ||
      /* Check for a valid reset mode parameter */
      ((targetState == (EcuM_StateType) ECUM_STATE_RESET) && (resetSleepMode >= ECUM_RESETMODECOUNT))
#endif
#if(ECUM_SLEEPMODELIST == STD_ON)
      ||
      /* Check for a valid sleep mode parameter */
      ((targetState == (EcuM_StateType) ECUM_STATE_SLEEP) && (resetSleepMode >= EcuM_GetSizeOfSleepModeList()))
# if(ECUM_VALIDOFSLEEPMODELIST == STD_ON)
      ||
      /* Check if this sleep mode is active in this variant */
      (!EcuM_IsValidOfSleepModeList(resetSleepMode))
# endif
#endif
  )
  {
    errorId = ECUM_E_STATE_PAR_OUT_OF_RANGE;
    retval = E_NOT_OK;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Set the state of the current shutdown target. */
    EcuM_CurrentShutdownTarget = targetState;

    if (targetState == ECUM_STATE_OFF)
    {
      /* #31 In case of ECUM_STATE_OFF ignore the resetSleepMode parameter and set the current shutdown mode to 0. */
      EcuM_CurrentShutdownMode = 0u;
    }
    else
    {
      /* #32 In case of ECUM_STATE_SLEEP / ECUM_STATE_RESET set the current shutdown mode to parameters value. */
      EcuM_CurrentShutdownMode = resetSleepMode;
    }

    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_SELECT_SHUTDOWN_TARGET, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetShutdownTarget
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget(
P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) target,
P2VAR(EcuM_ModeType, AUTOMATIC, ECUM_APPL_DATA) resetSleepMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #21 Check the current state of the EcuM. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if(EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  /* #22 Check that the passed parameters are not NULL_PTR. */
  if ((NULL_PTR == target) || (NULL_PTR == resetSleepMode))
  {
    errorId = ECUM_E_NULL_POINTER;
  }
  else
  {
    /* #30 Store the current shutdown target and current resetSleepMode in the passed parameters. */
    /* ----- Implementation ----------------------------------------------- */
    /* Set the target parameter to the value of the current shutdown target */
    *target = EcuM_CurrentShutdownTarget;  /* SBSW_ECUM_POINTERACCESS_SHUTDOWNTARGET */
    /* Reset and Sleep share the same variable for the selected mode. In case of ECUM_STATE_OFF the variable was set to 0 */
    *resetSleepMode = EcuM_CurrentShutdownMode;  /* SBSW_ECUM_POINTERACCESS_SHUTDOWNTARGET */

    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_SHUTDOWN_TARGET, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetLastShutdownTarget
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget(P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) target,
P2VAR(EcuM_ModeType, AUTOMATIC, ECUM_APPL_DATA) resetSleepMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #21 Check the current state of the EcuM. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if(EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  /* #22 Check that the passed parameters is not a NULL_PTR. */
  if ((NULL_PTR == target) || (NULL_PTR == resetSleepMode))
  {
    errorId = ECUM_E_NULL_POINTER;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Return the values of last shutdown target and mode. */
    /* Set the target parameter to the value of the current ShutdownTarget */
    *target = EcuM_LastShutdownTarget;  /* SBSW_ECUM_POINTERACCESS_SHUTDOWNTARGET */
    /* Reset and Sleep share the same variable for the selected mode. In case of ECUM_STATE_OFF the variable was set to 0 */
    *resetSleepMode = EcuM_LastShutdownMode;  /* SBSW_ECUM_POINTERACCESS_SHUTDOWNTARGET */

    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if(errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_LAST_SHUTDOWN_TARGET, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_SelectShutdownCause
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause(VAR(EcuM_ShutdownCauseType, AUTOMATIC) shutdownCause)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_INVALID_PAR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
#if (ECUM_SHUTDOWNCAUSECOUNT != 0u)
  /* ----- Implementation ----------------------------------------------- */
  /* #21 Check if the given cause parameter is in the range of configured shutdown causes. */
  if (shutdownCause < ECUM_SHUTDOWNCAUSECOUNT)
  {

    /* #30 Set the EcuM_ShutdownCause variable to the value of the parameter cause. */
    EcuM_ShutdownCause = shutdownCause;
    retval = E_OK;
    errorId = ECUM_E_NO_ERROR;
  }
#else
  ECUM_DUMMY_STATEMENT(shutdownCause); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
# if (ECUM_SHUTDOWNCAUSECOUNT != 0u)
  if (errorId != ECUM_E_NO_ERROR)
# endif
  {
    EcuM_Det_ReportError(ECUM_SID_SELECT_SHUTDOWN_CAUSE, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetShutdownCause
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause(P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause) /* PRQA S 3673 */ /* MD_EcuM_3673 */
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_INVALID_PAR; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
#if (ECUM_SHUTDOWNCAUSECOUNT != 0u)
# if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if(EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
# endif
  /* #21 Check that the passed parameter is not a NULL_PTR. */
  if(NULL_PTR == shutdownCause)
  {
    errorId = ECUM_E_NULL_POINTER;
  }
  else
  {
    /* #30 Set the pointer to EcuM_ShutdownCause and set the return value E_OK. */
    *shutdownCause = EcuM_ShutdownCause; /* SBSW_ECUM_POINTERACCESS_SHUTDOWNCAUSE */
    retval = E_OK;
    errorId = ECUM_E_NO_ERROR;
  }
#endif
  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
# if (ECUM_SHUTDOWNCAUSECOUNT != 0u)
  if (errorId != ECUM_E_NO_ERROR)
# endif
  {
    /* #40 If an error has occurred, call the Det with the corresponding errorId. */
    EcuM_Det_ReportError(ECUM_SID_GET_SHUTDOWN_CAUSE, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

#if (ECUM_SHUTDOWNCAUSECOUNT == 0u)
  ECUM_DUMMY_STATEMENT(shutdownCause); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetPendingWakeupEvents
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  EcuM_WakeupSourceType retval = ECUM_WKSOURCE_NONE; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #20 Check if the module is initialized. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_ONE)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* Access must be done in a critical area because the Validated Wakeups can change while the possible non-atomic 
     access on the EcuM_PendingWakeups */
    EcuM_EnterAtomicAccess_0();

    /* #31 Set the pending wakeups as return value. */
    retval = EcuM_PendingWakeups;

    EcuM_LeaveAtomicAccess_0();
#endif
  }
  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    /* If an error has occurred, call the Det with the corresponding errorId. */
    EcuM_Det_ReportError(ECUM_SID_GET_PENDING_WAKEUP_EVENTS, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_ClearWakeupEvent
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_ONE)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Disable all Interrupts while this operation to avoid access on this variables, access could be non-atomic. */
    EcuM_EnterCriticalArea_0();

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    EcuM_ClearedPendingWakeups |= (EcuM_PendingWakeups & WakeupSource);
#endif

    EcuM_InternalClearWakeupEvent(WakeupSource);

    if ( EcuM_GetModuleState() > ECUM_STATE_STARTUP_ONE)
    {
      BswM_EcuM_CurrentWakeup(WakeupSource, ECUM_WKSTATUS_NONE);
    }

    /* Restore all Interrupts */
    EcuM_LeaveCriticalArea_0();
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_CLEAR_WAKEUP_EVENT, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/***********************************************************************************************************************
 *  EcuM_ClearValidatedWakeupEvent
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_ClearValidatedWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_ONE)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Disable all Interrupts while accessing EcuM_ValidatedWakeups, access could be non-atomic. */
    EcuM_EnterCriticalArea_0();

    EcuM_ValidatedWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

    /* #31 Clear all passed validated wakeup events and notify them to the BswM, Interrupts has to be still disabled to
     *     avoid inconsistencies. */
#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    BswM_EcuM_CurrentWakeup((WakeupSource & (~EcuM_PendingWakeups)), ECUM_WKSTATUS_NONE);
#else
    BswM_EcuM_CurrentWakeup((WakeupSource), ECUM_WKSTATUS_NONE);
#endif

    /* Restore all Interrupts */
    EcuM_LeaveCriticalArea_0();
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_CLEAR_VALIDATED_WAKEUP_EVENT, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/***********************************************************************************************************************
 *  EcuM_GetValidatedWakeupEvents
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  EcuM_WakeupSourceType retval = ECUM_WKSOURCE_NONE; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
  /* If this routine is called and the module is not initialized, return ECUM_WKSOURCE_NONE */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_ONE)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Disable all Interrupts while accessing EcuM_ValidatedWakeups, access could be non-atomic. */
    EcuM_EnterAtomicAccess_0();

    /* #31 Set the validated wakeups as return value. */
    retval = EcuM_ValidatedWakeups;

    EcuM_LeaveAtomicAccess_0();
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_VALIDATED_WAKEUP_EVENTS, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetExpiredWakeupEvents
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  EcuM_WakeupSourceType retval = ECUM_WKSOURCE_NONE; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_ONE)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
#if (ECUM_TIMEOUTOFWAKEUPSOURCELIST == STD_ON)
    /* #30 Disable all Interrupts while accessing EcuM_ExpiredWakeups, access could be non-atomic. */
    /* Access must be done in  a critical area because the Validated Wakeups can change while the possible non-atomic 
     access on the EcuM_ExpiredWakeups */
    EcuM_EnterAtomicAccess_0();

    /* #31 Set the expired wakeups as return value. */
    retval = EcuM_ExpiredWakeups;

    EcuM_LeaveAtomicAccess_0();
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_EXPIRED_WAKEUP_EVENTS, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

#if (ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
/***********************************************************************************************************************
 *  EcuM_StartCheckWakeup
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 ShiftCount;

  ShiftCount = EcuM_GetShiftCount(WakeupSource);
  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the wakeup source parameter is a single bitmask and in a valid range. */
  if ((((EcuM_WakeupSourceType) 0u) != (((WakeupSource) - ((EcuM_WakeupSourceType) 1u)) & WakeupSource))
      || ((ShiftCount) >= (EcuM_GetMaxWakeupSourceCount()))
# if(ECUM_VALIDOFWAKEUPSOURCELIST == STD_ON)
      || (!EcuM_IsValidOfWakeupSourceList(ShiftCount))
# endif
  )
  {
    errorId = ECUM_E_UNKNOWN_WAKEUP_SOURCE;
  }
  else
  {
    if ( EcuM_GetCheckWakeupTimeOfWakeupSourceList(ShiftCount) > 0u)
    {
      /* #30 Disable all Interrupts while accessing EcuM_PendingCheckWakeups, access could be non-atomic. */
      EcuM_EnterCriticalArea_0();

      /* #31 Mark that the wakeup source has an unapproved CheckWakeup call. */
      EcuM_PendingCheckWakeups |= WakeupSource;

# if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
        EcuM_BswM_BufferedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);
# else
        /* #35 Report the new state of the source to the BswM only in a state where BswM is initialized. */
        if(EcuM_GetModuleState() > ECUM_STATE_STARTUP_TWO)
        {
          BswM_EcuM_CurrentWakeup(WakeupSource, ECUM_WKSTATUS_CHECKWAKEUP);
        }
# endif

      EcuM_LeaveCriticalArea_0();
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if ( errorId != ECUM_E_NO_ERROR )
  {
    EcuM_Det_ReportError( ECUM_SID_START_CHECK_WAKEUP, errorId );
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/***********************************************************************************************************************
 *  EcuM_EndCheckWakeup
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */

FUNC(void, ECUM_CODE) EcuM_EndCheckWakeup(EcuM_WakeupSourceType WakeupSource)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 ShiftCount;

  /* Get the Index of the wakeup source */
  ShiftCount = EcuM_GetShiftCount(WakeupSource);

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the wakeup source parameter is a single bitmask and in a valid range. */
  if ((((EcuM_WakeupSourceType) 0u) != (((WakeupSource) - ((EcuM_WakeupSourceType) 1u)) & WakeupSource))
      || ((ShiftCount) >= (EcuM_GetSizeOfWakeupSourceList()))
# if(ECUM_VALIDOFWAKEUPSOURCELIST == STD_ON)
      || (!EcuM_IsValidOfWakeupSourceList(ShiftCount))
# endif
  )
  {
    errorId = ECUM_E_UNKNOWN_WAKEUP_SOURCE;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    if ( EcuM_GetCheckWakeupTimeOfWakeupSourceList(ShiftCount) != ECUM_NO_VALIDATION_TIMEOUT)
    {
      EcuM_EnterCriticalArea_0();

      /* #31 Remove this wakeup source from the list of unapproved CheckWakeup calls. */
      EcuM_PendingCheckWakeups &= (~WakeupSource);

      /* #32 Notify the wakeup event as an expired source to the BswM, Interrupts has to be still disabled to avoid inconsistencies. */
# if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
        EcuM_ExpiredCheckWakeups |= WakeupSource;
        EcuM_BswM_BufferedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);
# else
        /* #35 Report the new state of the source to the BswM only in a state where BswM is initialized. */
        if(EcuM_GetModuleState() > ECUM_STATE_STARTUP_TWO)
        {
          BswM_EcuM_CurrentWakeup(WakeupSource, ECUM_WKSTATUS_EXPIRED);
        }
# endif
      EcuM_LeaveCriticalArea_0();

      /* #33 Stop the check wakeup timer for this source. */
      EcuM_SetValidationTimeoutTable(ShiftCount, ECUM_NO_VALIDATION_TIMEOUT); /* SBSW_ECUM_ACCESSVALTABLE */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if ( errorId != ECUM_E_NO_ERROR )
  {
    EcuM_Det_ReportError( ECUM_SID_END_CHECK_WAKEUP, errorId );
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

#endif

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
/***********************************************************************************************************************
 *  EcuM_CB_NfyNvMJobEnd
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
# if (ECUM_INCLUDE_NVRAM_MGR ==STD_ON)
FUNC(void, ECUM_CODE) EcuM_CB_NfyNvMJobEnd(uint8 ServiceID, NvM_RequestResultType JobResult)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the module is initialized. */
#  if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (EcuM_GetModuleState() < (EcuM_StateType) ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* dummy assignment to prevent compiler warnings on most of the compilers. */
    ECUM_DUMMY_STATEMENT(JobResult); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

    /* #30 This Callback is only relevant for the service NvM_WriteAll(). */
    if ((uint8) NVM_WRITE_ALL == ServiceID)
    {
      /* #31 In case that the state of NvM is ECUM_NVM_WRITEALL_CANCELED, set the NvM status to required. */
#  if(ECUM_SLEEPMODELIST == STD_ON)
      if ( EcuM_GetNvMWriteAllStatus() == ECUM_NVM_WRITEALL_CANCELED)
      {
        EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_REQUIRED);
      }
      /* #32 In case that the state of NvM is not ECUM_NVM_WRITEALL_CANCELED, set the NvM status to idle. */
      else
#  endif
      {
        EcuM_SetNvMWriteAllStatus(ECUM_NVM_WRITEALL_IDLE);
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#  if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_CB_NFY_NVM_JOB_END, errorId);
  }
#  else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif

  return;
}
# endif

/***********************************************************************************************************************
 *  EcuM_GetStateWrapper
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
/* PRQA S 1330 1 */ /* MD_EcuM_1330 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetStateWrapper(EcuM_UserType user,
    P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) state)
{

  /* dummy assignment to prevent compiler warnings on most of the compilers. */
  ECUM_DUMMY_STATEMENT(user); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return EcuM_GetState(state); /* SBSW_ECUM_POINTERACCESS_STATE */
}

/***********************************************************************************************************************
 *  EcuM_GetState
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetState(P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) state)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  Std_ReturnType retval = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check that the parameter is not a NULL_PTR. */
# if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (NULL_PTR == state)
  {
    errorId = ECUM_E_NULL_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Pass the current state to the pointer. */
    *state = EcuM_GetModuleState(); /* SBSW_ECUM_POINTERACCESS_STATE */
    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_STATE, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retval;
}
#endif

/***********************************************************************************************************************
 *  EcuM_GetBootTarget
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget(P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) BootTarget)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  Std_ReturnType retval = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check init state of the module and that parameter is not a NULL_PTR. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if(EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }

  /* Check if the given pointer is a NULL_POINTER */
  else if(NULL_PTR == BootTarget)
  {
    errorId = ECUM_E_NULL_POINTER;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Pass the current boot target to the pointer. */
    *BootTarget = EcuM_CurrentBootTarget; /* SBSW_ECUM_POINTERACCESS_BOOTTARGET */
    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_BOOT_TARGET, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_SelectBootTarget
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget(VAR(EcuM_BootTargetType, AUTOMATIC) BootTarget)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  Std_ReturnType retval = E_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check init state of the module and that parameter is not a NULL_PTR. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if ( EcuM_GetModuleState() < ECUM_STATE_STARTUP_TWO)
  {
    errorId = ECUM_E_UNINIT;
  }
  else
#endif
  {
    if((BootTarget != ECUM_BOOT_TARGET_APP)            && 
       (BootTarget != ECUM_BOOT_TARGET_OEM_BOOTLOADER) && 
       (BootTarget != ECUM_BOOT_TARGET_SYS_BOOTLOADER))
    {
      errorId = ECUM_E_INVALID_PAR;
    }
    else
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #30 Save the value of the passed parameter as current boot target. */
      EcuM_CurrentBootTarget = BootTarget;
      retval = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_SELECT_BOOT_TARGET, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_StartupTwo
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_StartupTwo(void)
{

#if (((ECUM_FIXED_BEHAVIOR == STD_OFF) && (ECUM_PARTITIONINIT == STD_ON)) || (ECUM_NUMBER_OF_CORES > 1u))
# if(ECUM_PARTITIONINIT == STD_ON)
  EcuM_SizeOfPartitionInitType applicationIdx = EcuM_InternalGetPartitionIdx();
# endif

  if ((GetCoreID() == ECUM_CORE_ID_BSW) 
# if(ECUM_PARTITIONINIT == STD_ON)
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
    && (applicationIdx < EcuM_GetSizeOfPartitionInit())
    && (EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
#  endif
# endif
    )
#endif
  {
    /* ----- Local Variables ---------------------------------------------- */
    uint8 errorId = ECUM_E_NO_ERROR;

    /* ----- Development Error Checks ------------------------------------- */
    /* #20 Check the init state of the module. */
#if(ECUM_DEV_ERROR_DETECT == STD_ON)
    if ( EcuM_GetModuleState() != ECUM_STATE_STARTUP_ONE)
    {
      errorId = ECUM_E_MODULE_NOT_IN_STARTUP;
    }
    else
#endif
    {
      /* ----- Implementation ----------------------------------------------- */

      /* #31 In case the Alarm Clock feature is configured, configure the GPT to run in Normal Mode. */
#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
      EcuM_GptStartClock((Gpt_ChannelType)EcuM_GetGptChannel(), GPT_MODE_NORMAL, (Gpt_ValueType)EcuM_GetGptValue());
#endif

      /* #32 Initialization of the schedule Manager. */
      SchM_Init(ECUM_SCHM_CONFIG_POINTER); /* SBSW_ECUM_FUNCTIONCALL_POINTER */

      /* #33 Initialization of the BswM. */
      BswM_Init(ECUM_BSWM_CONFIG_POINTER); /* SBSW_ECUM_FUNCTIONCALL_POINTER */

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
      EcuM_SetModuleState(ECUM_STATE_STARTUP_TWO);

      /* #34 Initialize BSW that does not need NvM Data (DriverInitListTwo). */
      ECUM_DRIVERINITLIST_TWO(); /* SBSW_ECUM_FUNCTIONPOINTER_CALL */

      /* #35 Execute user-specific code prior the Rte is started (EcuM_OnRTEStartup()). */
      EcuM_OnRTEStartup();

# if(ECUM_SUPPORT_RTE == STD_ON)
      /* #36 Start the AUTOSAR Rte. */
      (void) Rte_Start();
# endif
      /* #37 Initialize BSW that needs NvM Data (DriverInitListThree).*/
      ECUM_DRIVERINITLIST_THREE(); /* SBSW_ECUM_FUNCTIONPOINTER_CALL */

#else
      /* #38 Only relevant for EcuM Flex: From this point the EcuM is in the UP phase. */
      EcuM_SetModuleState(ECUM_STATE_RUN);
#endif

      /* #39 Check if there are wakeups stored in the EcuM_BswM_BufferedWakeups variable and in that case notify them to BswM. */
      EcuM_EnterCriticalArea_0();

      if (EcuM_ValidatedWakeups != 0u)
      {
        BswM_EcuM_CurrentWakeup((EcuM_BswM_BufferedWakeups & EcuM_ValidatedWakeups), ECUM_WKSTATUS_VALIDATED);
        EcuM_BswM_BufferedWakeups &= (~EcuM_ValidatedWakeups);
      }

      EcuM_LeaveCriticalArea_0();

#if(ECUM_FIXED_BEHAVIOR == STD_ON)
      /* #41 Only relevant for EcuM Fixed: Call the EcuM_StateMachine at the end of EcuM_StartupTwo to perform a startup in wakeup Validation or Run State. */
      EcuM_Statemachine();
#endif
    }

    /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
    if (errorId != ECUM_E_NO_ERROR)
    {
      EcuM_Det_ReportError(ECUM_SID_STARTUP_TWO, errorId);
    }
#else
    ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  }

#if (((ECUM_FIXED_BEHAVIOR == STD_OFF) && (ECUM_PARTITIONINIT == STD_ON)) || (ECUM_NUMBER_OF_CORES > 1))
  else
  {
# if (ECUM_PARTITIONINIT == STD_ON)
    if(applicationIdx < EcuM_GetSizeOfPartitionInit())
    {
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
      if(EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
#  endif
      {
        /* #32 Initialization of the schedule Manager. */
        SchM_Init(ECUM_SCHM_CONFIG_POINTER); /* SBSW_ECUM_FUNCTIONCALL_POINTER */
      }

#  if(ECUM_BSWMPARTITIONOFPARTITIONINIT == STD_ON)
#   if(ECUM_ISDEF_BSWMPARTITIONOFPARTITIONINIT == STD_OFF)
      if(EcuM_IsBswMPartitionOfPartitionInit(applicationIdx))
#   endif
      {
        /* #33 Initialization of the BswM. */
        BswM_Init( ECUM_BSWM_CONFIG_POINTER); /* SBSW_ECUM_FUNCTIONCALL_POINTER */
      }
#  endif
# endif

# if(ECUM_FIXED_BEHAVIOR == STD_ON)
    /* #35 Execute user-specific code prior the Rte is started (EcuM_OnRTEStartup()). */
    EcuM_OnRTEStartup();

#  if(ECUM_SUPPORT_RTE == STD_ON)
    /* #36 Start the AUTOSAR Rte. */
    (void)Rte_Start();
#  endif
# endif

# if (ECUM_PARTITIONINIT == STD_ON)
    }
# endif

  }
#endif

} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/***********************************************************************************************************************
 *  EcuM_SetWakeupEvent
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_SetWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 Shiftcount;

  Shiftcount = EcuM_GetShiftCount(WakeupSource);

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the wakeup source parameter is a single bitmask and in a valid range. */
  /* Check if that source is in the field of possible wakeup sources. Additional there is a check that only one bit is set 
   *  if(<Only one wakeup source> AND < WakeupSource is less than MaxWakeupSources>
   */
  if ((((EcuM_WakeupSourceType) 0u) != (((WakeupSource) - ((EcuM_WakeupSourceType) 1u)) & WakeupSource))
      || ((Shiftcount) >= (EcuM_GetMaxWakeupSourceCount()))
#if(ECUM_VALIDOFWAKEUPSOURCELIST == STD_ON)
      || (!EcuM_IsValidOfWakeupSourceList(Shiftcount))
#endif
      )
  {
    /* Throw a DET error if error reporting is active */
    errorId = ECUM_E_UNKNOWN_WAKEUP_SOURCE;
  }
  else
  {
  /* ----- Implementation ----------------------------------------------- */
#if(ECUM_CHECKWAKEUPTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* Enter a critical area to avoid access on this procedure on another context */
    EcuM_EnterCriticalArea_0();

    /* #30 Remove the current source from the pending check wakeup bit mask. */
    EcuM_PendingCheckWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

    EcuM_LeaveCriticalArea_0();
#endif

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* Enter a critical area to avoid access on this procedure on another context */
    EcuM_EnterCriticalArea_0();

    /* #31 Check if WakeupValidation is not already active for that source. */
    if ((EcuM_PendingWakeups & WakeupSource) == 0u)
    {
      EcuM_ClearedPendingWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

      /* #33 Check if validation is configured for that current source.
       * it is not necessary in the following case: - The value of EcuMValidationTimeout is NULL. */
      if ((EcuM_GetValidationTimeOfWakeupSourceList(Shiftcount) != 0u))
      {
        /* #34 Add this source to the global pending wakeups variable. */
        EcuM_PendingWakeups |= WakeupSource;

# if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
        EcuM_BswM_BufferedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);
# else
        /* #35 Report the new state of the source to the BswM only in a state where BswM is initialized. */
        if(EcuM_GetModuleState() > ECUM_STATE_STARTUP_TWO)
        {
          BswM_EcuM_CurrentWakeup(WakeupSource, ECUM_WKSTATUS_PENDING);
        }
# endif

        /* The timer itself is set with the next call of the EcuM_MainFunction */
        EcuM_SetValidationTimeoutTable(Shiftcount, ECUM_NO_VALIDATION_TIMEOUT); /* SBSW_ECUM_ACCESSVALTABLE */

        EcuM_LeaveCriticalArea_0();
      }
      else

#endif
      {
#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
        /* Because in EcuM_ValidatedWakeupEvent a critical section is entered, the section must be left before */
        EcuM_LeaveCriticalArea_0();
#endif

        /* Validation is not necessary for the current source */
        /* #40 Call EcuM_ValidateWakeupEvent directly to validate that source. */
        EcuM_ValidateWakeupEvent(WakeupSource);
      }

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    }
    else
    {
      EcuM_LeaveCriticalArea_0();
      /* Wakeup validation for this source is already active at the moment */
    }
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_SET_WAKEUP_EVENT, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT( errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}

/***********************************************************************************************************************
 *  EcuM_ValidateWakeupEvent
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_ValidateWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 Shiftcount = EcuM_GetShiftCount(WakeupSource);

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the wakeup source parameter is a single bitmask and in a valid range. */
  /* Check if that source is in the field of possible wakeup sources. Additional there is a check that only one bit is set */
  if ((((EcuM_WakeupSourceType) 0u) != (((WakeupSource) - ((EcuM_WakeupSourceType) 1u)) & WakeupSource))
      || ((Shiftcount) >= (EcuM_GetMaxWakeupSourceCount()))
#if(ECUM_VALIDOFWAKEUPSOURCELIST == STD_ON)
      || (!EcuM_IsValidOfWakeupSourceList(Shiftcount))
#endif
      )
  {
    errorId = ECUM_E_UNKNOWN_WAKEUP_SOURCE;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* Enter a critical area to avoid access on this procedure on another context */
    EcuM_EnterCriticalArea_0();

    /* #30 Check if that WakeupEvent has to be validated in the following two cases:
     * > Always if the WakeupSource is a ComChannel or a ComM PNC.
     * > For any other sources only if the Phase is != UP
     */
#if(ECUM_NONCHANNEL_WAKEUP_RUN == STD_OFF)
# if(ECUM_FIXED_BEHAVIOR == STD_OFF)
    if ((EcuM_GetModuleState() != ECUM_STATE_RUN)
# else
    if ((EcuM_GetModuleState() != ECUM_STATE_APP_RUN)
# endif

# if (ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON)
        || (EcuM_GetChannelOfWakeupSourceList(Shiftcount) != 0xFFu)
# endif
# if (ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
        || (EcuM_GetComMPNCsStartIdxOfWakeupSourceList(Shiftcount) != ECUM_NO_COMMPNCSSTARTIDXOFWAKEUPSOURCELIST)
# endif
    )
#endif
    {
      /* #33 Mark the wakeup source as a validated wakeup source. */
      EcuM_ValidatedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);

      /* #34 Check if the BswM notification is configured as Deferred. */
#if (ECUM_DEFERRED_BSWM_NOTIFICATION == STD_ON)
      /* #35 In case of deferred notification: Mark the wakeup source as a validated wakeup source buffered for the BswM notification. */
      EcuM_BswM_BufferedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);
#else
      /* #36 In case of no deferred notification: Report the new state of the source to the BswM only in a state where BswM is initialized. */
      if(EcuM_GetModuleState() > ECUM_STATE_STARTUP_TWO)
      {
        BswM_EcuM_CurrentWakeup(WakeupSource, ECUM_WKSTATUS_VALIDATED);
      }
      else
      {
        /* #37 If BswM is not initialized: Mark the wakeup source as a validated wakeup buffered for later BswM notification. */
        EcuM_BswM_BufferedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);
      }
#endif

#if ((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) || (ECUM_PNCOFCOMMPNCS == STD_ON)) /* COV_ECUM_PNCOFCOMMPNCS_QM */
# if(((ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) && (ECUM_PNCOFCOMMPNCS == STD_ON))) /* COV_ECUM_PNCOFCOMMPNCS_QM */
      if ((EcuM_GetChannelOfWakeupSourceList(Shiftcount) != 0xFFu)
          || (EcuM_GetComMPNCsStartIdxOfWakeupSourceList(Shiftcount) != ECUM_NO_COMMPNCSSTARTIDXOFWAKEUPSOURCELIST))
# elif (ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM_DEPENDENCY */
      if (EcuM_GetChannelOfWakeupSourceList(Shiftcount) != 0xFFu)
# else
      if (EcuM_GetComMPNCsStartIdxOfWakeupSourceList(Shiftcount) != ECUM_NO_COMMPNCSSTARTIDXOFWAKEUPSOURCELIST)
# endif
      {
        /* #40 Request the init status of the ComM. */
        VAR(ComM_InitStatusType, AUTOMATIC) ComMStatus;
        (void)ComM_GetStatus(&ComMStatus); /* SBSW_ECUM_ADRESSPARAMETER_TOCOMM */

        /* #41 In case the ComM is initialized: Report the new state of the source to the ComM. */
        if(ComMStatus == COMM_INIT)
        {
# if (ECUM_CHANNELOFWAKEUPSOURCELIST == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM_DEPENDENCY */
#  if (ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
          if(EcuM_GetChannelOfWakeupSourceList(Shiftcount) != 0xFFu)
#  endif
          {
            ComM_EcuM_WakeUpIndication(EcuM_GetChannelOfWakeupSourceList(Shiftcount));
          }
# endif
# if(ECUM_PNCOFCOMMPNCS == STD_ON) /* COV_ECUM_PNCOFCOMMPNCS_QM */
          if(EcuM_GetComMPNCsStartIdxOfWakeupSourceList(Shiftcount) != ECUM_NO_COMMPNCSSTARTIDXOFWAKEUPSOURCELIST)
          {
            EcuM_InternalComMPNCNotification(Shiftcount);
          }
# endif
        }
        /* #42 In case the ComM is not initialized: Mark the wakeup source as a validated wakeup buffered for later ComM notification. */
        else
        {
          EcuM_ComM_BufferedWakeups |= (EcuM_WakeupSourceType)(WakeupSource);
        }
      }
#endif
    }

#if (ECUM_VALIDATIONTIMEOFWAKEUPSOURCELIST == STD_ON)
    /* #50 Remove the wakeup source from the pending wakeup sources. */
    EcuM_PendingWakeups &= (EcuM_WakeupSourceType) (~WakeupSource);

    /* #51 Set the Timeout Table of this source to NO_TIMEOUT_SET to mark it as inactive. */
    EcuM_SetValidationTimeoutTable(Shiftcount, ECUM_NO_VALIDATION_TIMEOUT); /* SBSW_ECUM_ACCESSVALTABLE */
#endif

    EcuM_LeaveCriticalArea_0();
  }

  /* ----- Development Error Report --------------------------------------- */
#if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_VALIDATE_WAKEUP_EVENT, errorId);
  }
#else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#if(ECUM_FIXED_BEHAVIOR == STD_OFF)
/***********************************************************************************************************************
 *  EcuM_GoHalt
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if(ECUM_NUMBER_OF_CORES > 1u)
  CoreIdType coreID = GetCoreID();
# endif

# if(ECUM_SLEEPMODELIST == STD_ON) && (ECUM_PARTITIONINIT == STD_ON)
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
  EcuM_SizeOfPartitionInitType applicationIdx = EcuM_InternalGetPartitionIdx();
#  endif
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if(ECUM_NUMBER_OF_CORES > 1u)
  /* #20 In case of a multicore ECU: Check if the returned coreId is a valid one. */
#  if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (coreID >= EcuM_GetSizeOfCoreStatus())
  {
    EcuM_ErrorHook(ECUM_E_HOOK_INVALID_COREID);
  }
  else
#  endif
# endif
  {
    /* #21 Check if at least one sleepmode is configured. */
# if(ECUM_SLEEPMODELIST == STD_ON)
    /* ----- Implementation ----------------------------------------------- */
#  if(ECUM_PARTITIONINIT == STD_ON)
#   if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
    /* #22 In case of multiple partitions: Check if the current partition is an EcuM partition. */
   if((applicationIdx < EcuM_GetSizeOfPartitionInit())
      && (EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
      )
#   endif
#  endif
    {
      /* #30 On multicore ECUs check on which core this API was called. */
#  if(ECUM_NUMBER_OF_CORES > 1u)
      if (coreID != ECUM_CORE_ID_BSW)
      {
        /* #31 In case of a slave core, call the internal API to enter the sleep mode on a slave core. */
        retVal = EcuM_EnterSleepOnSlave(coreID);
      }
      else
#  endif
      {
        /* #32 In case of a BSW core, call the internal API to enter the sleep mode on the BSW core. */
        retVal = EcuM_EnterSleep( ECUM_ENTER_HALT);
      }
    }
# endif
  }
  /* ----- Development Error Report --------------------------------------- */
# if((ECUM_DEV_ERROR_REPORT == STD_ON) && (ECUM_SLEEPMODELIST == STD_OFF))
  {
    EcuM_Det_ReportError(ECUM_SID_GO_HALT, ECUM_E_NO_SLEEPMODE_CONFIGURED);
  }
# endif

  return retVal;
}

/***********************************************************************************************************************
 *  EcuM_GoPoll
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

# if(ECUM_NUMBER_OF_CORES > 1u)
  CoreIdType coreID = GetCoreID();
# endif

# if(ECUM_SLEEPMODELIST == STD_ON) && (ECUM_POLLINGOFSLEEPMODELIST == STD_ON) && (ECUM_PARTITIONINIT == STD_ON)
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
  EcuM_SizeOfPartitionInitType applicationIdx = EcuM_InternalGetPartitionIdx();
#  endif
# endif

  /* ----- Development Error Checks ------------------------------------- */
# if(ECUM_NUMBER_OF_CORES > 1u)
  /* #20 In case of a multicore ECU: Check if the returned coreId is a valid one. */
#  if (ECUM_DEV_ERROR_DETECT == STD_ON)
  if (coreID >= EcuM_GetSizeOfCoreStatus())
  {
    EcuM_ErrorHook(ECUM_E_HOOK_INVALID_COREID);
  }
  else
#  endif
# endif

  {
    /* #22 Check if at least one sleepmode is configured. */
# if ((ECUM_SLEEPMODELIST == STD_ON) && (ECUM_POLLINGOFSLEEPMODELIST == STD_ON))
  /* ----- Implementation ----------------------------------------------- */
#  if(ECUM_PARTITIONINIT == STD_ON)
#   if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
    /* #21 In case of multiple partitions: Check if the current partition is an EcuM partition. */
    if((applicationIdx < EcuM_GetSizeOfPartitionInit())
       && (EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
       )
#   endif
#  endif
    {
      /* #30 On multicore ECUs check on which core this API was called. */
#  if(ECUM_NUMBER_OF_CORES > 1u)
      if (coreID != ECUM_CORE_ID_BSW)
      {
        /* #31 In case of a slave core, call the internal API to enter the sleep mode on a slave core. */
        retVal = EcuM_EnterSleepOnSlave(coreID);
      }
      else
#  endif
      {
        /* #32 In case of a BSW core, call the internal API to enter the sleep mode on the BSW core. */
        retVal = EcuM_EnterSleep( ECUM_ENTER_POLL);
      }
    }
# endif
  }
  /* ----- Development Error Report --------------------------------------- */
# if((ECUM_DEV_ERROR_REPORT == STD_ON) && ((ECUM_SLEEPMODELIST == STD_OFF) || (ECUM_POLLINGOFSLEEPMODELIST == STD_OFF)))
  {
    EcuM_Det_ReportError(ECUM_SID_GO_POLL, ECUM_E_NO_SLEEPMODE_CONFIGURED);
  }
# endif

  return retVal;
}

/***********************************************************************************************************************
 *  EcuM_GoToSelectedShutdownTarget
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoToSelectedShutdownTarget(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;

  /* ----- Implementation ----------------------------------------------- */
# if (ECUM_SLEEPMODELIST == STD_ON)
  /* Check if the current shutdown target is set to Sleep, Reset or Off. */
  if (EcuM_CurrentShutdownTarget == ECUM_STATE_SLEEP)
  {
#  if (ECUM_POLLINGOFSLEEPMODELIST == STD_ON)
    /*  In case of Sleep differ if the current sleepmode needs polling or not. */
    if (EcuM_IsPollingOfSleepModeList(EcuM_CurrentShutdownMode))
    {
      /* In case the sleepmode needs polling, call the corresponding EcuM API. */
      retVal = EcuM_GoPoll();
    }
    else
#  endif
    {
      /* In case the sleepmode does not need polling, call the corresponding EcuM API. */
      retVal = EcuM_GoHalt();
    }
  }
  else
# endif
  {
    /* In case of Off / Reset, call the corresponding EcuM API. */
    retVal = EcuM_GoDown( ECUM_MODULE_ID);
  }

  return retVal;
}
#endif

/***********************************************************************************************************************
 *  EcuM_GoDown
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if(ECUM_FIXED_BEHAVIOR == STD_OFF)
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown(VAR(uint16, AUTOMATIC) caller)
#else
ECUM_LOCAL_INLINE FUNC(Std_ReturnType, ECUM_CODE) EcuM_InternalGoDown(void)
#endif
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */
  uint8 errorId = ECUM_E_NO_ERROR;

# if(ECUM_PARTITIONINIT == STD_ON)
  EcuM_SizeOfPartitionInitType applicationIdx = EcuM_InternalGetPartitionIdx();
  if ((GetCoreID() == ECUM_CORE_ID_BSW )
#  if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
        && (applicationIdx < EcuM_GetSizeOfPartitionInit())
        && (EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
#  endif
    )
# endif
  {

#if (ECUM_FIXED_BEHAVIOR == STD_OFF)
    /* Separate checks are necessary because of compiler warnings if ECUM_GODOWNALLOWEDOFFLEXUSER is not available */
# if (ECUM_GODOWNALLOWEDOFFLEXUSER == STD_ON) /* COV_ECUM_GODOWNALLOWEDOFFLEXUSER_QM */
    VAR(uint8_least, AUTOMATIC) LoopCount;
# else
    /* dummy assignment to prevent compiler warnings on most of the compilers. */
    ECUM_DUMMY_STATEMENT(caller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
#endif

    /* ----- Development Error Checks ------------------------------------- */
    /* #20 Check if the EcuM is in the correct state to proceed a shutdown. */
#if (ECUM_DEV_ERROR_DETECT == STD_ON && ECUM_FIXED_BEHAVIOR == STD_OFF)
    if ( EcuM_GetModuleState() != ECUM_STATE_RUN)
    {
      errorId = ECUM_E_MODULE_NOT_IN_RUN_STATE;
    }
    else
#endif
    {
      /* #21 In the case of defensive behavior: Check if the passed caller is allowed to shut down the ECU. */

      /* Check if the defensive behavior is active at the moment, and than check if the current caller is one of the allowed
       * Users for a shutdown call.*/
#if (ECUM_FIXED_BEHAVIOR == STD_OFF)
      /* Separate checks are necessary because of compiler warnings if ECUM_GODOWNALLOWEDOFFLEXUSER is not available */
# if (ECUM_GODOWNALLOWEDOFFLEXUSER == STD_ON) /* COV_ECUM_GODOWNALLOWEDOFFLEXUSER_QM */

      for(LoopCount = 0u; LoopCount < EcuM_GetSizeOfFlexUser(); LoopCount++)
      {
        /* Iterate over all configured EcuM Flex users and try to find the passed caller id. */
        if((EcuM_GetModuleIdOfFlexUser(LoopCount) == caller)
#  if(ECUM_ISDEF_GODOWNALLOWEDOFFLEXUSER == STD_OFF) /* COV_ECUM_GODOWNALLOWEDOFFLEXUSER_QM_DEPENDENCY */
            && (EcuM_IsGoDownAllowedOfFlexUser(LoopCount))
#  endif
        )
        {
          retVal = E_OK;
          break;
        }
      }

      if(retVal == E_NOT_OK)
      {
        /* If no user was found and the corresponding Dem event is configured, report the error to the Dem. */
#  if defined(ECUM_E_IMPROPER_CALLER) /* COV_ECUM_GODOWNALLOWEDOFFLEXUSER_QM_DEPENDENCY */
        Dem_ReportErrorStatus(ECUM_E_IMPROPER_CALLER, DEM_EVENT_STATUS_FAILED);
#  endif
      }

      /* Start the OffPreOS Sequence if checking for valid caller was not necessary or the check was true */
      else
# else
      retVal = E_OK;
# endif /* ECUM_GODOWNALLOWEDOFFLEXUSER == STD_ON) */

#else
      retVal = E_OK;
#endif /* (ECUM_FIXED_BEHAVIOR != STD_ON */
      {
        /* ----- Implementation ----------------------------------------------- */

#if(ECUM_FIXED_BEHAVIOR == STD_OFF)
        EcuM_SetModuleState(ECUM_STATE_GO_OFF_ONE);

        /* #30 Execute user-specific code shortly before Deinitialize BswM and SchM (EcuM_OnGoOffOne()).*/
        EcuM_OnGoOffOne();
#endif

        /* #31 Deinitialize the BswM and the SchM. */
        BswM_Deinit();

        SchM_Deinit();

        /* 32 Synchronize different cores with EcuM instances in case of Multicore. */
#if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
        EcuM_SetCoreStatusValue(ECUM_CORE_ID_BSW, ECUM_CORESTATUS_OFF); /* SBSW_SETCORESTATUS_BSWCOREID */
        EcuM_ShutdownSynchronization(ECUM_CORESTATUS_OFF);
#endif

        /* #33 Only if the CurrentShutdownTarget is OFF, the EcuM checks again for pending wakeups. */
        if (EcuM_CurrentShutdownTarget == ECUM_STATE_OFF)
        {
          /* Check if there are pending Wakeups, if so, set the shutdown target to Reset. */
          EcuM_EnterCriticalArea_0();

          if (ECUM_COMBINEDWAKEUPS != ECUM_WKSOURCE_NONE)
          {
            /* #34 In case of a detected pending wakeup, set the ShutdownTarget to reset and change the mode to ECUM_RESET_WAKEUP. */
            EcuM_CurrentShutdownTarget = ECUM_STATE_RESET;

#if defined(EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP)
            EcuM_CurrentShutdownMode = EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP;
#else
            /* EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP is not configured. Set EcuM_CurrentShutdownMode to a not used mode.*/
            EcuM_CurrentShutdownMode = 0xFFu;
#endif
          }

          EcuM_LeaveCriticalArea_0();
        }

        /* #35 Shut down the ASR OS, the routine expects an ErrorCode (E_OK) as parameter. */
        EcuM_ShutdownOS(E_OK);
      }
    }

    /* ----- Development Error Report --------------------------------------- */
#if (ECUM_DEV_ERROR_REPORT == STD_ON && ECUM_FIXED_BEHAVIOR == STD_OFF)
    if (errorId != ECUM_E_NO_ERROR)
    {
      EcuM_Det_ReportError(ECUM_SID_GO_DOWN, errorId);
    }
#else
    ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

  }
#if(ECUM_PARTITIONINIT == STD_ON)
  else
  {
    /* #40 Check if the current partitions is configured for EcuM or BswM. */
    if(applicationIdx < EcuM_GetSizeOfPartitionInit())
    {
# if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
      if(EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
# endif
      {
        /* #41 Execute user-specific code shortly before Deinitialize BswM and SchM (EcuM_OnGoOffOne()). */
        EcuM_OnGoOffOne();
      }

# if(ECUM_BSWMPARTITIONOFPARTITIONINIT == STD_ON)
#  if(ECUM_ISDEF_BSWMPARTITIONOFPARTITIONINIT == STD_OFF)
      if(EcuM_IsBswMPartitionOfPartitionInit(applicationIdx))
#  endif
      {
        /* #42 Deinitialize the BswM on the slave core. */
        BswM_Deinit();
      }
# endif

# if(ECUM_ISDEF_ECUMPARTITIONOFPARTITIONINIT == STD_OFF)
      if(EcuM_IsEcuMPartitionOfPartitionInit(applicationIdx))
# endif
      {
        /* #43 Deinitialize the SchM on the slave core. */
        SchM_Deinit();

# if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
        {
          CoreIdType coreID = GetCoreID();
          EcuM_EnterCriticalArea_1();
          EcuM_SetCoreStatusValue(coreID, ECUM_CORESTATUS_OFF); /* SBSW_SETCORESTATUS_OSCOREID */
          EcuM_LeaveCriticalArea_1();
        }
# endif
      }
    }
  }
#endif

  /* The return only occurs if retval = E_OK, because of the call of ShutdownOS does never return.  */
  return retVal;
} /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */

#if(ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/***********************************************************************************************************************
 *  EcuM_SetAbsWakeupAlarm
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm(VAR(EcuM_UserType, AUTOMATIC) user,
    VAR(EcuM_TimeType, AUTOMATIC) sec)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 AlarmClockUser;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the calling user is in the range of valid users. */
  if ((user >= EcuM_GetSizeOfFlexUser()) || (EcuM_GetAlarmClockIdOfFlexUser(user) == 0xFFu))
  {
    errorId = ECUM_E_INVALID_PAR;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */

    /* Get the AlarmClock Id of this User */
    AlarmClockUser = EcuM_GetAlarmClockIdOfFlexUser(user);

    /* #21 Check that no earlier alarm is already active. */
    if ((EcuM_GetAlarmClockTimeOut(AlarmClockUser) <= sec)
        && (EcuM_GetAlarmClockTimeOut(AlarmClockUser) != 0u))
    {
      retval = E_EARLIER_ACTIVE;
    }

    /* #22 Check that that the new alarm is in the future. */
    else if (sec <= EcuM_Clock)
    {
      retval = E_PAST;
    }

    else
    {
      /* #30 Save the time of the users AlarmClock. */
      EcuM_SetAlarmClockTimeOut(AlarmClockUser, sec); /* SBSW_ECUM_ACCESSALARMCLOCK */

      /* #31 Update the EcuM_MasterAlarm if the new Alarm is earlier than a previous one. */
      EcuM_UpdateMasterAlarm();

      retval = E_OK;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_SET_ABS_WAKEUP_ALARM, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif


  return retval;
}

/***********************************************************************************************************************
 *  EcuM_SetRelWakeupAlarm
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm(VAR(EcuM_UserType, AUTOMATIC) user,
    VAR(EcuM_TimeType, AUTOMATIC) sec)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Add the passed time to the EcuM Clock Time and pass the amount to the API EcuM_SetAbsWakeupAlarm. */
  return EcuM_SetAbsWakeupAlarm(user, sec + EcuM_Clock);
}

/***********************************************************************************************************************
 *  EcuM_AbortWakeupAlarm
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm(VAR(EcuM_UserType, AUTOMATIC) user)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;
  uint8 errorId = ECUM_E_NO_ERROR;
  uint8 AlarmClockUser;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check if the calling user is in the range of valid users. */
  if ((user >= EcuM_GetSizeOfFlexUser()) || (EcuM_GetAlarmClockIdOfFlexUser(user) == 0xFFu))
  {
    errorId = ECUM_E_INVALID_PAR;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    AlarmClockUser = EcuM_GetAlarmClockIdOfFlexUser(user);
    /* #21 Check for an active alarm clock set by this user. */
    if (EcuM_GetAlarmClockTimeOut(AlarmClockUser) != 0u)
    {
      /* #22 Set the current alarm clock of this user to 0. */
      EcuM_SetAlarmClockTimeOut(AlarmClockUser, 0u); /* SBSW_ECUM_ACCESSALARMCLOCK */

      /* #23 Update the next alarm time via EcuM_UpdateMasterAlarm. */
      EcuM_UpdateMasterAlarm();

      retval = E_OK;
    }
    else
    {
      retval = E_NOT_ACTIVE;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_ABORT_WAKEUP_ALARM, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetCurrentTime
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime(P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) sec)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;

  /* #20 Check that the passed pointer is not a Null Pointer. */
  if(sec != NULL_PTR)
  {
    /* ----- Implementation ----------------------------------------------- */
    EcuM_EnterCriticalArea_2();
    /* #30 Pass the current EcuM Time to the pointer. */
    *sec = EcuM_Clock; /* SBSW_ECUM_POINTERACCESS_TIME */
    EcuM_LeaveCriticalArea_2();

    retval = E_OK;
  }
  else
  {
    /* Null Pointer was given as parameter and leads to an error return. */
  }

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_GetWakeupTime
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime(P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) sec)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK;

  /* #20 Check that the passed pointer is not a Null Pointer. */
  if(sec != NULL_PTR)
  {
    /* ----- Implementation ----------------------------------------------- */
    EcuM_EnterCriticalArea_2();
    /* #30 Pass the current EcuM Alarm Time to the pointer. */
    *sec = EcuM_MasterAlarm; /* SBSW_ECUM_POINTERACCESS_TIME */
    EcuM_LeaveCriticalArea_2();

    retval = E_OK;
  }
  else
  {
    /* Null Pointer was given as parameter and leads to an error return. */
  }

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_SetClock
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock(VAR(EcuM_UserType, AUTOMATIC) user,
    VAR(EcuM_TimeType, AUTOMATIC) sec)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval = E_NOT_OK; /* PRQA S 2981 */ /* MD_MSR_RetVal */

  /* #20 Check that the calling user is valid and allowed to set the EcuM Time. */
  if ((user < EcuM_GetSizeOfFlexUser()) && EcuM_IsSetClockAllowedOfFlexUser(user))
  {
    /* ----- Implementation ----------------------------------------------- */
    EcuM_EnterCriticalArea_2();
    /* #30 Set the EcuM Time to the passed time parameter. */
    EcuM_Clock = sec;
    EcuM_LeaveCriticalArea_2();
    retval = E_OK;
  }
  else
  {
    retval = E_NOT_ALLOWED;
  }

  return retval;
}

/***********************************************************************************************************************
 *  EcuM_AlarmCheckWakeup
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_AlarmCheckWakeup(void)
{
  /* ----- Implementation ----------------------------------------------- */
  /* #20 Increment the current EcuM Time. */
  EcuM_Clock++;

  /* #30 If the EcuM Time has reached the Alarm time, a wakeup event shall be set. */
  if (EcuM_MasterAlarm == EcuM_Clock)
  {
    EcuM_SetWakeupEvent(ECUM_ALARM_WKSOURCE);

    EcuM_InternalClearAlarms();
  }
}
#endif /* (ECUM_ALARM_CLOCK_PRESENT == STD_ON) */

#if (ECUM_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  EcuM_GetVersionInfo
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = ECUM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #20 Check that the passed parameter is not a Null Pointer. */
  if (NULL_PTR == versioninfo)
  {
    errorId = ECUM_E_NULL_POINTER;
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Pass the EcuM version info from component header to the Std_VersionInfoType Pointer. */

    versioninfo->vendorID = (uint16)ECUM_VENDOR_ID;  /* SBSW_ECUM_POINTERACCESS_VERSIONINFO */
    versioninfo->moduleID = (uint16)ECUM_MODULE_ID;  /* SBSW_ECUM_POINTERACCESS_VERSIONINFO */

    versioninfo->sw_major_version = (uint8)ECUM_SW_MAJOR_VERSION;  /* SBSW_ECUM_POINTERACCESS_VERSIONINFO */
    versioninfo->sw_minor_version = (uint8)ECUM_SW_MINOR_VERSION;  /* SBSW_ECUM_POINTERACCESS_VERSIONINFO */
    versioninfo->sw_patch_version = (uint8)ECUM_SW_PATCH_VERSION;  /* SBSW_ECUM_POINTERACCESS_VERSIONINFO */
  }

  /* ----- Development Error Report --------------------------------------- */
# if(ECUM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != ECUM_E_NO_ERROR)
  {
    EcuM_Det_ReportError(ECUM_SID_GET_VERSION_INFO, errorId);
  }
# else
  ECUM_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif /* (ECUM_VERSION_INFO_API == STD_ON) */

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Justification for module-specific MISRA deviations:
*
     MD_EcuM_0771:
     Reason:     Multiple break used for optimize code runtime.
     Risk:       Relevant fragments of code not executed.
     Prevention: Covered by code review.

     MD_EcuM_0779:
     Reason:     Dependend on the variant name, init functions are not always unique within the first 31 characters.
     Risk:       There is no risk as such statements have no effect on the code.
     Prevention: Covered by code review.

     MD_EcuM_0841:
     Reason:     EcuM_PrivateCfg.h must not be used outside EcuM.
     Risk:       #undef of wrong identifier.
     Prevention: Covered by code review or Compiler Error in case an undefined identifier is used.

     MD_EcuM_1330:
     Reason:     Parameter names differ from declaration because the Rte does currently not use the correct ASR parameter names.
     Risk:       No risk, parameter names are not relevant.
     Prevention: Covered by code review.

     MD_EcuM_1514:
     Reason:     EcuM_ConfigDataPtr is a Global Config Pointer and cannot be made static.
     Risk:       No Risk.
     Prevention: Covered by code review.

     MD_EcuM_1533:
     Reason:     The value of the object is generated, therefore cannot be moved to the static file EcuM.c.
     Risk:       No Risk.
     Prevention: Covered by code review.

     MD_EcuM_2991_2992_2995_2996:
     Reason:     During runtime of EcuM_Init it must be detected if the Autosar startup core is also the BSW core. In case that ECUM_CORE_ID_STARTUP 
                 and ECUM_CORE_ID_BSW are configured to the same value this is not coverable.
     Risk:       There is no risk, most compilers will optimize these.
     Prevention: Covered by code review.

     MD_EcuM_3206:
     Reason:     Empty implementation. Dummy statements can only be used when a define ECUM_USE_DUMMY_STATEMENT is ON.
     Risk:       No risk.
     Prevention: Covered by code review.

     MD_EcuM_3218:
     Reason:     Not all compilers can cope with static const at function scope.
     Risk:       Developer is tempted to use static const variables in other functions although it is not designated.
     Prevention: Assert that the variables are used in one function only during review.

     MD_EcuM_3415:
     Reason:     Parameter check or function call at right hand of || or && is defined to have no side-effects.
     Risk:       Called functions have no side effects.
     Prevention: Covered by code review.

     MD_EcuM_3673:
     Reason:     API should not be called in this configuration but is available to prevent compiler errors.
     Risk:       No functional risk.
     Prevention: Covered by code review.

 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_ECUM_ACCESSVALTABLE
 \DESCRIPTION Access of ValidationTimeoutTable (via indirection over WakeupSourceList) with same index using ComStackLib
 \COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID SBSW_ECUM_ACCESSALARMCLOCK
 \DESCRIPTION Access of AlarmClockTimeOut using ComStackLib
 \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_ECUM_ACCESSUSERTABLE
 \DESCRIPTION Access of UserTable using ComStackLib
 \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_ECUM_POINTERACCESS_VERSIONINFO
 \DESCRIPTION The function writes to the 'version' pointer parameter.
 \COUNTERMEASURE \N The caller has to guarantee that the pointer is valid.

\ID SBSW_ECUM_POINTERACCESS_SHUTDOWNTARGET
 \DESCRIPTION The function writes to the 'target' and to 'resetSleepMode' pointer parameters.
 \COUNTERMEASURE \N The caller has to guarantee that the pointers are valid.

\ID SBSW_ECUM_POINTERACCESS_SHUTDOWNCAUSE
 \DESCRIPTION The function writes to the 'shutdownCause' pointer parameter.
 \COUNTERMEASURE \N The caller has to guarantee that the pointer is valid.

\ID SBSW_ECUM_POINTERACCESS_BOOTTARGET
 \DESCRIPTION The function writes to the 'BootTarget' pointer parameter.
 \COUNTERMEASURE \N The caller has to guarantee that the pointer is valid.

\ID SBSW_ECUM_POINTERACCESS_TIME
 \DESCRIPTION The function writes to the 'time' pointer parameter.
 \COUNTERMEASURE \N The caller has to guarantee that the pointer is valid.

\ID SBSW_ECUM_POINTERACCESS_STATE
 \DESCRIPTION The function writes to the 'state' pointer parameter.
 \COUNTERMEASURE \N The caller has to guarantee that the pointer is valid.

\ID SBSW_ECUM_FUNCTIONPOINTER_CALL
 \DESCRIPTION Call to a generated driver init function via a function pointer.
 \COUNTERMEASURE \S User verifies generated functions (SMI-8) and performs adequate integration (SMI-4).

\ID SBSW_ECUM_ADRESSPARAMETER_TOCOMM
 \DESCRIPTION The variable 'ComMStatus' is passed to the API ComM_GetState.
 \COUNTERMEASURE \N The passed parameter is declared locally and is trusted.

\ID SBSW_ECUM_ADRESSPARAMETER_TOOS
 \DESCRIPTION The variable 'status' is passed to the API StartCore.
 \COUNTERMEASURE \N The passed parameter is declared locally and is trusted.

\ID SBSW_SETCORESTATUS_BSWCOREID
 \DESCRIPTION The define 'ECUM_CORE_ID_BSW' is used to write to the array 'CoreStatus'.
 \COUNTERMEASURE \N It is assured via preprocessor error directive that 'ECUM_CORE_ID_BSW' is in range of the array.

\ID SBSW_SETCORESTATUS_OSCOREID
 \DESCRIPTION Access of CoreStatus using ComStackLib.
 \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID SBSW_ECUM_FUNCTIONCALL_POINTER
 \DESCRIPTION Pass pointer parameter to SchM and BswM initialization functions.
 \COUNTERMEASURE \S Check that ECUM_SCHM_CONFIG_POINTER and ECUM_BSWM_CONFIG_POINTER contain a valid pointer to
                    initialize those modules.

\ID SBSW_ECUM_DEM_FUNCTIONCALL_POINTER
 \DESCRIPTION Pass pointer parameter to Dem initialization functions.
 \COUNTERMEASURE \S Check that ECUM_DEM_CONFIG_POINTER contain a valid pointer to initialize this module.

SBSW_JUSTIFICATION_END */


/* COV_JUSTIFICATION_BEGIN

\ID COV_ECUM_LOCAL
  \ACCEPT XF
  \REASON Ensures that ECUM_LOCAL is always be set.

\ID COV_ECUM_LOCAL_INLINE
  \ACCEPT XF
  \REASON Ensures that ECUM_LOCAL_INLINE is always be set.

\ID COV_ECUM_ERRORS
  \ACCEPT TX
  \REASON Ensures that errors are always defined.

\ID COV_ECUM_01
  \ACCEPT  TF tf tx
  \REASON  It is only possible to cover this line in configurations with more than one wakeup source with a referenced
           ComM channel.

\ID COV_ECUM_02
  \ACCEPT  TX
  \REASON  This switch is generated by CSL and is currently always active if EcuM is available.

\ID COV_ECUM_03
  \ACCEPT  XX
  \REASON  The default case in EcuM_Shutdown is not reachable if the DET is enabled.

\ID COV_ECUM_04
  \ACCEPT  TX
  \REASON  This line can only be covered if the source which was responsible for a wakeup is part of the current sleepmode.

\ID COV_ECUM_05
  \ACCEPT  XF
  \REASON  Two wakeup sources with configured validation timeout must be configured to the same sleepmode.

\ID COV_ECUM_RESTARTID
  \ACCEPT  TF tf xf
  \REASON  The magic number check for reinitialized RAM content is performed with two different numbers for safety reasons
           but it is sufficient that either both of them are valid or both are not valid.

\ID COV_ECUM_CALLOUT
  \ACCEPT  XX
  \ACCEPT  TX
  \ACCEPT  TF tf xf
  \ACCEPT  TX tx xx
  \REASON  Some callout functions are not called by the static code of the EcuM and so they are not coverable.

\ID COV_ECUM_COREID_STARTUP
  \ACCEPT  XF
  \ACCEPT  TX
  \REASON  During runtime of EcuM_Init it must be detected if the Autosar startup core is also the BSW core. In case that ECUM_CORE_ID_STARTUP and ECUM_CORE_ID_BSW are configured
           to the same value this is not coverable.

\ID COV_ECUM_PARTITIONID
  \ACCEPT  TX
  \REASON  The EcuM_ErrorHook is called in case that an application ID is returned which is out of range of EcuM_GetSizeOfPartitionInit.

\ID COV_ECUM_PNCOFCOMMPNCS_QM
  \ACCEPT  TF tf xf tf
  \ACCEPT  XF tx xf
  \ACCEPT  TF tf xf
  \ACCEPT  XF
  \REASON  The feature switch ECUM_PNCOFCOMMPNCS is only valid for QM configurations.

\ID COV_ECUM_PNCOFCOMMPNCS_QM_DEPENDENCY
  \ACCEPT  TX
  \REASON  Due to the QM feature ECUM_PNCOFCOMMPNCS this switch cannot be covered completely.

\ID COV_ECUM_GODOWNALLOWEDOFFLEXUSER_QM
  \ACCEPT  XF
  \REASON  The feature 'Go Down Allowed Of Flex User' is only relevant in QM configurations.

\ID COV_ECUM_GODOWNALLOWEDOFFLEXUSER_QM_DEPENDENCY
  \ACCEPT  XX
  \REASON  Due to previous exlusion of the 'Go Down Allowed Of Flex User' feature, this switch cannot be covered completely.

COV_JUSTIFICATION_END */




/**********************************************************************************************************************
 *  END OF FILE: ECUM.C
 *********************************************************************************************************************/
