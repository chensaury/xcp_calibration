/*------------------------------------------------------------------------------- */
/* vx1000_mpc5xxx.c                                                               */
/* Program instrumentation for Vector VX with FSL/STM PowerPC xPC55xx and xPC56xx */
/* Version 2.0e 09.08.2012                                                        */
/* Vector Informatik GmbH                                                         */
/*                                                                                */
/* Don't modify this file, parameters are defined in vx1000_mpc5xxx_cfg.h         */
/*------------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------------------------------------------------- /
/ Status of MISRA conformance:                                                                                             /
/ ---------------------------                                                                                              /
/  * advisory and required rules 11.x and 17.x "usage of pointers, pointer arithmetics                                     /
/    and casts between differently typed or differently qualified pointers"                                                /
/     - violated because copying data from and to arbitrary locations is the core feature of this module                   /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 19.1 "location of file inclusions"                                                                      /
/     - violated because there exists no MISRA-conform workaround without loosing essential functionality                  /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.4 "complete statement inside a macro"                                                                /
/     - todo (not worked around yet because it's not clear whether this is a user's requirement or not - see comment)      /
/                                                                                                                          /
/  * advisory rule 19.7 "functions vs. macros"                                                                             /
/     - violated because possible workarounds induce a significant performance loss                                        /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.15 "repeated file inclusion"                                                                         /
/     - just a phantom detection by the checker tool, no real violation                                                    /
/                                                                                                                          /
/  * advisory and required rules 5.2, 8.8, 12.13, 17.4, 19.4                                                               /
/     - only violated in dead code (function calcAdd32() - todo: solve before using this code in new features!)            /
/                                                                                                                          /
/------------------------------------------------------------------------------------------------------------------------ */


/*
TODO: add all function headers according to this template/example:
*/

/*----------------------------------------------------------------------------------------------------------------------------*/
/* Internal name: vx1000_StimTransfer                                                                                         */
/* API name:      none                                                                                                        */
/* Return value:  none                                                                                                        */
/* Parameter1:    eventNumber E [0,gVX1000.Olda.EventCount)                                                                   */
/*                Validity ensured by internal silent abort. // or: {internal assertion, caller }.                            */
/* Preemption:    This function must not be interrupted by any vx1000_* function.                                             */
/*                This function should not interrupt and should not be interrupted by code that reads the stimulation data.   */
/* Termination:   May leave the destination data in an inconsistent state.                                                    */
/*                Internal data stays valid, no problems on reactivation.                                                     */
/* Precondition1: vx1000_OldaInit() must have been called successfully.                                                       */
/* Precondition2: The MMU must be programmed such that the source memory and the destination memory are visible.              */
/* Precondition3: The MPU must be programmed such that the source memory is readable and the destination memory is writable.  */
/* Description:   Processes all transfer descriptors assigned to parameter1, copies data from olda buffer to the destinations.*/
/*----------------------------------------------------------------------------------------------------------------------------*/

/*
TODO: use VX1000_SUFFUN() for all function calls and declarations
*/

#include "vx1000_mpc5xxx.h" /* PRQA S 0883*/ /* Actually not violating MISRA Rule 19.15: this file is included only once into this module */

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX)
#include <string.h>  /* Needed for memcpy */
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL, VX1000_MAILBOX */

#if defined(VX1000_MAILBOX_PRINTF)
#include <stdarg.h>
#if !defined(VX1000_PRINTF_MINIMAL)
#include <stdio.h> /* this violates MISRA Rule 20.9, but the user is responsible to turn off printf in production code while the features still are very useful in debug code */
#endif /* !VX1000_PRINTF_MINIMAL */
#endif /* VX1000_MAILBOX_PRINTF */

#if ((VX1000_FILE_VERSION) != 0x020e)
#error "version of vx1000_mpc5xxx.h does not match version of vx1000_mpc5xxx.c!"
#endif

#if defined(VX1000_DISABLE_INSTRUMENTATION)

/* Some compilers (e.g. cosmic) fail creating completly empty object files. Allow the user to provide a workaround: */
VX1000_EMPTYFILE_DUMMYDECL

#else /* !VX1000_DISABLE_INSTRUMENTATION */


/* include userdefined lines with optional section pragmas to force individual linkage of VX1000 code and/or data: */
#define VX1000_SECTION_START_MODULE_C
#include "vx1000_mpc5xxx_cfg.h"
#define VX1000_SECTION_START_MODULE_NEGATE_C


/* --- local prototypes --- */
#if defined(VX1000_STIM_BENCHMARK)
static void vx1000_StimBenchmarkStimCheck( void );
#endif /* VX1000_STIM_BENCHMARK */
#if defined(VX1000_MAILBOX)
#if defined(VX1000_OVERLAY) && !defined(VX1000_COMPILED_FOR_SLAVECORES)
#if !defined(VX1000_INIT_CAL_PAGE)
static void vx1000_InitCalPage( void );
#define VX1000_INIT_CAL_PAGE() vx1000_InitCalPage(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_INIT_CAL_PAGE_INTERNAL
#endif /* !VX1000_INIT_CAL_PAGE */
static VX1000_UINT8 vx1000_MMUWriteTLBEntry(VX1000_UINT8 n, VX1000_UINT32 ea, VX1000_UINT32 ra, VX1000_UINT32 pagesize,
                                     VX1000_UINT8 cache_inhibit, VX1000_UINT8 cache_writethrough, VX1000_UINT8 permissions);
#if !defined(VX1000_GET_CAL_PAGE)
static VX1000_UINT8 vx1000_GetCalPage( VX1000_UINT8 segment, VX1000_UINT8 mode );
#define VX1000_GET_CAL_PAGE(seg, mod) vx1000_GetCalPage((VX1000_UINT8)(seg), (VX1000_UINT8)(mod)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_GET_CAL_PAGE_INTERNAL
#endif /* !VX1000_GET_CAL_PAGE */
#if !defined(VX1000_SET_CAL_PAGE)
static VX1000_UINT8 vx1000_SetCalPage( VX1000_UINT8 segment, VX1000_UINT8 page, VX1000_UINT8 mode );
#define VX1000_SET_CAL_PAGE(seg, pag, mod) vx1000_SetCalPage((VX1000_UINT8)(seg), (VX1000_UINT8)(pag), (VX1000_UINT8)(mod)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_SET_CAL_PAGE_INTERNAL
#endif /* !VX1000_SET_CAL_PAGE */
#if !defined(VX1000_COPY_CAL_PAGE)
static VX1000_UINT8 vx1000_CopyCalPage( VX1000_UINT8 srcSeg, VX1000_UINT8 srcPage, VX1000_UINT8 dstSeg, VX1000_UINT8 dstPage );
#define VX1000_COPY_CAL_PAGE(sseg, spag, dseg, dpag) vx1000_CopyCalPage((VX1000_UINT8)(sseg), (VX1000_UINT8)(spag), (VX1000_UINT8)(dseg), (VX1000_UINT8)(dpag)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to use reconfigurable API wrappers */
#define VX1000_COPY_CAL_PAGE_INTERNAL
#endif /* !VX1000_COPY_CAL_PAGE */
#else /* !VX1000_OVERLAY */
#define VX1000_INIT_CAL_PAGE() /* empty */
#endif /* !VX1000_OVERLAY */
#if defined(VX1000_MAILBOX_PRINTF)
static void vx1000_MailboxPutchar( VX1000_CHAR character );
#endif /* VX1000_MAILBOX_PRINTF */
#endif /* VX1000_MAILBOX */

#if !defined(VX1000_RESET_STIM_TIMEOUT) || !defined(VX1000_CHECK_STIM_TIMEOUT)
static VX1000_UINT32 SetTimeoutUs(VX1000_UINT32 t);
static VX1000_UINT8 CheckTimeout(VX1000_UINT32 timeout);
#endif /* !VX1000_RESET_STIM_TIMEOUT && !VX1000_CHECK_STIM_TIMEOUT */






/* start of obsolete code */

/*----------------------------------------------------------------- */
/* Simple 1Mhz clock using EMIOS */


#if defined(VX1000_CLOCK_TB)  /* only for GNU compiler and a few derivatives! */


VX1000_UINT32 VX1000_Clock( void ) {

#if 0 /* can't reuse library */
   __asm("  mfspr !r3, 284");
   __asm("  stwu !r3,%[result]" : [result] "=" (clock));
#else
   return GetTBL();
#endif
}

void VX1000_ClockInit( void ) {

#if 0 /* can't reuse library */
   __asm("   isync");
   __asm("   mfspr   !r3, 1008");         /* read hardware implementation dependant register 0 */
   __asm("   ori     !r3, !r3, 0x4000");  /* set bit TBEN (time base enable) */
   __asm("   isync");
   __asm("   mtspr   1008, !r3");         /* write HID0 back */
   __asm("   isync");
#else
   InitTB();
#endif
}

#endif


#if defined(VX1000_CLOCK_EMIOS_CHANNEL)

#define vuint32_t volatile VX1000_UINT32
#define uint32_t VX1000_UINT32

struct EMIOS_tag {
   union {
      vuint32_t R;
      struct {
         vuint32_t:1;
         vuint32_t MDIS:1;
         vuint32_t FRZ:1;
         vuint32_t GTBE:1;
         vuint32_t ETB:1;
         vuint32_t GPREN:1;
         vuint32_t:6;
         vuint32_t SRV:4;
         vuint32_t GPRE:8;
         vuint32_t:8;
      } B;
   } MCR;     /* Module Configuration Register */

   union {
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t F23:1;
         vuint32_t F22:1;
         vuint32_t F21:1;
         vuint32_t F20:1;
         vuint32_t F19:1;
         vuint32_t F18:1;
         vuint32_t F17:1;
         vuint32_t F16:1;
         vuint32_t F15:1;
         vuint32_t F14:1;
         vuint32_t F13:1;
         vuint32_t F12:1;
         vuint32_t F11:1;
         vuint32_t F10:1;
         vuint32_t F9:1;
         vuint32_t F8:1;
         vuint32_t F7:1;
         vuint32_t F6:1;
         vuint32_t F5:1;
         vuint32_t F4:1;
         vuint32_t F3:1;
         vuint32_t F2:1;
         vuint32_t F1:1;
         vuint32_t F0:1;
      } B;
   } GFR;     /* Global FLAG Register */

   union {
      vuint32_t R;
      struct {
         vuint32_t:8;
         vuint32_t OU23:1;
         vuint32_t OU22:1;
         vuint32_t OU21:1;
         vuint32_t OU20:1;
         vuint32_t OU19:1;
         vuint32_t OU18:1;
         vuint32_t OU17:1;
         vuint32_t OU16:1;
         vuint32_t OU15:1;
         vuint32_t OU14:1;
         vuint32_t OU13:1;
         vuint32_t OU12:1;
         vuint32_t OU11:1;
         vuint32_t OU10:1;
         vuint32_t OU9:1;
         vuint32_t OU8:1;
         vuint32_t OU7:1;
         vuint32_t OU6:1;
         vuint32_t OU5:1;
         vuint32_t OU4:1;
         vuint32_t OU3:1;
         vuint32_t OU2:1;
         vuint32_t OU1:1;
         vuint32_t OU0:1;
      } B;
   } OUDR;    /* Output Update Disable Register */

   uint32_t emios_reserved[5];

   struct {
      union {
         vuint32_t R;    /* Channel A Data Register */
      } CADR;

      union {
         vuint32_t R;    /* Channel B Data Register */
      } CBDR;

      union {
         vuint32_t R;    /* Channel Counter Register */
      } CCNTR;

      union {
         vuint32_t R;
         struct {
            vuint32_t FREN:1;
            vuint32_t ODIS:1;
            vuint32_t ODISSL:2;
            vuint32_t UCPRE:2;
            vuint32_t UCPREN:1;
            vuint32_t DMA:1;
            vuint32_t:1;
            vuint32_t IF:4;
            vuint32_t FCK:1;
            vuint32_t FEN:1;
            vuint32_t:3;
            vuint32_t FORCMA:1;
            vuint32_t FORCMB:1;
            vuint32_t:1;
            vuint32_t BSL:2;
            vuint32_t EDSEL:1;
            vuint32_t EDPOL:1;
            vuint32_t MODE:7;
         } B;
      } CCR;              /* Channel Control Register */

      union {
         vuint32_t R;
         struct {
            vuint32_t OVR:1;
            vuint32_t:15;
            vuint32_t OVFL:1;
            vuint32_t:12;
            vuint32_t UCIN:1;
            vuint32_t UCOUT:1;
            vuint32_t FLAG:1;
         } B;
      } CSR;              /* Channel Status Register */

      uint32_t emios_channel_reserved[3];
   } CH[24];

};


#define EMIOS (*( struct EMIOS_tag *) 0xC3FA0000)


/* Initialize the clock */
void VX1000_ClockInit( void )
{
   EMIOS.MCR.B.GPRE = 32-1; /* Divide sysclk by 32 is eMIOSclk */
   EMIOS.MCR.B.ETB = 0; /* External time base is disabled; Ch 23 drives ctr bus A*/
   EMIOS.MCR.B.GPREN = 1; /* Enable eMIOS clock */
   EMIOS.MCR.B.GTBE = 1; /* Enable global time base */
   EMIOS.MCR.B.FRZ = 1; /* Enable stopping channels when in debug mode */

   EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CADR.R = 0xFFFFFFFF; /* Period will be full range */
   EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CCR.B.MODE = 0x10; /* Mode is Modulus Counter up, internal clock */
   EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CCR.B.BSL = 0x3; /* Use internal counter */
   EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CCR.B.UCPRE = 0x3; /* Set channel prescaler to divide by 4 */
   EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CCR.B.UCPREN = 1; /* Enable prescaler */
   EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CCR.B.FREN = 1; /* Freeze channel counting when in debug mode*/
}

/* Get the clock */
/* The clock is derived from a a 24 bit counter which is incremented at a rate of 1 MHz. */
/* To obtain a 32 bit clock (e.g. for the measurement tool), the counter value is simply */
/* shifted by 8 bits to the left. Thus the clock is effectively incremented by 256 ticks */
/* per microsecond. */
VX1000_UINT32 VX1000_Clock( void )
{
   return EMIOS.CH[VX1000_CLOCK_EMIOS_CHANNEL].CCNTR.R << 8;
}

#endif

