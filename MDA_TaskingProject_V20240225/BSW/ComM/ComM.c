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
/*!         \file  ComM.c
 *         \brief  Communication Manager ASR4
 *
 *       \details  Implementation of the Autosar Communication Manager
 *
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

#define CCL_ASR_COMM_SOURCE

/**********************************************************************************************************************
 *  LOCAL MISRA / PCLINT JUSTIFICATIONS
 *********************************************************************************************************************/
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0777 EOF */ /* MD_MSR_5.1_777 */
/* PRQA S 3453 EOF */ /* MD_MSR_19.7    */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "ComM_Private_Cfg.h"

#if (COMM_DCM_INDICATION == STD_ON)
# include "Dcm_Cbk.h"
# include "ComM_Dcm.h"
#endif

#if (COMM_NVM_SUPPORT == STD_ON)
# include "NvM.h"
#endif

#include "BswM_ComM.h"
#include "SchM_ComM.h"

#include "ComM_EcuMBswM.h"
#include "ComM_BusSM.h"
#include "ComM_Nm.h"

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
# include "Nm.h"
#endif

#if (COMM_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

#if (COMM_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
# include "EcuM_Error.h"
#endif

#if (COMM_EXTENDED_RAM_CHECK == STD_ON)
# include "CanSM.h"
# include "CanSM_ComM.h"
#endif

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* Check the version of ComM.h */
#if (  (COMM_SW_MAJOR_VERSION != (9u)) \
    || (COMM_SW_MINOR_VERSION != (0u)) \
    || (COMM_SW_PATCH_VERSION != (1u)) )
# error "Version numbers of ComM.h are inconsistent!"
#endif

/* Check the version of ComM_BusSM.h */
#if (  (COMM_BUSSM_MAJOR_VERSION != (9u)) \
    || (COMM_BUSSM_MINOR_VERSION != (0u)) \
    || (COMM_BUSSM_PATCH_VERSION != (1u)) )
# error "Version numbers of ComM_BusSM.h are inconsistent!"
#endif

/* Check the version of ComM_Dcm.h */
#if (COMM_DCM_INDICATION == STD_ON)
# if (  (COMM_DCM_MAJOR_VERSION != (9u)) \
     || (COMM_DCM_MINOR_VERSION != (0u)) \
     || (COMM_DCM_PATCH_VERSION != (1u)) )
#  error "Version numbers of ComM_Dcm.h are inconsistent!"
# endif
#endif

/* Check the version of ComM_EcuMBswM.h */
#if (  (COMM_ECUMBSWM_MAJOR_VERSION != (9u)) \
    || (COMM_ECUMBSWM_MINOR_VERSION != (0u)) \
    || (COMM_ECUMBSWM_PATCH_VERSION != (1u)) )
# error "Version numbers of ComM_EcuMBswM.h are inconsistent!"
#endif

/* Check the version of ComM_Nm.h */
#if (  (COMM_NM_MAJOR_VERSION != (9u)) \
    || (COMM_NM_MINOR_VERSION != (0u)) \
    || (COMM_NM_PATCH_VERSION != (1u)) )
# error "Version numbers of ComM_Nm.h are inconsistent!"
#endif

/* Check the version of ComM_Types.h */
#if (  (COMM_TYPES_MAJOR_VERSION != (9u)) \
    || (COMM_TYPES_MINOR_VERSION != (0u)) \
    || (COMM_TYPES_PATCH_VERSION != (1u)) )
# error "Version numbers of ComM_Types.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  COMPATIBILITY / DEFAULTS
 *********************************************************************************************************************/

#if (  (COMM_CONFIGURATION_VARIANT != COMM_CONFIGURATION_VARIANT_PRECOMPILE) \
    && (COMM_CONFIGURATION_VARIANT != COMM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) )
# error "ComM currently supports configuration variants PreCompile and PostBuild Loadable only"
#endif

/* Countermeasure of SBSW_COMM_ARRAY_CHANNEL_WRITE */
#if (COMM_ACTIVE_CHANNEL != ComM_GetSizeOfChannel())
# error "Generated data is invalid: COMM_ACTIVE_CHANNEL != ComM_GetSizeOfChannel()"
#endif

#if ((COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
# if ((COMM_MINFULLCOMTIMEOFCHANNEL == STD_OFF) || (COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL == STD_OFF))
#  error "Generated data is invalid: COMM_MINFULLCOMTIMEOFCHANNEL and COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL must be STD_ON"
# endif
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Bit mask to set the Prevent Wake-up status */
#define COMM_WAKEUP_INHIBITION_MASK                (uint8)0x01u
/*! Bit mask to clear the Prevent Wake-up status */
#define COMM_WAKEUP_INHIBITION_CLEAR_MASK          (uint8)0xfeu
/*! Bit mask to set the Mode Limitation status */
#define COMM_MODE_LIMITATION_MASK                  (uint8)0x02u
/*! Bit mask to clear the Mode Limitation status */
#define COMM_MODE_LIMITATION_CLEAR_MASK            (uint8)0xfdu

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/*! Bit mask to set PNC Routing Limitation status of a channel to activated (limited) */
#  define COMM_PNCROUTING_LIMITED                  (uint8)0x00
/*! Bit mask to set PNC Routing Limitation status of a channel to de-activated (partly) because Nm is in NM_REPEAT_MESSAGE state */
#  define COMM_PNCROUTING_NM_REPEAT_MESSAGE        (uint8)0x01
/*! Bit mask to set PNC Routing Limitation status of a channel to de-activated (default) */
#  define COMM_PNCROUTING_NOT_LIMITED              (uint8)0x02

/*! Bit mask to clear PNC Routing Limitation status de-activated (partly) */
#  define COMM_PNCROUTING_NM_REPEAT_MESSAGE_CLEAR  (uint8)0xfe
/*! Bit mask to clear PNC Routing Limitation status de-activated */
#  define COMM_PNCROUTING_NOT_LIMITED_CLEAR        (uint8)0xfd
# endif

/*! Send PNC signals on channels with Gateway Type ACTIVE */
# define COMM_SEND_ACTIVE_SIG_ONLY                  (uint8)(0u)
/*! Send PNC signals on channels with Gateway Type PASSIVE */
# define COMM_SEND_PASSIVE_SIG_ONLY                 (uint8)(1u)
/*! Send PNC signals on all channels */
# define COMM_SEND_ALL_SIG                          (uint8)(2u)
#endif

/*! Used to initialize and check the user request bit field */
#define COMM_NO_REQUESTS                           (uint8)0x00u

/*! Default value of the state change status */
#define COMM_NO_STATE_CHANGE                       (uint8)0x10u

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Compiler.h for AUTOSAR 4.0.3 won't have the 'static' keyword  */
#if !defined (COMM_LOCAL) /* COV_MSR_COMPATIBILITY */
# define COMM_LOCAL                                static
#endif

#if !defined (COMM_LOCAL_INLINE) /* COV_MSR_COMPATIBILITY */
# define COMM_LOCAL_INLINE                         LOCAL_INLINE
#endif

/* type definition of the ComM transition function call table */
typedef P2FUNC(void, COMM_CODE, ComM_TransitionFunctionType) (NetworkHandleType  Channel);

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES OF STATE TRANSITION FUNCTIONS (TF)
 *********************************************************************************************************************/

#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ComM_TF_NoCom_NetReq()
**********************************************************************************************************************/
/*! \brief      Performs the state transition from No Communication to Network Requested for the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-47933, SPEC-5081, SPEC-47933, SPEC-5456, SPEC-5414
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_NoCom_NetReq( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_NoCom_FullReadySleep()
**********************************************************************************************************************/
/*! \brief      Performs the state transition from No Communication to Ready Sleep for the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-5081, SPEC-5361, SPEC-5487, SPEC-5488
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_NoCom_FullReadySleep( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_Full_SiCom()
**********************************************************************************************************************/
/*! \brief      Performs the state transition from Full to Silent Communication for the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-5097
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_Full_SiCom( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_ReadyS_NetReq()
**********************************************************************************************************************/
/*! \brief      Performs the state transition from Ready Sleep to Network Requested for the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-5478
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_ReadyS_NetReq( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_SiCom_NoCom()
**********************************************************************************************************************/
/*! \brief      Performs the state transition from Full or Silent to No Communication for the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      CREQ-116030
 *  \trace      SPEC-5083, SPEC-5370
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_SiCom_NoCom( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_NetReq_ReadyS()
**********************************************************************************************************************/
/*! \brief      Performs the state transition from Network Requested to Ready Sleep for the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-5477, SPEC-5086
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_NetReq_ReadyS( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_No_Action()
**********************************************************************************************************************/
/*! \brief      Special state transition function for transitions that do not require any actions, needed as a placeholder
 *              in the state transition table.
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_No_Action( NetworkHandleType Channel );

/**********************************************************************************************************************
  ComM_TF_No_Transition()
**********************************************************************************************************************/
/*! \brief      Special state transition function for unsupported transitions to report development errors
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_No_Transition( NetworkHandleType Channel );

#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ROM DATA
**********************************************************************************************************************/
#define COMM_START_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/*! ComM transition table [requested][active], the element COMM_MAX_NUMBER_OF_STATES means that no transition is defined for the active/requested combination. */
/* PRQA S 3218 1 */ /* MD_ComM_3218 */
COMM_LOCAL CONST(ComM_StateType, COMM_CONST) ComM_TransitionTable[COMM_MAX_NUMBER_OF_STATES][COMM_MAX_NUMBER_OF_STATES] =    /* [row] [column] */
{/* COMM_NO_COM_NO_PENDING_REQUEST |COMM_NO_COM_REQUEST_PENDING     |COMM_FULL_COM_NETWORK_REQUESTED |COMM_FULL_COM_READY_SLEEP       |COMM_SILENT_COM                   requested mode: */
  {
    COMM_MAX_NUMBER_OF_STATES,      COMM_NO_COM_NO_PENDING_REQUEST,  COMM_FULL_COM_READY_SLEEP,       COMM_SILENT_COM,                 COMM_NO_COM_NO_PENDING_REQUEST  /* COMM_NO_COM_NO_PENDING_REQUEST */
  },
  {
    COMM_NO_COM_REQUEST_PENDING,    COMM_MAX_NUMBER_OF_STATES,       COMM_MAX_NUMBER_OF_STATES,       COMM_MAX_NUMBER_OF_STATES,       COMM_MAX_NUMBER_OF_STATES       /* COMM_NO_COM_REQUEST_PENDING */
  },
  {
    COMM_NO_COM_REQUEST_PENDING,    COMM_FULL_COM_NETWORK_REQUESTED, COMM_MAX_NUMBER_OF_STATES,       COMM_FULL_COM_NETWORK_REQUESTED, COMM_FULL_COM_NETWORK_REQUESTED /* COMM_FULL_COM_NETWORK_REQUESTED */
  },
  {
    COMM_NO_COM_REQUEST_PENDING,    COMM_FULL_COM_READY_SLEEP,       COMM_FULL_COM_READY_SLEEP,       COMM_MAX_NUMBER_OF_STATES,       COMM_FULL_COM_READY_SLEEP       /* COMM_FULL_COM_READY_SLEEP */
  },
  {
    COMM_MAX_NUMBER_OF_STATES,      COMM_MAX_NUMBER_OF_STATES,       COMM_FULL_COM_READY_SLEEP,       COMM_SILENT_COM,                 COMM_MAX_NUMBER_OF_STATES       /* COMM_SILENT_COM */
  }
};

#define COMM_STOP_SEC_CONST_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define COMM_START_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/*! ComM transition action table [requested][active], the element ComM_TF_No_Action means that no transition is defined for the active/requested combination. */
/* PRQA S 3218 1 */ /* MD_ComM_3218 */
COMM_LOCAL CONST(ComM_TransitionFunctionType, COMM_CONST) ComM_TransitionFctTable[COMM_MAX_NUMBER_OF_STATES][COMM_MAX_NUMBER_OF_STATES] =
{/* COMM_NO_COM_NO_PENDING_REQUEST |COMM_NO_COM_REQUEST_PENDING  |COMM_FULL_COM_NETWORK_REQUESTED |COMM_FULL_COM_READY_SLEEP |COMM_SILENT_COM                  requested mode: */
  {
    ComM_TF_No_Transition,          ComM_TF_No_Action,            ComM_TF_NetReq_ReadyS,           ComM_TF_Full_SiCom,        ComM_TF_SiCom_NoCom           /* COMM_NO_COM_NO_PENDING_REQUEST */
  },
  {
    ComM_TF_No_Action,              ComM_TF_No_Transition,        ComM_TF_No_Transition,           ComM_TF_No_Transition,     ComM_TF_No_Transition         /* COMM_NO_COM_REQUEST_PENDING */
  },
  {
    ComM_TF_No_Action,              ComM_TF_NoCom_NetReq,         ComM_TF_No_Transition,           ComM_TF_ReadyS_NetReq,     ComM_TF_NoCom_NetReq          /* COMM_FULL_COM_NETWORK_REQUESTED */
  },
  {
    ComM_TF_No_Action,              ComM_TF_NoCom_FullReadySleep, ComM_TF_NetReq_ReadyS,           ComM_TF_No_Transition,     ComM_TF_NoCom_FullReadySleep  /* COMM_FULL_COM_READY_SLEEP */
  },
  {
    ComM_TF_No_Transition,          ComM_TF_No_Transition,        ComM_TF_NetReq_ReadyS,           ComM_TF_Full_SiCom,        ComM_TF_No_Transition         /* COMM_SILENT_COM */
  }
};

#define COMM_STOP_SEC_CONST_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define COMM_START_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"
/*! Initialization state of ComM */
COMM_LOCAL VAR(ComM_InitStatusType, COMM_VAR_ZERO_INIT)   ComM_InitStatus = COMM_UNINIT;
#define COMM_STOP_SEC_VAR_ZERO_INIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define COMM_START_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/*! Communication state of a channel provided by BusSM */
COMM_LOCAL VAR(uint8, COMM_VAR_NOINIT)                    ComM_BusSmState[COMM_ACTIVE_CHANNEL];

#if ( COMM_USERMODENOTIFUNC == STD_ON )
/*! If BusSM indicates a change of communication state of a channel, this variable stores the new state and
 * is used to trigger a mode notification to all users mapped to this channel. As soon as mode notification
 * was carried out the default value COMM_NO_STATE_CHANGE is stored. */
COMM_LOCAL VAR(uint8, COMM_VAR_NOINIT)                    ComM_StateChange[COMM_ACTIVE_CHANNEL];

# if (COMM_PNC_SUPPORT == STD_ON)
/*! The flag signals, if a mode notification to PNC users is needed due to a PNC state change.
 * TRUE - a PNC changed the state from FULL_COM to NO_COM or vice versa or the last mode notification failed,
 * FALSE (default) - no PNC state changes to be notified and the last mode notification was successful. */
COMM_LOCAL VAR(boolean, COMM_VAR_NOINIT)                  ComM_NotifyPncStateChange;
# endif
#endif

#if (COMM_NVM_SUPPORT == STD_ON)
/*! TRUE if data has to be stored in NvM after mode limitation status has changed */
COMM_LOCAL VAR(boolean, COMM_VAR_NOINIT)                  ComM_NvMStoreReq;
#endif

/*! Communication allowed status of a channel */
COMM_LOCAL VAR(boolean, COMM_VAR_NOINIT)                  ComM_ComAllowed[COMM_ACTIVE_CHANNEL];

/*! Current state of a channel */
COMM_LOCAL VAR(ComM_StateType, COMM_VAR_NOINIT)           ComM_ActiveComMode[COMM_ACTIVE_CHANNEL];
/*! State requested externally (bus) */
COMM_LOCAL VAR(ComM_StateType, COMM_VAR_NOINIT)           ComM_BusComModeReq[COMM_ACTIVE_CHANNEL];

#if (COMM_BUS_TYPE_FR_PRESENT == STD_ON)
/*! TRUE if communication shutdown is ongoing on a Flexray channel */
COMM_LOCAL VAR(boolean, COMM_VAR_NOINIT)                  ComM_FrShutdown[COMM_ACTIVE_CHANNEL];
/*! State requested externally (bus) while shutdown is ongoing on a Flexray channel */
COMM_LOCAL VAR(ComM_StateType, COMM_VAR_NOINIT)           ComM_BusComModeReqFrShutdown[COMM_ACTIVE_CHANNEL];
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/*! Bit flags describing the current PNC Routing state per channel */
COMM_LOCAL VAR(uint8, COMM_VAR_NOINIT)                    ComM_PncToChannelRoutingState[COMM_ACTIVE_CHANNEL];
# endif
#endif

#define COMM_STOP_SEC_VAR_NOINIT_8BIT
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/*! Status of mode limitation (inhibition) */
VAR(ComM_InhibitionType, COMM_NVM_DATA)                   ComM_Inhibition;

#define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

#if (COMM_USE_INIT_POINTER == STD_ON)
# define COMM_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/*! Pointer to the current configuration */
/* PRQA S 3218 1 */ /* MD_ComM_3218 */
P2CONST(ComM_ConfigType, AUTOMATIC, COMM_INIT_DATA)       ComM_ConfigPtr = NULL_PTR; /* UREQ00035484 */

# define COMM_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"
#endif /* (COMM_USE_INIT_POINTER == STD_ON) */

/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
#define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ComM_CalculateHighestComMode()
**********************************************************************************************************************/
/*! \brief      Calculates the target highest communication mode of a channel by using the 'highest win' strategy
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \param[out] internalRequest         set to TRUE if an internal request via user, Dcm or coordinated PNC exists on the channel
 *  \return     The target highest communication mode of a channel
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-5379, SPEC-5255, SPEC-5462, SPEC-19856, SPEC-19846, SPEC-5413, SPEC-5454, SPEC-5475, SPEC-5457,
 *  \trace      SPEC-5426, SPEC-5111, SPEC-5138, SPEC-5080, SPEC-5085
 *********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_StateType, COMM_CODE) ComM_CalculateHighestComMode( NetworkHandleType channel, boolean *internalRequest );

/**********************************************************************************************************************
  ComM_ChannelStateTransition()
**********************************************************************************************************************/
/*! \brief      Performs a state transition on the given channel according to the target (highest requested) mode.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \param[in]  highestComModeReq       the target state of the transition, the highest requested mode
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-5483, SPEC-5472, SPEC-5479, SPEC-5463, SPEC-5469, SPEC-5474, SPEC-5397
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_ChannelStateTransition( NetworkHandleType channel, ComM_StateType highestComModeReq );

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
/**********************************************************************************************************************
  ComM_ProcessPassiveWakeUp()
**********************************************************************************************************************/
/*! \brief      Stores the states requested by bus (externally) after a Passive Wake-up occurred
 *  \details    -
 *  \param[in]  channel                 local channel handle where the wake-up event occurred
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_ProcessPassiveWakeUp( NetworkHandleType channel );
#endif

#if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
/**********************************************************************************************************************
  ComM_IsUserRequestingChannel()
**********************************************************************************************************************/
/*! \brief      Determines if a user is requesting the channel.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \return     TRUE                    a channel user requests FULL_COM or a PNC user requests FULL_COM (if PNC coordination is disabled).
 *  \return     FALSE                   otherwise.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_IsUserRequestingChannel( NetworkHandleType channel );
#endif

/**********************************************************************************************************************
  ComM_ChannelIsRequestPending()
**********************************************************************************************************************/
/*! \brief      Determines if a pending communication request exists on the channel. The function checks all communication
 *              requests that can occur in NO_COM mode: user requests and passive wake-ups. EIRA/ERA and Dcm requests are
 *              not relevant because they can occur only if communication is on.
 *  \details    The function is used by EcuM fixed and by BswM to evaluate the channel state before a sleep/shutdown.
 *  \param[in]  channel                 local channel handle
 *  \return     TRUE                    a passive wake-up occurred or a channel or PNC is requesting FULL_COM
 *  \return     FALSE                   otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ChannelIsRequestPending(NetworkHandleType channel);

#if ((COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON) || (COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
/**********************************************************************************************************************
  ComM_ChannelHandleTimers()
**********************************************************************************************************************/
/*! \brief      Handles Minimum FULL_COM mode timer and Nm Light timer of the channel
 *  \details    -
 *  \param[in]  channel                 local channel handler
 *  \param[in]  internalRequest         TRUE an internal request via user, Dcm or coordinated PNC exists on the channel
 *                                      FALSE otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-47932, SPEC-5395, SPEC-5396
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_ChannelHandleTimers( NetworkHandleType channel, boolean internalRequest );
#endif

#if (COMM_EXTENDED_RAM_CHECK == STD_ON)
/**********************************************************************************************************************
  ComM_ChannelGetMaxStateAfterExtRamCheck()
**********************************************************************************************************************/
/*! \brief      Provides the highest possible state according to the result of Extended RAM Check.
 *  \details    -
 *  \param[in]  channel                 local channel handler
 *  \param[in]  targetState             target communication state
 *  \return     COMM_NO_COM_NO_PENDING_REQUEST if Extended RAM Check status was CANSM_DISABLE_COMMUNICATION
 *  \return     COMM_NO_COM_REQUEST_PENDING if Extended RAM Check status was CANSM_DISABLE_COMMUNICATION_REPEAT
 *  \return     targetState otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_ChannelGetMaxStateAfterExtRamCheck( NetworkHandleType channel, ComM_StateType targetState );
#endif

#if (COMM_PNC_ACTIVE_COORD == STD_ON)
/**********************************************************************************************************************
  ComM_PncGetGwChannelRequest()
**********************************************************************************************************************/
/*! \brief      Calculates the requested state of the PN gateway channel depending on its Gateway Type and the highest requested mode of the PNCs
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \return     The requested state of the PN gateway channel
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC( ComM_StateType, COMM_CODE ) ComM_PncGetGwChannelRequest( NetworkHandleType channel );
#endif

#if (COMM_PNC_ACTIVE_COORD == STD_ON)
/**********************************************************************************************************************
  ComM_PncGetGwChannelState()
**********************************************************************************************************************/
/*! \brief      Calculates the target state of a PN gateway channel depending on its Gateway Type and the requested PNC mode
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \param[in]  highestPNComModeReq     the requested PNC mode
 *  \return     The target state of the PN gateway channel
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC( ComM_StateType, COMM_CODE ) ComM_PncGetGwChannelState( NetworkHandleType channel, ComM_PncModeType highestPNComModeReq );
#endif

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNCCHANNELMAPPING == STD_ON))
/**********************************************************************************************************************
  ComM_PncInFullComWakesUpTheChannel()
**********************************************************************************************************************/
/*! \brief      Determines if at least one PNC on the channel is in PNC_FULL_COMMUNICATION mode.
 *  \details    The function shall not be used if Partial Network Coordination Limitation is enabled, it does not take
 *              the limitation status of the channel into account.
 *  \param[in]  channel                 local channel handle
 *  \param[in]  highestRequest   the current highest channel request
 *  \return     COMM_FULL_COM_READY_SLEEP if the current highest request is COMM_NO_COM_NO_PENDING_REQUEST and at least 
 *              one PNC on this channel is in PNC_FULL_COMMUNICATION mode. Otherwise highestRequest (no changes).
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_PncInFullComWakesUpTheChannel(NetworkHandleType channel, ComM_StateType highestRequest);
#endif

#if (COMM_WAKEUP_INHIBITION == STD_ON)
/**********************************************************************************************************************
  ComM_PreventWakeUpActive()
**********************************************************************************************************************/
/*! \brief      Determines whether Prevent Wake-up is active on the channel.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \return     TRUE                    Prevent Wake-up is active on the channel
 *  \return     FALSE                   otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *  \trace      SPEC-5140, SPEC-5131
 *********************************************************************************************************************/
COMM_LOCAL FUNC(boolean, COMM_CODE) ComM_PreventWakeUpActive( NetworkHandleType channel );
#endif

#if ((COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON) && (COMM_MODE_LIMITATION == STD_ON))
/**********************************************************************************************************************
  ComM_NoComLimitationActive()
**********************************************************************************************************************/
/*! \brief      Determines whether Mode Limitation NO_COM is active on the channel.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \return     TRUE                    Mode Limitation to NO_COM is active on the channel
 *  \return     FALSE                   otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
COMM_LOCAL FUNC(boolean, COMM_CODE) ComM_NoComLimitationActive( NetworkHandleType channel );
#endif

#if ((COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON) && ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON)))
/**********************************************************************************************************************
  ComM_ChannelIsLimited()
**********************************************************************************************************************/
/*! \brief      Determines whether Mode Limitation NO_COM or Prevent Wake-up is active on the channel.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \return     TRUE                    Mode Limitation NO_COM or Prevent Wake-up is active on the channel
 *  \return     FALSE                   otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC( boolean, COMM_CODE) ComM_ChannelIsLimited( NetworkHandleType channel );
#endif

#if (COMM_RESETAFTERFORCINGNOCOMMOFCHANNEL == STD_ON)
/**********************************************************************************************************************
  ComM_ChannelResetAfterForcingNoComm()
**********************************************************************************************************************/
/*!
 * \brief       Initiates a reset after all channels entered NO_COM and at least one channel has an active Mode Limitation
 *              and Reset After Forcing NO_COM enabled.
 * \details     -
 * \param[in]   -
 * \pre         -
 * \context     ANY
 * \reentrant   TRUE
 * \synchronous TRUE
 * \trace       CREQ-116030
 * \trace       SPEC-2818113
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_ChannelResetAfterForcingNoComm( void );
#endif

#if (COMM_USERMODENOTIFUNC == STD_ON)
/**********************************************************************************************************************
  ComM_StateChangeNotification()
**********************************************************************************************************************/
/*! \brief      Called if BusSM mode has changed on the channel. It notifies users about a mode change if applicable.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *  \trace      CREQ-1269
 *  \trace      SPEC-5098, SPEC-19802, SPEC-5266
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_StateChangeNotification( NetworkHandleType channel );
#endif

#if( COMM_FULL_COMM_REQUEST_NOTIF == STD_ON )
/*********************************************************************************************************************
  ComM_CurrentChannelRequestUpdate()
*********************************************************************************************************************/
/*! \brief      This function updates the set of ComM users currently requesting FULL_COM for the channel.
 *  \details    The set is stored in the static variable ComM_FullComRequesters[]. Then it calls 
 *              ComM_CurrentChannelRequestNotification which detects if the set has changed and notifies RTE via the 
 *              optional sender-receiver interface 'ComM_CurrentChannelRequest'.
 *  \param[in]  channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_CurrentChannelRequestUpdate( NetworkHandleType channel );
#endif

#if ( COMM_PNC_SUPPORT == STD_ON )
/**********************************************************************************************************************
  ComM_PncInit()
**********************************************************************************************************************/
/*! \brief      Initialization of PNC related data.
 *  \details    -
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-19845, SPEC-19781
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncInit(void);

# if (COMM_PNCCHANNELMAPPING == STD_ON)
/**********************************************************************************************************************
  ComM_PncModeArbitration()
**********************************************************************************************************************/
/*! \brief      Determines if a PNC mapped to the channel has to perform a state transition or not and initiates
 *              a state transition if so.
 *  \details    -
 *  \param[in]  channel                 local channel handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-19808
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncModeArbitration( NetworkHandleType channel );
# endif

# if (COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON)
/**********************************************************************************************************************
  ComM_PncModeArbitrationWithoutChannels()
**********************************************************************************************************************/
/*! \brief      Determines if a PNC without channels has to perform a state transition or not and initiates
 *              a state transition if so.
 *  \details    -
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncModeArbitrationWithoutChannels(void);
# endif

/**********************************************************************************************************************
  ComM_PncStateTransition()
**********************************************************************************************************************/
/*! \brief      Performs state transitions to reach the target requested PNC state.
 *  \details    -
 *  \param[in]  ComM_CurrentPn          local PNC handle
 *  \param[in]  highestComModeReq       the target requested PNC state
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-19784, SPEC-19803, SPEC-19878, SPEC-19865, SPEC-19815
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncStateTransition( ComM_PncIterType ComM_CurrentPn, ComM_PncModeType highestComModeReq );

# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
/**********************************************************************************************************************
  ComM_PncIsOnlySystemUserRequesting()
**********************************************************************************************************************/
/*! \brief      Determines whether only the system user is requesting the PNC (via ERA) or regular PNC user.
 *  \details    -
 *  \param[in]  pncIndex                local PNC handle
 *  \param[in]  byteIndex               byte index of UserReqPncFullCom
 *  \return     TRUE                    if in the given request byte only the system user request is stored and no other PNC user request.
 *  \return     FALSE                   if at least one PNC user (not the system user) stored the request in the given byte.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC( boolean, COMM_CODE) ComM_PncIsOnlySystemUserRequesting( ComM_PncIterType pncIndex, ComM_UserReqPncFullComIterType byteIndex );

/**********************************************************************************************************************
  ComM_PncIsEraReceivedOnActiveChannel()
**********************************************************************************************************************/
/*! \brief      Determines whether a request is received via ERA on a channel with GW type ACTIVE. This is needed to
 *              calculate the target PNC state.
 *  \details    -
 *  \param[in]  pncIndex                local PNC handle
 *  \return     TRUE                    if at least one request is received via ERA on a channel with GW type ACTIVE
 *  \return     FALSE                   otherwise.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC( boolean, COMM_CODE) ComM_PncIsEraReceivedOnActiveChannel( ComM_PncIterType pncIndex );
# endif

/**********************************************************************************************************************
  ComM_CalculateHighestPNComMode()
**********************************************************************************************************************/
/*! \brief      Calculates the highest communication mode request for the PNC.
 *  \details    -
 *  \param[in]  pncIndex                local PNC handle
 *  \param[in]  pncCanBeRequested       The parameter is only used if PNC Routing Limitation feature is active
 *                                      TRUE: PNC is allowed to enter PNC_REQUESTED state, Routing Limitation is disabled on at least one channel
 *                                      FALSE: otherwise, ComM inhibits all FULL_COM requests to the PNC
 *  \return     Highest requested PNC mode
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-2818028, SPEC-2818290, SPEC-19872, SPEC-19786, SPEC-19866, SPEC-19806, SPEC-19857, SPEC-2818042,
 *  \trace      SPEC-19838, SPEC-19785, SPEC-19853
 *********************************************************************************************************************/
