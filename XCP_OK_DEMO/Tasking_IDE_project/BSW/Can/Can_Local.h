/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* STARTSINGLE_OF_MULTIPLE */

/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/*  \file     Can.c / Can_Irq.c
 *  \brief    Implementation of the CAN driver
 *  \details  see functional description below
 *
 *********************************************************************************************************************/
/* ***************************************************************************
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Her          Peter Herrmann            Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Rse          Robert Schelkle           Vector Informatik GmbH
| Huo          Chao Huo                  Vector Informatik GmbH
| Hum          Markus Iversen Huse       Vector Informatik GmbH
| Yoe          Yacine Ouldboukhitine     Vector Informatik GmbH
|-----------------------------------------------------------------------------
|               R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Version Author Description
| ---------  ------- ------ --------------------------------------------------
| 2012-04-13 1.00.00  Her - Initial revision (alpha version)
| 2012-08-28 1.00.01  Her - Initial revision (beta version )
| 2013-02-01 1.01.00  Her - ESCAN00065098: Initial release version
| 2013-03-18 1.02.00  Her - ESCAN00065594: Additional (High End) features
| 2013-06-03 1.03.00  Her - ESCAN00068062: Rx Dedicated Buffers support
|                     Her - ESCAN00068305: Reduce RAM resource consumption by tailoring the configuration
|                     Her - ESCAN00068956: CAN messages to be transmitted are missing
| 2013-07-26 1.03.80  Her - ESCAN00069335: CAN-FD Bitrate Switching Prototype
| 2013-08-08 1.04.00  Her - ESCAN00069461: Further transmissions are not accepted but a memory violation is reported
|                     Her - ESCAN00069673: Conditional ECC initialization of the embedded CAN Message RAM
|                     Her - ESCAN00069937: GHS support
| 2013-09-27 1.05.00  Her - ESCAN00070770: Use Overrun in Status
|                     Her - ESCAN00070771: Compiler error: "finishRxFullCan" undefined
| 2013-10-17 1.06.00  Her - ESCAN00070952: Support customer specific post initialization
|                     Her - ESCAN00071166: AR4-328: Predefined Runtime Measurement Points
|                     Her - ESCAN00071326: Delayed overrun notification
|                     Her - ESCAN00071493: Message processed in wrong (interrupt or task ) context 
| 2013-11-20 1.07.00  Her - ESCAN00073084: Improvements on derivative handling
| 2014-02-12 1.08.00  Her - ESCAN00073939: Enhanced CAN-FD (Full) support
| 2014-03-17 1.09.00  Her - ESCAN00074327: Support embedded assembler for DiabData
| 2014-06-13 1.10.00  Her - ESCAN00076201: Support MPC5777C derivative
| 2014-10-30 2.00.00  Her - ESCAN00079193: AR4-R11 Update using ComStackLib
| 2015-01-30 2.01.00  Her - ESCAN00079800: Added CBD support (for Traveo derivative)
| 2015-02-20 2.02.00  Her - ESCAN00081372: AR4-R11 Update using ComStackLib (support Spc58xx)
| 2015-03-18 2.02.01  Her - ESCAN00081884: compile error
| 2015-04-02 2.02.02  Her - ESCAN00082190: Power Down (sleep mode) correction
|                     Her - ESCAN00082291: Memory access misalignment exception
| 2015-04-16 2.02.03  Her - ESCAN00082521: Extended Id Type not correct detected
|                     Her - ESCAN00082722: CANbedded only: Memory access misalignment exception
|                     Her - ESCAN00082724: Speed up TxCopyToCan
| 2015-07-06 2.02.04  Her - ESCAN00083815: Tx Confirmation gets lost
|                     Her - ESCAN00088481: Compiler error occurs
| 2015-07-30 2.03.00  Her - ESCAN00084313: Support MCAN Core release 3.1.0 ff.
|                     Her - ESCAN00084515: Use generated FullCAN masks
|                     Her - ESCAN00084650: Support ARM Cortex-Mx Data Memory Barrier
|                     Her - ESCAN00084814: Compiler error due to nested macro construction
| 2015-10-09 2.03.01  Her - ESCAN00085813: Endless loop during reception of messages
| 2015-11-11 2.04.00  Her - ESCAN00086128: Dynamic Rx FullCAN Message filtering failure
|                     Her - ESCAN00086359: Bosch Errata - support of workaround
| 2015-12-02 2.04.01  Her - ESCAN00086934: Support Keil compiler
|                     Her - ESCAN00087003: Missing pre-processor constants
|                     Her - ESCAN00087005: Re-Initialization fails
|                     Her - ESCAN00087056: Erroneous cancel notification
| 2015-12-03 2.05.00  Her - ESCAN00087255: Restructured due to AR4/R14
|                     Her - ESCAN00087256: Compile warning (erratum_013)
| 2016-01-21 2.05.01  Her - ESCAN00087586: Memory overwrite during RAM check
|                     Her - ESCAN00087612: Wrong mailbox checked
| 2016-02-19 2.06.00  Her - ESCAN00088392: Support 8 CAN channels (only Organi affected)
|                     Her - ESCAN00088519: Support more than 255 Dynamic Rx Objects
|                     Her - ESCAN00088756: Reserved bits may only be written with "0"
|                     Her - ESCAN00088813: Incorrect switching between Normal CAN and CAN-FD
|                     Her - ESCAN00089048: Support Mirror Mode (CBD)
|                     Her - ESCAN00089049: Assertion causes compile error
|                     Her - ESCAN00089131: Dynamic Rx objects compile error
| 2016-04-12 2.06.01  Her - ESCAN00089406: AR4/R14 adaptations to AR3
| 2016-04-22 2.06.02  Her - ESCAN00089587: Memory overwrite during RAM check
|                     Her - ESCAN00089610: CAN-ID Rx access macros
| 2016-04-28 2.07.00  Her - ESCAN00089867: MISRA improvements
|            2.08.xx  Her - ESCAN00092200: Will be used for Silent branch
| 2016-06-22 2.09.00  Her - ESCAN00090584: Function call with missing parameter
|                     Her - ESCAN00090761: Generated filter for dynamic Rx objects must be disabled by default
|                     Her - ESCAN00090825: Omit obsolete cancellation delay 
|                     Her - ESCAN00091096: Support AR4/R16
|                     Her - ESCAN00091328: Support Mirror Mode (ASR)
|                     Her - ESCAN00091329: CAN-FD Bit Rate Switch always active
| 2016-08-24 2.10.00  Her - ESCAN00091681: Support dynamic MCAN Revision adaptation
|                     Her - ESCAN00092569: Compiler error: identifier "pduInfo_var_id" is undefined
|                     Her - ESCAN00092315: Compiler warning: function "CanLL_WakeUpHandling" was declared but never referenced
|                     Her - ESCAN00092713: Preprocessor parse error
| 2016-10-28 2.11.00  Pl  - ESCAN00092591: Support Aurix Plus with AR4/R16
| 2016-11-24 2.12.00  Her - ESCAN00092995: CAN-FD message without BRS will not be received
|                     Her - ESCAN00093167: Compiler error "maybe misaligned memory access"
|                     Pl  - ESCAN00093244: CAN Interrupt lock work not correct (Aurix Plus only)
| 2017-01-25 2.13.00  Pl  - ESCAN00093483: CAN communication only possible with channels CAN0, CAN4, CAN8 (Aurix Plus only)
|                     Pl  - ESCAN00093726: Support C_ENABLE_USE_OS_INTERRUPT_CONTROL (Aurix Plus only)
| 2017-02-02 2.13.01  Her - ESCAN00093849: CAN data bytes containing wrong content 
|                     Her - ESCAN00093852: Support Extended ID Masking
| 2017-03-09 2.14.00  Rse - ESCAN00094323: Support TeleChips Tcc802x derivatives for CANbedded
| 2017-04-19 2.14.01  Pl  - ESCAN00094085: Implementation of workaround for MCMCAN_TC.003_EPN Corruption of transmitted CAN Frame
| 2017-05-10 2.15.00  Her - ESCAN00094883: Improper workaround for MCAN Erratum #10 
| 2017-05-11 2.16.00  Her - ESCAN00094518: MCAN SafeBSW Support
| 2017-08-10 2.16.01  Her - STORYC-2289  : FEAT-2738 (silent mode), FEAT-2888 (selective multiplexedTx)
| 2017-08-25 2.17.00  Pl  - STORYC-2250  : M-CAN: Support new platform Telemaco3P with ARM DS5 compiler with CFG5
|                     Her - STORYC-2289  : Support derivatives TCC8021, SAMCA1E for CANbedded
| 2017-09-12 2.20.00  Her - STORYC-2729  : Support derivatives SPC5777M with AR4/R19, MCAN SafeBSW Support
|                     Her - STORYC-2780  : Stop Mode transition behaviour improved
|                     Her - ESCAN00097246: Pending Tx requests block transition to stop mode
|                     Her - ESCAN00097151: Incomplete Mirror Data
| 2017-10-27 2.21.00  Her - STORYC-2729  : MCAN SafeBSW Support (continued and ExtRamCheck Beta)
| 2017-12-01 3.00.00  Pl  - STORYC-3153  : Add infixing to support multiple driver instanced
|                     Her - STORYC-3325  : AR3/GENy adaptation
|                     Huo - ESCAN00098069: Add external PIA
| 2018-01-25 3.01.00  Hum - STORYC-4102  : Support Extended Ram Check
|                     Her - ESCAN00097602: OS assertion "CAN interrupt lost"
|                     Hum - ESCAN00098469: TCF Init enabled regardless of CANCEL_IN_HW
|                     Hum - ESCAN00098470: TDCR write not performed correctly in correspondance with dynamic MCAN revision. CAN_BOSCH_ERRATUM_012
|                     Hum - ESCAN00098467: Missing ampersand in RAM check resulting in a DET error.
| 2018-03-07 3.02.00  Pl  - STORYC-4771  : Support TC38X for Tricore
|                     Her - ESCAN00098887: static variable "mirrorData" linker section issue, 
|                     Her - ESCAN00098890: use kCanLoopStop instead of kCanLoopSleep (AR3 issue)
| 2018-09-17 4.00.00  Her - STORYC-6298  : MCAN RI 2.0 adaptation
|                     Hum - STORYC-6490  : Support for Traveo2
| 2018-10-26 4.00.01  Yoe - ESCAN00101172: Compiler error: wrong number of arguments in call to CanReInit
| 2019-03-14 5.00.00  Her - STORYC-7220  : from CBD/RI2.0 to AR/R21,R22 adaptation
|                     Hum - STORYC-8107  : Adapations for TriCore R22
|                     Hum - STORYC-7923  : Merge version 3-03-00 - 3-09-01:
|                                          - STORYC-4711  : Support TDA3x additional registers
|                                          - STORYC-4584  : Infixing improvements
|                                          - STORYC-5038  : Support GNU Compiler for TC38X
|                                          - ESCAN00099574: Adaptation LL for CANBEDDED
|                                          - STORYC-5679  : Support for Visconti5
|                                          - STORYC-5763  : Support extended ram check for TDA3x
|                                          - STORYC-6686  : Support for Traveo2
|                                          - STORYC-6964  : Support SafeBSW for RH850
|                                          - STORYC-7393  : Support SafeBsw for Tricore TC3xx
|                                          - STORYC-7392  : Support Extended RAM check for Tricore TC3xx
|                                          - ESCAN00101336: Rx BasicCan not deactivated when hwMailbox is corrupted
|                                          - ESCAN00101842: Extended Ram Check does not validate all configured registers
|                                          - STORYC-7578  : Support for ATSAME51/54 derivatives (STORYC-7633 for CANBEDDED)
|                                          - ESCAN00102628: Can controller does not leave NISO mode
| 2019-04-12 5.01.00  Hum - ESCAN00102829: Can driver causes hardware exception
|                     Hum - ESCAN00102850: Hardware issue "MCMCAN_AI.H001_EPN"
|                     Hum - STORYC-8181  : Support Traveo2 HighEnd
|************************************************************************** */

#if !defined(CAN_LOCAL_H)
#define  CAN_LOCAL_H

/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/
/* \trace SPEC-1583 */
#include "SchM_Can.h"
#include "Can.h"         /* include also all needed types */

/***************************************************************************/
/* Version Check                                                           */
/***************************************************************************/
/* \trace SPEC-20329 */
/* not the SW version but all file versions that represent the SW version are checked */
#if (CAN_COREVERSION           != 0x0800u) /* \trace SPEC-1699 */
# error "Header file are inconsistent!"
#endif
#if (CAN_RELEASE_COREVERSION   != 0x01u)
# error "Header file are inconsistent!"
#endif
#if( DRVCAN_MPC5700MCANASR_VERSION != 0x0501)
# error "Source and Header file are inconsistent!"
#endif

#if( DRVCAN_MPC5700MCANASR_RELEASE_VERSION != 0x00)
# error "Source and Header file are inconsistent!"
#endif

#if defined(CAN_GEN_Mpc5700McanAsr_VERSION )  /* COV_CAN_VERSION_CHECK */
# if(CAN_GEN_Mpc5700McanAsr_VERSION != 0x0100)     /* CFG5 */
#  error "Generated Data are inconsistent!"
# endif
#else
# define CAN_GEN_Mpc5700McanAsr_VERSION         CAN_GEN_MPC5700MCANASR_VERSION
# if(CAN_GEN_MPC5700MCANASR_VERSION != 0x0100)
#  error "Generated Data are inconsistent!"
# endif
#endif

/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */

/***************************************************************************/
/* compatibility defines                                                   */
/***************************************************************************/
#if defined(C_ENABLE_MIXED_ID) || defined(C_ENABLE_EXTENDED_ID)
# define CAN_ID_IDE_MASK            0x80000000UL
# define CAN_ID_FD_MASK             0x40000000UL /* \trace SPEC-50553 */
# define CAN_ID_MASK                0x1FFFFFFFUL
# define CAN_ID_MASK_STD            0x000007FFUL
# define CAN_ID_UNUSED_MASK         0x20000000UL
#else
# define CAN_ID_IDE_MASK            0x0000U
# define CAN_ID_FD_MASK             0x4000U /* \trace SPEC-50553 */
# define CAN_ID_MASK                0x07FFU
# define CAN_ID_MASK_STD            0x07FFU
# define CAN_ID_UNUSED_MASK         0x3800U
#endif
#define kCanAllChannels  ((CanChannelHandle)0xFFU)

