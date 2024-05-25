/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: EcuM
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: EcuM_PrivateCfg.h
 *   Generation Time: 2024-01-08 16:27:34
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/


#if !defined(ECUM_PRIVATECFG_H)
# define ECUM_PRIVATECFG_H

# if ( (defined ECUM_PRIVATE_CFG_INCLUDE) || (defined ECUM_PRIVATE_CFG_PARTLY_INCLUDE))
# else
#  error "EcuM_PrivateCfg.h must not be included outside of EcuM scope"
# endif

# if (defined ECUM_PRIVATE_CFG_INCLUDE)
#  include "EcuM_Init_PBcfg.h"
# endif

# include "Os.h"
# include "Mcu.h"
# include "Det.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/

/* PRQA S 3453 functiongen *//* MD_MSR_FctLikeMacro */
# define EcuM_GlobalSuspend()                                         DisableAllInterrupts()  
# define EcuM_GlobalRestore()                                         EnableAllInterrupts() 
/* PRQA L:functiongen */




/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  EcuMPCGetConstantDuplicatedRootDataMacros  EcuM Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define EcuM_GetCoreStatusOfPCConfig()                                EcuM_CoreStatus  /**< the pointer to EcuM_CoreStatus */
#define EcuM_GetDefaultAppModeOfPCConfig()                            OSDEFAULTAPPMODE  /**< EcuMDefaultAppMode of the Os module */
#define EcuM_GetDefaultShutdownModeOfPCConfig()                       0u  /**< Default Shutdown Mode - Depending on target it its either a Sleep Mode or Reset Mode. */
#define EcuM_GetDefaultShutdownTargetOfPCConfig()                     ECUM_STATE_OFF  /**< Default Shutdown Target */
#define EcuM_GetDriverInitOneOfPCConfig()                             EcuM_DriverInitOne  /**< the pointer to EcuM_DriverInitOne */
#define EcuM_GetEcuM_CRCHash_LowerOfPCConfig()                        0x6F3AD2A2u
#define EcuM_GetEcuM_CRCHash_UpperOfPCConfig()                        0xA9B813AFu
#define EcuM_GetGeneratorCompatibilityVersionOfPCConfig()             2560u
#define EcuM_GetMaxWakeupSourceCountOfPCConfig()                      11u  /**< Max Wakeup source count. */
#define EcuM_GetModuleStateOfPCConfig()                               (&(EcuM_ModuleState))  /**< the pointer to EcuM_ModuleState */
#define EcuM_GetNormalMcuModeOfPCConfig()                             McuConf_McuModeSettingConf_McuModeSettingConf_0  /**< EcuMNormalMcuModeRef id of the Mcu module */
#define EcuM_GetPartitionInitOfPCConfig()                             EcuM_PartitionInit  /**< the pointer to EcuM_PartitionInit */
#define EcuM_GetSizeOfCoreStatusOfPCConfig()                          6u  /**< the number of accomplishable value elements in EcuM_CoreStatus */
#define EcuM_GetSizeOfDriverInitOneOfPCConfig()                       1u  /**< the number of accomplishable value elements in EcuM_DriverInitOne */
#define EcuM_GetSizeOfPartitionInitOfPCConfig()                       6u  /**< the number of accomplishable value elements in EcuM_PartitionInit */
#define EcuM_GetSizeOfWakeupSourceListOfPCConfig()                    11u  /**< the number of accomplishable value elements in EcuM_WakeupSourceList */
#define EcuM_GetWakeupSourceListOfPCConfig()                          EcuM_WakeupSourceList  /**< the pointer to EcuM_WakeupSourceList */
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCGetDataMacros  EcuM Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define EcuM_GetCoreStatus(Index)                                     (EcuM_GetCoreStatusOfPCConfig()[(Index)])
#define EcuM_GetFunctionOfDriverInitOne(Index)                        (EcuM_GetDriverInitOneOfPCConfig()[(Index)].FunctionOfDriverInitOne)
#define EcuM_GetModuleState()                                         ((*(EcuM_GetModuleStateOfPCConfig())))
#define EcuM_GetApplicationOfPartitionInit(Index)                     (EcuM_GetPartitionInitOfPCConfig()[(Index)].ApplicationOfPartitionInit)
#define EcuM_GetChannelOfWakeupSourceList(Index)                      (EcuM_GetWakeupSourceListOfPCConfig()[(Index)].ChannelOfWakeupSourceList)
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCGetDeduplicatedDataMacros  EcuM Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define EcuM_GetDefaultAppMode()                                      EcuM_GetDefaultAppModeOfPCConfig()
#define EcuM_GetDefaultShutdownMode()                                 EcuM_GetDefaultShutdownModeOfPCConfig()
#define EcuM_GetDefaultShutdownTarget()                               EcuM_GetDefaultShutdownTargetOfPCConfig()
#define EcuM_GetEcuM_CRCHash_Lower()                                  EcuM_GetEcuM_CRCHash_LowerOfPCConfig()
#define EcuM_GetEcuM_CRCHash_Upper()                                  EcuM_GetEcuM_CRCHash_UpperOfPCConfig()
#define EcuM_GetGeneratorCompatibilityVersion()                       EcuM_GetGeneratorCompatibilityVersionOfPCConfig()
#define EcuM_GetMaxWakeupSourceCount()                                EcuM_GetMaxWakeupSourceCountOfPCConfig()
#define EcuM_GetNormalMcuMode()                                       EcuM_GetNormalMcuModeOfPCConfig()
#define EcuM_IsEcuMPartitionOfPartitionInit(Index)                    (((TRUE)) != FALSE)  /**< Set to true for the partitions with active BswM */
#define EcuM_GetSizeOfCoreStatus()                                    EcuM_GetSizeOfCoreStatusOfPCConfig()
#define EcuM_GetSizeOfDriverInitOne()                                 EcuM_GetSizeOfDriverInitOneOfPCConfig()
#define EcuM_GetSizeOfPartitionInit()                                 EcuM_GetSizeOfPartitionInitOfPCConfig()
#define EcuM_GetSizeOfWakeupSourceList()                              EcuM_GetSizeOfWakeupSourceListOfPCConfig()
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCSetDataMacros  EcuM Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define EcuM_SetModuleState(Value)                                    (*(EcuM_GetModuleStateOfPCConfig())) = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCHasMacros  EcuM Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define EcuM_HasCoreStatus()                                          (TRUE != FALSE)
#define EcuM_HasDefaultAppMode()                                      (TRUE != FALSE)
#define EcuM_HasDefaultShutdownMode()                                 (TRUE != FALSE)
#define EcuM_HasDefaultShutdownTarget()                               (TRUE != FALSE)
#define EcuM_HasDriverInitOne()                                       (TRUE != FALSE)
#define EcuM_HasFunctionOfDriverInitOne()                             (TRUE != FALSE)
#define EcuM_HasEcuM_CRCHash_Lower()                                  (TRUE != FALSE)
#define EcuM_HasEcuM_CRCHash_Upper()                                  (TRUE != FALSE)
#define EcuM_HasGeneratorCompatibilityVersion()                       (TRUE != FALSE)
#define EcuM_HasMaxWakeupSourceCount()                                (TRUE != FALSE)
#define EcuM_HasModuleState()                                         (TRUE != FALSE)
#define EcuM_HasNormalMcuMode()                                       (TRUE != FALSE)
#define EcuM_HasPartitionInit()                                       (TRUE != FALSE)
#define EcuM_HasApplicationOfPartitionInit()                          (TRUE != FALSE)
#define EcuM_HasEcuMPartitionOfPartitionInit()                        (TRUE != FALSE)
#define EcuM_HasSizeOfCoreStatus()                                    (TRUE != FALSE)
#define EcuM_HasSizeOfDriverInitOne()                                 (TRUE != FALSE)
#define EcuM_HasSizeOfPartitionInit()                                 (TRUE != FALSE)
#define EcuM_HasSizeOfWakeupSourceList()                              (TRUE != FALSE)
#define EcuM_HasWakeupSourceList()                                    (TRUE != FALSE)
#define EcuM_HasChannelOfWakeupSourceList()                           (TRUE != FALSE)
#define EcuM_HasPCConfig()                                            (TRUE != FALSE)
#define EcuM_HasCoreStatusOfPCConfig()                                (TRUE != FALSE)
#define EcuM_HasDefaultAppModeOfPCConfig()                            (TRUE != FALSE)
#define EcuM_HasDefaultShutdownModeOfPCConfig()                       (TRUE != FALSE)
#define EcuM_HasDefaultShutdownTargetOfPCConfig()                     (TRUE != FALSE)
#define EcuM_HasDriverInitOneOfPCConfig()                             (TRUE != FALSE)
#define EcuM_HasEcuM_CRCHash_LowerOfPCConfig()                        (TRUE != FALSE)
#define EcuM_HasEcuM_CRCHash_UpperOfPCConfig()                        (TRUE != FALSE)
#define EcuM_HasGeneratorCompatibilityVersionOfPCConfig()             (TRUE != FALSE)
#define EcuM_HasMaxWakeupSourceCountOfPCConfig()                      (TRUE != FALSE)
#define EcuM_HasModuleStateOfPCConfig()                               (TRUE != FALSE)
#define EcuM_HasNormalMcuModeOfPCConfig()                             (TRUE != FALSE)
#define EcuM_HasPartitionInitOfPCConfig()                             (TRUE != FALSE)
#define EcuM_HasSizeOfCoreStatusOfPCConfig()                          (TRUE != FALSE)
#define EcuM_HasSizeOfDriverInitOneOfPCConfig()                       (TRUE != FALSE)
#define EcuM_HasSizeOfPartitionInitOfPCConfig()                       (TRUE != FALSE)
#define EcuM_HasSizeOfWakeupSourceListOfPCConfig()                    (TRUE != FALSE)
#define EcuM_HasWakeupSourceListOfPCConfig()                          (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCIncrementDataMacros  EcuM Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define EcuM_IncModuleState()                                         EcuM_GetModuleState()++
/** 
  \}
*/ 

