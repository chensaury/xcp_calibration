
#include <CanMsgHandler/CanIf_Unpack.h>

Unpack_CAN_Signal Rx_CAN_Frame_Data_Buff_to_CAN_Signal_Hex_Fun( uint8_t* data_buff,          /**Byte array of CAN data field**/
																uint8_t signal_start_bit,    /**Rang:0~(FRAME_MAX_DLC * 8 - 1)**/
																uint8_t signal_length,       /**Rang:1~SIGNAL_MAX_LENGTH**/
																ByteEndian_t signal_byte_order, /**0:Intel;1:Motorola**/
																uint8_t frame_length)        /**Rang:1~FRAME_MAX_DLC**/
{
	Unpack_CAN_Signal can_signal;
	uint8_t i = 0;
	uint8_t byte_num = 0;
	uint8_t low_data_byte = 0;
	uint8_t high_data_byte = 0;
	uint8_t low_data_byte_position = 0;
	uint8_t high_data_byte_position = 0;
	uint8_t remaining_bit_number = 0;
	uint8_t remaining_byte_number = 0;
	uint64_t can_signal_mask = SIGNAL_INIT_MASK;
	
	can_signal.Signal_State = CAN_SIGNAL_NORMAL;
	can_signal.Signal_Value = SIGNAL_INIT_VALUE;
	
	if(frame_length == FRAME_ZERO_DLC)            /**DLC of CAN frame is 0**/
	{
		can_signal.Signal_State = CAN_SIGNAL_NO_VALUE;
	}
	else if(frame_length > FRAME_MAX_DLC)         /**DLC of CAN frame is out of range**/
	{
		can_signal.Signal_State = CAN_FRAME_DLC_OUT_OF_RANGE;
	}
	else if(
	        (signal_length > (frame_length * 8))            /**Invalid signal_length: The length of the signal is not in the range of DLC**/
	        || (signal_length > SIGNAL_MAX_LENGTH)          /**Invalid signal_length: The length of the signal exceeds the maximum Unsigned of C language**/
	        || (signal_length == SIGNAL_ZERO_LENGTH)        /**Invalid signal_length: The length of the signal is not equal to 0**/
			)
	{
		can_signal.Signal_State = INVALID_INPUT_PARAMETERS;
	}
	else
	{		
		/**Byte Order: Intel**/
		if(signal_byte_order == SIGNAL_BYTE_ORDER_INTEL)
		{
			/**Bytes used by CAN signal,Byte[0] is low byte,Byte[frame_length] is high byte**/
			low_data_byte = signal_start_bit / 8;
			high_data_byte = (signal_start_bit + signal_length - 1) / 8;  // 2 + 6 - 1 /8 = 0;  2 + 7 - 1 /8 = 1 ;  2 + 14 - 1 /8 = 1 ;  2 + 15 - 1 /8 = 2
			
			if((high_data_byte + 1) > frame_length)  /** CAN signal is not in the range of DLC**/
			{
				can_signal.Signal_State = CAN_FRAME_DLC_OUT_OF_RANGE;
			}
			else
			{
				for(i = 0;i < signal_length;i++)  /**Generate signal mask according to signal length**/
				{
					can_signal_mask |= 0x0000000000000001 << i;
				}
					
				low_data_byte_position = signal_start_bit % 8;  /**Distance from the lowest bit of each byte**/
				
				/**CAN Signal is in a bytes**/
				if(low_data_byte == high_data_byte) 
				{					
					can_signal.Signal_Value = (((uint64_t)data_buff[low_data_byte]) >> low_data_byte_position) & can_signal_mask;
				}
				/**CAN Signal in multiple bytes**/
				else
				{					
					for(byte_num = low_data_byte;byte_num <= high_data_byte;byte_num++)
					{
						if(byte_num == low_data_byte)
						{
							can_signal.Signal_Value |= ((uint64_t)data_buff[low_data_byte]) >> low_data_byte_position;
						}
						else
						{
							can_signal.Signal_Value |= ((uint64_t)data_buff[byte_num]) << ((byte_num - low_data_byte - 1) * 8 + (8 - low_data_byte_position));
						}						
					}
					
					can_signal.Signal_Value = can_signal.Signal_Value & can_signal_mask;					
				}				
			}
		}
		/** Byte Order: Motorola **/
		else  /**signal_byte_order == SIGNAL_BYTE_ORDER_MOTOROLA**/
		{
			/**Bytes used by CAN signal,Byte[0] is low byte,Byte[frame_length] is high byte**/
			high_data_byte = signal_start_bit / 8;	
			
			if((high_data_byte + 1) > frame_length)        /** CAN signal is not in the range of DLC**/
			{
		    	can_signal.Signal_State = CAN_FRAME_DLC_OUT_OF_RANGE;
			}
			else
			{
				for(i = 0;i < signal_length;i++)  /**Generate signal mask according to signal length**/
				{
					can_signal_mask |= 0x0000000000000001 << i;
				}
				
				high_data_byte_position = signal_start_bit % 8;  /**Distance from the lowest bit of each byte**/
				
				/**CAN Signal is in a bytes**/
				if(signal_length <= (8 - high_data_byte_position))
				{				
					can_signal.Signal_Value = (((uint64_t)data_buff[high_data_byte]) >> high_data_byte_position) & can_signal_mask;
				}
				/**CAN Signal in multiple bytes**/
				else
				{			
					remaining_bit_number = signal_length - (8 - high_data_byte_position); // 剩余bit = 12 - (8 - 2) = 6
					
					if((remaining_bit_number % 8) != 0)     
					{
						remaining_byte_number = remaining_bit_number / 8 + 1;          // remaining_byte_number = 1
					}
					else
					{
						remaining_byte_number = remaining_bit_number / 8;
					}
 
					for(byte_num = high_data_byte;byte_num >= (high_data_byte - remaining_byte_number);byte_num--)  // high_data_byte = 2  remaining_byte_number = 1
					{						
						if(byte_num == high_data_byte)
						{
							can_signal.Signal_Value |= ((uint64_t)data_buff[high_data_byte]) >> high_data_byte_position;
						}
						else
						{
							can_signal.Signal_Value |= ((uint64_t)data_buff[byte_num]) << ((high_data_byte - byte_num - 1) * 8 + (8 - high_data_byte_position));
						}		
						
						if(byte_num == 0)	
						{
							break;
						}						
					}
					can_signal.Signal_Value = can_signal.Signal_Value & can_signal_mask;									
				}			
			}				
		}
	}
 
	return can_signal;
} 