#if !defined(C_DRV_INTERNAL) /* COV_CAN_INTERNAL */
# error "Can_Local.h should only be included by Can.c"
#endif
/* real amount of controllers in this system (LT and PB) */
#define kCanNumberOfChannels  Can_GetControllerMax()
/* if kCanNumberOfChannels used to declare a table/dimension this table has to be generated to be also Link-Time-capable */
/*  -> see ESCAN00028069 controller-amount has to be Link-Time-capable */
/* real amount of controllers in this system (LT and PB) */
#define kCanNumberOfHwChannels  kCanNumberOfChannels

#if defined( C_SINGLE_RECEIVE_CHANNEL )
/* have to be done here to avoid declaration of "channel" in Can.h */
# define channel                                ((CanChannelHandle)0)
# define canHwChannel                           ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       ((CanChannelHandle)0)
# define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        ((CanChannelHandle)0)
#else
# define channel                                Controller
# define canHwChannel                           Controller
# define CAN_HL_HW_CHANNEL_STARTINDEX(ch)       (ch)
# define CAN_HL_HW_CHANNEL_STOPINDEX(ch)        (ch)
#endif
#if !defined(CAN_TRANSITION_CHECK) /* COV_CAN_COMPATIBILITY */
# define CAN_TRANSITION_CHECK STD_ON /* default may be deactivated by user configuration */
#endif
#if !defined(CAN_REINIT_START) /* COV_CAN_COMPATIBILITY */
# define CAN_REINIT_START STD_OFF
#endif

#if !defined(CAN_OS_TICK2MS) /* COV_CAN_COMPATIBILITY */
# error "CAN_OS_TICK2MS() should be defined to OS_TICKS2MS_<counterShortName>() macro from OS"
#endif
#if !defined(CAN_OS_COUNTER_ID) /* COV_CAN_COMPATIBILITY */
# error "CAN_OS_COUNTER_ID should be defined to 'counterShortName' from OS"
#endif

#if !defined(CAN_ID_MASK_IN_GENERIC_CALLOUT) /* COV_CAN_COMPATIBILITY */
# define CAN_ID_MASK_IN_GENERIC_CALLOUT (CAN_ID_IDE_MASK | CAN_ID_FD_MASK | CAN_ID_MASK)
/* May be changed to mask out FD-bit: (CAN_ID_IDE_MASK | CAN_ID_MASK) */
#endif

/* MCAN Version */

#if !defined ( CAN_C_ENABLE_MPC5700_MCAN_MAJOR_CREL )     /* MCAN Core Release */
# error "Derivative not defined."
#endif
#if !defined ( C_ENABLE_MPC5700_MCAN_CREL_STEP )          /* COV_CAN_HW_SPECIFIC */
# define C_ENABLE_MPC5700_MCAN_CREL_STEP       0u         /* Step of MCAN Core Release */
#endif
#if !defined ( C_ENABLE_MPC5700_MCAN_CREL_SSTEP )         /* COV_CAN_HW_SPECIFIC */
# define C_ENABLE_MPC5700_MCAN_CREL_SSTEP      0u         /* Sub-Step of MCAN Core Release */
#endif
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() > 3u )    /* COV_CAN_HW_SPECIFIC */
# error "MCAN Revision not supported yet."
#endif

#if defined(CAN_MCAN_REVISION) /* COV_CAN_INTERNAL */
#else
# if(   ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 2u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP() >= 1u ))   /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0321u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) &&  ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 2u ))  /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0320u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) &&  ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 1u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP() >= 5u ))  /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0315u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) &&  ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()  >= 1u ))  /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0310u
# elif( ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ))    /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0300u
# elif(   Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 2u )     /* COV_CAN_HW_SPECIFIC */
#  define CAN_MCAN_REVISION  0x0200u
#  if defined(C_ENABLE_CAN_FD_FULL)                             /* COV_CAN_HW_SPECIFIC */
#   error "This MCAN Revision does not support full CAN-FD!"
#  endif
# elif(   Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 1u )     /* COV_CAN_HW_SPECIFIC */
#  error "This MCAN Revision is no longer supported."
# else
#  error "Unknown MCAN Revision detected."
# endif
#endif /* CAN_MCAN_REVISION */

/* MCAN Errata */
/* Erratum #16:  "Configuration of NBTP.NTSEG2 = '0' not allowed." 
                  Relevant for MCAN Rel. 3.1.0, 3.2.0, 3.2.1    */
# if ( CAN_MCAN_REVISION >= 0x0315UL)  /* COV_CAN_HW_SPECIFIC */
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_006 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_006       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_007 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_007       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_008 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_008       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_010 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_010       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1, 3.1.0 */ 
# if !defined CAN_BOSCH_ERRATUM_011 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_011       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.6, 3.0.0, 3.0.1, 3.1.0 */
# if !defined CAN_BOSCH_ERRATUM_012 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_012       STD_OFF
# endif

#elif ( CAN_MCAN_REVISION >= 0x0310UL)  /* COV_CAN_HW_SPECIFIC */
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_006 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_006       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_007 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_007       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_008 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_008       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_010 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_010       STD_OFF
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1, 3.1.0 */ 
# if !defined CAN_BOSCH_ERRATUM_011 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_011       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.6, 3.0.0, 3.0.1, 3.1.0 */
# if !defined CAN_BOSCH_ERRATUM_012 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_012       STD_ON
# endif

#else
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_006 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_006       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_007 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_007       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_008 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_008       STD_ON
# endif
/* Relevant for MCAN Rel. 2.9.5, 2.9.6, 3.0.0, 3.0.1 */
# if !defined CAN_BOSCH_ERRATUM_010 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_010       STD_ON
# endif

# if ( CAN_MCAN_REVISION >= 0x0300UL)  /* COV_CAN_HW_SPECIFIC */
#  if !defined CAN_BOSCH_ERRATUM_011
#   define CAN_BOSCH_ERRATUM_011      STD_ON
#  endif
# else
#  if !defined CAN_BOSCH_ERRATUM_011 /* COV_CAN_ERRATUM_OFF */
#   define CAN_BOSCH_ERRATUM_011      STD_OFF /* MRAF exists since 3.0.0 */
#  endif
# endif

# if !defined CAN_BOSCH_ERRATUM_012 /* COV_CAN_ERRATUM_OFF */
#  define CAN_BOSCH_ERRATUM_012       STD_OFF /* PXHD exists since 3.1.0 */
# endif
#endif

#if !defined( CAN_ECC_INIT_SHM )
# define C_ENABLE_CAN_ECC_INIT_SHM
#else
# if ( CAN_ECC_INIT_SHM == STD_ON )
#  define C_ENABLE_CAN_ECC_INIT_SHM
# endif
#endif

#if( (!defined(C_ENABLE_EXTENDED_ID)) || (defined(C_ENABLE_MIXED_ID)) )
# define C_ENABLE_STD_ID
#endif

#if( (defined( C_ENABLE_GENERATE_FULLCAN_MASK ))  || (defined( C_DISABLE_GENERATE_FULLCAN_MASK )) || (defined( CAN_C_ENABLE_GENERATE_FULLCAN_MASK )) ) /* COV_CAN_GENTOOL_SPECIFIC */
# define C_ENABLE_FULLCAN_FILTER_GENERATION
#else
# error "Inconsistent Generation Tool. Please update GENy DLL Hw_Mpc5700McanCpuCan to version 1.09.00 or later."
#endif

#if !defined (kCanNumberOfStandardFilter) /* COV_CAN_COMPATIBILITY */
# if defined( CAN_SIDFEUSEDOFSIDFC )      /* COV_CAN_COMPATIBILITY */
#  if( CAN_SIDFEUSEDOFSIDFC == STD_ON )
#   define kCanNumberOfStandardFilter  1
#  else
#   define kCanNumberOfStandardFilter  0
#  endif
# else
#  define kCanNumberOfStandardFilter  1  /* GENy */
# endif
#endif

#if !defined (kCanNumberOfExtendedFilter) /* COV_CAN_COMPATIBILITY */
# if defined( CAN_XIDFEUSEDOFXIDFC )      /* COV_CAN_COMPATIBILITY */
#  if( CAN_XIDFEUSEDOFXIDFC == STD_ON )
#   define kCanNumberOfExtendedFilter  1
#  else
#   define kCanNumberOfExtendedFilter  0
#  endif
# else
#  define kCanNumberOfExtendedFilter  1   /* GENy */
# endif
#endif


/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
/* for variable Can_ActiveSendState */
#define kCanBufferFree              (uint8)0xFF     /* mark objects as free */
#define kCanBufferCancel            (uint8)0xFE     /* mark object as currently cancelling */
#define kCanBufferCancelSw          (uint8)0xFD
#define kCanBufferSend              (uint8)0x01     /* occupied send object */

/* HL return values */
#define kCanFailed                  (uint8)0x00     /* similar to CAN_NOT_OK but value may differ --> converted in HL (LL only use kCan...) */
#define kCanOk                      (uint8)0x01     /* similar to CAN_OK */
#define kCanRequested               (uint8)0x03

#define kCanFalse                   kCanFailed
#define kCanTrue                    kCanOk

#define Can_GetControllerMax()                        Can_GetSizeOfControllerData()
#define Can_GetCanToCanIfChannelMapping(Index)        Can_GetCanIfChannelId((Index))

/* ControllerConfig */
#define Can_GetCanControllerDefaultBaudrate(logCh)    Can_GetCanControllerDefaultBaudrateOfControllerConfig(logCh)
#define Can_GetCanControllerDefaultBaudrateIdx(logCh) Can_GetCanControllerDefaultBaudrateIdxOfControllerConfig(logCh)
#if !defined(Can_GetMailboxRxBasicLengthOfControllerConfig) /* If no Object is available ComStackLib do not generate start-stop index */
# define Can_GetMailboxRxBasicLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxBasicStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxBasicEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetRxBasicHandleMax(logCh)                Can_GetMailboxRxBasicLengthOfControllerConfig(logCh)
#define Can_GetRxBasicHandleStart(logCh)              (Can_HwHandleType)Can_GetMailboxRxBasicStartIdxOfControllerConfig(logCh)
#define Can_GetRxBasicHandleStop(logCh)               (Can_HwHandleType)Can_GetMailboxRxBasicEndIdxOfControllerConfig(logCh)
#define Can_GetRxBasicHwStart(logCh)                  Can_GetRxBasicHwStartOfControllerConfig(logCh)
#define Can_GetRxBasicHwStop(logCh)                   Can_GetRxBasicHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxRxFullLengthOfControllerConfig)
# define Can_GetMailboxRxFullLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxFullStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxRxFullEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetRxFullHandleMax(logCh)                 Can_GetMailboxRxFullLengthOfControllerConfig(logCh)
#define Can_GetRxFullHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxRxFullStartIdxOfControllerConfig(logCh)
#define Can_GetRxFullHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxRxFullEndIdxOfControllerConfig(logCh)
#define Can_GetRxFullHwStart(logCh)                   Can_GetRxFullHwStartOfControllerConfig(logCh)
#define Can_GetRxFullHwStop(logCh)                    Can_GetRxFullHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxTxBasicLengthOfControllerConfig) /* COV_CAN_GENDATA_FAILURE */
# define Can_GetMailboxTxBasicLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxBasicStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxBasicEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetTxBasicHandleMax(logCh)                Can_GetMailboxTxBasicLengthOfControllerConfig(logCh)
#define Can_GetTxBasicHandleStart(logCh)              (Can_HwHandleType)Can_GetMailboxTxBasicStartIdxOfControllerConfig(logCh)
#define Can_GetTxBasicHandleStop(logCh)               (Can_HwHandleType)Can_GetMailboxTxBasicEndIdxOfControllerConfig(logCh)
#define Can_GetTxBasicHwStart(logCh)                  Can_GetTxBasicHwStartOfControllerConfig(logCh)
#define Can_GetTxBasicHwStop(logCh)                   Can_GetTxBasicHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxTxFullLengthOfControllerConfig)
# define Can_GetMailboxTxFullLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxFullStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxTxFullEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetTxFullHandleMax(logCh)                 Can_GetMailboxTxFullLengthOfControllerConfig(logCh)
#define Can_GetTxFullHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxTxFullStartIdxOfControllerConfig(logCh)
#define Can_GetTxFullHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxTxFullEndIdxOfControllerConfig(logCh)
#define Can_GetTxFullHwStart(logCh)                   Can_GetTxFullHwStartOfControllerConfig(logCh)
#define Can_GetTxFullHwStop(logCh)                    Can_GetTxFullHwStopOfControllerConfig(logCh)
#if !defined(Can_GetMailboxUnusedLengthOfControllerConfig)  /* COV_CAN_GENDATA_FAILURE */
# define Can_GetMailboxUnusedLengthOfControllerConfig(logCh) 0u
# define Can_GetMailboxUnusedStartIdxOfControllerConfig(logCh) 0u
# define Can_GetMailboxUnusedEndIdxOfControllerConfig(logCh) 0u
#endif
#define Can_GetUnusedHandleMax(logCh)                 Can_GetMailboxUnusedLengthOfControllerConfig(logCh)
#define Can_GetUnusedHandleStart(logCh)               (Can_HwHandleType)Can_GetMailboxUnusedStartIdxOfControllerConfig(logCh)
#define Can_GetUnusedHandleStop(logCh)                (Can_HwHandleType)Can_GetMailboxUnusedEndIdxOfControllerConfig(logCh)
#define Can_GetUnusedHwStart(logCh)                   Can_GetUnusedHwStartOfControllerConfig(logCh)
#define Can_GetUnusedHwStop(logCh)                    Can_GetUnusedHwStopOfControllerConfig(logCh)