COMM_LOCAL FUNC(ComM_PncModeType, COMM_CODE) ComM_CalculateHighestPNComMode( ComM_PncIterType pncIndex, boolean pncCanBeRequested );

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/**********************************************************************************************************************
  ComM_PncRoutingLimitationHandleChannels()
**********************************************************************************************************************/
/*! \brief      Special handling (attaching and detaching) of channels while PNC is in state PNC_REQUESTED.
 *  \details    If the feature 'PNC To Channel Routing Limitation' is activated, channels can be attached or detached
 *              while PNC is in state PNC_REQUESTED by de-activating or activating the limitation. Here we ensure that:
 *              1) if the channel has been attached to PNC, EIRA with PNC bit = 1 is sent out or
 *              2) if the channel has been detached from PNC, EIRA with PNC bit = 0 is sent out on the channel.
 *              Note: attaching when entering NM_REPEAT_MESSAGE state is handled in ComM_Nm_StateChangeNotification().
 *              Note: function ComM_PncModeSendSignal() cannot be used because it handles all PNC channels.
 *  \param[in]  InternalPncId           local PNC handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncRoutingLimitationHandleChannels( ComM_PncIterType InternalPncId );

/**********************************************************************************************************************
  ComM_PncIsEraRequestReceivedOnChannel()
**********************************************************************************************************************/
/*! \brief      Determines if at least one PNC is requested via ERA_RX signal received on the given channel
 *  \details    -
 *  \param[in]  Channel                 local channel handle
 *  \return     TRUE                    if at least one PNC is requested via ERA_RX signal received on the given channel
 *  \return     FALSE                   otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL FUNC( boolean, COMM_CODE ) ComM_PncIsEraRequestReceivedOnChannel( NetworkHandleType  Channel );

/**********************************************************************************************************************
  ComM_PncRoutingLimitationSetState()
**********************************************************************************************************************/
/*! \brief      Updates the PNC Routing Limitation state depending on input parameters highestPNComModeReq and pncRequestIsPending
 *  \details    -
 *  \param[in]  channel              -   local channel handle
 *  \param[in]  highestPNComModeReq  -   the highest requested mode of Pncs mapped to the channel
 *  \param[in]  pncRequestIsPending  -   TRUE - at least one FULL_COM request for a PNC mapped to the channel exists
 *                                      FALSE - otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncRoutingLimitationSetState( CONST(NetworkHandleType, AUTOMATIC) channel, CONST(ComM_PncModeType, AUTOMATIC) highestPNComModeReq, CONST(boolean, AUTOMATIC) pncRequestIsPending );
# endif

# if (COMM_PNC_PS_TIMER > 0U)
/**********************************************************************************************************************
  ComM_HandlePncPrepareSleepTimer()
**********************************************************************************************************************/
/*! \brief      Decrements the PNC Prepare Sleep Timer for all PNCs and updates the bus-side request if the timer has expired.
 *  \details    -
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      CREQ-109081
 *  \trace      SPEC-19889
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_HandlePncPrepareSleepTimer( void );
# endif

# if (COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON)
/**********************************************************************************************************************
  ComM_PncModeSendSignal()
**********************************************************************************************************************/
/*! \brief      Processing of EIRA_TX transmission requests. The function is available if at least one EIRA_TX signal is present.
 *  \details    -
 *  \param[in]  PncHandle               internal PNC index to send EIRA TX signals for
 *  \param[in]  activeState             Defines the value of PNC bit in the COM signal to be sent:
 *                                      TRUE - PNC entered PNC_REQUESTED state, PNC bit = 1
 *                                      FALSE - PNC left PNC_REQUESTED state, PNC bit = 0
 *  \param[in]  SigSendType             Defines the target GW type of channels where COM signal shall be sent:
 *                                      COMM_SEND_ACTIVE_SIG_ONLY - send only on channels with GW type ACTIVE
 *                                      COMM_SEND_PASSIVE_SIG_ONLY - send only on channels with GW type PASSIVE
 *                                      COMM_SEND_ALL_SIG - send on all channels, this is to be used if PNC Gateway feature is disabled.
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      SPEC-19783, SPEC-19817, SPEC-19801
 *********************************************************************************************************************/
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncModeSendSignal( ComM_PncIterType PncHandle, boolean activeState, uint8 SigSendType );
# endif

# if ( COMM_USERMODENOTIFUNC == STD_ON )
/***********************************************************************************************************************
 *  ComM_PncStateChangeNotification()
 **********************************************************************************************************************/
/*! \brief      Notifies ComM user about a PNC main state change. If more than one PNC is assigned to a user, notify the lowest
 *              PNC state if it has changed since the last notification.
 *  \details    -
 *  \return     E_OK                    user notification is successful
 *  \return     E_NOT_OK                otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  FALSE
 *  \trace      CREQ-1269
 **********************************************************************************************************************/
COMM_LOCAL FUNC(Std_ReturnType, COMM_CODE) ComM_PncStateChangeNotification( void );
# endif

/**********************************************************************************************************************
  ComM_PncSetBitInSignal()
**********************************************************************************************************************/
/*! \brief      Sets PNC bit in the signal to 1.
 *  \details    -
 *  \param[in]  InternalSignalId        internal signal handle where to set the PNC bit
 *  \param[in]  InternalPncId           internal PNC handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncSetBitInSignal( ComM_SizeOfPncSignalType InternalSignalId, ComM_PncIterType InternalPncId );

/**********************************************************************************************************************
  ComM_PncClearBitInSignal()
**********************************************************************************************************************/
/*! \brief      Sets PNC bit in the signal to 0.
 *  \details    -
 *  \param[in]  InternalSignalId        internal signal handle where to set the PNC bit
 *  \param[in]  InternalPncId           internal PNC handle
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncClearBitInSignal( ComM_SizeOfPncSignalType InternalSignalId, ComM_PncIterType InternalPncId );
#endif

#if (COMM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
  ComM_InitCheckGeneratedData()
**********************************************************************************************************************/
/*! \brief      Checks generated data for correctness.
 *  \details    -
 *  \return     COMM_E_NO_ERROR             check is successful
 *  \return     COMM_E_WRONG_GENERATED_DATA otherwise
 *  \pre        -
 *  \context    TASK
 *  \reentrant  TRUE
 *********************************************************************************************************************/
COMM_LOCAL_INLINE FUNC(uint8, COMM_CODE) ComM_InitCheckGeneratedData(void);
#endif

/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

#if (COMM_PNC_SUPPORT == STD_ON)
/***********************************************************************************************************************
 *  ComM_PncStateTransition()
 **********************************************************************************************************************/
/*!
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
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncStateTransition( ComM_PncIterType ComM_CurrentPn, ComM_PncModeType highestComModeReq )
{
  /* #10 If the highest requested PNC mode differs from the currently active PNC mode, perform as many
   * state transitions as needed to reach the highest requested PNC mode.
   *     1) Send COM signal if entering or leaving PNC Requested state,
   *     2) Set the new PNC state,
   *     3) Notify BswM about the new PNC state (BusSM states of channels are not considered),
   *     4) Handle PNC Prepare Sleep Timer if applicable,
   *     5) Store a flag to notify PNC users about the new state if entering or leaving PNC Full Communication mode. */
  do
  {
    /* #20 PNC shall stay in Prepare Sleep state if PNC Prepare Sleep timer is running. */
# if (COMM_PNC_PS_TIMER > 0U)
    if ((ComM_GetPncPSleepTimer(ComM_CurrentPn) > 0) && (highestComModeReq <= COMM_PNC_PREPARE_SLEEP))
    {
      highestComModeReq = COMM_PNC_PREPARE_SLEEP;
    }
# endif

    if (highestComModeReq != ComM_GetActivePncComMode(ComM_CurrentPn))
    {
      switch (ComM_GetActivePncComMode(ComM_CurrentPn))
      {
      /* #30 State transition from COMM_PNC_NO_COMMUNICATION state. */
      case COMM_PNC_NO_COMMUNICATION:
        switch (highestComModeReq)
        {
        /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_REQUESTED */
        case COMM_PNC_REQUESTED:
# if (COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON)
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_ALL_SIG);
# endif

          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_REQUESTED);
# if ( COMM_USERMODENOTIFUNC == STD_ON )
          ComM_NotifyPncStateChange = TRUE;
# endif
          break;

        /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_REQUESTED_PASSIVE */
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
        case COMM_PNC_REQUESTED_PASSIVE:
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_ACTIVE_SIG_ONLY);
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED_PASSIVE); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_REQUESTED);
#  if ( COMM_USERMODENOTIFUNC == STD_ON )
          ComM_NotifyPncStateChange = TRUE;
#  endif
          break;
# endif

        /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_READY_SLEEP */
        case COMM_PNC_READY_SLEEP:
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_READY_SLEEP); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_READY_SLEEP);
# if ( COMM_USERMODENOTIFUNC == STD_ON )
          ComM_NotifyPncStateChange = TRUE;
# endif
          break;

        /* COMM_PNC_NO_COMMUNICATION -> COMM_PNC_PREPARE_SLEEP */
# if ((COMM_PNC_PS_TIMER > 0U) && ((COMM_SYNCHRONOUS_WAKE_UP == STD_ON) || (COMM_WAKEUPENABLEDOFPNC == STD_ON)))
        case COMM_PNC_PREPARE_SLEEP:
          /* Note: it is ensured that transition is only performed if COMM_PNC_PS_TIMER > 0 and 
           * (COMM_SYNCHRONOUS_WAKE_UP == STD_ON or COMM_WAKEUPENABLEDOFPNC == STD_ON) */
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_PREPARE_SLEEP); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_PREPARE_SLEEP);
          ComM_SetPncPSleepTimer(ComM_CurrentPn, COMM_PNC_PS_TIMER); /* SBSW_COMM_PNC_CSL02 */
#  if ( COMM_USERMODENOTIFUNC == STD_ON )
          ComM_NotifyPncStateChange = TRUE;
#  endif
          break;
# endif
        default: /* COV_COMM_MISRA */
          break;
        }
        break;

      /* #40 State transition from COMM_PNC_PREPARE_SLEEP state. */
# if (COMM_PNC_PS_TIMER > 0U)
      case COMM_PNC_PREPARE_SLEEP:
        switch (highestComModeReq)
        {
        /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_REQUESTED */
        case COMM_PNC_REQUESTED:
#  if (COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON)
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_ALL_SIG);
#  endif
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_REQUESTED);
          break;

        /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_REQUESTED_PASSIVE */
#  if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
        case COMM_PNC_REQUESTED_PASSIVE:
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_ACTIVE_SIG_ONLY);
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED_PASSIVE); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_REQUESTED);
          break;
#  endif

        /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_READY_SLEEP */   
        case COMM_PNC_READY_SLEEP:
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_READY_SLEEP); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_READY_SLEEP);
          break;

        /* COMM_PNC_PREPARE_SLEEP -> COMM_PNC_NO_COMMUNICATION */
        case COMM_PNC_NO_COMMUNICATION:
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_NO_COMMUNICATION);
#  if ( COMM_USERMODENOTIFUNC == STD_ON )
          ComM_NotifyPncStateChange = TRUE;
#  endif
          break;

        default: /* COV_COMM_MISRA */
          break;
        }

        /* When leaving COMM_PNC_PREPARE_SLEEP state, always stop the timer and reset ComM_BusPncComModeReq[] 
        if no EIRA = 1 signal received for the PNC. Needed e.g. in case PNC is not considered by Nm filter mask.
        Possible scenario: Synchronous Wake-up, FULL_COM request, NO_COM request. In this case highestComModeReq 
        shall be COMM_PNC_NO_COMMUNICATION and PNC shall enter COMM_PNC_PREPARE_SLEEP. (ESCAN00077600). */
        ComM_SetPncPSleepTimer(ComM_CurrentPn, 0); /* SBSW_COMM_PNC_CSL02 */
#  if ((COMM_SYNCHRONOUS_WAKE_UP == STD_ON) || (COMM_WAKEUPENABLEDOFPNC == STD_ON))
        if(ComM_GetBusPncComModeReq(ComM_CurrentPn) == COMM_PNC_PREPARE_SLEEP)
        {
          ComM_SetBusPncComModeReq(ComM_CurrentPn, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
        }
#  endif

        break;
# endif

      /* #50 State transition from COMM_PNC_READY_SLEEP state. */
      case COMM_PNC_READY_SLEEP:
        switch (highestComModeReq)
        {
        /* COMM_PNC_READY_SLEEP -> COMM_PNC_REQUESTED */
        case COMM_PNC_REQUESTED:
# if (COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON)
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_ALL_SIG);
# endif
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_REQUESTED);
          break;

        /* COMM_PNC_READY_SLEEP -> COMM_PNC_REQUESTED_PASSIVE, if COMM_PNC_ACTIVE_COORD == STD_ON */
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
        case COMM_PNC_REQUESTED_PASSIVE:
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_ACTIVE_SIG_ONLY);
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED_PASSIVE); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_REQUESTED);
          break;
# endif

        case COMM_PNC_NO_COMMUNICATION:
          /* Always indicate COMM_PNC_PREPARE_SLEEP to BswM, even if the state is omitted in case COMM_PNC_PS_TIMER == 0. */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_PREPARE_SLEEP);

# if (COMM_PNC_PS_TIMER == 0U)
          /* Special case if COMM_PNC_PREPARE_SLEEP == 0: COMM_PNC_READY_SLEEP -> COMM_PNC_NO_COMMUNICATION (ESCAN00067357) */
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_NO_COMMUNICATION);
#   if ( COMM_USERMODENOTIFUNC == STD_ON )
          ComM_NotifyPncStateChange = TRUE;
#   endif
# else  /* COMM_PNC_PS_TIMER > 0 */
          /* COMM_PNC_READY_SLEEP -> COMM_PNC_PREPARE_SLEEP */
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_PREPARE_SLEEP); /* SBSW_COMM_PNC_CSL02 */
          ComM_SetPncPSleepTimer(ComM_CurrentPn, COMM_PNC_PS_TIMER); /* SBSW_COMM_PNC_CSL02 */
# endif /* COMM_PNC_PS_TIMER */
          break;

        default: /* COV_COMM_MISRA */
          break;
        }
        break;

# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
      /* #60 State transition from COMM_PNC_REQUESTED_PASSIVE state. */
      case COMM_PNC_REQUESTED_PASSIVE:
        if(highestComModeReq == COMM_PNC_REQUESTED)
        {
          /* COMM_PNC_REQUESTED_PASSIVE -> COMM_PNC_REQUESTED, if COMM_PNC_ACTIVE_COORD == STD_ON */
          ComM_PncModeSendSignal(ComM_CurrentPn, TRUE, COMM_SEND_PASSIVE_SIG_ONLY);
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED); /* SBSW_COMM_PNC_CSL02 */
        }
        else
        {
          /* COMM_PNC_REQUESTED_PASSIVE -> COMM_PNC_READY_SLEEP, if COMM_PNC_ACTIVE_COORD == STD_ON.
          Note: there are only two possible transitions from COMM_PNC_REQUESTED_PASSIVE state, therefore using if..else is ok */
          ComM_PncModeSendSignal(ComM_CurrentPn, FALSE, COMM_SEND_ACTIVE_SIG_ONLY);
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_READY_SLEEP); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_READY_SLEEP);
        }
        break;
# endif

      /* #70 State transition from COMM_PNC_REQUESTED state. */
      case COMM_PNC_REQUESTED:
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
        if(highestComModeReq == COMM_PNC_REQUESTED_PASSIVE)
        {
          /* COMM_PNC_REQUESTED -> COMM_PNC_REQUESTED_PASSIVE, if COMM_PNC_ACTIVE_COORD == STD_ON */
          ComM_PncModeSendSignal(ComM_CurrentPn, FALSE, COMM_SEND_PASSIVE_SIG_ONLY);
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_REQUESTED_PASSIVE); /* SBSW_COMM_PNC_CSL02 */
        }
        else
# endif
        {
          /* COMM_PNC_REQUESTED -> COMM_PNC_READY_SLEEP
          Note: there are only two possible transitions from COMM_PNC_REQUESTED state, therefore using if..else is ok */
# if (COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON)
          ComM_PncModeSendSignal(ComM_CurrentPn, FALSE, COMM_SEND_ALL_SIG);
# endif
          ComM_SetActivePncComMode(ComM_CurrentPn, COMM_PNC_READY_SLEEP); /* SBSW_COMM_PNC_CSL02 */
          BswM_ComM_CurrentPNCMode(ComM_GetPncIdOfPnc(ComM_CurrentPn), COMM_PNC_READY_SLEEP);
        }
        break;

      default: /* COV_COMM_MISRA */
        break;
      }
    }
  } while (highestComModeReq != ComM_GetActivePncComMode(ComM_CurrentPn));
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNCCHANNELMAPPING == STD_ON)
/***********************************************************************************************************************
 *  ComM_PncModeArbitration()
 **********************************************************************************************************************/
/*!
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
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncModeArbitration(NetworkHandleType channel)
{
  ComM_PncModeType highestComModeReq;
#  if (COMM_PNC_ACTIVE_COORD == STD_ON)
  ComM_PncChannelMappingEndIdxOfPncPbType pncChIndex;
  boolean allCoordinatedChannelsAreInFullCom;
#   if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  boolean pncCanBeRequested;
#   endif
#  endif

  ComM_PncPbIndIterType pncPbIndIter;
  ComM_PncIterType pncIndex;

  for (pncPbIndIter = ComM_GetPncPbIndStartIdxOfChannelPb(channel);
       pncPbIndIter < ComM_GetPncPbIndEndIdxOfChannelPb(channel);
       pncPbIndIter++)
  {
    pncIndex = (ComM_PncIterType)ComM_GetPncPbInd(pncPbIndIter);

#  if (COMM_PNC_ACTIVE_COORD == STD_ON)
    allCoordinatedChannelsAreInFullCom = TRUE;
#   if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
    pncCanBeRequested = FALSE;
#   endif

    /* #10 If a PNC has channels, a potential state change of the PNC can be performed in context of current channel if
    *     1) the PNC is mapped to the current channel and
    *     2) all coordinated PNC channels are in FULL_COM mode in case PNC Gateway functionality is enabled.
    *     If the feature PNC to Channel Routing Limitation is enabled, only channels without limitation are considered.
    *     E.g. channels with limitation can be in NO_COM mode but PNC can change its state nevertheless. */
    for (pncChIndex = ComM_GetPncChannelMappingStartIdxOfPncPb(pncIndex);
         pncChIndex < ComM_GetPncChannelMappingEndIdxOfPncPb(pncIndex);
         pncChIndex++)
    {
#   if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
      /* Example: assume PNC is on CAN1 and CAN2 and routing is limited on CAN1. If PNC is requested, it changes to PNC_REQUESTED
       * as soon as CAN2 is in FULL_COM mode. The mode of CAN1 is not evaluated. */
      if( ComM_PncToChannelRoutingState[ComM_GetPncChannelMapping(pncChIndex)] != COMM_PNCROUTING_LIMITED )
      {
        /* Note: found a channel without Routing Limitation, it will be passed to ComM_CalculateHighestPNComMode() later */
        pncCanBeRequested = TRUE;
#   endif
        if( (ComM_ActiveComMode[ComM_GetPncChannelMapping(pncChIndex)] & COMM_FULL_COMMUNICATION) == 0u ) /*lint !e539 positive indentation is intended */
        {
          allCoordinatedChannelsAreInFullCom = FALSE;
        }
#   if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
      }
#   endif
    }

    /* #20 If a PNC can perform a state transition in the context of the current channel' task, calculate the highest requested mode
     *     of the PNC and perform the corresponding state transition. */
    highestComModeReq = COMM_PNC_NO_COMMUNICATION;
    if (allCoordinatedChannelsAreInFullCom == TRUE)
#  endif
    {
      /* Note: highestComModeReq shall be COMM_PNC_NO_COMMUNICATION (default) as long as at least one channel is not in FULL_COMM yet.
       * This is to ensure that a state transition (activation) of a coordinated PNC is performed AFTER all assigned channels have entered FULL_COMM. */
#  if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
      highestComModeReq = ComM_CalculateHighestPNComMode(pncIndex, pncCanBeRequested);
#  else
      highestComModeReq = ComM_CalculateHighestPNComMode(pncIndex, TRUE); /* 2nd parameter is not used */
#  endif
    }

    if (highestComModeReq != ComM_GetActivePncComMode(pncIndex))
    {
      ComM_PncStateTransition(pncIndex, highestComModeReq);
    }
#  if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
    else if(ComM_GetActivePncComMode(pncIndex) > COMM_PNC_READY_SLEEP)
    {
      ComM_PncRoutingLimitationHandleChannels( pncIndex );
    }
    else
    {
      /* nothing to do */
    }
#  endif
  } /* Iteration over PNCs */

#  if (COMM_ISDEF_PNCPBINDSTARTIDXOFCHANNELPB == STD_ON)
  COMM_DUMMY_STATEMENT(channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
}
# endif
#endif

#if (COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ComM_PncModeArbitrationWithoutChannels()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncModeArbitrationWithoutChannels(void)
{
  ComM_PncIterType pncIndex;
  ComM_PncModeType highestComModeReq;

  /* #10 If Extended PNC Functionality is enabled, a PNC may have no channels assigned. A potential state change of the PNC
   *     is always to be performed in context of Channel 0.
   *     Note: The function is called for Channel 0 even if it is disabled in the current variant. However, it is not necessary
   *     to check ComM_IsEnabledOfChannel, because no PNC will be assigned to such a disabled channel. */
  for (pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
  {
# if (COMM_PNCCHANNELMAPPING == STD_ON)
    if (ComM_GetPncChannelMappingStartIdxOfPncPb(pncIndex) == COMM_NO_PNCCHANNELMAPPINGSTARTIDXOFPNCPB)
# endif
    {
      highestComModeReq = ComM_CalculateHighestPNComMode(pncIndex, TRUE); /* 2nd parameter is not used */

      if (highestComModeReq != ComM_GetActivePncComMode(pncIndex))
      {
        ComM_PncStateTransition(pncIndex, highestComModeReq);
      }
    }
  }
}
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/***********************************************************************************************************************
 *  ComM_PncRoutingLimitationHandleChannels()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncRoutingLimitationHandleChannels( ComM_PncIterType InternalPncId )
{
  ComM_PncSignalIndIterType ComM_PncSignalMappingIndex;
  ComM_SizeOfPncSignalType ComM_SignalIndex;
  ComM_SizeOfChannelType ComM_ChannelIndex;

  for(ComM_PncSignalMappingIndex = ComM_GetPncSignalIndStartIdxOfPncPb(InternalPncId); ComM_PncSignalMappingIndex < ComM_GetPncSignalIndEndIdxOfPncPb(InternalPncId); ComM_PncSignalMappingIndex++)
  {
    ComM_SignalIndex = ComM_GetPncSignalInd(ComM_PncSignalMappingIndex);
    if (ComM_GetTypeOfPncSignal(ComM_SignalIndex) == COMM_EIRA_TX_TYPEOFPNCSIGNAL)
    {
      ComM_ChannelIndex = ComM_GetChannelIdxOfPncSignal(ComM_SignalIndex);

      /* #10 Attaching: PNC routing is not limited and PNC bit = 0 was sent on the channel, send PNC bit = 1 now. */
      if( ((ComM_PncToChannelRoutingState[ComM_ChannelIndex] & COMM_PNCROUTING_NOT_LIMITED) != 0x00) &&
          (!ComM_IsSignalStoredPncBitSet(ComM_SignalIndex, InternalPncId)) )
      {
#  if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
        if( (ComM_GetGwTypeOfChannel(ComM_ChannelIndex) == COMM_GATEWAY_TYPE_PASSIVE) && (ComM_GetActivePncComMode(InternalPncId) == COMM_PNC_REQUESTED_PASSIVE) )
        {
          /* PNC is requested via ERAp=1 from PASSIVE channel, do not keep the channel awake and do not mirror the request back */
        }
        else
#  endif
        {
          ComM_PncSetBitInSignal(ComM_SignalIndex, InternalPncId);
          ComM_ExecuteComSendSignal(ComM_SignalIndex, ComM_GetAddrPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(ComM_SignalIndex))); /* SBSW_COMM_CALL_WITH_PTR_TO_CONST */

#  if (COMM_PNCNMREQUESTOFCHANNEL == STD_ON)
          if (ComM_IsPncNmRequestOfChannel(ComM_ChannelIndex)) /* COV_COMM_SUBSET_OF_ELEMENTS */
          {
            (void)Nm_NetworkRequest(ComM_ChannelIndex);
          }
#  endif
        }
      }
      /* #20 Detaching: PNC routing is limited and PNC bit = 1 was sent on the channel, send PNC bit = 0 now. Valid for any GW type. */
      else if( (ComM_PncToChannelRoutingState[ComM_ChannelIndex] == COMM_PNCROUTING_LIMITED) &&
               (ComM_IsSignalStoredPncBitSet(ComM_SignalIndex, InternalPncId)) )
      {
          ComM_PncClearBitInSignal(ComM_SignalIndex, InternalPncId);
          ComM_ExecuteComSendSignal(ComM_SignalIndex, ComM_GetAddrPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(ComM_SignalIndex))); /* SBSW_COMM_CALL_WITH_PTR_TO_CONST */
      }
      else
      {
        /* nothing to do */
      }
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
# endif
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
/***********************************************************************************************************************
 *  ComM_PncSetBitInSignal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncSetBitInSignal(ComM_SizeOfPncSignalType InternalSignalId, ComM_PncIterType InternalPncId)
{
  /* #10 Calculate the new value of PNC signal byte by setting the corresponding PNC bit to 1. */
  ComM_SizeOfPncSignalValuesType signalByteIndex = (ComM_SizeOfPncSignalValuesType)(ComM_GetPncSignalValuesStartIdxOfPncSignal(InternalSignalId) + ComM_GetSignalByteIndexOfPncPb(InternalPncId));
  ComM_PncSignalValuesType signalByte = (ComM_PncSignalValuesType)(ComM_GetPncSignalValues(signalByteIndex) | ComM_GetSetMaskOfPnc(InternalPncId));

  /* #20 Update the PNC byte in the signal with the new value. */
  if( signalByteIndex < ComM_GetSizeOfPncSignalValues() ) /* COV_COMM_GENDATA_CHECK */ /* PRQA S 3355, 3358 */ /* MD_ComM_3355_3358 */
  {
    ComM_SetPncSignalValues(signalByteIndex, signalByte); /* SBSW_COMM_CSL01 */
  }

