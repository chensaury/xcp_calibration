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
/**         \file  ComM.h
 *         \brief  Communication Manager ASR4
 *
 *       \details  Header of the Autosar Communication Manager
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
  AUTHOR IDENTITY
-----------------------------------------------------------------------------------------------------------------------
  Name                          Initials      Company
-----------------------------------------------------------------------------------------------------------------------
  Michael Schligerski           vismih        Vector Informatik GmbH
  Pavol Marko                   vispmo        Vector Informatik GmbH
-----------------------------------------------------------------------------------------------------------------------
  REVISION HISTORY
-----------------------------------------------------------------------------------------------------------------------
  Version   Date        Author  Change Id     Description
-----------------------------------------------------------------------------------------------------------------------
  01.00.00  2012-06-14  vismih  ESCAN00058535 Implementation according to ASR 4.0.3
  01.00.01  2012-10-18  vismih  ESCAN00062348 Compiler error: Cannot open include file 'Nm.h'
                                ESCAN00061391 Compiler warning: unused variable 'ComM_FullComRequestors'
                                ESCAN00061400 Compiler warning: unused variable 'ComM_StateChange'
  01.01.00  2012-12-07  vismih  ESCAN00061388 DET errors reported when shutting down communication on LIN channel with Nm
                                ESCAN00062059 AR4-278: Add Port Interface of ComM_CurrentChannelRequest
                                ESCAN00063511 Compiler warning: more than one declaration of 'Rte_ModeType_ComMMode'
  01.02.00  2013-04-12  vismih  ESCAN00059545 BETA version - no series production allowed
                                ESCAN00064311 AR4-325: Implement Post-Build Loadable
                                ESCAN00065236 BswM gets notified about bus mode, which is not yet provided by the BusSM
                                ESCAN00066281 Various small improvements and optimizations
                                ESCAN00066282 NM Message Reception in Silent Mode leads to DET error and missing NM Tx Message
                                ESCAN00066290 ECU does not send Nm messages on a channel while ComM channel user requests FULL_COM
                                ESCAN00066311 Shutdown synchronisation is shortened or delayed depending on timing conditions
                                ESCAN00067357 Partial Network does not enter No Communication mode again when Pnc Prepare Sleep Timer is 0 and external wake-up occurred
                                ESCAN00067386 Network with partial networking does not enter sleep
                                ESCAN00067423 User of a Partial Network is not notified about a new communication mode
  02.00.00 2013-09-27   vismih  ESCAN00068132 DET error occurs on passive startup of NM (woken up by another NM message during prepare sleep)
                                ESCAN00068871 Missing DET check inside the function ComM_RequestComMode
                                ESCAN00068896 Mode Limitation API does not return the correct return value if the request is not accepted
                                ESCAN00068902 Prevent Wake-up API does not return the correct return value if the request is not accepted
                                ESCAN00069043 AR4-478: Support EthSM
                                ESCAN00069394 Added PC-lint error inhibition options
                                ESCAN00070962 MISRA deviation: MISRA-C:2004 Code Metrics
                                ESCAN00071329 AR4-438: Support for J1939
                                ESCAN00071488 MISRA deviation: MISRA-C:2004 Rule 14.3
  02.01.00 2014-02-07   vismih  ESCAN00072395 Removed unused memory sections and class
                                ESCAN00072736 LIN communication channel does not enter COMM_NO_COMMUNICATON
                                ESCAN00072762 Report Det error if diagnostic communication is requested or released on a channel with Nm PASSIVE
                                ESCAN00073325 Performance improvement for gateways with Partial Networking
                                ESCAN00073488 Code optimizations to improve run-time behavior and ROM usage
  03.00.00 2014-05-16   vismih  ESCAN00075473 Changed access on generated variables and constants due to introduction of ComStackLib
                                ESCAN00075701 Memory class qualifiers were conformed to the Vector standard
                                ESCAN00076098 Compiler error: 'Nm_NetworkRequest' undefined
  03.01.00 2014-07-11   vismih/ ESCAN00077029 Adapted generation and usage of PNC Signals, FullCommReqeust variables for Post-Build Selectable usecase
                        vispmo  ESCAN00076156 Improve Include Hierarchy of ComM
                                ESCAN00076857 AR4-776: Add Support of COMM_BUS_TYPE_INTERNAL
                                ESCAN00077600 ECU does not enter sleep when a PNC is requested and released after an external wake-up
                                ESCAN00077624 Support Mode Limitation without ComMGlobalNvMBlockDescriptor
                                ESCAN00077950 ComM_Inhibition shall not have STATIC linkage to be writeable by NvM
  03.02.00 2015-01-26   vismih  ESCAN00080440 MISRA deviation: MISRA-C:2004 Rule 5.1 and 19.7
                                ESCAN00080884 Support variance for ComMUser
  04.00.00 2015-02-18   vismih  ESCAN00076865 FEAT-111: add support for VAP partial networking use case
                                ESCAN00081330 FEAT-1114: Realization OSEK-NM
  04.00.01 2015-03-26   vismih  ESCAN00082101 Compiler error: the macro 'COMM_PNC_PS_TIMER' is not defined
  05.00.00 2015-06-21   vismih  ESCAN00080279 FEAT-427: SafeBSW Step 1
                                ESCAN00081767 FEAT-1275: SafeBSW Step 2
                                ESCAN00083603 FEAT-1440: Partial Network routing/coordination limitation
  05.00.01 2015-11-05   vismih  ESCAN00085722 Compiler warning: 'channel' unreferenced formal parameter
                                ESCAN00086538 FEAT-1275: SafeBSW Step 2 (completion)
  06.00.00 2015-11-27   vismih  ESCAN00085680 FEAT-1492: Support Ford SDLC: NM Gateway and Coordination
                                ESCAN00086618 ComM state does not reflect a pending channel wake-up
                                ESCAN00086661 ComM state does not reflect a pending user communication request
                                ESCAN00086915 The return value of NmIf APIs shall not be evaluated
  07.00.00 2016-02-26   vismih  ESCAN00087541 Compiler warning: condition is always true
                                ESCAN00087791 FEAT-1688: SafeBSW Step 4
                                ESCAN00088563 FEAT-598: Extended RAM Check
  07.00.01 2016-04-13   vismih  ESCAN00089461 Compiler warning: CanSM_RamCheckStatus is undefined
                                ESCAN00089740 FEAT-1688: SafeBSW Step 5
  07.00.02 2016-05-11   vismih  ESCAN00090228 FEAT-1688: SafeBSW Step 5 (completion)
  07.00.03 2016-06-24   vismih  ESCAN00090163 Inhibition Counter value is higher than expected
                                ESCAN00090714 Extended generation of channel-based variable arrays by ComStackLib
  07.01.00 2016-08-05   vismih  ESCAN00091346 FEAT-1948: provided new APIs ComM_GetDcmRequestStatus() and ComM_GetMinFullComModeTimerStatus()
  08.00.00 2016-10-06   vismih  FEATC-60: FEAT-2039: Support Reset After Forcing NoComm according to ASR4.2.2
                                FEATC-268: FEAT-1454: Configuration of Switch Ports (switchable per PNC)
                                ESCAN00090162 Pnc To Channel Routing Limitation is not considered by ComM_GetState()
                                ESCAN00091475 Channel with Nm Variant LIGHT does not enter NO COMMUNICATION after a wake-up on bus event
                                ESCAN00092198 ComM_GetCurrentComMode() and ComM_GetRequestedComMode() return COMM_FULL_COMMUNICATION if user is not attached to any Channel or PNC
  08.01.00 2017-01-13   vismih  ESCAN00092692 ComM_MainFunction() shall not report Det error if ComM is not initialized
                                ESCAN00093096 Compiler warning: truncating assignment
                                ESCAN00094086 Improved QAC and PClint compliance
  08.01.01 2017-08-08   vismih  ESCAN00094464 NvM data is not stored after calling ComM_DeInit()
                                STORYC-2178: Consistently used ComStackLib types to support uint16 indexes
  09.00.00 2017-10-26   vismih  ESCAN00093702: PNC Wake-up Indication does not work as specified in AUTOSAR
  09.00.01 2018-03-12   vismih  ESCAN00096807: Compiler warning: possible loss of data due to implicit cast from uint16 to uint8
**********************************************************************************************************************/