/* Mailbox */
/* GetMailboxSize: logical size of mailbox - use LL specific generated data to get hardware object size if needed */
#define Can_GetMailboxSize(htrh)                      Can_GetMailboxSizeOfMailbox(htrh)
#define Can_GetMailboxHwHandle(htrh)                  Can_GetHwHandleOfMailbox(htrh)
#define Can_GetMailboxIDValue(htrh)                   Can_GetIDValueOfMailbox(htrh)
#define Can_GetMailboxType(htrh)                      Can_GetMailboxTypeOfMailbox(htrh)
#define Can_GetMailboxDataLen(htrh)                   Can_GetMaxDataLenOfMailbox(htrh)
#define Can_GetMailboxFdPadding(htrh)                 Can_GetFdPaddingOfMailbox(htrh)
#define Can_GetMailboxController(htrh)                (CanChannelHandle)Can_GetControllerConfigIdxOfMailbox(htrh)
#define Can_GetMailboxActiveSendObject(htrh)          Can_GetActiveSendObjectOfMailbox(htrh)
#define Can_GetMailboxActiveSendData(htrh)            Can_GetActiveSendDataOfMailbox(htrh)
#define Can_GetMailboxMemSecObjIndex(htrh)            Can_GetMemorySectionsIndexOfMailbox(htrh)
#define Can_IsMailboxIndivPolling(htrh)               Can_IsIsIndivPollingOfMailbox(htrh)
#define Can_GetMailboxTxHwFifo(htrh)                  Can_GetTxHwFifoOfMailbox(htrh)

/* MemorySectionInfo */
#define Can_GetMemSecAddress(memSec)                  Can_GetMemoryStartAddressOfMemorySectionInfo(memSec)
#define Can_GetMemSecStartIndex(memSec)               Can_GetMemorySectionStartOfMemorySectionInfo(memSec)

/* MemorySectionObjects */
#define Can_GetMemSecObjHwHandle(memSecObj)           Can_GetHwHandleOfMemorySectionObjects(memSecObj)
#define Can_GetMemSecObjMailboxElement(memSecObj)     Can_GetMailboxElementOfMemorySectionObjects(memSecObj)
#define Can_GetMemSecObjMailboxHandle(memSecObj)      Can_GetMailboxHandleOfMemorySectionObjects(memSecObj)
#define Can_IsMemSecObjIndivPolling(memSecObj)        Can_IsIsIndivPollingOfMemorySectionObjects(memSecObj)

/* VAR */
#define Can_GetLastInitObject(Index)                   Can_GetLastInitObjectOfControllerData(Index)
#define Can_SetLastInitObject(Index, Value)            Can_SetLastInitObjectOfControllerData(Index, Value)
#define Can_GetCanInterruptOldStatus(Index)            Can_GetCanInterruptOldStatusOfControllerData(Index)
#define Can_SetCanInterruptOldStatus(Index, Value)     Can_SetCanInterruptOldStatusOfControllerData(Index, Value)
#define Can_GetCanInterruptCounter(Index)              Can_GetCanInterruptCounterOfControllerData(Index)
#define Can_SetCanInterruptCounter(Index, Value)       Can_SetCanInterruptCounterOfControllerData(Index, Value)
#define Can_IsIsWakeup(Index)                          Can_IsIsWakeupOfControllerData(Index)
#define Can_SetIsWakeup(Index, Value)                  Can_SetIsWakeupOfControllerData(Index, Value)
#define Can_IsIsBusOff(Index)                          Can_IsIsBusOffOfControllerData(Index)
#define Can_SetIsBusOff(Index, Value)                  Can_SetIsBusOffOfControllerData(Index, Value)
#define Can_GetModeTransitionRequest(Index)            Can_GetModeTransitionRequestOfControllerData(Index)
#define Can_SetModeTransitionRequest(Index, Value)     Can_SetModeTransitionRequestOfControllerData(Index, Value)
#define Can_GetBusOffTransitionRequest(Index)          Can_GetBusOffTransitionRequestOfControllerData(Index)
#define Can_SetBusOffTransitionRequest(Index, Value)   Can_SetBusOffTransitionRequestOfControllerData(Index, Value)
#define Can_GetRamCheckTransitionRequest(Index)        Can_GetRamCheckTransitionRequestOfControllerData(Index)
#define Can_SetRamCheckTransitionRequest(Index, Value) Can_SetRamCheckTransitionRequestOfControllerData(Index, Value)
/* controller states */
#define Can_GetLogStatus(Index)                        Can_GetLogStatusOfControllerData(Index)
#define Can_SetLogStatus(Index, Value)                 Can_SetLogStatusOfControllerData(Index, Value)
#define Can_GetCanLoopTimeout(ch, Index)               (Can_GetLoopTimeoutOfControllerData(ch))[(Index)]
#define Can_GetMirrorModeState(Index)                  Can_GetMirrorModeStateOfControllerData(Index)
#define Can_SetMirrorModeState(Index, Value)           Can_SetMirrorModeStateOfControllerData(Index, Value)
#define Can_GetSilentModeState(Index)                  Can_GetSilentModeStateOfControllerData(Index)
#define Can_SetSilentModeState(Index, Value)           Can_SetSilentModeStateOfControllerData(Index, Value)
/* ActiveSend */
#define Can_GetActiveSendPdu(Index)                    Can_GetPduOfActiveSendObject(Index)
#define Can_SetActiveSendPdu(Index, Value)             Can_SetPduOfActiveSendObject(Index, Value)
#define Can_GetActiveSendState(Index)                  Can_GetStateOfActiveSendObject(Index)
#define Can_SetActiveSendState(Index, Value)           Can_SetStateOfActiveSendObject(Index, Value)
#define Can_GetActiveSendPduInfo(Index)                Can_GetPduInfoOfActiveSendObject(Index)
#define Can_GetActiveSendId(Index)                     (Can_GetPduInfoOfActiveSendObject(Index)).id
#define Can_SetActiveSendId(Index, Value)              (Can_GetPduInfoOfActiveSendObject(Index)).id = (Value)
#define Can_GetActiveSendLength(Index)                 (Can_GetPduInfoOfActiveSendObject(Index)).length
#define Can_SetActiveSendLength(Index, Value)          (Can_GetPduInfoOfActiveSendObject(Index)).length = (Value)
#define Can_GetActiveSendSdu(Index)                    (Can_GetPduInfoOfActiveSendObject(Index)).sdu
#define Can_SetActiveSendSdu(Index, Value)             (Can_GetPduInfoOfActiveSendObject(Index)).sdu = (Value)
#define Can_GetActiveSendSwPduHandle(Index)            (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle
#define Can_SetActiveSendSwPduHandle(Index, Value)     (Can_GetPduInfoOfActiveSendObject(Index)).swPduHandle = (Value)
/* Use already ComStackLib name #define Can_GetActiveSendData(Index)                   Can_GetActiveSendData(Index) */
/* TxHwFifo */
#define Can_GetTxHwFifoWriteIndex(fifo)                Can_GetWriteIndexOfTxHwFifo(fifo)
#define Can_SetTxHwFifoWriteIndex(fifo, Value)         Can_SetWriteIndexOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoWriteIndex(fifo)                Can_IncWriteIndexOfTxHwFifo(fifo)
#define Can_GetTxHwFifoReadIndex(fifo)                 Can_GetReadIndexOfTxHwFifo(fifo)
#define Can_SetTxHwFifoReadIndex(fifo, Value)          Can_SetReadIndexOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoReadIndex(fifo)                 Can_IncReadIndexOfTxHwFifo(fifo)
#define Can_GetTxHwFifoFillCount(fifo)                 Can_GetFillCountOfTxHwFifo(fifo)
#define Can_SetTxHwFifoFillCount(fifo, Value)          Can_SetFillCountOfTxHwFifo(fifo, Value)
#define Can_IncTxHwFifoFillCount(fifo)                 Can_IncFillCountOfTxHwFifo(fifo)
#define Can_DecTxHwFifoFillCount(fifo)                 Can_DecFillCountOfTxHwFifo(fifo)

#if defined( CAN_GEN_COM_STACK_LIB )  /* COV_CAN_COMPATIBILITY */
# if defined(C_ENABLE_CAN_FD_FULL)
#  define GET_TXRXBB_OFFSET(num, dli) (vuint32)((num) * (8u + CanLL_xES2Bytes[dli]))
#  define GET_N_BYTES_FROM_ES(elementSize) (CanLL_xES2Bytes[(elementSize)&0x7u])
#  define GET_RX0F_OFFSET(num) (GET_TXRXBB_OFFSET((num), Can_GetF0DSOfShmElementSize(canHwChannel)))
#  define GET_RX1F_OFFSET(num) (GET_TXRXBB_OFFSET((num), Can_GetF1DSOfShmElementSize(canHwChannel)))
#  define GET_RXB_OFFSET(num)  (GET_TXRXBB_OFFSET((num), Can_GetRBDSOfShmElementSize(canHwChannel)))
#  define GET_TXB_OFFSET(num)  (GET_TXRXBB_OFFSET((num), Can_GetTBDSOfShmElementSize(canHwChannel)))
# else
#  define GET_RX0F_OFFSET(num) ((vuint32)(num)<<4u)
#  define GET_RX1F_OFFSET(num) ((vuint32)(num)<<4u)
#  define GET_RXB_OFFSET(num)  ((vuint32)(num)<<4u)
#  define GET_TXB_OFFSET(num)  ((vuint32)(num)<<4u)
# endif

# define ShmSIDF(num)      (*((tSIFEType*) (Can_GetSIDFAOfShmAdr(canHwChannel) + GET_SIDF_OFFSET(num))))
# define ShmXIDF(num)      (*((tXIFEType*) (Can_GetXIDFAOfShmAdr(canHwChannel) + GET_XIDF_OFFSET(num))))
# define ShmRXF0(num)      (  (tRxElmType*)(Can_GetRXF0AOfShmAdr(canHwChannel) + GET_RX0F_OFFSET(num)) )
# define ShmRXF1(num)      (  (tRxElmType*)(Can_GetRXF1AOfShmAdr(canHwChannel) + GET_RX1F_OFFSET(num)) )
# define ShmRXB(num)       (  (tRxElmType*)(Can_GetRXBAOfShmAdr(canHwChannel)  + GET_RXB_OFFSET (num)) )
# define ShmTXEF(num)      (*((tTxEventFifoElmType*)(Can_GetTXEFAOfShmAdr(canHwChannel) + GET_TXEF_OFFSET(num))))
# define ShmTXB(num)       (*((tTXBEType*) (Can_GetTXBAOfShmAdr(canHwChannel)  + GET_TXB_OFFSET (num))))
# define pShmTXB(num)      ( ((tTXBEType*) (Can_GetTXBAOfShmAdr(canHwChannel)  + GET_TXB_OFFSET (num))))

# define Can_GetCanTXBRP(ch)                                Can_GetTXBRPOfControllerData(ch)
# define Can_GetCanBusOffNotification(ch)                   Can_GetBusOffNotificationOfControllerData(ch)
# define Can_GetCanIntEnable(ch)                            Can_GetIntEnableOfControllerData(ch)
# define Can_GetCanBasisAdr(hwch)                           Can_GetBasisAdrOfControllerConfig(hwch)
# define Can_GetCanPrevMode(ch)                             Can_GetPrevModeOfControllerData(ch)
# define Can_GetCanLastState(ch)                            Can_GetLastStateOfControllerData(ch)

# define Can_GetCanBTP(initObject)                          Can_GetBTP(initObject)
# define Can_GetCanFBTP(initObject)                         Can_GetFBTP(initObject)
# define Can_GetCanTDCR(initObject)                         Can_GetTDCR(initObject)
# define Can_GetCanGFC(ch)                                  Can_GetGFC(ch)
# define Can_GetCanXIDAM(ch)                                Can_GetXIDAM(ch)
# define Can_GetCanRXBC(ch)                                 Can_GetRXBCOfBufferConfig(ch) 
# define Can_GetCanTXBC(ch)                                 Can_GetTXBCOfBufferConfig(ch) 
# define Can_GetCanTXEFC(ch)                                Can_GetTXEFCOfBufferConfig(ch) 
# define Can_GetCanRXF0C(ch)                                Can_GetRXF0COfBufferConfig(ch)
# define Can_GetCanRXF1C(ch)                                Can_GetRXF1COfBufferConfig(ch)
# define Can_GetCanSIDFC_FLSSAOfCanSIDFC(ch)                Can_GetFLSSAOfSIDFC(ch)
# define Can_GetCanXIDFC_FLESAOfCanXIDFC(ch)                Can_GetFLESAOfXIDFC(ch)
# define Can_GetCanSIDFC_LSSOfCanSIDFC(ch)                  Can_GetLSSOfSIDFC(ch)
# define Can_GetCanXIDFC_LSEOfCanXIDFC(ch)                  Can_GetLSEOfXIDFC(ch)
# define Can_GetCanSIDFE(ch)                                Can_GetSIDFE(ch)
# define Can_GetCanXIDFE(ch)                                Can_GetXIDFE(ch)
# define Can_GetCanSIDFEStartIndex(ch)                      Can_GetSIDFEStartIdxOfSIDFC(ch)
# define Can_GetCanXIDFEStartIndex(ch)                      Can_GetXIDFEStartIdxOfXIDFC(ch)
# define Can_GetCanXIDFEEIDFE_0OfCanXIDFE(ch)               Can_GetEIDFE_0OfXIDFE(ch)
# define Can_GetCanXIDFEEIDFE_1OfCanXIDFE(ch)               Can_GetEIDFE_1OfXIDFE(ch)

# if( CAN_ISTTCANOFCONTROLLERCONFIG == STD_ON ) /* COV_CAN_HW_SPECIFIC */ 
#  define Can_IsIsTTCan(ch)                                           Can_IsIsTTCanOfControllerConfig(ch)
#  define C_ENABLE_TTCAN_AVAILABLE
# endif
#else /* CAN_GEN_COM_STACK_LIB */

# if defined(C_ENABLE_CAN_FD_FULL)
#  define GET_TXRXBB_OFFSET(num, dli) (vuint32)((num) * (8 + CanLL_xES2Bytes[dli]))
#  define GET_N_BYTES_FROM_ES(elementSize) (CanLL_xES2Bytes[(elementSize)&0x7u])
#  define GET_RX0F_OFFSET(num) (GET_TXRXBB_OFFSET((num), Can_GetShmElementSize(canHwChannel)))
#  define GET_RX1F_OFFSET(num) (GET_TXRXBB_OFFSET((num), Can_GetShmElementSize(canHwChannel)))
#  define GET_RXB_OFFSET(num)  (GET_TXRXBB_OFFSET((num), Can_GetShmElementSize(canHwChannel)))
#  define GET_TXB_OFFSET(num)  (GET_TXRXBB_OFFSET((num), Can_GetShmElementSize(canHwChannel)))
# else
#  define GET_RX0F_OFFSET(num) ((num)<<4)
#  define GET_RX1F_OFFSET(num) ((num)<<4)
#  define GET_RXB_OFFSET(num)  ((num)<<4)
#  define GET_TXB_OFFSET(num)  ((num)<<4)
# endif

