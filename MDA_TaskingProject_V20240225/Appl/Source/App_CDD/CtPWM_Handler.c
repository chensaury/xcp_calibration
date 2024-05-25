/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtPWM_Handler.c
 *        Config:  Bsw_Project.dpa
 *     SW-C Type:  CtPWM_Handler
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1900078
 *
 *   Description:  C-Code implementation template for SW-C <CtPWM_Handler>
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

#include "Rte_CtPWM_Handler.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CtPWM_Handler.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"
#include "Pwm_17_GtmCcu6.h"
#include "Icu_17_TimerIp.h"
#include "Spi.h"
#include "Gpt.h"
#include "Dio.h"

//��������
Icu_17_TimerIp_DutyCycleType PWM_GET;
uint8 init_icu = 0;
uint8 init_gpt = 0;
uint32 pwm_duty = 0x0000;
uint32 pwm_duty_get = 0;

unsigned char ICU_sendBuf[2] = {0};
unsigned char ICU_sendBufRxBuf[2] = {0};


volatile uint8 testram = 0;
const uint8 testflash = 0;
uint8 testflash2 = 0;

//���ܺ�������
void ICU_mode_init(void);
void PWM_out(void);
void SPI_Send(uint8 channelId, uint8 sequenceId);
void SPI_Write(uint16 percent);
void GPT_start(void);
void IoHwAb_GptNotificationTOM0_Ch0(void);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


#define CtPWM_Handler_START_SEC_CODE
#include "CtPWM_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: PWM_SET
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 4ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: PWM_SET_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtPWM_Handler_CODE) PWM_SET(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: PWM_SET
 *********************************************************************************************************************/

//	ICU_mode_init();
//	PWM_out();//ʹ��23.2����ɱ�ռ�ձȲ���
//
//	Icu_17_TimerIp_GetDutyCycleValues(IcuConf_IcuChannel_IcuChannel_P34_1_PWMIN1,&PWM_GET);  //��ȡ������ֵ
//
//	pwm_duty_get = PWM_GET.ActiveTime*0x4000/PWM_GET.PeriodTime;  //�������ռ�ձȳ�0x4000�󸶸��µı���
//	Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_Drive2,0xA,pwm_duty_get);  //ʹ����һ��ͨ������µ�pwm
//
////	���ڿ������ռ�ձȲ�����ԣ�ʹ��spi0�����ݷ���
////	SPI_Write(PWM_GET.ActiveTime);
//
//	GPT_start();
//
//

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtPWM_Handler_STOP_SEC_CODE
#include "CtPWM_Handler_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

void ICU_mode_init(void)
{
	if(init_icu ==0)
	{
		//���벶���ʼ��
		Icu_17_TimerIp_SetMode(ICU_17_TIMERIP_MODE_NORMAL);
		Icu_17_TimerIp_StartSignalMeasurement (IcuConf_IcuChannel_IcuChannel_P34_1_PWMIN1);
		init_icu = 1;
	}
}

void GPT_start(void)
{
	if(init_gpt ==0)
	{
		//ͨ�ö�ʱ����ʼ��
		Gpt_EnableNotification(GptConf_GptChannelConfiguration_GptChannelConfiguration_TOM0_CH0);
		Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_TOM0_CH0, 10000 );
//		Gpt_StopTimer (const Gpt_ChannelType Channel);
		init_gpt = 1;
	}
}

void IoHwAb_GptNotificationTOM0_Ch0(void)
{
	static uint8 test_gpt = 0;
	test_gpt ^= 0x01;

	Dio_WriteChannel(DioConf_DioChannel_CAN2_STB_P0_7,test_gpt);
//	Gpt_StartTimer(GptConf_GptChannelConfiguration_GptChannelConfiguration_TOM0_CH0, 100 );
}




void PWM_out(void)
{
	//GTM��Ƶ��2M��0x0000-0x8000 === 0%-100%��         ����10us��Ƶ��200K,ռ�ձ�50%
	//PWM�������õ�ΪLOW������ռ�ձ�ֵΪ�͵�ƽ
	if (pwm_duty <= 0x8000)
	{
		Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_0_Drive1,0xA,pwm_duty);
//		Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_1_Drive2,0xA,0x4000);
//		Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_2_Drive3,0xA,pwm_duty);
//		Pwm_17_GtmCcu6_SetPeriodAndDuty(Pwm_17_GtmCcu6Conf_PwmChannel_PwmChannel_3_Drive4,0xA,pwm_duty);

		pwm_duty = pwm_duty + 0x1000;
	}
	else
	{
		pwm_duty = 0x0000;
	}
}


void SPI_Send(uint8 channelId, uint8 sequenceId)
{
    Std_ReturnType stdRet = E_NOT_OK;

 //   Spi_SetAsyncMode(1);

    stdRet = Spi_SetupEB(channelId, &ICU_sendBuf[0], &ICU_sendBufRxBuf[0], 1);

    if( E_OK == stdRet )
    {
        stdRet = Spi_SyncTransmit(sequenceId);
    }
}

void SPI_Write(uint16 percent)
{

	ICU_sendBuf[0]=percent&0xff;
	ICU_sendBuf[1]=((percent>>8)&0xff);
	//sendBuf[0]=(percent>>8&0xff);
	//sendBuf[1]=percent&0xFF;
	SPI_Send(0,0);
//	sendBuf[0] = 0;
//	sendBuf[1] = 0;
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
