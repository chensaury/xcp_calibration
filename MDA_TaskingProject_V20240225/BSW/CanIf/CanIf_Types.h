/********************************************************************************************************************
|    File Name: CanIf_Types.h
|
|  Description: Type definitions of the AUTOSAR CAN Interface
|--------------------------------------------------------------------------------------------------------------------
|               C O P Y R I G H T
|--------------------------------------------------------------------------------------------------------------------
| Copyright (c) 1996-2018 by Vector Informatik GmbH.       All rights reserved.
|
| This software is copyright protected and proprietary
| to Vector Informatik GmbH. Vector Informatik GmbH
| grants to you only those rights as set out in the
| license conditions. All other rights remain with
| Vector Informatik GmbH.
|
|--------------------------------------------------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|--------------------------------------------------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Rna          Ruediger Naas             Vector Informatik GmbH
| Seu          Eugen Stripling           Vector Informatik GmbH
| Tkr          Torsten Kercher           Vector Informatik GmbH
| Gaz          Carsten Gauglitz          Vector Informatik GmbH
|--------------------------------------------------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|--------------------------------------------------------------------------------------------------------------------
| Date        Version   Author  Description
| ----------  --------  ------  -------------------------------------------------------------------------------------
| 2012-07-02  05.00.00  Rna     ESCAN00060132: Support ASR 4.0 Rev 3
| 2013-03-05  05.01.00  Seu     ESCAN00064304: AR4-325: Implement Post-Build Loadable
| 2013-04-04            Rna     ESCAN00066285: Remove MSR features: CANIF_ASYNCH_TRCV_HANDLING and CANIF_TRCV_WAKEUPSTATETRANSITION
|                               ESCAN00066419: Service ID for APIs CanIf_CheckBaudrate is wrong
|                               ESCAN00066898: Compiler error: Undefined type CanIf_CanTrcv_CheckWakeFlagFctType/CanIf_CanTrcv_ClearTrcvWufFlagFctType
| 2013-07-12  06.00.00  Seu     ESCAN00068982: Generator version check shall check against the generator compatibility version
| 2013-09-13            Rna     ESCAN00068790: AR4-438: Dynamic address lookup table
|                       Rna     ESCAN00069108: AR4-397: CANFD Mode 1 (8 Byte Payload) - incl. Baudratenumschaltung
|                       Rna     ESCAN00070536: AR4-450: Usage of section PBCFG in PB files
| 2013-12-16  06.01.00  Seu     ESCAN00072681: Adapt the transceiver handling in order to comply with changes done for fix of ESCAN00072448
| 2013-12-19  06.02.00  Seu     ESCAN00070548: AR4-345: Implement PF4_PostBuildSelectable
| 2014-04-01  06.03.00  Seu     ESCAN00074690: Support generated code provided by ComStackLib
| 2014-05-23            Rna     ESCAN00064668: Compiler warning: cast truncates constant value
| 2014-07-09  06.04.00  Rna     ESCAN00076359: AR4-712 - Multiple CAN driver support
| 2014-09-23            Seu     ESCAN00078027: AR4-698: Post-Build Selectable (Identity Manager)
| 2014-11-26  06.05.00  Rna     ESCAN00079714: FEAT-516: Fixing CanIf address translation tables for multi-channel usage
| 2014-11-25  06.06.00  Rna     ESCAN00079793: FEAT-63: Support CAN-FD Mode 2 for communication and diagnostics
| 2015-02-09            Rna     ESCAN00081123: Check the size of the type "Can_IdType" for the function CanIf_Init()
| 2015-03-26  06.07.00  Seu     ESCAN00080296: FEAT-427: SafeBSW Step I
| 2015-08-05            Rna     ESCAN00084372: Changes for MISRA compliance
| 2015-09-15  06.08.00  Seu     ESCAN00084557: Changes for SafeBSW
| 2016-01-11  06.09.00  Rna     ESCAN00086059: FEAT-1429: Gateway Optimization
| 2016-01-26  06.09.01  Seu     ESCAN00087755: BasicCAN message is NOT received /  reported as wrong Rx-PDU to upper layer
| 2016-02-22  06.10.00  Rna     ESCAN00088265: FEAT-598: Extended RAM Check
| 2016-03-15            Rna     ESCAN00088887: [Only Multiple CAN driver]: BasicCAN-Tx-PDU is lost in case of CAN-hardware object is busy
| 2016-06-23  06.11.00  Seu     ESCAN00090492: FEAT-1914: Data checksum
| 2016-09-27  06.12.00  Rna     ESCAN00091556: FEAT-2024: Support simultaneous CAN/CAN and DoIP/CAN diagnostic routing via CAN-IF
| 2017-02-28  06.13.00  Rna     ESCAN00094118: Encapsulate EcuM_Cbk.h by corresponding switches
| 2018-02-21  06.14.00  Tkr     STORYC-3880:   Extend CanIfRxPduUserRxIndicationType
| 2018-05-03  06.14.01  Gaz     ESCAN00099183: A Gateway routes an incoming CAN FD frame to a CAN FD subnet as CAN2.0 frame.
| 2018-07-31  06.15.00  Gaz     STORYC-580:    Solve ToDos
|*******************************************************************************************************************/
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 3453 EOF */ /* MD_MSR_19.7 */