# if (COMM_ACTIVE_PNC == 1U)
  COMM_DUMMY_STATEMENT(InternalPncId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

# if (COMM_ISDEF_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL == STD_ON)
  COMM_DUMMY_STATEMENT(InternalSignalId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
/***********************************************************************************************************************
 *  ComM_PncClearBitInSignal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncClearBitInSignal(ComM_SizeOfPncSignalType InternalSignalId, ComM_PncIterType InternalPncId)
{
  /* #10 Calculate the new value of PNC signal byte by setting the corresponding PNC bit to 0. */
  ComM_SizeOfPncSignalValuesType signalByteIndex = (ComM_SizeOfPncSignalValuesType)(ComM_GetPncSignalValuesStartIdxOfPncSignal(InternalSignalId) + ComM_GetSignalByteIndexOfPncPb(InternalPncId));
  ComM_PncSignalValuesType signalByte = (ComM_PncSignalValuesType)(ComM_GetPncSignalValues(signalByteIndex) & ComM_GetClearMaskOfPnc(InternalPncId));

  /* #20 Update the PNC byte in the signal with the new value. */
  if( signalByteIndex < ComM_GetSizeOfPncSignalValues() ) /* COV_COMM_GENDATA_CHECK */ /* PRQA S 3355, 3358 */ /* MD_ComM_3355_3358 */
  {
    ComM_SetPncSignalValues(signalByteIndex, signalByte); /* SBSW_COMM_CSL01 */
  }

# if (COMM_ACTIVE_PNC == 1U)
  COMM_DUMMY_STATEMENT(InternalPncId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

# if (COMM_ISDEF_PNCSIGNALVALUESSTARTIDXOFPNCSIGNAL == STD_ON)
  COMM_DUMMY_STATEMENT(InternalSignalId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_PNC_PS_TIMER > 0U)
/***********************************************************************************************************************
 *  ComM_HandlePncPrepareSleepTimer()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_HandlePncPrepareSleepTimer( void )
{
  /* #10 For each PNC check the PNC Prepare Sleep Timer. If the timer is started, decrement it. If the timer is expired
   *     and PNC is not requested, set the bus requested mode to COMM_PNC_NO_COMMUNICATION to allow PNC to enter COMM_PNC_NO_COMMUNICATION. */
  ComM_PncIterType pncIndex;

# if (COMM_PNC_CHECK_ENABLED_AT_RUNTIME == STD_ON)
  if (ComM_HasPncPb())
# endif
  {
    for(pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
    {
      if(ComM_GetPncPSleepTimer(pncIndex) > 0) /* PNC state is always COMM_PNC_PREPARE_SLEEP in this case, no need to check it. */
      {
        ComM_DecPncPSleepTimer(pncIndex); /* SBSW_COMM_PNC_CSL02 */
        if( (ComM_GetBusPncComModeReq(pncIndex) == COMM_PNC_PREPARE_SLEEP) && (ComM_GetPncPSleepTimer(pncIndex) == 0) )
        {
          ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
        }
      }
    }
  }
}
#endif

#if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/*********************************************************************************************************************
 *  ComM_LimitPncToChannelRouting()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitPncToChannelRouting( PNCHandleType Pnc, NetworkHandleType Channel, boolean Status )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_PncIterType pncIndex;
  ComM_SizeOfPncLimitationType index;
  ComM_PncLimitationType value;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus == (ComM_InitStatusType)COMM_UNINIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Channel': it must be valid and PNC routing limitation must be supported on the channel. */
  /* Note: it is ensured by the code generator that only active channels having GW type != NONE support routing limitation. */
  else if ((Channel >= ComM_GetSizeOfChannelPb()) || (!ComM_IsPncLimitationUsedOfChannelPb(Channel)))
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */

    /* Get the internal PNC index from the given PNC identifier */
    for( pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++ )
    {
      if (Pnc == ComM_GetPncIdOfPnc(pncIndex))
      {
        break;
      }
    }

    /* #30 Check parameter 'Pnc': it must be a valid PNC identifier. */
    if( pncIndex < ComM_GetSizeOfPnc() )
    {
      /* #40 If parameter checks are successful, store the PNC to Channel Routing Limitation status. */
      if( Status == TRUE )
      {
        /* Limitation is activated */
        value = (ComM_PncLimitationType)(ComM_GetPncLimitation((ComM_SizeOfPncLimitationType)(ComM_GetPncLimitationStartIdxOfChannelPb(Channel) + ComM_GetSignalByteIndexOfPncPb(pncIndex))) | ComM_GetSetMaskOfPnc(pncIndex));
      }
      else
      {
        /* Limitation is de-activated */
        value = (ComM_PncLimitationType)(ComM_GetPncLimitation((ComM_SizeOfPncLimitationType)(ComM_GetPncLimitationStartIdxOfChannelPb(Channel) + ComM_GetSignalByteIndexOfPncPb(pncIndex))) & ComM_GetClearMaskOfPnc(pncIndex));
      }

      index = (ComM_SizeOfPncLimitationType)(ComM_GetPncLimitationStartIdxOfChannelPb(Channel) + ComM_GetSignalByteIndexOfPncPb(pncIndex));

      if( index < ComM_GetSizeOfPncLimitation() ) /* COV_COMM_GENDATA_CHECK */
      {
        ComM_SetPncLimitation(index, value); /* SBSW_COMM_CSL01 */
        retVal = E_OK;
      }
# if (COMM_DEV_ERROR_REPORT == STD_ON)
      else
      {
        errorId = COMM_E_WRONG_GENERATED_DATA;
      }
# endif
    }
# if (COMM_DEV_ERROR_REPORT == STD_ON)
    else
    {
      errorId = COMM_E_WRONG_PARAMETERS;
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  /* #50 Report errors if applicable. */
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_LIMITPNCTOCHANNELROUTING, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}
#endif

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_EXISTS_EIRA_TX_TYPEOFPNCSIGNAL == STD_ON))
/**********************************************************************************************************************
 *  ComM_PncModeSendSignal()
 *********************************************************************************************************************/
/*!
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
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_PncModeSendSignal(ComM_PncIterType PncHandle, boolean activeState, uint8 SigSendType)
{
  ComM_PncSignalIndIterType signalMappingIndex;
  ComM_SizeOfPncSignalType signalIndex;
# if ((COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON) && (COMM_PNCNMREQUESTOFCHANNEL == STD_ON))
  ComM_PncChannelMappingEndIdxOfPncPbType pncChannelMappingIndex;
# endif

  /* #10 Iterate over EIRA_TX signals mapped to the given PNC. Send the corresponding COM signal if
   *     1) the GW type of the corresponding channel matches the given SigSendType or
   *     2) all EIRA_TX signals have to be sent.
   *     The signal value (PNC bit) is set according to the PNC activation given by activeState.
   *     If PNC Routing Limitation is enabled, PNC activation can be set only if routing is not limited on the channel. */
  for(signalMappingIndex = ComM_GetPncSignalIndStartIdxOfPncPb(PncHandle); signalMappingIndex < ComM_GetPncSignalIndEndIdxOfPncPb(PncHandle); signalMappingIndex++)
  {
    signalIndex = ComM_GetPncSignalInd(signalMappingIndex);
# if (COMM_EXISTS_ERA_RX_TYPEOFPNCSIGNAL == STD_ON)
    if (ComM_GetTypeOfPncSignal(signalIndex) == COMM_EIRA_TX_TYPEOFPNCSIGNAL) /* COV_COMM_SUBSET_OF_ELEMENTS */ /* Signal Type can be EIRA_TX or ERA_RX */
# endif
    {
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
      if ((SigSendType == ComM_GetGwTypeOfChannel(ComM_GetChannelIdxOfPncSignal(signalIndex))) || (SigSendType == COMM_SEND_ALL_SIG))
# endif
      {
        if(activeState == TRUE)
        {
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
          if( ComM_PncToChannelRoutingState[ComM_GetChannelIdxOfPncSignal(signalIndex)] != COMM_PNCROUTING_LIMITED )
# endif
          {
            ComM_PncSetBitInSignal(signalIndex, PncHandle);
            ComM_ExecuteComSendSignal(signalIndex, ComM_GetAddrPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(signalIndex))); /* SBSW_COMM_CALL_WITH_PTR_TO_CONST */
          }
        }
        else
        {
          ComM_PncClearBitInSignal(signalIndex, PncHandle);
          ComM_ExecuteComSendSignal(signalIndex, ComM_GetAddrPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(signalIndex))); /* SBSW_COMM_CALL_WITH_PTR_TO_CONST */
        }

        /* #20 Call Nm_NetworkRequest() if PNC is activated and the parameter 'PNC Nm Request' is enabled on the channel.
         *   In case PNC Extended Functionality is enabled, only call Nm_NetworkRequest() if PNC is mapped to the channel.
         *   In case PNC Routing Limitation is enabled, only call Nm_NetworkRequest() if Routing is not limited on the channel.
         */
# if (COMM_PNCNMREQUESTOFCHANNEL == STD_ON)
        if (activeState == TRUE)
        {
#  if (COMM_ISDEF_PNCNMREQUESTOFCHANNEL == STD_OFF)
          if (ComM_IsPncNmRequestOfChannel(ComM_GetChannelIdxOfPncSignal(signalIndex))) /* COV_COMM_SUBSET_OF_ELEMENTS */
#  endif
          {
#  if (COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON)
            for (pncChannelMappingIndex = ComM_GetPncChannelMappingStartIdxOfPncPb(PncHandle);
                 pncChannelMappingIndex < ComM_GetPncChannelMappingEndIdxOfPncPb(PncHandle);
                 pncChannelMappingIndex++) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
            {
              if (ComM_GetPncChannelMapping(pncChannelMappingIndex) == ComM_GetChannelIdxOfPncSignal(signalIndex)) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
              {
                (void)Nm_NetworkRequest(ComM_GetChannelIdxOfPncSignal(signalIndex));
                break;
              }
            }
#  else
            /* Note: In normal PNC functionality, additional PNC signals without a PNC - Channel assignment are only allowed for preparing
             * for a PB-L usecase. In this case, the additional signals are automatically filtered in the generator, so we don't need
             * to verify the PNC - Channel assignment. The generator guarantees that PNC Signals exist only if there is a corresponding
             * PNC - Channel assignment. */
#   if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
            /* This is to prevent calling Nm_NetworkRequest() if Limitation is de-activated temporarily because Nm is in state NM_STATE_REPEAT_MESSAGE. */
            if( (ComM_PncToChannelRoutingState[ComM_GetChannelIdxOfPncSignal(signalIndex)] & COMM_PNCROUTING_NOT_LIMITED) != 0x00 )
#   endif
            {
              (void)Nm_NetworkRequest(ComM_GetChannelIdxOfPncSignal(signalIndex));
            }
#  endif
          }
        }
# endif
      }
    }
  }

# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_OFF)
  COMM_DUMMY_STATEMENT(SigSendType); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_EXISTS_EIRA_RX_TYPEOFPNCSIGNAL == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncProcessRxSignalEira()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEira(ComM_SizeOfPncSignalType InternalSignalId, const uint8 *SignalDataRx)
{
#  if (COMM_PNC_MAX_NUMBER_OF_EIRA_RX > 1U)
  uint8 SigValuesArb;
  ComM_PncSignalIterType signalIndex;
#  endif
  ComM_SizeOfPncType pncIndex;

  /* #10 Iterate over PNCs and update the target PNC state. */
  for (pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
  {
    if((SignalDataRx[ComM_GetSignalByteIndexOfPncPb(pncIndex)] & ComM_GetSetMaskOfPnc(pncIndex)) != 0u)
    {
      /* #110 If a PNC is requested via EIRA RX, set the target state to COMM_PNC_READY_SLEEP. */
      ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_READY_SLEEP); /* SBSW_COMM_PNC_CSL02 */
      ComM_PncSetBitInSignal(InternalSignalId, pncIndex);
    }
    else
    {
      /* #120 If a PNC is released via EIRA RX, check if it is requested on other bus types.
       *      If it is released on all other bus types, set the target state to COMM_PNC_NO_COMMUNICATION. */
      ComM_PncClearBitInSignal(InternalSignalId, pncIndex);
#  if (COMM_PNC_MAX_NUMBER_OF_EIRA_RX > 1U) /* If only one EIRA RX (bus type), no need to loop over signals */
      SigValuesArb = 0;
      for (signalIndex = 0; signalIndex < ComM_GetSizeOfPncSignal(); signalIndex++ )
      {
        if (ComM_GetTypeOfPncSignal(signalIndex) == COMM_EIRA_RX_TYPEOFPNCSIGNAL) /* COV_COMM_SUBSET_OF_ELEMENTS */
        {
          SigValuesArb |= ComM_GetPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(signalIndex) + ComM_GetSignalByteIndexOfPncPb(pncIndex));
        }
      }

      if ((SigValuesArb & ComM_GetSetMaskOfPnc(pncIndex)) == 0u)
#  endif
      {
        ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
      }
    }
  }
}
# endif
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_ACTIVE_COORD == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncProcessRxSignalEra()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_PncProcessRxSignalEra(ComM_SizeOfPncSignalType InternalSignalId, const uint8 *SignalDataRx)
{
  uint8 SigValuesArb;
  ComM_PncSignalIterType signalIndex;
  ComM_SizeOfPncType pncIndex;
  ComM_PncSignalIndIterType ComM_PncSignalMappingIndex;

  /* #10 Iterate over PNCs and request the system user accordingly. */
  for(pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
  {
#  if (COMM_ISDEF_COORDINATEDOFPNC == STD_OFF)
    if(ComM_IsCoordinatedOfPnc(pncIndex)) /* COV_COMM_SUBSET_OF_ELEMENTS */ /*lint !e506 */
#  endif
    {
      if((SignalDataRx[ComM_GetSignalByteIndexOfPncPb(pncIndex)] & ComM_GetSetMaskOfPnc(pncIndex)) > 0)
      {
        /* #110 If a PNC is requested via ERA, request the corresponding system user. */
        ComM_PncSetBitInSignal(InternalSignalId, pncIndex);
        (void)ComM_RequestComMode(ComM_GetSystemUserOfPnc(pncIndex), COMM_FULL_COMMUNICATION);
      }
      else
      {
        /* #120 If a PNC is released on all related ERA signals, release the corresponding system user. */
        ComM_PncClearBitInSignal(InternalSignalId, pncIndex);
        SigValuesArb = 0;
        for (ComM_PncSignalMappingIndex = ComM_GetPncSignalIndStartIdxOfPncPb(pncIndex); ComM_PncSignalMappingIndex < ComM_GetPncSignalIndEndIdxOfPncPb(pncIndex); ComM_PncSignalMappingIndex++)
        {
          signalIndex = ComM_GetPncSignalInd(ComM_PncSignalMappingIndex);
          if (ComM_GetTypeOfPncSignal(signalIndex) == COMM_ERA_RX_TYPEOFPNCSIGNAL) /* COV_COMM_SUBSET_OF_ELEMENTS */
          {
            SigValuesArb |= ComM_GetPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(signalIndex) + ComM_GetSignalByteIndexOfPncPb(pncIndex));
          }
        }

        if((SigValuesArb & ComM_GetSetMaskOfPnc(pncIndex)) == 0u) /* COV_COMM_PNC_EXTENDED_SINGLE_ERA */
        {
          (void)ComM_RequestComMode(ComM_GetSystemUserOfPnc(pncIndex), COMM_NO_COMMUNICATION);
        }
      }
    }
  }
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
# endif
#endif

#if (( COMM_PNC_SUPPORT == STD_ON ) && ( COMM_USERMODENOTIFUNC == STD_ON ))
/**********************************************************************************************************************
 *  ComM_PncStateChangeNotification()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(Std_ReturnType, COMM_CODE) ComM_PncStateChangeNotification( void )
{
  uint8 userIndex;
  ComM_ModeType lowestUserMode;
  ComM_UserPncByteMaskEndIdxOfUserType iByteMaskIndex;
  ComM_PncIterType pncIndex;
  Std_ReturnType retValueUser = RTE_E_OK;
  Std_ReturnType retValueOverall = E_OK;

  /* #10 Iterate over users that have configured User Mode (state change) notification and are mapped to PNC. */
  for (userIndex = 0; userIndex < ComM_GetSizeOfUser(); userIndex++)
  {
    if (ComM_GetUserModeNotiFunc(userIndex) != NULL_PTR) /* COV_COMM_SUBSET_OF_ELEMENTS */
    {
      if (ComM_IsPncUserOfUser(userIndex))
      {
        /* #20 Calculate the lowest mode of all PNCs assigned to the current user. If at least one PNC
         *     is in COMM_PNC_NO_COMMUNICATION mode, the lowest mode is COMM_NO_COMMUNICATION. */
        lowestUserMode = COMM_FULL_COMMUNICATION;

        for (iByteMaskIndex = ComM_GetUserPncByteMaskStartIdxOfUser(userIndex); iByteMaskIndex < ComM_GetUserPncByteMaskEndIdxOfUser(userIndex); iByteMaskIndex++)
        {
          for (pncIndex = 0; (lowestUserMode == COMM_FULL_COMMUNICATION) && (pncIndex < ComM_GetSizeOfPnc()); pncIndex++)
          {
# if (COMM_ISDEF_PNCIDOFPNC == STD_OFF) /* STD_ON: only one PNC exists, no run-time check is needed */
            if (ComM_GetPncIdOfPnc(pncIndex) == ComM_GetPncIDOfUserPncByteMask(iByteMaskIndex)) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
# endif
            {
              if (ComM_GetActivePncComMode(pncIndex) == COMM_PNC_NO_COMMUNICATION)
              {
                lowestUserMode = COMM_NO_COMMUNICATION;
              }
            }
          }
        }

        /* #30 If a new mode is available for the current user, notify it using the Mode Switch Interface (sender-receiver) 'ComM_CurrentMode'. */
        if (lowestUserMode != ComM_GetLastStateChange(userIndex))
        {
          if (userIndex < ComM_GetSizeOfUserModeNotiFunc()) /* COV_COMM_GENDATA_CHECK */ /* PRQA S 3355, 3358 */ /* MD_ComM_3355_3358 */
          {
            switch (lowestUserMode)
            {
            case COMM_FULL_COMMUNICATION:
              retValueUser = ComM_GetUserModeNotiFunc(userIndex)(RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION); /* SBSW_COMM_UserModeNotiFunc_PointerCall */
              break;
            case COMM_NO_COMMUNICATION:
              retValueUser = ComM_GetUserModeNotiFunc(userIndex)(RTE_MODE_ComMMode_COMM_NO_COMMUNICATION);   /* SBSW_COMM_UserModeNotiFunc_PointerCall */
              break;
              /* PRQA S 2018 1 */ /* MD_ComM_2018 */
            default: /* COV_COMM_MISRA */
              break;
            }
          }

          /* #40 If notification to the current user was successful, update the mode to ensure that the same one will not be notified again.
           *     Otherwise the notification will be processed again in the next task. */
          if (retValueUser == RTE_E_OK)
          {
            ComM_SetLastStateChange(userIndex, lowestUserMode); /* SBSW_COMM_USER_CSL02 */ /*lint !e661 ComM_LastStateChange[] has a size relation to ComM_User[] */
          }
          else
          {
            retValueOverall = E_NOT_OK;
          }
        }
      }
    }
  }

  return retValueOverall;
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
 *  ComM_CalculateHighestComMode()
 **********************************************************************************************************************/
/*!
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
COMM_LOCAL FUNC( ComM_StateType, COMM_CODE ) ComM_CalculateHighestComMode( NetworkHandleType channel, boolean *internalRequest )
{
  /* ----- Local Variables ---------------------------------------------- */
  ComM_StateType lHighestRequest;
  *internalRequest = FALSE; /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */

  /*lint -e661 */
  SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

#if( COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON )
  /* #10 The highest requested mode is COMM_FULL_COM_NETWORK_REQUESTED if the following conditions are true:
   *   Communication shutdown on FlexRay is finished. (This is to counteract the so-called 'clique problem' on FlexRay) and:
   *     1) If Communication Inhibition is not active and at least one user mapped to the channel directly or via PNC requests FULL_COM or
   *     2) Dcm has requested communication (it does not take Communication Inhibition into account). */
  lHighestRequest = COMM_NO_COM_NO_PENDING_REQUEST;
# if( COMM_BUS_TYPE_FR_PRESENT == STD_ON )
  /* PRQA S 3689 1 */ /* MD_ComM_3689 */
  /* ComM postpones the execution of communication requests until FrSM indicates entering NO_COM mode.  */
  if( ComM_FrShutdown[channel] == FALSE )
# endif
  {
# if ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON))
    if (ComM_ChannelIsLimited(channel) == FALSE)
# endif
    {
      if (ComM_IsUserRequestingChannel(channel) == TRUE)
      {
        lHighestRequest = COMM_FULL_COM_NETWORK_REQUESTED;
        *internalRequest = TRUE; /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */
      }
    }

# if (COMM_DCM_INDICATION == STD_ON)
    /* PRQA S 3689 1 */ /* MD_ComM_3689 */
    if( ComM_IsDcmRequestActive(channel) )
    {
      lHighestRequest = COMM_FULL_COM_NETWORK_REQUESTED;
      *internalRequest = TRUE; /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */
    }
# endif
    /*lint +e443 */
  }
#endif

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNCCHANNELMAPPING == STD_ON))
  /* #20 If PN feature is enabled and the channel is not requested by a user or Dcm, the requested mode is the highest one of
   *     the mode resulting from the Gateway Type of the channel and the highest activation of PNCs mapped to it or
   *     COMM_FULL_COM_READY_SLEEP if at least one PNC mapped to the channel is in PNC_FULL_COMMUNICATION state. */
# if (COMM_ISDEF_PNCPBINDUSEDOFCHANNELPB == STD_OFF) /* there are some channels without PNCs */
  if (ComM_IsPncPbIndUsedOfChannelPb(channel)) /* COV_COMM_SUBSET_OF_ELEMENTS */
# endif
  {
# if (COMM_PNC_ACTIVE_COORD == STD_ON)
    if( lHighestRequest == COMM_NO_COM_NO_PENDING_REQUEST )
    {
      lHighestRequest = ComM_PncGetGwChannelRequest( channel );
      if (lHighestRequest == COMM_FULL_COM_NETWORK_REQUESTED)
      {
        *internalRequest = TRUE; /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */
      }
    }

#  if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
    if( lHighestRequest == COMM_FULL_COM_NETWORK_REQUESTED )
    {
      /* Enter the state COMM_PNCROUTING_NOT_LIMITED because channel is kept awake by a ComM user. */
      ComM_PncToChannelRoutingState[channel] |= COMM_PNCROUTING_NOT_LIMITED; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    }
    else
    {
      /* nothing to do */
    }
#  endif
# endif

    /* This to consider all PNCs including not coordinated ones */
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
    if (ComM_PncToChannelRoutingState[channel] != COMM_PNCROUTING_LIMITED)
# endif
    {
      lHighestRequest = ComM_PncInFullComWakesUpTheChannel( channel, lHighestRequest );
    }
  }
#endif

  /* #30 The requested mode shall be at least as high as requested via bus.
   *     Bus communication requests shall always be granted according to the 'highest win' strategy. */
#if( COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON )
  if ((lHighestRequest == COMM_NO_COM_NO_PENDING_REQUEST)
# if ((COMM_EXISTS_NONE_NMTYPEOFCHANNEL == STD_ON) || (COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON))
     || (ComM_BusComModeReq[channel] == COMM_FULL_COM_NETWORK_REQUESTED)
# endif
     )
#endif
  {
    lHighestRequest = ComM_BusComModeReq[channel];
  }

  /*lint +e661 */

  SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  return lHighestRequest;
} /* PRQA S 6010, 6030 */ /* MD_MSR_STPTH, MD_MSR_STCYC */

#if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  ComM_IsUserRequestingChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_IsUserRequestingChannel(NetworkHandleType channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isUserRequesting = FALSE;
  ComM_UserReqFullComIterType userReqFullComIndex;
# if (COMM_PNC_ACTIVE_COORD == STD_ON)
  ComM_UserByteMaskIterType userByteMaskIndex;
  ComM_UserIterType userIndex;
