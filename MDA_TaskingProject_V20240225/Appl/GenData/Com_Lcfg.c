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
 *            Module: Com
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Com_Lcfg.c
 *   Generation Time: 2024-01-08 16:27:38
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


/**********************************************************************************************************************
  MISRA / PClint JUSTIFICATIONS
**********************************************************************************************************************/
/* PRQA  S 1881 EOF */ /* MD_MSR_AutosarBoolean */
/* PRQA  S 1882 EOF */ /* MD_MSR_AutosarBoolean */

/**********************************************************************************************************************
  INCLUDES
**********************************************************************************************************************/
#define V_IL_ASRCOMCFG5_LCFG_SOURCE

#include "Com.h"

#include "Com_Lcfg.h"


#include "SchM_Com.h"

/**********************************************************************************************************************
  LOCAL CONSTANT MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL FUNCTION MACROS
**********************************************************************************************************************/

/**********************************************************************************************************************
  LOCAL DATA TYPES AND STRUCTURES
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
  Com_ConstValueFloat32
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueFloat32
  \brief  Optimized array of commonly used values like initial or invalid values. (FLOAT32)
*/ 
#define COM_START_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueFloat32Type, COM_CONST) Com_ConstValueFloat32[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueFloat32      Referable Keys */
  /*     0 */ 0.0F                 /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_7013e7f5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_0d36ed6f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_6f298d95_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_RxInitValue] */
};
#define COM_STOP_SEC_CONST_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueSInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueSInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (SINT16)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueSInt16Type, COM_CONST) Com_ConstValueSInt16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueSInt16      Referable Keys */
  /*     0 */                 0   /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeALat_oVddmPropFr09_oCAN00_a776222d_RxInitValue, /ActiveEcuC/Com/ComConfig/ADataRawSafeALgt_oVddmPropFr09_oCAN00_4abc5057_RxInitValue, /ActiveEcuC/Com/ComConfig/ADataRawSafeAVert_oVddmPropFr09_oCAN00_5affce16_RxInitValue, /ActiveEcuC/Com/ComConfig/AgDataRawSafeRollRate_oVddmPropFr12_oCAN00_938781d5_RxInitValue, /ActiveEcuC/Com/ComConfig/AgDataRawSafeYawRate_oVddmPropFr12_oCAN00_ab257c3a_RxInitValue, /ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntAct_oEcmPropFr07_oCAN00_59efea99_RxInitValue, /ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntReq_oVddmPropFr08_oCAN00_b5a3120c_RxInitValue, /ActiveEcuC/Com/ComConfig/PtTqAtAxleReReq_oVddmPropFr08_oCAN00_ecdac0ff_RxInitValue, /ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntLeAct_oEcmPropFr07_oCAN00_2226bbb1_RxInitValue, /ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntRiAct_oEcmPropFr07_oCAN00_86eac12f_RxInitValue, /ActiveEcuC/Com/ComConfig/SteerWhlSnsrAgSpd_oVddmPropFr29_oCAN00_d671b60e_RxInitValue, /ActiveEcuC/Com/ComConfig/SteerWhlSnsrAg_oVddmPropFr29_oCAN00_896c638d_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt16
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt16
  \brief  Optimized array of commonly used values like initial or invalid values. (UINT16)
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt16Type, COM_CONST) Com_ConstValueUInt16[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt16      Referable Keys */
  /*     0 */           0x0000u   /* [/ActiveEcuC/Com/ComConfig/AccrPedlRatAccrPedlRat_oEcmPropFr00_oCAN00_4ad8b74f_RxInitValue, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntLeAct_oVddmPropFr10_oCAN00_b6b8e9ec_RxInitValue, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntRiAct_oVddmPropFr10_oCAN00_a1ab9bd5_RxInitValue, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReLeAct_oVddmPropFr10_oCAN00_8d4d2f89_RxInitValue, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReRiAct_oVddmPropFr10_oCAN00_9a5e5db0_RxInitValue, /ActiveEcuC/Com/ComConfig/BrkTqAtWhlsReq_oVddmPropFr08_oCAN00_2a675d21_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_1f1f7c0c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_76957b8d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_455450ed_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_2cde576c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_5071d764_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2d54ddfe_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_4f4bbd04_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_326eb79e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_86e41f3b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_ef6e18ba_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_dcaf33da_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_b525345b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_05cd1d48_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_78e817d2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_1af77728_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_67d27db2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_798d9eb1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_10079930_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_23c6b250_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_4a4cb5d1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_f956be0b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_8473b491_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e66cd46b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_9b49def1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_31f62729_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_4cd32db3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_2ecc4d49_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_53e947d3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_FWtimeOFF0_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2c61f86f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Frequency_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_c4966a2c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Ibias_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_9cd31f0c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostB_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_65518e5a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostP_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_382f0a40_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Ihold_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e7c79b2b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Ipeak_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2533c8f3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_675c3840_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_3339ef77_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbypass_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_8df9c3da_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_55fc637a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_0199b44d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_dd5ce5c0_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_893932f7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_FWtimeOFF0_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7dc19c34_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Frequency_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_36a98509_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Ibias_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_25a346c8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostB_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_e688b6ea_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostP_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_bbf632f0_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Ihold_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_5eb7c2ef_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Ipeak_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9c439137_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9563d765_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_c1060052_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbypass_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0e20fb6a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a7c38c5f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_f3a65b68_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_2f630ae5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7b06ddd2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_FWtimeOFF0_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8f2130d9_RxInitValue, 
              /ActiveEcuC/Com/ComConfig/Sig_Valve12_Frequency_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fb98b227_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Ibias_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3542aac5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostB_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b992f97b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostP_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e4ec7d61_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Ihold_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4e562ee2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Ipeak_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8ca27d3a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_5852e04b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0c37377c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbypass_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_513ab4fb_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_6af2bb71_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3e976c46_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e2523dcb_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b637eafc_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_FWtimeOFF0_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_de815482_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Frequency_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09a75d02_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Ibias_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_8c32f301_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostB_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3a4bc1cb_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostP_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_673545d1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Ihold_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_f7267726_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Ipeak_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_35d224fe_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_aa6d0f6e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_fe08d859_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbypass_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_d2e38c4b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_98cd5454_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_cca88363_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_106dd2ee_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_440805d9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_FWtimeOFF0_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_b1916f42_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Frequency_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ba8bda3a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Ibias_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_148172df_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostB_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_07a66659_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostP_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_5ad8e243_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Ihold_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_6f95f6f8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Ipeak_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ad61a520_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_19418856_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4d245f61_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbypass_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ef0e2bd9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_2be1d36c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_7f84045b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_a34155d6_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_f72482e1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_FWtimeOFF0_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_e0310b19_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Frequency_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48b4351f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Ibias_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_adf12b1b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostB_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_847f5ee9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostP_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d901daf3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Ihold_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d6e5af3c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Ipeak_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_1411fce4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_eb7e6773_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_bf1bb044_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbypass_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_6cd71369_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d9de3c49_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_8dbbeb7e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_517ebaf3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_051b6dc4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_FWtimeOFF0_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_12d1a7f4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Frequency_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_85850231_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Ibias_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_bd10c716_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostB_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_db651178_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostP_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_861b9562_RxInitValue, 
              /ActiveEcuC/Com/ComConfig/Sig_Valve16_Ihold_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c6044331_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Ipeak_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_04f010e9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_264f505d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_722a876a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbypass_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_33cd5cf8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_14ef0b67_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_408adc50_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_9c4f8ddd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c82a5aea_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_FWtimeOFF0_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_cdb96a4e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Frequency_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_84915280_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Ibias_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_16ed333d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostB_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c914d65f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostP_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_946a5245_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Ihold_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6df9b71a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Ipeak_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_af0de4c2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_275b00ec_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_733ed7db_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbypass_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_21bc9bdf_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_15fb5bd6_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_419e8ce1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_9d5bdd6c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c93e0a5b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_FWtimeOFF0_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_3f59c6a3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Frequency_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_49a065ae_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Ibias_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_060cdf30_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostB_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_960e99ce_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostP_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_cb701dd4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Ihold_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7d185b17_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Ipeak_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_bfec08cf_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_ea6a37c2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_be0fe0f5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbypass_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7ea6d44e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_d8ca6cf8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_8cafbbcf_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_506aea42_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_040f3d75_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_FWtimeOFF0_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6ef9a2f8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Frequency_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bb9f8a8b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Ibias_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bf7c86f4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostB_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_15d7a17e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostP_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_48a92564_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Ihold_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_c46802d3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Ipeak_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_069c510b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_1855d8e7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_4c300fd0_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbypass_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_fd7fecfe_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_2af583dd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7e9054ea_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_a2550567_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_f630d250_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_FWtimeOFF0_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_01e99938_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Frequency_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_08b30db3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Ibias_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_27cf072a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostB_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_283a06ec_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostP_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_754482f6_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Ihold_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_5cdb830d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Ipeak_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_9e2fd0d5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ab795fdf_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ff1c88e8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbypass_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_c0924b6c_RxInitValue, 
              /ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_99d904e5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_cdbcd3d2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1179825f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_451c5568_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_FWtimeOFF0_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5049fd63_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Frequency_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_fa8ce296_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Ibias_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_9ebf5eee_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostB_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_abe33e5c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostP_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_f69dba46_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Ihold_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e5abdac9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Ipeak_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_275f8911_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5946b0fa_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_0d2367cd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbypass_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_434b73dc_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_6be6ebc0_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_3f833cf7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e3466d7a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_b723ba4d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_FWtimeOFF0_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a2a9518e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Frequency_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37bdd5b8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Ibias_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_8e5eb2e3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostB_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f4f971cd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostP_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a987f5d7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Ihold_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f54a36c4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Ipeak_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37be651c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_947787d4_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_c01250e3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbypass_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_1c513c4d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a6d7dcee_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f2b20bd9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_2e775a54_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_7a128d63_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_FWtimeOFF0_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_f30935d5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Frequency_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_c5823a9d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Ibias_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_372eeb27_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostB_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_7720497d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostP_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_2a5ecd67_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Ihold_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_4c3a6f00_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Ipeak_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_8ece3cd8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_664868f1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_322dbfc6_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbypass_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_9f8804fd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_54e833cb_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_008de4fc_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_dc48b571_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_882d6246_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_FWtimeOFF0_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7c89260e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Frequency_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8a95dd89_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Ibias_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_6448b71e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostB_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8f223ee9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostP_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d25cbaf3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Ihold_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1f5c3339_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Ipeak_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_dda860e1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_295f8fe5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7d3a58d2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbypass_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_678a7369_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1bffd4df_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4f9a03e8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_935f5265_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_c73a8552_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_FWtimeOFF0_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_2d294255_RxInitValue, 
              /ActiveEcuC/Com/ComConfig/Sig_Valve9_Frequency_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_78aa32ac_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Ibias_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_dd38eeda_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostB_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_0cfb0659_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostP_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_51858243_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Ihold_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_a62c6afd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Ipeak_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_64d83925_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_db6060c0_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8f05b7f7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbypass_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e4534bd9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e9c03bfa_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_bda5eccd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_6160bd40_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_35056a77_RxInitValue, /ActiveEcuC/Com/ComConfig/TrsmVehSpd_oTcmPropFr04_oCAN00_9a41ead0_RxInitValue, /ActiveEcuC/Com/ComConfig/VehSpdLgtA_oVddmPropFr05_oCAN00_aa5f0501_RxInitValue, /ActiveEcuC/Com/ComConfig/WhlMotSysTqEstIsgTqAct_oIemEduPropFr01_oCAN00_32af1c7a_RxInitValue, /ActiveEcuC/Com/ComConfig/WhlMotSysTqReq_oEcmPropFr24_oCAN00_2b85d3d8_RxInitValue] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_ConstValueUInt8
**********************************************************************************************************************/
/** 
  \var    Com_ConstValueUInt8
  \brief  Optimized array of commonly used values like initial or invalid values. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_ConstValueUInt8Type, COM_CONST) Com_ConstValueUInt8[1] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     ConstValueUInt8      Referable Keys */
  /*     0 */            0x00u   /* [/ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlNotPsdSafe_oVddmPropFr05_oCAN00_6dd71a9b_RxInitValue, /ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlPsd_oVddmPropFr05_oCAN00_dcf25825_RxInitValue, /ActiveEcuC/Com/ComConfig/GearLvrIndcn_oEcmPropFr24_oCAN00_fa2560a8_RxInitValue, /ActiveEcuC/Com/ComConfig/HvSysSts_oBecmPropFr01_oCAN00_919ec934_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_940a4d73_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_e92f47e9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_8b302713_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_f6152d89_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_4378bd23_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2af2baa2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_193391c2_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_70b99643_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_880421cb_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_f5212b51_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_973e4bab_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ea1b4131_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_115de03b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_6c78eaa1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_0e678a5b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_734280c1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_811760c8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_fc326a52_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_9e2d0aa8_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_e3080032_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_fb218646_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_92ab81c7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_a16aaaa7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_c8e0ad26_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_DutyCycle_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e5041d25_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_MDAswitchPC_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_18c8890a_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Mode_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_4a458887_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve10_State_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_192e4a09_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_DutyCycle_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_173bf200_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_MDAswitchPC_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_fe762ee1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Mode_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_d093cbe5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve11_State_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a05e13cd_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_DutyCycle_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_da0ac52e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_MDAswitchPC_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0ec4c09d_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Mode_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_a4980802_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve12_State_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b0bfffc0_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_DutyCycle_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_28352a0b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_MDAswitchPC_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_e87a6776_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Mode_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3e4e4b60_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve13_State_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09cfa604_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_DutyCycle_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_9b19ad33_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_MDAswitchPC_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_34d01a24_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Mode_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4c8f8fcc_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve14_State_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_917c27da_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_DutyCycle_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_69264216_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_MDAswitchPC_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d26ebdcf_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Mode_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d659ccae_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve15_State_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_280c7e1e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_DutyCycle_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a4177538_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_MDAswitchPC_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_22dc53b3_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Mode_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a2520f49_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve16_State_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_38ed9213_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_DutyCycle_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_a5032589_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_MDAswitchPC_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6ab83b1c_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Mode_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_87ad547b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve1_State_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_93106638_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_DutyCycle_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_683212a7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_MDAswitchPC_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_9a0ad560_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Mode_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f3a6979c_RxInitValue, 
              /ActiveEcuC/Com/ComConfig/Sig_Valve2_State_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_83f18a35_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_DutyCycle_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_9a0dfd82_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_MDAswitchPC_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7cb4728b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Mode_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6970d4fe_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve3_State_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_3a81d3f1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_DutyCycle_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_29217aba_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_MDAswitchPC_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a01e0fd9_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Mode_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1bb11052_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve4_State_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a232522f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_DutyCycle_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_db1e959f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_MDAswitchPC_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_46a0a832_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Mode_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_81675330_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve5_State_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1b420beb_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_DutyCycle_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_162fa2b1_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_MDAswitchPC_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_b612464e_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Mode_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f56c90d7_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve6_State_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_0ba3e7e6_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_DutyCycle_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_e4104d94_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_MDAswitchPC_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_50ace1a5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Mode_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6fbad3b5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve7_State_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_b2d3be22_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_DutyCycle_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_ab07aa80_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_MDAswitchPC_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d437baab_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Mode_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_10ef198f_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve8_State_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_e1b5e21b_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_DutyCycle_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_593845a5_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_MDAswitchPC_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_32891d40_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Mode_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8a395aed_RxInitValue, /ActiveEcuC/Com/ComConfig/Sig_Valve9_State_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_58c5bbdf_RxInitValue] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_PduGrpVector
**********************************************************************************************************************/
/** 
  \var    Com_PduGrpVector
  \brief  Contains an I-PDU-Group vector for each I-PDU, mapping the I-PDU to the corresponding I-PDU-Groups.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_PduGrpVectorType, COM_CONST) Com_PduGrpVector[11] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     PduGrpVector      Referable Keys */
  /*     0 */         0x80u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*     1 */         0x20u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*     2 */         0x08u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*     3 */         0x40u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*     4 */         0x10u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*     5 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*     6 */         0x02u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*     7 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*     8 */         0x04u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*     9 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    10 */         0x01u   /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx, /ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx, /ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfo
  \brief  Contains all signal layout information necessary for signal access within an I-PDU.
  \details
  Element                   Description
  BufferIdx                 the index of the 0:1 relation pointing to Com_RxSigBufferUInt8,Com_RxSigBufferUInt16,Com_RxSigBufferUInt32,Com_RxSigBufferUInt64,Com_RxSigBufferZeroBit,Com_RxSigBufferSInt8,Com_RxSigBufferSInt16,Com_RxSigBufferSInt32,Com_RxSigBufferSInt64,Com_RxSigBufferFloat32,Com_RxSigBufferFloat64
  InitValueUsed             TRUE, if the 0:1 relation has minimum 1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  SignExtRequired           TRUE if sign extension is required for signal / group signal reception.
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  BytePosition              Little endian byte position of the signal or group signal within the I-PDU.
  InitValueIdx              the index of the 0:1 relation pointing to Com_ConstValueUInt8,Com_ConstValueUInt16,Com_ConstValueUInt32,Com_ConstValueUInt64,Com_ConstValueSInt8,Com_ConstValueSInt16,Com_ConstValueSInt32,Com_ConstValueSInt64,Com_ConstValueFloat32,Com_ConstValueFloat64
  RxPduInfoIdx              the index of the 1:1 relation pointing to Com_RxPduInfo
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoType, COM_CONST) Com_RxAccessInfo[370] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*     0 */        0u,          TRUE,            TRUE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       15u,         25u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           3u,           0u,          32u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeALat_oVddmPropFr09_oCAN00_a776222d_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  { /*     1 */        1u,          TRUE,            TRUE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       15u,         40u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           5u,           0u,          32u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeALgt_oVddmPropFr09_oCAN00_4abc5057_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  { /*     2 */        2u,          TRUE,            TRUE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       15u,         57u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,          32u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeAVert_oVddmPropFr09_oCAN00_5affce16_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  { /*     3 */        0u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       15u,          8u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           1u,           0u,           1u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/AccrPedlRatAccrPedlRat_oEcmPropFr00_oCAN00_4ad8b74f_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx] */
  { /*     4 */        3u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          34u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/AgDataRawSafeRollRate_oVddmPropFr12_oCAN00_938781d5_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  { /*     5 */        4u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          34u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/AgDataRawSafeYawRate_oVddmPropFr12_oCAN00_ab257c3a_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  { /*     6 */        1u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       13u,          8u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           1u,           0u,          33u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntLeAct_oVddmPropFr10_oCAN00_b6b8e9ec_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*     7 */        2u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       13u,         24u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           3u,           0u,          33u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntRiAct_oVddmPropFr10_oCAN00_a1ab9bd5_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*     8 */        3u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       13u,         40u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           5u,           0u,          33u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReLeAct_oVddmPropFr10_oCAN00_8d4d2f89_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*     9 */        4u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       13u,         56u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,          33u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReRiAct_oVddmPropFr10_oCAN00_9a5e5db0_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*    10 */        0u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          7u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,          30u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlNotPsdSafe_oVddmPropFr05_oCAN00_6dd71a9b_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  { /*    11 */        1u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        1u,          6u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           0u,           0u,          30u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlPsd_oVddmPropFr05_oCAN00_dcf25825_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  { /*    12 */        5u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12u,         12u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           1u,           0u,          31u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/BrkTqAtWhlsReq_oVddmPropFr08_oCAN00_2a675d21_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  { /*    13 */        2u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        3u,         25u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           3u,           0u,           3u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/GearLvrIndcn_oEcmPropFr24_oCAN00_fa2560a8_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
  { /*    14 */        3u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        2u,         57u,         COM_NBIT_BUSACCOFRXACCESSINFO,         0u,           7u,           0u,           0u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/HvSysSts_oBecmPropFr01_oCAN00_919ec934_Rx, /ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx] */
  { /*    15 */        5u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,           2u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntAct_oEcmPropFr07_oCAN00_59efea99_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  { /*    16 */        6u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          31u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntReq_oVddmPropFr08_oCAN00_b5a3120c_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  { /*    17 */        7u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          31u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/PtTqAtAxleReReq_oVddmPropFr08_oCAN00_ecdac0ff_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  { /*    18 */        8u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,           2u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntLeAct_oEcmPropFr07_oCAN00_2226bbb1_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  { /*    19 */        9u,          TRUE,           FALSE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,           2u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntRiAct_oEcmPropFr07_oCAN00_86eac12f_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  { /*    20 */        0u,          TRUE,           FALSE, COM_FLOAT32_APPLTYPEOFRXACCESSINFO,       32u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         4u,           1u,           0u,          25u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_7013e7f5_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    21 */        1u,          TRUE,           FALSE, COM_FLOAT32_APPLTYPEOFRXACCESSINFO,       32u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         4u,           1u,           0u,          26u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_0d36ed6f_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    22 */        2u,          TRUE,           FALSE, COM_FLOAT32_APPLTYPEOFRXACCESSINFO,       32u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         4u,           1u,           0u,          27u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_6f298d95_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    23 */        3u,          TRUE,           FALSE, COM_FLOAT32_APPLTYPEOFRXACCESSINFO,       32u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         4u,           1u,           0u,          28u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    24 */        4u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        112u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          14u,           0u,          25u,                    14u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_940a4d73_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    25 */        5u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        112u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          14u,           0u,          26u,                    14u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_e92f47e9_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    26 */        6u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        112u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          14u,           0u,          27u,                    14u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_8b302713_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    27 */        7u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        112u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          14u,           0u,          28u,                    14u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_f6152d89_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    28 */        8u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         56u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,           5u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_4378bd23_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    29 */        9u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         56u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,           6u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2af2baa2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    30 */       10u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         56u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,           7u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_193391c2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    31 */       11u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         56u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           7u,           0u,           8u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_70b99643_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    32 */       12u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        120u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          15u,           0u,          25u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_880421cb_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    33 */       13u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        120u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          15u,           0u,          26u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_f5212b51_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    34 */       14u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        120u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          15u,           0u,          27u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_973e4bab_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    35 */       15u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        120u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          15u,           0u,          28u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ea1b4131_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    36 */        6u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          0u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           0u,           0u,           5u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_1f1f7c0c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    37 */        7u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          0u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           0u,           0u,           6u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_76957b8d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    38 */        8u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          0u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           0u,           0u,           7u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_455450ed_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    39 */        9u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          0u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           0u,           0u,           8u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_2cde576c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    40 */       10u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          25u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_5071d764_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    41 */       11u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          26u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2d54ddfe_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    42 */       12u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          27u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_4f4bbd04_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    43 */       13u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          28u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_326eb79e_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    44 */       14u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         16u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           2u,           0u,           5u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_86e41f3b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    45 */       15u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         16u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           2u,           0u,           6u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_ef6e18ba_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    46 */       16u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         16u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           2u,           0u,           7u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_dcaf33da_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    47 */       17u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         16u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           2u,           0u,           8u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_b525345b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    48 */       18u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         80u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          10u,           0u,          25u,                    10u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_05cd1d48_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    49 */       19u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         80u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          10u,           0u,          26u,                    10u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_78e817d2_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*    50 */       20u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         80u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          10u,           0u,          27u,                    10u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_1af77728_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    51 */       21u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         80u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          10u,           0u,          28u,                    10u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_67d27db2_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    52 */       16u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          25u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_115de03b_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    53 */       17u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          26u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_6c78eaa1_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    54 */       18u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          27u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_0e678a5b_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    55 */       19u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          28u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_734280c1_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    56 */       20u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         72u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           9u,           0u,          25u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_811760c8_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    57 */       21u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         72u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           9u,           0u,          26u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_fc326a52_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    58 */       22u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         72u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           9u,           0u,          27u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_9e2d0aa8_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    59 */       23u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         72u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           9u,           0u,          28u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_e3080032_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    60 */       22u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         32u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           4u,           0u,           5u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_798d9eb1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    61 */       23u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         32u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           4u,           0u,           6u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_10079930_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    62 */       24u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         32u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           4u,           0u,           7u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_23c6b250_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    63 */       25u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         32u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           4u,           0u,           8u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_4a4cb5d1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    64 */       26u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         96u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          12u,           0u,          25u,                    12u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_f956be0b_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    65 */       27u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         96u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          12u,           0u,          26u,                    12u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_8473b491_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    66 */       28u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         96u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          12u,           0u,          27u,                    12u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e66cd46b_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    67 */       29u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         96u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          12u,           0u,          28u,                    12u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_9b49def1_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    68 */       30u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          25u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_31f62729_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*    69 */       31u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          26u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_4cd32db3_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*    70 */       32u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          27u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_2ecc4d49_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*    71 */       33u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          28u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_53e947d3_Rx, /ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*    72 */       24u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         48u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           6u,           0u,           5u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_fb218646_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    73 */       25u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         48u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           6u,           0u,           6u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_92ab81c7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    74 */       26u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         48u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           6u,           0u,           7u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_a16aaaa7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    75 */       27u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,         48u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           6u,           0u,           8u,                     6u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_c8e0ad26_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    76 */       28u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,           9u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_DutyCycle_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_a5032589_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    77 */       34u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,           9u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_FWtimeOFF0_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_cdb96a4e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    78 */       35u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,           9u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Frequency_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_84915280_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    79 */       36u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,           9u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Ibias_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_16ed333d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    80 */       37u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,           9u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostB_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c914d65f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    81 */       38u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,           9u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostP_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_946a5245_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    82 */       39u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,           9u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Ihold_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6df9b71a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    83 */       40u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,           9u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Ipeak_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_af0de4c2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    84 */       29u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,           9u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_MDAswitchPC_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6ab83b1c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    85 */       30u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,           9u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Mode_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_87ad547b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    86 */       31u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,           9u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_State_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_93106638_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    87 */       41u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,           9u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_275b00ec_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    88 */       42u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,           9u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_733ed7db_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    89 */       43u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,           9u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbypass_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_21bc9bdf_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    90 */       44u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,           9u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_15fb5bd6_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    91 */       45u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,           9u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_419e8ce1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    92 */       46u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,           9u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_9d5bdd6c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    93 */       47u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,           9u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c93e0a5b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    94 */       32u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          10u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_DutyCycle_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_683212a7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    95 */       48u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          10u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_FWtimeOFF0_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_3f59c6a3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    96 */       49u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          10u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Frequency_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_49a065ae_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    97 */       50u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          10u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Ibias_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_060cdf30_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    98 */       51u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          10u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostB_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_960e99ce_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    99 */       52u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          10u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostP_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_cb701dd4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*   100 */       53u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          10u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Ihold_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7d185b17_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   101 */       54u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          10u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Ipeak_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_bfec08cf_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   102 */       33u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          10u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_MDAswitchPC_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_9a0ad560_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   103 */       34u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          10u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Mode_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f3a6979c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   104 */       35u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          10u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_State_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_83f18a35_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   105 */       55u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          10u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_ea6a37c2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   106 */       56u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          10u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_be0fe0f5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   107 */       57u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          10u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbypass_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7ea6d44e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   108 */       58u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          10u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_d8ca6cf8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   109 */       59u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          10u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_8cafbbcf_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   110 */       60u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          10u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_506aea42_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   111 */       61u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          10u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_040f3d75_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*   112 */       36u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          11u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_DutyCycle_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_9a0dfd82_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   113 */       62u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          11u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_FWtimeOFF0_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6ef9a2f8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   114 */       63u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          11u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Frequency_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bb9f8a8b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   115 */       64u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          11u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Ibias_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bf7c86f4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   116 */       65u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          11u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostB_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_15d7a17e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   117 */       66u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          11u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostP_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_48a92564_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   118 */       67u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          11u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Ihold_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_c46802d3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   119 */       68u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          11u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Ipeak_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_069c510b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   120 */       37u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          11u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_MDAswitchPC_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7cb4728b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   121 */       38u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          11u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Mode_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6970d4fe_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   122 */       39u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          11u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_State_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_3a81d3f1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   123 */       69u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          11u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_1855d8e7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   124 */       70u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          11u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_4c300fd0_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   125 */       71u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          11u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbypass_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_fd7fecfe_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   126 */       72u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          11u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_2af583dd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   127 */       73u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          11u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7e9054ea_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   128 */       74u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          11u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_a2550567_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   129 */       75u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          11u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_f630d250_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*   130 */       40u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          12u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_DutyCycle_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_29217aba_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   131 */       76u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          12u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_FWtimeOFF0_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_01e99938_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   132 */       77u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          12u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Frequency_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_08b30db3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   133 */       78u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          12u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Ibias_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_27cf072a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   134 */       79u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          12u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostB_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_283a06ec_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   135 */       80u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          12u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostP_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_754482f6_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   136 */       81u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          12u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Ihold_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_5cdb830d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   137 */       82u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          12u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Ipeak_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_9e2fd0d5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   138 */       41u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          12u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_MDAswitchPC_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a01e0fd9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   139 */       42u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          12u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Mode_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1bb11052_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   140 */       43u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          12u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_State_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a232522f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   141 */       83u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          12u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ab795fdf_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   142 */       84u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          12u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ff1c88e8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   143 */       85u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          12u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbypass_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_c0924b6c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   144 */       86u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          12u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_99d904e5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   145 */       87u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          12u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_cdbcd3d2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   146 */       88u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          12u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1179825f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   147 */       89u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          12u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_451c5568_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*   148 */       44u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          13u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_DutyCycle_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_db1e959f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   149 */       90u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          13u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_FWtimeOFF0_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5049fd63_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*   150 */       91u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          13u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Frequency_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_fa8ce296_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   151 */       92u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          13u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Ibias_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_9ebf5eee_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   152 */       93u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          13u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostB_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_abe33e5c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   153 */       94u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          13u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostP_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_f69dba46_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   154 */       95u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          13u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Ihold_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e5abdac9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   155 */       96u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          13u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Ipeak_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_275f8911_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   156 */       45u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          13u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_MDAswitchPC_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_46a0a832_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   157 */       46u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          13u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Mode_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_81675330_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   158 */       47u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          13u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_State_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1b420beb_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   159 */       97u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          13u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5946b0fa_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   160 */       98u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          13u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_0d2367cd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   161 */       99u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          13u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbypass_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_434b73dc_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   162 */      100u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          13u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_6be6ebc0_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   163 */      101u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          13u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_3f833cf7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   164 */      102u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          13u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e3466d7a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   165 */      103u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          13u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_b723ba4d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   166 */       48u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          14u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_DutyCycle_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_162fa2b1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   167 */      104u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          14u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_FWtimeOFF0_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a2a9518e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   168 */      105u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          14u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Frequency_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37bdd5b8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   169 */      106u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          14u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Ibias_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_8e5eb2e3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   170 */      107u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          14u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostB_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f4f971cd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   171 */      108u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          14u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostP_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a987f5d7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   172 */      109u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          14u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Ihold_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f54a36c4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   173 */      110u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          14u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Ipeak_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37be651c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   174 */       49u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          14u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_MDAswitchPC_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_b612464e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   175 */       50u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          14u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Mode_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f56c90d7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   176 */       51u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          14u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_State_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_0ba3e7e6_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   177 */      111u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          14u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_947787d4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   178 */      112u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          14u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_c01250e3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   179 */      113u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          14u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbypass_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_1c513c4d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   180 */      114u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          14u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a6d7dcee_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   181 */      115u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          14u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f2b20bd9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   182 */      116u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          14u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_2e775a54_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   183 */      117u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          14u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_7a128d63_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   184 */       52u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          15u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_DutyCycle_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_e4104d94_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   185 */      118u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          15u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_FWtimeOFF0_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_f30935d5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   186 */      119u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          15u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Frequency_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_c5823a9d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   187 */      120u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          15u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Ibias_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_372eeb27_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   188 */      121u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          15u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostB_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_7720497d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   189 */      122u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          15u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostP_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_2a5ecd67_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   190 */      123u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          15u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Ihold_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_4c3a6f00_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   191 */      124u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          15u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Ipeak_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_8ece3cd8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   192 */       53u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          15u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_MDAswitchPC_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_50ace1a5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   193 */       54u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          15u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Mode_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6fbad3b5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   194 */       55u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          15u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_State_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_b2d3be22_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   195 */      125u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          15u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_664868f1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   196 */      126u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          15u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_322dbfc6_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   197 */      127u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          15u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbypass_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_9f8804fd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   198 */      128u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          15u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_54e833cb_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   199 */      129u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          15u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_008de4fc_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*   200 */      130u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          15u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_dc48b571_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   201 */      131u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          15u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_882d6246_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   202 */       56u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          16u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_DutyCycle_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_ab07aa80_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   203 */      132u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          16u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_FWtimeOFF0_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7c89260e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   204 */      133u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          16u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Frequency_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8a95dd89_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   205 */      134u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          16u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Ibias_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_6448b71e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   206 */      135u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          16u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostB_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8f223ee9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   207 */      136u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          16u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostP_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d25cbaf3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   208 */      137u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          16u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Ihold_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1f5c3339_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   209 */      138u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          16u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Ipeak_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_dda860e1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   210 */       57u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          16u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_MDAswitchPC_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d437baab_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   211 */       58u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          16u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Mode_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_10ef198f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   212 */       59u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          16u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_State_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_e1b5e21b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   213 */      139u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          16u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_295f8fe5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   214 */      140u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          16u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7d3a58d2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   215 */      141u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          16u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbypass_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_678a7369_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   216 */      142u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          16u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1bffd4df_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   217 */      143u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          16u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4f9a03e8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   218 */      144u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          16u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_935f5265_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   219 */      145u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          16u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_c73a8552_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   220 */       60u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          17u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_DutyCycle_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_593845a5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   221 */      146u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          17u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_FWtimeOFF0_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_2d294255_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   222 */      147u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          17u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Frequency_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_78aa32ac_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   223 */      148u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          17u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Ibias_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_dd38eeda_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   224 */      149u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          17u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostB_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_0cfb0659_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   225 */      150u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          17u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostP_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_51858243_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   226 */      151u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          17u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Ihold_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_a62c6afd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   227 */      152u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          17u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Ipeak_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_64d83925_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   228 */       61u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          17u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_MDAswitchPC_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_32891d40_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   229 */       62u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          17u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Mode_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8a395aed_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   230 */       63u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          17u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_State_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_58c5bbdf_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   231 */      153u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          17u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_db6060c0_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   232 */      154u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          17u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8f05b7f7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   233 */      155u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          17u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbypass_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e4534bd9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   234 */      156u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          17u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e9c03bfa_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   235 */      157u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          17u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_bda5eccd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   236 */      158u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          17u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_6160bd40_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   237 */      159u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          17u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_35056a77_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   238 */       64u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          18u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_DutyCycle_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e5041d25_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   239 */      160u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          18u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_FWtimeOFF0_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2c61f86f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   240 */      161u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          18u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Frequency_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_c4966a2c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   241 */      162u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          18u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Ibias_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_9cd31f0c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   242 */      163u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          18u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostB_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_65518e5a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   243 */      164u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          18u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostP_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_382f0a40_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   244 */      165u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          18u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Ihold_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e7c79b2b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   245 */      166u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          18u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Ipeak_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2533c8f3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   246 */       65u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          18u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_MDAswitchPC_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_18c8890a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   247 */       66u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          18u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Mode_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_4a458887_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   248 */       67u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          18u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_State_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_192e4a09_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   249 */      167u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          18u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_675c3840_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*   250 */      168u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          18u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_3339ef77_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   251 */      169u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          18u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbypass_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_8df9c3da_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   252 */      170u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          18u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_55fc637a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   253 */      171u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          18u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_0199b44d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   254 */      172u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          18u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_dd5ce5c0_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   255 */      173u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          18u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_893932f7_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   256 */       68u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          19u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_DutyCycle_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_173bf200_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   257 */      174u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          19u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_FWtimeOFF0_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7dc19c34_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   258 */      175u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          19u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Frequency_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_36a98509_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   259 */      176u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          19u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Ibias_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_25a346c8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   260 */      177u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          19u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostB_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_e688b6ea_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   261 */      178u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          19u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostP_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_bbf632f0_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   262 */      179u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          19u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Ihold_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_5eb7c2ef_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   263 */      180u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          19u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Ipeak_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9c439137_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   264 */       69u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          19u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_MDAswitchPC_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_fe762ee1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   265 */       70u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          19u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Mode_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_d093cbe5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   266 */       71u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          19u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_State_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a05e13cd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   267 */      181u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          19u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9563d765_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   268 */      182u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          19u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_c1060052_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   269 */      183u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          19u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbypass_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0e20fb6a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   270 */      184u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          19u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a7c38c5f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   271 */      185u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          19u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_f3a65b68_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   272 */      186u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          19u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_2f630ae5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   273 */      187u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          19u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7b06ddd2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   274 */       72u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          20u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_DutyCycle_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_da0ac52e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   275 */      188u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          20u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_FWtimeOFF0_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8f2130d9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   276 */      189u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          20u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Frequency_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fb98b227_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   277 */      190u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          20u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Ibias_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3542aac5_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   278 */      191u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          20u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostB_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b992f97b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   279 */      192u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          20u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostP_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e4ec7d61_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   280 */      193u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          20u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Ihold_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4e562ee2_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   281 */      194u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          20u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Ipeak_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8ca27d3a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   282 */       73u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          20u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_MDAswitchPC_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0ec4c09d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   283 */       74u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          20u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Mode_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_a4980802_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   284 */       75u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          20u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_State_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b0bfffc0_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   285 */      195u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          20u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_5852e04b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   286 */      196u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          20u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0c37377c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   287 */      197u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          20u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbypass_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_513ab4fb_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   288 */      198u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          20u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_6af2bb71_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   289 */      199u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          20u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3e976c46_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   290 */      200u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          20u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e2523dcb_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   291 */      201u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          20u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b637eafc_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   292 */       76u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          21u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_DutyCycle_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_28352a0b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   293 */      202u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          21u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_FWtimeOFF0_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_de815482_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   294 */      203u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          21u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Frequency_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09a75d02_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   295 */      204u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          21u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Ibias_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_8c32f301_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   296 */      205u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          21u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostB_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3a4bc1cb_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   297 */      206u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          21u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostP_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_673545d1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   298 */      207u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          21u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Ihold_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_f7267726_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   299 */      208u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          21u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Ipeak_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_35d224fe_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*   300 */       77u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          21u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_MDAswitchPC_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_e87a6776_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   301 */       78u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          21u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Mode_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3e4e4b60_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   302 */       79u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          21u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_State_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09cfa604_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   303 */      209u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          21u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_aa6d0f6e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   304 */      210u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          21u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_fe08d859_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   305 */      211u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          21u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbypass_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_d2e38c4b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   306 */      212u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          21u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_98cd5454_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   307 */      213u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          21u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_cca88363_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   308 */      214u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          21u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_106dd2ee_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   309 */      215u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          21u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_440805d9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   310 */       80u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          22u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_DutyCycle_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_9b19ad33_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   311 */      216u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          22u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_FWtimeOFF0_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_b1916f42_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   312 */      217u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          22u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Frequency_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ba8bda3a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   313 */      218u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          22u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Ibias_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_148172df_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   314 */      219u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          22u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostB_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_07a66659_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   315 */      220u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          22u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostP_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_5ad8e243_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   316 */      221u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          22u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Ihold_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_6f95f6f8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   317 */      222u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          22u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Ipeak_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ad61a520_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   318 */       81u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          22u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_MDAswitchPC_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_34d01a24_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   319 */       82u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          22u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Mode_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4c8f8fcc_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   320 */       83u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          22u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_State_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_917c27da_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   321 */      223u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          22u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_19418856_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   322 */      224u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          22u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4d245f61_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   323 */      225u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          22u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbypass_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ef0e2bd9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   324 */      226u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          22u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_2be1d36c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   325 */      227u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          22u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_7f84045b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   326 */      228u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          22u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_a34155d6_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   327 */      229u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          22u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_f72482e1_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   328 */       84u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          23u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_DutyCycle_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_69264216_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   329 */      230u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          23u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_FWtimeOFF0_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_e0310b19_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   330 */      231u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          23u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Frequency_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48b4351f_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   331 */      232u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          23u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Ibias_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_adf12b1b_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   332 */      233u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          23u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostB_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_847f5ee9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   333 */      234u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          23u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostP_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d901daf3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   334 */      235u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          23u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Ihold_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d6e5af3c_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   335 */      236u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          23u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Ipeak_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_1411fce4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   336 */       85u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          23u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_MDAswitchPC_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d26ebdcf_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   337 */       86u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          23u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Mode_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d659ccae_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   338 */       87u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          23u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_State_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_280c7e1e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   339 */      237u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          23u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_eb7e6773_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   340 */      238u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          23u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_bf1bb044_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   341 */      239u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          23u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbypass_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_6cd71369_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   342 */      240u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          23u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d9de3c49_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   343 */      241u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          23u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_8dbbeb7e_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   344 */      242u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          23u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_517ebaf3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   345 */      243u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          23u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_051b6dc4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   346 */       88u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,          0u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,           0u,           0u,          24u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_DutyCycle_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a4177538_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   347 */      244u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        216u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          27u,           0u,          24u,                    27u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_FWtimeOFF0_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_12d1a7f4_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   348 */      245u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,          8u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           1u,           0u,          24u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Frequency_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_85850231_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   349 */      246u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         72u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           9u,           0u,          24u,                     9u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Ibias_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_bd10c716_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
    /* Index    BufferIdx  InitValueUsed  SignExtRequired  ApplType                            BitLength  BitPosition  BusAcc                                 ByteLength  BytePosition  InitValueIdx  RxPduInfoIdx  StartByteInPduPosition        Referable Keys */
  { /*   350 */      247u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         24u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           3u,           0u,          24u,                     3u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostB_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_db651178_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   351 */      248u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         88u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          11u,           0u,          24u,                    11u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostP_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_861b9562_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   352 */      249u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        200u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          25u,           0u,          24u,                    25u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Ihold_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c6044331_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   353 */      250u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        136u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          17u,           0u,          24u,                    17u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Ipeak_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_04f010e9_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   354 */       89u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        248u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          31u,           0u,          24u,                    31u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_MDAswitchPC_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_22dc53b3_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   355 */       90u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        232u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          29u,           0u,          24u,                    29u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Mode_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a2520f49_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   356 */       91u,          TRUE,           FALSE,   COM_UINT8_APPLTYPEOFRXACCESSINFO,        8u,        240u,         COM_BYTE_BUSACCOFRXACCESSINFO,         1u,          30u,           0u,          24u,                    30u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_State_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_38ed9213_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   357 */      251u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         56u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           7u,           0u,          24u,                     7u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_264f505d_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   358 */      252u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          24u,                     5u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_722a876a_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   359 */      253u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        152u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          19u,           0u,          24u,                    19u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbypass_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_33cd5cf8_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   360 */      254u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        184u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          23u,           0u,          24u,                    23u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_14ef0b67_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   361 */      255u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        168u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          21u,           0u,          24u,                    21u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_408adc50_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   362 */      256u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        120u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          15u,           0u,          24u,                    15u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_9c4f8ddd_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   363 */      257u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,        104u,        COM_NBYTE_BUSACCOFRXACCESSINFO,         2u,          13u,           0u,          24u,                    13u },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c82a5aea_Rx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   364 */       10u,          TRUE,            TRUE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       14u,         24u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           3u,           0u,          35u,                     2u },  /* [/ActiveEcuC/Com/ComConfig/SteerWhlSnsrAgSpd_oVddmPropFr29_oCAN00_d671b60e_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
  { /*   365 */       11u,          TRUE,            TRUE,  COM_SINT16_APPLTYPEOFRXACCESSINFO,       15u,          8u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           1u,           0u,          35u,                     0u },  /* [/ActiveEcuC/Com/ComConfig/SteerWhlSnsrAg_oVddmPropFr29_oCAN00_896c638d_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
  { /*   366 */      258u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       16u,         40u,     COM_NBYTE_SW_BUSACCOFRXACCESSINFO,         2u,           5u,           0u,          29u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/TrsmVehSpd_oTcmPropFr04_oCAN00_9a41ead0_Rx, /ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx] */
  { /*   367 */      259u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       15u,         40u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           5u,           0u,          30u,                     4u },  /* [/ActiveEcuC/Com/ComConfig/VehSpdLgtA_oVddmPropFr05_oCAN00_aa5f0501_Rx, /ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  { /*   368 */      260u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       14u,         18u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           2u,           0u,           4u,                     1u },  /* [/ActiveEcuC/Com/ComConfig/WhlMotSysTqEstIsgTqAct_oIemEduPropFr01_oCAN00_32af1c7a_Rx, /ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx] */
  { /*   369 */      261u,          TRUE,           FALSE,  COM_UINT16_APPLTYPEOFRXACCESSINFO,       12u,         16u, COM_NBITNBYTE_SW_BUSACCOFRXACCESSINFO,         1u,           2u,           0u,           3u,                     1u }   /* [/ActiveEcuC/Com/ComConfig/WhlMotSysTqReq_oEcmPropFr24_oCAN00_2b85d3d8_Rx, /ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxAccessInfoInd
**********************************************************************************************************************/
/** 
  \var    Com_RxAccessInfoInd
  \brief  the indexes of the 1:1 sorted relation pointing to Com_RxAccessInfo
*/ 
#define COM_START_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxAccessInfoIndType, COM_CONST) Com_RxAccessInfoInd[370] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*     0 */              14u,  /* [/ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx] */
  /*     1 */               3u,  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx] */
  /*     2 */              15u,  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  /*     3 */              18u,  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  /*     4 */              19u,  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  /*     5 */              13u,  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
  /*     6 */             369u,  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
  /*     7 */             368u,  /* [/ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx] */
  /*     8 */              28u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  /*     9 */              36u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  /*    10 */              44u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  /*    11 */              60u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  /*    12 */              72u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  /*    13 */              29u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  /*    14 */              37u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  /*    15 */              45u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  /*    16 */              61u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  /*    17 */              73u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  /*    18 */              30u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  /*    19 */              38u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  /*    20 */              46u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  /*    21 */              62u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  /*    22 */              74u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  /*    23 */              31u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  /*    24 */              39u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  /*    25 */              47u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  /*    26 */              63u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  /*    27 */              75u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  /*    28 */              76u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    29 */              77u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    30 */              78u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    31 */              79u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    32 */              80u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    33 */              81u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    34 */              82u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    35 */              83u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    36 */              84u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    37 */              85u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    38 */              86u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    39 */              87u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    40 */              88u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    41 */              89u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    42 */              90u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    43 */              91u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    44 */              92u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    45 */              93u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    46 */              94u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    47 */              95u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    48 */              96u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    49 */              97u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*    50 */              98u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    51 */              99u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    52 */             100u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    53 */             101u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    54 */             102u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    55 */             103u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    56 */             104u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    57 */             105u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    58 */             106u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    59 */             107u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    60 */             108u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    61 */             109u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    62 */             110u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    63 */             111u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    64 */             112u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    65 */             113u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    66 */             114u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    67 */             115u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    68 */             116u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    69 */             117u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    70 */             118u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    71 */             119u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    72 */             120u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    73 */             121u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    74 */             122u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    75 */             123u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    76 */             124u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    77 */             125u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    78 */             126u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    79 */             127u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    80 */             128u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    81 */             129u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    82 */             130u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    83 */             131u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    84 */             132u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    85 */             133u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    86 */             134u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    87 */             135u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    88 */             136u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    89 */             137u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    90 */             138u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    91 */             139u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    92 */             140u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    93 */             141u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    94 */             142u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    95 */             143u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    96 */             144u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    97 */             145u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    98 */             146u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    99 */             147u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   100 */             148u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   101 */             149u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   102 */             150u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   103 */             151u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   104 */             152u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   105 */             153u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   106 */             154u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   107 */             155u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   108 */             156u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   109 */             157u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   110 */             158u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   111 */             159u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   112 */             160u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   113 */             161u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   114 */             162u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   115 */             163u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   116 */             164u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   117 */             165u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*   118 */             166u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   119 */             167u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   120 */             168u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   121 */             169u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   122 */             170u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   123 */             171u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   124 */             172u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   125 */             173u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   126 */             174u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   127 */             175u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   128 */             176u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   129 */             177u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   130 */             178u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   131 */             179u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   132 */             180u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   133 */             181u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   134 */             182u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   135 */             183u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*   136 */             184u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   137 */             185u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   138 */             186u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   139 */             187u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   140 */             188u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   141 */             189u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   142 */             190u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   143 */             191u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   144 */             192u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   145 */             193u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   146 */             194u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   147 */             195u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   148 */             196u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   149 */             197u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   150 */             198u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   151 */             199u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   152 */             200u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   153 */             201u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*   154 */             202u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   155 */             203u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   156 */             204u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   157 */             205u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   158 */             206u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   159 */             207u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   160 */             208u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   161 */             209u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   162 */             210u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   163 */             211u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   164 */             212u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   165 */             213u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   166 */             214u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   167 */             215u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   168 */             216u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   169 */             217u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   170 */             218u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   171 */             219u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*   172 */             220u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   173 */             221u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   174 */             222u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   175 */             223u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   176 */             224u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   177 */             225u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   178 */             226u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   179 */             227u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   180 */             228u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   181 */             229u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   182 */             230u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   183 */             231u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   184 */             232u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   185 */             233u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   186 */             234u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   187 */             235u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   188 */             236u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   189 */             237u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*   190 */             238u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   191 */             239u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   192 */             240u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   193 */             241u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   194 */             242u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   195 */             243u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   196 */             244u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   197 */             245u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   198 */             246u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   199 */             247u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   200 */             248u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   201 */             249u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   202 */             250u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   203 */             251u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   204 */             252u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   205 */             253u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   206 */             254u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   207 */             255u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*   208 */             256u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   209 */             257u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   210 */             258u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   211 */             259u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   212 */             260u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   213 */             261u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   214 */             262u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   215 */             263u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   216 */             264u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   217 */             265u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   218 */             266u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   219 */             267u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   220 */             268u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   221 */             269u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   222 */             270u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   223 */             271u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   224 */             272u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   225 */             273u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*   226 */             274u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   227 */             275u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   228 */             276u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   229 */             277u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   230 */             278u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   231 */             279u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   232 */             280u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   233 */             281u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   234 */             282u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   235 */             283u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   236 */             284u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   237 */             285u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   238 */             286u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   239 */             287u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   240 */             288u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   241 */             289u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   242 */             290u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   243 */             291u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*   244 */             292u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   245 */             293u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   246 */             294u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   247 */             295u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   248 */             296u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   249 */             297u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   250 */             298u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   251 */             299u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   252 */             300u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   253 */             301u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   254 */             302u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   255 */             303u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   256 */             304u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   257 */             305u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   258 */             306u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   259 */             307u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   260 */             308u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   261 */             309u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*   262 */             310u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   263 */             311u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   264 */             312u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   265 */             313u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   266 */             314u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   267 */             315u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   268 */             316u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   269 */             317u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   270 */             318u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   271 */             319u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   272 */             320u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   273 */             321u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   274 */             322u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   275 */             323u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   276 */             324u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   277 */             325u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   278 */             326u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   279 */             327u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*   280 */             328u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   281 */             329u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   282 */             330u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   283 */             331u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   284 */             332u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   285 */             333u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   286 */             334u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   287 */             335u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   288 */             336u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   289 */             337u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   290 */             338u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   291 */             339u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   292 */             340u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   293 */             341u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   294 */             342u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   295 */             343u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   296 */             344u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   297 */             345u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*   298 */             346u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   299 */             347u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   300 */             348u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   301 */             349u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   302 */             350u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   303 */             351u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   304 */             352u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   305 */             353u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   306 */             354u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   307 */             355u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   308 */             356u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   309 */             357u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   310 */             358u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   311 */             359u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   312 */             360u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   313 */             361u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   314 */             362u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   315 */             363u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*   316 */              20u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   317 */              24u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   318 */              32u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   319 */              40u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   320 */              48u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   321 */              52u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   322 */              56u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   323 */              64u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   324 */              68u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*   325 */              21u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   326 */              25u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   327 */              33u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   328 */              41u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   329 */              49u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   330 */              53u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   331 */              57u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   332 */              65u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   333 */              69u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*   334 */              22u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   335 */              26u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   336 */              34u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   337 */              42u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   338 */              50u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   339 */              54u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   340 */              58u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   341 */              66u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   342 */              70u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*   343 */              23u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   344 */              27u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   345 */              35u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   346 */              43u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   347 */              51u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   348 */              55u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   349 */              59u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /* Index     RxAccessInfoInd      Referable Keys */
  /*   350 */              67u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   351 */              71u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*   352 */             366u,  /* [/ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx] */
  /*   353 */              10u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  /*   354 */              11u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  /*   355 */             367u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  /*   356 */              12u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  /*   357 */              16u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  /*   358 */              17u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  /*   359 */               0u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  /*   360 */               1u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  /*   361 */               2u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  /*   362 */               6u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  /*   363 */               7u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  /*   364 */               8u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  /*   365 */               9u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  /*   366 */               4u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  /*   367 */               5u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  /*   368 */             364u,  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
  /*   369 */             365u   /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
};
#define COM_STOP_SEC_CONST_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Rx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduGrpInfoType, COM_CONST) Com_RxPduGrpInfo[36] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorEndIdx  PduGrpVectorStartIdx */
  { /*     0 */                11u,                  10u },
  { /*     1 */                11u,                  10u },
  { /*     2 */                11u,                  10u },
  { /*     3 */                11u,                  10u },
  { /*     4 */                11u,                  10u },
  { /*     5 */                 7u,                   6u },
  { /*     6 */                 7u,                   6u },
  { /*     7 */                 7u,                   6u },
  { /*     8 */                 7u,                   6u },
  { /*     9 */                 7u,                   6u },
  { /*    10 */                 7u,                   6u },
  { /*    11 */                 7u,                   6u },
  { /*    12 */                 7u,                   6u },
  { /*    13 */                 7u,                   6u },
  { /*    14 */                 7u,                   6u },
  { /*    15 */                 7u,                   6u },
  { /*    16 */                 7u,                   6u },
  { /*    17 */                 7u,                   6u },
  { /*    18 */                 7u,                   6u },
  { /*    19 */                 7u,                   6u },
  { /*    20 */                 7u,                   6u },
  { /*    21 */                 7u,                   6u },
  { /*    22 */                 7u,                   6u },
  { /*    23 */                 7u,                   6u },
  { /*    24 */                 7u,                   6u },
  { /*    25 */                 3u,                   2u },
  { /*    26 */                 2u,                   1u },
  { /*    27 */                 1u,                   0u },
  { /*    28 */                 7u,                   5u },
  { /*    29 */                11u,                  10u },
  { /*    30 */                11u,                  10u },
  { /*    31 */                11u,                  10u },
  { /*    32 */                11u,                  10u },
  { /*    33 */                11u,                  10u },
  { /*    34 */                11u,                  10u },
  { /*    35 */                11u,                  10u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxPduInfo
  \brief  Contains all relevant common information for Rx I-PDUs.
  \details
  Element                   Description
  RxDefPduBufferEndIdx      the end index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxDefPduBufferStartIdx    the start index of the 0:n relation pointing to Com_RxDefPduBuffer
  RxSigInfoEndIdx           the end index of the 0:n relation pointing to Com_RxSigInfo
  RxSigInfoStartIdx         the start index of the 0:n relation pointing to Com_RxSigInfo
  RxAccessInfoIndUsed       TRUE, if the 0:n relation has 1 relation pointing to Com_RxAccessInfoInd
  Type                      Defines whether rx Pdu is a NORMAL or TP IPdu.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxPduInfoType, COM_CONST) Com_RxPduInfo[36] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxDefPduBufferEndIdx  RxDefPduBufferStartIdx  RxSigInfoEndIdx  RxSigInfoStartIdx  RxAccessInfoIndUsed  Type                              Referable Keys */
  { /*     0 */                   8u,                     0u,              1u,                0u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*     1 */                  16u,                     8u,              2u,                1u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*     2 */                  22u,                    16u,              5u,                2u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*     3 */                  26u,                    22u,              7u,                5u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*     4 */                  29u,                    26u,              8u,                7u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*     5 */                  37u,                    29u,             13u,                8u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*     6 */                  45u,                    37u,             18u,               13u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*     7 */                  53u,                    45u,             23u,               18u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*     8 */                  61u,                    53u,             28u,               23u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*     9 */                 125u,                    61u,             46u,               28u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    10 */                 189u,                   125u,             64u,               46u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    11 */                 253u,                   189u,             82u,               64u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    12 */                 317u,                   253u,            100u,               82u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    13 */                 381u,                   317u,            118u,              100u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    14 */                 445u,                   381u,            136u,              118u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    15 */                 509u,                   445u,            154u,              136u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    16 */                 573u,                   509u,            172u,              154u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    17 */                 637u,                   573u,            190u,              172u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    18 */                 701u,                   637u,            208u,              190u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    19 */                 765u,                   701u,            226u,              208u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    20 */                 829u,                   765u,            244u,              226u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    21 */                 893u,                   829u,            262u,              244u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    22 */                 957u,                   893u,            280u,              262u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    23 */                1021u,                   957u,            298u,              280u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    24 */                1085u,                  1021u,            316u,              298u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  { /*    25 */                1101u,                  1085u,            325u,              316u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a] */
  { /*    26 */                1117u,                  1101u,            334u,              325u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71] */
  { /*    27 */                1133u,                  1117u,            343u,              334u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63] */
  { /*    28 */                1149u,                  1133u,            352u,              343u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38] */
  { /*    29 */                1155u,                  1149u,            353u,              352u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*    30 */                1161u,                  1155u,            356u,              353u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*    31 */                1169u,                  1161u,            359u,              356u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*    32 */                1177u,                  1169u,            362u,              359u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*    33 */                1185u,                  1177u,            366u,              362u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*    34 */                1189u,                  1185u,            368u,              366u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  { /*    35 */                1193u,                  1189u,            370u,              368u,                TRUE, COM_NORMAL_TYPEOFRXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_RxSigInfo
  \brief  Contains all relevant information for Rx signals.
  \details
  Element             Description
  RxAccessInfoIdx     the index of the 1:1 relation pointing to Com_RxAccessInfo
  SignalProcessing
  ValidDlc            Minimum length of PDU required to completely receive the signal or signal group.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_RxSigInfoType, COM_CONST) Com_RxSigInfo[370] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*     0 */             14u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx] */
  { /*     1 */              3u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx] */
  { /*     2 */             15u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  { /*     3 */             18u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  { /*     4 */             19u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  { /*     5 */             13u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
  { /*     6 */            369u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
  { /*     7 */            368u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx] */
  { /*     8 */             28u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*     9 */             36u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    10 */             44u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    11 */             60u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    12 */             72u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  { /*    13 */             29u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    14 */             37u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    15 */             45u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    16 */             61u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    17 */             73u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  { /*    18 */             30u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    19 */             38u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    20 */             46u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    21 */             62u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    22 */             74u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  { /*    23 */             31u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    24 */             39u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    25 */             47u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    26 */             63u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    27 */             75u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  { /*    28 */             76u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    29 */             77u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    30 */             78u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    31 */             79u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    32 */             80u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    33 */             81u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    34 */             82u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    35 */             83u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    36 */             84u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    37 */             85u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    38 */             86u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    39 */             87u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    40 */             88u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    41 */             89u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    42 */             90u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    43 */             91u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    44 */             92u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    45 */             93u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  { /*    46 */             94u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    47 */             95u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    48 */             96u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    49 */             97u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*    50 */             98u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    51 */             99u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    52 */            100u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    53 */            101u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    54 */            102u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    55 */            103u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    56 */            104u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    57 */            105u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    58 */            106u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    59 */            107u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    60 */            108u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    61 */            109u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    62 */            110u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    63 */            111u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  { /*    64 */            112u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    65 */            113u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    66 */            114u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    67 */            115u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    68 */            116u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    69 */            117u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    70 */            118u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    71 */            119u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    72 */            120u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    73 */            121u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    74 */            122u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    75 */            123u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    76 */            124u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    77 */            125u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    78 */            126u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    79 */            127u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    80 */            128u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    81 */            129u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  { /*    82 */            130u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    83 */            131u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    84 */            132u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    85 */            133u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    86 */            134u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    87 */            135u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    88 */            136u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    89 */            137u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    90 */            138u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    91 */            139u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    92 */            140u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    93 */            141u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    94 */            142u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    95 */            143u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    96 */            144u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    97 */            145u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    98 */            146u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  { /*    99 */            147u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   100 */            148u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   101 */            149u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   102 */            150u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   103 */            151u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   104 */            152u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   105 */            153u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   106 */            154u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   107 */            155u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   108 */            156u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   109 */            157u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   110 */            158u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   111 */            159u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   112 */            160u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   113 */            161u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   114 */            162u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   115 */            163u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   116 */            164u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   117 */            165u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  { /*   118 */            166u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   119 */            167u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   120 */            168u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   121 */            169u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   122 */            170u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   123 */            171u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   124 */            172u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   125 */            173u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   126 */            174u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   127 */            175u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   128 */            176u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   129 */            177u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   130 */            178u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   131 */            179u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   132 */            180u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   133 */            181u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   134 */            182u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   135 */            183u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  { /*   136 */            184u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   137 */            185u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   138 */            186u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   139 */            187u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   140 */            188u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   141 */            189u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   142 */            190u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   143 */            191u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   144 */            192u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   145 */            193u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   146 */            194u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   147 */            195u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   148 */            196u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   149 */            197u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   150 */            198u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   151 */            199u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   152 */            200u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   153 */            201u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  { /*   154 */            202u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   155 */            203u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   156 */            204u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   157 */            205u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   158 */            206u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   159 */            207u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   160 */            208u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   161 */            209u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   162 */            210u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   163 */            211u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   164 */            212u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   165 */            213u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   166 */            214u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   167 */            215u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   168 */            216u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   169 */            217u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   170 */            218u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   171 */            219u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  { /*   172 */            220u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   173 */            221u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   174 */            222u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   175 */            223u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   176 */            224u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   177 */            225u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   178 */            226u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   179 */            227u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   180 */            228u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   181 */            229u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   182 */            230u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   183 */            231u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   184 */            232u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   185 */            233u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   186 */            234u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   187 */            235u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   188 */            236u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   189 */            237u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  { /*   190 */            238u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   191 */            239u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   192 */            240u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   193 */            241u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   194 */            242u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   195 */            243u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   196 */            244u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   197 */            245u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   198 */            246u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   199 */            247u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   200 */            248u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   201 */            249u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   202 */            250u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   203 */            251u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   204 */            252u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   205 */            253u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   206 */            254u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   207 */            255u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  { /*   208 */            256u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   209 */            257u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   210 */            258u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   211 */            259u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   212 */            260u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   213 */            261u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   214 */            262u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   215 */            263u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   216 */            264u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   217 */            265u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   218 */            266u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   219 */            267u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   220 */            268u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   221 */            269u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   222 */            270u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   223 */            271u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   224 */            272u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   225 */            273u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  { /*   226 */            274u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   227 */            275u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   228 */            276u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   229 */            277u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   230 */            278u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   231 */            279u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   232 */            280u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   233 */            281u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   234 */            282u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   235 */            283u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   236 */            284u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   237 */            285u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   238 */            286u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   239 */            287u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   240 */            288u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   241 */            289u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   242 */            290u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   243 */            291u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  { /*   244 */            292u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   245 */            293u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   246 */            294u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   247 */            295u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   248 */            296u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   249 */            297u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   250 */            298u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   251 */            299u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   252 */            300u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   253 */            301u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   254 */            302u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   255 */            303u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   256 */            304u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   257 */            305u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   258 */            306u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   259 */            307u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   260 */            308u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   261 */            309u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  { /*   262 */            310u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   263 */            311u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   264 */            312u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   265 */            313u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   266 */            314u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   267 */            315u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   268 */            316u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   269 */            317u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   270 */            318u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   271 */            319u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   272 */            320u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   273 */            321u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   274 */            322u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   275 */            323u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   276 */            324u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   277 */            325u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   278 */            326u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   279 */            327u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  { /*   280 */            328u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   281 */            329u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   282 */            330u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   283 */            331u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   284 */            332u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   285 */            333u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   286 */            334u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   287 */            335u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   288 */            336u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   289 */            337u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   290 */            338u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   291 */            339u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   292 */            340u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   293 */            341u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   294 */            342u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   295 */            343u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   296 */            344u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   297 */            345u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  { /*   298 */            346u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   299 */            347u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      29u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   300 */            348u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       3u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   301 */            349u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      11u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   302 */            350u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   303 */            351u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      13u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   304 */            352u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      27u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   305 */            353u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      19u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   306 */            354u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      32u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   307 */            355u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      30u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   308 */            356u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      31u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   309 */            357u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   310 */            358u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   311 */            359u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      21u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   312 */            360u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      25u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   313 */            361u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      23u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   314 */            362u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      17u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   315 */            363u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  { /*   316 */             20u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   317 */             24u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   318 */             32u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      16u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   319 */             40u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   320 */             48u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      12u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   321 */             52u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   322 */             56u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      10u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   323 */             64u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      14u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   324 */             68u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  { /*   325 */             21u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   326 */             25u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   327 */             33u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      16u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   328 */             41u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   329 */             49u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      12u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   330 */             53u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   331 */             57u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      10u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   332 */             65u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      14u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   333 */             69u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  { /*   334 */             22u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   335 */             26u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   336 */             34u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      16u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   337 */             42u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   338 */             50u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      12u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   339 */             54u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   340 */             58u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      10u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   341 */             66u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      14u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   342 */             70u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  { /*   343 */             23u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       5u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   344 */             27u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      15u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   345 */             35u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      16u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   346 */             43u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       9u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   347 */             51u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      12u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   348 */             55u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   349 */             59u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      10u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
    /* Index    RxAccessInfoIdx  SignalProcessing                          ValidDlc        Referable Keys */
  { /*   350 */             67u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,      14u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   351 */             71u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       7u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  { /*   352 */            366u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx] */
  { /*   353 */             10u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  { /*   354 */             11u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       1u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  { /*   355 */            367u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  { /*   356 */             12u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  { /*   357 */             16u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  { /*   358 */             17u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  { /*   359 */              0u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  { /*   360 */              1u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  { /*   361 */              2u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  { /*   362 */              6u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*   363 */              7u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*   364 */              8u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       6u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*   365 */              9u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       8u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  { /*   366 */              4u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  { /*   367 */              5u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  { /*   368 */            364u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       4u },  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
  { /*   369 */            365u, COM_DEFERRED_SIGNALPROCESSINGOFRXSIGINFO,       2u }   /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeFalse
**********************************************************************************************************************/
/** 
  \var    Com_TxModeFalse
  \brief  Contains all relevant information for transmission mode false.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeFalseType, COM_CONST) Com_TxModeFalse[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic  TimePeriod        Referable Keys */
  { /*     0 */     TRUE,         1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*     1 */     TRUE,        15u }   /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxModeInfo
  \brief  Contains all relevant information for transmission mode handling.
  \details
  Element          Description
  InitMode         Initial transmission mode selector of the Tx I-PDU.
  MinimumDelay     Minimum delay factor of the Tx I-PDU.
  TxModeTrueIdx    the index of the 1:1 relation pointing to Com_TxModeTrue
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeInfoType, COM_CONST) Com_TxModeInfo[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    InitMode  MinimumDelay  TxModeTrueIdx        Referable Keys */
  { /*     0 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  { /*     1 */     TRUE,           2u,            0u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  { /*     2 */     TRUE,           2u,            0u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  { /*     3 */     TRUE,           2u,            0u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  { /*     4 */     TRUE,           2u,            0u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*     5 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*     6 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*     7 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*     8 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*     9 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*    10 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*    11 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*    12 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*    13 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*    14 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*    15 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*    16 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    17 */     TRUE,           2u,            1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    18 */     TRUE,           2u,            1u }   /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxModeTrue
**********************************************************************************************************************/
/** 
  \var    Com_TxModeTrue
  \brief  Contains all relevant information for transmission mode true.
  \details
  Element       Description
  Periodic      TRUE if transmission mode contains a cyclic part.
  TimePeriod    Cycle time factor.
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxModeTrueType, COM_CONST) Com_TxModeTrue[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    Periodic  TimePeriod        Referable Keys */
  { /*     0 */     TRUE,         1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*     1 */     TRUE,        15u }   /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpInfo
  \brief  Contains all I-PDU-Group relevant information for Tx I-PDUs.
  \details
  Element                 Description
  PduGrpVectorEndIdx      the end index of the 0:n relation pointing to Com_PduGrpVector
  PduGrpVectorStartIdx    the start index of the 0:n relation pointing to Com_PduGrpVector
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduGrpInfoType, COM_CONST) Com_TxPduGrpInfo[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    PduGrpVectorEndIdx  PduGrpVectorStartIdx */
  { /*     0 */                 9u,                   8u },
  { /*     1 */                 5u,                   4u },
  { /*     2 */                 4u,                   3u },
  { /*     3 */                11u,                   9u },
  { /*     4 */                 9u,                   7u },
  { /*     5 */                 9u,                   8u },
  { /*     6 */                 9u,                   8u },
  { /*     7 */                 9u,                   8u },
  { /*     8 */                 9u,                   8u },
  { /*     9 */                 9u,                   8u },
  { /*    10 */                 9u,                   8u },
  { /*    11 */                 9u,                   8u },
  { /*    12 */                 9u,                   8u },
  { /*    13 */                 9u,                   8u },
  { /*    14 */                 9u,                   8u },
  { /*    15 */                 9u,                   8u },
  { /*    16 */                 9u,                   8u },
  { /*    17 */                 9u,                   8u },
  { /*    18 */                 9u,                   8u }
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInfo
  \brief  Contains all relevant information for Tx I-PDUs.
  \details
  Element                    Description
  TxPduInitValueEndIdx       the end index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueStartIdx     the start index of the 0:n relation pointing to Com_TxPduInitValue
  TxPduInitValueUsed         TRUE, if the 0:n relation has 1 relation pointing to Com_TxPduInitValue
  MetaDataLength             Length of MetaData.
  TxBufferLength             the number of relations pointing to Com_TxBuffer
  TxSigGrpInfoIndEndIdx      the end index of the 0:n relation pointing to Com_TxSigGrpInfoInd
  TxSigGrpInfoIndStartIdx    the start index of the 0:n relation pointing to Com_TxSigGrpInfoInd
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInfoType, COM_CONST) Com_TxPduInfo[19] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxPduInitValueEndIdx  TxPduInitValueStartIdx  TxPduInitValueUsed  MetaDataLength  TxBufferLength  TxSigGrpInfoIndEndIdx                    TxSigGrpInfoIndStartIdx                          Referable Keys */
  { /*     0 */                  64u,                     0u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*     1 */                  72u,                    64u,               TRUE,             0u,             8u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  { /*     2 */                  80u,                    72u,               TRUE,             0u,             8u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  { /*     3 */                  88u,                    80u,               TRUE,             0u,             8u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  { /*     4 */                  96u,                    88u,               TRUE,             0u,             8u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  { /*     5 */                 112u,                    96u,               TRUE,             0u,            16u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*     6 */                 128u,                   112u,               TRUE,             0u,            16u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*     7 */                 144u,                   128u,               TRUE,             0u,            16u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*     8 */                 160u,                   144u,               TRUE,             0u,            16u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*     9 */                 224u,                   160u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    10 */                 288u,                   224u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    11 */                 352u,                   288u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    12 */                 416u,                   352u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    13 */                 480u,                   416u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    14 */                 544u,                   480u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    15 */                 608u,                   544u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO },  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    16 */                 672u,                   608u,               TRUE,             0u,            64u,                                      1u,                                        0u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    17 */                 736u,                   672u,               TRUE,             0u,            64u,                                      2u,                                        1u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  { /*    18 */                 800u,                   736u,               TRUE,             0u,            64u, COM_NO_TXSIGGRPINFOINDENDIDXOFTXPDUINFO, COM_NO_TXSIGGRPINFOINDSTARTIDXOFTXPDUINFO }   /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduInitValue
**********************************************************************************************************************/
/** 
  \var    Com_TxPduInitValue
  \brief  Initial values used for Tx I-PDU buffer initialization.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxPduInitValueType, COM_CONST) Com_TxPduInitValue[800] = {  /* PRQA S 1514, 1533, 0612 */  /* MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_BigStructure */
  /* Index     TxPduInitValue      Referable Keys */
  /*     0 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     1 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     2 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     3 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     4 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     5 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     6 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     7 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     8 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*     9 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    10 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    11 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    12 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    13 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    14 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    15 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    16 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    17 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    18 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    19 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    20 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    21 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    22 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    23 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    24 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    25 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    26 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    27 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    28 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    29 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    30 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    31 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    32 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    33 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    34 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    35 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    36 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    37 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    38 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    39 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    40 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    41 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    42 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    43 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    44 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    45 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    46 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    47 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    48 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    49 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*    50 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    51 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    52 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    53 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    54 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    55 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    56 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    57 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    58 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    59 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    60 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    61 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    62 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    63 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    64 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    65 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    66 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    67 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    68 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    69 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    70 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    71 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  /*    72 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    73 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    74 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    75 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    76 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    77 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    78 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    79 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  /*    80 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    81 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    82 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    83 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    84 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    85 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    86 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    87 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  /*    88 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    89 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    90 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    91 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    92 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    93 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    94 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    95 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  /*    96 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*    97 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*    98 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*    99 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   100 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   101 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   102 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   103 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   104 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   105 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   106 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   107 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   108 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   109 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   110 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   111 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  /*   112 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   113 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   114 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   115 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   116 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   117 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   118 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   119 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   120 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   121 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   122 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   123 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   124 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   125 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   126 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   127 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  /*   128 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   129 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   130 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   131 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   132 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   133 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   134 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   135 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   136 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   137 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   138 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   139 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   140 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   141 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   142 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   143 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  /*   144 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   145 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   146 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   147 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   148 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   149 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   150 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   151 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   152 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   153 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   154 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   155 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   156 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   157 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   158 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   159 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  /*   160 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   161 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   162 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   163 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   164 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   165 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   166 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   167 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   168 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   169 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   170 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   171 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   172 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   173 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   174 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   175 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   176 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   177 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   178 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   179 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   180 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   181 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   182 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   183 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   184 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   185 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   186 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   187 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   188 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   189 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   190 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   191 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   192 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   193 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   194 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   195 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   196 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   197 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   198 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   199 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   200 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   201 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   202 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   203 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   204 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   205 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   206 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   207 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   208 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   209 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   210 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   211 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   212 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   213 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   214 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   215 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   216 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   217 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   218 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   219 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   220 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   221 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   222 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   223 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   224 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   225 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   226 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   227 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   228 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   229 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   230 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   231 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   232 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   233 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   234 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   235 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   236 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   237 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   238 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   239 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   240 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   241 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   242 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   243 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   244 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   245 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   246 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   247 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   248 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   249 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   250 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   251 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   252 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   253 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   254 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   255 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   256 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   257 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   258 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   259 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   260 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   261 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   262 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   263 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   264 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   265 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   266 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   267 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   268 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   269 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   270 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   271 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   272 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   273 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   274 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   275 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   276 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   277 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   278 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   279 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   280 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   281 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   282 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   283 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   284 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   285 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   286 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   287 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   288 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   289 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   290 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   291 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   292 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   293 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   294 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   295 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   296 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   297 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   298 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   299 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   300 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   301 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   302 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   303 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   304 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   305 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   306 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   307 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   308 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   309 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   310 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   311 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   312 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   313 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   314 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   315 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   316 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   317 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   318 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   319 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   320 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   321 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   322 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   323 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   324 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   325 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   326 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   327 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   328 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   329 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   330 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   331 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   332 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   333 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   334 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   335 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   336 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   337 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   338 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   339 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   340 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   341 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   342 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   343 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   344 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   345 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   346 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   347 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   348 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   349 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   350 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   351 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   352 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   353 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   354 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   355 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   356 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   357 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   358 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   359 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   360 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   361 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   362 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   363 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   364 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   365 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   366 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   367 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   368 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   369 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   370 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   371 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   372 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   373 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   374 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   375 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   376 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   377 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   378 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   379 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   380 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   381 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   382 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   383 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   384 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   385 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   386 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   387 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   388 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   389 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   390 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   391 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   392 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   393 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   394 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   395 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   396 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   397 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   398 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   399 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   400 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   401 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   402 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   403 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   404 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   405 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   406 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   407 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   408 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   409 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   410 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   411 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   412 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   413 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   414 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   415 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   416 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   417 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   418 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   419 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   420 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   421 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   422 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   423 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   424 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   425 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   426 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   427 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   428 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   429 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   430 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   431 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   432 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   433 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   434 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   435 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   436 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   437 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   438 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   439 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   440 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   441 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   442 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   443 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   444 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   445 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   446 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   447 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   448 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   449 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   450 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   451 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   452 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   453 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   454 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   455 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   456 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   457 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   458 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   459 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   460 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   461 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   462 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   463 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   464 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   465 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   466 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   467 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   468 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   469 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   470 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   471 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   472 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   473 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   474 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   475 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   476 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   477 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   478 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   479 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   480 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   481 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   482 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   483 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   484 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   485 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   486 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   487 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   488 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   489 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   490 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   491 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   492 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   493 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   494 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   495 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   496 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   497 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   498 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   499 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   500 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   501 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   502 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   503 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   504 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   505 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   506 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   507 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   508 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   509 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   510 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   511 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   512 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   513 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   514 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   515 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   516 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   517 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   518 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   519 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   520 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   521 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   522 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   523 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   524 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   525 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   526 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   527 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   528 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   529 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   530 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   531 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   532 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   533 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   534 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   535 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   536 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   537 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   538 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   539 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   540 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   541 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   542 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   543 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   544 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   545 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   546 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   547 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   548 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   549 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   550 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   551 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   552 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   553 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   554 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   555 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   556 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   557 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   558 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   559 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   560 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   561 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   562 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   563 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   564 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   565 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   566 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   567 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   568 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   569 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   570 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   571 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   572 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   573 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   574 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   575 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   576 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   577 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   578 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   579 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   580 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   581 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   582 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   583 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   584 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   585 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   586 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   587 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   588 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   589 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   590 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   591 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   592 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   593 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   594 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   595 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   596 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   597 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   598 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   599 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   600 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   601 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   602 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   603 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   604 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   605 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   606 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   607 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   608 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   609 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   610 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   611 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   612 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   613 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   614 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   615 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   616 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   617 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   618 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   619 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   620 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   621 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   622 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   623 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   624 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   625 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   626 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   627 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   628 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   629 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   630 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   631 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   632 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   633 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   634 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   635 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   636 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   637 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   638 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   639 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   640 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   641 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   642 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   643 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   644 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   645 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   646 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   647 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   648 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   649 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   650 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   651 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   652 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   653 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   654 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   655 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   656 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   657 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   658 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   659 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   660 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   661 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   662 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   663 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   664 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   665 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   666 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   667 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   668 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   669 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   670 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   671 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   672 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   673 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   674 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   675 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   676 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   677 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   678 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   679 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   680 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   681 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   682 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   683 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   684 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   685 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   686 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   687 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   688 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   689 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   690 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   691 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   692 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   693 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   694 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   695 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   696 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   697 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   698 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   699 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   700 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   701 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   702 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   703 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   704 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   705 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   706 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   707 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   708 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   709 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   710 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   711 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   712 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   713 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   714 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   715 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   716 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   717 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   718 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   719 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   720 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   721 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   722 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   723 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   724 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   725 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   726 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   727 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   728 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   729 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   730 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   731 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   732 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   733 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   734 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   735 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   736 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   737 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   738 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   739 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   740 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   741 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   742 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   743 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   744 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   745 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   746 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   747 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   748 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   749 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /* Index     TxPduInitValue      Referable Keys */
  /*   750 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   751 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   752 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   753 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   754 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   755 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   756 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   757 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   758 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   759 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   760 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   761 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   762 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   763 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   764 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   765 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   766 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   767 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   768 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   769 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   770 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   771 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   772 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   773 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   774 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   775 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   776 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   777 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   778 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   779 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   780 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   781 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   782 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   783 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   784 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   785 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   786 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   787 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   788 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   789 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   790 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   791 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   792 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   793 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   794 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   795 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   796 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   797 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   798 */           0x00u,  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   799 */           0x00u   /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpInfo
  \brief  Contains all relevant information for Tx Signal Groups.
  \details
  Element                           Description
  TxBufferSigGrpInTxIPDUStartIdx    the start index of the 1:n relation pointing to Com_TxBuffer
  TxBufferStartIdx                  the start index of the 0:n relation pointing to Com_TxBuffer
  TxSigGrpMaskUsed                  TRUE, if the 0:n relation has 1 relation pointing to Com_TxSigGrpMask
  TransferProperty              
  TxBufferSigGrpInTxIPDULength      the number of relations pointing to Com_TxBuffer
  TxSigGrpMaskStartIdx              the start index of the 0:n relation pointing to Com_TxSigGrpMask
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigGrpInfoType, COM_CONST) Com_TxSigGrpInfo[2] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    TxBufferSigGrpInTxIPDUStartIdx  TxBufferStartIdx  TxSigGrpMaskUsed  TransferProperty                            TxBufferSigGrpInTxIPDULength  TxSigGrpMaskStartIdx        Referable Keys */
  { /*     0 */                           608u,             800u,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                          58u,                   0u },  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL3_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9e1f9c46_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL2_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3d89b40a_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_CRC_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_31745b74_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Counter_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_5e38a8f5_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_AngleRate_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9378dbfb_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL1_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0242ca9f_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Power_Diag_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_70e35f64_Tx] */
  { /*     1 */                           672u,             858u,             TRUE, COM_PENDING_TRANSFERPROPERTYOFTXSIGGRPINFO,                          58u,                  57u }   /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL5_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_1ae4a5b3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_CRC_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_ca199fab_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_Counter_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a5556c2a_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL3_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_65725899_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL4_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b9728dff_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL1_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_f92f0e40_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL2_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_c6e470d5_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigGrpMask
**********************************************************************************************************************/
/** 
  \var    Com_TxSigGrpMask
  \brief  Signal group mask needed to copy interlaced signal groups to the Tx PDU buffer.
*/ 
#define COM_START_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigGrpMaskType, COM_CONST) Com_TxSigGrpMask[115] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index     TxSigGrpMask      Referable Keys */
  /*     0 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     1 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     2 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     3 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     4 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     5 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     6 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     7 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     8 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*     9 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    10 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    11 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    12 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    13 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    14 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    15 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    16 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    17 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    18 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    19 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    20 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    21 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    22 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    23 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    24 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    25 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    26 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    27 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    28 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    29 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    30 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    31 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    32 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    33 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    34 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    35 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    36 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    37 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    38 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    39 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    40 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    41 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    42 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    43 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    44 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    45 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    46 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    47 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    48 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    49 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /* Index     TxSigGrpMask      Referable Keys */
  /*    50 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    51 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    52 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    53 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    54 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    55 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    56 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*    57 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    58 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    59 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    60 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    61 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    62 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    63 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    64 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    65 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    66 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    67 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    68 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    69 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    70 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    71 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    72 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    73 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    74 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    75 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    76 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    77 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    78 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    79 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    80 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    81 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    82 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    83 */         0x0Fu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    84 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    85 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    86 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    87 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    88 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    89 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    90 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    91 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    92 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    93 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    94 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    95 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    96 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    97 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    98 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*    99 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /* Index     TxSigGrpMask      Referable Keys */
  /*   100 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   101 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   102 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   103 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   104 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   105 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   106 */         0xFFu,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   107 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   108 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   109 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   110 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   111 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   112 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   113 */         0x00u,  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   114 */         0xFFu   /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
};
#define COM_STOP_SEC_CONST_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSigInfo
**********************************************************************************************************************/
/** 
  \var    Com_TxSigInfo
  \brief  Contains all relevant information for Tx signals and group signals.
  \details
  Element                   Description
  BitPosition               Little endian bit position of the signal or group signal within the I-PDU.
  TxBufferEndIdx            the end index of the 0:n relation pointing to Com_TxBuffer
  TxBufferStartIdx          the start index of the 0:n relation pointing to Com_TxBuffer
  ApplType                  Application data type.
  BitLength                 Bit length of the signal or group signal.
  BusAcc                    BUS access algorithm for signal or group signal packing / un-packing.
  ByteLength                Byte length of the signal or group signal.
  StartByteInPduPosition    Start Byte position of the signal or group signal within the I-PDU.
  TxPduInfoIdx              the index of the 1:1 relation pointing to Com_TxPduInfo
  TxSigGrpInfoIdx           the index of the 0:1 relation pointing to Com_TxSigGrpInfo
*/ 
#define COM_START_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
CONST(Com_TxSigInfoType, COM_CONST) Com_TxSigInfo[242] = {  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
    /* Index    BitPosition  TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BusAcc                             ByteLength  StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*     0 */          0u,           801u,             800u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_CRC_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_31745b74_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     1 */          8u,           802u,             801u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4u,        COM_NBIT_BUSACCOFTXSIGINFO,         0u,                     1u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Counter_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_5e38a8f5_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     2 */        352u,           849u,             844u, COM_UINT8_N_APPLTYPEOFTXSIGINFO,       40u, COM_ARRAY_BASED_BUSACCOFTXSIGINFO,         5u,                    44u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL1_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0242ca9f_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     3 */        392u,           850u,             849u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    49u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL2_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3d89b40a_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     4 */        456u,           858u,             857u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    57u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL3_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9e1f9c46_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     5 */        224u,           830u,             828u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    28u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     6 */        212u,           828u,             826u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    26u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     7 */        140u,           819u,             817u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    17u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     8 */        152u,           821u,             819u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    19u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*     9 */        164u,           822u,             820u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    20u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    10 */        176u,           824u,             822u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    22u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    11 */        344u,           844u,             843u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    43u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Power_Diag_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_70e35f64_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    12 */        248u,           833u,             831u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    31u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    13 */        272u,           836u,             834u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    34u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    14 */        296u,           839u,             837u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    37u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    15 */        320u,           842u,             840u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    40u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    16 */        236u,           831u,             829u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    29u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    17 */        260u,           834u,             832u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    32u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    18 */        284u,           837u,             835u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    35u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    19 */        308u,           840u,             838u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    38u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    20 */        332u,           843u,             841u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    41u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_AngleRate_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9378dbfb_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    21 */        188u,           825u,             823u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    23u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    22 */        200u,           827u,             825u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       12u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    25u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    23 */         12u,           804u,             801u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     1u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    24 */         28u,           806u,             803u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     3u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    25 */         44u,           808u,             805u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     5u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    26 */         60u,           810u,             807u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     7u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    27 */         76u,           812u,             809u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     9u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    28 */         92u,           814u,             811u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    11u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    29 */        108u,           816u,             813u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    13u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    30 */        124u,           818u,             815u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    15u,          16u,                                0u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  { /*    31 */         44u,           866u,             863u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     5u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    32 */        188u,           884u,             881u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    23u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    33 */        156u,           880u,             877u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    19u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    34 */         12u,           862u,             859u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     1u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    35 */        172u,           882u,             879u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    21u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    36 */        124u,           876u,             873u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    15u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    37 */         76u,           870u,             867u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     9u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    38 */        108u,           874u,             871u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    13u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    39 */         60u,           868u,             865u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     7u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    40 */         28u,           864u,             861u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     3u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    41 */        140u,           878u,             875u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    17u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    42 */         92u,           872u,             869u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                    11u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    43 */          0u,           859u,             858u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_CRC_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_ca199fab_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    44 */          8u,           860u,             859u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        4u,        COM_NBIT_BUSACCOFTXSIGINFO,         0u,                     1u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_Counter_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a5556c2a_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    45 */        204u,           885u,             883u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         1u,                    25u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL1_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_f92f0e40_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    46 */        264u,           892u,             891u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    33u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL2_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_c6e470d5_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    47 */        328u,           900u,             899u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    41u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL3_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_65725899_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    48 */        392u,           908u,             907u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    49u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL4_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b9728dff_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  { /*    49 */        456u,           916u,             915u,  COM_UINT64_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    57u,          17u,                                1u },  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL5_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_1ae4a5b3_Tx, /ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
    /* Index    BitPosition  TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BusAcc                             ByteLength  StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*    50 */          0u,             3u,               0u,  COM_UINT32_APPLTYPEOFTXSIGINFO,       18u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     0u,           0u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_d3a8bf7b_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  { /*    51 */         18u,             5u,               2u,  COM_UINT32_APPLTYPEOFTXSIGINFO,       18u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     2u,           0u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_b9c3726a_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  { /*    52 */         36u,             7u,               4u,  COM_UINT32_APPLTYPEOFTXSIGINFO,       18u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     4u,           0u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_29ebcf6e_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  { /*    53 */         54u,             9u,               6u,  COM_UINT32_APPLTYPEOFTXSIGINFO,       18u,   COM_NBITNBYTE_BUSACCOFTXSIGINFO,         2u,                     6u,           0u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_4380027f_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  { /*    54 */          8u,           101u,              97u, COM_FLOAT32_APPLTYPEOFTXSIGINFO,       32u,       COM_NBYTE_BUSACCOFTXSIGINFO,         4u,                     1u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_6a00d445_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    55 */          8u,           117u,             113u, COM_FLOAT32_APPLTYPEOFTXSIGINFO,       32u,       COM_NBYTE_BUSACCOFTXSIGINFO,         4u,                     1u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ec6aae44_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    56 */          8u,           133u,             129u, COM_FLOAT32_APPLTYPEOFTXSIGINFO,       32u,       COM_NBYTE_BUSACCOFTXSIGINFO,         4u,                     1u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_862e4532_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    57 */          8u,           149u,             145u, COM_FLOAT32_APPLTYPEOFTXSIGINFO,       32u,       COM_NBYTE_BUSACCOFTXSIGINFO,         4u,                     1u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_00443f33_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    58 */        112u,           111u,             110u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    14u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_8e197ec3_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    59 */        112u,           127u,             126u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    14u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_087304c2_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    60 */        112u,           143u,             142u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    14u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_6237efb4_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    61 */        112u,           159u,             158u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    14u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_e45d95b5_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    62 */         56u,            72u,              71u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,           1u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  { /*    63 */         56u,            80u,              79u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,           2u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  { /*    64 */         56u,            88u,              87u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,           3u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  { /*    65 */         56u,            96u,              95u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,           4u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*    66 */        120u,           112u,             111u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    15u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9217127b_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    67 */        120u,           128u,             127u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    15u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_147d687a_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    68 */        120u,           144u,             143u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    15u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_7e39830c_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    69 */        120u,           160u,             159u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    15u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f853f90d_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    70 */          0u,            66u,              64u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     0u,           1u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_dda52c0a_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  { /*    71 */          0u,            74u,              72u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     0u,           2u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_733b337f_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  { /*    72 */          0u,            82u,              80u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     0u,           3u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_e2db3ec2_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  { /*    73 */          0u,            90u,              88u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     0u,           4u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_4c4521b7_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*    74 */         56u,           105u,             103u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     7u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_4a62e4d4_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    75 */         56u,           121u,             119u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     7u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_cc089ed5_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    76 */         56u,           137u,             135u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     7u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_a64c75a3_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    77 */         56u,           153u,             151u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     7u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_20260fa2_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    78 */         16u,            68u,              66u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     2u,           1u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_4c2f58b5_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  { /*    79 */         16u,            76u,              74u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     2u,           2u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_e2b147c0_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  { /*    80 */         16u,            84u,              82u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     2u,           3u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_73514a7d_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  { /*    81 */         16u,            92u,              90u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     2u,           4u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ddcf5508_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*    82 */         80u,           108u,             106u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    10u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_1fde2ef8_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    83 */         80u,           124u,             122u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    10u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_99b454f9_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    84 */         80u,           140u,             138u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    10u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_f3f0bf8f_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    85 */         80u,           156u,             154u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    10u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_759ac58e_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    86 */          0u,            97u,              96u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_0b4ed38b_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    87 */          0u,           113u,             112u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_8d24a98a_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    88 */          0u,           129u,             128u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_e76042fc_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    89 */          0u,           145u,             144u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_610a38fd_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    90 */         72u,           106u,             105u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9b045378_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    91 */         72u,           122u,             121u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_1d6e2979_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*    92 */         72u,           138u,             137u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_772ac20f_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*    93 */         72u,           154u,             153u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f140b80e_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*    94 */         32u,            70u,              68u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     4u,           1u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_cc22eb0f_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  { /*    95 */         32u,            78u,              76u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     4u,           2u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_62bcf47a_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  { /*    96 */         32u,            86u,              84u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     4u,           3u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_f35cf9c7_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  { /*    97 */         32u,            94u,              92u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     4u,           4u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_5dc2e6b2_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*    98 */         96u,           110u,             108u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    12u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_e3458dbb_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*    99 */         96u,           126u,             124u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    12u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_652ff7ba_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
    /* Index    BitPosition  TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BusAcc                             ByteLength  StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*   100 */         96u,           142u,             140u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    12u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_0f6b1ccc_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*   101 */         96u,           158u,             156u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                    12u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_890166cd_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*   102 */         40u,           103u,             101u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     5u,           5u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_2be51499_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx] */
  { /*   103 */         40u,           119u,             117u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     5u,           6u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ad8f6e98_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx] */
  { /*   104 */         40u,           135u,             133u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     5u,           7u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_c7cb85ee_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx] */
  { /*   105 */         40u,           151u,             149u,  COM_UINT16_APPLTYPEOFTXSIGINFO,       16u,       COM_NBYTE_BUSACCOFTXSIGINFO,         2u,                     5u,           8u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_41a1ffef_Tx, /ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx] */
  { /*   106 */         48u,            71u,              70u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,           1u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_f43eb050_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx] */
  { /*   107 */         48u,            79u,              78u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,           2u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_5aa0af25_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx] */
  { /*   108 */         48u,            87u,              86u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,           3u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_cb40a298_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx] */
  { /*   109 */         48u,            95u,              94u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,           4u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_65debded_Tx, /ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx] */
  { /*   110 */         24u,           164u,             163u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_35deee4a_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   111 */         16u,           163u,             162u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_75935422_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   112 */         96u,           237u,             236u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_DCDC_HS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_aa37a69c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   113 */        104u,           238u,             237u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_DCDC_LS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_4342bfe7_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   114 */          0u,           161u,             160u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_9bb393fa_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   115 */          8u,           162u,             161u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_64dd9785_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   116 */          0u,           225u,             224u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_HS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_dc7f0e1c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   117 */          8u,           226u,             225u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_HS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_f6c3be94_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   118 */         16u,           227u,             226u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_LS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_350a1767_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   119 */         24u,           228u,             227u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_LS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_1fb6a7ef_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   120 */         32u,           229u,             228u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_HS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_27ff6475_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   121 */         40u,           230u,             229u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_HS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ddc29722_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   122 */         48u,           231u,             230u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_LS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ce8a7d0e_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   123 */         56u,           232u,             231u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_LS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_34b78e59_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   124 */         64u,           233u,             232u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_HS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_58ae3d07_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   125 */         72u,           234u,             233u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_HS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_72128d8f_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   126 */         80u,           235u,             234u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_LS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_b1db247c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   127 */         88u,           236u,             235u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,          10u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_LS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_9b6794f4_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  { /*   128 */         32u,           165u,             164u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_7f47993e_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   129 */         40u,           166u,             165u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_f5c9f897_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   130 */         96u,           301u,             300u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_DCDC_HS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_964be8d5_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   131 */        104u,           302u,             301u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_DCDC_LS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_7f3ef1ae_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   132 */         48u,           167u,             166u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_cc91bfa8_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   133 */         56u,           168u,             167u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_5b16e910_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   134 */          0u,           289u,             288u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_HS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ad20fc3f_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   135 */          8u,           290u,             289u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_HS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_879c4cb7_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   136 */         16u,           291u,             290u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_LS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_4455e544_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   137 */         24u,           292u,             291u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_LS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_6ee955cc_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   138 */         32u,           293u,             292u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_HS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_02f0e692_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   139 */         40u,           294u,             293u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_HS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_f8cd15c5_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   140 */         48u,           295u,             294u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_LS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_eb85ffe9_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   141 */         56u,           296u,             295u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_LS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_11b80cbe_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   142 */         64u,           297u,             296u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_HS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_29f1cf24_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   143 */         72u,           298u,             297u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_HS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_034d7fac_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   144 */         80u,           299u,             298u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_LS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_c084d65f_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   145 */         88u,           300u,             299u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,          11u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_LS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ea3866d7_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  { /*   146 */         64u,           169u,             168u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_f01fb62d_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   147 */         72u,           170u,             169u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_8a006304_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   148 */         96u,           365u,             364u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_DCDC_HS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_82602d12_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   149 */        104u,           366u,             365u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_DCDC_LS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b153469_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
    /* Index    BitPosition  TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BusAcc                             ByteLength  StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*   150 */         80u,           171u,             170u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_48a0a659_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   151 */         88u,           172u,             171u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_f880c15c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   152 */          0u,           353u,             352u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_HS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_8215adde_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   153 */          8u,           354u,             353u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_HS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a8a91d56_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   154 */         16u,           355u,             354u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_LS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b60b4a5_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   155 */         24u,           356u,             355u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_LS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_41dc042d_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   156 */         32u,           357u,             356u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_HS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_5b05e36e_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   157 */         40u,           358u,             357u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_HS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a1381039_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   158 */         48u,           359u,             358u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_LS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_b270fa15_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   159 */         56u,           360u,             359u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_LS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_484d0942_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   160 */         64u,           361u,             360u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_HS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_2454ba1c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   161 */         72u,           362u,             361u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_HS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_0ee80a94_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   162 */         80u,           363u,             362u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_LS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_cd21a367_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   163 */         88u,           364u,             363u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,          12u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_LS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_e79d13ef_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  { /*   164 */         96u,           173u,             172u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_ea7577d6_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   165 */        104u,           174u,             173u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_2e0da7bc_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   166 */         96u,           429u,             428u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_DCDC_HS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_eeb37447_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   167 */        104u,           430u,             429u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_DCDC_LS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_07c66d3c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   168 */        112u,           175u,             174u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    14u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_62d5e70c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   169 */        120u,           176u,             175u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    15u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_2480143a_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   170 */          0u,           417u,             416u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_HS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_3529bf8d_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   171 */          8u,           418u,             417u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_HS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_1f950f05_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   172 */         16u,           419u,             418u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_LS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_dc5ca6f6_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   173 */         24u,           420u,             419u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_LS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_f6e0167e_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   174 */         32u,           421u,             420u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_HS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9af9a520_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   175 */         40u,           422u,             421u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_HS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_60c45677_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   176 */         48u,           423u,             422u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_LS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_738cbc5b_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   177 */         56u,           424u,             423u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_LS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_89b14f0c_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   178 */         64u,           425u,             424u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_HS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_b1f88c96_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   179 */         72u,           426u,             425u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_HS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9b443c1e_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   180 */         80u,           427u,             426u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_LS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_588d95ed_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   181 */         88u,           428u,             427u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,          13u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_LS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_72312565_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  { /*   182 */        128u,           177u,             176u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    16u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_652d58c5_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   183 */        136u,           178u,             177u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    17u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_51c43c2f_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   184 */         96u,           493u,             492u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_DCDC_HS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_fa98b180_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   185 */        104u,           494u,             493u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_DCDC_LS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_13eda8fb_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   186 */        144u,           179u,             178u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    18u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_e6e4fefd_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   187 */        152u,           180u,             179u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    19u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_87163c76_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   188 */          0u,           481u,             480u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_HS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_b9eee1f2_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   189 */          8u,           482u,             481u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_HS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_9352517a_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   190 */         16u,           483u,             482u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_LS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_509bf889_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   191 */         24u,           484u,             483u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_LS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7a274801_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   192 */         32u,           485u,             484u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_HS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_eace6a13_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   193 */         40u,           486u,             485u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_HS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_10f39944_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   194 */         48u,           487u,             486u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_LS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_03bb7368_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   195 */         56u,           488u,             487u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_LS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_f986803f_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   196 */         64u,           489u,             488u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_HS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_959f3361_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   197 */         72u,           490u,             489u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_HS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_bf2383e9_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   198 */         80u,           491u,             490u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_LS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7cea2a1a_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  { /*   199 */         88u,           492u,             491u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,          14u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_LS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_56569a92_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
    /* Index    BitPosition  TxBufferEndIdx  TxBufferStartIdx  ApplType                         BitLength  BusAcc                             ByteLength  StartByteInPduPosition  TxPduInfoIdx  TxSigGrpInfoIdx                          Referable Keys */
  { /*   200 */        160u,           181u,             180u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    20u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_2fb42fb1_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   201 */        168u,           182u,             181u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    21u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_d19e909a_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   202 */         32u,           549u,             548u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          15u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_DCDC_HS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_c6e4ffc9_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*   203 */         40u,           550u,             549u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          15u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_DCDC_LS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_2f91e6b2_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*   204 */        176u,           183u,             182u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    22u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_b1c6d2af_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   205 */        184u,           184u,             183u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    23u,           9u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_b8dd42e3_Tx, /ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  { /*   206 */          0u,           545u,             544u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          15u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_HS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_f7d60532_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*   207 */          8u,           546u,             545u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          15u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_HS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd6ab5ba_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*   208 */         16u,           547u,             546u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          15u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_LS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_1ea31c49_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*   209 */         24u,           548u,             547u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          15u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_LS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_341facc1_Tx, /ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  { /*   210 */          8u,           738u,             737u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     1u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_0bdb9dd5_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   211 */          0u,           737u,             736u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     0u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_8ece5c4e_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   212 */         24u,           740u,             739u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     3u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_75a3d573_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   213 */         16u,           739u,             738u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     2u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_f0b614e8_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   214 */         40u,           742u,             741u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     5u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_5f8bed11_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   215 */         32u,           741u,             740u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     4u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_da9e2c8a_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   216 */         56u,           744u,             743u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     7u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_8953443f_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   217 */         48u,           743u,             742u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     6u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_0c4685a4_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   218 */         72u,           746u,             745u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     9u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_a37b7c5d_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   219 */         64u,           745u,             744u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                     8u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_266ebdc6_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   220 */         88u,           748u,             747u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    11u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_dd0334fb_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   221 */         80u,           747u,             746u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    10u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_5816f560_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   222 */        104u,           750u,             749u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    13u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_f72b0c99_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   223 */         96u,           749u,             748u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    12u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_723ecd02_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   224 */        120u,           752u,             751u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    15u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_abc360e6_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   225 */        112u,           751u,             750u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    14u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_2ed6a17d_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   226 */        136u,           754u,             753u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    17u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_81eb5884_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   227 */        128u,           753u,             752u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    16u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_04fe991f_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   228 */        152u,           756u,             755u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    19u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_b49ae336_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   229 */        144u,           755u,             754u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    18u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_318f22ad_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   230 */        168u,           758u,             757u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    21u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_9eb2db54_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   231 */        160u,           757u,             756u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    20u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_1ba71acf_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   232 */        184u,           760u,             759u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    23u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_e0ca93f2_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   233 */        176u,           759u,             758u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    22u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_65df5269_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   234 */        200u,           762u,             761u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    25u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_cae2ab90_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   235 */        192u,           761u,             760u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    24u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_4ff76a0b_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   236 */        216u,           764u,             763u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    27u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_1c3a02be_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   237 */        208u,           763u,             762u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    26u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_992fc325_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   238 */        232u,           766u,             765u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    29u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_36123adc_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   239 */        224u,           765u,             764u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    28u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_b307fb47_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   240 */        248u,           768u,             767u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    31u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO },  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_486a727a_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  { /*   241 */        240u,           767u,             766u,   COM_UINT8_APPLTYPEOFTXSIGINFO,        8u,        COM_BYTE_BUSACCOFTXSIGINFO,         1u,                    30u,          18u, COM_NO_TXSIGGRPINFOIDXOFTXSIGINFO }   /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_cd7fb3e1_Tx, /ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
};
#define COM_STOP_SEC_CONST_UNSPECIFIED
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CurrentTxMode
**********************************************************************************************************************/
/** 
  \var    Com_CurrentTxMode
  \brief  Current transmission mode state of all Tx I-PDUs.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CurrentTxModeType, COM_VAR_NOINIT) Com_CurrentTxMode[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CycleTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_CycleTimeCnt
  \brief  Current counter value of cyclic transmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CycleTimeCntType, COM_VAR_NOINIT) Com_CycleTimeCnt[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_CyclicSendRequest
**********************************************************************************************************************/
/** 
  \var    Com_CyclicSendRequest
  \brief  Cyclic send request flag used to indicate cyclic transmission mode for all Tx I-PDU.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_CyclicSendRequestType, COM_VAR_NOINIT) Com_CyclicSendRequest[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_DelayTimeCnt
**********************************************************************************************************************/
/** 
  \var    Com_DelayTimeCnt
  \brief  Current counter value of minimum delay counter.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_DelayTimeCntType, COM_VAR_NOINIT) Com_DelayTimeCnt[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_GatewayProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_GatewayProcessingISRLockCounterType, COM_VAR_NOINIT) Com_GatewayProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_HandleRxPduDeferred
**********************************************************************************************************************/
/** 
  \var    Com_HandleRxPduDeferred
  \brief  Array indicating received Rx I-PDUs to be processed deferred within the next call of Com_MainfunctionRx().
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_HandleRxPduDeferredUType, COM_VAR_NOINIT) Com_HandleRxPduDeferred;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_Initialized
**********************************************************************************************************************/
/** 
  \var    Com_Initialized
  \brief  Initialization state of Com. TRUE, if Com_Init() has been called, else FALSE.
*/ 
#define COM_START_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_InitializedType, COM_VAR_ZERO_INIT) Com_Initialized = FALSE;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_ZERO_INIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCnt
  \brief  Current repetition counter value for replication of transmission requests plus one initial transmit.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RepCntType, COM_VAR_NOINIT) Com_RepCnt[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RepCycleCnt
**********************************************************************************************************************/
/** 
  \var    Com_RepCycleCnt
  \brief  Current counter value of repetition period for replication of transmission requests.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RepCycleCntType, COM_VAR_NOINIT) Com_RepCycleCnt[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_RxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDefPduBuffer
**********************************************************************************************************************/
/** 
  \var    Com_RxDefPduBuffer
  \brief  Rx I-PDU buffer for deferred signal processing.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDefPduBufferUType, COM_VAR_NOINIT) Com_RxDefPduBuffer;  /* PRQA S 0759, 1514, 1533 */  /* MD_CSL_Union, MD_CSL_ObjectOnlyAccessedOnce, MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxDeferredProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxDeferredProcessingISRLockCounterType, COM_VAR_NOINIT) Com_RxDeferredProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_RxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_RxPduGrpActive
  \brief  Rx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxPduGrpActiveType, COM_VAR_NOINIT) Com_RxPduGrpActive[36];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BecmPropFr01_oCAN00_e2f0fff8_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr00_oCAN00_2afbaddb_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr07_oCAN00_203ea4c2_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/EcmPropFr24_oCAN00_80478ba7_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/IemEduPropFr01_oCAN00_97fdab75_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_985efe2d_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_8b12c95b_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_49f811f9_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_5ab4268f_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_83b4cf60_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f551f65d_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6e221c89_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_189b8427_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_83e86ef3_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f50d57ce_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6e7ebd1a_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_187e6692_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_830d8c46_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_99e24093_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0291aa47_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_7474937a_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_ef0779ae_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_99bee100_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_02cd0bd4_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_742832e9_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Rx_370d2033] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FL_oSchaeffler_MotorFL_CANFD_0dbeb0e9_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Rx_d87c4b2a] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_FR_oSchaeffler_MotorFR_CANFD_1af07762_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Rx_e11bfa71] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e8c7aa9c_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Rx_c653fc63] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ff896d17_Rx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Rx_ff344d38] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/TcmPropFr04_oCAN00_6f4049d8_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr05_oCAN00_53500d40_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr08_oCAN00_c8551891_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr09_oCAN00_04ff180f_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr10_oCAN00_0ccb1767_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr12_oCAN00_4eee101a_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/VddmPropFr29_oCAN00_2a093089_Rx, /ActiveEcuC/Com/ComConfig/MDA_oCAN00_Rx_982be727] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferFloat32
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferFloat32
  \brief  Rx Signal and Group Signal Buffer. (FLOAT32)
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferFloat32Type, COM_VAR_NOINIT) Com_RxSigBufferFloat32[4];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_7013e7f5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_7013e7f5_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_0d36ed6f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_0d36ed6f_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_6f298d95_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_6f298d95_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferSInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferSInt16
  \brief  Rx Signal and Group Signal Buffer. (SINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferSInt16Type, COM_VAR_NOINIT) Com_RxSigBufferSInt16[12];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeALat_oVddmPropFr09_oCAN00_a776222d_Rx, /ActiveEcuC/Com/ComConfig/ADataRawSafeALat_oVddmPropFr09_oCAN00_a776222d_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeALgt_oVddmPropFr09_oCAN00_4abc5057_Rx, /ActiveEcuC/Com/ComConfig/ADataRawSafeALgt_oVddmPropFr09_oCAN00_4abc5057_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/ADataRawSafeAVert_oVddmPropFr09_oCAN00_5affce16_Rx, /ActiveEcuC/Com/ComConfig/ADataRawSafeAVert_oVddmPropFr09_oCAN00_5affce16_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/AgDataRawSafeRollRate_oVddmPropFr12_oCAN00_938781d5_Rx, /ActiveEcuC/Com/ComConfig/AgDataRawSafeRollRate_oVddmPropFr12_oCAN00_938781d5_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/AgDataRawSafeYawRate_oVddmPropFr12_oCAN00_ab257c3a_Rx, /ActiveEcuC/Com/ComConfig/AgDataRawSafeYawRate_oVddmPropFr12_oCAN00_ab257c3a_Rx_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntAct_oEcmPropFr07_oCAN00_59efea99_Rx, /ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntAct_oEcmPropFr07_oCAN00_59efea99_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntReq_oVddmPropFr08_oCAN00_b5a3120c_Rx, /ActiveEcuC/Com/ComConfig/PtTqAtAxleFrntReq_oVddmPropFr08_oCAN00_b5a3120c_Rx_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/PtTqAtAxleReReq_oVddmPropFr08_oCAN00_ecdac0ff_Rx, /ActiveEcuC/Com/ComConfig/PtTqAtAxleReReq_oVddmPropFr08_oCAN00_ecdac0ff_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntLeAct_oEcmPropFr07_oCAN00_2226bbb1_Rx, /ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntLeAct_oEcmPropFr07_oCAN00_2226bbb1_Rx_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntRiAct_oEcmPropFr07_oCAN00_86eac12f_Rx, /ActiveEcuC/Com/ComConfig/PtTqAtWhlFrntRiAct_oEcmPropFr07_oCAN00_86eac12f_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/SteerWhlSnsrAgSpd_oVddmPropFr29_oCAN00_d671b60e_Rx, /ActiveEcuC/Com/ComConfig/SteerWhlSnsrAgSpd_oVddmPropFr29_oCAN00_d671b60e_Rx_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/SteerWhlSnsrAg_oVddmPropFr29_oCAN00_896c638d_Rx, /ActiveEcuC/Com/ComConfig/SteerWhlSnsrAg_oVddmPropFr29_oCAN00_896c638d_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt16
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt16
  \brief  Rx Signal and Group Signal Buffer. (UINT16)
*/ 
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt16Type, COM_VAR_NOINIT) Com_RxSigBufferUInt16[262];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/AccrPedlRatAccrPedlRat_oEcmPropFr00_oCAN00_4ad8b74f_Rx, /ActiveEcuC/Com/ComConfig/AccrPedlRatAccrPedlRat_oEcmPropFr00_oCAN00_4ad8b74f_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntLeAct_oVddmPropFr10_oCAN00_b6b8e9ec_Rx, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntLeAct_oVddmPropFr10_oCAN00_b6b8e9ec_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntRiAct_oVddmPropFr10_oCAN00_a1ab9bd5_Rx, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlFrntRiAct_oVddmPropFr10_oCAN00_a1ab9bd5_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReLeAct_oVddmPropFr10_oCAN00_8d4d2f89_Rx, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReLeAct_oVddmPropFr10_oCAN00_8d4d2f89_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReRiAct_oVddmPropFr10_oCAN00_9a5e5db0_Rx, /ActiveEcuC/Com/ComConfig/BrkFricTqAtWhlReRiAct_oVddmPropFr10_oCAN00_9a5e5db0_Rx_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/BrkTqAtWhlsReq_oVddmPropFr08_oCAN00_2a675d21_Rx, /ActiveEcuC/Com/ComConfig/BrkTqAtWhlsReq_oVddmPropFr08_oCAN00_2a675d21_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_1f1f7c0c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_1f1f7c0c_Rx_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_76957b8d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_76957b8d_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_455450ed_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_455450ed_Rx_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_2cde576c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_2cde576c_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_5071d764_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_5071d764_Rx_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2d54ddfe_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2d54ddfe_Rx_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_4f4bbd04_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_4f4bbd04_Rx_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_326eb79e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_326eb79e_Rx_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_86e41f3b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_86e41f3b_Rx_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_ef6e18ba_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_ef6e18ba_Rx_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_dcaf33da_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_dcaf33da_Rx_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_b525345b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_b525345b_Rx_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_05cd1d48_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_05cd1d48_Rx_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_78e817d2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_78e817d2_Rx_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_1af77728_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_1af77728_Rx_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_67d27db2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_67d27db2_Rx_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_798d9eb1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_798d9eb1_Rx_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_10079930_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_10079930_Rx_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_23c6b250_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_23c6b250_Rx_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_4a4cb5d1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_4a4cb5d1_Rx_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_f956be0b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_f956be0b_Rx_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_8473b491_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_8473b491_Rx_RxSignalBufferRouting] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e66cd46b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e66cd46b_Rx_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_9b49def1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_9b49def1_Rx_RxSignalBufferRouting] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_31f62729_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_31f62729_Rx_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_4cd32db3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_4cd32db3_Rx_RxSignalBufferRouting] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_2ecc4d49_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_2ecc4d49_Rx_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_53e947d3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_53e947d3_Rx_RxSignalBufferRouting] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_FWtimeOFF0_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_cdb96a4e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_FWtimeOFF0_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_cdb96a4e_Rx_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Frequency_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_84915280_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Frequency_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_84915280_Rx_RxSignalBufferRouting] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Ibias_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_16ed333d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Ibias_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_16ed333d_Rx_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostB_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c914d65f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostB_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c914d65f_Rx_RxSignalBufferRouting] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostP_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_946a5245_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_IboostP_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_946a5245_Rx_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Ihold_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6df9b71a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Ihold_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6df9b71a_Rx_RxSignalBufferRouting] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Ipeak_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_af0de4c2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Ipeak_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_af0de4c2_Rx_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_275b00ec_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_275b00ec_Rx_RxSignalBufferRouting] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_733ed7db_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbias_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_733ed7db_Rx_RxSignalBufferRouting] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbypass_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_21bc9bdf_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tbypass_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_21bc9bdf_Rx_RxSignalBufferRouting] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_15fb5bd6_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_15fb5bd6_Rx_RxSignalBufferRouting] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_419e8ce1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Thold_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_419e8ce1_Rx_RxSignalBufferRouting] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_9d5bdd6c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_off_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_9d5bdd6c_Rx_RxSignalBufferRouting] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c93e0a5b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Tpeak_tot_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_c93e0a5b_Rx_RxSignalBufferRouting] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_FWtimeOFF0_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_3f59c6a3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_FWtimeOFF0_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_3f59c6a3_Rx_RxSignalBufferRouting] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Frequency_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_49a065ae_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Frequency_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_49a065ae_Rx_RxSignalBufferRouting] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Ibias_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_060cdf30_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Ibias_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_060cdf30_Rx_RxSignalBufferRouting] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostB_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_960e99ce_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostB_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_960e99ce_Rx_RxSignalBufferRouting] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostP_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_cb701dd4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_IboostP_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_cb701dd4_Rx_RxSignalBufferRouting] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Ihold_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7d185b17_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Ihold_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7d185b17_Rx_RxSignalBufferRouting] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Ipeak_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_bfec08cf_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Ipeak_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_bfec08cf_Rx_RxSignalBufferRouting] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_ea6a37c2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_ea6a37c2_Rx_RxSignalBufferRouting] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_be0fe0f5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbias_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_be0fe0f5_Rx_RxSignalBufferRouting] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbypass_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7ea6d44e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tbypass_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_7ea6d44e_Rx_RxSignalBufferRouting] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_d8ca6cf8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_d8ca6cf8_Rx_RxSignalBufferRouting] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_8cafbbcf_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Thold_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_8cafbbcf_Rx_RxSignalBufferRouting] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_506aea42_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_off_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_506aea42_Rx_RxSignalBufferRouting] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_040f3d75_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Tpeak_tot_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_040f3d75_Rx_RxSignalBufferRouting] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_FWtimeOFF0_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6ef9a2f8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_FWtimeOFF0_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6ef9a2f8_Rx_RxSignalBufferRouting] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Frequency_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bb9f8a8b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Frequency_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bb9f8a8b_Rx_RxSignalBufferRouting] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Ibias_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bf7c86f4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Ibias_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_bf7c86f4_Rx_RxSignalBufferRouting] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostB_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_15d7a17e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostB_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_15d7a17e_Rx_RxSignalBufferRouting] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostP_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_48a92564_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_IboostP_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_48a92564_Rx_RxSignalBufferRouting] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Ihold_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_c46802d3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Ihold_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_c46802d3_Rx_RxSignalBufferRouting] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Ipeak_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_069c510b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Ipeak_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_069c510b_Rx_RxSignalBufferRouting] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_1855d8e7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_1855d8e7_Rx_RxSignalBufferRouting] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_4c300fd0_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbias_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_4c300fd0_Rx_RxSignalBufferRouting] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbypass_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_fd7fecfe_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tbypass_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_fd7fecfe_Rx_RxSignalBufferRouting] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_2af583dd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_2af583dd_Rx_RxSignalBufferRouting] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7e9054ea_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Thold_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7e9054ea_Rx_RxSignalBufferRouting] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_a2550567_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_off_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_a2550567_Rx_RxSignalBufferRouting] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_f630d250_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Tpeak_tot_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_f630d250_Rx_RxSignalBufferRouting] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_FWtimeOFF0_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_01e99938_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_FWtimeOFF0_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_01e99938_Rx_RxSignalBufferRouting] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Frequency_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_08b30db3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Frequency_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_08b30db3_Rx_RxSignalBufferRouting] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Ibias_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_27cf072a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Ibias_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_27cf072a_Rx_RxSignalBufferRouting] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostB_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_283a06ec_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostB_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_283a06ec_Rx_RxSignalBufferRouting] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostP_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_754482f6_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_IboostP_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_754482f6_Rx_RxSignalBufferRouting] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Ihold_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_5cdb830d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Ihold_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_5cdb830d_Rx_RxSignalBufferRouting] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Ipeak_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_9e2fd0d5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Ipeak_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_9e2fd0d5_Rx_RxSignalBufferRouting] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ab795fdf_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ab795fdf_Rx_RxSignalBufferRouting] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ff1c88e8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbias_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_ff1c88e8_Rx_RxSignalBufferRouting] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbypass_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_c0924b6c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tbypass_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_c0924b6c_Rx_RxSignalBufferRouting] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_99d904e5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_99d904e5_Rx_RxSignalBufferRouting] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_cdbcd3d2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Thold_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_cdbcd3d2_Rx_RxSignalBufferRouting] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1179825f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_off_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1179825f_Rx_RxSignalBufferRouting] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_451c5568_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Tpeak_tot_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_451c5568_Rx_RxSignalBufferRouting] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_FWtimeOFF0_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5049fd63_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_FWtimeOFF0_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5049fd63_Rx_RxSignalBufferRouting] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Frequency_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_fa8ce296_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Frequency_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_fa8ce296_Rx_RxSignalBufferRouting] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Ibias_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_9ebf5eee_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Ibias_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_9ebf5eee_Rx_RxSignalBufferRouting] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostB_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_abe33e5c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostB_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_abe33e5c_Rx_RxSignalBufferRouting] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostP_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_f69dba46_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_IboostP_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_f69dba46_Rx_RxSignalBufferRouting] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Ihold_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e5abdac9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Ihold_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e5abdac9_Rx_RxSignalBufferRouting] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Ipeak_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_275f8911_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Ipeak_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_275f8911_Rx_RxSignalBufferRouting] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5946b0fa_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_5946b0fa_Rx_RxSignalBufferRouting] */
  /*    98 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_0d2367cd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbias_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_0d2367cd_Rx_RxSignalBufferRouting] */
  /*    99 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbypass_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_434b73dc_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tbypass_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_434b73dc_Rx_RxSignalBufferRouting] */
  /* Index        Referable Keys */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_6be6ebc0_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_6be6ebc0_Rx_RxSignalBufferRouting] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_3f833cf7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Thold_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_3f833cf7_Rx_RxSignalBufferRouting] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e3466d7a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_off_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_e3466d7a_Rx_RxSignalBufferRouting] */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_b723ba4d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Tpeak_tot_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_b723ba4d_Rx_RxSignalBufferRouting] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_FWtimeOFF0_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a2a9518e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_FWtimeOFF0_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a2a9518e_Rx_RxSignalBufferRouting] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Frequency_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37bdd5b8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Frequency_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37bdd5b8_Rx_RxSignalBufferRouting] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Ibias_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_8e5eb2e3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Ibias_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_8e5eb2e3_Rx_RxSignalBufferRouting] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostB_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f4f971cd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostB_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f4f971cd_Rx_RxSignalBufferRouting] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostP_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a987f5d7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_IboostP_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a987f5d7_Rx_RxSignalBufferRouting] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Ihold_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f54a36c4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Ihold_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f54a36c4_Rx_RxSignalBufferRouting] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Ipeak_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37be651c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Ipeak_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_37be651c_Rx_RxSignalBufferRouting] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_947787d4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_947787d4_Rx_RxSignalBufferRouting] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_c01250e3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbias_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_c01250e3_Rx_RxSignalBufferRouting] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbypass_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_1c513c4d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tbypass_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_1c513c4d_Rx_RxSignalBufferRouting] */
  /*   114 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a6d7dcee_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_a6d7dcee_Rx_RxSignalBufferRouting] */
  /*   115 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f2b20bd9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Thold_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f2b20bd9_Rx_RxSignalBufferRouting] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_2e775a54_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_off_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_2e775a54_Rx_RxSignalBufferRouting] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_7a128d63_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Tpeak_tot_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_7a128d63_Rx_RxSignalBufferRouting] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_FWtimeOFF0_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_f30935d5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_FWtimeOFF0_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_f30935d5_Rx_RxSignalBufferRouting] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Frequency_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_c5823a9d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Frequency_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_c5823a9d_Rx_RxSignalBufferRouting] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Ibias_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_372eeb27_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Ibias_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_372eeb27_Rx_RxSignalBufferRouting] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostB_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_7720497d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostB_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_7720497d_Rx_RxSignalBufferRouting] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostP_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_2a5ecd67_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_IboostP_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_2a5ecd67_Rx_RxSignalBufferRouting] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Ihold_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_4c3a6f00_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Ihold_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_4c3a6f00_Rx_RxSignalBufferRouting] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Ipeak_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_8ece3cd8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Ipeak_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_8ece3cd8_Rx_RxSignalBufferRouting] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_664868f1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_664868f1_Rx_RxSignalBufferRouting] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_322dbfc6_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbias_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_322dbfc6_Rx_RxSignalBufferRouting] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbypass_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_9f8804fd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tbypass_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_9f8804fd_Rx_RxSignalBufferRouting] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_54e833cb_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_54e833cb_Rx_RxSignalBufferRouting] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_008de4fc_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Thold_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_008de4fc_Rx_RxSignalBufferRouting] */
  /*   130 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_dc48b571_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_off_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_dc48b571_Rx_RxSignalBufferRouting] */
  /*   131 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_882d6246_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Tpeak_tot_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_882d6246_Rx_RxSignalBufferRouting] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_FWtimeOFF0_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7c89260e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_FWtimeOFF0_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7c89260e_Rx_RxSignalBufferRouting] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Frequency_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8a95dd89_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Frequency_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8a95dd89_Rx_RxSignalBufferRouting] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Ibias_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_6448b71e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Ibias_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_6448b71e_Rx_RxSignalBufferRouting] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostB_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8f223ee9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostB_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_8f223ee9_Rx_RxSignalBufferRouting] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostP_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d25cbaf3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_IboostP_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d25cbaf3_Rx_RxSignalBufferRouting] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Ihold_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1f5c3339_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Ihold_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1f5c3339_Rx_RxSignalBufferRouting] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Ipeak_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_dda860e1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Ipeak_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_dda860e1_Rx_RxSignalBufferRouting] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_295f8fe5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_295f8fe5_Rx_RxSignalBufferRouting] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7d3a58d2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbias_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_7d3a58d2_Rx_RxSignalBufferRouting] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbypass_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_678a7369_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tbypass_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_678a7369_Rx_RxSignalBufferRouting] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1bffd4df_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_1bffd4df_Rx_RxSignalBufferRouting] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4f9a03e8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Thold_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_4f9a03e8_Rx_RxSignalBufferRouting] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_935f5265_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_off_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_935f5265_Rx_RxSignalBufferRouting] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_c73a8552_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Tpeak_tot_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_c73a8552_Rx_RxSignalBufferRouting] */
  /*   146 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_FWtimeOFF0_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_2d294255_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_FWtimeOFF0_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_2d294255_Rx_RxSignalBufferRouting] */
  /*   147 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Frequency_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_78aa32ac_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Frequency_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_78aa32ac_Rx_RxSignalBufferRouting] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Ibias_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_dd38eeda_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Ibias_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_dd38eeda_Rx_RxSignalBufferRouting] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostB_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_0cfb0659_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostB_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_0cfb0659_Rx_RxSignalBufferRouting] */
  /* Index        Referable Keys */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostP_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_51858243_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_IboostP_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_51858243_Rx_RxSignalBufferRouting] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Ihold_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_a62c6afd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Ihold_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_a62c6afd_Rx_RxSignalBufferRouting] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Ipeak_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_64d83925_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Ipeak_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_64d83925_Rx_RxSignalBufferRouting] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_db6060c0_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_db6060c0_Rx_RxSignalBufferRouting] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8f05b7f7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbias_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8f05b7f7_Rx_RxSignalBufferRouting] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbypass_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e4534bd9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tbypass_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e4534bd9_Rx_RxSignalBufferRouting] */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e9c03bfa_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_e9c03bfa_Rx_RxSignalBufferRouting] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_bda5eccd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Thold_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_bda5eccd_Rx_RxSignalBufferRouting] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_6160bd40_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_off_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_6160bd40_Rx_RxSignalBufferRouting] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_35056a77_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Tpeak_tot_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_35056a77_Rx_RxSignalBufferRouting] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_FWtimeOFF0_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2c61f86f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_FWtimeOFF0_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2c61f86f_Rx_RxSignalBufferRouting] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Frequency_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_c4966a2c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Frequency_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_c4966a2c_Rx_RxSignalBufferRouting] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Ibias_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_9cd31f0c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Ibias_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_9cd31f0c_Rx_RxSignalBufferRouting] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostB_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_65518e5a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostB_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_65518e5a_Rx_RxSignalBufferRouting] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostP_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_382f0a40_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_IboostP_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_382f0a40_Rx_RxSignalBufferRouting] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Ihold_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e7c79b2b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Ihold_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e7c79b2b_Rx_RxSignalBufferRouting] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Ipeak_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2533c8f3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Ipeak_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_2533c8f3_Rx_RxSignalBufferRouting] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_675c3840_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_675c3840_Rx_RxSignalBufferRouting] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_3339ef77_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbias_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_3339ef77_Rx_RxSignalBufferRouting] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbypass_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_8df9c3da_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tbypass_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_8df9c3da_Rx_RxSignalBufferRouting] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_55fc637a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_55fc637a_Rx_RxSignalBufferRouting] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_0199b44d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Thold_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_0199b44d_Rx_RxSignalBufferRouting] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_dd5ce5c0_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_off_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_dd5ce5c0_Rx_RxSignalBufferRouting] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_893932f7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Tpeak_tot_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_893932f7_Rx_RxSignalBufferRouting] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_FWtimeOFF0_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7dc19c34_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_FWtimeOFF0_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7dc19c34_Rx_RxSignalBufferRouting] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Frequency_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_36a98509_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Frequency_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_36a98509_Rx_RxSignalBufferRouting] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Ibias_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_25a346c8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Ibias_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_25a346c8_Rx_RxSignalBufferRouting] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostB_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_e688b6ea_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostB_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_e688b6ea_Rx_RxSignalBufferRouting] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostP_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_bbf632f0_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_IboostP_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_bbf632f0_Rx_RxSignalBufferRouting] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Ihold_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_5eb7c2ef_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Ihold_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_5eb7c2ef_Rx_RxSignalBufferRouting] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Ipeak_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9c439137_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Ipeak_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9c439137_Rx_RxSignalBufferRouting] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9563d765_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_9563d765_Rx_RxSignalBufferRouting] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_c1060052_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbias_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_c1060052_Rx_RxSignalBufferRouting] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbypass_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0e20fb6a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tbypass_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_0e20fb6a_Rx_RxSignalBufferRouting] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a7c38c5f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a7c38c5f_Rx_RxSignalBufferRouting] */
  /*   185 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_f3a65b68_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Thold_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_f3a65b68_Rx_RxSignalBufferRouting] */
  /*   186 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_2f630ae5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_off_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_2f630ae5_Rx_RxSignalBufferRouting] */
  /*   187 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7b06ddd2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Tpeak_tot_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_7b06ddd2_Rx_RxSignalBufferRouting] */
  /*   188 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_FWtimeOFF0_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8f2130d9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_FWtimeOFF0_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8f2130d9_Rx_RxSignalBufferRouting] */
  /*   189 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Frequency_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fb98b227_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Frequency_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_fb98b227_Rx_RxSignalBufferRouting] */
  /*   190 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Ibias_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3542aac5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Ibias_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3542aac5_Rx_RxSignalBufferRouting] */
  /*   191 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostB_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b992f97b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostB_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b992f97b_Rx_RxSignalBufferRouting] */
  /*   192 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostP_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e4ec7d61_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_IboostP_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e4ec7d61_Rx_RxSignalBufferRouting] */
  /*   193 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Ihold_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4e562ee2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Ihold_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_4e562ee2_Rx_RxSignalBufferRouting] */
  /*   194 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Ipeak_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8ca27d3a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Ipeak_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_8ca27d3a_Rx_RxSignalBufferRouting] */
  /*   195 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_5852e04b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_5852e04b_Rx_RxSignalBufferRouting] */
  /*   196 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0c37377c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbias_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0c37377c_Rx_RxSignalBufferRouting] */
  /*   197 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbypass_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_513ab4fb_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tbypass_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_513ab4fb_Rx_RxSignalBufferRouting] */
  /*   198 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_6af2bb71_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_6af2bb71_Rx_RxSignalBufferRouting] */
  /*   199 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3e976c46_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Thold_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_3e976c46_Rx_RxSignalBufferRouting] */
  /* Index        Referable Keys */
  /*   200 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e2523dcb_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_off_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_e2523dcb_Rx_RxSignalBufferRouting] */
  /*   201 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b637eafc_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Tpeak_tot_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b637eafc_Rx_RxSignalBufferRouting] */
  /*   202 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_FWtimeOFF0_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_de815482_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_FWtimeOFF0_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_de815482_Rx_RxSignalBufferRouting] */
  /*   203 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Frequency_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09a75d02_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Frequency_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09a75d02_Rx_RxSignalBufferRouting] */
  /*   204 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Ibias_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_8c32f301_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Ibias_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_8c32f301_Rx_RxSignalBufferRouting] */
  /*   205 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostB_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3a4bc1cb_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostB_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3a4bc1cb_Rx_RxSignalBufferRouting] */
  /*   206 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostP_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_673545d1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_IboostP_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_673545d1_Rx_RxSignalBufferRouting] */
  /*   207 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Ihold_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_f7267726_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Ihold_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_f7267726_Rx_RxSignalBufferRouting] */
  /*   208 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Ipeak_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_35d224fe_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Ipeak_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_35d224fe_Rx_RxSignalBufferRouting] */
  /*   209 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_aa6d0f6e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_aa6d0f6e_Rx_RxSignalBufferRouting] */
  /*   210 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_fe08d859_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbias_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_fe08d859_Rx_RxSignalBufferRouting] */
  /*   211 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbypass_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_d2e38c4b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tbypass_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_d2e38c4b_Rx_RxSignalBufferRouting] */
  /*   212 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_98cd5454_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_98cd5454_Rx_RxSignalBufferRouting] */
  /*   213 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_cca88363_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Thold_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_cca88363_Rx_RxSignalBufferRouting] */
  /*   214 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_106dd2ee_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_off_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_106dd2ee_Rx_RxSignalBufferRouting] */
  /*   215 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_440805d9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Tpeak_tot_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_440805d9_Rx_RxSignalBufferRouting] */
  /*   216 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_FWtimeOFF0_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_b1916f42_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_FWtimeOFF0_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_b1916f42_Rx_RxSignalBufferRouting] */
  /*   217 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Frequency_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ba8bda3a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Frequency_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ba8bda3a_Rx_RxSignalBufferRouting] */
  /*   218 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Ibias_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_148172df_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Ibias_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_148172df_Rx_RxSignalBufferRouting] */
  /*   219 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostB_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_07a66659_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostB_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_07a66659_Rx_RxSignalBufferRouting] */
  /*   220 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostP_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_5ad8e243_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_IboostP_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_5ad8e243_Rx_RxSignalBufferRouting] */
  /*   221 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Ihold_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_6f95f6f8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Ihold_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_6f95f6f8_Rx_RxSignalBufferRouting] */
  /*   222 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Ipeak_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ad61a520_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Ipeak_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ad61a520_Rx_RxSignalBufferRouting] */
  /*   223 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_19418856_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_19418856_Rx_RxSignalBufferRouting] */
  /*   224 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4d245f61_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbias_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4d245f61_Rx_RxSignalBufferRouting] */
  /*   225 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbypass_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ef0e2bd9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tbypass_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_ef0e2bd9_Rx_RxSignalBufferRouting] */
  /*   226 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_2be1d36c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_2be1d36c_Rx_RxSignalBufferRouting] */
  /*   227 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_7f84045b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Thold_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_7f84045b_Rx_RxSignalBufferRouting] */
  /*   228 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_a34155d6_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_off_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_a34155d6_Rx_RxSignalBufferRouting] */
  /*   229 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_f72482e1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Tpeak_tot_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_f72482e1_Rx_RxSignalBufferRouting] */
  /*   230 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_FWtimeOFF0_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_e0310b19_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_FWtimeOFF0_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_e0310b19_Rx_RxSignalBufferRouting] */
  /*   231 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Frequency_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48b4351f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Frequency_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_48b4351f_Rx_RxSignalBufferRouting] */
  /*   232 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Ibias_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_adf12b1b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Ibias_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_adf12b1b_Rx_RxSignalBufferRouting] */
  /*   233 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostB_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_847f5ee9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostB_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_847f5ee9_Rx_RxSignalBufferRouting] */
  /*   234 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostP_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d901daf3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_IboostP_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d901daf3_Rx_RxSignalBufferRouting] */
  /*   235 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Ihold_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d6e5af3c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Ihold_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d6e5af3c_Rx_RxSignalBufferRouting] */
  /*   236 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Ipeak_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_1411fce4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Ipeak_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_1411fce4_Rx_RxSignalBufferRouting] */
  /*   237 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_eb7e6773_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_eb7e6773_Rx_RxSignalBufferRouting] */
  /*   238 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_bf1bb044_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbias_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_bf1bb044_Rx_RxSignalBufferRouting] */
  /*   239 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbypass_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_6cd71369_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tbypass_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_6cd71369_Rx_RxSignalBufferRouting] */
  /*   240 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d9de3c49_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d9de3c49_Rx_RxSignalBufferRouting] */
  /*   241 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_8dbbeb7e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Thold_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_8dbbeb7e_Rx_RxSignalBufferRouting] */
  /*   242 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_517ebaf3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_off_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_517ebaf3_Rx_RxSignalBufferRouting] */
  /*   243 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_051b6dc4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Tpeak_tot_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_051b6dc4_Rx_RxSignalBufferRouting] */
  /*   244 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_FWtimeOFF0_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_12d1a7f4_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_FWtimeOFF0_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_12d1a7f4_Rx_RxSignalBufferRouting] */
  /*   245 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Frequency_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_85850231_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Frequency_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_85850231_Rx_RxSignalBufferRouting] */
  /*   246 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Ibias_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_bd10c716_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Ibias_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_bd10c716_Rx_RxSignalBufferRouting] */
  /*   247 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostB_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_db651178_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostB_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_db651178_Rx_RxSignalBufferRouting] */
  /*   248 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostP_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_861b9562_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_IboostP_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_861b9562_Rx_RxSignalBufferRouting] */
  /*   249 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Ihold_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c6044331_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Ihold_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c6044331_Rx_RxSignalBufferRouting] */
  /* Index        Referable Keys */
  /*   250 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Ipeak_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_04f010e9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Ipeak_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_04f010e9_Rx_RxSignalBufferRouting] */
  /*   251 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_264f505d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_264f505d_Rx_RxSignalBufferRouting] */
  /*   252 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_722a876a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbias_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_722a876a_Rx_RxSignalBufferRouting] */
  /*   253 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbypass_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_33cd5cf8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tbypass_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_33cd5cf8_Rx_RxSignalBufferRouting] */
  /*   254 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_14ef0b67_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_14ef0b67_Rx_RxSignalBufferRouting] */
  /*   255 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_408adc50_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Thold_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_408adc50_Rx_RxSignalBufferRouting] */
  /*   256 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_9c4f8ddd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_off_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_9c4f8ddd_Rx_RxSignalBufferRouting] */
  /*   257 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c82a5aea_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Tpeak_tot_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_c82a5aea_Rx_RxSignalBufferRouting] */
  /*   258 */  /* [/ActiveEcuC/Com/ComConfig/TrsmVehSpd_oTcmPropFr04_oCAN00_9a41ead0_Rx, /ActiveEcuC/Com/ComConfig/TrsmVehSpd_oTcmPropFr04_oCAN00_9a41ead0_Rx_RxSignalBufferRouting] */
  /*   259 */  /* [/ActiveEcuC/Com/ComConfig/VehSpdLgtA_oVddmPropFr05_oCAN00_aa5f0501_Rx, /ActiveEcuC/Com/ComConfig/VehSpdLgtA_oVddmPropFr05_oCAN00_aa5f0501_Rx_RxSignalBufferRouting] */
  /*   260 */  /* [/ActiveEcuC/Com/ComConfig/WhlMotSysTqEstIsgTqAct_oIemEduPropFr01_oCAN00_32af1c7a_Rx, /ActiveEcuC/Com/ComConfig/WhlMotSysTqEstIsgTqAct_oIemEduPropFr01_oCAN00_32af1c7a_Rx_RxSignalBufferRouting] */
  /*   261 */  /* [/ActiveEcuC/Com/ComConfig/WhlMotSysTqReq_oEcmPropFr24_oCAN00_2b85d3d8_Rx, /ActiveEcuC/Com/ComConfig/WhlMotSysTqReq_oEcmPropFr24_oCAN00_2b85d3d8_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_RxSigBufferUInt8
**********************************************************************************************************************/
/** 
  \var    Com_RxSigBufferUInt8
  \brief  Rx Signal and Group Signal Buffer. (BOOLEAN, UINT8)
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_RxSigBufferUInt8Type, COM_VAR_NOINIT) Com_RxSigBufferUInt8[92];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlNotPsdSafe_oVddmPropFr05_oCAN00_6dd71a9b_Rx, /ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlNotPsdSafe_oVddmPropFr05_oCAN00_6dd71a9b_Rx_RxSignalBufferRouting] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlPsd_oVddmPropFr05_oCAN00_dcf25825_Rx, /ActiveEcuC/Com/ComConfig/BrkPedlPsdBrkPedlPsd_oVddmPropFr05_oCAN00_dcf25825_Rx_RxSignalBufferRouting] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/GearLvrIndcn_oEcmPropFr24_oCAN00_fa2560a8_Rx, /ActiveEcuC/Com/ComConfig/GearLvrIndcn_oEcmPropFr24_oCAN00_fa2560a8_Rx_RxSignalBufferRouting] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/HvSysSts_oBecmPropFr01_oCAN00_919ec934_Rx, /ActiveEcuC/Com/ComConfig/HvSysSts_oBecmPropFr01_oCAN00_919ec934_Rx_RxSignalBufferRouting] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_940a4d73_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_940a4d73_Rx_RxSignalBufferRouting] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_e92f47e9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_e92f47e9_Rx_RxSignalBufferRouting] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_8b302713_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_8b302713_Rx_RxSignalBufferRouting] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_f6152d89_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_f6152d89_Rx_RxSignalBufferRouting] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_4378bd23_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_4378bd23_Rx_RxSignalBufferRouting] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2af2baa2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2af2baa2_Rx_RxSignalBufferRouting] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_193391c2_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_193391c2_Rx_RxSignalBufferRouting] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_70b99643_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_70b99643_Rx_RxSignalBufferRouting] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_880421cb_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_880421cb_Rx_RxSignalBufferRouting] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_f5212b51_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_f5212b51_Rx_RxSignalBufferRouting] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_973e4bab_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_973e4bab_Rx_RxSignalBufferRouting] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ea1b4131_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ea1b4131_Rx_RxSignalBufferRouting] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_115de03b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_115de03b_Rx_RxSignalBufferRouting] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_6c78eaa1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_6c78eaa1_Rx_RxSignalBufferRouting] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_0e678a5b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_0e678a5b_Rx_RxSignalBufferRouting] */
  /*    19 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_734280c1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_734280c1_Rx_RxSignalBufferRouting] */
  /*    20 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_811760c8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_811760c8_Rx_RxSignalBufferRouting] */
  /*    21 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_fc326a52_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_fc326a52_Rx_RxSignalBufferRouting] */
  /*    22 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_9e2d0aa8_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_9e2d0aa8_Rx_RxSignalBufferRouting] */
  /*    23 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_e3080032_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_e3080032_Rx_RxSignalBufferRouting] */
  /*    24 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_fb218646_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_fb218646_Rx_RxSignalBufferRouting] */
  /*    25 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_92ab81c7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_92ab81c7_Rx_RxSignalBufferRouting] */
  /*    26 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_a16aaaa7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_a16aaaa7_Rx_RxSignalBufferRouting] */
  /*    27 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Mot_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_c8e0ad26_Rx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_c8e0ad26_Rx_RxSignalBufferRouting] */
  /*    28 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_DutyCycle_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_a5032589_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_DutyCycle_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_a5032589_Rx_RxSignalBufferRouting] */
  /*    29 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_MDAswitchPC_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6ab83b1c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_MDAswitchPC_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_6ab83b1c_Rx_RxSignalBufferRouting] */
  /*    30 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_Mode_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_87ad547b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Mode_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_87ad547b_Rx_RxSignalBufferRouting] */
  /*    31 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve1_State_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_93106638_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_State_command_oMSG_MDA_Valve_01_oSchaeffler_MDA_CANFD_93106638_Rx_RxSignalBufferRouting] */
  /*    32 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_DutyCycle_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_683212a7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_DutyCycle_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_683212a7_Rx_RxSignalBufferRouting] */
  /*    33 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_MDAswitchPC_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_9a0ad560_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_MDAswitchPC_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_9a0ad560_Rx_RxSignalBufferRouting] */
  /*    34 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_Mode_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f3a6979c_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Mode_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_f3a6979c_Rx_RxSignalBufferRouting] */
  /*    35 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve2_State_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_83f18a35_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_State_command_oMSG_MDA_Valve_02_oSchaeffler_MDA_CANFD_83f18a35_Rx_RxSignalBufferRouting] */
  /*    36 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_DutyCycle_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_9a0dfd82_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_DutyCycle_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_9a0dfd82_Rx_RxSignalBufferRouting] */
  /*    37 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_MDAswitchPC_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7cb4728b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_MDAswitchPC_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_7cb4728b_Rx_RxSignalBufferRouting] */
  /*    38 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_Mode_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6970d4fe_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Mode_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_6970d4fe_Rx_RxSignalBufferRouting] */
  /*    39 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve3_State_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_3a81d3f1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_State_command_oMSG_MDA_Valve_03_oSchaeffler_MDA_CANFD_3a81d3f1_Rx_RxSignalBufferRouting] */
  /*    40 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_DutyCycle_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_29217aba_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_DutyCycle_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_29217aba_Rx_RxSignalBufferRouting] */
  /*    41 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_MDAswitchPC_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a01e0fd9_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_MDAswitchPC_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a01e0fd9_Rx_RxSignalBufferRouting] */
  /*    42 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_Mode_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1bb11052_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Mode_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_1bb11052_Rx_RxSignalBufferRouting] */
  /*    43 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve4_State_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a232522f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_State_command_oMSG_MDA_Valve_04_oSchaeffler_MDA_CANFD_a232522f_Rx_RxSignalBufferRouting] */
  /*    44 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_DutyCycle_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_db1e959f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_DutyCycle_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_db1e959f_Rx_RxSignalBufferRouting] */
  /*    45 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_MDAswitchPC_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_46a0a832_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_MDAswitchPC_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_46a0a832_Rx_RxSignalBufferRouting] */
  /*    46 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_Mode_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_81675330_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Mode_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_81675330_Rx_RxSignalBufferRouting] */
  /*    47 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve5_State_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1b420beb_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_State_command_oMSG_MDA_Valve_05_oSchaeffler_MDA_CANFD_1b420beb_Rx_RxSignalBufferRouting] */
  /*    48 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_DutyCycle_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_162fa2b1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_DutyCycle_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_162fa2b1_Rx_RxSignalBufferRouting] */
  /*    49 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_MDAswitchPC_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_b612464e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_MDAswitchPC_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_b612464e_Rx_RxSignalBufferRouting] */
  /* Index        Referable Keys */
  /*    50 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_Mode_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f56c90d7_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Mode_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_f56c90d7_Rx_RxSignalBufferRouting] */
  /*    51 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve6_State_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_0ba3e7e6_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_State_command_oMSG_MDA_Valve_06_oSchaeffler_MDA_CANFD_0ba3e7e6_Rx_RxSignalBufferRouting] */
  /*    52 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_DutyCycle_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_e4104d94_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_DutyCycle_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_e4104d94_Rx_RxSignalBufferRouting] */
  /*    53 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_MDAswitchPC_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_50ace1a5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_MDAswitchPC_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_50ace1a5_Rx_RxSignalBufferRouting] */
  /*    54 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_Mode_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6fbad3b5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Mode_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_6fbad3b5_Rx_RxSignalBufferRouting] */
  /*    55 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve7_State_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_b2d3be22_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_State_command_oMSG_MDA_Valve_07_oSchaeffler_MDA_CANFD_b2d3be22_Rx_RxSignalBufferRouting] */
  /*    56 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_DutyCycle_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_ab07aa80_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_DutyCycle_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_ab07aa80_Rx_RxSignalBufferRouting] */
  /*    57 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_MDAswitchPC_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d437baab_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_MDAswitchPC_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_d437baab_Rx_RxSignalBufferRouting] */
  /*    58 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_Mode_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_10ef198f_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Mode_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_10ef198f_Rx_RxSignalBufferRouting] */
  /*    59 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve8_State_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_e1b5e21b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_State_command_oMSG_MDA_Valve_08_oSchaeffler_MDA_CANFD_e1b5e21b_Rx_RxSignalBufferRouting] */
  /*    60 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_DutyCycle_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_593845a5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_DutyCycle_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_593845a5_Rx_RxSignalBufferRouting] */
  /*    61 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_MDAswitchPC_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_32891d40_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_MDAswitchPC_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_32891d40_Rx_RxSignalBufferRouting] */
  /*    62 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_Mode_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8a395aed_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Mode_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_8a395aed_Rx_RxSignalBufferRouting] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve9_State_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_58c5bbdf_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_State_command_oMSG_MDA_Valve_09_oSchaeffler_MDA_CANFD_58c5bbdf_Rx_RxSignalBufferRouting] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_DutyCycle_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e5041d25_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_DutyCycle_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_e5041d25_Rx_RxSignalBufferRouting] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_MDAswitchPC_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_18c8890a_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_MDAswitchPC_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_18c8890a_Rx_RxSignalBufferRouting] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_Mode_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_4a458887_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Mode_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_4a458887_Rx_RxSignalBufferRouting] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve10_State_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_192e4a09_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_State_command_oMSG_MDA_Valve_10_oSchaeffler_MDA_CANFD_192e4a09_Rx_RxSignalBufferRouting] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_DutyCycle_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_173bf200_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_DutyCycle_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_173bf200_Rx_RxSignalBufferRouting] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_MDAswitchPC_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_fe762ee1_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_MDAswitchPC_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_fe762ee1_Rx_RxSignalBufferRouting] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_Mode_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_d093cbe5_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Mode_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_d093cbe5_Rx_RxSignalBufferRouting] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve11_State_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a05e13cd_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_State_command_oMSG_MDA_Valve_11_oSchaeffler_MDA_CANFD_a05e13cd_Rx_RxSignalBufferRouting] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_DutyCycle_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_da0ac52e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_DutyCycle_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_da0ac52e_Rx_RxSignalBufferRouting] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_MDAswitchPC_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0ec4c09d_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_MDAswitchPC_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_0ec4c09d_Rx_RxSignalBufferRouting] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_Mode_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_a4980802_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Mode_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_a4980802_Rx_RxSignalBufferRouting] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve12_State_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b0bfffc0_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_State_command_oMSG_MDA_Valve_12_oSchaeffler_MDA_CANFD_b0bfffc0_Rx_RxSignalBufferRouting] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_DutyCycle_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_28352a0b_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_DutyCycle_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_28352a0b_Rx_RxSignalBufferRouting] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_MDAswitchPC_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_e87a6776_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_MDAswitchPC_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_e87a6776_Rx_RxSignalBufferRouting] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_Mode_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3e4e4b60_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Mode_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_3e4e4b60_Rx_RxSignalBufferRouting] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve13_State_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09cfa604_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_State_command_oMSG_MDA_Valve_13_oSchaeffler_MDA_CANFD_09cfa604_Rx_RxSignalBufferRouting] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_DutyCycle_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_9b19ad33_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_DutyCycle_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_9b19ad33_Rx_RxSignalBufferRouting] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_MDAswitchPC_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_34d01a24_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_MDAswitchPC_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_34d01a24_Rx_RxSignalBufferRouting] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_Mode_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4c8f8fcc_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Mode_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_4c8f8fcc_Rx_RxSignalBufferRouting] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve14_State_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_917c27da_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_State_command_oMSG_MDA_Valve_14_oSchaeffler_MDA_CANFD_917c27da_Rx_RxSignalBufferRouting] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_DutyCycle_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_69264216_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_DutyCycle_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_69264216_Rx_RxSignalBufferRouting] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_MDAswitchPC_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d26ebdcf_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_MDAswitchPC_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d26ebdcf_Rx_RxSignalBufferRouting] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_Mode_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d659ccae_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Mode_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_d659ccae_Rx_RxSignalBufferRouting] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve15_State_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_280c7e1e_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_State_command_oMSG_MDA_Valve_15_oSchaeffler_MDA_CANFD_280c7e1e_Rx_RxSignalBufferRouting] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_DutyCycle_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a4177538_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_DutyCycle_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a4177538_Rx_RxSignalBufferRouting] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_MDAswitchPC_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_22dc53b3_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_MDAswitchPC_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_22dc53b3_Rx_RxSignalBufferRouting] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_Mode_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a2520f49_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Mode_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_a2520f49_Rx_RxSignalBufferRouting] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/Sig_Valve16_State_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_38ed9213_Rx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_State_command_oMSG_MDA_Valve_16_oSchaeffler_MDA_CANFD_38ed9213_Rx_RxSignalBufferRouting] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_SigGrpEventFlag
**********************************************************************************************************************/
/** 
  \var    Com_SigGrpEventFlag
  \brief  Flag is set if a group signal write access caused a triggered event.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_SigGrpEventFlagType, COM_VAR_NOINIT) Com_SigGrpEventFlag[2];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TransmitRequest
**********************************************************************************************************************/
/** 
  \var    Com_TransmitRequest
  \brief  Transmit request flag used for decoupled Tx I-PDU tranmission.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TransmitRequestType, COM_VAR_NOINIT) Com_TransmitRequest[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxBuffer
**********************************************************************************************************************/
/** 
  \var    Com_TxBuffer
  \brief  Shared uint8 buffer for Tx I-PDUs and ComSignalGroup shadow buffer.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxBufferType, COM_VAR_NOINIT) Com_TxBuffer[916];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_d3a8bf7b_Tx] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_d3a8bf7b_Tx] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_d3a8bf7b_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_b9c3726a_Tx] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_b9c3726a_Tx] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceFR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_b9c3726a_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_29ebcf6e_Tx] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_29ebcf6e_Tx] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRL_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_29ebcf6e_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_4380027f_Tx] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_4380027f_Tx] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/Sig_MDA_ActiveForceRR_oMSG_MDA_Internal_oSchaeffler_MDA_CANFD_4380027f_Tx] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    63 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx] */
  /*    64 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_dda52c0a_Tx] */
  /*    65 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_dda52c0a_Tx] */
  /*    66 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_4c2f58b5_Tx] */
  /*    67 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_4c2f58b5_Tx] */
  /*    68 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_cc22eb0f_Tx] */
  /*    69 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_cc22eb0f_Tx] */
  /*    70 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_f43eb050_Tx] */
  /*    71 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx] */
  /*    72 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_733b337f_Tx] */
  /*    73 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_733b337f_Tx] */
  /*    74 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_e2b147c0_Tx] */
  /*    75 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_e2b147c0_Tx] */
  /*    76 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_62bcf47a_Tx] */
  /*    77 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_62bcf47a_Tx] */
  /*    78 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_5aa0af25_Tx] */
  /*    79 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx] */
  /*    80 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_e2db3ec2_Tx] */
  /*    81 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_e2db3ec2_Tx] */
  /*    82 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_73514a7d_Tx] */
  /*    83 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_73514a7d_Tx] */
  /*    84 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_f35cf9c7_Tx] */
  /*    85 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_f35cf9c7_Tx] */
  /*    86 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_cb40a298_Tx] */
  /*    87 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx] */
  /*    88 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_4c4521b7_Tx] */
  /*    89 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_4c4521b7_Tx] */
  /*    90 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ddcf5508_Tx] */
  /*    91 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ddcf5508_Tx] */
  /*    92 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_5dc2e6b2_Tx] */
  /*    93 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_5dc2e6b2_Tx] */
  /*    94 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_65debded_Tx] */
  /*    95 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx] */
  /*    96 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_0b4ed38b_Tx] */
  /*    97 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_6a00d445_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_6a00d445_Tx] */
  /*   100 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_6a00d445_Tx] */
  /*   101 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_2be51499_Tx] */
  /*   102 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_2be51499_Tx] */
  /* Index        Referable Keys */
  /*   103 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_4a62e4d4_Tx] */
  /*   104 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_4a62e4d4_Tx] */
  /*   105 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9b045378_Tx] */
  /*   106 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_1fde2ef8_Tx] */
  /*   107 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_1fde2ef8_Tx] */
  /*   108 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_e3458dbb_Tx] */
  /*   109 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_e3458dbb_Tx] */
  /*   110 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_8e197ec3_Tx] */
  /*   111 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9217127b_Tx] */
  /*   112 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_8d24a98a_Tx] */
  /*   113 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ec6aae44_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ec6aae44_Tx] */
  /*   116 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ec6aae44_Tx] */
  /*   117 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ad8f6e98_Tx] */
  /*   118 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ad8f6e98_Tx] */
  /*   119 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_cc089ed5_Tx] */
  /*   120 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_cc089ed5_Tx] */
  /*   121 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_1d6e2979_Tx] */
  /*   122 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_99b454f9_Tx] */
  /*   123 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_99b454f9_Tx] */
  /*   124 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_652ff7ba_Tx] */
  /*   125 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_652ff7ba_Tx] */
  /*   126 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_087304c2_Tx] */
  /*   127 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_147d687a_Tx] */
  /*   128 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_e76042fc_Tx] */
  /*   129 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_862e4532_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_862e4532_Tx] */
  /*   132 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_862e4532_Tx] */
  /*   133 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_c7cb85ee_Tx] */
  /*   134 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_c7cb85ee_Tx] */
  /*   135 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_a64c75a3_Tx] */
  /*   136 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_a64c75a3_Tx] */
  /*   137 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_772ac20f_Tx] */
  /*   138 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_f3f0bf8f_Tx] */
  /*   139 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_f3f0bf8f_Tx] */
  /*   140 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_0f6b1ccc_Tx] */
  /*   141 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_0f6b1ccc_Tx] */
  /*   142 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_6237efb4_Tx] */
  /*   143 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_7e39830c_Tx] */
  /*   144 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_State_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_610a38fd_Tx] */
  /*   145 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_00443f33_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_00443f33_Tx] */
  /*   148 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Current_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_00443f33_Tx] */
  /*   149 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_41a1ffef_Tx] */
  /*   150 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Voltage_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_41a1ffef_Tx] */
  /*   151 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_20260fa2_Tx] */
  /*   152 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Pos_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_20260fa2_Tx] */
  /*   153 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Temp_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f140b80e_Tx] */
  /*   154 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_759ac58e_Tx] */
  /*   155 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Speed_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_759ac58e_Tx] */
  /* Index        Referable Keys */
  /*   156 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_890166cd_Tx] */
  /*   157 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Torque_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_890166cd_Tx] */
  /*   158 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Diags_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_e45d95b5_Tx] */
  /*   159 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/Sig_Mot_Mode_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f853f90d_Tx] */
  /*   160 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_9bb393fa_Tx] */
  /*   161 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_64dd9785_Tx] */
  /*   162 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_75935422_Tx] */
  /*   163 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_35deee4a_Tx] */
  /*   164 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_7f47993e_Tx] */
  /*   165 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_f5c9f897_Tx] */
  /*   166 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_cc91bfa8_Tx] */
  /*   167 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_5b16e910_Tx] */
  /*   168 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_f01fb62d_Tx] */
  /*   169 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_8a006304_Tx] */
  /*   170 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_48a0a659_Tx] */
  /*   171 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_f880c15c_Tx] */
  /*   172 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_ea7577d6_Tx] */
  /*   173 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_2e0da7bc_Tx] */
  /*   174 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_62d5e70c_Tx] */
  /*   175 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_2480143a_Tx] */
  /*   176 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_652d58c5_Tx] */
  /*   177 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_51c43c2f_Tx] */
  /*   178 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_e6e4fefd_Tx] */
  /*   179 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_87163c76_Tx] */
  /*   180 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Channel_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_2fb42fb1_Tx] */
  /*   181 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Cksys_Lack_oMSG_PT2000_oSchaeffler_MDA_CANFD_d19e909a_Tx] */
  /*   182 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Disable_Output_oMSG_PT2000_oSchaeffler_MDA_CANFD_b1c6d2af_Tx] */
  /*   183 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_SPI_Error_oMSG_PT2000_oSchaeffler_MDA_CANFD_b8dd42e3_Tx] */
  /*   184 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   223 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx] */
  /*   224 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_HS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_dc7f0e1c_Tx] */
  /*   225 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_HS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_f6c3be94_Tx] */
  /*   226 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_LS1_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_350a1767_Tx] */
  /*   227 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve1_LS2_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_1fb6a7ef_Tx] */
  /*   228 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_HS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_27ff6475_Tx] */
  /*   229 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_HS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ddc29722_Tx] */
  /*   230 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_LS3_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_ce8a7d0e_Tx] */
  /*   231 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve2_LS4_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_34b78e59_Tx] */
  /*   232 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_HS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_58ae3d07_Tx] */
  /*   233 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_HS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_72128d8f_Tx] */
  /*   234 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_LS5_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_b1db247c_Tx] */
  /*   235 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_Valve3_LS6_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_9b6794f4_Tx] */
  /*   236 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_DCDC_HS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_aa37a69c_Tx] */
  /*   237 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT1_DCDC_LS7_oMSG_PTDriver_01_oSchaeffler_MDA_CANFD_4342bfe7_Tx] */
  /*   238 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   287 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx] */
  /*   288 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_HS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ad20fc3f_Tx] */
  /*   289 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_HS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_879c4cb7_Tx] */
  /* Index        Referable Keys */
  /*   290 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_LS1_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_4455e544_Tx] */
  /*   291 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve4_LS2_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_6ee955cc_Tx] */
  /*   292 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_HS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_02f0e692_Tx] */
  /*   293 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_HS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_f8cd15c5_Tx] */
  /*   294 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_LS3_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_eb85ffe9_Tx] */
  /*   295 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve5_LS4_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_11b80cbe_Tx] */
  /*   296 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_HS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_29f1cf24_Tx] */
  /*   297 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_HS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_034d7fac_Tx] */
  /*   298 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_LS5_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_c084d65f_Tx] */
  /*   299 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_Valve6_LS6_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_ea3866d7_Tx] */
  /*   300 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_DCDC_HS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_964be8d5_Tx] */
  /*   301 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT2_DCDC_LS7_oMSG_PTDriver_02_oSchaeffler_MDA_CANFD_7f3ef1ae_Tx] */
  /*   302 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   351 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx] */
  /*   352 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_HS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_8215adde_Tx] */
  /*   353 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_HS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a8a91d56_Tx] */
  /*   354 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_LS1_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b60b4a5_Tx] */
  /*   355 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve7_LS2_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_41dc042d_Tx] */
  /*   356 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_HS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_5b05e36e_Tx] */
  /*   357 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_HS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_a1381039_Tx] */
  /*   358 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_LS3_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_b270fa15_Tx] */
  /*   359 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve8_LS4_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_484d0942_Tx] */
  /*   360 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_HS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_2454ba1c_Tx] */
  /*   361 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_HS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_0ee80a94_Tx] */
  /*   362 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_LS5_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_cd21a367_Tx] */
  /*   363 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_Valve9_LS6_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_e79d13ef_Tx] */
  /*   364 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_DCDC_HS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_82602d12_Tx] */
  /*   365 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT3_DCDC_LS7_oMSG_PTDriver_03_oSchaeffler_MDA_CANFD_6b153469_Tx] */
  /*   366 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   415 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx] */
  /*   416 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_HS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_3529bf8d_Tx] */
  /*   417 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_HS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_1f950f05_Tx] */
  /*   418 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_LS1_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_dc5ca6f6_Tx] */
  /*   419 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve10_LS2_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_f6e0167e_Tx] */
  /*   420 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_HS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9af9a520_Tx] */
  /*   421 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_HS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_60c45677_Tx] */
  /*   422 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_LS3_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_738cbc5b_Tx] */
  /*   423 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve11_LS4_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_89b14f0c_Tx] */
  /*   424 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_HS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_b1f88c96_Tx] */
  /*   425 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_HS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_9b443c1e_Tx] */
  /*   426 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_LS5_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_588d95ed_Tx] */
  /*   427 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_Valve12_LS6_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_72312565_Tx] */
  /*   428 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_DCDC_HS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_eeb37447_Tx] */
  /*   429 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT4_DCDC_LS7_oMSG_PTDriver_04_oSchaeffler_MDA_CANFD_07c66d3c_Tx] */
  /*   430 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   479 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx] */
  /*   480 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_HS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_b9eee1f2_Tx] */
  /* Index        Referable Keys */
  /*   481 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_HS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_9352517a_Tx] */
  /*   482 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_LS1_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_509bf889_Tx] */
  /*   483 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve13_LS2_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7a274801_Tx] */
  /*   484 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_HS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_eace6a13_Tx] */
  /*   485 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_HS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_10f39944_Tx] */
  /*   486 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_LS3_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_03bb7368_Tx] */
  /*   487 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve14_LS4_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_f986803f_Tx] */
  /*   488 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_HS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_959f3361_Tx] */
  /*   489 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_HS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_bf2383e9_Tx] */
  /*   490 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_LS5_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_7cea2a1a_Tx] */
  /*   491 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_Valve15_LS6_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_56569a92_Tx] */
  /*   492 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_DCDC_HS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_fa98b180_Tx] */
  /*   493 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT5_DCDC_LS7_oMSG_PTDriver_05_oSchaeffler_MDA_CANFD_13eda8fb_Tx] */
  /*   494 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   543 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx] */
  /*   544 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_HS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_f7d60532_Tx] */
  /*   545 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_HS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_dd6ab5ba_Tx] */
  /*   546 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_LS1_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_1ea31c49_Tx] */
  /*   547 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_Valve16_LS2_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_341facc1_Tx] */
  /*   548 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_DCDC_HS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_c6e4ffc9_Tx] */
  /*   549 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/Sig_PT6_DCDC_LS7_oMSG_PTDriver_06_oSchaeffler_MDA_CANFD_2f91e6b2_Tx] */
  /*   550 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   607 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx] */
  /*   608 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_TxSigGrpInTxIPDU] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_TxSigGrpInTxIPDU] */
  /*   665 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_TxSigGrpInTxIPDU] */
  /*   666 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   671 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx] */
  /*   672 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_TxSigGrpInTxIPDU] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_TxSigGrpInTxIPDU] */
  /*   729 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_TxSigGrpInTxIPDU] */
  /*   730 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   735 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx] */
  /*   736 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_8ece5c4e_Tx] */
  /*   737 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve1_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_0bdb9dd5_Tx] */
  /*   738 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_f0b614e8_Tx] */
  /*   739 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve2_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_75a3d573_Tx] */
  /*   740 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_da9e2c8a_Tx] */
  /*   741 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve3_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_5f8bed11_Tx] */
  /*   742 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_0c4685a4_Tx] */
  /*   743 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve4_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_8953443f_Tx] */
  /*   744 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_266ebdc6_Tx] */
  /*   745 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve5_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_a37b7c5d_Tx] */
  /*   746 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_5816f560_Tx] */
  /*   747 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve6_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_dd0334fb_Tx] */
  /*   748 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_723ecd02_Tx] */
  /* Index        Referable Keys */
  /*   749 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve7_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_f72b0c99_Tx] */
  /*   750 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_2ed6a17d_Tx] */
  /*   751 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve8_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_abc360e6_Tx] */
  /*   752 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_04fe991f_Tx] */
  /*   753 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve9_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_81eb5884_Tx] */
  /*   754 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_318f22ad_Tx] */
  /*   755 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve10_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_b49ae336_Tx] */
  /*   756 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_1ba71acf_Tx] */
  /*   757 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve11_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_9eb2db54_Tx] */
  /*   758 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_65df5269_Tx] */
  /*   759 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve12_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_e0ca93f2_Tx] */
  /*   760 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_4ff76a0b_Tx] */
  /*   761 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve13_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_cae2ab90_Tx] */
  /*   762 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_992fc325_Tx] */
  /*   763 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve14_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_1c3a02be_Tx] */
  /*   764 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_b307fb47_Tx] */
  /*   765 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve15_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_36123adc_Tx] */
  /*   766 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_State_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_cd7fb3e1_Tx] */
  /*   767 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/Sig_Valve16_Diags_fbk_oMSG_Valve_oSchaeffler_MDA_CANFD_486a727a_Tx] */
  /*   768 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   799 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx] */
  /*   800 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_CRC_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_31745b74_Tx] */
  /*   801 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Counter_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_5e38a8f5_Tx] */
  /*   802 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx] */
  /*   803 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx] */
  /*   804 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx] */
  /*   805 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx] */
  /*   806 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx] */
  /*   807 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx] */
  /*   808 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx] */
  /*   809 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx] */
  /*   810 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx] */
  /*   811 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx] */
  /*   812 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx] */
  /*   813 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx] */
  /*   814 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx] */
  /*   815 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx] */
  /*   816 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx] */
  /*   817 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx] */
  /*   818 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx] */
  /*   819 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx] */
  /*   820 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx] */
  /*   821 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx] */
  /*   822 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx] */
  /*   823 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx] */
  /*   824 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx] */
  /*   825 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx] */
  /*   826 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx] */
  /*   827 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx] */
  /* Index        Referable Keys */
  /*   828 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx] */
  /*   829 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx] */
  /*   830 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx] */
  /*   831 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx] */
  /*   832 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx] */
  /*   833 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx] */
  /*   834 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx] */
  /*   835 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx] */
  /*   836 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx] */
  /*   837 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx] */
  /*   838 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx] */
  /*   839 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx] */
  /*   840 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx] */
  /*   841 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_AngleRate_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9378dbfb_Tx] */
  /*   842 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Steering_AngleRate_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9378dbfb_Tx] */
  /*   843 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_Sensor_Power_Diag_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_70e35f64_Tx] */
  /*   844 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL1_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0242ca9f_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL1_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0242ca9f_Tx] */
  /*   848 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL1_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0242ca9f_Tx] */
  /*   849 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL2_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3d89b40a_Tx] */
  /*   850 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*   856 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx] */
  /*   857 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx/Sig_ETL3_ID_B10_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9e1f9c46_Tx] */
  /*   858 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_CRC_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_ca199fab_Tx] */
  /*   859 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_Counter_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a5556c2a_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx] */
  /*   860 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx] */
  /*   861 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx] */
  /*   862 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx] */
  /*   863 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx] */
  /*   864 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx] */
  /*   865 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx] */
  /*   866 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx] */
  /*   867 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx] */
  /*   868 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx] */
  /*   869 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx] */
  /*   870 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx] */
  /*   871 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx] */
  /*   872 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx] */
  /*   873 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx] */
  /*   874 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx] */
  /*   875 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx] */
  /*   876 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx] */
  /*   877 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx] */
  /*   878 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx] */
  /*   879 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx] */
  /*   880 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx] */
  /*   881 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx] */
  /*   882 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx] */
  /*   883 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL1_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_f92f0e40_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx] */
  /* Index        Referable Keys */
  /*   884 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL1_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_f92f0e40_Tx] */
  /*   885 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   890 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   891 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL2_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_c6e470d5_Tx] */
  /*   892 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   898 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   899 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL3_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_65725899_Tx] */
  /*   900 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   906 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   907 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL4_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b9728dff_Tx] */
  /*   908 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   ... */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   914 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx] */
  /*   915 */  /* [/ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx, /ActiveEcuC/Com/ComConfig/SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx/Sig_ETL5_ID_B11_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_1ae4a5b3_Tx] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxCyclicProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxCyclicProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxCyclicProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxDeadlineMonitoringISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxDeadlineMonitoringISRLockCounterType, COM_VAR_NOINIT) Com_TxDeadlineMonitoringISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxIPduGroupISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxIPduGroupISRLockCounterType, COM_VAR_NOINIT) Com_TxIPduGroupISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxPduGrpActive
**********************************************************************************************************************/
/** 
  \var    Com_TxPduGrpActive
  \brief  Tx I-PDU based state (started/stopped) of the corresponding I-PDU-Group.
*/ 
#define COM_START_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxPduGrpActiveType, COM_VAR_NOINIT) Com_TxPduGrpActive[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_8BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxProcessingISRLockCounter
**********************************************************************************************************************/
#define COM_START_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxProcessingISRLockCounterType, COM_VAR_NOINIT) Com_TxProcessingISRLockCounter;  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
#define COM_STOP_SEC_VAR_NOINIT_16BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */

/**********************************************************************************************************************
  Com_TxSduLength
**********************************************************************************************************************/
/** 
  \var    Com_TxSduLength
  \brief  This var Array contains the Com Ipdu Length.
*/ 
#define COM_START_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */
VAR(Com_TxSduLengthType, COM_VAR_NOINIT) Com_TxSduLength[19];  /* PRQA S 1514, 1533 */  /* MD_CSL_ObjectOnlyAccessedOnce */
  /* Index        Referable Keys */
  /*     0 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_Internal_oSchaeffler_MDA_CANFD_a13999ba_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     1 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_ead19aa8_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFL_CANFD_Tx_8e26ecac] */
  /*     2 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_fd9f5d23_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorFR_CANFD_Tx_b7415df7] */
  /*     3 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_0fa880dd_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRL_CANFD_Tx_90095be5] */
  /*     4 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_18e64756_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MotorRR_CANFD_Tx_a96eeabe] */
  /*     5 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFL_oSchaeffler_MDA_CANFD_99f90215_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     6 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorFR_oSchaeffler_MDA_CANFD_75f8b505_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     7 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRL_oSchaeffler_MDA_CANFD_8f94e377_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     8 */  /* [/ActiveEcuC/Com/ComConfig/MSG_MotorRR_oSchaeffler_MDA_CANFD_63955467_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*     9 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PT2000_oSchaeffler_MDA_CANFD_d4e6fb05_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    10 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_01_oSchaeffler_MDA_CANFD_33033105_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    11 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_02_oSchaeffler_MDA_CANFD_45e60838_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    12 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_03_oSchaeffler_MDA_CANFD_de95e2ec_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    13 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_04_oSchaeffler_MDA_CANFD_a82c7a42_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    14 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_05_oSchaeffler_MDA_CANFD_335f9096_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    15 */  /* [/ActiveEcuC/Com/ComConfig/MSG_PTDriver_06_oSchaeffler_MDA_CANFD_45baa9ab_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    16 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_01_oSchaeffler_MDA_CANFD_37b39265_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    17 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Sensor_02_oSchaeffler_MDA_CANFD_4156ab58_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */
  /*    18 */  /* [/ActiveEcuC/Com/ComConfig/MSG_Valve_oSchaeffler_MDA_CANFD_e27dcce6_Tx, /ActiveEcuC/Com/ComConfig/MDA_oSchaeffler_MDA_CANFD_Tx_615787b5] */

#define COM_STOP_SEC_VAR_NOINIT_32BIT
/*lint -save -esym(961, 19.1) */
#include "MemMap.h"  /* PRQA S 5087 */  /* MD_MSR_MemMap */
/*lint -restore */


/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL DATA
**********************************************************************************************************************/


/**********************************************************************************************************************
  LOCAL FUNCTION PROTOTYPES
**********************************************************************************************************************/



/**********************************************************************************************************************
  LOCAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  GLOBAL FUNCTIONS
**********************************************************************************************************************/
/**********************************************************************************************************************
  CONFIGURATION CLASS: PRE_COMPILE
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/

/**********************************************************************************************************************
  CONFIGURATION CLASS: LINK
  SECTION: GLOBAL FUNCTIONS
**********************************************************************************************************************/






/**********************************************************************************************************************
  END OF FILE: Com_Lcfg.c
**********************************************************************************************************************/

