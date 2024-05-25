/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtMotor_FR.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtMotor_FR
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtMotor_FR>
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

#include "Rte_CtMotor_FR.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtMotor_FR.h"


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
  uint8 MotFRActSts;
  uint32 MotFRActCurrent;
  uint32 MotFRActVoltage;
  uint16 MotFRActPos;
  uint8 MotFRActTemp;
  uint16 MotFRActSpd;
  uint32 MotFRActTorq;
  uint8 MotFRDiagSts;
  uint8 MotTgtModeFR;
} MotFr_FeedBack;

MotFr_FeedBack MotFRAct_FrMot = {0};
MotFr_FeedBack MotFRAct_ToPc = {0};

typedef struct
{
  uint16 MotTgtSpdFR;
  uint32 MotTgtTorqFR;
  uint8 MotTgtModeFR;
  uint32 MotTgtPosFR;
  uint8 Mot_Mode_PreSC_FR;
} MotFR_TgtOut;



MotFR_TgtOut MotFR_TgtOut_FrPc = {0};
MotFR_TgtOut MotFR_TgtOut_check = {0};
MotFR_TgtOut MotFR_TgtOut_last = {0};

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
 * MotActFR: Record with elements
 *   MotFRActSts of type uint8
 *   MotFRActCurrent of type float32
 *   MotFRActVoltage of type float32
 *   MotFRActPos of type float32
 *   MotFRActTemp of type float32
 *   MotFRActSpd of type float32
 *   MotFRActTorq of type float32
 *   MotFRDiagSts of type uint8
 * MotTgtOutFR: Record with elements
 *   MotTgtSpdFR of type float32
 *   MotTgtTorqFR of type float32
 *   MotTgtModeFR of type uint8
 *   MotTgtPosFR of type float32
 *   Mot_Mode_PreSC_FR of type uint8
 *
 *********************************************************************************************************************/