# endif

  /* #10 PNC Coordinator is enabled and at least one channel or PNC user is requesting FULL_COM:
   *     Return TRUE if the channel has no PNCs assigned, otherwise iterate over channel users to check if one of them is requesting FULL_COM.
   *     Note that PNC users are handled separately because of dependency to the Gateway Type of channel. */

  /* #20 PNC Coordinator is disabled and at least one channel or PNC user is requesting FULL_COM:
   *     Return TRUE, because there is no dependency to the Gateway Type of channel. */

  /*lint -e443 */
  /* PRQA S 3689 1 */ /* MD_ComM_3689 */
  for (userReqFullComIndex = ComM_GetUserReqFullComStartIdxOfChannelPb(channel); userReqFullComIndex < ComM_GetUserReqFullComEndIdxOfChannelPb(channel); userReqFullComIndex++)
  {
    /* PRQA S 3689 1 */ /* MD_ComM_3689 */
    if ((ComM_GetUserReqFullCom(userReqFullComIndex) != COMM_NO_REQUESTS) && (isUserRequesting == FALSE)) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
    {
      /* At least one user assigned to this channel requests FULL_COM. The 2nd condition is because there is no downgrade of highest request. */
# if (COMM_PNC_ACTIVE_COORD == STD_ON)
#  if (COMM_ISDEF_PNCPBINDUSEDOFCHANNELPB == STD_OFF) /* there are some channels without PNCs */
      if (!ComM_IsPncPbIndUsedOfChannelPb(channel)) /* COV_COMM_SUBSET_OF_ELEMENTS */
      {
        isUserRequesting = TRUE;
      }
      else
#  endif
      {
        for (userIndex = 0; userIndex < ComM_GetSizeOfUser(); userIndex++)
        {
          if (!ComM_IsPncUserOfUser(userIndex))
          {
            for (userByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(userIndex); userByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(userIndex); userByteMaskIndex++)
            /* PRQA S 0715 SUPPRESS_0715 */ /* MD_MSR_1.1 */
            {
              if ((ComM_GetChannelOfUserByteMask(userByteMaskIndex) == channel) &&
                  ((ComM_GetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(userByteMaskIndex)) & ComM_GetSetMaskOfUserByteMask(userByteMaskIndex)) != COMM_NO_REQUESTS))
              {
                isUserRequesting = TRUE;
                break;
              }
            }
            /* PRQA L:SUPPRESS_0715 */
          }
        }
      }
# else
      isUserRequesting = TRUE;
# endif
    }
  }

  /* if ((COMM_CONFIGURATION_VARIANT == COMM_CONFIGURATION_VARIANT_PRECOMPILE) && (COMM_ACTIVE_CHANNEL == 1U)) */
  COMM_DUMMY_STATEMENT(channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return isUserRequesting;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
 *  ComM_ChannelIsRequestPending()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(boolean, COMM_CODE) ComM_ChannelIsRequestPending( NetworkHandleType channel )
{
  /* ----- Local Variables ---------------------------------------------- */
  boolean isRequestPending = FALSE;
#if( COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON )
  ComM_UserReqFullComIterType userReqFullComIndex;
#endif

#if( COMM_PNC_SUPPORT == STD_ON )
# if( COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON )
  ComM_PncIterType pncIndex;
  ComM_UserReqPncFullComIterType userReqPncFullComIndex;
# endif
#endif

  /* #10 If a passive wake-up occurred on the channel, return a pending request. */
  if( ComM_BusComModeReq[channel] != COMM_NO_COM_NO_PENDING_REQUEST )
  {
    isRequestPending = TRUE;
  }

  /* #20 If a passive wake-up occurred on a FlexRay channel during shutdown, return a pending request. */
#if( COMM_BUS_TYPE_FR_PRESENT == STD_ON )
  else if(ComM_BusComModeReqFrShutdown[channel] != COMM_NO_COM_NO_PENDING_REQUEST)
  {
    isRequestPending = TRUE;
  }
#endif

  /* #30 If at least one user is requesting the channel and the channel is not limited, return a pending request. */
#if( COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON )
  else
  {
# if( (COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON) )
    if( ComM_ChannelIsLimited(channel) == FALSE )
# endif
    {
      for( userReqFullComIndex = ComM_GetUserReqFullComStartIdxOfChannelPb(channel);
           userReqFullComIndex < ComM_GetUserReqFullComEndIdxOfChannelPb(channel);
           userReqFullComIndex++ )
      {
        if( ComM_GetUserReqFullCom(userReqFullComIndex) != COMM_NO_REQUESTS )
        {
          isRequestPending = TRUE;
          break;
        }
      }
    }

    /* If PNC Routing Limitation is enabled, reject the request if no channel user requests FULL_COM and the channel has limited routing */
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
    if (isRequestPending == TRUE)
    {
      if ((ComM_IsUserRequestingChannel(channel) == FALSE) && (ComM_PncToChannelRoutingState[channel] == COMM_PNCROUTING_LIMITED))
      {
        isRequestPending = FALSE;
      }
    }
# endif
  }
#endif

    /* #40 If Extended PNC Functionality is enabled, a PNC may have no channels assigned. If a user is requesting such a PNC,
     *     return a pending request for each channel to ensure ECU staying in RUN mode. */
#if( COMM_PNC_SUPPORT == STD_ON )
# if( COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON )
  for( pncIndex = 0;
      (pncIndex < ComM_GetSizeOfPncPb()) && (isRequestPending == FALSE); /* break the loop as soon as a pending request is detected */
       pncIndex++ )
  {
#   if( COMM_PNCCHANNELMAPPING == STD_ON )
    /* The condition is true if PNC has no channels */
    if (ComM_GetPncChannelMappingStartIdxOfPncPb(pncIndex) == COMM_NO_PNCCHANNELMAPPINGSTARTIDXOFPNCPB)
#   endif
    {
      for( userReqPncFullComIndex = ComM_GetUserReqPncFullComStartIdxOfPncPb(pncIndex);
           userReqPncFullComIndex < ComM_GetUserReqPncFullComEndIdxOfPncPb(pncIndex);
           userReqPncFullComIndex++ )
      {
        if( ComM_GetUserReqPncFullCom(userReqPncFullComIndex) != COMM_NO_REQUESTS )
        {
          isRequestPending = TRUE;
          break;
        }
      }
    }
  }
# endif
#endif

  return isRequestPending;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#if (COMM_PNC_ACTIVE_COORD == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncGetGwChannelRequest()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC( ComM_StateType, COMM_CODE ) ComM_PncGetGwChannelRequest( NetworkHandleType channel )
{
  /* ----- Local Variables ---------------------------------------------- */
  ComM_PncIterType pncIndex;
  ComM_PncPbIndIterType pncPbIndIter;
  ComM_StateType gwChannelComMode;
  ComM_PncModeType highestPNComModeReq = COMM_PNC_NO_COMMUNICATION;
  ComM_PncModeType tmpPNComModeReq;
#  if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  boolean eraRequestReceivedOnChannel = FALSE;
  boolean pncRequestIsPending = FALSE;
#  endif

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Iterate over PNCs mapped to the channel and calculate the highest requested mode of the PNCs.
   *     Break the iteration once the highest possible mode (COMM_PNC_REQUESTED) is detected. */
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  if(ComM_PncIsEraRequestReceivedOnChannel(channel) == TRUE)
  {
    /* Routing to this channel is not limited because an ERA signal containing a PNC request is received on the channel */
    eraRequestReceivedOnChannel = TRUE;
  }
# endif

  for (pncPbIndIter = ComM_GetPncPbIndStartIdxOfChannelPb(channel);
      (pncPbIndIter < ComM_GetPncPbIndEndIdxOfChannelPb(channel)) && (highestPNComModeReq != COMM_PNC_REQUESTED);
       pncPbIndIter++) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
  {
    pncIndex = (ComM_PncIterType)ComM_GetPncPbInd(pncPbIndIter);

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
    /* Parameter pncCanBeRequested is TRUE because we first need the potentially highest PNC request and will consider the channel' limitation state later. */
    tmpPNComModeReq = ComM_CalculateHighestPNComMode(pncIndex, TRUE);
    if (tmpPNComModeReq >= COMM_PNC_REQUESTED)
    {
      pncRequestIsPending = TRUE;
      /* PNC mode may control the channel mode only if Routing Limitation state of the channel is COMM_PNCROUTING_NOT_LIMITED,
       * i.e. if routing of this PNC is not limited on the channel or limitation is de-activated due to reception of ERA=1. Otherwise ignore the PNC mode.
       * Note: PNC mode does not control the channel mode if limitation is de-activated because Nm is in state NM_REPEAT_MESSAGE or
       * if PNC is woken up by EIRA=1 (not ERA). */
      if((!ComM_IsPncLimitation(channel, pncIndex)) || (eraRequestReceivedOnChannel == TRUE))
      {
        highestPNComModeReq = tmpPNComModeReq;
      }
    }
# else
    /* Found a PN assigned to the current channel. Calculate the highest PN requested mode of all PNs on the channel */
    tmpPNComModeReq = ComM_CalculateHighestPNComMode(pncIndex, TRUE); /* the 2nd parameter is not evaluated */
    if (tmpPNComModeReq >= COMM_PNC_REQUESTED)
    {
      highestPNComModeReq = tmpPNComModeReq;
    }
# endif
  }

  /* #20 Get the requested channel state depending on the highest requested mode of the PNCs and the Gateway Type of the channel. */
  gwChannelComMode = ComM_PncGetGwChannelState(channel, highestPNComModeReq);

  /* #30 If PNC Routing Limitation is enabled, update the limitation state of the channel. */
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  ComM_PncRoutingLimitationSetState( channel, highestPNComModeReq, pncRequestIsPending );
# endif

  return gwChannelComMode;
}
#endif

#if (COMM_PNC_ACTIVE_COORD == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncGetGwChannelState()
 *********************************************************************************************************************/
/*!
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
COMM_LOCAL_INLINE FUNC( ComM_StateType, COMM_CODE ) ComM_PncGetGwChannelState( NetworkHandleType channel, ComM_PncModeType highestPNComModeReq )
{
  /* The function is used in conditions, which are not always evaluated because of 'short-circuit evaluation'. 
   * Therefore the function is not allowed to change the module' state i.e. write global variables.
   */

  /* ----- Local Variables ---------------------------------------------- */
  ComM_StateType gwChannelComMode;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 The requested channel state depends on the highest requested mode of the PNCs and the Gateway Type of the channel:
   *     COMM_FULL_COM_NETWORK_REQUESTED if at least one PNC on the channel
   *      1) is requested internally by a PNC user or externally via ERA that is originated from a channel with Gateway Type ACTIVE.
   *      2) is requested externally via ERA that is originated from a channel with Gateway Type PASSIVE and the current channel has Gateway Type ACTIVE.
   *     COMM_FULL_COM_READY_SLEEP otherwise and if at least one PNC on the channel is requested externally via ERA that
   *      is originated from a channel with Gateway Type PASSIVE and the current channel has Gateway Type PASSIVE.
   *     COMM_NO_COM_NO_PENDING_REQUEST otherwise. */
  if( highestPNComModeReq == COMM_PNC_REQUESTED )
  {
    gwChannelComMode = COMM_FULL_COM_NETWORK_REQUESTED;
  }
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
  else if( highestPNComModeReq == COMM_PNC_REQUESTED_PASSIVE )
  {
    if( ComM_GetGwTypeOfChannel(channel) == COMM_GATEWAY_TYPE_ACTIVE ) /* COV_COMM_SUBSET_OF_ELEMENTS */
    {
      /* Channels with GW type ACTIVE shall be requested actively. */
      gwChannelComMode = COMM_FULL_COM_NETWORK_REQUESTED;
    }
    else
    {
      /* Channels with GW type PASSIVE shall not be requested actively. Note: no check for GwType needed because it is ensured
       * per validation rule that a coordinated channel always has GwType ACTIVE or PASSIVE and never has GwType NONE. */
      gwChannelComMode = COMM_FULL_COM_READY_SLEEP;
    }
  }
# endif
  else
  {
    gwChannelComMode = COMM_NO_COM_NO_PENDING_REQUEST;
  }

# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_OFF)
  COMM_DUMMY_STATEMENT(channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return gwChannelComMode;
}
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncRoutingLimitationSetState()
 *********************************************************************************************************************/
/*!
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
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncRoutingLimitationSetState( CONST(NetworkHandleType, AUTOMATIC) channel, CONST(ComM_PncModeType, AUTOMATIC) highestPNComModeReq, CONST(boolean, AUTOMATIC) pncRequestIsPending )
{
  ComM_PncPbIndIterType pncPbIndIter;

  if( highestPNComModeReq >= COMM_PNC_REQUESTED )
  {
    /* #10 Enter the Routing Limitation state COMM_PNCROUTING_NOT_LIMITED if
     *     1) ERA=1 is received on the channel or
     *     2) ComM user requests FULL_COM for a PNC, which is not limited on the channel. */
    ComM_PncToChannelRoutingState[channel] |= COMM_PNCROUTING_NOT_LIMITED; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }
  else if( pncRequestIsPending == TRUE )
  {
    /* #20 Exit the Routing Limitation state COMM_PNCROUTING_NOT_LIMITED if
     *     1) All ComM users assigned to the channel request NO_COM and
     *     2) ERA=0 is received on the channel and
     *     3) All PNCs being in state PNC_REQUESTED are limited on the channel.
     *     Clear the COMM_PNCROUTING_NOT_LIMITED flag, note that Nm can be in state NM_STATE_REPEAT_MESSAGE. */
    ComM_PncToChannelRoutingState[channel] &= COMM_PNCROUTING_NOT_LIMITED_CLEAR; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }
  else
  {
    /* #30 Otherwise and if at least one PNC on the channel is limited, exit the Routing Limitation state COMM_PNCROUTING_NOT_LIMITED. */
    /* This is needed e.g. for the following scenario: a PNC is limited on all channels, requesting the PNC via user shall not activate it. */
    for (pncPbIndIter = ComM_GetPncPbIndStartIdxOfChannelPb(channel);
         pncPbIndIter < ComM_GetPncPbIndEndIdxOfChannelPb(channel);
         pncPbIndIter++)
    {
      if (ComM_IsPncLimitation(channel, ComM_GetPncPbInd(pncPbIndIter)))
      {
        ComM_PncToChannelRoutingState[channel] &= COMM_PNCROUTING_NOT_LIMITED_CLEAR; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
        break;
      }
    }
  }
}
# endif
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncIsEraRequestReceivedOnChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
COMM_LOCAL FUNC( boolean, COMM_CODE ) ComM_PncIsEraRequestReceivedOnChannel( NetworkHandleType  Channel )
{
  boolean isEraRequestReceivedOnChannel = FALSE;
  uint8 pncSignalByteIndex;
  ComM_SizeOfPncSignalType pncSignalIndex;

  for(pncSignalIndex = 0; pncSignalIndex < ComM_GetSizeOfPncSignal(); pncSignalIndex++) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
  {
    if((ComM_GetTypeOfPncSignal(pncSignalIndex) == COMM_ERA_RX_TYPEOFPNCSIGNAL) && (ComM_GetChannelIdxOfPncSignal(pncSignalIndex) == Channel))
    {
      for(pncSignalByteIndex = ComM_GetPncSignalValuesStartIdxOfPncSignal(pncSignalIndex); pncSignalByteIndex < ComM_GetPncSignalValuesEndIdxOfPncSignal(pncSignalIndex); pncSignalByteIndex++ )
      {
        if(ComM_GetPncSignalValues(pncSignalByteIndex) != 0x00)
        {
          /* #10 Return TRUE if at least one PNC is requested via ERA_RX signal on the given channel. Return FALSE otherwise. */
          isEraRequestReceivedOnChannel = TRUE;
          break;
        }
      }
      break; /* Because there is one ERA_RX signal per channel at most. */
    }
  }

  return isEraRequestReceivedOnChannel;
}
# endif
#endif

#if ((COMM_PNC_SUPPORT == STD_ON) && (COMM_PNCCHANNELMAPPING == STD_ON))
/**********************************************************************************************************************
 *  ComM_PncInFullComWakesUpTheChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_PncInFullComWakesUpTheChannel(NetworkHandleType channel, ComM_StateType highestRequest)
{
  /* ----- Local Variables ---------------------------------------------- */
  ComM_PncIterType pncIndex;
  ComM_PncPbIndIterType pncPbIndIter;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 Return COMM_FULL_COM_READY_SLEEP if current highest request is COMM_NO_COM_NO_PENDING_REQUEST and
   *   at least one PNC on this channel is in PNC_FULL_COMMUNICATION mode.
   *   Otherwise return the current highest request (no changes). */

  /* Note: if COMM_FULL_COM_READY_SLEEP ComM ensures that the channel is at least in COMM_FULL_COM_READY_SLEEP state. */
  /* ESCAN00066290: There is no downgrade of highest request. If detected COMM_FULL_COM_NETWORK_REQUESTED, then no need to check PNCs anymore */
  if (highestRequest == COMM_NO_COM_NO_PENDING_REQUEST)
  {
    for (pncPbIndIter = ComM_GetPncPbIndStartIdxOfChannelPb(channel);
         pncPbIndIter < ComM_GetPncPbIndEndIdxOfChannelPb(channel);
         pncPbIndIter++) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
    {
      pncIndex = (ComM_PncIterType)ComM_GetPncPbInd(pncPbIndIter);

      if(ComM_GetActivePncComMode(pncIndex) != COMM_PNC_NO_COMMUNICATION)
      {
        highestRequest = COMM_FULL_COM_READY_SLEEP;
        break;
      }
    }
  }

# if (COMM_ISDEF_PNCPBINDSTARTIDXOFCHANNELPB == STD_ON)
  COMM_DUMMY_STATEMENT(channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
  
  return highestRequest;
}
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncIsOnlySystemUserRequesting()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC( boolean, COMM_CODE) ComM_PncIsOnlySystemUserRequesting( ComM_PncIterType pncIndex, ComM_UserReqPncFullComIterType byteIndex )
{
  boolean retValue = FALSE;
  ComM_UserPncByteMaskStartIdxOfUserType uSysUserByteMaskIndex;

  /* #10 If the provided byteIndex corresponds to the system user, check whether a request from another PNC user (not the system user)
   *     is stored in this byte. Return TRUE if only a request of the system user is stored in the request byte.
   *     Note: if PNC is synchronized, there is exactly one system user and one byte index where the system user' request is stored. */
#  if (COMM_ISDEF_COORDINATEDOFPNC == STD_OFF)
  if(ComM_IsCoordinatedOfPnc(pncIndex)) /* COV_COMM_SUBSET_OF_ELEMENTS */
#  endif
  {
    uSysUserByteMaskIndex = ComM_GetUserPncByteMaskStartIdxOfUser(ComM_GetSystemUserOfPnc(pncIndex));
    if (byteIndex == ComM_GetUserReqPncFullComIdxOfUserPncByteMask(uSysUserByteMaskIndex))
    {
      if (((ComM_GetUserReqPncFullCom(byteIndex) & ComM_GetClearMaskOfUserPncByteMask(uSysUserByteMaskIndex)) == COMM_NO_REQUESTS))
      {
        retValue = TRUE;
      }
    }
  }

  COMM_DUMMY_STATEMENT(pncIndex); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  return retValue;
}
# endif
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncIsEraReceivedOnActiveChannel()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
COMM_LOCAL_INLINE FUNC( boolean, COMM_CODE) ComM_PncIsEraReceivedOnActiveChannel( ComM_PncIterType pncIndex )
{
  ComM_PncSignalIndIterType pncSignalIndIter;
  ComM_SizeOfPncSignalType  pncSignalInd;
  boolean retValue = FALSE;

  /* #10 Return TRUE if at least one PNC request is received via ERA on a channel with GW type ACTIVE. Otherwise return FALSE. */
  /* Note: if PNC is coordinated if an ERA signal is mapped to it */
  for (pncSignalIndIter = ComM_GetPncSignalIndStartIdxOfPncPb(pncIndex);
       pncSignalIndIter < ComM_GetPncSignalIndEndIdxOfPncPb(pncIndex);
       pncSignalIndIter++)
  {
    pncSignalInd = ComM_GetPncSignalInd(pncSignalIndIter);
    if (ComM_GetTypeOfPncSignal(pncSignalInd) == COMM_ERA_RX_TYPEOFPNCSIGNAL) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
    {
      if ((ComM_GetGwTypeOfChannel(ComM_GetChannelIdxOfPncSignal(pncSignalInd)) == COMM_GATEWAY_TYPE_ACTIVE) && (ComM_IsSignalStoredPncBitSet(pncSignalInd, pncIndex))) /* COV_COMM_PNC_EXTENDED_NO_ERA_ON_ACTIVE_CHANNEL */
      {
        retValue = TRUE;
        break;
      }
    }
  }

#  if (COMM_ACTIVE_PNC == 1U)
  COMM_DUMMY_STATEMENT(pncIndex); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
  return retValue;
}
# endif
#endif

#if ((COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON) && ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON)))
/**********************************************************************************************************************
 *  ComM_ChannelIsLimited()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC( boolean, COMM_CODE) ComM_ChannelIsLimited( NetworkHandleType channel )
{
  boolean retValue = FALSE;

  /* #10 Return TRUE if Mode Limitation or Prevent Wake-up is active on the channel.
   *     Otherwise return FALSE. */
  if (
# if (COMM_MODE_LIMITATION == STD_ON)
     /* PRQA S 3415 1 */ /* MD_ComM_3415 */
     (ComM_NoComLimitationActive(channel) == TRUE)
#  if (COMM_WAKEUP_INHIBITION == STD_ON)
      ||
#  endif
# endif
# if (COMM_WAKEUP_INHIBITION == STD_ON)
     /* PRQA S 3415 1 */ /* MD_ComM_3415 */
     (ComM_PreventWakeUpActive(channel) == TRUE)
# endif
     )
  {
    retValue = TRUE;
  }

  return retValue;
}
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  ComM_CalculateHighestPNComMode()
 **********************************************************************************************************************/
/*!
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
 */
COMM_LOCAL FUNC( ComM_PncModeType, COMM_CODE) ComM_CalculateHighestPNComMode( ComM_PncIterType pncIndex, boolean pncCanBeRequested )
{
  ComM_PncModeType lHighestRequest = COMM_PNC_NO_COMMUNICATION;
  ComM_UserReqPncFullComIterType  userReqPncFullComIndex;
# if ( (COMM_PNCCHANNELMAPPING == STD_ON) && \
      ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON)) )
    ComM_PncChannelMappingIterType pncChMappingIndex;
# endif

  SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  /* The guard below is needed to inhibit FULL_COM request to a PNC if all its channels have
   * Routing Limitation state COMM_PNCROUTING_LIMITED (pncCanBeRequested == FALSE). */
  if( pncCanBeRequested == TRUE )
# endif
  {
    /* #10 Iterate through PNC user request bytes in ComM_UserReqPncFullCom[] for the given PN.
     *     If at least one user request is detected, set the requested mode to
     *     COMM_PNC_REQUESTED_PASSIVE if only system user is requesting and Passive Gw Type is supported or
     *     COMM_PNC_REQUESTED otherwise. */

    /* PRQA S 3689 1 */ /* MD_ComM_3689 */
    for (userReqPncFullComIndex = ComM_GetUserReqPncFullComStartIdxOfPncPb(pncIndex);
         userReqPncFullComIndex < ComM_GetUserReqPncFullComEndIdxOfPncPb(pncIndex);
         userReqPncFullComIndex++)
    {
      /* PRQA S 3689 1 */ /* MD_ComM_3689 */
      if (ComM_GetUserReqPncFullCom(userReqPncFullComIndex) != COMM_NO_REQUESTS)
      {
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
        lHighestRequest = COMM_PNC_REQUESTED_PASSIVE;
        if (ComM_PncIsOnlySystemUserRequesting(pncIndex, userReqPncFullComIndex) == FALSE)
# endif
        {
          lHighestRequest = COMM_PNC_REQUESTED;
          break; /* Highest requested mode found */
        }
      }
    }

    /* #20 If Passive Gw Type is supported and PNC activation is received via ERA from an Active channel,
     *     set the requested mode to COMM_PNC_REQUESTED. */
# if (COMM_PNC_PASSIVE_GW_SUPPORT == STD_ON)
    if (lHighestRequest == COMM_PNC_REQUESTED_PASSIVE)
    {
      if (ComM_PncIsEraReceivedOnActiveChannel(pncIndex) == TRUE) /* COV_COMM_PNC_EXTENDED_NO_ERA_ON_ACTIVE_CHANNEL */
      {
        lHighestRequest = COMM_PNC_REQUESTED;
      }
    }
# endif

    /* #30 If Node Limitation NO_COM or Prevent Wake-up is active on at least one PNC channel, ComM shall inhibit FULL_COM requests. */
# if ( (COMM_PNCCHANNELMAPPING == STD_ON) && \
       ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON)) )
    for (pncChMappingIndex = ComM_GetPncChannelMappingStartIdxOfPncPb(pncIndex);
         pncChMappingIndex < ComM_GetPncChannelMappingEndIdxOfPncPb(pncIndex);
         pncChMappingIndex++) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
    {
#  if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON) /* COV_COMM_PNC_ON_CHANNELS_NM_PASSIVE */
      if (ComM_ChannelIsLimited(ComM_GetPncChannelMapping(pncChMappingIndex)) == TRUE) /* COV_COMM_PNC_ON_CHANNELS_NM_PASSIVE */
#  endif
      {
        lHighestRequest = COMM_PNC_NO_COMMUNICATION;
        break;
      }
    }
# endif
  }

  /* Do not allow PNC activation if pncCanBeRequested == FALSE, but always allow PNC de-activation */
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  if ((pncCanBeRequested == TRUE) || (ComM_GetActivePncComMode(pncIndex) != COMM_PNC_NO_COMMUNICATION))
# endif
  {
    /* #40 The requested mode shall be at least as requested via bus (EIRA). */
    if (ComM_GetBusPncComModeReq(pncIndex) > lHighestRequest)
    {
      lHighestRequest = ComM_GetBusPncComModeReq(pncIndex);
    }
# if (COMM_PNC_PS_TIMER > 0U)
    else if ((ComM_GetPncPSleepTimer(pncIndex) > 0) && (lHighestRequest <= COMM_PNC_PREPARE_SLEEP)) /* COV_COMM_PNC_ON_CHANNELS_NM_PASSIVE */
    {
      lHighestRequest = COMM_PNC_PREPARE_SLEEP;
    }
    else
    {
      /* Nothing to do. Statement is needed for MISRA-C:2004 compliance (Rule 14.10). */
    }
# endif
  }

  SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_OFF)
  COMM_DUMMY_STATEMENT(pncCanBeRequested); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return lHighestRequest;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (COMM_WAKEUP_INHIBITION == STD_ON)
/*********************************************************************************************************************
 *  ComM_PreventWakeUpActive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(boolean, COMM_CODE) ComM_PreventWakeUpActive( NetworkHandleType  channel )
{
  /* The function is used in conditions, which are not always evaluated because of 'short-circuit evaluation'. 
   * Therefore the function is not allowed to change the module' state i.e. write global variables.
   */

  boolean retValue = FALSE;
  
  /* #10 Return TRUE if Prevent Wake-up
   *     1) is allowed by ECU Group Classification and
   *     2) is active on the channel and
   *     3) the channel is not in FULL_COM mode. */
  if( (ComM_Inhibition.ComM_ECUGroupClassification & COMM_WAKEUP_INHIBITION_MASK) == COMM_WAKEUP_INHIBITION_MASK )
  {
    /* check if prevent wake up is active */
    if( (ComM_Inhibition.ComM_InhibitionStatus[channel] & COMM_WAKEUP_INHIBITION_MASK) == COMM_WAKEUP_INHIBITION_MASK )
    {
      if((ComM_ActiveComMode[channel] & COMM_FULL_COMMUNICATION) == 0u)
      {
        /* The inhibition shall not get active in FULL_COM mode */
        retValue = TRUE;
      }
    }
  }

  return retValue;
}
#endif

#if ((COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON) && (COMM_MODE_LIMITATION == STD_ON))
/*********************************************************************************************************************
 *  ComM_NoComLimitationActive()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(boolean, COMM_CODE) ComM_NoComLimitationActive( NetworkHandleType channel )
{
  /* The function is used in conditions, which are not always evaluated because of 'short-circuit evaluation'. 
   * Therefore the function is not allowed to change the module' state i.e. write global variables.
   */

  boolean retValue = FALSE;
  
  /* #10 Return TRUE if Mode Limitation to NO_COM
   *     1) is active because of NmType PASSIVE or
   *     2) is allowed by ECU Group Classification and
   *     3) is active on the channel */

