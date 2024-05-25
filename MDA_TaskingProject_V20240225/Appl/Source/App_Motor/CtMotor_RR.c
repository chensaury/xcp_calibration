/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtMotor_RR.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtMotor_RR
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtMotor_RR>
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

#include "Rte_CtMotor_RR.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtMotor_RR.h"


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
  uint8 MotRRActSts;
  uint32 MotRRActCurrent;
  uint32 MotRRActVoltage;
  uint16 MotRRActPos;
  uint8 MotRRActTemp;
  uint16 MotRRActSpd;
  uint32 MotRRActTorq;
  uint8 MotRRDiagSts;
  uint8 MotTgtModeRR;
} MotRR_FeedBack;

MotRR_FeedBack MotRRAct_FrMot = {0};
MotRR_FeedBack MotRRAct_ToPc = {0};

typedef struct
{
  uint16 MotTgtSpdRR;
  uint32 MotTgtTorqRR;
  uint8 MotTgtModeRR;
  uint32 MotTgtPosRR;
  uint8 Mot_Mode_PreSC_RR;
} MotRR_TgtOut;



MotRR_TgtOut MotRR_TgtOut_FrPc = {0};
MotRR_TgtOut MotRR_TgtOut_check = {0};
MotRR_TgtOut MotRR_TgtOut_last = {0};

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
 * MotActRR: Record with elements
 *   MotRRActSts of type uint8
 *   MotRRActCurrent of type float32
 *   MotRRActVoltage of type float32
 *   MotRRActPos of type float32
 *   MotRRActTemp of type float32
 *   MotRRActSpd of type float32
 *   MotRRActTorq of type float32
 *   MotRRDiagSts of type uint8
 * MotTgtOutRR: Record with elements
 *   MotTgtSpdRR of type float32
 *   MotTgtTorqRR of type float32
 *   MotTgtModeRR of type uint8
 *   MotTgtPosRR of type float32
 *   Mot_Mode_PreSC_RR of type uint8
 *
 *********************************************************************************************************************/


