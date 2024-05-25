/*
 * CanIf_MsgHandler_IMU_350.c
 *
 *  Created on: 2023Äê12ÔÂ19ÈÕ
 *      Author: Administrator
 */

#include "IMU.h"
#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h"
#include "DoorSys.h"


#define No_Failure (0U)

void CanMsgHandler_IMU_350(void)
{
	can_message_t *msg = &g_RecvMsg_CAN0;

	IMU_350.IMU_LatAccelSigSta	= CanIf_MsgUnpack(msg->data,0,4);
	IMU_350.IMU_LongAccelSigSta = CanIf_MsgUnpack(msg->data,4,4);
	IMU_350.IMU_LatAccelVal		= CanIf_MsgUnpack(msg->data,8,8);
	IMU_350.IMU_LongAccelVal	= CanIf_MsgUnpack(msg->data,16,8);

	switch(IMU_350.IMU_LatAccelSigSta)
		{
			case 0:
			{
				IMU.LatAccelSigSta = No_failure;
				break;
			}
			case 1:
			{
				IMU.LatAccelSigSta = IMU_Lateral_acceleration_failure;
				break;
			}
			case 2:
			{
				IMU.LatAccelSigSta = Initialization_is_running;
				break;
			}
			case 3:
			{
				IMU.LatAccelSigSta = IMU_Lateral_acceleration_failure_AND_Initialization_is_running;
				break;
			}
			default:
				break;
		}
		switch(IMU_350.IMU_LongAccelSigSta)
		{
			case 0:
			{
				IMU.LongAccelSigSta = No_failure;
				break;
			}
			case 1:
			{
				IMU.LongAccelSigSta = IMU_Lateral_acceleration_failure;
				break;
			}
			case 2:
			{
				IMU.LongAccelSigSta = Initialization_is_running;
				break;
			}
			case 3:
			{
				IMU.LongAccelSigSta = IMU_Lateral_acceleration_failure_AND_Initialization_is_running;
				break;
			}
			default:
				break;
			}

		b_Roll = (((float)IMU_350.IMU_LatAccelVal / 5) - 25);
		b_Pitch = (((float)IMU_350.IMU_LongAccelVal / 5) - 25);

}


