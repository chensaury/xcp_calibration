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
 *            Module: Can
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Can_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:33
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


#define CAN_LCFG_SOURCE

/* PRQA S 0779 EOF */ /* MD_MSR_Rule5.2 */

/* -----------------------------------------------------------------------------
    Includes
 ----------------------------------------------------------------------------- */

#include "Can_Cfg.h"

/* -----------------------------------------------------------------------------
    Hw specific
 ----------------------------------------------------------------------------- */

/* HW specific CT global C file */

/* !HW specific CT global C file */

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
  Can_BTP
**********************************************************************************************************************/
/** 
  \var    Can_BTP
  \brief  Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_BTPType, CAN_CONST) Can_BTP[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     BTP              Comment */
  /*     0 */  0x001F0200u,  /* [CT_CAN00_4f940509 - CanControllerBaudrateConfig] */
  /*     1 */  0x00130100u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f - CanControllerBaudrateConfig] */
  /*     2 */  0x00130100u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a - CanControllerBaudrateConfig] */
  /*     3 */  0x00130100u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9 - CanControllerBaudrateConfig] */
  /*     4 */  0x00130100u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb - CanControllerBaudrateConfig] */
  /*     5 */  0x00130100u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_BufferConfig
**********************************************************************************************************************/
/** 
  \var    Can_BufferConfig
  \brief  CAN Buffer Configuration
  \details
  Element    Description
  RXF0C  
  TXBC   
  RXBC   
  RXF1C  
  TXEFC  
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_BufferConfigType, CAN_CONST) Can_BufferConfig[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RXF0C        TXBC         RXBC     RXF1C  TXEFC        Comment */
  { /*     0 */ 0x00060004u, 0x000101B4u, 0x0000u, 0x00u, 0x00u },  /* [CT_CAN00_4f940509] */
  { /*     1 */ 0x000602A0u, 0x001009F0u, 0x0450u, 0x00u, 0x00u },  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0x0006000Cu, 0x00020204u, 0x01BCu, 0x00u, 0x00u },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */ 0x000602A0u, 0x00020498u, 0x0450u, 0x00u, 0x00u },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */ 0x00060534u, 0x0002072Cu, 0x06E4u, 0x00u, 0x00u },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */ 0x000607C8u, 0x000209C0u, 0x0978u, 0x00u, 0x00u }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_CanIfChannelId
**********************************************************************************************************************/
/** 
  \var    Can_CanIfChannelId
  \brief  indirection table Can to CanIf controller ID
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_CanIfChannelIdType, CAN_CONST) Can_CanIfChannelId[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     CanIfChannelId      Comment */
  /*     0 */              0u,  /* [CT_CAN00_4f940509] */
  /*     1 */              1u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */              2u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */              3u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */              4u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */              5u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerConfig
**********************************************************************************************************************/
/** 
  \var    Can_ControllerConfig
  \brief  Global configuration for all controllers
  \details
  Element                            Description
  BasisAdr                           CAN channel base address
  CanControllerDefaultBaudrate   
  IsTTCan                            TTCAN channel support
  CanControllerDefaultBaudrateIdx
  MailboxRxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxRxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxRxFullEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxRxFullLength                the number of relations pointing to Can_Mailbox
  MailboxRxFullStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicEndIdx               the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxBasicLength               the number of relations pointing to Can_Mailbox
  MailboxTxBasicStartIdx             the start index of the 0:n relation pointing to Can_Mailbox
  MailboxTxFullEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxTxFullLength                the number of relations pointing to Can_Mailbox
  MailboxTxFullStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedEndIdx                the end index of the 0:n relation pointing to Can_Mailbox
  MailboxUnusedLength                the number of relations pointing to Can_Mailbox
  MailboxUnusedStartIdx              the start index of the 0:n relation pointing to Can_Mailbox
  RxBasicHwStart                 
  RxBasicHwStop                  
  RxFullHwStart                  
  RxFullHwStop                   
  RxSelection                        CAN Rx Selection
  TxBasicHwStart                 
  TxBasicHwStop                  
  TxFullHwStart                  
  TxFullHwStop                   
  UnusedHwStart                  
  UnusedHwStop                   
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ControllerConfigType, CAN_CONST) Can_ControllerConfig[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BasisAdr     CanControllerDefaultBaudrate  IsTTCan  CanControllerDefaultBaudrateIdx  MailboxRxBasicEndIdx                                                                                                                                                              MailboxRxBasicLength                                                                                                                                                              MailboxRxBasicStartIdx                                                                                                                                                              MailboxRxFullEndIdx                                                                                                                                                                                      MailboxRxFullLength                                                                                                                                                             MailboxRxFullStartIdx                                                                                                                                                                                      MailboxTxBasicEndIdx                                                                                                                                                              MailboxTxBasicLength                                                                                                                                                              MailboxTxBasicStartIdx                                                                                                                                                              MailboxTxFullEndIdx                                                                                                                                                                                      MailboxTxFullLength                                                                                                                                                             MailboxTxFullStartIdx                                                                                                                                                                                      MailboxUnusedEndIdx                                                                                                                                                             MailboxUnusedLength                                                                                                                                                             MailboxUnusedStartIdx                                                                                                                                                             RxBasicHwStart  RxBasicHwStop  RxFullHwStart  RxFullHwStop  RxSelection  TxBasicHwStart  TxBasicHwStop  TxFullHwStart  TxFullHwStop  UnusedHwStart  UnusedHwStop        Comment                                            Referable Keys */
  { /*     0 */ 0xF0218100u,                         500u,   FALSE,                              0u,                   2u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                     1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   , CAN_NO_MAILBOXRXFULLENDIDXOFCONTROLLERCONFIG  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                  0u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   , CAN_NO_MAILBOXRXFULLSTARTIDXOFCONTROLLERCONFIG  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                     0u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   , CAN_NO_MAILBOXTXFULLENDIDXOFCONTROLLERCONFIG  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                  0u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   , CAN_NO_MAILBOXTXFULLSTARTIDXOFCONTROLLERCONFIG  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                 56u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,                   55u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */                   ,             1u,            2u,            1u,           1u,       0x00u,             0u,            1u,            0u,           0u,            2u,          98u },  /* [CT_CAN00_4f940509]                    */  /* [/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509] */
  { /*     1 */ 0xF0218500u,                        1000u,   FALSE,                              0u,                  39u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                    38u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                                          38u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                 20u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                                            18u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                  18u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                    17u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                                          17u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                 15u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                                             2u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                 57u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,                   56u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */    ,            36u,           37u,           16u,          36u,       0x01u,            15u,           16u,            0u,          15u,           37u,          98u },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0xF0208100u,                        1000u,    TRUE,                              0u,                  43u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    42u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          42u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            41u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  41u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    40u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          40u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            39u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                 58u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   57u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,             3u,            4u,            2u,           3u,       0x00u,             1u,            2u,            0u,           1u,            4u,          98u },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */ 0xF0208500u,                        1000u,   FALSE,                              0u,                  47u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    46u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          46u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            45u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  45u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    44u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          44u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            43u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                 59u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   58u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,             3u,            4u,            2u,           3u,       0x02u,             1u,            2u,            0u,           1u,            4u,          98u },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */ 0xF0208900u,                        1000u,   FALSE,                              0u,                  51u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    50u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          50u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            49u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  49u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    48u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          48u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            47u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                 60u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   59u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,             3u,            4u,            2u,           3u,       0x01u,             1u,            2u,            0u,           1u,            4u,          98u },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */ 0xF0208D00u,                        1000u,   FALSE,                              0u,                  55u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    54u  /* RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          54u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            53u  /* RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  53u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   1u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                    52u  /* TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                          52u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                                            51u  /* TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                 61u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                  1u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,                   60u  /* UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController) */,             3u,            4u,            2u,           3u,       0x00u,             1u,            2u,            0u,           1u,            4u,          98u }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_FBTP
