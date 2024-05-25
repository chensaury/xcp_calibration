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
 *              File: CanIf_Cfg.h
 *   Generation Time: 2024-01-08 16:27:29
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

#if !defined(CANIF_CFG_H)
#define CANIF_CFG_H

/* PRQA S 0850 EOF */ /* MD_MSR_19.8 */
/* PRQA S 3453 EOF */ /* MD_MSR_19.7 */
/* PRQA S 0857 EOF */ /* MD_CanIf_1.1_NumberOfMacroDefinitions */
/* PRQA S 0777 EOF */ /* MD_CanIf_5.1 */

/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
/** 
  \brief  Required external files.
*/
#include "Can.h"




/**********************************************************************************************************************
  \def  Version defines
**********************************************************************************************************************/

#define CANIF_CFG5_VERSION                                 0x0409u
#define CANIF_CFG5_RELEASE_VERSION                         0x00u
#define IF_ASRIFCAN_GENTOOL_CFG5_MAJOR_VERSION             0x04u
#define IF_ASRIFCAN_GENTOOL_CFG5_MINOR_VERSION             0x09u
#define IF_ASRIFCAN_GENTOOL_CFG5_PATCH_VERSION             0x00u

#define CANIF_CFG5_GENERATOR_COMPATIBILITY_VERSION         0x0212u

/**********************************************************************************************************************
  \def  Switches
**********************************************************************************************************************/

#define CANIF_MULTIPLE_TX_BASICCANS                        STD_OFF
#define CANIF_TRANSMIT_BUFFER                              STD_ON /* Signals if Tx-buffer is enabled at all in CanIf. The value is determined from parameter "CanIfPublicTxBuffering". */
#define CANIF_TRANSMIT_BUFFER_PRIO_BY_CANID                STD_ON
#define CANIF_TRANSMIT_BUFFER_FIFO                         STD_OFF
#define CANIF_BITQUEUE                                     STD_OFF
#define CANIF_STATIC_FD_TXQUEUE                            STD_OFF
#define CANIF_WAKEUP_SUPPORT                               STD_OFF
#define CANIF_WAKEUP_VALIDATION                            STD_OFF
#define CANIF_WAKEUP_VALID_ALL_RX_MSGS                     STD_OFF
#define CANIF_WAKEUP_VALID_ONLY_NM_RX_MSGS                 STD_OFF
#define CANIF_DEV_ERROR_DETECT                             STD_OFF
#define CANIF_DEV_ERROR_REPORT                             STD_OFF
#define CANIF_TRANSMIT_CANCELLATION                        STD_OFF
#define CANIF_CANCEL_SUPPORT_API                           STD_OFF
#define CANIF_VERSION_INFO_API                             STD_OFF
#define CANIF_DLC_CHECK                                    STD_ON
#define CANIF_SUPPORT_NMOSEK_INDICATION                    STD_OFF
#define CANIF_TRCV_HANDLING                                STD_OFF
#define CANIF_TRCV_MAPPING                                 STD_OFF
#define CANIF_PN_TRCV_HANDLING                             STD_OFF
#define CANIF_EXTENDEDID_SUPPORT                           STD_ON
#define CANIF_ONE_CONTROLLER_OPTIMIZATION                  STD_OFF
#define CANIF_SETDYNAMICTXID_API                           STD_OFF
#define CANIF_PN_WU_TX_PDU_FILTER                          STD_OFF
#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_OFF
#define CANIF_RX_INDICATION_TYPE_I_IS_USED                 STD_OFF
#define CANIF_RX_INDICATION_TYPE_IV_IS_USED                STD_OFF
#define CANIF_CHANGE_BAUDRATE_SUPPORT                      STD_OFF
#define CANIF_SET_BAUDRATE_API                             STD_OFF
#define CANIF_META_DATA_RX_SUPPORT                         STD_OFF
#define CANIF_META_DATA_TX_SUPPORT                         STD_OFF
#define CANIF_J1939_DYN_ADDR_SUPPORT                       CANIF_J1939_DYN_ADDR_DISABLED
#define CANIF_MULTIPLE_CANDRV_SUPPORT                      STD_OFF
#define CANIF_RX_SEARCH_CONSIDER_MSG_TYPE                  STD_OFF
#define CANIF_ECUC_SAFE_BSW_CHECKS                         STD_OFF
#define CANIF_EXTENDED_RAM_CHECK_SUPPORT                   STD_OFF
#define CANIF_DATA_CHECKSUM_RX_SUPPORT                     STD_OFF
#define CANIF_DATA_CHECKSUM_TX_SUPPORT                     STD_OFF
#define CANIF_SET_PDU_RECEPTION_MODE_SUPPORT               STD_OFF 

#define CANIF_SUPPRESS_EXTENDED_VERSION_CHECK

#ifndef CANIF_USE_DUMMY_STATEMENT
#define CANIF_USE_DUMMY_STATEMENT STD_ON /* /MICROSAR/EcuC/EcucGeneral/DummyStatement */
#endif
#ifndef CANIF_DUMMY_STATEMENT
#define CANIF_DUMMY_STATEMENT(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_DUMMY_STATEMENT_CONST
#define CANIF_DUMMY_STATEMENT_CONST(v)  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */  /* /MICROSAR/vSet/vSetGeneral/vSetDummyStatementKind */
#endif
#ifndef CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD
#define CANIF_ATOMIC_BIT_ACCESS_IN_BITFIELD STD_OFF /* /MICROSAR/EcuC/EcucGeneral/AtomicBitAccessInBitfield */
#endif
#ifndef CANIF_ATOMIC_VARIABLE_ACCESS
#define CANIF_ATOMIC_VARIABLE_ACCESS 32u /* /MICROSAR/EcuC/EcucGeneral/AtomicVariableAccess */
#endif
#ifndef CANIF_PROCESSOR_TC397_STEPB
#define CANIF_PROCESSOR_TC397_STEPB
#endif
#ifndef CANIF_COMP_TASKING
#define CANIF_COMP_TASKING
#endif
#ifndef CANIF_GEN_GENERATOR_MSR
#define CANIF_GEN_GENERATOR_MSR
#endif
#ifndef CANIF_CPUTYPE_BITORDER_LSB2MSB
#define CANIF_CPUTYPE_BITORDER_LSB2MSB /* /MICROSAR/vSet/vSetPlatform/vSetBitOrder */
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#define CANIF_CONFIGURATION_VARIANT_PRECOMPILE 1
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_LINKTIME
#define CANIF_CONFIGURATION_VARIANT_LINKTIME 2
#endif
#ifndef CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE
#define CANIF_CONFIGURATION_VARIANT_POSTBUILD_LOADABLE 3
#endif
#ifndef CANIF_CONFIGURATION_VARIANT
#define CANIF_CONFIGURATION_VARIANT CANIF_CONFIGURATION_VARIANT_PRECOMPILE
#endif
#ifndef CANIF_POSTBUILD_VARIANT_SUPPORT
#define CANIF_POSTBUILD_VARIANT_SUPPORT STD_OFF
#endif


#define CANIF_CPU_TYPE_SET_IN_ECUC_MODULE                  CPU_TYPE_32

/**********************************************************************************************************************
  \def  Search algorithm
**********************************************************************************************************************/
#define CANIF_SEARCH_ALGORITHM                             CANIF_LINEAR


/**********************************************************************************************************************
  \def  Configuration variant
**********************************************************************************************************************/
#define CANIF_CONFIG_VARIANT                               CANIF_CFGVAR_PRECOMPILETIME


/**********************************************************************************************************************
  Type definitions
**********************************************************************************************************************/

/**********************************************************************************************************************
  \def  Tx-buffer - queue size type
**********************************************************************************************************************/
typedef uint8 CanIf_TxBufferSizeType;


/**********************************************************************************************************************
  \file  Includes
**********************************************************************************************************************/
#include "CanIf_Types.h"

/**********************************************************************************************************************
  \def  Memory mapping keywords
**********************************************************************************************************************/
#define CANIF_XCFG                                         CANIF_CONST
#define CANIF_VAR_XCFG_NOINIT                              CANIF_VAR_NOINIT


/**********************************************************************************************************************
  \def  Invalid PDU handle
**********************************************************************************************************************/
#define CanIf_TxPduHnd_INVALID                             0xFFu
#define CanIf_RxPduHnd_INVALID                             0xFFu


/**********************************************************************************************************************
  \def  Tx-buffer - handling types
**********************************************************************************************************************/
#define CANIF_TXBUFFER_HANDLINGTYPE_PRIOBYCANID                                                             1u
#define CANIF_TXBUFFER_HANDLINGTYPE_FIFO                                                                    2u
#define CANIF_TXBUFFER_HANDLINGTYPE_NONE                                                                    3u



/**********************************************************************************************************************
  \def  CAN controller channels - symbolic handles
**********************************************************************************************************************/

#define CanIfConf_CanIfCtrlCfg_CT_CAN00_4f940509                                                    0u
#define CanIfConf_CanIfCtrlCfg_CT_Schaeffler_MDA_CANFD_ffad619f                                     1u
#define CanIfConf_CanIfCtrlCfg_CT_Schaeffler_MotorFL_CANFD_5f63093a                                 2u
#define CanIfConf_CanIfCtrlCfg_CT_Schaeffler_MotorFR_CANFD_6882eea9                                 3u
#define CanIfConf_CanIfCtrlCfg_CT_Schaeffler_MotorRL_CANFD_a79236eb                                 4u
#define CanIfConf_CanIfCtrlCfg_CT_Schaeffler_MotorRR_CANFD_9073d178                                 5u








/**********************************************************************************************************************
  \def  Tx PDU handles
**********************************************************************************************************************/

#define CanIfTxPduHnd_XCP_R_oCAN00_267e057e_Tx                                                      0u
#define CanIfTxPduHnd_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx                                  1u
#define CanIfTxPduHnd_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx                             2u
#define CanIfTxPduHnd_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx                             3u
#define CanIfTxPduHnd_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx                             4u
#define CanIfTxPduHnd_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx                             5u
#define CanIfTxPduHnd_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx                             6u
#define CanIfTxPduHnd_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx                             7u
#define CanIfTxPduHnd_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx                                   8u
#define CanIfTxPduHnd_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx                                 9u
#define CanIfTxPduHnd_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx                                 10u
#define CanIfTxPduHnd_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx                                 11u
#define CanIfTxPduHnd_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx                                 12u
#define CanIfTxPduHnd_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx                               13u
#define CanIfTxPduHnd_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx                               14u
#define CanIfTxPduHnd_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx                            15u
#define CanIfTxPduHnd_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx                         16u
#define CanIfTxPduHnd_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx                         17u
#define CanIfTxPduHnd_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx                         18u
#define CanIfTxPduHnd_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx                         19u


