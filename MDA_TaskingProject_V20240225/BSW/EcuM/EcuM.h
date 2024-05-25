/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                           All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  EcuM.h
 *    Component:  SysService_Asr4EcuM
 *       Module:  EcuM
 *    Generator:  -
 *
 *  Description:  This EcuM.h provides the API functionality provided by the ASR4 EcuM Flexible
 *  
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Jochen Vorreiter              visvjn        Vector Informatik GmbH
 *  Philipp Ritter                visrpp        Vector Informatik GmbH
 *  Samridhi Langer               vislsi        Vector Informatik GmbH
 *  Patrick Kleemann              vispkn        Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  1.00.00   2012-03-12  visvjn  ESCAN00056774 Creation
 *  1.00.01   2013-01-22  visvjn  ESCAN00063386 Fixed inconsistent compiler abstraction, changed all functions to ECUM_CODE
 *                                ESCAN00064041 Fixed issue about ignored wakeup events caused by a timer overflow
 *                                ESCAN00064157 Fixed wrong array access on buffered wakeup events for ComM channels
 *  1.01.00   2013-03-21  visvjn  ESCAN00066628 Added support of asynchronous transceiver handling
 *                                ESCAN00064313 Added support for Post-Build loadable
 *                                ESCAN00065610 Notification of the BswM in case EcuM_ClearWakeupEvent is called
 *                                ESCAN00066141 Introduced API EcuM_ClearValidatedWakeupEvent
 *                                ESCAN00066360 Removed call of SetWakeupEvent inside Init to avoid exceptions in OS
 *                                ESCAN00066610 Configurable BswM notification about disabled wakeup sources
 *                                ESCAN00066611 Moved all includes out of EcuM_PrivateCfg.h to EcuM.c
 *                                ESCAN00064329 Introduced CRC check of Post-Build parameters
 *                                ESCAN00067125 Fixed wrong wake-up notification for a failed validation
 *                                ESCAN00067413 Corrected wrong service ID in Det notification in EcuM_ClearWakeupEvent
 *  2.00.00   2013-09-27  visvjn  ESCAN00068953 Added optimization for not configured polling wakeup sources
 *                                ESCAN00068958 Added optimization for not configured asynchronous wakeup sources
 *                                ESCAN00067822 Changed order of GlobalSuspend in EnterSleep to prevent missing wakeups
 *                                ESCAN00068869 Added check of parameter SleepMode in EcuM_SelectShutdownTarget
 *                                ESCAN00068895 LastShutdownTarget and LastShutdownMode are stored prior a sleep phase
 *                                ESCAN00068952 Changed Order of EcuM_EnableWakeupSources and BswM notification in sleep
 *                                ESCAN00068972 Changed start value of buffered ComM notifications to skip standard sources
 *                                ESCAN00068971 Changed start value of wakeup validation to skip standard sources
 *                                ESCAN00070292 Added support for MultiCore ECUs
 *                                ESCAN00070591 Removed BswM_EcuM_CurrentState() calls
 *                                ESCAN00069976 Changed handling of BswM_EcuM_CurrentWakeup
 *                                ESCAN00070756 Changed access on generated variables caused by ComStackLib
 *                                ESCAN00069008 Added support for AlarmClock handling
 *                                ESCAN00070759 Added API EcuM_GoToSelectedShutdownTarget()
 *                                ESCAN00070760 Removed inclusion of Dem.h and Det.h because is included in PrivateCfg.h
 *                                ESCAN00071113 Added HIS justifications
 *                                ESCAN00071141 Corrected change for valid range of wakeup source parameter in some APIs
 *                                ESCAN00071239 DET Error is thrown if GoDown / GoPoll is called without configured sleepmode
 *                                ESCAN00071310 Changed handling of EcuM_WakeupStateType and notification to BswM_EcuM_CurrentWakeup
 *  2.00.01   2013-12-10  visvjn  ESCAN00072526 Allow early invoking of EcuM APIs already during runtime of EcuM_StartupTwo
 *                                ESCAN00072546 Prevent BswM notification in case of pending wakeup during initialization
 *                                ESCAN00072548 Check if BswM is already initialized before notify VALIDATED
 *                                ESCAN00071568 Fixed Immediate Wake up Validation in ECUM_STATE_RUN
 *  2.01.00   2014-02-05  visvjn  ESCAN00073455 Call EcuM_StopWakeupSources for cleared wakeup sources
 *                                ESCAN00073714 Avoid compiler warning because of unreferenced loopCount variable in EcuM_Init
 *                                ESCAN00073820 Improved access on buffered wakeup during startup
 *                                ESCAN00074007 Fixed not working optimization for asynchronous wakeup validation
 *  3.00.00   2014-02-21  visvjn  ESCAN00070565 Support of PostBuild Selectable
 *                                ESCAN00074320 Support ASR3 EcuM behavior
 *                                ESCAN00074381 Support of Run Request Protocol and fixed state machine
 *                                ESCAN00074005 Optimization of wakeup source status variables
 *                                ESCAN00073258 Support gaps in WakeupSources
 *                                ESCAN00074008 Removed critical area in EcuM_EnterSleep
 *                                ESCAN00075998 Changed handling of SleepModes IDs, now starting with 0
 *                                ESCAN00075999 Early initialization of EcuM_GlobalConfigRoot_Ptr
 *                                ESCAN00076018 Fixed wrong enabled wakeup source in EcuM_EnterSleep
 *  3.00.01   2014-06-25  visrpp  ESCAN00076423 Compiler error: undeclared identifier EcuMConf_EcuMResetMode_ECUM_RESET_WAKEUP
 *                                ESCAN00076424 Optimization of EcuM_GetShutdownTarget and EcuM_GetLastShutdownTarget
 *  4.00.00   2014-10-02  visvjn  ESCAN00077179 Call DriverInitLists on slave cores
 *                                ESCAN00078231 Corrected reported SID in EcuM_SelectBootTarget()
 *                                ESCAN00078345 Support empty CommunicationAllowed list in case of fixed EcuM
 *                                ESCAN00078739 Corrected wrong RTE Mode defines
 *                                ESCAN00078740 Corrected API Rte_SwitchAck_EcuM_currentMode_currentMode()
 *                                ESCAN00078741 Adated access on PB Pointers in EcuM_Init()
 *                                ESCAN00078662 Fixed undefined variable loopcount in some configurations
 *                                ESCAN00078609 Fixed wrong parenthesis in EcuM_MainFunction()
 *                                ESCAN00078742 Introduced some smaller internal functions to reduce cyclomatic complexity
 *                                ESCAN00079279 Removed multiple return paths of some internal functions
 *                                ESCAN00079118 Changed access on initFunctions via ComstackLib
 *                                ESCAN00079040 Corrected encapsulation of Defensive Behavior in EcuM_GoDown
 *                                ESCAN00079117 Corrected break condition in Wakeup Validation
 *                                ESCAN00077330 Removed critical sections around the invocations of 
 *                                              EcuM_StarWakeupSources and EcuM_StopWakeupSources
 *                                ESCAN00079128 Avoided Misra warning and justified HIS warnings
 *                                ESCAN00079277 Extended support for PostBuild Selectable
 *                                ESCAN00079390 Added API EcuM_GetStateWrapper
 *  4.00.01   2014-11-13  visvjn  ESCAN00079472 Avoided access on EcuM_GoHalt and EcuM_GoPoll in case of fixed behavior
 *                                ESCAN00079571 Avoided compiler warning caused by missing switch ECUM_GODOWNALLOWEDOFFLEXUSER
 *                                ESCAN00079577 Added missing typecasts to avoid compiler warnings
 *                                ESCAN00079625 Fixed wrong call to EcuM_StopWakeupSources in case of cleared pending wakeups
 *                                ESCAN00079631 Removed critical section around invocation of EcuM_StopWakeupSources
 *                                              with cleared pending wakeups
 *                                ESCAN00079632 Changed critical section around read-modify-write access on 
 *                                              EcuM_BswM_BufferedWakeups
 *                                ESCAN00079709 Fixed wrong determination of active variant in case of MultiCore
 *  4.01.00   2015-01-21  visvjn  ESCAN00080699 Changed return value type of EcuM_QryComMRunRequest to boolean
 *                                ESCAN00080694 Fixed wrong preprocessor encapsulation of EcuM_InternalDeterminePbConfiguration()
 *                                ESCAN00080695 Fixed missing initialization of the ShutdownCause
 *                                ESCAN00080696 Fixed missing initialization of the BootTarget
 *                                ESCAN00080698 Adapted DET check in EcuM_StartCheckWakeup and EcuM_StopCheckWakeup
 *                                ESCAN00080801 Added additional global config pointer for variant modules
 *                                ESCAN00080899 Changed access on ComM Channels in case of EcuM Fixed
 *  4.02.00   2015-02-18  visvjn  ESCAN00081242 Fixed wrong interrupt handling in EcuM_EnterSleepOnSlave
 *                                ESCAN00081140 Changed memory mapping for VAR_NOCACHE_NOINIT_32BIT
 *                                ESCAN00081729 Added void-cast to GetResource() / ReleaseResource() to avoid MISRA violation
 *  5.00.00   2015-04-20  visvjn  ESCAN00080281 SafeBSW Step1
 *                                ESCAN00081769 SafeBSW Step2
 *                                ESCAN00082621 Implemented Mode Handling Feature
 *                                ESCAN00083920 Fixed not working gaps in wakeup source id
 *                                ESCAN00083916 Changed handling of disabled wakeup sources in case of wakeup validation
 *                                ESCAN00083177 Fixed wrong Typecast for expired wakeups
 *                                ESCAN00083293 Fixed wrong Typecast for pending wakeups
 *                                ESCAN00083913 Allowed deferred notification about asynchronous checkwakeup events.
 *                                ESCAN00083917 Made some wakeup source accessing APIs callable from ECUM_STATE_STARTUP_ONE
 *                                ESCAN00083924 Added check for user range in EcuM_SetClock
 *                                ESCAN00084142 Avoid inconsistent wakeup source state after wakeup from sleep
 *                                ESCAN00084146 Changed internal API EcuM_UpdateMasterAlarm
 *                                ESCAN00079635 Use of COMBINED_WAKEUPS MACRO in halt and polling sleep mode
 *  6.00.00   2015-09-02  visvjn  ESCAN00086779 SafeBSW for EcuM Fixed
 *                                ESCAN00086776 Added DET check for polling sleep modes.
 *                                ESCAN00086772 Fixed not working DET check in case of PB-L and EcuM NULL_PTR
 *                                ESCAN00085553 Prevent duplicated notifications about changing wakeup source states
 *                                ESCAN00087214 Fixed not locked interrupts in EcuM Fixed in transition from Run to PostRun
 *  7.00.00   2016-02-23  visvjn  ESCAN00087438 Fixed duplicated BswM wakeup notification about asynchronous check wakeups
 *                                ESCAN00088744 Fixed wrong ComStackLib access in AbortWakeupAlarm API
 *  8.00.00   2016-09-29  visvjn  FEATC-319     Support PNC references for WakeupSources
 *                                ESCAN00091357 Changed data type of Mcu Reset Reason in EcuM_Init
 *  8.00.01   2017-02-28  visvjn  ESCAN00092747 Mode Switch event in the wrong context leads to unexpected behavior
 *  8.00.02   2017-04-10  visvjn  ESCAN00092567 Support UseCase without communication stack (prevent include of ComM.h)
 *                                ESCAN00094629 EcuM causes a Det error during initialization (ECUM_E_NULL_POINTER)
 *  9.00.00   2018-06-18  visvjn  STORYC-2829   Support startup/shutdown of more than one partitions
 *            2018-06-18  visvjn  STORYC-3559   Support ECU wakeup for Non communication channel wakeup sources
 *  9.01.00   2018-07-25  visvjn  ESCAN00100168 BswM Wakeup notification is not called and so some BswM actions might not be executed
 *            2018-07-25  visvjn  STORYC-5965   Support startup/shutdown of more than one partitions finalization 
 *  9.02.00   2018-08-08  visvjn  ESCAN00100336 Polling Sleepmodes are not executed
 *            2018-08-10  visvjn  ESCAN00100360 Wrong compiler abstraction used in internal EcuM API
 * 10.00.00   2018-10-11  vislsi  STORYC-6134   MISRA-C:2012 Compliance
 *            2018-12-07  vispkn  ESCAN00094298 The Ecu does not startup properly in some MultiCore configurations
 *                                ESCAN00098617 Shutdown / Reset of a multicore ECU is not performed as expected
 *********************************************************************************************************************/

