/*----------------------------------------------------------------------------
| File:
|   XCP_CFG.H
|
| Project:
|   XCP on CAN driver configuration file 
|
 ----------------------------------------------------------------------------*/

#if defined ( __XCP_CFG_H__ )
#else
#define __XCP_CFG_H__


/*----------------------------------------------------------------------------*/
/* Project specific includes */

#include "project.h"


#define V_MEMROM0

#define XCP_DISABLE_UNALIGNED_MEM_ACCESS
#define XCP_TRANSPORT_LAYER_VERSION 0x100


/*----------------------------------------------------------------------------*/
/* VX1000 */

/* Enable VX1000 */
/* Share DAQ memory with VX */
#define XCP_ENABLE_VX1000
#define XCP_ENABLE_VX1000_MPC5XXX
/*#define XCP_ENABLE_VX1000_TRICORE*/



/*----------------------------------------------------------------------------*/
/* Test */
/* Use XCP_PRINT to generate diagnostic messages */

// #define XCP_ENABLE_TESTMODE
#ifdef XCP_ENABLE_TESTMODE
  #define ApplXcpPrint xcpPrintf
  #define XCP_ASSERT(x) if (!(x)) xcpPrint("Assertion failed");
#else
  #define XCP_PRINT(x)
  #define XCP_ASSERT(x)
#endif



/*----------------------------------------------------------------------------*/
/* XCP protocol parameters */

/* XCP slave device identification */
#define kXcpStationIdLength 7       /* Slave device identification length */
#define kXcpStationIdString "XCPDemo"
extern const vuint8 kXcpStationId[];


/* Byte order */
#define XCP_CPUTYPE_BIGENDIAN /* Motorola */ 

/* XCP message length */
#define kXcpMaxCTO     8      /* Maximum CTO Message Lenght */
#define kXcpMaxDTO     8      /* Maximum DTO Message Lenght */

/* Intensive parameter checking */
#define XCP_DISABLE_PARAMETER_CHECK

/* Enable COMM_MODE_INFO */
#define XCP_ENABLE_COMM_MODE_INFO

/* Enable GET_SEED and UNLOCK */
//#define XCP_ENABLE_SEED_KEY
#define XCP_DISABLE_SEED_KEY

/* Enable xcpUserService() to handle user defined commands */
//#define XCP_ENABLE_USER_COMMAND
#define XCP_DISABLE_USER_COMMAND

/* Enable transmission of event messages */
#define XCP_ENABLE_SEND_EVENT

/* Enable xcpPrintf() and xcpPutChar() via SERV_TEXT events */
#if 0
  #include <stdio.h>
  #include <stdarg.h>          
  #define XCP_ENABLE_SERV_TEXT
  #define XCP_ENABLE_SERV_TEXT_PUTCHAR
  #define XCP_ENABLE_SERV_TEXT_PRINT
  #define XCP_ENABLE_SERV_TEXT_PRINTF
#endif


/* Enable FLASH programming */
/* Implement the flash programming feature in the ECU */
//#define XCP_ENABLE_PROGRAM

/* Deactivate the flash programming kernel download */
//#define XCP_DISABLE_BOOTLOADER_DOWNLOAD




/*----------------------------------------------------------------------------*/
/* XCP Calibration Parameters */

#define XCP_ENABLE_CALIBRATION

#define XCP_ENABLE_SHORT_DOWNLOAD
#define XCP_ENABLE_SHORT_UPLOAD

/* Enable block transfer */ 
#define XCP_ENABLE_BLOCK_UPLOAD

#define XCP_ENABLE_BLOCK_DOWNLOAD
#define kXcpBlockDownloadMinSt 10 // 1ms, if XCP Handler is in 1ms Task

/* Enable memory checksum */
/* The checksum will be calculated in XcpBackground() */
/* This may be implementation specific */
#define XCP_ENABLE_CHECKSUM
#define kXcpChecksumMethod XCP_CHECKSUM_TYPE_ADD14
                   
// Tool handled calibration concept
#define ApplXcpInit cc_init_cal_page 
#define ApplXcpSetCalPage cc_set_cal_page 
#define ApplXcpGetCalPage cc_get_cal_page 
#define ApplXcpCopyCalPage cc_copy_cal_page 

/* Enable Calibration Page switching */
#define XCP_ENABLE_CALIBRATION_PAGE
#define XCP_ENABLE_PAGE_COPY

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

#define XCP_DISABLE_DAQ_HDR_ODT_DAQ //#define XCP_ENABLE_DAQ_HDR_ODT_DAQ
#define XCP_ENABLE_DAQ_PRESCALER
#define XCP_ENABLE_DAQ_OVERRUN_INDICATION
//#define XCP_ENABLE_DAQ_RESUME
#define XCP_ENABLE_DAQ_PROCESSOR_INFO
#define XCP_ENABLE_DAQ_RESOLUTION_INFO
#define XCP_ENABLE_WRITE_DAQ_MULTIPLE

/* Memory space reserved for DAQ */
#define kXcpDaqMemSize (1024*2) /* Use 2K for XCP */
#define XCP_ENABLE_SEND_QUEUE
#define XCP_DISABLE_SEND_BUFFER

/* DAQ Timestamp */ 
#define XCP_ENABLE_DAQ_TIMESTAMP
#ifdef XCP_ENABLE_DAQ_TIMESTAMP 
  #define kXcpDaqTimestampSize         2 
  #define kXcpDaqTimestampUnit         DAQ_TIMESTAMP_UNIT_1MS
  #define kXcpDaqTimestampTicksPerUnit ((VX1000_CLOCK_TICKS_PER_US*1000UL)/256UL)  
  #define ApplXcpGetTimestamp()        (XcpDaqTimestampType)(VX1000_CLOCK()>>8)
  #define ApplXcpDaqGetTimestamp()     (XcpDaqTimestampType)(VX1000_CLOCK()>>8)             
#endif


/* Enable Plug&Play for the event definitions */
//#define XCP_ENABLE_DAQ_EVENT_INFO
#define XCP_DISABLE_DAQ_EVENT_INFO


#endif


