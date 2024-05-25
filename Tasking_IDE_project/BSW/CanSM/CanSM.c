
/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2018 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/* \file    CanSM.c
 * \brief   Implementation of the CAN State Manager AUTOSAR Release 4
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  AUTHOR IDENTITY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Name                          Initials      Company
 *  -------------------------------------------------------------------------------------------------------------------
 *  Mark A. Fingerle              MFi           Vector Informatik GmbH
 *  -------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  -------------------------------------------------------------------------------------------------------------------
 *  Version   Date        Author  Change Id     Description
 *  -------------------------------------------------------------------------------------------------------------------
 *  02.00.00  2012-06-23  MFi     ESCAN00058510 Create Ccl_Asr4SmCan Implementation according to ASR 4.0.3
 *  02.01.00  2012-10-21  MFi     ESCAN00062053 Interface to provide internal bus-off recovery level; CanSM_CheckBorLevel()
 *                                ESCAN00062522 Remove compiler abstraction by typedef V A R
 *                                ESCAN00063353 CAN Tx stays offline after bus-off recovery; E_NOT_OK + CtrlModeIndication STARTED
 *                                ESCAN00062050 Instruction order for transition to no communication (CANSM_SD_TRCV_NORMAL)
 *                                ESCAN00063664 Encapsulate function declaration (CheckBaudrate ChangeBaudrate)
 *                                ESCAN00063810 Compiler error: because of missing define STATIC
 *  02.02.00  2013-03-23  MFi     ESCAN00066249 CanSM_ConfirmPnAvailability triggers Unwanted Det( UNINIT )
 *                                ESCAN00065274 Trigger CanIf PduMode wake up filter in PN use case
 *                                ESCAN00065305 Execute transition from SILENT to FULL within RequestComMode
 *                                ESCAN00066935 Correct compiler abstraction and memory mapping
 *  02.03.00  2013-06-13  MFi     ESCAN00068036 Implement functionality of CanSM_SetEcuPassive
 *                                ESCAN00068039 Implement functionality of CanSM_PreventBusSleepAtStartUp
 *  02.03.01  2013-07-23  MFi     ESCAN00069362 Usage of the un-initialized variable CanSM_ChannelConfigurationPtr within CanSM_PreventBusSleepAtStartUp()
 *  02.04.00  2013-07-23  MFi     ESCAN00069109 Set CBR; CANFD Mode 1 (8 Byte Payload) - incl. SetBaudrate
 *                                ESCAN00068797 BusOff Begin End, Support for J1939
 *                                ESCAN00069606 Compiler error: CanSM.c: Cannot open include file: 'CanNm.h': No such file or directory
 *  02.04.01  2014-02-23  MFi     ESCAN00072703 Det_ReportError() called with wrong Det ErrorId parameter (E_PARAM_CONTROLLER instead E_PARAM_TRANSCEIVER)
 *                                ESCAN00073907 BusoffEnd indication is called without bus-off
 *  02.05.00  2014-02-23  MFi     ESCAN00073871 Implement PF4_PostBuildSelectable CANSM_POSTBUILD_VARIANT_SUPPORT
 *  02.06.00  2014-08-23  MFi     ESCAN00078374 Post-Build Selectable (Identity Manager)
 *                                ESCAN00076224 CAN communication not started, because CAN wake up validation failed (Start Stop WakeupSources)
 *                                ESCAN00078867 Det error CANSM_E_INVALID_COMM_REQUEST not triggered
 *                                ESCAN00078993 BusOff recovery, TxOffline phase, takes to long time
 *  02.07.00  2015-02-13  MFi     ESCAN00079868 Avoid usage "...OfPCConfig" macros
 *  02.08.00  2015-05-13  MFi     ESCAN00080295 FEAT-427: SafeBSW Step I
 *                                ESCAN00081783 FEAT-427: SafeBSW Step II
 *                                ESCAN00082163 No Messages are transmitted (unintended EcuPassiveMode, TX_OFFLINE_ACTIVE)
 *  02.08.01  2015-10-13  MFi     ESCAN00085065 CAN communication is not possible, FULL_COMMUNICATION is indicated even Trcv is not set to NORMAL mode
 *                                ESCAN00085071 Memory mapping SEC_CODE does not work
 *                                ESCAN00084048 The BswM indication CANSM_BSWM_NO_COMMUNICATION is not called
 *  02.09.00  2015-10-23  MFi     ESCAN00086062 Reinitialization of CAN CC after NM-Timeout if PN is used
 *                                ESCAN00086732 OSEK NM message is no longer transmitted (BusOffBeginIndication without matching BusOffEndIndication , BusOffEndIndication missing)
 *  02.10.00  2016-01-23  MFi     ESCAN00088643 Extended RAM Check
 *                                ESCAN00087801 FEAT-1688: SafeBSW Step 4
 *                                ESCAN00088799 Communication not possible, because MAX repetition is evaluated wrong
 *  02.10.01  2016-04-01  MFi     ESCAN00089186 Use the type ComM_ModeType provided by ComM
 *                                ESCAN00089184 Modify EnableSetBusSleep array to avoid SBSW counter measure
 *                                ESCAN00089433 Add RAM check begin call out to the PreInit function FEAT-598
 *                                ESCAN00089434 Adapt RAM check parameter naming FEAT-598
 *  02.10.02  2016-05-23  MFi     ESCAN00090151 Compiler warning: function "CanSM_RamCheckEnd" was declared but never referenced
 *  02.11.00  2016-04-23  MFi     ESCAN00089488 FEAT-1933: Add API to provide CAN channel re-initialization
 *                                ESCAN00089962 Compiler warning: Useless assignment to variable StdReturnValue. Assigned value not used.
 *  02.12.00  2016-08-03  MFi     ESCAN00091303 Expand Tx timeout exception handling
 *  02.13.00  2016-11-23  MFi     ESCAN00092617 Toggle preProcessor statements
 *                                FEATC-570     Mode Request Timeout shall be available as Runtime Error (DEM)
 *                                ESCAN00093067 Restructure NetworkStatemachine implementation to consider unexpected states
 *                                ESCAN00093069 Restructure RamCheckEnd implementation to consider unexpected retrun values of RamCheckFinished
 *                                FEATC-527     AUTOSAR 4.2.2 SWS Traceability Goals 2 and 3
 *  02.13.01  2017-10-13  MFi     ESCAN00076256 BswM_CanSM_CurrentState called with locked interrupts - OS ErrorHook on Os API Invocation
 *                                ESCAN00097333 ComM_BusSM_ModeIndication called with locked interrupts - OS ErrorHook on Os API Invocation
 *  03.00.00  2018-05-23  MFi     ESCAN00099586 ErrorFrame after startup with wakeup validation
 *                                STORYC-5592   MISRA 2012
 *  03.00.01  2018-07-23  MFi     STORYC-5592   MISRA 2012 improvements
 *********************************************************************************************************************/



#define CANSM_SOURCE
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* include "Std_Types.h" */ /* already included by "CanSM.h" */
#include "CanSM.h"
/* \trace SPEC-644 */
#include "CanSM_BswM.h" /* Interfaces, which are dedicated to the BswM module. */
#include "CanSM_Cbk.h" /* Callback notification functions */
#include "CanSM_ComM.h" /* API dedicated to the ComM module. */
#include "CanSM_Dcm.h" /* BaudRate */
#include "CanSM_EcuM.h" /* Init function */
#include "CanSM_TxTimeoutException.h" /* TxTimeoutException function */

#include "BswM_CanSM.h"  /* get API declaration */
/* \trace SPEC-650 */
#include "ComM_BusSM.h" /* get API declaration */
/* \trace SPEC-648 */
#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
# include "CanNm.h"     /* get API declaration CanNm_ConfirmPnAvailability */
#endif /*  CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG  */
/* include "CanIf.h" */ /* included in CanSM_Cbk.h */


#if ( CANSM_DEV_ERROR_REPORT == STD_ON )
# include "Det.h"
/* \trace SPEC-645 */
#endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */
# include "SchM_CanSM.h" /* interrupt block, Mainfunction */

/**********************************************************************************************************************
 *  VERSION CHECK
 *********************************************************************************************************************/

/* vendor specific version information is BCD coded */
#if ( ( 0x03u != CANSM_SW_MAJOR_VERSION ) || ( 0x00u != CANSM_SW_MINOR_VERSION ) || ( 0x01u != CANSM_SW_PATCH_VERSION ) )
# error "File CanSM.c: Source and CanSM.h file are inconsistent!"
#endif

# if ( ( CCL_ASR4SMCAN_VERSION != CCL_ASR4SMCAN_BSWM_HEADER_VERSION ) || ( CCL_ASR4SMCAN_RELEASE_VERSION != CCL_ASR4SMCAN_BSWM_HEADER_RELEASE_VERSION ) )
#  error "File CanSM.c: Source and CanSM_BswM.h file are inconsistent!"
# endif

#if ( ( CCL_ASR4SMCAN_VERSION != CCL_ASR4SMCAN_CALLBACK_HEADER_VERSION ) || ( CCL_ASR4SMCAN_RELEASE_VERSION != CCL_ASR4SMCAN_CALLBACK_HEADER_RELEASE_VERSION ) )
# error "File CanSM.c: Source and CanSM_Cbk.h file are inconsistent!"
#endif

#if ( ( CCL_ASR4SMCAN_VERSION != CCL_ASR4SMCAN_COMM_HEADER_VERSION ) || ( CCL_ASR4SMCAN_RELEASE_VERSION != CCL_ASR4SMCAN_COMM_HEADER_RELEASE_VERSION ) )
# error "File CanSM.c: Source and CanSM_ComM.h file are inconsistent!"
#endif

#if ( ( CCL_ASR4SMCAN_VERSION != CCL_ASR4SMCAN_DCM_HEADER_VERSION ) || ( CCL_ASR4SMCAN_RELEASE_VERSION != CCL_ASR4SMCAN_DCM_HEADER_RELEASE_VERSION ) )
# error "File CanSM.c: Source and CanSM_Dcm.h file are inconsistent!"
#endif

#if ( ( CCL_ASR4SMCAN_VERSION != CCL_ASR4SMCAN_ECUM_HEADER_VERSION ) || ( CCL_ASR4SMCAN_RELEASE_VERSION != CCL_ASR4SMCAN_ECUM_HEADER_RELEASE_VERSION ) )
# error "File CanSM.c: Source and CanSM_EcuM.h file are inconsistent!"
#endif

#if ( ( CCL_ASR4SMCAN_VERSION != CCL_ASR4SMCAN_TXTIMEOUTEXCEPTION_HEADER_VERSION ) || ( CCL_ASR4SMCAN_RELEASE_VERSION != CCL_ASR4SMCAN_TXTIMEOUTEXCEPTION_HEADER_RELEASE_VERSION ) )
# error "File CanSM.c: Source and CanSM_TxTimeoutException.h file are inconsistent!"
#endif

#if (  ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_OFF ) && ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )  )
# error "Senseless configuration. CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG does NOT work without CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG"
#endif

/* AUTOSAR version information check has to match definition in header file */
#if ( ( CANSM_AR_RELEASE_MAJOR_VERSION != ( 0x04 )) || ( CANSM_AR_RELEASE_MINOR_VERSION != ( 0x00 ) ) )
# error "AUTOSAR Version numbers of CanSM.c and CanSM.h are inconsistent!"
#endif

/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/* CanSM_IsInitialized values */
#define CANSM_INITFUNCTION_NOT_CALLED         0x00u
#define CANSM_PRE_INITIALIZED                 0x01u
#define CANSM_INITFUNCTION_RUNNING            0x02u
#define CANSM_INITFUNCTION_FINISHED           0x03u
#define CANSM_STOPWAKEUPSOURCES_RUNNING       CANSM_INITFUNCTION_RUNNING
#define CANSM_STOPWAKEUPSOURCES_FINISHED      CANSM_INITFUNCTION_FINISHED

#if ( CANSM_PREVENT_BUSSLEEP_AT_STARTUP == STD_ON )
/* Set the CAN Channel to Sleep    during initialization CanSM_EnableSetBusSleep */
# define CANSM_SET_BUS_SLEEP_MODE             0x00u
# define CANSM_PREVENT_BUS_SLEEP_MODE         0x01u
#endif /* CANSM_PREVENT_BUSSLEEP_AT_STARTUP */

/* CanSM_LastValidBaudRate */
#define CANSM_INVALID_BAUDRATE                0xFFFFu


#define CANSM_TIMER_EXPIRED                   0x0000u
#define CANSM_CANCEL_TIMER                    CANSM_TIMER_EXPIRED

/* CanSM_CurrentState */
/* Start up  PRE_FULLCOM */
#define CANSM_SU_TRCV_NORMAL                  0x01u
#define CANSM_SU_CC_STOPPED                   0x02u
#define CANSM_SU_CC_STARTED                   0x03u

/* CANSM_S_FULLCOM */
#define CANSM_BO_BUS_OFF_CHECK                0x11u /* 17 */
#define CANSM_S_NO_BUS_OFF                    0x10u /* 16 */
#define CANSM_S_FULLCOM_ENSURED               CANSM_S_NO_BUS_OFF
#define CANSM_BO_TX_OFFLINE                   0x14u /* 20 */
/* define CANSM_S_RESTART_CC */

/* SILENT */
#define CANSM_S_SILENTCOM                     0x20u
/* shutdown incl. NoCom: CanSM_CurrentState > CANSM_S_SILENTCOM  */

/* ShutDown S_PRE_NOCOM */
#define CANSM_SD_PN_CLEAR_WUF                 0x21u /* 33 */
#define CANSM_SD_CC_STOPPED                   0x22u /* 34 */
#define CANSM_SD_RAMCHECK_END                 0x62u   /* 98 */
#define CANSM_SD_CHECK_RAM                    0x61u   /* 97 */
#define CANSM_SD_CC_SLEEP                     0x23u /* 35 */
#define CANSM_SD_TRCV_NORMAL                  0x24u /* 36 */
#define CANSM_SD_TRCV_STANDBY                 0x25u /* 37 */
#define CANSM_SD_CC_SLEEP_PN                  0x26u /* 38 */
#define CANSM_SD_CHK_WUF_CC_SLEEP             0x27u /* 39 */
#define CANSM_SD_CHK_WUF_NOT_CC_SLEEP         0x28u /* 40 */

#define CANSM_S_NOCOM                         0x40u /* 64 */
#define CANSM_S_STARTWAKEUPSOURCES_SUCCESSFUL 0x60u /* 96 */

#define CANSM_TX_TIMEOUT_EXCEPTION_RECEIVED   0x80u
#define CANSM_CLEAR_TX_TIMEOUT_EXCEPTION_FLAG 0x7Fu


#define CANSM_S_INTERIM_STATE_FILTER          0x0Fu
#define CANSM_S_INTERIM_STATE_DETECTED        0x01u


/* CanSM_ModeIndicationResponsible
 * CANSM_SID_GETVERSIONINFO used because it is ensured that these API will never trigger a BswM indication */
#define CANSM_NOBODY                                                  (CANSM_SID_GETVERSIONINFO)


/*  Last 4 bits used for substates.
 *  If substate bits are zero (0xY0u) a base state is reached (CANSM_S_SILENTCOM, CANSM_S_NO_BUS_OFF, CANSM_S_NOCOM)
 *  No action necessary till external request
 *  So NWSM NOT triggered */
