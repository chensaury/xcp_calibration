

#ifndef _CANIF_UNPACK_PASER_H_
#define _CANIF_UNPACK_PASER_H_

#include "cpu.h"
#include "Ostypedefs.h"
#define FRAME_ZERO_DLC  0   // unit:Byte
#define FRAME_MAX_DLC  8    // unit:Byte
#define SIGNAL_ZERO_LENGTH  0    // unit:Bit
#define SIGNAL_MAX_LENGTH  32    // unit:Bit
#define SIGNAL_INIT_VALUE  0
#define SIGNAL_INIT_MASK  0
  
 
#define CAN_SIGNAL_NORMAL  0
#define CAN_SIGNAL_NO_VALUE  1
#define CAN_FRAME_DLC_OUT_OF_RANGE  2
#define INVALID_INPUT_PARAMETERS 3

typedef enum
{
  SIGNAL_BYTE_ORDER_INTEL,
  SIGNAL_BYTE_ORDER_MOTOROLA
}ByteEndian_t;




typedef struct
{
   uint8_t Signal_State;      // Describes the state of a signal
   uint64_t Signal_Value;     // Describes the value of a signal

} Unpack_CAN_Signal; 


typedef struct
{
   uint8_t Signal_State;      // Describes the state of a signal
   uint64_t Signal_Value;     // Describes the value of a signal

} Pack_CAN_Signal;

Unpack_CAN_Signal Rx_CAN_Frame_Data_Buff_to_CAN_Signal_Hex_Fun( uint8_t* data_buff,          /**Byte array of CAN data field**/
																uint8_t signal_start_bit,    /**Rang:0~(FRAME_MAX_DLC * 8 - 1)**/
																uint8_t signal_length,       /**Rang:1~SIGNAL_MAX_LENGTH**/
																ByteEndian_t signal_byte_order, /**0:Intel;1:Motorola**/
																uint8_t frame_length);      /**Rang:1~FRAME_MAX_DLC**/

inline uint64_t CanIf_MsgUnpack(uint8_t* data_buff,uint8_t signal_start_bit,uint8_t signal_length)
{
	uint64_t  retVal = 0;
	Unpack_CAN_Signal canSignal=Rx_CAN_Frame_Data_Buff_to_CAN_Signal_Hex_Fun(data_buff,
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