/* end of obsolete code */

 
/*------------------------------------------------------------------------------- */
/* VX1000 initialization */

/* Initialize the global data */
/* Must be called before any other VX1000_XXXX routine is called */
void vx1000_Init(void)
{
#if defined(VX1000_CLOCK_TB) /* obsolete code */
   VX1000_ClockInit(); /* TB has to be initialised per core - synchronosation not implemented, yet! */
#endif

#if !defined(VX1000_COMPILED_FOR_SLAVECORES)
#if defined(VX1000_RUNNING_ON_MAINCORE)
   if (VX1000_RUNNING_ON_MAINCORE()) /* always true on singlecore MCU otherwise "(mfPIR() == 0)" (compiler specific assembly) */
#endif /* VX1000_RUNNING_ON_MAINCORE */
   {
#if defined(VX1000_CLOCK_EMIOS_CHANNEL) /* obsolete code */
      VX1000_ClockInit(); /* EMIOS only to be initialised from main core */
#endif
      /* Initialize the gVX1000 data structure   */
      VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
      /* VX1000_STORE_EVENT(0) -- Eventnumber is not touched, to be sure no event is triggered */
      gVX1000.Version = VX1000_STRUCT_VERSION; /* note: bits 8..31 are checked by old FW versions to be 0x000000 */
      gVX1000.GetIdPtr = VX1000_ECUID_PTR; /* PRQA S 0311 */ /* GetIdPtr is never used for writing, so MISRA Rule 11.5 is not relevant here */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because this integer variable either contains a pointer to an actual object or the an integral magig number for "invalid" */  /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
      gVX1000.GetIdLen = VX1000_ECUID_LEN;
      gVX1000.XcpMailboxPtr = VX1000_MAILBOX_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
      gVX1000.StimCtrlPtr = VX1000_STIM_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
      gVX1000.RamSynchField = 0;
      gVX1000.ToolDetectState = 0;
      gVX1000.OldaPtr = VX1000_OLDA_PTR; /* PRQA S 0303 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
      gVX1000.OldaEventNumber = 0;
      gVX1000.CalPtr = 0;
      gVX1000.ToolCtrlState = 0;
    /*gVX1000.res6 = 0;
      gVX1000.res7 = 0;  -- replced in v8 by TimestampInfo and VersionInfo: */

#if 0  /* start of dead code - we'll use another, yet to be defined method to store the info ... */    
      /* ASAM/XCP timestamp info: bits 0..15: TIMESTAMP_TICKS (per UNIT), 16..18: TIMESTAMP_MODE.SIZE (always 4 with VX), /
      /  19: TIMESTAMP_MODE.FIXED (always on with VX), 20..23: TIMESTAMP_MODE.UNIT , 24..31: currently reserved (0x00)   */
#if   ((VX1000_CLOCK_TICKS_PER_MS) <= 65UL )
      gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_S)          ) | (0x009c0000UL)); /* [s] */
#elif ((VX1000_CLOCK_TICKS_PER_MS) <= 0xFFFFUL )
      gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_MS)         ) | (0x006c0000UL)); /* [ms] */
#elif ((VX1000_CLOCK_TICKS_PER_US) <= 0xFFFFUL )
      gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_US)         ) | (0x003c0000UL)); /* [us] */
#else
      gVX1000.TimestampInfo = (VX1000_UINT32)(((VX1000_CLOCK_TICKS_PER_US) / 1000UL) | (0x000c0000UL)); /* [ns] */
#endif
       
      gVX1000.VersionInfo = (VX1000_UINT32)((((VX1000_FILE_VERSION) >> 8) & 0xffUL) | (((VX1000_FILE_VERSION) & 0xffUL) << 8));  /* bits 0..7: instrumentation files' major version, 8..15: minor version, 16..31: reserved (for status, patch version -> currently 0x0000) */
#endif /* endof dead code */      
      
      VX1000_OLDA_INIT()
      VX1000_MAILBOX_INIT()

#if defined(VX1000_STIM)
      VX1000_STIM_INIT()
      gVX1000.Stim.TimeoutCtr = 0;
      gVX1000.Stim.TimeoutCtr2 = 0;
      VX1000_STIM_BENCHMARK_INIT()
#endif /* VX1000_STIM */
      VX1000_HOOK_INIT()

#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_OVERLAY_CONTROL)
      VX1000_INIT_CAL_PAGE()
#endif /* VX1000_MAILBOX && VX1000_MAILBOX_OVERLAY_CONTROL */


      /* optional: structuresizetest feature */


      gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_INIT;
      gVX1000.MagicId = (VX1000_UINT32)VX1000_STRUCT_MAGIC;

      VX1000_DETECT_VX_VOID()

      VX1000_SPECIAL_EVENT(VX1000_EVENT_STRUCT_INIT)
   }
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */

   /* optional: VX1000_BreakpointInit(); /-* has to be performed per core */
   
}


/*------------------------------------------------------------------------------- */
/* Tool detection */

#if defined(VX1000_DETECTION)

#if defined(VX1000_COLDSTART_CALIBRATION)

static VX1000_UINT32 calcAdd32(VX1000_UINT32 addr, VX1000_UINT32 bytes); /* todo: move up */
static VX1000_UINT32 calcAdd32(VX1000_UINT32 addr, VX1000_UINT32 bytes)  /* todo: shall this be used anywhere else? Otherwise why not inlining the few lines into vx1000_CalcFlashChecksum()? */
{
   VX1000_UINT32 sum32 = 0;
#if 0 /* todo: this is just a MISRA compliant but functional inequivalent idea for profiling vs. the #else-code below. Must not be used! */
   VX1000_UINT32 k, *data = (VX1000_UINT32 *)addr; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
   for (k = 0; k <= bytes; k += 4UL * 8UL)
   {
      sum32 += data[0] + data[1] + data[2] + data[3] + data[4] + data[5] + data[6] + data[7];
      data = &data[8];
   }
#else
   VX1000_UINT32 *p, *pl;

   /* Don't change this \/ \/ \/ code, before you are sure that runtime will not be affected !! (note: 18 MISRA violations in this block!) */
   p  = (VX1000_UINT32 *)addr;
   pl = (VX1000_UINT32 *)(addr+bytes);
   do
   {
      sum32 += *p++;
      sum32 += *p++;
      sum32 += *p++;
      sum32 += *p++;
      sum32 += *p++;
      sum32 += *p++;
      sum32 += *p++;
      sum32 += *p++;
   } while (p < pl);
   /* Don't change this /\ /\ /\ code, before you are sure that runtime will not be affected !! */
#endif
   return sum32;
}

/*todo: add check for existence && NZ of the defines and then move everything into the consistency check section in the header*/
#if (VX1000_OLDA_MEMORY_SIZE) < (((VX1000_COLDSTART_FLASH_SIZE) / (VX1000_COLDSTART_CHS_BLOCK_SIZE)) + 4) * 4
#error "VX1000_MEMORY_SIZE too small for FLASH checksum array"
#endif /* VX1000_OLDA_MEMORY_SIZE < ... */
#if ((VX1000_COLDSTART_FLASH_SIZE) % (VX1000_COLDSTART_CHS_BLOCK_SIZE)) != 0
#error "VX1000_COLDSTART_FLASH_SIZE % VX1000_COLDSTART_CHS_BLOCK_SIZE != 0"
#endif /* VX1000_COLDSTART_FLASH_SIZE % VX1000_COLDSTART_CHS_BLOCK_SIZE */

/* todo: add the used global variables to the end of this module plus to the header plus add VX1000_COLDSTART_CHECKSUM_MAGIC */
extern void vx1000_CalcFlashChecksum( void ); /* todo: move to header */
void vx1000_CalcFlashChecksum( void )
{
   VX1000_UINT32 a;
   VX1000_UINT32 i, *p;

   p = (VX1000_UINT32*)gVX1000.Olda.MemoryAddr; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
   p[0] = (VX1000_UINT32)(VX1000_COLDSTART_CHS_MAGIC);
   p[1] = (VX1000_UINT32)(VX1000_COLDSTART_FLASH_ADDR);
   p[2] = (VX1000_UINT32)(VX1000_COLDSTART_FLASH_SIZE);
   p[3] = (VX1000_UINT32)(VX1000_COLDSTART_CHS_BLOCK_SIZE);
   p = (VX1000_UINT32*)&gVX1000.Olda.Data[4];
   a = (VX1000_UINT32)(VX1000_COLDSTART_FLASH_ADDR);
   for (i = 0; i < ((VX1000_COLDSTART_FLASH_SIZE) / (VX1000_COLDSTART_CHS_BLOCK_SIZE)); i++)
   {
      p[i] = calcAdd32(a, (VX1000_COLDSTART_CHS_BLOCK_SIZE));
      a += VX1000_COLDSTART_CHS_BLOCK_SIZE;
   }
}

#endif /* VX1000_COLDSTART_CALIBRATION */

/* Detect, if a VX1000 is connected */
/* Delay for coldstart measurement setup, if required by tool */
/* Returns VX1000_TDS_DETECTED if detected */
VX1000_UINT8 vx1000_DetectVx( void )
{
   VX1000_UINT32 startTime;

   /* Check if 1st call after reset */
   if (0==(gVX1000.ToolDetectState & ((VX1000_UINT32)VX1000_TDS_DETECT)))
   {
      VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
      gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_DETECT;
      startTime = gVX1000.EventTimestamp;

#if defined(VX1000_COLDSTART_BENCHMARK)
      gVX1000_DETECT_StartTime = startTime;
      gVX1000_DETECT_ToolDetectTime = 0;
      gVX1000_DETECT_ChecksumDoneTime = 0;
      gVX1000_DETECT_EndTime = 0;
#endif /* VX1000_COLDSTART_BENCHMARK */

      /* Wait some time for tool presence indication, when ECU was reset, the tool may need some time to react */
      /* Check timeout VX1000_DETECTION_TIMEOUT_US */
      /* At 1 MHz Nexus Clock 1,5ms were measured in the NIOS until VX1000_TCS_PRESENT was written to */
      /* ToolCtrlState after a reset had been detected. */
      do
      {
         /* Check tool presence */
         if ((gVX1000.ToolCtrlState & (VX1000_TCS_PRESENT)) != 0)
         {
            /* Acknowledge tool detect */
            gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_DETECTED;

#if defined(VX1000_COLDSTART_BENCHMARK)
            gVX1000_DETECT_ToolDetectTime = gVX1000.EventTimestamp;
#endif /* VX1000_COLDSTART_BENCHMARK */

            /* If tool has requested a coldstart, wait until the sequence has completed initializations */
            /* Check timeout VX1000_COLDSTART_TIMEOUT_MS */
            if ((gVX1000.ToolCtrlState & ((VX1000_UINT32)VX1000_TCS_COLDSTART_DELAY)) != 0)
            {
               gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_COLDSTART_DELAY;

               /* Calculate checksums over the calibration areas and store in Olda mmemory */
               /* VX1000 may use this to optimize calibration download */
#if defined(VX1000_COLDSTART_CALIBRATION)
               gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_COLDSTART_CHS_BUSY;
               vx1000_CalcFlashChecksum();
               gVX1000.ToolDetectState |= (VX1000_UINT32)VX1000_TDS_COLDSTART_CHS_DONE;
#if defined(VX1000_COLDSTART_BENCHMARK)
               gVX1000_DETECT_ChecksumDoneTime = VX1000_CLOCK();  /* here, gVX1000.EventTimestamp is outdated */
#endif /* VX1000_COLDSTART_BENCHMARK */
#endif /* VX1000_COLDSTART_CALIBRATION */

               for (gVX1000.ToolDetectState &= (VX1000_UINT32)~((VX1000_TDS_COLDSTART_DONE) | (VX1000_TDS_COLDSTART_TIMEOUT));
               0 != (gVX1000.ToolDetectState & (VX1000_UINT32) ((VX1000_TDS_COLDSTART_DONE) | (VX1000_TDS_COLDSTART_TIMEOUT)));)
               {
                  if ((gVX1000.EventTimestamp - startTime) >= ((VX1000_COLDSTART_TIMEOUT_MS) * (VX1000_CLOCK_TICKS_PER_MS)))
                  {
                     /* Timeout acknowledge */
                     gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_COLDSTART_TIMEOUT);
                  }
                  if ((gVX1000.ToolCtrlState & ((VX1000_UINT32)(VX1000_TCS_COLDSTART_DONE))) != 0)
                  {
                     /* Init acknowledge */
                     gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_COLDSTART_DONE);
                  }
                  VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
               } /* for(;;) */
            }
            break; /* note: this "early-out"-break can be removed safely if constant runtime is preferred */
         } /* Tool present */
         VX1000_STORE_TIMESTAMP(VX1000_CLOCK())
      } while ((gVX1000.EventTimestamp - startTime) < ((VX1000_DETECTION_TIMEOUT_US) * (VX1000_CLOCK_TICKS_PER_US)));

#if defined(VX1000_COLDSTART_BENCHMARK)
      gVX1000_DETECT_EndTime = VX1000_CLOCK();  /* here, gVX1000.EventTimestamp may be outdated (break's path) */
#endif /* VX1000_COLDSTART_BENCHMARK */
   } /* 1st call */
   else
   {
      /* Check if the VX is connected and update the state */
      if ((gVX1000.ToolCtrlState & ((VX1000_UINT32)(VX1000_TCS_PRESENT))) != 0)
      {
         /* VX1000 connected */
         gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_DETECTED);
      }
      else
      {
         gVX1000.ToolDetectState &= (VX1000_UINT32)~(VX1000_TDS_DETECTED);
      }
   }
#if defined(VX1000_DETECT_XCP)
   /* Check whether there is a XCP on CAN connected and disable VX OLDA in that case */
   if ((xcp.SessionStatus & (SS_CONNECTED)) != 0)
   {
      /* XCP connected */
      gVX1000.Olda.MagicId = 0; /* Disable OLDA */
   }
   else
   {
      gVX1000.Olda.MagicId = VX1000_OLDA_MAGIC; /* Reenable OLDA */
   }
#endif /* VX1000_DETECT_XCP */

   return (VX1000_UINT8)(gVX1000.ToolDetectState & (VX1000_UINT32)(VX1000_TDS_DETECTED));
}
#endif /* VX1000_DETECTION */



/*------------------------------------------------------------------------------- */
/* Breakpoint triggered actions */

/* optional: breakpoint externals and implementation */



