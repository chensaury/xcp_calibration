/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtMDA_Control_Logic.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtMDA_Control_Logic
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtMDA_Control_Logic>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Operation Prototypes:
 * =====================
 * PT2000_Enable_mode of Port Interface PiPT2000_Ctrl
 *   
 *
 * PT2000_Init of Port Interface PiPT2000_Ctrl
 *   
 *
 * PT2000_Mode_Change of Port Interface PiPT2000_Ctrl
 *   
 *
 * Set_ConstantCurrent of Port Interface PiPT2000_Ctrl
 *   
 *
 *********************************************************************************************************************/

#include "Rte_CtMDA_Control_Logic.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtMDA_Control_Logic.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void CtMDA_Control_Logic_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * BodyAcc: Record with elements
 *   BodyAccZFL of type float32
 *   BodyAccZFR of type float32
 *   BodyAccZRL of type float32
 *   BodyAccZRR of type float32
 * IMUAcc: Record with elements
 *   IMUAccX of type float32
 *   IMUAccY of type float32
 *   IMUAccZ of type float32
 * IMUAngle: Record with elements
 *   IMUPitchAngle of type float32
 *   IMURollAngle of type float32
 *   IMUYawAngle of type float32
 * IMURate: Record with elements
 *   IMURollRate of type float32
 *   IMUPitchRate of type float32
 *   IMUYawRate of type float32
 * IMUVel: Record with elements
 *   IMUVelNorth of type float32
 *   IMUVelEast of type float32
 *   IMUVelEarth of type float32
 * MotActFL: Record with elements
 *   MotFLActSts of type uint8
 *   MotFLActCurrent of type float32
 *   MotFLActVoltage of type float32
 *   MotFLActPos of type float32
 *   MotFLActTemp of type float32
 *   MotFLActSpd of type float32
 *   MotFLActTorq of type float32
 *   MotFLDiagSts of type uint8
 * MotActFR: Record with elements
 *   MotFRActSts of type uint8
 *   MotFRActCurrent of type float32
 *   MotFRActVoltage of type float32
 *   MotFRActPos of type float32
 *   MotFRActTemp of type float32
 *   MotFRActSpd of type float32
 *   MotFRActTorq of type float32
 *   MotFRDiagSts of type uint8
 * MotActRL: Record with elements
 *   MotRLActSts of type uint8
 *   MotRLActCurrent of type float32
 *   MotRLActVoltage of type float32
 *   MotRLActPos of type float32
 *   MotRLActTemp of type float32
 *   MotRLActSpd of type float32
 *   MotRLActTorq of type float32
 *   MotRLDiagSts of type uint8
 * MotActRR: Record with elements
 *   MotRRActSts of type uint8
 *   MotRRActCurrent of type float32
 *   MotRRActVoltage of type float32
 *   MotRRActPos of type float32
 *   MotRRActTemp of type float32
 *   MotRRActSpd of type float32
 *   MotRRActTorq of type float32
 *   MotRRDiagSts of type uint8
 * MotTgtOutFL: Record with elements
 *   MotTgtSpdFL of type float32
 *   MotTgtTorqFL of type float32
 *   MotTgtModeFL of type uint8
 *   MotTgtPosFL of type float32
 *   Mot_Mode_PreSC_FL of type uint8
 * MotTgtOutFR: Record with elements
 *   MotTgtSpdFR of type float32
 *   MotTgtTorqFR of type float32
 *   MotTgtModeFR of type uint8
 *   MotTgtPosFR of type float32
 *   Mot_Mode_PreSC_FR of type uint8
 * MotTgtOutRL: Record with elements
 *   MotTgtSpdRL of type float32
 *   MotTgtTorqRL of type float32
 *   MotTgtModeRL of type uint8
 *   MotTgtPosRL of type float32
 *   Mot_Mode_PreSC_RL of type uint8
 * MotTgtOutRR: Record with elements
 *   MotTgtSpdRR of type float32
 *   MotTgtTorqRR of type float32
 *   MotTgtModeRR of type uint8
 *   MotTgtPosRR of type float32
 *   Mot_Mode_PreSC_RR of type uint8
 * PedlPos: Record with elements
 *   AccPedlPos of type float32
 *   BrkPedlPos of type float32
 * Pressure: Record with elements
 *   PressureFL1 of type float32
 *   PressureFL2 of type float32
 *   PressureFR1 of type float32
 *   PressureFR2 of type float32
 *   PressureRL1 of type float32
 *   PressureRL2 of type float32
 *   PressureRR1 of type float32
 *   PressureRR2 of type float32
 * SteerWhl: Record with elements
 *   SteerWhlAngle of type float32
 *   SteerWhlAngleRate of type float32
 *   SteerWhlHandTrq of type float32
 * SuspHeight: Record with elements
 *   SuspHeightFL of type float32
 *   SuspHeightFR of type float32
 *   SuspHeightRL of type float32
 *   SuspHeightRR of type float32
 * VlvActFL: Record with elements
 *   VlvFLSts1 of type uint8
 *   VlvFLSts2 of type uint8
 *   VlvFLDiagSts1 of type uint8
 *   VlvFLDiagSts2 of type uint8
 * VlvActFR: Record with elements
 *   VlvFRSts1 of type uint8
 *   VlvFRSts2 of type uint8
 *   VlvFRDiagSts1 of type uint8
 *   VlvFRDiagSts2 of type uint8
 * VlvActRL: Record with elements
 *   VlvRLSts1 of type uint8
 *   VlvRLSts2 of type uint8
 *   VlvRLDiagSts1 of type uint8
 *   VlvRLDiagSts2 of type uint8
 * VlvActRR: Record with elements
 *   VlvRRSts1 of type uint8
 *   VlvRRSts2 of type uint8
 *   VlvRRDiagSts1 of type uint8
 *   VlvRRDiagSts2 of type uint8
 * VlvTgtCurrent: Record with elements
 *   VlvTgtCurrentFL1 of type uint16
 *   VlvTgtCurrentFL2 of type uint16
 *   VlvTgtCurrentFR1 of type uint16
 *   VlvTgtCurrentFR2 of type uint16
 *   VlvTgtCurrentRL1 of type uint16
 *   VlvTgtCurrentRL2 of type uint16
 *   VlvTgtCurrentRR1 of type uint16
 *   VlvTgtCurrentRR2 of type uint16
 * VlvTgtFlutter: Record with elements
 *   VlvTgtFlutterFL1 of type uint16
 *   VlvTgtFlutterFL2 of type uint16
 *   VlvTgtFlutterFR1 of type uint16
 *   VlvTgtFlutterFR2 of type uint16
 *   VlvTgtFlutterRL1 of type uint16
 *   VlvTgtFlutterRL2 of type uint16
 *   VlvTgtFlutterRR1 of type uint16
 *   VlvTgtFlutterRR2 of type uint16
 * VlvTgtFrequency: Record with elements
 *   VlvTgtFrequencyFL1 of type uint16
 *   VlvTgtFrequencyFL2 of type uint16
 *   VlvTgtFrequencyFR1 of type uint16
 *   VlvTgtFrequencyFR2 of type uint16
 *   VlvTgtFrequencyRL1 of type uint16
 *   VlvTgtFrequencyRL2 of type uint16
 *   VlvTgtFrequencyRR1 of type uint16
 *   VlvTgtFrequencyRR2 of type uint16
 * WhlAcc: Record with elements
 *   WhlAccZFL of type float32
 *   WhlAccZFR of type float32
 *   WhlAccZRL of type float32
 *   WhlAccZRR of type float32
 *
 *********************************************************************************************************************/


