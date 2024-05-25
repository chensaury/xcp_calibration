/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtPT2000_Handler.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtPT2000_Handler
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtPT2000_Handler>
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

#include "Rte_CtPT2000_Handler.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtPT2000_Handler.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "AppPT2000.h"

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
 * uint16: Integer in interval [0...65535] (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
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
 *
 *********************************************************************************************************************/


#define CtPT2000_Handler_START_SEC_CODE
#include "CtPT2000_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

  VlvActFL Write_PpVelFbAll_VlvFL;
  VlvActFR Write_PpVelFbAll_VlvFR;
  VlvActRL Write_PpVelFbAll_VlvRL;
  VlvActRR Write_PpVelFbAll_VlvRR;

  static int test = 0;

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PT2000_Diag_HD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PT2000_Diag_HD_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PT2000_Diag_HD(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PT2000_Diag_HD
 *********************************************************************************************************************/

	//valve_diag();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PT2000_Main_HD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 3ms
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PpVlvTgtCCFF_VlvTgtChannel(uint8 *data)
 *   Std_ReturnType Rte_Read_PpVlvTgtCCFF_VlvTgtCurrent(VlvTgtCurrent *data)
 *   Std_ReturnType Rte_Read_PpVlvTgtCCFF_VlvTgtFlutter(VlvTgtFlutter *data)
 *   Std_ReturnType Rte_Read_PpVlvTgtCCFF_VlvTgtFrequency(VlvTgtFrequency *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpVelFbAll_VlvFL(const VlvActFL *data)
 *   Std_ReturnType Rte_Write_PpVelFbAll_VlvFR(const VlvActFR *data)
 *   Std_ReturnType Rte_Write_PpVelFbAll_VlvRL(const VlvActRL *data)
 *   Std_ReturnType Rte_Write_PpVelFbAll_VlvRR(const VlvActRR *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PT2000_Main_HD_doc
 *********************************************************************************************************************/

uint16 Timer_coda  = 0;
uint16 Timer_coda1  = 0;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PT2000_Main_HD(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PT2000_Main_HD
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  uint8 Read_PpVlvTgtCCFF_VlvTgtChannel;
  VlvTgtCurrent Read_PpVlvTgtCCFF_VlvTgtCurrent;
  VlvTgtFlutter Read_PpVlvTgtCCFF_VlvTgtFlutter;
  VlvTgtFrequency Read_PpVlvTgtCCFF_VlvTgtFrequency;

//  VlvActFL Write_PpVelFbAll_VlvFL;
//  VlvActFR Write_PpVelFbAll_VlvFR;
//  VlvActRL Write_PpVelFbAll_VlvRL;
//  VlvActRR Write_PpVelFbAll_VlvRR;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtChannel(&Read_PpVlvTgtCCFF_VlvTgtChannel);
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

  fct_status = TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtCurrent(&Read_PpVlvTgtCCFF_VlvTgtCurrent);
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

  fct_status = TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtFlutter(&Read_PpVlvTgtCCFF_VlvTgtFlutter);
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

  fct_status = TSC_CtPT2000_Handler_Rte_Read_PpVlvTgtCCFF_VlvTgtFrequency(&Read_PpVlvTgtCCFF_VlvTgtFrequency);
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

  (void)memset(&Write_PpVelFbAll_VlvFL, 0, sizeof(Write_PpVelFbAll_VlvFL));
  fct_status = TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvFL(&Write_PpVelFbAll_VlvFL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpVelFbAll_VlvFR, 0, sizeof(Write_PpVelFbAll_VlvFR));
  fct_status = TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvFR(&Write_PpVelFbAll_VlvFR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpVelFbAll_VlvRL, 0, sizeof(Write_PpVelFbAll_VlvRL));
  fct_status = TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvRL(&Write_PpVelFbAll_VlvRL);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpVelFbAll_VlvRR, 0, sizeof(Write_PpVelFbAll_VlvRR));
  fct_status = TSC_CtPT2000_Handler_Rte_Write_PpVelFbAll_VlvRR(&Write_PpVelFbAll_VlvRR);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PoPT2000_Ctrl_PT2000_Enable_mode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PT2000_Enable_mode> of PortPrototype <PoPT2000_Ctrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_PT2000_Enable_mode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_PT2000_Enable_mode(uint8 Ch_number, uint8 Mode) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_PT2000_Enable_mode
 *********************************************************************************************************************/
	if(Timer_coda >= 250)
	{
		 Set_StartPin_State1( Ch_number,Mode);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PoPT2000_Ctrl_PT2000_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PT2000_Init> of PortPrototype <PoPT2000_Ctrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PoPT2000_Ctrl_PT2000_Init(uint8 init)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_PT2000_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_PT2000_Init(uint8 init) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_PT2000_Init
 *********************************************************************************************************************/
    PT2000_Init(init);
	GET_Valve_Value();
	PT2000_Contral();
//    pt2000_mode_control();

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PoPT2000_Ctrl_PT2000_Mode_Change
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <PT2000_Mode_Change> of PortPrototype <PoPT2000_Ctrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_PT2000_Mode_Change_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_PT2000_Mode_Change(uint8 Ch_number, uint8 Mode_Change) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_PT2000_Mode_Change
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PoPT2000_Ctrl_Set_ConstantCurrent
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_ConstantCurrent> of PortPrototype <PoPT2000_Ctrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_Set_ConstantCurrent_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_Set_ConstantCurrent(uint8 ChannelID, uint16 Current, uint16 Frequency, uint16 Flutter) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_Set_ConstantCurrent
 *********************************************************************************************************************/

	if(Timer_coda >= 400)
	{

		Set_ConstantCurrent1( ChannelID,0,0,0,0,0,Frequency,Flutter,Current,Frequency,0,Flutter,0,0);
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PoPT2000_Ctrl_Set_Peak_Hold
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Set_Peak_Hold> of PortPrototype <PoPT2000_Ctrl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_Set_Peak_Hold_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPT2000_Handler_CODE) PoPT2000_Ctrl_Set_Peak_Hold(uint8 ChannelID, uint16 IboostB, uint16 tbias_tot, uint16 tbias_off, uint16 ibias, uint16 iboostP, uint16 tpeak_tot, uint16 tpeak_off, uint16 ipeak, uint16 tbypass, uint16 thold_tot, uint16 thold_off, uint16 ihold, uint16 fwtimeOFF) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PoPT2000_Ctrl_Set_Peak_Hold
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtPT2000_Handler_STOP_SEC_CODE
#include "CtPT2000_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
