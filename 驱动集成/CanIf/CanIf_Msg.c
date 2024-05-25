/*
 * CanIf_Message.c
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#include <CanIf_Msg.h>
#include <CanIfCfg_Msg.h>
#include "CanIf.h"
#include "BatteryApp.h"

CanMsgIdHandler_t   canRxMsgIdHander[MSG_RX_COUNT];
CanMsgIdHandler_t   canTxMsgIdHander[MSG_TX_COUNT];

void CanIf0_Msg_Init(void)
{
	for(uint8_t i=0;i<MSG_RX_COUNT;i++)
	{
		canRxMsgIdHander[i].idx = canRxMsgCfg[i].idx;
		canRxMsgIdHander[i].enable = canRxMsgCfg[i].enable;
		canRxMsgIdHander[i].msgId = canRxMsgCfg[i].msgId;
		canRxMsgIdHander[i].msgIdHandlerFunc=canRxMsgCfg[i].msgIdHandlerFunc;

	}

	for(uint8_t i=0;i<MSG_TX_COUNT;i++)
	{
		canTxMsgIdHander[i].idx	= canTxMsgCfg[i].idx;
		canTxMsgIdHander[i].enable = canTxMsgCfg[i].enable;
		canTxMsgIdHander[i].msgId = canTxMsgCfg[i].msgId;
		canTxMsgIdHander[i].msgIdHandlerFunc=canTxMsgCfg[i].msgIdHandlerFunc;
	}

}

void CanIf0_RxMessagePocessing(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	if((b_Can0MsgRx == 0x1)&&(GetPDSBatteryModeApi() == BATTERY_MODE_NORMAL))
	{
		for(uint8_t i = 0;i < MSG_RX_COUNT;i++)
		{
			if(msg->id == canRxMsgIdHander[i].msgId)
			{
				if(canRxMsgIdHander[i].msgIdHandlerFunc !=NULL)
				{
					canRxMsgIdHander[i].msgIdHandlerFunc();
				}
			}
		}

		b_Can0MsgRx = 0;		
	}
}

void CanIf0_TxMessage (void)
{
	static uint8_t transmitIdx=0;

//	if(transmitIdx < MSG_TX_COUNT )
//	{
		if(transmitIdx == canTxMsgIdHander[transmitIdx].idx)
		{
			if(canTxMsgIdHander[transmitIdx].msgIdHandlerFunc !=NULL)
			{
				canTxMsgIdHander[transmitIdx].msgIdHandlerFunc();
			}
		}
//
//	}
//
//
//	transmitIdx++;
//	if(transmitIdx > MSG_TX_COUNT)
//	{
//		transmitIdx = 0;
//	}


}