/*------------------------------------------------------------------------------- */
/* Measurement data acquisition */

/* Copy routine */
/* Event number is limited to 0..30, event number 31 is reserved, >= 32 is not possible  */
/* Address must be dword aligned */

#if defined(VX1000_OLDA)

/* Initialize the olda data structure  */
void vx1000_OldaInit( void )
{
   gVX1000.Olda.Version = VX1000_OLDA_VERSION;
   gVX1000.Olda.Running = 0;
#if !defined(VX1000_OLDA_MEMORY_ADDR)
   gVX1000.Olda.MemoryAddr = (VX1000_UINT32)&gVX1000.Olda.Data[0]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
#else /* VX1000_OLDA_MEMORY_ADDR */
   gVX1000.Olda.MemoryAddr = VX1000_OLDA_MEMORY_ADDR;
#endif /* VX1000_OLDA_MEMORY_ADDR */
   gVX1000.Olda.MemorySize = VX1000_OLDA_MEMORY_SIZE;
   gVX1000.Olda.EventCount = 0;
   gVX1000.Olda.EventList = 0;
   gVX1000.Olda.TransferList = 0;
   gVX1000.Olda.SizeLengthNOffset = (VX1000_OLDA_SIZE_OFFSET) | ((VX1000_OLDA_SIZE_LENGTH) << 5);
   gVX1000.Olda.SizeSwapValue = VX1000_OLDA_SIZE_SWAP_VALUE;
   gVX1000.Olda.OldaFeatures = (VX1000_FEAT_OLDA_STIM)
                             | (VX1000_FEAT_OLDA_OVERLOADDETECT);
   gVX1000.Olda.Res1 = 0;
   gVX1000.Olda.Res2 = 0;

#if defined(VX1000_OLDA_BENCHMARK)
   {
      VX1000_UINT32 i;
      for (i = 0; i < VX1000_OLDA_EVENT_COUNT; i++) { gVX1000_OLDA_Duration[i] = 0; }
   }
#endif /* VX1000_OLDA_BENCHMARK */

   gVX1000.Olda.MagicId = VX1000_OLDA_MAGIC;
}


/* Trigger OLDA event (Copy routine) */
void vx1000_OldaEvent( VX1000_UINT8 eventNumber )
{
   VX1000_UINT8 size;
   VX1000_UINT32 *src = 0; /* note: few compilers warn about unused initialisation but more would warn if it was missing */ /* PRQA S 3197 */
   VX1000_UINT32 *dst;
   VX1000_UINT16 i, n;
   VX1000_OLDA_EVENT_T *event;
#if defined(VX1000_OLDA_FORCE_V7)
   VX1000_UINT32 j, sizeList;
#endif /* VX1000_OLDA_FORCE_V7 */

   /* Take the timestamp first to have maximum precision */
   /* This timestamp will be needed for data trace as well */
   VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))

   if ((gVX1000.Olda.Running == 1) && (gVX1000.Olda.MagicId == VX1000_OLDA_MAGIC))
   {
      /* OLDA is running */
      if (! (eventNumber >= gVX1000.Olda.EventCount) )
      {
         /* the eventNumer is valid */
         event = &gVX1000.Olda.EventList[eventNumber];
         n = event->TransferCount;
#if defined(VX1000_OLDA_BENCHMARK)
         gVX1000_OLDA_TransferSize[eventNumber]  = 0; /* Size of all transfers */
         gVX1000_OLDA_TransferCount[eventNumber] = n; /* Count of the tranfers */
#endif /* VX1000_OLDA_BENCHMARK */

         if (! (0==n) )
         {
            /* eventNumber is active, there's data to be copied */

            /* Take an individual copy of the timestamp for each event, gVX1000.EventTimestamp mustn't have changed meanwhile */
            event->EventTimestamp = gVX1000.EventTimestamp;
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
            /* Increase the Event-Counter to detect Overruns */
            event->EventCounter++;
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */

            /* Copy data to an intermediate location */
            i = event->TransferIndex;
            dst = (VX1000_UINT32*)event->TransferDest; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
            while (n > 0)
            {
               n--;
               src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
               i++;
#if defined(VX1000_OLDA_FORCE_V7)
               size = (VX1000_UINT8)((VX1000_UINT32)src & 0x00000003UL); /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 to avoid recomputation of integer bits already being present in the pointer variable */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
               if ( 0==size )
               {
                  /* TransferList entry consists of up to 5 transfer sizes [31..2] and size list identifier [1..0]==0 */
                  sizeList = (VX1000_UINT32)src >> 2; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 to avoid recomputation of integer bits already being present in the pointer variable */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
                  n++; /* undo decrement of remaining transfers because size list entry isn't a transfer */
                  for (j = 0; (j < 5) && (n > 0); j++)
                  {
                     size = (VX1000_UINT8)(sizeList & 0x3FUL);
                     sizeList >>= 6U;
                     n--;
                     src = (VX1000_UINT32*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
                     i++;
#if defined(VX1000_OLDA_BENCHMARK)
                     gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers */
#endif /* VX1000_OLDA_BENCHMARK */
                     while (size != 0)
                     {
                        *dst = *src;
                        dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                        src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                        size--;
                     } /* while size */
                  }
               }
               else
               {
                  /* TransferList entry consists of source address [31..2] and transfer size [1..0] in 32-bit-words */
                  src = (VX1000_UINT32*)((VX1000_UINT32)src ^ size); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
#if defined(VX1000_OLDA_BENCHMARK)
                  gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers */
#endif /* VX1000_OLDA_BENCHMARK */
                  while (size != 0)
                  {
                     *dst = *src;
                     dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                     src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                     size--;
                  } /* while size */
               }
#else /* !VX1000_OLDA_FORCE_V7 */
               size = (VX1000_UINT8)(((VX1000_UINT32)src >> 22U) & 0x3fUL); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
               src = (VX1000_UINT32*)((VX1000_UINT32)src & 0xF03FFFFFUL); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#if defined(VX1000_OLDA_BENCHMARK)
               gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers */
#endif /* VX1000_OLDA_BENCHMARK */
               while (size != 0)
               {
                  *dst = *src;
                  dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  size--;
               } /* while size */
#endif /* !VX1000_OLDA_FORCE_V7 */
            } /* while n*/
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
            /* Increase the Event-Counter to detect Overruns */
            event->EventCounter++;
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */

            /* Trigger the VX1000 to copy the data */
            VX1000_ENTER_SPINLOCK()
            gVX1000.OldaEventNumber ^= (VX1000_UINT32)(1UL << eventNumber);
            VX1000_LEAVE_SPINLOCK()
         } /* if n */
      } /* if eventNumber */
#if defined(VX1000_OLDA_BENCHMARK)
      /* Timing measurement */
      gVX1000_OLDA_Duration[eventNumber] = (VX1000_CLOCK()) - gVX1000.EventTimestamp;
#endif /* VX1000_OLDA_BENCHMARK */
   } /* if OLDA */

   /* Trigger a trace event */
   VX1000_STORE_EVENT(eventNumber) /* Had been removed due to EM00034754 but was readded due to EM00035042 */
   return;
}

#if defined(VX1000_STIM_BY_OLDA)

/* Trigger an STIM request event */
/* A STIM request is not associated to DAQ data, it is associated to STIM data */
void vx1000_OldaStimRequestEvent( VX1000_UINT8 eventNumber )
{
   VX1000_OLDA_EVENT_T *event;

   VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))

   if ((gVX1000.Olda.Running == 1) && (gVX1000.Olda.MagicId == VX1000_OLDA_MAGIC))
   {
      /* OLDA is running */
      if (eventNumber < gVX1000.Olda.EventCount)
      {
         /* eventNumer is valid */
         event = &gVX1000.Olda.EventList[eventNumber];

         /* Take an individual copy of the timestamp for each event */
         event->EventTimestamp = gVX1000.EventTimestamp;
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
         /* Increase the Event-Counter by two for Overrun detection */
         event->EventCounter += 2;
#endif /* VX1000_OLDA_OVERLOAD_DETECTION */

         /* Trigger the VX1000 to copy the data */
         VX1000_ENTER_SPINLOCK()
         gVX1000.OldaEventNumber ^= (VX1000_UINT32)(1UL << eventNumber);
         VX1000_LEAVE_SPINLOCK()
      }
   }
   VX1000_STORE_EVENT(eventNumber)
}


#endif /* VX1000_STIM_BY_OLDA */

#endif /* VX1000_OLDA */



/*------------------------------------------------------------------------------- */
/* Bypassing */

#if defined(VX1000_STIM)

