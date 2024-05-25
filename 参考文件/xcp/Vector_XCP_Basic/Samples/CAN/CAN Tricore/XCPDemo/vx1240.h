//-------------------------------------------------------------------------------
// VX1240.H
// Program instrumentation for Vector VX with VX1240 Tricore DAP ECU Interface                                                                                                                              
// Don't modify this file, parameters are defined in VX1240_CFG.H
// Version 1.9 15.10.2010
// Vector Informatik GmbH
//-------------------------------------------------------------------------------

#define VX1000_FILE_VERSION 0x0109

/*

Overview:

//--------------------------------------
// General

// Define global data needed by VX
VX1000_DATA;

// Initialize the global data needed for VX1000
// Must be called after reset during initialisation before any other VX1000_xxxx() routine is called !!
// VX1000_INIT just initializes VX1000_DATA, if will not use any Tricore or EEC resource
VX1000_INIT();

// Check if a VX1000 is connected and powered
// Must be called immediately after VX1000_INIT() before any other VX1000_xxxx() routine is called
// If this routine is not called, the VX will be in "hot attached mode"
// Returns true (!=0) if VX1000 is connected and online
// Can delay for up to VX1000_COLDSTART_TIMEOUT ms, if a coldstart measurement is initiated by the VX1000
r = VX1000_DETECT();

It might be necessary for the ECU software to detect the presense of a VX1000 to avoid resource conflicts. For instance flash emulation: A XCP on CAN 
driver or the VX1000 may want use EMEM or OVRAM and the OVRCON registers. If the VX1000 is attached and used for calibration, the XCP on CAN 
drivers flash emulation must be disabled. 

The VX1000 has two modes of operation: Hot attached mode and acknowledged mode. In hot attached mode, the VX1000 assumes that the ECU is not aware of its presence.
In acknowledged mode, the VX1000 assumes the ECU is aware of its presence and does not use any resource needed by VX1000. 

VX1000 detect handshake:      
After detecting a rising edge on the reset line, the VX1000 will write 0x31636556 to CBS_TRIG. 
The function VX1000_DETECT must not be called before 50us after reset. To be sure, VX1000_DETECT delays for 50us. 
If VX1000_DETECT has detected the VX1000, it will acknowledge this by writing 0x00005555 to CBS_TRIG. This causes the VX1000 to go to acknowleged mode.
So the only way to enter acknowledged mode, is to turn on the VX1000 before the ECU or before reseting the ECU. 

VX1000 detect handshake in coldstart mode:
Coldstart measurement means data acquisition beginning with the very first control loop. In this case, the VX1000 will initialize the measurement 
data transfer tables during VX1000_DETECT. 
If the VX1000 is in coldstart mode the pattern in CBS_TRIG will be 0x32636556. 
After detecting a VX1000 in coldstart mode, VX1000_DETECT aknowleges this in the usual way with CBS_TRIG=0x00005555 and delays for a maximum of 
VX1000_COLDSTART_TIMEOUT ms or until the VX1000 set CBS_TRIG to 0x55555555 to indicate completion of coldstart initialization. 
VX1000_DETECT will acknowledge with CBS_TRIG=0x00000000, in case of timeout with CBS_TRIG=0xFFFFFFFF. 



//--------------------------------------
// Measurement data acquisition

// Trigger an universal event (TRACE or OLDA) (0..30) with timestamp
VX1000_EVENT(DaqEvent);

// Trigger a TRACE only event (0..255) with timestamp
// This is faster than VX1000_EVENT() but all signals associated with this event must be measured with data trace measurments 
// Use this for very high data acqistion rates <=50us
VX1000_TRACE_EVENT(DaqEvent);


//--------------------------------------
// Stimulation and Bypassing

// Stimulation control function
// Call this periodically in a low priority background task
VX1000_STIM_CONTROL();

// Check if stimulation for a stimulation event is turned on (return !=0 true) and bypass  
// TimeOut is in ms
// if (!VX1000_BYPASS(1,2,1000) function_to_bypass(); 
r = VX1000_BYPASS(DaqEvent,StimEvent,TimeOut);



*/

#ifndef __VX1000_H__
#define __VX1000_H__


//------------------------------------------------------------------------------
// Defines

#define VX1000_UINT64 unsigned long long
#define VX1000_UINT32 unsigned int
#define VX1000_UINT16 unsigned short
#define VX1000_UINT8 unsigned char
#define VX1000_INT64 signed long long
#define VX1000_INT32 signed int
#define VX1000_INT16 signed short
#define VX1000_INT8 signed char

