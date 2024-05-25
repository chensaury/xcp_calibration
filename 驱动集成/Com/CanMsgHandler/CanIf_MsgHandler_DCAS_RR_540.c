/*
 *  CanIf_MsgHandler_DCAS_RR_540.c
 *
 *  Created on: 2023��12��19��
 *      Author: lenovo
 */


#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h"
#include "DoorSys.h"

void CanMsgHandler_DCAS_RR_540(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	DCAS_RR_540.DCAS_RR_Obstacle_Pos = (uint8_t)(CanIf_MsgUnpack(msg->data,0,8));
	DCAS_RR_540.DCAS_RR_Obstacle_Status = (uint8_t)(CanIf_MsgUnpack(msg->data,8,2));
	DCAS_RR_540.DCAS_RR_Sensor_State = (uint8_t)(CanIf_MsgUnpack(msg->data,10,2));
	DCAS_RR_540.DCAS_RR_Checksum = (uint8_t)(CanIf_MsgUnpack(msg->data,12,8));
	DCAS_RR_540.DCAS_RR_RollingCounter = (uint8_t)(CanIf_MsgUnpack(msg->data,20,4));

}
