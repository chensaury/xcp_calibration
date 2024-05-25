/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Spi.c
 *        Config:  Bsw_Project.dpa
 *    BSW Module:  Spi
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for BSW Module <Spi>
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

#include "SchM_Spi.h"
#include "TSC_SchM_Spi.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


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
 * ComM_InhibitionStatusType: Integer in interval [0...255]
 * ComM_UserHandleType: Integer in interval [0...255]
 * CounterType: Integer in interval [0...255]
 * EcuM_TimeType: Integer in interval [0...4294967295]
 * EcuM_UserType: Integer in interval [0...255]
 * NetworkHandleType: Integer in interval [0...255]
 * TimeInMicrosecondsType: Integer in interval [0...4294967295]
 * boolean: Boolean (standard type)
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint16: Integer in interval [0...65535] (standard type)
 * uint32: Integer in interval [0...4294967295] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * BswM_ESH_Mode: Enumeration of integer in interval [0...255] with enumerators
 * BswM_ESH_RunRequest: Enumeration of integer in interval [0...255] with enumerators
 * ComM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_BootTargetType: Enumeration of integer in interval [0...2] with enumerators
 * EcuM_ModeType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_ShutdownCauseType: Enumeration of integer in interval [0...3] with enumerators
 * EcuM_StateType: Enumeration of integer in interval [0...144] with enumerators
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


#define SPI_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Schedulable Entity Name: Spi_MainFunction_Handling
 *
 *********************************************************************************************************************/

FUNC(void, SPI_CODE) Spi_MainFunction_Handling(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Spi_MainFunction_Handling
 *********************************************************************************************************************/

  TSC_Spi_SchM_Enter_Spi_Buffer_Update();
  TSC_Spi_SchM_Exit_Spi_Buffer_Update();
  TSC_Spi_SchM_Enter_Spi_Cancel_Seq();
  TSC_Spi_SchM_Exit_Spi_Cancel_Seq();
  TSC_Spi_SchM_Enter_Spi_ChannelLock();
  TSC_Spi_SchM_Exit_Spi_ChannelLock();
  TSC_Spi_SchM_Enter_Spi_Queue_Update();
  TSC_Spi_SchM_Exit_Spi_Queue_Update();
  TSC_Spi_SchM_Enter_Spi_Queue_Update_QSPI0();
  TSC_Spi_SchM_Exit_Spi_Queue_Update_QSPI0();
  TSC_Spi_SchM_Enter_Spi_Queue_Update_QSPI1();
  TSC_Spi_SchM_Exit_Spi_Queue_Update_QSPI1();
  TSC_Spi_SchM_Enter_Spi_Queue_Update_QSPI2();
  TSC_Spi_SchM_Exit_Spi_Queue_Update_QSPI2();
  TSC_Spi_SchM_Enter_Spi_Queue_Update_QSPI3();
  TSC_Spi_SchM_Exit_Spi_Queue_Update_QSPI3();
  TSC_Spi_SchM_Enter_Spi_Queue_Update_QSPI4();
  TSC_Spi_SchM_Exit_Spi_Queue_Update_QSPI4();
  TSC_Spi_SchM_Enter_Spi_Queue_Update_QSPI5();
  TSC_Spi_SchM_Exit_Spi_Queue_Update_QSPI5();
  TSC_Spi_SchM_Enter_Spi_SyncLock();
  TSC_Spi_SchM_Exit_Spi_SyncLock();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define SPI_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


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
