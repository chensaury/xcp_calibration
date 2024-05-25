/*-------------------------------------------------------------------------------
 VX1000_TRICORE.H
 Program instrumentation for Vector VX with Tricore DAP                                                                                                                               
 Don't modify this file, parameters are defined in VX1000_TRICORE_CFG.H
 Version 2.2 10.3.2011
 Vector Informatik GmbH
-------------------------------------------------------------------------------*/

#define VX1000_FILE_VERSION 0x0202

#ifndef __VX1000_H__
#define __VX1000_H__


/*----------------------------------------------------------------------------*/
/* Datatypes */

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



/*----------------------------------------------------------------------------*/
/* User parameters */

/* Project specific include */
#include "VX1000_TRICORE_CFG.h"
      

/*----------------------------------------------------------------------------*/
/* Tricore related defines */

#undef STM_TIM0
#define STM_TIM0 *(volatile VX1000_UINT32*)0xF0000210UL /* System Timer 0 */

#undef OCDS_OCNTRL
#define OCDS_OCNTRL *(volatile VX1000_UINT32*)0xF000047CUL /* OSCU Control */

#undef OCDS_TRIGS
#define OCDS_TRIGS *(volatile VX1000_UINT32*)0xF00004A0UL /* TRIGS Register */
#undef OCDS_TRIGC
#define OCDS_TRIGC *(volatile VX1000_UINT32*)0xF00004A4UL /* TRIGC Register */
#undef OCDS_TRIG
#define OCDS_TRIG *(volatile VX1000_UINT32*)0xF00004A8UL /* TRIG Register */
      
#undef OVRCON
#define OVRCON *(volatile VX1000_UINT32*)0xF8000520UL /* OVRCON Register */

#undef SCU_RSTSTAT 
#define  SCU_RSTSTAT *(volatile VX1000_UINT32*)0xF0000550UL /* Reset Status Register */
#undef SCU_ARSTDIS 
#define  SCU_ARSTDIS *(volatile VX1000_UINT32*)0xF000055CUL /* Application Reset Disable Register */
#undef SCU_SWRSTCON 
#define  SCU_SWRSTCON *(volatile VX1000_UINT32*)0xF0000560UL /* Software Reset Configuration Register */


/*----------------------------------------------------------------------------*/
/* VX1000 Default Parameters */

/*
 Enable 3 or 2 wire DAP mode and disable BYPASS (JTAG) to increase imunity againt disturbances 
 Default is 2 wire DAP
 VX1000_OCDS_OCNTRL =  0x0000000F;  DJMODE = 11 Three PIN DAP with disabled BYPASS  
 VX1000_OCDS_OCNTRL =  0x00000007;  DJMODE = 01 Two-pin DAP with disabled BYPASS
*/
#ifndef VX1000_OCDS_OCNTRL
  #define VX1000_OCDS_OCNTRL 0x00000007UL
#endif
                                                                                         
/* 
 Clock
 Clock used for measurement data timestamps and bypass timeout checking
 The resolutiion of the clock must be specified here and also in VXPARAMS.INI
 Default is 180 MHz and using System Timer 0
*/
#ifndef	VX1000_CLOCK
  #define VX1000_CLOCK STM_TIM0
#endif
#ifndef	VX1000_CLOCK_TICKS_PER_MS
  #define VX1000_CLOCK_TICKS_PER_MS 45000UL	/* 180 MHz */
#endif


/*
 OLDA
 Transfer list based data acquisition (OLDA)
 Define the memory space used for OLDA tables, VX1000_MEMORY_SIZE=0 -> memory allocated by VX1000
 Default is OLDA on and memory allocated by VX1000 
*/
#define VX1000_OLDA
#ifndef VX1000_OLDA_MEMORY_SIZE
  #define VX1000_OLDA_MEMORY_SIZE 0UL 
  #ifndef	VX1000_OLDA_MEMORY_ADDR
    #define VX1000_OLDA_MEMORY_ADDR 0UL  
  #endif