#define CtMotor_FR_START_SEC_CODE
#include "CtMotor_FR_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CpApMotor_FR
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
 *   Std_ReturnType Rte_Read_PpMotTgtOutFR_MotTgtOutFR(MotTgtOutFR *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpMotFRAct_MotFRAct(const MotActFR *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_FR_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtMotor_FR_CODE) CpApMotor_FR(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_FR
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  MotTgtOutFR Read_PpMotTgtOutFR_MotTgtOutFR;

  MotActFR Write_PpMotFRAct_MotFRAct;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CtMotor_FR_Rte_Read_PpMotTgtOutFR_MotTgtOutFR(&Read_PpMotTgtOutFR_MotTgtOutFR);
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

	uint16 M_TgtSpdFR = (uint16)Read_PpMotTgtOutFR_MotTgtOutFR.MotTgtSpdFR;
	uint32 M_TgtTorqFR = (uint32)Read_PpMotTgtOutFR_MotTgtOutFR.MotTgtTorqFR;
	uint32 M_TgtPosFR = (uint32)Read_PpMotTgtOutFR_MotTgtOutFR.MotTgtPosFR;
	uint8  M_TgtModeFR = (uint8)Read_PpMotTgtOutFR_MotTgtOutFR.MotTgtModeFR;
	uint8  Mot_Mode_PreSC_FR = (uint8)Read_PpMotTgtOutFR_MotTgtOutFR.Mot_Mode_PreSC_FR;

	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_e92f47e9_Rx,&MotFRAct_FrMot.MotFRDiagSts);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_2d54ddfe_Rx,&MotFRAct_FrMot.MotFRActPos);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_78e817d2_Rx,&MotFRAct_FrMot.MotFRActSpd);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_State_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_6c78eaa1_Rx,&MotFRAct_FrMot.MotFRActSts);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_fc326a52_Rx,&MotFRAct_FrMot.MotFRActTemp);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Current_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_0d36ed6f_Rx,&MotFRAct_FrMot.MotFRActCurrent);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_8473b491_Rx,&MotFRAct_FrMot.MotFRActTorq);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_4cd32db3_Rx,&MotFRAct_FrMot.MotFRActVoltage);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkFR_oMSG_Motor_FR_oSchaeffler_MotorFR_CANFD_f5212b51_Rx,&MotFRAct_FrMot.MotTgtModeFR);

	MotFRAct_FrMot.MotTgtModeFR = 0;
	MotFRAct_ToPc = MotFRAct_FrMot;

	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_99b454f9_Tx,&MotFRAct_ToPc.MotFRActSpd);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_652ff7ba_Tx,&MotFRAct_ToPc.MotFRActTorq);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_cc089ed5_Tx,&MotFRAct_ToPc.MotFRActPos);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_147d687a_Tx,&MotFRAct_ToPc.MotTgtModeFR);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_State_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_0b4ed38b_Tx,&MotFRAct_ToPc.MotFRActSts);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_1d6e2979_Tx,&MotFRAct_ToPc.MotFRActTemp);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ad8f6e98_Tx,&MotFRAct_ToPc.MotFRActVoltage);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_087304c2_Tx,&MotFRAct_ToPc.MotFRDiagSts);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Current_fbkFR_ToPC_oMSG_MotorFR_oSchaeffler_MDA_CANFD_ec6aae44_Tx,&MotFRAct_ToPc.MotFRActCurrent);

	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_92ab81c7_Rx,&MotFR_TgtOut_FrPc.MotTgtModeFR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_2af2baa2_Rx,&MotFR_TgtOut_FrPc.Mot_Mode_PreSC_FR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_76957b8d_Rx,&MotFR_TgtOut_FrPc.MotTgtPosFR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_ef6e18ba_Rx,&MotFR_TgtOut_FrPc.MotTgtSpdFR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFR_FrPC_oMSG_MDA_MotorFR_FrPC_oSchaeffler_MDA_CANFD_10079930_Rx,&MotFR_TgtOut_FrPc.MotTgtTorqFR);


	if((MotFR_TgtOut_FrPc.MotTgtModeFR & 0x80) == 0x80)   //判断进入PC模式
	{
		if (MotFR_TgtOut_FrPc.MotTgtModeFR != MotFR_TgtOut_last.MotTgtModeFR )
		{
			MotFR_TgtOut_last.MotTgtModeFR = MotFR_TgtOut_FrPc.MotTgtModeFR;
			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_5aa0af25_Tx,&MotFR_TgtOut_FrPc.MotTgtModeFR);
		}
		switch(MotFR_TgtOut_FrPc.Mot_Mode_PreSC_FR & 0x0F)
		{
			case 0x01:
			{
				if (MotFR_TgtOut_FrPc.MotTgtSpdFR != MotFR_TgtOut_last.MotTgtSpdFR )
				{
					MotFR_TgtOut_last.MotTgtSpdFR = MotFR_TgtOut_FrPc.MotTgtSpdFR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&MotFR_TgtOut_FrPc.Mot_Mode_PreSC_FR);
					if(MotFRAct_FrMot.MotTgtModeFR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_e2b147c0_Tx,&MotFR_TgtOut_FrPc.MotTgtSpdFR);
					}
				}
			}
			  break;
			case 0x02:
			{
				if (MotFR_TgtOut_FrPc.MotTgtTorqFR != MotFR_TgtOut_last.MotTgtTorqFR )
				{
					MotFR_TgtOut_last.MotTgtTorqFR = MotFR_TgtOut_FrPc.MotTgtTorqFR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&MotFR_TgtOut_FrPc.Mot_Mode_PreSC_FR);
					if(MotFRAct_FrMot.MotTgtModeFR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_62bcf47a_Tx,&MotFR_TgtOut_FrPc.MotTgtTorqFR);
					}
				}
			}
			  break;
			case 0x03:
			{
				if (MotFR_TgtOut_FrPc.MotTgtPosFR != MotFR_TgtOut_last.MotTgtPosFR )
				{
					MotFR_TgtOut_last.MotTgtPosFR = MotFR_TgtOut_FrPc.MotTgtPosFR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&MotFR_TgtOut_FrPc.Mot_Mode_PreSC_FR);
					if(MotFRAct_FrMot.MotTgtModeFR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_733b337f_Tx,&MotFR_TgtOut_last.MotTgtPosFR);
					}
				}
			}
			  break;
			default:
			{
				uint8 MotModeFR_NC = 0x00;
				Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&MotModeFR_NC);
			}
		}

		MotFR_TgtOut_check.MotTgtModeFR = M_TgtModeFR;
		MotFR_TgtOut_check.MotTgtSpdFR = M_TgtSpdFR;
		MotFR_TgtOut_check.MotTgtTorqFR = M_TgtTorqFR;
		MotFR_TgtOut_check.MotTgtPosFR = M_TgtPosFR;
		MotFR_TgtOut_check.Mot_Mode_PreSC_FR = Mot_Mode_PreSC_FR;
	}
	else
	{
		MotFR_TgtOut_last.Mot_Mode_PreSC_FR = MotFR_TgtOut_FrPc.Mot_Mode_PreSC_FR;
		MotFR_TgtOut_last.MotTgtModeFR = MotFR_TgtOut_FrPc.MotTgtModeFR;
		MotFR_TgtOut_last.MotTgtPosFR = MotFR_TgtOut_FrPc.MotTgtPosFR;
		MotFR_TgtOut_last.MotTgtSpdFR = MotFR_TgtOut_FrPc.MotTgtSpdFR;
		MotFR_TgtOut_last.MotTgtTorqFR = MotFR_TgtOut_FrPc.MotTgtTorqFR;

		if (M_TgtModeFR != MotFR_TgtOut_check.MotTgtModeFR )
		{
			MotFR_TgtOut_check.MotTgtModeFR = M_TgtModeFR;
			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_5aa0af25_Tx,&M_TgtModeFR);
		}
		switch(Mot_Mode_PreSC_FR & 0x0F)
		{
			case 0x01:
			{
				if (M_TgtSpdFR != MotFR_TgtOut_check.MotTgtSpdFR)
				{
					MotFR_TgtOut_check.MotTgtSpdFR = M_TgtSpdFR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&Mot_Mode_PreSC_FR);
					if(MotFRAct_FrMot.MotTgtModeFR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_e2b147c0_Tx,&M_TgtSpdFR);
					}
				}
			}
			  break;
			case 0x02:
			{
				if (M_TgtTorqFR != MotFR_TgtOut_check.MotTgtTorqFR)
				{
					MotFR_TgtOut_check.MotTgtTorqFR = M_TgtTorqFR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&Mot_Mode_PreSC_FR);
					if (MotFRAct_FrMot.MotTgtModeFR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_62bcf47a_Tx,&M_TgtTorqFR);
					}
				}
			}
			  break;
			case 0x03:
			{
				if (M_TgtPosFR != MotFR_TgtOut_check.MotTgtPosFR)
				{
					MotFR_TgtOut_check.MotTgtPosFR = M_TgtPosFR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_d3c19435_Tx,&Mot_Mode_PreSC_FR);
					if (MotFRAct_FrMot.MotTgtModeFR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFR_oMSG_MDA_MotorFR_oSchaeffler_MotorFR_CANFD_733b337f_Tx,&M_TgtPosFR);
					}
				}
			}
			  break;
		}
	}

  (void)memset(&Write_PpMotFRAct_MotFRAct, 0, sizeof(Write_PpMotFRAct_MotFRAct));
	Write_PpMotFRAct_MotFRAct.MotFRActCurrent = (float)MotFRAct_FrMot.MotFRActCurrent;
	Write_PpMotFRAct_MotFRAct.MotFRActPos = MotFRAct_FrMot.MotFRActPos;
	Write_PpMotFRAct_MotFRAct.MotFRActSpd = MotFRAct_FrMot.MotFRActSpd;
	Write_PpMotFRAct_MotFRAct.MotFRActSts = MotFRAct_FrMot.MotFRActSts;
	Write_PpMotFRAct_MotFRAct.MotFRActTemp = MotFRAct_FrMot.MotFRActTemp;
	Write_PpMotFRAct_MotFRAct.MotFRActTorq = (float)MotFRAct_FrMot.MotFRActTorq;
	Write_PpMotFRAct_MotFRAct.MotFRActVoltage =(float)MotFRAct_FrMot.MotFRActVoltage;
	Write_PpMotFRAct_MotFRAct.MotFRDiagSts = MotFRAct_FrMot.MotFRDiagSts;
  fct_status = TSC_CtMotor_FR_Rte_Write_PpMotFRAct_MotFRAct(&Write_PpMotFRAct_MotFRAct);
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


#define CtMotor_FR_STOP_SEC_CODE
#include "CtMotor_FR_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
