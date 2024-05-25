/*
 * CanIf_MsgHandler_PDS_RL_372.c
 *
 *  Created on: 2023Äê12ÔÂ19ÈÕ
 *      Author: Administrator
 */


#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_MsgHandler.h>
#include <CanMsgHandler/CanIf_Pack.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include "CanIf_Msg.h"
#include "DoorSys.h"
#include "CanNM.h"

void CanMsgHandler_PDS_RL_372(void)
{
	PDS_RL_372.PDS_RL_CalibrStatus   = PDS_getCalibrStatus();
	PDS_RL_372.PDS_RL_ChimeReq       = PDS_getChimeReq();
	PDS_RL_372.PDS_RL_SnsrActCommand = PDS_getSnsrActCommand();
	PDS_RL_372.PDS_RL_BrakeStatus    = PDS_getBrakeStatus();
	PDS_RL_372.PDS_RL_DoorAngle      = PDS_getDoorAngle();
	PDS_RL_372.PDS_RL_DoorAngleStuck = PDS_getDoorAngleStuck();
	PDS_RL_372.PDS_RL_DrAngVel  = PDS_getDoorAngVel();
	PDS_RL_372.PDS_RL_SwingActrStatus= PDS_getSwingActrStatus();
	CanNMStatus.CanNM_RL_SleepFlag   = CanNM_Readysleep_Status();

#if(PDS_DOOR_SIDE_RL == PDS_DOOR_SIDE_TYPE)
	{
		can_message_t *msg = &g_TransmitMsg_CAN0;
		uint8_t dataBuf[8];
		msg->cs = 0;
		msg->id = canTxMsgIdHander[MSG_PDS_RL_372].msgId;
		msg->length = 8;

		CanIf_MsgPack(PDS_RL_372.PDS_RL_CalibrStatus   ,dataBuf,0, 2);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_ChimeReq       ,dataBuf,1, 2);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_SnsrActCommand ,dataBuf,4, 2);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_BrakeStatus    ,dataBuf,6, 2);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_DoorAngle      ,dataBuf,8, 7);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_DoorAngleStuck ,dataBuf,15,1);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_DrAngVel  	   ,dataBuf,16,8);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_SwingActrStatus,dataBuf,24,4);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_Mode		   ,dataBuf,28,4);
		CanIf_MsgPack(PDS_RL_372.PDS_RL_Handle_Request ,dataBuf,32,2);
		CanIf_MsgPack(CanNMStatus.CanNM_RL_SleepFlag   ,dataBuf,56,8);

		msg->data[0]=dataBuf[0];
		msg->data[1]=dataBuf[1];
		msg->data[2]=dataBuf[2];
		msg->data[3]=dataBuf[3];
		msg->data[4]=dataBuf[4];
		msg->data[5]=dataBuf[5];
		msg->data[6]=dataBuf[6];
		msg->data[7]=dataBuf[7];

		CanIf0_Send(msg);
	}
#endif
}