#else
  #ifndef VX1000_MEMORY_ADDR
    #define VX1000_MEMORY_ADDR &gVX1000_OldaMem
  #endif
#endif

/* Generate OldaFeature Flags */
#ifdef VX1000_STIM_BY_OLDA 
  #define VX1000_OLDA_FEATURE_STIM                (1U << 2)		
#else
  #define VX1000_OLDA_FEATURE_STIM                (0U << 2)
#endif
#ifdef VX1000_OLDA_SIZE_DYNAMIC 
  #define VX1000_OLDA_FEATURE_SIZE_DYNAMIC        (1U << 1)
#else
  #define VX1000_OLDA_FEATURE_SIZE_DYNAMIC        (0U << 1)
#endif
#ifdef VX1000_OLDA_OVERLOAD_DETECTION 
  #define VX1000_OLDA_FEATURE_OVERLOAD_DETECTION  (1U << 0)
#else
  #define VX1000_OLDA_FEATURE_OVERLOAD_DETECTION  (0U << 0)
#endif


/* Default address format is with mask 0xF81FFFFF to encode size/4 with 6 bit */
#ifndef VX1000_OLDA_SIZE_OFFSET 
  #define VX1000_OLDA_SIZE_OFFSET 21U
#endif
/* Default replacement of masked sized information */
#ifndef VX1000_OLDA_SIZE_SWAP_VALUE 
  #define VX1000_OLDA_SIZE_SWAP_VALUE 0x00U
#endif



/* STIM  */
/* Default is STIM off */


/* COLDSTART */
/* Default timeout for cold start initialization in ms */
#ifndef VX1000_COLDSTART_TIMEOUT
  #define VX1000_COLDSTART_TIMEOUT 100U /* ms  */
#endif

/*----------------------------------------------------------------------------*/
/* Defines  */

/* To save memory, the number range for stim events may be limited, maximum is 31  */
#define VX1000_STIM_EVENT_COUNT  31U /* Number of STIM events */
#define VX1000_STIM_EVENT_OFFSET 0U /* Number of the first STIM event */

/* To save memory, the number of olda events may be limited, maximum is 31  */
#define VX1000_OLDA_EVENT_COUNT 31U

#ifdef VX1000_STIM /* Bypassing requires the OLDA feature */
  #ifndef VX1000_OLDA
    #error "Bypassing requires the OLDA feature!"
  #endif
#endif

#ifdef VX1000_STIM_EVENT_OFFSET 
  #if VX1000_STIM_EVENT_OFFSET>30U
    #error "Event numbers must be <=30!"
  #endif
#endif

#if VX1000_OLDA_EVENT_COUNT>31U
  #error "Event numbers must be <=31!"
#endif


/* ToolDetectState */
#define VX1000_TDS_INIT              0x0001U  /* VX1000_INIT done */
#define VX1000_TDS_DETECT            0x0002U	 /* VX1000_DETECT done  */
#define VX1000_TDS_DETECTED          0x0004U	 /* Result of VX1000_DETECT */
#define VX1000_TDS_COLDSTART_DONE    0x0010U	 /* Coldstart done */
#define VX1000_TDS_COLDSTART_TIMEOUT 0x0020U	 /* Coldstart timeout */
#define VX1000_TDS_APPRST            0x0040U	 /* Resume after application reset done */


/* ToolCtrlState  */
#define VX1000_TCS_INIT              0xFEC70001UL 


/*----------------------------------------------------------------------------*/
/* ECUID  */

#if defined(VX1000_ECUID) && defined(VX1000_ECUID_LEN)   
  extern const char gVX1000_ECUID[VX1000_ECUID_LEN];
  #define VX1000_ECUID_DATA const char gVX1000_ECUID[VX1000_ECUID_LEN] = VX1000_ECUID;
  #define VX1000_ECUID_PTR (VX1000_UINT32)&gVX1000_ECUID[0]