typedef union vx1000_uuint32 {
  unsigned int d;
  struct {
    unsigned short w0;
    unsigned short w1;
  } w;
  struct {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
  } b;
} VX1000_UUINT32;



//------------------------------------------------------------------------------
// User parameters

// Project specific include
#include "vx1240_cfg.h"
      

//------------------------------------------------------------------------------
// Tricore defines

#undef STM_TIM0
#define STM_TIM0 *(volatile unsigned int*)0xF0000210 /* System Timer 0 */

#undef OCDS_OCNTRL
#define OCDS_OCNTRL *(volatile unsigned int*)0xF000047C /* OSCU Control */

#undef OCDS_TRIGS
#define OCDS_TRIGS *(volatile unsigned int*)0xF00004A0 /* TRIGS Register */
#undef OCDS_TRIGC
#define OCDS_TRIGC *(volatile unsigned int*)0xF00004A4 /* TRIGC Register */
#undef OCDS_TRIG
#define OCDS_TRIG *(volatile unsigned int*)0xF00004A8 /* TRIG Register */
      
#undef OVRCON
#define OVRCON *(volatile unsigned int*)0xF8000520 /* OVRCON Register */

#undef SCU_RSTSTAT 
#define  SCU_RSTSTAT *(volatile unsigned int*)0xF0000550 /* Reset Status Register */
#undef SCU_ARSTDIS 
#define  SCU_ARSTDIS *(volatile unsigned int*)0xF000055C /* Application Reset Disable Register */
#undef SCU_SWRSTCON 
#define  SCU_SWRSTCON *(volatile unsigned int*)0xF0000560 /* Software Reset Configuration Register */


//------------------------------------------------------------------------------
// Default parameters

// Enable 3 or 2 wire DAP mode and disable BYPASS (JTAG) to increase imunity againt disturbances 
// Default is 2 wire DAP
// VX1000_OCDS_OCNTRL =  0x0000000F;  // DJMODE = 11 Three PIN DAP with disabled BYPASS  
// VX1000_OCDS_OCNTRL =  0x00000007;  // DJMODE = 01 Two-pin DAP with disabled BYPASS
#ifndef VX1000_OCDS_OCNTRL
  #define VX1000_OCDS_OCNTRL 0x00000007
#endif
                                                                                         
// Clock
// Clock used for measurement data timestamps and bypass timeout checking
// The resolutiion of the clock must be specified here and also in VXPARAMS.INI
// Default is 180 MHz and using System Timer 0
#ifndef	VX1000_CLOCK
  #define VX1000_CLOCK STM_TIM0
#endif
#ifndef	VX1000_CLOCK_TICKS_PER_MS
  #define VX1000_CLOCK_TICKS_PER_MS 45000UL	// 180 MHz
#endif


// OLDA
// Transfer list based data acquisition (OLDA)
// Define the memory space used for OLDA tables, VX1000_MEMORY_SIZE=0 -> memory allocated by VX1000
// Default is OLDA on and memory allocated by VX1000 
#define VX1000_OLDA
#ifndef VX1000_OLDA_MEMORY_SIZE
  #define VX1000_OLDA_MEMORY_SIZE 0 
  #ifndef	VX1000_OLDA_MEMORY_ADDR
    #define VX1000_OLDA_MEMORY_ADDR 0  
  #endif
#else
  #ifndef VX1000_MEMORY_ADDR
    #define VX1000_MEMORY_ADDR &gVX1000_OldaMem
  #endif
#endif
// Default address format is with mask 0xF81FFFFF to encode size/4 with 6 bit
#ifndef VX1000_OLDA_SIZE_OFFSET 
  #define VX1000_OLDA_SIZE_OFFSET 21
#endif



// STIM
// Default is STIM off


// COLDSTART
// Default timeout for cold start initialization in ms
#ifndef VX1000_COLDSTART_TIMEOUT
  #define VX1000_COLDSTART_TIMEOUT 100 // ms 
#endif

//------------------------------------------------------------------------------
// Defines


#define VX1240_DATA VX1000_DATA
#define VX1240_INIT VX1000_INIT
#define VX1240_EVENT VX1000_EVENT
#define VX1240_TIMESTAMP VX1000_TIMESTAMP

// To save memory, the number range for stim events may be limited, maximum is 31 
#define VX1000_STIM_EVENT_COUNT  31 // Number of STIM events
#define VX1000_STIM_EVENT_OFFSET 0 // Number of the first STIM event

