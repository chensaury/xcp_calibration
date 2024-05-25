/*------------------------------------------------------------------------------- */
/* vx1000_mpc5xxx.h                                                               */
/* Program instrumentation for Vector VX with FSL/STM PowerPC xPC55xx and xPC56xx */
/* Version 2.0e 09.08.2012                                                        */
/* Vector Informatik GmbH                                                         */
/*                                                                                */
/* Don't modify this file, parameters are defined in vx1000_mpc5xxx_cfg.h         */
/*------------------------------------------------------------------------------- */


/* ----------------------------------------------------------------------------------------------------------------------- /
/ Status of MISRA conformance:                                                                                             /
/ ---------------------------                                                                                              /
/  * required rule 2.2 "usage of c++ comments"                                                                             /
/     - violated because there exists no MISRA-conform variadic macro definition                                           /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * advisory rule 12.11 "wraparound in const unsigned int computation"                                                    /
/     - violated only in a preprocessor assertion                                                                          /
/                                                                                                                          /
/  * required rule 19.4 "complete statement inside a macro"                                                                /
/     - todo                                                                                                               /
/                                                                                                                          /
/  * advisory rule 19.7 "functions vs. macros"                                                                             /
/     - violated because a MISRA-conform workaround would induce configuration-dependent MISRA violations in user's code   /
/     - see individual justifications of the particular violations in the code                                             /
/                                                                                                                          /
/  * required rule 19.10 "macro parameter used without parentheses"                                                        /
/     - todo ( hint: a dummy-"##" might serve as a workaraound... )                                                        /
/                                                                                                                          /
/------------------------------------------------------------------------------------------------------------------------ */

#if !defined(VX1000_MPC5XXX_H)
#define VX1000_MPC5XXX_H

#define VX1000_FILE_VERSION 0x020e


/* include userdefined lines with optional section pragmas to force individual linkage of VX1000 code and/or data: */
#define VX1000_SECTION_START_MODULE_H
#include "vx1000_mpc5xxx_cfg.h"
#define VX1000_SECTION_START_MODULE_NEGATE_H


/*------------------------------------------------------------------------------ */
/* Datatypes */

typedef unsigned int   VX1000_UINT32;
typedef unsigned short VX1000_UINT16;
typedef unsigned char  VX1000_UINT8;
typedef signed int     VX1000_INT32;
typedef signed short   VX1000_INT16;
typedef signed char    VX1000_INT8;
typedef int            VX1000_INT;
typedef long           VX1000_LONG;   /* needed for sizeof expression */
typedef char           VX1000_CHAR;   /* used by strings, __date etc; compile options may specify whether signed or not */
typedef float          VX1000_FLOAT;  /* needed for sizeof expression */
typedef double         VX1000_DOUBLE; /* needed for sizeof expression */
typedef long double    VX1000_LDOUBL; /* needed for sizeof expression */


/*---------------------------------------------------------------------------------------------------- */
/* Configuration */


/* Include user specified defines. */
#include "vx1000_mpc5xxx_cfg.h"


#if defined(VX1000_COMPILED_FOR_SLAVECORES)
/* On multicore systems with different instruction sets, the same function must exist multiple times, so add suffixes: */
#define VX1000_SUFFUN(F) F ## _ ## VX1000_COMPILED_FOR_SLAVECORES  /* PRQA S 3410 */ /* Willingly violating MISRA Rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#else /* !VX1000_COMPILED_FOR_SLAVECORES */
#define VX1000_SUFFUN(F) F /* direct mapping */ /* PRQA S 3410 */ /* Willingly violating MISRA Rule 19.10 because extra parentheses would change the meaning of the code (result is a label) */
#endif /* !VX1000_COMPILED_FOR_SLAVECORES */


/*---------------------------------------------------------------------------------------------------- */
/* Defaults */

#if !defined(VX1000_ENTER_SPINLOCK)
#define VX1000_ENTER_SPINLOCK()
#endif /* !VX1000_ENTER_SPINLOCK */
#if !defined(VX1000_LEAVE_SPINLOCK)
#define VX1000_LEAVE_SPINLOCK()
#endif /* !VX1000_LEAVE_SPINLOCK */

/*---------------------------------------------------------------------------------------------------- */
/* Default clock */

#if !defined(VX1000_CLOCK) && !defined(VX1000_DISABLE_INSTRUMENTATION)
/* start of obsolete code */
#if defined(VX1000_CLOCK_EMIOS_CHANNEL)
#define VX1000_CLOCK_TICKS_PER_US  (256)
#define VX1000_CLOCK() VX1000_Clock()
extern VX1000_UINT32 VX1000_Clock( void );
#elif defined(VX1000_CLOCK_TB)
#define VX1000_CLOCK() VX1000_Clock()
extern VX1000_UINT32 VX1000_Clock( void );
#else /* !VX1000_CLOCK_TB */
/* end of obsolete code */
#error Please define VX1000_CLOCK() as a free running 32 bit timer of desired resolution
#endif /* !VX1000_CLOCK_TB */
#endif /* !VX1000_CLOCK, !VX1000_DISABLE_INSTRUMENTATION */


#if defined(VX1000_CLOCK_TICKS_PER_BASE)

#if !defined(VX1000_CLOCK_TICKS_BASE_NS) && !defined(VX1000_DISABLE_INSTRUMENTATION)
#error Please define VX1000_CLOCK_TICKS_BASE_NS as the time bas in ns during which VX1000_CLOCK_TICKS_PER_BASE ticks occur
#endif /* !VX1000_CLOCK_TICKS_BASE_NS && !VX1000_DISABLE_INSTRUMENTATION */

#else /* !VX1000_CLOCK_TICKS_PER_BASE */

#if defined(VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_PER_BASE    (VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_BASE_NS     1000000000UL
#elif defined(VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_PER_BASE    (VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_BASE_NS     1000000UL
#elif defined(VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_PER_BASE    (VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_BASE_NS     1000UL
#elif !defined(VX1000_DISABLE_INSTRUMENTATION)
#error Please define VX1000_CLOCK_TICKS_PER_US or VX1000_CLOCK_TICKS_PER_MS or VX1000_CLOCK_TICKS_PER_S
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

#endif /* !VX1000_CLOCK_TICKS_PER_BASE */

#if !defined(VX1000_CLOCK_TICKS_PER_S)
#define VX1000_CLOCK_TICKS_PER_S ((1000000000UL * (VX1000_CLOCK_TICKS_PER_BASE)) / (VX1000_CLOCK_TICKS_BASE_NS))
#endif /* !VX1000_CLOCK_TICKS_PER_S */

#if !defined(VX1000_CLOCK_TICKS_PER_MS)
#define VX1000_CLOCK_TICKS_PER_MS ((1000000UL * (VX1000_CLOCK_TICKS_PER_BASE)) / (VX1000_CLOCK_TICKS_BASE_NS))
#endif /* !VX1000_CLOCK_TICKS_PER_MS */

#if !defined(VX1000_CLOCK_TICKS_PER_US)
#define VX1000_CLOCK_TICKS_PER_US ((1000UL * (VX1000_CLOCK_TICKS_PER_BASE)) / (VX1000_CLOCK_TICKS_BASE_NS))
#endif /* !VX1000_CLOCK_TICKS_PER_US */


