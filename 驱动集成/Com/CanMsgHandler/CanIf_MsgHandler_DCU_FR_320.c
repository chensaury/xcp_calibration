/*
 * CanIf_MsgHandler_DCU_FR_320.c
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

void CanMsgHandler_DCU_FR_320(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;
	DoorControl_t *door = &g_door;

	DCU_FR_320.DCU_FRMovementReq =(DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,4,2);

	if(DCU_FR_320.DCU_FRMovementReq == 	Opening)
	{
		door->DoorCmd = DOOR_CMD_OPEN;
	}
	else if(DCU_FR_320.DCU_FRMovementReq == Closing)
	{
		door->DoorCmd = DOOR_CMD_CLOSE;
	}
	else if(DCU_FR_320.DCU_FRMovementReq == Stop)
	{
		door->DoorCmd = DOOR_CMD_STOP;
	}
	else
	{

	}
	DCU_FR_320.DCU_FR_LatchState =(DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,0,2);
	DCU_FR_320.DCU_FR_WdState=(DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,3,2);
	DCU_FR_320.DCU_FR_ManAssistForce=(DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,6,2);
	DCU_FR_320.DCU_FR_StopAngle = (DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,8,8);
	DCU_FR_320.DCU_FR_RqstOpenVal = (DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,16,7);
	DCU_FR_320.DCU_FR_PDS_SETINGS = (DCU_MovementReq_t)CanIf_MsgUnpack(msg->data,23,1);
}