/* ---- Protection against multiple inclusion ----------------------------- */
#ifndef ECUM_H
# define ECUM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

# include "EcuM_Cbk.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define SYSSERVICE_ASR4ECUM_VERSION                                  0x1000u
# define SYSSERVICE_ASR4ECUM_RELEASE_VERSION                          0x00u

/* vendor and module identification */
# define ECUM_VENDOR_ID                                               (30u)   /* Vector Informatik GmbH */
# define ECUM_MODULE_ID                                               (10u)
# define ECUM_INSTANCE_ID                                             (0u)
 
/* AUTOSAR Software Specification Version Information */
# define ECUM_AR_RELEASE_MAJOR_VERSION                                (4u)
# define ECUM_AR_RELEASE_MINOR_VERSION                                (0u)
# define ECUM_AR_RELEASE_REVISION_VERSION                             (3u)

/* Component Version Information */
# define ECUM_SW_MAJOR_VERSION                                        (SYSSERVICE_ASR4ECUM_VERSION >> 8)
# define ECUM_SW_MINOR_VERSION                                        (SYSSERVICE_ASR4ECUM_VERSION & 0x00FFu)
# define ECUM_SW_PATCH_VERSION                                        (SYSSERVICE_ASR4ECUM_RELEASE_VERSION)

