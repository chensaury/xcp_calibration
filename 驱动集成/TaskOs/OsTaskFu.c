/*
 * OsTaskFu.c
 *
 *  Created on: 06.12.2023
 *
 */


#include <MotAct.h>
#include <Switch.h>
#include "OsTypedefs.h"

#include "DioIf.h"
#include "SpiIf.h"
#include "CanIf.h"
#include "UartIf.h"
#include "Adc_Mgt.h"
#include "DualHall.h"
#include "DoorSys.h"
#include"Current.h"
#include "DCU.h"
#include "TCU.h"
#include "IMU.h"
#include "TLE926x.h"
#include "FlashIf.h"
#include "SBC_Handler.h"
#include "CanNM.h"
#include "SBC_Handler.h"
#include "ADC_Config_Driver.h"
#include "Framework.h"
#include "CANTp.h"
#include "UDS.h"
#include "Application.h"



void CANTPFunction(void)
{
    TpTxTask();
    TpRxTask();
}

void OsTaskfu_cyclic(void)
{


    Framework_Task();

	Application_Task();

	CanIf0_DebugMsgRxProcessing();
	CanIf0_RxMessagePocessing();

	CANTPFunction();
	CanNm_RxIndication( g_RecvMsg_CAN0.id, g_RecvMsg_CAN0.data);

/*	MotorCurrent_Init();*/

}

void OsTaskfu_1ms(void)
{
	XCP();
	MotorActator_StateMachine();
	CanIf0_ApInfoTransmit();
	CanIf0_DebugMsgTransmit();

	DoorSys_ApEventCheck();

	IMU_Handler();

    TpTimerTask();
	XcpBackground();
	 if (CanMsgHandler_XcpTransmitCrmPossible())
	 {
		 CanMsgHandler_XcpTransmit();
	     XcpSendCallBack();
	 }
	 xcptest();


}

void OsTaskfu_5ms(void)
{
	DCU_Handler();

	Switch_CmdHandler();

	GetQueueAverage();

	DoorSys_CmdHandle();
	DoorSys_StateMachine();

	DoorSys_BlockCheck();
	EnQueue(GlideAverageValueFliet());


	DoorSys_ApEventCheck();

	DoorSys_TipToRunCheck();
}

void OsTaskfu_10ms(void)
{
	sbc_wd_trigger();

	DoorSys_ManaualAssitCheck();

	UdsTimerTask();

	SBC_transmit();




	MotorCurrent_RataChange(1);

}

void OsTaskfu_100ms(void)
{
	SBC_Check_OL();
	SBC_Check_HS_OC_OT();

}

void OsTaskfu_200ms(void)
{

	NOP();
	NOP();

}


void OsTaskfu_init(void)
{
    // Initialize Timer for OS Scheduler

	__disable();
	DioIf_Init();
	CanIf0_Init();
	ADC_Init();

	//UartIf_Init();
	//AdcIf_Init();
	//MotorCurrent_Init();

	__enable();
	SpiIf_SbcInit();
	DualHall_Init();

	SpiIf_sendSbc();

	Switch_Init();

	SBC_Sys_Init();

	Flash_Init();
	CanNm_Init();

	InitCurrentQueue();
	MotorAdc_InitValue();

	Framework_Init();


	Flash_Read();
	Flash_Write_Check();
	SBC_Check_WK_Source();
    Application_Init();

	NM_Check_Passiverequest();
}