#else
  #define VX1000_ECUID_DATA
  #define VX1000_ECUID_PTR 0UL
  #define VX1000_ECUID_LEN 0U   
#endif   


/*----------------------------------------------------------------------------*/
/* OLDA */

#ifdef VX1000_OLDA

  #define VX1000_OLDA_VERSION 0x05U
  #define VX1000_OLDA_MAGIC 0x2603U

  typedef struct {
    VX1000_UINT32   EventCounter;
    VX1000_UINT32   EventTimestamp;
    VX1000_UINT32   TransferDest;
    VX1000_UINT16   TransferIndex;
    VX1000_UINT16   TransferCount;
  } VX1000_OLDA_EVENT_T;

  typedef struct {
    VX1000_UINT16       MagicId;		  /* 0x00 */
    VX1000_UINT8        Version;
    VX1000_UINT8        Runing;
    VX1000_UINT32       MemoryAddr;	      /* 0x04 */
    VX1000_UINT16       Memorysize;	      /* 0x08 */
    VX1000_UINT16       EventCount;	      /* 0x0A */
    VX1000_OLDA_EVENT_T *EventList;	      /* 0x0C */
    VX1000_UINT32       *TransferList;    /* 0x10 */
    VX1000_UINT8        SizeOffset;       /* 0x14 */	   
    VX1000_UINT8        SizeSwapValue;    /* 0x15 */
    VX1000_UINT16       OldaFeatures;     /* 0x16 */
    VX1000_UINT32       Res1;             /* 0x18 */
    VX1000_UINT32       Res2;             /* 0x1C */
    #ifndef VX1000_OLDA_MEMORY_ADDR
      VX1000_UINT32         Data[VX1000_OLDA_MEMORY_SIZE/4];
    #endif
  } VX1000_OLDA_T;


  extern void VX1000_OLDA_INIT( void ); 
  extern void VX1000_OLDA_EVENT( VX1000_UINT8 e ); 

  #define VX1000_OLDA_DATA VX1000_OLDA_T Olda;
  #define VX1000_OLDA_PTR (VX1000_UINT32)&gVX1000.Olda  

  #ifdef VX1000_OLDA_BENCHMARK
    extern VX1000_UINT32 gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];
    extern VX1000_UINT32 gVX1000_OLDA_TransferSize[VX1000_OLDA_EVENT_COUNT];
    extern VX1000_UINT32 gVX1000_OLDA_TransferCount[VX1000_OLDA_EVENT_COUNT];
    #define VX1000_OLDA_BENCHMARK_DATA \
      VX1000_UINT32 gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT]; \
      VX1000_UINT32 gVX1000_OLDA_TransferSize[VX1000_OLDA_EVENT_COUNT]; \
      VX1000_UINT32 gVX1000_OLDA_TransferCount[VX1000_OLDA_EVENT_COUNT];
  #else
    #define VX1000_OLDA_BENCHMARK_DATA
  #endif

#else

  #define VX1000_OLDA_EVENT(x)  

  #define VX1000_OLDA_DATA
  #define VX1000_OLDA_PTR 0U  

  #define VX1000_OLDA_BENCHMARK_DATA

#endif


/*----------------------------------------------------------------------------*/
/* VX1000 Mailbox */

