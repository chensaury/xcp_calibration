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
 *              File: PduR_Cfg.h
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

#if !defined (PDUR_CFG_H)
# define PDUR_CFG_H

/**********************************************************************************************************************
 * MISRA JUSTIFICATION
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PduR_Types.h"

/**********************************************************************************************************************
 * GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef PDUR_USE_DUMMY_STATEMENT
#define PDUR_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef PDUR_DUMMY_STATEMENT
#define PDUR_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_DUMMY_STATEMENT_CONST
#define PDUR_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define PDUR_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef PDUR_ATOMIC_VARIABLE_ACCESS
#define PDUR_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef PDUR_PROCESSOR_TC397_STEPB
#define PDUR_PROCESSOR_TC397_STEPB
#endif
#ifndef PDUR_COMP_TASKING
#define PDUR_COMP_TASKING
#endif
#ifndef PDUR_GEN_GENERATOR_MSR
#define PDUR_GEN_GENERATOR_MSR
#endif
#ifndef PDUR_CPUTYPE_BITORDER_LSB2MSB
#define PDUR_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#define PDUR_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_LINKTIME
#define PDUR_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define PDUR_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef PDUR_CONFIGURATION_VARIANT
#define PDUR_CONFIGURATION_VARIANT PDUR_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef PDUR_POSTBUILD_VARIANT_SUPPORT
#define PDUR_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif



#define PDUR_DEV_ERROR_DETECT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSafeBswChecks] || /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */
#define PDUR_DEV_ERROR_REPORT STD_ON  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRDevErrorDetect] */

#define PDUR_METADATA_SUPPORT STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRMetaDataSupport] */
#define PDUR_VERSION_INFO_API STD_OFF  /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRVersionInfoApi] */

#define PDUR_ERROR_NOTIFICATION STD_OFF

#define PDUR_MAIN_FUNCTION STD_OFF

#define PDUR_MULTICORE STD_OFF /**< /ActiveEcuC/PduR/PduRGeneral[0:PduRSupportMulticore] */

#define PduR_PBConfigIdType uint32

 
 /*  DET Error define list  */ 
#define PDUR_FCT_CANIFRXIND 0x01u 
#define PDUR_FCT_CANIFTX 0x09u 
#define PDUR_FCT_CANIFTXCFM 0x02u 
#define PDUR_FCT_COMTX 0x89u 
 /*   PduR_CanIfIfRxIndication  PduR_CanIfTransmit  PduR_CanIfTxConfirmation  PduR_ComTransmit  */ 



/**
 * \defgroup PduRHandleIdsIfRxDest Handle IDs of handle space IfRxDest.
 * \brief Communication interface Rx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_BecmPropFr01_oCAN00_28e5cf36_Rx_fae18295_Rx 0u
#define PduRConf_PduRDestPdu_EcmPropFr00_oCAN00_c65985ac_Rx_e1fbfb28_Rx 1u
#define PduRConf_PduRDestPdu_EcmPropFr07_oCAN00_b0e01d02_Rx_85bab85c_Rx 2u
#define PduRConf_PduRDestPdu_EcmPropFr24_oCAN00_1f3ee830_Rx_c670cbec_Rx 3u
#define PduRConf_PduRDestPdu_IemEduPropFr01_oCAN00_5f0e9f9d_Rx_b89bceb5_Rx 4u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_006b0c6c_Rx_e3ca4023_Rx 5u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2975b1aa_Rx_01f05597_Rx 6u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_5c5f5dbc_Rx_b39ae31f_Rx 7u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_7541e07a_Rx_22b98a3a_Rx 8u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_7e88ebc8_Rx_e1df8ad7_Rx 9u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_fde13b0b_Rx_3baae64e_Rx 10u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_83398b4a_Rx_b2abe408_Rx 11u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_20439ccc_Rx_00ca1874_Rx 12u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5e9b2c8d_Rx_0182d1a5_Rx 13u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_ddf2fc4e_Rx_8eb8bcc7_Rx 14u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_a32a4c0f_Rx_ccd18f93_Rx 15u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4077d503_Rx_3b0ccb8b_Rx 16u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_3eaf6542_Rx_e3267653_Rx 17u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_01f5f23f_Rx_2dc7503e_Rx 18u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7f2d427e_Rx_75e7ddd6_Rx 19u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fc4492bd_Rx_ae89e63d_Rx 20u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_829c22fc_Rx_d9f53daa_Rx 21u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_21e6357a_Rx_4e8ce9aa_Rx 22u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_5f3e853b_Rx_cc32e7dd_Rx 23u
#define PduRConf_PduRDestPdu_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_dc5755f8_Rx_497553e8_Rx 24u
#define PduRConf_PduRDestPdu_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_a223d9ce_Rx_32000ae6_Rx 25u
#define PduRConf_PduRDestPdu_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_c1eff401_Rx_4b661c96_Rx 26u
#define PduRConf_PduRDestPdu_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_af0c3bc6_Rx_2ae17888_Rx 27u
#define PduRConf_PduRDestPdu_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ccc01609_Rx_f29797a8_Rx 28u
#define PduRConf_PduRDestPdu_TcmPropFr04_oCAN00_293cb77e_Rx_440872d3_Rx 29u
#define PduRConf_PduRDestPdu_VddmPropFr05_oCAN00_1161b1b8_Rx_57d9311c_Rx 30u
#define PduRConf_PduRDestPdu_VddmPropFr08_oCAN00_8af7b9d9_Rx_4c43d725_Rx 31u
#define PduRConf_PduRDestPdu_VddmPropFr09_oCAN00_1184530d_Rx_6c7f8382_Rx 32u
#define PduRConf_PduRDestPdu_VddmPropFr10_oCAN00_0b6b9fd8_Rx_14940491_Rx 33u
#define PduRConf_PduRDestPdu_VddmPropFr12_oCAN00_e6fd4c31_Rx_1550c19a_Rx 34u
#define PduRConf_PduRDestPdu_VddmPropFr29_oCAN00_c8bf9f02_Rx_d18651cd_Rx 35u
/**\} */