// To save memory, the number of olda events may be limited, maximum is 31 
#define VX1000_OLDA_EVENT_COUNT 31

#ifdef VX1000_STIM // Bypassing requires the OLDA feature
  #ifndef VX1000_OLDA
    #error "Bypassing requires the OLDA feature!"
  #endif
#endif

#ifdef VX1000_STIM_EVENT_OFFSET 
  #if VX1000_STIM_EVENT_OFFSET>30
    #error "Event numbers must be <=30!"
  #endif
#endif

#if VX1000_OLDA_EVENT_COUNT>31
  #error "Event numbers must be <=31!"
#endif


// ToolDetectState
#define VX1000_TDS_INIT              0x0001  // VX1000_INIT done
#define VX1000_TDS_DETECT            0x0002	 // VX1000_DETECT done
#define VX1000_TDS_DETECTED          0x0004	 // Result of VX1000_DETECT
#define VX1000_TDS_COLDSTART_DONE    0x0010	 // Coldstart done
#define VX1000_TDS_COLDSTART_TIMEOUT 0x0020	 // Coldstart timeout
#define VX1000_TDS_APPRST            0x0040	 // Resume after application reset done


// ToolCtrlState
#define VX1000_TCS_INIT              0xFEC70001 


//----------------------------------------------------------------------------------------------------
// ECUID

#if defined(VX1000_ECUID) && defined(VX1000_ECUID_LEN)   
  extern const char gVX1000_ECUID[VX1000_ECUID_LEN];
  #define VX1000_ECUID_DATA const char gVX1000_ECUID[VX1000_ECUID_LEN] = VX1000_ECUID;
  #define VX1000_ECUID_PTR (unsigned long)&gVX1000_ECUID[0]
#else
  #define VX1000_ECUID_DATA
  #define VX1000_ECUID_PTR 0
  #define VX1000_ECUID_LEN 0   
#endif   


//----------------------------------------------------------------------------------------------------
// OLDA

#ifdef VX1000_OLDA

  #define VX1000_OLDA_VERSION 0x04
  #define VX1000_OLDA_MAGIC 0x2603

  typedef struct {
    unsigned int   EventCounter;
    unsigned int   EventTimestamp;
    unsigned int   TransferDest;
    unsigned short TransferIndex;
    unsigned short TransferCount;
  } VX1000_OLDA_EVENT_T;

  typedef struct {
    unsigned short       MagicId;		   // 0x00
    unsigned char        Version;
    unsigned char        Runing;
    unsigned int         MemoryAddr;	   // 0x04
    unsigned short       Memorysize;	   // 0x08
    unsigned short       EventCount;	   // 0x0A
    VX1000_OLDA_EVENT_T *EventList;		   // 0x0C
    unsigned int        *TransferList;	   // 0x10
    unsigned char        SizeOffset;       // 0x14	   
    unsigned char        Res1;             // 0x15	   
    unsigned short       Res2;             // 0x16	   
    unsigned long        Res3;             // 0x18	   
    unsigned long        Res4;             // 0x1C	   
    #ifndef VX1000_OLDA_MEMORY_ADDR
      unsigned int         Data[VX1000_OLDA_MEMORY_SIZE/4];
    #endif
  } VX1000_OLDA_T;


  extern void VX1000_OLDA_INITIALIZE( void ); 
  extern void VX1000_OLDA_EVENT( unsigned char event ); 

  #define VX1000_OLDA_INIT VX1000_OLDA_INITIALIZE();
  #define VX1000_OLDA_DATA VX1000_OLDA_T Olda;
  #define VX1000_OLDA_PTR (unsigned int)&gVX1000.Olda  

  #ifdef VX1000_OLDA_BENCHMARK
    extern unsigned int gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];
    #define VX1000_OLDA_BENCHMARK_DATA unsigned int gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];
  #else
    #define VX1000_OLDA_BENCHMARK_DATA
  #endif

#else

  #define VX1000_OLDA_INITIALIZE() 
  #define VX1000_OLDA_EVENT(x)  

  #define VX1000_OLDA_INIT
  #define VX1000_OLDA_DATA
  #define VX1000_OLDA_PTR 0  

  #define VX1000_OLDA_BENCHMARK_DATA

#endif


   //----------------------------------------------------------------------------------------------------
// VX1000 Mailbox

