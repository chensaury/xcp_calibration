/*
 * CanIf_MsgHandler_DCAS_FR_520.c
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

void CanMsgHandler_DCAS_FR_520(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	DCAS_FR_520.DCAS_FR_Obstacle_Pos = (uint8_t)(CanIf_MsgUnpack(msg->data,0,8));
	DCAS_FR_520.DCAS_FR_Obstacle_Status = (uint8_t)(CanIf_MsgUnpack(msg->data,8,2));
	DCAS_FR_520.DCAS_FR_Sensor_State = (uint8_t)(CanIf_MsgUnpack(msg->data,10,2));
	DCAS_FR_520.DCAS_FR_Checksum = (uint8_t)(CanIf_MsgUnpack(msg->data,12,8));
	DCAS_FR_520.DCAS_FR_RollingCounter = (uint8_t)(CanIf_MsgUnpack(msg->data,20,4));

}