#define CtMotor_RR_START_SEC_CODE
#include "CtMotor_RR_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CpApMotor_RR
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
 *   Std_ReturnType Rte_Read_PpMotTgtOutRR_MotTgtOutRR(MotTgtOutRR *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpMotRRAct_MotRRAct(const MotActRR *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_RR_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtMotor_RR_CODE) CpApMotor_RR(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_RR
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  MotTgtOutRR Read_PpMotTgtOutRR_MotTgtOutRR;

  MotActRR Write_PpMotRRAct_MotRRAct;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CtMotor_RR_Rte_Read_PpMotTgtOutRR_MotTgtOutRR(&Read_PpMotTgtOutRR_MotTgtOutRR);
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

	uint16 M_TgtSpdRR = (uint16)Read_PpMotTgtOutRR_MotTgtOutRR.MotTgtSpdRR;
	uint32 M_TgtTorqRR = (uint32)Read_PpMotTgtOutRR_MotTgtOutRR.MotTgtTorqRR;
	uint32 M_TgtPosRR = (uint32)Read_PpMotTgtOutRR_MotTgtOutRR.MotTgtPosRR;
	uint8  M_TgtModeRR = (uint8)Read_PpMotTgtOutRR_MotTgtOutRR.MotTgtModeRR;
	uint8  Mot_Mode_PreSC_RR = (uint8)Read_PpMotTgtOutRR_MotTgtOutRR.Mot_Mode_PreSC_RR;


	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_f6152d89_Rx,&MotRRAct_FrMot.MotRRDiagSts);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_326eb79e_Rx,&MotRRAct_FrMot.MotRRActPos);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_67d27db2_Rx,&MotRRAct_FrMot.MotRRActSpd);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_State_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_734280c1_Rx,&MotRRAct_FrMot.MotRRActSts);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_e3080032_Rx,&MotRRAct_FrMot.MotRRActTemp);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Current_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_120c870f_Rx,&MotRRAct_FrMot.MotRRActCurrent);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_9b49def1_Rx,&MotRRAct_FrMot.MotRRActTorq);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_53e947d3_Rx,&MotRRAct_FrMot.MotRRActVoltage);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkRR_oMSG_Motor_RR_oSchaeffler_MotorRR_CANFD_ea1b4131_Rx,&MotRRAct_FrMot.MotTgtModeRR);

	MotRRAct_FrMot.MotTgtModeRR = 0;
	MotRRAct_ToPc = MotRRAct_FrMot;

	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_759ac58e_Tx,&MotRRAct_ToPc.MotRRActSpd);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_890166cd_Tx,&MotRRAct_ToPc.MotRRActTorq);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_20260fa2_Tx,&MotRRAct_ToPc.MotRRActPos);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f853f90d_Tx,&MotRRAct_ToPc.MotTgtModeRR);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_State_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_610a38fd_Tx,&MotRRAct_ToPc.MotRRActSts);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_f140b80e_Tx,&MotRRAct_ToPc.MotRRActTemp);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_41a1ffef_Tx,&MotRRAct_ToPc.MotRRActVoltage);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_e45d95b5_Tx,&MotRRAct_ToPc.MotRRDiagSts);
	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Current_fbkRR_ToPC_oMSG_MotorRR_oSchaeffler_MDA_CANFD_00443f33_Tx,&MotRRAct_ToPc.MotRRActCurrent);

	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_c8e0ad26_Rx,&MotRR_TgtOut_FrPc.MotTgtModeRR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_70b99643_Rx,&MotRR_TgtOut_FrPc.Mot_Mode_PreSC_RR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_2cde576c_Rx,&MotRR_TgtOut_FrPc.MotTgtPosRR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_b525345b_Rx,&MotRR_TgtOut_FrPc.MotTgtSpdRR);
	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_commandRR_FrPC_oMSG_MDA_MotorRR_FrPC_oSchaeffler_MDA_CANFD_4a4cb5d1_Rx,&MotRR_TgtOut_FrPc.MotTgtTorqRR);



	if((MotRR_TgtOut_FrPc.MotTgtModeRR & 0x80) == 0x80)   //判断进入PC模式
	{
		if (MotRR_TgtOut_FrPc.MotTgtModeRR != MotRR_TgtOut_last.MotTgtModeRR )
		{
			MotRR_TgtOut_last.MotTgtModeRR = MotRR_TgtOut_FrPc.MotTgtModeRR;
			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_65debded_Tx,&MotRR_TgtOut_FrPc.MotTgtModeRR);
		}
		switch(MotRR_TgtOut_FrPc.Mot_Mode_PreSC_RR & 0x0F)
		{
			case 0x01:
			{
				if (MotRR_TgtOut_FrPc.MotTgtTorqRR != MotRR_TgtOut_last.MotTgtTorqRR )
				{
					MotRR_TgtOut_last.MotTgtTorqRR = MotRR_TgtOut_FrPc.MotTgtTorqRR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&MotRR_TgtOut_FrPc.Mot_Mode_PreSC_RR);
					if(MotRRAct_FrMot.MotTgtModeRR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_5dc2e6b2_Tx,&MotRR_TgtOut_FrPc.MotTgtTorqRR);
					}
				}
			}
			  break;
			case 0x02:
			{
				if (MotRR_TgtOut_FrPc.MotTgtSpdRR != MotRR_TgtOut_last.MotTgtSpdRR )
				{
					MotRR_TgtOut_last.MotTgtSpdRR = MotRR_TgtOut_FrPc.MotTgtSpdRR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&MotRR_TgtOut_FrPc.Mot_Mode_PreSC_RR);
					if(MotRRAct_FrMot.MotTgtModeRR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ddcf5508_Tx,&MotRR_TgtOut_FrPc.MotTgtSpdRR);
					}
				}
			}
			  break;
			case 0x03:
			{
				if (MotRR_TgtOut_FrPc.MotTgtPosRR != MotRR_TgtOut_last.MotTgtPosRR )
				{
					MotRR_TgtOut_last.MotTgtPosRR = MotRR_TgtOut_FrPc.MotTgtPosRR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&MotRR_TgtOut_FrPc.Mot_Mode_PreSC_RR);
					if(MotRRAct_FrMot.MotTgtModeRR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_4c4521b7_Tx,&MotRR_TgtOut_last.MotTgtPosRR);
					}
				}
			}
			  break;
			default:
			{
				uint8 MotModeRR_NC = 0x00;
				Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&MotModeRR_NC);
			}
		}
		MotRR_TgtOut_check.MotTgtModeRR = M_TgtModeRR;
		MotRR_TgtOut_check.MotTgtSpdRR = M_TgtSpdRR;
		MotRR_TgtOut_check.MotTgtTorqRR = M_TgtTorqRR;
		MotRR_TgtOut_check.MotTgtPosRR = M_TgtPosRR;
		MotRR_TgtOut_check.Mot_Mode_PreSC_RR = Mot_Mode_PreSC_RR;
	}

	else
	{
		MotRR_TgtOut_last.Mot_Mode_PreSC_RR = MotRR_TgtOut_FrPc.Mot_Mode_PreSC_RR;
		MotRR_TgtOut_last.MotTgtModeRR = MotRR_TgtOut_FrPc.MotTgtModeRR;
		MotRR_TgtOut_last.MotTgtPosRR = MotRR_TgtOut_FrPc.MotTgtPosRR;
		MotRR_TgtOut_last.MotTgtSpdRR = MotRR_TgtOut_FrPc.MotTgtSpdRR;
		MotRR_TgtOut_last.MotTgtTorqRR = MotRR_TgtOut_FrPc.MotTgtTorqRR;

		if (M_TgtModeRR != MotRR_TgtOut_check.MotTgtModeRR )
		{
			MotRR_TgtOut_check.MotTgtModeRR = M_TgtModeRR;
			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_65debded_Tx,&M_TgtModeRR);
		}
		switch(Mot_Mode_PreSC_RR & 0x0F)
		{
			case 0x01:
			{
				if (M_TgtSpdRR != MotRR_TgtOut_check.MotTgtSpdRR)
				{
					MotRR_TgtOut_check.MotTgtSpdRR = M_TgtSpdRR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&Mot_Mode_PreSC_RR);
					if(MotRRAct_FrMot.MotTgtModeRR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ddcf5508_Tx,&M_TgtSpdRR);
					}
				}
			}
			  break;
			case 0x02:
			{
				if (M_TgtTorqRR != MotRR_TgtOut_check.MotTgtTorqRR)
				{
					MotRR_TgtOut_check.MotTgtTorqRR = M_TgtTorqRR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&Mot_Mode_PreSC_RR);
					if (MotRRAct_FrMot.MotTgtModeRR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_5dc2e6b2_Tx,&M_TgtTorqRR);
					}

				}
			}
			  break;
			case 0x03:
			{
				if (M_TgtPosRR != MotRR_TgtOut_check.MotTgtPosRR)
				{
					MotRR_TgtOut_check.MotTgtPosRR = M_TgtPosRR;
					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_ecbf86fd_Tx,&Mot_Mode_PreSC_RR);
					if (MotRRAct_FrMot.MotTgtModeRR == 0x00)
					{
						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandRR_oMSG_MDA_MotorRR_oSchaeffler_MotorRR_CANFD_4c4521b7_Tx,&M_TgtPosRR);
					}
				}
			}
			  break;
		}
	}
  (void)memset(&Write_PpMotRRAct_MotRRAct, 0, sizeof(Write_PpMotRRAct_MotRRAct));
	Write_PpMotRRAct_MotRRAct.MotRRActCurrent = (float)MotRRAct_FrMot.MotRRActCurrent;
	Write_PpMotRRAct_MotRRAct.MotRRActPos = MotRRAct_FrMot.MotRRActPos;
	Write_PpMotRRAct_MotRRAct.MotRRActSpd = MotRRAct_FrMot.MotRRActSpd;
	Write_PpMotRRAct_MotRRAct.MotRRActSts = MotRRAct_FrMot.MotRRActSts;
	Write_PpMotRRAct_MotRRAct.MotRRActTemp = MotRRAct_FrMot.MotRRActTemp;
	Write_PpMotRRAct_MotRRAct.MotRRActTorq = (float)MotRRAct_FrMot.MotRRActTorq;
	Write_PpMotRRAct_MotRRAct.MotRRActVoltage =(float)MotRRAct_FrMot.MotRRActVoltage;
	Write_PpMotRRAct_MotRRAct.MotRRDiagSts = MotRRAct_FrMot.MotRRDiagSts;
  fct_status = TSC_CtMotor_RR_Rte_Write_PpMotRRAct_MotRRAct(&Write_PpMotRRAct_MotRRAct);
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


#define CtMotor_RR_STOP_SEC_CODE
#include "CtMotor_RR_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