#ifndef COMM_H
# define COMM_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "ComM_Lcfg.h"                          /* Include ComM configuration header */
# include "ComM_PBcfg.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* ##V_CFG_MANAGEMENT ##CQProject : Ccl_Asr4ComMCfg5 CQComponent : Implementation */
# define CCL_ASR4COMMCFG5_VERSION                (0x0900u)
# define CCL_ASR4COMMCFG5_RELEASE_VERSION        (0x01u)

/* Vendor and module identification */
# define COMM_VENDOR_ID                          (30u)
# define COMM_MODULE_ID                          (12u)

/* ----- Component version information (decimal version of ALM implementation package) ----- */
# define COMM_SW_MAJOR_VERSION                   (CCL_ASR4COMMCFG5_VERSION >> 8)
# define COMM_SW_MINOR_VERSION                   (CCL_ASR4COMMCFG5_VERSION & 0x00FFu)
# define COMM_SW_PATCH_VERSION                   (CCL_ASR4COMMCFG5_RELEASE_VERSION)

/* AUTOSAR Software specification version information */
# define COMM_AR_RELEASE_MAJOR_VERSION           (4u)
# define COMM_AR_RELEASE_MINOR_VERSION           (0u)
# define COMM_AR_RELEASE_REVISION_VERSION        (3u)

