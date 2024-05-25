/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtMotor_FL.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtMotor_FL
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtMotor_FL>
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

#include "Rte_CtMotor_FL.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtMotor_FL.h"


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
  uint8 MotFLActSts;
  uint32 MotFLActCurrent;
  uint32 MotFLActVoltage;
  uint16 MotFLActPos;
  uint8 MotFLActTemp;
  uint16 MotFLActSpd;
  uint32 MotFLActTorq;
  uint8 MotFLDiagSts;
  uint8 MotTgtModeFL;
} MotFl_FeedBack;

MotFl_FeedBack MotFLAct_FrMot = {0};
MotFl_FeedBack MotFLAct_ToPc = {0};

typedef struct
{
  uint16 MotTgtSpdFL;
  uint32 MotTgtTorqFL;
  uint8  MotTgtModeFL;
  uint32 MotTgtPosFL;
  uint8  Mot_Mode_PreSC_FL;
} MotFL_TgtOut;



MotFL_TgtOut MotFL_TgtOut_FrPc = {0};
MotFL_TgtOut MotFL_TgtOut_check = {0};
MotFL_TgtOut MotFL_TgtOut_last = {0};

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
 * MotActFL: Record with elements
 *   MotFLActSts of type uint8
 *   MotFLActCurrent of type float32
 *   MotFLActVoltage of type float32
 *   MotFLActPos of type float32
 *   MotFLActTemp of type float32
 *   MotFLActSpd of type float32
 *   MotFLActTorq of type float32
 *   MotFLDiagSts of type uint8
 * MotTgtOutFL: Record with elements
 *   MotTgtSpdFL of type float32
 *   MotTgtTorqFL of type float32
 *   MotTgtModeFL of type uint8
 *   MotTgtPosFL of type float32
 *   Mot_Mode_PreSC_FL of type uint8
 *
 *********************************************************************************************************************/


