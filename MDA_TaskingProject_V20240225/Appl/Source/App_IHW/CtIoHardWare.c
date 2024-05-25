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

#include "Adc.h"
#include "Dio.h"
#include "Com.h"
#include "ADCFilter.h"

#define	 	ADC_0	0U
#define 	ADC_1	32U
#define 	ADC_2	64U
#define 	ADC_3	96U
#define 	ADC_8	256U

#define mainGroup_ch        8
#define mainChannel_nm      5
#define deputyGroup_ch      8
#define deputyChannel_nm    5

uint8 power_diag = 0;

unsigned short int   AdcResultBufferGroup0[mainGroup_ch*mainChannel_nm]={0};
unsigned short int   AdcResultBufferGroup1[mainGroup_ch*mainChannel_nm]={0};
unsigned short int   AdcResultBufferGroup2[mainGroup_ch*mainChannel_nm]={0};
unsigned short int   AdcResultBufferGroup3[mainGroup_ch*mainChannel_nm]={0};
unsigned short int   AdcResultBufferGroup8[120]={0};

unsigned short int   Adcsend[100]={0};

unsigned short int   Adcvalue0[mainGroup_ch][mainChannel_nm]={{0}};
unsigned short int   Adcvalue1[mainGroup_ch][mainChannel_nm]={{0}};
unsigned short int   Adcvalue2[mainGroup_ch][mainChannel_nm]={{0}};
unsigned short int   Adcvalue3[mainGroup_ch][mainChannel_nm]={{0}};
unsigned short int   Adcvalue8[deputyGroup_ch][deputyChannel_nm]={{0}};

unsigned short int   Sum_mianG_average_Value[4][mainGroup_ch] = {{0}};
unsigned short int   Sum_deputyG_average_Value[1][deputyGroup_ch] = {{0}};

unsigned short int   ADC_MG_average_ResultValue[4][mainGroup_ch] = {{0}};
unsigned short int   ADC_DG_average_ResultValue[1][deputyGroup_ch] = {{0}};

IMUAcc Write_PpIMU_IMUAcc;
IMUAngle Write_PpIMU_IMUAngle;
IMURate Write_PpIMU_IMURate;
IMUVel Write_PpIMU_IMUVel;
PedlPos Write_PpPedlPos_PedlPos;
Pressure Write_PpPressure_Pressure;
SteerWhl Write_PpSteerWhl_SteerWhl;
SuspHeight Write_PpSuspHeight_SuspHeight;


void Dio_init(void);
FUNC(void, CtIoHardWare_CODE) IOHWAB_ADC_Init(void);
void IoHwAb_ADC_ChannelData_Transfer(void);
void IoHwAb_ADC_Filter_Data(void);
void ADC_Value_Adjust(void);
void ADC_Value_SendSignal(void);
uint8 IoHwAb_Sensor_Power_Diag(void);

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

//  IMUAcc Write_PpIMU_IMUAcc;
//  IMUAngle Write_PpIMU_IMUAngle;
//  IMURate Write_PpIMU_IMURate;
//  IMUVel Write_PpIMU_IMUVel;
//  PedlPos Write_PpPedlPos_PedlPos;
//  Pressure Write_PpPressure_Pressure;
//  SteerWhl Write_PpSteerWhl_SteerWhl;
//  SuspHeight Write_PpSuspHeight_SuspHeight;

	Dio_init();

	IoHwAb_ADC_ChannelData_Transfer();
	IoHwAb_ADC_Filter_Data();
