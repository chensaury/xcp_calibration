/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtPSI5_Handler.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtPSI5_Handler
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtPSI5_Handler>
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

#include "Rte_CtPSI5_Handler.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtPSI5_Handler.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "float.h"
#include "Com.h"
#include "PSI5.h"
#include "Dio.h"

BodyAcc Write_PpBodyAccZ_BodyAcc;
WhlAcc Write_PpWhlAccZ_WhlAcc;

uint16 PSI5Data_Correct_Ch0_0 = 0;
uint16 PSI5Data_Correct_Ch0_1 = 0;
uint16 PSI5Data_Correct_Ch1_0 = 0;
uint16 PSI5Data_Correct_Ch1_1 = 0;
uint16 PSI5Data_Correct_Ch2_0 = 0;
uint16 PSI5Data_Correct_Ch2_1 = 0;
uint16 PSI5Data_Correct_Ch3_0 = 0;
uint16 PSI5Data_Correct_Ch3_1 = 0;
sint16 PSI5Data[4][2] = {{0}};

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
 * BodyAcc: Record with elements
 *   BodyAccZFL of type float32
 *   BodyAccZFR of type float32
 *   BodyAccZRL of type float32
 *   BodyAccZRR of type float32
 * WhlAcc: Record with elements
 *   WhlAccZFL of type float32
 *   WhlAccZFR of type float32
 *   WhlAccZRL of type float32
 *   WhlAccZRR of type float32
 *
 *********************************************************************************************************************/


#define CtPSI5_Handler_START_SEC_CODE
#include "CtPSI5_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PSI5MAIN_HD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 3ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpBodyAccZ_BodyAcc(const BodyAcc *data)
 *   Std_ReturnType Rte_Write_PpWhlAccZ_WhlAcc(const WhlAcc *data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PSI5MAIN_HD_doc
 *********************************************************************************************************************/
void PSI5_Value_SendSignal ()
{

	PSI5Data_Correct_Ch0_0 = (uint16)(PSI5Data[0][0] );
	PSI5Data_Correct_Ch0_1 = (uint16)(PSI5Data[0][1] );
	PSI5Data_Correct_Ch1_0 = (uint16)(PSI5Data[1][0] );
	PSI5Data_Correct_Ch1_1 = (uint16)(PSI5Data[1][1] );
	PSI5Data_Correct_Ch2_0 = (uint16)(PSI5Data[2][0] );
	PSI5Data_Correct_Ch2_1 = (uint16)(PSI5Data[2][1] );
	PSI5Data_Correct_Ch3_0 = (uint16)(PSI5Data[3][0] );
	PSI5Data_Correct_Ch3_1 = (uint16)(PSI5Data[3][1] );


    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d436b53e_Tx,&PSI5Data_Correct_Ch0_0);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4d35bc0b_Tx,&PSI5Data_Correct_Ch1_0);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_06d532cd_Tx,&PSI5Data_Correct_Ch2_0);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Body_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9fd63bf8_Tx,&PSI5Data_Correct_Ch3_0);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_7bc3a6cd_Tx,&PSI5Data_Correct_Ch0_1);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_e2c0aff8_Tx,&PSI5Data_Correct_Ch1_1);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_a920213e_Tx,&PSI5Data_Correct_Ch2_1);
    Com_SendSignal(ComConf_ComGroupSignal_Sig_X_Axis_Wheel_AccelRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_3023280b_Tx,&PSI5Data_Correct_Ch3_1);

    Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx);
}


//void PSI5_Value_Write_Str(void)
//{
//	Write_PpBodyAccZ_BodyAcc.BodyAccZFL = PSI5Data_Correct_Ch0_0;
//	Write_PpBodyAccZ_BodyAcc.BodyAccZFR = PSI5Data_Correct_Ch1_0;
//	Write_PpBodyAccZ_BodyAcc.BodyAccZRL = PSI5Data_Correct_Ch2_0;
//	Write_PpBodyAccZ_BodyAcc.BodyAccZRR = PSI5Data_Correct_Ch3_0;
//	Write_PpWhlAccZ_WhlAcc.WhlAccZFL = PSI5Data_Correct_Ch0_1;
//	Write_PpWhlAccZ_WhlAcc.WhlAccZFR = PSI5Data_Correct_Ch1_1;
//	Write_PpWhlAccZ_WhlAcc.WhlAccZRL = PSI5Data_Correct_Ch2_1;
//	Write_PpWhlAccZ_WhlAcc.WhlAccZRR = PSI5Data_Correct_Ch3_1;
//}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
uint8 count_init = 0;

uint8 init_psi5=0;

FUNC(void, CtPSI5_Handler_CODE) PSI5MAIN_HD(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PSI5MAIN_HD
 *********************************************************************************************************************/

//	static unsigned char  psi5STB = 0x00;
  //	psi5STB^=0x01;
  //	Dio_WriteChannel(DioConf_DioChannel_CAN4_STB_P0_9,psi5STB);
  //	if(init_psi5 = 0)
  //	{
  //		PSI5_Init();
  //		init_psi5 = 1;
  //	}
  	PSI5_ReadData_24Bit(PSI5Data);
  	PSI5_Value_SendSignal();
  //	PSI5_Value_Write_Str();


    Std_ReturnType fct_status;
    boolean fct_error = 0;
  //
  //  BodyAcc Write_PpBodyAccZ_BodyAcc;
  //  WhlAcc Write_PpWhlAccZ_WhlAcc;

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_PpBodyAccZ_BodyAcc, 0, sizeof(Write_PpBodyAccZ_BodyAcc));
	Write_PpBodyAccZ_BodyAcc.BodyAccZFL = (float)PSI5Data_Correct_Ch0_0;
	Write_PpBodyAccZ_BodyAcc.BodyAccZFR = (float)PSI5Data_Correct_Ch1_0;
	Write_PpBodyAccZ_BodyAcc.BodyAccZRL = (float)PSI5Data_Correct_Ch2_0;
	Write_PpBodyAccZ_BodyAcc.BodyAccZRR = (float)PSI5Data_Correct_Ch3_0;
  fct_status = TSC_CtPSI5_Handler_Rte_Write_PpBodyAccZ_BodyAcc(&Write_PpBodyAccZ_BodyAcc);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpWhlAccZ_WhlAcc, 0, sizeof(Write_PpWhlAccZ_WhlAcc));
	Write_PpWhlAccZ_WhlAcc.WhlAccZFL = (float)PSI5Data_Correct_Ch0_1;
	Write_PpWhlAccZ_WhlAcc.WhlAccZFR = (float)PSI5Data_Correct_Ch1_1;
	Write_PpWhlAccZ_WhlAcc.WhlAccZRL = (float)PSI5Data_Correct_Ch2_1;
	Write_PpWhlAccZ_WhlAcc.WhlAccZRR = (float)PSI5Data_Correct_Ch3_1;
  fct_status = TSC_CtPSI5_Handler_Rte_Write_PpWhlAccZ_WhlAcc(&Write_PpWhlAccZ_WhlAcc);
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


#define CtPSI5_Handler_STOP_SEC_CODE
#include "CtPSI5_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
