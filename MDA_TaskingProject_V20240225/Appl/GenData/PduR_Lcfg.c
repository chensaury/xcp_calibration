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
 *            Module: PduR
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: PduR_Lcfg.c
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

#define PDUR_LCFG_SOURCE

/**********************************************************************************************************************
 * MISRA / PCLINT JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR.h"
#include "PduR_Fm.h"
#include "PduR_Sm.h"
#include "PduR_RmIf.h"
#include "PduR_RmTp.h"
#include "PduR_RmTp_TxInst.h"
#include "SchM_PduR.h"
#if(PDUR_DEV_ERROR_REPORT == STD_ON)
# include "Det.h"
#endif

/* Include headers with callbacks */
#include "PduR_CanIf.h"
#include "PduR_Com.h"


/**********************************************************************************************************************
 * LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Exclusive Area Wrapper functions */
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void);
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void);
  
/**********************************************************************************************************************
 * LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA
 *********************************************************************************************************************/
/* \trace SPEC-663, SPEC-661 */

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA
**********************************************************************************************************************/
/**********************************************************************************************************************
  PduR_ExclusiveAreaRom
**********************************************************************************************************************/
/** 
  \var    PduR_ExclusiveAreaRom
  \brief  PduR Exclusive Area Locks
  \details
  Element    Description
  Lock       Lock function
  Unlock     Unlock function
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_ExclusiveAreaRomType, PDUR_CONST) PduR_ExclusiveAreaRom[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Lock                                        Unlock                                           Referable Keys */
  { /*     0 */ PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0, PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0 }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRLock_PduRExclusiveArea] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_IfRoutingStateTable