/* ----------Function Macros for compatibility to ASR4 -------------------- */

/* This two APIs are not supported in ASR4R5 */
# define EcuM_GetMostRecentShutdown(TARGET, MODE, CAUSE, TIME)
# define EcuM_GetNextRecentShutdown(TARGET, MODE, CAUSE, TIME)

/* ----------Error Codes in Development-Mode------------------------------- */
# define ECUM_E_UNINIT                                                (0x10u)
# define ECUM_E_SERVICE_DISABLED                                      (0x11u)
# define ECUM_E_NULL_POINTER                                          (0x12u)
# define ECUM_E_INVALID_PAR                                           (0x13u)
# define ECUM_E_MULTIPLE_RUN_REQUESTS                                 (0x14u)
# define ECUM_E_MISMATCHED_RUN_RELEASE                                (0x15u)
# define ECUM_E_STATE_PAR_OUT_OF_RANGE                                (0x16u)
# define ECUM_E_UNKNOWN_WAKEUP_SOURCE                                 (0x17u)
# define ECUM_E_INVALID_GEN_DATA                                      (0x18u)

/* Vector extensions to the standard error codes  SWS -------------------------------*/
# define ECUM_E_NO_ERROR                                              (0x00u)
# define ECUM_E_MODULE_NOT_IN_STARTUP                                 (0x20u)
# define ECUM_E_MODULE_NOT_IN_PREPSHUTDOWN                            (0x21u)
# define ECUM_E_MODULE_NOT_IN_RUN_STATE                               (0x22u)
# define ECUM_E_NO_SLEEPMODE_CONFIGURED                               (0x23u)
# define ECUM_E_INVALID_STATEREQUEST                                  (0x24u)