/* Default timeout for cold start initialization in ms */
#if !defined(VX1000_COLDSTART_TIMEOUT_MS)
#define VX1000_COLDSTART_TIMEOUT_MS 100UL
#endif /* !VX1000_COLDSTART_TIMEOUT_MS */


/*---------------------------------------------------------------------------------------------------- */
/* Defines */

#if defined(VX1000_DISABLE_INSTRUMENTATION)

#define VX1000_STORE_TIMESTAMP(t)    /* empty */
#define VX1000_STORE_EVENT(e)        /* empty */

#else /* !VX1000_DISABLE_INSTRUMENTATION */
/* Store the time t into gVX1000.EventTimestamp (use all 32bit -- is only avoided in VX1000_FAST_TRACE_EVENT.  */
#define VX1000_STORE_TIMESTAMP(t) gVX1000.EventTimestamp = (t);

/* Store the event ID e into gVX1000.EventNumber (use all 32bit -- is only avoided in VX1000_FAST_TRACE_EVENT. */
#define VX1000_STORE_EVENT(e) gVX1000.EventNumber = (e);
#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* Special Events */
#define VX1000_EVENT_RAMZERO_START    0x00010000UL
#define VX1000_EVENT_RAMZERO_DONE     0x00010001UL
#define VX1000_EVENT_RAMSYNC_START    0x00010002UL
#define VX1000_EVENT_MAILBOX_INIT     0x00020000UL
#define VX1000_EVENT_MAILBOX_UPDATE   0x00020001UL
#define VX1000_EVENT_MAILBOX_RESETREQ 0x00020002UL
#define VX1000_EVENT_STIM_INIT        0x00030100UL
#define VX1000_EVENT_STIM_ACK         0x00030101UL
#define VX1000_EVENT_STIM_TIMEOUT(e)  (0x00030200UL | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_EVENT_STIM_ERR(e)      (0x00030300UL | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_EVENT_STRUCT_INIT      0x00040000UL
#define VX1000_EVENT_GP(e)            (0x00050000UL | (e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 because a function call would inhibit constant propagation of the compiler */
#define VX1000_ECU_EVT_SW_RESET       VX1000_EVENT_GP(0x00000001UL)
#define VX1000_ECU_EVT_OLDA_OVERLOAD  VX1000_EVENT_GP(0x00000002UL)
#define VX1000_ECU_EVT_SW_RESET_FAIL  VX1000_EVENT_GP(0x00000003UL)


/* Check the configuration for plausibility */
#if !defined(VX1000_DISABLE_INSTRUMENTATION)

#if defined(VX1000_STIM_BY_OLDA) && !defined(VX1000_OLDA)
#error VX1000_STIM_BY_OLDA cannot be enabled while VX1000_OLDA is disabled!
#endif /* VX1000_STIM_BY_OLDA && !VX1000_OLDA */

#if defined(VX1000_STIM_BY_OLDA) && !defined(VX1000_STIM)
#error VX1000_STIM_BY_OLDA cannot be enabled while VX1000_STIM is disabled!
#endif /* VX1000_STIM_BY_OLDA && !VX1000_STIM */


/* To save memory, the number range for stim events may be reduced, maximum is 31  */
#if !defined(VX1000_STIM_EVENT_COUNT)
#define VX1000_STIM_EVENT_COUNT 31   /* Count of STIM events used starting from VX1000_STIM_EVENT_OFFSET */
#elif VX1000_STIM_EVENT_COUNT > 31
#error "VX1000_STIM_EVENT_COUNT must be <= 31"
#endif /* VX1000_STIM_EVENT_COUNT && VX1000_STIM_EVENT_COUNT > 31*/

#if !defined(VX1000_STIM_EVENT_OFFSET)
#define VX1000_STIM_EVENT_OFFSET 0U   /* Number of the first STIM event */
#elif (VX1000_STIM_EVENT_OFFSET > 30)
#error "Event numbers must be <= 30!"
#endif /* VX1000_STIM_EVENT_OFFSET && VX1000_STIM_EVENT_OFFSET > 30 */

#if !defined(VX1000_OLDA_EVENT_COUNT)
#define VX1000_OLDA_EVENT_COUNT 31U
#elif VX1000_OLDA_EVENT_COUNT > 31U
#error "VX1000_OLDA_EVENT_COUNT must be <= 31U!"
#endif /* VX1000_OLDA_EVENT_COUNT && VX1000_OLDA_EVENT_COUNT > 31 */

#if defined(VX1000_HOOK_ENABLE) && !defined(VX1000_HOOK_COUNT)
#error VX1000_HOOK_COUNT must be also defined when VX1000_HOOK_ENABLE is enabled!
#endif /* VX1000_HOOK_ENABLE && !VX1000_HOOK_COUNT */

#if defined(VX1000_HOOK_COUNT) && ((VX1000_HOOK_COUNT > 255) || (VX1000_HOOK_COUNT == 0))
#error VX1000_HOOK_COUNT must be defined in the range [1..255]
#endif /* VX1000_HOOK_COUNT */

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* States */

/* ToolDetectState */
#define VX1000_TDS_INIT               0x00000001UL    /* VX1000_INIT() has been called */
#define VX1000_TDS_DETECT             0x00000002UL    /* VX1000_DETECT_VX() has been called */
#define VX1000_TDS_DETECTED           0x00000004UL    /* VX1000 was detected by VX1000_DETECT_VX() */
#define VX1000_TDS_COLDSTART_DONE     0x00000010UL    /* Coldstart handshake successfully executed */
#define VX1000_TDS_COLDSTART_TIMEOUT  0x00000020UL    /* Coldstart handshake resulted in timeout */
#define VX1000_TDS_COLDSTART_DELAY    0x00000040UL    /* Coldstart Delay has been entered */
#define VX1000_TDS_APPRST             0x00000080UL    /* Resume after application reset done */
#define VX1000_TDS_FKL_REQ_DETECTED   0x00000100UL    /* FlashPrepare request detected: trying to handle it */
#define VX1000_TDS_FKL_REQ_IGNORED    0x00000200UL    /* FlashPrepare request could not be served right now; app still runs */
#define VX1000_TDS_FKL_FORCED_IDLE    0x00000400UL    /* request served: ECU stays idle; FKL can be downloaded by the tool; */
                                                      /* gVX1000.MagicId contains a pointer to the new communication space. */
#define VX1000_TDS_ERROR              0x00001000UL    /* VX1000_INIT() detected a misconfiguration */

#define VX1000_TDS_COLDSTART_CHS_BUSY 0x00010000UL    /* Coldstart checksum calculation ongoing */
#define VX1000_TDS_COLDSTART_CHS_DONE 0x00020000UL    /* Coldstart checksum calculation done */
/* ToolCtrlState */
#define VX1000_TCS_MAGIC_PREFIX       0xFEC70000UL    /* Used when VX handshaking via trace reg (bypassing the memory I/F)? */
#define VX1000_TCS_PRESENT            0x00000001UL    /* VX1000 is present */
#define VX1000_TCS_COLDSTART_DELAY    0x00000002UL    /* VX1000 requests coldstart delay */
#define VX1000_TCS_COLDSTART_DONE     0x00000004UL    /* VX1000 coldstart configuration done */
#define VX1000_TCS_FKL_REQUEST        0x00000008UL    /* VX1000 requests the appl to go idle and prepare to jump to a ptr */


