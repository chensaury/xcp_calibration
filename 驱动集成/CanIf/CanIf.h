/*
 * CanIf.h
 *
 *  Created on: 2023��12��7��
 *      Author: Administrator
 */

#ifndef _2_CDRV_CANIF_H_
#define _2_CDRV_CANIF_H_

#include "Cpu.h"

#include <stdio.h>
#include <string.h>
#include "stdarg.h"
#include <stdint.h>
#include <stdbool.h>
#include "ostypedefs.h"
#include <CanIf_DebugMsg.h>
#include "CanIf_Msg.h"

extern can_message_t g_RecvMsg_CAN0;
extern can_message_t g_TransmitMsg_CAN0;
extern boolean b_Can0DebugMsgRx;
extern boolean b_Can0MsgRx;

void CanIf0_Init(void);
void CanIf0_Send(can_message_t *message);
uint8_t TpCanTransmit(uint8_t *dataBuf);

#endif /* 2_CDRV_CANIF_H_ */