**********************************************************************************************************************/
/** 
  \var    PduR_IfRoutingStateTable
  \brief  Contains state transition for Communication Interface routings
  \details
  Element                                   Description
  NextState_For_Init_If_Routing_State   
  NextState_For_Wait_For_RxIndication   
  NextState_For_Wait_For_TriggerTransmit
  NextState_For_Wait_For_TxConfirmation 
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_IfRoutingStateTableType, PDUR_CONST) PduR_IfRoutingStateTable[4] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    NextState_For_Init_If_Routing_State                                                     NextState_For_Wait_For_RxIndication                                                     NextState_For_Wait_For_TriggerTransmit                                                     NextState_For_Wait_For_TxConfirmation                                                    */
  { /*     0 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                        0u,                                                                                       0u },
  { /*     1 */ PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE,                                                                                       0u },
  { /*     2 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TRIGGERTRANSMITOFIFROUTINGSTATETABLE, PDUR_WAIT_FOR_TRIGGERTRANSMIT_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE },
  { /*     3 */    PDUR_WAIT_FOR_RXINDICATION_NEXTSTATE_FOR_INIT_IF_ROUTING_STATEOFIFROUTINGSTATETABLE,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_RXINDICATIONOFIFROUTINGSTATETABLE,                                                                                        0u,  PDUR_WAIT_FOR_TXCONFIRMATION_NEXTSTATE_FOR_WAIT_FOR_TXCONFIRMATIONOFIFROUTINGSTATETABLE }
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_MmRom
**********************************************************************************************************************/
/** 
  \var    PduR_MmRom
  \brief  Module manager: Contains all function pointers of the bordering modules.
  \details
  Element                     Description
  CoreManagerRomIdx           the index of the 1:1 relation pointing to PduR_CoreManagerRom
  MaskedBits                  contains bitcoded the boolean data of PduR_LoIfOfMmRom, PduR_RmGDestRomUsedOfMmRom, PduR_UpIfOfMmRom
  RmGDestRomEndIdx            the end index of the 0:n relation pointing to PduR_RmGDestRom
  RmGDestRomStartIdx          the start index of the 0:n relation pointing to PduR_RmGDestRom
  UpIfRxIndicationFctPtr      Upper layer communication interface Rx indication function pointers.
  UpIfTxConfirmationFctPtr    Upper layer communication interface Tx confimation function pointers
  LoIfTransmitFctPtr          Lower layer If transmit function pointers
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_MmRomType, PDUR_CONST) PduR_MmRom[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    CoreManagerRomIdx  MaskedBits  RmGDestRomEndIdx  RmGDestRomStartIdx  UpIfRxIndicationFctPtr  UpIfTxConfirmationFctPtr  LoIfTransmitFctPtr        Comment                        Referable Keys */
  { /*     0 */                0u,      0x06u,              19u,                 0u, NULL_PTR              , NULL_PTR                , CanIf_Transmit     },  /* [BswModule: CanIf] */  /* [/ActiveEcuC/PduR/CanIf, /ActiveEcuC/PduR] */
  { /*     1 */                0u,      0x03u,              55u,                19u, Com_RxIndication      , Com_TxConfirmation      , NULL_PTR           }   /* [BswModule: Com]   */  /* [/ActiveEcuC/PduR/Com, /ActiveEcuC/PduR] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmDestRom
  \brief  PduR RoutiongPathManager destPdu Table
  \details
  Element          Description
  RmGDestRomIdx    the index of the 1:1 relation pointing to PduR_RmGDestRom
  RmSrcRomIdx      the index of the 1:1 relation pointing to PduR_RmSrcRom
  RoutingType      Type of the Routing (API Forwarding, Gateway).
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmDestRomType, PDUR_CONST) PduR_RmDestRom[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                       Referable Keys */
  { /*     0 */           31u,         12u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_20439ccc_Rx_00ca1874_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_20439ccc_Rx/PduRSrcPdu_00ca1874, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_20439ccc_Rx/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_20439ccc_Rx_00ca1874_Rx] */
  { /*     1 */           32u,         13u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5e9b2c8d_Rx_0182d1a5_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5e9b2c8d_Rx/PduRSrcPdu_0182d1a5, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5e9b2c8d_Rx/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5e9b2c8d_Rx_0182d1a5_Rx] */
  { /*     2 */           15u,         51u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx/PduRSrcPdu_01dee4b4, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx] */
  { /*     3 */           25u,          6u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2975b1aa_Rx_01f05597_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2975b1aa_Rx/PduRSrcPdu_01f05597, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2975b1aa_Rx/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2975b1aa_Rx_01f05597_Rx] */
  { /*     4 */           13u,         49u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx/PduRSrcPdu_12d568b6, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx] */
  { /*     5 */           52u,         33u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VddmPropFr10_oCAN00_0b6b9fd8_Rx_14940491_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr10_oCAN00_0b6b9fd8_Rx/PduRSrcPdu_14940491, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr10_oCAN00_0b6b9fd8_Rx/VddmPropFr10_oCAN00_0b6b9fd8_Rx_14940491_Rx] */
  { /*     6 */           53u,         34u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VddmPropFr12_oCAN00_e6fd4c31_Rx_1550c19a_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr12_oCAN00_e6fd4c31_Rx/PduRSrcPdu_1550c19a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr12_oCAN00_e6fd4c31_Rx/VddmPropFr12_oCAN00_e6fd4c31_Rx_1550c19a_Rx] */
  { /*     7 */           11u,         47u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx/PduRSrcPdu_1a5b62cb, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx] */
  { /*     8 */           27u,          8u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_7541e07a_Rx_22b98a3a_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_7541e07a_Rx/PduRSrcPdu_22b98a3a, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_7541e07a_Rx/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_7541e07a_Rx_22b98a3a_Rx] */
  { /*     9 */           46u,         27u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_af0c3bc6_Rx_2ae17888_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_af0c3bc6_Rx/PduRSrcPdu_2ae17888, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_af0c3bc6_Rx/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_af0c3bc6_Rx_2ae17888_Rx] */
  { /*    10 */            4u,         40u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx]              */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx/PduRSrcPdu_2ae8f5e9, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx] */
  { /*    11 */           37u,         18u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_01f5f23f_Rx_2dc7503e_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_01f5f23f_Rx/PduRSrcPdu_2dc7503e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_01f5f23f_Rx/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_01f5f23f_Rx_2dc7503e_Rx] */
  { /*    12 */            9u,         45u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx]                       */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx/PduRSrcPdu_31999496, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx/MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx] */
  { /*    13 */           44u,         25u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_a223d9ce_Rx_32000ae6_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_a223d9ce_Rx/PduRSrcPdu_32000ae6, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_a223d9ce_Rx/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_a223d9ce_Rx_32000ae6_Rx] */
  { /*    14 */            2u,         38u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx]              */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx/PduRSrcPdu_3adb47be, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx] */
  { /*    15 */           35u,         16u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4077d503_Rx_3b0ccb8b_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4077d503_Rx/PduRSrcPdu_3b0ccb8b, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4077d503_Rx/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4077d503_Rx_3b0ccb8b_Rx] */
  { /*    16 */           29u,         10u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_fde13b0b_Rx_3baae64e_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_fde13b0b_Rx/PduRSrcPdu_3baae64e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_fde13b0b_Rx/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_fde13b0b_Rx_3baae64e_Rx] */
  { /*    17 */           48u,         29u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: TcmPropFr04_oCAN00_293cb77e_Rx_440872d3_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/TcmPropFr04_oCAN00_293cb77e_Rx/PduRSrcPdu_440872d3, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/TcmPropFr04_oCAN00_293cb77e_Rx/TcmPropFr04_oCAN00_293cb77e_Rx_440872d3_Rx] */
  { /*    18 */           18u,         54u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx/PduRSrcPdu_46cea922, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx/MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx] */
  { /*    19 */           43u,         24u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_dc5755f8_Rx_497553e8_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_dc5755f8_Rx/PduRSrcPdu_497553e8, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_dc5755f8_Rx/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_dc5755f8_Rx_497553e8_Rx] */
  { /*    20 */            0u,         36u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx]                 */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx/PduRSrcPdu_49ab7256, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx] */
  { /*    21 */           45u,         26u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_c1eff401_Rx_4b661c96_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_c1eff401_Rx/PduRSrcPdu_4b661c96, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_c1eff401_Rx/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_c1eff401_Rx_4b661c96_Rx] */
  { /*    22 */           50u,         31u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VddmPropFr08_oCAN00_8af7b9d9_Rx_4c43d725_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr08_oCAN00_8af7b9d9_Rx/PduRSrcPdu_4c43d725, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr08_oCAN00_8af7b9d9_Rx/VddmPropFr08_oCAN00_8af7b9d9_Rx_4c43d725_Rx] */
  { /*    23 */           41u,         22u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_21e6357a_Rx_4e8ce9aa_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_21e6357a_Rx/PduRSrcPdu_4e8ce9aa, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_21e6357a_Rx/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_21e6357a_Rx_4e8ce9aa_Rx] */
  { /*    24 */           49u,         30u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VddmPropFr05_oCAN00_1161b1b8_Rx_57d9311c_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr05_oCAN00_1161b1b8_Rx/PduRSrcPdu_57d9311c, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr05_oCAN00_1161b1b8_Rx/VddmPropFr05_oCAN00_1161b1b8_Rx_57d9311c_Rx] */
  { /*    25 */            7u,         43u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx]                      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx/PduRSrcPdu_5f10ea86, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx/MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx] */
  { /*    26 */           10u,         46u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx/PduRSrcPdu_66a5da13, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx] */
  { /*    27 */            3u,         39u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx]              */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx/PduRSrcPdu_6b1a4ec4, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx] */
  { /*    28 */           51u,         32u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VddmPropFr09_oCAN00_1184530d_Rx_6c7f8382_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr09_oCAN00_1184530d_Rx/PduRSrcPdu_6c7f8382, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr09_oCAN00_1184530d_Rx/VddmPropFr09_oCAN00_1184530d_Rx_6c7f8382_Rx] */
  { /*    29 */           12u,         48u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx/PduRSrcPdu_75afcc50, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx] */
  { /*    30 */           38u,         19u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7f2d427e_Rx_75e7ddd6_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7f2d427e_Rx/PduRSrcPdu_75e7ddd6, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7f2d427e_Rx/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7f2d427e_Rx_75e7ddd6_Rx] */
  { /*    31 */            1u,         37u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx]              */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx/PduRSrcPdu_7724956e, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx] */
  { /*    32 */           21u,          2u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EcmPropFr07_oCAN00_b0e01d02_Rx_85bab85c_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr07_oCAN00_b0e01d02_Rx/PduRSrcPdu_85bab85c, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr07_oCAN00_b0e01d02_Rx/EcmPropFr07_oCAN00_b0e01d02_Rx_85bab85c_Rx] */
  { /*    33 */           33u,         14u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_ddf2fc4e_Rx_8eb8bcc7_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_ddf2fc4e_Rx/PduRSrcPdu_8eb8bcc7, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_ddf2fc4e_Rx/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_ddf2fc4e_Rx_8eb8bcc7_Rx] */
  { /*    34 */            5u,         41u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx]                      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx/PduRSrcPdu_a68661a0, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx/MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx] */
  { /*    35 */           16u,         52u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx/PduRSrcPdu_ad466705, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx/MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx] */
  { /*    36 */           39u,         20u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fc4492bd_Rx_ae89e63d_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fc4492bd_Rx/PduRSrcPdu_ae89e63d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fc4492bd_Rx/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fc4492bd_Rx_ae89e63d_Rx] */
  { /*    37 */           30u,         11u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_83398b4a_Rx_b2abe408_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_83398b4a_Rx/PduRSrcPdu_b2abe408, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_83398b4a_Rx/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_83398b4a_Rx_b2abe408_Rx] */
  { /*    38 */           26u,          7u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_5c5f5dbc_Rx_b39ae31f_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_5c5f5dbc_Rx/PduRSrcPdu_b39ae31f, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_5c5f5dbc_Rx/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_5c5f5dbc_Rx_b39ae31f_Rx] */
  { /*    39 */           23u,          4u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: IemEduPropFr01_oCAN00_5f0e9f9d_Rx_b89bceb5_Rx]                      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IemEduPropFr01_oCAN00_5f0e9f9d_Rx/PduRSrcPdu_b89bceb5, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IemEduPropFr01_oCAN00_5f0e9f9d_Rx/IemEduPropFr01_oCAN00_5f0e9f9d_Rx_b89bceb5_Rx] */
  { /*    40 */           22u,          3u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EcmPropFr24_oCAN00_1f3ee830_Rx_c670cbec_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr24_oCAN00_1f3ee830_Rx/PduRSrcPdu_c670cbec, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr24_oCAN00_1f3ee830_Rx/EcmPropFr24_oCAN00_1f3ee830_Rx_c670cbec_Rx] */
  { /*    41 */           14u,         50u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx]                  */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx/PduRSrcPdu_c9e77028, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx] */
  { /*    42 */           42u,         23u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_5f3e853b_Rx_cc32e7dd_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_5f3e853b_Rx/PduRSrcPdu_cc32e7dd, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_5f3e853b_Rx/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_5f3e853b_Rx_cc32e7dd_Rx] */
  { /*    43 */           34u,         15u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_a32a4c0f_Rx_ccd18f93_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_a32a4c0f_Rx/PduRSrcPdu_ccd18f93, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_a32a4c0f_Rx/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_a32a4c0f_Rx_ccd18f93_Rx] */
  { /*    44 */           54u,         35u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: VddmPropFr29_oCAN00_c8bf9f02_Rx_d18651cd_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr29_oCAN00_c8bf9f02_Rx/PduRSrcPdu_d18651cd, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr29_oCAN00_c8bf9f02_Rx/VddmPropFr29_oCAN00_c8bf9f02_Rx_d18651cd_Rx] */
  { /*    45 */            8u,         44u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx]                      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx/PduRSrcPdu_d429e390, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx/MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx] */
  { /*    46 */           40u,         21u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_829c22fc_Rx_d9f53daa_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_829c22fc_Rx/PduRSrcPdu_d9f53daa, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_829c22fc_Rx/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_829c22fc_Rx_d9f53daa_Rx] */
  { /*    47 */           28u,          9u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_7e88ebc8_Rx_e1df8ad7_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_7e88ebc8_Rx/PduRSrcPdu_e1df8ad7, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_7e88ebc8_Rx/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_7e88ebc8_Rx_e1df8ad7_Rx] */
  { /*    48 */           20u,          1u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: EcmPropFr00_oCAN00_c65985ac_Rx_e1fbfb28_Rx]                         */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr00_oCAN00_c65985ac_Rx/PduRSrcPdu_e1fbfb28, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr00_oCAN00_c65985ac_Rx/EcmPropFr00_oCAN00_c65985ac_Rx_e1fbfb28_Rx] */
  { /*    49 */           36u,         17u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_3eaf6542_Rx_e3267653_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_3eaf6542_Rx/PduRSrcPdu_e3267653, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_3eaf6542_Rx/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_3eaf6542_Rx_e3267653_Rx] */
    /* Index    RmGDestRomIdx  RmSrcRomIdx  RoutingType                                                 Comment                                                                                       Referable Keys */
  { /*    50 */           24u,          5u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_006b0c6c_Rx_e3ca4023_Rx] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_006b0c6c_Rx/PduRSrcPdu_e3ca4023, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_006b0c6c_Rx/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_006b0c6c_Rx_e3ca4023_Rx] */
  { /*    51 */           47u,         28u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ccc01609_Rx_f29797a8_Rx]     */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ccc01609_Rx/PduRSrcPdu_f29797a8, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ccc01609_Rx/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ccc01609_Rx_f29797a8_Rx] */
  { /*    52 */           17u,         53u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx]                    */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx/PduRSrcPdu_f51d1329, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx/MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx] */
  { /*    53 */           19u,          0u, PDUR_IF_UNBUFFERED_RX_API_FWD_ROUTINGTYPEOFRMDESTROM },  /* [PduRDestPdu: BecmPropFr01_oCAN00_28e5cf36_Rx_fae18295_Rx]                        */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BecmPropFr01_oCAN00_28e5cf36_Rx/PduRSrcPdu_fae18295, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BecmPropFr01_oCAN00_28e5cf36_Rx/BecmPropFr01_oCAN00_28e5cf36_Rx_fae18295_Rx] */
  { /*    54 */            6u,         42u, PDUR_IF_UNBUFFERED_TX_API_FWD_ROUTINGTYPEOFRMDESTROM }   /* [PduRDestPdu: MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx]                      */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx/PduRSrcPdu_ff21d41d, /ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx/MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmGDestRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmGDestRom
  \brief  PduR RoutiongPathManager global destPdu Table
  \details
  Element                  Description
  DestHnd                  handle to be used as parameter for the StartOfReception, CopyRxData, Transmit or RxIndication function call.
  Direction                Direction of this Pdu: Rx or Tx
  MmRomIdx                 the index of the 1:1 relation pointing to PduR_MmRom
  PduRDestPduProcessing    Is Processing Type of destination PDU.
  RmDestRomIdx             the index of the 0:1 relation pointing to PduR_RmDestRom
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmGDestRomType, PDUR_CONST) PduR_RmGDestRom[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    DestHnd                                                                        Direction                      MmRomIdx  PduRDestPduProcessing                             RmDestRomIdx        Comment                                                                                   Referable Keys */
  { /*     0 */    CanIfConf_CanIfTxPduCfg_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          20u },  /* [Globale PduRDestPdu: MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     1 */ CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          31u },  /* [Globale PduRDestPdu: MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx]  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     2 */ CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          14u },  /* [Globale PduRDestPdu: MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx]  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     3 */ CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          27u },  /* [Globale PduRDestPdu: MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx]  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     4 */ CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          10u },  /* [Globale PduRDestPdu: MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx]  */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     5 */         CanIfConf_CanIfTxPduCfg_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          34u },  /* [Globale PduRDestPdu: MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     6 */         CanIfConf_CanIfTxPduCfg_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          54u },  /* [Globale PduRDestPdu: MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     7 */         CanIfConf_CanIfTxPduCfg_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          25u },  /* [Globale PduRDestPdu: MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     8 */         CanIfConf_CanIfTxPduCfg_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          45u },  /* [Globale PduRDestPdu: MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx]          */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*     9 */          CanIfConf_CanIfTxPduCfg_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          12u },  /* [Globale PduRDestPdu: MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx]           */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    10 */     CanIfConf_CanIfTxPduCfg_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          26u },  /* [Globale PduRDestPdu: MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx]      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    11 */     CanIfConf_CanIfTxPduCfg_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           7u },  /* [Globale PduRDestPdu: MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx]      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    12 */     CanIfConf_CanIfTxPduCfg_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          29u },  /* [Globale PduRDestPdu: MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx]      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    13 */     CanIfConf_CanIfTxPduCfg_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           4u },  /* [Globale PduRDestPdu: MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx]      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    14 */     CanIfConf_CanIfTxPduCfg_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          41u },  /* [Globale PduRDestPdu: MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx]      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    15 */     CanIfConf_CanIfTxPduCfg_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           2u },  /* [Globale PduRDestPdu: MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx]      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    16 */       CanIfConf_CanIfTxPduCfg_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          35u },  /* [Globale PduRDestPdu: MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx]        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    17 */       CanIfConf_CanIfTxPduCfg_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          52u },  /* [Globale PduRDestPdu: MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx]        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    18 */           CanIfConf_CanIfTxPduCfg_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx, PDUR_TX_DIRECTIONOFRMGDESTROM,       0u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          18u },  /* [Globale PduRDestPdu: MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx]            */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx, /ActiveEcuC/PduR/CanIf] */
  { /*    19 */                               ComConf_ComIPdu_BecmPropFr01_oCAN00_e2f0fff8_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          53u },  /* [Globale PduRDestPdu: BecmPropFr01_oCAN00_e2f0fff8_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/BecmPropFr01_oCAN00_e2f0fff8_Rx, /ActiveEcuC/PduR/Com] */
  { /*    20 */                                ComConf_ComIPdu_EcmPropFr00_oCAN00_2afbaddb_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          48u },  /* [Globale PduRDestPdu: EcmPropFr00_oCAN00_2afbaddb_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EcmPropFr00_oCAN00_2afbaddb_Rx, /ActiveEcuC/PduR/Com] */
  { /*    21 */                                ComConf_ComIPdu_EcmPropFr07_oCAN00_203ea4c2_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          32u },  /* [Globale PduRDestPdu: EcmPropFr07_oCAN00_203ea4c2_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EcmPropFr07_oCAN00_203ea4c2_Rx, /ActiveEcuC/PduR/Com] */
  { /*    22 */                                ComConf_ComIPdu_EcmPropFr24_oCAN00_80478ba7_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          40u },  /* [Globale PduRDestPdu: EcmPropFr24_oCAN00_80478ba7_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/EcmPropFr24_oCAN00_80478ba7_Rx, /ActiveEcuC/PduR/Com] */
  { /*    23 */                             ComConf_ComIPdu_IemEduPropFr01_oCAN00_97fdab75_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          39u },  /* [Globale PduRDestPdu: IemEduPropFr01_oCAN00_97fdab75_Rx]                      */  /* [/ActiveEcuC/EcuC/EcucPduCollection/IemEduPropFr01_oCAN00_97fdab75_Rx, /ActiveEcuC/PduR/Com] */
  { /*    24 */        ComConf_ComIPdu_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          50u },  /* [Globale PduRDestPdu: MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx, /ActiveEcuC/PduR/Com] */
  { /*    25 */        ComConf_ComIPdu_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           3u },  /* [Globale PduRDestPdu: MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx, /ActiveEcuC/PduR/Com] */
  { /*    26 */        ComConf_ComIPdu_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          38u },  /* [Globale PduRDestPdu: MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx, /ActiveEcuC/PduR/Com] */
  { /*    27 */        ComConf_ComIPdu_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           8u },  /* [Globale PduRDestPdu: MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx, /ActiveEcuC/PduR/Com] */
  { /*    28 */            ComConf_ComIPdu_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          47u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx, /ActiveEcuC/PduR/Com] */
  { /*    29 */            ComConf_ComIPdu_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          16u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx, /ActiveEcuC/PduR/Com] */
  { /*    30 */            ComConf_ComIPdu_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          37u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx, /ActiveEcuC/PduR/Com] */
  { /*    31 */            ComConf_ComIPdu_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           0u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx, /ActiveEcuC/PduR/Com] */
  { /*    32 */            ComConf_ComIPdu_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           1u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx, /ActiveEcuC/PduR/Com] */
  { /*    33 */            ComConf_ComIPdu_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          33u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx, /ActiveEcuC/PduR/Com] */
  { /*    34 */            ComConf_ComIPdu_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          43u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx, /ActiveEcuC/PduR/Com] */
  { /*    35 */            ComConf_ComIPdu_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          15u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx, /ActiveEcuC/PduR/Com] */
  { /*    36 */            ComConf_ComIPdu_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          49u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx, /ActiveEcuC/PduR/Com] */
  { /*    37 */            ComConf_ComIPdu_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          11u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx, /ActiveEcuC/PduR/Com] */
  { /*    38 */            ComConf_ComIPdu_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          30u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx, /ActiveEcuC/PduR/Com] */
  { /*    39 */            ComConf_ComIPdu_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          36u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx, /ActiveEcuC/PduR/Com] */
  { /*    40 */            ComConf_ComIPdu_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          46u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx, /ActiveEcuC/PduR/Com] */
  { /*    41 */            ComConf_ComIPdu_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          23u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx, /ActiveEcuC/PduR/Com] */
  { /*    42 */            ComConf_ComIPdu_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          42u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx, /ActiveEcuC/PduR/Com] */
  { /*    43 */            ComConf_ComIPdu_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          19u },  /* [Globale PduRDestPdu: MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx, /ActiveEcuC/PduR/Com] */
  { /*    44 */            ComConf_ComIPdu_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          13u },  /* [Globale PduRDestPdu: MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx, /ActiveEcuC/PduR/Com] */
  { /*    45 */            ComConf_ComIPdu_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          21u },  /* [Globale PduRDestPdu: MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx, /ActiveEcuC/PduR/Com] */
  { /*    46 */            ComConf_ComIPdu_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           9u },  /* [Globale PduRDestPdu: MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx, /ActiveEcuC/PduR/Com] */
  { /*    47 */            ComConf_ComIPdu_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          51u },  /* [Globale PduRDestPdu: MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx]     */  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx, /ActiveEcuC/PduR/Com] */
  { /*    48 */                                ComConf_ComIPdu_TcmPropFr04_oCAN00_6f4049d8_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          17u },  /* [Globale PduRDestPdu: TcmPropFr04_oCAN00_6f4049d8_Rx]                         */  /* [/ActiveEcuC/EcuC/EcucPduCollection/TcmPropFr04_oCAN00_6f4049d8_Rx, /ActiveEcuC/PduR/Com] */
  { /*    49 */                               ComConf_ComIPdu_VddmPropFr05_oCAN00_53500d40_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          24u },  /* [Globale PduRDestPdu: VddmPropFr05_oCAN00_53500d40_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VddmPropFr05_oCAN00_53500d40_Rx, /ActiveEcuC/PduR/Com] */
    /* Index    DestHnd                                                                        Direction                      MmRomIdx  PduRDestPduProcessing                             RmDestRomIdx        Comment                                                                                   Referable Keys */
  { /*    50 */                               ComConf_ComIPdu_VddmPropFr08_oCAN00_c8551891_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          22u },  /* [Globale PduRDestPdu: VddmPropFr08_oCAN00_c8551891_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VddmPropFr08_oCAN00_c8551891_Rx, /ActiveEcuC/PduR/Com] */
  { /*    51 */                               ComConf_ComIPdu_VddmPropFr09_oCAN00_04ff180f_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          28u },  /* [Globale PduRDestPdu: VddmPropFr09_oCAN00_04ff180f_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VddmPropFr09_oCAN00_04ff180f_Rx, /ActiveEcuC/PduR/Com] */
  { /*    52 */                               ComConf_ComIPdu_VddmPropFr10_oCAN00_0ccb1767_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           5u },  /* [Globale PduRDestPdu: VddmPropFr10_oCAN00_0ccb1767_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VddmPropFr10_oCAN00_0ccb1767_Rx, /ActiveEcuC/PduR/Com] */
  { /*    53 */                               ComConf_ComIPdu_VddmPropFr12_oCAN00_4eee101a_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,           6u },  /* [Globale PduRDestPdu: VddmPropFr12_oCAN00_4eee101a_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VddmPropFr12_oCAN00_4eee101a_Rx, /ActiveEcuC/PduR/Com] */
  { /*    54 */                               ComConf_ComIPdu_VddmPropFr29_oCAN00_2a093089_Rx, PDUR_RX_DIRECTIONOFRMGDESTROM,       1u, PDUR_IMMEDIATE_PDURDESTPDUPROCESSINGOFRMGDESTROM,          44u }   /* [Globale PduRDestPdu: VddmPropFr29_oCAN00_2a093089_Rx]                        */  /* [/ActiveEcuC/EcuC/EcucPduCollection/VddmPropFr29_oCAN00_2a093089_Rx, /ActiveEcuC/PduR/Com] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmSrcRom
**********************************************************************************************************************/
/** 
  \var    PduR_RmSrcRom
  \brief  PduR RoutiongManager SrcPdu Table
  \details
  Element              Description
  MmRomIdx             the index of the 1:1 relation pointing to PduR_MmRom
  RmDestRomLength      the number of relations pointing to PduR_RmDestRom
  RmDestRomStartIdx    the start index of the 1:n relation pointing to PduR_RmDestRom
  SrcHnd               handle to be used as parameter for the TxConfirmation or TriggerTransmit function call.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmSrcRomType, PDUR_CONST) PduR_RmSrcRom[55] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    MmRomIdx  RmDestRomLength  RmDestRomStartIdx  SrcHnd                                                                       Comment                                       Referable Keys */
  { /*     0 */       0u,              1u,               53u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_fae18295] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/BecmPropFr01_oCAN00_28e5cf36_Rx/PduRSrcPdu_fae18295] */
  { /*     1 */       0u,              1u,               48u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_e1fbfb28] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr00_oCAN00_c65985ac_Rx/PduRSrcPdu_e1fbfb28] */
  { /*     2 */       0u,              1u,               32u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_85bab85c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr07_oCAN00_b0e01d02_Rx/PduRSrcPdu_85bab85c] */
  { /*     3 */       0u,              1u,               40u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_c670cbec] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/EcmPropFr24_oCAN00_1f3ee830_Rx/PduRSrcPdu_c670cbec] */
  { /*     4 */       0u,              1u,               39u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_b89bceb5] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/IemEduPropFr01_oCAN00_5f0e9f9d_Rx/PduRSrcPdu_b89bceb5] */
  { /*     5 */       0u,              1u,               50u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_e3ca4023] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_006b0c6c_Rx/PduRSrcPdu_e3ca4023] */
  { /*     6 */       0u,              1u,                3u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_01f05597] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2975b1aa_Rx/PduRSrcPdu_01f05597] */
  { /*     7 */       0u,              1u,               38u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_b39ae31f] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_5c5f5dbc_Rx/PduRSrcPdu_b39ae31f] */
  { /*     8 */       0u,              1u,                8u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_22b98a3a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_7541e07a_Rx/PduRSrcPdu_22b98a3a] */
  { /*     9 */       0u,              1u,               47u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_e1df8ad7] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_7e88ebc8_Rx/PduRSrcPdu_e1df8ad7] */
  { /*    10 */       0u,              1u,               16u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3baae64e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_fde13b0b_Rx/PduRSrcPdu_3baae64e] */
  { /*    11 */       0u,              1u,               37u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_b2abe408] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_83398b4a_Rx/PduRSrcPdu_b2abe408] */
  { /*    12 */       0u,              1u,                0u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_00ca1874] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_20439ccc_Rx/PduRSrcPdu_00ca1874] */
  { /*    13 */       0u,              1u,                1u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_0182d1a5] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5e9b2c8d_Rx/PduRSrcPdu_0182d1a5] */
  { /*    14 */       0u,              1u,               33u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_8eb8bcc7] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_ddf2fc4e_Rx/PduRSrcPdu_8eb8bcc7] */
  { /*    15 */       0u,              1u,               43u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ccd18f93] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_a32a4c0f_Rx/PduRSrcPdu_ccd18f93] */
  { /*    16 */       0u,              1u,               15u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_3b0ccb8b] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4077d503_Rx/PduRSrcPdu_3b0ccb8b] */
  { /*    17 */       0u,              1u,               49u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_e3267653] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_3eaf6542_Rx/PduRSrcPdu_e3267653] */
  { /*    18 */       0u,              1u,               11u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_2dc7503e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_01f5f23f_Rx/PduRSrcPdu_2dc7503e] */
  { /*    19 */       0u,              1u,               30u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_75e7ddd6] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7f2d427e_Rx/PduRSrcPdu_75e7ddd6] */
  { /*    20 */       0u,              1u,               36u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_ae89e63d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fc4492bd_Rx/PduRSrcPdu_ae89e63d] */
  { /*    21 */       0u,              1u,               46u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d9f53daa] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_829c22fc_Rx/PduRSrcPdu_d9f53daa] */
  { /*    22 */       0u,              1u,               23u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4e8ce9aa] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_21e6357a_Rx/PduRSrcPdu_4e8ce9aa] */
  { /*    23 */       0u,              1u,               42u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_cc32e7dd] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_5f3e853b_Rx/PduRSrcPdu_cc32e7dd] */
  { /*    24 */       0u,              1u,               19u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_497553e8] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_dc5755f8_Rx/PduRSrcPdu_497553e8] */
  { /*    25 */       0u,              1u,               13u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_32000ae6] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_a223d9ce_Rx/PduRSrcPdu_32000ae6] */
  { /*    26 */       0u,              1u,               21u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4b661c96] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_c1eff401_Rx/PduRSrcPdu_4b661c96] */
  { /*    27 */       0u,              1u,                9u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_2ae17888] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_af0c3bc6_Rx/PduRSrcPdu_2ae17888] */
  { /*    28 */       0u,              1u,               51u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_f29797a8] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ccc01609_Rx/PduRSrcPdu_f29797a8] */
  { /*    29 */       0u,              1u,               17u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_440872d3] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/TcmPropFr04_oCAN00_293cb77e_Rx/PduRSrcPdu_440872d3] */
  { /*    30 */       0u,              1u,               24u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_57d9311c] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr05_oCAN00_1161b1b8_Rx/PduRSrcPdu_57d9311c] */
  { /*    31 */       0u,              1u,               22u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_4c43d725] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr08_oCAN00_8af7b9d9_Rx/PduRSrcPdu_4c43d725] */
  { /*    32 */       0u,              1u,               28u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_6c7f8382] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr09_oCAN00_1184530d_Rx/PduRSrcPdu_6c7f8382] */
  { /*    33 */       0u,              1u,                5u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_14940491] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr10_oCAN00_0b6b9fd8_Rx/PduRSrcPdu_14940491] */
  { /*    34 */       0u,              1u,                6u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_1550c19a] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr12_oCAN00_e6fd4c31_Rx/PduRSrcPdu_1550c19a] */
  { /*    35 */       0u,              1u,               44u,                                              PDUR_NO_SRCHNDOFRMSRCROM },  /* [PduRSrcPdu: PduRSrcPdu_d18651cd] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/VddmPropFr29_oCAN00_c8bf9f02_Rx/PduRSrcPdu_d18651cd] */
  { /*    36 */       1u,              1u,               20u,    ComConf_ComIPdu_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx },  /* [PduRSrcPdu: PduRSrcPdu_49ab7256] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx/PduRSrcPdu_49ab7256] */
  { /*    37 */       1u,              1u,               31u, ComConf_ComIPdu_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx },  /* [PduRSrcPdu: PduRSrcPdu_7724956e] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx/PduRSrcPdu_7724956e] */
  { /*    38 */       1u,              1u,               14u, ComConf_ComIPdu_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx },  /* [PduRSrcPdu: PduRSrcPdu_3adb47be] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx/PduRSrcPdu_3adb47be] */
  { /*    39 */       1u,              1u,               27u, ComConf_ComIPdu_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx },  /* [PduRSrcPdu: PduRSrcPdu_6b1a4ec4] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx/PduRSrcPdu_6b1a4ec4] */
  { /*    40 */       1u,              1u,               10u, ComConf_ComIPdu_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx },  /* [PduRSrcPdu: PduRSrcPdu_2ae8f5e9] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx/PduRSrcPdu_2ae8f5e9] */
  { /*    41 */       1u,              1u,               34u,         ComConf_ComIPdu_MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx },  /* [PduRSrcPdu: PduRSrcPdu_a68661a0] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx/PduRSrcPdu_a68661a0] */
  { /*    42 */       1u,              1u,               54u,         ComConf_ComIPdu_MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx },  /* [PduRSrcPdu: PduRSrcPdu_ff21d41d] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx/PduRSrcPdu_ff21d41d] */
  { /*    43 */       1u,              1u,               25u,         ComConf_ComIPdu_MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx },  /* [PduRSrcPdu: PduRSrcPdu_5f10ea86] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx/PduRSrcPdu_5f10ea86] */
  { /*    44 */       1u,              1u,               45u,         ComConf_ComIPdu_MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx },  /* [PduRSrcPdu: PduRSrcPdu_d429e390] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx/PduRSrcPdu_d429e390] */
  { /*    45 */       1u,              1u,               12u,          ComConf_ComIPdu_MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx },  /* [PduRSrcPdu: PduRSrcPdu_31999496] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx/PduRSrcPdu_31999496] */
  { /*    46 */       1u,              1u,               26u,     ComConf_ComIPdu_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx },  /* [PduRSrcPdu: PduRSrcPdu_66a5da13] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx/PduRSrcPdu_66a5da13] */
  { /*    47 */       1u,              1u,                7u,     ComConf_ComIPdu_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx },  /* [PduRSrcPdu: PduRSrcPdu_1a5b62cb] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx/PduRSrcPdu_1a5b62cb] */
  { /*    48 */       1u,              1u,               29u,     ComConf_ComIPdu_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx },  /* [PduRSrcPdu: PduRSrcPdu_75afcc50] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx/PduRSrcPdu_75afcc50] */
  { /*    49 */       1u,              1u,                4u,     ComConf_ComIPdu_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx },  /* [PduRSrcPdu: PduRSrcPdu_12d568b6] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx/PduRSrcPdu_12d568b6] */
    /* Index    MmRomIdx  RmDestRomLength  RmDestRomStartIdx  SrcHnd                                                                       Comment                                       Referable Keys */
  { /*    50 */       1u,              1u,               41u,     ComConf_ComIPdu_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx },  /* [PduRSrcPdu: PduRSrcPdu_c9e77028] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx/PduRSrcPdu_c9e77028] */
  { /*    51 */       1u,              1u,                2u,     ComConf_ComIPdu_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx },  /* [PduRSrcPdu: PduRSrcPdu_01dee4b4] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx/PduRSrcPdu_01dee4b4] */
  { /*    52 */       1u,              1u,               35u,       ComConf_ComIPdu_MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx },  /* [PduRSrcPdu: PduRSrcPdu_ad466705] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx/PduRSrcPdu_ad466705] */
  { /*    53 */       1u,              1u,               52u,       ComConf_ComIPdu_MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx },  /* [PduRSrcPdu: PduRSrcPdu_f51d1329] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx/PduRSrcPdu_f51d1329] */
  { /*    54 */       1u,              1u,               18u,           ComConf_ComIPdu_MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx }   /* [PduRSrcPdu: PduRSrcPdu_46cea922] */  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx/PduRSrcPdu_46cea922] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_RmTransmitFctPtr
