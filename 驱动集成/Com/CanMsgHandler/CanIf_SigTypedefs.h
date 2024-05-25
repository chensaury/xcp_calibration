/*
 * CanIf_MsgCfg.h
 *
 *  Created on: 2023��12��15��
 *      Author: lenovo
 */

#ifndef _2_CDRV_CANIF_MSGCFG_H_
#define _2_CDRV_CANIF_MSGCFG_H_

#include "Cpu.h"




typedef enum BCM_IgnSwSta
{
	OFF,
	ON,
	Not_used,
	Error_Indicator,
}BCM_IgnSwSta_t;

typedef enum BCM_CenralLockState
{
	Unlocked,
	CenralLockState_Reserved,
	Locked,
	CenralLockState_Unknown,
}BCM_CenralLockState_t;

typedef enum BCM_SunRoofOpnSta
{
	SunRoofOpnSta_Closed,
	SunRoofOpnSta_Opened,
	SunRoofOpnSta_Not_Used,
	SunRoofOpnSta_Error_Indicator,
}BCM_SunRoofOpnSta_t;

typedef enum BCM_Crash_Occur
{
	Crash_Occur_No_crash,
	Crash_Occur_Crash,
}BCM_Crash_Occur_t;

typedef enum BCM_DrSpeedSet
{
	DrSpeedSet_Slow,
	DrSpeedSet_Standard,
	DrSpeedSet_Fast,
	DrSpeedSet_Reserved,
}BCM_DrSpeedSet_t;

typedef enum DCU_LatchState
{
	LatchState_PRIMARY_POS,
	LatchState_SECONDARY_POS,
	LatchState_UNLATCHED,
	LatchState_Unknown,
}DCU_LatchState_t;

typedef enum DCU_WdState
{
	Window_Close,
	Window_Open,
	WdState_Not_Used,
	WdState_Error_Indicator,
}DCU_WdState_t;

/***************
 * 0x0:Idle
 * 0x1:Opening
 * 0x2:Closing
 * 0x3:Stop
 *****************/
typedef enum DCU_MovementReq
{
	Idle,
	Opening,
	Closing,
	Stop,
}DCU_MovementReq_t;


typedef enum DCU_ManAssistForce
{
	Light,
	Normal,
	Heavy,
	Reserved
}DCU_ManAssistForce_t;

typedef enum DCU_PDS_SETINGS
{
	AUTO,
	MANUAL,
	HOLD,
	RESERVED,
}DCU_PDS_SETINGS_t;


typedef enum DATC_BlwrLvl
{
	BlwrLvl_OFF,
	Level_0,
	Level_1,
	Level_2,
	Level_3,
	Level_4,
	Level_5,
	Level_6,
	Level_7,
	Level_8,
	Reserved_0,
	Reserved_1,
	Reserved_2,
	Reserved_3,
	Reserved_4,
	ErrorIndicator
}DATC_BlwrLvl_t;



typedef enum DATC_IntakeDis
{
	DATC_IntakeDis_Default,
	REC,
	FRE,
	Error_indicator,
}DATC_IntakeDis_t;


typedef enum DCAS_Obstacle_Status
{
	No_obstacle,
	Obstacle_Not_Move,
	Obstcle_Moving_Close,
	Obstcle_Moving_Away,
}DCAS_Obstacle_Status_t;


typedef enum DCAS_Sensor_State
{
	Sensor_State_Idle,
	Measuring,
	Degraded,
	Fault,
}DCAS_Sensor_State_t;


typedef enum PDS_CalibrStatus
{
	CalibrStatus_Calibrated, //0
	CalibrStatus_Uncalibrated, //1
	CalibrStatus_Reserved, //2
	CalibrStatus_Error, //3
}PDS_CalibrStatus_t;

typedef enum PDS_ChimeReq
{
	ChimeReq_WarningRepeated,
	ChimeReq_Warning,
	ChimeReq_Operation,
	ChimeReq_OFF,
}PDS_ChimeReq_t;


typedef enum PDS_SnsrActCommand
{
	SnsrActCommand_Idle,
	SnsrActCommand_Measure,
	SnsrActCommand_Reserved,
	SnsrActCommand_ErrorAndStop,
}PDS_SnsrActCommand_t;

typedef enum PDS_BrakeStatus
{
	NoBrake,
	EBrake,
	HoldBrake,
	Both
}PDS_BrakeStatus_t;


typedef enum PDS_DoorAngleStuck
{
	DoorAngleStuck_Off,
	DoorAngleStuck_On,
}PDS_DoorAngleStuck_t;

typedef enum PDS_SwingActrStatus
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

typedef enum PDS_Mode
{
	Mode_Unknown,
	PowerMode,
	TipToRunMode,
	ManualAssistMode,
	SafeClosingMode,
	PlayProtectMode,
	ThermalProtectMode,
	DiagnosticMode,
	ManufatureMode,
	MatenanceMode,
	ShipmentMode,
	Reserved1,
	Reserved2,
	Reserved3,
	Reserved4,
	Reserved5,
}PDS_Mode_t;