/*---------------------------------------------------------------------------------------------------- */
/* VX1000 Detection */

#if defined(VX1000_DETECTION)

/* Check whether a VX1000 was already detected by VX1000_DETECT_VX() */
/*#define VX1000_DETECTED()   ((gVX1000.ToolCtrlState  & (VX1000_TDS_DETECTED)) != 0) //really "Ctrl & TDS"? and not #define VX1000_DETECTED() ((gVX1000.ToolDetectState & (VX1000_TDS_DETECTED)) != 0)*/
#define VX1000_DETECTED() (((gVX1000.ToolCtrlState & (VX1000_TCS_PRESENT)) != 0UL) || ((gVX1000.ToolDetectState & (VX1000_TDS_DETECTED)) != 0UL))

/* Check if a VX is connected and powered. This API is always enabled? */
/* Must be called after VX1000_INIT() before any other VX1000_xxxx() routine is called */
/* Returns true (!=0) if VX is connected and online  */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_DetectVx)(void);
#define VX1000_DETECT_VX(     )       VX1000_SUFFUN(vx1000_DetectVx)()  /* usable in/as an expression  */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_DETECT_VX_VOID() (void)VX1000_SUFFUN(vx1000_DetectVx)(); /* usable as a whole statement */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_DETECTION */

#define VX1000_DETECTED()        (0)        /* means "no VX detected" */
#define VX1000_DETECT_VX(     )  (0)        /* means "no VX detected" */
#define VX1000_DETECT_VX_VOID()             /* empty */

#endif /* !VX1000_DETECTION */

#define VX1000_DETECT_BENCHMARK_DATA


/*---------------------------------------------------------------------------------------------------- */
/* Coldstart */

#define VX1000_COLDSTART_CHS_MAGIC 0xFEC70A09UL
#if defined(VX1000_COLDSTART_BENCHMARK) && defined(VX1000_OLDA)
extern VX1000_UINT32 gVX1000_DETECT_StartTime, gVX1000_DETECT_ToolDetectTime, gVX1000_DETECT_ChecksumDoneTime, gVX1000_DETECT_EndTime;
#define VX1000_COLDSTART_BENCHMARK_DATA VX1000_UINT32 gVX1000_DETECT_StartTime, gVX1000_DETECT_ToolDetectTime, gVX1000_DETECT_ChecksumDoneTime, gVX1000_DETECT_EndTime;
#else /* !VX1000_COLDSTART_BENCHMARK || !VX1000_OLDA*/
#define VX1000_COLDSTART_BENCHMARK_DATA     /* empty */
#endif /* !VX1000_COLDSTART_BENCHMARK || !VX1000_OLDA*/


/*---------------------------------------------------------------------------------------------------- */
/* Flash kernel download support */
#if defined(VX1000_FKL_SUPPORT_ADDR)
extern void VX1000_SUFFUN(vx1000_FlashPrepareLoop)(void);
#define VX1000_DETECT_FKL_REQUESTS() \
 if (((gVX1000.ToolDetectState & (VX1000_TDS_DETECTED)) != 0) && ((gVX1000.ToolCtrlState & (VX1000_TCS_FKL_REQUEST)) != 0)) \
 {                                                                                                                          \
    VX1000_SUFFUN(vx1000_FlashPrepareLoop)();                                                                                              \
 }

typedef void VX1000_FKL_FCT(VX1000_UINT32);
typedef struct
{
   VX1000_UINT16 DeprotectTrigger;     /*  0+ */
   VX1000_UINT16 DeprotectState;       /*  2+ */
   VX1000_UINT32 TransitionTimeout;    /*  4+ */
   VX1000_UINT32 WdgData1;             /*  8+ */
   VX1000_UINT32 WdgData2;             /* 12+ */
   VX1000_UINT32 WdgData3;             /* 16+ */
   VX1000_UINT32 FklParam;             /* 20+ */
   VX1000_FKL_FCT *EntryPoint;         /* 24+ */
} VX1000_FKL_WORKSPACE_T;
#define VX1000_FKL_WORKSPACE           ((VX1000_FKL_WORKSPACE_T*)(void*)(0xFFFFffe0UL & (VX1000_UINT32)(VX1000_FKL_SUPPORT_ADDR)))
#define VX1000_FKL_TRANSITION_TIMEOUT  0xffffffffUL
#define VX1000_FKL_STATE1CODE          0x1243U
#define VX1000_FKL_STATE2CODE          0x2486U
#define VX1000_FKL_STATE3CODE          0x36c9U
#define VX1000_FKL_STATE4CODE          0x480cU
#define VX1000_FKL_STATE5CODE          0x5a4fU
#define VX1000_FKL_TOSTATE1CODE        0x6bf0U
#define VX1000_FKL_TOSTATE2CODE        0x7a0fU
#define VX1000_FKL_TOSTATE3CODE        0x891eU
#define VX1000_FKL_TOSTATE4CODE        0x98e1U
#define VX1000_FKL_TOSTATE5CODE        0xa72dU
#define VX1000_FKL_LAUNCHCODE          0xb6d2U
#else  /* !VX1000_FKL_SUPPORT_ADDR */
#if defined(VX1000_DISABLE_INSTRUMENTATION)
#define VX1000_DETECT_FKL_REQUESTS()   /* empty */
#else /* !VX1000_DISABLE_INSTRUMENTATION)*/
#define VX1000_DETECT_FKL_REQUESTS() \
 if (((gVX1000.ToolDetectState & (VX1000_TDS_DETECTED)) != 0) && ((gVX1000.ToolCtrlState & (VX1000_TCS_FKL_REQUEST)) != 0)) \
 {                                                                                                                          \
    gVX1000.ToolDetectState |= (VX1000_TDS_FKL_REQ_DETECTED) | (VX1000_TDS_FKL_REQ_IGNORED);                                \
 }
#endif /* !VX1000_DISABLE_INSTRUMENTATION */
#endif /* !VX1000_FKL_SUPPORT_ADDR */


/*---------------------------------------------------------------------------------------------------- */
/* VX1000 Mailbox */

#define VX1000_MAILBOX_OK              0UL
#define VX1000_MAILBOX_ERR_FULL        1UL
#define VX1000_MAILBOX_ERR_EMPTY       2UL
#define VX1000_MAILBOX_ERR_INDICES     3UL
#define VX1000_MAILBOX_ERR_SEQUENCE    4UL
#define VX1000_MAILBOX_ERR_SIZE        5UL
#define VX1000_MAILBOX_SLOT_RSVD       6UL
#define VX1000_MAILBOX_ERR_NULL        7UL
#define VX1000_MAILBOX_ERR_SPLIT_PEND  8UL

#if defined(VX1000_MAILBOX)

#define VX1000_MAILBOX_MAGIC           0xFEC70A06UL