/**
 * \defgroup PduRHandleIdsIfRxSrc Handle IDs of handle space IfRxSrc.
 * \brief Communication interface Rx source PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2ae17888                       27u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2dc7503e                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3b0ccb8b                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3baae64e                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4b661c96                       26u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4c43d725                       31u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_4e8ce9aa                       22u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6c7f8382                       32u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_8eb8bcc7                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_00ca1874                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_01f05597                       6u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_22b98a3a                       8u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_57d9311c                       30u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_75e7ddd6                       19u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_85bab85c                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_0182d1a5                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1550c19a                       34u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_32000ae6                       25u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_440872d3                       29u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_497553e8                       24u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_14940491                       33u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ae89e63d                       20u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b2abe408                       11u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b39ae31f                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_b89bceb5                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c670cbec                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_cc32e7dd                       23u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ccd18f93                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d9f53daa                       21u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d18651cd                       35u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e1df8ad7                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e1fbfb28                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e3ca4023                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_e3267653                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f29797a8                       28u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_fae18295                       0u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTpTxSrc Handle IDs of handle space IfTpTxSrc.
 * \brief Communication interface and transport protocol Tx PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRSrcPdu_PduRSrcPdu_1a5b62cb                       11u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_2ae8f5e9                       4u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_3adb47be                       2u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_5f10ea86                       7u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_6b1a4ec4                       3u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_01dee4b4                       15u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_12d568b6                       13u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_46cea922                       18u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_49ab7256                       0u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_66a5da13                       10u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_75afcc50                       12u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_7724956e                       1u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_31999496                       9u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_a68661a0                       5u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ad466705                       16u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_c9e77028                       14u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_d429e390                       8u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_f51d1329                       17u
#define PduRConf_PduRSrcPdu_PduRSrcPdu_ff21d41d                       6u
/**\} */

/**
 * \defgroup PduRHandleIdsIfTxDest Handle IDs of handle space IfTxDest.
 * \brief Communication interface Tx destination PDUs
 * \{
 */

/* Handle IDs active in all predefined variants (the application has not to take the active variant into account) */
/*      Symbolic Name                                                 Value   Active in predefined variant(s) */
#define PduRConf_PduRDestPdu_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_b74b7962_Tx 0u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_53dbc0c9_Tx 1u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_3017ed06_Tx 2u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_5ef422c1_Tx 3u
#define PduRConf_PduRDestPdu_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_3d380f0e_Tx 4u
#define PduRConf_PduRDestPdu_MSG_MotorFL_oSchaeffler_MDA_CANFD_1da4e61d_Tx 5u
#define PduRConf_PduRDestPdu_MSG_MotorFR_oSchaeffler_MDA_CANFD_006ed244_Tx 6u
#define PduRConf_PduRDestPdu_MSG_MotorRL_oSchaeffler_MDA_CANFD_0168dba5_Tx 7u
#define PduRConf_PduRDestPdu_MSG_MotorRR_oSchaeffler_MDA_CANFD_1ca2effc_Tx 8u
#define PduRConf_PduRDestPdu_MSG_PT2000_oSchaeffler_MDA_CANFD_167dd35e_Tx 9u
#define PduRConf_PduRDestPdu_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_31886f96_Tx 10u
#define PduRConf_PduRDestPdu_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_b2e1bf55_Tx 11u
#define PduRConf_PduRDestPdu_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_cc390f14_Tx 12u
#define PduRConf_PduRDestPdu_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6f431892_Tx 13u
#define PduRConf_PduRDestPdu_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_119ba8d3_Tx 14u
#define PduRConf_PduRDestPdu_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_92f27810_Tx 15u
#define PduRConf_PduRDestPdu_MSG_Sensor_01_oSchaeffler_MDA_CANFD_c0447ce7_Tx 16u
#define PduRConf_PduRDestPdu_MSG_Sensor_02_oSchaeffler_MDA_CANFD_432dac24_Tx 17u
#define PduRConf_PduRDestPdu_MSG_Valve_oSchaeffler_MDA_CANFD_a81c1ccd_Tx 18u
/**\} */


/* User Config File Start */

/* User Config File End */


/**********************************************************************************************************************
 * GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* PDUR_CFG_H */
/**********************************************************************************************************************
 * END OF FILE: PduR_Cfg.h
 *********************************************************************************************************************/