/*******************************************************************************************************************/
/*  Defines                                                                                                        */
/*******************************************************************************************************************/

/* Configuration variants */
#define CANIF_CFGVAR_PRECOMPILETIME           1u
#define CANIF_CFGVAR_LINKTIME                 2u
#define CANIF_CFGVAR_POSTBUILDTIME            3u

/* Version */

/* Version of CanIf_Types header */
#define CANIF_TYPES_MAJOR_VERSION             0x06u
#define CANIF_TYPES_MINOR_VERSION             0x15u
#define CANIF_TYPES_PATCH_VERSION             0x00u


/* Development Errors */
/* \trace SPEC-1894 */
#define CANIF_E_PARAM_CANID                   10u
#define CANIF_E_PARAM_DLC                     11u
#define CANIF_E_PARAM_HRH                     12u
#define CANIF_E_PARAM_LPDU                    13u
#define CANIF_E_PARAM_CONTROLLER              14u
#define CANIF_E_PARAM_CONTROLLERID            15u
#define CANIF_E_PARAM_WAKEUPSOURCE            16u
#define CANIF_E_PARAM_TRCV                    17u
#define CANIF_E_PARAM_TRCVMODE                18u
#define CANIF_E_PARAM_TRCVWAKEUPMODE          19u
#define CANIF_E_PARAM_POINTER                 20u
#define CANIF_E_PARAM_CTRLMODE                21u
#define CANIF_E_PARAM_PDU_MODE                22u

#define CANIF_E_UNINIT                        30u

#define CANIF_E_INVALID_TXPDUID               50u
#define CANIF_E_INVALID_RXPDUID               60u
#define CANIF_E_INVALID_DLC                   61u
#define CANIF_E_STOPPED                       70u
#define CANIF_E_NOT_SLEEP                     71u

/* Not defined by AUTOSAR */
#define CANIF_E_NO_ERROR                      0u
#define CANIF_E_INVALID_PDURECEPTIONMODE      44u
#define CANIF_E_CONFIG                        45u
#define CANIF_E_FATAL                         46u
#define CANIF_E_INVALID_SA                    47u
#define CANIF_E_INVALID_DA                    48u
#define CANIF_E_INVALID_CANIDTYPESIZE         49u
#define CANIF_E_INVALID_DLC_METADATA          50u

#define CANIF_E_FULL_TX_BUFFER_FIFO           51u /* FEAT-1429 */
#define CANIF_E_INVALID_DOUBLEHASH_CALC       52u /* ESCAN00087755 */

/* Module ID of CAN Interface */
#define CANIF_MODULE_ID                       60u

/* Vendor ID of CAN Interface */ /* CANIF726 */
#define CANIF_VENDOR_ID                       0x001Eu

/* Search algorithm */
#define CANIF_LINEAR                          1u
#define CANIF_BINARY                          2u
#define CANIF_DOUBLE_HASH                     3u


#define CanIf_TrcvIndex_INVALID               ((uint8)0xFFu)


/* API IDs for Error Reporting */
#define CANIF_INIT_API                        1u
/* #define CANIF_INITCONTROLLER_API              2u */
#define CANIF_SETCONTROLLERMODE_API           3u
#define CANIF_GETCONTROLLERMODE_API           4u
#define CANIF_TRANSMIT_API                    5u
#define CANIF_READRXDATA_API                  6u