# define COMM_INSTANCE_ID_DET                    (0u)

/* ----- Error codes ----- */
# define COMM_E_NO_ERROR                         (0x00u) /*!< used to check if no error occurred - use a value unequal to any error code */
# define COMM_E_NOT_INITED                       (0x01u) /*!< Error code: API service used without module initialization */
# define COMM_E_WRONG_PARAMETERS                 (0x02u) /*!< Error code: API service used with wrong parameters */
# define COMM_E_ERROR_IN_PROV_SERVICE            (0x03u) /*!< Error code: Provided API services of other module returns with an error */
# define COMM_E_NOSUPPORTED_MODECHANGE           (0x04u) /*!< Error code: ComM is trying to perform a mode change which is not supported */
# define COMM_E_DIAGNOSTIC_NOT_SUPPORTED         (0x05u) /*!< Error code: Diagnostic communication is requested or released on a channel where diagnostic is not supported */
# define COMM_E_ALREADY_INITIALIZED              (0x06u) /*!< Error code: The service ComM_Init() is called while the module is already initialized  */
# define COMM_E_WRONG_GENERATED_DATA             (0x07u) /*!< Error code: Check of generated data has failed */

/* ----- API service IDs ----- */
# define COMM_SID_INIT                           (0x01u) /*!< Service ID: ComM_Init() */
# define COMM_SID_DEINIT                         (0x02u) /*!< Service ID: ComM_DeInit() */
# define COMM_SID_GETSTATUS                      (0x03u) /*!< Service ID: ComM_GetStatus() */
# define COMM_SID_GETSTATE                       (0x34u) /*!< Service ID: ComM_GetState() */
# define COMM_SID_GETINHIBITIONSTATUS            (0x04u) /*!< Service ID: ComM_GetInhibitionStatus() */
# define COMM_SID_REQUESTCOMMODE                 (0x05u) /*!< Service ID: ComM_RequestComMode() */
# define COMM_SID_GETMAXCOMMODE                  (0x06u) /*!< Service ID: ComM_GetMaxComMode() */
# define COMM_SID_GETREQUESTEDCOMMODE            (0x07u) /*!< Service ID: ComM_GetRequestedComMode() */
# define COMM_SID_GETCURRENTCOMMODE              (0x08u) /*!< Service ID: ComM_GetCurrentComMode() */
# define COMM_SID_PREVENTWAKEUP                  (0x09u) /*!< Service ID: ComM_PreventWakeUp() */
# define COMM_SID_LIMITCHANNELTONOCOMMODE        (0x0Bu) /*!< Service ID: ComM_LimitChannelToNoComMode() */
# define COMM_SID_LIMITECUTONOCOMMODE            (0x0Cu) /*!< Service ID: ComM_LimitECUToNoComMode() */
# define COMM_SID_READINHIBITCOUNTER             (0x0Du) /*!< Service ID: ComM_ReadInhibitCounter() */
# define COMM_SID_RESETINHIBITCOUNTER            (0x0Eu) /*!< Service ID: ComM_ResetInhibitCounter() */
# define COMM_SID_SETECUGROUPCLASSIFICATION      (0x0Fu) /*!< Service ID: ComM_SetECUGroupClassification() */
# define COMM_SID_GETVERSIONINFO                 (0x10u) /*!< Service ID: ComM_GetVersionInfo() */
# define COMM_SID_MAINFUNCTION                   (0x60u) /*!< Service ID: ComM_MainFunction() */
# define COMM_SID_COMMUNICATIONALLOWED           (0x35u) /*!< Service ID: ComM_CommunicationAllowed() */
# define COMM_SID_LIMITPNCTOCHANNELROUTING       (0x36u) /*!< Service ID: ComM_LimitPncToChannelRouting() */
# define COMM_SID_GETDCMREQUESTSTATUS            (0x37u) /*!< Service ID: ComM_GetDcmRequestStatus() */
# define COMM_SID_GETMINFULLCOMMODETIMERSTATUS   (0x38u) /*!< Service ID: ComM_GetMinFullComModeTimerStatus() */