#ifdef VX1000_MAILBOX

  #define VX1000_MAILBOX_MAGIC  0xFEC70A06UL

  #define MAILBOX_SLOTS                  4U
  #define MAILBOX_SLOT_DWORDS            3U    /* 4 byte + 8 byte xcp command */

  #define MAILBOX_OK                     0U
  #define MAILBOX_ERR_FULL               1U
  #define MAILBOX_ERR_EMPTY              2U
  #define MAILBOX_ERR_INDICES            3U
  #define MAILBOX_ERR_SEQUENCE           4U
  #define MAILBOX_ERR_SIZE               5U
  #define MAILBOX_SLOT_RSVD              6U
  #define MAILBOX_ERR_NULL               7U
  #define MAILBOX_ERR_SPLIT_PEND         8U
  
  #define MAILBOX_FREE_WR_SLOTS          ((gVX1000.Mailbox.SM_ReadIdx - gVX1000.Mailbox.SM_WriteIdx - 1) & (MAILBOX_SLOTS - 1))
  #define MAILBOX_USED_RD_SLOTS          ((gVX1000.Mailbox.MS_WriteIdx - gVX1000.Mailbox.MS_ReadIdx) & (MAILBOX_SLOTS - 1))
  #define MAILBOX_NEXT(idx)              ((idx + 1) & (MAILBOX_SLOTS - 1))
  
  #define VX1000_EVENT_MAILBOX_INIT     0x00020000UL
  #define VX1000_EVENT_MAILBOX_UPDATE   0x00020001UL
  #define VX1000_EVENT_MAILBOX_RESETREQ 0x00020002UL

  extern void VX1000_MAILBOX_INIT(void);
  extern void VX1000_MAILBOX_CONTROL(void); 
  extern VX1000_UINT32 vx1000_MailboxWrite(VX1000_UINT32 len, VX1000_UINT8* pBuf);
  extern VX1000_UINT32 vx1000_MailboxRead(VX1000_UINT32* pLen, VX1000_UINT8* pBuf);
  
  struct VX1000_mailbox {
    VX1000_UINT32  MagicId;
    VX1000_UINT32  Version;
    VX1000_UINT16 SlotSize;
    VX1000_UINT8  MS_Slots;
    VX1000_UINT8  SM_Slots;
    VX1000_UINT32  MS_Ptr;
    VX1000_UINT32  SM_Ptr;
    VX1000_UINT8  MS_ReadIdx;
    VX1000_UINT8  MS_WriteIdx;
    VX1000_UINT8  SM_ReadIdx;
    VX1000_UINT8  SM_WriteIdx;
    VX1000_UINT16 RstReq;
    VX1000_UINT16 RstAck;
    VX1000_UINT32   MSData[MAILBOX_SLOTS][MAILBOX_SLOT_DWORDS];
    VX1000_UINT32   SMData[MAILBOX_SLOTS][MAILBOX_SLOT_DWORDS];
  };
  #define VX1000_MAILBOX_DATA struct VX1000_mailbox Mailbox;
  #define VX1000_MAILBOX_PTR (VX1000_UINT32)&gVX1000.Mailbox


  #ifdef VX1000_MAILBOX_OVERLAY_CONTROL

    #define VX1000_CAL_ECU                 0x01U
    #define VX1000_CAL_XCP                 0x02U
    #define VX1000_CAL_ALL                 0x80U        

    #define VX1000_CRC_CMD_UNKNOWN         0x20U
    #define VX1000_CRC_CMD_SYNTAX          0x21U
    #define VX1000_CRC_OUT_OF_RANGE        0x22U
    #define VX1000_CRC_WRITE_PROTECTED     0x23U
    #define VX1000_CRC_ACCESS_DENIED       0x24U
    #define VX1000_CRC_ACCESS_LOCKED       0x25U
    #define VX1000_CRC_PAGE_NOT_VALID      0x26U
    #define VX1000_CRC_PAGE_MODE_NOT_VALID 0x27U
    #define VX1000_CRC_SEGMENT_NOT_VALID   0x28U

    extern void VX1000_INIT_CAL_PAGE( void ); 
    extern VX1000_UINT8 VX1000_GET_CAL_PAGE( VX1000_UINT8 segment, VX1000_UINT8 mode ); 
    extern VX1000_UINT8 VX1000_SET_CAL_PAGE( VX1000_UINT8 segment, VX1000_UINT8 page, VX1000_UINT8 mode);
    extern VX1000_UINT8 VX1000_COPY_CAL_PAGE( VX1000_UINT8 srcSeg, VX1000_UINT8 srcPage, VX1000_UINT8 destSeg, VX1000_UINT8 destPage );

  #endif

  #ifdef VX1000_MAILBOX_PRINTF

    void vx1000_Printf( const char *str, ... );
    #define VX1000_PRINT vx1000_Printf 

  #endif

