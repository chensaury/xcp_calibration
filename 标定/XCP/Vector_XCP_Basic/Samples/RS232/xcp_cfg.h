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

/*----------------------------------------------------------------------------*/
/* Project specific includes for XCP20.C */

#include "project.h"


/*----------------------------------------------------------------------------*/
/* Test */
/* Use XCP_PRINT to generate diagnostic messages */

#define XCP_DISABLE_TESTMODE
#ifdef XCP_ENABLE_TESTMODE
  /* Enable xcpPutchar */
  #define XCP_ENABLE_SERV_TEXT
  #define XCP_ENABLE_SERV_TEXT_PUTCHAR
  #define ApplXcpSendStall() 0
  #define ApplXcpPrint cprintf
  #define XCP_ASSERT(x) if (!(x)) cprintf("Assertion failed");
#else
  #define XCP_PRINT(x)
  #define XCP_ASSERT(x)
#endif


/*----------------------------------------------------------------------------*/
/* XCP parameters */

  /* 8-Bit qualifier */
typedef unsigned char  vuint8;
typedef signed char    vsint8;   

/* 16-Bit qualifier */
typedef unsigned short vuint16;
typedef signed short   vsint16;

/* 32-Bit qualifier */
typedef unsigned long  vuint32; 
typedef signed long    vsint32;

                                     
/*----------------------------------------------------------------------------*/
/* XCP protocol parameters */

/* Byte order */
//#define C_CPUTYPE_BIGENDIAN  /* Motorola */
#define C_CPUTYPE_LITTLEENDIAN /* Intel */

/* XCP message length */
#define kXcpMaxCTO     14      /* Maximum CTO Message Lenght */
#define kXcpMaxDTO     14      /* Maximum DTO Message Lenght */

/* Enable/Disable parameter checking (save memory) */
#define XCP_DISABLE_PARAMETER_CHECK

/* Enable COMM_MODE_INFO */
#define XCP_ENABLE_COMM_MODE_INFO

/* Enable GET_SEED and UNLOCK */
#define XCP_DISABLE_SEED_KEY

/* Enable xcpUserService() to handle user defined commands */
#define XCP_DISABLE_USER_COMMAND

/* Enable transmission of event messages */
#define XCP_DISABLE_SEND_EVENT

/* Disable FLASH programming */
/* Implement the flash programming feature in the ECU */
/* Not available in xcpBasic ! */
#define XCP_DISABLE_PROGRAM

/* Activate the flash programming kernel download support */
#define XCP_DISABLE_BOOTLOADER_DOWNLOAD

/*----------------------------------------------------------------------------*/
/* Disable/Enable Interrupts */

/* Has to be defined if XcpSendCallBack() can interrupt XcpEvent() */
extern unsigned char gInteruptLevel;
extern unsigned char gInterupt;
#define XCP_DISABLE_INTERRUPT  asm("CLI"); gInteruptLevel++;
#define XCP_ENABLE_INTERRUPT   if (--gInteruptLevel==0 && gInterupt==0) asm("SEI");
#define XCP_INTERUPT_CONTROL_ON gInterupt = 0;
#define XCP_INTERUPT_CONTROL_OFF gInterupt = 1;


/*----------------------------------------------------------------------------*/
/* Memory copy */

#define xcpMemCpy memcpy
#define xcpMemSet memset




/*----------------------------------------------------------------------------*/
/* XCP Calibration Parameters */

#define XCP_ENABLE_CALIBRATION

#define XCP_DISABLE_SHORT_DOWNLOAD
#define XCP_ENABLE_SHORT_UPLOAD

/* Enable block transfer */ 
#define XCP_DISABLE_BLOCK_UPLOAD
#define XCP_DISABLE_BLOCK_DOWNLOAD

/* Enable memory checksum */
/* The checksum will be calculated in XcpBackground() */
/* This may be implementation specific */
#define XCP_DISABLE_CHECKSUM
//#define kXcpChecksumMethod XCP_CHECKSUM_TYPE_ADD14
                   
/* Enable Calibration Page switching and dynamic calibration overlay RAM allocation */
#define XCP_DISABLE_CALIBRATION_MEM_ACCESS_BY_APPL
#define XCP_DISABLE_CALIBRATION_PAGE
#define XCP_DISABLE_PAGE_COPY
#define XCP_DISABLE_SEGMENT_INFO
#define XCP_DISABLE_PAGE_INFO 
#define XCP_DISABLE_PAGE_FREEZE


/*----------------------------------------------------------------------------*/
/* XCP Data Stimulation Parameters */

/* Synchronous Data Stimulation (STIM) */ 
#define XCP_DISABLE_STIM
//#define XCP_ENABLE_STIM
//#define kXcpStimOdtCount 16


/*----------------------------------------------------------------------------*/
/* XCP Data Acquisition Parameters */
                                  
/* Enable data acquisition */
#define XCP_ENABLE_DAQ                   

/* Memory space reserved for DAQ */
#define kXcpDaqMemSize 128

#define XCP_ENABLE_SEND_QUEUE
#define XCP_DISABLE_SEND_BUFFER
#define XCP_DISABLE_DAQ_PRESCALER
#define XCP_DISABLE_DAQ_OVERRUN_INDICATION
#define XCP_DISABLE_DAQ_RESUME
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_RESOLUTION_INFO
#define XCP_DISABLE_WRITE_DAQ_MULTIPLE
#define XCP_DISABLE_DAQ_HDR_ODT_DAQ

/* Enable DAQ Timestamps */ 
#define XCP_DISABLE_DAQ_TIMESTAMP
/*
typedef vuint16 XcpDaqTimestampType;
#define kXcpDaqTimestampSize                 2
#define kXcpDaqTimestampUnit                 DAQ_TIMESTAMP_UNIT_1US
#define kXcpDaqTimestampTicksPerUnit         1
extern unsigned int ApplXcpTimer(void);
#define ApplXcpGetTimestamp()                (XcpDaqTimestampType)ApplXcpTimer()              
#define ApplXcpDaqGetTimestamp()             (XcpDaqTimestampType)ApplXcpTimer()             
*/                                                  

#endif