/* #define CANIF_READTXNOTIFSTATUS_API           7u */
/* #define CANIF_READRXNOTIFSTATUS_API           8u */

#define CANIF_SETPDUMODE_API                  9u
#define CANIF_GETPDUMODE_API                  10u
#define CANIF_GETVERSIONINFO_API              11u

#define CANIF_SETDYNAMICTXID_API_ID           12u

#define CANIF_SETTRCVMODE_API                 13u
#define CANIF_GETTRCVMODE_API                 14u
#define CANIF_GETTRCVWAKEUPREASON_API         15u
#define CANIF_SETTRCVWAKEUPMODE_API           16u

#define CANIF_CHECKWAKEUP_API                 17u

#define CANIF_CHECKVALIDATIONUP_API           18u

#define CANIF_TXCONFIRMATION_API              19u
#define CANIF_RXINDICATION_API                20u

#define CANIF_CANCELTXCONFIRMATION_API        21u

#define CANIF_CONTROLLERBUSOFF_API            22u

#define CANIF_CONTROLLERMODEINDICATION_API    23u
#define CANIF_TRCVMODEINDICATION_API          24u

#define CANIF_GETTXCONFIRMATIONSTATE_API      25u

#define CANIF_CONFIRMPNAVAILABILITY_API       26u  /* 0x1A */
#define CANIF_BAUDRATECHECK_API               28u  /* 0x1C */
#define CANIF_BAUDRATECHANGE_API              27u  /* 0x1B */
#define CANIF_BAUDRATESET_API                 39u  /* 0x27 */

#define CANIF_CLEARTRCVWUFFLAG_API            30u
#define CANIF_CHECKTRCVWAKEFLAG_API           31u
#define CANIF_CLEARTRCVWUFFLAGINDICATION_API  32u
#define CANIF_CHECKTRCVWAKEFLAGINDICATION_API 33u

/* Not defined by AUTOSAR */
#define CANIF_RAMCHECKEXECUTE_API             249u  /* FEAT-598 */
#define CANIF_RAMCHECKENABLEMAILBOX_API       248u  /* FEAT-598 */
#define CANIF_RAMCHECKENABLECONTROLLER_API    247u  /* FEAT-598 */
#define CANIF_SETPDURECEPTIONMODE_API         246u  /* FEAT-2024 */
#define CANIF_RAMCHECKCORRUPTMAILBOX_API      245u  /* FEAT-598 */
#define CANIF_RAMCHECKCORRUPTCONTROLLER_API   244u  /* FEAT-598 */

#define CANIF_CANCELTRANSMIT_API              250u
#define CANIF_TXNOTIFICATION_API              251u

/* J1939 */
#define CANIF_SETADDRESSTABLEENTRY_API        252u
#define CANIF_RESETADDRESSTABLEENTRY_API      253u

#define CANIF_J1939_DYN_ADDR_DISABLED         0u
#define CANIF_J1939_DYN_ADDR_EXT_CANID        1u
#define CANIF_J1939_DYN_ADDR_MIXED_CANID      2u

/* hard coded array size */
#define CANIF_STATIC_BUFFER_SIZE              8u

/*******************************************************************************************************************/
/*  CanIf_Types.h is only allowed to be included by CanIf_Cfg.h                                                    */
/*******************************************************************************************************************/

#include "Can_GeneralTypes.h"
#if ((CANIF_WAKEUP_SUPPORT == STD_ON) || (CANIF_WAKEUP_VALIDATION == STD_ON) || (CANIF_CONFIG_VARIANT == CANIF_CFGVAR_POSTBUILDTIME))
# include "EcuM_Cbk.h"
#endif


