/*
 * CanIf_MsgHandler_DCAS_RL_530.c
 *
 *  Created on: 2023Äê12ÔÂ19ÈÕ
 *      Author: lenovo
 */


#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h"
#include "DoorSys.h"

void CanMsgHandler_DCAS_RL_530(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	DCAS_RL_530.DCAS_RL_Obstacle_Pos = (uint8_t)(CanIf_MsgUnpack(msg->data,0,8));
	DCAS_RL_530.DCAS_RL_Obstacle_Status = (uint8_t)(CanIf_MsgUnpack(msg->data,8,2));
	DCAS_RL_530.DCAS_RL_Sensor_State = (uint8_t)(CanIf_MsgUnpack(msg->data,10,2));
	DCAS_RL_530.DCAS_RL_Checksum = (uint8_t)(CanIf_MsgUnpack(msg->data,12,8));
	DCAS_RL_530.DCAS_RL_RollingCounter = (uint8_t)(CanIf_MsgUnpack(msg->data,20,4));

}
