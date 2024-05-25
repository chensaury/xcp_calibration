
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
/* \file    CanSM.h
 * \brief   Public header of the CAN State Manager AUTOSAR Release 4
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


#if !defined (CANSM_H)
# define CANSM_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/*  include Std_Types.h Std_VersionInfoType */
/*  include Compiler.h */ /* compiler abstraction */
/*  include ComStack_Types.h */ /* NetworkHandleType; includes ComStack_Types.h, which includes Std_Types.h which include "Platform_Types.h" and include "Compiler.h" */
# include "CanSM_Cfg.h" /* includes ComStack_Types.h  */
# include "ComM_Types.h"        /* needed cause of ComM_ModeType */
# include "CanIf.h"           /* needed cause of Can_HwHandleType */

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/* Vendor and module identification */
# define CANSM_VENDOR_ID                                              (0x1Eu)
# define CANSM_MODULE_ID                                              (0x8Cu)

/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4SmCan CQComponent : Implementation */
/* Version - BCD coded version number - Main- and Sub-Version - Release-Version */
# define CCL_ASR4SMCAN_VERSION                                        0x0300u   /* BCD coded version number */
# define CCL_ASR4SMCAN_RELEASE_VERSION                                0x01u    /* BCD coded release version number  */

/* AUTOSAR Release Version */
# define CANSM_AR_RELEASE_MAJOR_VERSION                               (0x04u)                                /* Major version number of AUTOSAR specification on which the appropriate implementation is based on. */
# define CANSM_AR_RELEASE_MINOR_VERSION                               (0x00u)                               /* Minor version number of AUTOSAR specification on which the appropriate implementation is based on. */
# define CANSM_AR_RELEASE_REVISION_VERSION                            (0x03u)                              /* Patch level version number of AUTOSAR specification on which the appropriate implementation is based on. */

/* AUTOSAR Software Specification Version  */
# define CANSM_AR_MAJOR_VERSION                                       (0x02u)                                /* Major version number of AUTOSAR specification on which the appropriate implementation is based on. */
# define CANSM_AR_MINOR_VERSION                                       (0x02u)                               /* Minor version number of AUTOSAR specification on which the appropriate implementation is based on. */
# define CANSM_AR_PATCH_VERSION                                       (0x00u)                              /* Patch level version number of AUTOSAR specification on which the appropriate implementation is based on. */

# define CANSM_SW_MAJOR_VERSION                                       (CCL_ASR4SMCAN_VERSION >> 8)         /* Major version number of the vendor specific implementation of the module. */
# define CANSM_SW_MINOR_VERSION                                       (CCL_ASR4SMCAN_VERSION  & 0x00FFu)  /* Minor version number of the vendor specific implementation of the module. */
# define CANSM_SW_PATCH_VERSION                                       (CCL_ASR4SMCAN_RELEASE_VERSION)    /* Patch level version number of the vendor specific implementation of the module. */


/* Defines used for calling Det_ReportError */
/* Definition of the API ID ( ASR service function ) */
# define CANSM_SID_INIT                                        (0x00u)
# define CANSM_SID_GETVERSIONINFO                              (0x01u)
# define CANSM_SID_REQUESTCOMMODE                              (0x02u)
# define CANSM_SID_GETCURRENTCOMMODE                           (0x03u)
# define CANSM_SID_CONTROLLERBUSOFF                            (0x04u)
# define CANSM_SID_MAINFUNCTION                                (0x05u)
# define CANSM_SID_CONFIRMPNAVAILABILITY                       (0x06u)
# define CANSM_SID_CONTROLLERMODEINDICATION                    (0x07u)
# define CANSM_SID_CLEARTRCVWUFFLAGINDICATION                  (0x08u)
# define CANSM_SID_TRANSCEIVERMODEINDICATION                   (0x09u)
# define CANSM_SID_CHECKTRANSCEIVERWAKEFLAGINDICATION          (0x0Au)
# define CANSM_SID_TXTIMEOUTEXCEPTION                          (0x0Bu)
# define CANSM_SID_CHECKBAUDRATE                               (0x0Cu)
# define CANSM_SID_CHANGEBAUDRATE                              (0x0Eu)
# define CANSM_SID_SETBAUDRATE                                 (0x0Du)

/* API service to provide internal bus-off recovery level */
# define CANSM_SID_CHECKBORLEVEL                               (0x0Fu)
# define CANSM_SID_PREVENTBUSSLEEPATSTARTUP                    (0x40u)