#define CtMotor_FL_START_SEC_CODE
#include "CtMotor_FL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CpApMotor_FL
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
 *   Std_ReturnType Rte_Read_PpMotTgtOutFL_MotTgtOutFL(MotTgtOutFL *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpMotFLAct_MotFLAct(const MotActFL *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_FL_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtMotor_FL_CODE) CpApMotor_FL(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CpApMotor_FL
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  MotTgtOutFL Read_PpMotTgtOutFL_MotTgtOutFL;

  MotActFL Write_PpMotFLAct_MotFLAct;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CtMotor_FL_Rte_Read_PpMotTgtOutFL_MotTgtOutFL(&Read_PpMotTgtOutFL_MotTgtOutFL);
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


  /*************************************************
     * 读取应用层输出命令值
     *************************************************/
     	uint16 M_TgtSpdFL = (uint16)Read_PpMotTgtOutFL_MotTgtOutFL.MotTgtSpdFL;
     	uint32 M_TgtTorqFL = (uint32)Read_PpMotTgtOutFL_MotTgtOutFL.MotTgtTorqFL;
     	uint32 M_TgtPosFL = (uint32)Read_PpMotTgtOutFL_MotTgtOutFL.MotTgtPosFL;
     	uint8  M_TgtModeFL = (uint8)Read_PpMotTgtOutFL_MotTgtOutFL.MotTgtModeFL;
     	uint8  Mot_Mode_PreSC_FL = (uint8)Read_PpMotTgtOutFL_MotTgtOutFL.Mot_Mode_PreSC_FL;
  	/*************************************************
  	* 接收电机诊断反馈信号，发送至上位机
  	*************************************************/
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_940a4d73_Rx,&MotFLAct_FrMot.MotFLDiagSts);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_5071d764_Rx,&MotFLAct_FrMot.MotFLActPos);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_05cd1d48_Rx,&MotFLAct_FrMot.MotFLActSpd);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_State_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_115de03b_Rx,&MotFLAct_FrMot.MotFLActSts);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_811760c8_Rx,&MotFLAct_FrMot.MotFLActTemp);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Current_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_7013e7f5_Rx,&MotFLAct_FrMot.MotFLActCurrent);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_f956be0b_Rx,&MotFLAct_FrMot.MotFLActTorq);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_31f62729_Rx,&MotFLAct_FrMot.MotFLActVoltage);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkFL_oMSG_Motor_FL_oSchaeffler_MotorFL_CANFD_880421cb_Rx,&MotFLAct_FrMot.MotTgtModeFL);


  	MotFLAct_FrMot.MotTgtModeFL = 0;
  	MotFLAct_ToPc = MotFLAct_FrMot;  //诊断信号结构体赋值上位机结构体

  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_1fde2ef8_Tx,&MotFLAct_ToPc.MotFLActSpd);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_e3458dbb_Tx,&MotFLAct_ToPc.MotFLActTorq);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_4a62e4d4_Tx,&MotFLAct_ToPc.MotFLActPos);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9217127b_Tx,&MotFLAct_ToPc.MotTgtModeFL);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_State_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_0b4ed38b_Tx,&MotFLAct_ToPc.MotFLActSts);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Temp_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_9b045378_Tx,&MotFLAct_ToPc.MotFLActTemp);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Voltage_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_2be51499_Tx,&MotFLAct_ToPc.MotFLActVoltage);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Diags_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_8e197ec3_Tx,&MotFLAct_ToPc.MotFLDiagSts);
  	Com_SendSignal(ComConf_ComSignal_Sig_Mot_Current_fbkFL_ToPC_oMSG_MotorFL_oSchaeffler_MDA_CANFD_6a00d445_Tx,&MotFLAct_ToPc.MotFLActCurrent);
  	/*************************************************
  	* 接收上位机控制命令
  	*************************************************/
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_fb218646_Rx,&MotFL_TgtOut_FrPc.MotTgtModeFL);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_4378bd23_Rx,&MotFL_TgtOut_FrPc.Mot_Mode_PreSC_FL);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_1f1f7c0c_Rx,&MotFL_TgtOut_FrPc.MotTgtPosFL);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_86e41f3b_Rx,&MotFL_TgtOut_FrPc.MotTgtSpdFL);
  	Com_ReceiveSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFL_FrPC_oMSG_MDA_MotorFL_FrPC_oSchaeffler_MDA_CANFD_798d9eb1_Rx,&MotFL_TgtOut_FrPc.MotTgtTorqFL);


  	if((MotFL_TgtOut_FrPc.MotTgtModeFL & 0x80) == 0x80)   //判断进入PC模式
  	{
  		if (MotFL_TgtOut_FrPc.MotTgtModeFL != MotFL_TgtOut_last.MotTgtModeFL )
  		{
  			MotFL_TgtOut_last.MotTgtModeFL = MotFL_TgtOut_FrPc.MotTgtModeFL;
  			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_f43eb050_Tx,&MotFL_TgtOut_FrPc.MotTgtModeFL);
  		}
  		switch(MotFL_TgtOut_FrPc.Mot_Mode_PreSC_FL & 0x0F)
  		{
  			case 0x01:
  			{
  				if (MotFL_TgtOut_FrPc.MotTgtSpdFL != MotFL_TgtOut_last.MotTgtSpdFL )
  				{
  					MotFL_TgtOut_last.MotTgtSpdFL = MotFL_TgtOut_FrPc.MotTgtSpdFL;
  					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&MotFL_TgtOut_FrPc.Mot_Mode_PreSC_FL);
  					if(MotFLAct_FrMot.MotTgtModeFL == 0x00)
  					{
  						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_4c2f58b5_Tx,&MotFL_TgtOut_FrPc.MotTgtSpdFL);
  					}
  				}
  			}
  			  break;
  			case 0x02:
  			{
  				if (MotFL_TgtOut_FrPc.MotTgtTorqFL != MotFL_TgtOut_last.MotTgtTorqFL )
  				{
  					MotFL_TgtOut_last.MotTgtTorqFL = MotFL_TgtOut_FrPc.MotTgtTorqFL;
  					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&MotFL_TgtOut_FrPc.Mot_Mode_PreSC_FL);
  					if(MotFLAct_FrMot.MotTgtModeFL == 0x00)
  					{
  						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_cc22eb0f_Tx,&MotFL_TgtOut_FrPc.MotTgtTorqFL);
  					}
  				}
  			}
  			  break;
  			case 0x03:
  			{
  				if (MotFL_TgtOut_FrPc.MotTgtPosFL != MotFL_TgtOut_last.MotTgtPosFL )
  				{
  					MotFL_TgtOut_last.MotTgtPosFL = MotFL_TgtOut_FrPc.MotTgtPosFL;
  					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&MotFL_TgtOut_FrPc.Mot_Mode_PreSC_FL);
  					if(MotFLAct_FrMot.MotTgtModeFL == 0x00)
  					{
  						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_dda52c0a_Tx,&MotFL_TgtOut_last.MotTgtPosFL);
  					}
  				}
  			}
  			  break;
  			default:
  			{
  				uint8 MotModeFL_NC = 0x00;
  				Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&MotModeFL_NC);
  			}
  		}


  		MotFL_TgtOut_check.MotTgtModeFL = M_TgtModeFL;
  		MotFL_TgtOut_check.MotTgtSpdFL = M_TgtSpdFL;
  		MotFL_TgtOut_check.MotTgtTorqFL = M_TgtTorqFL;
  		MotFL_TgtOut_check.MotTgtPosFL = M_TgtPosFL;
  		MotFL_TgtOut_check.Mot_Mode_PreSC_FL = Mot_Mode_PreSC_FL;
  	/**************************************************************************************************
  	*此部分代码为测试代码
  	//  		if( ((MotFL_TgtOut_FrPc.MotTgtModeFL & 0x80) == 0x80) &&
  	//  		    ((MotFL_TgtOut_FrPc.MotTgtPosFL != MotFL_TgtOut_last.MotTgtPosFL )||
  	//  		     (MotFL_TgtOut_FrPc.MotTgtSpdFL != MotFL_TgtOut_last.MotTgtSpdFL )||
  	//			 (MotFL_TgtOut_FrPc.MotTgtTorqFL != MotFL_TgtOut_last.MotTgtTorqFL ))
  	//		  )
  	//  		{
  	//  			Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_ToMot_oMSG_MotorFL_oSchaeffler_MDA_CANFD_fd60d3bb_Tx,&MotFL_TgtOut_FrPc.MotTgtModeFL);
  	//
  	//  			if(MotFLAct_FrMot.MotTgtModeFL == 0x00)
  	//  			{
  	//				if (MotFL_TgtOut_FrPc.MotTgtPosFL != MotFL_TgtOut_last.MotTgtPosFL )
  	//				{
  	//					MotFL_TgtOut_last.MotTgtPosFL = MotFL_TgtOut_FrPc.MotTgtPosFL;
  	//					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFL_ToMot_oMSG_MotorFL_oSchaeffler_MDA_CANFD_b7c1772b_Tx,&MotFL_TgtOut_last.MotTgtPosFL);
  	//				}
  	//				if (MotFL_TgtOut_FrPc.MotTgtSpdFL != MotFL_TgtOut_last.MotTgtSpdFL )
  	//				{
  	//					MotFL_TgtOut_last.MotTgtSpdFL = MotFL_TgtOut_FrPc.MotTgtSpdFL;
  	//					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFL_ToMot_oMSG_MotorFL_oSchaeffler_MDA_CANFD_a1881529_Tx,&MotFL_TgtOut_FrPc.MotTgtSpdFL);
  	//				}
  	//				if (MotFL_TgtOut_FrPc.MotTgtTorqFL != MotFL_TgtOut_last.MotTgtTorqFL )
  	//				{
  	//					MotFL_TgtOut_last.MotTgtTorqFL = MotFL_TgtOut_FrPc.MotTgtTorqFL;
  	//					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFL_ToMot_oMSG_MotorFL_oSchaeffler_MDA_CANFD_a84a78fb_Tx,&MotFL_TgtOut_FrPc.MotTgtTorqFL);
  	//				}
  	//  			}
  	//  		}
  	//
  	//  		MotFL_TgtOut_check.MotTgtModeFL = M_TgtModeFL;
  	//  		MotFL_TgtOut_check.MotTgtSpdFL = M_TgtSpdFL;
  	//  		MotFL_TgtOut_check.MotTgtTorqFL = M_TgtTorqFL;
  	//  		MotFL_TgtOut_check.MotTgtPosFL = M_TgtPosFL;
  	********************************************************************************************************/
  	}
  	else
  	{
  		MotFL_TgtOut_last.Mot_Mode_PreSC_FL = MotFL_TgtOut_FrPc.Mot_Mode_PreSC_FL;
  		MotFL_TgtOut_last.MotTgtModeFL = MotFL_TgtOut_FrPc.MotTgtModeFL;
  		MotFL_TgtOut_last.MotTgtPosFL = MotFL_TgtOut_FrPc.MotTgtPosFL;
  		MotFL_TgtOut_last.MotTgtSpdFL = MotFL_TgtOut_FrPc.MotTgtSpdFL;
  		MotFL_TgtOut_last.MotTgtTorqFL = MotFL_TgtOut_FrPc.MotTgtTorqFL;

  		if (M_TgtModeFL != MotFL_TgtOut_check.MotTgtModeFL )
  		{
  			MotFL_TgtOut_check.MotTgtModeFL = M_TgtModeFL;
  			Com_SendSignal(ComConf_ComSignal_Sig_Mot_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_f43eb050_Tx,&M_TgtModeFL);
  		}
  		switch(Mot_Mode_PreSC_FL & 0x0F)
  		{
  			case 0x01:
  			{
  				if (M_TgtSpdFL != MotFL_TgtOut_check.MotTgtSpdFL)
  				{
  					MotFL_TgtOut_check.MotTgtSpdFL = M_TgtSpdFL;
  					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&Mot_Mode_PreSC_FL);
  					if(MotFLAct_FrMot.MotTgtModeFL == 0x00)
  					{
  						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Speed_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_4c2f58b5_Tx,&M_TgtSpdFL);
  					}
  				}
  			}
  			  break;
  			case 0x02:
  			{
  				if (M_TgtTorqFL != MotFL_TgtOut_check.MotTgtTorqFL)
  				{
  					MotFL_TgtOut_check.MotTgtTorqFL = M_TgtTorqFL;
  					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&Mot_Mode_PreSC_FL);
  					if (MotFLAct_FrMot.MotTgtModeFL == 0x00)
  					{
  						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Torque_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_cc22eb0f_Tx,&M_TgtTorqFL);
  					}
  				}
  			}
  			  break;
  			case 0x03:
  			{
  				if (M_TgtPosFL != MotFL_TgtOut_check.MotTgtPosFL)
  				{
  					MotFL_TgtOut_check.MotTgtPosFL = M_TgtPosFL;
  					Com_SendSignal(ComConf_ComSignal_Sig_Mot_Mode_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_7d5f8b40_Tx,&Mot_Mode_PreSC_FL);
  					if (MotFLAct_FrMot.MotTgtModeFL == 0x00)
  					{
  						Com_SendSignal(ComConf_ComSignal_Sig_Mot_Pos_commandFL_oMSG_MDA_MotorFL_oSchaeffler_MotorFL_CANFD_dda52c0a_Tx,&M_TgtPosFL);
  					}
  				}
  			}
  			  break;
  		}

  	}


  (void)memset(&Write_PpMotFLAct_MotFLAct, 0, sizeof(Write_PpMotFLAct_MotFLAct));
	Write_PpMotFLAct_MotFLAct.MotFLActCurrent = (float)MotFLAct_FrMot.MotFLActCurrent;
	Write_PpMotFLAct_MotFLAct.MotFLActPos = MotFLAct_FrMot.MotFLActPos;
	Write_PpMotFLAct_MotFLAct.MotFLActSpd = MotFLAct_FrMot.MotFLActSpd;
	Write_PpMotFLAct_MotFLAct.MotFLActSts = MotFLAct_FrMot.MotFLActSts;
	Write_PpMotFLAct_MotFLAct.MotFLActTemp = MotFLAct_FrMot.MotFLActTemp;
	Write_PpMotFLAct_MotFLAct.MotFLActTorq = (float)MotFLAct_FrMot.MotFLActTorq;
	Write_PpMotFLAct_MotFLAct.MotFLActVoltage =(float)MotFLAct_FrMot.MotFLActVoltage;
	Write_PpMotFLAct_MotFLAct.MotFLDiagSts = MotFLAct_FrMot.MotFLDiagSts;
  fct_status = TSC_CtMotor_FL_Rte_Write_PpMotFLAct_MotFLAct(&Write_PpMotFLAct_MotFLAct);
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


#define CtMotor_FL_STOP_SEC_CODE
#include "CtMotor_FL_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