#if (  ( CANSM_S_SILENTCOM & CANSM_S_INTERIM_STATE_FILTER ) != 0 )
# error "illegal value of meta state: CANSM_S_SILENTCOM"
#endif
#if (  ( CANSM_S_NO_BUS_OFF & CANSM_S_INTERIM_STATE_FILTER ) != 0 )
# error "illegal value of meta state: CANSM_S_FULLCOM_ENSURED, CANSM_S_NO_BUS_OFF"
#endif
#if (  ( CANSM_S_NOCOM & CANSM_S_INTERIM_STATE_FILTER ) != 0 )
# error "illegal value of meta state: CANSM_S_NOCOM"
#endif

#if ( CANSM_S_NO_BUS_OFF == ( CANSM_S_SILENTCOM & CANSM_S_NO_BUS_OFF ) )
# error "illegal value of meta state: CANSM_S_SILENTCOM, metaBit FullCom is active"
#endif
#if ( CANSM_S_NO_BUS_OFF == ( CANSM_S_NOCOM & CANSM_S_NO_BUS_OFF ) )
# error "illegal value of meta state: CANSM_S_NOCOM, metaBit FullCom is active"
#endif
#if defined ( CANSM_BOR_NONE )
# if ( CANSM_BOR_NONE != 0 )
#  error "illegal value of BOR counter, BOR state: CANSM_BOR_NONE"
# endif
#else /* defined ( CANSM_BOR_NONE ) */
# define CANSM_BOR_NONE                       (0x00u)
#endif /* defined ( CANSM_BOR_NONE ) */

/* CanSM_TxOnlineDelayTime
 * uint8 sufficient, only DELAY */
#define CANSM_DELAY_TIMER_INACTIVE            0xFFu

/* CanSM_BusOffCounter */
#define CANSM_COUNTER_MAX_VALUE               0xFFu


#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
# if ( CANSM_ISDEF_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
#  define CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
/* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_OFF is equal to CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG STD_OFF */
# else /* CANSM_ISDEF_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG */
#  define CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
# endif
#endif


#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_OFF )
# define CANSM_TRCVSTANDBY_NEVER_INDICATED_AT_PN_CHANNELS
#endif /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG */

#if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
# define CANSM_TRCVSTANDBY_ONLY_INDICATED_AT_PN_CHANNELS
#else /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */
# if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
#  if ( CANSM_ISDEF_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG == STD_ON )
#   define CANSM_TRCVSTANDBY_ONLY_INDICATED_AT_PN_CHANNELS
#  endif /* ( CANSM_ISDEF_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG == STD_ON ) */
# endif /* ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
#endif /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */


#if !defined CANSM_TRCVSTANDBY_NEVER_INDICATED_AT_PN_CHANNELS
# if !defined CANSM_TRCVSTANDBY_ONLY_INDICATED_AT_PN_CHANNELS
#  define CANSM_TRCVSTANDBY_INDICATED_AT_PN_CHANNELS_AND_NON_PN_CHANNELS_MIXED
# endif /* !defined CANSM_TRCVSTANDBY_ONLY_INDICATED_AT_PN_CHANNELS */
#endif /* !defined CANSM_TRCVSTANDBY_NEVER_INDICATED_AT_PN_CHANNELS */



#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/* Trcv at least on one channel active */
# if ( CANSM_ISDEF_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
#  define CANSM_TRANSCEIVER_HANDLING_ALWAYS_ON
# else   /* ISDEF */
#  define CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF
# endif  /* ISDEF */
#endif  /* sometimes or ever ON */




# if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_OFF ) /* Trcv active at least at one channel */
# define CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_WITHOUT_TRCV
#endif /* CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG */

#if defined CANSM_TRANSCEIVER_HANDLING_ALWAYS_ON
# define CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_HAS_TRCV
#endif /* CANSM_TRANSCEIVER_HANDLING_ALWAYS_ON */

#if defined CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF
/* Any PnTrcvCh has always Trcv */
# if ( CANSM_ISDEF_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG == STD_OFF )
#  define CANSM_SD_CC_SLEEP_NON_PN_CHANNELS_TRCV_MIXED
# endif /* ( CANSM_ISDEF_TRCV_INACTIVE_ATALL_NONPNCANNELSOFCHANNELCONFIG == STD_ON ) */
#endif /* CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF */

/* if !defined ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON ) is already checked before the state will be evaluated  define CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_WITHOUT_TRCV has to be removed to get the variant coverage */


#if ( CANSM_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_ON )
# if ( CANSM_ISDEF_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_ON )
#  define CANSM_BOR_TX_CONFIRMATION_POLLING_ALWAYS_ON
# endif
#endif



/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/* To provide compatibility, the component defines a CANSM_LOCAL on its own. */
#if !defined ( CANSM_LOCAL ) /* COV_CANSM_CHECKDEFINE */
# define CANSM_LOCAL static
#endif
#if !defined ( CANSM_LOCAL_INLINE ) /* COV_CANSM_CHECKDEFINE */
# define CANSM_LOCAL_INLINE LOCAL_INLINE
#endif

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

#if ( CANSM_USE_INIT_POINTER == STD_ON )
# define CANSM_START_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* \trace SPEC-640 */

CANSM_LOCAL P2CONST( CanSM_ConfigType, CANSM_VAR_NOINIT, CANSM_CONST ) CanSM_ConfigDataPtr;

# define CANSM_STOP_SEC_VAR_NOINIT_UNSPECIFIED
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* ( CANSM_USE_INIT_POINTER == STD_ON ) */

#define CANSM_START_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! Used values are CANSM_INITFUNCTION_NOT_CALLED, CANSM_PRE_INITIALIZED, CANSM_INITFUNCTION_RUNNING, CANSM_INITFUNCTION_FINISHED */
CANSM_LOCAL VAR( uint8, CANSM_VAR_ZERO_INIT ) CanSM_IsInitialized = CANSM_INITFUNCTION_NOT_CALLED;
/* \trace SPEC-11327, SPEC-47131 */


#define CANSM_STOP_SEC_VAR_ZERO_INIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
#define CANSM_START_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

CANSM_LOCAL VAR( boolean, CANSM_VAR_NOINIT ) CanSM_EcuPassiveMode;

#define CANSM_STOP_SEC_VAR_NOINIT_8BIT
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif /* CANSM_ECU_PASSIVE_MODE == STD_ON  */

/**********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

#define CANSM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
  CanSM_FullComReached()
 **********************************************************************************************************************/