**********************************************************************************************************************/
/** 
  \var    Can_FBTP
  \brief  Fast Bit Timing and Prescaler
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_FBTPType, CAN_CONST) Can_FBTP[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     FBTP             Comment */
  /*     0 */  0x00000000u,  /* [CT_CAN00_4f940509 - CanControllerBaudrateConfig] */
  /*     1 */  0x00030100u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f - CanControllerBaudrateConfig] */
  /*     2 */  0x00030100u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a - CanControllerBaudrateConfig] */
  /*     3 */  0x00030100u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9 - CanControllerBaudrateConfig] */
  /*     4 */  0x00030100u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb - CanControllerBaudrateConfig] */
  /*     5 */  0x00030100u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_GFC
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_GFCType, CAN_CONST) Can_GFC[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     GFC        Comment */
  /*     0 */  0x3Fu,  /* [CT_CAN00_4f940509] */
  /*     1 */  0x3Fu,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */  0x3Fu,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */  0x3Fu,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */  0x3Fu,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */  0x3Fu   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_INT_Priority
**********************************************************************************************************************/
/** 
  \var    Can_INT_Priority
  \brief  Interrupt Priority
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_INT_PriorityType, CAN_CONST) Can_INT_Priority[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     INT_Priority      Comment */
  /*     0 */         0x00u,  /* [CT_CAN00_4f940509] */
  /*     1 */         0x00u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */         0x00u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */         0x00u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */         0x00u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */         0x00u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_INT_RoutingGroup
**********************************************************************************************************************/
/** 
  \var    Can_INT_RoutingGroup
  \brief  Interrupt routing for Groups
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_INT_RoutingGroupType, CAN_CONST) Can_INT_RoutingGroup[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     INT_RoutingGroup      Comment */
  /*     0 */       0x00000000u,  /* [CT_CAN00_4f940509] */
  /*     1 */       0x11111111u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */       0x00000000u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */       0x11111111u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */       0x22222222u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */       0x33333333u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectBaudrate
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectBaudrate
  \brief  baudrates ('InitStruct' as index)
*/ 
#define CAN_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectBaudrateType, CAN_CONST) Can_InitObjectBaudrate[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectBaudrate      Comment */
  /*     0 */                500u,  /* [CT_CAN00_4f940509 - CanControllerBaudrateConfig] */
  /*     1 */               1000u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f - CanControllerBaudrateConfig] */
  /*     2 */               1000u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a - CanControllerBaudrateConfig] */
  /*     3 */               1000u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9 - CanControllerBaudrateConfig] */
  /*     4 */               1000u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb - CanControllerBaudrateConfig] */
  /*     5 */               1000u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectFdBrsConfig
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectFdBrsConfig
  \brief  FD config ('BaudrateObject' as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectFdBrsConfigType, CAN_CONST) Can_InitObjectFdBrsConfig[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectFdBrsConfig                */
  /*     0 */       CAN_NONE_INITOBJECTFDBRSCONFIG,
  /*     1 */  CAN_FD_RXONLY_INITOBJECTFDBRSCONFIG,
  /*     2 */  CAN_FD_RXONLY_INITOBJECTFDBRSCONFIG,
  /*     3 */  CAN_FD_RXONLY_INITOBJECTFDBRSCONFIG,
  /*     4 */  CAN_FD_RXONLY_INITOBJECTFDBRSCONFIG,
  /*     5 */  CAN_FD_RXONLY_INITOBJECTFDBRSCONFIG
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_InitObjectStartIndex
**********************************************************************************************************************/
/** 
  \var    Can_InitObjectStartIndex
  \brief  Start index of 'InitStruct' / baudratesets (controllers as index)
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_InitObjectStartIndexType, CAN_CONST) Can_InitObjectStartIndex[7] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     InitObjectStartIndex      Comment */
  /*     0 */                    0u,  /* [CT_CAN00_4f940509] */
  /*     1 */                    1u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */                    2u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */                    3u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */                    4u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */                    5u,  /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
  /*     6 */                    6u   /* [stop index] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_IsrOsId
**********************************************************************************************************************/
/** 
  \var    Can_IsrOsId
  \brief  OS Symbolic Name Value for Service Request Nodes.
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_OsIsrType, CAN_CONST) Can_IsrOsId[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     IsrOsId       Comment */
  /*     0 */ CanIsr_4 ,  /* [CT_CAN00_4f940509 [Node | Channel] 4] */
  /*     1 */ CanIsr_5 ,  /* [CT_Schaeffler_MDA_CANFD_ffad619f [Node | Channel] 5] */
  /*     2 */ CanIsr_0 ,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a [Node | Channel] 0] */
  /*     3 */ CanIsr_1 ,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9 [Node | Channel] 1] */
  /*     4 */ CanIsr_2 ,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb [Node | Channel] 2] */
  /*     5 */ CanIsr_3    /* [CT_Schaeffler_MotorRR_CANFD_9073d178 [Node | Channel] 3] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_Mailbox
**********************************************************************************************************************/
/** 
  \var    Can_Mailbox
  \brief  mailbox configuration (over all controllers)
  \details
  Element                Description
  IDValue            
  ActiveSendObject   
  ControllerConfigIdx    the index of the 1:1 relation pointing to Can_ControllerConfig
  FdPadding          
  HwHandle           
  MailboxSize        
  MailboxType        
  MaxDataLen         
  MemorySectionsIndex
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MailboxType, CAN_CONST) Can_Mailbox[61] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    IDValue      ActiveSendObject  ControllerConfigIdx                                                                           FdPadding  HwHandle  MailboxSize  MailboxType                                MaxDataLen  MemorySectionsIndex        Comment                                                                                Referable Keys */
  { /*     0 */ 0x00000000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                   ,        0u,       0u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  0u },  /* [CN_CAN00_8c3ac689_Tx]                                                     */  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_8c3ac689_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     1 */ 0x00000000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                   ,        0u,       1u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  1u },  /* [CN_CAN00_eb5ad8b0_Rx]                                                     */  /* [/ActiveEcuC/Can/CanConfigSet/CN_CAN00_eb5ad8b0_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     2 */ 0x98FF0A11u,               1u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       0u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  2u },  /* [CanHardwareObject_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     3 */ 0x98FF0B10u,               2u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       1u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  3u },  /* [CanHardwareObject_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx]        */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     4 */ 0x98FF0B11u,               3u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       2u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  4u },  /* [CanHardwareObject_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx]        */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     5 */ 0x98FF0C11u,               4u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       3u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  5u },  /* [CanHardwareObject_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx]          */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     6 */ 0x98FF0C12u,               5u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       4u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  6u },  /* [CanHardwareObject_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx]          */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     7 */ 0x98FF0C13u,               6u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       5u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  7u },  /* [CanHardwareObject_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx]          */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     8 */ 0x98FF0C14u,               7u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       6u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  8u },  /* [CanHardwareObject_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx]          */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*     9 */ 0x98FF0D10u,               8u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       7u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                  9u },  /* [CanHardwareObject_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx]            */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    10 */ 0x98FF0E11u,               9u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       8u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 10u },  /* [CanHardwareObject_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    11 */ 0x98FF0E12u,              10u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,       9u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 11u },  /* [CanHardwareObject_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    12 */ 0x98FF0E13u,              11u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      10u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 12u },  /* [CanHardwareObject_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    13 */ 0x98FF0E14u,              12u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      11u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 13u },  /* [CanHardwareObject_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    14 */ 0x98FF0E15u,              13u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      12u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 14u },  /* [CanHardwareObject_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    15 */ 0x98FF0E16u,              14u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      13u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 15u },  /* [CanHardwareObject_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx]      */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    16 */ 0x98FF0F11u,              15u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      14u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 16u },  /* [CanHardwareObject_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx]           */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    17 */ 0x00000000u,              16u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      15u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 17u },  /* [CN_Schaeffler_MDA_CANFD_c149c45e_Tx]                                      */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MDA_CANFD_c149c45e_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    18 */ 0x91FF0C1Fu,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      16u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 18u },  /* [CanHardwareObject_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    19 */ 0x91FF0C1Eu,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      17u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 19u },  /* [CanHardwareObject_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    20 */ 0x91FF0C1Du,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      18u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 20u },  /* [CanHardwareObject_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    21 */ 0x91FF0C1Cu,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      19u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 21u },  /* [CanHardwareObject_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    22 */ 0x91FF0C1Bu,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      20u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 22u },  /* [CanHardwareObject_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    23 */ 0x91FF0C1Au,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      21u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 23u },  /* [CanHardwareObject_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    24 */ 0x91FF0C19u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      22u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 24u },  /* [CanHardwareObject_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    25 */ 0x91FF0C18u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      23u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 25u },  /* [CanHardwareObject_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    26 */ 0x91FF0C17u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      24u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 26u },  /* [CanHardwareObject_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    27 */ 0x91FF0C16u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      25u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 27u },  /* [CanHardwareObject_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    28 */ 0x91FF0C15u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      26u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 28u },  /* [CanHardwareObject_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    29 */ 0x91FF0C14u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      27u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 29u },  /* [CanHardwareObject_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    30 */ 0x91FF0C13u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      28u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 30u },  /* [CanHardwareObject_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    31 */ 0x91FF0C12u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      29u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 31u },  /* [CanHardwareObject_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    32 */ 0x91FF0C11u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      30u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 32u },  /* [CanHardwareObject_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    33 */ 0x91FF0C10u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      31u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 33u },  /* [CanHardwareObject_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    34 */ 0x91FF0B24u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      32u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 34u },  /* [CanHardwareObject_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    35 */ 0x91FF0B23u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      33u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 35u },  /* [CanHardwareObject_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    36 */ 0x91FF0B22u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      34u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 36u },  /* [CanHardwareObject_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    37 */ 0x91FF0B21u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      35u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 37u },  /* [CanHardwareObject_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx] */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    38 */ 0x00000000u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      36u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 38u },  /* [CN_Schaeffler_MDA_CANFD_821576c1_Rx]                                      */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MDA_CANFD_821576c1_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    39 */ 0x98FF0C11u,              17u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,        0u,       0u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 39u },  /* [CanHardwareObject_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx]  */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    40 */ 0x00000000u,              18u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,        0u,       1u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 40u },  /* [CN_Schaeffler_MotorFL_CANFD_b5523491_Tx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFL_CANFD_b5523491_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    41 */ 0x91FF0B11u,               0u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,        0u,       2u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 41u },  /* [CanHardwareObject_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    42 */ 0x00000000u,               0u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,        0u,       3u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 42u },  /* [CN_Schaeffler_MotorFL_CANFD_ef6a29f1_Rx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFL_CANFD_ef6a29f1_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    43 */ 0x98FF0C12u,              19u,                  3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,        0u,       0u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 43u },  /* [CanHardwareObject_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx]  */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    44 */ 0x00000000u,              20u,                  3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,        0u,       1u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 44u },  /* [CN_Schaeffler_MotorFR_CANFD_82b3d302_Tx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFR_CANFD_82b3d302_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    45 */ 0x91FF0B12u,               0u,                  3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,        0u,       2u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 45u },  /* [CanHardwareObject_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    46 */ 0x00000000u,               0u,                  3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,        0u,       3u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 46u },  /* [CN_Schaeffler_MotorFR_CANFD_29cfe1c4_Rx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorFR_CANFD_29cfe1c4_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    47 */ 0x98FF0C13u,              21u,                  4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,        0u,       0u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 47u },  /* [CanHardwareObject_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx]  */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    48 */ 0x00000000u,              22u,                  4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,        0u,       1u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 48u },  /* [CN_Schaeffler_MotorRL_CANFD_4da30b40_Tx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRL_CANFD_4da30b40_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    49 */ 0x91FF0B13u,               0u,                  4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,        0u,       2u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 49u },  /* [CanHardwareObject_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
    /* Index    IDValue      ActiveSendObject  ControllerConfigIdx                                                                           FdPadding  HwHandle  MailboxSize  MailboxType                                MaxDataLen  MemorySectionsIndex        Comment                                                                                Referable Keys */
  { /*    50 */ 0x00000000u,               0u,                  4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,        0u,       3u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 50u },  /* [CN_Schaeffler_MotorRL_CANFD_8b339743_Rx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRL_CANFD_8b339743_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    51 */ 0x98FF0C14u,              23u,                  5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,        0u,       0u,          1u,  CAN_TX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 51u },  /* [CanHardwareObject_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx]  */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178, TX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    52 */ 0x00000000u,              24u,                  5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,        0u,       1u,          1u, CAN_TX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 52u },  /* [CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Tx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Tx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178, TX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    53 */ 0x91FF0B14u,               0u,                  5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,        0u,       2u,          1u,  CAN_RX_FULLCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 53u },  /* [CanHardwareObject_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx]     */  /* [/ActiveEcuC/Can/CanConfigSet/CanHardwareObject_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178, RX_FULLCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    54 */ 0x00000000u,               0u,                  5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,        0u,       3u,          6u, CAN_RX_BASICCAN_TYPE_MAILBOXTYPEOFMAILBOX,        64u,                 54u },  /* [CN_Schaeffler_MotorRR_CANFD_4d965f76_Rx]                                  */  /* [/ActiveEcuC/Can/CanConfigSet/CN_Schaeffler_MotorRR_CANFD_4d965f76_Rx (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanHardwareObject), /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178, RX_BASICCAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    55 */ 0x00000000u,               0u,                  0u  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                   ,        0u,       2u,         96u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                  2u },  /* []                                                                         */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    56 */ 0x00000000u,               0u,                  1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,        0u,      37u,         61u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                 39u },  /* []                                                                         */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    57 */ 0x00000000u,               0u,                  2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,        0u,       4u,         94u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                 43u },  /* []                                                                         */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    58 */ 0x00000000u,               0u,                  3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,        0u,       4u,         94u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                 47u },  /* []                                                                         */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    59 */ 0x00000000u,               0u,                  4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,        0u,       4u,         94u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                 51u },  /* []                                                                         */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
  { /*    60 */ 0x00000000u,               0u,                  5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,        0u,       4u,         94u,  CAN_UNUSED_CAN_TYPE_MAILBOXTYPEOFMAILBOX,         0u,                 55u }   /* []                                                                         */  /* [undefined, /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178, UNUSED_CAN_TYPE/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 (DefRef: /MICROSAR/Can_Mpc5700Mcan/Can/CanConfigSet/CanController)] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionInfo
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionInfo
  \brief  Memory section description
  \details
  Element               Description
  MemorySectionStart
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionInfoType, CAN_CONST) Can_MemorySectionInfo[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MemorySectionStart        Comment */
  { /*     0 */                 0u },  /* [MemorySection: Memory_CT_CAN00_4f940509] */
  { /*     1 */                 2u },  /* [MemorySection: Memory_CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */                39u },  /* [MemorySection: Memory_CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */                43u },  /* [MemorySection: Memory_CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */                47u },  /* [MemorySection: Memory_CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */                51u }   /* [MemorySection: Memory_CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_MemorySectionObjects
**********************************************************************************************************************/
/** 
  \var    Can_MemorySectionObjects
  \brief  Memory section objects description
  \details
  Element           Description
  HwHandle      
  MailboxElement
  MailboxHandle 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_MemorySectionObjectsType, CAN_CONST) Can_MemorySectionObjects[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*     0 */       0u,             0u,            0u },  /* [Memory_CT_CAN00_4f940509 - CN_CAN00_8c3ac689_Tx] */
  { /*     1 */       1u,             0u,            1u },  /* [Memory_CT_CAN00_4f940509 - CN_CAN00_eb5ad8b0_Rx] */
  { /*     2 */       0u,             0u,            2u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx] */
  { /*     3 */       1u,             0u,            3u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx] */
  { /*     4 */       2u,             0u,            4u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx] */
  { /*     5 */       3u,             0u,            5u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx] */
  { /*     6 */       4u,             0u,            6u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx] */
  { /*     7 */       5u,             0u,            7u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx] */
  { /*     8 */       6u,             0u,            8u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx] */
  { /*     9 */       7u,             0u,            9u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx] */
  { /*    10 */       8u,             0u,           10u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx] */
  { /*    11 */       9u,             0u,           11u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx] */
  { /*    12 */      10u,             0u,           12u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx] */
  { /*    13 */      11u,             0u,           13u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx] */
  { /*    14 */      12u,             0u,           14u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx] */
  { /*    15 */      13u,             0u,           15u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx] */
  { /*    16 */      14u,             0u,           16u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx] */
  { /*    17 */      15u,             0u,           17u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CN_Schaeffler_MDA_CANFD_c149c45e_Tx] */
  { /*    18 */      16u,             0u,           18u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx] */
  { /*    19 */      17u,             0u,           19u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx] */
  { /*    20 */      18u,             0u,           20u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx] */
  { /*    21 */      19u,             0u,           21u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx] */
  { /*    22 */      20u,             0u,           22u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx] */
  { /*    23 */      21u,             0u,           23u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx] */
  { /*    24 */      22u,             0u,           24u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx] */
  { /*    25 */      23u,             0u,           25u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx] */
  { /*    26 */      24u,             0u,           26u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx] */
  { /*    27 */      25u,             0u,           27u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx] */
  { /*    28 */      26u,             0u,           28u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx] */
  { /*    29 */      27u,             0u,           29u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx] */
  { /*    30 */      28u,             0u,           30u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx] */
  { /*    31 */      29u,             0u,           31u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx] */
  { /*    32 */      30u,             0u,           32u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx] */
  { /*    33 */      31u,             0u,           33u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx] */
  { /*    34 */      32u,             0u,           34u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx] */
  { /*    35 */      33u,             0u,           35u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx] */
  { /*    36 */      34u,             0u,           36u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx] */
  { /*    37 */      35u,             0u,           37u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CanHardwareObject_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx] */
  { /*    38 */      36u,             0u,           38u },  /* [Memory_CT_Schaeffler_MDA_CANFD_ffad619f - CN_Schaeffler_MDA_CANFD_821576c1_Rx] */
  { /*    39 */       0u,             0u,           39u },  /* [Memory_CT_Schaeffler_MotorFL_CANFD_5f63093a - CanHardwareObject_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx] */
  { /*    40 */       1u,             0u,           40u },  /* [Memory_CT_Schaeffler_MotorFL_CANFD_5f63093a - CN_Schaeffler_MotorFL_CANFD_b5523491_Tx] */
  { /*    41 */       2u,             0u,           41u },  /* [Memory_CT_Schaeffler_MotorFL_CANFD_5f63093a - CanHardwareObject_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx] */
  { /*    42 */       3u,             0u,           42u },  /* [Memory_CT_Schaeffler_MotorFL_CANFD_5f63093a - CN_Schaeffler_MotorFL_CANFD_ef6a29f1_Rx] */
  { /*    43 */       0u,             0u,           43u },  /* [Memory_CT_Schaeffler_MotorFR_CANFD_6882eea9 - CanHardwareObject_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx] */
  { /*    44 */       1u,             0u,           44u },  /* [Memory_CT_Schaeffler_MotorFR_CANFD_6882eea9 - CN_Schaeffler_MotorFR_CANFD_82b3d302_Tx] */
  { /*    45 */       2u,             0u,           45u },  /* [Memory_CT_Schaeffler_MotorFR_CANFD_6882eea9 - CanHardwareObject_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx] */
  { /*    46 */       3u,             0u,           46u },  /* [Memory_CT_Schaeffler_MotorFR_CANFD_6882eea9 - CN_Schaeffler_MotorFR_CANFD_29cfe1c4_Rx] */
  { /*    47 */       0u,             0u,           47u },  /* [Memory_CT_Schaeffler_MotorRL_CANFD_a79236eb - CanHardwareObject_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx] */
  { /*    48 */       1u,             0u,           48u },  /* [Memory_CT_Schaeffler_MotorRL_CANFD_a79236eb - CN_Schaeffler_MotorRL_CANFD_4da30b40_Tx] */
  { /*    49 */       2u,             0u,           49u },  /* [Memory_CT_Schaeffler_MotorRL_CANFD_a79236eb - CanHardwareObject_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx] */
    /* Index    HwHandle  MailboxElement  MailboxHandle        Comment */
  { /*    50 */       3u,             0u,           50u },  /* [Memory_CT_Schaeffler_MotorRL_CANFD_a79236eb - CN_Schaeffler_MotorRL_CANFD_8b339743_Rx] */
  { /*    51 */       0u,             0u,           51u },  /* [Memory_CT_Schaeffler_MotorRR_CANFD_9073d178 - CanHardwareObject_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx] */
  { /*    52 */       1u,             0u,           52u },  /* [Memory_CT_Schaeffler_MotorRR_CANFD_9073d178 - CN_Schaeffler_MotorRR_CANFD_7a42ecd3_Tx] */
  { /*    53 */       2u,             0u,           53u },  /* [Memory_CT_Schaeffler_MotorRR_CANFD_9073d178 - CanHardwareObject_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx] */
  { /*    54 */       3u,             0u,           54u }   /* [Memory_CT_Schaeffler_MotorRR_CANFD_9073d178 - CN_Schaeffler_MotorRR_CANFD_4d965f76_Rx] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFC
**********************************************************************************************************************/
/** 
  \var    Can_SIDFC
  \brief  Standard ID filter configuration
  \details
  Element          Description
  FLSSA            Filter List Standard Start Address
  LSS              List size standard
  SIDFEEndIdx      the end index of the 0:n relation pointing to Can_SIDFE
  SIDFEStartIdx    the start index of the 0:n relation pointing to Can_SIDFE
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SIDFCType, CAN_CONST) Can_SIDFC[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FLSSA    LSS    SIDFEEndIdx                                                                           SIDFEStartIdx                                                                                 Comment */
  { /*     0 */ 0x0000u, 0x01u,          1u  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                   ,            0u  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                    },  /* [CT_CAN00_4f940509] */
  { /*     1 */ 0x01FCu, 0x01u,          2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,            1u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */     },  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0x0000u, 0x01u,          3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,            2u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */ },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */ 0x0294u, 0x01u,          4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,            3u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */ },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */ 0x0528u, 0x01u,          5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,            4u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */ },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */ 0x07BCu, 0x01u,          6u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,            5u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */ }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SIDFE
