/*
 * CanIf_Message.c
 *
 *  Created on: 2023年12月16日
 *      Author: Administrator
 */

#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h"
#include "DoorSys.h"
#include "DCU.h"


void CanMsgHandler_DCU_FL_310(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;
	DoorControl_t *door = & g_door;
	static DCU_MovementReq_t DCU_FLMovementReq_Old = Stop;

	DCU_FL_310.DCU_FLMovementReq 		= (DCU_MovementReq_t)	CanIf_MsgUnpack(msg->data,4,2);
	DCU_FL_310.DCU_FL_LatchState 		= (DCU_LatchState_t)	CanIf_MsgUnpack(msg->data,0,2);
	DCU_FL_310.DCU_FL_WdState 			= (DCU_WdState_t)		CanIf_MsgUnpack(msg->data,2,2);
	DCU_FL_310.DCU_FL_ManAssistForce	= (DCU_ManAssistForce_t)CanIf_MsgUnpack(msg->data,6,2);
	DCU_FL_310.DCU_FL_StopAngle			= (uint8_t)				CanIf_MsgUnpack(msg->data,8,8);
	DCU_FL_310.DCU_FL_RqstOpenVal 		= (uint8_t)				CanIf_MsgUnpack(msg->data,16,7);
	DCU_FL_310.DCU_FL_PDS_SETINGS		= (DCU_PDS_SETINGS_t)	CanIf_MsgUnpack(msg->data,24,2);

	int flag = 1;
	int canflag = 1;

	if((DCU_FL_310.DCU_FLMovementReq == Opening) ||(DCU_FL_310.DCU_FLMovementReq == Closing))
	{
		if(timer300ms_counter != 0 )
		{
			/* 2 */
			if((DCU_FL_310.DCU_FLMovementReq == Opening)||(DCU_FL_310.DCU_FLMovementReq == Closing ))
			{
				canflag = 0;
			}
			//不再响应

		}
		else if(timer300ms_counter == 0)
		{
			TIMERSTART = 1; //计时开始
			//超出300响应
			canflag = 1;

		}

	}

	/* issue fix */
	if(canflag)
	{
		if((door->state == DOOR_STATE_OPENNING)||(door->state == DOOR_STATE_CLOSING) )
		{
			if((DCU_FL_310.DCU_FLMovementReq == Opening) ||(DCU_FL_310.DCU_FLMovementReq == Closing))
			{
				DCU.MovementReq = Stop;
				flag = 0;
			}
		}
	}

	if(canflag)
	{
		if(flag)
		{
			if(DCU_FL_310.DCU_FLMovementReq == 	Opening)
			{
				DCU.MovementReq = Opening;
			}
			else if(DCU_FL_310.DCU_FLMovementReq == Closing)
			{
				DCU.MovementReq = Closing;
			}
			else if(DCU_FL_310.DCU_FLMovementReq == Stop)
			{
				DCU.MovementReq = Stop;
			}
		}
	}

	DCU_FLMovementReq_Old = DCU_FL_310.DCU_FLMovementReq;
	
	switch(DCU_FL_310.DCU_FL_LatchState)
	{
		case 0:
		{
			DCU.LatchState = LatchState_PRIMARY_POS;
			break;
		}
		case 1:
		{
			DCU.LatchState = LatchState_SECONDARY_POS;
			break;
		}
		case 2:
		{
			DCU.LatchState = LatchState_UNLATCHED;
			break;
		}
		case 3:
		{
			DCU.LatchState = LatchState_Unknown;
			break;
		}
		default:
			break;
	}

	switch(DCU_FL_310.DCU_FL_WdState)
	{
		case 0:
		{
			DCU.WdState = Window_Close;
			break;
		}
		case 1:
		{
			DCU.WdState = Window_Open;
			break;
		}
		case 2:
		{
			DCU.WdState = WdState_Not_Used;
			break;
		}
		case 3:
		{
			DCU.WdState = WdState_Error_Indicator;
			break;
		}
		default:
			break;
	}
	
	switch(DCU_FL_310.DCU_FL_ManAssistForce)
	{
		case 0:
		{
			DCU.ManAssistForce = Light;
			break;
		}
		case 1:
		{
			DCU.ManAssistForce = Normal;
			break;
		}
		case 2:
		{
			DCU.ManAssistForce = Heavy;
			break;
		}
		case 3:
		{
			DCU.ManAssistForce = Reserved;
			break;
		}
		default:
			break;
	}

	switch(DCU_FL_310.DCU_FL_PDS_SETINGS)
	{
		case 0:
		{
			DCU.PDS_SETINGS = AUTO;
			break;
		}
		case 1:
		{
			DCU.PDS_SETINGS = MANUAL;
			break;
		}
		case 2:
		{
			DCU.PDS_SETINGS = HOLD;
			break;
		}
		case 3:
		{
			DCU.PDS_SETINGS = RESERVED;
			break;
		}
		default:
			break;
	}
}


