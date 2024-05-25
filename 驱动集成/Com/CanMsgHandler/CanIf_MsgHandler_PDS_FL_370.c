/*
 * PDS_Message.c
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
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

void CanMsgHandler_PDS_FL_370(void)
{
	PDS_FL_370.PDS_FL_CalibrStatus   = PDS_getCalibrStatus();
	PDS_FL_370.PDS_FL_ChimeReq       = PDS_getChimeReq();
	PDS_FL_370.PDS_FL_SnsrActCommand = PDS_getSnsrActCommand();
	PDS_FL_370.PDS_FL_BrakeStatus    = PDS_getBrakeStatus();
	PDS_FL_370.PDS_FL_DoorAngle      = PDS_getDoorAngle();
	PDS_FL_370.PDS_FL_DoorAngleStuck = PDS_getDoorAngleStuck();
	PDS_FL_370.PDS_FL_DrAngVel 		 = PDS_getDoorAngVel();
	PDS_FL_370.PDS_FL_SwingActrStatus= PDS_getSwingActrStatus();
	CanNMStatus.CanNM_FL_SleepFlag   = CanNM_Readysleep_Status();

#if(PDS_DOOR_SIDE_FL == PDS_DOOR_SIDE_TYPE)
	{
		can_message_t *msg = &g_TransmitMsg_CAN0;
		uint8_t dataBuf[8];
		msg->cs = 0;
		msg->id = canTxMsgIdHander[MSG_PDS_FL_370].msgId;
		msg->length = 8;

		CanIf_MsgPack(PDS_FL_370.PDS_FL_CalibrStatus   ,dataBuf,0, 2);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_ChimeReq       ,dataBuf,2, 2);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_SnsrActCommand ,dataBuf,4, 2);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_BrakeStatus    ,dataBuf,6, 2);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_DoorAngle      ,dataBuf,8, 7);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_DoorAngleStuck ,dataBuf,15,1);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_DrAngVel	   ,dataBuf,16,8);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_SwingActrStatus,dataBuf,24,4);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_Mode		   ,dataBuf,28,4);
		CanIf_MsgPack(PDS_FL_370.PDS_FL_Handle_Request ,dataBuf,32,2);
		CanIf_MsgPack(CanNMStatus.CanNM_FL_SleepFlag   ,dataBuf,56,8);


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