/*******************************************************************************************************************/
/*  Compatibility / Defaults                                                                                       */
/*******************************************************************************************************************/
#if !defined (CANIF_PN_WU_TX_PDU_FILTER)
# error "CANIF_PN_WU_TX_PDU_FILTER is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_TRCV_HANDLING)
# error "CANIF_TRCV_HANDLING is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_PN_TRCV_HANDLING)
# error "CANIF_PN_TRCV_HANDLING is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_WAKEUP_VALIDATION)
# error "CANIF_WAKEUP_VALIDATION is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_SETDYNAMICTXID_API)
# error "CANIF_SETDYNAMICTXID_API is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_META_DATA_RX_SUPPORT)
# error "CANIF_META_DATA_RX_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_META_DATA_TX_SUPPORT)
# error "CANIF_META_DATA_TX_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_STATIC_FD_TXQUEUE)
# error "CANIF_STATIC_FD_TXQUEUE is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_MULTIPLE_CANDRV_SUPPORT)
# error "CANIF_MULTIPLE_CANDRV_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_CANCEL_SUPPORT_API)
# error "CANIF_CANCEL_SUPPORT_API is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_WAKEUP_SUPPORT)
# error "CANIF_WAKEUP_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_CHANGE_BAUDRATE_SUPPORT)
# error "CANIF_CHANGE_BAUDRATE_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_SET_BAUDRATE_API)
# error "CANIF_SET_BAUDRATE_API is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_J1939_DYN_ADDR_SUPPORT)
# error "CANIF_J1939_DYN_ADDR_SUPPORT is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CPU_TYPE)
# error "CPU_TYPE is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

#if !defined (CANIF_SEARCH_ALGORITHM)
# error "CANIF_SEARCH_ALGORITHM is undefined. Please check the reason why it is not generated and set the #define manually, if necessary!"
#endif

/* \trace SPEC-1836, changed to support non Vector CanDrv */
#if (CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON)
# define CanIf_HwHandleType uint16 
#else
# define CanIf_HwHandleType Can_HwHandleType
#endif


/*******************************************************************************************************************/
/*  Data types                                                                                                     */
/*******************************************************************************************************************/

/* \trace SPEC-5204 */

typedef enum 
{
  CANIF_CS_UNINIT = 0u,
  CANIF_CS_STOPPED,
  CANIF_CS_STARTED,
  CANIF_CS_SLEEP
} CanIf_ControllerModeType;


typedef enum 
{
  CANIF_SET_OFFLINE = 0u,
  CANIF_SET_RX_OFFLINE,
  CANIF_SET_RX_ONLINE,
  CANIF_SET_TX_OFFLINE,
  CANIF_SET_TX_ONLINE,
  CANIF_SET_ONLINE,
  CANIF_SET_TX_OFFLINE_ACTIVE,
#if (CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
  CANIF_SET_ONLINE_WAKF,
  CANIF_SET_TX_ONLINE_WAKF,
#endif
  CANIF_NO_MODE_PDU_SET_MODE_TYPE_END /* no PDU mode, is used to determine the size of CanIfState */
} CanIf_PduSetModeType;


typedef enum
{
  CANIF_GET_OFFLINE = 0u,
  CANIF_GET_RX_ONLINE,
  CANIF_GET_TX_ONLINE,
  CANIF_GET_ONLINE,
  CANIF_GET_OFFLINE_ACTIVE,
  CANIF_GET_OFFLINE_ACTIVE_RX_ONLINE, 
#if (CANIF_PN_WU_TX_PDU_FILTER == STD_ON)
  CANIF_GET_ONLINE_WAKF,              
  CANIF_GET_TX_ONLINE_WAKF,           
#endif
  CANIF_NO_MODE_PDU_GET_MODE_TYPE_END /* no PDU mode, is used to determine the size of CanIfState */
} CanIf_PduGetModeType;


typedef enum
{
  CANIF_RxBasicCANMailbox = 0u,
  CANIF_RxFullCANMailbox,
  CANIF_TxBasicCANMailbox,
  CANIF_TxFullCANMailbox,
  CANIF_UnusedCANMailbox
} CanIf_MailBoxTypeType;


typedef enum
{
  CanIf_SimpleRxIndicationLayout = 0u,
  CanIf_AdvancedRxIndicationLayout,
  CanIf_NmOsekRxIndicationLayout,
  CanIf_CddRxIndicationLayout
} CanIf_RxIndicationLayoutType;


typedef enum
{
  CANIF_NO_NOTIFICATION = 0u,
  CANIF_TX_RX_NOTIFICATION
} CanIf_NotifStatusType;

typedef enum 
{
  CANIF_WAKEUPREQUEST_NONE = 0u,
  CANIF_WAKEUPREQUEST_CAN  = 1u,
  CANIF_WAKEUPREQUEST_TRCV = 2u
} CanIf_WakeUpTargetType;