#ifdef VX1000_MAILBOX

  #define VX1000_MAILBOX_MAGIC  0xFEC70A06

  #define MAILBOX_SLOTS                  4
  #define MAILBOX_SLOT_DWORDS            3    // 4 byte + 8 byte xcp command

  #define MAILBOX_OK                     0
  #define MAILBOX_ERR_FULL               1
  #define MAILBOX_ERR_EMPTY              2
  #define MAILBOX_ERR_INDICES            3
  #define MAILBOX_ERR_SEQUENCE           4
  #define MAILBOX_ERR_SIZE               5
  #define MAILBOX_SLOT_RSVD              6
  #define MAILBOX_ERR_NULL               7
  #define MAILBOX_ERR_SPLIT_PEND         8
  
  #define MAILBOX_FREE_WR_SLOTS          ((gVX1000.Mailbox.SM_ReadIdx - gVX1000.Mailbox.SM_WriteIdx - 1) & (MAILBOX_SLOTS - 1))
  #define MAILBOX_USED_RD_SLOTS          ((gVX1000.Mailbox.MS_WriteIdx - gVX1000.Mailbox.MS_ReadIdx) & (MAILBOX_SLOTS - 1))
  #define MAILBOX_NEXT(idx)              ((idx + 1) & (MAILBOX_SLOTS - 1))
  
  #define VX1000_EVENT_MAILBOX_INIT     0x00020000UL
  #define VX1000_EVENT_MAILBOX_UPDATE   0x00020001UL
  #define VX1000_EVENT_MAILBOX_RESETREQ 0x00020002UL

  extern void vx1000_MailboxInit(void);
  extern void vx1000_MailboxHandler(void); 
  extern unsigned int vx1000_MailboxWrite(unsigned int len, unsigned char* pBuf);
  extern unsigned int vx1000_MailboxRead(unsigned int* pLen, unsigned char* pBuf);
  
  struct VX1000_mailbox {
    unsigned long  MagicId;
    unsigned long  Version;
    unsigned short SlotSize;
    unsigned char  MS_Slots;
    unsigned char  SM_Slots;
    unsigned long  MS_Ptr;
    unsigned long  SM_Ptr;
    unsigned char  MS_ReadIdx;
    unsigned char  MS_WriteIdx;
    unsigned char  SM_ReadIdx;
    unsigned char  SM_WriteIdx;
    unsigned short RstReq;
    unsigned short RstAck;
    unsigned int   MSData[MAILBOX_SLOTS][MAILBOX_SLOT_DWORDS];
    unsigned int   SMData[MAILBOX_SLOTS][MAILBOX_SLOT_DWORDS];
  };
  #define VX1000_MAILBOX_INIT vx1000_MailboxInit();
  #define VX1000_MAILBOX_CONTROL() vx1000_MailboxHandler()
  #define VX1000_MAILBOX_DATA struct VX1000_mailbox Mailbox;
  #define VX1000_MAILBOX_PTR (unsigned long)&gVX1000.Mailbox


  #ifdef VX1000_MAILBOX_OVERLAY_CONTROL

    #define CAL_ECU                 0x01
    #define CAL_XCP                 0x02
    #define CAL_ALL                 0x80        

    #define CRC_CMD_UNKNOWN         0x20
    #define CRC_CMD_SYNTAX          0x21
    #define CRC_OUT_OF_RANGE        0x22
    #define CRC_WRITE_PROTECTED     0x23
    #define CRC_ACCESS_DENIED       0x24
    #define CRC_ACCESS_LOCKED       0x25
    #define CRC_PAGE_NOT_VALID      0x26
    #define CRC_PAGE_MODE_NOT_VALID 0x27
    #define CRC_SEGMENT_NOT_VALID   0x28

    extern unsigned char VX1000_GET_CAL_PAGE( unsigned char segment, unsigned char mode ); 
    extern unsigned char VX1000_SET_CAL_PAGE( unsigned char segment, unsigned char page, unsigned char mode);
    extern unsigned char VX1000_COPY_CAL_PAGE( unsigned char srcSeg, unsigned char srcPage, unsigned char destSeg, unsigned char destPage );

  #endif

  #ifdef VX1000_MAILBOX_PRINTF

    void vx1000_Printf( const char *str, ... );
    #define VX1000_PRINT vx1000_Printf 

  #endif

#else
  #define VX1000_MAILBOX_INIT
  #define VX1000_MAILBOX_CONTROL()
  #define VX1000_MAILBOX_DATA
  #define VX1000_MAILBOX_PTR 0 
#endif



//----------------------------------------------------------------------------------------------------
// STIM