//	ADC_Value_Adjust();
//	ADC_Value_Write_Str();  //应用层结构体赋值，暂时不用，已经赋过值
	IoHwAb_Sensor_Power_Diag();
	ADC_Value_SendSignal();

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  (void)memset(&Write_PpIMU_IMUAcc, 0, sizeof(Write_PpIMU_IMUAcc));
  Write_PpIMU_IMUAcc.IMUAccX = (float)Filter_Calc.IMUAccX.average;
  Write_PpIMU_IMUAcc.IMUAccY = (float)Filter_Calc.IMUAccY.average;
  Write_PpIMU_IMUAcc.IMUAccZ = (float)Filter_Calc.IMUAccZ.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMUAcc(&Write_PpIMU_IMUAcc);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpIMU_IMUAngle, 0, sizeof(Write_PpIMU_IMUAngle));
  Write_PpIMU_IMUAngle.IMUPitchAngle = (float)Filter_Calc.IMUPitchAngle.average;
  Write_PpIMU_IMUAngle.IMURollAngle = (float)Filter_Calc.IMURollAngle.average;
  Write_PpIMU_IMUAngle.IMUYawAngle = (float)Filter_Calc.IMURollAngle.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMUAngle(&Write_PpIMU_IMUAngle);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpIMU_IMURate, 0, sizeof(Write_PpIMU_IMURate));
  Write_PpIMU_IMURate.IMUPitchRate = (float)Filter_Calc.IMUPitchRate.average;
  Write_PpIMU_IMURate.IMURollRate = (float)Filter_Calc.IMURollRate.average;
  Write_PpIMU_IMURate.IMUYawRate = (float)Filter_Calc.IMUYawRate.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMURate(&Write_PpIMU_IMURate);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpIMU_IMUVel, 0, sizeof(Write_PpIMU_IMUVel));
  Write_PpIMU_IMUVel.IMUVelEarth = (float)Filter_Calc.IMUVelEarth.average;
  Write_PpIMU_IMUVel.IMUVelEast = (float)Filter_Calc.IMUVelEast.average;
  Write_PpIMU_IMUVel.IMUVelNorth = (float)Filter_Calc.IMUVelNorth.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpIMU_IMUVel(&Write_PpIMU_IMUVel);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpPedlPos_PedlPos, 0, sizeof(Write_PpPedlPos_PedlPos));
  //  Write_PpPedlPos_PedlPos.AccPedlPos = (float)Filter_Calc.AccPedlPos.average;
  //  Write_PpPedlPos_PedlPos.BrkPedlPos = (float)Filter_Calc.BrkPedlPos.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpPedlPos_PedlPos(&Write_PpPedlPos_PedlPos);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpPressure_Pressure, 0, sizeof(Write_PpPressure_Pressure));
  //	Write_PpPressure_Pressure.PressureFL1 = (float)Filter_Calc.PressureFL1.average;
  //	Write_PpPressure_Pressure.PressureFL2 = (float)Filter_Calc.PressureFL2.average;
  //	Write_PpPressure_Pressure.PressureFR1 = (float)Filter_Calc.PressureFR1.average;
  //	Write_PpPressure_Pressure.PressureFR2 = (float)Filter_Calc.PressureFR2.average;
  //	Write_PpPressure_Pressure.PressureRL1 = (float)Filter_Calc.PressureRL1.average;
  //	Write_PpPressure_Pressure.PressureRL2 = (float)Filter_Calc.PressureRL2.average;
  //	Write_PpPressure_Pressure.PressureRR1 = (float)Filter_Calc.PressureRR1.average;
  //	Write_PpPressure_Pressure.PressureRR2 = (float)Filter_Calc.PressureRR2.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpPressure_Pressure(&Write_PpPressure_Pressure);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpSteerWhl_SteerWhl, 0, sizeof(Write_PpSteerWhl_SteerWhl));
  Write_PpSteerWhl_SteerWhl.SteerWhlAngle = (float)Filter_Calc.SteerWhlAngle.average;
  Write_PpSteerWhl_SteerWhl.SteerWhlAngleRate = (float)Filter_Calc.SteerWhlAngleRate.average;
  Write_PpSteerWhl_SteerWhl.SteerWhlHandTrq = (float)Filter_Calc.SteerWhlHandTrq.average;
  fct_status = TSC_CtIoHardWare_Rte_Write_PpSteerWhl_SteerWhl(&Write_PpSteerWhl_SteerWhl);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
  }

  (void)memset(&Write_PpSuspHeight_SuspHeight, 0, sizeof(Write_PpSuspHeight_SuspHeight));
  //  Write_PpSuspHeight_SuspHeight.SuspHeightFL = (float)Filter_Calc.SuspHeightFL.average;
  //  Write_PpSuspHeight_SuspHeight.SuspHeightFR = (float)Filter_Calc.SuspHeightFR.average;
  //  Write_PpSuspHeight_SuspHeight.SuspHeightRL = (float)Filter_Calc.SuspHeightRL.average;
  //  Write_PpSuspHeight_SuspHeight.SuspHeightRR = (float)Filter_Calc.SuspHeightRR.average;
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