#if defined(VX1000_STIM_BY_OLDA)
/* copy OLDA STIM data */
static void vx1000_StimTransfer( VX1000_UINT8 eventNumber );
static void vx1000_StimTransfer( VX1000_UINT8 eventNumber )
{
   VX1000_UINT8 size;
   VX1000_UINT8 *src;
   VX1000_UINT8 *dst;
   VX1000_UINT16 i, n;
   VX1000_OLDA_EVENT_T *event;
#if defined(VX1000_OLDA_FORCE_V7)
   VX1000_UINT32 j = 0, sizeList = 0; /* sizeList dummy initialisation to avoid compiler warnings */
#endif /* VX1000_OLDA_FORCE_V7 */
#if defined(VX1000_OLDA_BENCHMARK) /* Timing measurement */
   VX1000_UINT32 t0;

   t0 = VX1000_CLOCK();
#endif /* VX1000_OLDA_BENCHMARK */
   if ((gVX1000.Olda.Running == 1) && (gVX1000.Olda.MagicId == VX1000_OLDA_MAGIC))
   {
      /* OLDA is running */
      if (eventNumber < gVX1000.Olda.EventCount)
      {
         /* eventNumer is valid */
         event = &gVX1000.Olda.EventList[eventNumber];
         src = (VX1000_UINT8*)event->TransferDest; /* yes: src is loaded from dst entry for stim */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
         n = event->TransferCount;
#if defined(VX1000_OLDA_BENCHMARK)
         gVX1000_OLDA_TransferSize[eventNumber]  = 0; /* Size of all transfers */
         gVX1000_OLDA_TransferCount[eventNumber] = n; /* Count of the tranfers */
#endif /* VX1000_OLDA_BENCHMARK */
         for (i = event->TransferIndex; (i == i) && (n > 0); i++) /* yes: check n, not i */
         {
            /* eventNumber is active: data is to be copied */
#if defined(VX1000_OLDA_FORCE_V7)
            /* TransferList entry consists of up to 4 transfer sizes, followed by up to 4 pure transfer address entries */
            if (j==0)
            {
               j = 4;
               sizeList = gVX1000.Olda.TransferList[i];
            }
            else
            {
               j--;
               dst = (VX1000_UINT8*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
               size = (VX1000_UINT8)(sizeList & 0x000000FFUL); /* copy 0..255 bytes (this differs from DAQ which uses words) */
               sizeList >>= 8U;
#else /* !VX1000_OLDA_FORCE_V7 */
            /* TransferList entry contains merged size and address information for exactly one transfer */
            {
               dst = (VX1000_UINT8*)gVX1000.Olda.TransferList[i]; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
               size = (VX1000_UINT8)(((VX1000_UINT32)dst >> 22U) & 0x3FUL); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
               dst = (VX1000_UINT8*)((VX1000_UINT32)dst & 0xF03FFFFFUL); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because pointers are transferred compressed and decompression uses integer operations */
#endif /* !VX1000_OLDA_FORCE_V7 */
#if defined(VX1000_OLDA_BENCHMARK)
               gVX1000_OLDA_TransferSize[eventNumber] += size; /* Size of all transfers */
#endif /* VX1000_OLDA_BENCHMARK */
               while (size != 0)
               {
                  *dst = *src;
                  dst++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  src++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  size--;
               } /* while size */
               n--;
            }
         } /* for */
      }
#if defined(VX1000_OLDA_BENCHMARK)
      gVX1000_OLDA_Duration[eventNumber] = (VX1000_CLOCK()) - t0; /* Timing measurement */
#endif /* VX1000_OLDA_BENCHMARK */
   }
   return;
}
#endif /* VX1000_STIM_BY_OLDA */

#if (0==(VX1000_STIM_EVENT_OFFSET))
#define VX1000_IS_STIM_EVENT(e)  ((e) < ((VX1000_STIM_EVENT_OFFSET) + (VX1000_STIM_EVENT_COUNT))) /* PRQA S 3453 */ /* willingsly violating MISRA Rule 19.7 because calling a function instead of executing a single machine instruction is far too inefficient for realtime applications */
#else /* VX1000_STIM_EVENT_OFFSET */
#define VX1000_IS_STIM_EVENT(e)  (((e) >= VX1000_STIM_EVENT_OFFSET) && \
                                  ((e) < ((VX1000_STIM_EVENT_OFFSET) + (VX1000_STIM_EVENT_COUNT))))
#endif /* VX1000_STIM_EVENT_OFFSET */


#if !defined(VX1000_RESET_STIM_TIMEOUT) || !defined(VX1000_CHECK_STIM_TIMEOUT)

static VX1000_UINT32 SetTimeoutUs(VX1000_UINT32 t)
{
   return (VX1000_CLOCK()) + (t * (VX1000_CLOCK_TICKS_PER_US));
}

static VX1000_UINT8 CheckTimeout(VX1000_UINT32 timeout)
{
   VX1000_UINT8 retVal = 0;  /* "no timeout, yet" */
   if (((timeout - (VX1000_CLOCK())) & 0x80000000UL) != 0) { retVal = 1; }
   return retVal;
}

/* todo MISRA: the next line violates(?) the "C macros shall only expand to a braced initialised, a constant, a   /
/  parenthesised expression, a type qualifier, a storage class specifier, or a do-while-zero construct."-rule!    /
/  Embracing it or wrapping into do-while-zero however did not make the qac message vanish. So check why we need  /
/  this user-redefinable macro at all or whether we can manually expand it in the code                           */
#define VX1000_RESET_STIM_TIMEOUT(x) gVX1000_timeout = SetTimeoutUs((VX1000_UINT32)(x)); 
#define VX1000_CHECK_STIM_TIMEOUT() CheckTimeout(gVX1000_timeout) /* Return true if timeout */

#endif /* !VX1000_RESET_STIM_TIMEOUT && !VX1000_CHECK_STIM_TIMEOUT */



/* Initialize the STIM data structure */
/* Called once in VX1000_INIT and everytime STIM is turned off */
void vx1000_StimInit(void)
{
   VX1000_UINT32 i;

   gVX1000.Stim.Version = 0;
   gVX1000.Stim.Control = 0;
   gVX1000.Stim.EvtOffset = VX1000_STIM_EVENT_OFFSET;
   gVX1000.Stim.EvtNumber = VX1000_STIM_EVENT_COUNT;
   for (i = 0; i < VX1000_STIM_EVENT_COUNT; i++)
   {
      gVX1000.Stim.Event[i].Ctr = 0;
      gVX1000.Stim.Event[i].RqCtr = 0;
      gVX1000.Stim.Event[i].Enable = 0;
#if !defined(VX1000_STIM_BY_OLDA)
      gVX1000.Stim.Event[i].Copying = 0;
#endif /* !VX1000_STIM_BY_OLDA */
   }
   gVX1000.Stim.Enable = 0;
   gVX1000.Stim.MagicId = (VX1000_UINT32)(VX1000_STIM_MAGIC);
}


#if defined(VX1000_STIM_BENCHMARK)

/* Init the STIM benchmark data */
void vx1000_StimBenchmarkInit( void )
{
   VX1000_UINT32 i;

   for (i = 0; i < VX1000_STIM_EVENT_COUNT; i++)
   {
      gVX1000_STIM_Begin[i] = 0;
      gVX1000_STIM_Duration[i] = 0;
   }

#if defined(VX1000_STIM_HISTOGRAM)
   for (i = 0; i < 256; i++) { gVX1000_STIM_Histogram[i] = 0; }
   for (i = 0; i < 16; i++) { gVX1000_STIM_Histogram2[i] = 0; }
#endif /* VX1000_STIM_HISTOGRAM */
}


/* Start benchmark timer */
void vx1000_StimBenchmarkStimBegin( VX1000_UINT8 stim_event )
{
   gVX1000_STIM_Begin[stim_event - (VX1000_STIM_EVENT_OFFSET)] = VX1000_CLOCK(); /* Timing measurement */
}

/* Stop benchmark timer */
void vx1000_StimBenchmarkStimEnd( VX1000_UINT8 stim_event, VX1000_UINT8 timeout_flag )
{
   VX1000_UINT32 t0,t1,dt;

   t0 = gVX1000_STIM_Begin[stim_event - (VX1000_STIM_EVENT_OFFSET)];
   if (t0 != 0)
   {
      gVX1000_STIM_Begin[stim_event - (VX1000_STIM_EVENT_OFFSET)] = 0;
      t1 = VX1000_CLOCK();
      dt =  t1 - t0;
      gVX1000_STIM_Duration[stim_event - (VX1000_STIM_EVENT_OFFSET)] = dt; /* Last delay for each individual event */

      /* Build the histograms for event VX1000_STIM_HISTOGRAM */
#if defined(VX1000_STIM_HISTOGRAM)
      if (stim_event == (VX1000_STIM_HISTOGRAM))
      {
         gVX1000_STIM_Histogram2[0]++; /* Index 0 is the cycles with 0 timeouts counter ! */

         if (!timeout_flag)
         {
            /* Build the delay histogram */
            /* 20us resolution, 0..5100us:     */
            t0 = (VX1000_UINT32)(dt / ((VX1000_CLOCK_TICKS_PER_MS) / 50UL));
            if (t0 >= 256) { t0 = 255; }
            gVX1000_STIM_Histogram[t0]++;
         }
         else
         {
            /* Build the timeout burst count histogram */
            /* 0..15 */
            t0 = gVX1000.Stim.TimeoutCtr2;
            if (t0 <= 15)
            {
               gVX1000_STIM_Histogram2[t0]++;
               gVX1000_STIM_Histogram2[t0-1]--; /* t0 is always >0 when timeout_flag is set */
            }
         }
      }
#else /* !VX1000_STIM_HISTOGRAM */
      timeout_flag = timeout_flag; /* dummy access to prevent compiler warning */
#endif /* !VX1000_STIM_HISTOGRAM */
   }
}

/* Check benchmark timer */
static void vx1000_StimBenchmarkStimCheck( void )
{
#if defined(VX1000_STIM_HISTOGRAM)
   if (VX1000_STIM_ACTIVE(VX1000_STIM_HISTOGRAM) != 0)
   {
      if ((gVX1000.Stim.Event[(VX1000_STIM_HISTOGRAM) - (VX1000_STIM_EVENT_OFFSET)].Ctr)
      ==  (gVX1000.Stim.Event[(VX1000_STIM_HISTOGRAM) - (VX1000_STIM_EVENT_OFFSET)].RqCtr))
      {
         VX1000_STIM_BENCHMARK_STIM_END(VX1000_STIM_HISTOGRAM, 0)
      }
   }
#endif /* VX1000_STIM_HISTOGRAM */
}


#endif /* VX1000_STIM_BENCHMARK */

/* Keep-Alive-Handler (to be called cyclic by the application)*/
void vx1000_StimControl(void)
{
   if ((gVX1000.Stim.Control != 0) && (0==gVX1000.Stim.Enable))
   {
      /* Reset state of generic bypassing -- the code is a little bit misplaced, isn't it ... */
#if defined(VX1000_HOOK_ENABLE)
      gVX1000_HookControl.active_index = VX1000_HOOK_COUNT;
      gVX1000_HookControl.active_id = 0xFFFFU;
#endif /* VX1000_HOOK_ENABLE */

      /* Clear benchmark data */
      VX1000_STIM_BENCHMARK_INIT()

      gVX1000.Stim.TimeoutCtr = 0;
      gVX1000.Stim.TimeoutCtr2 = 0;

#if defined(VX1000_STIM_TYPE_0)
      VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ACK) /* Send an acknowledge STIM event when the ECU is ready for STIM  */
#endif /* VX1000_STIM_TYPE_0 */

      gVX1000.Stim.Enable = 1;
   }
   else
   {
      /* Reinitialize STIM when VX1000 turns STIM off */
      if ((0==gVX1000.Stim.Control) && (gVX1000.Stim.Enable == 1)) { VX1000_STIM_INIT() }
   }

#if defined(VX1000_STIM_BENCHMARK)
   /* STIM Benchmark: Specific measurements for a single event from request to acknowledge */
   vx1000_StimBenchmarkStimCheck();
#endif /* VX1000_STIM_BENCHMARK */
}


/* Stim Active Check */
VX1000_UINT8 vx1000_StimActive( VX1000_UINT8 stim_event )
{
   VX1000_UINT8 retVal = 0;  /* "inactive" */
   if ((gVX1000.Stim.Control != 0) && (gVX1000.Stim.Enable  != 0) && (VX1000_IS_STIM_EVENT(stim_event))
   && (gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].Enable != 0))
   {
      retVal = 1;  /* "active" */
   }
   return retVal;
}


/* Request a specific STIM data set assciated to event stim_event */
void vx1000_StimRequest( VX1000_UINT8 stim_event )
{
   VX1000_STIM_BENCHMARK_STIM_BEGIN(stim_event)

   gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr++;
   VX1000_STIM_REQUEST_EVENT(stim_event)
}


/* Wait until a specific STIM request is fullfilled */
/* Timeout specified in [us], the time relates to a previous call of VX1000_STIM_REQUEST() */
/* Return 1 in case of timeout */
VX1000_UINT8 vx1000_StimWait( VX1000_UINT8 stim_event, VX1000_UINT8 copy_enable, VX1000_UINT32 timeout_us )
{
   VX1000_UINT8 errorcode = 0U;
   static volatile VX1000_UINT32 gVX1000_timeout; /* can be per core and static */

   VX1000_RESET_STIM_TIMEOUT(timeout_us)
   while ( (0==errorcode) /* Busy wait with timeout until direct stimulation is done (or olda stimulation data arrived) */
   && (gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].Ctr
   !=  gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr) )
   {
      /* Power PC 5xxx respectively e200 NEXUS Class 3 specific: */
      /* Update the timestamp in the VX parameter structure while waiting */
      /* for the STIM data. Thus stuck Nexus trace data will be flushed.  */
      VX1000_TIMESTAMP_UPDATE(VX1000_CLOCK())
      
      if ((VX1000_CHECK_STIM_TIMEOUT()) != 0)
      {
#if !defined(VX1000_STIM_BY_OLDA)
         if (gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].Copying != 0)
         {
            /* If timeout happened, but copying data has already started,   */
            /* give a second chance to complete within the next milisecond: */
            VX1000_RESET_STIM_TIMEOUT(1000U)
            while (0==errorcode)
            {
               if (gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].Ctr
               ==  gVX1000.Stim.Event[stim_event - (VX1000_STIM_EVENT_OFFSET)].RqCtr)
               {
                  errorcode = 1; /* timeout, but new data already valid */
               }
               else if (VX1000_CHECK_STIM_TIMEOUT())
               {
                  VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_ERR(stim_event))
                  errorcode = 2; /* timeout, data incomplete */
               }
            }
         }
         else
#endif /* !VX1000_STIM_BY_OLDA */
         {
            if ((VX1000_STIM_ACTIVE(stim_event)) != 0) { VX1000_SPECIAL_EVENT(VX1000_EVENT_STIM_TIMEOUT(stim_event)) }
            errorcode = 2; /* timeout, no new data */
         }
      } /* Timeout */
   } /* while */
   
   if (errorcode == 2) /* Timeout (no new valid data) --> increment timeout counter and timeout burst counter */
   {
      gVX1000.Stim.TimeoutCtr++;
      gVX1000.Stim.TimeoutCtr2++;
   }
   else /* either no timeout at all or timeout, but still all data arrived successfully */
   {
      gVX1000.Stim.TimeoutCtr2 = 0; /* Clear the timeout burst counter */
#if defined(VX1000_STIM_BY_OLDA)
      /* Copy the STIM data to final memory locations */
      if (copy_enable != 0) { vx1000_StimTransfer(stim_event); }
#else /* !VX1000_STIM_BY_OLDA */
      copy_enable = copy_enable; /* dummy access to prevent compiler warning */
#endif /* !VX1000_STIM_BY_OLDA */
   }
   errorcode >>= 1;
   VX1000_STIM_BENCHMARK_STIM_END(stim_event, errorcode)
   return errorcode;
}


/* Event number daq_event is the bypass stimulation event, it indicates */
/* that the ECU is now waiting for completion of the stimulation */
/* Event number stim_event is the bypass trigger event, it should be used */
/* to trigger calculation of the bypass in the tool; as long */
/* as the bypass is not activated in the tool, this event is not executed. */
/* Time timeout specified in [us], the time starts now. */
/* Return 1, if the bypass is active and the bypassed code has to be disabled */
/* Return 2, in case of timeout */
VX1000_UINT8 vx1000_Bypass( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us)
{
   VX1000_UINT8 retVal = 0;    /* 0 means "Bypass inactive, enable the bypassed code" */
   
   if ((VX1000_STIM_ACTIVE(stim_event)) != 0)
   {
      VX1000_EVENT(daq_event)
      VX1000_STIM_REQUEST(stim_event)
      if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != 0)
      {
         retVal = 2;           /* "Bypass active, timeout" */
      }
      else
      {
         retVal = 1;           /* "Bypass active, ok, disable the bypassed code" */
      }
   }
   return retVal;
}

VX1000_UINT8 vx1000_BypassTrigger( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event )
{
   VX1000_UINT8 retVal = 0;    /* 0 means "Bypass inactive" */
   
   if (VX1000_STIM_ACTIVE(stim_event) != 0)
   {
      VX1000_EVENT(daq_event)
      retVal = 1;              /* "Bypass active" */
   }
   return retVal;
}

/* Time timeout specified in [us], the time starts now. */
VX1000_UINT8 vx1000_BypassWait( VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us )
{
   VX1000_UINT8 retVal = 0;    /* 0 means "Bypass inactive, enable the bypassed code" */
   
   if (VX1000_STIM_ACTIVE(stim_event) != 0)
   {
      VX1000_STIM_REQUEST(stim_event)
      if (VX1000_STIM_WAIT(stim_event, timeout_us) != 0)
      {
         retVal = 2;           /* "Bypass active, timeout. It may be too late to enable the bypassed code" */
      }
      else
      {
         retVal = 1;           /* "Bypass active, ok, disable the bypassed code" */
      }
   }
   return retVal;
}


/* Event number stim_trigger_event is the stimulation daq event to request data from CANape */
/* Event number stim_event is the stimulation event */
/* Return 1, if stimulation is active  */
/* Return 2, if stimulation is active and there is a timeout */
/* cycle_delay specifies the number of cycles between the triggering and the associated stimulation, the */
/* first (cycle_delay) cycles are not stimulated ! */
/* timeout may be 0, if cycle_delay is >0 */
#if defined(VX1000_STIM_BY_OLDA)
/* Reuse the events copying flag as cycle delay counter: */
#define CycleDelayCtr(event) gVX1000.Stim.Event[(event) - (VX1000_STIM_EVENT_OFFSET)].Copying /* PRQA S 3453 */ /* willingly violating MISRA Rule 19.7 because define is used as an lvalue and thus cannot be replaced by a function call */

VX1000_UINT8 vx1000_Stimulate( VX1000_UINT8 stim_trigger_event, VX1000_UINT8 stim_event,
                               VX1000_UINT8 cycle_delay, VX1000_UINT32 timeout_us)
{
   VX1000_UINT8 retVal = 0; /* means "Stim not active" */
   
   if (0==cycle_delay)
   {
      /* If cycle_delay is 0, stimulation has normal bypass behaviour */
      retVal = vx1000_Bypass(stim_trigger_event, stim_event, timeout_us);
   }
   else
   {
      if (VX1000_STIM_ACTIVE(stim_event) != 0)
      {
         if (0==(CycleDelayCtr(stim_event)))
         {
            /* Delay period has expired */
            /* Wait for stimulation data available in the OLDA buffer and stimulate */
            if ((VX1000_STIM_WAIT(stim_event, timeout_us)) != 0)
            {
               /* We cannot distinguish the cases "EOF_stimfile reached, no more data" and   */
               /* "timeout requirement just too hard, stim data still waiting in the queue". */
               /* In either case we do NOT try to prefetch further data and we always signal */
               /* "Stim (still) active, Timeout" to the caller: */
               retVal = 2;
            }
            else
            {
               VX1000_STIM_REQUEST(stim_event)     /* Request stimulation data */
               VX1000_EVENT(stim_trigger_event)    /* Trigger a stimulation */
               retVal = 1;                         /* Stim active, Ok */
            }
         }
         else
         {
            CycleDelayCtr(stim_event)--;
            VX1000_EVENT(stim_trigger_event)       /* Trigger a stimulation */
            if (0==(CycleDelayCtr(stim_event)))
            {
               VX1000_STIM_REQUEST(stim_event)     /* Request stimulation data */
            }
            /* Stim not active, startup delay still in progress */
         }
      } /* if Stim active */
      else
      {
         if (cycle_delay > 100) { cycle_delay = 100; } /* Silently ensures to not exceed the VX's max queue size */
         CycleDelayCtr(stim_event) = cycle_delay;
      } /* if Stim not active */
   } /* if cycle_delay > 0 */
   
   return retVal;
}
#endif /* VX1000_STIM_BY_OLDA */

