/* CCPPAR.H */


#define C_ENABLE_CCP
#define C_MINI_CAN_DRIVER
#define C_COMP_TASKING_C16X


#define CCP_INTEL

#define CCP_RAM
#define CCP_ROM     const

#define CCP_BYTE    unsigned char
#define CCP_WORD    unsigned short
#define CCP_DWORD   unsigned long
#define CCP_BYTEPTR unsigned char*

#define CCP_DISABLE_INTERRUPT
#define CCP_ENABLE_INTERRUPT

#define CCP_MTABYTEPTR huge unsigned char*
#define CCP_DAQBYTEPTR huge unsigned char*

#define CCP_STATION_ID "CCPtest"
#define CCP_STATION_ADDR 0x1

#define CCP_DTO_ID 0x101
#define CCP_CRO_ID 0x100

#define CCP_DAQ
#define CCP_MAX_ODT 3
#define CCP_MAX_DAQ 2

#define CCP_SEND_QUEUE_OVERRUN_INDICATION

#define CCP_SEND_QUEUE
#define CCP_SEND_QUEUE_SIZE 6

#define CCP_CHECKSUM
#define CCP_CHECKSUM_TYPE CCP_WORD

#define CCP_BOOTLOADER_DOWNLOAD

#define CCP_CALPAGE