#if defined (E_NOT_SUPPORTED) /* COV_ECUM_ERRORS */
#else
# define E_NOT_SUPPORTED                                              (Std_ReturnType)(0x02u)
#endif
#if defined (E_EARLIER_ACTIVE) /* COV_ECUM_ERRORS */
#else
# define E_EARLIER_ACTIVE                                             (Std_ReturnType)(0x03u)
#endif
#if defined (E_PAST) /* COV_ECUM_ERRORS */
#else
# define E_PAST                                                       (Std_ReturnType)(0x04u)
#endif
#if defined (E_NOT_ACTIVE) /* COV_ECUM_ERRORS */
#else
# define E_NOT_ACTIVE                                                 (Std_ReturnType)(0x05u)
#endif
#if defined (E_NOT_ALLOWED) /* COV_ECUM_ERRORS */
#else
# define E_NOT_ALLOWED                                                (Std_ReturnType)(0x06u)
#endif
#if defined (ECUM_E_HOOK_RAM_CHECK_FAILED) /* COV_ECUM_ERRORS */
#else
# define ECUM_E_HOOK_RAM_CHECK_FAILED                                 (Std_ReturnType)(0x07u)
#endif
#if defined (ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT) /* COV_ECUM_ERRORS */
#else
# define ECUM_E_HOOK_CONFIGURATION_DATA_INCONSISTENT                  (Std_ReturnType)(0x08u)
#endif
#if defined (ECUM_E_HOOK_WRONG_ECUM_USAGE) /* COV_ECUM_ERRORS */
#else
# define ECUM_E_HOOK_WRONG_ECUM_USAGE                                 (Std_ReturnType)(0x09u)
#endif
#if defined (ECUM_E_HOOK_INVALID_COREID) /* COV_ECUM_ERRORS */
#else
# define ECUM_E_HOOK_INVALID_COREID                                   (Std_ReturnType)(0x0Au)
#endif
#if defined (ECUM_E_HOOK_INVALID_APPLICATIONID) /* COV_ECUM_ERRORS */
#else
# define ECUM_E_HOOK_INVALID_APPLICATIONID                            (Std_ReturnType)(0x0Bu)
#endif

/* ----------EcuM Service Identification----------------------------------- */
# define ECUM_SID_GET_VERSION_INFO                                    (0x00u)
# define ECUM_SID_INIT                                                (0x01u)
# define ECUM_SID_SHUTDOWN                                            (0x02u)
# define ECUM_SID_REQUEST_RUN                                         (0x03u)
# define ECUM_SID_RELEASE_RUN                                         (0x04u)
# define ECUM_SID_KILL_ALL_RUN_REQUESTS                               (0x05u)
# define ECUM_SID_SELECT_SHUTDOWN_TARGET                              (0x06u)
# define ECUM_SID_GET_STATE                                           (0x07u)
# define ECUM_SID_GET_LAST_SHUTDOWN_TARGET                            (0x08u)
# define ECUM_SID_GET_SHUTDOWN_TARGET                                 (0x09u)
# define ECUM_SID_REQUEST_POST_RUN                                    (0x0au)
# define ECUM_SID_RELEASE_POST_RUN                                    (0x0bu)
# define ECUM_SID_SET_WAKEUP_EVENT                                    (0x0Cu)
# define ECUM_SID_GET_PENDING_WAKEUP_EVENTS                           (0x0Du)
# define ECUM_SID_SELECT_BOOT_TARGET                                  (0x12u)
# define ECUM_SID_GET_BOOT_TARGET                                     (0x13u)
# define ECUM_SID_VALIDATE_WAKEUP_EVENT                               (0x14u)
# define ECUM_SID_GET_VALIDATED_WAKEUP_EVENTS                         (0x15u)
# define ECUM_SID_CLEAR_WAKEUP_EVENT                                  (0x16u)
# define ECUM_SID_MAIN_FUNCTION                                       (0x18u)
# define ECUM_SID_GET_EXPIRED_WAKEUP_EVENTS                           (0x19u)
# define ECUM_SID_STARTUP_TWO                                         (0x1Au)
# define ECUM_SID_SELECT_SHUTDOWN_CAUSE                               (0x1Bu)
# define ECUM_SID_GET_SHUTDOWN_CAUSE                                  (0x1Cu)
# define ECUM_SID_GET_MOST_RECENT_SHUTDOWN                            (0x1Du)
# define ECUM_SID_GET_NEXT_RECENT_SHUTDOWN                            (0x1Eu)
# define ECUM_SID_GO_DOWN                                             (0x1Fu)
# define ECUM_SID_GO_HALT                                             (0x20u)
# define ECUM_SID_GO_POLL                                             (0x21u)
# define ECUM_SID_SET_REL_WAKEUP_ALARM                                (0x22u)
# define ECUM_SID_SET_ABS_WAKEUP_ALARM                                (0x23u)
# define ECUM_SID_ABORT_WAKEUP_ALARM                                  (0x24u)
# define ECUM_SID_GET_CURRENT_TIME                                    (0x25u)
# define ECUM_SID_GET_WAKEUP_TIME                                     (0x26u)
# define ECUM_SID_SET_CLOCK                                           (0x27u)
# define ECUM_SID_START_CHECK_WAKEUP                                  (0x28u)
# define ECUM_SID_END_CHECK_WAKEUP                                    (0x29u)
# define ECUM_SID_KILL_ALL_POST_RUN_REQUESTS                          (0x2Au)
# define ECUM_SID_SET_STATE                                           (0x2Bu)
# define ECUM_SID_CLEAR_VALIDATED_WAKEUP_EVENT                        (0x30u)
# define ECUM_SID_CB_NFY_NVM_JOB_END                                  (0x65u)



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define ECUM_START_SEC_CODE
# include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  EcuM_Init
 **********************************************************************************************************************/
/*! \brief       Initializes the EcuM.
 *  \details     Initiate the startup procedure that takes place before the OS is started.
 *               In context of this function the driver init list zero and one are called, the global configuration is
 *               determined and finally the OS is started.
 *  \pre         Interrupts are disabled.
 *  \context     TASK|ISR
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-470
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Init(void);

/***********************************************************************************************************************
 *  EcuM_Shutdown
 **********************************************************************************************************************/
/*! \brief       Shutdown the ECU.
 *  \details     Typically called from the shutdown hook, this function takes over execution control and will carry
 *               out GO OFF II activities.
 *  \pre         EcuM must be in state ECUM_STATE_GO_OFF_ONE.
 *  \context     SHUTHOOK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-421
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Shutdown(void);

/***********************************************************************************************************************
 *  EcuM_SelectShutdownTarget
 **********************************************************************************************************************/
