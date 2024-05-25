
/*****************************************************************************
| Project Name:   XCP on CAN demo for Infineon Tricore TC17x7
|    File Name:   
|
|  Description:  
|             XCP Slave with 500 Kbit/s, DTO-Id 0x200, CRO-Id 0x201
|             No Seed&Key
|             Dynamic DAQ lists
|             Events:
|               ADC_TASK 0 10ms
|               BACKGROUND_TASK 1 100ms
|             Calibration Concept
|               Transparent. On demand OVRAM overlay creation
|               8 Kbyte OVRAM, 16*512 Bytes overlay segments
|               BUILD_CHECKSUM, SET/GET_CAL_PAGE and COPY_CAL_PAGE supported
|
|-----------------------------------------------------------------------------
|               D E M O
|-----------------------------------------------------------------------------
|
|       Please note, that the demo and example programs 
|       only show special aspects of the software. 
|       With regard to the fact that these programs are meant 
|       for demonstration purposes only,
|       Vector Informatik's liability shall be expressly excluded in cases 
|       of ordinary negligence, to the extent admissible by law or statute.
|
|-----------------------------------------------------------------------------
|               C O P Y R I G H T
|-----------------------------------------------------------------------------
| Copyright (c) 2010 by Vector Informatik GmbH.           All rights reserved.
|
|       This software is copyright protected and 
|       proporietary to Vector Informatik GmbH.
|       Vector Informatik GmbH grants to you only
|       those rights as set out in the license conditions.
|       All other rights remain with Vector Informatik GmbH.
| 
|       Diese Software ist urheberrechtlich geschuetzt. 
|       Vector Informatik GmbH raeumt Ihnen an dieser Software nur 
|       die in den Lizenzbedingungen ausdruecklich genannten Rechte ein.
|       Alle anderen Rechte verbleiben bei Vector Informatik GmbH.
|
|-----------------------------------------------------------------------------
|***************************************************************************/


#include "project.h"
#include "CanIf.h"

//------------------------------------------------------------------------------
// Slave device id

#if defined ( kXcpStationIdLength )
  V_MEMROM0 MEMORY_ROM vuint8 kXcpStationId[kXcpStationIdLength] = kXcpStationIdString;
#endif
typedef unsigned char  ubyte;    // 1 byte unsigned; prefix: ub


// Receive 
// Handle transmission done
void XcpHandler( void ) {
    XcpSendCallBack();
    XcpCommand( (void*)&Com_PduRx_0x201_Buf_1 );
}

// Transmit
void ApplXcpSend( vuint8 len, MEMORY_ROM BYTEPTR msg ) {
    PduInfoType buf;
    memset(&buf, 0, sizeof(PduInfoType));
    volatile uint8 tmp[8];
    buf.SduDataPtr = tmp;
    buf.SduLength = len;
    memcpy(buf.SduDataPtr, msg, len);
    buf.SduLength = len;
//    PRINTF_USH("in XcpHandler\n");
    CanIf_Transmit(2, &buf);
}


// vuint8 ApplXcpSendStall( void ) {

//   while (!CAN_ubRequestMsgObj(1));
//   XcpSendCallBack();
//   return 1;
// }



//------------------------------------------------------------------------------
// Platform dependend functions

// Convert a XCP address to a pointer
MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr ) {

//  addr_ext = addr_ext;
  return (MTABYTEPTR)addr;
}





/*----------------------------------------------------------------------------*/
/* Flash Programming by Flash Kernel */
#if defined ( XCP_ENABLE_BOOTLOADER_DOWNLOAD )

// Prepare flash programming bootloader download
// From PROGRAM_PREPARE
vuint8 ApplXcpDisableNormalOperation( MTABYTEPTR a, vuint16 s )
{
  xcp.BootloaderStartAddr = (vuint32)a;

  // Check if size and address for bootloader download area
  // are not in conflict with anything else
  if (!(xcp.BootloaderStartAddr+s-1<(vuint32)&xcp || xcp.BootloaderStartAddr>(vuint32)&xcp+sizeof(xcp)-1)) {
    return 0; // Access denied
  }

  return 1;
}


// Start XCP/CCP flash programming bootloader
// From PROGRAM_START
vuint8 ApplXcpStartBootLoader( MTABYTEPTR a ) {

  typedef void (*xcpBootLoader_t)(void);

  ((xcpBootLoader_t)a)();
 
  return 0;
}


#endif