/* viszr: For flashkernel usage, the Mailbox is increased to hold an XCP packet */
/* of 256 bytes plus the length dword. Maybe todo: move to vx1000_xxx_cfg.h */
#define VX1000_MAILBOX_SLOT_DWORDS     (64UL + 2UL)     /* must be at least 3 (=4 bytes + 8 bytes xcp command) */
#define VX1000_MAILBOX_SLOTS           8UL
#define VX1000_MAILBOX_FREE_WR_SLOTS   ((gVX1000.Mailbox.SM_ReadIdx-gVX1000.Mailbox.SM_WriteIdx-1U) & ((VX1000_MAILBOX_SLOTS)-1U))
#define VX1000_MAILBOX_USED_RD_SLOTS   (((VX1000_UINT32)(gVX1000.Mailbox.MS_WriteIdx - gVX1000.Mailbox.MS_ReadIdx)) & ((VX1000_MAILBOX_SLOTS) - 1UL))
#define VX1000_MAILBOX_NEXT(idx)       (((idx) + 1U) & ((VX1000_MAILBOX_SLOTS) - 1U))  /* PRQA S 3453 */ /* Accepting violation of MISRA Rule 19.7 because a function call would consume unnecessarily high resources */

typedef struct
{
   VX1000_UINT32  MagicId;        /* 0x00 */
   VX1000_UINT32  Version;        /* 0x04 */
   VX1000_UINT16  SlotSize;       /* 0x08 */
   VX1000_UINT8   MS_Slots;       /* 0x0A */
   VX1000_UINT8   SM_Slots;       /* 0x0B */
   VX1000_UINT32  MS_Ptr;         /* 0x0C */
   VX1000_UINT32  SM_Ptr;         /* 0x10 */
   VX1000_UINT8   MS_ReadIdx;     /* 0x14 */
   VX1000_UINT8   MS_WriteIdx;    /* 0x15 */
   VX1000_UINT8   SM_ReadIdx;     /* 0x16 */
   VX1000_UINT8   SM_WriteIdx;    /* 0x17 */
   VX1000_UINT16  RstReq;         /* 0x18 */
   VX1000_UINT16  RstAck;         /* 0x1A */
   VX1000_UINT32  MSData[VX1000_MAILBOX_SLOTS][VX1000_MAILBOX_SLOT_DWORDS]; /* 0x1C */
   VX1000_UINT32  SMData[VX1000_MAILBOX_SLOTS][VX1000_MAILBOX_SLOT_DWORDS];
} VX1000_MAILBOX_T;

#define VX1000_CRC_CMD_UNKNOWN         0x20U

#if defined(VX1000_MAILBOX_OVERLAY_CONTROL)

#define VX1000_CAL_ECU                 0x01U
#define VX1000_CAL_XCP                 0x02U
#define VX1000_CAL_ALL                 0x80U

#define VX1000_CRC_CMD_SYNTAX          0x21U
#define VX1000_CRC_OUT_OF_RANGE        0x22U
#define VX1000_CRC_WRITE_PROTECTED     0x23U
#define VX1000_CRC_ACCESS_DENIED       0x24U
#define VX1000_CRC_ACCESS_LOCKED       0x25U
#define VX1000_CRC_PAGE_NOT_VALID      0x26U
#define VX1000_CRC_PAGE_MODE_NOT_VALID 0x27U
#define VX1000_CRC_SEGMENT_NOT_VALID   0x28U

#endif /* VX1000_OVERLAY_CONTROL */

extern void VX1000_SUFFUN(vx1000_MailboxInit)(void);
#define VX1000_MAILBOX_INIT() VX1000_SUFFUN(vx1000_MailboxInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_Mailboxhandler)(void);
#define VX1000_MAILBOX_CONTROL() VX1000_SUFFUN(vx1000_MailboxHandler)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWrite)(VX1000_UINT32 len, const VX1000_CHAR* pBuf);
#define VX1000_MAILBOX_WRITE(     L, B)       VX1000_SUFFUN(vx1000_MailboxWrite)((L), (B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE_VOID(L, B) (void)VX1000_SUFFUN(vx1000_MailboxWrite)((L), (B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxRead)(VX1000_UINT32* pLen, VX1000_CHAR* pBuf);
#define VX1000_MAILBOX_READ(     L, B)       VX1000_SUFFUN(vx1000_MailboxRead)((L), (B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READ_VOID(L, B) (void)VX1000_SUFFUN(vx1000_MailboxRead)((L), (B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_DATA VX1000_MAILBOX_T Mailbox;
#define VX1000_MAILBOX_PTR ((VX1000_UINT32)&gVX1000.Mailbox)

#else /* !VX1000_MAILBOX */

#define VX1000_MAILBOX_INIT() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_CONTROL() /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE(     L, B) (VX1000_MAILBOX_ERR_FULL) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITE_VOID(L, B) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READ(     L, B)  (VX1000_MAILBOX_ERR_EMPTY) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READ_VOID(L, B)  /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_DATA
#define VX1000_MAILBOX_PTR 0UL

#endif /* !VX1000_MAILBOX */

#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PROVIDE_SPLITWRITE)
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWriteDone)(VX1000_UINT32 len);
#define VX1000_MAILBOX_WRITEDONE(      L)       VX1000_SUFFUN(vx1000_MailboxWriteDone)((L))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITEDONE_VOID( L) (void)VX1000_SUFFUN(vx1000_MailboxWriteDone)((L)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxWriteSplit)(VX1000_UINT32** ppBuf);
#define VX1000_MAILBOX_WRITESPLIT(     B)       VX1000_SUFFUN(vx1000_MailboxWriteSplit)((B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT_VOID(B) (void)VX1000_SUFFUN(vx1000_MailboxWriteSplit)((B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITWRITE */
#define VX1000_MAILBOX_WRITEDONE(      L) (VX1000_MAILBOX_ERR_SIZE) /* todo: find a better one */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITEDONE_VOID( L) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT(     B) (VX1000_MAILBOX_ERR_FULL) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_WRITESPLIT_VOID(B) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITWRITE */
#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PROVIDE_SPLITREAD)
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxReadDone)(void);
#define VX1000_MAILBOX_READDONE(     )       VX1000_SUFFUN(vx1000_MailboxReadDone)()  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READDONE_VOID() (void)VX1000_SUFFUN(vx1000_MailboxReadDone)(); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT32 VX1000_SUFFUN(vx1000_MailboxReadSplit)(VX1000_UINT32* pLen, VX1000_UINT32** ppBuf);
#define VX1000_MAILBOX_READSPLIT(     L, B)       VX1000_SUFFUN(vx1000_MailboxReadSplit)((L), (B))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT_VOID(L, B) (void)VX1000_SUFFUN(vx1000_MailboxReadSplit)((L), (B)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITREAD */
#define VX1000_MAILBOX_READDONE(     ) (VX1000_MAILBOX_ERR_SPLIT_PEND) /* todo: find a better one */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READDONE_VOID() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT(     L, B) (VX1000_MAILBOX_ERR_EMPTY) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_MAILBOX_READSPLIT_VOID(L, B) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PROVIDE_SPLITREAD */
#if defined(VX1000_MAILBOX) && (defined(VX1000_MAILBOX_OVERLAY_CONTROL) || defined(VX1000_MAILBOX_FLASH))
extern void VX1000_SUFFUN(vx1000_MailboxHandler)(void);
#define VX1000_MAILBOX_HANDLER() VX1000_SUFFUN(vx1000_MailboxHandler)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_MAILBOX || !(VX1000_MAILBOX_OVERLAY_CONTROL && VX1000_MAILBOX_FLASH) */
#define VX1000_MAILBOX_HANDLER() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_MAILBOX || !(VX1000_MAILBOX_OVERLAY_CONTROL && VX1000_MAILBOX_FLASH) */
#if defined(VX1000_MAILBOX) && defined(VX1000_MAILBOX_PRINTF)
void VX1000_SUFFUN(vx1000_MailboxPrintf)( const VX1000_CHAR *format, ... ); /* PRQA S 5069 */ /* Cannot avoid violating MISRA Rule 19.4 because a C++-based workaround would only violate other rules */
#define VX1000_PRINTF VX1000_SUFFUN(vx1000_MailboxPrintf)
#else  /* !VX1000_MAILBOX || !VX1000_MAILBOX_PRINTF */
/* todo: check whether "#define VX1000_PRINTF (void)" would be a bearable alternative to the c++ comment (preprocessors might throw it away during expansion!) */
#define VX1000_PRINTF  /* PRQA S 1011 */ // uses this c++ comment starter to disable rest of line - yes: violates MISRA Rule 2.2 and fails on multiline statements ...
#endif /* !VX1000_MAILBOX || !VX1000_MAILBOX_PRINTF */