**********************************************************************************************************************/
/** 
  \var    Can_SIDFE
  \brief  Standard ID filters
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SIDFEType, CAN_CONST) Can_SIDFE[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SIDFE                                   Comment                                       Referable Keys */
  /*     0 */  0x88000000u  /*  I: 0 S0 FIFO_0 */,  /* [CT_CAN00_4f940509]                    */  /* [/ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509] */
  /*     1 */  0x88000000u  /*  I: 0 S0 FIFO_0 */,  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */  0x88000000u  /*  I: 0 S0 FIFO_0 */,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */  0x88000000u  /*  I: 0 S0 FIFO_0 */,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */  0x88000000u  /*  I: 0 S0 FIFO_0 */,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */  0x88000000u  /*  I: 0 S0 FIFO_0 */   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_SRN_Address
**********************************************************************************************************************/
/** 
  \var    Can_SRN_Address
  \brief  Service Request Node Addresses
*/ 
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_SRN_AddressType, CAN_CONST) Can_SRN_Address[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     SRN_Address      Comment */
  /*     0 */  0xF00385F0u,  /* [CT_CAN00_4f940509] */
  /*     1 */  0xF00385F4u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */  0xF00385B0u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */  0xF00385B4u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */  0xF00385B8u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */  0xF00385BCu   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ShmAdr
**********************************************************************************************************************/
/** 
  \var    Can_ShmAdr
  \brief  CAN Shared Message RAM configuration
  \details
  Element     Description
  RXBA        RX Buffer Address
  RXF0A       RX FIFO0 Address
  RXF1A       RX FIFO1 Address
  SIDFA       Standard Filters Address
  StartAdr    Start address of the shared memory area
  StopAdr     Stop address of the shared memory area
  TXBA        TX Buffer address
  TXEFA       TX Event FIFO address
  XIDFA       Extended Filters Address
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ShmAdrType, CAN_CONST) Can_ShmAdr[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RXBA                              RXF0A                            RXF1A                          SIDFA                          StartAdr     StopAdr      TXBA                              TXEFA                          XIDFA                                  Comment */
  { /*     0 */ 0xF0210000u  /* Size[B]: 0 */   , 0xF0210004u  /* Size[B]: 432 */, 0xF0210000u  /* Size[B]: 0 */, 0xF0210000u  /* Size[B]: 4 */, 0xF0210000u, 0xF02101FDu, 0xF02101B4u  /* Size[B]: 72 */  , 0xF0210000u  /* Size[B]: 0 */, 0xF0210000u  /* Size[B]: 0 */   },  /* [CT_CAN00_4f940509] */
  { /*     1 */ 0xF0210450u  /* Size[B]: 1440 */, 0xF02102A0u  /* Size[B]: 432 */, 0xF0210000u  /* Size[B]: 0 */, 0xF02101FCu  /* Size[B]: 4 */, 0xF0210000u, 0xF0210E71u, 0xF02109F0u  /* Size[B]: 1152 */, 0xF0210000u  /* Size[B]: 0 */, 0xF0210200u  /* Size[B]: 160 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0xF02001BCu  /* Size[B]: 72 */  , 0xF020000Cu  /* Size[B]: 432 */, 0xF0200000u  /* Size[B]: 0 */, 0xF0200000u  /* Size[B]: 4 */, 0xF0200000u, 0xF0200295u, 0xF0200204u  /* Size[B]: 144 */ , 0xF0200000u  /* Size[B]: 0 */, 0xF0200004u  /* Size[B]: 8 */   },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */ 0xF0200450u  /* Size[B]: 72 */  , 0xF02002A0u  /* Size[B]: 432 */, 0xF0200000u  /* Size[B]: 0 */, 0xF0200294u  /* Size[B]: 4 */, 0xF0200000u, 0xF0200529u, 0xF0200498u  /* Size[B]: 144 */ , 0xF0200000u  /* Size[B]: 0 */, 0xF0200298u  /* Size[B]: 8 */   },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */ 0xF02006E4u  /* Size[B]: 72 */  , 0xF0200534u  /* Size[B]: 432 */, 0xF0200000u  /* Size[B]: 0 */, 0xF0200528u  /* Size[B]: 4 */, 0xF0200000u, 0xF02007BDu, 0xF020072Cu  /* Size[B]: 144 */ , 0xF0200000u  /* Size[B]: 0 */, 0xF020052Cu  /* Size[B]: 8 */   },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */ 0xF0200978u  /* Size[B]: 72 */  , 0xF02007C8u  /* Size[B]: 432 */, 0xF0200000u  /* Size[B]: 0 */, 0xF02007BCu  /* Size[B]: 4 */, 0xF0200000u, 0xF0200A51u, 0xF02009C0u  /* Size[B]: 144 */ , 0xF0200000u  /* Size[B]: 0 */, 0xF02007C0u  /* Size[B]: 8 */   }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ShmElementSize
