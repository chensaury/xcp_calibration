/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Core0Swc.c
 *        Config:  E:/Autosar_CP/TC397_Classic/SIP_0317/give_customer/Bsw_Project/Bsw_Project.dpa
 *     SW-C Type:  Core0Swc
 *  Generated at:  Tue Mar 21 20:44:33 2023
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <Core0Swc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_Core0Swc.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "Dio.h"
#include"com.h"
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define Core0Swc_START_SEC_CODE
#include "Core0Swc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
unsigned int Core0_Counter = 0;
uint16	Comp_speed_of_compressor = 0;
uint16  calibration_P0 = 0;
uint16  calibration_Counter = 0;
/**********************************************************************************************************************
 *
 * Runnable Entity Name: Core0Runnable
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 100ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: Core0Runnable_doc
 *********************************************************************************************************************/

uint16 GET_Comp_speed_of_compressor_Value(void)
{
	static uint16 get_32E_value =0;
    Com_ReceiveSignal(ComConf_ComSignal_Comp_speed_of_compressor_oACP_32E_oCAN00_c033917a_Rx,&get_32E_value);
	return get_32E_value;
}

uint8 SET_TgtSpd_rpm_Value(uint16 num)
{
	uint8 status =1;

	if((num >= 0)&&(num <= 65535))
	{
		Com_SendSignal(ComConf_ComSignal_TgtSpd_rpm_oITMS_350_oCAN00_b9dd7dcf_Tx,&num);
		status =0;
	} else
	{
		status =1;
	}
	return status;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, Core0Swc_CODE) Core0Runnable(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: Core0Runnable
 *********************************************************************************************************************/
	static unsigned char  LedSt=0;
	LedSt ^= 0x01;
	if(Core0_Counter <= 50000)
   {
	   Core0_Counter ++;
   }else
   {
	   Core0_Counter = 0;
   }
	SET_TgtSpd_rpm_Value(Core0_Counter);
   Dio_WriteChannel(DioConf_DioChannel_LED0,LedSt);
   Comp_speed_of_compressor = GET_Comp_speed_of_compressor_Value();

   if(calibration_P0 == 1){
	   calibration_Counter = 345;
   }else if(calibration_P0 == 2){
		if(calibration_Counter <= 50000)
	   {
			calibration_Counter ++;
	   }else
	   {
		   calibration_Counter = 0;
	   }
   }else
   {
	   calibration_Counter = 12321;
   }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}



#define Core0Swc_STOP_SEC_CODE
#include "Core0Swc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