# if defined( C_ENABLE_TTCAN_AVAILABLE )
#  define Can_IsIsTTCan(ch)                                           CanIsTTCanChannel[(ch)]
# else
#  define Can_IsIsTTCan(ch)                                           0
# endif


# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define Can_GetStartAdrOfShmAdr(ch)                                 CAN_SHM_RAM_START
#  define Can_GetStopAdrOfShmAdr(ch)                                  CAN_SHM_RAM_END
# else
#  define Can_GetStartAdrOfShmAdr(ch)                                 CanShmStartEndAdr[(ch)].startAdr
#  define Can_GetStopAdrOfShmAdr(ch)                                  CanShmStartEndAdr[(ch)].endAdr
# endif

# define Can_GetCanBasisAdr(hwch)                                     CanBasisAdr[(hwch)]
# define Can_GetCanShmAdr(hwch)                                       CanShmAdr[(hwch)]
# define Can_GetCanShmAdr_SIDFAOfCanShmAdr(hwch)                      CanShmAdr[(hwch)].SIDFA
# define Can_GetCanShmAdr_XIDFAOfCanShmAdr(hwch)                      CanShmAdr[(hwch)].XIDFA

# define CAN_C_ENABLE_MPC5700_MCAN_MAJOR_CREL                         C_ENABLE_MPC5700_MCAN_MAJOR_CREL
# define Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL()                    C_ENABLE_MPC5700_MCAN_MAJOR_CREL
# if defined( C_ENABLE_MPC5700_MCAN_CREL_STEP ) /* COV_CAN_HW_SPECIFIC */
#  define CAN_C_ENABLE_MPC5700_MCAN_CREL_STEP                         C_ENABLE_MPC5700_MCAN_CREL_STEP
#  define Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()                    C_ENABLE_MPC5700_MCAN_CREL_STEP
#  define CAN_C_ENABLE_MPC5700_MCAN_CREL_SSTEP                        C_ENABLE_MPC5700_MCAN_CREL_SSTEP
#  define Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP()                   C_ENABLE_MPC5700_MCAN_CREL_SSTEP
# else
#  define CAN_C_ENABLE_MPC5700_MCAN_CREL_STEP                         0
#  define Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP()                    0
#  define CAN_C_ENABLE_MPC5700_MCAN_CREL_SSTEP                        0
#  define Can_GetC_ENABLE_MPC5700_MCAN_CREL_SSTEP()                   0
#  endif

# if defined( C_ENABLE_ARM_CORTEX_M ) /* COV_CAN_HW_SPECIFIC */
#  define CAN_C_ENABLE_ARM_CORTEX_M                         C_ENABLE_ARM_CORTEX_M
#  define Can_GetC_ENABLE_ARM_CORTEX_M()                              C_ENABLE_ARM_CORTEX_M
# endif
# if defined( CAN_FD_NISO )
#  define CAN_CAN_FD_NISO                                             CAN_FD_NISO
#  define Can_GetCAN_FD_NISO()                                        CAN_FD_NISO
# else
#  define CAN_CAN_FD_NISO                                             0
#  define Can_GetCAN_FD_NISO()                                        0
# endif


# define Can_GetNonFdObjectsPendingFlag(canHwChannel)                 Can_NonFdObjectsPendingFlag[(canHwChannel)]   

/* *** CAN_FD mode-2 **** */
# define Can_GetShmElementSize(ch)                                    CanShmElementSize[ch]
/* *** CAN_FD mode-2 **** */

# define Can_GetCanPrevMode(canHwChannel)                             CanPrevMode(canHwChannel)
# define Can_GetCanLastState(canHwChannel)                            CanLastState(canHwChannel)
# define Can_GetCanTXBRP(canHwChannel)                                CanTXBRP[(canHwChannel)]
# define Can_GetCanBusOffNotification(canHwChannel)                   CanBusOffNotification[(canHwChannel)]
# define Can_GetCanIntEnable(canHwChannel)                            CanIntEnable[(canHwChannel)]
# define Can_GetCanBTP(initObject)                                    CanBTP[(initObject)]
# define Can_GetCanFBTP(initObject)                                   CanFBTP[(initObject)]
# define Can_GetCanTDCR(initObject)                                   CanTDCR[(initObject)]
# define Can_GetCanGFC(canHwChannel)                                  CanGFC[(canHwChannel)]
# define Can_GetCanXIDAM(canHwChannel)                                CanXIDAM[(canHwChannel)]
# define Can_GetCanRXBC(canHwChannel)                                 CanRXBC[(canHwChannel)]
# define Can_GetCanTXBC(canHwChannel)                                 CanTXBC[(canHwChannel)]
# define Can_GetCanTXEFC(canHwChannel)                                CanTXEFC[(canHwChannel)]
# define Can_GetCanRXF0C(canHwChannel)                                CanRXF0C[(canHwChannel)]
# define Can_GetCanRXF1C(canHwChannel)                                CanRXF1C[(canHwChannel)]
# define Can_GetCanSIDFC_FLSSAOfCanSIDFC(canHwChannel)                CanSIDFC[(canHwChannel)].FLSSA
# define Can_GetCanXIDFC_FLESAOfCanXIDFC(canHwChannel)                CanXIDFC[(canHwChannel)].FLESA
# define Can_GetCanSIDFC_LSSOfCanSIDFC(canHwChannel)                  CanSIDFC[(canHwChannel)].LSS
# define Can_GetCanXIDFC_LSEOfCanXIDFC(canHwChannel)                  CanXIDFC[(canHwChannel)].LSE
# define Can_GetCanSIDFE(canHwChannel)                                CanSIDFE[(canHwChannel)]
# define Can_GetCanXIDFE(canHwChannel)                                CanXIDFE[(canHwChannel)]
# define Can_GetCanSIDFEStartIndex(canHwChannel)                      CanSIDFE_StartIndex[(canHwChannel)]
# define Can_GetCanXIDFEStartIndex(canHwChannel)                      CanXIDFE_StartIndex[(canHwChannel)]
# define Can_GetCanSIDFEDynStartIndex(canHwChannel)                   CanSIDFE_DynStartIndex[(canHwChannel)]
# define Can_GetCanXIDFEDynStartIndex(canHwChannel)                   CanXIDFE_DynStartIndex[(canHwChannel)]
# define Can_GetCanXIDFEEIDFE_0OfCanXIDFE(canHwChannel)               CanXIDFE[(canHwChannel)].EIDFE_0
# define Can_GetCanXIDFEEIDFE_1OfCanXIDFE(canHwChannel)               CanXIDFE[(canHwChannel)].EIDFE_1

# define Shm               (Can_GetCanShmAdr(canHwChannel))
# define ShmSIDF(num)      (*((tSIFEType*) (Shm.SIDFA + GET_SIDF_OFFSET(num))))
# define ShmXIDF(num)      (*((tXIFEType*) (Shm.XIDFA + GET_XIDF_OFFSET(num))))
# define ShmRXF0(num)      (  (tRxElmType*)(Shm.RXF0A + GET_RX0F_OFFSET(num)) )
# define ShmRXF1(num)      (  (tRxElmType*)(Shm.RXF1A + GET_RX1F_OFFSET(num)) )
# define ShmRXB(num)       (  (tRxElmType*)(Shm.RXBA  + GET_RXB_OFFSET (num)) )
# define ShmTXEF(num)      (*((tTxEventFifoElmType*)(Shm.TXEFA + GET_TXEF_OFFSET(num))))
# define ShmTXB(num)       (*((tTXBEType*) (Shm.TXBA  + GET_TXB_OFFSET (num))))
# define pShmTXB(num)      ( ((tTXBEType*) (Shm.TXBA  + GET_TXB_OFFSET (num))))
#endif /* CAN_GEN_COM_STACK_LIB */


/***************************************************************************/
/* Default switches                                                        */
/* Automatic define settings, depending on user configuration in can_cfg.h */
/***************************************************************************/
#define C_HL_ENABLE_OVERRUN_IN_STATUS

#define C_HL_DISABLE_HW_RANGES_FILTER

#define C_HL_ENABLE_IDTYPE_IN_ID


/* Specify the ID tables which contain the ID type */
# define C_LL_RX_IDTYPE_TABLE      CanRxId0
# define C_LL_TX_IDTYPE_TABLE      CanTxId0


#define C_HL_DISABLE_DUMMY_FCT_CALL


#define C_HL_DISABLE_TX_MSG_DESTROYED


#define C_HL_DISABLE_CANCEL_IN_HW_TASK


#define C_HL_ENABLE_CAN_IRQ_DISABLE

#define C_HL_DISABLE_ADJUST_RXHANDLE

#define C_HL_DISABLE_REJECT_UNWANTED_IDTYPE

#define C_HL_DISABLE_REJECT_REMOTE_FRAME

#define C_HL_DISABLE_REJECT_REMOTE_FRAME_FULLCAN

#define C_HL_ENABLE_REJECT_ILLEGAL_DLC

#define C_HL_DISABLE_COPROCESSOR_SUPPORT



#define C_HL_ENABLE_RETRANSMIT_FCT

#define C_HL_ENABLE_RETRANSMIT_CONF_ISR

#define C_HL_DISABLE_AVOID_REENTRANT_APPLCANCANCELNOTIFICATION

/* Possibility to disable the prototypes of interrupt service routines in the driver header file */

#define C_ENABLE_TX_ACTUAL_MACROS



/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/
#define kCanNumberOfUsedCanRxIdTables 0x01u
#define kCanNumberOfUsedCanTxIdTables 0x01u



#if defined (MISRA_CHECK) /* COV_CAN_MISRA */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptDisable",      0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptRestore",      0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsStop",                 0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsPassive",              0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsWarning",              0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_HwIsBusOff",               0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "Cn",                                     0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CnX",                                    0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "Shm",                                    0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_TxIsRetransmitPossible",   0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_TxRetransmit",             0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_TxIsObjFree",              0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualErrorCounter",        0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualErrorCounter",        0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "assertHardware",                         0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "assertUser",                             0303           /* MD_Can_HwAccess */

# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualDLC",                 0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualExtId",               0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualStdId",               0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualIdType",              0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualFdType",              0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0303           /* MD_Can_HwAccess */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualExtId",               0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualStdId",               0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdType",              0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualFdType",              0310           /* MD_Can_PointerCast */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualFdType",              0303           /* MD_Can_HwAccess */

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0312           /* MD_Can_NoneVolatilePointerCast */

# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_ApplCanTimerStart",        432
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_ApplCanTimerEnd",          432

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdType",              0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualDLC",                 0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualExtId",               0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualStdId",               0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualIdType",              0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanTxActualFdType",              0488           /* MD_Can_0488_LL */

# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptDisable",      1006           /* MD_Can_1006_inlineASM */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_CanInterruptRestore",      1006           /* MD_Can_1006_inlineASM */
# pragma PRQA_MACRO_MESSAGES_OFF "CanLL_SYNCP",                    1006           /* MD_Can_1006_inlineASM */

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualData",                0488           /* MD_Can_0488_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualFdType",              0488           /* MD_Can_0488_LL */

# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdRaw0",              3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdRaw1",              3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualExtId",               3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualStdId",               3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualIdType",              3305           /* MD_Can_3305_LL */
# pragma PRQA_MACRO_MESSAGES_OFF "CanRxActualDLC",                 3305           /* MD_Can_3305_LL */
#endif

/* macros to set DLC and ID in RX-,TX-structures -------------------------- */
#define MK_RX_RANGE_MASK_IDSTD0(id)   ( MK_STDID0((id)) )
#define MK_RX_RANGE_CODE_IDSTD0(id)   ( MK_STDID0((id)) )
#define MK_RX_RANGE_MASK_IDEXT0(id)   ( MK_EXTID0((id)) & (~(kCanIdTypeExt)) )
#define MK_RX_RANGE_CODE_IDEXT0(id)   ( MK_EXTID0((id)) )
#define MK_STDID0(id)                 (vuint32) (((vuint32)(((vuint32)(id)) << 18))       & 0x1FFC0000u)    /* Tx/Rx-Buffer   */
#define MK_EXTID0(id)                 (vuint32) ((vuint32)((id) | (vuint32)kCanIdTypeExt) & 0x5FFFFFFFu)    /* Tx/Rx-Buffer   */


#define MK_TX_DLC(dlc)       ((tCanDlc)((tCanDlc)(dlc) & (tCanDlc)0xFu))                  /* return code has to be tCanDlc (Dlc in register format) */
#define MK_TX_DLC_EXT(dlc)   ((tCanDlc)((tCanDlc)(dlc) & (tCanDlc)0xFu))                  /* return code has to be tCanDlc (Dlc in register format) */

/* extract  DLC from register format to logical format */
#define XT_TX_DLC(dlc)       ((vuint8)((dlc) & 0xFu))        /* return code has to be vuint8 */



/* The macros CanRxActualIdRawx() have to provide the register context of the ID registers.
   It is not necessary to mask any bits. These macros are for internal use only and masking
   will be done in can_hls.c
*/                                                 
# define CanRxActualIdRaw0(rxStruct)   ((vuint32)*((CanChipMsgPtr32)((rxStruct)->pChipMsgObj)))

/* Macros for CAN message access within ApplCanMsgReceived() or PreCopy() function */
#if defined( C_ENABLE_EXTENDED_ID )
# define CanRxActualIdExtHi(rxStruct)      ((vuint8) ( *((rxStruct)->pChipMsgObj) >> 24u) & 0x1Fu)   /* return code has to be vuint8 */
# define CanRxActualIdExtMidHi(rxStruct)   ((vuint8) ( *((rxStruct)->pChipMsgObj) >> 16u))           /* return code has to be vuint8 */
# define CanRxActualIdExtMidLo(rxStruct)   ((vuint8) ( *((rxStruct)->pChipMsgObj) >>  8u))           /* return code has to be vuint8 */
# define CanRxActualIdExtLo(rxStruct)      ((vuint8) ( *((rxStruct)->pChipMsgObj) ))                 /* return code has to be vuint8 */
#endif

