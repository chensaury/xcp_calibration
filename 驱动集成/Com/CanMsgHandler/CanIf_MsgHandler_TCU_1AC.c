/*
 * CanIf_Message.c
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h"
#include "CanIf_SigTypedefs.h"
#include "TCU.h"



void CanMsgHandler_TCU_1AC(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	TCU_1AC.TCU_VehSpdKphVal = (uint16_t)(CanIf_MsgUnpack(msg->data,0,13));
	TCU_1AC.TCU_VehicleSpeedValid = (uint8_t)(CanIf_MsgUnpack(msg->data,13,1));
	TCU_1AC.TCU_1AC_Checksum =  (uint8_t)(CanIf_MsgUnpack(msg->data,16,8));
	TCU_1AC.TCU_1AC_RollingCounter = (uint8_t)(CanIf_MsgUnpack(msg->data,24,4));

	TCU.Vehicle_Speed = TCU_1AC.TCU_VehSpdKphVal;

	if(TCU_1AC.TCU_VehicleSpeedValid == 0)
	{
		TCU.Vehicle_speed_valid = Valid;
	}
	else if(TCU_1AC.TCU_VehicleSpeedValid == 1)
	{
		TCU.Vehicle_speed_valid = Invalid;
	}


}