**********************************************************************************************************************/
/** 
  \var    PduR_RmTransmitFctPtr
  \brief  Internal routing manager Transmit functions.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_RmTransmitFctPtrType, PDUR_CONST) PduR_RmTransmitFctPtr[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RmTransmitFctPtr                    Referable Keys */
  /*     0 */ PduR_RmIf_RxIndication_MultiIf    /* [PduR_RmIf_RxIndication_MultiIf] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Tx2Lo
**********************************************************************************************************************/
/** 
  \var    PduR_Tx2Lo
  \brief  Contains all informations to route a Pdu from a upper layer to a lower layer module, or to cancel a transmission
  \details
  Element                Description
  RmTransmitFctPtrIdx    the index of the 1:1 relation pointing to PduR_RmTransmitFctPtr
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_Tx2LoType, PDUR_CONST) PduR_Tx2Lo[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RmTransmitFctPtrIdx        Referable Keys */
  { /*     0 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx/PduRSrcPdu_49ab7256] */
  { /*     1 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx/PduRSrcPdu_7724956e] */
  { /*     2 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx/PduRSrcPdu_3adb47be] */
  { /*     3 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx/PduRSrcPdu_6b1a4ec4] */
  { /*     4 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx/PduRSrcPdu_2ae8f5e9] */
  { /*     5 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx/PduRSrcPdu_a68661a0] */
  { /*     6 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx/PduRSrcPdu_ff21d41d] */
  { /*     7 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx/PduRSrcPdu_5f10ea86] */
  { /*     8 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx/PduRSrcPdu_d429e390] */
  { /*     9 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx/PduRSrcPdu_31999496] */
  { /*    10 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx/PduRSrcPdu_66a5da13] */
  { /*    11 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx/PduRSrcPdu_1a5b62cb] */
  { /*    12 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx/PduRSrcPdu_75afcc50] */
  { /*    13 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx/PduRSrcPdu_12d568b6] */
  { /*    14 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx/PduRSrcPdu_c9e77028] */
  { /*    15 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx/PduRSrcPdu_01dee4b4] */
  { /*    16 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx/PduRSrcPdu_ad466705] */
  { /*    17 */                  0u },  /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx/PduRSrcPdu_f51d1329] */
  { /*    18 */                  0u }   /* [/ActiveEcuC/PduR/PduRRoutingTables/PduRRoutingTable/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx/PduRSrcPdu_46cea922] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_TxIf2Up
**********************************************************************************************************************/
/** 
  \var    PduR_TxIf2Up
  \brief  This table contains all routing information to perform the Tx handling of an interface routing. Used in the &lt;LLIf&gt;_TriggerTransmit and &lt;LLIf&gt;_TxConfirmation
  \details
  Element               Description
  TxConfirmationUsed    True, if the any of the source PduRDestPdus use a TxConfirmation.
*/ 
#define PDUR_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(PduR_TxIf2UpType, PDUR_CONST) PduR_TxIf2Up[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxConfirmationUsed        Referable Keys */
  { /*     0 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx] */
  { /*     1 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx] */
  { /*     2 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx] */
  { /*     3 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx] */
  { /*     4 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx] */
  { /*     5 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx] */
  { /*     6 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx] */
  { /*     7 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx] */
  { /*     8 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx] */
  { /*     9 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx] */
  { /*    10 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx] */
  { /*    11 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx] */
  { /*    12 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx] */
  { /*    13 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx] */
  { /*    14 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx] */
  { /*    15 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx] */
  { /*    16 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx] */
  { /*    17 */               TRUE },  /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx] */
  { /*    18 */               TRUE }   /* [/ActiveEcuC/EcuC/EcucPduCollection/MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx] */
};
#define PDUR_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  PduR_Initialized
**********************************************************************************************************************/
/** 
  \var    PduR_Initialized
  \brief  Initialization state of PduR. TRUE, if PduR_Init() has been called, else FALSE
*/ 
#define PDUR_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(PduR_InitializedType, PDUR_VAR_ZERO_INIT) PduR_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define PDUR_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


#define PDUR_START_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */

#if(PDUR_USE_INIT_POINTER == STD_ON)
P2CONST(PduR_PBConfigType, PDUR_VAR_ZERO_INIT, PDUR_PBCFG) PduR_ConfigDataPtr = (const PduR_PBConfigType *) NULL_PTR;
#endif

#define PDUR_STOP_SEC_VAR_ZERO_INIT_UNSPECIFIED
#include "MemMap.h"    /* PRQA S 5087 */        /* MD_MSR_MemMap */
  
/**********************************************************************************************************************
 * LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
#define PDUR_START_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* Exclusive Area Wrapper functions */

/**********************************************************************************************************************
 * PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  enter the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Enter_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/**********************************************************************************************************************
 * PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0
 *********************************************************************************************************************/
/*!
 * \internal
 * -  exit the EA  
 * \endinternal
 *********************************************************************************************************************/
static FUNC(void, PDUR_CODE) PduR_SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0(void)
{
  SchM_Exit_PduR_PDUR_EXCLUSIVE_AREA_0();
}


/* Upper Layer Interface APIs */

/**********************************************************************************************************************
 * PduR_ComTransmit
 *********************************************************************************************************************/
/*!
 * \internal
 * - call upper layer Transmit function. 
 * \endinternal
 *********************************************************************************************************************/
FUNC(Std_ReturnType, PDUR_CODE) PduR_ComTransmit(PduIdType id, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
  Std_ReturnType retVal = E_NOT_OK;        /* PRQA S 2981 */ /* MD_MSR_RetVal */
  
#if (PDUR_TX2LO == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  retVal = PduR_UpTransmit(id, info); /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_TX, PDUR_E_PDU_ID_INVALID);
#endif

  PDUR_DUMMY_STATEMENT(id);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */

  return retVal;
}


/* Communication Interface APIs */

/**********************************************************************************************************************
 * PduR_CanIfRxIndication
 *********************************************************************************************************************/
/*!
 * \internal
 * -  call internal general IfRxIndication function.  
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfRxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info) /* COV_PDUR_WRAPPER_FUNC */
{
#if (PDUR_RXIF2DEST == STD_ON) /* COV_PDUR_RX_OR_TX_ONLY_CONFIG */
  PduR_LoIfRxIndication(RxPduId, info);  /* SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY */
#else
  PduR_Det_ReportError(PDUR_FCT_IFRXIND, PDUR_E_PDU_ID_INVALID);
#endif
  PDUR_DUMMY_STATEMENT(RxPduId);        /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
  PDUR_DUMMY_STATEMENT(info);   		/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* lint -e{438} */
}


/**********************************************************************************************************************
 * PduR_CanIfTxConfirmation
 *********************************************************************************************************************/
/*!
 * \internal
 * - call internal general communication interface TxConfirmation function.
 * \endinternal
 *********************************************************************************************************************/
FUNC(void, PDUR_CODE) PduR_CanIfTxConfirmation(PduIdType TxPduId) /* COV_PDUR_WRAPPER_FUNC */
{
  PduR_LoIfTxConfirmation(TxPduId);
}




/* Transport Protocol APIs */

/* CancelReceive global without UseTag API */

/* ChangeParameter global without UseTag  API */

/* Communication Interface / Transport Protocol APIs */

/* Communication Interface / Transport Protocol APIs */

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/


#define PDUR_STOP_SEC_CODE
/* PRQA S 5087 1 */ /* MD_MSR_MemMap */
#include "MemMap.h"

/* SBSW_JUSTIFICATION_BEGIN

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_AND_PTR
    \DESCRIPTION    The API is called with an Id and a pointer.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \N The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       The pointer is provided by the lower layer and is assumed to be valid. It is passed as is to the corresponding function. 

  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ID_ONLY
    \DESCRIPTION    The API is called with an Id.
                    The API call is forwarded using a function pointer which is read using ComStackLib macros.
                    
    \COUNTERMEASURE \R The function pointer is read using the passed Id (and ComStackLib macros). 
                       The Id is a SNV provided by the lower layer. 
                       It is checked at runtime if it is in the valid range.
                       
  \ID SBSW_PDUR_EXTERNAL_API_CALL_FORWARDING_ONLY
    \DESCRIPTION    The API call is forwarded to an internal function.
    \COUNTERMEASURE \N The parameter are checked in the called function.

 SBSW_JUSTIFICATION_END */
 
 /* COV_JUSTIFICATION_BEGIN
 
  \ID COV_PDUR_WRAPPER_FUNC
    \ACCEPT X
    \REASON Each neighbouring module call the same internal function. The call is covered by an other module. 
    
  \ID COV_PDUR_RX_OR_TX_ONLY_CONFIG
    \ACCEPT TX
    \REASON The API is mandatory if this Bsw module exists. In case of Rx or Tx only configs the API call is not forwarded to the internal function. 
 
 COV_JUSTIFICATION_END */
 

/**********************************************************************************************************************
 * END OF FILE: PduR_Lcfg.c
 *********************************************************************************************************************/