/*---------------------------------------------------------------------------------------------------- */
/* VX1000 ECU ID */

#if defined(VX1000_ECUID) && defined(VX1000_ECUID_LEN)
extern const VX1000_UINT8 gVX1000_ECUID[(VX1000_ECUID_LEN) + 1U];
#define VX1000_ECUID_DATA const VX1000_UINT8 gVX1000_ECUID[(VX1000_ECUID_LEN) + 1U] = VX1000_ECUID;
#define VX1000_ECUID_PTR ((VX1000_UINT32)(void*)(VX1000_UINT8*)&gVX1000_ECUID[0])
#else /* !VX1000_ECUID || !VX1000_ECUID_LEN */
#define VX1000_ECUID_DATA
#define VX1000_ECUID_PTR  0UL
#define VX1000_ECUID_LEN  0U
#endif /* !VX1000_ECUID || !VX1000_ECUID_LEN */


/*---------------------------------------------------------------------------------------------------- */
/* OLDA */

#if defined(VX1000_OLDA)

#if defined(VX1000_OLDA_FORCE_V7)
#define VX1000_OLDA_VERSION            0x07U /* Olda Version 7 + 0x10 * Plattform code 0x0 (same as MPC56x) */
#define VX1000_OLDA_SIZE_SWAP_VALUE    0x00000000UL     /* dummy value, only used in coldstart verification */
#define VX1000_OLDA_SIZE_LENGTH        0x0              /* dummy value, only used in coldstart verification */
#define VX1000_OLDA_SIZE_OFFSET        0x0              /* dummy value, only used in coldstart verification */
#else  /* !VX1000_OLDA_FORCE_V7 */
#define VX1000_OLDA_VERSION            0x05U /* Olda Version 5 + 0x10 * Plattform code 0x0 (same as MPC56x) */
#if !defined(VX1000_OLDA_SIZE_SWAP_VALUE)
#define VX1000_OLDA_SIZE_SWAP_VALUE    0x00000000UL
#endif /* !VX1000_OLDA_SIZE_SWAP_VALUE */
#if !defined(VX1000_OLDA_SIZE_LENGTH)
#define VX1000_OLDA_SIZE_LENGTH        6UL
#endif /* !VX1000_OLDA_SIZE_LENGTH */
#if !defined(VX1000_OLDA_SIZE_OFFSET)
#define VX1000_OLDA_SIZE_OFFSET        22UL
#endif /* !VX1000_OLDA_SIZE_OFFSET */
#if ( ((VX1000_OLDA_SIZE_LENGTH) < 4U) || ((VX1000_OLDA_SIZE_LENGTH) > 7U) )
#error "VX1000_OLDA_SIZE_LENGTH not in allowed range of 4..7!"
#endif
#if ((VX1000_OLDA_SIZE_OFFSET) + (VX1000_OLDA_SIZE_LENGTH) > 32U)
#error "VX1000_OLDA_SIZE_OFFSET + VX1000_OLDA_SIZE_LENGTH exceeds DWORD border!"
#endif
#endif /* !VX1000_OLDA_FORCE_V7 */

#define VX1000_OLDA_MAGIC              0x2603U


/* Generate Olda Size mask and replacement */
#define VX1000_OLDA_SIZE_MASK ( ((1UL << (VX1000_OLDA_SIZE_LENGTH)) - 1UL) << (VX1000_OLDA_SIZE_OFFSET))
#define VX1000_OLDA_SIZE_REPLACEMENT (VX1000_UINT32) (((VX1000_OLDA_SIZE_SWAP_VALUE) << (VX1000_OLDA_SIZE_OFFSET)) & (VX1000_OLDA_SIZE_MASK))

#if (((VX1000_OLDA_SIZE_SWAP_VALUE) & (~((1UL << (VX1000_OLDA_SIZE_LENGTH)) - 1UL))) != 0UL) /* PRQA S 3302 */ /* Accepted violation of MISRA Rule 12.11 because this formula deals with bitfields and not with numbers */
#error Overlapping data fields inside the olda descriptors (SIZE_SWAP_VALUE vs. SIZE_LENGTH)!
#endif /* VX1000_OLDA_SIZE_SWAP_VALUE , VX1000_OLDA_SIZE_LENGTH */


/* Default memory size */
#if !defined(VX1000_OLDA_MEMORY_SIZE)
#define VX1000_OLDA_MEMORY_SIZE        1024 /* Default to 1K when not provided by vx1000_mpc5xxx_cfg.h */
#endif /* !VX1000_OLDA_MEMORY_SIZE */

/* Feature flags */
#if defined(VX1000_STIM_BY_OLDA)
#define VX1000_FEAT_OLDA_STIM            (1U << 2U)
#else /* !VX1000_STIM_BY_OLDA */
#define VX1000_FEAT_OLDA_STIM            (0U << 2U)
#endif /* !VX1000_STIM_BY_OLDA */
#if defined(VX1000_OLDA_OVERLOAD_DETECTION)
#define VX1000_FEAT_OLDA_OVERLOADDETECT  (1U << 0U)
#else /* !VX1000_OLDA_OVERLOAD_DETECTION */
#define VX1000_FEAT_OLDA_OVERLOADDETECT  (0U << 0U)
#endif /* !VX1000_OLDA_OVERLOAD_DETECTION */

typedef struct
{
   VX1000_UINT32   EventCounter;
   VX1000_UINT32   EventTimestamp;
   VX1000_UINT32   TransferDest;
   VX1000_UINT16   TransferIndex;
   VX1000_UINT16   TransferCount;
} VX1000_OLDA_EVENT_T;

