/*
 * CanIf_MsgHandler_DATC_380.c
 *
 *  Created on: 2023Äê12ÔÂ18ÈÕ
 *      Author: lenovo
 */

#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h"
#include "DoorSys.h"

void CanMsgHandler_DATC_380(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	DATC_380.DATC_OutTempSnsrVal	= (uint8_t)(CanIf_MsgUnpack(msg->data,0,8));
	DATC_380.DATC_BlwrLvl			= (uint8_t)(CanIf_MsgUnpack(msg->data,8,4));
	DATC_380.DATC_BlwrLvl_Ps		= (uint8_t)(CanIf_MsgUnpack(msg->data,12,4));
	DATC_380.DATC_BlwLel_Rr			= (uint8_t)(CanIf_MsgUnpack(msg->data,16,4));
	DATC_380.DATC_IntakeDis			= (uint8_t)(CanIf_MsgUnpack(msg->data,20,2));

}