typedef enum
{
  CANIF_WUVALIDATION_IDLE     = 0u,
  CANIF_WUVALIDATION_ARMED    = 1u,
  CANIF_WUVALIDATION_DETECTED = 2u
} CanIf_WakeUpValidationStateType;

typedef enum
{
  CANIF_DO_TRANSMIT     = 0u,/*!< CANIF_DO_TRANSMIT */
  CANIF_DO_NOT_TRANSMIT = 1u /*!< CANIF_DO_NOT_TRANSMIT */
} CanIf_TransmitStateType;

typedef enum
{
  CANIF_MSG_TYPE_CAN = 0u,
  CANIF_MSG_TYPE_FD_CAN,
  CANIF_MSG_TYPE_NO_FD_CAN
} CanIf_MsgType;

typedef enum
{
  CANIF_RMT_RECEIVE_STOP      = 0u,
  CANIF_RMT_IGNORE_CONTINUE   = 1u
} CanIf_ReceptionModeType;

typedef struct sCanIf_RxSearchParamsType
{
  Can_IdType    eCanId;
  PduIdType     eRxPduId;
  PduIdType     eRxPduIdMatch;
#if (CANIF_RX_SEARCH_CONSIDER_MSG_TYPE == STD_ON) || (CANIF_META_DATA_RX_SUPPORT == STD_ON)
  CanIf_MsgType eRxMsgType;
#endif
  CanIf_HwHandleType eHrh;
  boolean       eContinueSearch;
} CanIf_RxSearchParamsType;

/* Type of confirmation function */
/* typedef void (*CanIf_TxConfirmationFctType)(PduIdType CanTxPduId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_TxConfirmationFctType) (VAR(PduIdType, AUTOMATIC) CanTxPduId);


/* Type of indication function */
/* Simple type for CanNm, PduR */
/* typedef void (*CanIf_SimpleRxIndicationFctType)(PduIdType CanRxPduId, const uint8 *CanSduPtr); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_SimpleRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(uint8, AUTOMATIC, CANIF_UL_STANDARD_VAR) CanSduPtr);

/* Advanced type for CanTP */
/* typedef void (*CanIf_AdvancedRxIndicationFctType)(PduIdType CanRxPduId, const PduInfoType *PduInfoPtr); */
/* PduInfoPtr is created on stack -> AUTOMATIC */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_AdvancedRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR) PduInfoPtr);

/* NmOsek type */
/* typedef void (*CanIf_NmOsekRxIndicationFctType)(PduIdType CanRxPduId, const uint8 *CanSduPtr, Can_IdType CanId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_NmOsekRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(uint8, AUTOMATIC, CANIF_UL_OSEKNM_VAR) CanSduPtr, VAR(Can_IdType, AUTOMATIC) CanId);

/* CDD type */
/* typedef void (*CanIf_CddRxIndicationFctType)(PduIdType CanRxPduId, const PduInfoType *PduInfoPtr, Can_IdType CanId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_CddRxIndicationFctType) (VAR(PduIdType, AUTOMATIC) CanRxPduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_UL_ADVANCED_VAR) PduInfoPtr, VAR(Can_IdType, AUTOMATIC) CanId);

/* CANIF687 */
/* typedef void (*CanIf_CtrlModeIndicationFctType) (uint8 ControllerId, CanIf_ControllerModeType ControllerMode); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_CtrlModeIndicationFctType) (VAR(uint8, AUTOMATIC) ControllerId, VAR(CanIf_ControllerModeType, AUTOMATIC) ControllerMode);

/* \trace SPEC-1839 */
/* typedef void (*CanIf_BusOffNotificationFctType)(uint8 ControllerId); */
typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_BusOffNotificationFctType) (VAR(uint8, AUTOMATIC) ControllerId);

#if (CANIF_WAKEUP_VALIDATION == STD_ON)
/* WakeUp Validation */
/* \trace SPEC-5053 */
/* typedef void (*CanIf_WakeUpValidationFctType)(EcuM_WakeupSourceType, CanWakeupEvents); */
typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_WakeUpValidationFctType) (VAR(EcuM_WakeupSourceType, AUTOMATIC) CanWakeupEvents);
#endif