typedef struct
{
   VX1000_UINT16        MagicId;              /* 0x00 */
   VX1000_UINT8         Version;              /* 0x02 */
   VX1000_UINT8         Running;              /* 0x03 */
   VX1000_UINT32        MemoryAddr;           /* 0x04 */
   VX1000_UINT16        MemorySize;           /* 0x08 */
   VX1000_UINT16        EventCount;           /* 0x0A */
   VX1000_OLDA_EVENT_T *EventList;            /* 0x0C */
   VX1000_UINT32       *TransferList;         /* 0x10 */
   VX1000_UINT8         SizeLengthNOffset;    /* 0x14 */
   VX1000_UINT8         SizeSwapValue;        /* 0x15 */
   VX1000_UINT16        OldaFeatures;         /* 0x16 */
   VX1000_UINT32        Res1;                 /* 0x18 */
   VX1000_UINT32        Res2;                 /* 0x1C */
#if !defined(VX1000_OLDA_MEMORY_ADDR)
   VX1000_UINT32       Data[(VX1000_OLDA_MEMORY_SIZE) / 4UL];
#endif /* !VX1000_OLDA_MEMORY_ADDR */
} VX1000_OLDA_T;


extern void VX1000_SUFFUN(vx1000_OldaInit)( void );
#define VX1000_OLDA_INIT() VX1000_SUFFUN(vx1000_OldaInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_OldaEvent)( VX1000_UINT8 eventNumber );
#define VX1000_OLDA_EVENT(x) VX1000_SUFFUN(vx1000_OldaEvent)((x)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_OLDA_DATA VX1000_OLDA_T Olda;
#define VX1000_OLDA_PTR ((VX1000_UINT32)&gVX1000.Olda)

#if defined(VX1000_OLDA_BENCHMARK)
extern VX1000_UINT32 gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];
extern VX1000_UINT32 gVX1000_OLDA_TransferSize[VX1000_OLDA_EVENT_COUNT];
extern VX1000_UINT32 gVX1000_OLDA_TransferCount[VX1000_OLDA_EVENT_COUNT];
#define VX1000_OLDA_BENCHMARK_DATA                                      \
   VX1000_UINT32 gVX1000_OLDA_Duration[VX1000_OLDA_EVENT_COUNT];        \
   VX1000_UINT32 gVX1000_OLDA_TransferSize[VX1000_OLDA_EVENT_COUNT];    \
   VX1000_UINT32 gVX1000_OLDA_TransferCount[VX1000_OLDA_EVENT_COUNT];
#else /* !VX1000_OLDA_BENCHMARK */
#define VX1000_OLDA_BENCHMARK_DATA
#endif /* VX1000_OLDA_BENCHMARK */

#else /* !VX1000_OLDA */

#define VX1000_OLDA_EVENT(x)
#define VX1000_OLDA_INIT()
#define VX1000_OLDA_DATA
#define VX1000_OLDA_PTR 0UL
#define VX1000_OLDA_BENCHMARK_DATA

#endif /* !VX1000_OLDA */


/*---------------------------------------------------------------------------------------------------- */
/* VX1000 Stim */

#if defined(VX1000_STIM)

#define VX1000_STIM_MAGIC  0xFEC70A07UL

typedef struct
{
   VX1000_UINT32 MagicId;
   VX1000_UINT16 Version;
   VX1000_UINT16 Control;
   VX1000_UINT8  EvtOffset;
   VX1000_UINT8  EvtNumber;
   VX1000_UINT16 Reserved;
   struct VX1000_stim_event
   {
      VX1000_UINT8 Ctr;
      VX1000_UINT8 RqCtr;
      VX1000_UINT8 Enable;
      VX1000_UINT8 Copying;
   } Event[VX1000_STIM_EVENT_COUNT];
   VX1000_UINT16 Enable;
   VX1000_UINT16 TimeoutCtr;
   VX1000_UINT16 TimeoutCtr2;
} VX1000_STIM_T;

/* stim API */
extern void VX1000_SUFFUN(vx1000_StimInit)(void);
#define VX1000_STIM_INIT() VX1000_SUFFUN(vx1000_StimInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DATA VX1000_STIM_T Stim;
#define VX1000_STIM_PTR ((VX1000_UINT32)&gVX1000.Stim)
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_StimWait)( VX1000_UINT8 stim_event, VX1000_UINT8 copy_enable, VX1000_UINT32 timeout_us );
#define VX1000_STIM_WAIT(     E, T)       VX1000_SUFFUN(vx1000_StimWait)((E), 1, (T) )  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_VOID(E, T) (void)VX1000_SUFFUN(vx1000_StimWait)((E), 1, (T) ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_Stimulate)( VX1000_UINT8 stim_trigger_event, VX1000_UINT8 stim_event,
                                                     VX1000_UINT8 cycle_delay, VX1000_UINT32 timeout_us);
#define VX1000_STIMULATE(     D, S, P, T)       VX1000_SUFFUN(vx1000_Stimulate)((D), (S), (P), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T) (void)VX1000_SUFFUN(vx1000_Stimulate)((D), (S), (P), (T)); /* usable as a whole statement */
 /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimControl)( void );
#define VX1000_STIM_CONTROL() VX1000_SUFFUN(vx1000_StimControl)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassTrigger)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event );
#define VX1000_BYPASS_TRIGGER(     D, S)       VX1000_SUFFUN(vx1000_BypassTrigger)((D), (S))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER_VOID(D, S) (void)VX1000_SUFFUN(vx1000_BypassTrigger)((D), (S)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_BypassWait)( VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us);
#define VX1000_BYPASS_WAIT(     S, T)       VX1000_SUFFUN(vx1000_BypassWait)((S), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT_VOID(S, T) (void)VX1000_SUFFUN(vx1000_BypassWait)((S), (T)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_Bypass)( VX1000_UINT8 daq_event, VX1000_UINT8 stim_event, VX1000_UINT32 timeout_us );
#define VX1000_BYPASS(      D, S, T)       VX1000_SUFFUN(vx1000_Bypass)( (D), (S), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_VOID( D, S, T) (void)VX1000_SUFFUN(vx1000_Bypass)( (D), (S), (T)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#if defined(VX1000_STIM_BENCHMARK)
extern volatile VX1000_UINT32 gVX1000_STIM_Begin[VX1000_STIM_EVENT_COUNT];
extern volatile VX1000_UINT32 gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT];
#if defined(VX1000_STIM_HISTOGRAM)
extern volatile VX1000_UINT32 gVX1000_STIM_Histogram[256];
extern volatile VX1000_UINT32 gVX1000_STIM_Histogram2[16];
#define VX1000_STIM_BENCHMARK_DATA \
   volatile VX1000_UINT32 gVX1000_STIM_Begin[VX1000_STIM_EVENT_COUNT]; \
   volatile VX1000_UINT32 gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT]; \
   volatile VX1000_UINT32 gVX1000_STIM_Histogram[256]; \
   volatile VX1000_UINT32 gVX1000_STIM_Histogram2[16];
#else /* !VX1000_STIM_HISTOGRAM */
#define VX1000_STIM_BENCHMARK_DATA \
   volatile VX1000_UINT32 gVX1000_STIM_Begin[VX1000_STIM_EVENT_COUNT]; \
   volatile VX1000_UINT32 gVX1000_STIM_Duration[VX1000_STIM_EVENT_COUNT];