# if (COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL == STD_ON)
  if (ComM_GetNmTypeOfChannel(channel) == COMM_PASSIVE_NMTYPEOFCHANNEL)
  {
    retValue = TRUE;
  }
  else
# endif
  {
    if( (ComM_Inhibition.ComM_ECUGroupClassification & COMM_MODE_LIMITATION_MASK) == COMM_MODE_LIMITATION_MASK )
    {
      if( (ComM_Inhibition.ComM_InhibitionStatus[channel] & COMM_MODE_LIMITATION_MASK) == COMM_MODE_LIMITATION_MASK )
      {
        retValue = TRUE;
      }
    }
  }

  return retValue;
}
#endif

#if (COMM_FULL_COMM_REQUEST_NOTIF == STD_ON)
/*********************************************************************************************************************
 *  ComM_CurrentChannelRequestUpdate()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_CurrentChannelRequestUpdate( NetworkHandleType channel )
{
  uint8 currentNumOfRequesters = 0u; /* Number of users requesting the channel */
  ComM_UserByteMaskEndIdxOfUserType iByteMaskIndex;
  uint8 userIndex;

  /* #10 Initialize the list with the default user handle. */
  for (userIndex = 0u; userIndex < ComM_GetSizeOfFullComRequesters(); userIndex++)
  {
    ComM_SetFullComRequesters(userIndex, 0xffu); /* SBSW_COMM_CSL01 */
  }

  /* #20 If communication inhibition is active all FULL_COM user requests for this channel are rejected. */
# if ( (COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON) )
  if (ComM_ChannelIsLimited(channel) == FALSE)
# endif
  {
    /* #30 Otherwise store handles of users that are mapped to the current channel and requesting FULL_COM. */
    for(userIndex = 0u; userIndex < ComM_GetSizeOfUser(); userIndex++)
    {
# if ( COMM_PNC_SUPPORT == STD_ON )
      if (!ComM_IsPncUserOfUser(userIndex))
# endif
      {
        for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(userIndex); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(userIndex); iByteMaskIndex++)
        {
          if (
# if (COMM_ACTIVE_CHANNEL > 1U) /* If only one channel exists, every channel user is always mapped to it. */
              (ComM_GetChannelOfUserByteMask(iByteMaskIndex) == channel) &&
# endif
              ((ComM_GetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(iByteMaskIndex)) & ComM_GetSetMaskOfUserByteMask(iByteMaskIndex)) != COMM_NO_REQUESTS))
          {
            if( currentNumOfRequesters < ComM_GetSizeOfFullComRequesters() ) /* COV_COMM_GENDATA_CHECK */
            {
              ComM_SetFullComRequesters(currentNumOfRequesters, userIndex); /* SBSW_COMM_CSL01 */ /* Justification is applicable because of the run-time check above */
              currentNumOfRequesters++;
            }
          }
        }
      }
    }
  }

  /* #40 Trigger notification via Sender-Receiver interface. */
  /* Note: The function below will evaluate ComM_FullComRequesters[] and if detected a change, it will notify RTE via
   * the optional sender-receiver interface ComM_CurrentChannelRequest */
  ComM_CurrentChannelRequestNotification( channel, currentNumOfRequesters );
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

/*********************************************************************************************************************
 *  ComM_TF_NoCom_NetReq()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_NoCom_NetReq(NetworkHandleType Channel)
{
#if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)

  /* #10 Request COMM_FULL_COMMUNICATION from the state manager. */
  ComM_RequestBusSMMode( Channel, COMM_FULL_COMMUNICATION );

  switch (ComM_GetNmTypeOfChannel(Channel))
  {
  /* #20 Nm variant NONE: once communication requested, ComM shall not trigger shutdown on the channel. */
# if (COMM_EXISTS_NONE_NMTYPEOFCHANNEL == STD_ON)
  case COMM_NONE_NMTYPEOFCHANNEL:
    ComM_BusComModeReq[Channel] = COMM_FULL_COM_NETWORK_REQUESTED; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    break;
# endif

  /* #30 Nm variant LIGHT: cancel the LIGHT SILENT timer (ComM_NmLightTimer variable is re-used). */
# if (COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL == STD_ON)
  case COMM_LIGHT_NMTYPEOFCHANNEL:
#  if (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON)
    ComM_SetNmLightTimer(Channel, 0); /* SBSW_COMM_CHANNEL_CSL02 */
#  endif

    /* #40 Nm variant LIGHT: start the timer for ComMTMinFullComModeDuration. */
    ComM_SetMinFullComModeTimer(Channel, ComM_GetMinFullComTimeOfChannel(Channel)); /* SBSW_COMM_CHANNEL_CSL02 */
    break;
# endif

  /* #50 Nm variant FULL: notify Nm about network request. */
# if (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_ON)
  case COMM_FULL_NMTYPEOFCHANNEL:
    (void)Nm_NetworkRequest(Channel);

    /* #60 Nm variant FULL: start the timer for ComMTMinFullComModeDuration. */
    /* ESCAN00081330 */
#  if (COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON)
    ComM_SetMinFullComModeTimer(Channel, ComM_GetMinFullComTimeOfChannel(Channel)); /* SBSW_COMM_CHANNEL_CSL02 */
#  endif
    break;
# endif
    /* PRQA S 2018 1 */ /* MD_ComM_2018 */
  default: /* COV_COMM_MISRA */
    break;
  }

#else
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/*********************************************************************************************************************
 *  ComM_TF_NoCom_FullReadySleep()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_NoCom_FullReadySleep(NetworkHandleType Channel)
{
  /* #10 If Nm is supported on the channel, request FULL_COM from BusSM and notify Nm about passive start-up. */
#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
# if (COMM_ISDEF_NMSUPPORTOFCHANNEL == STD_OFF)
  if (ComM_IsNmSupportOfChannel(Channel)) /* COV_COMM_SUBSET_OF_ELEMENTS */
# endif
  {
    ComM_RequestBusSMMode( Channel, COMM_FULL_COMMUNICATION );

    /* ComM shall call Nm_PassiveStartUp() when entering Ready Sleep for robustness reasons and ignore E_NOT_OK return value ESCAN00068132 */
    (void)Nm_PassiveStartUp(Channel);
  }
#else
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
  /* Note: the function cannot be called for channels with Nm Variant LIGHT because Minimum Full Com Duration
   * always exists for LIGHT and this results that channels enters Network Requested state and not Ready Sleep. */
}

/*********************************************************************************************************************
 *  ComM_TF_Full_SiCom()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_Full_SiCom( NetworkHandleType Channel )
{
#if (COMM_SILENTSUPPORTOFCHANNEL == STD_ON)
# if (COMM_ISDEF_SILENTSUPPORTOFCHANNEL == STD_OFF)
  if (ComM_IsSilentSupportOfChannel(Channel))
# endif
  {
# if (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON)
#  if (COMM_ISDEF_NMLIGHTSILENTDURATIONOFCHANNEL == STD_OFF)
    if (ComM_GetNmLightSilentDurationOfChannel(Channel) > 0x00u)
#  endif
    {
      /* #10 If Nm Variant is LIGHT and the LIGHT SILENT timer is configured, start the timer. */
      ComM_SetNmLightTimer(Channel, ComM_GetNmLightSilentDurationOfChannel(Channel)); /* SBSW_COMM_CHANNEL_CSL02 */
    }
# endif

    /* #20 Request COMM_SILENT_COMMUNICATION from BusSM. Silent mode is only available on CAN (except J1939Nm) or ETH with Nm Variants FULL or PASSIVE (ESCAN00069043) or LIGHT SILENT timer.
     *     Note: EthSM will ignore the mode request, but ComM shall trigger it for the sake of consistency because UdpNm indicates Prepare Bus Sleep Mode. */
    ComM_RequestBusSMMode( Channel, COMM_SILENT_COMMUNICATION );
  }
#else
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/*********************************************************************************************************************
 *  ComM_TF_ReadyS_NetReq()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_ReadyS_NetReq(NetworkHandleType Channel)
{
#if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)

  /* #10 If Nm Type is LIGHT, cancel the light timer. */
# if (COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON)
  ComM_SetNmLightTimer(Channel, 0); /* SBSW_COMM_CHANNEL_CSL02 */
# endif
  
  /* #20 If Nm Type is FULL, notify Nm about network requested. */
# if (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_ON)
#  if( COMM_ISDEF_NMTYPEOFCHANNEL == STD_OFF )
  if (ComM_GetNmTypeOfChannel(Channel) == COMM_FULL_NMTYPEOFCHANNEL) /* COV_COMM_SUBSET_OF_ELEMENTS */
#  endif
  {
    (void)Nm_NetworkRequest(Channel);
  }
# endif

# if ((COMM_NMLIGHTDURATIONOFCHANNEL == STD_OFF) && (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_OFF))
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#else
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/*********************************************************************************************************************
 *  ComM_TF_SiCom_NoCom()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_SiCom_NoCom(NetworkHandleType Channel)
{
#if (COMM_MODE_LIMITATION == STD_ON)
  ComM_UserReqFullComIterType userReqFullComIndex;
# if (( COMM_PNC_SUPPORT == STD_ON ) && ( COMM_PNCCHANNELMAPPING == STD_ON ) )
  ComM_UserReqPncFullComIterType userReqPncFullComIndex;
  ComM_PncPbIndIterType pncPbIndIter;
# endif
#endif
  
  /* #10 Set channel mode to NO_COM before requesting NO_COM from the BusSM to ensure accepting bus wake-ups. */
  ComM_ActiveComMode[Channel] = COMM_NO_COM_NO_PENDING_REQUEST; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */ /* ESCAN00091475 */

  ComM_RequestBusSMMode( Channel, COMM_NO_COMMUNICATION );

  /* #20 If the channel is limited to NO_COM, clear all FULL_COM requests for channel and PNC users. */
#if (COMM_MODE_LIMITATION == STD_ON)
# if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
  if (ComM_NoComLimitationActive(Channel) == TRUE)
# endif
  {
    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    for (userReqFullComIndex = ComM_GetUserReqFullComStartIdxOfChannelPb(Channel);
         userReqFullComIndex < ComM_GetUserReqFullComEndIdxOfChannelPb(Channel);
         userReqFullComIndex++)
    {
      ComM_SetUserReqFullCom(userReqFullComIndex, COMM_NO_REQUESTS); /* SBSW_COMM_UserReqFullCom_over_ChannelPb_or_ByteMask_CSL03 */
    }

# if (( COMM_PNC_SUPPORT == STD_ON ) && ( COMM_PNCCHANNELMAPPING == STD_ON ))
    for (pncPbIndIter = ComM_GetPncPbIndStartIdxOfChannelPb(Channel);
         pncPbIndIter < ComM_GetPncPbIndEndIdxOfChannelPb(Channel);
         pncPbIndIter++)
    {
      for (userReqPncFullComIndex = ComM_GetUserReqPncFullComStartIdxOfPncPb(ComM_GetPncPbInd(pncPbIndIter));
           userReqPncFullComIndex < ComM_GetUserReqPncFullComEndIdxOfPncPb(ComM_GetPncPbInd(pncPbIndIter));
           userReqPncFullComIndex++)
      {
        ComM_SetUserReqPncFullCom(userReqPncFullComIndex, COMM_NO_REQUESTS); /* SBSW_COMM_UserReqPncFullCom_over_UserPncByteMask_or_PncPb_CSL03 */
      }
    }
# endif /* COMM_PNC_SUPPORT == STD_ON */

    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
#endif /* COMM_MODE_LIMITATION */
}

/*********************************************************************************************************************
 *  ComM_TF_NetReq_ReadyS()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_NetReq_ReadyS(NetworkHandleType Channel)
{
#if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
  
  /* #10 If Nm Light timer is configured, start it. It is ensured by generator that Nm Type of the channel is LIGHT. */
# if (COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON)
#  if (COMM_ISDEF_NMLIGHTDURATIONOFCHANNEL == STD_OFF)
  if (ComM_GetNmLightDurationOfChannel(Channel) > 0)
#  endif
  {
    ComM_SetNmLightTimer(Channel, ComM_GetNmLightDurationOfChannel(Channel)); /* SBSW_COMM_CHANNEL_CSL02 */
  }
# endif

  /* #20 If Nm Type is FULL, notify Nm about network release. */
# if (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_ON)
#  if (COMM_ISDEF_NMTYPEOFCHANNEL == STD_OFF)
  if (ComM_GetNmTypeOfChannel(Channel) == COMM_FULL_NMTYPEOFCHANNEL)
#  endif
  {
    (void)Nm_NetworkRelease(Channel);
  }
# endif

# if ((COMM_NMLIGHTDURATIONOFCHANNEL == STD_OFF) && (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_OFF))
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#else
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/*********************************************************************************************************************
 *  ComM_TF_No_Action()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_No_Action(NetworkHandleType Channel)
{
  /* #10 There is no action for this sub-state transition. Use cases:
   * COMM_NO_COM_REQUEST_PENDING to COMM_NO_COM_NO_PENDING_REQUEST (communication was never allowed and user/DCM request is canceled)
   * COMM_NO_COM_NO_PENDING_REQUEST to COMM_NO_COM_REQUEST_PENDING (communication is requested and ComM waits for allowed notification)
   */
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}

/*********************************************************************************************************************
 *  ComM_TF_No_Transition()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
COMM_LOCAL FUNC(void, COMM_CODE) ComM_TF_No_Transition(NetworkHandleType Channel)
{
  /* #10 This is an invalid state transition, report a Det error. */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_MAINFUNCTION, COMM_E_NOSUPPORTED_MODECHANGE );
#endif

  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
}

#if (COMM_USERMODENOTIFUNC == STD_ON)
/**********************************************************************************************************************
 *  ComM_StateChangeNotification()
 **********************************************************************************************************************/
