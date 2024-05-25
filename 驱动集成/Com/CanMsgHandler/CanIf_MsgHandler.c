/*
 * CanIf_Message.c
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#include <CanIf_Msg.h>
#include "CanIf.h"
#include <CanIfCfg_Msg.h>
#include <CanMsgHandler/CanIf_MsgHandler.h>
#include <CanMsgHandler/CanIf_Signals.h>
#include <CanMsgHandler/CanIf_Unpack.h>
#include "CanIf_Msg.h" 
#include "DoorSys.h"


PDS_CalibrStatus_t PDS_getCalibrStatus(void)
{
	DoorControl_t *door = &g_door;
	PDS_CalibrStatus_t retStatus = CalibrStatus_Uncalibrated;

	if((door->b_PosCloseLearned)&&(door->b_PosOpenLearned))
	{
		retStatus = CalibrStatus_Calibrated;
	}

		return (PDS_CalibrStatus_t)(retStatus);


}



PDS_ChimeReq_t PDS_getChimeReq(void)
{
	return ChimeReq_WarningRepeated;
}

uint8_t PDS_getDoorAngle(void)
{
	DoorControl_t *door = &g_door;

	int16_t Pos =(int16_t)(door->u16Realtime_Pos);

     return (uint8_t)((Pos-2000)/21.4);
}

PDS_ChimeReq_t PDS_getSnsrActCommand(void)
{
	return SnsrActCommand_Idle;
}

PDS_BrakeStatus_t PDS_getBrakeStatus(void)
{
	DoorControl_t *door = &g_door;
	PDS_BrakeStatus_t retStatus = NoBrake;

	if(door->b_ebrake)
	{
		retStatus = EBrake;
	}
	return (PDS_BrakeStatus_t)retStatus;
}


PDS_DoorAngleStuck_t PDS_getDoorAngleStuck(void)
{

	DoorControl_t *door = &g_door;
	PDS_DoorAngleStuck_t retStatus = DoorAngleStuck_Off;

	if(door->b_close_block)
	{
		retStatus = DoorAngleStuck_On;
	}

	if(door->b_open_block)
	{
		retStatus = DoorAngleStuck_On;
	}

	return (PDS_DoorAngleStuck_t)retStatus;
}

uint8_t PDS_getDoorAngVel(void)
{
	 DoorControl_t *door = &g_door;

    return (door->u16Velocity/100);
}


PDS_SwingActrStatus_t PDS_getSwingActrStatus(void)
{

	 DoorControl_t *door = &g_door;
	 PDS_SwingActrStatus_t doorStatus= Unknown;
	/****************************************
	{
		Unknown,
		FullClosed,
		FullOpened,
		OverOpened,
		MiddleOfOpen,
		Secondary,
		WaitForMvmtCondition,
		MovgOutAuto,
		MovgOutTip2Run,
		MovgOutManAssist,
		MovgOutReverse,
		MovgInAuto,
		MovgInTip2Run,
		MovgInManAssist,
		MovgInReverse,
		MovgInReset,
	}PDS_SwingActrStatus_t;
	*********************************************/

	if(door->u16Realtime_Pos < door->u16SoftClosePos+50)
	{
		doorStatus = FullClosed;
	}
	else if(door->u16Realtime_Pos > door->u16SoftOpenPos-50)
	{
		doorStatus = FullOpened;
	}
	else if((door->u16Realtime_Pos < door->u16SoftOpenPos-50)&&(door->u16Realtime_Pos > door->u16SoftClosePos+50))
	{
		doorStatus = MiddleOfOpen;
	}

	return doorStatus;

}

PDS_Mode_t PDS_getMode(void)
{

	 PDS_Mode_t PDS_Mode = Mode_Unknown;

	 return PDS_Mode;
}

PDS_Handle_Request_t PDS_getHandleRequest(void)
{

	 PDS_Handle_Request_t PDS_Handle_Request = Handle_Request_OFF;

	 return PDS_Handle_Request;
}
