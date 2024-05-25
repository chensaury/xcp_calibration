/*
 * CanIf_Message.h
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#ifndef _2_CDRV_CANIF_MESSAGEHANDER_H_
#define _2_CDRV_CANIF_MESSAGEHANDER_H_

#include "CanIf_SigTypedefs.h"

PDS_CalibrStatus_t PDS_getCalibrStatus(void);
PDS_ChimeReq_t PDS_getChimeReq(void);
PDS_ChimeReq_t PDS_getSnsrActCommand(void);
PDS_BrakeStatus_t PDS_getBrakeStatus(void);

PDS_DoorAngleStuck_t PDS_getDoorAngleStuck(void);
uint8_t PDS_getDoorAngle(void);
uint8_t PDS_getDoorAngVel(void);
PDS_SwingActrStatus_t PDS_getSwingActrStatus(void);
PDS_Mode_t PDS_getMode(void);
PDS_Handle_Request_t PDS_getHandleRequest(void);


void CanMsgHandler_TCU_1AC(void);
void CanMsgHandler_IMU_350(void);
void CanMsgHandler_BCM_365(void);
void CanMsgHandler_DATC_380(void);

void CanMsgHandler_DCU_FL_310(void);
void CanMsgHandler_DCU_FR_320(void);
void CanMsgHandler_DCU_RL_330(void);
void CanMsgHandler_DCU_RR_340(void);

void CanMsgHandler_PDS_FL_370(void);
void CanMsgHandler_PDS_FR_371(void);
void CanMsgHandler_PDS_RL_372(void);
void CanMsgHandler_PDS_RR_373(void);

void CanMsgHandler_DCAS_FL_510(void);
void CanMsgHandler_DCAS_FR_520(void);
void CanMsgHandler_DCAS_RL_530(void);
void CanMsgHandler_DCAS_RR_540(void);
 
#endif /* _2_CDRV_CANIF_MESSAGEHANDER_H_ */
