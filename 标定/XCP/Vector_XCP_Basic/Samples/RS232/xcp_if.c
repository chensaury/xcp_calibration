/*****************************************************************************
| Project Name:   XCP V1.0 - Driver
|    File Name:   xcp_if.c
|
|  Description: 
|   XCP driver custom module 
|   This module provides the adaption to a particular platform
|   It contains all platform specific functions
|
|***************************************************************************/

#include "project.h"

#ifdef USE_XCP

#define XCP_PACKET_CHECKSUM
#define XCP_PACKET_CHECKSUM_PLUS_LEN
#define XCP_PACKET_SLIP


//------------------------------------------------------------------------------

#ifdef XCP_INTERRUPT_CONTROL
  unsigned char gInteruptLevel = 0;
  unsigned char gInterupt = 0;
#endif


//------------------------------------------------------------------------------
// Transport Layer

#define SLIP_SYNC 0x9A
#define SLIP_ESC  0x9B

#if xcpMaxCTO>255
  #error
#endif
static vuint8 sBuf[kXcpMaxCTO+2]; // + Header + Checksum
static vuint8 sBufPtr = 0;
static vuint8 sync = 0;


vsint16 GetChar( void ) {

  if (!DataInReceiveBuffer()) return -1;
  return ReceiveByte();
}

#ifdef XCP_PACKET_SLIP
vsint16 GetSlipChar( void ) {

  vuint8 b;
  vuint16 timeout;

  if (!DataInReceiveBuffer()) return -1; // Empty
  b = ReceiveByte(); 

  if (b==SLIP_SYNC) { // Sync
    return 0x100; 
  }
  
  if (b==SLIP_ESC) { // Escape
    timeout = 0;
    while (!DataInReceiveBuffer()) {
      if (++timeout>1000) return -1; // Error Timeout
    }
    b = ReceiveByte();
    switch (b) {
      case 0x00:      return SLIP_ESC;
      case 0x01:      return SLIP_SYNC;
      case SLIP_SYNC: return 0x100; 
      default:        return -1; // Error
    }
  }

  return (vsint16)b;
}

#else

  #define GetSlipChar GetChar

#endif

static vuint8 xcpReceive( void ) {

  vsint16 b;
  vuint8 i;
  vuint8 l;
  vuint8 s;
   
  for (;;) {

    // SlipMode
    // A new packet always starts with a 0xFF
    #ifdef XCP_PACKET_SLIP
      if (!sync) {

        // Get the sync byte
        b = GetChar();
        if (b<0) return 0;
        if (b!=SLIP_SYNC) continue; // Skip this byte
        sync = 1;
        sBufPtr = 0;

      } 
    #endif

    // Get the next byte
    b = GetSlipChar();
    if (b<0) return 0;
    #ifdef XCP_PACKET_SLIP
      if (b==0x100) { // Sync
        sync = 1; // restart
        sBufPtr = 0;
        continue;
      }
    #endif

    // Save this byte 
    sBuf[sBufPtr] = b;
    l = sBuf[0]; // sBuf[0] always is the packet length
    sBufPtr++;

    // Check if this is a valid packet
    if (l==0) { 
      sync = 0;
      sBufPtr = 0;
      continue;
    }

    #ifdef XCP_PACKET_CHECKSUM

      // Check if the packet is complete
      if (sBufPtr<=l+1) {
        continue;
      }

      // Verify checksum
      #ifdef XCP_PACKET_CHECKSUM_PLUS_LEN
        s = l;
      #else
        s = 0;
      #endif
      for (i=0;i<l;i++) s += sBuf[i+1]; 
      if (s!=sBuf[sBufPtr-1]) { // Checksum error
        sync = 0;
        sBufPtr = 0;
        return 0;
      }

    #else

      // Check if the packet is complete
      if (sBufPtr<=l) {
        continue;
      }
  
    #endif

    // Return the packet
    sync = 0;
    sBufPtr = 0;
    return 1;        

  } // for (;;)
 
}


// Receive a XCP packet
void XcpReceiveCommand( void ) {
  if (xcpReceive()) {
    XcpCommand( (void*)&sBuf[1] );
  }
}

#ifdef XCP_PACKET_SLIP
  vuint8 TransmitSlipByte( vuint8 b ) {  

      switch (b) {
        case SLIP_ESC:  
          return TransmitByte(SLIP_ESC) && TransmitByte(0x00);
        case SLIP_SYNC: 
          return TransmitByte(SLIP_ESC) && TransmitByte(0x01);
        default: 
          return TransmitByte(b);
      }
  }
#else
  #define TransmitSlipByte TransmitByte
#endif

// Transmit a XCP packet
// Called by the XCP driver
void ApplXcpSend( vuint8 len, MEMORY_ROM BYTEPTR msg1 ) {
               
  vuint8 b;
  BYTEPTR msg = (BYTEPTR)msg1;
  #ifdef XCP_PACKET_CHECKSUM
    vuint8 checksum;
  #endif
 
  if (len==0||len>kXcpMaxDTO) return; // should not happen

  #ifdef XCP_PACKET_SLIP
    if (!TransmitByte(SLIP_SYNC)) return; // Each packet begins with 0xFF
  #endif
  if (!TransmitSlipByte(len)) return;
  #ifdef XCP_PACKET_CHECKSUM
    #ifdef XCP_PACKET_CHECKSUM_PLUS_LEN
      checksum = len;
    #else
      checksum = 0;
    #endif
  #endif
  while (len--) {
    b = *msg++;
    #ifdef XCP_PACKET_CHECKSUM
      checksum += b;
    #endif
    if (!TransmitSlipByte(b)) return;   
  }  
  #ifdef XCP_PACKET_CHECKSUM
    if (!TransmitSlipByte(checksum)) return;   
  #endif 
    
  return;       
}

/*
vuint8 ApplXcpSend( vuint8 len, BYTEPTR msg1 ) {
  ApplXcpSend1(len,msg1);
  return 0;
}
*/

//------------------------------------------------------------------------------
// Platform dependend functions

// Convert a XCP address to a pointer
MTABYTEPTR ApplXcpGetPointer( vuint8 addr_ext, vuint32 addr ) {

  addr_ext = addr_ext;
  return (MTABYTEPTR)addr;
}

#endif
