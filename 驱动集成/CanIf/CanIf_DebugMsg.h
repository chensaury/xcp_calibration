/*
 * CanIf_Msg.h
 *
 *   Created on: 7.12.2023
 *      Author: Administrator
 */

#ifndef _2_CDRV_CANIF_MSG_H_
#define _2_CDRV_CANIF_MSG_H_

#include "cpu.h"

#define Rx_Filter  0x0
#define RX_MAILBOX_CAN0  (0UL)
#define TX_MAILBOX_CAN0  (1UL)

#define TX_MAILBOX_CAN1  (2UL)
#define TX_MAILBOX_CAN2  (3UL)
#define TX_MAILBOX_CAN3  (4UL)
#define TX_MAILBOX_CAN4  (5UL)
#define TX_MAILBOX_CAN5  (6UL)
#define TX_MAILBOX_CAN6  (7UL)
#define TX_MAILBOX_CAN7  (8UL)
#define TX_UDS_Mailbox  (9UL)

#define CAN_MESSAGE_TXD_ID01       (0x301)
#define CAN_MESSAGE_TXD_ID02       (0x302)
#define CAN_MESSAGE_TXD_ID03       (0x303)
#define CAN_MESSAGE_TXD_ID04       (0x304)
#define CAN_MESSAGE_TXD_ID05       (0x305)

#define CAN_MESSAGE_RXD_ID01       (0x311)

#define CAN_DOOR_CMD_OPEN         (0x01)
#define CAN_DOOR_CMD_STOP         (0x02)
#define CAN_DOOR_CMD_CLOSE        (0x03) 

#define CAN_DOOR_EVENT_TIP2RUN      (0xE1)
#define CAN_DOOR_EVENT_AP           (0xE2)
#define CAN_DOOR_EVENT_ASSIT        (0xE3)
#define CAN_DOOR_EVENT_BLOCK        (0xE4)
#define CAN_DOOR_EVENT_EBRAKE       (0xE5)

#define CAN_DOOR_POS_UNLEARNED         (0xA0)
#define CAN_DOOR_POS_RESET             (0xA1)
#define CAN_DOOR_DUTY_SET           (0xA5)

void CanIf0_DebugMsgRxProcessing(void);

void CanIf0_transmitDebugMsg1(void);
void CanIf0_transmitDebugMsg2(void);
void CanIf0_transmitDebugMsg3(void);
void CanIf0_transmitDebugMsg4(void);
void CanIf0_transmitDebugMsg5(void);


void CanIf0_DebugMsgTransmit(void);
 void CanIf0_ApInfoTransmit(void);
#endif /* 2_CDRV_CANIF_MSG_H_ */
