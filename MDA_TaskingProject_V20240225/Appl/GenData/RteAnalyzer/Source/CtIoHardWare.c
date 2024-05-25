/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtIoHardWare.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtIoHardWare
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtIoHardWare>
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

#include "Rte_CtIoHardWare.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtIoHardWare.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"

static void CtIoHardWare_TestDefines(void);


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
 *
 * Record Types:
 * =============
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
 *
 *********************************************************************************************************************/


#define CtIoHardWare_START_SEC_CODE
#include "CtIoHardWare_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: Adc_Write
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 1ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpIMU_IMUAcc(const IMUAcc *data)
 *   Std_ReturnType Rte_Write_PpIMU_IMUAngle(const IMUAngle *data)
 *   Std_ReturnType Rte_Write_PpIMU_IMURate(const IMURate *data)
 *   Std_ReturnType Rte_Write_PpIMU_IMUVel(const IMUVel *data)
 *   Std_ReturnType Rte_Write_PpPedlPos_PedlPos(const PedlPos *data)
 *   Std_ReturnType Rte_Write_PpPressure_Pressure(const Pressure *data)
 *   Std_ReturnType Rte_Write_PpSteerWhl_SteerWhl(const SteerWhl *data)
 *   Std_ReturnType Rte_Write_PpSuspHeight_SuspHeight(const SuspHeight *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc_Write_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtIoHardWare_CODE) Adc_Write(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Adc_Write
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  IMUAcc Write_PpIMU_IMUAcc;
  IMUAngle Write_PpIMU_IMUAngle;
  IMURate Write_PpIMU_IMURate;
  IMUVel Write_PpIMU_IMUVel;
  PedlPos Write_PpPedlPos_PedlPos;
  Pressure Write_PpPressure_Pressure;
  SteerWhl Write_PpSteerWhl_SteerWhl;
  SuspHeight Write_PpSuspHeight_SuspHeight;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_PpIMU_IMUAcc, 0, sizeof(Write_PpIMU_IMUAcc));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMUAcc(&Write_PpIMU_IMUAcc);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpIMU_IMUAngle, 0, sizeof(Write_PpIMU_IMUAngle));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMUAngle(&Write_PpIMU_IMUAngle);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpIMU_IMURate, 0, sizeof(Write_PpIMU_IMURate));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMURate(&Write_PpIMU_IMURate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpIMU_IMUVel, 0, sizeof(Write_PpIMU_IMUVel));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMUVel(&Write_PpIMU_IMUVel);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpPedlPos_PedlPos, 0, sizeof(Write_PpPedlPos_PedlPos));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpPedlPos_PedlPos(&Write_PpPedlPos_PedlPos);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpPressure_Pressure, 0, sizeof(Write_PpPressure_Pressure));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpPressure_Pressure(&Write_PpPressure_Pressure);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpSteerWhl_SteerWhl, 0, sizeof(Write_PpSteerWhl_SteerWhl));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpSteerWhl_SteerWhl(&Write_PpSteerWhl_SteerWhl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpSuspHeight_SuspHeight, 0, sizeof(Write_PpSuspHeight_SuspHeight));
  fct_status = TSC_CtIoHardWare_Rte_Write_PpSuspHeight_SuspHeight(&Write_PpSuspHeight_SuspHeight);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  CtIoHardWare_TestDefines();


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtIoHardWare_STOP_SEC_CODE
#include "CtIoHardWare_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CtIoHardWare_TestDefines(void)
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