#endif /* VX1000_STIM */


/*------------------------------------------------------------------------------- */
/* Generic Hooking */

#if defined(VX1000_HOOK_ENABLE)

void vx1000_HookInit( void )
{
   VX1000_UINT8 i;

   gVX1000_HookControl.magic = VX1000_HOOK_MAGIC;
   gVX1000_HookControl.count = 0;
   gVX1000_HookControl.active_index = VX1000_HOOK_COUNT;
   gVX1000_HookControl.active_id = 0xFFFFU;
   for (i = 0; i < VX1000_HOOK_COUNT; i++)
   {
      /* Define standard behaviour copy=on, execute original code=off, daq=off */
      gVX1000_HookControl.table[i].id = 0xFFFFU;
#if defined(VX1000_STIM)  
      gVX1000_HookControl.table[i].stim_event = 0xFFU;
#endif
      gVX1000_HookControl.table[i].trigger_event = 0xFFU;
      gVX1000_HookControl.table[i].daq_event = 0xFFU;
      gVX1000_HookControl.table[i].control = VX1000_HOOK_COPY_ENABLE;
   }
}


/* Generic event */
void vx1000_GenericEvent( VX1000_UINT16 hook_id )
{
   VX1000_UINT8 i;
  
   /* Lookup the hook id */
   if ((gVX1000_HookControl.magic == (VX1000_HOOK_MAGIC)) && (gVX1000_HookControl.count != 0))
   {
      for (i = 0; (i < gVX1000_HookControl.count) && (gVX1000_HookControl.table[i].id != hook_id); i++)
      {
         /* just loop until we found a valid index i pointing to hook_id or there are no indices left */
      }
      if (i < gVX1000_HookControl.count)
      {
         VX1000_EVENT(gVX1000_HookControl.table[i].trigger_event)
      }
   }
}


/* Trigger a generic bypass
/   return 0: Run the original code
/             (inactive bypass or active bypass and original code enabled)
/   return 1: Don't run the original code
/             (bypass active and original code disabled) */
VX1000_UINT8 vx1000_EnterHook( VX1000_UINT16 hook_id )
{
   VX1000_UINT8 i, retVal = 0; /* means "enable the bypassed code" */

   /* Initialization check */
   if ((gVX1000_HookControl.magic == (VX1000_HOOK_MAGIC)) && (gVX1000_HookControl.count != 0))
   {
      for (i = 0; (i < gVX1000_HookControl.count) && (gVX1000_HookControl.table[i].id != hook_id); i++)
      {
         /* just loop until we found a valid index i pointing to hook_id or there are no indices left */
      }
      if (i < gVX1000_HookControl.count)
      {
#if defined(VX1000_STIM)
        /* i is a valid index -> found a bypass entry */
        if (vx1000_StimActive(gVX1000_HookControl.table[i].stim_event) != 0)
        {
           /* This bypass is enabled by the tool, but check for nested bypasses first */
           if (gVX1000_HookControl.active_index >= gVX1000_HookControl.count)
           {
               /* Trigger this bypass */
               gVX1000_HookControl.active_index = i;
               gVX1000_HookControl.active_id = hook_id;
               VX1000_EVENT(gVX1000_HookControl.table[i].trigger_event)
               vx1000_StimRequest(gVX1000_HookControl.table[i].stim_event);
               if (0==(gVX1000_HookControl.table[i].control & (VX1000_HOOK_CODE_ALWAYS)))
               {
                  retVal = 1; /* Bypass active normally --> don't execute the bypassed code */
               }
               /* else: Bypass active but original code enabled --> enable the bypassed code */
            }
            /* else: Nesting detected, don't execute this bypass --> enable the bypassed code */
         }
         else
#endif /* VX1000_STIM */
         {
            gVX1000_HookControl.active_index = i;
            gVX1000_HookControl.active_id = hook_id;
            if ((gVX1000_HookControl.table[i].control & (VX1000_HOOK_TRIGGER_EVENT_ENABLE)) != 0)
            {
               VX1000_EVENT(gVX1000_HookControl.table[i].trigger_event)
            }
         }
         /* Bypass inactive --> enable the bypassed code */
      }
      /* else: Id not found, Bypass inactive --> enable the bypassed code */
   }
   /* else: Generic bypassing not initialized yet --> enable the bypassed code */
   return retVal;
}


/* Stimulate for a generic bypass
/   return 3: stimulation not done, timeout, execute original code
/   return 2: stimulation not done, timeout
/   return 1: stimulation done, no timeout, ok
/   return 0: bypass inactive */
VX1000_UINT8 vx1000_LeaveHook( VX1000_UINT16 hook_id, VX1000_UINT32 timeout)
{
   VX1000_UINT16 idx, ident;
   VX1000_UINT8 retVal = 0; /* this means "bypass inactive" */

   if ((gVX1000_HookControl.magic == (VX1000_HOOK_MAGIC)) && (gVX1000_HookControl.count != 0))
   {
      /* Generic bypassing is initialised */
      idx = gVX1000_HookControl.active_index;
      ident = gVX1000_HookControl.active_id;
      if ((idx < gVX1000_HookControl.count) && (ident == hook_id))
      {
         /* The specified generic bypass is being executed right now */
         gVX1000_HookControl.active_index = VX1000_HOOK_COUNT;
         gVX1000_HookControl.active_id = 0xFFFFU;
#if defined(VX1000_STIM)
         if (vx1000_StimActive(gVX1000_HookControl.table[idx].stim_event) != 0)
         {
            if ((gVX1000_HookControl.table[idx].control & (VX1000_HOOK_DAQ_EVENT_ENABLE)) != 0)
            {
               VX1000_EVENT(gVX1000_HookControl.table[idx].daq_event)    /* Trigger an additional DAQ event */
            }
            /* Wait */
            if (vx1000_StimWait(gVX1000_HookControl.table[idx].stim_event
            ,(VX1000_UINT8)(gVX1000_HookControl.table[idx].control & (VX1000_UINT8)(VX1000_HOOK_COPY_ENABLE)), timeout) != 0)
            {
               if ((gVX1000_HookControl.table[idx].control & (VX1000_HOOK_CODE_TIMEOUT)) != 0)
               {
                  retVal = 3;  /* Timeout, execute original code */
               }
               else
               {
                  retVal = 2; /* Timeout, no action */
               }
            }
            else
            {
               retVal = 1;   /* Bypass active, done, ok */
            }
         }
         else
#endif /* VX1000_STIM */
         {
            if ((gVX1000_HookControl.table[idx].control & (VX1000_HOOK_DAQ_EVENT_ENABLE)) != 0)
            {
               VX1000_EVENT(gVX1000_HookControl.table[idx].daq_event)    /* Trigger an additional DAQ event */
            }
         } /* do not remove this pair of braces - it's required for MISRA */
         /* Bypass not startet by tool, Bypass inactive */
      }
      /* else: Id not found, Bypass inactive */
   }
   /* else: Generic bypassing not active at all */
   return retVal;
}

#endif /* VX1000_HOOK_ENABLE */



/*------------------------------------------------------------------------------- */
/* Calibration */


#if defined(VX1000_OVERLAY) && defined(VX1000_MAILBOX) && !defined(VX1000_COMPILED_FOR_SLAVECORES) /* mailbox no slavecore support and slavecore no MMU */ 

#if !(defined(VX1000_MPC_MMU_MTMAS0)&&defined(VX1000_MPC_MMU_MTMAS1)&&defined(VX1000_MPC_MMU_MTMAS2)&&defined(VX1000_MPC_MMU_MTMAS3))
#error VX1000_MPC_MMU_MTMASxx() must be defined for your compiler in vx1000_mpc5xxx_cfg.h
#endif 
#if !defined(VX1000_MPC_MMU_TLBWE)
#error VX1000_MPC_MMU_TLBWE() must be defined for your compiler in vx1000_mpc5xxx_cfg.h
#endif /* !VX1000_MPC_MMU_TLBWE */   
/* returns 1 if MMU settings had to be changed, 0 if unmodified */
static VX1000_UINT8 vx1000_MMUWriteTLBEntry( VX1000_UINT8 n,
                                             VX1000_UINT32 ea,
                                             VX1000_UINT32 ra,
                                             VX1000_UINT32 pagesize,
                                             VX1000_UINT8 cache_inhibit,
                                             VX1000_UINT8 cache_writethrough,
                                             VX1000_UINT8 permissions )
{
   VX1000_UINT32 rpn, epn;
   VX1000_UINT8 pagetype, pageshift, retVal = 0;

   switch (pagesize)
   {
      case 0x001000UL: pagetype = 1U; pageshift = 12U; break; /*   4 K */
      case 0x004000UL: pagetype = 2U; pageshift = 14U; break; /*  16 K */
      case 0x010000UL: pagetype = 3U; pageshift = 16U; break; /*  64 K */
      case 0x040000UL: pagetype = 4U; pageshift = 18U; break; /* 256 K */
      case 0x100000UL: pagetype = 5U; pageshift = 20U; break; /*   1 M */
      default: pagetype = 0U; pageshift = 0U; break;        /* invalid */
   }

   if (!((0==pagetype) || ((ra % pagesize) != 0) || ((ea % pagesize) != 0)))
   {
      rpn = ra / pagesize;
      epn = ea / pagesize;

      /* Select TLB entry */
      VX1000_MPC_MMU_MTMAS0(0x10000000UL | ((VX1000_UINT32)n << 16U))

      /* Define description context and configuration control:*/
      /* VALID=1, IPROT=0, TID=0, TS=0, TSIZE=pagetype */
      VX1000_MPC_MMU_MTMAS1(0x80000000UL | ((VX1000_UINT32)pagetype << 8U))

      /* Define EPN and page attributes: */
      /* EPN = 0x06000 (addr=0x60000000), WIMAGE = xx000 */
      VX1000_MPC_MMU_MTMAS2((epn << pageshift) | (cache_inhibit ? 0x8:0) | (cache_writethrough ? 0x10:0))

      /* Define RPN and access control for data R/W */
      /* RPN = , U0:3=0, UX/SX=0, UR/SR=1, UW/SW=1 */
      VX1000_MPC_MMU_MTMAS3((rpn << pageshift) | (0x3FU & permissions))

      VX1000_MPC_MMU_TLBWE()  /* Make precharged entry from MAS0..MAS3 to valid as an MMU TLB */
      retVal = 1;
   }
   return retVal;
}

#if !defined(VX1000_OVERLAY_ADDR) || !defined(VX1000_OVERLAY_SIZE) || !defined(VX1000_CALRAM_ADDR)
#error Please define the overlay parameters in vx1000_mpc5xxx_cfg.h !
#endif

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
#define VX1000_CALPAGE_RAM 1
#define VX1000_CALPAGE_FLASH 0
static VX1000_UINT8 gVX1000_XCP_CalPage; /* RAM */
static VX1000_UINT8 gVX1000_ECU_CalPage; /* RAM */
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */


#if defined(VX1000_INIT_CAL_PAGE_INTERNAL)
static void vx1000_InitCalPage( void )
{
   /* Initialize CALRAM */
   (void)memcpy((void*)VX1000_CALRAM_ADDR,(void*)VX1000_OVERLAY_ADDR,VX1000_OVERLAY_SIZE); /* FLASH->RAM */ /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
   /* Map RAM over FLASH, cache inhibit, RWE */
   (void)vx1000_MMUWriteTLBEntry(VX1000_OVERLAY_TLB, VX1000_OVERLAY_ADDR, VX1000_CALRAM_ADDR,
                                 VX1000_OVERLAY_SIZE, 1, 1, 0x3F); /* RAM */

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
   gVX1000_XCP_CalPage = VX1000_CALPAGE_RAM; /* RAM */
   gVX1000_ECU_CalPage = VX1000_CALPAGE_RAM; /* RAM */
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */
}
#endif /* VX1000_INIT_CAL_PAGE_INTERNAL */

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)

#if defined(VX1000_GET_CAL_PAGE_INTERNAL)
static VX1000_UINT8 vx1000_GetCalPage( VX1000_UINT8 segment, VX1000_UINT8 mode )
{
   VX1000_UINT8 retVal = gVX1000_ECU_CalPage;
   
   if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == (VX1000_CAL_ECU))
   {
      retVal = gVX1000_ECU_CalPage;
   }
   else if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == (VX1000_CAL_XCP))
   {
      retVal = gVX1000_XCP_CalPage;
   }
   else /* just here for MISRA */
   {
      segment++; /* just to avoid compiler warnings */ /* PRQA S 3199 */ /* just a dummy access anyway */
   }
   return retVal;
}
#endif /* VX1000_GET_CAL_PAGE_INTERNAL */


