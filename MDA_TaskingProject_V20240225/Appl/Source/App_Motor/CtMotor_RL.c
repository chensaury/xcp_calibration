/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtMotor_RL.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtMotor_RL
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtMotor_RL>
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

#include "Rte_CtMotor_RL.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtMotor_RL.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "Com.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
typedef struct
{
  uint8 MotRLActSts;
  uint32 MotRLActCurrent;
  uint32 MotRLActVoltage;
  uint16 MotRLActPos;
  uint8 MotRLActTemp;
  uint16 MotRLActSpd;
  uint32 MotRLActTorq;
  uint8 MotRLDiagSts;
  uint8 MotTgtModeRL;
} MotRL_FeedBack;

MotRL_FeedBack MotRLAct_FrMot = {0};
MotRL_FeedBack MotRLAct_ToPc = {0};

typedef struct
{
  uint16 MotTgtSpdRL;
  uint32 MotTgtTorqRL;
  uint8 MotTgtModeRL;
  uint32 MotTgtPosRL;
  uint8 Mot_Mode_PreSC_RL;
} MotRL_TgtOut;



MotRL_TgtOut MotRL_TgtOut_FrPc = {0};
MotRL_TgtOut MotRL_TgtOut_check = {0};
MotRL_TgtOut MotRL_TgtOut_last = {0};

/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * float32: Real in interval [-FLT_MAX...FLT_MAX] with single precision (standard type)
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Record Types:
 * =============
 * MotActRL: Record with elements
 *   MotRLActSts of type uint8
 *   MotRLActCurrent of type float32
 *   MotRLActVoltage of type float32
 *   MotRLActPos of type float32
 *   MotRLActTemp of type float32
 *   MotRLActSpd of type float32
 *   MotRLActTorq of type float32
 *   MotRLDiagSts of type uint8
 * MotTgtOutRL: Record with elements
 *   MotTgtSpdRL of type float32
 *   MotTgtTorqRL of type float32
 *   MotTgtModeRL of type uint8
 *   MotTgtPosRL of type float32
 *   Mot_Mode_PreSC_RL of type uint8
 *
 *********************************************************************************************************************/