/*! \brief        Full communication reached
 *  \details      Enters of the meta state S_FullCom, resp. S_BUS_OFF_CHECK
 *  \param[in]    CanSM_CanNetworkIdx           Current CanSM channel index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_RequestComMode CanSM_ControllerModeIndication and CanSM_MainFunction
 */
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_FullComReached( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_FullComToSilent()
 **********************************************************************************************************************/
/*! \brief        Full communication to silent
 *  \details      Transition form FullCom To SilentCom
 *  \param[in]    CanSM_CanNetworkIdx           Current CanSM channel index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_RequestComMode CanSM_ControllerModeIndication and CanSM_MainFunction
 **********************************************************************************************************************/
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_FullComToSilent( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_NoComReached()
 **********************************************************************************************************************/
/*! \brief        No communication reached
 *  \details      Enters the meta state S_NoCom
 *
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_RequestComMode CanSM_ControllerModeIndication and CanSM_MainFunction
 **********************************************************************************************************************/
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_NoComReached( P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_NetworkStatemachine()
 **********************************************************************************************************************/
/*! \brief        Network state machine
 *  \details      Handles the state transitions
 *
 *  \param[in]    CanSM_CanNetworkIdx           Current CanSM channel index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  FALSE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_RequestComMode CanSM_Init and CanSM_MainFunction
 **********************************************************************************************************************/
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_NetworkStatemachine( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );


/**********************************************************************************************************************
  CanSM_InitializeVariables()
 **********************************************************************************************************************/
/*! \brief        Initialize variables
 *  \details      Initialize the variables of the current channel
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_Init
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_InitializeVariables( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx );

/**********************************************************************************************************************
  CanSM_UninitToNoCom()
 **********************************************************************************************************************/
/*! \brief        Initial transition
 *  \details      Initial transition to no communication for the current channel
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  FALSE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_Init
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_UninitToNoCom( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx );

#if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/**********************************************************************************************************************
  CanSM_RamCheckEnd()
 **********************************************************************************************************************/
/*! \brief        RAM check end
 *  \details      Memorize and evaluate the return value
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \context      TASK
 *  \reentrant    TRUE for different networks
 *  \synchronous  FALSE
 *  \config       CANSM_EXTENDED_RAM_CHECK
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_RamCheckEnd( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx );
#endif /* CANSM_EXTENDED_RAM_CHECK  */

/**********************************************************************************************************************
  CanSM_BusOffCheckToNoBusOff
 **********************************************************************************************************************/
/*! \brief        Full communication ensured
 *  \details      Transition BusOffCheck to NoBusOff
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_BusOffCheckToNoBusOff( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_CtrlStartedIndicated
 **********************************************************************************************************************/
/*! \brief        Controller mode started indicated
 *  \details      Evaluate the indicated mode CtrlStartedIndicated
 *                Evaluates the received mode and triggers according transition if needed
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_CtrlStartedIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_CtrlStoppedIndicated
 **********************************************************************************************************************/
/*! \brief        Controller mode stopped indicated
 *  \details      Evaluate the indicated mode CtrlStoppIndicated
 *                Evaluates the received mode and triggers according transition if needed
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_CtrlStoppedIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_CtrlSleepIndicated
 **********************************************************************************************************************/
/*! \brief        Controller mode sleep indicated
 *  \details      Evaluate the indicated mode CtrlSleepIndicated
 *                Evaluates the received mode and triggers according transition if needed
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_CtrlSleepIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/**********************************************************************************************************************
  CanSM_TrcvNormalIndicated
 **********************************************************************************************************************/
/*! \brief        Transceiver mode normal indicated
 *  \details      Evaluate the indicated mode TrcvNormalIndicated
 *                Evaluates the received mode and triggers according transition if needed
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_TrcvNormalIndicated( P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );
#endif /* ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */

#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/**********************************************************************************************************************
  CanSM_TrcvStandbyIndicatedAsExpected
 **********************************************************************************************************************/
/*! \brief        Transceiver mode standby indicated
 *  \details      Evaluate the indicated mode TrcvStandbyIndicated
 *                Evaluates the received mode and triggers according transition if needed
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_TrcvStandbyIndicatedAsExpected( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );
#endif /* ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */

/**********************************************************************************************************************
  CanSM_EvaluateComModeRequest
 **********************************************************************************************************************/
/*! \brief        Evaluate the requested communication mode
 *  \details      Modify the internal variables to lead the CanSM to the correct path to reach the desired communication mode
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_EvaluateComModeRequest( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_HandleBusOffInSilent
 **********************************************************************************************************************/
/*! \brief        Bus-off in silent communication
 *  \details      Handle bus-off events which occur in state silent communication
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_HandleBusOffInSilent( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_EvaluateMaxModeRequests
 **********************************************************************************************************************/
/*! \brief        Evaluate maximum mode requests
 *  \details      Triggers shut down if the number of requests exceed the configured maximum
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_EvaluateMaxModeRequests( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_TimerHandling
 **********************************************************************************************************************/
/*! \brief        Timer handling
 *  \details      Runs the timer, enable mode request repetition
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_TimerHandling( P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_HandleComModeRequest
 **********************************************************************************************************************/
/*! \brief        Handles valid communication mode request
 *  \details      Memorizes the communication mode and triggers short transitions i.e. without hardware mode changes
 *  \param[in]    CanSM_RequestedComMMode        communication mode, desired by ComM
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_HandleComModeRequest( ComM_ModeType CanSM_RequestedComMMode, CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_MapNetworkHandleToLocalIndex()
 **********************************************************************************************************************/
/*! \brief        Map network handle to local index
 *  \details      Determines the local index from the passed index
 *  \param[in]    CanSM_NetworkHandle                   identification number of the network
 *  \return       CanSM Index - valid if given handle was found otherwise value out of range
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(CanSM_SizeOfChannelVarRecordType, CANSM_CODE) CanSM_MapNetworkHandleToLocalIndex( NetworkHandleType CanSM_NetworkHandle );

#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/**********************************************************************************************************************
  CanSM_MapTransceiverIdToLocalIndex()
 **********************************************************************************************************************/
/*! \brief        Map transceiver index to local index
 *  \details      Determines the local index from the passed index
 *  \param[in]    CanSM_TransceiverId                   identification number of the transceiver
 *  \return       CanSM Index - valid if given handle was found otherwise value out of range
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(CanSM_SizeOfChannelVarRecordType, CANSM_CODE) CanSM_MapTransceiverIdToLocalIndex( uint8 CanSM_TransceiverId );
#endif /* ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */

/**********************************************************************************************************************
  CanSM_MapControllerIdToLocalIndex()
 **********************************************************************************************************************/
/*! \brief        Map controller index to local index
 *  \details      Determines the local index from the passed index
 *  \param[in]    CanSM_ControllerId                   identification number of the controller
 *  \return       CanSM Index - valid if given handle was found otherwise value out of range
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(CanSM_SizeOfChannelVarRecordType, CANSM_CODE) CanSM_MapControllerIdToLocalIndex( uint8 CanSM_ControllerId );

/**********************************************************************************************************************
  CanSM_BusOffIndicated()
 **********************************************************************************************************************/
/*! \brief        Bus off indicated
 *  \details      Handles new bus-off indication
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_BusOffIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx );

/**********************************************************************************************************************
  CanSM_SetCanIfPduModeFullCom()
 **********************************************************************************************************************/
/*! \brief        Set PDU Mode Full Com
 *  \details      Set the PDU mode if state bus-off check (FullCom) is entered
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_SetCanIfPduModeFullCom( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, uint8 CanSM_BusOffLevel );

/**********************************************************************************************************************
  CanSM_StartControllerToBusOffCheck()
 **********************************************************************************************************************/
/*! \brief        Enter full communication check
 *  \details      Enter the state bus-off check (FullCom)
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *  \note         Called by CanSM_FullComReached
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_StartControllerToBusOffCheck( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_FullComToRestartController()
 **********************************************************************************************************************/
/*! \brief        Enter Bus Off Tx offline
 *  \details      Enters the state (FullCom) Tx offline
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_FullComToRestartController( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_InitiateShutDownSequence()
 **********************************************************************************************************************/
/*! \brief        Initiate Shut Down Sequence
 *  \details      Starts (executes the first step of) the shut down sequence
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 *********************************************************************************************************************/
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_InitiateShutDownSequence( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr );

/**********************************************************************************************************************
  CanSM_CheckModeIndication()
 **********************************************************************************************************************/
/*! \brief        Handels the indication to BswM and ComM
 *  \details      Informs the BswM/ComM about occurred mode changes
 *  \param[in]    CanSM_CanNetworkIdx           Can network index
 *  \param[in]    CanSM_CurrentChannelVarPtr    Pointer to channel specific variable structure
 *  \param[in]    CanSM_ModeIndiResp            API-ID of the function which has the premission to trigger the indication
 *  \context      ANY
 *  \reentrant    TRUE for different networks
 *  \synchronous  TRUE
 *  \config       -
 *  \pre          -
 *  \trace        -
 **********************************************************************************************************************/
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_CheckModeIndication( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr, uint8 CanSM_ModeIndiResp );


#define CANSM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */




/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

#define CANSM_START_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  CanSM_SetCanIfPduModeFullCom
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_SetCanIfPduModeFullCom( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, uint8 CanSM_BusOffLevel )
{ /* Context: NWSM; CANSM_BO_TX_OFFLINE timer elapsed, CanSM_CtrlStartedIndicated after startup resp. no BOR CanSM_HandleComModeRequest; from SILENT to FULL;;    CanSM_FullComReached; withOUT new raw pending BusOff;;; CanSM_StartControllerToBusOffCheck; enter FullCom */

#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
  if ( CanSM_EcuPassiveMode == FALSE )
#endif  /* CANSM_ECU_PASSIVE_MODE */
  {
#if ( CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG == STD_ON )
    if ( CanSM_BusOffLevel == CANSM_BOR_NONE )
    {
      (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_ONLINE_WAKF );
    }
    else
    { /* enter FULL after BO no wake up for other ECU necessary. Avoid WAKF to accelerate normal Tx communication */
      (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_ONLINE );
    }

#else /* CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG */

    (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_ONLINE );

#endif   /* end else  if ( CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG == STD_ON ) */

  }
#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
  else /*  CanSM_EcuPassiveMode true */
  {
    (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_TX_OFFLINE_ACTIVE );
    (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_RX_ONLINE );
  } /* CanSM_EcuPassiveMode */
#endif  /* CANSM_ECU_PASSIVE_MODE */

#if ( CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG != STD_ON )
  CANSM_DUMMY_STATEMENT( CanSM_BusOffLevel ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* ( CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG != STD_ON ) */
  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_SetCanIfPduModeFullCom */




/***********************************************************************************************************************
 *  CanSM_CheckModeIndication
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_CheckModeIndication( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr, uint8 CanSM_ModeIndiResp )
{ /* Context: CanSM_RequestComMode(CanSM_HandleComModeRequest),  CanSM_BusOffIndicated(CanSM_BusOffIndicated), CanSM_MainFunction, CanSM_ControllerModeIndication */


  if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CanSM_ModeIndiResp )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_NOBODY; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    if ( (*CanSM_CurrentChannelVarPtr).CanSM_BswMIndicatedState != (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState )
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_BswMIndicatedState = (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      BswM_CanSM_CurrentState( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ), (*CanSM_CurrentChannelVarPtr).CanSM_BswMIndicatedState );
    } /* BswM changed */

    if (  ( (*CanSM_CurrentChannelVarPtr).CanSM_IndicatedComMode != (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode ) || ( (*CanSM_CurrentChannelVarPtr).CanSM_EnfroceComModeIndication == TRUE )  )
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_EnfroceComModeIndication = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      (*CanSM_CurrentChannelVarPtr).CanSM_IndicatedComMode = (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      ComM_BusSM_ModeIndication( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ), &( (*CanSM_CurrentChannelVarPtr ).CanSM_IndicatedComMode ) ); /* SBSW_CANSM_COMMMODEINDICATION_CALL */
    } /* ComM changed */

  } /* caller is Indication Responsible  */


  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* end CanSM_CheckModeIndication() */



/***********************************************************************************************************************
 *  CanSM_StartControllerToBusOffCheck
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_StartControllerToBusOffCheck( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /*  Context: NWSM; CANSM_BO_TX_OFFLINE timer elapsed, CanSM_CtrlStartedIndicated after startup resp. no BOR CanSM_HandleComModeRequest; from SILENT to FULL;;    CanSM_FullComReached; withOUT new raw pending BusOff */
  /* \trace SPEC-11274,  SPEC-11360  */

  (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_FULL_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_FULL_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  CanSM_SetCanIfPduModeFullCom( CanSM_CanNetworkIdx, (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter );


  (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_BO_BUS_OFF_CHECK; /* CREQ-368 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#if ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_ON )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag == TRUE )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_TxTimeoutExceptionEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) );  /* SBSW_CANSM_TX_TIMEOUT_END_INDICATION */
  }
#endif /* ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_OFF ) */


#if defined CANSM_BOR_TX_CONFIRMATION_POLLING_ALWAYS_ON
  (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#elif ( CANSM_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_OFF )
  (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CanSM_GetBorTimeTxEnsuredOfChannelConfig( CanSM_CanNetworkIdx ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#else /* Some channels with BOR_TX_CONFIRMATION_POLLING     Some channels without TxPolling  */
  if ( CanSM_IsBor_Tx_Confirmation_PollingOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  }
  else
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CanSM_GetBorTimeTxEnsuredOfChannelConfig( CanSM_CanNetworkIdx ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  }
#endif /* BOR_TX_CONFIRMATION_POLLING */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_StartControllerToBusOffCheck */



/***********************************************************************************************************************
 *  CanSM_FullComToRestartController
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_FullComToRestartController( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_BusOffIndicated; new raw bus-off */

  (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_BUS_OFF; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_SILENT_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  /* \trace..SPEC-11324 */
  /* \trace..SPEC-11416 */

#if ( CANSM_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG == STD_ON )
# if ( CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG == STD_ON )
  CanSM_Dem_ReportErrorEvent( CanSM_GetDemEventId_BusOff_OfChannelConfig( CanSM_CanNetworkIdx ), DEM_EVENT_STATUS_PREFAILED );
# else /* CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG */
  if ( CanSM_IsProdErrorDetect_BusOff_OfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  {
    CanSM_Dem_ReportErrorEvent( CanSM_GetDemEventId_BusOff_OfChannelConfig( CanSM_CanNetworkIdx ), DEM_EVENT_STATUS_PREFAILED );
  }
# endif /* CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG */
#endif /* ( CANSM_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG == STD_ON ) */
  /* \trace..SPEC-11335 */

  (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* trigger NwSM next MainFuncCycle */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STARTED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_FullComToRestartController */


/***********************************************************************************************************************
 *  CanSM_InitiateShutDownSequence
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_InitiateShutDownSequence( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_Init, CanSM_InitializeVariables; CanSM_MainFunction, CanSM_EvaluateComModeRequest CanSM_MainFunction, CanSM_EvaluateMaxModeRequests CanSM_TxTimeoutException, no bus-off */
  /* \trace..SPEC-11288 */

  (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  /* \trace..SPEC-11365 */
  (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


#if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
  if ( CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
#endif /*   CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF */
  {
#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_PN_CLEAR_WUF; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif  /* not always OFF ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
  }
#if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
  else
#endif /*   CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF */
  {
#if !defined ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON )
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif /* ( not CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON  ) */
  }

#if ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_ON )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag == TRUE )
  {
    (*CanSM_TxTimeoutExceptionEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) ); /* SBSW_CANSM_TX_TIMEOUT_END_INDICATION */
  }
#endif /* ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_OFF ) */
  (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_InitiateShutDownSequence */



/***********************************************************************************************************************
 *  CanSM_InitializeVariables
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_InitializeVariables( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx )
{ /* Context: Called by CanSM_Init */
  P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
  CanSM_EcuPassiveMode = FALSE;
#endif  /* CANSM_ECU_PASSIVE_MODE */

  (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter = 0; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate = CANSM_INVALID_BAUDRATE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode = COMM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_IndicatedComMode = COMM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_NOBODY;  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_BswMIndicatedState = CANSM_BSWM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_NO_COMMUNICATION;  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_EnfroceComModeIndication = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )
  (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime = CANSM_DELAY_TIMER_INACTIVE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */

  CanSM_InitiateShutDownSequence( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

} /* CanSM_InitializeVariables */



/***********************************************************************************************************************
 *  CanSM_UninitToNoCom
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_UninitToNoCom( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx )
{ /* Context: CanSM_Init */

  P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

  (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_INIT;  /* avoid mode indication */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
  (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState   = CANSM_SD_CHECK_RAM; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  CanSM_RamCheckEnd( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx );
#endif /* CANSM_EXTENDED_RAM_CHECK  */

#if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_RamCheckState == CANSM_ENABLE_COMMUNICATION )
#endif /* CANSM_PREVENT_BUSSLEEP_AT_STARTUP CANSM_USE_INIT_POINTER */
  {

#if (  ( CANSM_PREVENT_BUSSLEEP_AT_STARTUP == STD_ON ) && ( CANSM_USE_INIT_POINTER == STD_OFF )  )
    if ( CanSM_EnableSetBusSleep[ CanSM_CanNetworkIdx ] != CANSM_SET_BUS_SLEEP_MODE )
    { /* skip initial transition to NoCom */
      (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState   = CANSM_S_NOCOM; /* CREQ-365 */ /* CanSM_PreventBusSleepAtStartUp */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }
    else
#endif /* CANSM_PREVENT_BUSSLEEP_AT_STARTUP CANSM_USE_INIT_POINTER */
    {
      CanSM_NetworkStatemachine( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      /* \trace SPEC-11277 */
    }  /* EnableSetBusSleep CANSM_SET_BUS_SLEEP_MODE  */

  } /* CanSM_RamCheckState  CANSM_ENABLE_COMMUNICATION */

  (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_NOBODY;  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


} /* CanSM_UninitToNoCom */



/***********************************************************************************************************************
 *  FUNC CanSM_BusOffCheckToNoBusOff
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_BusOffCheckToNoBusOff( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: NWSM; CANSM_BO_BUS_OFF_CHECK */

  /* \trace..SPEC-11322 */
#if ( CANSM_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG == STD_ON )
# if ( CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG == STD_ON )
  CanSM_Dem_ReportErrorEvent( CanSM_GetDemEventId_BusOff_OfChannelConfig( CanSM_CanNetworkIdx ), DEM_EVENT_STATUS_PASSED );
# else /* CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG */
  if ( CanSM_IsProdErrorDetect_BusOff_OfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
  {
    CanSM_Dem_ReportErrorEvent( CanSM_GetDemEventId_BusOff_OfChannelConfig( CanSM_CanNetworkIdx ), DEM_EVENT_STATUS_PASSED );
  }
# endif /* CANSM_ISDEF_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG */
#endif /* ( CANSM_PRODERRORDETECT_BUSOFF_OFCHANNELCONFIG == STD_ON ) */

  (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_S_NO_BUS_OFF; /* CREQ-368 */ /* CANSM_S_FULLCOM_ENSURED */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_BusOffCheckToNoBusOff */



/***********************************************************************************************************************
 *  CanSM_CtrlStartedIndicated
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
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_CtrlStartedIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_ControllerModeIndication, CANIF_CS_STARTED received in state CANSM_SU_CC_STARTED */

  (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter = 0; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode &= CANSM_CLEAR_TX_TIMEOUT_EXCEPTION_FLAG; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

#if !defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode == COMM_NO_COMMUNICATION )
  { /* CanSM_StartWakeupSources  Skip FullCom Indication */
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_S_STARTWAKEUPSOURCES_SUCCESSFUL; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */ /* PRQA S 2982 */ /* MD_CANSM_Rule2.2_2982 */
  }
  else
#endif /* !defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter == CANSM_BOR_NONE )
  { /* E_FULLCOM */ /* E_FULL_COM */
#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
    SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_5(); /* RequestComMode MainFunction SetEcuPassive */
#endif /* CANSM_ECU_PASSIVE_MODE == STD_ON  */

    CanSM_FullComReached( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace..SPEC-11304 */
    /* \trace SPEC-11373, SPEC-11381, SPEC-11387, SPEC-47117, SPEC-47124 */
#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
    SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_5();
#endif /* CANSM_ECU_PASSIVE_MODE == STD_ON  */
  }
  else
  { /* E_TX_OFF */

    (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_TX_OFFLINE );

    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_BO_TX_OFFLINE; /* CREQ-367 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    if ( CanSM_GetBorCounterL1ToL2OfChannelConfig( CanSM_CanNetworkIdx ) > (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter )
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CanSM_GetBorTimeL1OfChannelConfig( CanSM_CanNetworkIdx ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }
    else
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CanSM_GetBorTimeL2OfChannelConfig( CanSM_CanNetworkIdx ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }
#if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )

    /* Check if CanSM_TxOnlineDelayTime ins unequal to CANSM_DELAY_TIMER_INACTIVE is redundant to the preProcessor switch */

    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer += (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime; /* J1939Nm delay */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace..SPEC-2181238 */
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */

  }

} /* CanSM_CtrlStartedIndicated */



/***********************************************************************************************************************
 *  CanSM_CtrlStoppedIndicated
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
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_CtrlStoppedIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_ControllerModeIndication, CANIF_CS_STOPPED received */

  if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SU_CC_STOPPED )
  {

#if ( ( CANSM_SET_BAUDRATE_API == STD_ON ) || ( CANSM_CHANGE_BAUDRATE_API == STD_ON ) )
    if (  (*CanSM_CurrentChannelVarPtr).CanSM_BswMIndicatedState == CANSM_BSWM_CHANGE_BAUDRATE )
    { /* E_CHANGE_BAUDRATE CANSM_BSM_S_CHANGE_BAUDRATE */

      (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_NO_COMMUNICATION;  /* CBR  END; */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      /* \trace..SPEC-11339 */

# if ( CANSM_SET_BAUDRATE_API == STD_ON)
      (void)CanIf_SetBaudrate( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate );  /* CanSM_LastValidBaudRate contains value of BaudRateConfigID */
# else /* # if (  ==CANSM_CHANGE_BAUDRATE_API  either SetBR  or ChangeBR allowed */
      (void)CanIf_ChangeBaudrate( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate );
# endif /*  CANSM_CHANGE_BAUDRATE_API ) */
      /* \trace..SPEC-47122 */
      /* \trace..SPEC-11353 */

    }
#endif /* (  CANSM_SET_BAUDRATE_API ) || ( CANSM_CHANGE_BAUDRATE_API ) ) */

    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STARTED; /* CANSM_S_BR_CC_STARTED */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace..SPEC-11309 */
    /* \trace..SPEC-47113 */

  }
  else if ( CANSM_SD_CC_STOPPED == (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState )
  { /* shut down  */


#if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_TRCV_NORMAL; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#else /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */

# if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
    if ( !CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
# endif /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF */
    {
      /* already checked above; if ! defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */
      (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_SLEEP; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      /* already checked see below;  end if ( not CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON  ) */
# if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
      if ( CanSM_IsInitialized != CANSM_STOPWAKEUPSOURCES_RUNNING ) /*  alias CANSM_INITFUNCTION_RUNNING */
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CHECK_RAM; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }
# endif /* CANSM_EXTENDED_RAM_CHECK  */
      /* \trace..SPEC-11425 */
    }
# if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
    else
# endif /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF */
    {
# if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
      (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_TRCV_NORMAL; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# endif  /* not always OFF ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
      /* \trace..SPEC-11309 */
    }

#endif /* not defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */

    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  }
  else
  {
    /* MISRA QAC */
  }

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_CtrlStoppedIndicated */



/***********************************************************************************************************************
 * CanSM_CtrlSleepIndicated
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_CtrlSleepIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_ControllerModeIndication, CANIF_CS_SLEEP received */

#if !defined ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CC_SLEEP )
  {

    /* \trace SPEC-11295 */
# if defined CANSM_SD_CC_SLEEP_NON_PN_CHANNELS_TRCV_MIXED
    if ( CanSM_IsTransceiver_Channel_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
# endif /* Trcv ID, runtime check needed, channels on or off */
    {
#if !defined CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_WITHOUT_TRCV
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */ /* PRQA S 2982 */ /* MD_CANSM_Rule2.2_2982 */
      (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_TRCV_NORMAL; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */ /* PRQA S 2982 */ /* MD_CANSM_Rule2.2_2982 */
# endif /* CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_WITHOUT_TRCV */
    } /* end if Trcv active on current channel */
# if defined CANSM_SD_CC_SLEEP_NON_PN_CHANNELS_TRCV_MIXED
    else
# endif /* Trcv ID runtime check, mixed on off */
    {
      /* Trcv active at least at one channel */
#if !defined CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_HAS_TRCV
      CanSM_NoComReached( CanSM_CurrentChannelVarPtr );  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif /*  CANSM_SD_CC_SLEEP_ALL_NON_PN_CHANNELS_HAS_TRCV  */
    }
    /* \trace SPEC-11341, SPEC-11405 */

  }
#endif /* ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON ) */
#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
#if defined ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON )
  if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CC_SLEEP_PN ) || ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CHK_WUF_NOT_CC_SLEEP ) )
# else
  else if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CC_SLEEP_PN ) || ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CHK_WUF_NOT_CC_SLEEP ) )
# endif /* ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON ) */
  { /* PN */
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CHK_WUF_CC_SLEEP; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  }
  else
  {
    /* MISRA QAC */
  }
#endif /* if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_CtrlSleepIndicated */



#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_TrcvNormalIndicated
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_TrcvNormalIndicated( P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_TransceiverModeIndication, CANTRCV_TRCVMODE_NORMAL received */

  if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SU_TRCV_NORMAL )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace..SPEC-11284 */
    /* \trace..SPEC-11296 */
  }
  else if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_TRCV_NORMAL )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_TRCV_STANDBY; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace..SPEC-11291 */
    /* \trace..SPEC-11379 */
    /* \trace..SPEC-11394 */
  }
  else
  {
    /* MISRA */ /* unexpected indication e.g. during transceiver initialization */
  }

} /* CanSM_TrcvNormalIndicated */
#endif /* ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */



#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_TrcvStandbyIndicatedAsExpected
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_TrcvStandbyIndicatedAsExpected( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_TransceiverModeIndication, CANTRCV_TRCVMODE_STANDBY received in state CANSM_SD_TRCV_STANDBY */

  /* Indicated As Expected
   * CanSM_CurrentState == CANSM_SD_TRCV_STANDBY
   * * if the transceiver mode stand by indication is caused by a CanSM request is already ensured * */
# if defined CANSM_TRCVSTANDBY_INDICATED_AT_PN_CHANNELS_AND_NON_PN_CHANNELS_MIXED
  if ( CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
# endif /* CANSM_TRCVSTANDBY_INDICATED_AT_PN_CHANNELS_AND_NON_PN_CHANNELS_MIXED */
  {

# if !defined CANSM_TRCVSTANDBY_NEVER_INDICATED_AT_PN_CHANNELS
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_SLEEP_PN; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# endif  /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG */
    /* \trace..SPEC-11354 */
    /* \trace..SPEC-11395 */

  }
# if defined CANSM_TRCVSTANDBY_INDICATED_AT_PN_CHANNELS_AND_NON_PN_CHANNELS_MIXED
  else
# endif /* CANSM_TRCVSTANDBY_INDICATED_AT_PN_CHANNELS_AND_NON_PN_CHANNELS_MIXED */
  {
# if !defined CANSM_TRCVSTANDBY_ONLY_INDICATED_AT_PN_CHANNELS
    CanSM_NoComReached( CanSM_CurrentChannelVarPtr );  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# endif /* ( not CANSM_TRCVSTANDBY_ONLY_INDICATED_AT_PN_CHANNELS  ) */
  }
  /* \trace..SPEC-11281 */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_TrcvStandbyIndicatedAsExpected  */
#endif /* ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */



/***********************************************************************************************************************
 *  FUNC CanSM_EvaluateComModeRequest
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
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_EvaluateComModeRequest( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: each CanSM_MainFunction */

  if (  ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode == COMM_FULL_COMMUNICATION ) && ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState > CANSM_S_SILENTCOM )   )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_TRCV_NORMAL; /* will be changed to CANSM_SU_CC_STOPPED in NWSM if Trcv is inactive on channel */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#else /* CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG */
    (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif /*  CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG */

  } /* COMM_FULL_COMMUNICATION */
  else if (  ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode == COMM_NO_COMMUNICATION ) && ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState <= CANSM_S_SILENTCOM )  ) /* check if ShutDown is already running; NoComReq and not on the way */
  { /* E_PRE_NO_COM  E_PRE_NOCOM */
    /* prepares shut down, executes the first step of the shut down sequence */
    CanSM_InitiateShutDownSequence( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  } /* COMM_NO_COMMUNICATION */
  else
  {
    /* MISRA */
  }

} /* CanSM_EvaluateComModeRequest */



/***********************************************************************************************************************
 *  FUNC CanSM_HandleBusOffInSilent
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_HandleBusOffInSilent( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: each CanSM_MainFunction */

  if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag == TRUE ) && ( ( (*CanSM_CurrentChannelVarPtr ).CanSM_CurrentState ) == CANSM_S_SILENTCOM ) )
  { /* BO in Silent */

    (void)CanIf_SetControllerMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_CS_STARTED );
    (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )
    (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime = CANSM_DELAY_TIMER_INACTIVE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */
#if ( CANSM_BUSOFF_END_INDICATION == STD_ON )
    (*CanSM_BusOffEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) ); /* J1939Nm_BusOffEnd */ /* SBSW_CANSM_BUS_OFF_END_INDICATION */
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */

  }

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_HandleBusOffInSilent */



/***********************************************************************************************************************
 *  FUNC CanSM_EvaluateMaxModeRequests
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_EvaluateMaxModeRequests( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: each CanSM_MainFunction, protected by AREA_1 */

  if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter > CanSM_GetModeRequestRepetitionMaxOfPCConfig() )
  {

#if ( CANSM_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG == STD_ON )
# if ( CANSM_ISDEF_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG == STD_ON )
    CanSM_Dem_ReportErrorEvent( CanSM_GetDemEventId_ModeRequest_OfChannelConfig( CanSM_CanNetworkIdx ), DEM_EVENT_STATUS_FAILED );
# else /* CANSM_ISDEF_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG */
    if ( CanSM_IsProdErrorDetect_ModeRequest_OfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
    {
      CanSM_Dem_ReportErrorEvent( CanSM_GetDemEventId_ModeRequest_OfChannelConfig( CanSM_CanNetworkIdx ), DEM_EVENT_STATUS_FAILED );
    }
#  if ( CANSM_DEV_ERROR_REPORT == STD_ON )
    else
    {
      (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT );
      /* \trace SPEC-807, SPEC-809 */
    }
#  endif /* CANSM_DEV_ERROR_REPORT */
# endif /* CANSM_ISDEF_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG */
#else /* ( CANSM_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG == STD_ON ) */
# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT );
    /* \trace SPEC-807, SPEC-809 */
# endif /* CANSM_DEV_ERROR_REPORT */
#endif /* ( CANSM_PRODERRORDETECT_MODEREQUEST_OFCHANNELCONFIG == STD_ON ) */


    (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter = 0; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    CanSM_InitiateShutDownSequence( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode = COMM_NO_COMMUNICATION; /* block vs. CanSM_RequestComMode */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace SPEC-11308, SPEC-11338, SPEC-11371, SPEC-11376, SPEC-11407, SPEC-11409, SPEC-47121  */
  } /* RepetitionMax */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanSM_EvaluateMaxModeRequests */



/***********************************************************************************************************************
 *  FUNC CanSM_TimerHandling
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_TimerHandling( P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: each CanSM_MainFunction, protected by AREA_1 */

  if ( (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer > CANSM_TIMER_EXPIRED )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer--; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer == CANSM_TIMER_EXPIRED ) &&
#if ( CANSM_ISDEF_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_OFF )
        ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState != CANSM_BO_BUS_OFF_CHECK ) &&
#endif /* ( CANSM_ISDEF_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_ON ) */
        ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState != CANSM_BO_TX_OFFLINE )  )
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter++; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
      if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CC_SLEEP_PN )
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CHK_WUF_NOT_CC_SLEEP; /* CANSM_SD_CHK_WUF */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }
#endif /* if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
    }
  } /* not  CANSM_TIMER_EXPIRED */

} /* CanSM_TimerHandling */



/***********************************************************************************************************************
 *  CanSM_HandleComModeRequest
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_HandleComModeRequest( ComM_ModeType CanSM_RequestedComMMode, CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_RequestComMode, valid */

#if (   (  ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) || ( CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG == STD_ON )  ) && ( CANSM_SWIFT_TX_TIMEOUT_RECOVERY == STD_OFF )   )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode >= CANSM_TX_TIMEOUT_EXCEPTION_RECEIVED )
  { /* TxTimeout handling force Transition to NoCom, postpone Request */
    (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode = (uint8)( CanSM_RequestedComMMode + CANSM_TX_TIMEOUT_EXCEPTION_RECEIVED ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace SPEC-656 */
  }
  else if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode != CanSM_RequestedComMMode )
#else
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode != CanSM_RequestedComMMode )
#endif /* ( ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) || ( CANSM_PARTIAL_NETWORK_WAKEUP_FILTEROFCHANNELCONFIG == STD_ON ) ) */
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode = CanSM_RequestedComMMode; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    /* \trace SPEC-654, SPEC-2181132 */

    SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_2(); /* MainFunction( ) ControllerModeIndication( ) TransceiverModeIndication( ) ClearTrcvWufFlagIndication( ) CheckTransceiverWakeFlagIndication( ) TxTimeoutException( ) SetEcuPassive( ) StartWakeupSources( ) StopWakeupSources( )  */

    if (   ( CanSM_RequestedComMMode == COMM_FULL_COMMUNICATION ) && (  ( (*CanSM_CurrentChannelVarPtr ).CanSM_CurrentState == CANSM_S_SILENTCOM )
#if !defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
          || ( (*CanSM_CurrentChannelVarPtr ).CanSM_CurrentState == CANSM_S_STARTWAKEUPSOURCES_SUCCESSFUL )
#endif /* !defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON */
          )   )
    { /* Execute transition from SILENT to FULL within RequestComMode */
      CanSM_FullComReached( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }
    else if ( ( CanSM_RequestedComMMode != COMM_FULL_COMMUNICATION ) && ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState & CANSM_S_NO_BUS_OFF ) == CANSM_S_NO_BUS_OFF ) ) /* Meta FullCom */ /* CANSM_S_FULLCOM CANSM_BO_BUS_OFF_CHECK CANSM_S_NO_BUS_OFF    CANSM_S_FULLCOM_ENSURED CANSM_BO_TX_OFFLINE  */ /* PRQA S 0715 2 */ /* MD_MSR_Dir1.1 */
    {
      CanSM_FullComToSilent( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      /* \trace..SPEC-11307 */
      /* \trace SPEC-11347 */
    } /* end if Transition Full To Silent */ /* else the Transition is PostPoned ( StartUp ) OR illegal ( NoCom, ShutDown ) */
    else
    {
      /* MISRA, transition postponed to MainFunc */
    }

    if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CANSM_NOBODY )
    { /* BswM state has been changed and has to be handled by MainFunction */
      (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_REQUESTCOMMODE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }

    SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_2();


    CanSM_CheckModeIndication( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr, CANSM_SID_REQUESTCOMMODE ); /* Function checks if mode has changed */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


  } /* end if No TxTimeout */
  else
  { /* TxTimeOutException active postpone ComModeRequests */
    /* MISRA QAC */
  }

} /* CanSM_HandleComModeRequest  */



/***********************************************************************************************************************
 *  CanSM_MapNetworkHandleToLocalIndex
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(CanSM_SizeOfChannelVarRecordType, CANSM_CODE) CanSM_MapNetworkHandleToLocalIndex( NetworkHandleType CanSM_NetworkHandle )
{ /* Context: CanSM_RequestComMode CanSM_GetCurrentComMode CanSM_PreventBusSleepAtStartUp CanSM_SetBaudrate CanSM_CheckBaudrate CanSM_ChangeBaudrate CanSM_TxTimeoutException CanSM_CheckBorLevel CanSM_StartWakeupSources CanSM_StopWakeupSources */

  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;

  /* lint -e442  -e440 */
  for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelConfigOfPCConfig(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
  {
    if ( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) == CanSM_NetworkHandle )
    {
      break; /* CanSM_NetworkHandle valid; found in configuration; stop searching, stop for-loop */
    } /* NetworkHandle index in list ==> NetworkHandle valid */
  }

  return (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx;

} /* CanSM_MapNetworkHandleToLocalIndex */



#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_MapTransceiverIdToLocalIndex
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(CanSM_SizeOfChannelVarRecordType, CANSM_CODE) CanSM_MapTransceiverIdToLocalIndex( uint8 CanSM_TransceiverId )
{  /* Context: CanSM_TransceiverModeIndication CanSM_ClearTrcvWufFlagIndication CanSM_CheckTransceiverWakeFlagIndication CanSM_ConfirmPnAvailability */
  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;

  /* lint -e442  -e440 */
  for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelConfigOfPCConfig(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
  {
    if ( CanSM_GetTransceiverIdOfChannelConfig( CanSM_CanNetworkIdx ) == CanSM_TransceiverId )
    {
      break; /* TransceiverId valid; found in configuration; stop searching, stop for-loop */
    } /* TransceiverId index in list ==> TransceiverId valid */
  }

  CANSM_DUMMY_STATEMENT( CanSM_TransceiverId ); /* might be unreferenced due to ComStackLib optimization */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx;

} /* CanSM_MapTransceiverIdToLocalIndex */
#endif /* ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */



/***********************************************************************************************************************
 *  CanSM_MapControllerIdToLocalIndex
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(CanSM_SizeOfChannelVarRecordType, CANSM_CODE) CanSM_MapControllerIdToLocalIndex( uint8 CanSM_ControllerId )
{ /* Context: CanSM_ControllerBusOff CanSM_ControllerModeIndication */
  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;

  /* lint -e442  -e440 */
  for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelConfigOfPCConfig(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
  {
    if ( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ) == CanSM_ControllerId )
    {
      break; /* ControllerId valid; found in configuration; stop searching, stop for-loop */
    } /* ControllerId index in list ==> TransceiverId valid */
  }

  return (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx;

} /* CanSM_MapControllerIdToLocalIndex */



/***********************************************************************************************************************
 * CanSM_BusOffIndicated
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
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_BusOffIndicated( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx )
{ /* Context: CanSM_BusOffIndicated */
  P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

  if ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter < CANSM_COUNTER_MAX_VALUE )
  { /* value greater 0 triggers transition to CANSM_BO_TX_OFFLINE in case of Ctrl STARTED indication */
    (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter++; /* further BO indication impossible until Ctrl Started and Tx Online */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  }

  (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag = TRUE; /* CREQ-367 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_3(); /* RequestComMode( ) ControllerBusOff( ) TxTimeoutException( ) */
  if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_BO_BUS_OFF_CHECK ) || ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_NO_BUS_OFF ) ) /* CANSM_S_FULLCOM_ENSURED  CANSM_S_NO_BUS_OFF */
  {

    CanSM_FullComToRestartController( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CANSM_NOBODY )
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_CONTROLLERBUSOFF; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }

  }
  SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_3();


  CanSM_CheckModeIndication( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr, CANSM_SID_CONTROLLERBUSOFF ); /* Function checks if mode has changed */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


#if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )
  (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime = 0; /* detect missing BusOffEndIndication in case of ComModeRequest */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_BusOffBeginIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ), &( (*CanSM_CurrentChannelVarPtr ).CanSM_TxOnlineDelayTime ) ); /* J1939Nm_GetBusOffDelay() */ /* SBSW_CANSM_GETBUSOFFDELAY_POINTERWRITEACCESS */ /* SBSW_CANSM_GETBUSOFFDELAY_INDICATION */
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */

} /* CanSM_BusOffIndicated */



#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  CanSM_RamCheckEnd
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
CANSM_LOCAL_INLINE FUNC(void, CANSM_CODE) CanSM_RamCheckEnd( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx )
{ /* Context: CanSM_Init or Mainfunc, NW SM, SD RAM check */

  P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );


  (*CanSM_CurrentChannelVarPtr).CanSM_RamCheckState = Appl_CanSM_RamCheckFinished( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx )  ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

  switch ( (*CanSM_CurrentChannelVarPtr).CanSM_RamCheckState )
  {
    case CANSM_ENABLE_COMMUNICATION:
    {
      CanIf_RamCheckEnableController( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ) );
      (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_SLEEP; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

      break;
    }
    case CANSM_DISABLE_COMMUNICATION:
    {
      CanSM_NoComReached( CanSM_CurrentChannelVarPtr );  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      break;
    }
    case CANSM_ENABLE_COMMUNICATION_REPEAT:
    {
      CanIf_RamCheckEnableController( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ) );
      /* enable repetition of state  CANSM_SD_CHECK_RAM next Mainfunction see fall through  */
    } /* fall through */ /* no break */
    default: /* PRQA S 2003 */ /* MD_CANSM_Rule16.3 */
    { /* case CANSM_DISABLE_COMMUNICATION_REPEAT: or illegal value */
      /* enable repetition of state  CANSM_SD_CHECK_RAM next Mainfunction */
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_TIMER_EXPIRED; /* retry next cycle */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      break;
    }
  }

} /* CanSM_RamCheckEnd */
#endif /* CANSM_EXTENDED_RAM_CHECK  */