void Dio_init(void)
{
	static uint8 Dio_init = 0;
	static unsigned char  CAN_STB_LOW = 0x00;
//	static unsigned char  CAN_STB_HIGH = 0x01;
//	static unsigned char  STB = 0x00;
//	STB^=0x01;
	if (Dio_init == 0)
	{
		Dio_WriteChannel(DioConf_DioChannel_CAN1_STB_P0_6,CAN_STB_LOW);
		Dio_WriteChannel(DioConf_DioChannel_CAN2_STB_P0_7,CAN_STB_LOW);
		Dio_WriteChannel(DioConf_DioChannel_CAN3_STB_P0_8,CAN_STB_LOW);
		Dio_WriteChannel(DioConf_DioChannel_CAN4_STB_P0_9,CAN_STB_LOW);
		Dio_WriteChannel(DioConf_DioChannel_CAN5_STB_P0_10,CAN_STB_LOW);
		Dio_WriteChannel(DioConf_DioChannel_CAN6_STB_P0_11,CAN_STB_LOW);
		Dio_init = 1;
	}
}


/****************************************************************
 * FUNC(void, CtIoHardWare_CODE) IOHWAB_ADC_Init(void)
 * ADC初始化，ECM使用该函数
 * 设置ADC模块采集缓冲区，开始采集
 *****************************************************************/
FUNC(void, CtIoHardWare_CODE) IOHWAB_ADC_Init(void)
{
	boolean status0 = E_NOT_OK;
	boolean status1 = E_NOT_OK;
	boolean status2 = E_NOT_OK;
	boolean status3 = E_NOT_OK;
	boolean status8 = E_NOT_OK;

	status0 = Adc_SetupResultBuffer(ADC_0,  AdcResultBufferGroup0);
	status1 = Adc_SetupResultBuffer(ADC_1,  AdcResultBufferGroup1);
	status2 = Adc_SetupResultBuffer(ADC_2,  AdcResultBufferGroup2);
	status3 = Adc_SetupResultBuffer(ADC_3,  AdcResultBufferGroup3);
	status8 = Adc_SetupResultBuffer(ADC_8,  AdcResultBufferGroup8);


	if((status0 != E_NOT_OK) && (status1 != E_NOT_OK) && (status2 != E_NOT_OK) && (status3 != E_NOT_OK) && (status8 != E_NOT_OK))
	{
		Adc_EnableGroupNotification(ADC_0);
		Adc_StartGroupConversion(ADC_0);
		Adc_EnableGroupNotification(ADC_1);
		Adc_StartGroupConversion(ADC_1);
		Adc_EnableGroupNotification(ADC_2);
		Adc_StartGroupConversion(ADC_2);
		Adc_EnableGroupNotification(ADC_3);
		Adc_StartGroupConversion(ADC_3);
		Adc_EnableGroupNotification(ADC_8);
		Adc_StartGroupConversion(ADC_8);
	}
	else
	{
		//do nothing
	}
}

/****************************************************************
 * void IoHwAb_ADC_ChannelData_Transfer(void)
 * ADC通道采集数据搬运，将获取值从采集缓冲区赋给计算缓冲区
 * 对单通道采集20次的结果进行数据有效性判断，累加求和计算均值
 *****************************************************************/