/*!
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
COMM_LOCAL FUNC(void, COMM_CODE) ComM_StateChangeNotification( NetworkHandleType channel )
{
  uint8 userIndex;
  ComM_ModeType ComM_CalcMode;
  Std_ReturnType retValue;
  Std_ReturnType retValueCumulated;

# if ( COMM_ACTIVE_CHANNEL > 1U )
  ComM_UserByteMaskEndIdxOfUserType iByteMaskIndex;
  boolean bNotify;
# endif

  retValue = RTE_E_OK;
  retValueCumulated = RTE_E_OK;

  /* #10 Iterate over users that have configured User Mode (state change) notification and are mapped to channels (not PNC). */
  for( userIndex = 0; userIndex < ComM_GetSizeOfUser(); userIndex++ )
  {
    if (ComM_GetUserModeNotiFunc(userIndex) != NULL_PTR) /* COV_COMM_SUBSET_OF_ELEMENTS */
    {
# if ( COMM_PNC_SUPPORT == STD_ON )
      if (!ComM_IsPncUserOfUser(userIndex))
# endif
      {
        /* #20 In single-channel configurations notify the BusSM mode to the users */
        ComM_CalcMode = ComM_BusSmState[channel];

# if ( COMM_ACTIVE_CHANNEL > 1U )
        /* #30 In multi-channel configurations only notify a new user mode if
         *     1) the user is mapped to the current channel where the BusSM mode has changed and
         *     2) the lowest mode of all channels mapped to the user has changed since the last mode notification. */
        bNotify = FALSE;

        for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(userIndex); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(userIndex); iByteMaskIndex++)
        {
          if( ComM_GetChannelOfUserByteMask(iByteMaskIndex) == channel )
          {
            bNotify = TRUE;
          }
          
          if( ComM_BusSmState[ComM_GetChannelOfUserByteMask(iByteMaskIndex)] < ComM_CalcMode )
          {
            ComM_CalcMode = ComM_BusSmState[ComM_GetChannelOfUserByteMask(iByteMaskIndex)];
          }
        }

        if( bNotify == TRUE ) /* COV_COMM_COMMON_USER_WITH_MODE_NOTIFICATION */
# endif
        {
          if( ComM_CalcMode != ComM_GetLastStateChange(userIndex) )
          {
            if( userIndex < ComM_GetSizeOfUserModeNotiFunc() ) /* COV_COMM_GENDATA_CHECK */ /* PRQA S 3355, 3358 */ /* MD_ComM_3355_3358 */
            {
              /* #40 If a new mode is available for the current user notify it using the Mode Switch Interface (sender-receiver) 'ComM_CurrentMode' */
              switch(ComM_CalcMode)
              {
              case COMM_FULL_COMMUNICATION:
                retValue = ComM_GetUserModeNotiFunc(userIndex)(RTE_MODE_ComMMode_COMM_FULL_COMMUNICATION);   /* SBSW_COMM_UserModeNotiFunc_PointerCall */
                break;
              case COMM_SILENT_COMMUNICATION:
                retValue = ComM_GetUserModeNotiFunc(userIndex)(RTE_MODE_ComMMode_COMM_SILENT_COMMUNICATION); /* SBSW_COMM_UserModeNotiFunc_PointerCall */
                break;
              case COMM_NO_COMMUNICATION:
                retValue = ComM_GetUserModeNotiFunc(userIndex)(RTE_MODE_ComMMode_COMM_NO_COMMUNICATION);     /* SBSW_COMM_UserModeNotiFunc_PointerCall */
                break;
                /* PRQA S 2018 1 */ /* MD_ComM_2018 */
              default: /* COV_COMM_MISRA */
                break;
              }
            }

            if( retValue == RTE_E_OK )
            {
              /* #400 If notification to the current user was successful, update the mode to ensure that the same one will not be notified again. */
              ComM_SetLastStateChange(userIndex, ComM_CalcMode); /* SBSW_COMM_USER_CSL02 */ /*lint !e661 ComM_LastStateChange[] has a size relation to ComM_User[] */
            }
            else
            {
              /* #410 If at least one user notification was not successful, the state change on this channel will be processed again in the next task. */
              retValueCumulated = E_NOT_OK;
            }
          }
        }
      }
    }
  }

  if( retValueCumulated == RTE_E_OK )
  {
    /* #50 If all users were notified successfully, mark processing of this state change as completed. */
    ComM_StateChange[channel] = COMM_NO_STATE_CHANGE; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
/**********************************************************************************************************************
 *  ComM_ProcessPassiveWakeUp()
 **********************************************************************************************************************/
/*!
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
COMM_LOCAL FUNC( void, COMM_CODE ) ComM_ProcessPassiveWakeUp( NetworkHandleType channel )
{
# if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
  uint8 channelIndex;
#  if (COMM_PNC_SUPPORT == STD_ON)
#   if (COMM_PNC_PS_TIMER > 0U) /* ESCAN00067357 */
  ComM_PncIterType pncIndex;
#   endif
#  endif
# endif

# if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
  /* #10 If Synchronous Wake-up is enabled, notify passive wake-up to all ComM channels being in NO_COM or SI_COM state.
   *     This is done by setting the bus-side requested state to FULL_COM (Network Requested or Ready Sleep). */
  for(channelIndex = 0u; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
  {
#  if (COMM_BUS_TYPE_FR_PRESENT == STD_ON)
    if(ComM_FrShutdown[channelIndex] == TRUE)
    {
      /* #100 If communication shutdown is ongoing on a FlexRay channel, delay the notification until FrSM indicates NO_COM
       *      because shutdown on FlexRay shall not be interrupted.
       *      Note: the ongoing shutdown means that the channel is not in FULL_COM anymore, no need to check. */
      ComM_BusComModeReqFrShutdown[channelIndex] = ComM_GetWakeupStateOfChannel(channelIndex); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    }
    else
#  endif
    {
      if((ComM_ActiveComMode[channelIndex] & COMM_FULL_COMMUNICATION) == 0u)
      {
        ComM_BusComModeReq[channelIndex] = ComM_GetWakeupStateOfChannel(channelIndex); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
    }
  }

  /* #20 If Synchronous Wake-up is enabled, activate all PNCs at least for the duration of the PNC Prepare Sleep Timer. */
#  if (COMM_PNC_SUPPORT == STD_ON)
#   if (COMM_PNC_PS_TIMER > 0U) /* ESCAN00067357 */
#    if (COMM_PNC_CHECK_ENABLED_AT_RUNTIME == STD_ON)
  if (ComM_HasPncPb())
#    endif
  {
    for(pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
    {
      if( (ComM_GetActivePncComMode(pncIndex) == COMM_PNC_NO_COMMUNICATION) && (ComM_GetBusPncComModeReq(pncIndex) == COMM_PNC_NO_COMMUNICATION) )
      {
        ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_PREPARE_SLEEP); /* SBSW_COMM_PNC_CSL02 */
      }
    }
  }
#   endif
#  endif

  COMM_DUMMY_STATEMENT(channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

# else /* #if ( COMM_SYNCHRONOUS_WAKE_UP == STD_OFF ) */

  /* #30 If Synchronous Wake-up is disabled, notify passive wake-up to the channel by setting the bus-side
   *     requested state to FULL_COM (Network Requested or Ready Sleep). Ignore the wake-up in FULL_COM mode. */
#  if (COMM_BUS_TYPE_FR_PRESENT == STD_ON)
  if(ComM_FrShutdown[channel] == TRUE)
  {
    /* #300 If communication shutdown is ongoing on FlexRay channel, delay the notification until FrSM indicates NO_COM
     *      because shutdown on FlexRay shall not be interrupted. */
    ComM_BusComModeReqFrShutdown[channel] = ComM_GetWakeupStateOfChannel(channel); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }
  else
#  endif
  {
    if((ComM_ActiveComMode[channel] & COMM_FULL_COMMUNICATION) == 0u) /* ESCAN00091475 */
    {
      ComM_BusComModeReq[channel] = ComM_GetWakeupStateOfChannel(channel); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    }
  }
# endif /* #if ( COMM_SYNCHRONOUS_WAKE_UP ) */
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

#if (COMM_EXTENDED_RAM_CHECK == STD_ON)
/**********************************************************************************************************************
 *  ComM_ChannelGetMaxStateAfterExtRamCheck()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(ComM_StateType, COMM_CODE) ComM_ChannelGetMaxStateAfterExtRamCheck( NetworkHandleType channel, ComM_StateType targetState )
{
  ComM_StateType maxState;
  Std_ReturnType ramCheckStatus;

  maxState = targetState;

  /* #10 Provide the maximum communication state on CAN channels according to the result of Extended RAM Check:
   *     COMM_NO_COM_NO_PENDING_REQUEST if check result is Disable,
   *     COMM_NO_COM_REQUEST_PENDING if check result is Disable Repeat,
   *     the targetState (no changes) otherwise. */
# if (COMM_ISDEF_BUSTYPEOFCHANNEL == STD_OFF)
  if (ComM_GetBusTypeOfChannel(channel) == COMM_BUS_TYPE_CAN)
# endif
  {
    ramCheckStatus = CanSM_RamCheckStatus(channel);

    if (ramCheckStatus == CANSM_DISABLE_COMMUNICATION)
    {
      maxState = COMM_NO_COM_NO_PENDING_REQUEST;
    }
    else if (ramCheckStatus == CANSM_DISABLE_COMMUNICATION_REPEAT)
    {
      maxState = COMM_NO_COM_REQUEST_PENDING;
    }
    else
    {
      /* no changes */
    }
  }

  return maxState;
}
#endif

#if (COMM_RESETAFTERFORCINGNOCOMMOFCHANNEL == STD_ON)
/**********************************************************************************************************************
*  ComM_ChannelResetAfterForcingNoComm()
**********************************************************************************************************************/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_ChannelResetAfterForcingNoComm( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  ComM_SizeOfChannelType channelIndex;
  boolean allChannelsAreInNoComm = TRUE;
  boolean aChannelNeedsResetAfterForcingNoComm = FALSE;

  /* ----- Implementation ----------------------------------------------- */
  for (channelIndex = 0; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
  {
#  if (COMM_EXISTS_NONE_NMTYPEOFCHANNEL == STD_ON)
    if (ComM_GetNmTypeOfChannel(channelIndex) != COMM_NONE_NMTYPEOFCHANNEL)
#  endif        
    {
      /* #10 Check for each channel except NM NONE: BusSm indicated NO_COM and the channel is in NO_COM (ignore possible passive wake-ups). */
      if ((ComM_BusSmState[channelIndex] != COMM_NO_COMMUNICATION) || (ComM_ActiveComMode[channelIndex] > COMM_NO_COM_REQUEST_PENDING))
      {
        allChannelsAreInNoComm = FALSE;
      }

      /* #20 Check that at least one channel has an active Mode Limitation and has Reset After Forcing NoCom enabled. */
# if (COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL == STD_ON)
      if (ComM_IsResetAfterForcingNoCommOfChannel(channelIndex)) /* Needed only for channels with Nm PASSIVE */
# endif
      {
        if (ComM_NoComLimitationActive(channelIndex) == TRUE)
        {
          aChannelNeedsResetAfterForcingNoComm = TRUE;
        }
      }
    }
  }

  /* #30 If the conditions above are true, call BswM_ComM_InitiateReset(). */
  if ((allChannelsAreInNoComm == TRUE) && (aChannelNeedsResetAfterForcingNoComm == TRUE))
  {
    BswM_ComM_InitiateReset();
  }
}
#endif

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/

/***********************************************************************************************************************
 *  ComM_Init()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
#if (COMM_INIT_POINTER_ENABLED == STD_ON)
FUNC(void, COMM_CODE) ComM_Init(P2CONST(ComM_ConfigType, AUTOMATIC, COMM_INIT_DATA) ConfigPtr)
#else
FUNC(void, COMM_CODE) ComM_Init(void)
#endif
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;
  uint8 ComM_ChannelIndex;
  uint8 ComM_ByteIndex;

#if ( (COMM_USERMODENOTIFUNC == STD_ON) || (COMM_FULL_COMM_REQUEST_NOTIF == STD_ON) )
  uint8 userIndex;
#endif

#if (COMM_NVM_SUPPORT == STD_ON)
  NvM_RequestResultType requestResult = NVM_REQ_NOT_OK;
#endif

#if ( COMM_USE_INIT_POINTER == STD_ON )
  /* Avoid compiler from optimizing access to the PbData */
  ComM_ConfigPtr = ConfigPtr;
#else
# if (COMM_INIT_POINTER_ENABLED == STD_ON)
  /* In this case the init pointer is NULL because all variants have same configuration data, no error. */
  COMM_DUMMY_STATEMENT_CONST(ConfigPtr); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is not initialized. */
  if (ComM_InitStatus == COMM_INIT)
  {
    errorId = COMM_E_ALREADY_INITIALIZED;
  } else
#endif

#if ( COMM_USE_INIT_POINTER == STD_ON ) /* Always check the init pointer if it is used. The only use-case when COMM_USE_INIT_POINTER == STD_OFF is when configuration data of all variants is the same. */
  /* #20 Check that configuration pointer is valid. */
  if( ConfigPtr == NULL_PTR )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
#  if ( COMM_USE_ECUM_BSW_ERROR_HOOK == STD_ON )
    EcuM_BswErrorHook((uint16) COMM_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);
#  endif
  } else

# if ( COMM_FINALMAGICNUMBER == STD_ON )
  /* #30 Check the magic number. */  /* SPEC-35483 */
  if (ComM_GetFinalMagicNumber() != COMM_FINAL_MAGIC_NUMBER) /* COV_COMM_MAGICNUMBER_CHECK */
  {
    errorId = COMM_E_WRONG_PARAMETERS;
    EcuM_BswErrorHook((uint16) COMM_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
  } else
# endif /* COMM_FINALMAGICNUMBER == STD_ON */
#endif /* COMM_USE_INIT_POINTER == STD_ON */
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Restore the NvM data. */
#if (COMM_NVM_SUPPORT == STD_ON)
    if( NvM_GetErrorStatus((NvM_BlockIdType)COMM_NVM_BLOCK_ID, &requestResult) != E_OK ) /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */
    {
      errorId = COMM_E_ERROR_IN_PROV_SERVICE;
    }

    if(requestResult != NVM_REQ_OK) /* The last NvM read request has failed, initialize with configured data. */
#endif
    {
      ComM_Inhibition.ComM_ECUGroupClassification = ComM_ECUGroupClassInit;  /* initialize the ECU group classification with the configured value */ 
      ComM_Inhibition.ComM_InhibitCnt             = 0x00u;                   /* reset the inhibition counter */
    }

    /* #50 Initialize ComM variables. */
#if ( COMM_FULL_COMM_REQUEST_NOTIF == STD_ON )
    ComM_CurrentChannelRequestInit();

    for( userIndex = 0u; userIndex < ComM_GetSizeOfFullComRequesters(); userIndex++)
    {
      ComM_SetFullComRequesters(userIndex, 0xffu);                                /* SBSW_COMM_CSL01 */
    }
#endif

#if ( COMM_USERMODENOTIFUNC == STD_ON )
    for( userIndex = 0u; userIndex < ComM_GetSizeOfUser(); userIndex++)
    {
      ComM_SetLastStateChange(userIndex, COMM_NO_COMMUNICATION);                  /* SBSW_COMM_USER_CSL02 */
    }
#endif

    for(ComM_ChannelIndex = 0u; ComM_ChannelIndex < ComM_GetSizeOfChannel(); ComM_ChannelIndex++)
    {
      ComM_BusComModeReq[ComM_ChannelIndex] = COMM_NO_COM_NO_PENDING_REQUEST;     /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

#if( COMM_BUS_TYPE_FR_PRESENT == STD_ON )
      ComM_BusComModeReqFrShutdown[ComM_ChannelIndex] = COMM_NO_COM_NO_PENDING_REQUEST;  /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      ComM_FrShutdown[ComM_ChannelIndex] = FALSE;                                 /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
#endif

      ComM_ActiveComMode[ComM_ChannelIndex] = COMM_NO_COM_NO_PENDING_REQUEST;     /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      ComM_BusSmState[ComM_ChannelIndex] = COMM_NO_COMMUNICATION;                 /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

#if (COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON)
      ComM_SetMinFullComModeTimer(ComM_ChannelIndex, 0x00u);                      /* SBSW_COMM_CHANNEL_CSL02 */
#endif

#if ((COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
      ComM_SetNmLightTimer(ComM_ChannelIndex, 0x00u);                             /* SBSW_COMM_CHANNEL_CSL02 */
#endif

      ComM_ComAllowed[ComM_ChannelIndex] = FALSE;                                 /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

#if ((COMM_DCM_INDICATION) && (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON))
      ComM_SetDcmRequestActive(ComM_ChannelIndex, FALSE);                         /* SBSW_COMM_CHANNEL_CSL02 */
#endif

#if (COMM_USERMODENOTIFUNC == STD_ON)
      ComM_StateChange[ComM_ChannelIndex] = COMM_NO_STATE_CHANGE;                 /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
#endif

#if (COMM_NVM_SUPPORT == STD_ON)
      if(requestResult == NVM_REQ_OK)
      {
        /* Successfully restored non-volatile data, ComM_InhibitionStatus[] now contains the restored status of Wake-up Inhibition. 
        * Now add the configured value of ComMNoCom (No Com Mode Limitation) which is not stored non-volatile. */
        ComM_Inhibition.ComM_InhibitionStatus[ComM_ChannelIndex] |= (uint8)(ComM_GetInhibitionInitValueOfChannel(ComM_ChannelIndex) & COMM_WAKEUP_INHIBITION_CLEAR_MASK); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
      else
#endif
      {
        /* Mode Limitation and Wake-up Inhibition are disabled or couldn't restore non-volatile data, initialize with configured values. */
        ComM_Inhibition.ComM_InhibitionStatus[ComM_ChannelIndex] = ComM_GetInhibitionInitValueOfChannel(ComM_ChannelIndex); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
    }

    for(ComM_ByteIndex = 0u; ComM_ByteIndex < ComM_GetSizeOfUserReqFullCom(); ComM_ByteIndex++)
    {
      ComM_SetUserReqFullCom(ComM_ByteIndex, COMM_NO_REQUESTS);            /* SBSW_COMM_CSL01 */
    }

#if (COMM_NVM_SUPPORT == STD_ON)
    ComM_NvMStoreReq = FALSE;
# endif

#if (COMM_BUS_TYPE_INTERNAL_PRESENT == STD_ON)
    ComM_InitInternalBusSMMode();
#endif

#if (COMM_PNC_SUPPORT)
    ComM_PncInit();
#endif

    /* #60 Check generated data and if successful set the initialization status to initialized. */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
    if (ComM_InitCheckGeneratedData() == COMM_E_NO_ERROR) /* COV_COMM_GENDATA_CHECK */ /* PRQA S 3355, 3358 */ /* MD_ComM_3355_3358 */
#endif
    {
      ComM_InitStatus = COMM_INIT;
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_INIT, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

#if (COMM_DEV_ERROR_DETECT == STD_ON)
/**********************************************************************************************************************
 *  ComM_InitCheckGeneratedData()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
COMM_LOCAL_INLINE FUNC(uint8, COMM_CODE) ComM_InitCheckGeneratedData(void)
{
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_ChannelIterType channelIndex;

  /* PRQA S 3325, 3201 SUPPRESS_3325_3201 */ /* MD_ComM_3325_3201 */
  if (ComM_GetSizeOfChannel() != ComM_GetSizeOfChannelPb())  /* COV_COMM_GENDATA_CHECK */ /*lint !e506 */
  {
    errorId = COMM_E_WRONG_GENERATED_DATA;
  }
# if (COMM_PNC_SUPPORT)
  else if (ComM_GetSizeOfPnc() != ComM_GetSizeOfPncPb())  /* COV_COMM_GENDATA_CHECK */ /*lint !e506 */
  {
    errorId = COMM_E_WRONG_GENERATED_DATA;
  }
# endif
  else
  {
    for (channelIndex = 0u; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
    {
      /* Check the target wake-up state of the channel because it is used as index in ComM_TransitionFctTable */
      if (ComM_GetWakeupStateOfChannel(channelIndex) >= COMM_MAX_NUMBER_OF_STATES) /* COV_COMM_GENDATA_CHECK */ /*lint !e506 */
      {
        errorId = COMM_E_WRONG_GENERATED_DATA;
        break;
      }
    }
  }
  /* PRQA L:SUPPRESS_3325_3201 */

  return errorId;
}
#endif

#if (COMM_PNC_SUPPORT == STD_ON)
/**********************************************************************************************************************
 *  ComM_PncInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_PncInit(void)
{
  ComM_UserReqPncFullComIterType userReqPncFullComIndex;
  ComM_PncIterType pncIndex;
  ComM_PncSignalValuesIterType pncSignalValueIndex;

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  ComM_ChannelIterType channelIndex;
  ComM_PncLimitationIterType pncLimitationIndex;
# endif

  /* #10 Initialize all PNC related data. */
  for (userReqPncFullComIndex = 0u; userReqPncFullComIndex < ComM_GetSizeOfUserReqPncFullCom(); userReqPncFullComIndex++)
  {
    ComM_SetUserReqPncFullCom(userReqPncFullComIndex, COMM_NO_REQUESTS); /* SBSW_COMM_CSL01 */
  }

  for (pncIndex = 0u; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
  {
    ComM_SetPncPSleepTimer(pncIndex, 0x00u); /* SBSW_COMM_PNC_CSL02 */
    ComM_SetActivePncComMode(pncIndex, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
    ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_NO_COMMUNICATION); /* SBSW_COMM_PNC_CSL02 */
  }

  /* #20 Clear stored signal values (EIRA_RX, ERA_RX, EIRA_TX) */
  for (pncSignalValueIndex = 0u; pncSignalValueIndex < ComM_GetSizeOfPncSignalValues(); pncSignalValueIndex++)
  {
    ComM_SetPncSignalValues(pncSignalValueIndex, 0x00); /* SBSW_COMM_CSL01 */
  }

  /* #30 If PNC Routing Limitation is enabled, set channel status to not limited. */
# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
  for (channelIndex = 0u; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
  {
    ComM_PncToChannelRoutingState[channelIndex] = COMM_PNCROUTING_NOT_LIMITED; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }

  for (pncLimitationIndex = 0u; pncLimitationIndex < ComM_GetSizeOfPncLimitation(); pncLimitationIndex++)
  {
    ComM_SetPncLimitation(pncLimitationIndex, (uint8)0x00u); /* SBSW_COMM_CSL01 */
  }
# endif

# if (COMM_USERMODENOTIFUNC == STD_ON)
  ComM_NotifyPncStateChange = FALSE;
# endif
} /* PRQA S 6010, 6080 */ /* MD_MSR_STPTH, MD_MSR_STMIF */
#endif /* COMM_PNC_SUPPORT == STD_ON */

/*********************************************************************************************************************
 *  ComM_DeInit()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_DeInit(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  ComM_ChannelIterType channelIndex;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 No parameter checks are needed */

  /* ----- Implementation ----------------------------------------------- */
  /* #20 Trigger storage of non-volatile values. Only store the Wake-up Inhibition bit, clear the No Com Mode Limitation bit,
   *     it shall not be stored to NvM. */
#if (COMM_NVM_SUPPORT == STD_ON)
  if(ComM_NvMStoreReq == TRUE)
  {
    for(channelIndex = 0; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
    {
      ComM_Inhibition.ComM_InhibitionStatus[channelIndex] &= COMM_WAKEUP_INHIBITION_MASK; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    }

    if( NvM_SetRamBlockStatus((NvM_BlockIdType)COMM_NVM_BLOCK_ID, TRUE) != E_OK )
    {
      errorId = COMM_E_ERROR_IN_PROV_SERVICE;
    }

    ComM_NvMStoreReq = FALSE;
  }
#endif

  /* #30 Iterate over the channels and check if all are in state COMM_NO_COM_NO_PENDING_REQUEST. 
   *     If so, set the initialization status to COMM_UNINIT. */
  for(channelIndex = 0; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
  {
    if(ComM_ActiveComMode[channelIndex] != COMM_NO_COM_NO_PENDING_REQUEST)
    {
      break; /* De-Initialization impossible */
    }
  }

  if(channelIndex == ComM_GetSizeOfChannel()) /* All channels are in state COMM_NO_COM_NO_PENDING_REQUEST because break above was not reached */
  {
    ComM_InitMemory();
  }

  /* ----- Development Error Report --------------------------------------- */
#if ((COMM_DEV_ERROR_REPORT == STD_ON) && (COMM_NVM_SUPPORT == STD_ON))
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_DEINIT, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif
}

/*********************************************************************************************************************
 *  ComM_InitMemory()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, COMM_CODE) ComM_InitMemory(void)
{
  /* #10 Set initialization status of ComM to COMM_UNINIT */
  ComM_InitStatus = COMM_UNINIT;
#if (COMM_USE_INIT_POINTER == STD_ON)
  ComM_ConfigPtr = NULL_PTR;
#endif
}

/**********************************************************************************************************************
 *  ComM_GetState()
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, COMM_CODE) ComM_GetState( NetworkHandleType Channel, P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_VAR) State)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
# if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
# endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'State': it must be a valid pointer. */
  else if (State == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 If parameter checks are successful, store the current active state of the channel by default. */
    *State = ComM_ActiveComMode[Channel]; /* SBSW_COMM_PARAMETER_PTR_WRITE */

    /* #50 If the active state is COMM_NO_COM_NO_PENDING_REQUEST and there is a pending request (external or internal),
     *     the current state depends on Extended RAM Check functionality:
     *     1) if Extended RAM Check functionality is used, the ComM channel is allowed to enter COMM_NO_COM_REQUEST_PENDING state depending on the check result.
     *     2) if Extended RAM Check functionality is not used, store COMM_NO_COM_REQUEST_PENDING.
     *     Note: COMM_NO_COM_REQUEST_PENDING ensures that the request can be considered and ECU stays in RUN mode. */
    if (ComM_ActiveComMode[Channel] == COMM_NO_COM_NO_PENDING_REQUEST)
    {
      if (ComM_ChannelIsRequestPending(Channel) == TRUE)
      {
#if (COMM_EXTENDED_RAM_CHECK == STD_ON)
        *State = ComM_ChannelGetMaxStateAfterExtRamCheck( Channel, COMM_NO_COM_REQUEST_PENDING ); /* SBSW_COMM_PARAMETER_PTR_WRITE */
#else
        *State = COMM_NO_COM_REQUEST_PENDING; /* SBSW_COMM_PARAMETER_PTR_WRITE */
#endif
      }
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETSTATE, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */


/*********************************************************************************************************************
 *  ComM_GetStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus( P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check parameter 'Status': it must be a valid pointer. */
  retVal = E_NOT_OK;
  if (Status == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 If parameter checks are successful, store the initialization state of ComM. */
    *Status = ComM_InitStatus; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETSTATUS, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}

/*********************************************************************************************************************
 *  ComM_RequestComMode()
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_UserByteMaskEndIdxOfUserType iByteMaskIndex;
  ComM_UserReqFullComType userReqFullCom;

#if (COMM_PNC_SUPPORT == STD_ON)
  ComM_UserReqPncFullComType userReqPncFullCom;
#endif

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'User'. */
  else if (User >= ComM_GetSizeOfUser())
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'ComMode'. */
  /* If called with ComMode != COMM_NO_COMMUNICATION && ComMode != COMM_FULL_COMMUNICATION (ESCAN00068871) */
  else if ((ComMode != COMM_NO_COMMUNICATION) && (ComMode != COMM_FULL_COMMUNICATION))
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    retVal = E_OK; /* Can be set to COMM_E_MODE_LIMITATION later. */
    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #40 If COMM_NO_COMMUNICATION is requested, clear the user request in each related byte of UserReqFullCom and UserReqPncFullCom. */
    if( ComMode == COMM_NO_COMMUNICATION )
    {
      for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(User); iByteMaskIndex++)
      {
        userReqFullCom = (ComM_UserReqFullComType)(ComM_GetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(iByteMaskIndex)) & ComM_GetClearMaskOfUserByteMask(iByteMaskIndex));
        ComM_SetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(iByteMaskIndex), userReqFullCom); /* SBSW_COMM_UserReqFullCom_over_ChannelPb_or_ByteMask_CSL03 */
      }
#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_CHECK_ENABLED_AT_RUNTIME == STD_ON)
      if(ComM_HasPncPb())
# endif
      {
        if (ComM_IsPncUserOfUser(User))
        {
          /* clear bit for full request */
          for(iByteMaskIndex = ComM_GetUserPncByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserPncByteMaskEndIdxOfUser(User); iByteMaskIndex++)
          {
            userReqPncFullCom = (ComM_UserReqPncFullComType)(ComM_GetUserReqPncFullCom(ComM_GetUserReqPncFullComIdxOfUserPncByteMask(iByteMaskIndex)) & ComM_GetClearMaskOfUserPncByteMask(iByteMaskIndex));
            ComM_SetUserReqPncFullCom(ComM_GetUserReqPncFullComIdxOfUserPncByteMask(iByteMaskIndex), userReqPncFullCom); /* SBSW_COMM_UserReqPncFullCom_over_UserPncByteMask_or_PncPb_CSL03 */
          }
        }
      }
#endif
    }
    else
    {
      /* #50 If COMM_FULL_COMMUNICATION is requested, set the user request in each related byte of UserReqFullCom and UserReqPncFullCom. */
      for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(User); iByteMaskIndex++)
      {
        userReqFullCom = (ComM_UserReqFullComType)(ComM_GetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(iByteMaskIndex)) | ComM_GetSetMaskOfUserByteMask(iByteMaskIndex));
        ComM_SetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(iByteMaskIndex), userReqFullCom); /* SBSW_COMM_UserReqFullCom_over_ChannelPb_or_ByteMask_CSL03 */

        /* #60 If Node Limitation NO_COM or Prevent Wake-up is active, ComM stores the FULL_COM request but does not perform it. */
#if ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON))
# if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
        if (ComM_ChannelIsLimited(ComM_GetChannelOfUserByteMask(iByteMaskIndex)) == TRUE)
# endif
        {
          retVal = COMM_E_MODE_LIMITATION;
        }
#endif
      }

#if (COMM_PNC_SUPPORT == STD_ON)
# if (COMM_PNC_CHECK_ENABLED_AT_RUNTIME == STD_ON)
      if(ComM_HasPncPb())
# endif
      {
        if (ComM_IsPncUserOfUser(User))
        {
          for(iByteMaskIndex = ComM_GetUserPncByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserPncByteMaskEndIdxOfUser(User); iByteMaskIndex++)
          {
            userReqPncFullCom = (ComM_UserReqPncFullComType)(ComM_GetUserReqPncFullCom(ComM_GetUserReqPncFullComIdxOfUserPncByteMask(iByteMaskIndex)) | ComM_GetSetMaskOfUserPncByteMask(iByteMaskIndex));
            ComM_SetUserReqPncFullCom(ComM_GetUserReqPncFullComIdxOfUserPncByteMask(iByteMaskIndex), userReqPncFullCom); /* SBSW_COMM_UserReqPncFullCom_over_UserPncByteMask_or_PncPb_CSL03 */
          }
        }
      }
#endif
    }

    /* #70 If FULL_COM request is inhibited, increment the inhibition counter and store it in NvM. */
#if ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON))
    if (retVal == COMM_E_MODE_LIMITATION)
    {
      if (ComM_Inhibition.ComM_InhibitCnt < 65535)
      {
        ComM_Inhibition.ComM_InhibitCnt++;
# if (COMM_NVM_SUPPORT == STD_ON)
        ComM_NvMStoreReq = TRUE;
# endif
      }
    }
#endif

    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_REQUESTCOMMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  if ((COMM_ISDEF_USERBYTEMASKSTARTIDXOFUSER == STD_ON) && (COMM_PNC_SUPPORT == STD_OFF))
  COMM_DUMMY_STATEMENT(User); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
# endif

  return retVal;
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */


/*********************************************************************************************************************
 *  ComM_GetMaxComMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;
#if ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON))
  ComM_UserByteMaskEndIdxOfUserType iByteMaskIndex;
#endif

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'ComMode': it must be a valid pointer. */
  else if (ComMode == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'User': it must be valid. */
  else if (User >= ComM_GetSizeOfUser())
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 If parameter checks are successful, get the maximum allowed communication mode of the user:
     *     NO_COM if Mode Limitation NO_COM or Prevent Wake-up is active on at least one channel mapped to the user,
     *     FULL_COM otherwise. */
    *ComMode = (ComM_ModeType)COMM_FULL_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */

#if ((COMM_MODE_LIMITATION == STD_ON) || (COMM_WAKEUP_INHIBITION == STD_ON))
    for (iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(User); iByteMaskIndex++)
    {
# if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
      if (ComM_ChannelIsLimited(ComM_GetChannelOfUserByteMask(iByteMaskIndex)) == TRUE)
# endif
      {
        *ComMode = (ComM_ModeType)COMM_NO_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
      }
    }
#endif
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETMAXCOMMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  COMM_DUMMY_STATEMENT(User); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/*********************************************************************************************************************
 *  ComM_GetRequestedComMode()
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_UserByteMaskEndIdxOfUserType iByteMaskIndex;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'ComMode'. */
  else if (ComMode == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'User'. */
  else if (User >= ComM_GetSizeOfUser())
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 If parameter checks are successful, get the requested mode of the user:
     *     NO_COM if at least one channel mapped to the user is not requested or
     *       if this PNC user is mapped to PNCs without channels (special case) and at least one PNC is not requested.
     *     FULL_COM otherwise. */
    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* Set the default value to NO_COM to consider users having no channels and no PNCs, in this case the function does not change it. ESCAN00092198 */
    *ComMode = COMM_NO_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */

#if (COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON)
    if ((ComM_IsPncUserOfUser(User)) && (ComM_GetUserByteMaskEndIdxOfUser(User) == COMM_NO_USERBYTEMASKENDIDXOFUSER)) /* COV_COMM_PNC_EXTENDED_ALL_PNC_WITHOUT_CHANNELS */
    {
      /* Special case: this PNC user is mapped to PNCs without channels */
      for(iByteMaskIndex = ComM_GetUserPncByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserPncByteMaskEndIdxOfUser(User); iByteMaskIndex++)
      {
        if( (ComM_GetUserReqPncFullCom(ComM_GetUserReqPncFullComIdxOfUserPncByteMask(iByteMaskIndex)) & ComM_GetSetMaskOfUserPncByteMask(iByteMaskIndex)) != COMM_NO_REQUESTS)
        {
          *ComMode = COMM_FULL_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
        }
        else
        {
          *ComMode = COMM_NO_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
          break;
        }
      }
    }
    else
#endif
    {
      for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(User); iByteMaskIndex++)
      {
        if( (ComM_GetUserReqFullCom(ComM_GetUserReqFullComIdxOfUserByteMask(iByteMaskIndex)) & ComM_GetSetMaskOfUserByteMask(iByteMaskIndex)) != COMM_NO_REQUESTS)
        {
          *ComMode = COMM_FULL_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
        }
        else
        {
          *ComMode = COMM_NO_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
          break;
        }
      }
    }

    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETREQUESTEDCOMMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  COMM_DUMMY_STATEMENT(User); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
} /* PRQA S 6010, 6080 */ /* MD_MSR_STPTH, MD_MSR_STMIF */

/*********************************************************************************************************************
 *  ComM_GetCurrentComMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_UserByteMaskEndIdxOfUserType iByteMaskIndex;
  ComM_ModeType tmpComMode;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'User': it must be a valid user identifier. */
  else if (User >= ComM_GetSizeOfUser())
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'ComMode': it must be a valid pointer. */
  else if (ComMode == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 If parameter checks are successful, get the lowest BusSM mode of all channels mapped to the user.  */
    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* Set the default value to NO_COM to consider users having no channels and no PNCs, in this case the function does not change it. ESCAN00092198 */
    *ComMode = COMM_NO_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(User); iByteMaskIndex = ComM_GetUserByteMaskEndIdxOfUser(User))
    {
      /* If user has channels or PNCs, set the default value to FULL_COM by executing this loop exactly once. */
      *ComMode = COMM_FULL_COMMUNICATION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    }

    for(iByteMaskIndex = ComM_GetUserByteMaskStartIdxOfUser(User); iByteMaskIndex < ComM_GetUserByteMaskEndIdxOfUser(User); iByteMaskIndex++)
    {
      ComM_GetCurrentBusSMMode(ComM_GetChannelOfUserByteMask(iByteMaskIndex), &tmpComMode); /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */
      if(tmpComMode < *ComMode)
      {
        *ComMode = tmpComMode; /* SBSW_COMM_PARAMETER_PTR_WRITE */
      }
    }

    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETCURRENTCOMMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  if (COMM_ISDEF_USERBYTEMASKSTARTIDXOFUSER == STD_ON)
  COMM_DUMMY_STATEMENT(User); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
# endif

  return retVal;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/**********************************************************************************************************************
 *  ComM_GetInhibitionStatus()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus( NetworkHandleType Channel, P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Status': it must be valid pointer. */
  else if (Status == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 If parameter checks are successful, store the inhibition status of the channel. */
    *Status = ComM_Inhibition.ComM_InhibitionStatus[Channel]; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETINHIBITIONSTATUS, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}


/*********************************************************************************************************************
 *  ComM_PreventWakeUp()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp( NetworkHandleType Channel, boolean Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
# if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
# endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and the feature Prevent Wake-up is enabled, process the request. */
#if ( COMM_WAKEUP_INHIBITION == STD_ON )
  SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

  if(Status == TRUE)
  {
    /* #40 Only accept the request if ECU Group Classification supports Prevent Wake-up. */
    /* ESCAN00068902 */
    if( (ComM_Inhibition.ComM_ECUGroupClassification & COMM_WAKEUP_INHIBITION_MASK) == COMM_WAKEUP_INHIBITION_MASK )
    {
      ComM_Inhibition.ComM_InhibitionStatus[Channel] |= COMM_WAKEUP_INHIBITION_MASK; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
# if (COMM_NVM_SUPPORT == STD_ON)
      ComM_NvMStoreReq = TRUE;
# endif
      retVal = E_OK;
    }
    else
    {
      retVal = E_NOT_OK;
    }
  }
  else
  {
    /* #50 Always accept releasing the Prevent Wake-up. */
    ComM_Inhibition.ComM_InhibitionStatus[Channel] &= COMM_WAKEUP_INHIBITION_CLEAR_MASK; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
# if (COMM_NVM_SUPPORT == STD_ON)
    ComM_NvMStoreReq = TRUE;
# endif
    retVal = E_OK;
  }

  SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#else
    /* #60 Reject the request if the feature Prevent Wake-up is disabled. */
    /* ESCAN00068896 */
    retVal = E_NOT_OK;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
# if ( COMM_WAKEUP_INHIBITION == STD_ON )
  if (errorId != COMM_E_NO_ERROR)
# endif
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_PREVENTWAKEUP, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

#if ( COMM_WAKEUP_INHIBITION == STD_OFF )
  COMM_DUMMY_STATEMENT(Status); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# if ( COMM_DEV_ERROR_DETECT == STD_OFF )
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#endif

  return retVal;
}


/*********************************************************************************************************************
 *  ComM_LimitChannelToNoComMode()
 *********************************************************************************************************************/
/*!
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
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode( NetworkHandleType Channel, boolean Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal = E_NOT_OK;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
# if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
# endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and the feature Mode Limitation to NO_COM is enabled and
     *     at least one channel has Nm Type other than PASSIVE, process the request. */
#if ((COMM_MODE_LIMITATION == STD_ON) && (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON))
    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    if (Status == TRUE)
    {
      /* #40 Accept a request for Mode Limitation to NO_COM if
       *     1) the channel is in state COMM_FULL_COM_NETWORK_REQUESTED and
       *     2) the channel has Nm Type other than NONE (because ComM does not shutdown communication on NONE) and
       *     3) ECU Group Classification supports Mode Limitation NO_COM. */
      /* ESCAN00068896 */
# if ((COMM_EXISTS_NONE_NMTYPEOFCHANNEL == STD_OFF) || (COMM_ISDEF_NMTYPEOFCHANNEL == STD_OFF)) /* COV_COMM_ALL_CHANNELS_NM_NONE */
#  if (COMM_EXISTS_NONE_NMTYPEOFCHANNEL == STD_ON) /* implies that COMM_ISDEF_NMTYPEOFCHANNEL == STD_OFF according to the condition above */
      if (ComM_GetNmTypeOfChannel(Channel) != COMM_NONE_NMTYPEOFCHANNEL)
#  endif
      {
        if ((ComM_ActiveComMode[Channel] == COMM_FULL_COM_NETWORK_REQUESTED) &&
            ((ComM_Inhibition.ComM_ECUGroupClassification & COMM_MODE_LIMITATION_MASK) == COMM_MODE_LIMITATION_MASK ))
        {
          ComM_Inhibition.ComM_InhibitionStatus[Channel] |= COMM_MODE_LIMITATION_MASK; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
          retVal = E_OK;
        }
      }
# endif
    }
    else
    {
      /* #50 Accept releasing the Mode Limitation to NO_COM if the channel has Nm Type other than PASSIVE. */
      /* Note: a possible use case for NONE is when limitation has been set initially in the configuration. */
# if (COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL == STD_ON)
      if (ComM_GetNmTypeOfChannel(Channel) != COMM_PASSIVE_NMTYPEOFCHANNEL)
# endif
      {
        ComM_Inhibition.ComM_InhibitionStatus[Channel] &= COMM_MODE_LIMITATION_CLEAR_MASK; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
        retVal = E_OK;
      }
    }
    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_0(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#endif
    /* #60 Reject the request if the feature Mode Limitation to NO_COM is disabled or all channels have Nm Type PASSIVE. */
    /* ESCAN00068896 */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_LIMITCHANNELTONOCOMMODE, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

#if ((COMM_MODE_LIMITATION == STD_OFF) || (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_OFF))
  COMM_DUMMY_STATEMENT(Status); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# if (COMM_DEV_ERROR_DETECT == STD_OFF)
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
#endif

  return retVal;
}


/*********************************************************************************************************************
 *  ComM_LimitECUToNoComMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode(boolean Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;
#if ((COMM_MODE_LIMITATION == STD_ON) && (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON))
  NetworkHandleType ComM_ChannelIndex;
#endif

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 If parameter checks are successful and the feature Mode Limitation to NO_COM is enabled and
     *     at least one channel has Nm Type other than PASSIVE, request mode limitation for each channel. */
#if ((COMM_MODE_LIMITATION == STD_ON) && (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON))
    retVal = E_OK;
    for(ComM_ChannelIndex = 0; ComM_ChannelIndex < ComM_GetSizeOfChannel(); ComM_ChannelIndex++)
    {
# if (COMM_ENABLEDOFCHANNEL == STD_ON)
      if(ComM_IsEnabledOfChannel(ComM_ChannelIndex))
# endif
      {
        if( ComM_LimitChannelToNoComMode(ComM_ChannelIndex, Status) != E_OK )
        {
          /* #30 If the request failed for at least one channel, the overall status shall be E_NOT_OK as well. */
          /* ESCAN00068896 */
          retVal = E_NOT_OK;
        }
      }
    }
#else
    /* #40 Reject the request if the feature Mode Limitation to NO_COM is disabled or all channels have Nm Type PASSIVE. */
    /* (ESCAN00068896) */
    retVal = E_NOT_OK;
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_LIMITECUTONOCOMMODE, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

#if (( COMM_MODE_LIMITATION == STD_OFF ) || (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_OFF))
  COMM_DUMMY_STATEMENT(Status); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}


/*********************************************************************************************************************
 *  ComM_ReadInhibitCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter(P2VAR(uint16, AUTOMATIC, COMM_APPL_VAR) CounterValue)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'CounterValue': it must be a valid pointer. */
  else if (CounterValue == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 If parameter checks are successful, store the inhibition counter. */
    *CounterValue = ComM_Inhibition.ComM_InhibitCnt; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_READINHIBITCOUNTER, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}


/*********************************************************************************************************************
 *  ComM_ResetInhibitCounter()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful, set the inhibition counter to 0 and mark NvM data to be stored if NvM support is enabled. */
    ComM_Inhibition.ComM_InhibitCnt = (uint16)0x00;

#if (COMM_NVM_SUPPORT == STD_ON)
    ComM_NvMStoreReq = TRUE;
#endif
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_RESETINHIBITCOUNTER, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}


/*********************************************************************************************************************
 *  ComM_SetECUGroupClassification()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  retVal = E_NOT_OK;
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Status': it must have a value between 0 and 3. */
  else if (Status > 0x03)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful, set ECU group classification and mark NvM data to be stored if NvM is supported. */
    ComM_Inhibition.ComM_ECUGroupClassification = Status;

#if (COMM_NVM_SUPPORT == STD_ON)
    ComM_NvMStoreReq = TRUE;
#endif
    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_SETECUGROUPCLASSIFICATION, errorId );
  }