#define CtMDA_Control_Logic_START_SEC_CODE
#include "CtMDA_Control_Logic_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: MDA_Control_Logic
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PpBodyAccZ_BodyAcc(BodyAcc *data)
 *   Std_ReturnType Rte_Read_PpIMU_IMUAcc(IMUAcc *data)
 *   Std_ReturnType Rte_Read_PpIMU_IMUAngle(IMUAngle *data)
 *   Std_ReturnType Rte_Read_PpIMU_IMURate(IMURate *data)
 *   Std_ReturnType Rte_Read_PpIMU_IMUVel(IMUVel *data)
 *   Std_ReturnType Rte_Read_PpMotFLAct_MotFLAct(MotActFL *data)
 *   Std_ReturnType Rte_Read_PpMotFRAct_MotFRAct(MotActFR *data)
 *   Std_ReturnType Rte_Read_PpMotRLAct_MotRLAct(MotActRL *data)
 *   Std_ReturnType Rte_Read_PpMotRRAct_MotRRAct(MotActRR *data)
 *   Std_ReturnType Rte_Read_PpPedlPos_PedlPos(PedlPos *data)
 *   Std_ReturnType Rte_Read_PpPressure_Pressure(Pressure *data)
 *   Std_ReturnType Rte_Read_PpSteerWhl_SteerWhl(SteerWhl *data)
 *   Std_ReturnType Rte_Read_PpSuspHeight_SuspHeight(SuspHeight *data)
 *   Std_ReturnType Rte_Read_PpVelFbAll_VlvFL(VlvActFL *data)
 *   Std_ReturnType Rte_Read_PpVelFbAll_VlvFR(VlvActFR *data)
 *   Std_ReturnType Rte_Read_PpVelFbAll_VlvRL(VlvActRL *data)
 *   Std_ReturnType Rte_Read_PpVelFbAll_VlvRR(VlvActRR *data)
 *   Std_ReturnType Rte_Read_PpWhlAccZ_WhlAcc(WhlAcc *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpMotTgtOutFL_MotTgtOutFL(const MotTgtOutFL *data)
 *   Std_ReturnType Rte_Write_PpMotTgtOutFR_MotTgtOutFR(const MotTgtOutFR *data)
 *   Std_ReturnType Rte_Write_PpMotTgtOutRL_MotTgtOutRL(const MotTgtOutRL *data)
 *   Std_ReturnType Rte_Write_PpMotTgtOutRR_MotTgtOutRR(const MotTgtOutRR *data)
 *   Std_ReturnType Rte_Write_PpVlvTgtCCFF_VlvTgtChannel(uint8 data)
 *   Std_ReturnType Rte_Write_PpVlvTgtCCFF_VlvTgtCurrent(const VlvTgtCurrent *data)
 *   Std_ReturnType Rte_Write_PpVlvTgtCCFF_VlvTgtFlutter(const VlvTgtFlutter *data)
 *   Std_ReturnType Rte_Write_PpVlvTgtCCFF_VlvTgtFrequency(const VlvTgtFrequency *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PoPT2000_Ctrl_PT2000_Init(uint8 init)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: MDA_Control_Logic_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtMDA_Control_Logic_CODE) MDA_Control_Logic(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: MDA_Control_Logic
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  BodyAcc Read_PpBodyAccZ_BodyAcc;
  IMUAcc Read_PpIMU_IMUAcc;
  IMUAngle Read_PpIMU_IMUAngle;
  IMURate Read_PpIMU_IMURate;
  IMUVel Read_PpIMU_IMUVel;
  MotActFL Read_PpMotFLAct_MotFLAct;
  MotActFR Read_PpMotFRAct_MotFRAct;
  MotActRL Read_PpMotRLAct_MotRLAct;
  MotActRR Read_PpMotRRAct_MotRRAct;
  PedlPos Read_PpPedlPos_PedlPos;
  Pressure Read_PpPressure_Pressure;
  SteerWhl Read_PpSteerWhl_SteerWhl;
  SuspHeight Read_PpSuspHeight_SuspHeight;
  VlvActFL Read_PpVelFbAll_VlvFL;
  VlvActFR Read_PpVelFbAll_VlvFR;
  VlvActRL Read_PpVelFbAll_VlvRL;
  VlvActRR Read_PpVelFbAll_VlvRR;
  WhlAcc Read_PpWhlAccZ_WhlAcc;

  MotTgtOutFL Write_PpMotTgtOutFL_MotTgtOutFL;
  MotTgtOutFR Write_PpMotTgtOutFR_MotTgtOutFR;
  MotTgtOutRL Write_PpMotTgtOutRL_MotTgtOutRL;
  MotTgtOutRR Write_PpMotTgtOutRR_MotTgtOutRR;
  VlvTgtCurrent Write_PpVlvTgtCCFF_VlvTgtCurrent;
  VlvTgtFlutter Write_PpVlvTgtCCFF_VlvTgtFlutter;
  VlvTgtFrequency Write_PpVlvTgtCCFF_VlvTgtFrequency;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpBodyAccZ_BodyAcc(&Read_PpBodyAccZ_BodyAcc);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUAcc(&Read_PpIMU_IMUAcc);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUAngle(&Read_PpIMU_IMUAngle);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMURate(&Read_PpIMU_IMURate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpIMU_IMUVel(&Read_PpIMU_IMUVel);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpMotFLAct_MotFLAct(&Read_PpMotFLAct_MotFLAct);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpMotFRAct_MotFRAct(&Read_PpMotFRAct_MotFRAct);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpMotRLAct_MotRLAct(&Read_PpMotRLAct_MotRLAct);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpMotRRAct_MotRRAct(&Read_PpMotRRAct_MotRRAct);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpPedlPos_PedlPos(&Read_PpPedlPos_PedlPos);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpPressure_Pressure(&Read_PpPressure_Pressure);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpSteerWhl_SteerWhl(&Read_PpSteerWhl_SteerWhl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpSuspHeight_SuspHeight(&Read_PpSuspHeight_SuspHeight);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvFL(&Read_PpVelFbAll_VlvFL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvFR(&Read_PpVelFbAll_VlvFR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvRL(&Read_PpVelFbAll_VlvRL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpVelFbAll_VlvRR(&Read_PpVelFbAll_VlvRR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Read_PpWhlAccZ_WhlAcc(&Read_PpWhlAccZ_WhlAcc);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_NEVER_RECEIVED:
      fct_error = 1;
      break;
    case RTE_E_INVALID:
      fct_error = 1;
      break;
    case RTE_E_MAX_AGE_EXCEEDED:
      fct_error = 1;
      break;
  }

  (void)memset(&Write_PpMotTgtOutFL_MotTgtOutFL, 0, sizeof(Write_PpMotTgtOutFL_MotTgtOutFL));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutFL_MotTgtOutFL(&Write_PpMotTgtOutFL_MotTgtOutFL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpMotTgtOutFR_MotTgtOutFR, 0, sizeof(Write_PpMotTgtOutFR_MotTgtOutFR));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutFR_MotTgtOutFR(&Write_PpMotTgtOutFR_MotTgtOutFR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpMotTgtOutRL_MotTgtOutRL, 0, sizeof(Write_PpMotTgtOutRL_MotTgtOutRL));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutRL_MotTgtOutRL(&Write_PpMotTgtOutRL_MotTgtOutRL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpMotTgtOutRR_MotTgtOutRR, 0, sizeof(Write_PpMotTgtOutRR_MotTgtOutRR));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpMotTgtOutRR_MotTgtOutRR(&Write_PpMotTgtOutRR_MotTgtOutRR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtChannel(Rte_InitValue_PpVlvTgtCCFF_VlvTgtChannel);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpVlvTgtCCFF_VlvTgtCurrent, 0, sizeof(Write_PpVlvTgtCCFF_VlvTgtCurrent));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtCurrent(&Write_PpVlvTgtCCFF_VlvTgtCurrent);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpVlvTgtCCFF_VlvTgtFlutter, 0, sizeof(Write_PpVlvTgtCCFF_VlvTgtFlutter));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtFlutter(&Write_PpVlvTgtCCFF_VlvTgtFlutter);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpVlvTgtCCFF_VlvTgtFrequency, 0, sizeof(Write_PpVlvTgtCCFF_VlvTgtFrequency));
  fct_status = TSC_CtMDA_Control_Logic_Rte_Write_PpVlvTgtCCFF_VlvTgtFrequency(&Write_PpVlvTgtCCFF_VlvTgtFrequency);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Enable_mode(0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Init(0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_PT2000_Mode_Change(0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_Set_ConstantCurrent(0U, 0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CtMDA_Control_Logic_Rte_Call_PoPT2000_Ctrl_Set_Peak_Hold(0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
  }

  CtMDA_Control_Logic_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtMDA_Control_Logic_STOP_SEC_CODE
#include "CtMDA_Control_Logic_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CtMDA_Control_Logic_TestDefines(void)
{
  /* Primitive Types */

  float32 Test_float32_LL_1 = AccPedlPos_LowerLimit;
  float32 Test_float32_UL_1 = AccPedlPos_UpperLimit;
  float32 Test_float32_LL_2 = PressureRR1_LowerLimit;
  float32 Test_float32_UL_2 = PressureRR1_UpperLimit;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