#if (CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON)
/* typedef void (*CanIf_RamCheckCorruptMailboxIndFctType)(uint8 ControllerId, CanIf_HwHandleType HwHandle); */
typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_RamCheckCorruptMailboxIndFctType) (VAR(uint8, AUTOMATIC) ControllerId, VAR(CanIf_HwHandleType, AUTOMATIC) HwHandle);

/* typedef void (*CanIf_RamCheckCorruptControllerIndFctType)(uint8 ControllerId); */
typedef P2FUNC(void, CANIF_APPL_STATE_CODE, CanIf_RamCheckCorruptControllerIndFctType) (VAR(uint8, AUTOMATIC) ControllerId);
#endif /* (CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON) */


#if (CANIF_MULTIPLE_CANDRV_SUPPORT == STD_ON) /* function pointer definition needed if multiple CanDrivers used */
/* function pointer types needed for generated CanDriver function calls */

/* typedef Can_ReturnType (*CanIf_Can_SetControllerModeFctType) (Controller, Transition); */
typedef P2FUNC(Can_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_SetControllerModeFctType) (VAR(uint8, AUTOMATIC) Controller, VAR(Can_StateTransitionType, AUTOMATIC) Transition);

/* typedef Can_ReturnType (*CanIf_Can_WriteFctType) (Hth, PduInfo); */
typedef P2FUNC(Can_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_WriteFctType) (VAR(Can_HwHandleType, AUTOMATIC) Hth, P2CONST(Can_PduType, AUTOMATIC, CANIF_VAR_STACK) PduInfo);

# if (CANIF_CANCEL_SUPPORT_API == STD_ON)
/* typedef void (*CanIf_Can_CancelTxFctType) (Hth, PduId); */
typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_CancelTxFctType) (VAR(Can_HwHandleType, AUTOMATIC) Hth, VAR(PduIdType, AUTOMATIC) PduId);
# endif

# if (CANIF_WAKEUP_SUPPORT == STD_ON)
/* typedef Std_ReturnType (*CanIf_Can_CancelTxFctType) (Controller); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_CheckWakeupFctType) (VAR(uint8, AUTOMATIC) Controller);
# endif

# if (CANIF_CHANGE_BAUDRATE_SUPPORT == STD_ON)
/* typedef Std_ReturnType (*CanIf_Can_CheckBaudrateFctType) (Controller, Baudrate); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_CheckBaudrateFctType) (VAR(uint8, AUTOMATIC) Controller, CONST(uint16, AUTOMATIC) Baudrate);

/* typedef Std_ReturnType (*CanIf_Can_ChangeBaudrateFctType) (Controller, Baudrate); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_ChangeBaudrateFctType) (VAR(uint8, AUTOMATIC) Controller, CONST(uint16, AUTOMATIC) Baudrate);
# endif

# if (CANIF_SET_BAUDRATE_API == STD_ON)
/* typedef Std_ReturnType (*CanIf_Can_SetBaudrateFctType) (Controller, BaudRateConfigID); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_CANDRV_CODE, CanIf_Can_SetBaudrateFctType) (VAR(uint8, AUTOMATIC) Controller, VAR(uint16, AUTOMATIC) BaudRateConfigID);
# endif

# if (CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON)
/* typedef void (*CanIf_Can_RamCheckExecuteFctType) (ControllerId); */
typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_RamCheckExecuteFctType) (VAR(uint8, AUTOMATIC) Controller);

/* typedef void (*CanIf_Can_RamCheckEnableMailboxFctType) (ControllerId, HwHandle); */
typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_RamCheckEnableMailboxFctType) (VAR(Can_HwHandleType, AUTOMATIC) htrh);

/* typedef void (*CanIf_Can_RamCheckEnableControllerFctType) (ControllerId); */
typedef P2FUNC(void, CANIF_CBK_CANDRV_CODE, CanIf_Can_RamCheckEnableControllerFctType) (VAR(uint8, AUTOMATIC) Controller);
# endif /* (CANIF_EXTENDED_RAM_CHECK_SUPPORT == STD_ON) */

#endif