void IoHwAb_ADC_ChannelData_Transfer(void)
{
	if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(ADC_0))
	{
		Adc_StopGroupConversion(ADC_0);
		uint16 gci0 = 0;
		uint32 Sum0[mainGroup_ch] = {0};
		uint8  nmu_average0 = 0;
		for(uint8 Ag0_ch = 0;Ag0_ch<mainGroup_ch;Ag0_ch++)
		{
			for(uint8 Ag0_ch_nm = 0;Ag0_ch_nm<5;Ag0_ch_nm++)
			{
				if(AdcResultBufferGroup0[gci0]>=0 && AdcResultBufferGroup0[gci0] <= 4095)
				{
					nmu_average0++;
					Adcvalue0[Ag0_ch][Ag0_ch_nm] = AdcResultBufferGroup0[gci0];
					Sum0[Ag0_ch] += Adcvalue0[Ag0_ch][Ag0_ch_nm];
					gci0++;
				}
			}
			Sum_mianG_average_Value[0][Ag0_ch] = Sum0[Ag0_ch] / nmu_average0;
			nmu_average0 = 0;
		}
		Adc_StartGroupConversion(ADC_0);
		gci0 = 0;
	}

	if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(ADC_1))
	{
		Adc_StopGroupConversion(ADC_1);
		uint16 gci1 = 0;
		uint32 Sum1[mainGroup_ch] = {0};
		uint8  nmu_average1 = 0;
		for(uint8 Ag1_ch = 0;Ag1_ch<mainGroup_ch;Ag1_ch++)
		{
			for(uint8 Ag1_ch_nm = 0;Ag1_ch_nm<5;Ag1_ch_nm++)
			{
				if(AdcResultBufferGroup1[gci1]>=0 && AdcResultBufferGroup1[gci1] <= 4095)
				{
					nmu_average1++;
					Adcvalue1[Ag1_ch][Ag1_ch_nm] = AdcResultBufferGroup1[gci1];
					Sum1[Ag1_ch] += Adcvalue1[Ag1_ch][Ag1_ch_nm];
					gci1++;
				}
			}
			Sum_mianG_average_Value[1][Ag1_ch] = (uint16)(Sum1[Ag1_ch] / nmu_average1);
			nmu_average1 = 0;
		}
		Adc_StartGroupConversion(ADC_1);
		gci1 = 0;
	}

	if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(ADC_2))
	{
		Adc_StopGroupConversion(ADC_2);
		uint16 gci2 = 0;
		uint32 Sum2[mainGroup_ch] = {0};
		uint8  nmu_average2 = 0;
		for(uint8 Ag2_ch = 0;Ag2_ch<mainGroup_ch;Ag2_ch++)
		{
			for(uint8 Ag2_ch_nm = 0;Ag2_ch_nm<5;Ag2_ch_nm++)
			{
				if(AdcResultBufferGroup1[gci2]>=0 && AdcResultBufferGroup1[gci2] <= 4095)
				{
					nmu_average2++;
					Adcvalue2[Ag2_ch][Ag2_ch_nm] = AdcResultBufferGroup2[gci2];
					Sum2[Ag2_ch] += Adcvalue2[Ag2_ch][Ag2_ch_nm];
					gci2++;
				}
			}
			Sum_mianG_average_Value[2][Ag2_ch] = Sum2[Ag2_ch] / nmu_average2;
			nmu_average2 = 0;
		}
		Adc_StartGroupConversion(ADC_2);
		gci2 = 0;
	}
	if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(ADC_3))
	{
		Adc_StopGroupConversion(ADC_3);
		uint16 gci3 = 0;
		uint32 Sum3[mainGroup_ch] = {0};
		uint8  nmu_average3 = 0;
		for(uint8 Ag3_ch = 0;Ag3_ch<mainGroup_ch;Ag3_ch++)
		{
			for(uint8 Ag3_ch_nm = 0;Ag3_ch_nm<5;Ag3_ch_nm++)
			{
				if(AdcResultBufferGroup3[gci3]>=0 && AdcResultBufferGroup3[gci3] <= 4095)
				{
					nmu_average3++;
					Adcvalue3[Ag3_ch][Ag3_ch_nm] = AdcResultBufferGroup3[gci3];
					Sum3[Ag3_ch] += Adcvalue3[Ag3_ch][Ag3_ch_nm];
					gci3++;
				}
			}
			Sum_mianG_average_Value[3][Ag3_ch] = Sum3[Ag3_ch] / nmu_average3;
			nmu_average3 = 0;
		}
		Adc_StartGroupConversion(ADC_3);
		gci3 = 0;
	}
	if (ADC_STREAM_COMPLETED == Adc_GetGroupStatus(ADC_8))
	{
		Adc_StopGroupConversion(ADC_8);
		uint16 gci8 = 0;
		uint32 Sum8[deputyGroup_ch] = {0};
		uint8  nmu_average8 = 0;
		for(uint8 Ag8_ch = 0;Ag8_ch<deputyGroup_ch;Ag8_ch++)
		{
			for(uint8 Ag8_ch_nm = 0;Ag8_ch_nm<5;Ag8_ch_nm++)
			{
				if(AdcResultBufferGroup8[gci8]>=0 && AdcResultBufferGroup8[gci8] <= 4095)
				{
					nmu_average8++;
					Adcvalue8[Ag8_ch][Ag8_ch_nm] = AdcResultBufferGroup8[gci8];
					Sum8[Ag8_ch] += Adcvalue8[Ag8_ch][Ag8_ch_nm];
					gci8++;
				}
			}
			Sum_deputyG_average_Value[0][Ag8_ch] = Sum8[Ag8_ch] / nmu_average8;
			nmu_average8 = 0;
		}
		Adc_StartGroupConversion(ADC_8);
		gci8 = 0;
	}
	else
	{
		/*do nothing*/
	}

}