# define CANSM_SID_STARTWAKEUPSOURCES                          (0x20u)
# define CANSM_SID_STOPWAKEUPSOURCES                           (0x21u)

# define CANSM_SID_RAMCHECKSTATUS                              (0x30u)
# define CANSM_SID_RAMCHECKCORRUPTMAILBOX                      (0x31u)
# define CANSM_SID_RAMCHECKCORRUPTCONTROLLER                   (0x32u)
# define CANSM_SID_RAMCHECKENABLEMAILBOX                       (0x33u)



/* The identifier of the index based instance of a module, starting from 0,
 * If the module is a single instance module it shall pass 0 as the InstanceId. */
# define CANSM_INSTANCE_ID                                            (0x00u)

/* Definition of errors/exceptions code  \trace SPEC-11412, SPEC-2181267 */
# define CANSM_E_NO_ERROR                                             (0x00u)
/* API service used without module initialization */
# define CANSM_E_UNINIT                                               (0x01u)
/* API service called with invalid pointer in parameter list */
# define CANSM_E_PARAM_POINTER                                        (0x02u)
/* API service called with invalid network handle parameter */
# define CANSM_E_INVALID_NETWORK_HANDLE                               (0x03u)
/* API service called with invalid controller parameter */
# define CANSM_E_PARAM_CONTROLLER                                     (0x04u)
/* API service called with invalid transceiver parameter */
# define CANSM_E_PARAM_TRANSCEIVER                                    (0x05u)
/* Network   mode   request during  not  finished  bus-off recovery */
# define CANSM_E_BUSOFF_RECOVERY_ACTIVE                               (0x06u)
/* Network   mode   request during pending indication */
# define CANSM_E_WAIT_MODE_INDICATION                                 (0x07u)
/* API service called with invalid communication mode requested */
# define CANSM_E_INVALID_COMM_REQUEST                                 (0x08u)
/* API service called with invalid BaudrateConfig */
# define CANSM_E_PARAM_INVALID_BAUDRATE                               (0x09u)
/* Mode request for a network failed more often as  allowed  by configuration */
# define CANSM_E_MODE_REQUEST_TIMEOUT                                 (0x0Au)
  /* API CanSM_PreventBusSleepAtStartUp called after CanSM_Init */
# define CANSM_E_INITIALIZED                                          (0xB0u)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

# if ( STD_ON == CANSM_BOR_CHECK_LEVEL )
/* Defines the values of the internal internal bus-off recovery level used by CanSM_CheckBorLevel() */
typedef   uint8   CanSM_BorStateType;
#  define CANSM_BOR_NONE                                               (0x00u)
#  define CANSM_BOR_LEVEL1                                             (0x01u)
#  define CANSM_BOR_LEVEL2                                             (0x02u)
# endif /* ( STD_ON == CANSM_BOR_CHECK_LEVEL ) */


#if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
# define  CANSM_ENABLE_COMMUNICATION                                      E_OK
# define  CANSM_DISABLE_COMMUNICATION                                    (0x02u)
# define  CANSM_ENABLE_COMMUNICATION_REPEAT                              (0x04u)
# define  CANSM_DISABLE_COMMUNICATION_REPEAT                             (0x06u)
#endif /*  CANSM_EXTENDED_RAM_CHECK */

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define CANSM_START_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */


# if ( STD_ON ==  CANSM_VERSION_INFO_API )
/***********************************************************************************************************************
 *  CanSM_GetVersionInfo
 **********************************************************************************************************************/
/*! \brief       Returns the version information
 *  \details     Returns the software version, vendor ID and AUTOSAR module ID of the component.
 *  \param[out]  VersionInfo             Pointer to version information. Parameter must not be NULL (BSW00407).
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      CANSM_VERSION_INFO_API
 *  \pre         -
 *  \trace       CREQ-364
 *********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_GetVersionInfo( P2VAR( Std_VersionInfoType, AUTOMATIC, CANSM_APPL_VAR ) VersionInfo );
# endif /* end  if ( STD_ON ==  CANSM_VERSION_INFO_API ) */