#define CtMotor_RL_START_SEC_CODE
#include "CtMotor_RL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CpApMotor_RL
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
 *   Std_ReturnType Rte_Read_PpMotTgtOutRL_MotTgtOutRL(MotTgtOutRL *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpMotRLAct_MotRLAct(const MotActRL *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_RL_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtMotor_RL_CODE) CpApMotor_RL(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_RL
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  MotTgtOutRL Read_PpMotTgtOutRL_MotTgtOutRL;

  MotActRL Write_PpMotRLAct_MotRLAct;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CtMotor_RL_Rte_Read_PpMotTgtOutRL_MotTgtOutRL(&Read_PpMotTgtOutRL_MotTgtOutRL);
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

	uint16 M_TgtSpdRL = (uint16)Read_PpMotTgtOutRL_MotTgtOutRL.MotTgtSpdRL;
	uint32 M_TgtTorqRL = (uint32)Read_PpMotTgtOutRL_MotTgtOutRL.MotTgtTorqRL;
	uint32 M_TgtPosRL = (uint32)Read_PpMotTgtOutRL_MotTgtOutRL.MotTgtPosRL;
	uint8  M_TgtModeRL = (uint8)Read_PpMotTgtOutRL_MotTgtOutRL.MotTgtModeRL;
	uint8  Mot_Mode_PreSC_RL = (uint8)Read_PpMotTgtOutRL_MotTgtOutRL.Mot_Mode_PreSC_RL;


	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_8b302713_Rx,&MotRLAct_FrMot.MotRLDiagSts);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_4f4bbd04_Rx,&MotRLAct_FrMot.MotRLActPos);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_1af77728_Rx,&MotRLAct_FrMot.MotRLActSpd);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_State_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_0e678a5b_Rx,&MotRLAct_FrMot.MotRLActSts);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_9e2d0aa8_Rx,&MotRLAct_FrMot.MotRLActTemp);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_Rx,&MotRLAct_FrMot.MotRLActCurrent);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_e66cd46b_Rx,&MotRLAct_FrMot.MotRLActTorq);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_2ecc4d49_Rx,&MotRLAct_FrMot.MotRLActVoltage);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkRL_oMSG_Motor_RL_oSchaeffler_MotorRL_CANFD_973e4bab_Rx,&MotRLAct_FrMot.MotTgtModeRL);

	MotRLAct_FrMot.MotTgtModeRL = 0;
	MotRLAct_ToPc = MotRLAct_FrMot;


	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_f3f0bf8f_Tx,&MotRLAct_ToPc.MotRLActSpd);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_0f6b1ccc_Tx,&MotRLAct_ToPc.MotRLActTorq);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_a64c75a3_Tx,&MotRLAct_ToPc.MotRLActPos);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_7e39830c_Tx,&MotRLAct_ToPc.MotTgtModeRL);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_State_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_e76042fc_Tx,&MotRLAct_ToPc.MotRLActSts);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_772ac20f_Tx,&MotRLAct_ToPc.MotRLActTemp);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_c7cb85ee_Tx,&MotRLAct_ToPc.MotRLActVoltage);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_6237efb4_Tx,&MotRLAct_ToPc.MotRLDiagSts);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Current_fbkRL_ToPC_oMSG_MotorRL_oSchaeffler_MDA_CANFD_862e4532_Tx,&MotRLAct_ToPc.MotRLActCurrent);

	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_a16aaaa7_Rx,&MotRL_TgtOut_FrPc.MotTgtModeRL);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_193391c2_Rx,&MotRL_TgtOut_FrPc.Mot_Mode_PreSC_RL);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_455450ed_Rx,&MotRL_TgtOut_FrPc.MotTgtPosRL);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_dcaf33da_Rx,&MotRL_TgtOut_FrPc.MotTgtSpdRL);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_commandRL_FrPC_oMSG_MDA_MotorRL_FrPC_oSchaeffler_MDA_CANFD_23c6b250_Rx,&MotRL_TgtOut_FrPc.MotTgtTorqRL);


	if((MotRL_TgtOut_FrPc.MotTgtModeRL & 0x80) == 0x80)   //判断进入PC模式
	{
		if (MotRL_TgtOut_FrPc.MotTgtModeRL != MotRL_TgtOut_last.MotTgtModeRL )
		{
			MotRL_TgtOut_last.MotTgtModeRL = MotRL_TgtOut_FrPc.MotTgtModeRL;
			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_cb40a298_Tx,&MotRL_TgtOut_FrPc.MotTgtModeRL);
		}
		switch(MotRL_TgtOut_FrPc.Mot_Mode_PreSC_RL & 0x0F)
		{
			case 0x01:
			{
				if (MotRL_TgtOut_FrPc.MotTgtSpdRL != MotRL_TgtOut_last.MotTgtSpdRL )
				{
					MotRL_TgtOut_last.MotTgtSpdRL = MotRL_TgtOut_FrPc.MotTgtSpdRL;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&MotRL_TgtOut_FrPc.Mot_Mode_PreSC_RL);
					if(MotRLAct_FrMot.MotTgtModeRL == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_73514a7d_Tx,&MotRL_TgtOut_FrPc.MotTgtSpdRL);
					}
				}
			}
			  break;
			case 0x02:
			{
				if (MotRL_TgtOut_FrPc.MotTgtTorqRL != MotRL_TgtOut_last.MotTgtTorqRL )
				{
					MotRL_TgtOut_last.MotTgtTorqRL = MotRL_TgtOut_FrPc.MotTgtTorqRL;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&MotRL_TgtOut_FrPc.Mot_Mode_PreSC_RL);
					if(MotRLAct_FrMot.MotTgtModeRL == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_f35cf9c7_Tx,&MotRL_TgtOut_FrPc.MotTgtTorqRL);
					}
				}
			}
			  break;
			case 0x03:
			{
				if (MotRL_TgtOut_FrPc.MotTgtPosRL != MotRL_TgtOut_last.MotTgtPosRL )
				{
					MotRL_TgtOut_last.MotTgtPosRL = MotRL_TgtOut_FrPc.MotTgtPosRL;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&MotRL_TgtOut_FrPc.Mot_Mode_PreSC_RL);
					if(MotRLAct_FrMot.MotTgtModeRL == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_e2db3ec2_Tx,&MotRL_TgtOut_last.MotTgtPosRL);
					}
				}
			}
			  break;
			default:
			{
				uint8 MotModeRL_NC = 0x00;
				Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&MotModeRL_NC);
			}
		}
		MotRL_TgtOut_check.MotTgtModeRL = M_TgtModeRL;
		MotRL_TgtOut_check.MotTgtSpdRL = M_TgtSpdRL;
		MotRL_TgtOut_check.MotTgtTorqRL = M_TgtTorqRL;
		MotRL_TgtOut_check.MotTgtPosRL = M_TgtPosRL;
		MotRL_TgtOut_check.Mot_Mode_PreSC_RL = Mot_Mode_PreSC_RL;
	}
	else
	{
		MotRL_TgtOut_last.Mot_Mode_PreSC_RL = MotRL_TgtOut_FrPc.Mot_Mode_PreSC_RL;
		MotRL_TgtOut_last.MotTgtModeRL = MotRL_TgtOut_FrPc.MotTgtModeRL;
		MotRL_TgtOut_last.MotTgtPosRL = MotRL_TgtOut_FrPc.MotTgtPosRL;
		MotRL_TgtOut_last.MotTgtSpdRL = MotRL_TgtOut_FrPc.MotTgtSpdRL;
		MotRL_TgtOut_last.MotTgtTorqRL = MotRL_TgtOut_FrPc.MotTgtTorqRL;

		if (M_TgtModeRL != MotRL_TgtOut_check.MotTgtModeRL )
		{
			MotRL_TgtOut_check.MotTgtModeRL = M_TgtModeRL;
			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_cb40a298_Tx,&M_TgtModeRL);
		}
		switch(Mot_Mode_PreSC_RL & 0x0F)
		{
			case 0x01:
			{
				if (M_TgtSpdRL != MotRL_TgtOut_check.MotTgtSpdRL)
				{
					MotRL_TgtOut_check.MotTgtSpdRL = M_TgtSpdRL;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&Mot_Mode_PreSC_RL);
					if(MotRLAct_FrMot.MotTgtModeRL == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_73514a7d_Tx,&M_TgtSpdRL);
					}
				}
			}
			  break;
			case 0x02:
			{
				if (M_TgtTorqRL != MotRL_TgtOut_check.MotTgtTorqRL)
				{
					MotRL_TgtOut_check.MotTgtTorqRL = M_TgtTorqRL;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&Mot_Mode_PreSC_RL);
					if (MotRLAct_FrMot.MotTgtModeRL == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_f35cf9c7_Tx,&M_TgtTorqRL);
					}

				}
			}
			  break;
			case 0x03:
			{
				if (M_TgtPosRL != MotRL_TgtOut_check.MotTgtPosRL)
				{
					MotRL_TgtOut_check.MotTgtPosRL = M_TgtPosRL;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_42219988_Tx,&Mot_Mode_PreSC_RL);
					if (MotRLAct_FrMot.MotTgtModeRL == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandRL_oMSG_MDA_MotorRL_oSchaeffler_MotorRL_CANFD_e2db3ec2_Tx,&M_TgtPosRL);
					}
				}
			}
			  break;
		}

	}

  (void)memset(&Write_PpMotRLAct_MotRLAct, 0, sizeof(Write_PpMotRLAct_MotRLAct));
	Write_PpMotRLAct_MotRLAct.MotRLActCurrent =(float)MotRLAct_FrMot.MotRLActCurrent;
	Write_PpMotRLAct_MotRLAct.MotRLActPos = MotRLAct_FrMot.MotRLActPos;
	Write_PpMotRLAct_MotRLAct.MotRLActSpd = MotRLAct_FrMot.MotRLActSpd;
	Write_PpMotRLAct_MotRLAct.MotRLActSts = MotRLAct_FrMot.MotRLActSts;
	Write_PpMotRLAct_MotRLAct.MotRLActTemp = MotRLAct_FrMot.MotRLActTemp;
	Write_PpMotRLAct_MotRLAct.MotRLActTorq = (float)MotRLAct_FrMot.MotRLActTorq;
	Write_PpMotRLAct_MotRLAct.MotRLActVoltage =(float)MotRLAct_FrMot.MotRLActVoltage;
	Write_PpMotRLAct_MotRLAct.MotRLDiagSts = MotRLAct_FrMot.MotRLDiagSts;
  fct_status = TSC_CtMotor_RL_Rte_Write_PpMotRLAct_MotRLAct(&Write_PpMotRLAct_MotRLAct);
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


#define CtMotor_RL_STOP_SEC_CODE
#include "CtMotor_RL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