**********************************************************************************************************************/
/** 
  \var    Can_ShmElementSize
  \brief  data buffer size in case of CAN_FD Full
  \details
  Element    Description
  F0DS   
  F1DS   
  RBDS   
  TBDS   
  TEFBDS 
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_ShmElementSizeType, CAN_CONST) Can_ShmElementSize[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    F0DS                  F1DS                  RBDS                  TBDS                  TEFBDS                        Comment */
  { /*     0 */ 0x07u  /* F0DS 64 */, 0x00u  /* F1DS 8 */ , 0x00u  /* RBDS 8 */ , 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ },  /* [CT_CAN00_4f940509] */
  { /*     1 */ 0x07u  /* F0DS 64 */, 0x07u  /* F1DS 64 */, 0x07u  /* RBDS 64 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0x07u  /* F0DS 64 */, 0x00u  /* F1DS 8 */ , 0x07u  /* RBDS 64 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */ 0x07u  /* F0DS 64 */, 0x00u  /* F1DS 8 */ , 0x07u  /* RBDS 64 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */ 0x07u  /* F0DS 64 */, 0x00u  /* F1DS 8 */ , 0x07u  /* RBDS 64 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */ 0x07u  /* F0DS 64 */, 0x00u  /* F1DS 8 */ , 0x07u  /* RBDS 64 */, 0x07u  /* TBDS 64 */,  0x00u  /* EFTBDS 8 */ }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_TDCR
