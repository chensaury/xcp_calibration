/*
 * CanIf.c
 *
 *  Created on: 7.12.2023
 *      Author: Administrator
 */
#include <DoorSys.h>
#include "can_pal.h"
#include "CAN0can_pal1.h"
#include "DualHall.h"
#include "CanIf.h"
#include "CANTp.h"
#include "user_config.h"


can_buff_config_t Rx_buffCfg =
{
  .enableFD = false,
  .enableBRS = false,
  .fdPadding = 0U,
  .idType = CAN_MSG_ID_STD,
  .isRemote = false
};

can_buff_config_t Tx_buffCfg =
{
  .enableFD = false,
  .enableBRS = false,
  .fdPadding = 0U,
  .idType = CAN_MSG_ID_STD,
  .isRemote = false
};

/*CAN*/  
can_message_t g_RecvMsg_CAN0;
can_message_t g_TransmitMsg_CAN0;


boolean b_Can0DebugMsgRx = 0;
boolean b_Can0MsgRx = 0;
/*************************************************************************
   *FUNCTION NAME:			CAN0_Callback_Func
   *FUNCTION DESCRIPTION:		CAN send and receive callback functions
   *PAPRAMETER:		uint32_t instance,can_event_t event,uint32_t buffIdx,void *flexcanState
   *RETURN VALUE:		void	VALUENAME:void
   *EDITOR:			ReaveGan
   *DATE:				2023.12.07
   *VERSION:			1.0
   *************************************************************************/
 void CanIf0_Callback_Func (uint32_t instance,can_event_t event,uint32_t buffIdx,void *flexcanState)
{
	(void)flexcanState;
	(void)instance;
	(void)buffIdx;
	
	CAN_Receive(&CAN0can_pal1_instance,RX_MAILBOX_CAN0,&g_RecvMsg_CAN0);

	switch(event)
	{
		case CAN_EVENT_RX_COMPLETE:
		{
			if(g_RecvMsg_CAN0.id == 0x311)
			{

				b_Can0DebugMsgRx = 1;
			}
			else
			{

				b_Can0MsgRx = 1;
			}

			if((RX_FUN_ID == g_RecvMsg_CAN0.id)||(RX_PHY_ID == g_RecvMsg_CAN0.id)) /*UDS ID*/
			{
			   TpCanRxProcess(&CAN0can_pal1_instance, &g_RecvMsg_CAN0); 
			}
		}
		break;
		case CAN_EVENT_TX_COMPLETE:

		break;
		default:
			break;
	}
}
 /************************************************************************
 * Function 	 :	 ISR_CAN_RxError
 
 * Description	 :
 * Input		 :	 None
 * Output		 :	 None
 * Author/Time	 :
 * Called		 :
 * Others		 :	Error: FLEXCAN_INT_ERR /
 *						   FLEXCAN_INT_RX_WARNING /
 *						   FLEXCAN_INT_TX_WARNING /
 *						   FLEXCAN_INT_BUSOFF
 *************************************************************************/
 void ISR_CAN_RxError(uint8_t instance, flexcan_event_type_t errorType, flexcan_state_t * State)
 {
	 if(instance <= CAN0can_pal1_instance.instIdx){
		 switch(errorType){
			 case FLEXCAN_EVENT_ERROR:
				 if((FLEXCAN_DRV_GetErrorStatus(CAN0can_pal1_instance.instIdx) >> 2u) & 1u)    /* BusOff */
				 {
					 //HSCAN0_OnBusOff();
				 }
				 break;
 
			 default:
				 break;
		 }
	 }
 }
 /*************************************************************************
   *FUNCTION NAME:			CAN0_Init
   *FUNCTION DESCRIPTION:		CAN0_Init
   *PAPRAMETER:		void
   *RETURN VALUE:		void	VALUENAME:void
   *EDITOR:			ReaveGan
   *DATE:				2023.12.07
   *VERSION:			1.0
   *************************************************************************/
 void CanIf0_Init(void)
 {
 	CAN_Init(&CAN0can_pal1_instance, &CAN0can_pal1_Config0);

 	CAN_ConfigRxBuff(&CAN0can_pal1_instance,RX_MAILBOX_CAN0,&Rx_buffCfg,Rx_Filter);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN0,&Tx_buffCfg);

 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN1,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN2,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN3,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN4,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN5,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN6,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN7,&Tx_buffCfg);
 	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_UDS_Mailbox,&Tx_buffCfg); /*TX UDS message buffer*/

 	CAN_SetRxFilter(&CAN0can_pal1_instance,CAN_MSG_ID_STD,RX_MAILBOX_CAN0,0);

	CAN_InstallEventCallback(&CAN0can_pal1_instance,&CanIf0_Callback_Func,(void*)0);
	FLEXCAN_DRV_InstallErrorCallback(CAN0can_pal1_instance.instIdx, (flexcan_error_callback_t)ISR_CAN_RxError, (void *)0);

	CAN_Receive(&CAN0can_pal1_instance,RX_MAILBOX_CAN0,&g_RecvMsg_CAN0);

 	CanIf0_Msg_Init();
 }


 void CanIf0_Send(can_message_t *message )
 {
	can_buff_config_t Tx_buffCfg1 =
	{
	  .enableFD = false,
	  .enableBRS = false,
	  .fdPadding = 0U,
	  .idType = CAN_MSG_ID_STD,
	  .isRemote = false
	};

	CAN_ConfigTxBuff(&CAN0can_pal1_instance,TX_MAILBOX_CAN0,&Tx_buffCfg1);
	CAN_Send(&CAN0can_pal1_instance,TX_MAILBOX_CAN0, message);
 }

 void CAN_TxConfirm(const can_instance_t * const instance, uint32_t ID)
{
    if (ID == TX_ID)
    {
        TpRxDrvTxOKConfirm(instance);
        TpTxDrvTxOKConfirm(instance);
    }
}

uint8_t TpCanTransmit(uint8_t *dataBuf)
{
	g_TransmitMsg_CAN0.cs = 0;
	g_TransmitMsg_CAN0.id = TX_ID;
	g_TransmitMsg_CAN0.length = 8;
			
	g_TransmitMsg_CAN0.data[0] = dataBuf[0];
	g_TransmitMsg_CAN0.data[1] = dataBuf[1];
	g_TransmitMsg_CAN0.data[2] = dataBuf[2];
	g_TransmitMsg_CAN0.data[3] = dataBuf[3];
	g_TransmitMsg_CAN0.data[4] = dataBuf[4];
	g_TransmitMsg_CAN0.data[5] = dataBuf[5];
	g_TransmitMsg_CAN0.data[6] = dataBuf[6];
	g_TransmitMsg_CAN0.data[7] = dataBuf[7];

    if (0 == CAN_Send(&CAN0can_pal1_instance,TX_UDS_Mailbox, &g_TransmitMsg_CAN0))
    {      
		CAN_TxConfirm(&CAN0can_pal1_instance, g_TransmitMsg_CAN0.id);
        return 0;
    }
    return 1;
}