/* ----- Callback function service IDs ----- */
# define COMM_SID_CBK_NM_NETWORKSTARTINDICATION  (0x15u) /*!< Service ID: ComM_Nm_NetworkStartIndication() */
# define COMM_SID_CBK_NM_NETWORKMODE             (0x18u) /*!< Service ID: ComM_Nm_NetworkMode() */
# define COMM_SID_CBK_NM_PREPAREBUSSLEEPMODE     (0x19u) /*!< Service ID: ComM_Nm_PrepareBusSleepMode() */
# define COMM_SID_CBK_NM_BUSSLEEPMODE            (0x1Au) /*!< Service ID: ComM_Nm_BusSleepMode() */
# define COMM_SID_CBK_NM_RESTARTINDICATION       (0x1Bu) /*!< Service ID: ComM_Nm_RestartIndication() */
# define COMM_SID_CBK_NM_STATECHANGENOTIFICATION (0x1Cu) /*!< Service ID: ComM_Nm_StateChangeNotification() */
# define COMM_SID_CBK_DCM_ACTIVEDIAGNOSTIC       (0x1Fu) /*!< Service ID: ComM_DCM_ActiveDiagnostic() */
# define COMM_SID_CBK_DCM_INACTIVEDIAGNOSTIC     (0x20u) /*!< Service ID: ComM_DCM_InactiveDiagnostic() */
# define COMM_SID_CBK_ECUM_WAKEUPINDICATION      (0x2Au) /*!< Service ID: ComM_EcuM_WakeUpIndication() */
# define COMM_SID_CBK_ECUM_PNCWAKEUPINDICATION   (0x2Bu) /*!< Service ID: ComM_EcuM_PNCWakeUpIndication() */
# define COMM_SID_CBK_BUSSMMODEINDICATION        (0x33u) /*!< Service ID: ComM_BusSM_ModeIndication() */

/* advanced return type of the communication manager */
# define COMM_E_MODE_LIMITATION                  (Std_ReturnType)(2u) /*!< Mode is limited and cannot be requested by a ComM User */
# define COMM_E_UNINIT                           (Std_ReturnType)(3u) /*!< API called but ComM is not initialized */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