**********************************************************************************************************************/
/** 
  \var    Can_TDCR
  \brief  Transmitter Delay Compensation
*/ 
#define CAN_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_TDCRType, CAN_CONST) Can_TDCR[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TDCR       Comment */
  /*     0 */  0x00u,  /* [CT_CAN00_4f940509 - CanControllerBaudrateConfig] */
  /*     1 */  0x00u,  /* [CT_Schaeffler_MDA_CANFD_ffad619f - CanControllerBaudrateConfig] */
  /*     2 */  0x00u,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a - CanControllerBaudrateConfig] */
  /*     3 */  0x00u,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9 - CanControllerBaudrateConfig] */
  /*     4 */  0x00u,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb - CanControllerBaudrateConfig] */
  /*     5 */  0x00u   /* [CT_Schaeffler_MotorRR_CANFD_9073d178 - CanControllerBaudrateConfig] */
};
#define CAN_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDAM
**********************************************************************************************************************/
#define CAN_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDAMType, CAN_CONST) Can_XIDAM[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     XIDAM            Comment */
  /*     0 */  0x1FFFFFFFu,  /* [CT_CAN00_4f940509] */
  /*     1 */  0x1FFFFFFFu,  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  /*     2 */  0x1FFFFFFFu,  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  /*     3 */  0x1FFFFFFFu,  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  /*     4 */  0x1FFFFFFFu,  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  /*     5 */  0x1FFFFFFFu   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFC
**********************************************************************************************************************/
/** 
  \var    Can_XIDFC
  \brief  Extended ID filter configuration
  \details
  Element          Description
  FLESA            Filter List Extended Start Address
  LSE              List size extended
  XIDFEEndIdx      the end index of the 0:n relation pointing to Can_XIDFE
  XIDFEStartIdx    the start index of the 0:n relation pointing to Can_XIDFE
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDFCType, CAN_CONST) Can_XIDFC[6] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    FLESA    LSE    XIDFEEndIdx                                                                                         XIDFEStartIdx                                                                                               Comment */
  { /*     0 */ 0x0000u, 0x00u, CAN_NO_XIDFEENDIDXOFXIDFC  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                   , CAN_NO_XIDFESTARTIDXOFXIDFC  /* /ActiveEcuC/Can/CanConfigSet/CT_CAN00_4f940509 */                    },  /* [CT_CAN00_4f940509] */
  { /*     1 */ 0x0200u, 0x14u,                       20u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */    ,                          0u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f */     },  /* [CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0x0004u, 0x01u,                       21u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */,                         20u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a */ },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*     3 */ 0x0298u, 0x01u,                       22u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */,                         21u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9 */ },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*     4 */ 0x052Cu, 0x01u,                       23u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */,                         22u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb */ },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*     5 */ 0x07C0u, 0x01u,                       24u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */,                         23u  /* /ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178 */ }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_XIDFE
