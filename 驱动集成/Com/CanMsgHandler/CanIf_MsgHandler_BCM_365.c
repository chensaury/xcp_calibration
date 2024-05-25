/*
 * CanIf_MsgHandler_BCM_365.c
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


void CanMsgHandler_BCM_365(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	BCM_365.BCM_Ign1SwSta 		= (uint8_t)(CanIf_MsgUnpack(msg->data,0,2));
	BCM_365.BCM_Ign2SwSta  		= (uint8_t)(CanIf_MsgUnpack(msg->data,2,2));
	BCM_365.BCM_ACCSwSta  		= (uint8_t)(CanIf_MsgUnpack(msg->data,4,2));
	BCM_365.BCM_KeyInSwSta 		= (uint8_t)(CanIf_MsgUnpack(msg->data,6,2));
	BCM_365.BCM_CenralLockState = (uint8_t)(CanIf_MsgUnpack(msg->data,8,2));
	BCM_365.BCM_SunRoofOpnSta   = (uint8_t)(CanIf_MsgUnpack(msg->data,10,2));
	BCM_365.BCM_Crash_Occur     = (uint8_t)(CanIf_MsgUnpack(msg->data,12,1));
	BCM_365.BCM_DrSpeedSet    = (uint8_t)(CanIf_MsgUnpack(msg->data,13,2));


}