/**********************************************************************************************************************
  \def  Rx PDU handles (Rx indication function specific ones)
**********************************************************************************************************************/

/* These definitions can change at Link-time and Post-build configuration time. Use them wisely. */
/* Assigned to: NULL_PTR*/
/* Assigned to: PduR_CanIfRxIndication*/
#define CanIfRxPduHnd_TcmPropFr04_oCAN00_28f82aa0_Rx                                                0u
#define CanIfRxPduHnd_VddmPropFr12_oCAN00_f60c01d6_Rx                                               1u
#define CanIfRxPduHnd_BecmPropFr01_oCAN00_e0c55a4e_Rx                                               2u
#define CanIfRxPduHnd_VddmPropFr10_oCAN00_4c52103e_Rx                                               3u
#define CanIfRxPduHnd_EcmPropFr07_oCAN00_e92ad649_Rx                                                4u
#define CanIfRxPduHnd_VddmPropFr09_oCAN00_2f1b4ca4_Rx                                               5u
#define CanIfRxPduHnd_VddmPropFr05_oCAN00_043d2456_Rx                                               6u
#define CanIfRxPduHnd_IemEduPropFr01_oCAN00_25d7e216_Rx                                             7u
#define CanIfRxPduHnd_EcmPropFr24_oCAN00_df718eb8_Rx                                                8u
#define CanIfRxPduHnd_EcmPropFr00_oCAN00_7944854a_Rx                                                9u
#define CanIfRxPduHnd_VddmPropFr08_oCAN00_72344450_Rx                                               10u
#define CanIfRxPduHnd_VddmPropFr29_oCAN00_817078ff_Rx                                               11u
#define CanIfRxPduHnd_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx                            12u
#define CanIfRxPduHnd_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx                            13u
#define CanIfRxPduHnd_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx                            14u
#define CanIfRxPduHnd_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx                            15u
#define CanIfRxPduHnd_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx                            16u
#define CanIfRxPduHnd_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx                            17u
#define CanIfRxPduHnd_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx                            18u
#define CanIfRxPduHnd_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx                            19u
#define CanIfRxPduHnd_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx                            20u
#define CanIfRxPduHnd_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx                            21u
#define CanIfRxPduHnd_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx                            22u
#define CanIfRxPduHnd_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx                            23u
#define CanIfRxPduHnd_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx                            24u
#define CanIfRxPduHnd_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx                            25u
#define CanIfRxPduHnd_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx                            26u
#define CanIfRxPduHnd_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx                            27u
#define CanIfRxPduHnd_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx                        28u
#define CanIfRxPduHnd_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx                        29u
#define CanIfRxPduHnd_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx                        30u
#define CanIfRxPduHnd_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx                        31u
#define CanIfRxPduHnd_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx                            32u
#define CanIfRxPduHnd_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx                            33u
#define CanIfRxPduHnd_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx                            34u
#define CanIfRxPduHnd_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx                            35u
/* Assigned to: Xcp_CanIfRxIndication*/
#define CanIfRxPduHnd_XCP_S_oCAN00_d18922f7_Rx                                                      0u



/**********************************************************************************************************************
  \def  AUTOSAR Tx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfTxPduCfg_XCP_R_oCAN00_267e057e_Tx                                            0u
#define CanIfConf_CanIfTxPduCfg_MSG_PT2000_oSchaeffler_MDA_CANFD_cec24bf8_Tx                        1u
#define CanIfConf_CanIfTxPduCfg_MSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd68fb6b_Tx                   2u
#define CanIfConf_CanIfTxPduCfg_MSG_PTDriver_05_oSchaeffler_MDA_CANFD_dd214dbe_Tx                   3u
#define CanIfConf_CanIfTxPduCfg_MSG_PTDriver_04_oSchaeffler_MDA_CANFD_6bc92232_Tx                   4u
#define CanIfConf_CanIfTxPduCfg_MSG_PTDriver_03_oSchaeffler_MDA_CANFD_ddb22014_Tx                   5u
#define CanIfConf_CanIfTxPduCfg_MSG_PTDriver_02_oSchaeffler_MDA_CANFD_6b5a4f98_Tx                   6u
#define CanIfConf_CanIfTxPduCfg_MSG_PTDriver_01_oSchaeffler_MDA_CANFD_6b13f94d_Tx                   7u
#define CanIfConf_CanIfTxPduCfg_MSG_Valve_oSchaeffler_MDA_CANFD_8c0c0b2b_Tx                         8u
#define CanIfConf_CanIfTxPduCfg_MSG_MotorRR_oSchaeffler_MDA_CANFD_7ca905dc_Tx                       9u
#define CanIfConf_CanIfTxPduCfg_MSG_MotorRL_oSchaeffler_MDA_CANFD_7406f785_Tx                       10u
#define CanIfConf_CanIfTxPduCfg_MSG_MotorFR_oSchaeffler_MDA_CANFD_d6ac7cdf_Tx                       11u
#define CanIfConf_CanIfTxPduCfg_MSG_MotorFL_oSchaeffler_MDA_CANFD_de038e86_Tx                       12u
#define CanIfConf_CanIfTxPduCfg_MSG_Sensor_02_oSchaeffler_MDA_CANFD_691e2c16_Tx                     13u
#define CanIfConf_CanIfTxPduCfg_MSG_Sensor_01_oSchaeffler_MDA_CANFD_2f85334a_Tx                     14u
#define CanIfConf_CanIfTxPduCfg_MSG_MDA_Internal_oSchaeffler_MDA_CANFD_8168c451_Tx                  15u
#define CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_9e587cec_Tx               16u
#define CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_0d227ca2_Tx               17u
#define CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_7f0267f6_Tx               18u
#define CanIfConf_CanIfTxPduCfg_MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ec7867b8_Tx               19u


/**********************************************************************************************************************
  \def  AUTOSAR Rx PDU handles
**********************************************************************************************************************/

#define CanIfConf_CanIfRxPduCfg_XCP_S_oCAN00_d18922f7_Rx                                            0u
#define CanIfConf_CanIfRxPduCfg_TcmPropFr04_oCAN00_28f82aa0_Rx                                      1u
#define CanIfConf_CanIfRxPduCfg_VddmPropFr12_oCAN00_f60c01d6_Rx                                     2u
#define CanIfConf_CanIfRxPduCfg_BecmPropFr01_oCAN00_e0c55a4e_Rx                                     3u
#define CanIfConf_CanIfRxPduCfg_VddmPropFr10_oCAN00_4c52103e_Rx                                     4u
#define CanIfConf_CanIfRxPduCfg_EcmPropFr07_oCAN00_e92ad649_Rx                                      5u
#define CanIfConf_CanIfRxPduCfg_VddmPropFr09_oCAN00_2f1b4ca4_Rx                                     6u
#define CanIfConf_CanIfRxPduCfg_VddmPropFr05_oCAN00_043d2456_Rx                                     7u
#define CanIfConf_CanIfRxPduCfg_IemEduPropFr01_oCAN00_25d7e216_Rx                                   8u
#define CanIfConf_CanIfRxPduCfg_EcmPropFr24_oCAN00_df718eb8_Rx                                      9u
#define CanIfConf_CanIfRxPduCfg_EcmPropFr00_oCAN00_7944854a_Rx                                      10u
#define CanIfConf_CanIfRxPduCfg_VddmPropFr08_oCAN00_72344450_Rx                                     11u
#define CanIfConf_CanIfRxPduCfg_VddmPropFr29_oCAN00_817078ff_Rx                                     12u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_0cec5eb5_Rx                  13u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48713321_Rx                  14u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_c2d51592_Rx                  15u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_c14be809_Rx                  16u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4befceba_Rx                  17u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0f72a32e_Rx                  18u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_85d6859d_Rx                  19u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_d397c520_Rx                  20u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_5933e393_Rx                  21u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_d4aa3e16_Rx                  22u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_5e0e18a5_Rx                  23u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1a937531_Rx                  24u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_90375382_Rx                  25u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_93a9ae19_Rx                  26u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_190d88aa_Rx                  27u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_5d90e53e_Rx                  28u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_6ac63dec_Rx              29u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_b935cb14_Rx              30u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_01303143_Rx              31u
#define CanIfConf_CanIfRxPduCfg_MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_d2c3c7bb_Rx              32u
#define CanIfConf_CanIfRxPduCfg_MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_cba68950_Rx                  33u
#define CanIfConf_CanIfRxPduCfg_MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2dde8cc4_Rx                  34u
#define CanIfConf_CanIfRxPduCfg_MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_d871beff_Rx                  35u
#define CanIfConf_CanIfRxPduCfg_MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_3e09bb6b_Rx                  36u



/**********************************************************************************************************************
  \def  Tx buffer type
**********************************************************************************************************************/

#define CanIfTxBufferType                    BYTE_QUEUE

/**********************************************************************************************************************
  \def  For ASR4.0.3/ASR4.2.2 compatibility - indirection macros
**********************************************************************************************************************/
#define  CanIf_RxIndication(Hrh, CanId, CanDlc, CanSduPtr) CanIf_RxIndicationAsr403((Hrh), (CanId), (CanDlc), (CanSduPtr))