# define COMM_START_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/*! Status information of mode limitation and prevent wake-up (mode inhibition) */
extern VAR(ComM_InhibitionType, COMM_NVM_DATA)              ComM_Inhibition;

# define COMM_STOP_SEC_VAR_SAVED_ZONE0_UNSPECIFIED
 /* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 *  INTERNAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 * ComM_MainFunction()
 *********************************************************************************************************************/
/*! \brief       Function to perform channel-specific state transitions and state change notifications.
 *  \details     This function must be called cyclically with the configured channel-specific cycle time.
 *  \param[in]   Channel                 Valid channel identifier (network handle)
 *  \pre         -
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       SPEC-19840
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_MainFunction(NetworkHandleType Channel);

# define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define COMM_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/**********************************************************************************************************************
 * ComM_Init()
 *********************************************************************************************************************/
/*! \brief       Initialization function of the ComM
 *  \details     -
 *  \param[in]   ConfigPtr              Optional pointer to configuration data
 *  \pre         ComM must not be initialized
 *  \pre         The NVRAM Manager module has to be initialized
 *  \context     TASK
 *  \reentrant   FALSE
 *  \synchronous TRUE
 *  \trace       CREQ-102775
 *  \trace       SPEC-5254, SPEC-5139
*********************************************************************************************************************/
# if (COMM_INIT_POINTER_ENABLED == STD_ON)
extern FUNC(void, COMM_CODE) ComM_Init(P2CONST(ComM_ConfigType, AUTOMATIC, COMM_INIT_DATA) ConfigPtr);
# else
extern FUNC(void, COMM_CODE) ComM_Init(void);
# endif

/**********************************************************************************************************************
 * ComM_InitMemory()
 *********************************************************************************************************************/
/*! \brief       Function for initialization of ComM_InitStatus
 *  \details     Service to initialize module global variable ComM_InitStatus at power up. This function can be used to initialize the
 *               variables in *_INIT_* sections in case they are not initialized by the startup code.
 *               This function has to be called once during start-up and before ComM_Init() is called.
 *  \pre         -
 *  \context     TASK
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-102775
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_InitMemory(void);

/**********************************************************************************************************************
 * ComM_DeInit()
 *********************************************************************************************************************/
/*! \brief       This function stores non-volatile values in NVRAM. Additionally it de-initializes ComM and sets the
 *               initialization status to COMM_UNINIT if all channels are in state COMM_NO_COM_NO_PENDING_REQUEST.
 *  \details     -
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       CREQ-102778
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_DeInit(void);

/**********************************************************************************************************************
 * ComM_GetStatus()
 *********************************************************************************************************************/
/*! \brief       Queries the initialization status of the module.
 *  \details     -
 *  \param[in]   Status                  Valid pointer where the current ComM state shall be stored
 *  \return      E_OK                    Request is accepted
 *               E_NOT_OK                Invalid parameter
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-102775
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetStatus(P2VAR(ComM_InitStatusType, AUTOMATIC, COMM_APPL_VAR) Status);

/**********************************************************************************************************************
 * ComM_GetState()
 *********************************************************************************************************************/
/*! \brief       Queries the current communication state of the corresponding channel.
 *  \details     -
 *  \param[in]   Channel                 Valid channel identifier (network handle), can be found in ComM_Lcfg.h
 *  \param[out]  State                   Valid pointer where the current ComM state shall be stored
 *  \return      E_OK                    Request is accepted
 *               E_NOT_OK                Invalid parameter
 *               COMM_E_UNINIT           ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \note        The function is used by EcuM fixed and by BswM.
 *  \trace       CREQ-102779
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetState( NetworkHandleType Channel, P2VAR(ComM_StateType, AUTOMATIC, COMM_APPL_VAR) State);

/**********************************************************************************************************************
 * ComM_RequestComMode()
 *********************************************************************************************************************/