#else
  #define VX1000_MAILBOX_INIT()
  #define VX1000_MAILBOX_CONTROL()
  #define VX1000_MAILBOX_DATA
  #define VX1000_MAILBOX_PTR 0U 
#endif



/*----------------------------------------------------------------------------*/
/* STIM */

#ifdef VX1000_STIM

  #define VX1000_STIM_MAGIC  0xFEC70A07UL
  
  typedef struct {                
    VX1000_UINT32  MagicId;        /* 0x00 */
    VX1000_UINT16 Version;
    VX1000_UINT16 Control;
    VX1000_UINT8 EvtOffset;
    VX1000_UINT8 EvtNumber;
    VX1000_UINT16 reserved;
    struct VX1000_STIM_event {   /* 0x0C,0x10,0x14,0x18,0x1C,.... */
      VX1000_UINT8 Ctr;
      VX1000_UINT8 RqCtr;
      VX1000_UINT8 Enable;
      VX1000_UINT8 Copying;
    } Event[VX1000_STIM_EVENT_COUNT];
    VX1000_UINT16 Enable;
    VX1000_UINT16 TimeoutCtr;
    VX1000_UINT16 TimeoutCtr2;
  } VX1000_STIM_T;
  
  extern void VX1000_STIM_INIT(void);
  
  #define VX1000_STIM_DATA VX1000_STIM_T Stim;
  #define VX1000_STIM_PTR ((VX1000_UINT32)(&gVX1000.Stim))
  
  #ifdef VX1000_STIM_BENCHMARK
    extern volatile VX1000_UINT32 gVX1000_STIM_Duration[];	
    #ifdef VX1000_STIM_HISTOGRAM
      extern volatile VX1000_UINT32 gVX1000_STIM_Histogram[256];
      extern volatile VX1000_UINT32 gVX1000_STIM_Histogram2[16];
      #define VX1000_STIM_BENCHMARK_DATA \
        volatile VX1000_UINT32 gVX1000_STIM_Duration[32]; \
        volatile VX1000_UINT32 gVX1000_STIM_Histogram[256]; \
        volatile VX1000_UINT32 gVX1000_STIM_Histogram2[16]; 
    #else
      #define VX1000_STIM_BENCHMARK_DATA volatile VX1000_UINT32 gVX1000_STIM_Duration[32];
    #endif
  #else
    #define VX1000_STIM_BENCHMARK_DATA
  #endif

  #define VX1000_STIM_TIMEOUTS gVX1000.Stim.TimeoutCtr
  #define VX1000_STIM_TIMEOUTS_IN_SEQ gVX1000.Stim.TimeoutCtr2

  #define VX1000_EVENT_STIM_INIT        0x30100UL
  #define VX1000_EVENT_STIM_ACK         0x30101UL
  #define VX1000_EVENT_STIM_TIMEOUT(e)  (0x30200UL|(e))
  #define VX1000_EVENT_STIM_ERR(e)      (0x30300UL|(e))
  
  extern void VX1000_RESET_TIMEOUT(VX1000_UINT32 timeout);
  extern VX1000_UINT8 VX1000_CHECK_TIMEOUT(void);
  extern VX1000_UINT8 VX1000_STIM_WAIT(VX1000_UINT8 e,VX1000_UINT32 timeout);
  extern void VX1000_STIM_REQUEST_EVENT(VX1000_UINT8 e);
  
  #if VX1000_STIM_EVENT_OFFSET>0
    #define VX1000_IS_STIM_EVENT(e) ((e)>=VX1000_STIM_EVENT_OFFSET&&(e)<(VX1000_STIM_EVENT_OFFSET+VX1000_STIM_EVENT_COUNT))
  #else
    #define VX1000_IS_STIM_EVENT(e) ((e)<VX1000_STIM_EVENT_COUNT)
  #endif
  
  
  /* Request a specific STIM data set associated to event e */
  #define VX1000_STIM_REQUEST(e) gVX1000.Stim.Event[e-VX1000_STIM_EVENT_OFFSET].RqCtr++; VX1000_STIM_REQUEST_EVENT(e)