/** 
  \defgroup  EcuMPCDecrementDataMacros  EcuM Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define EcuM_DecModuleState()                                         EcuM_GetModuleState()--
/** 
  \}
*/ 

  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/* Postbuild */
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 Macros_3453 */  /* MD_MSR_FctLikeMacro */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:Macros_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


# if (defined ECUM_PRIVATE_CFG_INCLUDE)
#  if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
typedef EcuM_GlobalConfigType EcuM_ConfigType;
#  else
typedef uint8 EcuM_ConfigType;
#  endif
# endif

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  EcuM_CoreStatus
**********************************************************************************************************************/
/** 
  \var    EcuM_CoreStatus
  \brief  Stores status of each core.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EcuM_CoreStatusArrayType, ECUM_CONST) EcuM_CoreStatus[6];
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_DriverInitOne
**********************************************************************************************************************/
/** 
  \var    EcuM_DriverInitOne
  \details
  Element     Description
  Function
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EcuM_DriverInitOneType, ECUM_CONST) EcuM_DriverInitOne[1];
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_PartitionInit
**********************************************************************************************************************/
/** 
  \var    EcuM_PartitionInit
  \brief  Contains all parameters configured for initialization of partitions.
  \details
  Element        Description
  Application    
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EcuM_PartitionInitType, ECUM_CONST) EcuM_PartitionInit[6];
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_WakeupSourceList
**********************************************************************************************************************/
/** 
  \var    EcuM_WakeupSourceList
  \brief  Contains all parameters configured for Wakeup Sources
  \details
  Element    Description
  Channel    Mapped ComM channel number - 255 if no ComM channel is assigned.
*/ 
#define ECUM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern CONST(EcuM_WakeupSourceListType, ECUM_CONST) EcuM_WakeupSourceList[11];
#define ECUM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  EcuM_ModuleState
**********************************************************************************************************************/
#define ECUM_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
extern VAR(EcuM_StateType, ECUM_VAR_NOINIT) EcuM_ModuleState;
#define ECUM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */



/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
 *  CALLOUT FUNCTIONS
 *********************************************************************************************************************/
 
# define ECUM_START_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# if (defined ECUM_PRIVATE_CFG_INCLUDE)

/***********************************************************************************************************************
 *  EcuM_AL_SetProgrammableInterrupts
 **********************************************************************************************************************/
/*! \brief       Enables programmable interrupts.
 *  \details     On ECUs with programmable interrupt priorities, these priorities must be set before the OS is started.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-375
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_SetProgrammableInterrupts(void);

/***********************************************************************************************************************
 *  EcuM_StartOS
 **********************************************************************************************************************/
/*! \brief       Starts the Os.
 *  \details     The Os is started in context of this callout. If some preparation is needed like starting cores,
 *               this can be done before.
 *  \param[in]   appMode          The application mode which shall be passed to the OS.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_StartOS(AppModeType appMode);

#if(ECUM_SLAVE_CORE_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  EcuM_WaitForSlaveCores
 **********************************************************************************************************************/
/*! \brief       Synchronization with slave cores.
 *  \details     Slave cores can be triggered in context of this callout to enter their sleep state.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_NUMBER_OF_CORES
 *  \trace       CREQ-473
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_WaitForSlaveCores(void);
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/***********************************************************************************************************************
 *  EcuM_GptStartClock
 **********************************************************************************************************************/