/*! \brief       Requesting of a Communication Mode by a user.
 *  \details     -
 *  \param[in]   User                    Valid handle of the User, can be found in ComM_Lcfg.h
 *  \param[in]   ComMode                 The requested communication mode (COMM_FULL_COMMUNICATION or COMM_NO_COMMUNICATION)
 *  \return      E_OK                    Request is accepted
 *               E_NOT_OK                Invalid parameter
 *               COMM_E_UNINIT           ComM is not initialized
 *               COMM_E_MODE_LIMITATION  COMM_FULL_COMMUNICATION is requested but mode limitation is active
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-1267
 *  \trace       SPEC-5108, SPEC-5440, SPEC-5434, SPEC-5358, SPEC-5112, SPEC-5082, SPEC-5099, SPEC-5094, SPEC-5089
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_RequestComMode(ComM_UserHandleType User, ComM_ModeType ComMode);

/**********************************************************************************************************************
 * ComM_GetMaxComMode()
 *********************************************************************************************************************/
/*! \brief       Function to query the maximum allowed communication mode of the corresponding user.
 *  \details     -
 *  \param[in]   User                   Valid handle of the User, can be found in ComM_Lcfg.h
 *  \param[out]  ComMode                Valid pointer where to store the maximal communication mode of the given user
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               Invalid parameter
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-1267
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMaxComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);

/**********************************************************************************************************************
 * ComM_GetRequestedComMode()
 *********************************************************************************************************************/
/*! \brief       Function to query the requested communication mode of the corresponding user.
 *  \details     -
 *  \param[in]   User                   Valid handle of the User, can be found in ComM_Lcfg.h
 *  \param[out]  ComMode                Valid pointer where to store the requested communication mode of the given user
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               Invalid parameter
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-1267
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetRequestedComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);

/**********************************************************************************************************************
 * ComM_GetCurrentComMode()
 *********************************************************************************************************************/
/*! \brief       Function to query the current communication mode of the corresponding user.
 *  \details     -
 *  \param[in]   User                   Valid handle of the User, can be found in ComM_Lcfg.h
 *  \param[out]  ComMode                Valid pointer where to store the current communication mode of the given user
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               Invalid parameter
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       SPEC-5091
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetCurrentComMode(ComM_UserHandleType User, P2VAR(ComM_ModeType, AUTOMATIC, COMM_APPL_VAR) ComMode);

/**********************************************************************************************************************
 * ComM_GetInhibitionStatus()
 *********************************************************************************************************************/
/*! \brief       This function gets the current inhibition status of the given channel.
 *  \details     -
 *  \param[in]   Channel                 Valid channel identifier (network handle), can be found in ComM_Lcfg.h
 *  \param[in]   Status                  Valid pointer where the inhibition status shall be stored
 *  \return      E_OK                    Request is accepted
 *               E_NOT_OK                Invalid parameter
 *               COMM_E_UNINIT           ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetInhibitionStatus( NetworkHandleType Channel, P2VAR(ComM_InhibitionStatusType, AUTOMATIC, COMM_APPL_VAR) Status);

/**********************************************************************************************************************
 * ComM_PreventWakeUp()
 *********************************************************************************************************************/
/*! \brief       Requests or releases Prevent Wake-up for a ComM channel
 *  \details     -
 *  \param[in]   Channel                Valid channel identifier (network handle), can be found in ComM_Lcfg.h
 *  \param[in]   Status                 TRUE: request Wake-up Inhibition
 *                                      FALSE: release Wake-up Inhibition
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               Request is ignored if one of the following occurs
 *                                      - Channel parameter is invalid or
 *                                      - 'Wake-Up Inhibition Enabled' is de-activated in the module configuration or
 *                                      - 'ECU Group Classification' does not support Prevent Wake-Up
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       SPEC-5113
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_PreventWakeUp( NetworkHandleType Channel, boolean Status);

/**********************************************************************************************************************
 * ComM_LimitChannelToNoComMode()
 *********************************************************************************************************************/