/****************************************************************
 * void ADC_Value_Write_Str(void)
 * 数据赋值给结构体元素，结构体定义由达芬奇应用层设置
 *
 *****************************************************************/
//void ADC_Value_Write_Str(void)
//{
// 	Write_PpPedlPos_PedlPos.AccPedlPos = (float)Sum_mianG_average_Value[0][6];
//	Write_PpPedlPos_PedlPos.BrkPedlPos = (float)Sum_mianG_average_Value[0][7];
//
//	Write_PpPressure_Pressure.PressureFL1 = (float)Sum_mianG_average_Value[1][0];
//	Write_PpPressure_Pressure.PressureFL2 = (float)Sum_mianG_average_Value[1][1];
//	Write_PpPressure_Pressure.PressureFR1 = (float)Sum_mianG_average_Value[1][2];
//	Write_PpPressure_Pressure.PressureFR2 = (float)Sum_mianG_average_Value[1][3];
//	Write_PpPressure_Pressure.PressureRL1 = (float)Sum_mianG_average_Value[1][4];
//	Write_PpPressure_Pressure.PressureRL2 = (float)Sum_mianG_average_Value[1][5];
//	Write_PpPressure_Pressure.PressureRR1 = (float)Sum_mianG_average_Value[1][6];
//	Write_PpPressure_Pressure.PressureRR2 = (float)Sum_mianG_average_Value[0][4];//使用主组0的通道4
//
//	Write_PpSuspHeight_SuspHeight.SuspHeightFL = (float)Sum_mianG_average_Value[1][7];
//	Write_PpSuspHeight_SuspHeight.SuspHeightFR = (float)Sum_mianG_average_Value[2][0];
//	Write_PpSuspHeight_SuspHeight.SuspHeightRL = (float)Sum_mianG_average_Value[2][4];
//	Write_PpSuspHeight_SuspHeight.SuspHeightRR = (float)Sum_mianG_average_Value[2][5];
//
//	Write_PpIMU_IMUAcc.IMUAccX = (float)Sum_mianG_average_Value[2][6];
//	Write_PpIMU_IMUAcc.IMUAccY = (float)Sum_mianG_average_Value[2][7];
//	Write_PpIMU_IMUAcc.IMUAccZ = (float)Sum_deputyG_average_Value[0][5];//使用副组8的通道5
//	Write_PpIMU_IMURate.IMURollRate = (float)Sum_mianG_average_Value[3][1];
//	Write_PpIMU_IMURate.IMUPitchRate = (float)Sum_mianG_average_Value[3][2];
//	Write_PpIMU_IMURate.IMUYawRate = (float)Sum_mianG_average_Value[3][3];
//	Write_PpIMU_IMUAngle.IMURollAngle = (float)Sum_mianG_average_Value[3][4];
//	Write_PpIMU_IMUAngle.IMUPitchAngle =  (float)Sum_mianG_average_Value[3][5];
//	Write_PpIMU_IMUAngle.IMUYawAngle = (float)Sum_mianG_average_Value[3][6];
//	Write_PpIMU_IMUVel.IMUVelNorth = (float)Sum_mianG_average_Value[3][7];
//
//	Write_PpIMU_IMUVel.IMUVelEarth = (float)Sum_deputyG_average_Value[0][1];   //辅助转换组8，数组定义为二维1*16
//	Write_PpIMU_IMUVel.IMUVelEast = (float)Sum_deputyG_average_Value[0][0];
//	Write_PpSteerWhl_SteerWhl.SteerWhlAngle = (float)Sum_deputyG_average_Value[0][2];
//	Write_PpSteerWhl_SteerWhl.SteerWhlHandTrq = (float)Sum_deputyG_average_Value[0][3];
//	Write_PpSteerWhl_SteerWhl.SteerWhlAngleRate = (float)Sum_deputyG_average_Value[0][4];//此信号目前只传递给应用层
//
//}


/****************************************************************
 * void ADC_Value_SendSignal(void)
 * 数据通过CAN11发送到上位机
 * 数据内容为单个通道采集平均值
 *****************************************************************/