#if defined(VX1000_SET_CAL_PAGE_INTERNAL)
static VX1000_UINT8 vx1000_SetCalPage( VX1000_UINT8 segment, VX1000_UINT8 page, VX1000_UINT8 mode )
{
   VX1000_UINT8 retVal = 0;
   
   if (segment != 0)
   { 
      retVal = VX1000_CRC_OUT_OF_RANGE; /* Only one segment supported */
   }
   else if (page > 1)
   {
      retVal = VX1000_CRC_PAGE_NOT_VALID;
   }
   else if ((mode & ((VX1000_CAL_ECU) | (VX1000_CAL_XCP))) == ((VX1000_CAL_ECU) | (VX1000_CAL_XCP)))
   {
      if (page != gVX1000_ECU_CalPage)
      {
         if (page == VX1000_CALPAGE_RAM)
         { /* RAM */
            /* Map RAM over FLASH, cache inhibit, RWE */
            (void)vx1000_MMUWriteTLBEntry(VX1000_OVERLAY_TLB, VX1000_OVERLAY_ADDR, VX1000_CALRAM_ADDR,
                                          VX1000_OVERLAY_SIZE, 1, 1, 0x3F); /* RAM */
         }
         else
         {
            /* Map FLASH, cache inhibit, RWE */
            (void)vx1000_MMUWriteTLBEntry(VX1000_OVERLAY_TLB, VX1000_OVERLAY_ADDR, VX1000_OVERLAY_ADDR,
                                          VX1000_OVERLAY_SIZE, 1, 1, 0x3F); /* FLASH */
         }
         gVX1000_XCP_CalPage = page;
         gVX1000_ECU_CalPage = page;
      }
   }
   else if ((mode & (VX1000_CAL_ECU)) != 0)
   {
      if (page != gVX1000_ECU_CalPage)
      {
         if (page == VX1000_CALPAGE_RAM)
         { /* RAM */
            /* Map RAM over FLASH, cache inhibit, RWE */
            (void)vx1000_MMUWriteTLBEntry(VX1000_OVERLAY_TLB, VX1000_OVERLAY_ADDR, VX1000_CALRAM_ADDR,
                                          VX1000_OVERLAY_SIZE, 1, 1, 0x3F); /* RAM */
         }
         else
         {
            /* Map FLASH, cache inhibit, RWE */
            (void)vx1000_MMUWriteTLBEntry(VX1000_OVERLAY_TLB, VX1000_OVERLAY_ADDR, VX1000_OVERLAY_ADDR,
                                          VX1000_OVERLAY_SIZE, 1, 1, 0x3F); /* FLASH */
         }
         gVX1000_ECU_CalPage = page;
      }
   }
   else if ((mode & (VX1000_CAL_XCP)) != 0)
   {
      gVX1000_XCP_CalPage = page;
   }
   else
   {
      ; /* the empty else case is here only for MISRA */
   }
   return retVal;
}
#endif /* VX1000_SET_CAL_PAGE_INTERNAL */


#if defined(VX1000_COPY_CAL_PAGE_INTERNAL)
static VX1000_UINT8 vx1000_CopyCalPage( VX1000_UINT8 srcSeg, VX1000_UINT8 srcPage, VX1000_UINT8 dstSeg, VX1000_UINT8 dstPage )
{
   VX1000_UINT8 retVal = 0;
   /* Check parameters */
   /* Only copy from RAM to FLASH makes sense */
   if ((srcSeg | dstSeg) != 0) { retVal = VX1000_CRC_SEGMENT_NOT_VALID; /* Segments are not supported */ }
   else if (dstPage == srcPage) { retVal = VX1000_CRC_PAGE_NOT_VALID; /* Can not copy on itself */ }
   else if (0==dstPage) { retVal = VX1000_CRC_ACCESS_DENIED; /* Can not copy to FLASH page  */ }
   /* Initialize CALRAM */
   /* Initialize CALRAM, copy from FLASH to RAM */
   /* Turn mapping of, if needed */
   else if (gVX1000_ECU_CalPage == (VX1000_CALPAGE_RAM))
   {
      (void)vx1000_SetCalPage(0, VX1000_CALPAGE_FLASH, VX1000_CAL_ECU);
      (void)memcpy((void*)VX1000_CALRAM_ADDR, (void*)(VX1000_OVERLAY_ADDR), VX1000_OVERLAY_SIZE); /* FLASH->RAM */ /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
      (void)vx1000_SetCalPage(0, VX1000_CALPAGE_RAM, VX1000_CAL_ECU);
   }
   else
   {
      (void)memcpy((void*)VX1000_CALRAM_ADDR, (void*)(VX1000_OVERLAY_ADDR), VX1000_OVERLAY_SIZE); /* FLASH->RAM */ /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */
   }
   return retVal;
}
#endif /* VX1000_COPY_CAL_PAGE_INTERNAL */


#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */


#endif /* VX1000_OVERLAY && !VX1000_COMPILED_FOR_SLAVECORES */


/*---------------------------------------------------------------------------- */
/* Mailbox */

#if defined(VX1000_MAILBOX) && !defined(VX1000_COMPILED_FOR_SLAVECORES)

#define VX1000_MAILBOX_FLG_CLR                0
#define VX1000_MAILBOX_FLG_SET                1

#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
static VX1000_UINT32 sFlgRdSplitPend;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */
#if defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
static VX1000_UINT32 sFlgWrSplitPend;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITWRITE */


/* Initialize the Master->Slave and Slave->Master mailboxes. */
void vx1000_MailboxInit(void)
{
#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
   sFlgRdSplitPend = VX1000_MAILBOX_FLG_CLR;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */
#if defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
   sFlgWrSplitPend = VX1000_MAILBOX_FLG_CLR;
#endif /* VX1000_MAILBOX_PROVIDE_SPLITWRITE */

   gVX1000.Mailbox.Version = 0;
   gVX1000.Mailbox.SlotSize = (VX1000_MAILBOX_SLOT_DWORDS) << 2;
   gVX1000.Mailbox.MS_ReadIdx = 0;
   gVX1000.Mailbox.MS_WriteIdx = 0;
   gVX1000.Mailbox.SM_ReadIdx = 0;
   gVX1000.Mailbox.SM_WriteIdx = 0;
   gVX1000.Mailbox.RstReq = 0;
   gVX1000.Mailbox.RstAck = 0;
   gVX1000.Mailbox.MS_Slots = VX1000_MAILBOX_SLOTS;
   gVX1000.Mailbox.SM_Slots = VX1000_MAILBOX_SLOTS;
   gVX1000.Mailbox.MS_Ptr = (VX1000_UINT32)gVX1000.Mailbox.MSData; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
   gVX1000.Mailbox.SM_Ptr = (VX1000_UINT32)gVX1000.Mailbox.SMData; /* PRQA S 0306 */ /* willingly violating MISRA Rule 11.3 here to be able to replace pointer arithmetic by integer arithmetic elsewhere */ /* PRQA S 0309 */ /* not violating MISRA Rule 11.3 with respect to the type sizes: 32 bit are sufficient to hold either a 0:32 flat or a 10:16 paged pointer */
   gVX1000.Mailbox.MagicId = (VX1000_UINT32)VX1000_MAILBOX_MAGIC;
}


/* Write len bytes from pBuf to the Slave->Master mailbox */
/* and notify the master. */
VX1000_UINT32 vx1000_MailboxWrite(VX1000_UINT32 len, const VX1000_CHAR* pBuf)
{
   VX1000_UINT32 retVal = VX1000_MAILBOX_OK;
   
   if (0==(VX1000_MAILBOX_FREE_WR_SLOTS))
   {
      retVal = VX1000_MAILBOX_ERR_FULL;
   }
   else if (0==pBuf)
   {
      retVal = VX1000_MAILBOX_ERR_NULL;
   }
   else if (len > ((VX1000_MAILBOX_SLOT_DWORDS) << 2))
   {
      retVal = VX1000_MAILBOX_ERR_SIZE;
   }
   else
   {
      (void)memcpy((void*)&gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][1], (VX1000_CHAR*)pBuf, len); /* PRQA S 0311 */ /* compiler warnings about differing prototype of this library function force violation of MISRA Rule 11.5 */
      gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][0] = len;
      gVX1000.Mailbox.SM_WriteIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.SM_WriteIdx);
      VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) /* note: EM00034754 did not mention to remove THIS one */
   }
   return retVal;
}


#if defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
/* Return a pointer to the data field of the next free Slave->Master mailbox slot in ppBuf. */
/* Once data is filled into the mailbox by the calling function, */
/* vx1000_MailboxWriteDone() has to be called to notify the master. */
VX1000_UINT32 vx1000_MailboxWriteSplit(VX1000_UINT32 **ppBuf)
{
   VX1000_UINT32 retVal = VX1000_MAILBOX_OK;

   if (0==(VX1000_MAILBOX_FREE_WR_SLOTS))
   {
      retVal = VX1000_MAILBOX_ERR_FULL;
   }
   else if (0==ppBuf)
   {
      retVal = VX1000_MAILBOX_ERR_NULL;
   }
   else if (sFlgWrSplitPend != 0)
   {
      retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
   }
   else
   {
      sFlgWrSplitPend = VX1000_MAILBOX_FLG_SET;
      *ppBuf = (VX1000_UINT32 *)&gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][1];
   }
   return retVal;
}


/* Finish a Slave->Master mailbox transfer that has been started with vx1000_MailboxWriteSplit(). */
VX1000_UINT32 vx1000_MailboxWriteDone(VX1000_UINT32 len)
{
   VX1000_UINT32 retVal = VX1000_MAILBOX_OK;
   
   if (len > ((VX1000_MAILBOX_SLOT_DWORDS) << 2))
   {
      retVal = VX1000_MAILBOX_ERR_SIZE;
   }
   else if (0==sFlgWrSplitPend)
   {
      retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
   }
   else
   {
      sFlgWrSplitPend = VX1000_MAILBOX_FLG_CLR;
      gVX1000.Mailbox.SMData[gVX1000.Mailbox.SM_WriteIdx][0] = len;
      gVX1000.Mailbox.SM_WriteIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.SM_WriteIdx);
      VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) /* note: EM00034754 did not mention to remove THIS one */
   }
   return retVal;  
}
#endif /* VX1000_MAILBOX_PROVIDE_SPLITWRITE */

/* Read the data from the next filled Master->Slave mailbox slot */
/* into pBuf and return the number of bytes in pLen. */
/* Upon calling pLen contains the maximum number of bytes that */
/* can be read into pBuf. If the number of bytes exceeds pLen, */
/* an error is returned and no data is copied. */
VX1000_UINT32 vx1000_MailboxRead(VX1000_UINT32* pLen, VX1000_CHAR* pBuf)
{
   VX1000_UINT32 len;
   VX1000_UINT32 retVal = VX1000_MAILBOX_OK;
   
   if (0==(VX1000_MAILBOX_USED_RD_SLOTS))
   {
      retVal = VX1000_MAILBOX_ERR_EMPTY;
   }
   else if ((0==pLen) || (0==pBuf))
   {
      retVal = VX1000_MAILBOX_ERR_NULL;
   }
   else
   {
      len = gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][0];
      if (len > *pLen)
      {
         retVal = VX1000_MAILBOX_ERR_SIZE;
      }
#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
      else if (sFlgRdSplitPend != 0)
      {
         retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
      }
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */
      else
      {
         *pLen = len;
         (void)memcpy(pBuf, (void*)&gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][1], len);
         gVX1000.Mailbox.MS_ReadIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.MS_ReadIdx);
         /* VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) -- removed due to EM00034754 */
      }
   }
   return retVal;
}


#if defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
/* Return the data length in pLen and a pointer on the data of the next */
/* filled Master->Slave mailbox slot in ppBuf. */
/* Once the mailbox slot is read by the calling function, mailboxReadDone() */
/* must be called to mark the mailbox slot as empty and notify the master. */
VX1000_UINT32 vx1000_MailboxReadSplit(VX1000_UINT32* pLen, VX1000_UINT32** ppBuf)
{
   VX1000_UINT32 retVal = VX1000_MAILBOX_OK;
   
   if (0==(VX1000_MAILBOX_USED_RD_SLOTS))
   {
      retVal = VX1000_MAILBOX_ERR_EMPTY;
   }
   else if ((0==pLen) || (0==ppBuf))
   {
      retVal = VX1000_MAILBOX_ERR_NULL;
   }
   else if (sFlgRdSplitPend != 0)
   {
      retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
   }
   else
   {
      sFlgRdSplitPend = VX1000_MAILBOX_FLG_SET;
      *pLen = gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][0];
      *ppBuf = (VX1000_UINT32*)&gVX1000.Mailbox.MSData[gVX1000.Mailbox.MS_ReadIdx][1];
   }
   return retVal;
}

/* Mark the filled Master->Slave mailbox slot as empty, that has been returned */
/* by previously calling mailboxReadSplit(). Notify the master afterwards. */
VX1000_UINT32 vx1000_MailboxReadDone(void)                                        /* used by flash kernels */
{
   VX1000_UINT32 retVal = VX1000_MAILBOX_OK;
   
   if (0==sFlgRdSplitPend)
   {
      retVal = VX1000_MAILBOX_ERR_SPLIT_PEND;
   }
   else
   {
      sFlgRdSplitPend = VX1000_MAILBOX_FLG_CLR;
      gVX1000.Mailbox.MS_ReadIdx = (VX1000_UINT8)VX1000_MAILBOX_NEXT(gVX1000.Mailbox.MS_ReadIdx);
      /* VX1000_SPECIAL_EVENT(VX1000_EVENT_MAILBOX_UPDATE) -- removed due to EM00034754 */
   }
   return retVal;
}
#endif /* VX1000_MAILBOX_PROVIDE_SPLITREAD */


/* XCP compliant protocol handler - though these defines are only visible inside this module, they still may conflict whith stuff coming in via vx1000_tricore_cfg.h subincludes, so better add VX1000_-pefices */
#define VX1000_CRM_CMD txBuf[0]
#define VX1000_CRM_ERR txBuf[1]


/* XCP calibration page handling */
#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)

#define CC_SET_CAL_PAGE                    0xEB
#define CC_GET_CAL_PAGE                    0xEA
#define CC_COPY_CAL_PAGE                   0xE4

/* SET_CAL_PAGE */
#define CRO_SET_CAL_PAGE_LEN               4
#define CRO_SET_CAL_PAGE_MODE              rxBuf[(1)]
#define CRO_SET_CAL_PAGE_SEGMENT           rxBuf[(2)]
#define CRO_SET_CAL_PAGE_PAGE              rxBuf[(3)]
#define CRM_SET_CAL_PAGE_LEN               1

/* GET_CAL_PAGE */
#define CRO_GET_CAL_PAGE_LEN               3
#define CRO_GET_CAL_PAGE_MODE              rxBuf[(1)]
#define CRO_GET_CAL_PAGE_SEGMENT           rxBuf[(2)]
#define CRM_GET_CAL_PAGE_LEN               4
#define CRM_GET_CAL_PAGE_PAGE              txBuf[(3)]