/***********************************************************************************************************************
 *  CanSM_FullComReached
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
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_FullComReached( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: NWSM; CANSM_BO_TX_OFFLINE timer elapsed, CanSM_CtrlStartedIndicated after startup resp. no BOR CanSM_HandleComModeRequest; from SILENT to FULL  */
  /* E_FULLCOM */ /* E_FULL_COM E_FULLCOM E_BR_END_FULL_COM E_CHANGE_BR_END E_CHANGE_BR_END_FULL_COM E_TX_ON E_SILENT_TO_FULL_COM */
  /* \trace SPEC-11319, SPEC-11417 */
  /* \trace SPEC-11293, SPEC-11370 */
  /* \trace SPEC-11433, SPEC-11435, SPEC-2181148, SPEC-47112  */
  /* \trace SPEC-11275, SPEC-11297, SPEC-2181377 */



  if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode == COMM_FULL_COMMUNICATION )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode &= CANSM_CLEAR_TX_TIMEOUT_EXCEPTION_FLAG; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


    if ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag == FALSE )
    {
      CanSM_StartControllerToBusOffCheck( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }
    else
    { /*  (currently un-handled) BO occurred in silent mode, Start BO recovery handling */
      CanSM_FullComToRestartController( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    } /* end if BO In Silent, start recovery */

  }
  else
  { /* FullToSilent E_FULL_TO_SILENT_COM */ /* Silent has been requested during the transition from NoCom To FullCom */
    CanSM_FullComToSilent( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  }

} /* end Func CanSM_FullComReached */



/***********************************************************************************************************************
 *  CanSM_FullComToSilent
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_FullComToSilent( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_RequestComMode, CanSM_HandleComModeRequest; Meta state FullCom CanSM_CtrlStartedIndicated, CanSM_FullComReached pending Silent request */
  /* FullToSilent E_FULL_TO_SILENT_COM */
  /* \trace..SPEC-11310 */
  /* \trace..SPEC-11383 */
  (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_SILENT_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_SILENT_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  /* \trace..SPEC-11401 */

#if ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_ON )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag == TRUE )
  {
    (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    (*CanSM_TxTimeoutExceptionEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) ); /* SBSW_CANSM_TX_TIMEOUT_END_INDICATION */
  }
#endif /* ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_OFF ) */

  (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_RX_ONLINE );  /* CANIF_SET_ONLINE explicitly demanded by SWS but senseless. As compromise set RxOnline, avoids problems with passive mode resp. saves IR lock */
  (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_TX_OFFLINE );

  (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode &= CANSM_CLEAR_TX_TIMEOUT_EXCEPTION_FLAG; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_S_SILENTCOM; /* CREQ-366 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* Stop timer e.g. if ComMRequest during CHECK or TxOffline */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

#if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )
  if ( (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime != CANSM_DELAY_TIMER_INACTIVE )
  { /* BusOffBeginIndication has been made, eventually BusOffEndIndication missing */
    (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime = CANSM_DELAY_TIMER_INACTIVE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# if ( CANSM_BUSOFF_END_INDICATION == STD_ON )
    (*CanSM_BusOffEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) ); /* J1939Nm_BusOffEnd(); */  /* SBSW_CANSM_BUS_OFF_END_INDICATION */
# endif /* ( CANSM_BUSOFF_END_INDICATION == STD_ON ) */
  }
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */

  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* end Func CanSM_FullComToSilent */



/***********************************************************************************************************************
 *  CanSM_NoComReached
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_NoComReached( P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_CheckTransceiverWakeFlagIndication; state CANSM_SD_CHK_WUF_CC_SLEEP CanSM_CtrlSleepIndicated; noPN noTrcv CanSM_TrcvStandbyIndicatedAsExpected; noPN */
  /* E_NOCOM */
  (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter = 0; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode &= CANSM_CLEAR_TX_TIMEOUT_EXCEPTION_FLAG; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_S_NOCOM; /* CREQ-365 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  (*CanSM_CurrentChannelVarPtr).CanSM_EnfroceComModeIndication = TRUE; /* FORCE NoCom Indication */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
  /* \trace..SPEC-11340 */
  /* \trace..SPEC-2181146 */

} /* end Func CanSM_NoComReached */


/***********************************************************************************************************************
 *  CanSM_NetworkStatemachine
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
CANSM_LOCAL FUNC(void, CANSM_CODE) CanSM_NetworkStatemachine( CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx, P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr )
{ /* Context: CanSM_MainFunction; CANSM_TIMER_EXPIRED, CANSM_S_INTERIM_STATE_DETECTED resp. ComModeChanged; CanSM_StartWakeupSources; CanSM_StopWakeupSources;  CanSM_Init; CanSM_UninitToNoCom  */
  /* \trace SPEC-11282, SPEC-11292, SPEC-11301, SPEC-11306, SPEC-11315, SPEC-11318, SPEC-11326, SPEC-11334, SPEC-11343, SPEC-11356, SPEC-11385, SPEC-11390, SPEC-11423, SPEC-11427, SPEC-11429, SPEC-11439, SPEC-47123 */

  uint8 CanSM_RetValTriggerFunc = E_OK;
  uint8 CanSM_OldState;
#if ( CANSM_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_ON )
  CanIf_NotifStatusType CanSM_TxNotificationStatus;
#endif

  do
  {
    CanSM_OldState = (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState;

    (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CanSM_GetModeRequestRepetitionTimeOfPCConfig(); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    switch ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState )
    {
      /* StartUp State machine */
#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
      case CANSM_SU_TRCV_NORMAL:
      {
        /* \trace..SPEC-11355 */

        /* \trace SPEC-11295 */
# if defined CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF
        if ( CanSM_IsTransceiver_Channel_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
# endif /*   CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF  */
        {
          /* already checked above; if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )  */
          CanSM_RetValTriggerFunc = CanIf_SetTrcvMode( CanSM_GetTransceiverIdOfChannelConfig( CanSM_CanNetworkIdx ), CANTRCV_TRCVMODE_NORMAL );
          /* already checked see below;    endif   CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG */
        } /* end if Trcv active on current channel */
# if defined CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF
        else
# endif /*   CANSM_TRANSCEIVER_HANDLING_MIXED_ON_AND_OFF  */
        {
# if !defined CANSM_TRANSCEIVER_HANDLING_ALWAYS_ON /* sometimes or ever OFF */
          (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# endif /*   CANSM_TRANSCEIVER_HANDLING_ALWAYS_ON  */
        }

        break;
      } /* end case CANSM_SU_TRCV_NORMAL CanSM_CurrentState */
#endif /* if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */
      /*  the case CANSM_SU_CC_STOPPED has been shifted below */
      case CANSM_SU_CC_STARTED:
      {

        CanSM_RetValTriggerFunc = CanIf_SetControllerMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_CS_STARTED );
        if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState != CANSM_SU_CC_STARTED ) /* PRQA S 2992, 2996, 2147 */ /* MD_CANSM_Rule2.2_2982, MD_CANSM_Rule2.2_2996, MD_CANSM_Rule14.3 */
        { /* Indication has been received; negative return value irrelevant */
          CanSM_RetValTriggerFunc = E_OK;  /* PRQA S 2880 */ /* MD_CANSM_Rule2.1 */
          CanSM_OldState = (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState; /* Avoid repetition */ /* final state (of sequence) which is handled by NWSM */
        }
        (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

        break;
      } /* end case CANSM_SU_CC_STARTED: */
      /* ShutDown State machine */
#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
      case CANSM_SD_PN_CLEAR_WUF:
      {
        /* \trace..SPEC-11345 */

        CanSM_RetValTriggerFunc = CanIf_ClearTrcvWufFlag( CanSM_GetTransceiverIdOfChannelConfig( CanSM_CanNetworkIdx ) );

        break;
      } /* end case CANSM_SD_PN_CLEAR_WUF: */
#endif /* if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
      case CANSM_SU_CC_STOPPED: /* PRQA S 2003 */ /* MD_CANSM_Rule16.3 */
      {
        CanSM_RetValTriggerFunc = CanIf_SetControllerMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_CS_STOPPED );
        (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

        break;
      } /* end case CANSM_SU_CC_STOPPED: */

#if !defined ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON )
      case CANSM_SD_CC_SLEEP:
#endif /* ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON ) */
#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
      case CANSM_SD_CC_SLEEP_PN: /* PRQA S 2003 */ /* MD_CANSM_Rule16.3 */ /* BullsEye; if overall report blames unapproachable, it is a lie */
#endif  /* not always OFF ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
      {

        CanSM_RetValTriggerFunc = CanIf_SetControllerMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_CS_SLEEP );


        break;
      } /* end case CANSM_SD_CC_SLEEP: */
#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
      case CANSM_SD_TRCV_NORMAL: /* PRQA S 2003 */ /* MD_CANSM_Rule16.3 */
      {
        CanSM_RetValTriggerFunc = CanIf_SetTrcvMode( CanSM_GetTransceiverIdOfChannelConfig( CanSM_CanNetworkIdx ), CANTRCV_TRCVMODE_NORMAL );

        break;
      } /* end case CANSM_SD_TRCV_NORMAL */
      case CANSM_SD_TRCV_STANDBY: /* PRQA S 2003 */ /* MD_CANSM_Rule16.3 */
      {
        CanSM_RetValTriggerFunc = CanIf_SetTrcvMode( CanSM_GetTransceiverIdOfChannelConfig( CanSM_CanNetworkIdx ), CANTRCV_TRCVMODE_STANDBY );

        break;
      } /* end case CANSM_SD_TRCV_STANDBY */
# if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )

      case CANSM_SD_CHK_WUF_CC_SLEEP: /* fall through */ /* no break */
      case CANSM_SD_CHK_WUF_NOT_CC_SLEEP:
      {
        CanSM_RetValTriggerFunc = CanIf_CheckTrcvWakeFlag( CanSM_GetTransceiverIdOfChannelConfig( CanSM_CanNetworkIdx ) );

        break;
      } /* end case CANSM_SD_CHK_WUF_CC_SLEEP: CANSM_SD_CHK_WUF_NOT_CC_SLEEP: */
# endif /* if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */
#endif /* if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */
      case CANSM_BO_TX_OFFLINE:
      {
#if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )
        (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime = CANSM_DELAY_TIMER_INACTIVE; /* BusOffEndIndication not missing */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */
#if ( CANSM_BUSOFF_END_INDICATION == STD_ON )
        (*CanSM_BusOffEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) ); /* J1939Nm_BusOffEnd(); */  /* SBSW_CANSM_BUS_OFF_END_INDICATION */
#endif /* ( CANSM_BUSOFF_END_INDICATION == STD_ON ) */

        CanSM_FullComReached( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        CanSM_OldState = (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState; /* Avoid repetition */
        break;
      } /* end case CANSM_SD_CHK_WUF_CC_SLEEP: CANSM_SD_CHK_WUF_NOT_CC_SLEEP: */
      case CANSM_BO_BUS_OFF_CHECK:
      {
#if defined CANSM_BOR_TX_CONFIRMATION_POLLING_ALWAYS_ON
        CanSM_TxNotificationStatus = CanIf_GetTxConfirmationState( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ) );
        /* \trace..SPEC-11305 */

        if ( CanSM_TxNotificationStatus == CANIF_TX_RX_NOTIFICATION )
        {
          CanSM_BusOffCheckToNoBusOff( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        }
#elif ( CANSM_BOR_TX_CONFIRMATION_POLLINGOFCHANNELCONFIG == STD_OFF )
        CanSM_BusOffCheckToNoBusOff( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#else /* Some channels with BOR_TX_CONFIRMATION_POLLING     Some channels without TxPolling  */
        if ( CanSM_IsBor_Tx_Confirmation_PollingOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
        {
          CanSM_TxNotificationStatus = CanIf_GetTxConfirmationState( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ) );
        }
        else
        {
          CanSM_TxNotificationStatus = CANIF_TX_RX_NOTIFICATION;
        }

        if ( CanSM_TxNotificationStatus == CANIF_TX_RX_NOTIFICATION )
        {
          CanSM_BusOffCheckToNoBusOff( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        }
#endif /* BOR_TX_CONFIRMATION_POLLING */

        (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* corrects the repetition time, re-triggers SM if TxPolling failed */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        CanSM_OldState = (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState; /* Avoid repetition */

        break;
      } /* end case CANSM_BO_BUS_OFF_CHECK */
#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
      case CANSM_SD_CHECK_RAM:
      {
        Appl_CanSM_RamCheckStart( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) );

        CanIf_RamCheckExecute( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ) ); /* potential implicit calls of CanSM_RamCheckErrorIndication() with adaptation of CanSM_RamCheckState */

        CanSM_RamCheckEnd( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx );

        break;
      } /* end case CANSM_SD_CHECK_RAM */
#endif /* CANSM_EXTENDED_RAM_CHECK  */
      default: /* PRQA S 2003 */ /* MD_CANSM_Rule16.3 */
      { /* case CANSM_SD_CC_STOPPED */
        /* \trace..SPEC-11361 */
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4(); /* CanIR BO */

        if ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag == TRUE )
        { /* BO in Silent */
          (void)CanIf_SetControllerMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_CS_STARTED );
          (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */ /* PRQA S 2982 */ /* MD_CANSM_Rule2.2_2982 */
          (*CanSM_CurrentChannelVarPtr).CanSM_BusOffFlag = FALSE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        } /* end if  BO in Silent */

        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4(); /* CanIR BO */

#if ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON )
        if ( (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime != CANSM_DELAY_TIMER_INACTIVE )
        { /* BusOffEndIndication missing */
          (*CanSM_CurrentChannelVarPtr).CanSM_TxOnlineDelayTime = CANSM_DELAY_TIMER_INACTIVE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# if ( CANSM_BUSOFF_END_INDICATION == STD_ON )
          (*CanSM_BusOffEndIndicationFctPtr)( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) ); /* J1939Nm_BusOffEnd(); */  /* SBSW_CANSM_BUS_OFF_END_INDICATION */
# endif /* ( CANSM_BUSOFF_END_INDICATION == STD_ON ) */
        }
#endif /* ( CANSM_BUSOFF_BEGIN_INDICATION == STD_ON ) */

        CanSM_RetValTriggerFunc = CanIf_SetControllerMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_CS_STOPPED );
        (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter = CANSM_BOR_NONE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        break;
      } /* end case CANSM_SD_CC_STOPPED: */
    } /* end switch      (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState */

    if ( CanSM_RetValTriggerFunc != E_OK )
    {
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* Set Trcv,Ctrl fail, stop timer to retry next cycle */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter++; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
    }
    /* \trace SPEC-11278, SPEC-11312, SPEC-11317, SPEC-11346, SPEC-11350, SPEC-11351, SPEC-11363, SPEC-11366, SPEC-11437, SPEC-11440, SPEC-2181158, SPEC-47111, SPEC-47115 */
    /* \trace SPEC-11279, SPEC-11300, SPEC-11302, SPEC-11314, SPEC-11408, SPEC-11430, SPEC-2181382, SPEC-2181386, SPEC-2181391 */
    /* \trace SPEC-11278, SPEC-11312, SPEC-11317, SPEC-11346, SPEC-11350, SPEC-11351, SPEC-11363, SPEC-11366, SPEC-11437, SPEC-11440, SPEC-47111, SPEC-47115 */
    /* \trace SPEC-11290, SPEC-11321, SPEC-11325, SPEC-11330, SPEC-11332, SPEC-11344, SPEC-11349, SPEC-11368, SPEC-11369, SPEC-11388, SPEC-11404, SPEC-11411, SPEC-11415, SPEC-11419, SPEC-11421, SPEC-11426, SPEC-11438, SPEC-2181390, SPEC-47116, SPEC-47119 */



    if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_NOCOM )
    {
      CanSM_RetValTriggerFunc = E_OK;
      (*CanSM_CurrentChannelVarPtr).CanSM_ModeRequestRepetitionCounter = 0; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* Set Trcv,Ctrl fail, stop timer to retry next cycle */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      CanSM_OldState = (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState; /* Avoid repetition */
    }

  }while ( CanSM_OldState != (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState );



  CANSM_DUMMY_STATEMENT( CanSM_CanNetworkIdx );  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* end  Func CanSM_NetworkStatemachine */  /* PRQA S 6030, 6050 */  /* MD_MSR_STCYC, MD_MSR_STCAL */



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  CanSM_InitMemory
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_InitMemory(void)
{
#if (  ( CANSM_PREVENT_BUSSLEEP_AT_STARTUP == STD_ON ) && ( CANSM_USE_INIT_POINTER == STD_OFF )  )
  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;

  /* lint -e442  -e440 */
  for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CANSM_ENABLE_SET_BUS_SLEEP_ARRAY_MAX_SIZE; CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
  {
    CanSM_EnableSetBusSleep[ CanSM_CanNetworkIdx ] = CANSM_SET_BUS_SLEEP_MODE; /* CanSM_PreventBusSleepAtStartUp() */ /* SBSW_CANSM_ENABLE_SET_BUS_SLEEP_ARRAY */
  } /* end for ( each CAN channel index ) */
#endif /* CANSM_PREVENT_BUSSLEEP_AT_STARTUP CANSM_USE_INIT_POINTER */

  /* blocks the calling of API function ( except CanSM_Init ) */
  CanSM_IsInitialized = CANSM_INITFUNCTION_NOT_CALLED;

} /* end Func CanSM_InitMemory() */


/*********************************************************************************************************************
 * CanSM_Init
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
FUNC(void, CANSM_CODE) CanSM_PreInit( CONSTP2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_CONST ) ConfigPtr ) /* PRQA S 1505 */ /*MD_MSR_Rule8.7 */
{ /* \trace SPEC-834 */
  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

#if ( CANSM_USE_INIT_POINTER == STD_OFF )
  CANSM_DUMMY_STATEMENT_CONST(ConfigPtr); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#else /* CANSM_USE_INIT_POINTER */

  CanSM_ConfigDataPtr = ConfigPtr; /* assignment needed by HasChannelConfig() */

  if ( CanSM_ConfigDataPtr == NULL_PTR )
  {
    CanSM_DetErrorId = CANSM_E_PARAM_POINTER;
    /* \trace SPEC-828 */
  }
  else if ( CanSM_HasChannelConfig() )
#endif /* (  CANSM_USE_INIT_POINTER ) */
  {

    if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
    {
      /* lint -e442 -e440 */
      for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelVarRecord(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
      {

        CanSM_InitializeVariables( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx );
#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
        Appl_CanSM_RamCheckStart( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) );
#endif /* CANSM_EXTENDED_RAM_CHECK  */

      } /* end for ( each CAN channel index ) */

      CanSM_IsInitialized = CANSM_PRE_INITIALIZED;

    } /* CANSM_PRE_INITIALIZED */
  }
#if ( CANSM_USE_INIT_POINTER != STD_OFF )
  else
  {
    /* MISRA QAC */ /* inactive configuration without channels, valid for PBS */
  }
#endif /* ( CANSM_USE_INIT_POINTER != STD_OFF ) */

#if (  ( CANSM_DEV_ERROR_REPORT == STD_ON ) && ( CANSM_USE_INIT_POINTER == STD_ON )  )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_INIT, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
#else /* CANSM_DEV_ERROR_REPORT CANSM_USE_INIT_POINTER */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* CANSM_DEV_ERROR_REPORT CANSM_USE_INIT_POINTER */


} /* End Func CanSM_PreInit() */



/*********************************************************************************************************************
 * CanSM_Init
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_Init( CONSTP2CONST( CanSM_ConfigType, AUTOMATIC, CANSM_CONST ) ConfigPtr )
{ /* \trace SPEC-834, SPEC-47130 */
  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;

  CanSM_PreInit( ConfigPtr ); /* SBSW_CANSM_CFG_POINTER */ /* CanSM_InitializeVariables */ /* function call is redundant if CanSM_PreInit() is used actually and has no effect */

  if ( CanSM_IsInitialized == CANSM_PRE_INITIALIZED )
  {
    CanSM_IsInitialized = CANSM_INITFUNCTION_RUNNING;

    /* lint -e442 -e440 */
    for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelVarRecord(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
    {

      CanSM_UninitToNoCom( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx );

    } /* end for ( each CAN channel index ) */

    CanSM_IsInitialized = CANSM_INITFUNCTION_FINISHED;
  } /* CANSM_PRE_INITIALIZED */

} /* End Func CanSM_Init() */



/***********************************************************************************************************************
 *  CanSM_MainFunction
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
FUNC(void, CANSM_CODE) CanSM_MainFunction( void )
{ /* \trace SPEC-853 */
  P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr;
  CanSM_ChannelVarRecordIterType CanSM_CanNetworkIdx;

  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_FINISHED )
  {

    /* \trace SPEC-11386 */
    /* lint -e442 -e440 */
    for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelVarRecord(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
    {
      CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      CanSM_EvaluateComModeRequest( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

      SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_1(); /* RequestComMode( ) StartWakeupSources( ) StopWakeupSources( ) ControllerBusOff( ) TxTimeoutException( ) SetEcuPassive( )  */

      if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CANSM_NOBODY )
      { /* BswM state has been changed and has to be handled by MainFunction */
        (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_MAINFUNCTION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }

      CanSM_HandleBusOffInSilent( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      CanSM_EvaluateMaxModeRequests( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      CanSM_TimerHandling( CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

      SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_1();

      SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_1(); /* RequestComMode( ) StartWakeupSources( ) StopWakeupSources( ) ControllerBusOff( ) TxTimeoutException( ) SetEcuPassive( )  */
      if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer == CANSM_TIMER_EXPIRED ) && ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState & CANSM_S_INTERIM_STATE_FILTER ) >= CANSM_S_INTERIM_STATE_DETECTED ) )
      {

        CanSM_NetworkStatemachine( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

      }
      SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_1();

      CanSM_CheckModeIndication( (CanSM_SizeOfChannelVarRecordType)CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr, CANSM_SID_MAINFUNCTION ); /* Function checks if mode has changed */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    } /* end for ( CanNetworkIdx ) each CanSM network */

  } /* no error detected */


} /* end Func CanSM_MainFunction() */ /* PRQA S 6050 */  /* MD_MSR_STCAL */


/***********************************************************************************************************************
 *  CanSM_RequestComMode
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_RequestComMode( NetworkHandleType CanSM_NetworkHandle, ComM_ModeType CanSM_RequestedComMMode )
{ /* \trace SPEC-819 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  Std_ReturnType CanSM_StdReturnValue;

  /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  CanSM_StdReturnValue = E_NOT_OK;
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-11287 */ /* \trace SPEC-829 */
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );
    /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
      /* \trace SPEC-655 */ /* \trace SPEC-830 */ /* \trace SPEC-817 */
    }
    else
#endif /* CANSM_DEV_ERROR_DETECT  */
    {
      /* \trace SPEC-823 */
      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
      if (  ( CanSM_RequestedComMMode != COMM_NO_COMMUNICATION ) && ( CanSM_RequestedComMMode != COMM_FULL_COMMUNICATION ) && ( CanSM_RequestedComMMode != COMM_SILENT_COMMUNICATION )  )
      { /*   Request denied because out of value range */
        CanSM_DetErrorId = CANSM_E_INVALID_COMM_REQUEST;
        /* \trace SPEC-654 */

      }
      else if ( ( CanSM_RequestedComMMode == COMM_SILENT_COMMUNICATION ) && ( ( (*CanSM_CurrentChannelVarPtr ).CanSM_CurrentState ) > CANSM_S_SILENTCOM ) )
      { /* Request silent in state NoCom OR Silent, Request denied */
        CanSM_DetErrorId = CANSM_E_INVALID_COMM_REQUEST;
        /* \trace SPEC-820 */ /* \trace SPEC-825 */
      }
      else
#endif /* CANSM_DEV_ERROR_DETECT  */
      {
        CanSM_StdReturnValue = E_OK;

        CanSM_HandleComModeRequest( CanSM_RequestedComMMode, CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        /* \trace SPEC-826 */
        /* \trace..SPEC-11294 */
        /* \trace..SPEC-11406 */
        /* \trace..SPEC-11418 */

      } /* end if valid ComModeRequest */

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

#if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_REQUESTCOMMODE, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
#else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* end Func CanSM_RequestComMode() */ /* PRQA S 6030 */ /* MD_MSR_STCYC */



/***********************************************************************************************************************
 *  CanSM_GetCurrentComMode
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_GetCurrentComMode( NetworkHandleType CanSM_NetworkHandle, P2VAR( ComM_ModeType, AUTOMATIC, CANSM_APPL_VAR ) CanSM_ComMModePtr )
{ /* \trace SPEC-837 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  Std_ReturnType CanSM_StdReturnValue;

  /* \trace SPEC-691 */
  /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  CanSM_StdReturnValue = E_NOT_OK;
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-836 */
  }
  else if ( CanSM_ComMModePtr == NULL_PTR )
  {
    CanSM_DetErrorId = CANSM_E_PARAM_POINTER;
    /* \trace SPEC-840 */
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );
    /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
      /* \trace SPEC-835 */
      /* \trace SPEC-841 */
    }
    else
#endif /* CANSM_DEV_ERROR_DETECT  */
    {
      /* \trace SPEC-838 */

      CanSM_StdReturnValue = E_OK;
      *CanSM_ComMModePtr   = CanSM_GetChannelVarRecord( CanSM_CanNetworkIdx ).CanSM_IndicatedComMode; /* SBSW_CANSM_GETCURRENTCOMMODE_POINTERWRITEACCESS */
      /* \trace SPEC-839 */
    } /* NetworkHandle index in list */
  } /* no error detected */

#if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_GETCURRENTCOMMODE, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
#else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* end Func CanSM_GetCurrentComMode() */



#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  CanSM_RamCheckStatus
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CANSM_CODE) CanSM_RamCheckStatus( NetworkHandleType CanSM_NetworkHandle )
{
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  Std_ReturnType CanSM_StdReturnValue;

#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  CanSM_StdReturnValue = E_NOT_OK;
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
#endif /* CANSM_DEV_ERROR_DETECT  */
    {

      CanSM_StdReturnValue = CanSM_GetChannelVarRecord( CanSM_CanNetworkIdx ).CanSM_RamCheckState;
    } /* NetworkHandle index in list */
  } /* no error detected */

#if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_RAMCHECKSTATUS, CanSM_DetErrorId );
  }
#else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* end Func CanSM_RamCheckStatus() */
#endif /* CANSM_EXTENDED_RAM_CHECK  */



/***********************************************************************************************************************
 *  CanSM_ControllerBusOff
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_ControllerBusOff( uint8 CanSM_ControllerId )
{ /* \trace SPEC-843 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-844 */
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapControllerIdToLocalIndex( CanSM_ControllerId );
    /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_CONTROLLER;
      /* \trace SPEC-845 */
    }
    else
#endif /* CANSM_DEV_ERROR_DETECT  */
    {

      CanSM_BusOffIndicated( CanSM_CanNetworkIdx );
      /* \trace SPEC-842 */
      /* \trace..SPEC-11398 */
      /* \trace..SPEC-2181140 */
    } /* ControllerId valid; found in configuration */

  } /* no error detected */

#if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CONTROLLERBUSOFF, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PClint: not accessed, not used. GHS: was set but never used */ /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* end Func CanSM_ControllerBusOff() */



#if ( CANSM_ECU_PASSIVE_MODE == STD_ON )
/***********************************************************************************************************************
 *  CanSM_SetEcuPassive
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
/* \trace..SPEC-2181318 */
FUNC(void, CANSM_CODE) CanSM_SetEcuPassive( boolean CanSM_TxOfflineActive )
{
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;

  if ( CanSM_EcuPassiveMode != CanSM_TxOfflineActive )
  {
    CanSM_EcuPassiveMode = CanSM_TxOfflineActive;
    /* \trace SPEC-2181272 */


    /* lint -e442  -e440 */
    for ( CanSM_CanNetworkIdx = 0; CanSM_CanNetworkIdx < CanSM_GetSizeOfChannelVarRecord(); CanSM_CanNetworkIdx++ ) /* lint +e442 +e440 */
    {
      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_5(); /* RequestComMode MainFunction */
      if ( ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_FULLCOM_ENSURED ) || ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_BO_BUS_OFF_CHECK ) ) )
      { /* BOR SM not running a recovery, State IS ONLINE */

        if ( CanSM_EcuPassiveMode == TRUE )
        { /* Activate ECU passive mode immediately */
          (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_TX_OFFLINE_ACTIVE );
          /* \trace..SPEC-2181273 */

        }
        else
        { /* DeActivate ECU passive mode immediately */
          (void)CanIf_SetPduMode( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CANIF_SET_TX_ONLINE );
          /* \trace..SPEC-2181274 */

        }

      } /* end if full Com && BOR SM not running a recovery */
      SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_5();

    } /* end for ( each CAN channel index ) */

  } /* Request toggled */

} /* end CanSM_SetEcuPassive() */
#endif /* CANSM_ECU_PASSIVE_MODE == STD_ON  */