**********************************************************************************************************************/
/** 
  \var    Can_XIDFE
  \brief  Extended ID filters
  \details
  Element    Description
  EIDFE_0
  EIDFE_1
*/ 
#define CAN_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Can_XIDFEType, CAN_CONST) Can_XIDFE[24] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    EIDFE_0                        EIDFE_1                              Comment                                            Referable Keys */
  { /*     0 */ 0xF1FF0C1Fu  /* FULLCAN_0 */ , 0x80000000u  /* FULLCAN_0 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     1 */ 0xF1FF0C1Eu  /* FULLCAN_1 */ , 0x80000001u  /* FULLCAN_1 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     2 */ 0xF1FF0C1Du  /* FULLCAN_2 */ , 0x80000002u  /* FULLCAN_2 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     3 */ 0xF1FF0C1Cu  /* FULLCAN_3 */ , 0x80000003u  /* FULLCAN_3 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     4 */ 0xF1FF0C1Bu  /* FULLCAN_4 */ , 0x80000004u  /* FULLCAN_4 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     5 */ 0xF1FF0C1Au  /* FULLCAN_5 */ , 0x80000005u  /* FULLCAN_5 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     6 */ 0xF1FF0C19u  /* FULLCAN_6 */ , 0x80000006u  /* FULLCAN_6 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     7 */ 0xF1FF0C18u  /* FULLCAN_7 */ , 0x80000007u  /* FULLCAN_7 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     8 */ 0xF1FF0C17u  /* FULLCAN_8 */ , 0x80000008u  /* FULLCAN_8 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*     9 */ 0xF1FF0C16u  /* FULLCAN_9 */ , 0x80000009u  /* FULLCAN_9 */  },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    10 */ 0xF1FF0C15u  /* FULLCAN_10 */, 0x8000000Au  /* FULLCAN_10 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    11 */ 0xF1FF0C14u  /* FULLCAN_11 */, 0x8000000Bu  /* FULLCAN_11 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    12 */ 0xF1FF0C13u  /* FULLCAN_12 */, 0x8000000Cu  /* FULLCAN_12 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    13 */ 0xF1FF0C12u  /* FULLCAN_13 */, 0x8000000Du  /* FULLCAN_13 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    14 */ 0xF1FF0C11u  /* FULLCAN_14 */, 0x8000000Eu  /* FULLCAN_14 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    15 */ 0xF1FF0C10u  /* FULLCAN_15 */, 0x8000000Fu  /* FULLCAN_15 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    16 */ 0xF1FF0B24u  /* FULLCAN_16 */, 0x80000010u  /* FULLCAN_16 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    17 */ 0xF1FF0B23u  /* FULLCAN_17 */, 0x80000011u  /* FULLCAN_17 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    18 */ 0xF1FF0B22u  /* FULLCAN_18 */, 0x80000012u  /* FULLCAN_18 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    19 */ 0xF1FF0B21u  /* FULLCAN_19 */, 0x80000013u  /* FULLCAN_19 */ },  /* [CT_Schaeffler_MDA_CANFD_ffad619f]     */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MDA_CANFD_ffad619f] */
  { /*    20 */ 0xF1FF0B11u  /* FULLCAN_0 */ , 0x80000000u  /* FULLCAN_0 */  },  /* [CT_Schaeffler_MotorFL_CANFD_5f63093a] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFL_CANFD_5f63093a] */
  { /*    21 */ 0xF1FF0B12u  /* FULLCAN_0 */ , 0x80000000u  /* FULLCAN_0 */  },  /* [CT_Schaeffler_MotorFR_CANFD_6882eea9] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorFR_CANFD_6882eea9] */
  { /*    22 */ 0xF1FF0B13u  /* FULLCAN_0 */ , 0x80000000u  /* FULLCAN_0 */  },  /* [CT_Schaeffler_MotorRL_CANFD_a79236eb] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRL_CANFD_a79236eb] */
  { /*    23 */ 0xF1FF0B14u  /* FULLCAN_0 */ , 0x80000000u  /* FULLCAN_0 */  }   /* [CT_Schaeffler_MotorRR_CANFD_9073d178] */  /* [/ActiveEcuC/Can/CanConfigSet/CT_Schaeffler_MotorRR_CANFD_9073d178] */
};
#define CAN_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ActiveSendObject
**********************************************************************************************************************/
/** 
  \var    Can_ActiveSendObject
  \brief  temporary data for TX object
  \details
  Element    Description
  State      send state like cancelled or send activ
  Pdu        buffered PduId for confirmation or cancellation
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ActiveSendObjectType, CAN_VAR_NOINIT) Can_ActiveSendObject[25];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Can_ControllerData
**********************************************************************************************************************/
/** 
  \var    Can_ControllerData
  \brief  struct for all controller related variable data
  \details
  Element                      Description
  IntEnable                    CAN Interrupt Enable state for each controller
  NonFdObjectsPendingFlag      CAN Tx Objects pending with CAN-FD format
  TXBCR                        CAN Tx Buffer Cancellation Request for each controller
  TXBRP                        CAN Tx Buffer request Pending for each controller
  BusOffNotification           CAN state for each controller: busoff occur
  BusOffTransitionRequest      CAN state request for each controller: ContinueBusOffRecovery=0x00, FinishBusOffRecovery=0x01
  CanInterruptCounter          CAN interrupt disable counter for each controller
  IsBusOff                     CAN state for each controller: busoff occur
  LastInitObject               last set baudrate for reinit
  LastState                    CAN mode transition request status for each controller
  LogStatus                    CAN state for each controller: UNINIT=0x00, START=0x01, STOP=0x02, INIT=0x04, INCONSISTENT=0x08, WARNING =0x10, PASSIVE=0x20, BUSOFF=0x40, SLEEP=0x80
  ModeTransitionRequest        CAN state request for each controller: INIT=0x00, SLEEP=0x01, WAKEUP=0x02, STOP+INIT=0x03, START=0x04, START+INIT=0x05, NONE=0x06
  PrevMode                     CAN mode transition request for each controller
  RamCheckTransitionRequest    CAN state request for each controller: kCanSuppressRamCheck=0x01, kCanExecuteRamCheck=0x00
  CanInterruptOldStatus        last CAN interrupt status for restore interrupt for each controller
  LoopTimeout                  hw loop timeout for each controller
*/ 
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Can_ControllerDataType, CAN_VAR_NOINIT) Can_ControllerData[6];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/