#if (CANIF_TRCV_HANDLING == STD_ON)
/* \trace SPEC-5279 */
/* typedef void (*CanIf_TrcvModeIndicationFctType) (uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_TrcvModeIndicationFctType) (VAR(uint8, AUTOMATIC) TransceiverId, VAR(CanTrcv_TrcvModeType, AUTOMATIC) TransceiverMode);

/* \trace SPEC-1967 */
/* typedef Std_ReturnType (*CanIf_CanTrcv_CheckWakeupFctType)(uint8 Transceiver); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_CheckWakeupFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex);

/* \trace SPEC-1967 */
/* typedef Std_ReturnType (*CanIf_CanTrcv_SetOpModeFctType)(uint8 Transceiver, CanTrcv_TrcvModeType OpMode); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_SetOpModeFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, VAR(CanTrcv_TrcvModeType, AUTOMATIC) OpMode);

/* \trace SPEC-1967 */
/* typedef Std_ReturnType (*CanIf_CanTrcv_GetOpModeFctType)(uint8 Transceiver, CanTrcv_TrcvModeType *OpMode); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_GetOpModeFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_STATE_VAR) OpMode);

/* \trace SPEC-1967 */
/* typedef Std_ReturnType (*CanIf_CanTrcv_GetBusWuReasonFctType)(uint8 Transceiver, CanTrcv_TrcvWakeupReasonType *Reason); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_GetBusWuReasonFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_STATE_VAR)Reason);

/* \trace SPEC-1967 */
/* typedef Std_ReturnType (*CanIf_CanTrcv_SetWakeupModeFctType)(uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode); */
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_SetWakeupModeFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);

# if (CANIF_PN_TRCV_HANDLING == STD_ON)
/* CANIF821 */
/* typedef void (*CanIf_ConfirmPnAvailabilityFctType) (uint8 TransceiverId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_ConfirmPnAvailabilityFctType) (VAR(uint8, AUTOMATIC) TransceiverId);

/* CANIF788 */
/* typedef void (*CanIf_ClearTrcvWufFlagIndicationFctType) (uint8 TransceiverId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_ClearTrcvWufFlagIndicationFctType) (VAR(uint8, AUTOMATIC) TransceiverId);

/* CANIF814 */
/* typedef void (*CanIf_CheckTrcvWakeFlagIndicationFctType) (uint8 TransceiverId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_CheckTrcvWakeFlagIndicationFctType) (VAR(uint8, AUTOMATIC) TransceiverId);

#  if(CANIF_TRCV_MAPPING == STD_ON)
/* typedef void (*CanIf_CanTrcv_ClearTrcvWufFlagFctType) (uint8 TransceiverId)*/
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_ClearTrcvWufFlagFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex);

/* typedef void (*CanIf_CanTrcv_CheckWakeFlagFctType) (uint8 TransceiverId)*/
typedef P2FUNC(Std_ReturnType, CANIF_CBK_TRCV_CODE, CanIf_CanTrcv_CheckWakeFlagFctType) (VAR(uint8, AUTOMATIC) CanTrcvIndex);
#  endif



# endif /* (CANIF_PN_TRCV_HANDLING == STD_ON) */
#endif /* (CANIF_TRCV_HANDLING == STD_ON) */

typedef union
{ /* PRQA S 0750 1 */ /* MD_MSR_18.4 */
  CanIf_SimpleRxIndicationFctType     eSimpleRxIndicationType;
  CanIf_AdvancedRxIndicationFctType   eAdvancedRxIndicationType;
  CanIf_NmOsekRxIndicationFctType     eNmOsekRxIndicationType;
  CanIf_CddRxIndicationFctType        eCddRxIndicationType;
} CanIf_RxIndicationFctType;

#if ( CPU_TYPE == CPU_TYPE_32 ) /* COV_CANIF_PLATFORM_DEPENDENCY */
typedef uint32 CanIf_TxQueueFlagType;
#endif
#if ( CPU_TYPE == CPU_TYPE_16 ) /* COV_CANIF_UNSUPPORTED */
typedef uint16 CanIf_TxQueueFlagType;
#endif
#if ( CPU_TYPE == CPU_TYPE_8 ) /* COV_CANIF_UNSUPPORTED */
typedef uint8 CanIf_TxQueueFlagType;
#endif

/* typedef boolean CanIf_CancelResultType; */
typedef boolean CanIf_CancelResultType;