#else

  #define VX1000_STIM_DATA
  #define VX1000_STIM_PTR 0UL  
  #define VX1000_STIM_BENCHMARK_DATA
  
#endif



/*----------------------------------------------------------------------------*/
/* TOOL_DETECT and COLDSTART */

#ifdef VX1000_COLDSTART_BENCHMARK

  extern VX1000_UINT32 gVX1000_DETECT_StartTime;
  extern VX1000_UINT32 gVX1000_DETECT_EndTime; 

  #define VX1000_DETECT_BENCHMARK_DATA \
    VX1000_UINT32 gVX1000_DETECT_StartTime; \
    VX1000_UINT32 gVX1000_DETECT_EndTime; 

#else
  #define VX1000_DETECT_BENCHMARK_DATA
#endif



/*----------------------------------------------------------------------------*/
/* Calibration */
			  
#ifdef VX1000_CAL

#include "cc_autosar.h"
#define CC_PTR (VX1000_UINT32)&gCC

#else

#define CC_PTR 0U

#endif


/*----------------------------------------------------------------------------*/
/* VX1000 struct */

/* History: */
/* New in version:  */
/*  4: OldaPtr */
/*  5: Olda integrated at fixed position 0x40 */
/*  6: CalPtr */
/*  7: ToolCtrlState (written by tool) */

#define VX1000_STRUCT_VERSION 7U 
#define VX1000_STRUCT_MAGIC 0xFEC70A08UL

struct VX1000 {
  VX1000_UUINT32 EventNumber;       /* 00 */
  VX1000_UUINT32 EventTimestamp;
  VX1000_UINT32 MagicId;
  VX1000_UINT32 Version;             
  VX1000_UINT32 GetIdPtr;            /* 10 */  
  VX1000_UINT32 GetIdLen;
  VX1000_UINT32 XcpMailboxPtr;
  VX1000_UINT32 StimCtrlPtr;
  VX1000_UINT32 RamSynchField;       /* 20 */
  VX1000_UINT32 ToolDetectState;
  VX1000_UINT32 OldaPtr;
  VX1000_UINT32 OldaEventNumber;    
  VX1000_UINT32 CalPtr;              /* 30 */
  VX1000_UINT32 ToolCtrlState;
  VX1000_UINT32 res6;
  VX1000_UINT32 res7;
                                    /* 40 */
  #if defined(VX1000_OLDA)		      /* Do not change the offset here, must be 0x40 ! */
   VX1000_OLDA_DATA
  #endif

  #if defined(VX1000_STIM)		    
    VX1000_STIM_DATA
  #endif  

  #if defined(VX1000_MAILBOX)		    
   VX1000_MAILBOX_DATA
  #endif


};                                  


/*----------------------------------------------------------------------------*/
/* User functions and macros for VX1000 initialisation */


extern volatile struct VX1000 gVX1000;

/* Define the global data needed for VX1000 */
/* Should be in a memory segment with zero initialization */
#ifdef VX1000_STRUCT_ADDR

	#define VX1000_DATA \
	  volatile struct VX1000 gVX1000 __at(VX1000_STRUCT_ADDR); \
	  VX1000_ECUID_DATA \
	  VX1000_DETECT_BENCHMARK_DATA \
	  VX1000_OLDA_BENCHMARK_DATA \
	  VX1000_STIM_BENCHMARK_DATA