/*! \brief       Select a shutdown target.
 *  \details     Application may change the EcuM shutdown target for the next shutdown via this API.
 *  \param[in]   targetState        Target state.
 *  \param[in]   resetSleepMode     Target sleep mode if target state is ECUM_STATE_SLEEP or target reset mode if the
 *                                  target state is ECUM_STATE_RESET.
 *  \pre         -
 *  \return      E_NOT_OK - error
 *  \return      E_OK     - success
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-445
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownTarget(VAR(EcuM_StateType, AUTOMATIC) targetState,
                                                              VAR(EcuM_ModeType, AUTOMATIC) resetSleepMode);

/***********************************************************************************************************************
 *  EcuM_GetShutdownTarget
 **********************************************************************************************************************/
/*! \brief       Get the shutdown target.
 *  \details     Application or BSW may get the current EcuM shutdown target for the next shutdown via this API.
 *  \param[out]  target          Current shutdown target.
 *  \param[out]  resetSleepMode  Current sleep mode.
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-483
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownTarget
(
    P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) target,
    P2VAR(EcuM_ModeType, AUTOMATIC, ECUM_APPL_DATA)          resetSleepMode
);

/***********************************************************************************************************************
 *  EcuM_GetLastShutdownTarget
 **********************************************************************************************************************/
/*! \brief       Get the last shutdown target.
 *  \details     Returns not the current shutdown target but the shutdown target set before the last reset.
 *  \param[out]  target          Current shutdown target.
 *  \param[out]  resetSleepMode  Current sleep mode.
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-522
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetLastShutdownTarget(P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) target,
                                                               P2VAR(EcuM_ModeType, AUTOMATIC, ECUM_APPL_DATA) resetSleepMode);

/***********************************************************************************************************************
 *  EcuM_SelectShutdownCause
 **********************************************************************************************************************/
/*! \brief       Selects a new shutdown cause.
 *  \details     Selects a new Shutdown cause for an intended shutdown
 *  \param[in]   shutdownCause           Current shutdown cause.
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-531
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectShutdownCause(VAR(EcuM_ShutdownCauseType, AUTOMATIC) shutdownCause);

/***********************************************************************************************************************
 *  EcuM_GetShutdownCause
 **********************************************************************************************************************/
/*! \brief       Get the current shutdown cause.
 *  \details     Returns the currently selected shutdown cause for an intended shutdown.
 *  \param[out]  shutdownCause           Current shutdown cause.
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-438
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetShutdownCause(P2VAR(EcuM_ShutdownCauseType, AUTOMATIC, ECUM_APPL_DATA) shutdownCause);

/***********************************************************************************************************************
 *  EcuM_ClearWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Clear wakeup events.
 *  \details     Clears all pending, validated, checkWakeup and expired wakeup events.
 *  \param[in]   WakeupSource     Wakeup event(s) which have to be cleared.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-515
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_ClearWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

/***********************************************************************************************************************
 *  EcuM_ClearValidatedWakeupEvent
 **********************************************************************************************************************/
/*! \brief       Clear validated wakeup events.
 *  \details     Clears all passed sources from the validated wakeup events.
 *  \param[in]   WakeupSource     Wakeup event(s) which have to be cleared.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-515
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_ClearValidatedWakeupEvent(VAR(EcuM_WakeupSourceType, AUTOMATIC) WakeupSource);

/***********************************************************************************************************************
 *  EcuM_GetPendingWakeupEvents
 **********************************************************************************************************************/
/*! \brief       Get pending wakeup events.
 *  \details     Returns wakeup events which have been set but not validated yet.
 *  \return      EcuM_WakeupSourceType   Wakeup sources which are currently in state pending.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-490
 **********************************************************************************************************************/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetPendingWakeupEvents(void);

/***********************************************************************************************************************
 *  EcuM_GetValidatedWakeupEvents
 **********************************************************************************************************************/
/*! \brief       Get validated wakeup events.
 *  \details     Returns wakeup events which are currently in state validated.
 *  \return      EcuM_WakeupSourceType   Wakeup sources which are currently in state validated.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-541
 **********************************************************************************************************************/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetValidatedWakeupEvents(void);

/***********************************************************************************************************************
 *  EcuM_GetExpiredWakeupEvents
 **********************************************************************************************************************/
/*! \brief       Get expired wakeup events.
 *  \details     Returns wakeup events which are currently in state expired.
 *  \return      EcuM_WakeupSourceType   Wakeup sources which are currently in state expired.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-540
 **********************************************************************************************************************/
FUNC(EcuM_WakeupSourceType, ECUM_CODE) EcuM_GetExpiredWakeupEvents(void);

/***********************************************************************************************************************
 *  EcuM_StartCheckWakeup
 **********************************************************************************************************************/
/*! \brief       Start the check wakeup timeout mechanism.
 *  \details     Starts the check wakeup timeout mechanism and marks that the wakeup source has an
 *               unapproved CheckWakeup call if applicable on given wakeup source (check wakeup timeout > 0).
 *  \param[in]   WakeupSource            Wakeup source to be started.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_StartCheckWakeup(EcuM_WakeupSourceType WakeupSource);

/***********************************************************************************************************************
 *  EcuM_EndCheckWakeup
 **********************************************************************************************************************/