/* COPY_CAL_PAGE */
#define CRO_COPY_CAL_PAGE_LEN              5
#define CRO_COPY_CAL_PAGE_SRC_SEGMENT      rxBuf[(1)]
#define CRO_COPY_CAL_PAGE_SRC_PAGE         rxBuf[(2)]
#define CRO_COPY_CAL_PAGE_DEST_SEGMENT     rxBuf[(3)]
#define CRO_COPY_CAL_PAGE_DEST_PAGE        rxBuf[(4)]
#define CRM_COPY_CAL_PAGE_LEN              1
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */

/* flash programming via mailbox */
#if defined(VX1000_MAILBOX_FLASH)

/* Commands: */
#define CC_PROGRAM_START                   0xD2
#define CC_PROGRAM_CLEAR                   0xD1
#define CC_PROGRAM                         0xD0
#define CC_PROGRAM_RESET                   0xCF
#define CC_PROGRAM_PREPARE                 0xCC
#define CC_PROGRAM_NEXT                    0xCA
#define CC_PROGRAM_MAX                     0xC9
#define CC_PROGRAM_VERIFY                  0xC8

/* Data for: */
/* - PROGRAM_PREPARE */
#define CRO_PROGRAM_PREPARE_LEN            4
#define CRO_PROGRAM_PREPARE_SIZE           *((VX1000_UINT16*)&rxBuf[(2)])
#define CRM_PROGRAM_PREPARE_LEN            1

/* - PROGRAM_START */
#define CRO_PROGRAM_START_LEN              1
#define CRM_PROGRAM_START_LEN              7
#define CRM_PROGRAM_COMM_MODE_PGM          txBuf[(2)]
#define CRM_PROGRAM_MAX_CTO_PGM            txBuf[(3)]
#define CRM_PROGRAM_MAX_BS_PGM             txBuf[(4)]
#define CRM_PROGRAM_MIN_ST_PGM             txBuf[(5)]
#define CRM_PROGRAM_QUEUE_SIZE_PGM         txBuf[(6)]

/* - PROGRAM_CLEAR */
#define CRO_PROGRAM_CLEAR_LEN              8
#define CRO_PROGRAM_CLEAR_MODE             rxBuf[(1)]
#define CRO_PROGRAM_CLEAR_SIZE             *((VX1000_UINT32*)&rxBuf[(4)])
#define CRM_PROGRAM_CLEAR_LEN              1

/* - PROGRAM */
#define CRO_PROGRAM_MAX_SIZE               ((VX1000_UINT8)((kXcpMaxCTO - 2) / kXcpAG))
#define CRO_PROGRAM_LEN                    2 /* + CRO_PROGRAM_SIZE */
#define CRO_PROGRAM_SIZE                   rxBuf[(1)]
#define CRO_PROGRAM_DATA                   (&rxBuf[(2))]
#define CRM_PROGRAM_LEN                    1

#endif /* VX1000_MAILBOX_FLASH */

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH)
void vx1000_MailboxHandler(void)
{
   VX1000_UINT32 rxLen, txLen;
   VX1000_CHAR rxBuf[8], txBuf[8];

   rxLen = 8;
   if ((VX1000_MAILBOX_OK) == vx1000_MailboxRead(&rxLen, &rxBuf[0]))
   {
      txLen = 2;
      VX1000_CRM_CMD = (VX1000_CHAR)-1;
      VX1000_CRM_ERR = 0x00;
      switch ((VX1000_UINT8)rxBuf[0]) /* check CRO_CMD */
      {
#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)
      case (VX1000_UINT8)(CC_GET_CAL_PAGE):
         CRM_GET_CAL_PAGE_PAGE = (VX1000_CHAR)(VX1000_GET_CAL_PAGE((CRO_GET_CAL_PAGE_SEGMENT), (CRO_GET_CAL_PAGE_MODE)));
         txLen = CRM_GET_CAL_PAGE_LEN;
         break;
      case (VX1000_UINT8)(CC_SET_CAL_PAGE):
         VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_SET_CAL_PAGE((CRO_SET_CAL_PAGE_SEGMENT), (CRO_SET_CAL_PAGE_PAGE), (CRO_SET_CAL_PAGE_MODE)));
         txLen = CRM_SET_CAL_PAGE_LEN;
         break;
      case (VX1000_UINT8)(CC_COPY_CAL_PAGE):
         VX1000_CRM_ERR = (VX1000_CHAR)(VX1000_COPY_CAL_PAGE((CRO_COPY_CAL_PAGE_SRC_SEGMENT),  (CRO_COPY_CAL_PAGE_SRC_PAGE),
                                                            (CRO_COPY_CAL_PAGE_DEST_SEGMENT), (CRO_COPY_CAL_PAGE_DEST_PAGE)));
         txLen = CRM_COPY_CAL_PAGE_LEN;
         break;
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL */
#if defined(VX1000_MAILBOX_FLASH)
      case (VX1000_UINT8)(CC_PROGRAM_PREPARE):
         /* CRO_PROGRAM_PREPARE_SIZE */
         /* @@@@ Problem: get start addr from a previous SET_MTA, then check that FKL memory does not interfer */
         /*      (HOW to get FKL end address?!?) with current RAM usage and in case provide error handling !   */
         txLen = CRM_PROGRAM_PREPARE_LEN;
         break;
      case (VX1000_UINT8)(CC_PROGRAM_START):
         CRM_PROGRAM_COMM_MODE_PGM = 0;
         CRM_PROGRAM_MAX_CTO_PGM = 8;
         CRM_PROGRAM_MAX_BS_PGM = 1;
         CRM_PROGRAM_MIN_ST_PGM = 0;
         CRM_PROGRAM_QUEUE_SIZE_PGM = 1;
         txLen = CRM_PROGRAM_START_LEN;
         /* @@@@ Problem: how to actually program flash? */
         break;
#endif /* VX1000_MAILBOX_FLASH */
      default:
         VX1000_CRM_ERR = VX1000_CRC_CMD_UNKNOWN;
      }
      if ((VX1000_CRM_ERR) != 0) { VX1000_CRM_CMD = (VX1000_CHAR)-2; }
      (void)vx1000_MailboxWrite(txLen, txBuf);
   }
}
#endif /* VX1000_MAILBOX_OVERLAY_CONTROL, VX1000_MAILBOX_FLASH */

#if defined(VX1000_MAILBOX_PRINTF)
static void vx1000_MailboxPutchar( VX1000_CHAR character )
{
   static VX1000_CHAR vx1000EvBuf[8];
   static VX1000_UINT32 vx1000EvLen;

   if ((vx1000EvBuf[0] != (VX1000_CHAR)-4) || (vx1000EvBuf[1] != (VX1000_CHAR)1) || (vx1000EvLen >= 8UL)) /* PRQA S 3355 */ /* though it's true that this algorithm speculates on probabilities, MISRA Rule 13.7 is NOT violated (the checker ignored the static nature of the variables) */
   {
      /* initialize the protocol header once */
      vx1000EvBuf[0] = (VX1000_CHAR)-4; /* SERV */
      vx1000EvBuf[1] = (VX1000_CHAR)1;  /* SERV_TEXT */
      vx1000EvLen = 2;
   }
   vx1000EvBuf[vx1000EvLen] = character;
   vx1000EvLen++;
   if ( (vx1000EvLen >= 8) || (0==character) ) /* PRQA S 3356 */ /* though it's true that this algorithm speculates on probabilities, MISRA Rule 13.7 is NOT violated (the checker ignored the static nature of the variables) */
   {
      (void)vx1000_MailboxWrite(vx1000EvLen, vx1000EvBuf);
      vx1000EvLen = 2;
   }
}

#if !defined(VX1000_PRINTF_MINIMAL)
/* The full printf library function not only occupies two dozens of Kbytes TEXT but also allocates */
/* a rather huge amount of stack upon calls so it is not well suited for multitasking environments */
void vx1000_MailboxPrintf( const VX1000_CHAR *format, ... ) /* PRQA S 5069 */ /* Cannot avoid violating MISRA Rule 19.4 because a C++-based workaround would only violate other rules */
{
   va_list argptr;
   VX1000_CHAR buf[256];

   va_start(argptr,format);
   (void)vsprintf((VX1000_CHAR*)buf, (const VX1000_CHAR*)format, argptr);
   va_end(argptr); /* PRQA S 3199 */ /* it depends on the used compiler whether this statement has useful side effects or not */

   /* Transmit the text message */
   {
      VX1000_CHAR *p = buf;
      while (*p != 0)
      {
         vx1000_MailboxPutchar((VX1000_CHAR)*p);
         p++; /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
      }
   }

   /* Transmit the terminating 0x00. */
   vx1000_MailboxPutchar( 0x00 );
}
#else /* VX1000_PRINTF_MINIMAL */
/* This reduced printf implementation does not support features like float support or argument */
/* repetition, but it usually uses less TEXT and RAM usage is only a few bytes at runtime.     */

#define PF_NONE          0U
#define PF_IN_TOKEN      1U
#define PF_IN_WIDTH      2U
#define PF_AFTER_WIDTH   4U
#define PF_IN_PREC       8U
#define PF_AFTER_PREC   16U
#define PF_IN_SIZE      32U
#define PF_AFTER_SIZE   64U
#define PF_INVALID     128U
#define GENBIN2DECAUXSTAGE(B)                                                                                                   \
if (number >=(2*(B))){ if (number >=(6*(B))){ if (number >=(8*(B))) { if (number >=(9*(B))){ number -= 9*(B); *p = '9'; p++;}   \
                                                                      else                 { number -= 8*(B); *p = '8'; p++;}}  \
                                              else                  { if (number >=(7*(B))){ number -= 7*(B); *p = '7'; p++;}   \
                                                                      else                 { number -= 6*(B); *p = '6'; p++;}}} \
                       else                 { if (number >=(4*(B))) { if (number >=(5*(B))){ number -= 5*(B); *p = '5'; p++;}   \
                                                                      else                 { number -= 4*(B); *p = '4'; p++;}}  \
                                              else                  { if (number >=(3*(B))){ number -= 3*(B); *p = '3'; p++;}   \
                                                                      else                 { number -= 2*(B); *p = '2'; p++;}}}}\
else                 { if (number >=(1*(B)))                                               { number -= 1*(B); *p = '1'; p++;}   \
                       else                                                                { number -= 0*(B); *p = '0'; p++;}}