#ifdef VX1000_STIM

  #define VX1000_STIM_MAGIC  0xFEC70A07
  
  typedef struct {                
    unsigned int  MagicId;        // 0x00
    unsigned short Version;
    unsigned short Control;
    unsigned char EvtOffset;
    unsigned char EvtNumber;
    unsigned short reserved;
    struct VX1000_STIM_event {   // 0x0C,0x10,0x14,0x18,0x1C,....
      unsigned char Ctr;
      unsigned char RqCtr;
      unsigned char Enable;
      unsigned char Copying;
    } Event[VX1000_STIM_EVENT_COUNT];
  } VX1000_STIM_T;
  
  extern void VX1000_STIM_INITIALIZE(void);
  #define VX1000_STIM_INIT VX1000_STIM_INITIALIZE();
  
  
  #define VX1000_STIM_DATA \
    volatile VX1000_STIM_T gVX1000_STIM; \
    volatile unsigned int gVX1000_STIM_Timeout_Ctr; \
    volatile unsigned int gVX1000_STIM_Enable;

  #define VX1000_STIM_PTR (unsigned int)&gVX1000_STIM
  
  #ifdef VX1000_STIM_BENCHMARK
    extern volatile unsigned int gVX1000_STIM_Duration[];
    #define VX1000_STIM_BENCHMARK_DATA volatile unsigned int gVX1000_STIM_Duration[32];
  #else
    #define VX1000_STIM_BENCHMARK_DATA
  #endif

  extern volatile VX1000_STIM_T gVX1000_STIM;
  extern volatile unsigned int gVX1000_STIM_Timeout_Ctr;
  extern volatile unsigned int gVX1000_STIM_Timeout;
  extern volatile unsigned int gVX1000_STIM_Enable;

  extern unsigned char VX1000_BYPASS( unsigned char daq_event, unsigned char stim_event, unsigned int timeout);

#else

  #define VX1000_STIM_INIT
  #define VX1000_STIM_DATA
  #define VX1000_STIM_PTR 0  
  #define VX1000_STIM_BENCHMARK_DATA
  
#endif



//----------------------------------------------------------------------------------------------------
// TOOL_DETECT and COLDSTART

#ifdef VX1000_COLDSTART_BENCHMARK

  extern unsigned int gVX1000_DETECT_StartTime;
  extern unsigned int gVX1000_DETECT_EndTime; 

  #define VX1000_DETECT_BENCHMARK_DATA \
    unsigned int gVX1000_DETECT_StartTime; \
    unsigned int gVX1000_DETECT_EndTime; 

#else
  #define VX1000_DETECT_BENCHMARK_DATA
#endif



//----------------------------------------------------------------------------------------------------
// Calibration
			  
#ifdef VX1000_CAL

#include "cc_autosar.h"
#define CC_PTR (unsigned int)&gCC

#else

#define CC_PTR 0

#endif


//----------------------------------------------------------------------------------------------------
// VX1000 struct

// History:
// New in version: 
//  4: OldaPtr
//  5: Olda integrated at fixed position 0x40
//  6: CalPtr
//  7: ToolCtrlState (written by tool)

#define VX1000_STRUCT_VERSION 7 
#define VX1000_STRUCT_MAGIC 0xFEC70A08

struct VX1000 {
  VX1000_UUINT32 EventNumber;       // 00
  VX1000_UUINT32 EventTimestamp;
  unsigned int MagicId;
  unsigned int Version;             
  unsigned int GetIdPtr;            // 10  
  unsigned int GetIdLen;
  unsigned int XcpMailboxPtr;
  unsigned int StimCtrlPtr;
  unsigned int RamSynchField;       // 20
  unsigned int ToolDetectState;
  unsigned int OldaPtr;
  unsigned int OldaEventNumber;    
  unsigned int CalPtr;              // 30
  unsigned int ToolCtrlState;
  unsigned int res6;
  unsigned int res7;
                                    // 40
  #if defined(VX1000_OLDA)		      // Do not change the offset here, must be 0x40 !
   VX1000_OLDA_DATA
  #endif

  #if defined(VX1000_MAILBOX)		    
   VX1000_MAILBOX_DATA
  #endif


};                                  


//----------------------------------------------------------------------------------------------------
// VX1000_DATA, VX1000_INIT
// User macros for initialisation and global data


extern volatile struct VX1000 gVX1000;

