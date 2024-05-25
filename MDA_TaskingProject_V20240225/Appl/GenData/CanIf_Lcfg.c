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
 *            Module: CanIf
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: CanIf_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:30
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

#define CANIF_LCFG_SOURCE

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 0857 EOF */ /* MD_CanIf_1.1_NumberOfMacroDefinitions */
/* PRQA S 0779 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 0777 EOF */ /* MD_CanIf_5.1 */
/* PRQA S 1330, 1334 EOF */ /* MD_CanIf_16.4, MD_CanIf_16.4 */

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/ 

#include "CanIf_Cfg.h"

 /*  PduR Header Files  */ 
#include "PduR_Cfg.h"
#include "PduR_CanIf.h"
 /*  Xcp Header Files  */ 
#include "CanXcp.h"
 /*  CanSM Header Files  */ 
#include "CanSM_Cbk.h"

#define CANIF_START_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  \var  Prototypes of callback functions
**********************************************************************************************************************/

/** 
  \brief  Tx confirmation functions.
*/



/** 
  \brief  Rx indication functions.
*/





#define CANIF_STOP_SEC_APPL_CODE
/* PRQA S 5087 1 */ /* MD_MSR_19.1 */
#include "MemMap.h"

/**********************************************************************************************************************
  ComStackLib
**********************************************************************************************************************/
/**********************************************************************************************************************
  LOCAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: LOCAL DATA
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: LOCAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr = CanSM_ControllerBusOff;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CanIfCtrlId2MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_CanIfCtrlId2MappedTxBuffersConfig
  \brief  CAN controller configuration - mapped Tx-buffer(s).
  \details
  Element                          Description
  MappedTxBuffersConfigEndIdx      the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
  MappedTxBuffersConfigStartIdx    the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[6] = {
    /* Index    MappedTxBuffersConfigEndIdx                                                                      MappedTxBuffersConfigStartIdx                                                                            Referable Keys */
  { /*     0 */                         1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509 */,                           0uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509 */ },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509] */
  { /*     1 */                         0uL  /* CanChannelWithoutTxBuffer */                                   ,                           0uL  /* CanChannelWithoutTxBuffer */                                    },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */                         0uL  /* CanChannelWithoutTxBuffer */                                   ,                           0uL  /* CanChannelWithoutTxBuffer */                                    },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */                         0uL  /* CanChannelWithoutTxBuffer */                                   ,                           0uL  /* CanChannelWithoutTxBuffer */                                    },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */                         0uL  /* CanChannelWithoutTxBuffer */                                   ,                           0uL  /* CanChannelWithoutTxBuffer */                                    },  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */                         0uL  /* CanChannelWithoutTxBuffer */                                   ,                           0uL  /* CanChannelWithoutTxBuffer */                                    }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlModeIndicationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr = CanSM_ControllerModeIndication;
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MailBoxConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MailBoxConfig
  \brief  Mailbox table.
  \details
  Element                 Description
  CtrlStatesIdx           the index of the 1:1 relation pointing to CanIf_CtrlStates
  PduIdFirst              "First" PDU mapped to mailbox.
  PduIdLast               "Last" PDU mapped to mailbox.
  TxBufferCfgIdx          the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig
  TxBufferHandlingType
  MailBoxType             Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[55] = {
    /* Index    CtrlStatesIdx                                                                                         PduIdFirst                            PduIdLast                            TxBufferCfgIdx                                                                              TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*     0 */           0uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509 */                   ,         0u  /* Unused, TxPduId 0 */ ,        0u  /* Unused, TxPduId 0 */ ,                                    0uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2 */, CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID, CANIF_TxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_8c3ac689_Tx] */
  { /*     1 */           0uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509 */                   ,         0u  /* RxPduId */           ,       12u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex1 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxBasicCANMailbox },  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_eb5ad8b0_Rx] */
  { /*     2 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 15 */,        0u  /* Unused, TxPduId 15 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex2 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx] */
  { /*     3 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 14 */,        0u  /* Unused, TxPduId 14 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex3 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx] */
  { /*     4 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 13 */,        0u  /* Unused, TxPduId 13 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex4 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx] */
  { /*     5 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 12 */,        0u  /* Unused, TxPduId 12 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex5 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx] */
  { /*     6 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 11 */,        0u  /* Unused, TxPduId 11 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex6 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx] */
  { /*     7 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 10 */,        0u  /* Unused, TxPduId 10 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex7 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx] */
  { /*     8 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 9 */ ,        0u  /* Unused, TxPduId 9 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex8 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx] */
  { /*     9 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 8 */ ,        0u  /* Unused, TxPduId 8 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex9 */                                , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx] */
  { /*    10 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 7 */ ,        0u  /* Unused, TxPduId 7 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex10 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx] */
  { /*    11 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 6 */ ,        0u  /* Unused, TxPduId 6 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex11 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx] */
  { /*    12 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 5 */ ,        0u  /* Unused, TxPduId 5 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex12 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx] */
  { /*    13 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 4 */ ,        0u  /* Unused, TxPduId 4 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex13 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx] */
  { /*    14 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 3 */ ,        0u  /* Unused, TxPduId 3 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex14 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx] */
  { /*    15 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 2 */ ,        0u  /* Unused, TxPduId 2 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex15 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx] */
  { /*    16 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused, TxPduId 1 */ ,        0u  /* Unused, TxPduId 1 */ , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex16 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx] */
  { /*    17 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex17 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MDA_CANFD_c149c45e_Tx] */
  { /*    18 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        13u  /* RxPduId */           ,       13u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex18 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx] */
  { /*    19 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        14u  /* RxPduId */           ,       14u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex19 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx] */
  { /*    20 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        15u  /* RxPduId */           ,       15u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex20 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx] */
  { /*    21 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        16u  /* RxPduId */           ,       16u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex21 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx] */
  { /*    22 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        17u  /* RxPduId */           ,       17u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex22 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx] */
  { /*    23 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        18u  /* RxPduId */           ,       18u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex23 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx] */
  { /*    24 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        19u  /* RxPduId */           ,       19u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex24 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx] */
  { /*    25 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        20u  /* RxPduId */           ,       20u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex25 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx] */
  { /*    26 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        21u  /* RxPduId */           ,       21u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex26 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx] */
  { /*    27 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        22u  /* RxPduId */           ,       22u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex27 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx] */
  { /*    28 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        23u  /* RxPduId */           ,       23u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex28 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx] */
  { /*    29 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        24u  /* RxPduId */           ,       24u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex29 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx] */
  { /*    30 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        25u  /* RxPduId */           ,       25u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex30 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx] */
  { /*    31 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        26u  /* RxPduId */           ,       26u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex31 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx] */
  { /*    32 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        27u  /* RxPduId */           ,       27u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex32 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx] */
  { /*    33 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        28u  /* RxPduId */           ,       28u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex33 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx] */
  { /*    34 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        29u  /* RxPduId */           ,       29u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex34 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx] */
  { /*    35 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        30u  /* RxPduId */           ,       30u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex35 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx] */
  { /*    36 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        31u  /* RxPduId */           ,       31u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex36 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx] */
  { /*    37 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        32u  /* RxPduId */           ,       32u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex37 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx] */
  { /*    38 */           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    ,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex38 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MDA_CANFD_821576c1_Rx] */
  { /*    39 */           2uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a */,         0u  /* Unused, TxPduId 16 */,        0u  /* Unused, TxPduId 16 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex39 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx] */
  { /*    40 */           2uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex40 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFL_CANFD_b5523491_Tx] */
  { /*    41 */           2uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a */,        33u  /* RxPduId */           ,       33u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex41 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx] */
  { /*    42 */           2uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex42 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFL_CANFD_ef6a29f1_Rx] */
  { /*    43 */           3uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,         0u  /* Unused, TxPduId 17 */,        0u  /* Unused, TxPduId 17 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex43 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx] */
  { /*    44 */           3uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex44 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFR_CANFD_82b3d302_Tx] */
  { /*    45 */           3uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,        34u  /* RxPduId */           ,       34u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex45 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx] */
  { /*    46 */           3uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex46 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFR_CANFD_29cfe1c4_Rx] */
  { /*    47 */           4uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb */,         0u  /* Unused, TxPduId 18 */,        0u  /* Unused, TxPduId 18 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex47 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx] */
  { /*    48 */           4uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex48 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRL_CANFD_4da30b40_Tx] */
  { /*    49 */           4uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb */,        35u  /* RxPduId */           ,       35u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex49 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx] */
    /* Index    CtrlStatesIdx                                                                                         PduIdFirst                            PduIdLast                            TxBufferCfgIdx                                                                              TxBufferHandlingType                     MailBoxType                    Referable Keys */
  { /*    50 */           4uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex50 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRL_CANFD_8b339743_Rx] */
  { /*    51 */           5uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178 */,         0u  /* Unused, TxPduId 19 */,        0u  /* Unused, TxPduId 19 */, CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex51 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_TxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx] */
  { /*    52 */           5uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex52 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Tx] */
  { /*    53 */           5uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178 */,        36u  /* RxPduId */           ,       36u  /* RxPduId  */          , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex53 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_RxFullCANMailbox  },  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx] */
  { /*    54 */           5uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178 */,         0u  /* Unused object */     ,        0u  /* Unused object */     , CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG  /* unusedIndex54 */                               , CANIF_TXBUFFER_HANDLINGTYPE_NONE       , CANIF_UnusedCANMailbox  }   /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRR_CANFD_4d965f76_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_MappedTxBuffersConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_MappedTxBuffersConfig
  \brief  Mapped Tx-buffer(s)
  \details
  Element             Description
  MailBoxConfigIdx    the index of the 1:1 relation pointing to CanIf_MailBoxConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1] = {
    /* Index    MailBoxConfigIdx                                                                 Referable Keys */
  { /*     0 */              0uL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_8c3ac689_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxIndicationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_RxIndicationFctList
  \brief  Rx indication functions table.
  \details
  Element               Description
  RxIndicationFct       Rx indication function.
  RxIndicationLayout    Layout of Rx indication function.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[3] = {
    /* Index    RxIndicationFct                                               RxIndicationLayout                                                            Referable Keys */
  { /*     0 */  { (CanIf_SimpleRxIndicationFctType)NULL_PTR }              , CanIf_SimpleRxIndicationLayout    /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [NULL_PTR] */
  { /*     1 */  { (CanIf_SimpleRxIndicationFctType)PduR_CanIfRxIndication }, CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ },  /* [PduR_CanIfRxIndication] */
  { /*     2 */  { (CanIf_SimpleRxIndicationFctType)Xcp_CanIfRxIndication } , CanIf_AdvancedRxIndicationLayout  /* PRQA S 313 */ /* MD_CanIf_11.1 */ }   /* [Xcp_CanIfRxIndication] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_RxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_RxPduConfig
  \brief  Rx-PDU configuration table.
  \details
  Element                   Description
  RxPduCanId                Rx-PDU: CAN identifier.
  RxPduMask                 Rx-PDU: CAN identifier mask.
  UpperPduId                PDU ID defined by upper layer.
  Dlc                       Data length code.
  RxIndicationFctListIdx    the index of the 1:1 relation pointing to CanIf_RxIndicationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[37] = {
    /* Index    RxPduCanId                                                                                  RxPduMask                                                                   UpperPduId                                 Dlc  RxIndicationFctListIdx                                      Comment                                                                                      Referable Keys */
  { /*     0 */ 0x000006FFuL  /* XCP_S_oCAN00_d18922f7_Rx, 2.0- or FD-PDU */                              , 0x400007FFuL  /* XCP_S_oCAN00_d18922f7_Rx */                              , XcpConf_XcpRxPdu_XCP_S_oCAN00_aa3b84ab_Rx,  8u,                    2uL  /* Xcp_CanIfRxIndication */  },  /* [PDU: XCP_S_oCAN00_d18922f7_Rx, CanId: 0x6ff]                                    */  /* [CanIfConf_CanIfRxPduCfg_XCP_S_oCAN00_d18922f7_Rx] */
  { /*     1 */ 0x00000181uL  /* TcmPropFr04_oCAN00_28f82aa0_Rx, 2.0- or FD-PDU */                        , 0x000007FFuL  /* TcmPropFr04_oCAN00_28f82aa0_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_440872d3  ,  6u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: TcmPropFr04_oCAN00_28f82aa0_Rx, CanId: 0x181]                              */  /* [CanIfConf_CanIfRxPduCfg_TcmPropFr04_oCAN00_28f82aa0_Rx] */
  { /*     2 */ 0x00000161uL  /* VddmPropFr12_oCAN00_f60c01d6_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* VddmPropFr12_oCAN00_f60c01d6_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_1550c19a  ,  4u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: VddmPropFr12_oCAN00_f60c01d6_Rx, CanId: 0x161]                             */  /* [CanIfConf_CanIfRxPduCfg_VddmPropFr12_oCAN00_f60c01d6_Rx] */
  { /*     3 */ 0x00000141uL  /* BecmPropFr01_oCAN00_e0c55a4e_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* BecmPropFr01_oCAN00_e0c55a4e_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_fae18295  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: BecmPropFr01_oCAN00_e0c55a4e_Rx, CanId: 0x141]                             */  /* [CanIfConf_CanIfRxPduCfg_BecmPropFr01_oCAN00_e0c55a4e_Rx] */
  { /*     4 */ 0x00000138uL  /* VddmPropFr10_oCAN00_4c52103e_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* VddmPropFr10_oCAN00_4c52103e_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_14940491  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: VddmPropFr10_oCAN00_4c52103e_Rx, CanId: 0x138]                             */  /* [CanIfConf_CanIfRxPduCfg_VddmPropFr10_oCAN00_4c52103e_Rx] */
  { /*     5 */ 0x00000121uL  /* EcmPropFr07_oCAN00_e92ad649_Rx, 2.0- or FD-PDU */                        , 0x000007FFuL  /* EcmPropFr07_oCAN00_e92ad649_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_85bab85c  ,  6u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: EcmPropFr07_oCAN00_e92ad649_Rx, CanId: 0x121]                              */  /* [CanIfConf_CanIfRxPduCfg_EcmPropFr07_oCAN00_e92ad649_Rx] */
  { /*     6 */ 0x00000081uL  /* VddmPropFr09_oCAN00_2f1b4ca4_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* VddmPropFr09_oCAN00_2f1b4ca4_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_6c7f8382  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: VddmPropFr09_oCAN00_2f1b4ca4_Rx, CanId: 0x81]                              */  /* [CanIfConf_CanIfRxPduCfg_VddmPropFr09_oCAN00_2f1b4ca4_Rx] */
  { /*     7 */ 0x00000076uL  /* VddmPropFr05_oCAN00_043d2456_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* VddmPropFr05_oCAN00_043d2456_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_57d9311c  ,  6u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: VddmPropFr05_oCAN00_043d2456_Rx, CanId: 0x76]                              */  /* [CanIfConf_CanIfRxPduCfg_VddmPropFr05_oCAN00_043d2456_Rx] */
  { /*     8 */ 0x0000004CuL  /* IemEduPropFr01_oCAN00_25d7e216_Rx, 2.0- or FD-PDU */                     , 0x000007FFuL  /* IemEduPropFr01_oCAN00_25d7e216_Rx */                     , PduRConf_PduRSrcPdu_PduRSrcPdu_b89bceb5  ,  3u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: IemEduPropFr01_oCAN00_25d7e216_Rx, CanId: 0x4c]                            */  /* [CanIfConf_CanIfRxPduCfg_IemEduPropFr01_oCAN00_25d7e216_Rx] */
  { /*     9 */ 0x0000004BuL  /* EcmPropFr24_oCAN00_df718eb8_Rx, 2.0- or FD-PDU */                        , 0x000007FFuL  /* EcmPropFr24_oCAN00_df718eb8_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_c670cbec  ,  4u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: EcmPropFr24_oCAN00_df718eb8_Rx, CanId: 0x4b]                               */  /* [CanIfConf_CanIfRxPduCfg_EcmPropFr24_oCAN00_df718eb8_Rx] */
  { /*    10 */ 0x0000004AuL  /* EcmPropFr00_oCAN00_7944854a_Rx, 2.0- or FD-PDU */                        , 0x000007FFuL  /* EcmPropFr00_oCAN00_7944854a_Rx */                        , PduRConf_PduRSrcPdu_PduRSrcPdu_e1fbfb28  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: EcmPropFr00_oCAN00_7944854a_Rx, CanId: 0x4a]                               */  /* [CanIfConf_CanIfRxPduCfg_EcmPropFr00_oCAN00_7944854a_Rx] */
  { /*    11 */ 0x00000041uL  /* VddmPropFr08_oCAN00_72344450_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* VddmPropFr08_oCAN00_72344450_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_4c43d725  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: VddmPropFr08_oCAN00_72344450_Rx, CanId: 0x41]                              */  /* [CanIfConf_CanIfRxPduCfg_VddmPropFr08_oCAN00_72344450_Rx] */
  { /*    12 */ 0x00000031uL  /* VddmPropFr29_oCAN00_817078ff_Rx, 2.0- or FD-PDU */                       , 0x000007FFuL  /* VddmPropFr29_oCAN00_817078ff_Rx */                       , PduRConf_PduRSrcPdu_PduRSrcPdu_d18651cd  ,  4u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: VddmPropFr29_oCAN00_817078ff_Rx, CanId: 0x31]                              */  /* [CanIfConf_CanIfRxPduCfg_VddmPropFr29_oCAN00_817078ff_Rx] */
  { /*    13 */ 0x91FF0C1FuL  /* MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_497553e8  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx, CanId: 0x11ff0c1f]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx] */
  { /*    14 */ 0x91FF0C1EuL  /* MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_cc32e7dd  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx, CanId: 0x11ff0c1e]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx] */
  { /*    15 */ 0x91FF0C1DuL  /* MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_4e8ce9aa  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx, CanId: 0x11ff0c1d]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx] */
  { /*    16 */ 0x91FF0C1CuL  /* MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_d9f53daa  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx, CanId: 0x11ff0c1c]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx] */
  { /*    17 */ 0x91FF0C1BuL  /* MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_ae89e63d  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx, CanId: 0x11ff0c1b]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx] */
  { /*    18 */ 0x91FF0C1AuL  /* MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_75e7ddd6  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx, CanId: 0x11ff0c1a]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx] */
  { /*    19 */ 0x91FF0C19uL  /* MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_2dc7503e  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx, CanId: 0x11ff0c19]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx] */
  { /*    20 */ 0x91FF0C18uL  /* MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_e3267653  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx, CanId: 0x11ff0c18]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx] */
  { /*    21 */ 0x91FF0C17uL  /* MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_3b0ccb8b  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx, CanId: 0x11ff0c17]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx] */
  { /*    22 */ 0x91FF0C16uL  /* MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_ccd18f93  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx, CanId: 0x11ff0c16]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx] */
  { /*    23 */ 0x91FF0C15uL  /* MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_8eb8bcc7  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx, CanId: 0x11ff0c15]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx] */
  { /*    24 */ 0x91FF0C14uL  /* MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_0182d1a5  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx, CanId: 0x11ff0c14]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx] */
  { /*    25 */ 0x91FF0C13uL  /* MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_00ca1874  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx, CanId: 0x11ff0c13]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx] */
  { /*    26 */ 0x91FF0C12uL  /* MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_b2abe408  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx, CanId: 0x11ff0c12]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx] */
  { /*    27 */ 0x91FF0C11uL  /* MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_3baae64e  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx, CanId: 0x11ff0c11]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx] */
  { /*    28 */ 0x91FF0C10uL  /* MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_e1df8ad7  , 64u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx, CanId: 0x11ff0c10]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx] */
  { /*    29 */ 0x91FF0B24uL  /* MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx, 2.0- or FD-PDU */, 0xDFFFFFFFuL  /* MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx */, PduRConf_PduRSrcPdu_PduRSrcPdu_22b98a3a  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx, CanId: 0x11ff0b24] */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx] */
  { /*    30 */ 0x91FF0B23uL  /* MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx, 2.0- or FD-PDU */, 0xDFFFFFFFuL  /* MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx */, PduRConf_PduRSrcPdu_PduRSrcPdu_b39ae31f  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx, CanId: 0x11ff0b23] */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx] */
  { /*    31 */ 0x91FF0B22uL  /* MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx, 2.0- or FD-PDU */, 0xDFFFFFFFuL  /* MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx */, PduRConf_PduRSrcPdu_PduRSrcPdu_01f05597  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx, CanId: 0x11ff0b22] */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx] */
  { /*    32 */ 0x91FF0B21uL  /* MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx, 2.0- or FD-PDU */, 0xDFFFFFFFuL  /* MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx */, PduRConf_PduRSrcPdu_PduRSrcPdu_e3ca4023  ,  8u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx, CanId: 0x11ff0b21] */  /* [CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx] */
  { /*    33 */ 0x91FF0B11uL  /* MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_32000ae6  , 16u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx, CanId: 0x11ff0b11]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx] */
  { /*    34 */ 0x91FF0B12uL  /* MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_4b661c96  , 16u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx, CanId: 0x11ff0b12]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx] */
  { /*    35 */ 0x91FF0B13uL  /* MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_2ae17888  , 16u,                    1uL  /* PduR_CanIfRxIndication */ },  /* [PDU: MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx, CanId: 0x11ff0b13]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx] */
  { /*    36 */ 0x91FF0B14uL  /* MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx, 2.0- or FD-PDU */    , 0xDFFFFFFFuL  /* MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx */    , PduRConf_PduRSrcPdu_PduRSrcPdu_f29797a8  , 16u,                    1uL  /* PduR_CanIfRxIndication */ }   /* [PDU: MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx, CanId: 0x11ff0b14]     */  /* [CanIfConf_CanIfRxPduCfg_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueConfig
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE
  \details
  Element                                             Description
  TxBufferPrioByCanIdBaseIdx                          the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase
  TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx      the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusLength      the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx    the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1] = {
    /* Index    TxBufferPrioByCanIdBaseIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdx                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusLength                                                      TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdx                                                            Referable Keys */
  { /*     0 */                        0uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2 */,                                            1uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2 */,                                            1uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2 */,                                              0uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2 */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
  \brief  Tx-buffer: PRIO_BY_CANID as BYTE_QUEUE: Mapped Tx-PDUs
  \details
  Element           Description
  TxPduConfigIdx    the index of the 1:1 relation pointing to CanIf_TxPduConfig
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[1] = {
    /* Index    TxPduConfigIdx                                                                       Referable Keys */
  { /*     0 */            0uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/XCP_R_oCAN00_267e057e_Tx */ }   /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxConfirmationFctList
**********************************************************************************************************************/
/** 
  \var    CanIf_TxConfirmationFctList
  \brief  Tx confirmation functions table.
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[3] = {
  /* Index     TxConfirmationFctList                      Referable Keys */
  /*     0 */ (CanIf_TxConfirmationFctType)NULL_PTR ,  /* [NULL_PTR] */
  /*     1 */ PduR_CanIfTxConfirmation              ,  /* [PduR_CanIfTxConfirmation] */
  /*     2 */ Xcp_CanIfTxConfirmation                  /* [Xcp_CanIfTxConfirmation] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduConfig
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduConfig
  \brief  Tx-PDUs - configuration.
  \details
  Element                     Description
  CanId                       CAN identifier (16bit / 32bit).
  UpperLayerTxPduId           Upper layer handle ID (8bit / 16bit).
  CtrlStatesIdx               the index of the 1:1 relation pointing to CanIf_CtrlStates
  Dlc                         Data length code.
  MailBoxConfigIdx            the index of the 1:1 relation pointing to CanIf_MailBoxConfig
  TxConfirmationFctListIdx    the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[20] = {
    /* Index    CanId         UpperLayerTxPduId                                                           CtrlStatesIdx                                                                                         Dlc  MailBoxConfigIdx                                                                                                              TxConfirmationFctListIdx                                        Comment                                                                  Referable Keys */
  { /*     0 */ 0x000006FEuL, XcpConf_XcpTxPdu_XCP_R_oCAN00_31486e7f_Tx                                 ,           0uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509 */                   ,  8u,              0uL  /* /ActiveEcuC/Can/CanConfigSet/CN_CAN00_8c3ac689_Tx */                                                   ,                      2uL  /* Xcp_CanIfTxConfirmation */  },  /* [PDU: XCP_R_oCAN00_267e057e_Tx]                              */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/XCP_R_oCAN00_267e057e_Tx] */
  { /*     1 */ 0xD8FF0F11uL, PduRConf_PduRDestPdu_MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx         ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             16uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx */         ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx] */
  { /*     2 */ 0xD8FF0E16uL, PduRConf_PduRDestPdu_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx    ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             15uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx */    ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx] */
  { /*     3 */ 0xD8FF0E15uL, PduRConf_PduRDestPdu_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx    ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             14uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx */    ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx] */
  { /*     4 */ 0xD8FF0E14uL, PduRConf_PduRDestPdu_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx    ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             13uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx */    ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx] */
  { /*     5 */ 0xD8FF0E13uL, PduRConf_PduRDestPdu_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx    ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             12uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx */    ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx] */
  { /*     6 */ 0xD8FF0E12uL, PduRConf_PduRDestPdu_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx    ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             11uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx */    ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx] */
  { /*     7 */ 0xD8FF0E11uL, PduRConf_PduRDestPdu_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx    ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,             10uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx */    ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx] */
  { /*     8 */ 0xD8FF0D10uL, PduRConf_PduRDestPdu_MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx          ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,              9uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx */          ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx] */
  { /*     9 */ 0xD8FF0C14uL, PduRConf_PduRDestPdu_MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx        ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 16u,              8uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx */        ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx] */
  { /*    10 */ 0xD8FF0C13uL, PduRConf_PduRDestPdu_MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx        ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 16u,              7uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx */        ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx] */
  { /*    11 */ 0xD8FF0C12uL, PduRConf_PduRDestPdu_MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx        ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 16u,              6uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx */        ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx] */
  { /*    12 */ 0xD8FF0C11uL, PduRConf_PduRDestPdu_MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx        ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 16u,              5uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx */        ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx] */
  { /*    13 */ 0xD8FF0B11uL, PduRConf_PduRDestPdu_MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx      ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,              4uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx */      ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx] */
  { /*    14 */ 0xD8FF0B10uL, PduRConf_PduRDestPdu_MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx      ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,              3uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx */      ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx] */
  { /*    15 */ 0xD8FF0A11uL, PduRConf_PduRDestPdu_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx   ,           1uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f */    , 64u,              2uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx */   ,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx] */
  { /*    16 */ 0xD8FF0C11uL, PduRConf_PduRDestPdu_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx,           2uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a */,  8u,             39uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx */,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx] */
  { /*    17 */ 0xD8FF0C12uL, PduRConf_PduRDestPdu_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx,           3uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,  8u,             43uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx */,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx] */
  { /*    18 */ 0xD8FF0C13uL, PduRConf_PduRDestPdu_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx,           4uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb */,  8u,             47uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx */,                      1uL  /* PduR_CanIfTxConfirmation */ },  /* [PDU: MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx] */
  { /*    19 */ 0xD8FF0C14uL, PduRConf_PduRDestPdu_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx,           5uL  /* /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178 */,  8u,             51uL  /* /ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx */,                      1uL  /* PduR_CanIfTxConfirmation */ }   /* [PDU: MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxPduQueueIndex
**********************************************************************************************************************/
/** 
  \var    CanIf_TxPduQueueIndex
  \brief  Indirection table: Tx-PDU handle ID to corresponding Tx buffer handle ID. NOTE: Only BasicCAN Tx-PDUs have a valid indirection into the Tx buffer.
  \details
  Element       Description
  TxQueueIdx    the index of the 0:1 relation pointing to CanIf_TxQueue
*/ 
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[20] = {
    /* Index    TxQueueIdx                                                                                                                              Comment                                                                                         Referable Keys */
  { /*     0 */                                  0uL  /* /ActiveEcuC/CanIf/CanIfInitCfg/XCP_R_oCAN00_267e057e_Tx */                              },  /* [XCP_R_oCAN00_267e057e_Tx, BasicCAN TxPdu with Tx-buffer]                           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/XCP_R_oCAN00_267e057e_Tx, /ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509] */
  { /*     1 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx */          },  /* [MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx, FullCAN TxPdu NO Tx-buffer]          */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx] */
  { /*     2 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx */     },  /* [MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx, FullCAN TxPdu NO Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx] */
  { /*     3 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx */     },  /* [MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx, FullCAN TxPdu NO Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx] */
  { /*     4 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx */     },  /* [MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx, FullCAN TxPdu NO Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx] */
  { /*     5 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx */     },  /* [MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx, FullCAN TxPdu NO Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx] */
  { /*     6 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx */     },  /* [MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx, FullCAN TxPdu NO Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx] */
  { /*     7 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx */     },  /* [MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx, FullCAN TxPdu NO Tx-buffer]     */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx] */
  { /*     8 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx */           },  /* [MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx, FullCAN TxPdu NO Tx-buffer]           */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx] */
  { /*     9 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx */         },  /* [MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx, FullCAN TxPdu NO Tx-buffer]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx] */
  { /*    10 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx */         },  /* [MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx, FullCAN TxPdu NO Tx-buffer]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx] */
  { /*    11 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx */         },  /* [MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx, FullCAN TxPdu NO Tx-buffer]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx] */
  { /*    12 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx */         },  /* [MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx, FullCAN TxPdu NO Tx-buffer]         */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx] */
  { /*    13 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx */       },  /* [MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx, FullCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx] */
  { /*    14 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx */       },  /* [MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx, FullCAN TxPdu NO Tx-buffer]       */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx] */
  { /*    15 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx */    },  /* [MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx, FullCAN TxPdu NO Tx-buffer]    */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx] */
  { /*    16 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx */ },  /* [MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx, FullCAN TxPdu NO Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx] */
  { /*    17 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx */ },  /* [MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx, FullCAN TxPdu NO Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx] */
  { /*    18 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx */ },  /* [MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx, FullCAN TxPdu NO Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx] */
  { /*    19 */ CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX  /* /ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx */ }   /* [MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx, FullCAN TxPdu NO Tx-buffer] */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx] */
};
#define CANIF_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_CtrlStates
**********************************************************************************************************************/
/** 
  \var    CanIf_CtrlStates
  \details
  Element     Description
  CtrlMode    Controller mode.
  PduMode     PDU mode state.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_CAN00_4f940509] */
  /*     1 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */  /* [/ActiveEcuC/CanIf/CanIfCtrlDrvCfg_7d254554/CT_Schaeffler_MotorRR_CANFD_9073d178] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxBufferPrioByCanIdBase
**********************************************************************************************************************/
/** 
  \var    CanIf_TxBufferPrioByCanIdBase
  \brief  Variable declaration - Tx-buffer: PRIO_BY_CANID as byte/bit-queue. Stores at least the QueueCounter.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/CHNL_0fb271d2] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */

/**********************************************************************************************************************
  CanIf_TxQueue
**********************************************************************************************************************/
/** 
  \var    CanIf_TxQueue
  \brief  Variable declaration - Tx byte queue.
*/ 
#define CANIF_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
  /* Index        Referable Keys  */
  /*     0 */  /* [/ActiveEcuC/CanIf/CanIfInitCfg/XCP_R_oCAN00_267e057e_Tx] */

#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/



