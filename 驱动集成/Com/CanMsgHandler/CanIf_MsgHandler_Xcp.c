/*
 * CanIf_Message.c
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#include <CanIf_Msg.h>
#include "CanIf.h"
#include "CanIf_MsgHandler_Xcp.h"

uint8 msg_R_byte[8] = {0};
uint8 Xcp_indicator = 0;
uint8 Xcp_Tx_indicator = 0;

volatile uint32 calibration_2 = 0x3583;
uint32 calibration_1 = 0x3585;
uint32 calibration_1000 __attribute__ ((section(".xcp_cal_wp"))) = 1;
uint32 calibration_2000 __attribute__ ((section(".xcp_cal_wp"))) = 2;
uint32 calibration_3000 __attribute__ ((section(".xcp_cal_wp"))) = 3;
uint32 calibration_4000 __attribute__ ((section(".xcp_cal_wp"))) = 4;
uint32 calibration_5000 __attribute__ ((section(".xcp_cal_wp"))) = 5;
uint32 calibration_6000 __attribute__ ((section(".xcp_cal_wp"))) = 6;
uint32 calibration_7000 __attribute__ ((section(".xcp_cal_wp"))) = 7;
uint32 calibration_8000 __attribute__ ((section(".xcp_cal_wp"))) = 8;
uint32 calibration_9000 __attribute__ ((section(".xcp_cal_wp"))) = 9;
uint32 calibration_10000 __attribute__ ((section(".xcp_cal_wp"))) = 10;


uint32 measure_1000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_2000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_3000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_4000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_5000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_6000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_7000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_8000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_9000 __attribute__ ((section(".xcp_mes"))) ;
uint32 measure_10000 __attribute__ ((section(".xcp_mes")));



void detectDisconnectCommand(uint8 data0)
{
	if(data0==0xFE)
	{

		/* TODO: Do somthing after disconnetion */

	}
}

/***************************xcp********************************************************************************/
void CanMsgHandler_XcpTransmitCrm(CCP_BYTEPTR pMsgTxData , uint8_t len)
{

    CCP_BYTEPTR p_XcpTxDataBuf = pMsgTxData;
	uint8_t XcpTxDataBufLen = len;

	if(XcpTxDataBufLen <= 8)
	{
		can_message_t *msg = &g_TransmitMsg_CAN0;
		msg->cs = 0;
		msg->id = CAN_MSG_XCP_TX;
		msg->length = 8;

		msg->data[0]=(uint8_t)p_XcpTxDataBuf[0];
		msg->data[1]=(uint8_t)p_XcpTxDataBuf[1];
		msg->data[2]=(uint8_t)p_XcpTxDataBuf[2];
		msg->data[3]=(uint8_t)p_XcpTxDataBuf[3];
		msg->data[4]=(uint8_t)p_XcpTxDataBuf[4];
		msg->data[5]=(uint8_t)p_XcpTxDataBuf[5];
		msg->data[6]=(uint8_t)p_XcpTxDataBuf[6];
		msg->data[7]=(uint8_t)p_XcpTxDataBuf[7];

		Xcp_Tx_indicator = 1;

	}

}

void CanMsgHandler_XcpTransmit(void)
{
	if(Xcp_Tx_indicator)
	{
		can_message_t *msg = &g_TransmitMsg_CAN0;
	    CanIf0_Send(msg);

	    Xcp_Tx_indicator = 0;
	}
}

int CanMsgHandler_XcpTransmitCrmPossible( void )
{
	int transferState = 0;

	/* if return Success, then XcpSendCallBack() will be called to clear XCP flags bit*/
    if(STATUS_SUCCESS == CAN_GetTransferStatus(&CAN0can_pal1_instance,TX_MAILBOX_CAN1))
    {
    	transferState = 1;
    }

    return transferState;
}


void CanMsgHandler_XcpReq(void)
{
	can_message_t *pMsg_R = &g_RecvMsg_CAN0;

	msg_R_byte[0]= (uint8)pMsg_R->data[0];
	msg_R_byte[1]= (uint8)(pMsg_R->data[1]);
	msg_R_byte[2]= (uint8)(pMsg_R->data[2]);
	msg_R_byte[3]= (uint8)(pMsg_R->data[3]);
	msg_R_byte[4]= (uint8)(pMsg_R->data[4]);
	msg_R_byte[5]= (uint8)(pMsg_R->data[5]);
	msg_R_byte[6]= (uint8)(pMsg_R->data[6]);
	msg_R_byte[7]= (uint8)(pMsg_R->data[7]);

	Xcp_indicator = 1;

}

void CanMsgHandler_XcpCommand(void)
{
    if(Xcp_indicator)
    {
    	Xcp_indicator = 0;
		XcpCommand((const vuint32*)(&(msg_R_byte[0])));
		detectDisconnectCommand(msg_R_byte[0]);
    }
}

void XCP()
{
	CanMsgHandler_XcpCommand();
	XcpBackground();
	 if (CanMsgHandler_XcpTransmitCrmPossible())
	 {
		 CanMsgHandler_XcpTransmit();
	     XcpSendCallBack();
	 }
}


void xcptest()
{
	if(calibration_1==1234)
	{
		measure_1000=1234;
	}
	if(calibration_1000==0)
	{
		measure_1000=0;
	}
	if(calibration_2000==0)
	{
		measure_2000=0;
	}

	if(calibration_3000==0)
	{
		measure_3000=0;
	}

	if(calibration_4000==0)
	{
		measure_4000=0;
	}


	if(calibration_5000==0)
	{
		measure_5000=0;
	}

	if(calibration_6000==0)
	{
		measure_6000=0;
	}

	if(calibration_7000==0)
	{
		measure_7000=0;
	}
	if(calibration_8000==0)
	{
		measure_8000=0;
	}

	if(calibration_9000==0)
	{
		measure_9000=0;
	}

	if(calibration_10000==0)
	{
		measure_10000=0;
	}

}
/***************************xcp********************************************************************************/