/*! \brief       Requests or releases Mode Limitation for a ComM channel
 *  \details     -
 *  \param[in]   Channel                Valid channel identifier (network handle), can be found in ComM_Lcfg.h
 *  \param[in]   Status                 TRUE: request Mode Limitation
 *                                      FALSE: release Mode Limitation
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               - the channel is not in state COMM_FULL_COM_NETWORK_REQUESTED or
 *                                      - the channel has Nm Variant NONE or
 *                                      - ECU Group Classification supports Mode Limitation
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
 *  \trace       SPEC-5453, SPEC-5433
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitChannelToNoComMode( NetworkHandleType Channel, boolean Status);

/**********************************************************************************************************************
 * ComM_LimitECUToNoComMode()
 *********************************************************************************************************************/
/*! \brief       Requests or releases Mode Limitation for all ComM channels
 *  \details     -
 *  \param[in]   Status                 TRUE: request Mode Limitation
 *                                      FALSE: release Mode Limitation
 *  \return      E_OK                   Request is accepted
 *  \return      E_NOT_OK               Request is ignored if one of the following occurs
 *                                      - Mode Limitation to NO_COM is disabled or
 *                                      - ECU Group Classification does not support Mode Limitation or
 *                                      - The API ComM_LimitChannelToNoComMode returned E_NOT_OK for at least one channel
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   FALSE
 *  \synchronous FALSE
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitECUToNoComMode(boolean Status);

/**********************************************************************************************************************
 * ComM_ReadInhibitCounter()
 *********************************************************************************************************************/
/*! \brief       Queries the inhibition counter, which is number of rejected Full Communication user requests.
 *  \details     -
 *  \param[out]  CounterValue           Valid pointer where the value of inhibition counter shall be stored
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               Invalid parameter
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-1301
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ReadInhibitCounter(P2VAR(uint16, AUTOMATIC, COMM_APPL_VAR) CounterValue);

/**********************************************************************************************************************
 * ComM_ResetInhibitCounter()
 *********************************************************************************************************************/
/*! \brief       Resets the inhibition counter, which is number of rejected Full Communication user requests.
 *  \details     -
 *  \return      E_OK                   Request is accepted
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-1301
 *  \trace       SPEC-5099
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_ResetInhibitCounter(void);

/**********************************************************************************************************************
 * ComM_SetECUGroupClassification()
 *********************************************************************************************************************/
/*! \brief       Sets the value of ECU group classification status during runtime. The value is stored non-volatile.
 *  \details     -
 *  \param[in]   Status                 The value of ECU group classification. Defines Mode Inhibition types the ECU is affected by:
 *                                      0 - ECU is not affected by mode inhibition
 *                                      1 - ECU is affected by Wake-up Inhibition only
 *                                      2 - ECU is affected by Mode Limitation only
 *                                      3 - ECU is affected by both inhibition types
 *  \return      E_OK                   Request is accepted
 *               E_NOT_OK               Invalid parameter
 *               COMM_E_UNINIT          ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \trace       CREQ-1302
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_SetECUGroupClassification(ComM_InhibitionStatusType Status);

# if (COMM_VERSION_INFO_API == STD_ON)
/**********************************************************************************************************************
 * ComM_GetVersionInfo()
 *********************************************************************************************************************/
/*! \brief       Provides the version information of the module.
 *  \details     -
 *  \param[in]   Versioninfo             Valid pointer where the version information shall be stored
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-102776
*********************************************************************************************************************/
extern FUNC(void, COMM_CODE) ComM_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, COMM_APPL_VAR) Versioninfo);
# endif

# if (COMM_PNC_TO_CHANNEL_ROUTING_LIMITATION_ENABLED == STD_ON)
/**********************************************************************************************************************
 * ComM_LimitPncToChannelRouting()
 *********************************************************************************************************************/