void vx1000_MailboxPrintf( const VX1000_CHAR *format, ... ) /* PRQA S 5069 */ /* Cannot avoid violating MISRA Rule 19.4 because a C++-based workaround would only violate other rules */
{
   va_list arglist;
   VX1000_LONG number;
   VX1000_LDOUBL fdummy = 0.0;
   VX1000_CHAR *p2, numbuf[24];
   VX1000_INT   i, width=0, prec=0, size=0, basesize=0;
   VX1000_CHAR  c, digif=0, filler=0, alignleft=0, showpos=0, showbase=0, *p, signedtype=0, floattype=0;
   VX1000_UINT8 state;

   va_start(arglist,format);
   state = (PF_NONE);
   for (; *format != 0; format++) /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
   {
      c = *format;
      if (state == (PF_NONE))
      {
         if (c == '%')
         {
            state = (PF_IN_TOKEN);
            width = prec = size = basesize = 0;
            floattype = signedtype = 0;
            filler = showpos = ' ';
         }
         else
         {
            vx1000_MailboxPutchar(c);
         }
         continue;
      }
      if (c == '%')
      {
         if (state == (PF_IN_TOKEN)) /* no real token, just an escaped "%" */
         {
            state = (PF_NONE);
            vx1000_MailboxPutchar(c);
         }
         else
         {
            state |= (PF_INVALID);
         }
         continue;
      }
      if ((c >= '0') && (c <= '9'))
      {
         c -= '0';
         switch (state & ((PF_IN_WIDTH) | (PF_IN_PREC) | (PF_IN_SIZE))) /* continue in a number */
         {
            case (PF_IN_WIDTH): width = (10 * width) + (VX1000_INT)c; continue;
            case (PF_IN_PREC):  prec  = (10 * prec ) + (VX1000_INT)c; continue;
            case (PF_IN_SIZE):  size  = (10 * size ) + (VX1000_INT)c; continue;
            default:  /* only here for MISRA */
               break; /* only here for MISRA */
         }
         if (0==(state & (PF_AFTER_WIDTH))) /* start reading width number */
         {
            state |= (PF_IN_WIDTH);
            width = (VX1000_INT)c;
            if (c==0) { filler = '0'; }
            continue;
         }
         if (0==(state & (PF_AFTER_PREC))) /* start reading precission number */
         {
            state |= (PF_IN_PREC);
            prec = (VX1000_INT)c;
            continue;
         }
         state |= (PF_INVALID);
         continue;
      }
      switch (state & ((PF_IN_WIDTH) | (PF_IN_PREC) | (PF_IN_SIZE))) /* stop any number */
      {
         case (PF_IN_WIDTH): state ^= (PF_IN_WIDTH) | (PF_AFTER_WIDTH); break;
         case (PF_IN_PREC):  state ^= (PF_IN_PREC)  | (PF_AFTER_PREC);  break;
         case (PF_IN_SIZE):  state ^= (PF_IN_SIZE)  | (PF_AFTER_SIZE);  break;
         default:  /* only here for MISRA */
            break; /* only here for MISRA */
      }
      if (c == 'l')
      {
            state |= (PF_IN_SIZE);
            size += (VX1000_INT)(8 * (sizeof(VX1000_LONG) - sizeof(VX1000_INT)));
            if (size > 64) { state |= (PF_INVALID); }
            continue;
      }
      switch (c) /* get the format specifier */
      {
         case '#':
            showbase = 1;
            continue;
         case '+':
            showpos = '+';
            continue;
         case '-':
            alignleft = 1;
            continue;
         case 'L':
            state |= (PF_AFTER_SIZE);
            size = 256;
            continue;
         case 'I': /* microsoft specific size: start reading the number */
            state |= (PF_IN_SIZE);
            continue;
         case 'c':
            vx1000_MailboxPutchar((VX1000_CHAR)va_arg(arglist, VX1000_INT));
            state = (PF_NONE);
            continue;
         case 's':
            /* todo: care for alignment */
            p = (VX1000_CHAR*)va_arg(arglist, VX1000_CHAR*);
            while (*p != 0) { vx1000_MailboxPutchar(*p); p++; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            state = (PF_NONE);
            continue;
         case 'o':
            digif = '7';
            basesize = 8 * sizeof(VX1000_INT);
            break;
         case 'd':
            /*fallthrough*/
         case 'i':
            signedtype = 1;
            /*fallthrough*/
         case 'u':
            digif = '9';
            basesize = 8 * sizeof(VX1000_INT);
            break;
         case 'X':
            digif = 'F';
            basesize = 8 * sizeof(VX1000_INT);
            break;
         case 'x':
            digif = 'f';
            basesize = 8 * sizeof(VX1000_INT);
            break;
         case 'e':
         case 'E':
            /* scientific floats are not supported */
            basesize = 128;
            floattype= 1;
            break;
         case 'f':
         case 'F':
         case 'g':
         case 'G':
            /* fixed floats are not supported */
            basesize = 64;
            floattype= 1;
            break;
         default:
            state |= (PF_INVALID);
      }
      if (0==(state & (PF_INVALID)))
      {
         state = (PF_NONE);
         if (size < basesize) { size = basesize; }
         if (floattype != 0)
         {
            switch (size)
            {
               /* floats currently are not supported - just advance the pointer and print a hash sign as placeholder */
               case 64:  vx1000_MailboxPutchar('#'); fdummy = (VX1000_LDOUBL)va_arg(arglist, /*float*/VX1000_DOUBLE); continue;
               case 128: vx1000_MailboxPutchar('#'); fdummy = (VX1000_LDOUBL)va_arg(arglist, VX1000_DOUBLE);          continue;
               case 256: vx1000_MailboxPutchar('#'); fdummy = (VX1000_LDOUBL)va_arg(arglist, VX1000_LDOUBL);          continue;
               default:     /* only here for MISRA */
                  fdummy++; /* just to avoid compiler warnings */ /* PRQA S 3199 */ /* dont't care - it's just a dummy! */
                  break;    /* only here for MISRA */
            }
         }
         else
         {
            switch (size)
            {
               case 8 * sizeof(VX1000_INT): number = (VX1000_LONG)va_arg(arglist, VX1000_INT);   break;
               default:                     number = (VX1000_LONG)va_arg(arglist, VX1000_LONG);  break;
            }
            if (signedtype != 0)
            {
               if (number < 0)
               {
                  number = -number;
                  showpos = '-';
               }
            }
            if (showpos != ' ') { vx1000_MailboxPutchar(showpos); }
            switch (digif)
            {
               case '7':
                  i = 11;
                  numbuf[i] = 0;
                  while (i != 0)
                  {
                     i--; numbuf[i] = (VX1000_CHAR)(0x7UL & (VX1000_UINT32)number);
                     numbuf[i] += '0';
                     number >>= 3; /* PRQA S 0502 */ /* Actually not violating MISRA Rule 12.7 because any bits shifted in are masked before usage of the result */
                  }
                  break;
               case '9':
                  /*numbuf[10] = 0;*/
                  p = numbuf;
                  if ((VX1000_UINT32)number >= (2 * 1000000000UL))  { if ((VX1000_UINT32)number >= (4UL * 1000000000UL))
                                                                           { number -= 2 * 1000000000L; 
                                                                             number -= 2 * 1000000000L; *p = '4'; p++;} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                                                     else             { if ((VX1000_UINT32)number >= (3UL * 1000000000UL))
                                                                           { number -= 2 * 1000000000L;
                                                                             number -= 1 * 1000000000L; *p = '3'; p++;} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                                                                        else
                                                                           { number -= 2 * 1000000000L; *p = '2'; p++;}}} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  else                             { if ((VX1000_UINT32)number >= (1 * 1000000000UL))
                                                                           { number -= 1 * 1000000000L; *p = '1'; p++;} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                                                     else
                                                                           { number -= 0 * 1000000000L; *p = '0'; p++;}} /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(100000000L) /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(10000000L)  /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(1000000L)   /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(100000L)    /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(10000L)     /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(1000L)      /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(100L)       /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(10L)        /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  GENBIN2DECAUXSTAGE(1L)         /* PRQA S 0715 */ /* if the compiler warns that it does not support more than 15 nested IFs, disable the VX1000_PRINTF_MINIMAL define in the header */ /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
                  *p = 0;
                  number = number; p = p; /* PRQA S 3198 */ /* dummy assignments to avoid compiler warnings */
                  break;
               case 'F': /* fallthrough to 'f' */
               case 'f':
                  digif -= 15;
                  i = 8;
                  numbuf[i] = 0;
                  while (i != 0)
                  {
                     c = (VX1000_CHAR)(0xfUL & (VX1000_UINT32)number);
                     number >>= 4; /* PRQA S 0502 */ /* Actually not violating MISRA Rule 12.7 because any bits shifted in are masked before usage of the result */
                     c += (VX1000_CHAR)((c > 9) ? digif : (VX1000_CHAR)'0');
                     i--; numbuf[i] = c;
                  }
                  break;
               default:  /* only here for MISRA */
                  break; /* only here for MISRA */
            }
            for (p = numbuf; *p == '0'; p++) { } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            if (0==*p) { p--; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because strcat and thus pointer deccrementation is a core feature of this application */
            if (alignleft == 1)
            {
               if ((showbase == 1) && (digif != '9'))
               {
                  vx1000_MailboxPutchar((VX1000_CHAR)'0');
                  if (digif != '7') { vx1000_MailboxPutchar((VX1000_CHAR)'x'); }
               }
               for (; *p != 0; p++) { vx1000_MailboxPutchar(*p); width--; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
               for (--width; width >= 0; width--) { vx1000_MailboxPutchar(' ');  }
            }
            else
            {
               for (p2 = p; *p2 != 0; p2++) { width--; } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
               for (--width; width >= 0; width--) { vx1000_MailboxPutchar(filler); }
               if ((showbase == 1) && (digif != '9'))
               {
                  vx1000_MailboxPutchar((VX1000_CHAR)'0');
                  if (digif != '7') { vx1000_MailboxPutchar((VX1000_CHAR)'x'); }
               }
               for (; *p != 0; p++) { vx1000_MailboxPutchar(*p); } /* PRQA S 0489 */ /* cannot avoid violating MISRA Rule 17.4 because memcopy and thus pointer incrementation is a core feature of this application */
            }
            continue;
         }
      }
      /* reaching here means we misunderstood the format string and assumed stupid argument. /
      /  type. To avoid invalid pointer accesses to any following arguments, we leave now:  */
      vx1000_MailboxPutchar('!');vx1000_MailboxPutchar(64);vx1000_MailboxPutchar('!');
      break; /* the for loop */
   } /* for */
   va_end(arglist); /* PRQA S 3199 */ /* it depends on the used compiler whether this statement has useful side effects or not */
   /* Transmit the terminating 0x00. */
   vx1000_MailboxPutchar( (VX1000_UINT8)0x00U );
}
#endif /* VX1000_PRINTF_MINIMAL */



#endif /* VX1000_MAILBOX_PRINTF */
#endif /* VX1000_MAILBOX  && !VX1000_COMPILED_FOR_SLAVECORES */


#if defined(VX1000_FKL_SUPPORT_ADDR) && !defined(VX1000_COMPILED_FOR_SLAVECORES)
void vx1000_FlashPrepareLoop(void)
{
   gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_FKL_REQ_DETECTED);
   VX1000_DISABLE_ALL_INTERRUPTS()                /* prevent other tasks / ISRs from overwriting RAM / reading flash */
   VX1000_STOP_OS_TIMING_PROTECTION()             /* prevent Autosar OS in SC2 / SC4 from killing the loop/kernel */
   VX1000_STOP_OTHER_CORES()                      /* prevent other cores (or DMA/PEC) from overwriting RAM / reading flash */
   VX1000_ENABLE_STANDARD_RAM_MAPPING()           /* repair nondefault RAM mapping (the FKL is linked to standard location) */

   (VX1000_FKL_WORKSPACE)->DeprotectState    = (VX1000_UINT16)(VX1000_FKL_STATE1CODE); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
   (VX1000_FKL_WORKSPACE)->DeprotectTrigger  = (VX1000_UINT16)(VX1000_FKL_TOSTATE1CODE); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
   (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
   (VX1000_FKL_WORKSPACE)->WdgData1 = (VX1000_UINT32)0xFFFFffffUL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
   (VX1000_FKL_WORKSPACE)->WdgData2 = (VX1000_UINT32)0xFFFFffffUL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
   (VX1000_FKL_WORKSPACE)->WdgData3 = (VX1000_UINT32)0xFFFFffffUL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
   *(VX1000_UINT32*)&((VX1000_FKL_WORKSPACE)->EntryPoint) = (VX1000_UINT32)0xFFFFFFFFUL; /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow invalidation of the function pointer */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */

   /* Now normal operation of the ECU (Appl + XCP instrumentation) is stopped: tell the tool how to further communicate: */
   gVX1000.MagicId = (VX1000_UINT32)(VX1000_FKL_SUPPORT_ADDR);
   gVX1000.ToolDetectState |= (VX1000_UINT32)(VX1000_TDS_FKL_FORCED_IDLE);
   /* Once the tool accepted the new communication area, no longer access gVX1000, because that location is likely to be */
   /* reused for storing the flash kernel code, so reads would return invalid data and writes could destroy the kernel.  */

   while (1) /* intentional infinite loop (can be left by pseudo call to FKL or by watchdog reset) */
   {
      /* The code inside this loop must not use stack (access non-register-ed local variables or call non-FKL functions) */
      /* (if that can't be ensured, we'd have to reload the SP with (VX1000_FKL_SUPPORT_ADDR-16): HW-SPECIFIC ASSEMBLY!) */
      if ((VX1000_FKL_WORKSPACE)->TransitionTimeout != 0) /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
      {
         (VX1000_FKL_WORKSPACE)->TransitionTimeout--; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
         VX1000_SERVE_WATCHDOG(&((VX1000_FKL_WORKSPACE)->WdgData1))
      }
      else
      {
         switch ((((VX1000_UINT32)((VX1000_FKL_WORKSPACE)->DeprotectState) << 8U) << 8U) | (VX1000_FKL_WORKSPACE)->DeprotectTrigger) /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
         {
            case ((VX1000_UINT32)(VX1000_FKL_STATE1CODE) << 16) | (VX1000_FKL_TOSTATE1CODE):
               /* still in the initialisation phase */
               break;
            case ((VX1000_UINT32)(VX1000_FKL_STATE1CODE) << 16) | (VX1000_FKL_TOSTATE2CODE):
               (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE2CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               break;
            case ((VX1000_UINT32)(VX1000_FKL_STATE2CODE) << 16) | (VX1000_FKL_TOSTATE3CODE):
               (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE3CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               break;
            case ((VX1000_UINT32)(VX1000_FKL_STATE3CODE) << 16) | (VX1000_FKL_TOSTATE4CODE):
               (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE4CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               break;
            case ((VX1000_UINT32)(VX1000_FKL_STATE4CODE) << 16) | (VX1000_FKL_TOSTATE5CODE):
               (VX1000_FKL_WORKSPACE)->TransitionTimeout = (VX1000_UINT32)(VX1000_FKL_TRANSITION_TIMEOUT); /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               (VX1000_FKL_WORKSPACE)->DeprotectState = VX1000_FKL_STATE5CODE; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               break;
            case ((VX1000_UINT32)(VX1000_FKL_STATE5CODE) << 16) | (VX1000_FKL_LAUNCHCODE):
               (VX1000_FKL_WORKSPACE)->TransitionTimeout = 1UL; /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               if (*(VX1000_UINT32*)&((VX1000_FKL_WORKSPACE)->EntryPoint) != 0xFFFFFFFFUL)  /* PRQA S 0310 */ /* accept violating MISRA Rule 11.4 to allow checking for invalidated function pointer */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               {
                  ((VX1000_FKL_WORKSPACE)->EntryPoint)((VX1000_FKL_WORKSPACE)->FklParam);  /* call the FKL: will not return here */ /* PRQA S 0306 */ /* cannot avoid violating MISRA Rule 11.3 because access to unallocated address space requires usage of pointers */
               }
               break;
            default:
               /* bad trigger sequence detected */
               while (1) /* intentional infinite loop without watchdog serving, will lead to watchdog reset */
               {
                  /* intentionally left empty */
               }
               /*break; /-* unreachable code, intentionally here to please MISRA checkers */
         }
      }
   }
}
#endif /* VX1000_FKL_SUPPORT_ADDR  && !VX1000_COMPILED_FOR_SLAVECORES */


#if !defined(VX1000_COMPILED_FOR_SLAVECORES) /* global data have to exist only once (in shared memory) */

/* The following is VX1000_DATA, but split to allow separate linkage of gVX1000 at a userdefined address */
VX1000_STIM_BENCHMARK_DATA
VX1000_ECUID_DATA
VX1000_OLDA_BENCHMARK_DATA
VX1000_COLDSTART_BENCHMARK_DATA
VX1000_HOOK_CONTROL_DATA

/* include userdefined lines with optional section pragmas to force individual linkage of VX1000 structure data. */
#define VX1000_SECTION_START_STRUCT_C
#include "vx1000_mpc5xxx_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_SECTION_START_STRUCT_NEGATE_C

VX1000_STRUCT_DATA

/* include userdefined lines with optional section pragmas to restore previous linkage of data: */
#define VX1000_SECTION_END_STRUCT_C
#include "vx1000_mpc5xxx_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_SECTION_END_STRUCT_NEGATE_C

#endif /* !VX1000_COMPILED_FOR_SLAVECORES */

/* Note that we were using nested section switches here (which might be unsupported by some compilers but has the    */
/* advantage of not requiring #undefs (those would violate the MISRA coding guidelines) nor VX1000_SECTION_xxx_2     */
/* defines (those would spoil the yyy_cfg.h file). This means that we SHOULDN'T PLACE ANY FURTHER CODE OR DATA below */
 
/* include userdefined lines with optional section pragmas to restore standard linkage of code and/or data: */
#define VX1000_SECTION_END_MODULE_C
#include "vx1000_mpc5xxx_cfg.h" /* PRQA S 5087 */ /* willingly violating MISRA Rule 19.1 because the section pragmas are needed exactly here (and not at the start of the file) */
#define VX1000_SECTION_END_MODULE_NEGATE_C

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

