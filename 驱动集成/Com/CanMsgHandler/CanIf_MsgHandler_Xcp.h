/*
 * CanIf_Message.h
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#ifndef _2_CDRV_CANIF_MESSAGEHANDER_XCP_H_
#define _2_CDRV_CANIF_MESSAGEHANDER_XCP_H_

#include "XcpBasic.h"
#include "xcp_can_interface.h"  
#include <OsTypedefs.h>

void CanMsgHandler_XcpTransmitCrm(CCP_BYTEPTR pMsgTxData , uint8_t len);

int  CanMsgHandler_XcpTransmitCrmPossible(void);
void CanMsgHandler_XcpReq(void);

void CanMsgHandler_XcpCommand(void);

void CanMsgHandler_XcpTransmit(void);

void XCP(void);
void xcptest(void);
#endif /* _2_CDRV_CANIF_MESSAGEHANDER_H_ */