#endif /* !VX1000_STIM_HISTOGRAM */
extern void VX1000_SUFFUN(vx1000_StimBenchmarkInit)( void );
#define VX1000_STIM_BENCHMARK_INIT() VX1000_SUFFUN(vx1000_StimBenchmarkInit)(); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimBenchmarkStimBegin)( VX1000_UINT8 stim_event );
#define VX1000_STIM_BENCHMARK_STIM_BEGIN(E) VX1000_SUFFUN(vx1000_StimBenchmarkStimBegin)( (E) ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimBenchmarkStimEnd)( VX1000_UINT8 stim_event, VX1000_UINT8 timeout_flag );
#define VX1000_STIM_BENCHMARK_STIM_END(E, F) VX1000_SUFFUN(vx1000_StimBenchmarkStimEnd)( (E), (F) ); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_STIM_BENCHMARK */
#define VX1000_STIM_BENCHMARK_DATA
#define VX1000_STIM_BENCHMARK_INIT() /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_BEGIN(E) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_END(E, F) /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_STIM_BENCHMARK */

#define VX1000_STIM_TIMEOUTS gVX1000.Stim.TimeoutCtr
#define VX1000_STIM_TIMEOUTS_IN_SEQ gVX1000.Stim.TimeoutCtr2

extern VX1000_UINT8 VX1000_SUFFUN(vx1000_StimActive)( VX1000_UINT8 stim_event );
#define VX1000_STIM_ACTIVE(S) VX1000_SUFFUN(vx1000_StimActive)((S))   /* usable in/as an expression */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern void VX1000_SUFFUN(vx1000_StimRequest)( VX1000_UINT8 stim_event );
#define VX1000_STIM_REQUEST(S) VX1000_SUFFUN(vx1000_StimRequest)((S)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#if defined(VX1000_STIM_BY_OLDA)
extern void VX1000_SUFFUN(vx1000_OldaStimRequestEvent)( VX1000_UINT8 eventNumber );
#define VX1000_STIM_REQUEST_EVENT(x) VX1000_SUFFUN(vx1000_OldaStimRequestEvent)((x)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#else /* !VX1000_STIM_BY_OLDA */
#define VX1000_STIM_REQUEST_EVENT(x) VX1000_EVENT((x)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#endif /* !VX1000_STIM_BY_OLDA */

#else /* !VX1000_STIM */

#define VX1000_STIM_INIT()                    /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_DATA                      /* empty */
#define VX1000_STIM_PTR 0UL                   /* "invalid" */
#define VX1000_STIM_BENCHMARK_DATA            /* empty */
#define VX1000_STIM_WAIT(     E, T) (1)       /* return code for "timeout" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_WAIT_VOID(E, T)           /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE(     D, S, P, T) (0) /* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIMULATE_VOID(D, S, P, T)     /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_ACTIVE(S) (0)             /* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_CONTROL()                 /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_REQUEST(S)                /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER(     D, S) (0)  /* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_TRIGGER_VOID(D, S)      /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT(     S, T) (0)     /* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_WAIT_VOID(S, T)         /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS(     D, S, T) (0)       /* return code for "inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_BYPASS_VOID(D, S, T)           /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_INIT()          /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_BEGIN(E)   /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_STIM_BENCHMARK_STIM_END(E, F)  /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_STIM */


/*---------------------------------------------------------------------------------------------------- */
/* VX1000 Generic Hooking Control */

#if defined(VX1000_HOOK_ENABLE)

#define VX1000_HOOK_MAGIC                0x2603U
#define VX1000_HOOK_COPY_ENABLE          (1U << 0U)   /* Enable copy of stim data */
#define VX1000_HOOK_CODE_ALWAYS          (1U << 1U)   /* Run the original code always */
#define VX1000_HOOK_CODE_TIMEOUT         (1U << 2U)   /* Run the original code after timeout */
#define VX1000_HOOK_CODE_RESERVED        (1U << 3U)
#define VX1000_HOOK_TRIGGER_EVENT_ENABLE (1U << 4U)   /* Trigger stim_event always, even if there is no bypass  */
#define VX1000_HOOK_DAQ_EVENT_ENABLE     (1U << 5U)   /* Trigger daq_event always immediately after original code,
                                                      /  even if there is no bypass */
typedef struct
{
   VX1000_UINT16 magic;
   VX1000_UINT16 count;
   VX1000_UINT16 active_id;
   VX1000_UINT16 active_index;
   struct
   {
      VX1000_UINT16 id;
#if defined(VX1000_STIM)  
      VX1000_UINT8 stim_event;
#endif /* VX1000_STIM */
      VX1000_UINT8 trigger_event;
      VX1000_UINT8 daq_event;
      VX1000_UINT8 control;
   } table[VX1000_HOOK_COUNT];
} VX1000_HOOK_T;
extern volatile VX1000_HOOK_T gVX1000_HookControl;
#define VX1000_HOOK_CONTROL_DATA volatile VX1000_HOOK_T gVX1000_HookControl;
extern void VX1000_SUFFUN(vx1000_HookInit)( void );
#define VX1000_HOOK_INIT() VX1000_SUFFUN(vx1000_HookInit)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_EnterHook)( VX1000_UINT16 hook_id );
#define VX1000_HOOK_TRIGGER(     I)       VX1000_SUFFUN(vx1000_EnterHook)((I))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_TRIGGER_VOID(I) (void)VX1000_SUFFUN(vx1000_EnterHook)((I)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
extern VX1000_UINT8 VX1000_SUFFUN(vx1000_LeaveHook)( VX1000_UINT16 hook_id, VX1000_UINT32 timeout);
#define VX1000_HOOK_WAIT(     I, T)       VX1000_SUFFUN(vx1000_LeaveHook)((I), (T))  /* usable in/as an expression  */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_WAIT_VOID(I, T) (void)VX1000_SUFFUN(vx1000_LeaveHook)((I), (T)); /* usable as a whole statement */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK(id, timeout, code)                                    \
   if (VX1000_SUFFUN(vx1000_EnterHook)((id)) == 0)                        \
   {                                                                      \
      code /* PRQA S 3410 */ /*Cannot avoid violating MISRA Rule 19.10 because this parameter cannot be set into parentheses*/ \
      VX1000_SUFFUN(vx1000_LeaveHook)((id), (timeout));                   \
   }                                                                      \
   else                                                                   \
   {                                                                      \
      if (VX1000_SUFFUN(vx1000_LeaveHook)((id), (timeout)) == 3U)         \
      {                                                                   \
         code /*PRQA S 3410*/ /*Cannot avoid violating MISRA Rule 19.10 because this parameter cannot be set into parentheses*/\
      }                                                                   \
   } /* PRQA S 3453 */ /* Impossible to not violate MISRA Rule 19.7 because a conform function would have to execute code passed as an argument */
   
extern void VX1000_SUFFUN(vx1000_GenericEvent)( VX1000_UINT16 hook_id );
#define VX1000_GENERIC_EVENT(id) VX1000_SUFFUN(vx1000_GenericEvent)((id)); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_HOOK_ENABLE */

#define VX1000_HOOK_CONTROL_DATA        /* empty */
#define VX1000_HOOK_INIT()              /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_TRIGGER(     I) (0) /* this means "execute original code" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_TRIGGER_VOID(I)     /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_WAIT(     I, T) (0) /* this means "bypassing inactive" */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK_WAIT_VOID(I, T)     /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_HOOK(id, code)           /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */
#define VX1000_GENERIC_EVENT(I)         /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_HOOK_ENABLE */


