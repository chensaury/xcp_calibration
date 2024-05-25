/*
 * CanIfCfg_Message.c
 *
 *  Created on: 2023Äê12ÔÂ16ÈÕ
 *      Author: Administrator
 */

#ifndef _2_CDRV_CANIFCFG_MESSAGE_C_
#define _2_CDRV_CANIFCFG_MESSAGE_C_


#define PDS_DOOR_SIDE_FL   (1)
#define PDS_DOOR_SIDE_FR   (2)
#define PDS_DOOR_SIDE_RL   (3)
#define PDS_DOOR_SIDE_RR   (4)

#define PDS_DOOR_SIDE_TYPE  (PDS_DOOR_SIDE_FL)

#define XCP_DTO_ID              (0X101)           /* CAN identifier ECU -> Master */
#define XCP_CRO_ID              (0X100)           /* CAN identifier Master -> ECU */


#define CAN_MSG_XCP_TX        (XCP_DTO_ID)
#define CAN_MSG_XCP_RX        (XCP_CRO_ID)

#define CAN_MSG_DIAG_REQ		(0x711)
#define CAN_MSG_DIAG_RSP		(0x712)


#define CAN_MSG_DIAG_REQ_ENABLE       (1U)
#define CAN_MSG_XCP_RX_ENABLE         (1U)


#define CAN_MSG_TCU_1AC_0x1AC          (0x1AC)

#define CAN_MSG_BCM_365_ID0x365        (0x365)

#define CAN_MSG_IMU_350_ID0x350        (0x350)

#define CAN_MSG_DATC_380_ID0x380       (0x380)

#define CAN_MSG_DCAS_FL_510_ID0x510    (0x510)
#define CAN_MSG_DCAS_FR_520_ID0x520    (0x520)
#define CAN_MSG_DCAS_RL_530_ID0x530    (0x530)
#define CAN_MSG_DCAS_RR_540_ID0x540    (0x540)

#define CAN_MSG_DCU_FL_310_ID0x310     (0x310)
#define CAN_MSG_DCU_FR_320_ID0x320     (0x320)
#define CAN_MSG_DCU_RL_330_ID0x330     (0x330)
#define CAN_MSG_DCU_RR_340_ID0x340     (0x340)

#if  (PDS_DOOR_SIDE_FL == PDS_DOOR_SIDE_TYPE)
#define CAN_MSG_PDS_FL_370_ID0x370     (0x370)
#elif(PDS_DOOR_SIDE_FR == PDS_DOOR_SIDE_TYPE)
#define CAN_MSG_PDS_FR_371_ID0x371     (0x371)
#elif(PDS_DOOR_SIDE_RL == PDS_DOOR_SIDE_TYPE)
#define CAN_MSG_PDS_RL_372_ID0x372     (0x372)
#elif(PDS_DOOR_SIDE_RR == PDS_DOOR_SIDE_TYPE)
#define CAN_MSG_PDS_RR_373_ID0x373     (0x373)
#else
#error "No PDS Door side defined in CAN_MSG_PDS_XXXX."
#endif


#define CAN_MSG_TCU_1AC_ENABLE        (1U)
#define CAN_MSG_BCM_365_ENABLE        (1U)
#define CAN_MSG_IMU_350_ENABLE        (1U)
#define CAN_MSG_DATC_380_ENABLE       (1U)

#define CAN_MSG_DCAS_FL_510_ENABLE    (1U)
#define CAN_MSG_DCAS_FR_520_ENABLE    (0U)
#define CAN_MSG_DCAS_RL_530_ENABLE    (0U)
#define CAN_MSG_DCAS_RR_540_ENABLE    (0U)

#define CAN_MSG_DCU_FL_310_ENABLE     (1U)
#define CAN_MSG_DCU_FR_320_ENABLE     (0U)
#define CAN_MSG_DCU_RL_330_ENABLE     (0U)
#define CAN_MSG_DCU_RR_340_ENABLE     (0U)

#define CAN_MSG_PDS_FL_370_ENABLE     (1U)
#define CAN_MSG_PDS_FR_371_ENABLE     (0U)
#define CAN_MSG_PDS_RL_372_ENABLE     (0U)
#define CAN_MSG_PDS_RR_373_ENABLE     (0U)

#define CAN_MSG_DIAG_REQ_ENABLE       (1U)
#define CAN_MSG_XCP_RX_ENABLE         (1U)

#define CAN_MSG_DIAG_REQ_ID0x711		(0x711)
#define CAN_MSG_DIAG_RSP_ID0x712		(0x712)


typedef void (*MsgIDHandlerFunction)(void);

typedef enum enRxMsgIdx
{
	MSG_TCU_1AC,
	MSG_IMU_350,
	MSG_BCM_365,
	MSG_DATC_380,
	MSG_DCAS_FL_510,
	MSG_DCAS_FR_520,
	MSG_DCAS_RL_530,
	MSG_DCAS_RR_540,
	MSG_DCU_FL_310,
	MSG_DCU_FR_320,
	MSG_DCU_RL_330,
	MSG_DCU_RR_340,
	MSG_SBC_TEST,
	MSG_FLASH_TEST,
	MSG_DIAG_REQ,
	MSG_XCP_REQ,
	MSG_RX_COUNT
}enRxMsgIdx_t;


typedef enum enTxMsgIdx
{
#if(PDS_DOOR_SIDE_FL == PDS_DOOR_SIDE_TYPE)
	MSG_PDS_FL_370,
#elif (PDS_DOOR_SIDE_FR== PDS_DOOR_SIDE_TYPE)
	MSG_PDS_FR_371,
#elif (PDS_DOOR_SIDE_RL== PDS_DOOR_SIDE_TYPE)
	MSG_PDS_RL_372,
#elif (PDS_DOOR_SIDE_RR== PDS_DOOR_SIDE_TYPE)
	MSG_PDS_RR_373,
#else
#error "No PDS Door side defined in enTxMsgIdx_t."
#endif
	MSG_TX_COUNT
}enTxMsgIdx_t;

typedef struct
{
	enRxMsgIdx_t  idx;
	uint8_t     enable;
	uint32_t    msgId;
	MsgIDHandlerFunction msgIdHandlerFunc;

}CanMsgCfg_t;


typedef struct
{
	uint8_t    idx;
	uint8_t     enable;
	uint32_t   msgId;
	MsgIDHandlerFunction msgIdHandlerFunc;

}CanMsgIdHandler_t;



extern const CanMsgCfg_t   canRxMsgCfg[MSG_RX_COUNT];
extern const CanMsgCfg_t   canTxMsgCfg[MSG_TX_COUNT];



#endif /* 2_CDRV_CANIFCFG_MESSAGE_C_ */