// Define the global data needed for VX1000
// Should be in a memory segment with zero initialization
#ifdef VX1000_STRUCT_ADDR
#define VX1000_DATA \
  volatile struct VX1000 gVX1000 __at(VX1000_STRUCT_ADDR); \
  VX1000_STIM_DATA \
  VX1000_ECUID_DATA \
  VX1000_DETECT_BENCHMARK_DATA \
  VX1000_OLDA_BENCHMARK_DATA \
  VX1000_STIM_BENCHMARK_DATA 
#else
#define VX1000_DATA \
  volatile struct VX1000 gVX1000; \
  VX1000_STIM_DATA \
  VX1000_ECUID_DATA \
  VX1000_DETECT_BENCHMARK_DATA \
  VX1000_OLDA_BENCHMARK_DATA \
  VX1000_STIM_BENCHMARK_DATA 
#endif


// Initialize the global data needed for VX1000
// Must be called before any other VX1000_xxxx() routine is called
extern void VX1000_INIT(void);

// Check if a VX1240 is connected and powered
// Must be called after VX1000_INIT() before any other VX1000_xxxx() routine is called
// Returns true (!=0) if VX is connected and online 
extern unsigned char VX1000_DETECT(void);

// Check if a VX1240 has been detected by VX1000_DETECT()
#define VX1000_DETECTED() ((gVX1000.ToolDetectState&VX1000_TDS_DETECTED) || (gVX1000.ToolCtrlState&VX1000_TCS_INIT))




//----------------------------------------------------------------------------------------------------
// VX1000_TIMESTAMP, VX1000_EVENT
// User macros for DAQ

// Update the timestamp
// Optional, only needed if timestamp update rate by events is too slow
#define VX1000_TIMESTAMP() \
  gVX1000.EventTimestamp.d = VX1000_CLOCK;

#if defined(VX1000_OLDA) || defined(VX1000_STIM)

// Trigger an universal event (TRACE or OLDA) (0..30)
#define VX1000_EVENT(x) { VX1000_OLDA_EVENT(x); gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (x); }

// Trigger a TRACE event (0..255)
#define VX1000_TRACE_EVENT(x) { gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (x); }

// Trigger a TRACE event (0..255)
// Improved trace load but higher cpu effort
#define VX1000_FAST_TRACE_EVENT(x) { register unsigned int t = VX1000_CLOCK; if (gVX1000.EventTimestamp.w.w1==(unsigned short)(t>>16)) { gVX1000.EventTimestamp.w.w0 = gVX1000.EventTimestamp.w.w0 = (unsigned short)t; gVX1000.EventNumber.w.w0 = (x); } else { gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = t; gVX1000.EventNumber.d = (x);} }

// Trigger a special event (0..255,TRIGS=31)
#define VX1000_SPECIAL_EVENT(x) { gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (x); OCDS_TRIGS = 0x80000000; }  

#else


// Trigger a TRACE event (0..255)
#define VX1000_EVENT(x) { gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (x); }


#endif



//----------------------------------------------------------------------------------------------------
// VX1000_STIM_CONTROL, VX1000_BYPASS, VX1000_STIM_WAIT, VX1000_STIM_REQUEST
// User macros and function prototypes for STIM

#ifdef VX1000_STIM
  
#define VX1000_EVENT_STIM_INIT        0x30100
#define VX1000_EVENT_STIM_ACK         0x30101
#define VX1000_EVENT_STIM_TIMEOUT(e)  (0x30200|e)
#define VX1000_EVENT_STIM_ERR(e)      (0x30300|e)

extern void VX1000_RESET_TIMEOUT(unsigned int timeout);
extern unsigned char VX1000_CHECK_TIMEOUT(void);
extern void VX1000_STIM_WAIT(unsigned char event,unsigned int timeout);
extern void VX1000_STIM_CONTROL(void);

#if VX1000_STIM_EVENT_OFFSET>0
  #define VX1000_IS_STIM_EVENT(e) ((e)>=VX1000_STIM_EVENT_OFFSET&&(e)<(VX1000_STIM_EVENT_OFFSET+VX1000_STIM_EVENT_COUNT))
#else
  #define VX1000_IS_STIM_EVENT(e) ((e)<VX1000_STIM_EVENT_COUNT)
#endif

// Stim Active Check
#define VX1000_STIM_ACTIVE(e) \
  (gVX1000_STIM.Control && gVX1000_STIM_Enable && VX1000_IS_STIM_EVENT(e) && gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].Enable)

// Request a specific STIM data set associated to event e
#define VX1000_STIM_REQUEST(e) \
   gVX1000_STIM.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr++; \
   VX1000_EVENT(e);


#endif
  
#endif