/*! \brief       Stop the check wakeup timeout mechanism.
 *  \details     Stops the check wakeup timeout mechanism and removes the wakeup source from the list of
 *               unapproved CheckWakeup calls.
 *  \param[in]   WakeupSource            Wakeup source to be stopped.
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE for different wakeup sources.
 *  \synchronous TRUE
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_EndCheckWakeup(EcuM_WakeupSourceType WakeupSource);

/***********************************************************************************************************************
 *  EcuM_GetBootTarget
 **********************************************************************************************************************/
/*! \brief       Returns the current selected boot target.
 *  \details     Returns the current selected boot target of the ECU.
 *  \param[out]  BootTarget              The current selected BootTarget.
 *  \return      E_OK      - success
 *  \return      E_NOT_OK  - error
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-492
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetBootTarget
(
  P2VAR(EcuM_BootTargetType, AUTOMATIC, ECUM_APPL_DATA) BootTarget
);

/***********************************************************************************************************************
 *  EcuM_SelectBootTarget
 **********************************************************************************************************************/
/*! \brief       Sets the boot target for the next boot.
 *  \details     Sets the current selected boot target of the ECU.
 *  \param[in]   BootTarget              The current selected BootTarget.
 *  \return      E_OK      - success
 *  \return      E_NOT_OK  - error
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-442
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SelectBootTarget(VAR(EcuM_BootTargetType, AUTOMATIC) BootTarget);

/***********************************************************************************************************************
 *  EcuM_StartupTwo
 **********************************************************************************************************************/
/*! \brief       Completes the startup phase.
 *  \details     Implements the startup phase where the OS is already running.
 *               This function should be scheduled by a task directly after StartOS() and only be called once.
 *  \pre         EcuM must be in state ECUM_STATE_STARTUP_ONE.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-389
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_StartupTwo(void);

#if (ECUM_FIXED_BEHAVIOR == STD_OFF)

/***********************************************************************************************************************
 *  EcuM_GoHalt
 **********************************************************************************************************************/
/*! \brief       Halt the ECU.
 *  \details     This Api is called to set the ECU to a halted sleep mode. In this mode no more code is executed after
 *               entering that state.
 *  \return      E_OK      - success
 *  \return      E_NOT_OK  - error
 *  \pre         Shutdown target must be set to ECUM_STATE_SLEEP.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR disabled
 *  \trace       CREQ-475
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoHalt(void);

/***********************************************************************************************************************
 *  EcuM_GoPoll
 **********************************************************************************************************************/
/*! \brief       Poll for wakeups in power saving mode.
 *  \details     This Api is called to set the ECU to a polling sleep mode. In this mode code is executed and the EcuM
 *               has to poll for wakeup events.
 *  \return      E_OK      - success
 *  \return      E_NOT_OK  - error
 *  \pre         Shutdown target must be set to ECUM_STATE_SLEEP.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR disabled
 *  \trace       CREQ-383
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoPoll(void);

/***********************************************************************************************************************
 *  EcuM_GoToSelectedShutdownTarget
 **********************************************************************************************************************/
/*! \brief       Go to the selected shutdown target.
 *  \details     This Api is called in some modes for saving power. In this API is checked if a call of EcuM_GoPoll,
 *               EcuM_GoHalt or EcuM_GoDown is necessary.
 *  \return      E_OK      - success
 *  \return      E_NOT_OK  - error
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR disabled
 *  \trace       CREQ-372
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoToSelectedShutdownTarget(void);

/***********************************************************************************************************************
 *  EcuM_GoDown
 **********************************************************************************************************************/
/*! \brief       Prepare the ECU for shutdown.
 *  \details     This routine is called to initiate a shutdown or perhaps a reset. The routine checks if the caller is
 *               one of the allowed callers (if configured) and then the EcuM calls the shutdown OS and thereafter the
 *               EcuM_Shutdown is called by the shutdown hook.
 *  \return      E_OK      - success
 *  \return      E_NOT_OK  - error
 *  \pre         Shutdown target must be ECUM_STATE_SLEEP or ECUM_STATE_RESET.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR disabled
 *  \trace       CREQ-535
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GoDown(VAR(uint16, AUTOMATIC) caller);
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
/***********************************************************************************************************************
 *  EcuM_SetRelWakeupAlarm
 **********************************************************************************************************************/
/*! \brief       Relative wakeup alarm.
 *  \details     This function sets a relative wakeup alarm. For use of this function, the current time is not needed
 *               to know.
 *  \return      E_NOT_OK             - No Alarm was started because of an invalid user parameter
 *  \return      E_OK                 - Alarm was successfully set
 *  \return      E_EARLIER_ACTIVE     - Alarm not set because there is already an earlier one.
 *  \param[in]   user            The FlexUser ID of the current caller.
 *  \param[in]   time            Relative time for the wake-up alarm in seconds.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 *  \trace       CREQ-373
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetRelWakeupAlarm
(
  VAR(EcuM_UserType, AUTOMATIC) user, 
  VAR(EcuM_TimeType, AUTOMATIC) sec
);

/***********************************************************************************************************************
 *  EcuM_SetAbsWakeupAlarm
 **********************************************************************************************************************/
/*! \brief       Absolute wakeup alarm.
 *  \details     This function sets an absolute wakeup alarm. For use of this function, the current time must be known.
 *  \return      E_NOT_OK                - error
 *  \return      E_OK                    - success
 *  \return      E_EARLIER_ACTIVE        - Another alarm was set which is earlier in time
 *  \return      E_PAST                  - The new alarm clock time is already in past
 *  \param[in]   user                    The FlexUser ID of the current caller.
 *  \param[in]   time                    The time value designated for that alarm clock.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 *  \trace       CREQ-371
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetAbsWakeupAlarm
(
  VAR(EcuM_UserType, AUTOMATIC) user, 
  VAR(EcuM_TimeType, AUTOMATIC) sec
);

/***********************************************************************************************************************
 *  EcuM_AbortWakeupAlarm
 **********************************************************************************************************************/
