/*
 * CanIf_Msg.c
 *
 *  Created on: 7.12.2023
 *      Author: Administrator
 */
#include <CanIf_DebugMsg.h>
#include <DoorSys.h>
#include "DoorSys.h"
#include "CanIf.h" 
#include "Switch.h"
#include <DoorSys_VelocityControl.h>
#include "DoorSys_AntiPinch.h"
#include "IMU.h"
#include "1_Bsw/Components/Current.h"
#include "BatteryApp.h"
uint8_t  DebugRxData[8];

DoorControl_t *door = &g_door;

void CanIf0_DebugMsgRxProcessing(void)
{
	static uint8_t u8CanDoorCmd=0,u8CanDoorCmd_old=0;
	static uint8_t u8CanDoorDuty;

	if(b_Can0DebugMsgRx)
	{
		if(CAN_MESSAGE_RXD_ID01==g_RecvMsg_CAN0.id)
		{
			DebugRxData[0]=g_RecvMsg_CAN0.data[0];
			DebugRxData[1]=g_RecvMsg_CAN0.data[1];
			DebugRxData[2]=g_RecvMsg_CAN0.data[2];
			DebugRxData[3]=g_RecvMsg_CAN0.data[3];
			DebugRxData[4]=g_RecvMsg_CAN0.data[4];
			DebugRxData[5]=g_RecvMsg_CAN0.data[5];
			DebugRxData[6]=g_RecvMsg_CAN0.data[6];
			DebugRxData[7]=g_RecvMsg_CAN0.data[7];

			u8CanDoorCmd=DebugRxData[0];
			u8CanDoorDuty=DebugRxData[1];

			if(u8CanDoorCmd!=u8CanDoorCmd_old)
			{
				if(CAN_DOOR_CMD_OPEN==u8CanDoorCmd)
				{
					door->DoorCmd = DOOR_CMD_OPEN;
				}
				else if(CAN_DOOR_CMD_CLOSE == u8CanDoorCmd)
				{
					door->DoorCmd = DOOR_CMD_CLOSE;

				}
				else if(CAN_DOOR_CMD_STOP == u8CanDoorCmd)
				{
					door->DoorCmd = DOOR_CMD_STOP;
				}
				else if(CAN_DOOR_EVENT_TIP2RUN == u8CanDoorCmd)
				{
					door->event = DOOR_EVENT_TIP2RUN;	
				}
				else if(CAN_DOOR_EVENT_AP == u8CanDoorCmd)
				{
					door->event =  DOOR_EVENT_AP;
				}
				else if(CAN_DOOR_EVENT_ASSIT == u8CanDoorCmd)
				{
					door->event = DOOR_EVENT_ASSIST_MODE;
				}
				else if(CAN_DOOR_EVENT_BLOCK == u8CanDoorCmd)
				{
					door->event = DOOR_EVENT_BLOCK;
				}
				else if(CAN_DOOR_POS_UNLEARNED == u8CanDoorCmd)
				{
					door->b_PosCloseLearned = 0;
					door->b_PosOpenLearned  = 0;

					door->u16HardClosePos = g_DoorSysPosCfg.u16PosMin;
					door->u16SoftClosePos = g_DoorSysPosCfg.u16PosMin;

					door->u16HardOpenPos = g_DoorSysPosCfg.u16PosMax;
					door->u16SoftOpenPos = g_DoorSysPosCfg.u16PosMax;

				}
				else if(CAN_DOOR_POS_RESET == u8CanDoorCmd)
				{
					{
						door->u16Realtime_Pos = g_DoorSysPosCfg.u16PosPowerUpInit;
						door->u16HardClosePos = door->u16Realtime_Pos;
						door->u16SoftClosePos = door->u16Realtime_Pos + K_POS_CLOSE_SOFT_DELTA;
						door->u16ManualAssistPosMin = door->u16Realtime_Pos + K_POS_ASSIT_LEN_MIN;
						door->b_PosCloseLearned = 1;
					}					

					{
						
						door->u16HardOpenPos =  g_DoorSysPosCfg.u16PosPowerUpInit + K_POS_TIP2RUN_LEN;
						door->u16SoftOpenPos = door->u16HardOpenPos - K_POS_OPEN_SOFT_DELTA;
						door->u16Tip2RunPosMax =  door->u16SoftOpenPos;
						door->u16ManualAssistPosMax = door->u16SoftOpenPos;
			    		door->u16ManualAssistPosMax = door->u16SoftOpenPos;

						door->b_PosOpenLearned = 1;
					}

				}
				else if(CAN_DOOR_EVENT_EBRAKE == u8CanDoorCmd)
				{
					door->event = DOOR_EVENT_EBRAKE;

				}
				else if(CAN_DOOR_DUTY_SET == u8CanDoorCmd)
				{
					if(u8CanDoorDuty < PWM_DUTY_MAX/PWM_DUTY_PECENT)
					{
			         g_i16DoorDutyPercent=u8CanDoorDuty;
					}
				}
			}
			u8CanDoorCmd_old=u8CanDoorCmd;

		}

		b_Can0DebugMsgRx = 0;
	}

	/********************************************************************************************************************* */

}