//void ADC_Value_SendSignal(void)
//{
//
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx,&Sum_mianG_average_Value[0][6]);       //G0H6_AccPedIPos
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx,&Sum_mianG_average_Value[0][7]);     //G0H7_BrkPedIPos
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx,&Sum_mianG_average_Value[1][0]);   //G1H0_PressureFL1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx,&Sum_mianG_average_Value[1][1]); //G1H1_PressureFL2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx,&Sum_mianG_average_Value[1][2]);   //G1H2_PressureFR1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx,&Sum_mianG_average_Value[1][3]); //G1H3_PressureFR2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx,&Sum_mianG_average_Value[1][4]);   //G1H4_PressureRL1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx,&Sum_mianG_average_Value[1][5]); //G1H5_PressureRL2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx,&Sum_mianG_average_Value[1][6]);   //G1H6_PressureRR1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx,&Sum_mianG_average_Value[0][4]);  //使用主组0的通道4 //G0H4_PressureRR2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx,&Sum_mianG_average_Value[1][7]);        //G1H7_SuspHeightFL
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx,&Sum_mianG_average_Value[2][0]);        //G2H0_SuspHeightFR
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx,&Sum_mianG_average_Value[2][4]);        //G2H4_SuspHeightRL
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx,&Sum_mianG_average_Value[2][5]);        //G2H5_SuspHeightRR
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx,&Sum_mianG_average_Value[2][6]); //G2H6_IMUACCX
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx,&Sum_mianG_average_Value[2][7]);  //G2H7_IMUACCY
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx,&Sum_deputyG_average_Value[0][5]); //使用副组8的通道5//G8H5_IMUACCZ
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx,&Sum_mianG_average_Value[3][1]);      //G3H1_IMURoolRate
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx,&Sum_mianG_average_Value[3][2]);     //G3H2_IMUPitchRate
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx,&Sum_deputyG_average_Value[0][6]);//使用副组8的通道6//G8H6_IMUYawRate
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx,&Sum_mianG_average_Value[3][4]);     //G3H4_IMURoolAngle
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx,&Sum_mianG_average_Value[3][5]);    //G3H5_IMUPitchAngle
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx,&Sum_mianG_average_Value[3][6]);   //G3H6_IMUYawAngle
////	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx,&Sum_mianG_average_Value[3][7]);     //G3H7_IMUVelNorth
////	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx,&Sum_deputyG_average_Value[0][0]);      //G8H0_IMUVelEast
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx,&Sum_deputyG_average_Value[0][1]);   //G8H1_IMUVelEarth
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx,&Sum_deputyG_average_Value[0][4]);     //G8H2_SteerWhlAngle
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx,&Sum_deputyG_average_Value[0][3]);    //G8H3_SteerWhlHandTrq
//
//
//
//	Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx);
//	Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx);
//
//}


/****************************************************************
 * void IoHwAb_ADC_Filter_Data(void)
 * ADC数据滤波处理
 * 均值递推滤波
 *****************************************************************/
void IoHwAb_ADC_Filter_Data(void)
{

//	Sliding_Mean_Filter_Calc(&Filter_Calc.AccPedlPos,Sum_mianG_average_Value[0][6] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.BrkPedlPos,Sum_mianG_average_Value[0][7] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureFL1,Sum_mianG_average_Value[1][0] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureFL2,Sum_mianG_average_Value[1][1] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureFR1,Sum_mianG_average_Value[1][2] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureFR2,Sum_mianG_average_Value[1][3] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureRL1,Sum_mianG_average_Value[1][4] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureRL2,Sum_mianG_average_Value[1][5] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureRR1,Sum_mianG_average_Value[1][6] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.PressureRR2,Sum_mianG_average_Value[0][4] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.SuspHeightFL,Sum_mianG_average_Value[1][7] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.SuspHeightFR,Sum_mianG_average_Value[2][0] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.SuspHeightRL,Sum_mianG_average_Value[2][4] );
//	Sliding_Mean_Filter_Calc(&Filter_Calc.SuspHeightRR,Sum_mianG_average_Value[2][5] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUAccX,Sum_mianG_average_Value[2][6] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUAccY,Sum_mianG_average_Value[2][7] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUAccZ,Sum_deputyG_average_Value[0][5] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMURollRate,Sum_mianG_average_Value[3][1] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUPitchRate,Sum_mianG_average_Value[3][2] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUYawRate,Sum_deputyG_average_Value[0][6] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMURollAngle,Sum_mianG_average_Value[3][4] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUPitchAngle,Sum_mianG_average_Value[3][5] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUYawAngle,Sum_mianG_average_Value[3][6] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUVelNorth,Sum_mianG_average_Value[3][7] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUVelEarth,Sum_deputyG_average_Value[0][1] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.IMUVelEast,Sum_deputyG_average_Value[0][0] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.SteerWhlAngle,Sum_deputyG_average_Value[0][2] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.SteerWhlHandTrq,Sum_deputyG_average_Value[0][3] );
	Sliding_Mean_Filter_Calc(&Filter_Calc.SteerWhlAngleRate,Sum_deputyG_average_Value[0][4] );
}