#define CanRxActualExtId(rxStruct)        (vuint32) (           (*((volatile vuint32*)((rxStruct)->pChipMsgObj))) & 0x1FFFFFFFUL)
#define CanRxActualStdId(rxStruct)        (vuint16) (((vuint32)((*((volatile vuint32*)((rxStruct)->pChipMsgObj))) & 0x1FFC0000UL)) >> 18u)
#define CanRxActualData(rxStruct,i)       (vuint8)  ( *((rxStruct)->pChipData+(i)) )               /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */ /* return code has to be vuint8 */
#define CanRxActualIdType(rxStruct)      (tCanIdType) ((* (volatile vuint32*) ((rxStruct)->pChipMsgObj))          & kCanIdTypeExt)  /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */ /* return code has to be tCanIdType */
#define CanRxActualFdType(rxStruct)      (tCanFdType) (((((volatile tRXMsg*) ((rxStruct)->pChipMsgObj))->uR1.r1 ) >> 16u) & kCanFdTypeFd)  /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */ /* return code has to be tCanFdType */
                                                                                              /* (tCanFdType)((volatile tRXMsg*)((rxStruct)->pChipMsgObj))->uR1.R1.FDF
                                                                                              R1 Bit 21 EDL: 1 = CAN FD frame format (new DLC-coding and CRC)
                                                                                              R1 Bit 20 BRS: 1 = Frame received with bit rate switching    */
#define CanRxActualDLC(rxStruct)       (vuint8)    CAN_DLC2LEN( ((volatile tRXMsg*)((rxStruct)->pChipMsgObj))->uR1.R1.DLC)       /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */ /* return code has to be vuint8 */

#if defined (C_CPUTYPE_BITORDER_LSB2MSB) /* COV_CAN_CPUTYPE */
# define CanBswap32(x)                   (vuint32)(x)
#else /* endianess */
# define CanBswap32(x)                   (vuint32)  ((((vuint32)((x) & 0xFF000000UL)) >> 24u) | \
                                                    ( ((vuint32)((x) & 0x00FF0000UL)) >>  8u) | \
                                                    ( ((vuint32)((x) & 0x0000FF00UL)) <<  8u) | \
                                                    ( ((vuint32)((x) & 0x000000FFUL)) << 24u))      /* swap b4-b3-b2-b1 to b1-b2-b3-b4 */
#endif /* endianess */

/* support reading the error counters */
#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CanTxActualErrorCounter()             (vuint8)(((( V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(0)))->ECR)         & 0x000000FFUL)
# define CanRxActualErrorCounter()             (vuint8)(((((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(0)))->ECR) >> 8u)  & 0x0000007FUL)
#else
# define CanTxActualErrorCounter(ch)           (vuint8)(((( V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(ch)))->ECR)        & 0x000000FFUL)
# define CanRxActualErrorCounter(ch)           (vuint8)(((((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(ch)))->ECR) >> 8u) & 0x0000007FUL)
#endif /* C_SINGLE_RECEIVE_CHANNEL */



/* Macros for CAN message access within GenericConfirmation() function */
/* *** Only Mirror Mode *** */
#define CanTxActualIdType(txConfStruct)       ((tCanIdType) ( *((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipMsgObj))    & kCanIdTypeExt))        /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */
#define CanTxActualStdId(txConfStruct)        ((vuint16) ((*((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipMsgObj))    & 0x1FFC0000UL) >> 18u))  /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */
#define CanTxActualExtId(txConfStruct)        ((vuint32)    ( *((V_DEF_P2VAR(volatile, vuint32, AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipMsgObj))    & 0x1FFFFFFFUL))                /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */
#define CanTxActualFdType(txConfStruct)       ((vuint8)      ((((volatile tTXMsg*) ((txConfStruct)->pChipMsgObj)) ->uT1.t1 ) >> 16u) & kCanFdTypeFd )                                  /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */ /* return code has to be tCanFdType */
#define CanTxActualDLC(txConfStruct)          ((vuint8)      CAN_DLC2LEN(((volatile tTXMsg*)((txConfStruct)->pChipMsgObj))->uT1.T1.DLC))           /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */
#define CanTxActualData(txConfStruct,i)       *((V_DEF_P2VAR(volatile, vuint8,  AUTOMATIC, VAR_NOINIT)) ((txConfStruct)->pChipData)  +(i))      /* PRQA S 0310, 488 */ /* MD_Can_PointerCast, MD_Can_0488_LL */

/* Macros for CAN message access within PreTransmit() function */
                                        
#define CanTxWriteActId(txStruct,id)      { (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT0.T0.ID) = MK_STDID0((id)); \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.FDF) = 0;              \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.BRS) = 0; } /* actively clear fd flag */ 
#define CanTxWriteActFdId(txStruct,id)    { (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT0.T0.ID) = MK_STDID0((id)); \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.FDF) = 1;              \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.BRS) = 1; } /* actively set fd flag   */ 

#define CanTxWriteActExtId(txStruct,id)   { (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT0.T0.ID) = MK_EXTID0((id)); \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.FDF) = 0;              \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.BRS) = 0; } /* actively clear fd flag  */ 
                                            
#define CanTxWriteActFdExtId(txStruct,id) { (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT0.T0.ID) = MK_EXTID0((id)); \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.FDF) = 1;              \
                                            (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.BRS) = 1; } /* actively set fd flag    */ 

#define CanTxWriteActDLC(txStruct,dlc)   { (((volatile tTXMsg*)((txStruct).pChipMsgObj))->uT1.T1.DLC) = ((dlc) & 0x0Fu); } 


/* Macros for Message and CAN buffer access (mostly used by upper layers but also available for usage by the application) */
/* Message buffers (for each message ID) */



#define CAN_HL_MIN(x, y) (((x)>(y)) ? (y) : (x)) /* COV_CAN_GENDATA_FAILURE */
#define CAN_HL_MAX(x, y) (((x)<(y)) ? (y) : (x)) /* COV_CAN_GENDATA_FAILURE */

/***************************************************************************************************/
/* Macros for dummy statements */
#if !defined(CAN_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
#  define CAN_DUMMY_STATEMENT(x) (x) = (x) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
# else
#  define CAN_DUMMY_STATEMENT(x)
# endif
#endif
#if !defined(CAN_DUMMY_STATEMENT_CONST) /* COV_CAN_COMPATIBILITY */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
#  define CAN_DUMMY_STATEMENT_CONST(x) (void)(x)
# else
#  define CAN_DUMMY_STATEMENT_CONST(x)
# endif
#endif

/***************************************************************************************************/
/* Macros for DET and assertions */
#if (CAN_DEV_ERROR_REPORT == STD_ON) /* \trace SPEC-1404, SPEC-1696 */
/* \trace SPEC-1725, SPEC-1403, SPEC-1568 */
# define Can_CallDetReportError(api, err) ((void) Det_ReportError(CAN_MODULE_ID, CAN_INSTANCE_ID, (api), (err)))
# define assertHardware(a, b, c)  if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertInternal(a, b, c)  if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertUser(a, b, c)      if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define assertGen(a, b, c)       if (!(a)) {Can_CallDetReportError(CAN_HW_ACCESS_ID, (c));}
# define C_ENABLE_HARDWARE_CHECK
# define C_ENABLE_INTERNAL_CHECK
# define C_ENABLE_USER_CHECK
# define C_ENABLE_GEN_CHECK
#else
# define Can_CallDetReportError(api, err)
# define assertHardware(a, b, c)
# define assertInternal(a, b, c)
# define assertUser(a, b, c)
# define assertGen(a, b, c)
#endif

/***************************************************************************************************/
/* Macros for Critical Area 0 abstraction */

#define CanDeclareGlobalInterruptOldStatus
/* CAN_EXCLUSIVE_AREA_0 called only by LL code */
#define CanSingleGlobalInterruptDisable()     SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanSingleGlobalInterruptRestore()     SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
#define CanGlobalInterruptDisable()           SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanGlobalInterruptRestore()           SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()
#define CanNestedGlobalInterruptDisable()     SchM_Enter_Can_CAN_EXCLUSIVE_AREA_0()
#define CanNestedGlobalInterruptRestore()     SchM_Exit_Can_CAN_EXCLUSIVE_AREA_0()

/***************************************************************************************************/
/* Macros for LL-HLL compatibility */

/***************************************************************************************************/
/* Macros for ProtectedMode / PeripheralAccess */
# if defined ( C_ENABLE_USER_MODE_OS )
#  define CAN_WRITE_PROTECTED_REG8(area, regAdr, val)         osWritePeripheral8((area), (uint32)(regAdr), (val))
#  define CAN_WRITE_PROTECTED_REG16(area, regAdr, val)        osWritePeripheral16((area), (uint32)(regAdr), (val))
#  define CAN_WRITE_PROTECTED_REG32(area, regAdr, val)        osWritePeripheral32((area), (uint32)(regAdr), (val))
#  define CAN_WRITE_PROTECTED_REG8_RESET(area, regAdr, bits)  osModifyPeripheral8((area), (uint32)(regAdr), (uint8)~(bits), (uint8)0x00u)
#  define CAN_WRITE_PROTECTED_REG16_RESET(area, regAdr, bits) osModifyPeripheral16((area), (uint32)(regAdr), (uint16)~(bits), (uint16)0x0000u)
#  define CAN_WRITE_PROTECTED_REG32_RESET(area, regAdr, bits) osModifyPeripheral32((area), (uint32)(regAdr), (uint32)~(bits), (uint32)0x00000000UL)
#  define CAN_WRITE_PROTECTED_REG8_SET(area, regAdr, bits)    osModifyPeripheral8((area), (uint32)(regAdr), (uint8)0xFFu, (bits))
#  define CAN_WRITE_PROTECTED_REG16_SET(area, regAdr, bits)   osModifyPeripheral16((area), (uint32)(regAdr), (uint16)0xFFFFu, (bits))
#  define CAN_WRITE_PROTECTED_REG32_SET(area, regAdr, bits)   osModifyPeripheral32((area), (uint32)(regAdr), (uint32)0xFFFFFFFFUL, (bits))
#  define CAN_READ_PROTECTED_REG8(area, regAdr)               osReadPeripheral8((area), (uint32)(regAdr))
#  define CAN_READ_PROTECTED_REG16(area, regAdr)              osReadPeripheral16((area), (uint32)(regAdr))
#  define CAN_READ_PROTECTED_REG32(area, regAdr)              osReadPeripheral32((area), (uint32)(regAdr))
# endif
# if defined ( C_ENABLE_USER_MODE_APPL )
#  define CAN_WRITE_PROTECTED_REG8(area, regAdr, val)         ApplCanWriteProtectedRegister8((regAdr), (uint8)0xFFu, (val))
#  define CAN_WRITE_PROTECTED_REG16(area, regAdr, val)        ApplCanWriteProtectedRegister16((regAdr), (uint16)0xFFFFu, (val))
#  define CAN_WRITE_PROTECTED_REG32(area, regAdr, val)        ApplCanWriteProtectedRegister32((regAdr), (uint32)0xFFFFFFFFUL, (val))
#  define CAN_WRITE_PROTECTED_REG8_RESET(area, regAdr, bits)  ApplCanWriteProtectedRegister8((regAdr), (bits), (uint8)0x00u)
#  define CAN_WRITE_PROTECTED_REG16_RESET(area, regAdr, bits) ApplCanWriteProtectedRegister16((regAdr), (bits), (uint16)0x0000u)
#  define CAN_WRITE_PROTECTED_REG32_RESET(area, regAdr, bits) ApplCanWriteProtectedRegister32((regAdr), (bits), (uint32)0x00000000UL)
#  define CAN_WRITE_PROTECTED_REG8_SET(area, regAdr, bits)    ApplCanWriteProtectedRegister8((regAdr), (bits), (bits))
#  define CAN_WRITE_PROTECTED_REG16_SET(area, regAdr, bits)   ApplCanWriteProtectedRegister16((regAdr), (bits), (bits))
#  define CAN_WRITE_PROTECTED_REG32_SET(area, regAdr, bits)   ApplCanWriteProtectedRegister32((regAdr), (bits), (bits))
#  define CAN_READ_PROTECTED_REG8(area, regAdr)               ApplCanReadProtectedRegister8((regAdr))
#  define CAN_READ_PROTECTED_REG16(area, regAdr)              ApplCanReadProtectedRegister16((regAdr))
#  define CAN_READ_PROTECTED_REG32(area, regAdr)              ApplCanReadProtectedRegister32((regAdr))
# endif
# if !defined(C_ENABLE_USER_MODE_OS) && !defined(C_ENABLE_USER_MODE_APPL)
#  define CAN_WRITE_PROTECTED_REG8(area, regAdr, val)         *(regAdr) = (val)
#  define CAN_WRITE_PROTECTED_REG16(area, regAdr, val)        *(regAdr) = (val)
#  define CAN_WRITE_PROTECTED_REG32(area, regAdr, val)        *(regAdr) = (val)
#  define CAN_WRITE_PROTECTED_REG8_RESET(area, regAdr, bits)  *(regAdr) &= (uint8)~(bits)
#  define CAN_WRITE_PROTECTED_REG16_RESET(area, regAdr, bits) *(regAdr) &= (uint16)~(bits)
#  define CAN_WRITE_PROTECTED_REG32_RESET(area, regAdr, bits) *(regAdr) &= (uint32)~(bits)
#  define CAN_WRITE_PROTECTED_REG8_SET(area, regAdr, bits)    *(regAdr) |= (bits)
#  define CAN_WRITE_PROTECTED_REG16_SET(area, regAdr, bits)   *(regAdr) |= (bits)
#  define CAN_WRITE_PROTECTED_REG32_SET(area, regAdr, bits)   *(regAdr) |= (bits)
#  define CAN_READ_PROTECTED_REG8(area, regAdr)               *(regAdr)
#  define CAN_READ_PROTECTED_REG16(area, regAdr)              *(regAdr)
#  define CAN_READ_PROTECTED_REG32(area, regAdr)              *(regAdr)
# endif

/***************************************************************************/
/* error codes                                                             */
/***************************************************************************/
/* error numbers for User Assertions 0x20-0x3f - hardware dependent */
#define kCanErrorDisabledChannel                  ((vuint8)0x20)

