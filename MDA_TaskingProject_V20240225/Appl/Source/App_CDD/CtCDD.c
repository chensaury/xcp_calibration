/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtCDD.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtCDD
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtCDD>
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

#include "Rte_CtCDD.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtCDD.h"
#include "TLF35584.h"
#include "Dio.h"

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define CtCDD_START_SEC_CODE
#include "CtCDD_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CtCDD
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 50ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCDD_doc
 *********************************************************************************************************************/
void QSPI0TX_DMACallout(void)
{}
void QSPI1TX_DMACallout(void)
{}
void QSPI2TX_DMACallout(void)
{}
void QSPI3TX_DMACallout(void)
{}
void QSPI0RX_DMACallout(void)
{}
void QSPI1RX_DMACallout(void)
{}
void QSPI2RX_DMACallout(void)
{}
void QSPI3RX_DMACallout(void)
{}
//void IoHwAb_GptNotificationTOM0_Ch0(void)
//{}
void IoHwAb_GptNotificationTOM0_Ch1(void)
{}
void IoHwAb_GptNotificationTOM0_Ch2(void)
{}
void IoHwAb_GptNotificationTOM0_Ch3(void)
{}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
tlf35584Syssf SystemStatusFlags;
stateStatusType CurrentState;
uint8 MONSF0Status, MONSF1Status, MONSF2Status, MONSF3Status, OTFAILStatus;
uint8 Window_State = 0;

FUNC(void, CtCDD_CODE) CtCDD(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CtCDD
 *********************************************************************************************************************/
//	SystemStatusFlags.U = getSystemStatusFlagsTFL35584(&g_tlfDevice);//电源芯片是否正常工作
//
//	CurrentState = getCurrentStateTLF35584(&g_tlfDevice);//当前电源芯片状态
//	if(CurrentState != DeviceStateTransition_normal);
//
//	MONSF0Status = getMONSF0StatusFlagsTFL35584(&g_tlfDevice);//短路
//	MONSF1Status = getMONSF0StatusFlagsTFL35584(&g_tlfDevice);//过压
//	MONSF2Status = getMONSF0StatusFlagsTFL35584(&g_tlfDevice);//欠压
//	MONSF3Status = getMONSF0StatusFlagsTFL35584(&g_tlfDevice);//过流
//	OTFAILStatus = getOTFAILStatusFlagsTFL35584(&g_tlfDevice);//过温
//
//	switch(Window_State)//开窗关窗状态机
//	{
//	   case 0: case 1: case 2:
//		   Dio_WriteChannel(DioConf_DioChannel_WatchDog_35584, 1);
//		   Window_State++;
//		   break;
//
//	   case 3:
//		   Dio_WriteChannel(DioConf_DioChannel_WatchDog_35584, 0);
//		   Window_State++;
//		   break;
//
//	   case 4: case 5: case 6: case 7: case 8:case 9: case 10: case 11: case 12:case 13: case 14:case 15: case 16: case 17: case 18:case 19:
//		  if(Window_State==16)
//				Window_State=0;
//		  else  Window_State++;
//		  break;
//
//	  default:
//		  break;
//	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtCDD_STOP_SEC_CODE
#include "CtCDD_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