typedef struct sCanIf_TxQueueBaseType
{
#if((CANIF_SETDYNAMICTXID_API == STD_ON) || (CANIF_J1939_DYN_ADDR_SUPPORT != CANIF_J1939_DYN_ADDR_DISABLED) || (CANIF_META_DATA_TX_SUPPORT == STD_ON)) /* COV_CANIF_UNSUPPORTED_J1939_DYN_ADDR */
  Can_IdType    eCanId;     /* CAN-ID will be buffered */
#endif
  uint8         eSduLength; /* uint8: Is sufficient: 8-64 bytes */
} CanIf_TxQueueBaseType;


typedef struct sCanIf_TxQueueBaseWithDataType
{
#if (CANIF_STATIC_FD_TXQUEUE == STD_OFF)
  uint8                   eSdu[CANIF_STATIC_BUFFER_SIZE]; /* const 64 bit     */
#endif
  CanIf_TxQueueBaseType eBaseParams;                    /* CanId, SduLength */
} CanIf_TxQueueBaseWithDataType;

/*** START - Tx-FIFO-buffer-types - START ***/
/* Base data type for "CanIfBufferCfg" with "CanIfTxBufferHandlingType == PRIO_BY_CANID". */
/* This type is to be instantiated "CanIfBufferSize"-times.  */
typedef struct sCanIf_TxPrioByCanIdByteQueueType
{
  CanIf_TxQueueBaseWithDataType eQueueParams; /* CanId, SduLength, Sdu */
  uint8                         eQueued;      /* Validity flag: 0: invalid, 1: valid */
} CanIf_TxPrioByCanIdByteQueueType;

/* Base data type for "CanIfBufferCfg" with "CanIfTxBufferHandlingType == PRIO_BY_CANID". */
/* This type is to be instantiated "CanIfBufferSize"-times.  */
typedef struct sCanIf_TxPrioByCanIdBitQueueType
{
  CanIf_TxQueueBaseWithDataType eQueueParams; /* CanId, SduLength, Sdu */
} CanIf_TxPrioByCanIdBitQueueType;

/* This type is to be instantiated one per each "CanIfBufferCfg" with "CanIfTxBufferHandlingType == PRIO_BY_CANID" and BYTE_QUEUE is configured */
typedef struct sCanIf_TxBufferPrioByCanIdBaseType
{
  CanIf_TxBufferSizeType  eQueueCounter; /* How many elements are queued within the Tx-buffer. */
} CanIf_TxBufferPrioByCanIdBaseType;


/* Base data type for "CanIfBufferCfg" with "CanIfTxBufferHandlingType == FIFO". */
/* This type is to be instantiated "CanIfBufferSize"-times.  */
typedef struct sCanIf_TxFifoQueueBaseType
{
  CanIf_TxQueueBaseType eBaseParams; /* CanId, SduLength */
  PduIdType             eTxPduId;
#if (CANIF_CANCEL_SUPPORT_API == STD_ON)
  uint8                 eQueued;     /* Validity flag: 0: invalid, 1: valid */
#endif
} CanIf_TxFifoQueueBaseType;

/* This type is to be instantiated one per each "CanIfBufferCfg" with "CanIfTxBufferHandlingType == FIFO" */
typedef struct sCanIf_TxBufferFifoBaseType
{
  CanIf_TxBufferSizeType  eWriteIdx;     /* Next position to be written into FIFO */
  CanIf_TxBufferSizeType  eReadIdx;      /* Next position to be read from FIFO */
  CanIf_TxBufferSizeType  eQueueCounter; /* How many elements are queued within the Tx-buffer. */
} CanIf_TxBufferFifoBaseType;


/*** END - FEAT-1429 Tx-buffer-types - END ***/

/*** BEGIN - FEAT-1914 Data checksum - BEGIN ***/

/* Type for Data checksum Rx error indication function */
/* typedef void (*CanIf_DataChecksumRxErrFctType) (PduIdType CanIfRxPduId); */
typedef P2FUNC(void, CANIF_APPL_MSG_CODE, CanIf_DataChecksumRxErrFctType) (VAR(PduIdType, AUTOMATIC) CanIfRxPduId);

/*** END - FEAT-1914 Data checksum - END ***/

#endif