# if ( STD_ON == CANSM_ECU_PASSIVE_MODE )
/*********************************************************************************************************************
  FUNCTION: CanSM_SetEcuPassive
*********************************************************************************************************************/
/*! \brief      ( De)Activates ECU passive mode
 *  \details     in passive mode the Tx pdu mode is set to offline active instead online
 *  \param[in]   CanSM_TxOfflineActive       Tx offline active
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \config      CANSM_ECU_PASSIVE_MODE
 *  \pre         -
 *  \trace       -
 **********************************************************************************************************************/
FUNC( void, CANSM_CODE ) CanSM_SetEcuPassive( boolean CanSM_TxOfflineActive );
# endif   /* end  if ( STD_ON == CANSM_ECU_PASSIVE_MODE ) */

#if ( STD_ON == CANSM_BOR_CHECK_LEVEL )
/***********************************************************************************************************************
*  CanSM_CheckBorLevel
**********************************************************************************************************************/
/*! \brief       Reports the current bus-off level
 *  \details     Reports the bus-off level CANSM_BOR_NONE, CANSM_BOR_LEVEL1 or CANSM_BOR_LEVEL2
 *  \param[in]   CanSM_NetworkHandle     Network handle
 *  \param[out]  CanSM_BorStatePtr       Pointer to bus-off level target
 *  \return      E_OK      Request was accepted
 *  \return      E_NOT_OK  Request was not accepted
 *  \context     ANY
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      CANSM_BOR_CHECK_LEVEL
 *  \pre         -
 *  \trace       CREQ-1012
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_CODE ) CanSM_CheckBorLevel( CONST(NetworkHandleType, AUTOMATIC)  CanSM_NetworkHandle, P2VAR( CanSM_BorStateType, AUTOMATIC, CANSM_APPL_VAR ) CanSM_BorStatePtr );
#endif /* ( STD_ON == CANSM_BOR_CHECK_LEVEL ) */


#if ( CANSM_EXTENDED_RAM_CHECK == STD_ON )
/***********************************************************************************************************************
 *  Appl_CanSM_RamCheckStart
 **********************************************************************************************************************/
/*! \brief       Indicates the begin of the RAM check
 *  \details     Indicates the begin of the RAM check.
 *  \param[in]   CanSM_NetworkHandle     network handle
 *  \context     TASK
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC( void, CANSM_APPL_CODE ) Appl_CanSM_RamCheckStart( NetworkHandleType CanSM_NetworkHandle );

/***********************************************************************************************************************
 *  Appl_CanSM_RamCheckCorruptController
 **********************************************************************************************************************/
/*! \brief       Forwards register RAM failures
 *  \details     If register RAM failures occurs the information from the CanDrv is passed through the Application.
 *  \param[in]   CanSM_NetworkHandle     network handle
 *  \context     TASK
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC( void, CANSM_APPL_CODE ) Appl_CanSM_RamCheckCorruptController( NetworkHandleType CanSM_NetworkHandle );

/***********************************************************************************************************************
 *  Appl_CanSM_RamCheckCorruptMailbox
 **********************************************************************************************************************/
/*! \brief       Forwards message box RAM failures
 *  \details     If a message box RAM failures occurs the information from the CanDrv is passed through the Application.
 *  \param[in]   CanSM_NetworkHandle  Network handle
 *  \param[in]   CanSM_MailBoxHandle  HW mail box identifier
 *  \context     TASK
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC( void, CANSM_APPL_CODE ) Appl_CanSM_RamCheckCorruptMailbox( NetworkHandleType CanSM_NetworkHandle, Can_HwHandleType CanSM_MailBoxHandle );

/***********************************************************************************************************************
 *  Appl_CanSM_RamCheckFinished
 **********************************************************************************************************************/
/*! \brief       Indicates the end of the RAM check
 *  \details     The CanDrv has finished the extended RAM check. All potential errors have been reported. The Application has to specify further actions via return value.
 *  \param[in]   CanSM_NetworkHandle                Network handle
 *  \return      CANSM_ENABLE_COMMUNICATION         Every thing is E_OK
 *               CANSM_DISABLE_COMMUNICATION        Communication shall be disabled
*                CANSM_ENABLE_COMMUNICATION_REPEAT  Communication shall be enabled and the RAM check repeated
*                CANSM_DISABLE_COMMUNICATION_REPEAT Communication shall be disabled and the RAM check repeated
 *  \context     TASK
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC( Std_ReturnType, CANSM_APPL_CODE ) Appl_CanSM_RamCheckFinished( NetworkHandleType CanSM_NetworkHandle );

/***********************************************************************************************************************
 *  CanSM_RamCheckEnableMailbox
 **********************************************************************************************************************/