#if ( CANSM_PREVENT_BUSSLEEP_AT_STARTUP == STD_ON )
/*********************************************************************************************************************
 *  CanSM_PreventBusSleepAtStartUp
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CANSM_CODE) CanSM_PreventBusSleepAtStartUp( NetworkHandleType CanSM_NetworkHandle )
{
  Std_ReturnType CanSM_StdReturnValue;

# if ( CANSM_USE_INIT_POINTER == STD_OFF )
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
#  if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  CanSM_StdReturnValue = E_NOT_OK;
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_INITIALIZED;
  }
  else
#  endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );
    /* \trace SPEC-812, SPEC-811 */
#  if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CANSM_ENABLE_SET_BUS_SLEEP_ARRAY_MAX_SIZE )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
#  endif /* CANSM_DEV_ERROR_DETECT  */
    {

      CanSM_EnableSetBusSleep[ CanSM_CanNetworkIdx ] = CANSM_PREVENT_BUS_SLEEP_MODE; /* SBSW_CANSM_ENABLE_SET_BUS_SLEEP_ARRAY */
      CanSM_StdReturnValue = E_OK;

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

#  if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_PREVENTBUSSLEEPATSTARTUP, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
#  else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif /* CANSM_DEV_ERROR_REPORT */

# else /* CANSM_USE_INIT_POINTER */
  CANSM_DUMMY_STATEMENT( CanSM_NetworkHandle ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CanSM_StdReturnValue = E_NOT_OK;
# endif /* CANSM_USE_INIT_POINTER */

  return CanSM_StdReturnValue;

} /* end CanSM_PreventBusSleepAtStartUp() */
#endif /* ( CANSM_PREVENT_BUSSLEEP_AT_STARTUP == STD_ON ) */



#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  CanSM_RamCheckEnableMailbox
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_RamCheckEnableMailbox( NetworkHandleType CanSM_NetworkHandle, Can_HwHandleType CanSM_MailBoxHandle )
{ /* Context: CanSM_ControllerModeIndication, CANIF_CS_STOPPED received */

  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      CanIf_RamCheckEnableMailbox( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CanSM_MailBoxHandle );

    } /* CanSM_ControllerId index in list */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_RAMCHECKENABLEMAILBOX, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* CanSM_RamCheckEnableMailbox */
#endif /* CANSM_EXTENDED_RAM_CHECK  */


#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  CanSM_RamCheckCorruptMailbox
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_RamCheckCorruptMailbox( uint8 CanSM_ControllerId, Can_HwHandleType CanSM_MailBoxHandle )
{ /* Context: CanSM_ControllerModeIndication, CANIF_CS_STOPPED received */

  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapControllerIdToLocalIndex( CanSM_ControllerId );
    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_CONTROLLER;
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      Appl_CanSM_RamCheckCorruptMailbox( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ), CanSM_MailBoxHandle );

    } /* CanSM_ControllerId index in list */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_RAMCHECKCORRUPTMAILBOX, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* CanSM_RamCheckCorruptMailbox */