/*! \brief       Service to set the status of PNC to Channel Routing Limitation
 *  \details     The function stores the limitation status for the given PNC and Channel. The status will be used in combination with
                 some other conditions (current Nm state, receiving of ERA signal) to decide whether the routing of PNC information on
                 the channel is active or not. The decision and corresponding actions are taken in the next ComM_MainFunction().
 *  \param[in]   Pnc                    Valid PNC identifier
 *  \param[in]   Channel                Valid channel identifier (network handle)
 *  \param[in]   Status                 TRUE: limitation of the PNC on the Channel shall be activated
 *                                      FALSE: limitation of the PNC on the Channel shall be de-activated (default status after initialization)
 *  \return      E_OK                   parameters are correct, ComM accepted the request
 *               E_NOT_OK               parameters are incorrect, ComM discarded the request
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous FALSE
 *  \trace       CREQ-109320
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_LimitPncToChannelRouting( PNCHandleType Pnc, NetworkHandleType Channel, boolean Status );
# endif

#if (COMM_DCM_INDICATION == STD_ON)
/**********************************************************************************************************************
 * ComM_GetDcmRequestStatus()
 *********************************************************************************************************************/
/*! \brief       Queries the status of DCM active diagnostic request of the corresponding channel.
 *  \details     -
 *  \param[in]   Channel                 Valid channel identifier (network handle)
 *  \param[out]  Status                  Valid pointer where the request status shall be stored
 *                                       TRUE: DCM indicated active diagnostic
 *                                       FALSE: otherwise
 *  \return      E_OK                    Request is accepted
 *               E_NOT_OK                Invalid parameter
 *               COMM_E_UNINIT           ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      (COMM_DCM_INDICATION == STD_ON)
 *  \trace       CREQ-102677
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetDcmRequestStatus(NetworkHandleType Channel, P2VAR(boolean, AUTOMATIC, COMM_APPL_VAR) Status);
# endif

# if (COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON)
/**********************************************************************************************************************
 * ComM_GetMinFullComModeTimerStatus()
 *********************************************************************************************************************/
/*! \brief       Queries the status of Min Full Com Mode Timer of the corresponding channel.
 *  \details     -
 *  \param[in]   Channel                 Valid channel identifier (network handle)
 *  \param[out]  Status                  Valid pointer where the timer status shall be stored
 *                                       TRUE: Min Full Com Mode Timer is running
 *                                       FALSE: otherwise
 *  \return      E_OK                    Request is accepted
 *               E_NOT_OK                Invalid parameter
 *               COMM_E_UNINIT           ComM is not initialized
 *  \pre         -
 *  \context     ANY
 *  \reentrant   TRUE
 *  \synchronous TRUE
 *  \config      (COMM_MINFULLCOMTIMEOFCHANNEL == STD_ON)
 *  \trace       CREQ-1306
*********************************************************************************************************************/
extern FUNC(Std_ReturnType, COMM_CODE) ComM_GetMinFullComModeTimerStatus(NetworkHandleType Channel, P2VAR(boolean, AUTOMATIC, COMM_APPL_VAR) Status);
# endif

# define COMM_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
# include "MemMap.h"

/*!
 * \exclusivearea COMM_EXCLUSIVE_AREA_0
 * Protects the ComM active channel state user request status.
 * \protects ComM_ActiveComMode, ComM_UserReqFullCom, ComM_UserReqPncFullCom
 * \usedin ComM_CalculateHighestComMode, ComM_CalculateHighestPNComMode, ComM_TF_SiCom_NoCom, ComM_RequestComMode, 
 *         ComM_GetRequestedComMode, ComM_GetCurrentComMode, ComM_PreventWakeUp, ComM_LimitChannelToNoComMode
 * \exclude -
 * \length LONG This exclusive area covers calls to several sub-functions.
 * \endexclusivearea
 */

/*!
 * \exclusivearea COMM_EXCLUSIVE_AREA_1
 * Protects the ComM active channel state from becoming inconsistent while execution of the main function.
 * \protects ComM_ActiveComMode
 * \usedin ComM_MainFunction
 * \exclude Nm_MainFunction, BusNm_MainFunction (e.g. CanNm_MainFunction), BusSM_MainFunction (e.g. CanSM_MainFunction)
 * \length LONG This exclusive area covers calls to several sub-functions.
 * \endexclusivearea
 */

#endif  /* COMM_H */

/**********************************************************************************************************************
  END OF FILE: ComM.H
**********************************************************************************************************************/

