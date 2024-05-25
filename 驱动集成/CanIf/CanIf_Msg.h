/*
 * CanIf_Message.h
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#ifndef _2_CDRV_CANIF_MESSAGE_H_
#define _2_CDRV_CANIF_MESSAGE_H_

#include "CanIf_SigTypedefs.h"
#include "CanIfCfg_Msg.h"

#define MSG_TX_SLOTS   (9)
extern CanMsgIdHandler_t   canRxMsgIdHander[MSG_RX_COUNT];
extern CanMsgIdHandler_t   canTxMsgIdHander[MSG_TX_COUNT];

void CanIf0_Msg_Init(void);
void CanIf0_TxMessage(void);

void CanIf0_RxMessagePocessing(void);
#endif /* 2_CDRV_CANIF_MESSAGE_H_ */