#endif /* CANSM_EXTENDED_RAM_CHECK  */


#if( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  CanSM_RamCheckCorruptController
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_RamCheckCorruptController( uint8 CanSM_ControllerId )
{ /* Context: CanSM_ControllerModeIndication, CANIF_CS_STOPPED received */

  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapControllerIdToLocalIndex( CanSM_ControllerId );
    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_CONTROLLER;
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      Appl_CanSM_RamCheckCorruptController( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) );

    } /* CanSM_ControllerId index in list */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_RAMCHECKCORRUPTCONTROLLER, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* CanSM_RamCheckCorruptController */
#endif /* CANSM_EXTENDED_RAM_CHECK  */




/***********************************************************************************************************************
 *  CanSM_ControllerModeIndication
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
FUNC(void, CANSM_CODE) CanSM_ControllerModeIndication( uint8 CanSM_ControllerId, CanIf_ControllerModeType CanSM_ControllerMode )
{ /* \trace SPEC-847 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-848 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapControllerIdToLocalIndex( CanSM_ControllerId );
    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_CONTROLLER;
      /* \trace SPEC-846 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_4(); /* CanIR BO */

      if ( CanSM_ControllerMode == CANIF_CS_STOPPED )
      {
        CanSM_CtrlStoppedIndicated( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      } /* end if CanIf CC CANIF_CS_STOPPED */
      else if ( CanSM_ControllerMode == CANIF_CS_SLEEP )
      {
        CanSM_CtrlSleepIndicated( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      } /* end if CanIf CC CANIF_CS_SLEEP */
      else if ( ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SU_CC_STARTED ) && ( CanSM_ControllerMode == CANIF_CS_STARTED ) )
      {
        CanSM_CtrlStartedIndicated( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      } /* end if CanIf CC CANIF_CS_STARTED */
      else
      {
        /* MISRA QAC */
      }


      if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CANSM_NOBODY ) /* PRQA S 0715 4 */ /* MD_MSR_Dir1.1 */
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_CONTROLLERMODEINDICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        /* EXCLUSIVE_AREA_4 */
      }

      SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_4();


      CanSM_CheckModeIndication( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr, CANSM_SID_CONTROLLERMODEINDICATION ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    } /* CanSM_ControllerId index in list */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CONTROLLERMODEINDICATION, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* end Func CanSM_ControllerModeIndication */ /* PRQA S 6050, 6080 */ /* MD_MSR_STCAL, MD_MSR_STMIF */