#else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#endif

  return retVal;
}


#if (COMM_VERSION_INFO_API == STD_ON)
/*********************************************************************************************************************
 *  ComM_GetVersionInfo()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_VAR) Versioninfo)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check Versioninfo for NULL pointer. Note: no initialization check is needed. */
  if (Versioninfo == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Set Versioninfo with corresponding macros from component header. */
    Versioninfo->vendorID = COMM_VENDOR_ID; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    Versioninfo->moduleID = COMM_MODULE_ID; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    Versioninfo->sw_major_version = COMM_SW_MAJOR_VERSION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    Versioninfo->sw_minor_version = COMM_SW_MINOR_VERSION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    Versioninfo->sw_patch_version = COMM_SW_PATCH_VERSION; /* SBSW_COMM_PARAMETER_PTR_WRITE */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETVERSIONINFO, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

/**********************************************************************************************************************
 *  ComM_CommunicationAllowed()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_CommunicationAllowed(NetworkHandleType Channel, boolean Allowed)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful, store the Communication Allowed status of the Channel. */
    ComM_ComAllowed[Channel] = Allowed; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_COMMUNICATIONALLOWED, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}

#if (COMM_DCM_INDICATION == STD_ON)
/**********************************************************************************************************************
 *  ComM_GetDcmRequestStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetDcmRequestStatus(NetworkHandleType Channel, P2VAR(boolean, AUTOMATIC, COMM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'Status': it must be a valid pointer. */
  else if (Status == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Store TRUE if Dcm indicated active diagnostic. Store FALSE otherwise. */
# if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
    if (ComM_IsDcmRequestActive(Channel))
    {
      *Status = TRUE; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    }
    else
# endif
    {
      *Status = FALSE; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETDCMREQUESTSTATUS, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}
#endif

#if (COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON)
/**********************************************************************************************************************
 *  ComM_GetMinFullComModeTimerStatus()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, COMM_CODE) ComM_GetMinFullComModeTimerStatus(NetworkHandleType Channel, P2VAR(boolean, AUTOMATIC, COMM_APPL_VAR) Status)
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retVal;
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  retVal = E_NOT_OK;
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
    retVal = COMM_E_UNINIT;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'Status': it must be a valid pointer. */
  else if (Status == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 Store TRUE if MinFullComModeTimer is running. Store FALSE otherwise. */
    if (ComM_GetMinFullComModeTimer(Channel) > 0x00)
    {
      *Status = TRUE; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    }
    else
    {
      *Status = FALSE; /* SBSW_COMM_PARAMETER_PTR_WRITE */
    }

    retVal = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_GETMINFULLCOMMODETIMERSTATUS, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

  return retVal;
}
#endif

/**********************************************************************************************************************
 *  ComM_MainFunction()
 **********************************************************************************************************************/
/*!
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
 */
FUNC(void, COMM_CODE) ComM_MainFunction(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_StateType  highestComModeReq;     /* The highest Com mode request */
  boolean  internalRequest;

  /* ----- Development Error Checks ------------------------------------- */
  /* #10 Check that module is initialized. If not, the function returns immediately without performing any functionality and without raising any errors. */
  if (ComM_InitStatus != COMM_INIT)
  {
    /* no error reporting */
  }
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if (Channel >= COMM_ACTIVE_CHANNEL)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
#endif
  else
  {
    /* ----- Implementation ----------------------------------------------- */
#if (COMM_ENABLEDOFCHANNEL == STD_ON)
    /* If the channel is de-activated in the current variant, the main function shall do nothing
    * besides handling of PN prepare sleep timer. */
    if (ComM_IsEnabledOfChannel(Channel))
#endif
    {
      SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      /* #30 If parameter checks are successful and the channel is active in the current variant, get the highest
       *     requested communication mode and perform a state transition accordingly. */
      highestComModeReq = ComM_CalculateHighestComMode(Channel, &internalRequest); /* SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE */

      /* #31 If Extended RAM Check functionality is used and communication needs to be started on the channel,
       *     limit the highest requested mode according to the RAM Check result. */
#if (COMM_EXTENDED_RAM_CHECK == STD_ON)
      if ((ComM_ActiveComMode[Channel] <= COMM_NO_COM_REQUEST_PENDING) && (highestComModeReq > COMM_NO_COM_REQUEST_PENDING))
      {
        highestComModeReq = ComM_ChannelGetMaxStateAfterExtRamCheck( Channel, highestComModeReq );
      }
#endif

      ComM_ChannelStateTransition(Channel, highestComModeReq);

      /* #40 If User Mode Notification is enabled and BusSM indicated a state change on the channel or the last notification failed,
       *     notify the mode change of channel users via RTE Mode Switch Interface.
       *     Note: do it outside of the exclusive area to avoid that calls to RTE extend the interrupt lock time. */
#if (COMM_USERMODENOTIFUNC == STD_ON)
      if (ComM_StateChange[Channel] != COMM_NO_STATE_CHANGE)
      {
        SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
        ComM_StateChangeNotification(Channel);
        SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      }
#endif

      /* #50 If Notification of Channel Requesters is enabled, update the data via RTE Sender-Receiver Interface if applicable.
       *     Note: do it outside of the exclusive area to avoid that calls to RTE extend the interrupt lock time. */
#if( COMM_FULL_COMM_REQUEST_NOTIF == STD_ON )
      SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
      ComM_CurrentChannelRequestUpdate( Channel );
      SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
#endif

      /* #60 If Minimum FULL_COM Mode or Nm Light timer are enabled, handle the timers. */
#if ((COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON) || (COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
      ComM_ChannelHandleTimers(Channel, internalRequest);
#endif

      SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    } /* ComM_IsEnabledOfChannel(Channel) */

    /* #70 If Partial Networking is enabled and the current channel id is 0:
     *     1) handle the optional PNC Prepare Sleep Timer. Note: the timer value is same for all PNCs, it is calculated based on the cycle time of channel 0.
     *     2) if PNC Extended Functionality is enabled, handle PNCs without channels and perform state transitions if applicable. */
    /* #80 If Partial Networking is enabled and the current channel is enabled, handle PNCs with channels and perform state transitions if applicable. */
#if (COMM_PNC_SUPPORT == STD_ON)
    SchM_Enter_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

# if (COMM_ACTIVE_CHANNEL > 1U)
    if (Channel == 0u)
# endif
    {
# if (COMM_PNC_PS_TIMER > 0U)
      ComM_HandlePncPrepareSleepTimer();
# endif
# if (COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON)
      ComM_PncModeArbitrationWithoutChannels();
# endif
    }

# if (COMM_PNCCHANNELMAPPING == STD_ON)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
    /* If the channel is de-activated in the current variant, the main function shall do nothing
     * besides handling of PN prepare sleep timer. */
    if (ComM_IsEnabledOfChannel(Channel))
#  endif
    {
      ComM_PncModeArbitration(Channel);
    }
# endif

    SchM_Exit_ComM_COMM_EXCLUSIVE_AREA_1(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

    /* #90 If User Mode Notification is enabled, notify the mode change of PNC users via RTE Mode Switch Port. */
# if (COMM_USERMODENOTIFUNC == STD_ON)
    if( ComM_NotifyPncStateChange == TRUE )
    {
      /* PNC users: a PNC changed the state from FULL_COM to NO_COM or vice versa or the last mode notification failed (ESCAN00067386) */
      if( ComM_PncStateChangeNotification() == E_OK )
      {
        /* All PNC users have been successfully notified about new mode, reset the flag.
         * Otherwise, if at least one user mode notification failed, ComM will try again in the next task (ESCAN00067423) */
        ComM_NotifyPncStateChange = FALSE;
      }
    }
# endif
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_MAINFUNCTION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 *  ComM_ChannelStateTransition()
 **********************************************************************************************************************/
/*!
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
 */
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_ChannelStateTransition(NetworkHandleType channel, ComM_StateType highestComModeReq)
{
  ComM_StateType  calculatedComModeReq;  /* the calculated ComM mode */

  do
  {
    /* #10 Check if a timer is running for Nm Variants FULL or LIGHT. Do not perform any state transitions if
     *    1) Nm Light timer is running and there is no FULL_COM request by users or DCM (applicable in COMM_FULL_COM_READY_SLEEP or COMM_SILENT_COM) or
     *    2) Min FULL_COM mode timer is running.
     */
#if ((COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON) || (COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
    if(
# if ((COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
       ((ComM_GetNmLightTimer(channel) > 0x00) && (highestComModeReq == COMM_NO_COM_NO_PENDING_REQUEST)) ||
# endif
       (ComM_GetMinFullComModeTimer(channel) > 0x00)
      ) /* COV_COMM_TIMER_INIT_VALUE_CAN_BE_ONE */
    {
      highestComModeReq = ComM_ActiveComMode[channel];
    }
    /* #20 If no timer is running, calculate the next state transition step and perform as many transitions as needed
     *     to reach the target state, which is defined by the highest requested communication mode. */
    else
#endif
    {
      calculatedComModeReq = ComM_TransitionTable[highestComModeReq][ComM_ActiveComMode[channel]];
      if ((ComM_ActiveComMode[channel] < COMM_MAX_NUMBER_OF_STATES) && (calculatedComModeReq < COMM_MAX_NUMBER_OF_STATES))
      {
        if ((ComM_ActiveComMode[channel] == COMM_NO_COM_REQUEST_PENDING) && (calculatedComModeReq > COMM_NO_COM_REQUEST_PENDING))
        {
          /* #30 If the channel is in COMM_NO_COM_REQUEST_PENDING state and there is a pending request to start communication,
           *     check the Communication Allowed flag. If Communication Allowed is FALSE, stay in COMM_NO_COM_REQUEST_PENDING state
           *     and try again in the next task if request is still pending. */
          if( ComM_ComAllowed[channel] == FALSE )
          {
            highestComModeReq = ComM_ActiveComMode[channel];
          }
        }

        if (highestComModeReq != ComM_ActiveComMode[channel])
        {
          ComM_TransitionFctTable[calculatedComModeReq][ComM_ActiveComMode[channel]](channel); /* SBSW_COMM_TransitionFct_PointerCall */
          ComM_ActiveComMode[channel] = calculatedComModeReq;                                  /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
        }
      }
      else
      {
        highestComModeReq = ComM_ActiveComMode[channel];
      }
    }
  } while (ComM_ActiveComMode[channel] != highestComModeReq);
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#if ((COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON) || (COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
/**********************************************************************************************************************
 *  ComM_ChannelHandleTimers()
 **********************************************************************************************************************/
/*!
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
COMM_LOCAL_INLINE FUNC(void, COMM_CODE) ComM_ChannelHandleTimers(NetworkHandleType channel, boolean internalRequest)
{
  /* #10 If Minimum FULL_COM mode timer is running, decrement the timer.
   *     Cancel the timer in case an internal request (ComM user or Dcm) exists and the channel has Nm Variant LIGHT. */
  if(ComM_GetMinFullComModeTimer(channel) > 0x00u)
  {
    ComM_DecMinFullComModeTimer(channel); /* SBSW_COMM_CHANNEL_CSL02 */

#  if (COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL == STD_ON)
#   if (COMM_ISDEF_NMTYPEOFCHANNEL == STD_OFF)
    if (ComM_GetNmTypeOfChannel(channel) == COMM_LIGHT_NMTYPEOFCHANNEL) /* COV_COMM_SUBSET_OF_ELEMENTS */
#   endif
    {
      if (internalRequest == TRUE)
      {
        ComM_SetMinFullComModeTimer(channel, 0x00); /* SBSW_COMM_CHANNEL_CSL02 */
      }
    }
#  endif

    /* #20 If Minimum FULL_COM mode timer is expired, the communication is not required anymore and channel can leave Network Requested state.
     *     If Nm Variant is FULL the next state is Ready Sleep where ComM waits for a shutdown trigger from Nm.
     *     If Nm Variant is LIGHT the target state is NO_COM, the transition depends on configuration of Nm Light and Nm Light Silent timers. */
    if (ComM_GetMinFullComModeTimer(channel) == 0x00u)
    {
      /* Set the default state, it's accepted to overwrite it later (if Nm Type is FULL) to keep the code cleaner */
      ComM_BusComModeReq[channel] = COMM_NO_COM_NO_PENDING_REQUEST; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

#  if (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_ON)
#   if (COMM_ISDEF_NMTYPEOFCHANNEL == STD_OFF)
      if (ComM_GetNmTypeOfChannel(channel) == COMM_FULL_NMTYPEOFCHANNEL) /* COV_COMM_SUBSET_OF_ELEMENTS */
#   endif
      {
        ComM_BusComModeReq[channel] = COMM_FULL_COM_READY_SLEEP; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
#  endif
    }
  }

  /* #30 If Nm Light or Nm Light Silent timer is running, decrement the timer.
   *     If the timer is expired set the target state is NO_COM. Note that the variable ComM_NmLightTimer is
   *     shared by Nm Light and Nm Light Silent timers. If Nm Light timer is expired, the target state is NO_COM but
   *     the next state will be SI_COM in case Nm Light Silent timer is configured. */
# if ((COMM_NMLIGHTDURATIONOFCHANNEL == STD_ON) || (COMM_NMLIGHTSILENTDURATIONOFCHANNEL == STD_ON))
  if( ComM_GetNmLightTimer(channel) > 0x00u )
  {
    ComM_DecNmLightTimer(channel); /* SBSW_COMM_CHANNEL_CSL02 */

    if(ComM_GetNmLightTimer(channel) == 0x00u) /* COV_COMM_TIMER_INIT_VALUE_CAN_BE_ONE */
    {
      ComM_BusComModeReq[channel] = COMM_NO_COM_NO_PENDING_REQUEST; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    }
  }
# endif

# if (COMM_EXISTS_LIGHT_NMTYPEOFCHANNEL == STD_OFF)
  COMM_DUMMY_STATEMENT(internalRequest); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif


/**********************************************************************************************************************
  CALLBACK FUNCTIONS (AUTOSAR NM)
**********************************************************************************************************************/

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
/*********************************************************************************************************************
 *  ComM_Nm_NetworkStartIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_Nm_NetworkStartIndication(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and Nm support is enabled, forward the indication to the passive wake-up processing. */
    ComM_ProcessPassiveWakeUp( Channel );
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_NM_NETWORKSTARTINDICATION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
/*********************************************************************************************************************
 *  ComM_Nm_NetworkMode()
 *********************************************************************************************************************/
/*!
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
FUNC(void, COMM_CODE) ComM_Nm_NetworkMode(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and Nm support is enabled, process Network Mode notification. */
    /* #40 If Prepare Bus-Sleep Mode is supported and Network Mode is notified while ComM is in SI_COM and Nm
     *     has notified Prepare Bus Sleep Mode before it, immediately enter the target wake-up state of the channel
     *     (Network Requested or Ready Sleep) and trigger BusSM to enter FULL_COM to ensure that Nm message
     *     can be sent as first message on the bus. */
#  if (COMM_SILENTSUPPORTOFCHANNEL == STD_ON)
    if(( ComM_ActiveComMode[Channel] == COMM_SILENT_COM ) && ( ComM_BusComModeReq[Channel] == COMM_SILENT_COM ))
    {
      /* ESCAN00066282 Note: ComM_ActiveComMode is set first to ensure that condition is not re-entered. */
      ComM_ActiveComMode[Channel] = ComM_GetWakeupStateOfChannel(Channel); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      ComM_TransitionFctTable[ComM_GetWakeupStateOfChannel(Channel)][COMM_SILENT_COM](Channel); /* SBSW_COMM_TransitionFct_PointerCall */
    }
#  endif

    ComM_BusComModeReq[Channel] = ComM_GetWakeupStateOfChannel(Channel); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_NM_NETWORKMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if ((COMM_NMSUPPORTOFCHANNEL == STD_ON) && (COMM_SILENTSUPPORTOFCHANNEL == STD_ON))
/*********************************************************************************************************************
 *  ComM_Nm_PrepareBusSleepMode()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_Nm_PrepareBusSleepMode(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and Prepare Bus-Sleep mode is supported, initiate the state transition to SI_COM. */
    ComM_BusComModeReq[Channel] = COMM_SILENT_COM; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

    ComM_TF_Full_SiCom(Channel);

    ComM_ActiveComMode[Channel] = COMM_SILENT_COM; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_NM_PREPAREBUSSLEEPMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
/*********************************************************************************************************************
 *  ComM_Nm_BusSleepMode()
 *********************************************************************************************************************/
/*!
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
FUNC(void, COMM_CODE) ComM_Nm_BusSleepMode(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and support of Network Management is enabled, process the Bus Sleep Mode indication. */
# if( COMM_BUS_TYPE_FR_PRESENT == STD_ON )
#  if (COMM_ISDEF_BUSTYPEOFCHANNEL == STD_OFF)
    if (ComM_GetBusTypeOfChannel(Channel) == COMM_BUS_TYPE_FR)
#  endif
    {
      /* #40 Store the status that shutdown on a FlexRay channel has started (this is to counteract the so-called 'clique problem' on FlexRay). */
      ComM_FrShutdown[Channel] = TRUE; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
    }
# endif

    ComM_BusComModeReq[Channel] = COMM_NO_COM_NO_PENDING_REQUEST; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

    /* #50 There are two use cases how Nm calls the function which can be identified through ComM_ActiveComMode: */
# if (COMM_EXISTS_FULL_NMTYPEOFCHANNEL == STD_ON)
    if (ComM_ActiveComMode[Channel] == COMM_FULL_COM_NETWORK_REQUESTED)
    {
      /* #60 ComM_Nm_BusSleepMode() is called in context of Nm_NetworkRelease() while ComM performs the state transition COMM_FULL_COM_NETWORK_REQUESTED to COMM_FULL_COM_READY_SLEEP.
       *     This is only possible if LinNm without coordination (ESCAN00061388, ESCAN00072736) or J1939Nm (ESCAN00071329) is configured on the channel.
       *     Do nothing here and perform the transition to NoCom in the next ComM_MainFunction(). */
    }
    else
# endif
    {
      /* #70 ComM_Nm_BusSleepMode() is called from the main function of a Nm module, this is the normal case. ComM shall perform the transition to NoCom immediately. */
      ComM_TF_SiCom_NoCom(Channel);
    }

    /* #80 If FrSM reached NO_COM state, set the FlexRay shutdown status as finished. */
# if (COMM_BUS_TYPE_FR_PRESENT == STD_ON)
#  if (COMM_ISDEF_BUSTYPEOFCHANNEL == STD_OFF)
    if (ComM_GetBusTypeOfChannel(Channel) == COMM_BUS_TYPE_FR)
#  endif
    {
      if ((ComM_BusSmState[Channel] == COMM_NO_COMMUNICATION) && (ComM_FrShutdown[Channel] == TRUE))
      {
        ComM_FrShutdown[Channel] = FALSE; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
    }
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_NM_BUSSLEEPMODE, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_NMSUPPORTOFCHANNEL == STD_ON)
/*********************************************************************************************************************
 *  ComM_Nm_RestartIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_Nm_RestartIndication(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If parameter checks are successful and Nm support is enabled, forward the indication to the passive wake-up processing. */
    ComM_ProcessPassiveWakeUp( Channel );
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_NM_RESTARTINDICATION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/*********************************************************************************************************************
 *  ComM_Nm_StateChangeNotification()
 *********************************************************************************************************************/
/*!
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
FUNC(void, COMM_CODE) ComM_Nm_StateChangeNotification( CONST(NetworkHandleType, AUTOMATIC) Channel, CONST(Nm_StateType, AUTOMATIC) NmPreviousState, CONST(Nm_StateType, AUTOMATIC) NmCurrentState )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;
  ComM_PncIterType pnc;
  ComM_PncChannelMappingIterType pncChIdx;
  ComM_SizeOfPncSignalType signalIndex;
  boolean sendSignal = FALSE;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* PRQA S 0715 SUPPRESS_0715 */ /* MD_MSR_1.1 */
    if (ComM_IsPncLimitationUsedOfChannelPb(Channel)) /* COV_COMM_SUBSET_OF_ELEMENTS */
    {
      if (NmCurrentState == NM_STATE_REPEAT_MESSAGE)
      {
        /* #30 If Nm entered NM_STATE_REPEAT_MESSAGE state, set the status bit accordingly. */
        if( ComM_PncToChannelRoutingState[Channel] == COMM_PNCROUTING_LIMITED )
        {
          /* #300 If PNC routing is limited on the channel, immediately send PNC bits = 1 for all PNC's connected to the channel
           *      and being in state PNC_REQUESTED.
           */
          for (signalIndex = 0; signalIndex < ComM_GetSizeOfPncSignal(); signalIndex++) /* COV_COMM_FOR_LOOP_OPTIMIZATION */
          {
            if ((ComM_GetTypeOfPncSignal(signalIndex) == COMM_EIRA_TX_TYPEOFPNCSIGNAL) && (ComM_GetChannelIdxOfPncSignal(signalIndex) == Channel))
            {
              for (pnc = 0; pnc < ComM_GetSizeOfPnc(); pnc++)
              {
                for (pncChIdx = ComM_GetPncChannelMappingStartIdxOfPncPb(pnc); pncChIdx < ComM_GetPncChannelMappingEndIdxOfPncPb(pnc); pncChIdx++)
                {
                  /* PRQA S 3415 1 */ /* MD_ComM_3415 */
                  if ((!ComM_IsSignalStoredPncBitSet(signalIndex, pnc)) &&
                      (ComM_GetPncChannelMapping(pncChIdx) == Channel) &&
                      (ComM_PncGetGwChannelState(Channel, ComM_GetActivePncComMode(pnc)) == COMM_FULL_COM_NETWORK_REQUESTED))
                  {
                    /* #310 Attaching the channel: PNC Routing Limitation becomes temporarily disabled, send PNC bit = 1 if
                     *      1) PNC state is COMM_PNC_REQUESTED (the highest activation), then send bit = 1 on each channel or
                     *      2) PNC state is COMM_PNC_REQUESTED_PASSIVE (lower activation), then send bit = 1 on ACTIVE channels only.
                     */
                    ComM_PncSetBitInSignal(signalIndex, pnc);
                    sendSignal = TRUE;
                  }
                }
              }

              if (sendSignal == TRUE)
              {
                ComM_ExecuteComSendSignal(signalIndex, ComM_GetAddrPncSignalValues(ComM_GetPncSignalValuesStartIdxOfPncSignal(signalIndex))); /* SBSW_COMM_CALL_WITH_PTR_TO_CONST */
              }
              break; /* There is only one EIRA_TX signal per channel */
            }
          }
        }

        /* Example sequence: Routing Limitation is enabled on a channel and a PNC is already in PNC_REQUESTED.
         * Channel user requests FULL_COM, channel enters COMM_NETWORK_REQUESTED and Nm enters NM_STATE_REPEAT_MESSAGE.
         * Then the user requests NO_COM while Nm is still in NM_STATE_REPEAT_MESSAGE. In this case
         * ComM_PncToChannelRoutingState[Channel] shall be COMM_PNCROUTING_NM_REPEAT_MESSAGE and PNC bit=1 shall be
         * sent as long as Nm is in Repeat Message state.
         */
        ComM_PncToChannelRoutingState[Channel] |= COMM_PNCROUTING_NM_REPEAT_MESSAGE; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
      else if (NmPreviousState == NM_STATE_REPEAT_MESSAGE)
      {
        /* #40 If Nm has left NM_STATE_REPEAT_MESSAGE, clear the status bit. If PNC routing status changes to COMM_PNCROUTING_LIMITED,
         *     ComM will set PNC bits to 0 for all PNC's connected to the channel and being in state PNC_REQUESTED in the next ComM_MainFunction().
         */
        ComM_PncToChannelRoutingState[Channel] &= COMM_PNCROUTING_NM_REPEAT_MESSAGE_CLEAR; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      }
      else
      {
        /* nothing to do */
      }
    }
    /* PRQA L:SUPPRESS_0715 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_NM_STATECHANGENOTIFICATION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif

} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
  CALLBACK FUNCTIONS (AUTOSAR DCM)
**********************************************************************************************************************/

#if (COMM_DCM_INDICATION == STD_ON)
/*********************************************************************************************************************
 *  ComM_DCM_ActiveDiagnostic()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_DCM_ActiveDiagnostic(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Check that Nm Variant of the channel is not PASSIVE. */
# if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
#  if (COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL == STD_ON)
    if (ComM_GetNmTypeOfChannel(Channel) == COMM_PASSIVE_NMTYPEOFCHANNEL)
    {
      errorId = COMM_E_DIAGNOSTIC_NOT_SUPPORTED; /* ESCAN00072762 */
    }
    else
#  endif
    /* #40 If parameter checks are successful, store the active status of the diagnostic session on the channel. */
    {
      ComM_SetDcmRequestActive(Channel, TRUE); /* SBSW_COMM_CHANNEL_CSL02 */
      errorId = COMM_E_NO_ERROR;
    }
# else
    errorId = COMM_E_DIAGNOSTIC_NOT_SUPPORTED; /* ESCAN00072762 */
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
#  if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_OFF)
  /* Don't need a condition because errorId == COMM_E_DIAGNOSTIC_NOT_SUPPORTED in this case */
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  else
  if (errorId != COMM_E_NO_ERROR)
#  endif
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_DCM_ACTIVEDIAGNOSTIC, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

#if (COMM_DCM_INDICATION == STD_ON)
/*********************************************************************************************************************
 *  ComM_DCM_InactiveDiagnostic()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_DCM_InactiveDiagnostic(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 Check that Nm Variant of the channel is not PASSIVE. */
# if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_ON)
#  if (COMM_EXISTS_PASSIVE_NMTYPEOFCHANNEL == STD_ON)
    if (ComM_GetNmTypeOfChannel(Channel) == COMM_PASSIVE_NMTYPEOFCHANNEL)
    {
      errorId = COMM_E_DIAGNOSTIC_NOT_SUPPORTED; /* ESCAN00072762 */
    }
    else
#  endif
    /* #40 If parameter checks are successful, store the inactive status of the diagnostic session on the channel. */
    {
      ComM_SetDcmRequestActive(Channel, FALSE); /* SBSW_COMM_CHANNEL_CSL02 */
      errorId = COMM_E_NO_ERROR;
    }
# else
    errorId = COMM_E_DIAGNOSTIC_NOT_SUPPORTED; /* ESCAN00072762 */
# endif
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
#  if (COMM_KEEP_AWAKE_CHANNELS_SUPPORT == STD_OFF)
  /* Don't need a condition because errorId == COMM_E_DIAGNOSTIC_NOT_SUPPORTED in this case */
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  else
  if (errorId != COMM_E_NO_ERROR)
#  endif
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_DCM_INACTIVEDIAGNOSTIC, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
}
#endif

/**********************************************************************************************************************
  CALLBACK FUNCTIONS (AUTOSAR EcuM)
**********************************************************************************************************************/

/*********************************************************************************************************************
 *  ComM_EcuM_WakeUpIndication()
 *********************************************************************************************************************/
/*!
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
FUNC(void, COMM_CODE) ComM_EcuM_WakeUpIndication(NetworkHandleType Channel)
{
  /* ----- Local Variables ---------------------------------------------- */
#if ( COMM_SYNCHRONOUS_WAKE_UP == STD_ON )
  uint8 ComM_ChannelIndex;
# if ( COMM_PNC_SUPPORT == STD_ON )
#  if (COMM_PNC_PS_TIMER > 0U) /* ESCAN00067357 */
  ComM_PncIterType pncIndex;
#  endif
# endif
#endif
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 If Synchronous Wake-up is enabled, notify passive wake-up to all ComM channels being in NO_COM or SI_COM state.
     *     This is done by setting the bus-side requested state to FULL_COM (Network Requested or Ready Sleep). */
#if ( COMM_SYNCHRONOUS_WAKE_UP == STD_ON )
    for(ComM_ChannelIndex = 0; ComM_ChannelIndex < ComM_GetSizeOfChannel(); ComM_ChannelIndex++)
    {
      if((ComM_ActiveComMode[ComM_ChannelIndex] & COMM_FULL_COMMUNICATION) == 0u)
      {
        ComM_BusComModeReq[ComM_ChannelIndex] = ComM_GetWakeupStateOfChannel(ComM_ChannelIndex); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

        /* #31 If NM Gateway Extension is enabled notify Nm_PassiveStartUp() for each channel with Nm. */
# if( COMM_NM_GW_EXT_ENABLED == STD_ON )
#  if (COMM_ISDEF_NMSUPPORTOFCHANNEL == STD_OFF)
        if (ComM_IsNmSupportOfChannel(ComM_ChannelIndex))
#  endif
        {
          (void)Nm_PassiveStartUp(ComM_ChannelIndex);
        }
# endif
      }
    }

    /* #40 If Synchronous Wake-up is enabled, activate all PNCs at least for the duration of the PNC Prepare Sleep Timer. */
# if (COMM_PNC_SUPPORT == STD_ON)
#  if (COMM_PNC_PS_TIMER > 0U) /* ESCAN00067357 */
#   if (COMM_PNC_CHECK_ENABLED_AT_RUNTIME == STD_ON)
    if(ComM_HasPncPb())
#   endif
    {
      for(pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
      {
        if( (ComM_GetActivePncComMode(pncIndex) == COMM_PNC_NO_COMMUNICATION) && (ComM_GetBusPncComModeReq(pncIndex) == COMM_PNC_NO_COMMUNICATION) )
        {
          ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_PREPARE_SLEEP); /* SBSW_COMM_PNC_CSL02 */
        }
      }
    }
#  endif
# endif

#else /* #if ( COMM_SYNCHRONOUS_WAKE_UP == STD_ON ) */

    /* #50 If Synchronous Wake-up is disabled, notify passive wake-up to the channel by setting the bus-side
     *     requested state to FULL_COM (Network Requested or Ready Sleep). Ignore the wake-up in FULL_COM mode. */
    if((ComM_ActiveComMode[Channel] & COMM_FULL_COMMUNICATION) == 0u) /* ESCAN00091475 */
    {
      ComM_BusComModeReq[Channel] = ComM_GetWakeupStateOfChannel(Channel); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      
      /* #51 If NM Gateway Extension is enabled notify Nm_PassiveStartUp(). */
# if( COMM_NM_GW_EXT_ENABLED == STD_ON )
#  if (COMM_ISDEF_NMSUPPORTOFCHANNEL == STD_OFF)
      if (ComM_IsNmSupportOfChannel(Channel)) /* COV_COMM_SUBSET_OF_ELEMENTS */
#  endif
      {
        (void)Nm_PassiveStartUp(Channel);
      }
# endif
    }

#endif /* #if ( COMM_SYNCHRONOUS_WAKE_UP == STD_ON ) */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_ECUM_WAKEUPINDICATION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
  COMM_DUMMY_STATEMENT(Channel); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
#  endif
# endif
} /* PRQA S 6030, 6080 */ /* MD_MSR_STCYC, MD_MSR_STMIF */

#if ((COMM_WAKEUPENABLEDOFPNC == STD_ON) && (COMM_PNC_PS_TIMER > 0U))
/*********************************************************************************************************************
 *  ComM_EcuM_PNCWakeUpIndication()
 *********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
FUNC(void, COMM_CODE) ComM_EcuM_PNCWakeUpIndication( PNCHandleType PNCid )
{
  /* ----- Local Variables ---------------------------------------------- */  
  uint8 errorId = COMM_E_WRONG_PARAMETERS;
  ComM_PncIterType pncIndex;
  ComM_PncChannelMappingIterType pncChannelMappingIndex;
  ComM_ChannelIterType channelIndex;

  /* ----- Development Error Checks ------------------------------------- */
# if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus == (ComM_InitStatusType)COMM_UNINIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
# if (COMM_PNC_CHECK_ENABLED_AT_RUNTIME == STD_ON)
    if(ComM_HasPncPb())
# endif
    {
      /* Get the internal PNC index from the given PNC identifier */
      for (pncIndex = 0; pncIndex < ComM_GetSizeOfPnc(); pncIndex++)
      {
        if (PNCid == ComM_GetPncIdOfPnc(pncIndex))
        {
          break;
        }
      }

      /* #20 Check parameter 'PNCid': it must be a valid PNC identifier. */
      if (pncIndex < ComM_GetSizeOfPnc())
      {
        /* #30 Wakeup the PNC if it is in NO_COM state and no wake-up occurred before. */
        if ((ComM_GetActivePncComMode(pncIndex) == COMM_PNC_NO_COMMUNICATION) && (ComM_GetBusPncComModeReq(pncIndex) == COMM_PNC_NO_COMMUNICATION))
        {
          ComM_SetBusPncComModeReq(pncIndex, COMM_PNC_PREPARE_SLEEP); /* SBSW_COMM_PNC_CSL02 */
        }

        /* #40 Propagate the wake-up to all channels that are mapped to the PNC and are in NO_COM or SI_COM state. */
        for (pncChannelMappingIndex = ComM_GetPncChannelMappingStartIdxOfPncPb(pncIndex);
             pncChannelMappingIndex < ComM_GetPncChannelMappingEndIdxOfPncPb(pncIndex);
             pncChannelMappingIndex++)
        {
          channelIndex = ComM_GetPncChannelMapping(pncChannelMappingIndex);

          if ((ComM_ActiveComMode[channelIndex] & COMM_FULL_COMMUNICATION) == 0u)
          {
            ComM_BusComModeReq[channelIndex] = ComM_GetWakeupStateOfChannel(channelIndex); /* SBSW_COMM_BusComModeReq_over_PncChannelMapping_CSL03 */
          }
        }

        /* #50 If Synchronous Wake-up is enabled, propagate the wake-up to all channels that are in NO_COM or SI_COM state. */
# if (COMM_SYNCHRONOUS_WAKE_UP == STD_ON)
        for(channelIndex = 0; channelIndex < ComM_GetSizeOfChannel(); channelIndex++)
        {
          if((ComM_ActiveComMode[channelIndex] & COMM_FULL_COMMUNICATION) == 0u)
          {
            ComM_BusComModeReq[channelIndex] = ComM_GetWakeupStateOfChannel(channelIndex); /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
          }
        }
# endif

# if (COMM_DEV_ERROR_REPORT == STD_ON)
        errorId = COMM_E_NO_ERROR;
# endif
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  /* #60 Report errors if applicable. */
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_ECUM_PNCWAKEUPINDICATION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

/**********************************************************************************************************************
  CALLBACK FUNCTIONS (AUTOSAR BusSM)
**********************************************************************************************************************/

/*********************************************************************************************************************
 *  ComM_BusSM_ModeIndication()
 *********************************************************************************************************************/
/*!
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
 */
/* PRQA S 3673 1 */ /* MD_ComM_3673 */
FUNC(void, COMM_CODE) ComM_BusSM_ModeIndication(NetworkHandleType Channel, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode)
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId = COMM_E_NO_ERROR;

  /* ----- Development Error Checks ------------------------------------- */
#if (COMM_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check that module is initialized. */
  if (ComM_InitStatus != COMM_INIT)
  {
    errorId = COMM_E_NOT_INITED;
  }
  /* #20 Check parameter 'Channel': it must be valid and active in the current variant. */
  else if ((Channel >= COMM_ACTIVE_CHANNEL)
#  if (COMM_ENABLEDOFCHANNEL == STD_ON)
   || (!ComM_IsEnabledOfChannel(Channel))
#  endif
       )
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  /* #30 Check parameter 'ComMode': it must be a valid pointer and its value must be a valid communication mode. */
  else if (ComMode == NULL_PTR)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else if (*ComMode > COMM_FULL_COMMUNICATION)
  {
    errorId = COMM_E_WRONG_PARAMETERS;
  }
  else
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    if( ComM_BusSmState[Channel] != *ComMode )
    {
      /* #40 If BusSM indicated a new mode, store it and propagate to BswM. */
      /* ESCAN00065236 */
      ComM_BusSmState[Channel] = *ComMode; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
      BswM_ComM_CurrentMode( Channel, *ComMode );

      /* #50 If a passive wake-up occurred during shutdown of FR, restore the target requested mode to start communication in the next main function. */
#if (COMM_BUS_TYPE_FR_PRESENT == STD_ON)
# if (COMM_ISDEF_BUSTYPEOFCHANNEL == STD_OFF)
      if (ComM_GetBusTypeOfChannel(Channel) == COMM_BUS_TYPE_FR)
# endif
      {
        if (*ComMode == COMM_NO_COMMUNICATION)
        {
          ComM_FrShutdown[Channel] = FALSE; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */

          /* ESCAN00081330: ComM_BusComModeReqFrShutdown can be COMM_FULL_COM_NETWORK_REQUESTED or COMM_FULL_COM_READY_SLEEP depending on Min Full Com Mode Duration. */
          if(ComM_BusComModeReqFrShutdown[Channel] != COMM_NO_COM_NO_PENDING_REQUEST)
          {
            ComM_BusComModeReq[Channel] = ComM_BusComModeReqFrShutdown[Channel]; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
            ComM_BusComModeReqFrShutdown[Channel] = COMM_NO_COM_NO_PENDING_REQUEST; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
          }
        }
      }
#endif

      /* #60 Store the new mode to handle User Mode Notification in the next main function. */
#if (COMM_USERMODENOTIFUNC == STD_ON)
      ComM_StateChange[Channel] = *ComMode; /* SBSW_COMM_ARRAY_CHANNEL_WRITE */
#endif

      /* #70 Notify Dcm about the new mode. */
#if (COMM_DCM_INDICATION == STD_ON)
      switch (*ComMode)
      {
      case COMM_FULL_COMMUNICATION:
        Dcm_ComM_FullComModeEntered(Channel);
        break;

      case COMM_SILENT_COMMUNICATION:
        Dcm_ComM_SilentComModeEntered(Channel);
        break;

      case COMM_NO_COMMUNICATION:
        Dcm_ComM_NoComModeEntered(Channel);
        break;

      default: /* COV_COMM_MISRA */
        break;
      }
#endif

      /* #80 If NO_COM is indicated and Reset after Forcing NO_COM is enabled, check if a reset can be performed. */
#if (COMM_RESETAFTERFORCINGNOCOMMOFCHANNEL == STD_ON)
      if (*ComMode == COMM_NO_COMMUNICATION)
      {
        ComM_ChannelResetAfterForcingNoComm();
      }
#endif
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (COMM_DEV_ERROR_REPORT == STD_ON)
  if (errorId != COMM_E_NO_ERROR)
  {
    (void)Det_ReportError( COMM_MODULE_ID, COMM_INSTANCE_ID_DET, COMM_SID_CBK_BUSSMMODEINDICATION, errorId );
  }
# else
  COMM_DUMMY_STATEMENT(errorId); /* PRQA S 3112, 3199 */ /* MD_MSR_14.2 */ /*lint -e{438} */
# endif
} /* PRQA S 6010, 6030, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STMIF */

/* module specific MISRA deviations:
MD_ComM_2018:
      Reason:     Default label is provided as a defensive measure against possible future code changes and to comply with rule 15.3.
      Risk:       There is no risk.
      Prevention: Covered by code review.
MD_ComM_3218:
      Reason:     Some compilers are not able to compile code with static declarations inside functions.
      Risk:       There is no risk.
      Prevention: N/A
MD_ComM_3415:
      Reason:     The function does not have any side-effects (it does not change the module' state').
      Risk:       There is no risk.
      Prevention: Covered by code review.
MD_ComM_3451:
      Reason:     It is ensured by code generator that the declarations remain compatible. The first declaration is in ComM_Private_Cfg.h, which is not included via ComM.h. 
                  The second declaration is in ComM_Lcfg.h, which is included via ComM.h and therefore visible to other modules.
      Risk:       There is no risk.
      Prevention: Covered by code review.
MD_ComM_3673:
      Reason:     The function parameter list is required by the AUTOSAR specification.
      Risk:       There is no risk.
      Prevention: N/A.
MD_ComM_3689:
      Reason:     A function parameter is used to access an array element. The parameter is always passed by an internal ComM function (e.g. by ComM_MainFunction) that ensures that the parameter 
                  is in a valid range. The parameter cannot be written by other BSW module or application. Additional run-time check is therefore omitted.
      Risk:       There is no risk.
      Prevention: Covered by code review.
MD_ComM_3355_3358:
      Reason:     Run-time check of generated array size that shall always return true.
      Risk:       There is no risk.
      Prevention: Covered by code review.
MD_ComM_3325_3201:
      Reason:     Run-time check of generated data that shall always return false.
      Risk:       There is no risk.
      Prevention: Covered by code review.
*/

/* SBSW_JUSTIFICATION_BEGIN

\ID                SBSW_COMM_CSL01
\DESCRIPTION       Access to an array using the GetSizeOf macro of the this array.
\COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

\ID                SBSW_COMM_UserReqFullCom_over_ChannelPb_or_ByteMask_CSL03
\DESCRIPTION       Access to ComM_UserReqFullCom via indirection over ComM_UserByteMask or ComM_ChannelPb structure respectively.
\COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

\ID                SBSW_COMM_UserReqPncFullCom_over_UserPncByteMask_or_PncPb_CSL03
\DESCRIPTION       Access to ComM_UserReqPncFullCom via indirection over ComM_UserPncByteMask or ComM_PncPb structure respectively.
\COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

\ID                SBSW_COMM_BusComModeReq_over_PncChannelMapping_CSL03
\DESCRIPTION       Access to ComM_BusComModeReq via indirection over ComM_PncChannelMapping structure.
\COUNTERMEASURE \N Qualified use-case CSL03 of ComStackLib

\ID                SBSW_COMM_PNC_CSL02
\DESCRIPTION       Access to an array that has a size relation to ComM_Pnc.
\COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID                SBSW_COMM_USER_CSL02
\DESCRIPTION       Access to an array that has a size relation to ComM_User.
\COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID                SBSW_COMM_CHANNEL_CSL02
\DESCRIPTION       Access to an array that has a size relation to ComM_Channel.
\COUNTERMEASURE \N Qualified use-case CSL02 of ComStackLib

\ID                SBSW_COMM_ARRAY_CHANNEL_WRITE
\DESCRIPTION       Write access to an array of size COMM_ACTIVE_CHANNEL.
\COUNTERMEASURE \N A preprocessor check ensures that COMM_ACTIVE_CHANNEL == ComM_GetSizeOfChannel(). The reason is that some channel-based arrays are
                   defined locally in this file and some are defined using the ComStackLib. The check is needed to ensure that arrays have the same size.
                   For all implementation variant ComM_GetSizeOfChannel() is always defined to a constant number.
                   If used in a for loop, the array index is always smaller than ComM_GetSizeOfChannel(). If a function parameter
                   is used as array index, the validity is ensured by a DET check.

\ID                SBSW_COMM_PARAMETER_PTR_WRITE
\DESCRIPTION       The function writes to the pointer parameter.
\COUNTERMEASURE \N The caller ensures that the parameters of the following functions point to a valid memory location:
                   'Status': ComM_GetStatus(), ComM_GetInhibitionStatus();
                   'State': ComM_GetState();
                   'ComMode': ComM_GetMaxComMode(), ComM_GetRequestedComMode(), ComM_GetCurrentComMode();
                   'CounterValue': ComM_ReadInhibitCounter();
                   'Versioninfo': ComM_GetVersionInfo().

\ID                SBSW_COMM_CALL_WITH_PTR_TO_CONST
\DESCRIPTION       A pointer to constant data is passed to a called function.
\COUNTERMEASURE \N The pointed data is constant and cannot be written.

\ID                SBSW_COMM_CALL_BUSSM_GET_CURRENT_COMMODE
\DESCRIPTION       A pointer is passed to a BusSM function as parameter and could be used within the function directly to write to a memory location.
\COUNTERMEASURE \N This function is called by ComM_GetCurrentComMode() only, which provides a pointer to a local variable.
                   This pointer is passed to the callee (BusSM) without changes. This ensures that the callee always gets a valid pointer.

\ID                SBSW_COMM_PASSED_PTR_WRITE_ACCESS
\DESCRIPTION       A pointer is passed to ComM_GetCurrentBusSMMode() and is used within the function directly to write to a memory location.
\COUNTERMEASURE \N This function is called by ComM_GetCurrentComMode() only, which provides a pointer to a local variable.

\ID                SBSW_COMM_CALL_WITH_PTR_TO_LOCAL_VARIABLE
\DESCRIPTION       A pointer is passed to a function as parameter and is used within the function directly to write to a memory location.
\COUNTERMEASURE \N The passed pointer references a local stack variable and is therefore always valid.

\ID                SBSW_COMM_ARRAY_CHANNEL_REQUESTORS_WRITE
\DESCRIPTION       The function writes to the array handleArray[]. The index is limited by a generated define containing the array size.
                   The type of the array is defined by RTE because it is used to exchange data via Sender-Receiver Interface ComM_CurrentChannelRequest.
\COUNTERMEASURE \S Verify that the array size generated by ComM matches to the array size in the type definition of RTE. The following procedure shall be
                   applied to each channel that has activated the ComM parameter 'Full Comm Request Notification Enabled'.
                   1) ComM_Cfg.h contains array size definition in the format COMM_MAX_CR_<ShortNameOfChannel>
                   2) rte_type.h contains the definition of the corresponding structure type in the format ComM_UserHandleArrayType_<ShortNameOfChannel>
                   3) Verify that the structure member 'handleArray' has the same size as the corresponding define value of ComM in 1).
                   4) Verify the content of the generated functions ComM_CurrentChannelRequestInit and ComM_CurrentChannelRequestNotification to ensure that
                      the proper define COMM_MAX_CR_<ShortNameOfChannel> is used to limit the array index when writing to
                      ComM_UserHandleArrayType_<ShortNameOfChannel>.handleArray[]. [SMI-94]

\ID                SBSW_COMM_CALL_COM_RECEIVE_SIGNAL
\DESCRIPTION       This function passes a pointer to Com_ReceiveSignal(), which uses the pointer to write to a memory location.
\COUNTERMEASURE \S Verify that the value of ComSignalLength (byte) in Com module is smaller or equal to the value of COMM_PNC_SIGNAL_LENGTH (can be found in ComM_Cfg.h).
                   This shall be verified for each ComPncSignal referenced by Partial Network Clusters and having ComMPncComSignalDirection = RX. [SMI-95]

\ID                SBSW_COMM_TransitionFct_PointerCall
\DESCRIPTION       Calling a function pointer defined in ComM_TransitionFctTable[].
\COUNTERMEASURE \R A runtime check ensures that array index never exceeds the size of ComM_TransitionFctTable[]. It is ensured by code inspection that the elements
                   of ComM_TransitionFctTable[] are valid state transition functions and the size of the array is COMM_MAX_NUMBER_OF_STATES.

\ID                SBSW_COMM_UserModeNotiFunc_PointerCall
\DESCRIPTION       Calling a function pointer defined in ComM_UserModeNotiFunc[].
\COUNTERMEASURE \S The user of MICROSAR Safe shall verify that each element of ComM_UserModeNotiFunc[] is either a valid function pointer or NULL_PTR.
                   This measure is only needed if at least one ComM user has enabled the parameter 'User Mode Notification'. [SMI-1046]
                \R A runtime check prevents dereferencing a NULL pointer.
                \R Qualified use-case CSL01 of ComStackLib because ComM_GetSizeOfUserModeNotiFunc() is used to check the array index.

SBSW_JUSTIFICATION_END */

/* START_COVERAGE_JUSTIFICATION

\ID COV_COMM_MISRA
  \ACCEPT XX
  \REASON [MSR_COV_MISRA]

\ID COV_COMM_GENDATA_CHECK
  \ACCEPT TX
  \ACCEPT XF
  \REASON The condition is for plausibility checks of the generated data. The code is verified by code inspection.

\ID COV_COMM_MAGICNUMBER_CHECK
  \ACCEPT XF
  \REASON The condition is for magic number check of the post-build data. The code is verified by code inspection.

\ID COV_COMM_FOR_LOOP_OPTIMIZATION
  \ACCEPT TX
  \ACCEPT TF tf tx
  \REASON A run-time optimization to cut short a for loop using a break statement. The loop goes through an element list where exactly one element meets certain
          conditions inside the loop. Once the element is found, the loop can be terminated to save run-time.

\ID COV_COMM_SUBSET_OF_ELEMENTS
  \ACCEPT TX
  \ACCEPT XF
  \REASON There is an iteration loop over elements such as channels or PNCs or signals and an action (e.g. an API call) has to be performed if an element has a 
          certain configuration parameter set to true. This parameter is used to select a subset of elements at run-time and it may be true for all relevant elements 
          in some configurations so that the run-time decision always returns true. An encapsulation of such run-time decisions would substantially degrade 
          readability of the code. The run-time decisions do not have an else branch.

\ID COV_COMM_TIMER_INIT_VALUE_CAN_BE_ONE
  \ACCEPT TX
  \ACCEPT TF tf tx tf
  \REASON A timer value can be configured to exactly one main function period of the corresponding channel. In this case after decrementing the timer its value is always 0.

\ID COV_COMM_COMMON_USER_WITH_MODE_NOTIFICATION
  \ACCEPT TX
  \REASON In some configurations a user can be mapped to all channels. If such a user has mode notification enabled, 
          every state change of a channel triggers a re-calculation of the lowest mode of this user.

\ID COV_COMM_PNC_EXTENDED_NO_ERA_ON_ACTIVE_CHANNEL
  \ACCEPT XF xf xx
  \REASON In configurations with COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON it is possible to assign Gateway Type ACTIVE to so called additional channels (e.g. LIN)
          in order to keep those channels awake via PNC. But ERA signals cannot be received on those channels.

\ID COV_COMM_PNC_EXTENDED_SINGLE_ERA
  \ACCEPT TX
  \REASON In configurations with COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON it is possible to have only one ERA signal. When this ERA signal is received
          and PNC bit is 0 the corresponding PNC system user shall be released. Note that having multiple ERA signals is the most common use case.

\ID COV_COMM_PNC_EXTENDED_ALL_PNC_WITHOUT_CHANNELS
  \ACCEPT TF tf tx
  \REASON In configurations with COMM_PNC_EXTENDED_FUNCTIONALITY_ENABLED == STD_ON it is possible that all PNCs have no channels. Therefore all PNC users have no
          connections to channels.

\ID COV_COMM_PNC_ON_CHANNELS_NM_PASSIVE
  \ACCEPT TF tf tx
  \ACCEPT TX
  \REASON In configurations where PNCs are mapped only to channels with Nm Type PASSIVE all user requests to those PNCs are ignored.

\ID COV_COMM_ALL_CHANNELS_NM_NONE
  \ACCEPT TX tf tf
  \REASON This is an optimization for the (improbable) case that all channels have Nm Variant NONE and Mode Limitation is enabled.

END_COVERAGE_JUSTIFICATION */

#define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"
