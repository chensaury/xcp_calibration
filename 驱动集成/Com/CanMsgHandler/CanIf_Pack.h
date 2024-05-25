

#ifndef _CANIF_PASER_H_
#define _CANIF_PASER_H_
#include <CanMsgHandler/CanIf_Unpack.h>

Pack_CAN_Signal Rx_CAN_Frame_CAN_Signal_to_Data_Buff_Fun( uint64_t Signal_Value,
		                                                  uint8_t* data_buff,          /**Byte array of CAN data field**/
														  uint8_t signal_start_bit,    /**Rang:0~(FRAME_MAX_DLC * 8 - 1)**/
														  uint8_t signal_length,       /**Rang:1~SIGNAL_MAX_LENGTH**/
														  ByteEndian_t signal_byte_order, /**0:Intel;1:Motorola**/
														  uint8_t frame_length);        /**Rang:1~FRAME_MAX_DLC**/

inline uint64_t CanIf_MsgPack(uint64_t Signal_Value,uint8_t* data_buff,uint8_t signal_start_bit,uint8_t signal_length)
{
	uint64_t  retVal = 0;
	Pack_CAN_Signal canSignal=Rx_CAN_Frame_CAN_Signal_to_Data_Buff_Fun(
												  Signal_Value,
												  data_buff,
												  signal_start_bit,
												  signal_length,
												  SIGNAL_BYTE_ORDER_INTEL,
												  FRAME_MAX_DLC) ;

	if(CAN_SIGNAL_NORMAL == canSignal.Signal_State)
	{

		retVal = canSignal.Signal_Value;
	}

	return retVal;
}
#endif /* _CANIF_PASER_H_*/