extern uint32_t timer_ticks;
extern sAntiPinch_t g_antipinch;
 void CanIf0_transmitDebugMsg1(void)
 {

	 can_message_t Tx_msg1 = {
	 							 .cs = 0U,
	 							 .id = 0x01,
	 							 .data[0] = 0,
	 							 .data[1] = 0,
	 							 .data[2] = 0x2,
	 							 .data[3] = 0x3,
	 							 .data[4] = 0x4,
	 							 .data[5] = 0x5,
	 							 .data[6] = 0x6,
	 							 .data[7] = 0x7,
	 							 .length = 8
	 						 };
							 
	 can_message_t* tx_msg = &Tx_msg1; 
	 volatile uint8 u8SendVar=0;
	 tx_msg->id = CAN_MESSAGE_TXD_ID01;
	 tx_msg->length = 8;
	 tx_msg->data[0] = (uint8_t)(door->u16Realtime_Pos);
	 tx_msg->data[1] = (uint8_t)(door->u16Realtime_Pos>>8);
	 tx_msg->data[2] = (uint8_t)(door->u16Target_Pos);
	 tx_msg->data[3] = (uint8_t)(door->u16Target_Pos>>8);

	 u8SendVar = 0;
	 u8SendVar = (uint8)((door->b_dir_close&0x01)      );	 
	 u8SendVar |=(uint8)((door->b_dir_close_fbk&0x01   )<<1);
	 u8SendVar |=(uint8)((door->b_dir_open&0x01        )<<2);
	 u8SendVar |=(uint8)((door->b_dir_open_fbk&0x01    )<<3);
	 u8SendVar |=(uint8)((door->b_ebrake&0x01    )<<4);

	 tx_msg->data[4] = (uint8_t)(u8SendVar);

	 u8SendVar = 0;
     u8SendVar = (uint8)((door->b_PosCloseLearned&0x01));
	 u8SendVar |=(uint8)((door->b_PosOpenLearned&0x01 )<<1);
	 u8SendVar |=(uint8)((door->b_close_block&0x01    )<<2);
	 u8SendVar |=(uint8)((door->b_open_block&0x01     )<<3);
	 u8SendVar |=(uint8)((door->b_close_antipinch&0x01)<<4);
	 u8SendVar |=(uint8)((door->b_open_antipinch&0x01 )<<5);
	 u8SendVar |=(uint8)((door->b_tip2run&0x01        )<<6);
	 u8SendVar |=(uint8)((door->b_assisting&0x01      )<<7);
	 tx_msg->data[5] = (uint8_t)(u8SendVar);

	 tx_msg->data[6] = (uint8_t)(door->event);
	 tx_msg->data[7] = (uint8_t)(door->state);

	 CAN_Send(&CAN0can_pal1_instance,TX_MAILBOX_CAN3, tx_msg);
 }


 void CanIf0_transmitDebugMsg2(void)
 {
	 can_message_t Tx_msg2 = {
	 	 							 .cs = 0U,
	 	 							 .id = 0x01,
	 	 							 .data[0] = 0,
	 	 							 .data[1] = 0,
	 	 							 .data[2] = 0x2,
	 	 							 .data[3] = 0x3,
	 	 							 .data[4] = 0x4,
	 	 							 .data[5] = 0x5,
	 	 							 .data[6] = 0x6,
	 	 							 .data[7] = 0x7,
	 	 							 .length = 8
	 	 						 };



	 uint16 u16SendVar=0;

	 can_message_t* tx_msg = &Tx_msg2;
	 tx_msg->id = CAN_MESSAGE_TXD_ID02;
	 tx_msg->length = 8;

	 u16SendVar=hall_A.HallWidth;
	 tx_msg->data[0] = (uint8_t)(u16SendVar);
	 tx_msg->data[1] = (uint8_t)(u16SendVar>>8);

	 u16SendVar=door->i16Tip2run_Count;
	 tx_msg->data[2] = (uint8_t)(u16SendVar);

	 u16SendVar = g_motor.duty/PWM_DUTY_PECENT;
	 tx_msg->data[3] = (uint8_t)(u16SendVar);

	 u16SendVar = g_motor.state;
	 tx_msg->data[4] = (uint8_t)(u16SendVar);

	 u16SendVar = door->u16BlockCount;
	 tx_msg->data[5] = (uint8_t)(u16SendVar);

	 u16SendVar = g_switch.adVal>>4;
	 tx_msg->data[6] = (uint8_t)u16SendVar;

	 u16SendVar = g_switch.cmdIndex;
	 tx_msg->data[7] = (uint8_t)(u16SendVar);
	 CAN_Send(&CAN0can_pal1_instance,TX_MAILBOX_CAN4, tx_msg);
 }

 void CanIf0_transmitDebugMsg3(void)
 {
	 can_message_t Tx_msg3 = {.cs = 0U,.id = 0x303,.data[0] = 0,.data[1] = 0,.data[2] = 0x2,.data[3] = 0x3,
		 	 					  .data[4] = 0x4,.data[5] = 0x5,.data[6] = 0x6,.data[7] = 0x7,.length = 8
		 	 						 };

	 can_message_t* tx_msg = &Tx_msg3;
	 uint16 u16SendVar=0;

	 tx_msg->cs = 0;
	 tx_msg->id = CAN_MESSAGE_TXD_ID03;
	 tx_msg->length = 8;

	 u16SendVar=door->u16Realtime_Pos;
	 tx_msg->data[0] = (uint8_t)(u16SendVar);
	 tx_msg->data[1] = (uint8_t)(u16SendVar>>8);

	 extern uint16_t u16LocalApCalSpeed;
	 u16SendVar=u16LocalApCalSpeed;
	 tx_msg->data[2] = (uint8_t)(u16SendVar);
	 tx_msg->data[3] = (uint8_t)(u16SendVar>>8);

	 extern int16_t i16SpeedDiff1;
     u16SendVar  = (uint16_t)(i16SpeedDiff1);
	 tx_msg->data[4] = (uint8_t)(u16SendVar);
	 tx_msg->data[5] = (uint8_t)(u16SendVar>>8);

/*	 extern int16_t  i16ApAdapt;*/
     u16SendVar  = (uint16_t)( g_velocityControl.ref);
	 tx_msg->data[6] = (uint8_t)(u16SendVar);
	 tx_msg->data[7] = (uint8_t)(u16SendVar>>8);

	 CAN_Send(&CAN0can_pal1_instance,TX_MAILBOX_CAN1, tx_msg);
 }

 void CanIf0_transmitDebugMsg4(void)
 {   
	 can_message_t Tx_msg4 = {.cs = 0U,.id = 0x303,.data[0] = 0,.data[1] = 0,.data[2] = 0x2,.data[3] = 0x3,
	 	 					  .data[4] = 0x4,.data[5] = 0x5,.data[6] = 0x6,.data[7] = 0x7,.length = 8
	 	 						 };
	 can_message_t* tx_msg = &Tx_msg4;	 
	 uint16 u16SendVar=0;

	 tx_msg->id = CAN_MESSAGE_TXD_ID04;
	 tx_msg->length = 8;

	 extern int16_t i16ApThreshold;
	 u16SendVar=(uint16)i16ApThreshold;
	 tx_msg->data[0] = (uint8_t)(u16SendVar);
	 tx_msg->data[1] = (uint8_t)(u16SendVar>>8);

	 extern int16_t i16ApSum;
	 u16SendVar=i16ApSum;
	 tx_msg->data[2] = (uint8_t)(u16SendVar);
	 tx_msg->data[3] = (uint8_t)(u16SendVar>>8);


	 u16SendVar = g_Roll_level;
	 tx_msg->data[4] = (uint8_t)(u16SendVar);


	 u16SendVar = g_Pitch_level;
	 tx_msg->data[5] = (uint8_t)(u16SendVar);


	 u16SendVar = MotorCurrent.Adc_Average;
	 tx_msg->data[6] = (uint8_t)u16SendVar;
	 tx_msg->data[7] = (uint8_t)(u16SendVar>>8);

	 CAN_Send(&CAN0can_pal1_instance,TX_MAILBOX_CAN2, tx_msg);
 }


 void CanIf0_transmitDebugMsg5(void)
 {
	 can_message_t Tx_msg5 = {
	 	 							 .cs = 0U,
	 	 							 .id = 0x305,
	 	 							 .data[0] = 0,
	 	 							 .data[1] = 0,
	 	 							 .data[2] = 0x2,
	 	 							 .data[3] = 0x3,
	 	 							 .data[4] = 0x4,
	 	 							 .data[5] = 0x5,
	 	 							 .data[6] = 0x6,
	 	 							 .data[7] = 0x7,
	 	 							 .length = 8
	 	 						 };

	 can_message_t* tx_msg = &Tx_msg5;
	 uint16_t sendVar;
	 extern int16_t g_i16DoorDutyPercent;
	 stEBrakeControl *ebrake = &g_ebrake;
	 tx_msg->id = CAN_MESSAGE_TXD_ID05;
	 tx_msg->length = 8;

	 sendVar = g_i16DoorDutyPercent;
	 tx_msg->data[0] = (uint8_t)(sendVar);
	 tx_msg->data[1] = (uint8_t)(sendVar>>8);

	 sendVar = ebrake->i16eBrake_count;
	 tx_msg->data[2] =(uint8_t)(sendVar);

	 sendVar = ((PDSBatteryCtrl.AdcValue *250)/4096)+4;
	 tx_msg->data[3] =(uint8_t)(sendVar);
	 tx_msg->data[4] =(uint8_t)(sendVar>>8);

	 tx_msg->data[5] = g_RecvMsg_CAN0.data[5];


	 sendVar = door->u16Velocity;
	 tx_msg->data[6] = (uint8_t)(sendVar);
	 tx_msg->data[7] = (uint8_t)(sendVar>>8);

	 CAN_Send(&CAN0can_pal1_instance,TX_MAILBOX_CAN5, tx_msg);
 }



 void CanIf0_DebugMsgTransmit(void)
 {
	 static uint8_t transmitIdx=0;

	 switch(transmitIdx)
	 {
		 case 0:
				CanIf0_transmitDebugMsg1();
				transmitIdx++;
			 break;
		 case 1:
				CanIf0_transmitDebugMsg2();
				transmitIdx++;
			 break;
		 case 2:
			   CanIf0_transmitDebugMsg5();
			   transmitIdx++;
			 break;
			 /* reserved slots*/
		 case 3:
			 transmitIdx++;
			 break;
		 case 4:
			 transmitIdx++;
			 break;
		 case 5:
			 transmitIdx++;
			 break;
		 case 6:
			 transmitIdx++;
		 	break;
		 case 7:
			 transmitIdx++;
		 	break;
		 case 8:
			 transmitIdx++;
		 			 break;
		 case 9:
			 transmitIdx=0;
		 			 break;
		 default:
			transmitIdx=0;
		 break;

	 }

 }

 void CanIf0_ApInfoTransmit(void)
 {

	if(DoorSys_ApInfoSendEnable())
	{
	  static uint8_t transmitApInfoIdx=0;

		switch(transmitApInfoIdx)
		{
			case 0:
					CanIf0_transmitDebugMsg3();
					transmitApInfoIdx++;
				break;
			case 1:
					CanIf0_transmitDebugMsg4();

					transmitApInfoIdx=0;

					DoorSys_ApInfoSendReset();
				break;
			default :
			transmitApInfoIdx=0;
			break;
		}
	}
 }