/*---------------------------------------------------------------------------------------------------- */
/* Calibration */

#if defined(VX1000_CAL)

#include "cc_autosar.h"
#define CC_PTR ((VX1000_UINT32)&gCC)

#else /* !VX1000_CAL */

#define CC_PTR 0UL

#endif /* !VX1000_CAL */


/*---------------------------------------------------------------------------------------------------- */
/* User functions and macros for DAQ */

#if defined(VX1000_OLDA)

/* Trigger a universal event (TRACE or OLDA; event numbers 0 to 29) */
#define VX1000_EVENT(x)  VX1000_OLDA_EVENT((x)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

/* Trigger a special event (EventNumber=0..0xFFFFFFFF, OldaEventNumber=31) */
#define VX1000_SPECIAL_EVENT(e) do                                                     \
   {                                                                                   \
      VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))                                         \
      VX1000_STORE_EVENT((VX1000_UINT32)(e))                                           \
      VX1000_ENTER_SPINLOCK()                                                          \
      gVX1000.OldaEventNumber ^= (VX1000_UINT32)0x80000000UL;                          \
      VX1000_LEAVE_SPINLOCK()                                                          \
   } while(0); /* this never-looping while is here only for MISRA */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_OLDA */

/* Trigger an event or special event (TRACE only; event numbers 0 to 250 and 0x00010000 to 0x0FFFFFFF)*/
#define VX1000_EVENT(e) do                       \
   {                                             \
      VX1000_STORE_TIMESTAMP((VX1000_CLOCK()))   \
      VX1000_STORE_EVENT((e))                    \
   } while(0); /* this never-looping while is here only for MISRA */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#define VX1000_SPECIAL_EVENT(e) VX1000_EVENT((e)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#endif /* !VX1000_OLDA */

/* Update the ECU timestamp with a given value */
#define VX1000_TIMESTAMP_UPDATE(t)               \
   VX1000_STORE_TIMESTAMP((VX1000_UINT32)(t)) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

/* Trigger an event with a given value for ECU timestamp */
#define VX1000_TIMESTAMP_EVENT(e, t) do          \
   {                                             \
      VX1000_STORE_TIMESTAMP((VX1000_UINT32)(t)) \
      VX1000_STORE_EVENT((e))                    \
   } while(0); /* this never-loop-while is here only for MISRA */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */


/* Update the timestamp (optional, only needed if timestamp update rate by events is too slow): */
#define VX1000_TIMESTAMP() VX1000_STORE_TIMESTAMP((VX1000_CLOCK())) /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */


/*---------------------------------------------------------------------------------------------------- */
/* VX1000 struct */


#if defined(VX1000_DISABLE_INSTRUMENTATION)

#define VX1000_DATA                     /* empty */
#define VX1000_INIT()                   /* empty */ /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

#else /* !VX1000_DISABLE_INSTRUMENTATION */

/*---------------------------------------------------------------------------------------------------- */
/* VX1000_DATA, VX1000_INIT() */
/* User functions and macros macros for declaration and initialisation and global data */

/* History: */
/* New in version:  */
/*  4: OldaPtr */
/*  5: Olda integrated at fixed position 0x40 */
/*  6: CalPtr */
/*  7: ToolCtrlState (written by tool) */
/*  8: TimestampInfo, VersionInfo (constants) */

#define VX1000_STRUCT_VERSION  8UL
#define VX1000_STRUCT_MAGIC    0xFEC70A08UL

typedef struct
{
   VX1000_UINT32   EventNumber;         /* 00 */
   VX1000_UINT32   EventTimestamp;
   VX1000_UINT32   MagicId;
   VX1000_UINT32   Version;
   VX1000_UINT32   GetIdPtr;            /* 10 */
   VX1000_UINT32   GetIdLen;
   VX1000_UINT32   XcpMailboxPtr;
   VX1000_UINT32   StimCtrlPtr;
   VX1000_UINT32   RamSynchField;       /* 20 */
   VX1000_UINT32   ToolDetectState;
   VX1000_UINT32   OldaPtr;
   VX1000_UINT32   OldaEventNumber;
   VX1000_UINT32   CalPtr;              /* 30 */
   VX1000_UINT32   ToolCtrlState;
   VX1000_UINT32   TimestampInfo;
   VX1000_UINT32   VersionInfo;

   VX1000_OLDA_DATA                     /* no fix offset (note: coldstart currently expects 0x40!) */

   VX1000_STIM_DATA                     /* no fix offset */

   VX1000_MAILBOX_DATA                  /* no fix offset */
} VX1000_STRUCT_T;

/* Initialize the global data needed for VX1000 */
/* Must be called before any other VX1000_xxxx() routine is called but after timestamp provider has been initialised */
extern void VX1000_SUFFUN(vx1000_Init)(void);
#define VX1000_INIT() VX1000_SUFFUN(vx1000_Init)(); /* PRQA S 3453 */ /* Willingly violating MISRA Rule 19.7 to be able to provide configurable API wrappers */

/* Define the global data needed for VX1000 (the user must ensure that the VX1000_STRUCT_DATA part is linked first!) */
#define VX1000_DATA /* now an empty dummy because the actual data is already declared in vx1000_mpc5xxx.c module directly! \
   VX1000_STRUCT_DATA \
   VX1000_STIM_BENCHMARK_DATA \
   VX1000_ECUID_DATA \
   VX1000_OLDA_BENCHMARK_DATA \
   VX1000_COLDSTART_BENCHMARK_DATA \
   VX1000_HOOK_CONTROL_DATA
*/

/* include userdefined lines with optional section pragmas to force individual linkage of VX1000 structure data. */
/* Note that we're using nested section switches here (which might be unsupported by some compilers but has the  */
/* advantage of not requiring #undefs as those would violate the MISRA coding guidelines).                       */
#define VX1000_SECTION_START_STRUCT_H
#include "vx1000_mpc5xxx_cfg.h"
#define VX1000_SECTION_START_STRUCT_NEGATE_H

extern volatile VX1000_STRUCT_T gVX1000;
#if !defined(VX1000_MEMORY_SECTION)
#define VX1000_STRUCT_DATA volatile VX1000_STRUCT_T gVX1000;
#else /* VX1000_MEMORY_SECTION */
#define VX1000_STRUCT_DATA VX1000_MEMORY_SECTION volatile VX1000_STRUCT_T gVX1000;
#endif /* VX1000_MEMORY_SECTION */

/* include userdefined lines with optional section pragmas to restore previous linkage of data: */
#define VX1000_SECTION_END_STRUCT_H
#include "vx1000_mpc5xxx_cfg.h"
#define VX1000_SECTION_END_STRUCT_NEGATE_H

#endif /* !VX1000_DISABLE_INSTRUMENTATION */

/* include userdefined lines with optional section pragmas to restore standard linkage of code and/or data: */
#define VX1000_SECTION_END_MODULE_H
#include "vx1000_mpc5xxx_cfg.h"
#define VX1000_SECTION_END_MODULE_NEGATE_H

#endif /* !VX1000_MPC5XXX_H */