/*! \brief       Aborts an users wakeup alarm.
 *  \details     This function aborts a former set user alarm clock.
 *  \return      E_NOT_OK             - error
 *  \return      E_OK                 - success
 *  \return      E_NOT_ACTIVE    For this FlexUser ID no alarm is set.
 *  \param[in]   user            The FlexUser ID of the current caller.
 *  \pre         Active wakeup alarm.
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 *  \trace       CREQ-529
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_AbortWakeupAlarm(VAR(EcuM_UserType, AUTOMATIC) user);

/***********************************************************************************************************************
 *  EcuM_GetWakeupTime
 **********************************************************************************************************************/
/*! \brief       Returns next wakeup alarm.
 *  \details     This function can be used to get the next configured wakeup time.
 *  \return      E_NOT_OK             - error
 *  \return      E_OK                 - success
 *  \param[in]   time            The time value designated for the new time.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 *  \trace       CREQ-497
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetWakeupTime(P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) sec);

/***********************************************************************************************************************
 *  EcuM_GetCurrentTime
 **********************************************************************************************************************/
/*! \brief       Returns the current time.
 *  \details     This function can be used to get the current EcuM_Clock value.
 *  \return      E_NOT_OK             - error
 *  \return      E_OK                 - success
 *  \param[out]  time            The time value of the current EcuM_Clock
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 *  \trace       CREQ-501
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetCurrentTime(P2VAR(EcuM_TimeType, AUTOMATIC, ECUM_APPL_DATA) sec);

/***********************************************************************************************************************
 *  EcuM_SetClock
 **********************************************************************************************************************/
/*! \brief       Returns the current time.
 *  \details     This function can be used to set the EcuM_Clock. This is only necessary for testing purpose. The
 *               possibility to set the EcuM_Clock is only allowed to some special users.
 *  \return      E_NOT_ALLOWED        - This user is not allowed to set the clock
 *  \return      E_OK                 - success
 *  \param[in]   user            The FlexUser ID of the current caller.
 *  \param[in]   time            The time value designated for the new time.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_ALARM_CLOCK_PRESENT
 *  \trace       CREQ-414
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_SetClock
(
  VAR(EcuM_UserType, AUTOMATIC) user, 
  VAR(EcuM_TimeType, AUTOMATIC) sec
);
#endif

# if (ECUM_VERSION_INFO_API == STD_ON)
/***********************************************************************************************************************
 *  EcuM_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version information.
 *  \details     Returns the version information of this Module.
 *  \param[in]   versioninfo     pointer to store the version information
 *  \pre         -
 *  \context     TASK|ISR
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ECUM_VERSION_INFO_API
 *  \trace       CREQ-435
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, ECUM_APPL_DATA) versioninfo);
# endif 

# if (ECUM_FIXED_BEHAVIOR == STD_ON)
/***********************************************************************************************************************
 *  EcuM_GetState
 **********************************************************************************************************************/
/*! \brief       Returns the current module state.
 *  \details     Returns the current module state of the ECUM.
 *  \param[out]  Reference to the current state of the ECUM.
 *  \return      E_OK                    - The parameter state was not a NULL_PTR.
 *  \return      E_NOT_OK                - The parameter state was a NULL_PTR.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \trace       CREQ-696
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_GetState(P2VAR(EcuM_StateType, AUTOMATIC, ECUM_APPL_DATA) state);

/***********************************************************************************************************************
 *  EcuM_KillAllRUNRequests
 **********************************************************************************************************************/
/*! \brief       Kills all Run Requests.
 *  \details     Releases all Post Run Requests. Use this function with care. Side affects may occur in the Applications.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \note        Function should only be called by diagnostics. Use this function with care, side affects may occur in
 *               the Applications.
 *  \trace       CREQ-695
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_KillAllRUNRequests(void);

/***********************************************************************************************************************
 *  EcuM_KillAllPostRUNRequests
 **********************************************************************************************************************/
/*! \brief       Kills all Post Run Requests.
 *  \details     Releases all Post Run Requests. Use this function with care. Side affects may occur
 *               in the Applications.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR
 *  \note        Function should only be called by diagnostics. Use this function with care, side affects may occur in
 *               the Applications.
 *  \trace       CREQ-694
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_KillAllPostRUNRequests(void);
#endif

# if((ECUM_MODE_HANDLING == STD_ON) || (ECUM_FIXED_BEHAVIOR == STD_ON))
/***********************************************************************************************************************
 *  EcuM_RequestRUN
 **********************************************************************************************************************/
/*! \brief       User Run Request.
 *  \details     Requests the RUN state. Requests can be placed by every user known to the state manager at
 *               configuration time. In Development mode ECUM_E_MULTIPLE_RUN_REQUESTS will thrown if a User requests
 *               multiple RUN states.
 *  \param[in]   User_t   User which requests RUN state
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         EcuM is in a state > ECUM_STATE_STARTUP_TWO
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR | ECUM_MODE_HANDLING
 *  \trace       CREQ-649, CREQ-691
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestRUN(EcuM_UserType User);

/***********************************************************************************************************************
 *  EcuM_ReleaseRUN
 **********************************************************************************************************************/