/*! \brief       Forwards enable mail box
 *  \details     If a mail box shall be enabled the information from the application is passed through to the CanDrv via CanIf.
 *  \param[in]   CanSM_NetworkHandle  Network handle
 *  \param[in]   CanSM_MailBoxHandle  HW mail box identifier
 *  \context     TASK
 *  \reentrant   TRUE for different handles
 *  \synchronous TRUE
 *  \config      CANSM_EXTENDED_RAM_CHECK
 *  \pre         -
 *  \trace       CREQ-106018
 **********************************************************************************************************************/
FUNC(void, CANSM_CODE) CanSM_RamCheckEnableMailbox( NetworkHandleType CanSM_NetworkHandle, Can_HwHandleType CanSM_MailBoxHandle );

#endif /* CANSM_EXTENDED_RAM_CHECK  */





/*!
 * \exclusivearea CANSM_EXCLUSIVE_AREA_1
 * Ensures consistency while performing state changes
 * \protects CanSM_ChannelVarRecord
 * \usedin CanSM_MainFunction
 * \exclude CanSM_RequestComMode, CanSM_ControllerBusOff, CanSM_TxTimeoutException, CanSM_SetEcuPassive, CanSM_StopWakeupSources, CanSM_StartWakeupSources
 * \length LONG This exclusive area covers calls to several BSW functions.
 * \endexclusivearea
 *
 * \exclusivearea CANSM_EXCLUSIVE_AREA_2
 * Ensures consistency while performing state changes
 * \protects CanSM_ChannelVarRecord
 * \usedin CanSM_RequestComMode
 * \exclude CanSM_MainFunction, CanSM_ControllerModeIndication, CanSM_TransceiverModeIndication, CanSM_ClearTrcvWufFlagIndication, CanSM_CheckTransceiverWakeFlagIndication, CanSM_TxTimeoutException, CanSM_SetEcuPassive, CanSM_StopWakeupSources, CanSM_StartWakeupSources.
 * \length LONG This exclusive area covers calls to several BSW functions.
 * \endexclusivearea
 *
 * \exclusivearea CANSM_EXCLUSIVE_AREA_3
 * Ensures consistency while performing state changes
 * \protects CanSM_ChannelVarRecord
 * \usedin CanSM_ControllerBusOff
 * \exclude CanSM_RequestComMode, CanSM_ControllerBusOff, CanSM_TxTimeoutException
 * \length LONG This exclusive area covers calls to several BSW functions.
 * \endexclusivearea
 *
 * \exclusivearea CANSM_EXCLUSIVE_AREA_4
 * Ensures consistency while modifying/evaluating controller mode
 * \protects CAN Peripheral
 * \usedin CanSM_MainFunction, CanSM_ControllerModeIndication, CanSM_StartWakeupSources, CanSM_StopWakeupSources, CanSM_Init
 * \exclude CAN interrupts
 * \length LONG This exclusive area covers calls to several BSW functions.
 * \endexclusivearea
 *
 * \exclusivearea CANSM_EXCLUSIVE_AREA_5
 * Ensures consistency while performing state changes
 * \protects CanSM_ChannelVarRecord
 * \usedin CanSM_ControllerModeIndication, CanSM_SetEcuPassive, CanSM_StartWakeupSources, CanSM_StopWakeupSources
 * \exclude CanSM_RequestComMode, CanSM_MainFunction, CanSM_ControllerModeIndication
 * \length LONG This exclusive area covers calls to several BSW functions.
 * \endexclusivearea
 *
 * \exclusivearea CANSM_EXCLUSIVE_AREA_6
 * Ensures consistency of state which is indication to the BswM.
 * \protects CanSM_ChannelVarRecord
 * \usedin CanSM_SetBaudrate, CanSM_ChangeBaudrate
 * \exclude CanSM_RequestComMode, CanSM_ControllerBusOff, CanSM_MainFunction, CanSM_ControllerModeIndication, CanSM_SetBaudrate, CanSM_ChangeBaudrate
 * \length SHORT Only variables are written.
 * \endexclusivearea
 *
 *
 */


# define CANSM_STOP_SEC_CODE
# include "MemMap.h"  /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* end if not defined ( CANSM_H ) */

/**********************************************************************************************************************
 *  END OF FILE: CanSM.h
 *********************************************************************************************************************/