/*! \brief       Start the Gpt clock.
 *  \details     During initialization this callout is used to start the configured Gpt channel for the Alarm Clock.
 *  \param[in]   GptChannel   The configured Gpt channel which serves as time base for alarm clock 
 *  \param[in]   Mode         The Gpt normal mode
 *  \param[in]   Value        The value to start the Gpt timer for second based notification / wake up 
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_GptStartClock(Gpt_ChannelType GptChannel, Gpt_ModeType Mode, Gpt_ValueType Value);

/***********************************************************************************************************************
 *  EcuM_GptSetNormal
 **********************************************************************************************************************/
/*! \brief       Sets the Gpt to normal mode.
 *  \details     When regaining from sleep, this callout is used to switch the Gpt mode back to normal mode.
 *  \param[in]   GptChannel   The configured Gpt channel which serves as time base for alarm clock 
 *  \param[in]   Mode         The Gpt normal mode
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_GptSetNormal(Gpt_ChannelType GptChannel, Gpt_ModeType Mode);

/***********************************************************************************************************************
 *  EcuM_GptSetSleep
 **********************************************************************************************************************/
/*! \brief       Sets the Gpt to sleep mode.
 *  \details     When entering a sleep phase, this callout is used to switch the Gpt mode to sleep mode.
 *  \param[in]   GptChannel   The configured Gpt channel which serves as time base for alarm clock 
 *  \param[in]   Mode         The Gpt sleep mode
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_GptSetSleep(Gpt_ChannelType GptChannel, Gpt_ModeType Mode);
#endif

/***********************************************************************************************************************
 *  EcuM_CheckRamHash
 **********************************************************************************************************************/
/*! \brief       Checks the RAM hash.
 *  \details     This callout can be used to check the RAM hash after the ECU has regained from a low power mode.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-440
 **********************************************************************************************************************/
FUNC(uint8, ECUM_CODE) EcuM_CheckRamHash(void);

/***********************************************************************************************************************
 *  EcuM_McuSetMode
 **********************************************************************************************************************/
/*! \brief       Sets the Mcu mode.
 *  \details     The Mcu mode for a reduced power mode, a sleep mode or to restore the normal mcu mode can be performed
 *               in this callout. If some preparation is needed like enabling or disabling of interrupts, this can also
 *               be done inside this callout.
 *  \param[in]   McuMode            The ID of the Mcu mode which shall be set.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_McuSetMode(Mcu_ModeType McuMode);

/***********************************************************************************************************************
 *  EcuM_SleepActivity
 **********************************************************************************************************************/
/*! \brief       Activities in a reduced power mode.
 *  \details     Can be used to poll for occurred wakeup events and to control the frequency for the polling.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-486
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_SleepActivity(void);

/***********************************************************************************************************************
 *  EcuM_GenerateRamHash
 **********************************************************************************************************************/
/*! \brief       Generates a RAM hash.
 *  \details     This callout can be used to generate a RAM hash prior the ECU is switched to a low power mode.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-381
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_GenerateRamHash(void);

/***********************************************************************************************************************
 *  EcuM_ShutdownOS
 **********************************************************************************************************************/
/*! \brief       Shut down the Os.
 *  \details     This callout can be used to shut down the Os. If it is necessary e.g. for safety projects to perform
 *               this in a different context, the context switch can be initiated from here.
 *  \param[in]   ErrCode            Error code which is passed to the ShutdownOS call.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_ShutdownOS(Std_ReturnType ErrCode);

/***********************************************************************************************************************
 *  EcuM_AL_SwitchOff
 **********************************************************************************************************************/
/*! \brief       Switches off the ECU.
 *  \details     This callout implements the shutdown of the power supply of the ECU.
 *  \context     SHUTHOOK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-519
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_SwitchOff(void);

/***********************************************************************************************************************
 *  EcuM_AL_Reset
 **********************************************************************************************************************/