#if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_TransceiverModeIndication
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_TransceiverModeIndication( uint8 CanSM_TransceiverId, CanTrcv_TrcvModeType CanSM_TransceiverMode )
{ /* \trace SPEC-11280 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-850 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapTransceiverIdToLocalIndex( CanSM_TransceiverId );
    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_TRANSCEIVER;
      /* \trace SPEC-849 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if ( CanSM_TransceiverMode == CANTRCV_TRCVMODE_NORMAL )
      {
        CanSM_TrcvNormalIndicated( CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }
      else if ( ( CanSM_TransceiverMode == CANTRCV_TRCVMODE_STANDBY ) && ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_TRCV_STANDBY ) )
      {
        CanSM_TrcvStandbyIndicatedAsExpected( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      } /* end if Trcv Standby Indicated */
      else
      {
        /* MISRA QAC */ /* ignore SLEEP inaction */
      }

    } /* TransceiverId valid; found in configuration */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_TRANSCEIVERMODEINDICATION, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* end Func CanSM_TransceiverModeIndication */
#endif /* if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */



#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_ClearTrcvWufFlagIndication
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_ClearTrcvWufFlagIndication( uint8 CanSM_TransceiverId )
{ /* \trace SPEC-11414 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-11362 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapTransceiverIdToLocalIndex( CanSM_TransceiverId );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_TRANSCEIVER;
      /* \trace SPEC-11316 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_PN_CLEAR_WUF )
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        /* \trace..SPEC-11299 */
      }

    } /* TransceiverId valid; found in configuration; */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CLEARTRCVWUFFLAGINDICATION, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* End Func CanSM_ClearTrcvWufFlagIndication   () */
#endif /* end   else if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */



#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_CheckTransceiverWakeFlagIndication
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_CheckTransceiverWakeFlagIndication( uint8 CanSM_TransceiverId )
{ /* \trace SPEC-11313 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-11372 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {
    CanSM_CanNetworkIdx = CanSM_MapTransceiverIdToLocalIndex( CanSM_TransceiverId );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_TRANSCEIVER;
      /* \trace SPEC-11436 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CHK_WUF_CC_SLEEP )
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode &= CANSM_CLEAR_TX_TIMEOUT_EXCEPTION_FLAG; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        CanSM_NoComReached( CanSM_CurrentChannelVarPtr );  /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }
      else if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CHK_WUF_NOT_CC_SLEEP )
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_PN_CLEAR_WUF; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }
      else
      {
        /* MISRA QAC */ /* ignore unexpected indications */
      }
      /* \trace..SPEC-11413 */

    } /* CanSM_TransceiverId valid; found in configuration */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CHECKTRANSCEIVERWAKEFLAGINDICATION, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* End Func CanSM_CheckTransceiverWakeFlagIndication() */
#endif /* end   else if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */


/* \trace SPEC-827, SPEC-832 */
#if ( CANSM_VERSION_INFO_API == STD_ON )
/***********************************************************************************************************************
 *  CanSM_GetVersionInfo
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, CANSM_APPL_VAR ) VersionInfo )
{ /* \trace SPEC-821 */
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( VersionInfo == NULL_PTR )
  {
    CanSM_DetErrorId = CANSM_E_PARAM_POINTER;
    /* \trace SPEC-831 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {
    /* \trace SPEC-824 */
    (*VersionInfo).vendorID = (uint16)CANSM_VENDOR_ID; /* SBSW_CANSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*VersionInfo).moduleID = (uint8)CANSM_MODULE_ID; /* SBSW_CANSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*VersionInfo).sw_major_version = (uint8)CANSM_SW_MAJOR_VERSION; /* SBSW_CANSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*VersionInfo).sw_minor_version = (uint8)CANSM_SW_MINOR_VERSION; /* SBSW_CANSM_GETVERSIONINFO_POINTERWRITEACCESS */
    (*VersionInfo).sw_patch_version = (uint8)CANSM_SW_PATCH_VERSION; /* SBSW_CANSM_GETVERSIONINFO_POINTERWRITEACCESS */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_GETVERSIONINFO, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* end Func CanSM_GetVersionInfo() */
#endif /* end  if ( CANSM_VERSION_INFO_API == STD_ON ) */



#if ( CANSM_SET_BAUDRATE_API == STD_ON )
/* \trace..SPEC-2181378 */
/* \trace..SPEC-47140 */
/***********************************************************************************************************************
 *  CanSM_SetBaudrate
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetBaudrate( NetworkHandleType Network, uint16 BaudRateConfigID )
{
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  Std_ReturnType CanSM_StdReturnValue = E_NOT_OK;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace..SPEC-47137 */
    /* \trace..SPEC-47128 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( Network );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
      /* \trace..SPEC-47127 */
      /* \trace..SPEC-47129 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_FULLCOM_ENSURED ) /* CANSM_S_NO_BUS_OFF */
      {

        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_6();
        if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CANSM_NOBODY )
        {
          (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_SETBAUDRATE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
          (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_CHANGE_BAUDRATE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        }
        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_6();

        (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate = BaudRateConfigID; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* trigger NwSM next MainFuncCycle */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        /* \trace..SPEC-47154 */


        CanSM_CheckModeIndication( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr, CANSM_SID_SETBAUDRATE ); /* Function checks if mode has changed */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


        /* \trace..SPEC-11328 */
        CanSM_StdReturnValue = E_OK;
        /* \trace..SPEC-47141 */
      }
      /* \trace..SPEC-47135 */

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_SETBAUDRATE, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* End Func CanSM_SetBaudrate() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* if ( CANSM_SET_BAUDRATE_API == STD_ON ) */


/* \trace SPEC-11359, SPEC-11402 */
#if ( CANSM_CHANGE_BAUDRATE_API == STD_ON )
/***********************************************************************************************************************
 *  CanSM_CheckBaudrate
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(Std_ReturnType, CANSM_CODE) CanSM_CheckBaudrate( NetworkHandleType CanSM_NetworkHandle, CONST( uint16, AUTOMATIC ) CanSM_Baudrate )
{ /* \trace SPEC-11396 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  Std_ReturnType CanSM_StdReturnValue = E_NOT_OK;
  /* \trace SPEC-11380 */

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
      /* \trace SPEC-11352 */
      /* \trace SPEC-11392 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      /* \trace SPEC-11391 */ /* \trace SPEC-11393 */
      if ( CanIf_CheckBaudrate( CanSM_GetControllerIdOfChannelConfig( CanSM_CanNetworkIdx ), CanSM_Baudrate ) == E_OK )
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate = CanSM_Baudrate; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        /* \trace SPEC-11323 */
        CanSM_StdReturnValue = E_OK;
        /* \trace SPEC-11329 */
      }
      else
      {
        (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate = CANSM_INVALID_BAUDRATE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
      }

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CHECKBAUDRATE, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* End Func CanSM_CheckBaudrate () */
#endif /* if ( CANSM_CHANGE_BAUDRATE_API == STD_ON ) */


/* \trace SPEC-11367, SPEC-11382 */
#if ( CANSM_CHANGE_BAUDRATE_API == STD_ON )
/***********************************************************************************************************************
 *  CanSM_ChangeBaudrate
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_ChangeBaudrate( NetworkHandleType CanSM_NetworkHandle, CONST( uint16, AUTOMATIC ) CanSM_Baudrate )
{ /* \trace SPEC-11336 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;
  Std_ReturnType CanSM_StdReturnValue = E_NOT_OK;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-11357 */
    /* \trace SPEC-11428 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
      /* \trace SPEC-11364 */
      /* \trace SPEC-11348 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_FULLCOM_ENSURED ) /* CANSM_S_NO_BUS_OFF */
      {

        if ( (*CanSM_CurrentChannelVarPtr).CanSM_LastValidBaudRate == CanSM_Baudrate )
        {

          SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_6();
          if ( (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible == CANSM_NOBODY )
          {
            (*CanSM_CurrentChannelVarPtr).CanSM_ModeIndicationResponsible = CANSM_SID_CHANGEBAUDRATE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
            (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_CHANGE_BAUDRATE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
          }
          SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_6();


          (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* trigger NwSM next MainFuncCycle */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
          (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


          CanSM_CheckModeIndication( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr, CANSM_SID_CHANGEBAUDRATE ); /* Function checks if mode has changed */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */


          CanSM_StdReturnValue = E_OK;
          /* \trace SPEC-11403 */
        }
        /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
        else
        {
          CanSM_DetErrorId = CANSM_E_PARAM_INVALID_BAUDRATE;
          /* \trace SPEC-11337 */
          CanSM_StdReturnValue = E_NOT_OK;
          /* \trace SPEC-11283 */
        }
#endif /* end if ( CANSM_DEV_ERROR_DETECT == STD_ON ) */

      }
      else
      { /* CBR request within illegal communication mode, not COMM_FULL_COMMUNICATION */
        CanSM_StdReturnValue = E_NOT_OK;
        /* \trace SPEC-11384 */
      }

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CHANGEBAUDRATE, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* End Func CanSM_ChangeBaudrate() */ /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* if ( CANSM_CHANGE_BAUDRATE_API == STD_ON ) */



/***********************************************************************************************************************
 *  CanSM_TxTimeoutException
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
FUNC(void, CANSM_CODE) CanSM_TxTimeoutException( NetworkHandleType CanSM_NetworkHandle )
{ /* \trace SPEC-11331 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-11374 */
  }
  else
#endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
#if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
      /* \trace SPEC-11303 */
    }
    else
#endif /* CANSM_DEV_ERROR_DETECT  */
    {
      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if (  ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_NO_BUS_OFF ) /* CANSM_S_FULLCOM_ENSURED */
#if ( CANSM_EXPANDED_TX_TIMEOUT_RECOVERY == STD_ON )
          ||  ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_BO_BUS_OFF_CHECK )
          ||  ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_SILENTCOM )
#endif
         )
      {

#if ( CANSM_SWIFT_TX_TIMEOUT_RECOVERY == STD_OFF )

        CanSM_InitiateShutDownSequence( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode |=  CANSM_TX_TIMEOUT_EXCEPTION_RECEIVED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

#else /* CANSM_SWIFT_TX_TIMEOUT_RECOVERY */
        (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_UniversalTimer = CANSM_CANCEL_TIMER; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_BswMNewState = CANSM_BSWM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_SILENT_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
        /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
#endif /* CANSM_SWIFT_TX_TIMEOUT_RECOVERY */
        /* \trace..SPEC-47114 */

      } /* NoBusOff ==> handle TxTimeout */

      (*CanSM_CurrentChannelVarPtr).CanSM_TxTimeoutEndIndicationFlag = TRUE; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

    } /* NetworkHandle index in configuration list ==> NetworkHandle valid */
  } /* no error detected */

#if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_TXTIMEOUTEXCEPTION, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
#else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* end Func CanSM_TxTimeoutException */



#if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON )
/***********************************************************************************************************************
 *  CanSM_ConfirmPnAvailability
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
FUNC(void, CANSM_CODE) CanSM_ConfirmPnAvailability( uint8 CanSM_TransceiverId )
{ /* \trace SPEC-11375 */
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized == CANSM_INITFUNCTION_NOT_CALLED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace SPEC-11358 */
  }
  else if ( CanSM_IsInitialized == CANSM_INITFUNCTION_RUNNING )
  {
    /* Nm not initialized, avoid Det call */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapTransceiverIdToLocalIndex( CanSM_TransceiverId );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_PARAM_TRANSCEIVER;
      /* \trace SPEC-11434 */
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {
      CanNm_ConfirmPnAvailability( CanSM_GetNetworkHandleOfChannelConfig( CanSM_CanNetworkIdx ) );
      /* \trace SPEC-11378 */
      /* \trace SPEC-11431 */
    } /* TransceiverId valid; found in configuration */

  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CONFIRMPNAVAILABILITY, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

} /* end Func CanSM_ConfirmPnAvailability */
#endif /* end  else  if ( CANSM_PARTIAL_NETWORK_TRCV_SUPPORTOFCHANNELCONFIG == STD_ON ) */



#if ( CANSM_BOR_CHECK_LEVEL == STD_ON )
/***********************************************************************************************************************
 *  CanSM_CheckBorLevel
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_CheckBorLevel( CONST( NetworkHandleType, AUTOMATIC ) CanSM_NetworkHandle, P2VAR( CanSM_BorStateType, AUTOMATIC, CANSM_APPL_VAR ) CanSM_BorStatePtr )
{
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;
  Std_ReturnType CanSM_StdReturnValue;

  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  CanSM_StdReturnValue = E_NOT_OK;
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else if ( CanSM_BorStatePtr == NULL_PTR )
  {
    CanSM_DetErrorId = CANSM_E_PARAM_POINTER;
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

      P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

      if ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter == CANSM_BOR_NONE )
      {
        *CanSM_BorStatePtr = CANSM_BOR_NONE; /* SBSW_CANSM_CHECKBORLEVEL_POINTERWRITEACCESS */
      }
      else if ( (*CanSM_CurrentChannelVarPtr).CanSM_BusOffCounter < CanSM_GetBorCounterL1ToL2OfChannelConfig( CanSM_CanNetworkIdx ) )
      {
        *CanSM_BorStatePtr = CANSM_BOR_LEVEL1; /* SBSW_CANSM_CHECKBORLEVEL_POINTERWRITEACCESS */
      }
      else
      {
        *CanSM_BorStatePtr = CANSM_BOR_LEVEL2; /* SBSW_CANSM_CHECKBORLEVEL_POINTERWRITEACCESS */
      }

      CanSM_StdReturnValue = E_OK;

    } /* NetworkHandle index in configuration list ==> NetworkHandle valid */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_CHECKBORLEVEL, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

  return CanSM_StdReturnValue;

} /* end CanSM_CheckBorLevel */  /* PRQA S 6080 */ /* MD_MSR_STMIF  */
#endif /* ( CANSM_BOR_CHECK_LEVEL == STD_ON ) */