/**********************************************************************************************************************
  GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
#define CANIF_CFG_MAXRXDLC_PLUS_MAXMETADATA     0u



/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCDataSwitches  CanIf Data Switches  (PRE_COMPILE)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_BUSOFFNOTIFICATIONFCTPTR                                STD_ON
#define CANIF_CANCHANNELIDUPTOLOWMAP                                  STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLIDXOFCANCHANNELIDUPTOLOWMAP                 STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap.CanDrvFctTblIdx' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBLUSEDOFCANCHANNELIDUPTOLOWMAP                STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap.CanDrvFctTblUsed' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANNELINDEXOFCANCHANNELIDUPTOLOWMAP                    STD_OFF  /**< Deactivateable: 'CanIf_CanChannelIdUpToLowMap.ChannelIndex' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANDRVFCTTBL                                            STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANCELTXFCTOFCANDRVFCTTBL                               STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CancelTxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHANGEBAUDRATEFCTOFCANDRVFCTTBL                         STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.ChangeBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKBAUDRATEFCTOFCANDRVFCTTBL                          STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANDRVFCTTBL                            STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.CheckWakeupFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLECONTROLLERFCTOFCANDRVFCTTBL               STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableControllerFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKENABLEMAILBOXFCTOFCANDRVFCTTBL                  STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckEnableMailboxFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_RAMCHECKEXECUTEFCTOFCANDRVFCTTBL                        STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.RamCheckExecuteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETBAUDRATEFCTOFCANDRVFCTTBL                            STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetBaudrateFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_SETCONTROLLERMODEFCTOFCANDRVFCTTBL                      STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.SetControllerModeFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_WRITEFCTOFCANDRVFCTTBL                                  STD_OFF  /**< Deactivateable: 'CanIf_CanDrvFctTbl.WriteFct' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIG                       STD_ON
#define CANIF_INVALIDHNDOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG           STD_OFF  /**< Deactivateable: 'CanIf_CanIfCtrlId2MappedTxBuffersConfig.InvalidHnd' Reason: 'the value of CanIf_InvalidHndOfCanIfCtrlId2MappedTxBuffersConfig is always 'false' due to this, the array is deactivated.' */
#define CANIF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_ON
#define CANIF_CANTRCVFCTTBL                                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEFLAGFCTOFCANTRCVFCTTBL                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CHECKWAKEUPFCTOFCANTRCVFCTTBL                           STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.CheckWakeupFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CLEARTRCVWUFFLAGFCTOFCANTRCVFCTTBL                      STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.ClearTrcvWufFlagFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETBUSWUREASONFCTOFCANTRCVFCTTBL                        STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetBusWuReasonFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_GETOPMODEFCTOFCANTRCVFCTTBL                             STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.GetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETOPMODEFCTOFCANTRCVFCTTBL                             STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetOpModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_SETWAKEUPMODEFCTOFCANTRCVFCTTBL                         STD_OFF  /**< Deactivateable: 'CanIf_CanTrcvFctTbl.SetWakeupModeFct' Reason: 'Transceiver handling and transceiver mapping are deactivated.' */
#define CANIF_CTRLCONFIG                                              STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_FEATUREPNWUTXPDUFILTERENABLEDOFCTRLCONFIG               STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.FeaturePnWuTxPduFilterEnabled' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_J1939DYNADDROFFSETOFCTRLCONFIG                          STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrOffset' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_J1939DYNADDRSUPPORTOFCTRLCONFIG                         STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.J1939DynAddrSupport' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXDHRANDOMNUMBER1OFCTRLCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber1' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_RXDHRANDOMNUMBER2OFCTRLCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_CtrlConfig.RxDHRandomNumber2' Reason: 'Table: CanIf_CtrlConfig[] is not required.' */
#define CANIF_CTRLMODEINDICATIONFCTPTR                                STD_ON
#define CANIF_CTRLSTATES                                              STD_ON
#define CANIF_CTRLMODEOFCTRLSTATES                                    STD_ON
#define CANIF_PDUMODEOFCTRLSTATES                                     STD_ON
#define CANIF_FINALMAGICNUMBER                                        STD_OFF  /**< Deactivateable: 'CanIf_FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSION                           STD_ON
#define CANIF_GENERATORVERSION                                        STD_ON
#define CANIF_HXHOFFSET                                               STD_OFF  /**< Deactivateable: 'CanIf_HxhOffset' Reason: 'Multiple CAN driver support is deactivated.' */
#define CANIF_INITDATAHASHCODE                                        STD_OFF  /**< Deactivateable: 'CanIf_InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIG                                           STD_ON
#define CANIF_CTRLSTATESIDXOFMAILBOXCONFIG                            STD_ON
#define CANIF_MAILBOXTYPEOFMAILBOXCONFIG                              STD_ON
#define CANIF_PDUIDFIRSTOFMAILBOXCONFIG                               STD_ON
#define CANIF_PDUIDLASTOFMAILBOXCONFIG                                STD_ON
#define CANIF_TXBUFFERCFGIDXOFMAILBOXCONFIG                           STD_ON
#define CANIF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                          STD_ON
#define CANIF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                     STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIG                                   STD_ON
#define CANIF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG                 STD_ON
#define CANIF_PDURXMODE                                               STD_OFF  /**< Deactivateable: 'CanIf_PduRxMode' Reason: 'the array is deactivated because the size is 0 in all variants and the piece of data is in the configuration class: PRE_COMPILE' */
#define CANIF_RXDHADJUST                                              STD_OFF  /**< Deactivateable: 'CanIf_RxDHAdjust' Reason: 'Search algorithm "double hash" is deactivated.' */
#define CANIF_RXINDICATIONFCTLIST                                     STD_ON
#define CANIF_RXINDICATIONFCTOFRXINDICATIONFCTLIST                    STD_ON
#define CANIF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST                 STD_ON
#define CANIF_RXPDUCONFIG                                             STD_ON
#define CANIF_CANIFRXPDUIDOFRXPDUCONFIG                               STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.CanIfRxPduId' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_DLCOFRXPDUCONFIG                                        STD_ON
#define CANIF_ISDATACHECKSUMRXPDUOFRXPDUCONFIG                        STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.IsDataChecksumRxPdu' Reason: '"CanIfDataChecksumRxSupport" is deactivated.' */
#define CANIF_MSGTYPEOFRXPDUCONFIG                                    STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.MsgType' Reason: '"CanIfRxSearchConsiderMsgType" is deactivated.' */
#define CANIF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                     STD_ON
#define CANIF_RXMETADATALENGTHOFRXPDUCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_RxPduConfig.RxMetaDataLength' Reason: 'Rx meta data support is deactivated.' */
#define CANIF_RXPDUCANIDOFRXPDUCONFIG                                 STD_ON
#define CANIF_RXPDUMASKOFRXPDUCONFIG                                  STD_ON
#define CANIF_UPPERPDUIDOFRXPDUCONFIG                                 STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG                 STD_ON
#define CANIF_SIZEOFCTRLSTATES                                        STD_ON
#define CANIF_SIZEOFMAILBOXCONFIG                                     STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIG                             STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLIST                               STD_ON
#define CANIF_SIZEOFRXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASE                           STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS          STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLIST                             STD_ON
#define CANIF_SIZEOFTXPDUCONFIG                                       STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEX                                   STD_ON
#define CANIF_SIZEOFTXQUEUE                                           STD_ON
#define CANIF_TRANSCEIVERUPTOLOWMAP                                   STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_CANTRCVFCTTBLIDXOFTRANSCEIVERUPTOLOWMAP                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.CanTrcvFctTblIdx' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_CHANNELINDEXOFTRANSCEIVERUPTOLOWMAP                     STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToLowMap.ChannelIndex' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_TRANSCEIVERUPTOUPPERMAP                                 STD_OFF  /**< Deactivateable: 'CanIf_TransceiverUpToUpperMap' Reason: 'Transceiver handling and transceiver mapping are deactivated and one controller optimization is activated.' */
#define CANIF_TRCVTOCTRLMAP                                           STD_OFF  /**< Deactivateable: 'CanIf_TrcvToCtrlMap' Reason: 'Transceiver handling is deactivated.' */
#define CANIF_TXBUFFERFIFOCONFIG                                      STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_SIZEOFONEPAYLOADELOFTXBUFFERFIFOCONFIG                  STD_OFF  /**< Deactivateable: 'CanIf_TxBufferFifoConfig.SizeOfOnePayloadEl' Reason: 'Tx-buffer FIFO support is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBASE                                 STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBITQUEUECONFIG                       STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_BITPOS2TXPDUIDOFFSETOFTXBUFFERPRIOBYCANIDBITQUEUECONFIG STD_OFF  /**< Deactivateable: 'CanIf_TxBufferPrioByCanIdBitQueueConfig.BitPos2TxPduIdOffset' Reason: 'Tx-buffer PRIO_BY_CANID support as BIT_QUEUE is deactivated.' */
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIG                      STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS                STD_ON
#define CANIF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS STD_ON
#define CANIF_TXCONFIRMATIONFCTLIST                                   STD_ON
#define CANIF_TXPDUCONFIG                                             STD_ON
#define CANIF_CANIDOFTXPDUCONFIG                                      STD_ON
#define CANIF_CANIDTXMASKOFTXPDUCONFIG                                STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.CanIdTxMask' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_CTRLSTATESIDXOFTXPDUCONFIG                              STD_ON
#define CANIF_DLCOFTXPDUCONFIG                                        STD_ON
#define CANIF_ISDATACHECKSUMTXPDUOFTXPDUCONFIG                        STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.IsDataChecksumTxPdu' Reason: '"CanIfDataChecksumTxSupport" is deactivated.' */
#define CANIF_MAILBOXCONFIGIDXOFTXPDUCONFIG                           STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG                   STD_ON
#define CANIF_TXMETADATALENGTHOFTXPDUCONFIG                           STD_OFF  /**< Deactivateable: 'CanIf_TxPduConfig.TxMetaDataLength' Reason: 'Tx meta data support is deactivated.' */
#define CANIF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                          STD_ON
#define CANIF_TXPDUQUEUEINDEX                                         STD_ON
#define CANIF_TXQUEUEIDXOFTXPDUQUEUEINDEX                             STD_ON
#define CANIF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                            STD_ON
#define CANIF_TXPDUSTATIC2DYNAMICINDIRECTION                          STD_OFF  /**< Deactivateable: 'CanIf_TxPduStatic2DynamicIndirection' Reason: 'Dynamic Tx-CanId support is deactivated.' */
#define CANIF_TXQUEUE                                                 STD_ON
#define CANIF_TXQUEUEINDEX2DATASTARTSTOP                              STD_OFF  /**< Deactivateable: 'CanIf_TxQueueIndex2DataStartStop' Reason: 'Static FD Tx-buffer is deactivated.' */
#define CANIF_ULRXPDUID2INTERNALRXPDUID                               STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGIDXOFULRXPDUID2INTERNALRXPDUID               STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigIdx' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_RXPDUCONFIGUSEDOFULRXPDUID2INTERNALRXPDUID              STD_OFF  /**< Deactivateable: 'CanIf_UlRxPduId2InternalRxPduId.RxPduConfigUsed' Reason: 'Configuration variant is Pre-compile and the feature to be able to set the reception mode of a Rx-PDU at runtime is disabled!' */
#define CANIF_ULTXPDUID2INTERNALTXPDUID                               STD_OFF  /**< Deactivateable: 'CanIf_UlTxPduId2InternalTxPduId' Reason: 'Configuration variant is Pre-compile!' */
#define CANIF_WAKEUPCONFIG                                            STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig' Reason: 'Wake-up support is deactivated.' */
#define CANIF_CONTROLLEROFWAKEUPCONFIG                                STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.Controller' Reason: 'Wake-up support is deactivated.' */
#define CANIF_WAKEUPSOURCEOFWAKEUPCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.WakeUpSource' Reason: 'Wake-up support is deactivated.' */
#define CANIF_WAKEUPTARGETADDRESSOFWAKEUPCONFIG                       STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetAddress' Reason: 'Wake-up support is deactivated.' */
#define CANIF_WAKEUPTARGETMODULEOFWAKEUPCONFIG                        STD_OFF  /**< Deactivateable: 'CanIf_WakeUpConfig.WakeUpTargetModule' Reason: 'Wake-up support is deactivated.' */
#define CANIF_PCCONFIG                                                STD_ON
#define CANIF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG             STD_ON
#define CANIF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                      STD_ON
#define CANIF_CTRLSTATESOFPCCONFIG                                    STD_ON
#define CANIF_FINALMAGICNUMBEROFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.FinalMagicNumber' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_GENERATORCOMPATIBILITYVERSIONOFPCCONFIG                 STD_ON
#define CANIF_GENERATORVERSIONOFPCCONFIG                              STD_ON
#define CANIF_INITDATAHASHCODEOFPCCONFIG                              STD_OFF  /**< Deactivateable: 'CanIf_PCConfig.InitDataHashCode' Reason: 'the module configuration does not support flashing of data.' */
#define CANIF_MAILBOXCONFIGOFPCCONFIG                                 STD_ON
#define CANIF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                         STD_ON
#define CANIF_RXINDICATIONFCTLISTOFPCCONFIG                           STD_ON
#define CANIF_RXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_SIZEOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG       STD_ON
#define CANIF_SIZEOFCTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_SIZEOFMAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_SIZEOFMAPPEDTXBUFFERSCONFIGOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFRXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_SIZEOFRXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBASEOFPCCONFIG                 STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG      STD_ON
#define CANIF_SIZEOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG STD_ON
#define CANIF_SIZEOFTXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_SIZEOFTXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_SIZEOFTXPDUQUEUEINDEXOFPCCONFIG                         STD_ON
#define CANIF_SIZEOFTXQUEUEOFPCCONFIG                                 STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                       STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG            STD_ON
#define CANIF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG      STD_ON
#define CANIF_TXCONFIRMATIONFCTLISTOFPCCONFIG                         STD_ON
#define CANIF_TXPDUCONFIGOFPCCONFIG                                   STD_ON
#define CANIF_TXPDUQUEUEINDEXOFPCCONFIG                               STD_ON
#define CANIF_TXQUEUEOFPCCONFIG                                       STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCNoReferenceDefines  CanIf No Reference Defines (PRE_COMPILE)
  \brief  These defines are used to indicate unused indexes in data relations.
  \{
*/ 
#define CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG                        255u
#define CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX                          255u
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIsReducedToDefineDefines  CanIf Is Reduced To Define Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define is STD_ON else STD_OFF.
  \{
*/ 
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_OFF
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFMAILBOXCONFIG                      STD_OFF
#define CANIF_ISDEF_MAILBOXTYPEOFMAILBOXCONFIG                        STD_OFF
#define CANIF_ISDEF_PDUIDFIRSTOFMAILBOXCONFIG                         STD_OFF
#define CANIF_ISDEF_PDUIDLASTOFMAILBOXCONFIG                          STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGIDXOFMAILBOXCONFIG                     STD_OFF
#define CANIF_ISDEF_TXBUFFERCFGUSEDOFMAILBOXCONFIG                    STD_OFF
#define CANIF_ISDEF_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG               STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG           STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTOFRXINDICATIONFCTLIST              STD_OFF
#define CANIF_ISDEF_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST           STD_OFF
#define CANIF_ISDEF_DLCOFRXPDUCONFIG                                  STD_OFF
#define CANIF_ISDEF_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG               STD_OFF
#define CANIF_ISDEF_RXPDUCANIDOFRXPDUCONFIG                           STD_OFF
#define CANIF_ISDEF_RXPDUMASKOFRXPDUCONFIG                            STD_OFF
#define CANIF_ISDEF_UPPERPDUIDOFRXPDUCONFIG                           STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG STD_OFF
#define CANIF_ISDEF_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLIST                             STD_OFF
#define CANIF_ISDEF_CANIDOFTXPDUCONFIG                                STD_OFF
#define CANIF_ISDEF_CTRLSTATESIDXOFTXPDUCONFIG                        STD_OFF
#define CANIF_ISDEF_DLCOFTXPDUCONFIG                                  STD_OFF
#define CANIF_ISDEF_MAILBOXCONFIGIDXOFTXPDUCONFIG                     STD_OFF
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG             STD_OFF
#define CANIF_ISDEF_UPPERLAYERTXPDUIDOFTXPDUCONFIG                    STD_OFF
#define CANIF_ISDEF_TXQUEUEIDXOFTXPDUQUEUEINDEX                       STD_OFF
#define CANIF_ISDEF_TXQUEUEUSEDOFTXPDUQUEUEINDEX                      STD_OFF
#define CANIF_ISDEF_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG       STD_ON
#define CANIF_ISDEF_CTRLMODEINDICATIONFCTPTROFPCCONFIG                STD_ON
#define CANIF_ISDEF_CTRLSTATESOFPCCONFIG                              STD_ON
#define CANIF_ISDEF_MAILBOXCONFIGOFPCCONFIG                           STD_ON
#define CANIF_ISDEF_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_RXINDICATIONFCTLISTOFPCCONFIG                     STD_ON
#define CANIF_ISDEF_RXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                 STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG      STD_ON
#define CANIF_ISDEF_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG STD_ON
#define CANIF_ISDEF_TXCONFIRMATIONFCTLISTOFPCCONFIG                   STD_ON
#define CANIF_ISDEF_TXPDUCONFIGOFPCCONFIG                             STD_ON
#define CANIF_ISDEF_TXPDUQUEUEINDEXOFPCCONFIG                         STD_ON
#define CANIF_ISDEF_TXQUEUEOFPCCONFIG                                 STD_ON
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCEqualsAlwaysToDefines  CanIf Equals Always To Defines (PRE_COMPILE)
  \brief  If all values in a CONST array or an element in a CONST array of structs are equal, the define contains the always equals value.
  \{
*/ 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGENDIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG 
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGSTARTIDXOFCANIFCTRLID2MAPPEDTXBUFFERSCONFIG 
#define CANIF_EQ2_CTRLSTATESIDXOFMAILBOXCONFIG                        
#define CANIF_EQ2_MAILBOXTYPEOFMAILBOXCONFIG                          
#define CANIF_EQ2_PDUIDFIRSTOFMAILBOXCONFIG                           
#define CANIF_EQ2_PDUIDLASTOFMAILBOXCONFIG                            
#define CANIF_EQ2_TXBUFFERCFGIDXOFMAILBOXCONFIG                       
#define CANIF_EQ2_TXBUFFERCFGUSEDOFMAILBOXCONFIG                      
#define CANIF_EQ2_TXBUFFERHANDLINGTYPEOFMAILBOXCONFIG                 
#define CANIF_EQ2_MAILBOXCONFIGIDXOFMAPPEDTXBUFFERSCONFIG             
#define CANIF_EQ2_RXINDICATIONFCTOFRXINDICATIONFCTLIST                
#define CANIF_EQ2_RXINDICATIONLAYOUTOFRXINDICATIONFCTLIST             
#define CANIF_EQ2_DLCOFRXPDUCONFIG                                    
#define CANIF_EQ2_RXINDICATIONFCTLISTIDXOFRXPDUCONFIG                 
#define CANIF_EQ2_RXPDUCANIDOFRXPDUCONFIG                             
#define CANIF_EQ2_RXPDUMASKOFRXPDUCONFIG                              
#define CANIF_EQ2_UPPERPDUIDOFRXPDUCONFIG                             
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSENDIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSLENGTHOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSSTARTIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUECONFIG 
#define CANIF_EQ2_TXPDUCONFIGIDXOFTXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUS 
#define CANIF_EQ2_TXCONFIRMATIONFCTLIST                               
#define CANIF_EQ2_CANIDOFTXPDUCONFIG                                  
#define CANIF_EQ2_CTRLSTATESIDXOFTXPDUCONFIG                          
#define CANIF_EQ2_DLCOFTXPDUCONFIG                                    
#define CANIF_EQ2_MAILBOXCONFIGIDXOFTXPDUCONFIG                       
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTIDXOFTXPDUCONFIG               
#define CANIF_EQ2_UPPERLAYERTXPDUIDOFTXPDUCONFIG                      
#define CANIF_EQ2_TXQUEUEIDXOFTXPDUQUEUEINDEX                         
#define CANIF_EQ2_TXQUEUEUSEDOFTXPDUQUEUEINDEX                        
#define CANIF_EQ2_BUSOFFNOTIFICATIONFCTPTROFPCCONFIG                  CanIf_BusOffNotificationFctPtr
#define CANIF_EQ2_CANIFCTRLID2MAPPEDTXBUFFERSCONFIGOFPCCONFIG         CanIf_CanIfCtrlId2MappedTxBuffersConfig
#define CANIF_EQ2_CTRLMODEINDICATIONFCTPTROFPCCONFIG                  CanIf_CtrlModeIndicationFctPtr
#define CANIF_EQ2_CTRLSTATESOFPCCONFIG                                CanIf_CtrlStates.raw
#define CANIF_EQ2_MAILBOXCONFIGOFPCCONFIG                             CanIf_MailBoxConfig
#define CANIF_EQ2_MAPPEDTXBUFFERSCONFIGOFPCCONFIG                     CanIf_MappedTxBuffersConfig
#define CANIF_EQ2_RXINDICATIONFCTLISTOFPCCONFIG                       CanIf_RxIndicationFctList
#define CANIF_EQ2_RXPDUCONFIGOFPCCONFIG                               CanIf_RxPduConfig
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBASEOFPCCONFIG                   CanIf_TxBufferPrioByCanIdBase.raw
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUECONFIGOFPCCONFIG        CanIf_TxBufferPrioByCanIdByteQueueConfig
#define CANIF_EQ2_TXBUFFERPRIOBYCANIDBYTEQUEUEMAPPEDTXPDUSOFPCCONFIG  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus
#define CANIF_EQ2_TXCONFIRMATIONFCTLISTOFPCCONFIG                     CanIf_TxConfirmationFctList
#define CANIF_EQ2_TXPDUCONFIGOFPCCONFIG                               CanIf_TxPduConfig
#define CANIF_EQ2_TXPDUQUEUEINDEXOFPCCONFIG                           CanIf_TxPduQueueIndex
#define CANIF_EQ2_TXQUEUEOFPCCONFIG                                   CanIf_TxQueue.raw
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicInitializationPointers  CanIf Symbolic Initialization Pointers (PRE_COMPILE)
  \brief  Symbolic initialization pointers to be used in the call of a preinit or init function.
  \{
*/ 
#define CanIf_Config_Ptr                                              NULL_PTR  /**< symbolic identifier which shall be used to initialize 'CanIf' */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCInitializationSymbols  CanIf Initialization Symbols (PRE_COMPILE)
  \brief  Symbolic initialization pointers which may be used in the call of a preinit or init function. Please note, that the defined value can be a 'NULL_PTR' and the address operator is not usable.
  \{
*/ 
#define CanIf_Config                                                  NULL_PTR  /**< symbolic identifier which could be used to initialize 'CanIf */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGeneral  CanIf General (PRE_COMPILE)
  \brief  General constant defines not associated with a group of defines.
  \{
*/ 
#define CANIF_CHECK_INIT_POINTER                                      STD_OFF  /**< STD_ON if the init pointer shall not be used as NULL_PTR and a check shall validate this. */
#define CANIF_FINAL_MAGIC_NUMBER                                      0x3C1Eu  /**< the precompile constant to validate the size of the initialization structure at initialization time of CanIf */
#define CANIF_INDIVIDUAL_POSTBUILD                                    STD_OFF  /**< the precompile constant to check, that the module is individual postbuildable. The module 'CanIf' is not configured to be postbuild capable. */
#define CANIF_INIT_DATA                                               CANIF_CONST  /**< CompilerMemClassDefine for the initialization data. */
#define CANIF_INIT_DATA_HASH_CODE                                     -713533440L  /**< the precompile constant to validate the initialization structure at initialization time of CanIf with a hashcode. The seed value is '0x3C1Eu' */
#define CANIF_USE_ECUM_BSW_ERROR_HOOK                                 STD_OFF  /**< STD_ON if the EcuM_BswErrorHook shall be called in the ConfigPtr check. */
#define CANIF_USE_INIT_POINTER                                        STD_OFF  /**< STD_ON if the init pointer CanIf shall be used. */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfLTDataSwitches  CanIf Data Switches  (LINK)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_LTCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_LTConfig' Reason: 'the struct is deactivated because all elements are deactivated in all variants.' */
/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL CONSTANT MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPBDataSwitches  CanIf Data Switches  (POST_BUILD)
  \brief  These defines are used to deactivate data and their processing.
  \{
*/ 
#define CANIF_PBCONFIG                                                STD_OFF  /**< Deactivateable: 'CanIf_PBConfig' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_LTCONFIGIDXOFPBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.LTConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
#define CANIF_PCCONFIGIDXOFPBCONFIG                                   STD_OFF  /**< Deactivateable: 'CanIf_PBConfig.PCConfigIdx' Reason: 'the module configuration is VARIANT_PRE_COMPILE.' */
/** 
  \}
*/ 



/**********************************************************************************************************************
  GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCGetConstantDuplicatedRootDataMacros  CanIf Get Constant Duplicated Root Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated by constance root data elements.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtrOfPCConfig()                 CanIf_BusOffNotificationFctPtr  /**< the pointer to CanIf_BusOffNotificationFctPtr */
#define CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()        CanIf_CanIfCtrlId2MappedTxBuffersConfig  /**< the pointer to CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetCtrlModeIndicationFctPtrOfPCConfig()                 CanIf_CtrlModeIndicationFctPtr  /**< the pointer to CanIf_CtrlModeIndicationFctPtr */
#define CanIf_GetCtrlStatesOfPCConfig()                               CanIf_CtrlStates.raw  /**< the pointer to CanIf_CtrlStates */
#define CanIf_GetGeneratorCompatibilityVersionOfPCConfig()            0x0212u
#define CanIf_GetGeneratorVersionOfPCConfig()                         0x00040900uL
#define CanIf_GetMailBoxConfigOfPCConfig()                            CanIf_MailBoxConfig  /**< the pointer to CanIf_MailBoxConfig */
#define CanIf_GetMappedTxBuffersConfigOfPCConfig()                    CanIf_MappedTxBuffersConfig  /**< the pointer to CanIf_MappedTxBuffersConfig */
#define CanIf_GetRxIndicationFctListOfPCConfig()                      CanIf_RxIndicationFctList  /**< the pointer to CanIf_RxIndicationFctList */
#define CanIf_GetRxPduConfigOfPCConfig()                              CanIf_RxPduConfig  /**< the pointer to CanIf_RxPduConfig */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()  6uL  /**< the number of accomplishable value elements in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
#define CanIf_GetSizeOfCtrlStatesOfPCConfig()                         6uL  /**< the number of accomplishable value elements in CanIf_CtrlStates */
#define CanIf_GetSizeOfMailBoxConfigOfPCConfig()                      55uL  /**< the number of accomplishable value elements in CanIf_MailBoxConfig */
#define CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()              1uL  /**< the number of accomplishable value elements in CanIf_MappedTxBuffersConfig */
#define CanIf_GetSizeOfRxIndicationFctListOfPCConfig()                3uL  /**< the number of accomplishable value elements in CanIf_RxIndicationFctList */
#define CanIf_GetSizeOfRxPduConfigOfPCConfig()                        37uL  /**< the number of accomplishable value elements in CanIf_RxPduConfig */
#define CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()            1uL  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig() 1uL  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() 1uL  /**< the number of accomplishable value elements in CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
#define CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()              3uL  /**< the number of accomplishable value elements in CanIf_TxConfirmationFctList */
#define CanIf_GetSizeOfTxPduConfigOfPCConfig()                        20uL  /**< the number of accomplishable value elements in CanIf_TxPduConfig */
#define CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()                    20uL  /**< the number of accomplishable value elements in CanIf_TxPduQueueIndex */
#define CanIf_GetSizeOfTxQueueOfPCConfig()                            1uL  /**< the number of accomplishable value elements in CanIf_TxQueue */
#define CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()                  CanIf_TxBufferPrioByCanIdBase.raw  /**< the pointer to CanIf_TxBufferPrioByCanIdBase */
#define CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()       CanIf_TxBufferPrioByCanIdByteQueueConfig  /**< the pointer to CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus  /**< the pointer to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
#define CanIf_GetTxConfirmationFctListOfPCConfig()                    CanIf_TxConfirmationFctList  /**< the pointer to CanIf_TxConfirmationFctList */
#define CanIf_GetTxPduConfigOfPCConfig()                              CanIf_TxPduConfig  /**< the pointer to CanIf_TxPduConfig */
#define CanIf_GetTxPduQueueIndexOfPCConfig()                          CanIf_TxPduQueueIndex  /**< the pointer to CanIf_TxPduQueueIndex */
#define CanIf_GetTxQueueOfPCConfig()                                  CanIf_TxQueue.raw  /**< the pointer to CanIf_TxQueue */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDataMacros  CanIf Get Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read CONST and VAR data.
  \{
*/ 
#define CanIf_GetBusOffNotificationFctPtr()                           (CanIf_GetBusOffNotificationFctPtrOfPCConfig())
#define CanIf_GetMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig(Index) (CanIf_GetCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()[(Index)].MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig)
#define CanIf_GetCtrlModeIndicationFctPtr()                           (CanIf_GetCtrlModeIndicationFctPtrOfPCConfig())
#define CanIf_GetCtrlModeOfCtrlStates(Index)                          (CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates)
#define CanIf_GetPduModeOfCtrlStates(Index)                           (CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates)
#define CanIf_GetCtrlStatesIdxOfMailBoxConfig(Index)                  (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].CtrlStatesIdxOfMailBoxConfig)
#define CanIf_GetMailBoxTypeOfMailBoxConfig(Index)                    (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].MailBoxTypeOfMailBoxConfig)
#define CanIf_GetPduIdFirstOfMailBoxConfig(Index)                     (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdFirstOfMailBoxConfig)
#define CanIf_GetPduIdLastOfMailBoxConfig(Index)                      (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].PduIdLastOfMailBoxConfig)
#define CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index)                 (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferCfgIdxOfMailBoxConfig)
#define CanIf_GetTxBufferHandlingTypeOfMailBoxConfig(Index)           (CanIf_GetMailBoxConfigOfPCConfig()[(Index)].TxBufferHandlingTypeOfMailBoxConfig)
#define CanIf_GetMailBoxConfigIdxOfMappedTxBuffersConfig(Index)       (CanIf_GetMappedTxBuffersConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfMappedTxBuffersConfig)
#define CanIf_GetRxIndicationFctOfRxIndicationFctList(Index)          (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationFctOfRxIndicationFctList)
#define CanIf_GetRxIndicationLayoutOfRxIndicationFctList(Index)       (CanIf_GetRxIndicationFctListOfPCConfig()[(Index)].RxIndicationLayoutOfRxIndicationFctList)
#define CanIf_GetDlcOfRxPduConfig(Index)                              (CanIf_GetRxPduConfigOfPCConfig()[(Index)].DlcOfRxPduConfig)
#define CanIf_GetRxIndicationFctListIdxOfRxPduConfig(Index)           (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxIndicationFctListIdxOfRxPduConfig)
#define CanIf_GetRxPduCanIdOfRxPduConfig(Index)                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduCanIdOfRxPduConfig)
#define CanIf_GetRxPduMaskOfRxPduConfig(Index)                        (CanIf_GetRxPduConfigOfPCConfig()[(Index)].RxPduMaskOfRxPduConfig)
#define CanIf_GetUpperPduIdOfRxPduConfig(Index)                       (CanIf_GetRxPduConfigOfPCConfig()[(Index)].UpperPduIdOfRxPduConfig)
#define CanIf_GetTxBufferPrioByCanIdBase(Index)                       (CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)])
#define CanIf_GetTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueConfigOfPCConfig()[(Index)].TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig)
#define CanIf_GetTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus(Index) (CanIf_GetTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()[(Index)].TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus)
#define CanIf_GetTxConfirmationFctList(Index)                         (CanIf_GetTxConfirmationFctListOfPCConfig()[(Index)])
#define CanIf_GetCanIdOfTxPduConfig(Index)                            (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CanIdOfTxPduConfig)
#define CanIf_GetCtrlStatesIdxOfTxPduConfig(Index)                    (CanIf_GetTxPduConfigOfPCConfig()[(Index)].CtrlStatesIdxOfTxPduConfig)
#define CanIf_GetDlcOfTxPduConfig(Index)                              (CanIf_GetTxPduConfigOfPCConfig()[(Index)].DlcOfTxPduConfig)
#define CanIf_GetMailBoxConfigIdxOfTxPduConfig(Index)                 (CanIf_GetTxPduConfigOfPCConfig()[(Index)].MailBoxConfigIdxOfTxPduConfig)
#define CanIf_GetTxConfirmationFctListIdxOfTxPduConfig(Index)         (CanIf_GetTxPduConfigOfPCConfig()[(Index)].TxConfirmationFctListIdxOfTxPduConfig)
#define CanIf_GetUpperLayerTxPduIdOfTxPduConfig(Index)                (CanIf_GetTxPduConfigOfPCConfig()[(Index)].UpperLayerTxPduIdOfTxPduConfig)
#define CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index)                   (CanIf_GetTxPduQueueIndexOfPCConfig()[(Index)].TxQueueIdxOfTxPduQueueIndex)
#define CanIf_GetTxQueue(Index)                                       (CanIf_GetTxQueueOfPCConfig()[(Index)])
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCGetDeduplicatedDataMacros  CanIf Get Deduplicated Data Macros (PRE_COMPILE)
  \brief  These macros can be used to read deduplicated data elements.
  \{
*/ 
#define CanIf_GetGeneratorCompatibilityVersion()                      CanIf_GetGeneratorCompatibilityVersionOfPCConfig()
#define CanIf_GetGeneratorVersion()                                   CanIf_GetGeneratorVersionOfPCConfig()
#define CanIf_IsTxBufferCfgUsedOfMailBoxConfig(Index)                 (((boolean)(CanIf_GetTxBufferCfgIdxOfMailBoxConfig(Index) != CANIF_NO_TXBUFFERCFGIDXOFMAILBOXCONFIG)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig */
#define CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfig()            CanIf_GetSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfCtrlStates()                                   CanIf_GetSizeOfCtrlStatesOfPCConfig()
#define CanIf_GetSizeOfMailBoxConfig()                                CanIf_GetSizeOfMailBoxConfigOfPCConfig()
#define CanIf_GetSizeOfMappedTxBuffersConfig()                        CanIf_GetSizeOfMappedTxBuffersConfigOfPCConfig()
#define CanIf_GetSizeOfRxIndicationFctList()                          CanIf_GetSizeOfRxIndicationFctListOfPCConfig()
#define CanIf_GetSizeOfRxPduConfig()                                  CanIf_GetSizeOfRxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdBase()                      CanIf_GetSizeOfTxBufferPrioByCanIdBaseOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfig()           CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig()
#define CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()     CanIf_GetSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig()
#define CanIf_GetSizeOfTxConfirmationFctList()                        CanIf_GetSizeOfTxConfirmationFctListOfPCConfig()
#define CanIf_GetSizeOfTxPduConfig()                                  CanIf_GetSizeOfTxPduConfigOfPCConfig()
#define CanIf_GetSizeOfTxPduQueueIndex()                              CanIf_GetSizeOfTxPduQueueIndexOfPCConfig()
#define CanIf_GetSizeOfTxQueue()                                      CanIf_GetSizeOfTxQueueOfPCConfig()
#define CanIf_IsTxQueueUsedOfTxPduQueueIndex(Index)                   (((boolean)(CanIf_GetTxQueueIdxOfTxPduQueueIndex(Index) != CANIF_NO_TXQUEUEIDXOFTXPDUQUEUEINDEX)) != FALSE)  /**< TRUE, if the 0:1 relation has minimum 1 relation pointing to CanIf_TxQueue */
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSetDataMacros  CanIf Set Data Macros (PRE_COMPILE)
  \brief  These macros can be used to write data.
  \{
*/ 
#define CanIf_SetCtrlModeOfCtrlStates(Index, Value)                   CanIf_GetCtrlStatesOfPCConfig()[(Index)].CtrlModeOfCtrlStates = (Value)
#define CanIf_SetPduModeOfCtrlStates(Index, Value)                    CanIf_GetCtrlStatesOfPCConfig()[(Index)].PduModeOfCtrlStates = (Value)
#define CanIf_SetTxBufferPrioByCanIdBase(Index, Value)                CanIf_GetTxBufferPrioByCanIdBaseOfPCConfig()[(Index)] = (Value)
#define CanIf_SetTxQueue(Index, Value)                                CanIf_GetTxQueueOfPCConfig()[(Index)] = (Value)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCHasMacros  CanIf Has Macros (PRE_COMPILE)
  \brief  These macros can be used to detect at runtime a deactivated piece of information. TRUE in the CONFIGURATION_VARIANT PRE-COMPILE, TRUE or FALSE in the CONFIGURATION_VARIANT POST-BUILD.
  \{
*/ 
#define CanIf_HasBusOffNotificationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfig()                  (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig() (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig() (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtr()                           (TRUE != FALSE)
#define CanIf_HasCtrlStates()                                         (TRUE != FALSE)
#define CanIf_HasCtrlModeOfCtrlStates()                               (TRUE != FALSE)
#define CanIf_HasPduModeOfCtrlStates()                                (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersion()                      (TRUE != FALSE)
#define CanIf_HasGeneratorVersion()                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfig()                                      (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfMailBoxConfig()                       (TRUE != FALSE)
#define CanIf_HasMailBoxTypeOfMailBoxConfig()                         (TRUE != FALSE)
#define CanIf_HasPduIdFirstOfMailBoxConfig()                          (TRUE != FALSE)
#define CanIf_HasPduIdLastOfMailBoxConfig()                           (TRUE != FALSE)
#define CanIf_HasTxBufferCfgIdxOfMailBoxConfig()                      (TRUE != FALSE)
#define CanIf_HasTxBufferCfgUsedOfMailBoxConfig()                     (TRUE != FALSE)
#define CanIf_HasTxBufferHandlingTypeOfMailBoxConfig()                (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfig()                              (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfMappedTxBuffersConfig()            (TRUE != FALSE)
#define CanIf_HasRxIndicationFctList()                                (TRUE != FALSE)
#define CanIf_HasRxIndicationFctOfRxIndicationFctList()               (TRUE != FALSE)
#define CanIf_HasRxIndicationLayoutOfRxIndicationFctList()            (TRUE != FALSE)
#define CanIf_HasRxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasDlcOfRxPduConfig()                                   (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListIdxOfRxPduConfig()                (TRUE != FALSE)
#define CanIf_HasRxPduCanIdOfRxPduConfig()                            (TRUE != FALSE)
#define CanIf_HasRxPduMaskOfRxPduConfig()                             (TRUE != FALSE)
#define CanIf_HasUpperPduIdOfRxPduConfig()                            (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfig()            (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStates()                                   (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfig()                                (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctList()                          (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBase()                      (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfig()           (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus()     (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctList()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfig()                                  (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndex()                              (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueue()                                      (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBase()                            (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfig()                 (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig() (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdus()           (TRUE != FALSE)
#define CanIf_HasTxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus() (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctList()                              (TRUE != FALSE)
#define CanIf_HasTxPduConfig()                                        (TRUE != FALSE)
#define CanIf_HasCanIdOfTxPduConfig()                                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesIdxOfTxPduConfig()                         (TRUE != FALSE)
#define CanIf_HasDlcOfTxPduConfig()                                   (TRUE != FALSE)
#define CanIf_HasMailBoxConfigIdxOfTxPduConfig()                      (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListIdxOfTxPduConfig()              (TRUE != FALSE)
#define CanIf_HasUpperLayerTxPduIdOfTxPduConfig()                     (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndex()                                    (TRUE != FALSE)
#define CanIf_HasTxQueueIdxOfTxPduQueueIndex()                        (TRUE != FALSE)
#define CanIf_HasTxQueueUsedOfTxPduQueueIndex()                       (TRUE != FALSE)
#define CanIf_HasTxQueue()                                            (TRUE != FALSE)
#define CanIf_HasPCConfig()                                           (TRUE != FALSE)
#define CanIf_HasBusOffNotificationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()        (TRUE != FALSE)
#define CanIf_HasCtrlModeIndicationFctPtrOfPCConfig()                 (TRUE != FALSE)
#define CanIf_HasCtrlStatesOfPCConfig()                               (TRUE != FALSE)
#define CanIf_HasGeneratorCompatibilityVersionOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasGeneratorVersionOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasMailBoxConfigOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasMappedTxBuffersConfigOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasRxIndicationFctListOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasRxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasSizeOfCanIfCtrlId2MappedTxBuffersConfigOfPCConfig()  (TRUE != FALSE)
#define CanIf_HasSizeOfCtrlStatesOfPCConfig()                         (TRUE != FALSE)
#define CanIf_HasSizeOfMailBoxConfigOfPCConfig()                      (TRUE != FALSE)
#define CanIf_HasSizeOfMappedTxBuffersConfigOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfRxIndicationFctListOfPCConfig()                (TRUE != FALSE)
#define CanIf_HasSizeOfRxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdBaseOfPCConfig()            (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueConfigOfPCConfig() (TRUE != FALSE)
#define CanIf_HasSizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() (TRUE != FALSE)
#define CanIf_HasSizeOfTxConfirmationFctListOfPCConfig()              (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduConfigOfPCConfig()                        (TRUE != FALSE)
#define CanIf_HasSizeOfTxPduQueueIndexOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasSizeOfTxQueueOfPCConfig()                            (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdBaseOfPCConfig()                  (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueConfigOfPCConfig()       (TRUE != FALSE)
#define CanIf_HasTxBufferPrioByCanIdByteQueueMappedTxPdusOfPCConfig() (TRUE != FALSE)
#define CanIf_HasTxConfirmationFctListOfPCConfig()                    (TRUE != FALSE)
#define CanIf_HasTxPduConfigOfPCConfig()                              (TRUE != FALSE)
#define CanIf_HasTxPduQueueIndexOfPCConfig()                          (TRUE != FALSE)
#define CanIf_HasTxQueueOfPCConfig()                                  (TRUE != FALSE)
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCIncrementDataMacros  CanIf Increment Data Macros (PRE_COMPILE)
  \brief  These macros can be used to increment VAR data with numerical nature.
  \{
*/ 
#define CanIf_IncCtrlModeOfCtrlStates(Index)                          CanIf_GetCtrlModeOfCtrlStates(Index)++
#define CanIf_IncPduModeOfCtrlStates(Index)                           CanIf_GetPduModeOfCtrlStates(Index)++
#define CanIf_IncTxBufferPrioByCanIdBase(Index)                       CanIf_GetTxBufferPrioByCanIdBase(Index)++
#define CanIf_IncTxQueue(Index)                                       CanIf_GetTxQueue(Index)++
/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCDecrementDataMacros  CanIf Decrement Data Macros (PRE_COMPILE)
  \brief  These macros can be used to decrement VAR data with numerical nature.
  \{
*/ 
#define CanIf_DecCtrlModeOfCtrlStates(Index)                          CanIf_GetCtrlModeOfCtrlStates(Index)--
#define CanIf_DecPduModeOfCtrlStates(Index)                           CanIf_GetPduModeOfCtrlStates(Index)--
#define CanIf_DecTxBufferPrioByCanIdBase(Index)                       CanIf_GetTxBufferPrioByCanIdBase(Index)--
#define CanIf_DecTxQueue(Index)                                       CanIf_GetTxQueue(Index)--
/** 
  \}
*/ 

  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/

/** 
  \defgroup  DataAccessMacros  Data Access Macros
  \brief  generated data access macros to abstract the generated data from the code to read and write CONST or VAR data.
  \{
*/ 
  /* PRQA S 3453 MACROS_3453 */  /* MD_CSL_3453 */
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION MACROS
**********************************************************************************************************************/
  /* PRQA L:MACROS_3453 */
/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL ACCESS FUNCTION MACROS
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCIterableTypes  CanIf Iterable Types (PRE_COMPILE)
  \brief  These type definitions are used to iterate over an array with least processor cycles for variable access as possible.
  \{
*/ 
/**   \brief  type used to iterate CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef uint8_least CanIf_CanIfCtrlId2MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_CtrlStates */
typedef uint8_least CanIf_CtrlStatesIterType;

/**   \brief  type used to iterate CanIf_MailBoxConfig */
typedef uint8_least CanIf_MailBoxConfigIterType;

/**   \brief  type used to iterate CanIf_MappedTxBuffersConfig */
typedef uint8_least CanIf_MappedTxBuffersConfigIterType;

/**   \brief  type used to iterate CanIf_RxIndicationFctList */
typedef uint8_least CanIf_RxIndicationFctListIterType;

/**   \brief  type used to iterate CanIf_RxPduConfig */
typedef uint8_least CanIf_RxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdBase */
typedef uint8_least CanIf_TxBufferPrioByCanIdBaseIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef uint8_least CanIf_TxBufferPrioByCanIdByteQueueConfigIterType;

/**   \brief  type used to iterate CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8_least CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusIterType;

/**   \brief  type used to iterate CanIf_TxConfirmationFctList */
typedef uint8_least CanIf_TxConfirmationFctListIterType;

/**   \brief  type used to iterate CanIf_TxPduConfig */
typedef uint8_least CanIf_TxPduConfigIterType;

/**   \brief  type used to iterate CanIf_TxPduQueueIndex */
typedef uint8_least CanIf_TxPduQueueIndexIterType;

/**   \brief  type used to iterate CanIf_TxQueue */
typedef uint8_least CanIf_TxQueueIterType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCValueTypes  CanIf Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value based data representations.
  \{
*/ 
/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_GeneratorCompatibilityVersion */
typedef uint16 CanIf_GeneratorCompatibilityVersionType;

/**   \brief  value based type definition for CanIf_GeneratorVersion */
typedef uint32 CanIf_GeneratorVersionType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfMailBoxConfig */
typedef uint8 CanIf_CtrlStatesIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdFirstOfMailBoxConfig */
typedef uint8 CanIf_PduIdFirstOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_PduIdLastOfMailBoxConfig */
typedef uint8 CanIf_PduIdLastOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgIdxOfMailBoxConfig */
typedef uint8 CanIf_TxBufferCfgIdxOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferCfgUsedOfMailBoxConfig */
typedef boolean CanIf_TxBufferCfgUsedOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_TxBufferHandlingTypeOfMailBoxConfig */
typedef uint8 CanIf_TxBufferHandlingTypeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfMappedTxBuffersConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_DlcOfRxPduConfig */
typedef uint8 CanIf_DlcOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxIndicationFctListIdxOfRxPduConfig */
typedef uint8 CanIf_RxIndicationFctListIdxOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduCanIdOfRxPduConfig */
typedef uint32 CanIf_RxPduCanIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_RxPduMaskOfRxPduConfig */
typedef uint32 CanIf_RxPduMaskOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperPduIdOfRxPduConfig */
typedef PduIdType CanIf_UpperPduIdOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfCanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfCtrlStates */
typedef uint8 CanIf_SizeOfCtrlStatesType;

/**   \brief  value based type definition for CanIf_SizeOfMailBoxConfig */
typedef uint8 CanIf_SizeOfMailBoxConfigType;

/**   \brief  value based type definition for CanIf_SizeOfMappedTxBuffersConfig */
typedef uint8 CanIf_SizeOfMappedTxBuffersConfigType;

/**   \brief  value based type definition for CanIf_SizeOfRxIndicationFctList */
typedef uint8 CanIf_SizeOfRxIndicationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfRxPduConfig */
typedef uint8 CanIf_SizeOfRxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdBase */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdBaseType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8 CanIf_SizeOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  value based type definition for CanIf_SizeOfTxConfirmationFctList */
typedef uint8 CanIf_SizeOfTxConfirmationFctListType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduConfig */
typedef uint8 CanIf_SizeOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_SizeOfTxPduQueueIndex */
typedef uint8 CanIf_SizeOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_SizeOfTxQueue */
typedef uint8 CanIf_SizeOfTxQueueType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig */
typedef uint8 CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  value based type definition for CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef uint8 CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  value based type definition for CanIf_CanIdOfTxPduConfig */
typedef uint32 CanIf_CanIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_CtrlStatesIdxOfTxPduConfig */
typedef uint8 CanIf_CtrlStatesIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_DlcOfTxPduConfig */
typedef uint8 CanIf_DlcOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_MailBoxConfigIdxOfTxPduConfig */
typedef uint8 CanIf_MailBoxConfigIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxConfirmationFctListIdxOfTxPduConfig */
typedef uint8 CanIf_TxConfirmationFctListIdxOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_UpperLayerTxPduIdOfTxPduConfig */
typedef PduIdType CanIf_UpperLayerTxPduIdOfTxPduConfigType;

/**   \brief  value based type definition for CanIf_TxQueueIdxOfTxPduQueueIndex */
typedef uint8 CanIf_TxQueueIdxOfTxPduQueueIndexType;

/**   \brief  value based type definition for CanIf_TxQueueUsedOfTxPduQueueIndex */
typedef boolean CanIf_TxQueueUsedOfTxPduQueueIndexType;

/** 
  \}
*/ 

/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/** 
  \defgroup  CanIfPCStructTypes  CanIf Struct Types (PRE_COMPILE)
  \brief  These type definitions are used for structured data representations.
  \{
*/ 
/**   \brief  type used in CanIf_CanIfCtrlId2MappedTxBuffersConfig */
typedef struct sCanIf_CanIfCtrlId2MappedTxBuffersConfigType
{
  CanIf_MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigEndIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the end index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
  CanIf_MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfigType MappedTxBuffersConfigStartIdxOfCanIfCtrlId2MappedTxBuffersConfig;  /**< the start index of the 1:n relation pointing to CanIf_MappedTxBuffersConfig */
} CanIf_CanIfCtrlId2MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_CtrlStates */
typedef struct sCanIf_CtrlStatesType
{
  CanIf_ControllerModeType CtrlModeOfCtrlStates;  /**< Controller mode. */
  CanIf_PduGetModeType PduModeOfCtrlStates;  /**< PDU mode state. */
} CanIf_CtrlStatesType;

/**   \brief  type used in CanIf_MailBoxConfig */
typedef struct sCanIf_MailBoxConfigType
{
  CanIf_CtrlStatesIdxOfMailBoxConfigType CtrlStatesIdxOfMailBoxConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_PduIdFirstOfMailBoxConfigType PduIdFirstOfMailBoxConfig;  /**< "First" PDU mapped to mailbox. */
  CanIf_PduIdLastOfMailBoxConfigType PduIdLastOfMailBoxConfig;  /**< "Last" PDU mapped to mailbox. */
  CanIf_TxBufferCfgIdxOfMailBoxConfigType TxBufferCfgIdxOfMailBoxConfig;  /**< the index of the 0:1 relation pointing to CanIf_TxBufferPrioByCanIdByteQueueConfig */
  CanIf_TxBufferHandlingTypeOfMailBoxConfigType TxBufferHandlingTypeOfMailBoxConfig;
  CanIf_MailBoxTypeType MailBoxTypeOfMailBoxConfig;  /**< Type of mailbox: Rx-/Tx- BasicCAN/FullCAN/unused. */
} CanIf_MailBoxConfigType;

/**   \brief  type used in CanIf_MappedTxBuffersConfig */
typedef struct sCanIf_MappedTxBuffersConfigType
{
  CanIf_MailBoxConfigIdxOfMappedTxBuffersConfigType MailBoxConfigIdxOfMappedTxBuffersConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
} CanIf_MappedTxBuffersConfigType;

/**   \brief  type used in CanIf_RxIndicationFctList */
typedef struct sCanIf_RxIndicationFctListType
{
  CanIf_RxIndicationFctType RxIndicationFctOfRxIndicationFctList;  /**< Rx indication function. */
  CanIf_RxIndicationLayoutType RxIndicationLayoutOfRxIndicationFctList;  /**< Layout of Rx indication function. */
} CanIf_RxIndicationFctListType;

/**   \brief  type used in CanIf_RxPduConfig */
typedef struct sCanIf_RxPduConfigType
{
  CanIf_RxPduCanIdOfRxPduConfigType RxPduCanIdOfRxPduConfig;  /**< Rx-PDU: CAN identifier. */
  CanIf_RxPduMaskOfRxPduConfigType RxPduMaskOfRxPduConfig;  /**< Rx-PDU: CAN identifier mask. */
  CanIf_UpperPduIdOfRxPduConfigType UpperPduIdOfRxPduConfig;  /**< PDU ID defined by upper layer. */
  CanIf_DlcOfRxPduConfigType DlcOfRxPduConfig;  /**< Data length code. */
  CanIf_RxIndicationFctListIdxOfRxPduConfigType RxIndicationFctListIdxOfRxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_RxIndicationFctList */
} CanIf_RxPduConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdByteQueueConfig */
typedef struct sCanIf_TxBufferPrioByCanIdByteQueueConfigType
{
  CanIf_TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdBaseIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxBufferPrioByCanIdBase */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusEndIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the end index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusLengthOfTxBufferPrioByCanIdByteQueueConfig;  /**< the number of relations pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
  CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfigType TxBufferPrioByCanIdByteQueueMappedTxPdusStartIdxOfTxBufferPrioByCanIdByteQueueConfig;  /**< the start index of the 1:n relation pointing to CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
} CanIf_TxBufferPrioByCanIdByteQueueConfigType;

/**   \brief  type used in CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus */
typedef struct sCanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType
{
  CanIf_TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdusType TxPduConfigIdxOfTxBufferPrioByCanIdByteQueueMappedTxPdus;  /**< the index of the 1:1 relation pointing to CanIf_TxPduConfig */
} CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType;

/**   \brief  type used in CanIf_TxPduConfig */
typedef struct sCanIf_TxPduConfigType
{
  CanIf_CanIdOfTxPduConfigType CanIdOfTxPduConfig;  /**< CAN identifier (16bit / 32bit). */
  CanIf_UpperLayerTxPduIdOfTxPduConfigType UpperLayerTxPduIdOfTxPduConfig;  /**< Upper layer handle ID (8bit / 16bit). */
  CanIf_CtrlStatesIdxOfTxPduConfigType CtrlStatesIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_CtrlStates */
  CanIf_DlcOfTxPduConfigType DlcOfTxPduConfig;  /**< Data length code. */
  CanIf_MailBoxConfigIdxOfTxPduConfigType MailBoxConfigIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_MailBoxConfig */
  CanIf_TxConfirmationFctListIdxOfTxPduConfigType TxConfirmationFctListIdxOfTxPduConfig;  /**< the index of the 1:1 relation pointing to CanIf_TxConfirmationFctList */
} CanIf_TxPduConfigType;

/**   \brief  type used in CanIf_TxPduQueueIndex */
typedef struct sCanIf_TxPduQueueIndexType
{
  CanIf_TxQueueIdxOfTxPduQueueIndexType TxQueueIdxOfTxPduQueueIndex;  /**< the index of the 0:1 relation pointing to CanIf_TxQueue */
} CanIf_TxPduQueueIndexType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCSymbolicStructTypes  CanIf Symbolic Struct Types (PRE_COMPILE)
  \brief  These structs are used in unions to have a symbol based data representation style.
  \{
*/ 
/**   \brief  type to be used as symbolic data element access to CanIf_CtrlStates */
typedef struct CanIf_CtrlStatesStructSTag
{
  CanIf_CtrlStatesType CT_CAN00_4f940509[1];
  CanIf_CtrlStatesType CT_Schaeffler_MDA_CANFD_ffad619f[1];
  CanIf_CtrlStatesType CT_Schaeffler_MotorFL_CANFD_5f63093a[1];
  CanIf_CtrlStatesType CT_Schaeffler_MotorFR_CANFD_6882eea9[1];
  CanIf_CtrlStatesType CT_Schaeffler_MotorRL_CANFD_a79236eb[1];
  CanIf_CtrlStatesType CT_Schaeffler_MotorRR_CANFD_9073d178[1];
} CanIf_CtrlStatesStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxBufferPrioByCanIdBase */
typedef struct CanIf_TxBufferPrioByCanIdBaseStructSTag
{
  CanIf_TxBufferPrioByCanIdBaseType CHNL_0fb271d2[1];
} CanIf_TxBufferPrioByCanIdBaseStructSType;

/**   \brief  type to be used as symbolic data element access to CanIf_TxQueue */
typedef struct CanIf_TxQueueStructSTag
{
  CanIf_TxPrioByCanIdByteQueueType XCP_R_oCAN00_267e057e_Tx[1];
} CanIf_TxQueueStructSType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCUnionIndexAndSymbolTypes  CanIf Union Index And Symbol Types (PRE_COMPILE)
  \brief  These unions are used to access arrays in an index and symbol based style.
  \{
*/ 
/**   \brief  type to access CanIf_CtrlStates in an index and symbol based style. */
typedef union CanIf_CtrlStatesUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  CanIf_CtrlStatesType raw[6];
  CanIf_CtrlStatesStructSType str;
} CanIf_CtrlStatesUType;

/**   \brief  type to access CanIf_TxBufferPrioByCanIdBase in an index and symbol based style. */
typedef union CanIf_TxBufferPrioByCanIdBaseUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  CanIf_TxBufferPrioByCanIdBaseType raw[1];
  CanIf_TxBufferPrioByCanIdBaseStructSType str;
} CanIf_TxBufferPrioByCanIdBaseUType;

/**   \brief  type to access CanIf_TxQueue in an index and symbol based style. */
typedef union CanIf_TxQueueUTag
{  /* PRQA S 0750 */  /* MD_CSL_18.4 */
  CanIf_TxPrioByCanIdByteQueueType raw[1];
  CanIf_TxQueueStructSType str;
} CanIf_TxQueueUType;

/** 
  \}
*/ 

/** 
  \defgroup  CanIfPCRootValueTypes  CanIf Root Value Types (PRE_COMPILE)
  \brief  These type definitions are used for value representations in root arrays.
  \{
*/ 
/**   \brief  type used in CanIf_PCConfig */
typedef struct sCanIf_PCConfigType
{
  uint8 CanIf_PCConfigNeverUsed;  /**< dummy entry for the structure in the configuration variant precompile which is not used by the code. */
} CanIf_PCConfigType;

typedef CanIf_PCConfigType CanIf_ConfigType;  /**< A structure type is present for data in each configuration class. This typedef redefines the probably different name to the specified one. */

/** 
  \}
*/ 


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL SIMPLE DATA TYPES AND STRUCTURES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL COMPLEX DATA TYPES AND STRUCTURES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CanIf_BusOffNotificationFctPtr
**********************************************************************************************************************/
#define CANIF_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */
extern CONST(CanIf_BusOffNotificationFctType, CANIF_CONST) CanIf_BusOffNotificationFctPtr;
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
extern CONST(CanIf_CanIfCtrlId2MappedTxBuffersConfigType, CANIF_CONST) CanIf_CanIfCtrlId2MappedTxBuffersConfig[6];  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
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
extern CONST(CanIf_CtrlModeIndicationFctType, CANIF_CONST) CanIf_CtrlModeIndicationFctPtr;
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
extern CONST(CanIf_MailBoxConfigType, CANIF_CONST) CanIf_MailBoxConfig[55];
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
extern CONST(CanIf_MappedTxBuffersConfigType, CANIF_CONST) CanIf_MappedTxBuffersConfig[1];
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
extern CONST(CanIf_RxIndicationFctListType, CANIF_CONST) CanIf_RxIndicationFctList[3];
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
extern CONST(CanIf_RxPduConfigType, CANIF_CONST) CanIf_RxPduConfig[37];
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
extern CONST(CanIf_TxBufferPrioByCanIdByteQueueConfigType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueConfig[1];  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
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
extern CONST(CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdusType, CANIF_CONST) CanIf_TxBufferPrioByCanIdByteQueueMappedTxPdus[1];  /* PRQA S 0777 */  /* MD_MSR_5.1_777 */
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
extern CONST(CanIf_TxConfirmationFctType, CANIF_CONST) CanIf_TxConfirmationFctList[3];
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
extern CONST(CanIf_TxPduConfigType, CANIF_CONST) CanIf_TxPduConfig[20];
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
extern CONST(CanIf_TxPduQueueIndexType, CANIF_CONST) CanIf_TxPduQueueIndex[20];
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
extern VAR(CanIf_CtrlStatesUType, CANIF_VAR_NOINIT) CanIf_CtrlStates;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
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
extern VAR(CanIf_TxBufferPrioByCanIdBaseUType, CANIF_VAR_NOINIT) CanIf_TxBufferPrioByCanIdBase;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
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
extern VAR(CanIf_TxQueueUType, CANIF_VAR_NOINIT) CanIf_TxQueue;  /* PRQA S 0759 */  /* MD_CSL_18.4 */
#define CANIF_STOP_SEC_VAR_NOINIT_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_19.1 */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL DATA PROTOTYPES
**********************************************************************************************************************/


/**********************************************************************************************************************
  GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: POST_BUILD
  SECTION: GLOBAL FUNCTION PROTOTYPES
**********************************************************************************************************************/




#endif  /* CANIF_CFG_H */
/**********************************************************************************************************************
  END OF FILE: CanIf_Cfg.h
**********************************************************************************************************************/