/*! \brief       Reset the ECU.
 *  \details     This callout implements the code for resetting the ECU.
 *  \param[in]   Reset            The ID of the current reset mode.
 *  \context     SHUTHOOK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-391
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_AL_Reset(EcuM_ResetType Reset);

#  if((ECUM_CONFIGURATION_VARIANT == ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE) || (ECUM_POSTBUILD_VARIANT_SUPPORT == STD_ON))
/***********************************************************************************************************************
 *  EcuM_DeterminePbConfiguration
 **********************************************************************************************************************/
/*! \brief       Determines configuration data.
 *  \details     This callout evaluates some condition, like port pin or NVRAM value, to determine which post-build
 *               configuration shall be used in the remainder of the startup process.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE | ECUM_POSTBUILD_VARIANT_SUPPORT
 *  \trace       CREQ-488
 **********************************************************************************************************************/
FUNC(EcuM_GlobalConfigRefType, ECUM_CODE) EcuM_DeterminePbConfiguration(void);
#  endif

/***********************************************************************************************************************
 *  EcuM_ErrorHook
 **********************************************************************************************************************/
/*! \brief       Handling of runtime errors
 *  \details     Provides the possibility to react on errors which occurs during the runtime of the ECU.
 *  \param[in]   reason                  The reason for the currently occurred error.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-431
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_ErrorHook(Std_ReturnType reason);

/***********************************************************************************************************************
 *  EcuM_EnableWakeupSources
 **********************************************************************************************************************/
/*! \brief       Enable wakeup sources.
 *  \details     Enable wakeup interrupts for the specific sources which should be active for the upcoming sleep phase.
 *  \param[in]   wakeupSource                  The wakeup source to start, passed as a bitmask.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-415
 *  \note        Can be called with ECUM_WKSOURCE_NONE as wakeupSource.
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources(EcuM_WakeupSourceType wakeupSource);

/***********************************************************************************************************************
 *  EcuM_DisableWakeupSources
 **********************************************************************************************************************/
/*! \brief       Disable wakeup sources.
 *  \details     Disable wakeup interrupts for the specific sources which were active in the past sleep phase.
 *  \param[in]   wakeupSource                  The wakeup source to start, passed as a bitmask.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-423
 *  \note        Can be called with ECUM_WKSOURCE_NONE as wakeupSource.
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources(EcuM_WakeupSourceType wakeupSource);

/***********************************************************************************************************************
 *  EcuM_StartWakeupSources
 **********************************************************************************************************************/
/*! \brief       Start wakeup sources.
 *  \details     After a wakeup interrupt has occurred which has lead to a start of the wakeup validation, with this
 *               callout the respective wakeup source can be set to the state to detect if this was a valid wakeup
 *               event.
 *  \param[in]   wakeupSource                  The wakeup source to start, passed as a bitmask.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-376
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_StartWakeupSources(EcuM_WakeupSourceType wakeupSource);

/***********************************************************************************************************************
 *  EcuM_StopWakeupSources
 **********************************************************************************************************************/
/*! \brief       Stop wakeup sources.
 *  \details     After a wakeup validation has elapsed and was not successful, with this callout the wakeup source can
 *               be set back to a wakeup capable state again.
 *  \param[in]   wakeupSource                  The wakeup source to start, passed as a bitmask.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-539
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_StopWakeupSources(EcuM_WakeupSourceType wakeupSource);

/***********************************************************************************************************************
 *  EcuM_CheckValidation
 **********************************************************************************************************************/
/*! \brief       Check validation of a wakeup source.
 *  \details     Periodically poll a wakeup source which is currently in wakeup validation if the occurred wakeup was a
 *               valid one.
 *  \param[in]   wakeupSource                  The wakeup source to start, passed as a bitmask.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-430
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_CheckValidation(EcuM_WakeupSourceType wakeupSource);

/***********************************************************************************************************************
 *  EcuM_OnGoOffOne
 **********************************************************************************************************************/
/*! \brief       Go Off One callout
 *  \details     This callout can be used to perform user specific code in the Go Off I state of the EcuM which is
 *               executed in context of EcuM_GoDown() prior the BswM and the SchM are de-initialized.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-441, CREQ-666
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnGoOffOne(void);

/***********************************************************************************************************************
 *  EcuM_OnGoOffTwo
 **********************************************************************************************************************/