/*! \brief       User Run Release.
 *  \details     Releases a RUN request previously done with a call to EcuM_RequestRUN.
 *               In Development mode the error code ECUM_E_MISMATCHED_RUN_RELEASES will
 *               be thrown if a user releases a RUN state without a matching request.
 *  \param[in]   User_t   User which releases RUN state
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         EcuM is in a state > ECUM_STATE_STARTUP_TWO
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR | ECUM_MODE_HANDLING
 *  \trace       CREQ-651, CREQ-692
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleaseRUN(EcuM_UserType User);

/***********************************************************************************************************************
 *  EcuM_RequestPOST_RUN
 **********************************************************************************************************************/
/*! \brief       User Post Run Request.
 *  \details     Requests the POST RUN state. Requests can be placed for every user known to the state
 *               manager at configuration time. In Development mode ECUM_E_MULTIPLE_RUN_REQUESTS will thrown if a
 *               User requests multiple POST RUN states.
 *  \param[in]   User_t   User which requests POST RUN
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         EcuM is in a state > ECUM_STATE_STARTUP_TWO
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR | ECUM_MODE_HANDLING
 *  \trace       CREQ-648, CREQ-690
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_RequestPOST_RUN(EcuM_UserType User);

/***********************************************************************************************************************
 *  EcuM_ReleasePOST_RUN
 **********************************************************************************************************************/
/*! \brief       User Post Run Release.
 *  \details     Releases a POST RUN request previously done with a call to EcuM_RequestPOST_RUN(). In Development
 *               mode the error code ECUM_E_MISMATCHED_RUN_RELEASES will be thrown if a user releases a RUN  state
 *               without a matching request.
 *  \param[in]   User_t   User which releases POST RUN
 *  \return      E_NOT_OK  - error
 *  \return      E_OK      - success
 *  \pre         EcuM is in a state > ECUM_STATE_STARTUP_TWO
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_FIXED_BEHAVIOR | ECUM_MODE_HANDLING
 *  \trace       CREQ-650, CREQ-693
 **********************************************************************************************************************/
FUNC(Std_ReturnType, ECUM_CODE) EcuM_ReleasePOST_RUN(EcuM_UserType User);
# endif

#if(ECUM_MODE_HANDLING == STD_ON)
/***********************************************************************************************************************
 *  EcuM_SetState
 **********************************************************************************************************************/
/*! \brief       Request a specific state.
 *  \details     Requests a specific state which will be mapped to the corresponding RTE mode. This mode will be used
 *               to trigger a RTE mode switch.
 *  \param[in]   state   State indicated by BswM.
 *  \pre         EcuM is in a state > ECUM_STATE_STARTUP_TWO
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \config      ECUM_MODE_HANDLING
 *  \trace       CREQ-655
 **********************************************************************************************************************/
FUNC(void, ECUM_CODE) EcuM_SetState(EcuM_StateType state);
#endif


# define ECUM_STOP_SEC_CODE
# include "MemMap.h"      /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  EcuM_MainFunction()
 *********************************************************************************************************************/
/*! \fn          EcuM_MainFunction
 *  \brief       MainFunction of the EcuM
 *  \details     Implements the processes of the ECU Management, which need a fix cyclic scheduling. Wakeup validation,
 *               alarm clock handling and in case of the EcuM fix the state handling is performed in this cyclic
 *               function.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-432
*********************************************************************************************************************/
/* The EcuM_MainFunction definition is localized in EcuM.c. The declaration is realized by SchM */


#endif /* ECUM_H */

/*
 * \exclusivearea ECUM_EXCLUSIVE_AREA_0
 * Protect the wakeup event variables during wakeup validation.
 * \protects EcuM_ValidatedWakeups, EcuM_EnabledWakeups, EcuM_BswM_BufferedWakeups, EcuM_PendingWakeups,
 *           EcuM_ClearedPendingWakeups, EcuM_ExpiredWakeups, EcuM_PendingCheckWakeups,
 *           EcuM_ComM_BufferedWakeups
 * \usedin EcuM_EnterSleep, EcuM_MainFunction, EcuM_ClearWakeupEvent, EcuM_ClearValidatedWakeupEvent,
 *         EcuM_StartCheckWakeup, EcuM_EndCheckWakeup, EcuM_StartupTwo, EcuM_SetWakeupEvent, EcuM_ValidateWakeupEvent,
 *         EcuM_GoDown, EcuM_StateMachine
 * \exclude EcuM_CheckWakeup, EcuM_SetWakeupEvent (both called by wake-up interrupts), EcuM_ValidateWakeupEvent
 * \length LONG (User callouts without knowledge about implementation)
 * \endexclusivearea
 *
 * \exclusivearea ECUM_EXCLUSIVE_AREA_1
 * Ensures consistency of the global EcuM core status variables on multicore ECUs.
 * \protects CoreStatus
 * \usedin EcuM_EnterSleep, EcuM_EnterSleepOnSlave, EcuM_GoDown
 * \exclude EcuM_GoHalt, EcuM_GoPoll, EcuM_GoDown, EcuM_GoToSelectedShutdownTarget (On a slave core).
 * \length SHORT
 * \endexclusivearea
 *
 * \exclusivearea ECUM_EXCLUSIVE_AREA_2
 * Ensures consistency of the global EcuM clock time while modifying the time.
 * \protects EcuM_MasterAlarm, EcuM_Clock
 * \usedin EcuM_GetCurrentTime, EcuM_GetWakeupTime, EcuM_SetClock
 * \exclude EcuM_CheckWakeup (called by GPT), EcuM_SetAbsWakeupAlarm, EcuM_SetRelWakeupAlarm
 * \length SHORT
 * \endexclusivearea
 *
 */
/**********************************************************************************************************************
 *  END OF FILE: ECUM.H
 *********************************************************************************************************************/