/***********************************************************************************************************************
 *  CanSM_StartWakeupSources
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_StartWakeupSources( NetworkHandleType CanSM_NetworkHandle )
{
  Std_ReturnType CanSM_StdReturnValue = E_NOT_OK;
#if !defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;

  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

# if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
      if ( !CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
# endif /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF */
      {
        /* No PN  */

        P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

//        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_5(); /* RequestComMode MainFunction */
        if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode == COMM_NO_COMMUNICATION )
        {

# if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON )
          (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_TRCV_NORMAL; /* will be changed to CANSM_SU_CC_STOPPED in NWSM if Trcv is inactive on channel */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# else /* CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG  */
          (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SU_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
# endif /* if ( CANSM_TRANSCEIVER_CHANNEL_SUPPORTOFCHANNELCONFIG == STD_ON ) */

          /* CanSM_StartupStatemachine */
          CanSM_NetworkStatemachine( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

          if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_STARTWAKEUPSOURCES_SUCCESSFUL )
          {
            CanSM_StdReturnValue = E_OK;
          }
          else
          {
            (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_S_NOCOM; /* CREQ-365 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */
          }

          (*CanSM_CurrentChannelVarPtr).CanSM_NewComMode = COMM_NO_COMMUNICATION; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

        } /* COMM_NO_COMMUNICATION Req; trigger valid */
//        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_5();
      } /* no PN channel */

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_STARTWAKEUPSOURCES, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

#endif /* ( not CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON  ) */

  CANSM_DUMMY_STATEMENT( CanSM_NetworkHandle ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return CanSM_StdReturnValue;

} /* end CanSM_StartWakeupSources */ /* PRQA S 6080 */ /* MD_MSR_STMIF */



/***********************************************************************************************************************
 *  CanSM_StopWakeupSources
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
FUNC(Std_ReturnType, CANSM_CODE) CanSM_StopWakeupSources( NetworkHandleType CanSM_NetworkHandle, EcuM_WakeupSourceType WakeupSource )
{
  Std_ReturnType CanSM_StdReturnValue = E_NOT_OK;
#if !defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON
  CanSM_SizeOfChannelVarRecordType CanSM_CanNetworkIdx;

  uint8 CanSM_DetErrorId = CANSM_E_NO_ERROR;

  /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
  if ( CanSM_IsInitialized != CANSM_INITFUNCTION_FINISHED )
  {
    CanSM_DetErrorId = CANSM_E_UNINIT;
    /* \trace..SPEC-2181302 */
  }
  else
# endif /* CANSM_DEV_ERROR_DETECT  */
  {

    CanSM_CanNetworkIdx = CanSM_MapNetworkHandleToLocalIndex( CanSM_NetworkHandle );

    /* \trace SPEC-812, SPEC-811 */
# if ( CANSM_DEV_ERROR_DETECT == STD_ON )
    if ( CanSM_CanNetworkIdx >= CanSM_GetSizeOfChannelVarRecord() )
    {
      CanSM_DetErrorId = CANSM_E_INVALID_NETWORK_HANDLE;
    }
    else
# endif /* CANSM_DEV_ERROR_DETECT  */
    {

# if defined CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF
      if ( !CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig( CanSM_CanNetworkIdx ) ) /* PRQA S 4304, 4404, 1881, 1882, 4558 */ /* MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean, MD_MSR_AutosarBoolean */
# endif /* CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_MIXED_ON_AND_OFF */
      {

        P2VAR(CanSM_ChannelVarRecordType, AUTOMATIC, CANSM_VAR_NOINIT) CanSM_CurrentChannelVarPtr = CanSM_GetAddrChannelVarRecord( CanSM_CanNetworkIdx );

        SchM_Enter_CanSM_CANSM_EXCLUSIVE_AREA_5(); /* RequestComMode MainFunction */

        if ( (*CanSM_CurrentChannelVarPtr).CanSM_RequestedComMode == COMM_NO_COMMUNICATION )
        {

          (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_SD_CC_STOPPED; /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

          if ( (*CanSM_CurrentChannelVarPtr).CanSM_IndicatedComMode == COMM_NO_COMMUNICATION )
          {
            CanSM_IsInitialized = CANSM_STOPWAKEUPSOURCES_RUNNING; /* avoid RamCheck */
          }

          /* CanSM_ShutDownStatemachine */
          CanSM_NetworkStatemachine( CanSM_CanNetworkIdx, CanSM_CurrentChannelVarPtr ); /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

          if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_SD_CC_SLEEP )
          { /* CANIF_CS_SLEEP failed trigger wakeup */
            EcuM_SetWakeupEvent( WakeupSource );
            CanSM_StdReturnValue = E_OK;
          }
          else if ( (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState == CANSM_S_NOCOM )
          {
            CanSM_StdReturnValue = E_OK;
          }
          else
          {
            CanSM_StdReturnValue = E_NOT_OK; /* redundant */
          }

          CanSM_IsInitialized = CANSM_STOPWAKEUPSOURCES_FINISHED;

          (*CanSM_CurrentChannelVarPtr).CanSM_CurrentState = CANSM_S_NOCOM; /* CREQ-365 */ /* SBSW_CANSM_CHANNEL_STRUCT_ACCESS */

        } /* COMM_NO_COMMUNICATION request; trigger valid */
        /* Exit ExclusiveArea, InterruptsEnabled */
        SchM_Exit_CanSM_CANSM_EXCLUSIVE_AREA_5();

      } /* !CanSM_IsPartial_Network_Trcv_SupportOfChannelConfig  */

    } /* NetworkHandle index in list ==> NetworkHandle valid */
  } /* no error detected */

# if ( CANSM_DEV_ERROR_REPORT == STD_ON )
  if ( CanSM_DetErrorId != CANSM_E_NO_ERROR )
  {
    (void)Det_ReportError( CANSM_MODULE_ID, CANSM_INSTANCE_ID, CANSM_SID_STOPWAKEUPSOURCES, CanSM_DetErrorId );
    /* \trace SPEC-807, SPEC-809 */
  }
# else /* CANSM_DEV_ERROR_REPORT */
  CANSM_DUMMY_STATEMENT( CanSM_DetErrorId ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif /* end if ( CANSM_DEV_ERROR_REPORT == STD_ON ) */

#endif /* ( not CANSM_PARTIAL_NETWORK_TRCV_SUPPORT_ALWAYS_ON  ) */

  CANSM_DUMMY_STATEMENT( CanSM_NetworkHandle ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CANSM_DUMMY_STATEMENT( WakeupSource ); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return CanSM_StdReturnValue; /* more than one 'return' path */ /* Network valid; found in configuration; stop searching, stop for-loop */

} /* end CanSM_StopWakeupSources */ /* PRQA S 6080 */ /* MD_MSR_STMIF */



#define CANSM_STOP_SEC_CODE
#include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* Dummy statement because of tool bug */ /* PRQA S 1533 */ /* MD_CANSM_Rule8.9 */
/* Module specific MISRA deviations:
 * MD_CANSM_Rule2.1
 *   Reason:     Incorrect message from QAC, this code is reachable.
 *   Risk:       none
 *   Prevention: Covered by runtime code coverage.
 * MD_CANSM_Rule2.2_2982
 *   Reason:     Incorrect message from QAC, This assignment is not redundant. The value of this object is used before being modified.
 *   Risk:       none
 *   Prevention: Covered by runtime code coverage.
 * MD_CANSM_Rule2.2_2996
 *   Reason:     Incorrect message from QAC, the result of this logical operation is not always 'false
 *   Risk:       none
 *   Prevention: Covered by runtime code coverage.
 * MD_CANSM_Rule8.9
 *   Reason:     The actual function pointer value is generated. So the declaration has to stay in the gererated c file.
 *   Risk:       none
 *   Prevention: Covered by code review.
 * MD_CANSM_Rule8.11
 *   Reason:     Avoid libraries with arrays which contains only one single element caused by compiler optimization.
 *   Risk:       none
 *   Prevention: Covered by code review.
 * MD_CANSM_Rule14.3
 *   Reason:     Incorrect message from QAC, the result of this logical operation is not always 'false
 *   Risk:       none
 *   Prevention: Covered by runtime code coverage.
 * MD_CANSM_Rule16.3
 *   Reason:     Intentionally switch case with out break statement to proceed the next step immediately
 *   Risk:       none
 *   Prevention: Covered by code review.
 */


/* SBSW_JUSTIFICATION_BEGIN



   \ID SBSW_CANSM_GETCURRENTCOMMODE_POINTERWRITEACCESS
   \DESCRIPTION The function writes to the object referenced by the pointer parameter.
   \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter is valid. [SMI-16]

   \ID SBSW_CANSM_GETVERSIONINFO_POINTERWRITEACCESS
   \DESCRIPTION The function writes to the object referenced by the pointer parameter.
   \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter is valid. [SMI-16]

   \ID SBSW_CANSM_COMMMODEINDICATION_CALL
   \DESCRIPTION   Call to ComM_BusSM_ModeIndication function with network handle and pointer to the communication mode variable.
   \COUNTERMEASURE \N The pointer is valid because the calculation is secured by SBSW_CANSM_CHANNEL_STRUCT_ACCESS

   \ID SBSW_CANSM_GETBUSOFFDELAY_POINTERWRITEACCESS
   \DESCRIPTION The function writes to the object referenced by parameter OnlineDelayCyclesPtr.
   \COUNTERMEASURE \N The passed pointer is valid due to SBSW_CANSM_CHANNEL_STRUCT_ACCESS.

   \ID SBSW_CANSM_GETBUSOFFDELAY_INDICATION
   \DESCRIPTION Function pointer to the get bus off delay indication function
   \COUNTERMEASURE \S Verify that the function pointer CanSM_BusOffBeginIndicationFctPtr refers to a valid function. [SMI-389]

   \ID SBSW_CANSM_CHANNEL_STRUCT_ACCESS
   \DESCRIPTION Access of channel struct using ComStackLib
   \COUNTERMEASURE \N Qualified use-case CSL01 of ComStackLib

   \ID SBSW_CANSM_BUS_OFF_END_INDICATION
   \DESCRIPTION Function pointer to the bus off end indication function.
   \COUNTERMEASURE \S Verify that the function pointer CanSM_BusOffEndIndicationFctPtr refers to a valid function. [SMI-389]

   \ID SBSW_CANSM_TX_TIMEOUT_END_INDICATION
   \DESCRIPTION Function pointer to the Tx timeout end indication function.
   \COUNTERMEASURE \S Verify that the function pointer CanSM_TxTimeoutExceptionEndIndicationFctPtr refers to a valid function. [SMI-389]

   \ID SBSW_CANSM_CHECKBORLEVEL_POINTERWRITEACCESS
   \DESCRIPTION The function CanSM_CheckBorLevel writes to the object referenced by parameter CanSM_BorStatePtr.
   \COUNTERMEASURE \N The caller ensures that the pointer passed to the parameter is valid. [SMI-16]

   \ID SBSW_CANSM_ENABLE_SET_BUS_SLEEP_ARRAY
   \DESCRIPTION Access of CanSM_EnableSetBusSleep limited by the define which is used fore declaration.
   \COUNTERMEASURE \N The same define which is used in definition is used in the for loop which provides the write access index

   \ID SBSW_CANSM_CFG_POINTER
   \DESCRIPTION Pointer parameter is forwarded to an internal subfunction.
   \COUNTERMEASURE \N NULL pointer check is executed within the subfunction


   SBSW_JUSTIFICATION_END */

/* COV_JUSTIFICATION_BEGIN

   \ID COV_CANSM_CHECKDEFINE
   \ACCEPT TX
   \REASON The condition checks whether a define exists and conditionally assigns a default value.

   COV_JUSTIFICATION_END */

/**********************************************************************************************************************
  END OF FILE: CanSM.c
 *********************************************************************************************************************/