/*! \brief       Go Off Two callout
 *  \details     This callout can be used to perform user specific code in the Go Off II state of the EcuM which is
 *               executed at the beginning of EcuM_Shutdown().
 *  \context     SHUTHOOK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-419, CREQ-667
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnGoOffTwo(void);


#  if(ECUM_FIXED_BEHAVIOR == STD_ON)

/***********************************************************************************************************************
 *  EcuM_OnEnterRun
 **********************************************************************************************************************/
/*! \brief       Call on enter the Run state.
 *  \details     This callout allows the system designer to notify that the run state is about to be entered.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-661
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnEnterRun(void);

/***********************************************************************************************************************
 *  EcuM_OnExitRun
 **********************************************************************************************************************/
/*! \brief       Call on exit the Run state.
 *  \details     This callout allows the system designer to notify that the run state is about to be leaved.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-660
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnExitRun(void);

/***********************************************************************************************************************
 *  EcuM_OnGoSleep
 **********************************************************************************************************************/
/*! \brief       Call on enter the sleep state.
 *  \details     This callout allows the system designer to notify that the go sleep state is about to be entered.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-665
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnGoSleep(void);

/***********************************************************************************************************************
 *  EcuM_OnPrepShutdown
 **********************************************************************************************************************/
/*! \brief       Call on enter the prepare shutdown state.
 *  \details     This callout allows the system designer to notify that the prepare shutdown state is about to be entered.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-664
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnPrepShutdown(void);

/***********************************************************************************************************************
 *  EcuM_OnExitPostRun
 **********************************************************************************************************************/
/*! \brief       Call on exit the Post Run state.
 *  \details     This callout allows the system designer to notify that the post run state is about to be leaved.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-663
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnExitPostRun(void);

/***********************************************************************************************************************
 *  EcuM_OnFailedNvmWriteAllJobReaction
 **********************************************************************************************************************/
/*! \brief       Call on a failed NvM WriteAll Job.
 *  \details     This callout allows the system designer to notify that the NvM WriteAll was not successful.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnFailedNvmWriteAllJobReaction(void);

/***********************************************************************************************************************
 *  EcuM_OnWakeupReaction
 **********************************************************************************************************************/
/*! \brief       Call on enter the wakeup reaction state.
 *  \details     This callout allows the system designer to notify that the wakeup reaction state is about to be entered.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-702
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnWakeupReaction(void);

/***********************************************************************************************************************
 *  EcuM_OnRTEStartup
 **********************************************************************************************************************/
/*! \brief       Call prior Rte is started.
 *  \details     This callout prepares the RTE for the upcoming Rte start call.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-662
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_OnRTEStartup(void);

#  endif
# endif

/***********************************************************************************************************************
 *  EcuM_AL_DriverInitZero
 **********************************************************************************************************************/
/*! \fn          EcuM_AL_DriverInitZero
 *  \brief       Driver Initialization Zero.
 *  \details     Provides driver initialization and other hardware-related startup activities for loading the
 *               post-build configuration data.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-505
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  EcuM_AL_DriverInitOne
 **********************************************************************************************************************/
/*! \fn          EcuM_AL_DriverInitOne
 *  \brief       Driver Initialization One.
 *  \details     Provides driver initialization and other hardware-related startup activities prior the start of the OS.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-525
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  EcuM_AL_DriverRestart
 **********************************************************************************************************************/
/*! \fn          EcuM_AL_DriverRestart
 *  \brief       Re-Initialize Drivers.
 *  \details     Provides driver re-initialization after regaining from a low power mode.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-509
 **********************************************************************************************************************/
/* PRQA S 0779 FUNCTIONDECLARATIONS */ /* MD_EcuM_0779 */

/**********************************************************************************************************************
  
**********************************************************************************************************************/
extern FUNC(void, ECUM_CODE) EcuM_AL_DriverInitZero(void) ;
extern FUNC(void, ECUM_CODE) EcuM_AL_DriverInitOne(void) ;
#if (ECUM_SLEEPMODELIST == STD_ON)
extern FUNC(void, ECUM_CODE) EcuM_AL_DriverRestartList(void) ;
#endif
/* PRQA L:FUNCTIONDECLARATIONS */


# define ECUM_STOP_SEC_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* ECUM_PRIVATECFG_H */
/**********************************************************************************************************************
 *  END OF FILE: ECUM_PRIVATECFG.H
 *********************************************************************************************************************/


