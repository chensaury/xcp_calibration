/*----------------------------------------------------------------------------
| File:
|   XCP_CFG.H
|
| Project:
|   PC Emulation of a ECU using XCP on Ethernet or XCP on CAN
|
 ----------------------------------------------------------------------------*/

#if defined ( __XCP_CFG_H__ )
#else
#define __XCP_CFG_H__


// General includes
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <windows.h>



/*----------------------------------------------------------------------------*/
/* Test instrumentation */

/* Turn on screen logging and assertions */

#define XCP_ENABLE_TESTMODE
#ifdef XCP_ENABLE_TESTMODE

  #define ApplXcpPrint printf
  #define XCP_ASSERT(x) if (!(x)) ApplXcpPrint("Assertion failed\n");
  #define XCP_PARAMETER_CHECKS

#endif

//#define XCP_ENABLE_DPRAM

// Activate autom. map name detection
#define XCP_ENABLE_VECTOR_MAPNAMES

/*----------------------------------------------------------------------------*/
/* XCP Transport Layer */
#define XCP_TRANSPORT_LAYER_TYPE_ETHERNET


/*----------------------------------------------------------------------------*/
/* Platform specific definitions */

  /* 8-Bit qualifier */
typedef unsigned char  vuint8;
typedef signed char    vsint8;

/* 16-Bit qualifier */
typedef unsigned short vuint16;
typedef signed short   vsint16;

/* 32-Bit qualifier */
typedef unsigned long  vuint32;
typedef signed long    vsint32;

/* Byte order */
//#define C_CPUTYPE_BIGENDIAN  /* Motorola */
#define C_CPUTYPE_LITTLEENDIAN /* Intel */



/*----------------------------------------------------------------------------*/
/* XCP protocol parameters */


/* XCP message length */
#define kXcpMaxCTO     8      /* Maximum CTO Message Lenght */
#define kXcpMaxDTO     8      /* Maximum DTO Message Lenght */


/*----------------------------------------------------------------------------*/
/* XCP protocol data acquisition parameters */

/* Enable DAQ and set the memory size reserved for DAQ lists */
#define XCP_ENABLE_DAQ
#define kXcpDaqMemSize 256
#define XCP_ENABLE_DAQ_PRESCALER



/* Flush the transmit buffer after a command response */
extern void ApplXcpSendFlush( void );
#define ApplXcpSendFlush ApplXcpSendFlush

/* Enable DAQ Timestamps */
extern unsigned __int64 tmTimer(void);
#define XCP_ENABLE_DAQ_TIMESTAMP
typedef vuint16 XcpDaqTimestampType;
#define kXcpDaqTimestampSize                 2
#define kXcpDaqTimestampUnit                 DAQ_TIMESTAMP_UNIT_100US
#define kXcpDaqTimestampTicksPerUnit         1
#define ApplXcpGetTimestamp()                    (XcpDaqTimestampType)tmTimer()
#define ApplXcpDaqGetTimestamp()                 (XcpDaqTimestampType)tmTimer()


#define XCP_DISABLE_DAQ_HDR_ODT_DAQ
#undef XCP_ENABLE_DPRAM

#endif