typedef enum PDS_Handle_Request
{
	Handle_Request_OFF,
	ExtOn,
	IntOn,
	Handle_Request_Reserved,
}PDS_Handle_Request_t;


/***************************************************************
 *
 **********     Message Signals                          *******
 *
 ****************************************************************/


typedef struct TCU_1AC
{
	uint16_t TCU_VehSpdKphVal;
	uint8_t TCU_VehicleSpeedValid;
	uint8_t TCU_1AC_Checksum;
	uint8_t TCU_1AC_RollingCounter;
}TCU_1AC_t;

typedef struct BCM_365
{
	BCM_IgnSwSta_t BCM_Ign1SwSta;
	BCM_IgnSwSta_t BCM_Ign2SwSta;
	BCM_IgnSwSta_t BCM_ACCSwSta;
	BCM_IgnSwSta_t BCM_KeyInSwSta;
	BCM_CenralLockState_t BCM_CenralLockState;
	BCM_SunRoofOpnSta_t BCM_SunRoofOpnSta;
	BCM_Crash_Occur_t BCM_Crash_Occur;
	BCM_DrSpeedSet_t BCM_DrSpeedSet;

}BCM_365_t;

typedef struct DCU_FL_310
{
	DCU_LatchState_t DCU_FL_LatchState;
	DCU_WdState_t DCU_FL_WdState;
	DCU_MovementReq_t DCU_FLMovementReq;
	DCU_ManAssistForce_t DCU_FL_ManAssistForce;
	uint8_t DCU_FL_StopAngle;
	uint8_t DCU_FL_RqstOpenVal;
	DCU_PDS_SETINGS_t DCU_FL_PDS_SETINGS;
}DCU_FL_310_t;


typedef struct DCU_FR_320
{
	DCU_LatchState_t DCU_FR_LatchState;
	DCU_WdState_t DCU_FR_WdState;
	DCU_MovementReq_t DCU_FRMovementReq;
	DCU_ManAssistForce_t DCU_FR_ManAssistForce;
	uint8_t DCU_FR_StopAngle;
	uint8_t DCU_FR_RqstOpenVal;
	DCU_PDS_SETINGS_t DCU_FR_PDS_SETINGS;
}DCU_FR_320_t;

typedef struct DCU_RL_330
{
	DCU_LatchState_t DCU_RL_LatchState;
	DCU_WdState_t DCU_RL_WdState;
	DCU_MovementReq_t DCU_RLMovementReq;
	DCU_ManAssistForce_t DCU_RL_ManAssistForce;
	uint8_t DCU_RL_StopAngle;
	uint8_t DCU_RL_RqstOpenVal;
	DCU_PDS_SETINGS_t DCU_RL_PDS_SETINGS;
}DCU_RL_330_t;

typedef struct DCU_RR_340
{
	DCU_LatchState_t DCU_RR_LatchState;
	DCU_WdState_t DCU_RR_WdState;
	DCU_MovementReq_t DCU_RRMovementReq;
	DCU_ManAssistForce_t DCU_RR_ManAssistForce;
	uint8_t DCU_RR_StopAngle;
	uint8_t DCU_RR_RqstOpenVal;
	DCU_PDS_SETINGS_t DCU_RR_PDS_SETINGS;
}DCU_RR_340_t;

typedef struct IMU_350
{
	uint8_t IMU_LatAccelSigSta;
	uint8_t IMU_LongAccelSigSta;
	uint8_t IMU_LatAccelVal;
	uint8_t IMU_LongAccelVal;
}IMU_350_t;

typedef struct DATC_380
{
	uint8_t DATC_OutTempSnsrVal;
	DATC_BlwrLvl_t DATC_BlwrLvl;
	DATC_BlwrLvl_t DATC_BlwrLvl_Ps;
	DATC_BlwrLvl_t DATC_BlwLel_Rr;
	DATC_IntakeDis_t DATC_IntakeDis;
}DATC_380_t;

typedef struct DCAS_FL_510
{
	uint8_t DCAS_FL_Obstacle_Pos;
	DCAS_Obstacle_Status_t DCAS_FL_Obstacle_Status;
	DCAS_Sensor_State_t DCAS_FL_Sensor_State;
	uint8_t DCAS_FL_Checksum;
	uint8_t DCAS_FL_RollingCounter;
}DCAS_FL_510_t;

typedef struct DCAS_FR_520
{
	uint8_t DCAS_FR_Obstacle_Pos;
	DCAS_Obstacle_Status_t DCAS_FR_Obstacle_Status;
	DCAS_Sensor_State_t DCAS_FR_Sensor_State;
	uint8_t DCAS_FR_Checksum;
	uint8_t DCAS_FR_RollingCounter;
}DCAS_FR_520_t;