/* error numbers for Generation tool Assertions 0x60-0x7f - hardware dependent */

/* error numbers for Hardware Assertions 0xA0-0xBF - hardware dependent */
# define kCanErrorWrongBaseAddress                ((vuint8)0xA0)
# define kCanErrorCanSleepFromReset               ((vuint8)0xA1)
# define kCanErrorMcanRevision                    ((vuint8)0xA2)
# define kCanErrorMcanMessageRAMOverflow          ((vuint8)0xA3)
# define kCanErrorChannelHdlTooLarge              ((vuint8)0xA4)
# define kCanErrorSICANFDKeyRejected              ((vuint8)0xA5)
# define kCanErrorUnexpectedConfirmation          ((vuint8)0xA6)

/* error numbers for Internal Assertions 0xe0-0xff - hardware dependent */
# define kCanErrorUndefinedStatus                 ((vuint8)0xE0)

/***************************************************************************/
/* CAN-Hardware Data Definitions                                           */
/***************************************************************************/

/***************************************************************************/
/* Special switches need by CAN driver                                     */
/***************************************************************************/

/***************************************************************************/
/* Defines / data types / structures / unions                              */
/***************************************************************************/
/* Define CAN Chip hardware; segment must be located in locator file    */
/* register layout of the can chip                                      */
/* Structure describing CAN receive buffer. */
/* Note: When the M_CAN addresses the Message RAM it addresses 32-bit words, not single bytes. */

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
# if( kCanNumberOfUsedCanRxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id); \
                                   (paraStruct)->idRaw4 = MK_STDID4(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id); \
                                   (paraStruct)->idRaw4 = MK_EXTID4(id)
# elif ( kCanNumberOfUsedCanRxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id)
# elif ( kCanNumberOfUsedCanRxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id)
# elif ( kCanNumberOfUsedCanRxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id)
# else
#  define SET_PARASTRUCT_IDRAW_RX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id)
#  define SET_PARASTRUCT_IDRAW_RX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id)
# endif
#endif

#if( kCanNumberOfUsedCanTxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id); \
                                   (paraStruct)->idRaw4 = MK_STDID4(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id); \
                                   (paraStruct)->idRaw4 = MK_EXTID4(id)
#elif ( kCanNumberOfUsedCanTxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id); \
                                   (paraStruct)->idRaw3 = MK_STDID3(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id); \
                                   (paraStruct)->idRaw3 = MK_EXTID3(id)
#elif ( kCanNumberOfUsedCanTxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id); \
                                   (paraStruct)->idRaw2 = MK_STDID2(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id); \
                                   (paraStruct)->idRaw2 = MK_EXTID2(id)
#elif ( kCanNumberOfUsedCanTxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id); \
                                   (paraStruct)->idRaw1 = MK_STDID1(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id); \
                                   (paraStruct)->idRaw1 = MK_EXTID1(id)
#else
# define SET_PARASTRUCT_IDRAW_TX_STD(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_STDID0(id)
# define SET_PARASTRUCT_IDRAW_TX_EXT(paraStruct, id) \
                                   (paraStruct)->idRaw0 = MK_EXTID0(id)
#endif

/***************************************************************************/
/* Core - LowLevel API                                                     */
/***************************************************************************/
typedef struct sCanRxInfoStruct
{
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  CanObjectHandle   localMailboxHandle; 
  Can_IdType               localId; 
  uint8                    localDlc;
  /* LL specific part */
} tCanRxInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxInfoStruct, VAR_NOINIT) CanRxInfoStructPtr;

typedef struct sCanTxConfInfoStruct
{
  CanChipMsgPtr     pChipMsgObj;
  CanChipDataPtr    pChipData;
  /* LL specific part */
  tAlign32bit     tmpTXB; /* PRQA S 0759 */ /* MD_Can_Union */
} tCanTxConfInfoStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxConfInfoStruct, VAR_NOINIT) CanTxConfInfoStructPtr;

typedef struct sCanInitParaStruct
{
  CanInitHandle     initObject;
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
  tCanRxId0                idRaw0;
# if( kCanNumberOfUsedCanRxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId1                idRaw1;
# endif
# if( kCanNumberOfUsedCanRxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId2                idRaw2;
# endif
# if( kCanNumberOfUsedCanRxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId3                idRaw3;
# endif
# if( kCanNumberOfUsedCanRxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
  tCanRxId4                idRaw4;
# endif
  tCanIdType               idType;
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8                    doRamCheck;
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  uint8                    isChRamCheckFail;
# endif
#endif
  uint8                    isInitOk;
  /* LL specific part */
  vuint32 ie;     /* INT enable/disable control */
  vuint32 txbtie; /* TXBTIE, TXBCIE enable/disable control */
  #if defined( C_ENABLE_STD_ID )
  # if (kCanNumberOfStandardFilter > 0)  /* at least one std filter available */
  V_DEF_P2CONST(V_NONE, Can_SIDFEType, AUTOMATIC, CONST_PBCFG) pFS;
  # endif
  vuint16 stdFeCount;
  #endif
  #if defined( C_ENABLE_EXTENDED_ID )
  vuint16 extFeCount;
  #endif
  vuint32 tmpVal;
  V_DEF_P2VAR(V_NONE, tTXBEType, AUTOMATIC, VAR_NOINIT) pTXB; /* pointer to TxBuffer */
} tCanInitParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanInitParaStruct, VAR_NOINIT) CanInitParaStructPtr;

#define TxDataPtr Can_SduPtrType /* CBD compatibility */
typedef struct sCanTxTransmissionParaStruct
{
  /* logical formats */
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement; /* logical index within the mailbox for muxTx or FIFO element */
  CanObjectHandle   hwObjHandle;    /* set to the initial hwHandle by core but has to be modified by LL in case of muxTx or FIFO */
  CanObjectHandle   activeSendObject; /* index of the logical Tx mailbox (Tx * Element) */
  tCanTxId0                idRaw0;
#if( kCanNumberOfUsedCanTxIdTables > 1 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId1                idRaw1;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 2 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId2                idRaw2;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 3 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId3                idRaw3;
#endif
#if( kCanNumberOfUsedCanTxIdTables > 4 ) /* COV_CAN_COMPATIBILITY */
  tCanTxId4                idRaw4;
#endif
  tCanDlc                  dlcRaw;
  TxDataPtr                CanMemCopySrcPtr;
#if defined( C_ENABLE_CAN_FD_USED )
  tCanFdType               fdType;
  tCanFdBrsType            fdBrsType;
  uint8                    messageLen;
  uint8                    frameLen;
  uint8                    paddingVal;
#endif
  Can_PduType              pdu;
  /* LL specific part */
  tTXBEType*      lpTXB;
  #if defined( C_ENABLE_PRETRANSMIT_FCT ) 
  tAlign32bit     tmpTXB; /* PRQA S 0759 */ /* MD_Can_Union */
  #endif
} tCanTxTransmissionParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxTransmissionParaStruct, VAR_NOINIT) CanTxTransmissionParaStructPtr;

typedef struct sCanRxBasicParaStruct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
#if !defined( C_HL_ENABLE_OVERRUN_IN_STATUS ) && defined( C_ENABLE_OVERRUN )
#endif
  tCanRxInfoStruct         rxStruct;
  /* LL specific part */
  V_DEF_P2VAR(V_NONE,   tRxElmType, AUTOMATIC, VAR_NOINIT) pShm;        /* shared message RAM   */
  V_DEF_P2VAR(volatile, vuint32,    AUTOMATIC, VAR_NOINIT) pFifoAck;    /* Fifo acknowledge register (RXFnA) */
  V_DEF_P2VAR(volatile, tRXFnS,     AUTOMATIC, VAR_NOINIT) pFifoStatus; /* Fifo status register (RXFnS) */
  tRxElmType fElm;
  vuint8     fGetIndex;
} tCanRxBasicParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxBasicParaStruct, VAR_NOINIT) CanRxBasicParaStructPtr;

typedef struct sCanRxFullParaStruct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   hwObjHandle;
  tCanRxInfoStruct         rxStruct;
  /* LL specific part */
  V_DEF_P2VAR(V_NONE, tRxElmType, AUTOMATIC, VAR_NOINIT) pShm;        /* shared message RAM   */
  vuint16    objectNumber;
  tRxElmType bfElm;
} tCanRxFullParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanRxFullParaStruct, VAR_NOINIT) CanRxFullParaStructPtr;

#if defined( C_ENABLE_CANCEL_SUPPORT_API )
typedef struct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement; /* logical index within the mailbox for muxTx or FIFO element */
  CanObjectHandle   hwObjHandle;    /* set to the initial hwHandle by core but has to be modified by LL in case of muxTx or FIFO */
  CanObjectHandle   activeSendObject; /* index of the logical mailbox + muxTx or FIFO element 0..n */
  CanTransmitHandle   canHandleCurTxObj;
} tCanTxCancellationParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxCancellationParaStruct, VAR_NOINIT) CanTxCancellationParaStructPtr;
#endif

typedef struct
{
  CanObjectHandle   mailboxHandle;
  CanObjectHandle   mailboxElement; /* logical index within the mailbox for muxTx or FIFO element */
  CanObjectHandle   hwObjHandle;    /* set to the initial hwHandle by core but has to be modified by LL in case of muxTx or FIFO */
  CanObjectHandle   activeSendObject; /* index of the logical mailbox + muxTx or FIFO element 0..n */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  CanTxConfInfoStructPtr   txStructConf;
#endif
  tAlign32bit tmpTXB; /* PRQA S 0759 */ /* MD_Can_Union */
} tCanTxConfirmationParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTxConfirmationParaStruct, VAR_NOINIT) CanTxConfirmationParaStructPtr;

typedef struct sCanTaskParaStruct
{
  CanObjectHandle mailboxHandle;
  CanObjectHandle hwObjHandle;
  /* LL specific part */
} tCanTaskParaStruct;
V_DEF_P2VAR_TYPE(V_NONE, tCanTaskParaStruct, VAR_NOINIT) CanTaskParaStructPtr;
    
/***************************************************************************/
/* module global variable declaration                                      */
/***************************************************************************/

/***************************************************************************/
/* External Declarations                                                   */
/***************************************************************************/
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED  /*---------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /*----------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***************************************************************************/
/* local function prototypes (only internal usage)                         */
/***************************************************************************/
#define CAN_START_SEC_STATIC_CODE  /*--------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/************************************************************************************************************
 *  CanLL_WriteReg32()
 ***********************************************************************************************************/
/*! \brief         Write value and do RamCheck
 *  \details       Write the value of the hardware mailbox or controller register and read back for RamCheck. 
 *                 set initPara->isChRamCheckFail or initPara->isMbRamCheckFail in case of an HW issue to deactivate hardware.
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     regPtr           valid pointer to Register to be written.
 *  \param[in]     value            value to be written.
 *  \param[in]     readMask         mask to check the read back value.
 *  \param[in]     doRamCheck       execute the RAM check (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        kCanTrue         RamCheck failed.
 *  \return        kCanFalse        RamCheck passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WriteReg32(CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, uint32 value, uint32 readMask, CanInitParaStructPtr initPara);
/* CODE CATEGORY 4 END */

# if defined(C_ENABLE_USER_MODE_APPL) || defined(C_ENABLE_USER_MODE_OS)
/************************************************************************************************************
 *  CanLL_WriteProtectedReg32()
 ***********************************************************************************************************/
/*! \brief         Write value via OS and do RamCheck
 *  \details       Write the value of the hardware mailbox or controller register and read back for RamCheck. 
 *                 set initPara->isChRamCheckFail or initPara->isMbRamCheckFail in case of an HW issue to deactivate hardware.
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     area             Memory area to be written.
 *  \param[in]     regPtr           valid pointer to Register to be written.
 *  \param[in]     value            Value to be written.
 *  \param[in]     readMask         Mask to check the read back value.
 *  \param[in]     doRamCheck       execute the RAM check (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        kCanTrue         RamCheck failed.
 *  \return        kCanFalse        RamCheck passed.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WriteProtectedReg32(CAN_CHANNEL_CANTYPE_FIRST uint16 area, CanChipMsgPtr32 regPtr, uint32 value, uint32 readMask, CanInitParaStructPtr initPara);
/* CODE CATEGORY 4 END */
# endif /* User Mode */

/**********************************************************************************************************************
 *  CanLL_InitBegin()
 *********************************************************************************************************************/
/*! \brief         Starts the channel initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBegin( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
/**********************************************************************************************************************
 *  CanLL_InitBeginIsRegisterCorrupt()
 *********************************************************************************************************************/
/*! \brief         Performs the channel register RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanFalse           No corrupt register RAM found
 *                 kCanTrue            Register RAM is considered corrupt or failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */


#endif

/**********************************************************************************************************************
 *  CanLL_InitBeginSetRegisters()
 *********************************************************************************************************************/
/*! \brief         Performs the channel register initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMailboxTx()
 *********************************************************************************************************************/
/*! \brief         Initializes a transmit mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxTx( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

#if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxTxDeactivate()
 *********************************************************************************************************************/
/*! \brief         Deactivates a transmit mailbox if it is considered corrupt by the RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxTxDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
#endif


#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCan()
 *********************************************************************************************************************/
/*! \brief         Initializes a receive FullCAN mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxFullCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCanDeactivate()
 *********************************************************************************************************************/
/*! \brief         Deactivates a receive FullCAN mailbox if it is considered corrupt by the RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxFullCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
# endif

#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCan()
 *********************************************************************************************************************/
/*! \brief         Initializes a receive BasicCAN mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxBasicCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCanDeactivate()
 *********************************************************************************************************************/
/*! \brief         Deactivates a receive BasicCAN mailbox if it is considered corrupt by the RAM check
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxBasicCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */


/**********************************************************************************************************************
 *  CanLL_InitEndSetRegisters()
 *********************************************************************************************************************/
/*! \brief         Finishes the channel register initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitEnd()
 *********************************************************************************************************************/
/*! \brief         Finishes the channel initialization
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK )
/**********************************************************************************************************************
 *  CanLL_InitIsMailboxCorrupt()
 *********************************************************************************************************************/
/*! \brief         Performs the RAM check for a mailbox
 *  \details       Called by CanInit()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] initPara            Pointer to local variables of CanInit()
 *  \return        kCanFalse           Mailbox is not corrupt
 *                 kCanTrue            Mailbox is considered corrupt or failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_InitIsMailboxCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */
#endif


/**********************************************************************************************************************
 *  CanLL_InitPowerOn()
 *********************************************************************************************************************/
/*! \brief         Performs the hardware specific global module initialization
 *  \details       Called by CanInitPowerOn()
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOn( void );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMemoryPowerOn()
 *********************************************************************************************************************/
/*! \brief         Internal function, called by Can_InitMemory().
 *  \details       Performs the platform specific memory initialization.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMemoryPowerOn( void );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitPowerOnChannelSpecific()
 *********************************************************************************************************************/
/*! \brief         Performs the channel dependent hardware specific global module initialization
 *  \details       Called by CanInitPowerOn()
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanOk              Successfully completed
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOnChannelSpecific( CAN_CHANNEL_CANTYPE_ONLY );
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_TxBegin()
 *********************************************************************************************************************/
/*! \brief         Perform start of transmission
 *  \details       Called by transmission to prepare send object
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxSetMailbox()
 *********************************************************************************************************************/
/*! \brief         Set mailbox data for transmission
 *  \details       Called by transmission to set ID, DLC
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxCopyToCan()
 *********************************************************************************************************************/
/*! \brief         Set mailbox data for transmission
 *  \details       Called by transmission to set data part in mailbox
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxStart()
 *********************************************************************************************************************/
/*! \brief         Trigger mailbox to start the transmission
 *  \details       Called by transmission to start transmission
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \return        kCanOk              No issue
 *                 kCanFailed          Issue occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_TxEnd()
 *********************************************************************************************************************/
/*! \brief         Perform end handling of the transmission
 *  \details       Called by transmission to finish transmission
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of transmission
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);
/* CODE CATEGORY 1 END */
#if defined( C_ENABLE_TX_POLLING )
/**********************************************************************************************************************
 *  CanLL_TxIsGlobalConfPending()
 *********************************************************************************************************************/
/*! \brief         Check global pending of transmission
 *  \details       Called by transmission to get global pending flag
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanTrue            pending confirmation
 *                 kCanFailed          no pending confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
/**********************************************************************************************************************
 *  CanLL_TxProcessPendings()
 *********************************************************************************************************************/
/*! \brief         Check pending of transmission object
 *  \details       Called by transmission to get pending flag of mailbox
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txPara              Pointer to local variables of confirmation task
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);
/* CODE CATEGORY 2 END */
#endif
/**********************************************************************************************************************
 *  CanLL_TxConfBegin()
 *********************************************************************************************************************/
/*! \brief         Perform start of confirmation
 *  \details       Called by confirmation
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);
/* CODE CATEGORY 1 END */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/**********************************************************************************************************************
 *  CanLL_TxConfSetTxConfStruct()
 *********************************************************************************************************************/
/*! \brief         Set confirmation struct
 *  \details       Called by confirmation to set confirmation data struct
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);
/* CODE CATEGORY 1 END */
#endif
/**********************************************************************************************************************
 *  CanLL_TxConfSetTxConfStruct()
 *********************************************************************************************************************/
/*! \brief         Perform confirmation end handling
 *  \details       Called by confirmation
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara);
/* CODE CATEGORY 1 END */

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedBegin()
 *********************************************************************************************************************/
/*! \brief         Perform BasicCAN receive begin
 *  \details       Called by reception to begin handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \return        kCanOk              No Issue occur
 *                 kCanFailed          Issue occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxBasicReleaseObj()
 *********************************************************************************************************************/
/*! \brief         Release BasicCAN mailbox
 *  \details       Called by reception to release object
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedEnd()
 *********************************************************************************************************************/
/*! \brief         Release BasicCAN receive end
 *  \details       Called by reception to finish handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara);
/* CODE CATEGORY 1 END */
# if defined( C_ENABLE_RX_BASICCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxBasicIsGlobalIndPending()
 *********************************************************************************************************************/
/*! \brief         Check BasicCAN receive global pending
 *  \details       Called by reception to get pending state
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanTrue            global pending
 *                 kCanFailed          no pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
/**********************************************************************************************************************
 *  CanLL_RxBasicProcessPendings()
 *********************************************************************************************************************/
/*! \brief         Check BasicCAN receive pending
 *  \details       Called by reception to get mailbox pending state
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] taskPara            Pointer to local variables of reception task
 *  \return        kCanTrue            mailbox pending
 *                 kCanFailed          no pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_BASICCAN_POLLING */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedBegin()
 *********************************************************************************************************************/
/*! \brief         Perform FullCAN receive begin
 *  \details       Called by reception to begin handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \return        kCanOk              No Issue occur
 *                 kCanFailed          Issue occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxFullReleaseObj()
 *********************************************************************************************************************/
/*! \brief         Release FullCAN mailbox
 *  \details       Called by reception to release object
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);
/* CODE CATEGORY 1 END */
/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedEnd()
 *********************************************************************************************************************/
/*! \brief         Release FullCAN receive end
 *  \details       Called by reception to finish handling
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] rxBasicPara         Pointer to local variables of reception
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara);
/* CODE CATEGORY 1 END */
# if defined( C_ENABLE_RX_FULLCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxFullIsGlobalIndPending()
 *********************************************************************************************************************/
/*! \brief         Check FullCAN receive global pending
 *  \details       Called by reception to get pending state
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanTrue            global pending
 *                 kCanFailed          no pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
/**********************************************************************************************************************
 *  CanLL_RxFullProcessPendings()
 *********************************************************************************************************************/
/*! \brief         Check FullCAN receive pending
 *  \details       Called by reception to get mailbox pending state
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in,out] taskPara            Pointer to local variables of reception task
 *  \return        kCanTrue            mailbox pending
 *                 kCanFailed          no pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara);
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_FULLCAN_POLLING */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

/**********************************************************************************************************************
 *  CanLL_ErrorHandlingBegin()
 *********************************************************************************************************************/
/*! \brief         Perform error handling begin
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
/**********************************************************************************************************************
 *  CanLL_BusOffOccured()
 *********************************************************************************************************************/
/*! \brief         Check BusOff occur
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanTrue            BusOff occur
 *                 kCanFailed          no BusOff occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */

#if defined( C_HL_ENABLE_OVERRUN_IN_STATUS )    /* COV_CAN_OVERRUN_IN_STATUS */
# if defined( C_ENABLE_OVERRUN ) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/**********************************************************************************************************************
 *  CanLL_RxBasicCanOverrun()
 *********************************************************************************************************************/
/*! \brief         Check BasicCAN overrun occur
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \return        kCanTrue            Overrun occur
 *                 kCanFailed          no Overrun occur
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicCanOverrun(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
# endif
#endif


/**********************************************************************************************************************
 *  CanLL_ErrorHandlingEnd()
 *********************************************************************************************************************/
/*! \brief         Perform error handling end
 *  \details       Called by error handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 2 END */
#if defined( C_ENABLE_EXTENDED_STATUS )
/**********************************************************************************************************************
 *  CanLL_GetStatusBegin()
 *********************************************************************************************************************/
/*! \brief         Perform read out of status information
 *  \details       Called by GetStatus API
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 3 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GetStatusBegin(CAN_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 3 END */
#endif
/**********************************************************************************************************************
 *  CanLL_ModeTransition()
 *********************************************************************************************************************/
/*! \brief         Perfrom mode change
 *  \details       Called by mode handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \param[in]     mode                mode to be set
 *  \param[in]     busOffRecovery      BusOff recovery should be done or not
 *  \param[in]     ramCheck            RamCheck should be done or not
 *  \return        kCanOk              Successfully completed
 *                 kCanRequested       Mode not yet reached
 *                 kCanFailed          Failure occured
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST vuint8 mode, vuint8 busOffRecovery, vuint8 ramCheck);
/* CODE CATEGORY 4 END */
/**********************************************************************************************************************
 *  CanLL_StopReinit()
 *********************************************************************************************************************/
/*! \brief         Perform reinitialization for mode change
 *  \details       Called by mode handler
 *  \param[in]     channel             Index of the CAN channel (only if multiple channels are used)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
**********************************************************************************************************************/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_StopReinit(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL )   /* COV_CAN_LOCK_ISR_BY_APPL */
/************************************************************************************************************
 *  CanLL_CanInterruptDisable()
 ***********************************************************************************************************/
/*! \brief         Disables CAN interrupts.
 *  \details       Stores current state and disables the individual CAN interrupt sources.
 *  \param[in]     canHwChannel              CAN channel
 *  \param[out]    localInterruptOldFlagPtr  Pointer to global variable that holds the interrupt state
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr);
/* CODE CATEGORY 1 END */

/************************************************************************************************************
 *  CanLL_CanInterruptRestore()
 ***********************************************************************************************************/
/*! \brief         Restores CAN interrupts.
 *  \details       Restores the previous state of the individual CAN interrupt sources.
 *  \param[in]     canHwChannel              CAN channel
 *  \param[in]     localInterruptOldFlag     Global variable that holds the interrupt state
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 ***********************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOld localInterruptOldFlag);
/* CODE CATEGORY 1 END */
#endif




#if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_TriCoreErratum_AI_H001()
 ***********************************************************************************************************/
/*! \brief         Enforces clearing of the requested interrupt flag. 
 *  \details       workaround for MCMCAN Erratum AI.H001. Persists the clearing of an interrupt flag 
 *                 in the interrupt request register.
 *  \param[in]     Controller   CAN controller
 *  \param[in]     CanIrFlag    Interrupt flag
 *  \pre           -
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANTYPE_FIRST vuint32 CanIrFlag);
/* CODE CATEGORY 4 END */
#endif

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanBoschErratum_010()
 ***********************************************************************************************************/
/*! \brief         Restart Tx FSM after erratum_010 appeared (When CCCR.CCE is set while a Tx scan is in progress the Tx Handler FSM stops.)
 *  \details       1) Cancel all pending transmission requests, 
 *                 2) Issue a clock stop request
 *                 3) Wait until Clock Stop Acknowledge
 *                 4) Go back to Normal Operation (First reset CCCR.CSR, then reset CCCR.INIT)
 *                 5) Issue a second clock stop request
 *                 6) Await Clock Stop Acknowledge
 *                 7) Set CCCR.CCE and reset CCCR.CSR
 *  \param[in]     Controller   CAN controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
#if ( CAN_BOSCH_ERRATUM_010 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanBoschErratum_010( CAN_HW_CHANNEL_CANTYPE_ONLY );
#endif
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_SetAllFilter()
 ***********************************************************************************************************/
/*! \brief         Write the hardware filters into the Message RAM
 *  \details       Write standard and extended filter information for each CAN channel into the Message RAM
 *  \param[in]     Controller   CAN controller
 *  \return        kCanOk     Filters succesful set
 *  \return        kCanFailed Filters could not be set
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8,   STATIC_CODE) CanLL_SetAllFilter( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara );
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_SetAllRegister()
 ***********************************************************************************************************/
/*! \brief         Initialize MCAN configuration registers
 *  \details       Assure that MCAN is in configuration enable mode and fill in all configuration relevant registers
 *  \param[in]     Controller   CAN controller
 *  \param[in]     initInfo     CAN controller configuration data
 *  \return        kCanOk     Registers succesful set
 *  \return        kCanFailed Registers could not be set
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_SetAllRegister( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_SetExtraRegister()
 ***********************************************************************************************************/
/*! \brief         Initialize Platform specific registers
 *  \details       Assure that the platform specific additional functionality is configured correctly and that all aditional registers are initialized.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void,   STATIC_CODE) CanLL_SetExtraRegister( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr localInfo );
/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StartRequest()
 ***********************************************************************************************************/
/*! \brief         Start mode transition from STOP to NORMAL
 *  \details       Check the current state and trigger the transition to Normal Operation mode if necessary
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Normal Mode already reached
 *  \return        kCanRequested:   Transition to Normal Mode requested 
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_StartRequest(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

#if defined(C_ENABLE_SILENT_MODE) 
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StartSilentRequest()
 ***********************************************************************************************************/
/*! \brief         Start mode transition from STOP to NORMAL
 *  \details       Check the current state and trigger the transition to Normal/Silent Operation mode if necessary
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Normal/Silent Mode already reached
 *  \return        kCanRequested:   Transition to Normal/Silent Mode requested 
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_StartSilentRequest(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_StopRequest()
 ***********************************************************************************************************/
/*! \brief         Stop mode transition from NORMAL to STOP
 *  \details       Check the current state and trigger the transition to Stop mode if necessary
 *  \param[in]     Controller       CAN controller
 *  \return        kCanOk:          Stop Mode already reached
 *  \return        kCanRequested:   Transition to Stop Mode requested 
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_StopRequest(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanLL_if_TxIsObjConfPending()
 ***********************************************************************************************************/
/*! \brief         Check for pending Tx confirmations
 *  \details       Check all Tx objects within the configuration for any pending confirmation or cancellation
 *  \param[in]     Controller   CAN controller
 *  \param[in]     txBuffer     Buffer requests pending
 *  \return        kCanTrue:    at least one request pending
 *  \return        kCanFalse:   no request is pending
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
#if defined(C_ENABLE_TX_POLLING)
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint32, STATIC_CODE) CanLL_if_TxIsObjConfPending( CAN_CHANNEL_CANTYPE_FIRST vuint32 txBuffer );
#endif
/* CODE CATEGORY 4 END */

#if( CAN_BOSCH_ERRATUM_012 == STD_ON )  /* COV_CAN_ERRATUM_OFF */
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanInterruptTimeoutCounter()
 ***********************************************************************************************************/
/*! \brief         Protocol exception handling
 *  \details       check for protocol error and try to proceed if an exception appeared
 *  \param[in]     Controller   CAN controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void,   STATIC_CODE) CanInterruptTimeoutCounter(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif /* End CAN_BOSCH_ERRATUM_012 */

/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanErrorHandlingBusOff()
 ***********************************************************************************************************/
/*! \brief         BusOff detection and treatment 
 *  \details       check the MCAN BusOff state,Message RAM access error and failure handling
 *  \param[in]     Controller   CAN controller
 *  \return        kCanTrue:    Channel is in BusOff state
 *  \return        kCanFalse:   Channel is not in BusOff state
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanErrorHandlingBusOff(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */

#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
      defined( C_ENABLE_INDIVIDUAL_POLLING ) )        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanBasicInterruptRx()
 ***********************************************************************************************************/
/*! \brief         Rx interrupt detection and handling 
 *  \details       Check the Rx buffer and Rx FIFO(s) for new data and call the appropriate CanMsgReceived function.
 *  \param[in]     Controller   CAN controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanBasicInterruptRx(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif

#if ((defined( C_ENABLE_RX_FULLCAN_OBJECTS )  && !defined( C_ENABLE_RX_FULLCAN_POLLING ))  || \
      defined( C_ENABLE_INDIVIDUAL_POLLING ) )        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanInterruptFullRx()
 ***********************************************************************************************************/
/*! \brief         Rx interrupt detection and handling 
 *  \details       Check the Rx buffer and Rx FIFO(s) for new data and call the appropriate CanMsgReceived function.
 *  \param[in]     Controller   CAN controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanFullInterruptRx(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif

#if !defined(C_ENABLE_ERROR_POLLING)
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanInterruptErrorHandling()
 ***********************************************************************************************************/
/*! \brief         Error detection and treatment
 *  \details       Check the MCAN error states and perform error handling
 *  \param[in]     Controller   CAN controller
 *  \return        kCanOk:      No error detected for the channel
 *  \return        kCanFailed:  Error detected for the channel
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanInterruptErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif

#if !defined(C_ENABLE_TX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  CanInterruptTx()
 ***********************************************************************************************************/
/*! \brief         Check the transmit status
 *  \details       Check the MCAN transmit status and perform status/transmission handling
 *  \param[in]     Controller   CAN controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanInterruptTx(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 4 END */
#endif

#if defined( C_ENABLE_CAN_ECC_INIT_SHM )
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  Can_EccInit()
 ***********************************************************************************************************/
/*! \brief         Initialize the message RAM
 *  \details       Initializes the used parts of the message RAM for all active channels.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
************************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) Can_EccInit(void); /* PRQA S 3447 */ /* MD_Can_ExternalScope */
/* CODE CATEGORY 4 END */
#endif  /* C_ENABLE_CAN_ECC_INIT_SHM */


/************************************************************************************************************
 *  CanHL_CleanUpSendState()
 ***********************************************************************************************************/
/*! \brief         Clean up send state
 *  \details       Reset active send state (semaphore blocking TX while send).
 *                 Called by Can_SetControllerMode(), Can_Mainfunction_Mode() (CanHL_ReInit() do same but without this call).
 *  \param[in]     Controller    CAN controller \n
 *                               (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_CleanUpSendState(CAN_CHANNEL_CANTYPE_ONLY);

# if (CAN_HW_LOOP_SUPPORT_API == STD_OFF)
/************************************************************************************************************
 *  ApplCanTimerLoop()
 ***********************************************************************************************************/
/*! \brief         Time out monitoring
 *  \details       Service function to check (against generated maximum loop value) whether a hardware loop shall be continued or broken.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \return        CAN_NOT_OK  when loop shall be broken (observation stops) \n
 *                             CAN_NOT_OK should only be used in case of a time out occurs due to a hardware issue. \n
 *                             After this an appropriate error handling is needed (see chapter Hardware Loop Check / Time out Monitoring).
 *  \return        CAN_OK      when loop shall be continued (observation continues)
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Please refer to chapter "Hardware Loop Check".
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop(CAN_CHANNEL_CANTYPE_FIRST uint8 source);
# endif

/************************************************************************************************************
 *  CanHL_ModeTransition()
 ***********************************************************************************************************/
/*! \brief         Request mode transition
 *  \details       Handle/Request transition and wait asynchronous-short time.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller         CAN controller (Controller must be in valid range). \n
 *                                    (only if not using "Optimize for one controller") \n
 *  \param[in]     transitionRequest  transition request used to switch mode (kCanModeInit, kCanModeSleep, kCanModeWakeupStopReinit, \n
 *                                    kCanModeStopReinit, kCanModeStopReinitFast, kCanModeStart, kCanModeStartReinit, kCanModeSilent, \n
 *                                    kCanModeResetBusOffStart, kCanModeResetBusOffEnd). \n
 *  \param[in]     busOffRecovery     handling of the busoff behaviour (kCanFinishBusOffRecovery, kCanContinueBusOffRecovery). \n
 *  \param[in]     doRamCheck         do a RAM check while reinit or not (kCanExecuteRamCheck, kCanSuppressRamCheck). \n
 *  \return        kCanFailed         transition rejected
 *  \return        kCanRequested      transition requested but is ongoing asynchronous
 *  \return        kCanOk             transition finished successful
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_ModeTransition(CAN_CHANNEL_CANTYPE_FIRST uint8 transitionRequest, uint8 busOffRecovery, uint8 doRamCheck);

/************************************************************************************************************
 *  CanHL_NotifyTransition()
 ***********************************************************************************************************/
/*! \brief         notify about sucessful mode transition
 *  \details       notify to upper layer.
 *                 Called by Can_SetControllerMode().
 *  \param[in]     Controller         CAN controller (Controller must be in valid range). \n
 *                                    (only if not using "Optimize for one controller") \n
 *  \param[in]     canState           CAN controller mode to be switched to (CAN_STATUS_STOP, CAN_STATUS_START, CAN_STATUS_SLEEP). \n
 *  \param[in]     canIfState         CAN controller mode to be switched to (CANIF_CS_STOPPED, CANIF_CS_STARTED, CANIF_CS_SLEEP). \n
 *  \param[in]     transitionState    transition request state (kCanFailed, kCanRequested, kCanOk). \n
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_NotifyTransition(CAN_CHANNEL_CANTYPE_FIRST uint8 canState, CanIf_ControllerModeType canIfState, uint8 transitionState);


/************************************************************************************************************
 *  CanHL_WritePrepare()
 ***********************************************************************************************************/
/*! \brief         TX preparation
 *  \details       Search for BasicCAN object handle to transmit (Multiplexed TX) and backup data for cancel TX object if necessary.
 *                 calculate txPara member activeSendObject, and mailboxElement
 *                 Called by Can_Write().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in,out] txPara           mailbox information
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepare(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);



/************************************************************************************************************
 *  CanHL_WriteStart()
 ***********************************************************************************************************/
/*! \brief         TX start
 *  \details       Write ID, DLC and Data to FullCAN or BasicCAN object and set transmit request
 *                 Called by Can_Write().
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in,out] txPara          mailbox information
 *  \return        CAN_NOT_OK      transmission failed.
 *  \return        CAN_OK          transmission successful.
 *  \return        CAN_BUSY        transition object busy - repeat it.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart(CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara);

/************************************************************************************************************
 *  CanHL_GetActiveSendObject()
 ***********************************************************************************************************/
/*! \brief         Convert Handle
 *  \details       Hardware to logical Handle conversion.
 *  \param[in]     mailboxHandle   Handle to mailbox object
 *  \param[in]     mailboxElement  mailbox element
 *  \return        logical handle for the given hardware mailbox
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetActiveSendObject(Can_HwHandleType mailboxHandle, Can_HwHandleType mailboxElement);


#if defined(C_ENABLE_CAN_RAM_CHECK)
/************************************************************************************************************
 *  CanHL_RamCheckMailboxNotification()
 ***********************************************************************************************************/
/*! \brief         RAM check
 *  \details       Notify upper layer in case of an HW issue and deactivate controller.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \param[in]     htrh             Hrh or Hth of the hardware object
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

/************************************************************************************************************
 *  CanHL_InitBegin()
 ***********************************************************************************************************/
/*! \brief         Start Initialization
 *  \details       LL implementation see token CanLL_InitBegin description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitTxFullCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize TX FullCAN
 *  \details       LL implementation see token CanLL_InitTxObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara          include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

/************************************************************************************************************
 *  CanHL_InitTxBasicCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize TX BasicCAN
 *  \details       LL implementation see token CanLL_InitTxObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);


#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/************************************************************************************************************
 *  CanHL_InitRxFullCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize RX FullCAN
 *  \details       LL implementation see token CanLL_InitFullCANObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/************************************************************************************************************
 *  CanHL_InitRxBasicCAN()
 ***********************************************************************************************************/
/*! \brief         Initialize RX BasicCAN
 *  \details       LL implementation see token CanLL_InitBasicCANObj description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);
#endif

/************************************************************************************************************
 *  CanHL_InitEnd_InitMode()
 ***********************************************************************************************************/
/*! \brief         End Initialization
 *  \details       LL implementation see token CanLL_InitEnd_InitMode description.
 *                 Called by CanHL_ReInit().
 *  \param[in]     Controller       CAN controller. \n
 *                                  (only if not using "Optimize for one controller")
 *  \param[in]     initPara         include controller and all LL specific settings.
 *  \return        errorId
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara);

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/************************************************************************************************************
 *  CanHL_RxBasicCanPolling()
 ***********************************************************************************************************/
/*! \brief         RX BasicCAN polling
 *  \details       RX BasicCAN polling handling.
 *                 Called by Can_MainFunctionRead().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicCanPolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/************************************************************************************************************
 *  CanHL_RxFullCanPolling()
 ***********************************************************************************************************/
/*! \brief         RX FullCAN polling
 *  \details       RX FullCAN polling handling.
 *                 Called by Can_MainFunctionRead().
 *  \param[in]     Controller    CAN controller.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullCanPolling(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/************************************************************************************************************
 *  CanHL_RxMsgReceivedNotification()
 ***********************************************************************************************************/
/*! \brief         RX notification
 *  \details       RX queue and notification handling for BasicCAN and FullCAN reception.
 *                 Called by CanHL_BasicCanMsgReceived(),CanHL_FullCanMsgReceived().
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxStructPtr     include general rx info and all LL specific data.
 *  \return        errorId         error identifier reporting to DET
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANTYPE_FIRST CanRxInfoStructPtr rxStructPtr);
#endif

#if defined(C_ENABLE_RX_QUEUE)
/************************************************************************************************************
 *  CanHL_RxQueueExecution()
 ***********************************************************************************************************/
/*! \brief         RX queue
 *  \details       RX queue execution and notification.
 *                 Called by Can_MainFunction_Read().
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxQueueExecution(void);
#endif

#if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */
/************************************************************************************************************
 *  CanHL_TxConfirmationPolling()
 ***********************************************************************************************************/
/*! \brief         TX Confirmation intermediate call
 *  \details       intermediate call to do interrupt locks between polling call from LL and HL handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     mailboxHandle   mailbox handle
 *  \param[in]     mailboxElement  index of the mailboxElement (muxTx, FIFO)
 *  \param[in]     hwObjHandle     hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxConfirmationPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_TxConfirmation()
 ***********************************************************************************************************/
/*! \brief         TX Confirmation handling
 *  \details       Called for a transmit or cancel event. Finish transmission by free send mailbox and call confirmation. \n
 *                 Called for FullCAN and BasicCAN handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     mailboxHandle   mailbox handle
 *  \param[in]     mailboxElement  index of the mailboxElement (muxTx, FIFO)
 *  \param[in]     hwObjHandle     transmitted hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle);


#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/************************************************************************************************************
 *  CanHL_SetCanPduInfo()
 ***********************************************************************************************************/
/*! \brief         copy the confirmation parameter info to the PduInfo struct
 *  \details       Called while confirmation handling to set data struct need for confirmation API2. \n
 *  \param[in,out] PduInfo             Pointer to local PduInfo struct
 *  \param[in]     txConfPara          Pointer to local variables of confirmation
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_SetCanPduInfo(Can_PduInfoPtrType_var PduInfo, CanTxConfirmationParaStructPtr txConfPara);
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/************************************************************************************************************
 *  CanHL_BasicCanMsgReceivedPolling()
 ***********************************************************************************************************/
/*! \brief         RX Indication intermediate call
 *  \details       intermediate call to do interrupt locks between polling call from LL and HL handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_BasicCanMsgReceivedPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
# endif

/************************************************************************************************************
 *  CanHL_BasicCanMsgReceived()
 ***********************************************************************************************************/
/*! \brief         Handle reception
 *  \details       Receive BasicCAN data and call indication function.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_BasicCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/************************************************************************************************************
 *  CanHL_FullCanMsgReceivedPolling()
 ***********************************************************************************************************/
/*! \brief         RX Indication intermediate call
 *  \details       intermediate call to do interrupt locks between polling call from LL and HL handling.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_FullCanMsgReceivedPolling(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_FullCanMsgReceived()
 ***********************************************************************************************************/
/*! \brief         Handle reception
 *  \details       Receive FullCAN data and call indication function.
 *  \param[in]     Controller      CAN controller. \n
 *                                 (only if not using "Optimize for one controller")
 *  \param[in]     rxMailboxHandle mailbox handle
 *  \param[in]     hwObjHandle     received hardware handle
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_FullCanMsgReceived(CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle);
#endif

/************************************************************************************************************
 *  CanHL_ErrorHandling()
 ***********************************************************************************************************/
/*! \brief         BUSOFF handling
 *  \details       Handler for bus off situation.
 *  \param[in]     Controller    CAN controller. \n
 *                               (only if not using "Optimize for one controller")
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY);



/************************************************************************************************************
 *  CanHL_ReInit()
 ***********************************************************************************************************/
/*! \brief         Initialization of controller specific CAN hardware.
 *  \details       Initialization of the CAN controller hardware registers and CAN driver variables. \n
 *                 after that the controller is fully initialized and can be swtiched to "STOP Mode".
 *  \param[in]     Controller            CAN controller. \n
 *                                       (only if not using "Optimize for one controller")
 *  \param[in]     doRamCheck            RAM check exectuion (kCanExecuteRamCheck, kCanSuppressRamCheck).
 *  \return        error                 return kCanFailed in case of issue or kCanOk if initialization pass.
 *  \pre           controller is ready to be configured (INIT mode).
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         no mode change must be done inside. No CAN bus depended hardware loops allowed.
***********************************************************************************************************/
V_DEF_FUNC(CAN_STATIC, uint8, STATIC_CODE) CanHL_ReInit(CAN_HW_CHANNEL_CANTYPE_FIRST uint8 doRamCheck);

#define CAN_STOP_SEC_STATIC_CODE  /*----------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* CAN_LOCAL_H */

/* End of channel */



/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