#else

	#define VX1000_DATA \
	  volatile struct VX1000 gVX1000; \
	  VX1000_ECUID_DATA \
	  VX1000_DETECT_BENCHMARK_DATA \
	  VX1000_OLDA_BENCHMARK_DATA \
      VX1000_STIM_BENCHMARK_DATA 

#endif


/* Initialize the global data needed for VX1000 */
/* Must be called before any other VX1000_xxxx() routine is called */
extern void VX1000_INIT(void);

/* Check if a VX is connected and powered */
/* Must be called after VX1000_INIT() before any other VX1000_xxxx() routine is called */
/* Returns true (!=0) if VX is connected and online  */
extern VX1000_UINT8 VX1000_DETECT(void);

/* Check if a VX has been detected by VX1000_DETECT() */
#define VX1000_DETECTED() ((gVX1000.ToolDetectState&VX1000_TDS_DETECTED) || (gVX1000.ToolCtrlState&VX1000_TCS_INIT))




/*----------------------------------------------------------------------------*/
/* User functions and macros for DAQ */

/* Update the timestamp */
/* Optional, only needed if timestamp update rate by events is too slow */
#define VX1000_TIMESTAMP() gVX1000.EventTimestamp.d = VX1000_CLOCK

#if defined(VX1000_OLDA) || defined(VX1000_STIM)

/* Trigger an universal event (TRACE or OLDA) (0..30) */
#define VX1000_EVENT(e) VX1000_OLDA_EVENT(e)

/* Trigger a TRACE event (0..255) */
#define VX1000_TRACE_EVENT(e) gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (e)

/* Trigger a TRACE event (0..255) */
/* Improved trace load but higher cpu effort */
#define VX1000_FAST_TRACE_EVENT(e) { register VX1000_UINT32 t = VX1000_CLOCK; if (gVX1000.EventTimestamp.w.w1==(VX1000_UINT16)(t>>16)) { gVX1000.EventTimestamp.w.w0 = gVX1000.EventTimestamp.w.w0 = (VX1000_UINT16)t; gVX1000.EventNumber.w.w0 = (x); } else { gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = t; gVX1000.EventNumber.d = (e);} }

/* Trigger a special event (0..255,TRIGS=31) */
#define VX1000_SPECIAL_EVENT(e) gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (e); OCDS_TRIGS = 0x80000000UL

#else


/* Trigger a TRACE event (0..255) */
#define VX1000_EVENT(e) gVX1000.EventTimestamp.d = gVX1000.EventTimestamp.d = VX1000_CLOCK; gVX1000.EventNumber.d = (e) 


#endif



/*----------------------------------------------------------------------------*/
/* User functions and macros for STIM */

#ifdef VX1000_STIM
  

#define VX1000_STIM_ACTIVE(stim_event) (gVX1000.Stim.Control && gVX1000.Stim.Enable && VX1000_IS_STIM_EVENT(stim_event) && gVX1000.Stim.Event[(stim_event)-VX1000_STIM_EVENT_OFFSET].Enable)

extern void VX1000_STIM_CONTROL( void );
extern VX1000_UINT8 VX1000_BYPASS( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT32 timeout);
extern VX1000_UINT8 VX1000_BYPASS_TRIGGER( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event );
extern VX1000_UINT8 VX1000_BYPASS_WAIT( VX1000_UINT8 stim_event, VX1000_UINT32 timeout);

#endif /* VX1000_STIM */


  
#endif


/* History:  */
/*
$Log: /VX1000/TriCore/Hover/vx1000_tricore.h $
// 
// 59    10.05.11 13:23 Rainer
// VX1000_INIT_CAL_PAGE
// 
// 58    1.04.11 18:25 Rainer
// Some MISRA violations removed
// 
// 57    1.04.11 17:24 Rainer
// Some MISRA violations removed
 
//  56    8.03.11 8:23 Rainer
//  Log
*/