typedef struct DCAS_RL_530
{
	uint8_t DCAS_RL_Obstacle_Pos;
	DCAS_Obstacle_Status_t DCAS_RL_Obstacle_Status;
	DCAS_Sensor_State_t DCAS_RL_Sensor_State;
	uint8_t DCAS_RL_Checksum;
	uint8_t DCAS_RL_RollingCounter;
}DCAS_RL_530_t;

typedef struct DCAS_RR_540
{
	uint8_t DCAS_RR_Obstacle_Pos;
	DCAS_Obstacle_Status_t DCAS_RR_Obstacle_Status;
	DCAS_Sensor_State_t DCAS_RR_Sensor_State;
	uint8_t DCAS_RR_Checksum;
	uint8_t DCAS_RR_RollingCounter;
}DCAS_RR_540_t;

typedef struct PDS_FL_370
{
	PDS_CalibrStatus_t PDS_FL_CalibrStatus;
	PDS_ChimeReq_t PDS_FL_ChimeReq;
	PDS_SnsrActCommand_t PDS_FL_SnsrActCommand;
	PDS_BrakeStatus_t PDS_FL_BrakeStatus;
	uint8_t PDS_FL_DoorAngle;
	PDS_DoorAngleStuck_t PDS_FL_DoorAngleStuck;
	uint8_t PDS_FL_DrAngVel;
	PDS_SwingActrStatus_t PDS_FL_SwingActrStatus;
	PDS_Mode_t PDS_FL_Mode;
	PDS_Handle_Request_t PDS_FL_Handle_Request;
}PDS_FL_370_t;

typedef struct PDS_FR_371
{
	PDS_CalibrStatus_t PDS_FR_CalibrStatus;
	PDS_ChimeReq_t PDS_FR_ChimeReq;
	PDS_SnsrActCommand_t PDS_FR_SnsrActCommand;
	PDS_BrakeStatus_t PDS_FR_BrakeStatus;
	uint8_t PDS_FR_DoorAngle;
	PDS_DoorAngleStuck_t PDS_FR_DoorAngleStuck;
	uint8_t PDS_FR_DrAngVel;
	PDS_SwingActrStatus_t PDS_FR_SwingActrStatus;
	PDS_Mode_t PDS_FR_Mode;
	PDS_Handle_Request_t PDS_FR_Handle_Request;
}PDS_FR_371_t;

typedef struct PDS_RL_372
{
	PDS_CalibrStatus_t PDS_RL_CalibrStatus;
	PDS_ChimeReq_t PDS_RL_ChimeReq;
	PDS_SnsrActCommand_t PDS_RL_SnsrActCommand;
	PDS_BrakeStatus_t PDS_RL_BrakeStatus;
	uint8_t PDS_RL_DoorAngle;
	PDS_DoorAngleStuck_t PDS_RL_DoorAngleStuck;
	uint8_t PDS_RL_DrAngVel;
	PDS_SwingActrStatus_t PDS_RL_SwingActrStatus;
	PDS_Mode_t PDS_RL_Mode;
	PDS_Handle_Request_t PDS_RL_Handle_Request;
}PDS_RL_372_t;

typedef struct PDS_RR_373
{
	PDS_CalibrStatus_t PDS_RR_CalibrStatus;
	PDS_ChimeReq_t PDS_RR_ChimeReq;
	PDS_SnsrActCommand_t PDS_RR_SnsrActCommand;
	PDS_BrakeStatus_t PDS_RR_BrakeStatus;
	uint8_t PDS_RR_DoorAngle;
	PDS_DoorAngleStuck_t PDS_RR_DoorAngleStuck;
	uint8_t PDS_RR_DrAngVel;
	PDS_SwingActrStatus_t PDS_RR_SwingActrStatus;
	PDS_Mode_t PDS_RR_Mode;
	PDS_Handle_Request_t PDS_RR_Handle_Request;
}PDS_RR_373_t;

/*boolean CAN_RX_TCU_1AC_TimeOut_f;
boolean CAN_RX_BCM_365_TimeOut_f;
boolean CAN_RX_DCU_FL_310_TimeOut_f;
boolean CAN_RX_DCU_FR_320_TimeOut_f;
boolean CAN_RX_DCU_RL_330_TimeOut_f;
boolean CAN_RX_DCU_RR_340_TimeOut_f;
boolean CAN_RX_IMU_350_TimeOut_f;
boolean CAN_RX_DATC_380_TimeOut_f;
boolean CAN_RX_DCAS_FL_510_TimeOut_f;
boolean CAN_RX_DCAS_FR_520_TimeOut_f;
boolean CAN_RX_DCAS_RL_530_TimeOut_f;
boolean CAN_RX_DCAS_RR_540_TimeOut_f;*/



#endif /* 2_CDRV_CANIF_MSGCFG_H_ */