void ADC_Value_Adjust(void)
{

//	Filter_Calc.AccPedlPos.average = ((Filter_Calc.AccPedlPos.average - 2)*4095)/4079;
//	Filter_Calc.BrkPedlPos.average = ((Filter_Calc.BrkPedlPos.average - 0)*4095)/4080;

//	Filter_Calc.PressureFL1.average = ((Filter_Calc.PressureFL1.average - 6)*4095)/4065;
//	Filter_Calc.PressureFL2.average = ((Filter_Calc.PressureFL2.average - 2)*4095)/4060;
//	Filter_Calc.PressureFR1.average = ((Filter_Calc.PressureFR1.average - 4)*4095)/4067;
//	Filter_Calc.PressureFR2.average = ((Filter_Calc.PressureFR2.average - 5)*4095)/4063;
//	Filter_Calc.PressureRL1.average = ((Filter_Calc.PressureRL1.average - 3)*4095)/4061;
//	Filter_Calc.PressureRL2.average = ((Filter_Calc.PressureRL2.average - 1)*4095)/4062;
//	Filter_Calc.PressureRR1.average = ((Filter_Calc.PressureRR1.average - 2)*4095)/4063;
//	Filter_Calc.PressureRR2.average = ((Filter_Calc.PressureRR2.average - 3)*4095)/4062;

}



/****************************************************************
 * uint8 IoHwAb_Sensor_Power_Diag(void)
 * 传感器电源诊断
 * 全局变量
 *****************************************************************/
uint8 IoHwAb_Sensor_Power_Diag(void)
{
	if((Sum_mianG_average_Value[2][1]>=4000)&&(Sum_mianG_average_Value[2][2]>=4000))
	{
		power_diag = 0;
	}
	else
	{
		power_diag = 1;
	}
	return power_diag;
}


/****************************************************************
 * void ADC_Value_SendSignal(void)
 * 数据通过CAN11发送到上位机
 * 数据内容为单个通道20次采集平均值
 *****************************************************************/
void ADC_Value_SendSignal(void)
{
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx,&Sum_mianG_average_Value[0][6]);       //G0H6_AccPedIPos
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx,&Sum_mianG_average_Value[0][7]);     //G0H7_BrkPedIPos
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx,&Sum_mianG_average_Value[1][0]);   //G1H0_PressureFL1
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx,&Sum_mianG_average_Value[1][1]); //G1H1_PressureFL2
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx,&Sum_mianG_average_Value[1][2]);   //G1H2_PressureFR1
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx,&Sum_mianG_average_Value[1][3]); //G1H3_PressureFR2
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx,&Sum_mianG_average_Value[1][4]);   //G1H4_PressureRL1
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx,&Sum_mianG_average_Value[1][5]); //G1H5_PressureRL2
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx,&Sum_mianG_average_Value[1][6]);   //G1H6_PressureRR1
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx,&Sum_mianG_average_Value[0][4]);  //使用主组0的通道4 //G0H4_PressureRR2
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx,&Sum_mianG_average_Value[1][7]);        //G1H7_SuspHeightFL
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx,&Sum_mianG_average_Value[2][0]);        //G2H0_SuspHeightFR
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx,&Sum_mianG_average_Value[2][4]);        //G2H4_SuspHeightRL
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx,&Sum_mianG_average_Value[2][5]);        //G2H5_SuspHeightRR



//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Gas_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_85d258d3_Tx,&Filter_Calc.AccPedlPos.average);       //G0H6_AccPedIPos
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Brake_pedal_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4466e9c1_Tx,&Filter_Calc.BrkPedlPos.average);     //G0H7_BrkPedIPos
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4ff296ad_Tx,&Filter_Calc.PressureFL1.average);   //G1H0_PressureFL1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_49f6aa56_Tx,&Filter_Calc.PressureFL2.average); //G1H1_PressureFL2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d6f19f98_Tx,&Filter_Calc.PressureFR1.average);   //G1H2_PressureFR1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d0f5a363_Tx,&Filter_Calc.PressureFR2.average); //G1H3_PressureFR2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9d11115e_Tx,&Filter_Calc.PressureRL1.average);   //G1H4_PressureRL1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9b152da5_Tx,&Filter_Calc.PressureRL2.average); //G1H5_PressureRL2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_UpRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_0412186b_Tx,&Filter_Calc.PressureRR1.average);   //G1H6_PressureRR1
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Pressure_DownRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_02162490_Tx,&Filter_Calc.PressureRR2.average);  //使用主组0的通道4 //G0H4_PressureRR2
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightFL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_05802db6_Tx,&Filter_Calc.SuspHeightFL.average);        //G2H0_SuspHeightFL---//更换通道为1-7
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightFR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9c832483_Tx,&Filter_Calc.SuspHeightFR.average);        //G2H1_SuspHeightFR---//更换通道为2-0
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightRL_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_d763aa45_Tx,&Filter_Calc.SuspHeightRL.average);        //G2H2_SuspHeightRL---//更换通道为2-4
//	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_HeightRR_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_4e60a370_Tx,&Filter_Calc.SuspHeightRR.average);        //G2H3_SuspHeightRR---//更换通道为2-5


	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Vertical_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_12c41d42_Tx,&Filter_Calc.IMUAccX.average); //G2H6_IMUACCX
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Lateral_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_8d5c04c7_Tx,&Filter_Calc.IMUAccY.average);  //G2H7_IMUACCY
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Body_Accel_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_bddf38ed_Tx,&Filter_Calc.IMUAccZ.average); //使用副组8的通道5//G8H5_IMUACCZ
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Roll_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_b173e7f1_Tx,&Filter_Calc.IMURollRate.average);      //G3H1_IMURollRate
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Pitch_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_39d01e28_Tx,&Filter_Calc.IMUPitchRate.average);     //G3H2_IMUPitchRate
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Yawing_Rate_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_e7d19a3d_Tx,&Filter_Calc.IMUYawRate.average);//使用副组8的通道6//G8H6_IMUYawRate
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Roll_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a36dcf74_Tx,&Filter_Calc.IMURollAngle.average);     //G3H4_IMURollAngle
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Pitch_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5cea06fd_Tx,&Filter_Calc.IMUPitchAngle.average);    //G3H5_IMUPitchAngle
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Yawing_Angle_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_31e9e392_Tx,&Filter_Calc.IMUYawAngle.average);   //G3H6_IMUYawAngle
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_North_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_a75ef127_Tx,&Filter_Calc.IMUVelNorth.average);     //G3H7_IMUVelNorth
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_East_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_d74b99fa_Tx,&Filter_Calc.IMUVelEast.average);      //G8H0_IMUVelEast
	Com_SendSignal(ComConf_ComGroupSignal_Sig_9_Axis_IMU_Ground_Speed_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_5603cee8_Tx,&Filter_Calc.IMUVelEarth.average);   //G8H1_IMUVelEarth
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Steering_Angle_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_32c000be_Tx,&Filter_Calc.SteerWhlAngle.average);     //G8H2_SteerWhlAngle
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Steering_Torque_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_fc4f17d8_Tx,&Filter_Calc.SteerWhlHandTrq.average);    //G8H3_SteerWhlHandTrq
	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Steering_AngleRate_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_9378dbfb_Tx,&Filter_Calc.SteerWhlAngleRate.average);    //G8H4_SteerWhlAngleRate


	Com_SendSignal(ComConf_ComGroupSignal_Sig_Sensor_Power_Diag_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_70e35f64_Tx,&power_diag);        //电源诊断ok：0；error：1



	Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sensor_ID_B10_Signal_Group_oMSG_Sensor_01_oSchaeffler_MDA_CANFD_c17b80f3_Tx);
	Com_SendSignalGroup(ComConf_ComSignalGroup_SG_Sensor_ID_B11_Signal_Group_oMSG_Sensor_02_oSchaeffler_MDA_CANFD_7da04a5d_Tx);

}


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
