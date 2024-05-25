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

/* \trace SPEC-1570 */
/***************************************************************************/
/* Include files                                                           */
/***************************************************************************/
/* ECO_IGNORE_BLOCK_BEGIN */
#define C_DRV_INTERNAL /* compatibility */
#define CAN_SOURCE     /* testability */
#define __CAN_SRC__       /* compatibility RTM not aware of multi driver instance */ /* PRQA S 0602,0603 */ /* MD_Can_ModuleDefine */
#if !defined(__CAN_SRC__) /* driver use ORGANI without infix */ /* COV_CAN_INTERNAL */
# define __CAN_SRC__      /* for all MSR module (used by RTM) */ /* PRQA S 0602,0603 */ /* MD_Can_ModuleDefine */
#endif

/* \trace SPEC-1408, SPEC-1590, SPEC-1588 */
/* PRQA S 0777 EOF */ /* MD_Can_0777_LL */
/* PRQA S 0779 EOF */ /* MD_MSR_5.1_779 */
/* PRQA S 0841 EOF */ /* MD_Can_0841    */
/* \trace SPEC-1392 */
#include "CanIf_Cbk.h"   /* for callback declaration */
/* \trace SPEC-1707 */
#include "CanIf.h"       /* for version check */
#include "Can_Local.h"    /* have to be last include due to channel define will lead to problems */


#if (CAN_DEV_ERROR_REPORT == STD_ON)
/* \trace SPEC-1596 */
# include "Det.h"
#endif

#if !defined(CAN_AMD_RUNTIME_MEASUREMENT) /* COV_CAN_COMPATIBILITY */
# define CAN_AMD_RUNTIME_MEASUREMENT STD_OFF
#endif
#if (CAN_AMD_RUNTIME_MEASUREMENT == STD_ON) /* COV_CAN_AMD_RUNTIME_MEASUREMENT */
# include "AmdRtm.h"
#endif

#if !defined(CAN_RUNTIME_MEASUREMENT_SUPPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_RUNTIME_MEASUREMENT_SUPPORT STD_OFF
#endif
#if (CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
/* AR4-328 */
# define C_ENABLE_RUNTIME_MEASUREMENT_SUPPORT
# include "Rtm.h"
#endif

#include "vstdlib.h"

/* ECO_IGNORE_BLOCK_END */

/***************************************************************************/
/* Version Check                                                           */
/***************************************************************************/
/* \trace SPEC-20329 */
/* not the SW version but all file versions that represent the SW version are checked */
#if (CAN_COREVERSION           != 0x0800u) /* \trace SPEC-1699 */
# error "Source and Header file are inconsistent!"
#endif
#if (CAN_RELEASE_COREVERSION   != 0x01u)
# error "Source and Header file are inconsistent!"
#endif
#if defined(CAN_GEN_BASE_CFG5_VERSION) /* COV_CAN_COMPATIBILITY */
# if (CAN_GEN_BASE_CFG5_VERSION         != 0x0103u)
#  error "Source and Generated Header file are inconsistent!"
# endif
#else
# error "No CAN_GEN_BASE_CFG5_VERSION is defined"
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

/***************************************************************************/
/* Defines                                                                 */
/***************************************************************************/
#if defined(CAN_USE_NO_VECTOR_IF) /* for testability */
# define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#else
# if defined(CANIF_VENDOR_ID) /* COV_CAN_COMPATIBILITY */
#  if (CANIF_VENDOR_ID == 0x001E) /* COV_CAN_COMPATIBILITY */
#   define CAN_USE_VECTOR_IF
#   if defined(IF_ASRIFCAN_VERSION) /* COV_CAN_COMPATIBILITY */
#    if (IF_ASRIFCAN_VERSION < 0x0410) /* COV_CAN_COMPATIBILITY */
#     define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#    endif
#   endif
#  else
#   define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
#  endif
# else
#  define CAN_USE_CRITICALSECTION_OVER_CONFIRMATION
# endif
#endif
/* Compatibility to CBD */
/* instead of direct canCanInterruptCounter[] use Can_GetCanInterruptCounter(Index) abstraction for ComStackLib */

#if (CAN_RUNTIME_MEASUREMENT_SUPPORT == STD_ON)
# define CanHookBegin_Can_Init()                              Rtm_Start(RtmConf_RtmMeasurementPoint_Can_Init)
# define CanHookEnd_Can_Init()                                Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_Init)
# define CanHookBegin_Can_SetControllerMode()                 Rtm_Start(RtmConf_RtmMeasurementPoint_Can_SetControllerMode)
# define CanHookEnd_Can_SetControllerMode()                   Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_SetControllerMode)
# define CanHookBegin_Can_Write()                             Rtm_Start(RtmConf_RtmMeasurementPoint_Can_Write)
# define CanHookEnd_Can_Write()                               Rtm_Stop(RtmConf_RtmMeasurementPoint_Can_Write)

#else /* BRS runtime measurement */
# define CanHookBegin_Can_Init()
# define CanHookEnd_Can_Init()
# define CanHookBegin_Can_SetControllerMode() \

# define CanHookEnd_Can_SetControllerMode() \

# define CanHookBegin_Can_Write() \

# define CanHookEnd_Can_Write() \

#endif

# define CanHookBegin_CanHL_ReInit() \

# define CanHookEnd_CanHL_ReInit() \

#define CanHookBegin_CanHL_TxConfirmation() \

#define CanHookEnd_CanHL_TxConfirmation() \

#define CanHookBegin_CanHL_BasicCanMsgReceived() \

#define CanHookEnd_CanHL_BasicCanMsgReceived() \

#define CanHookBegin_CanHL_FullCanMsgReceived() \

#define CanHookEnd_CanHL_FullCanMsgReceived() \

#define CanHookBegin_Can_MainFunction_Write() \

#define CanHookEnd_Can_MainFunction_Write() \

#define CanHookBegin_Can_MainFunction_Read() \

#define CanHookEnd_Can_MainFunction_Read() \


/*!
 *  Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
*/





/* Start value of the Message RAM Watchdog Counter. 
   With the reset value of '0' the counter is disabled. */
#define kCan_RWD                        0x00000000UL

/* Bitmasks of MCAN CCCR */
#define kCanCCCR_INIT                   0x00000001UL /*! '1'= Initialization is started */
#define kCanCCCR_CCE                    0x00000002UL /*! Configuration Change Enable: '1'= CPU has write access to the protected configuration registers (while CCCR.INIT = '1') */
#define kCanCCCR_ASM                    0x00000004UL /*! Restricted Operation Mode: '1'= Restricted Operation Mode active */
#define kCanCCCR_CSA                    0x00000008UL /*! Clock Stop Acknowledge: '1'= M_CAN may be set in power down by stopping host and core clock */
#define kCanCCCR_CSR                    0x00000010UL /*! Clock Stop Request:     '1'= Clock stop requested (after all pending transfers are completed and CAN reached Bus_Idle 
                                                                                    first INIT and then CSA will be set */
#define kCanCCCR_MON                    0x00000020UL /*! Bus Monitoring Mode:    '1'= Bus Monitoring Mode enabled */
#define kCanCCCR_DAR                    0x00000040UL /*! Disable Automatic Retransmission: '1'= Automatic retransmission disabled */
#define kCanCCCR_TEST                   0x00000080UL /*! Test Enable Mode:       '1'= Test Mode (write access to register TEST enabled) */

#define kCanFBTP_TDC_Disable            0x00000000UL          /*! Transceiver Delay Compensation disabled  */
#define kCanTDCR_TDC_Disable            kCanFBTP_TDC_Disable /*! TDCO moved to new register TDCR (since Rev. 3.1.0) */
#define kCanTDCR_FBTP_TDCO_300          0x1F000000UL /*! Transceiver Delay Compensation Offset from FBTP (Rev. 3.0) */
#define kCanTDCR_FBTP_TDCO_Mask_310     0x00FFFFFFUL  /*! Transceiver Delay Compensation Offset Mask (since Rev. 3.0) */
#define kCanFBTP_to_TDCR_bit_offset_r   16UL         /*! Transceiver Delay Compensation Offset bit offset from register FBTP to TDCR (Rev. 3.0 to Rev. 3.1.0) */

#if !defined(kCanGFC_ANFS) /* COV_CAN_HW_SPECIFIC */
/* Non-matching Frames Standard */
# define kCanGFC_ANFS                   0x00000030UL  /*! 0x00000000UL Accept in Rx FIFO 0
                                                        0x00000010UL Accept in Rx FIFO 1
                                                        0x00000030UL Reject */
#endif

#if !defined(kCanGFC_ANFE) /* COV_CAN_HW_SPECIFIC */
/* Non-matching Frames Extended */
# define kCanGFC_ANFE                   0x0000000CUL  /*! 0x00000000UL Accept in Rx FIFO 0
                                                        0x00000004UL Accept in Rx FIFO 1
                                                        0x0000000CUL Reject */
#endif

#if !defined(kCanGFC_RRFS) /* COV_CAN_HW_SPECIFIC */
/* Remote Frames Standard */
# define kCanGFC_RRFS                   0x00000002UL  /*! 0x00000000 Filter Remote Frames Standard       
                                                        0x00000002 Reject Remote Frames Standard */
#endif

#if !defined(kCanGFC_RRFE) /* COV_CAN_HW_SPECIFIC */
/* Remote Frames Extended */
# define kCanGFC_RRFE                   0x00000001UL  /*! 0x00000000 Filter Remote Frames Extended       
                                                        0x00000001 Reject Remote Frames Extended */
#endif

# define MCMCAN_GLOBAL_ADDR_0      0xF0208000UL       /*! Address of Mc_Mcan_0 */
# define MCMCAN_GLOBAL_ADDR_1      0xF0218000UL       /*! Address of Mc_Mcan_1 */
# define MCMCAN_GLOBAL_ADDR_2      0xF0228000UL       /*! Address of Mc_Mcan_2 */

# define kCanEnableMemAccess            0xFFFFFFFFUL  /*! 0xFFFFFFFF Enable Memory Access to all Register */
# define kCanSetMCR_prog_sequence_0     0xC0000000UL  /*! To be able to change the clock settings the following programming sequence needs to be met: */
# define kCanSetMCR_prog_sequence_1     0xC00000FFUL  /*! CANn_MCR|=0xC0000000;  change clock settings within MCR; CANn_MCR&=~0xC0000000; */
# define kCanSetMCR_prog_sequence_2     0x000000FFUL  /*! after this clock settings for CAN nodes becomes active. */
# define kCanDisable_Service_Request    0xFFFFFBFFUL  /*! disable the CAN Interrupt in the SRN */
# define kCanSRCR_Mask                  0x00003CFFu   /*! Mask for Service Request Node register */




/*  High Priority Message Status Register (HPMS):
Bits 16     FLST Filter List
Indicates the filter list of the matching filter element.
0 Standard Filter List
1 Extended Filter List

Bits 17:23  FIDX Filter Index
Index of matching filter element. Range is 0 to SIDFC[LSS] - 1 resp. XIDFC[LSE] - 1.

Bits 24:25  MSI Message Storage Indicator
00 No FIFO selected
01 FIFO overrun
10 Message stored in FIFO 0
11 Message stored in FIFO 1

Bits 26:31  BIDX Buffer Index
Index of Rx FIFO element to which the message was stored. Only valid when MSI[1] = '1'.
*/
#define kCanHPMS_FLST_STD               0x00000000UL
#define kCanHPMS_FLST_EXT               0x00008000UL
#define kCanHPMS_FIDX                   0x00007F00UL
#define kCanHPMS_MSI_NOFIFO             0x00000000UL
#define kCanHPMS_MSI_FIFO_OWFL          0x00000040UL
#define kCanHPMS_MSI_FIFO_0             0x00000080UL
#define kCanHPMS_MSI_FIFO_1             0x000000C0UL
#define kCanHPMS_BIDX                   0x0000003FUL

/*Standard Message ID Filter element:
  Bits 31:30 SFT[1:0] Standard Filter Type
  00 Range filter from SF1ID to SF2ID (with SF2ID >= SF1ID)
  01 Dual ID filter for SF1ID or SF2ID
  10 Classic filter: SF1ID = filter, SF2ID = mask
  11 Reserved

  Bit 29:27 SFEC[2:0] Standard Filter Element Configuration
  000 Disable filter element
  001 Store in Rx FIFO 0 if filter matches
  010 Store in Rx FIFO 1 if filter matches
  011 Reject ID if filter matches
  100 Set priority if filter matches
  101 Set priority and store in FIFO 0 if filter matches
  110 Set priority and store in FIFO 1 if filter matches
  111 Store into Rx Buffer or as debug message, configuration of SFT[1:0] ignored
  All enabled filter elements are used for acceptance filtering of standard frames. 
  Acceptance filtering stops at the first matching enabled filter element or when the end 
  of the filter list is reached. 
  If SFEC = '100', '101', or '110' a match generates an interrupt (if enabled).
  In this case register HPMS is updated with the status of the priority match.

  Bits 26:16 SFID1[10:0] Standard Filter ID 1
  First ID of standard ID filter element.
  When filtering for debug messages this field defines the ID of a standard debug
  message to be stored to the re-assigned Rx FIFO 1 element 61...63. 
  The received identifiers must match exactly, no masking mechanism is used.

  Bits 10:0 SFID2[10:0] Standard Filter ID 2
  Second ID of standard ID filter element.
  When filtering for debug messages SFID2[5:0] defines the Rx FIFO 1 element number 
  for storage of a matching debug message.
  SFID2[10:9] decides whether the received message is treated as message A, B, or C of 
  the debug message sequence:
  00= Reserved
  01= Message A
  10= Message B
  11= Message C  */
#define kCanSFE_SFTRange               0x00000000UL
#define kCanSFE_SFTDualId              0x40000000UL
#define kCanSFE_SFTClassic             0x80000000UL
#define kCanSFE_SFTRes                 0xC0000000UL

#define kCanSFE_SFEC_Disable           0x00000000UL
#define kCanSFE_SFEC_F0                0x08000000UL
#define kCanSFE_SFEC_F1                0x10000000UL
#define kCanSFE_SFEC_Reject            0x18000000UL
#define kCanSFE_SFEC_SetPrio           0x20000000UL
#define kCanSFE_SFEC_SetPrioStoreF0    0x28000000UL
#define kCanSFE_SFEC_SetPrioStoreF1    0x30000000UL
#define kCanSFE_SFEC                   0x38000000UL

#define kCanSFE_SFID1                  0x07FF0000UL  /*! bits 16:26 */
#define kCanSFE_Res                    0x0000F800UL  /*! bits 11:15 */
#define kCanSFE_SFID2                  0x000007FFUL  /*! bits  0:10 */
#define kCanSFE_SFID2_RBSA             0x0000003FUL  /*! bits  0:5 */

/*Extended message ID filter element:
  F0 Bits 31:29 EFEC[2:0] Extended Filter Element Configuration 
  000 Disable filter element
  001 Store in Rx FIFO 0 if filter matches
  010 Store in Rx FIFO 1 if filter matches
  011 Reject ID if filter matches
  100 Set priority if filter matches
  101 Set priority and store in FIFO 0 if filter matches
  110 Set priority and store in FIFO 1 if filter matches
  111 Store as debug message, configuration of EFT[1:0] ignored

  F0 Bits 28:0 EFID1[28:0] Extended Filter ID 1
  When filtering for debug messages this field defines the ID of a extended debug 
  message to be stored to the re-assigned Rx FIFO 1 element 61...63. The received 
  identifiers must match exactly, no masking mechanism is used.

  F0 Bits 28:0  EFID1[28:0]

  F1 Bits 31:30 EFT[1:0] Extended Filter Type
  00 Range filter from EF1ID to EF2ID (EF2ID >= EF1ID)
  01 Dual ID filter for EF1ID or EF2ID
  10 Classic filter: EF1ID = filter, EF2ID = mask
  11 Range filter from EF1ID to EF2ID (EF2ID >= EF1ID), XIDAM mask not applied

  F1 Bits 28:0 EFID2[28:0]
  Extended Filter ID 2
  Second ID of extended ID filter element.
  When filtering for debug messages EFID2[5:0] defines the Rx FIFO 1 element number 
  for storage of a matching debug message.
  EFID2[10:9] decides whether the received message is treated as message A, B, or C of 
  the debug message sequence.
  00= Reserved
  01= Message A
  10= Message B
  11= Message C */
#define kCanEFE_EFTRangewMask          kCanSFE_SFTRange
#define kCanEFE_EFTDualId              kCanSFE_SFTDualId
#define kCanEFE_EFTClassic             kCanSFE_SFTClassic
#define kCanEFE_EFTRangewoMask         0xC0000000UL

#define kCanEFE_EFEC_Disable           0x00000000UL
#define kCanEFE_EFEC_F0                0x20000000UL
#define kCanEFE_EFEC_F1                0x40000000UL
#define kCanEFE_EFEC_Reject            0x60000000UL
#define kCanEFE_EFEC_SetPrio           0x80000000UL
#define kCanEFE_EFEC_SetPrioStoreF0    0xA0000000UL
#define kCanEFE_EFEC_SetPrioStoreF1    0xC0000000UL
#define kCanEFE_EFEC                   0xE0000000UL

#define kCanEFE_EFID1                  0x1FFFFFFFUL  /*! bits  0:28 */
#define kCanEFE_Res                    0x02000000UL  /*! bits    29 */
#define kCanEFE_EFID2                  0x1FFFFFFFUL  /*! bits  0:28 */
#define kCanEFE_EFID2_RBSA             0x0000003FUL  /*! bits  0:5 */

#define kCanSIDFCMax                   128  /* max number of std filters per channel */
#define kCanXIDFCMax                    64  /* max number of ext filters per channel */


/* Rx FIFO 0/1 Configuration (RXFnC):
Bits 0          Blocking or overwrite mode 
Bits 1:7        F0WM Rx FIFO 0 Watermark
                0     Watermark interrupt disabled
                1-64  Level for Rx FIFO 0 watermark interrupt (IR[RF0W])
                >64   Watermark interrupt disabled
Bits 8:9        Reserved
Bits 10:15      F0S Rx FIFO 0 Size
                0 No Rx FIFO 0
                1-64 Number of Rx FIFO 0 elements
                >64 Values greater than 64 are interpreted as 64
                The Rx FIFO 0 elements are indexed from 0 to F0S-1
Bits 16:29      FOSA Rx FIFO 0 Start Address
                Start address of Rx FIFO 0 in Message RAM (32-bit word address, Figure 547).
Bits 30:31      Reserved */
#define kCanRXF0C_F0WM         0x7F000000UL
#define kCanRXF0C_F0S          0x003F0000UL
#define kCanRXF1C_F0WM         kCanRXF0C_F0WM
#define kCanRXF1C_F0S          0x007F0000UL
#define kCanRXFnOM_BLOCK       0x00000000UL        /*! Blocking Mode  */
#define kCanRXFnOM_OVERWRITE   0x80000000UL        /*! Overwrite Mode */

/*Tx Buffer Configuration Register (TXBC):
Bit 1       TFQM Tx FIFO/Queue Mode
            0 Tx FIFO operation
            1 Tx Queue operation
Bits 2:7    TFQS Tx FIFO/Queue Size
            0   No Tx FIFO/Queue
            1-32 Number of Tx Buffers used for Tx FIFO/Queue
            >32 Values greater than 32 are interpreted as 32
Bits 10:15  NDTB Number of Dedicated Transmit Buffers
            0   No Dedicated Tx Buffers
            1-32 Number of Dedicated Tx Buffers
            >32 Values greater than 32 are interpreted as 32
Bits 16:29  TBSA Tx Buffers Start Address in Message RAM */
#define kCanTXBC_TFQM_MODE            0x40000000UL /*! 0=FIFO/1=QUEUE Mode */
#define kCanTXBC_TFQS                 0x3F000000UL /*! (1..32) FIFO/QUEUE size */
#define kCanTXBC_NDTB                 0x20u        /*! see CanTXBC: (1..32) Number of dedicated Tx buffers */
#define kCanTXBC_TBSA                 0x0000FFFCUL /*! Tx Buffer Start Address */

#define kCanTXBE_EFC                  0x00800000UL /*! Tx Buffer Event Fifo Control */

/* Tx Buffer Request Pending Register (TXBRP) */
#define kCanTXBRP_RP                  0x00000001UL   /* Tx request pending */
/* Tx Buffer confirmation and cancellation interrupts */
#define kCanTXBTIE_ENABLE_ALL         0xFFFFFFFFUL
#define kCanTXBCIE_ENABLE_ALL         0xFFFFFFFFUL
/* Frame detection */
#define kCanFrm_XTD                   0x40000000UL
#define kCanFrm_RTR                   0x20000000UL

/*Tx Event FIFO Configuration (TXEFC):
Bits [0:1]      Reserved.
Bits [2:7]      EFWM Event FIFO Watermark.
                0 Watermark interrupt disabled
                1..32 Level for Tx Event FIFO watermark interrupt (IR[TEFW])
                >32 Watermark interrupt disabled
Bits [8:9]      Reserved.
Bits [10:15]    EFS Event FIFO Size.
                0 Tx Event FIFO disabled
                1..32 Number of Tx Event FIFO elements
                >32 Values greater than 32 are interpreted as 32
                The Tx Event FIFO elements are indexed from 0 to EFS - 1
Bits [16:29]    EFSA Event FIFO Start Address.
                Start address of Tx Event FIFO in Message RAM (32-bit word address,Figure 547.
Bits [30:31]    Reserved. */
#define kCanTXEFC_EFWM        0x3F000000UL  /*! '0' or '>32' means INT disabled */
#define kCanTXEFC_EFS         0x003F0000UL  /*! '0' or '>32' means Event Fifo disabled */
#define kCanTXEFC_EFSA        0x0000FFFCUL  /*! Event Fifo Start Address */

/* Bitmasks of MCAN ECR */
#define kCanECR_CEL                     0x00FF0000UL  /*! CAN error logging     */
#define kCanECR_RP                      0x00008000UL  /*! receive error passive */
#define kCanECR_REC                     0x00007F00UL  /*! Rx error counter      */
#define kCanECR_TEC                     0x000000FFUL  /*! Tx error counter      */
/* Protocol Status Register (PSR): */
#if ( CAN_MCAN_REVISION >= 0x0200UL )    /* COV_CAN_HW_SPECIFIC */
# define kCanPSR_REDL                    0x00002000UL /*! Received CAN FD Message with EDL flag */
# define kCanPSR_RBRS                    0x00001000UL /*! BRS flag of last received CAN FD Message */
# define kCanPSR_RBSI                    0x00000800UL /*! ESI CAN FD Message with ESI flag */
# define kCanPSR_FLEC                    0x00000700UL /*! Fast Last Error Code */
#endif
#define kCanPSR_PXE                     0x00004000UL /*! Protocol Exception Event */
#define kCanPSR_BO                      0x00000080UL /*! Bus_Off status */
#define kCanPSR_EW                      0x00000040UL /*! Warning status */
#define kCanPSR_EP                      0x00000020UL /*! Error Passive  */
#define kCanPSR_ACT                     0x00000018UL /*! Activity */
#define kCanPSR_ACT_SYNC                0x00000000UL /*! Activity: synchronizing */
#define kCanPSR_ACT_IDLE                0x00000008UL /*! Activity: idle          */
#define kCanPSR_ACT_RX                  0x00000010UL /*! Activity: reception     */
#define kCanPSR_ACT_TX                  0x00000018UL /*! Activity: transmission  */
#define kCanPSR_LEC                     0x00000007UL /*! last error code */


/* Protocol Status Register (PSR):
Bit 24      BO  Bus_Off Status
            1  The M_CAN is in Bus_Off state
Bit 25      EW  Warning Status
            0  Both error counters are below the Error_Warning limit of 96
            1  At least one of error counter has reached the Error_Warning limit of 96
Bit 26      EP  Error Passive
            0  Error_Active state (takes part in bus communication and sends an active error flag when an error has been detected)
            1  M_CAN is in the Error_Passive state
Bit 27:28   ACT Activity - Monitors the module's CAN communication state.
            00  Synchronizing - node is synchronizing on CAN communication
            01  Idle - node is neither receiver nor transmitter
            10  Receiver - node is operating as receiver
            11  Transmitter - node is operating as transmitter 
Bits 29:31  LEC Last Error Code (will be cleared to '0' when a message has been transferred (Rx or Tx) without error)
            0    No Error: No error occurred since LEC has been reset by successful reception or transmission.
            1    Stuff Error: More than 5 equal bits in a sequence have occurred in a part of a received message where this is not allowed.
            2    Form Error: A fixed format part of a received frame has the wrong format.
            3    AckError: The message transmitted by the M_CAN was not acknowledged by another node.
            4    Bit1Error: During transmission (except of the arbitration field): device wants to send a recessive level but the monitored bus value was dominant
            5    Bit0Error: During transmission (message, ACK bit, active error flag, overload flag) device wants to send a dominant level but the monitored bus value was recessive. 
                 During Bus_Off recovery this status is set each time a sequence of 11 recessive bits is monitored (monitor proceeding of Bus_Off recovery sequence).
            6    CRCError: CRC of incoming message != CRC calculated from received data.
            7    NoChange: no CAN bus event was detected since the last read access (any read access to the PSR re-initializes the LEC to '7') */

#define kCanBusoff                  0x01u       /*! CAN driver is in recovery phase after bus off */ 
#define kCanBusoffInit              0x02u       /*! Driver finished recovery and needs to be initialized */
#define kCanNormal                  0x03u       /*! Driver completed recovery and is in normal mode */ 

#define kCan_TSCC_TCP               0x00000000UL /*! Timestamp Counter Prescaler (hardware uses one more than the value programmed here) */
# define kCan_TSCC_TSS              0x00000000UL /*! 00 Timestamp counter value always zero */

#define kCan_TOCC_TOP               0x000000C8UL /*! Start value of the Timeout Counter (down-counter, in multiples of CAN bit times) */
#define kCan_TOCC_TOS               0x00000000UL /*! Timeout Select (00=Continuous operation, 01/10/11=controlled by Tx Event FIFO/by Rx FIFO 0/by Rx FIFO 1 */
#define kCan_TOCC_ETOC              0x00000001UL /*! 0=Timeout Counter disabled, 1=Timeout Counter enabled */

/*(IR)  The flags are set when one of the listed conditions is detected (edge-sensitive). 
        The flags remain set until the Host clears them. 
        A flag is cleared by writing a '1' to the corresponding bit position. Writing a '0' has no effect. 
        A hard reset will clear the register. 
  (IE)  The settings determine which status changes in the IR will be signalled on an interrupt line.
  (ILE) Each of the two interrupt lines to the CPU can be enabled/disabled separately by programming bits EINT0/EINT1. */
#if !defined(kCanIR_CLEAR_ALL)          /* COV_CAN_HW_SPECIFIC */
# if   ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
#  define kCanIR_CLEAR_ALL              0x3FFFFFFFUL  /*! clear all pending INT flags        */
# elif ( CAN_MCAN_REVISION >= 0x0200UL ) /* COV_CAN_HW_SPECIFIC */
#  define kCanIR_CLEAR_ALL              0xFFFFFFFFUL  /*! clear all pending INT flags        */
# else /* ( CAN_MCAN_REVISION == 0x0100UL ) */
#  define kCanIR_CLEAR_ALL              0xFFF7FFFFUL  /*! clear all pending INT flags        */
# endif
#endif

#if !defined(kCanIE_DISABLE_ALL)        /* COV_CAN_HW_SPECIFIC */
# define kCanIE_DISABLE_ALL             0x00000000UL
#endif
#define kCan_ALL_ONE                    0xFFFFFFFFUL
#define kCanIE_ENABLE_ALL               kCan_ALL_ONE /* enable all INTs */

/*Interrupts (IR):
Bit 0   STE   Stuff Error
Bit 1   FOE   Format Error
Bit 2   ACKE  Acknowledge Error
Bit 3   BE    Bit Error
Bit 4   CRCE  CRC Error
Bit 5   WDI   Message RAM Watchdog Interrupt 
Bit 6   BO    Bus_Off Status
Bit 7   EW    Warning Status 
Bit 8   EP    Error Passive Status
Bit 9   ELO   Error Logging Overflow
Bit 10  BEU   Message RAM Bit Error Uncorrected
Bit 11  BEC   Bit Error Corrected
Bit 12        MPC5746M = Reserved, MPC5777M = DRX (Message stored to Dedicated Rx Buffer)
Bit 13  TOO   Timeout Occurred
Bit 14  UMD   Unprocessed Message Discarded
              When a new message is received while the acceptance filtering process for the previously received message has not yet completed, this message is discarded.
Bit 15  TSW   Timestamp Wraparound
Bit 16  TEFL  Tx Event FIFO Event Lost
Bit 17  TEFF  Tx Event FIFO Full
Bit 18  TEFW  Tx Event FIFO Watermark Reached
Bit 19  TEFN  Tx Event FIFO New Entry
Bit 20  TFE   Tx FIFO Empty
Bit 21  TCF   Transmission Cancellation Finished
Bit 22  TC    Transmission Completed
Bit 23  HPM   High Priority Message
Bit 24  RF1L  Rx FIFO 1 Message Lost
Bit 25  RF1F  Rx FIFO 1 full
Bit 26  RF1W  Rx FIFO 1 Watermark Reached
Bit 27  RF1N  Rx FIFO 1 New Message
Bit 28  RF0L  Rx FIFO 0 Message Lost
Bit 29  RF0F  Rx FIFO 0 Full
Bit 30  RF0W  Rx FIFO 0 Watermark Reached
Bit 31  RF0N  Rx FIFO 0 New Message  */

#define kCanIR_STE                      0x80000000UL  /*! Stuff Error */
#define kCanIR_FOE                      0x40000000UL  /*! Format Error */
#define kCanIR_ACKE                     0x20000000UL /*! A transmitted message was not acknowledged by another node */
#define kCanIR_CRCE                     0x08000000UL /*! Received CRC did not match the calculated CRC */
#define kCanIR_WDI                      0x04000000UL /*! Watchdog Interrupt */
#define kCanIR_BO                       0x02000000UL /*! Bus_Off status changed */
#define kCanIR_EW                       0x01000000UL /*! Error_Warning status changed */
#define kCanIR_EP                       0x00800000UL /*! Error_Passive status changed */
#define kCanIR_BEU                      0x00200000UL /*! Bit Error Uncorrected */
#define kCanIR_BEC                      0x00100000UL /*! Bit Error Corrected */
#if ( CAN_MCAN_REVISION >= 0x0200UL )    /* COV_CAN_HW_SPECIFIC */
# define kCanIR_DRX                     0x00080000UL /*! Message stored to Dedicated Rx Buffer (check NDAT1/2) */
#endif
#if ( CAN_MCAN_REVISION >= 0x0300UL )    /* COV_CAN_HW_SPECIFIC */
# define kCanIR_MRAF                     0x00020000UL /*! Message RAM Access Failure */
#else
# define kCanIR_UMD                      0x00020000UL /*! Unprocessed message discarded */
#endif
#define kCanIR_PEA                      0x08000000UL /*! Protocol Error in Arbitration Phase */
#define kCanIR_TOO                      0x00040000UL /*! Timeout Occurred */
#define kCanIR_TCF                      0x00000400UL /*! Transmission cancellation finished */
#define kCanIR_TC                       0x00000200UL /*! Transmission completed */
#define kCanIR_HPM                      0x00000100UL /*! High Priority Message */
#define kCanIR_RF1L                     0x00000080UL /*! Rx FIFO 1 message lost (also set after write attempt to Rx FIFO 1 of size zero) */
#define kCanIR_RF1F                     0x00000040UL /*! Rx FIFO 1 full */
#define kCanIR_RF1W                     0x00000020UL /*! Rx FIFO 1 fill level reached watermark */
#define kCanIR_RF1N                     0x00000010UL /*! New message written to Rx FIFO 1 */
#define kCanIR_RF1X                     0x000000F0UL /*! Any Rx FIFO 1 */
#define kCanIR_RF0L                     0x00000008UL /*! Rx FIFO 0 message lost (also set after write attempt to Rx FIFO 0 of size zero) */
#define kCanIR_RF0F                     0x00000004UL /*! Rx FIFO 0 full */
#define kCanIR_RF0W                     0x00000002UL /*! Rx FIFO 0 fill level reached watermark */
#define kCanIR_RF0N                     0x00000001UL /*! New message written to Rx FIFO 0 */
#define kCanIR_RF0X                     0x0000000FUL /*! Any Rx FIFO 0 */
#define kCanIR_TFE                      0x00000800UL /*! Tx FIFO Empty */
#define kCanIR_TEFN                     0x00001000UL /*! Tx Event FIFO New Entry */
#define kCanIR_TEFW                     0x00002000UL /*! Tx Event FIFO Watermark Reached */
#define kCanIR_TEFF                     0x00004000UL /*! Tx Event FIFO Full */
#define kCanIR_TEFL                     0x00008000UL /*! Tx Event FIFO Event Lost */
#define kCanIR_TEF_EVTYPE_TX            0x00400000UL /*! Tx Event FIFO Event Type = Tx Event */
#define kCanIR_TEF_EVTYPE_TXCANCEL      0x00800000UL /*! Tx Event FIFO Event Type = Transmission in spite of cancellation */
#define kCanIR_TSW                      0x00010000UL /*! Timestamp Wrap-around */
#define kCanIR_ELO                      0x00400000UL /*! Error Logging Overflow */

/* Fifo (RXFn): */
#define kCanRXFnS_FnGI                  0x00003F00UL  /*! Fifo Get Index */
#define kCanRXFnS_FnFL                  0x0000007FUL  /*! Fifo Fill Level */

/*** A change of the CAN operation mode is requested by writing to this bit field. 
After change to the requested operation mode the bit field is reset to '00' and the status flags FACT and LACT are set accordingly. 
In case the requested CAN operation mode is not enabled, the value written to CMR is retained until it is overwritten by the next mode change request. 
Default is normal CAN operation. 
CAN Mode Request
  00 unchanged
  01 Long Frame Mode request
  10 Long + Fast Frame Mode request
  11 Normal CAN operation request
CAN Mode Enable
  00 Normal CAN operation according to ISO11898-1
  01 Long        Frame Mode enabled: transmission of long, reception of long and fast CAN FD frames is enabled
  10 Long + Fast Frame Mode enabled: transmission and reception of long and fast CAN FD frames is enabled
  11 Long + Fast Frame Mode enabled: transmission and reception of long and fast CAN FD frames is enabled ***/
#if ( CAN_MCAN_REVISION >= 0x0310UL )    /* COV_CAN_HW_SPECIFIC */
/***  - CMR removed, transmit format configured in Tx Buffer element
      - CME replaced by FDOE and BRSE ***/
# define kCanCCCR_BRSE                  0x00000200UL /*! Bit Rate Switch enable */
# define kCanCCCR_FDOE                  0x00000100UL /*! FD operation enable */
# if ( CAN_MCAN_REVISION >= 0x0315UL )    /* COV_CAN_HW_SPECIFIC */
/***  NISO added since Rev. 3.1.5 ***/
#  define kCanCCCR_NISO                 0x00008000UL /*! Non ISO Operation 
                                                       0= CAN FD frame format according to ISO11898-1
                                                       1= CAN FD frame format according to Bosch CAN FD Spec. V1.0 */
# endif
#else
# define kCanCCCR_CME_CAN20             0x00000300UL /*! NORMAL CAN */
# define kCanCCCR_CME_LONG              0x00000100UL /*! LONG */
# define kCanCCCR_CME_LONG_FAST         0x00000200UL /*! LONG & FAST */
# define kCanCCCR_CMR_CAN20             0x00000C00UL /*! NORMAL CAN */
# define kCanCCCR_CMR_LONG              0x00000400UL /*! LONG */
# define kCanCCCR_CMR_LONG_FAST         0x00000800UL /*! LONG & FAST */
#endif
#if ( CAN_MCAN_REVISION >= 0x0300UL )   /* COV_CAN_HW_SPECIFIC */ /* Since rev3 */ 
# define kCanCCCR_TXP                  0x00004000UL /*! Transmit Pause */
# if ( CAN_MCAN_REVISION >= 0x0310UL )   /* COV_CAN_HW_SPECIFIC */
#  define kCanCCCR_EFBI                 0x00002000UL /*! new control bit PXHD (Protocol Exception Handling Disable) replaces status flag FDO */
#  define kCanCCCR_PXHD                 0x00001000UL /*! new control bit EFBI (Edge Filtering during Bus Integration) replaces status flag FDBS */
# else
#  define kCanCCCR_FDO                  0x00001000UL /*! CAN FD Operation */
#  define kCanCCCR_FDBS                 0x00002000UL /*! CAN FD Bit Rate Switching */
# endif
#else
# define kCanCCCR_LACT                 0x00001000UL /*! Long Frame Mode Active */
# define kCanCCCR_FACT                 0x00002000UL /*! Fast Frame Mode Active */
#endif

#if ( CAN_MCAN_REVISION >= 0x0300UL )    /* COV_CAN_HW_SPECIFIC */
# if !defined( CAN_SET_BR_ID ) /* COV_CAN_COMPATIBILITY */
#  define CAN_SET_BR_ID  0x0F
# endif
#endif
#if !defined(CAN_NONE) /* COV_CAN_COMPATIBILITY */
# define CAN_NONE        0u
#endif
#if !defined(CAN_BRS) /* COV_CAN_COMPATIBILITY */
# define CAN_BRS         1u
#endif
#if !defined(CAN_FULL) /* COV_CAN_COMPATIBILITY */
# define CAN_FULL        2u
#endif
#if !defined(CAN_FD_RXONLY) /* COV_CAN_COMPATIBILITY */
# define CAN_FD_RXONLY   2u
#endif
#if !defined(CAN_FD_RXTX) /* COV_CAN_COMPATIBILITY */
# define CAN_FD_RXTX     1u
#endif

#if !defined(STD_ON) /* COV_CAN_COMPATIBILITY */
# define STD_ON          1u
#endif
#if !defined(STD_OFF) /* COV_CAN_COMPATIBILITY */
# define STD_OFF         0u
#endif

#if !defined (CAN_FD_SUPPORT) /* COV_CAN_COMPATIBILITY */
# define CAN_FD_SUPPORT CAN_NONE
#endif

#if !defined (CAN_TXP_SUPPORT) /* COV_CAN_HW_SPECIFIC */
# define CAN_TXP_SUPPORT  STD_OFF
# define C_DISABLE_CAN_TXP_SUPPORT
#else
# if (CAN_TXP_SUPPORT == STD_ON)
#  define C_ENABLE_CAN_TXP_SUPPORT
# else
#  define C_DISABLE_CAN_TXP_SUPPORT
# endif
#endif

#if !defined( kCanNumberOfRxObjects )  /* COV_CAN_COMPATIBILITY */
# define kCanNumberOfRxObjects 0
#endif

/* Compatibility define */

/* PRQA S 3614 QAC_Can_3614 */ /* MD_Can_3614_LL */
/* PRQA  L:QAC_Can_3614 */


#define kCanRegCheckMaskCCCR_RP        0x00000003UL /*! CCE, INIT*/
#define kCanRegCheckMaskCCCR_CCE       0xFFFFFFFDUL

#if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
# define kCanRegCheckMaskFBTP    0x009F1FFFUL /*! TDC, DBRP, DTSEG1, DTSEG2, DSJW */
#else
# define kCanRegCheckMaskFBTP    0x1F9F0F73UL /*! TDCO, TDC, FBRP, FTSEG1, FTSEG2, FSJW */
#endif  /* MCAN Core Release < 0x0310UL */

#define kCanRegCheckMaskRWD    0x000000FFUL /*! WDC */

# if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
#  if ( CAN_MCAN_REVISION >= 0x0315UL ) /* COV_CAN_HW_SPECIFIC */
#   define kCanRegCheckMaskCCCR 0x0000F3F7UL /*! NISO, TXP, EFBI, PXHD, BRSE, FDOE, TEST, DAR, MON, CSR, CSA, ASM, CCE, INIT*/
#  else
#   define kCanRegCheckMaskCCCR 0x000073F7UL /*! TXP, EFBI, PXHD, BRSE, FDOE, TEST, DAR, MON, CSR, CSA, ASM, CCE, INIT*/
#  endif/* MCAN Core Release < 0x0315UL */
# else  
#  define kCanRegCheckMaskCCCR 0x00004FF7UL /*! TXP, CMR, CME, TEST, DAR, MON, CSR, CSA, ASM, CCE, INIT*/
# endif/* MCAN Core Release < 0x0310UL */

#if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
# define kCanRegCheckMaskBTP   0xFFFFFF7FUL /*! NSJW, NBRP, NTSEG1, NTSEG2 */
#else
# define kCanRegCheckMaskBTP   0x03FF3FFFUL /*! BRP, TSEG, TSEG2, SJW */
#endif /* MCAN Core Release < 0x0310UL */

#define kCanRegCheckMaskTSCC   0x000F0003UL /*! TCP, TSS */
#define kCanRegCheckMaskTOCC   0xFFFF0007UL /*! TOP, TOS, ETOC */

#if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
# define kCanRegCheckMaskTDCR   0x00007F7FUL /*! TDCO, TDCF */
#endif /* MCAN Core Release < 0x0310UL */

#if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
#  define kCanRegCheckMaskIE    0x1FCFFFFFUL /*! PEDE, PEAE, WDIE, BOE, EWE, EPE, ELOE, DRXE, TOOE, MRAFE, TSWE, TEFLE, TEFFE, TEFWE, TEFNE, TFEE, TCFE, TCE, HPME, RF1LE, RF1FE, RF1WE, RF1NE, RF0LE, RF0FE, RF0WE, RF0NE */
#else
# define kCanRegCheckMaskIE    0xFFFFFFFFUL /*! STEE, FOEE, ACKEE, BEE, CRCEE, WDIE, BOE, EWE, EPE, ELOE, BEUE, BECE, DRXE, TOOE, MRAFE, TSWE, TEFLE, TEFFE, TEFWE, TEFNE, TFEE, TCFE, TCE, HPME, RF1LE, RF1FE, RF1WE, RF1NE, RF0LE, RF0FE, RF0WE, RF0NE */
# define kCanRegCheckMaskILS   0xFFFFFFFFUL /*! STEL, FOEL, ACKEL, BEL, CRCEL, WDIL, BOL, EWL, EPL, ELOL, BEUL, BECL, DRXL, TOOL, MRAFL, TSWL, TEFLL, TEFFL, TEFWL, TEFNL, TFEL, TCFL, TCL, HPML, RF1LL, RF1FL, RF1WL, RF1NL, RF0LL, RF0FL, RF0WL, RF0NL */
#endif /* MCAN Core Release < 0x0310UL */

#define kCanRegCheckMaskGFC    0x0000003FUL /*! ANFS, ANFE, RRFS, RRFE */
#define kCanRegCheckMaskSIDFC  0x00FFFFFCUL /*! LSS,FLSSA */
#define kCanRegCheckMaskXIDFC  0x007FFFFCUL /*! LSE, FLESA */
#define kCanRegCheckMaskXIDAM  0x1FFFFFFFUL /*! EIDM */
#define kCanRegCheckMaskRXF0C  0xFF7FFFFCUL /*! F0OM,F0WM, F0S, F0SA */
#define kCanRegCheckMaskRXF0A  0x0000003FUL /*! F0AI */
#define kCanRegCheckMaskRXBC   0x0000FFFCUL /*! RBSA */
#define kCanRegCheckMaskRXF1C  0xFF7FFFFCUL /*! F1OM, F1WM, F1S, F1SA */
#define kCanRegCheckMaskRXF1A  0x0000003FUL /*! F1AI */
#define kCanRegCheckMaskRXESC  0x00000777UL /*! RBDS, F1DS, F0DS */
#define kCanRegCheckMaskTXBC   0x7F3FFFFCUL /*! TFQM, TFQS, NDTB, TBSA */
#define kCanRegCheckMaskTXESC  0x00000007UL /*! TxBufferDataFieldSize */
#define kCanRegCheckMaskTXBTIE 0xFFFFFFFFUL /*! TIE31...TIE0*/
#define kCanRegCheckMaskTXEFC  0x3F3FFFFCUL /*! EFWM, EFS, EFSA */
#if defined ( C_ENABLE_TTCAN_AVAILABLE ) /* COV_CAN_HW_SPECIFIC */
# define kCanRegCheckMaskTTOCF  0x07FFFFFBUL /*! EVTP, ECC, EGTF, AWL, EECS, IRTO, LDSDL, TM GEN, OM */
#endif

#if defined( C_ENABLE_STD_ID ) && (kCanNumberOfStandardFilter > 0)
# define kCanRegCheckMaskSMIDFE_S0   0xFFFF07FFUL /*! SFT, SFEC, SFID1, SFID2 */
#endif
#if defined(C_ENABLE_EXTENDED_ID) && (kCanNumberOfExtendedFilter > 0)
# define kCanRegCheckMaskEMIDFE_F0   0xFFFFFFFFUL /*! EFEC, EFID1 */
# define kCanRegCheckMaskEMIDFE_F1   0xDFFFFFFFUL /*! EFT, EFID2 */
#endif





# define kCanRegCheckMaskMCMCAN_GRINT        0xFFFFFFFFUL /*! Interrupt routing for Groups */
# define kCanRegCheckMaskMCMCAN_ACCENNODE0   0xFFFFFFFFUL /*! Access Enable Register */
# define kCanRegCheckMaskMCMCAN_NPCR         0x00000707UL /*! Node Port Control Register */
# define kCanRegCheckMaskMCMCANCH_STARTADR   0x0000FFFCUL /*! Start Address Node */
# define kCanRegCheckMaskMCMCANCH_ENDADR     0x0000FFFCUL /*! End Address Node */
# define kCanRegCheckMaskMCMCANCH_NTCCR      0x001CCF00UL /*! Node Timer Clock Control Register */
# define kCanRegCheckMaskMCMCANCH_NTXTTR     0x0100FFFFUL /*! Node Timer X Transmit Trigger Register */
# define kCanRegCheckMaskMCMCANCH_NTRTR      0x0040FFFFUL /*! Node Timer Receive Timeout Register */


#if defined(C_ENABLE_SHM_DATAQOS) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
# define kCanRegCheckMaskMRCFG_DATAQOS       0x00000003UL /*! Data Quality of Service */
#endif

/* *********************************************************************** */
/* SafeBSW check (LL)                                                      */
/* *********************************************************************** */
#if !defined(CAN_SAFE_BSW) /* COV_CAN_COMPATIBILITY */
# define CAN_SAFE_BSW    STD_OFF
#endif
# if (CAN_SAFE_BSW == STD_ON)
#  if !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL) /* COV_CAN_SAFE_BSW_EXCLUSION_LL */
#   error "An unsupported feature is active for SafeBSW!"
#  endif
# endif

/***************************************************************************/
/* macros                                                                  */
/***************************************************************************/
/* PRQA S 3453 FctLikeMacroLabel */ /* MD_MSR_FctLikeMacro */

/* for LL compatibility */
/* hw handles */
#define CAN_HL_HW_TX_NORMAL_INDEX(hwch)     (Can_GetTxBasicHwStart(hwch)) 
#if defined(CAN_HL_HW_LAYOUT_TXBASIC_FIRST) /* COV_CAN_HW_LAYOUT_TXBASIC_FIRST */
# define CAN_HL_HW_TX_STARTINDEX(hwch)      (Can_GetTxBasicHwStart(hwch))
#else
# define CAN_HL_HW_TX_STARTINDEX(hwch)      (Can_GetTxFullHwStart(hwch))
#endif
#define CAN_HL_HW_TX_FULL_STARTINDEX(hwch)  (Can_GetTxFullHwStart(hwch))
#define CAN_HL_HW_UNUSED_STARTINDEX(hwch)   (Can_GetUnusedHwStart(hwch))
#define CAN_HL_HW_RX_FULL_STARTINDEX(hwch)  (Can_GetRxFullHwStart(hwch))
#define CAN_HL_HW_RX_BASIC_STARTINDEX(hwch) (Can_GetRxBasicHwStart(hwch))
#if defined(CAN_HL_HW_LAYOUT_TXBASIC_FIRST) /* COV_CAN_HW_LAYOUT_TXBASIC_FIRST */
# define CAN_HL_HW_TX_STOPINDEX(hwch)       (Can_GetTxFullHwStop(hwch))
#else
# define CAN_HL_HW_TX_STOPINDEX(hwch)       (Can_GetTxBasicHwStop(hwch))
#endif
#define CAN_HL_HW_TX_FULL_STOPINDEX(hwch)   (Can_GetTxFullHwStop(hwch))
#define CAN_HL_HW_UNUSED_STOPINDEX(hwch)    (Can_GetUnusedHwStop(hwch))
#define CAN_HL_HW_RX_FULL_STOPINDEX(hwch)   (Can_GetRxFullHwStop(hwch))
#define CAN_HL_HW_RX_BASIC_STOPINDEX(hwch)  (Can_GetRxBasicHwStop(hwch))
/* mailbox handles */
#define CAN_HL_MB_RX_FULL_STARTINDEX(hwch)  (Can_GetRxFullHandleStart(hwch))
#define CAN_HL_MB_RX_BASIC_STARTINDEX(hwch) (Can_GetRxBasicHandleStart(hwch))
#define CAN_HL_MB_TX_FULL_STARTINDEX(hwch)  (Can_GetTxFullHandleStart(hwch))
#define CAN_HL_MB_TX_BASIC_STARTINDEX(hwch) (Can_GetTxBasicHandleStart(hwch))
#define CAN_HL_MB_RX_FULL_STOPINDEX(hwch)   (Can_GetRxFullHandleStop(hwch))
#define CAN_HL_MB_RX_BASIC_STOPINDEX(hwch)  (Can_GetRxBasicHandleStop(hwch))
#define CAN_HL_MB_TX_FULL_STOPINDEX(hwch)   (Can_GetTxFullHandleStop(hwch))
#define CAN_HL_MB_TX_BASIC_STOPINDEX(hwch)  (Can_GetTxBasicHandleStop(hwch))

#if defined(C_ENABLE_CAN_RAM_CHECK)
# if !defined(CAN_RAM_CHECK_MAILBOX_RESULT) /* May be defined by test suite to stimulate RAM_CHECK failure */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#   define CAN_RAM_CHECK_MAILBOX_RESULT(ch, initParaPtr) CanLL_InitIsMailboxCorrupt((initParaPtr))
#  else
#   define CAN_RAM_CHECK_MAILBOX_RESULT(ch, initParaPtr) CanLL_InitIsMailboxCorrupt((ch), (initParaPtr))
#  endif
# endif
# if !defined(CAN_RAM_CHECK_FINISHED_CTP) /* May be defined by test suite to check RAM_CHECK finished / executed */
#  define CAN_RAM_CHECK_FINISHED_CTP(ch)
# endif
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
# if !defined(CAN_RAM_CHECK_BEGIN_REG_RESULT) /* May be defined by test suite to stimulate RAM_CHECK_EXTENDED failure */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#   define CAN_RAM_CHECK_BEGIN_REG_RESULT(ch, initParaPtr) CanLL_InitBeginIsRegisterCorrupt((initParaPtr))
#  else
#   define CAN_RAM_CHECK_BEGIN_REG_RESULT(ch, initParaPtr) CanLL_InitBeginIsRegisterCorrupt((ch), (initParaPtr))
#  endif
# endif
# if !defined(CAN_RAM_CHECK_END_REG_RESULT) /* May be defined by test suite to stimulate RAM_CHECK_EXTENDED failure */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
#   define CAN_RAM_CHECK_END_REG_RESULT(ch, initParaPtr) CanLL_InitEndIsRegisterCorrupt((initParaPtr))
#  else
#   define CAN_RAM_CHECK_END_REG_RESULT(ch, initParaPtr) CanLL_InitEndIsRegisterCorrupt((ch), (initParaPtr))
#  endif
# endif
# if !defined(CAN_RAM_CHECK_READ_BACK_RESULT) /* May be defined by test suite to stimulate RAM_CHECK_EXTENDED failure */
#  define CAN_RAM_CHECK_READ_BACK_RESULT(ch)
# endif
#endif

#define CanHL_IsStart(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_START) == CAN_STATUS_START)
#define CanHL_IsSleep(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_SLEEP) == CAN_STATUS_SLEEP)
#define CanHL_IsStop(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_STOP) == CAN_STATUS_STOP)
#define CanHL_IsBusOff(ch) (Can_IsIsBusOff(ch))
#define CanHL_IsControllerInit(ch) ((Can_GetLogStatus(ch) & CAN_STATUS_INIT) == CAN_STATUS_INIT)

#if defined(C_ENABLE_CAN_FD_USED) /* also for BRS because DLC may be bigger than 8 and will be checked by CanIf */
# define CAN_DLC2LEN(dlc) (Can_DlcToFrameLenght[((uint8)(dlc)) & ((uint8)0xFu)])
# define CAN_LEN2DLC(length) ((uint8)Can_MessageLengthToDlc[(length)])
#else
# define CAN_DLC2LEN(dlc) (dlc)
# define CAN_LEN2DLC(length) (length)
#endif
#if defined(C_ENABLE_CAN_FD_FULL)
# define CAN_MAX_DATALEN_OBJ(Index) Can_GetMailboxDataLen(Index)
#else
# define CAN_MAX_DATALEN_OBJ(Index) 8u
#endif
#define CanHL_IsFdMessage(id) (((id) & (Can_IdType)CAN_ID_FD_MASK) == (Can_IdType)CAN_ID_FD_MASK) /* \trace SPEC-60432, SPEC-50586 */
#define CanHL_IsFdTxBrs(ch)   (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(ch)) == CAN_FD_RXTX) /* \trace SPEC-60432, SPEC-50586 */

/* PRQA L:FctLikeMacroLabel */

/* PRQA S 3453 FctLikeMacroLabel */ /* MD_MSR_FctLikeMacro */
/* 
  parameter for ApplCanTimerStart(),-End(), -Loop()
  index has to start with 0, continuous numbers have to be used. Gaps are not allowed! 
*/

# define kCanACTIVE           0x00000001UL /* '1'= used to search or set the active connection  */ 
# define CanLL_HwDlcMask      0x000F0000UL /* MCAN register layout */



/*
|<DataModelStart>| CanLL_TxIsObjFree
Relation_Context:
# from CanTransmit, CanMsgTransmit, CanCopyDataAndStartTransmission() #
Relation:
ChannelAmount, TxBasicAmount
ChannelAmount, TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
#define CanLL_TxIsObjFree( hwCh, txObjHandle ) ( ((Cn->TXBC & kCanTXBC_TFQS) > 0UL) ? /* check Fifo/Queue size */ \
            (kCanFalse) :  /* N/A: Fifo/Queue exists with size != zero */ \
            ( ((Cn->TXBRP & ((vuint32)(kCanTXBRP_RP << (txObjHandle)))) == 0UL) ) )   /* all buffers are dedicated buffers, return true if pending bit is not set */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
/* Each Tx Buffer has its own pending bit. 
   The bits are set via TXBAR. 
   The bits are reset after transmission has completed or has been cancelled (via TXBCR).

   A cancellation request resets the corresponding transmission request pending bit of register TXBRP. 
   The corresponding TXBCF bit is set for all unsuccessful transmissions.
   In DAR mode all transmissions are automatically cancelled if they are not successful. */



/* Power down mode
   Controlled by input signal clock stop request or via CCCR[CSR]. 
   As long as the clock stop request signal is active, bit CCCR[CSR] is read as one. 

   a) all pending transmission requests are completed
   b) Bus_Idle is awaited
   c) CCCR[INIT] is set to '1' (prevent any further CAN transfers)
   d) Clock stop acknowledge output signal =1, CCCR[CSA] =1 (M_CAN acknowledges that it is ready for power down)
   In this state, before the clocks are switched off, further register accesses can be made (write access to CCCR[INIT] has no effect)
   e) Module clock inputs (CAN and Host clock) may be switched off now */
/*
|<DataModelStart>| CanLL_HwIsStop
Relation_Context:
Relation:
OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
#define CanLL_HwIsStop( hwCh )   ((Cn->CCCR & kCanCCCR_INIT) != 0UL)

/*
|<DataModelStart>| CanLL_HwIsBusOff
Relation_Context:
Relation:
OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
#define CanLL_HwIsBusOff( hwCh ) ((Cn->PSR & kCanPSR_BO) != 0UL)

#if defined( C_ENABLE_EXTENDED_STATUS )
/*
|<DataModelStart>| CanLL_HwIsPassive
Relation_Context:
Relation:
CanGetStatus, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
# define CanLL_HwIsPassive( hwCh ) ((Cn->PSR & kCanPSR_EP) != 0UL)

/*
|<DataModelStart>| CanLL_HwIsWarning
Relation_Context:
Relation:
CanGetStatus, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
# define CanLL_HwIsWarning( hwCh )  ((Cn->PSR & kCanPSR_EW) != 0UL)
#endif /* C_ENABLE_EXTENDED_STATUS */


#if defined( C_ENABLE_HW_LOOP_TIMER )
# if defined(C_MULTIPLE_RECEIVE_CHANNEL)
#  define CanLL_ApplCanTimerStart(loop)  ApplCanTimerStart(channel, loop)
#  define CanLL_ApplCanTimerEnd(loop)    ApplCanTimerEnd(channel, loop)
#  define CanLL_ApplCanTimerLoop(loop)   ApplCanTimerLoop(channel, loop)
# else
#  define CanLL_ApplCanTimerStart(loop)  ApplCanTimerStart(loop)
#  define CanLL_ApplCanTimerEnd(loop)    ApplCanTimerEnd(loop)
#  define CanLL_ApplCanTimerLoop(loop)   ApplCanTimerLoop(loop)
# endif
#else
# define CanLL_ApplCanTimerStart(loop)
# define CanLL_ApplCanTimerEnd(loop)
# define CanLL_ApplCanTimerLoop(loop)    (vuint8)(1u)
#endif

# define CAN_MSG_RAM_SYNC()   


#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
# if !defined( C_ENABLE_CAN_RAM_CHECK )
#  error "C_ENABLE_CAN_RAM_CHECK has to be defined if C_ENABLE_CAN_RAM_CHECK_EXTENDED is set."
# endif
#endif


 
#  define CAN_WRITE_SRN_PROTECTED_REG32(area, regAddr, val)     CAN_WRITE_PROTECTED_REG32( (area), ((vuint32*)regAddr), (val) )
#  define CAN_READ_SRN_PROTECTED_REG32(area, regAddr)           CAN_READ_PROTECTED_REG32((area), ((vuint32*)regAddr) )

# if defined(C_ENABLE_USER_MODE_APPL) || defined(C_ENABLE_USER_MODE_OS)
#   define CAN_SET_OSVALUE_32_CHANNEL(regAddr,val,mask,localPara) (void)CanLL_WriteProtectedReg32(CAN_CHANNEL_CANPARA_FIRST CAN_PROTECTED_AREA_CHANNEL, (regAddr), (val), (mask), (localPara))
# else
#   define CAN_SET_OSVALUE_32_CHANNEL(regAddr,val,mask,localPara) (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST (regAddr), (val), (mask), (localPara))
# endif

#if defined(V_CPU_TC3XX) /* COV_CAN_HW_SPECIFIC */
# define CAN_ENDINIT_PROTECT_OFF()    Appl_UnlockEndinit()
# define CAN_ENDINIT_PROTECT_ON()     Appl_LockEndinit()
#endif
 

/* PRQA L:FctLikeMacroLabel */

/***************************************************************************/
/* Constants                                                               */
/***************************************************************************/
#define CAN_START_SEC_CONST_UNSPECIFIED  /*--------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* BR:012 */
V_DEF_CONST(V_NONE, uint8, CONST) Can_MainVersion         = (uint8)CAN_SW_MAJOR_VERSION; /* PRQA S 3408 */ /* MD_Can_ExternalScope */
V_DEF_CONST(V_NONE, uint8, CONST) Can_SubVersion          = (uint8)CAN_SW_MINOR_VERSION; /* PRQA S 3408 */ /* MD_Can_ExternalScope */
V_DEF_CONST(V_NONE, uint8, CONST) Can_ReleaseVersion      = (uint8)CAN_SW_PATCH_VERSION; /* PRQA S 3408 */ /* MD_Can_ExternalScope */


#if defined(C_ENABLE_CAN_FD_USED)
V_DEF_CONST(CAN_STATIC, uint8, CONST) Can_DlcToFrameLenght[16] = /* PRQA S 3218,3408 */ /* MD_Can_GlobalScope */
{
  0u,  1u,  2u,  3u,
  4u,  5u,  6u,  7u,
  8u, 12u, 16u, 20u,
 24u, 32u, 48u, 64u
};
V_DEF_CONST(CAN_STATIC, uint8, CONST) Can_MessageLengthToDlc[65] = /* PRQA S 3218,3408 */ /* MD_Can_GlobalScope */
{
/* 00..07 */  0u,  1u,  2u,  3u,  4u,  5u,  6u,  7u,
/* 08..15 */  8u,  9u,  9u,  9u,  9u, 10u, 10u, 10u,
/* 16..23 */ 10u, 11u, 11u, 11u, 11u, 12u, 12u, 12u,
/* 24..31 */ 12u, 13u, 13u, 13u, 13u, 13u, 13u, 13u,
/* 32..39 */ 13u, 14u, 14u, 14u, 14u, 14u, 14u, 14u,
/* 40..47 */ 14u, 14u, 14u, 14u, 14u, 14u, 14u, 14u,
/* 48..55 */ 14u, 15u, 15u, 15u, 15u, 15u, 15u, 15u,
/* 56..63 */ 15u, 15u, 15u, 15u, 15u, 15u, 15u, 15u,
/* 64     */ 15u
};
#endif

/* Global constants with CAN driver main and subversion */

#if defined( C_ENABLE_CAN_RAM_CHECK )
/* ROM CATEGORY 4 START */
V_DEF_CONST(CAN_STATIC, vuint32, CONST) CanMemCheckValues32bit[3] =  /* PRQA S 3218 */ /* MD_Can_GlobalScope */
{
  0xAAAAAAAAUL, 0x55555555UL, 0x00000000UL
};
/* ROM CATEGORY 4 END */
#endif

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
/* ROM CATEGORY 4 START */
V_DEF_CONST(CAN_STATIC, vuint32, CONST) CanRegCheckValues32bit[4] =  /* PRQA S 3218 */ /* MD_Can_GlobalScope */
{
  0xAAAAAAAAUL, 0x55555555UL, 0xAAAAAAAAUL, 0x00000000UL
};
/* ROM CATEGORY 4 END */
#endif

#if defined(C_ENABLE_CAN_FD_FULL) 
V_DEF_CONST(CAN_STATIC, vuint8, CONST) CanLL_xES2Bytes[8] =
{
  8, 12, 16, 20,
 24, 32, 48, 64
};
#endif


#define CAN_STOP_SEC_CONST_UNSPECIFIED  /*---------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***************************************************************************/
/* global data definitions                                                 */
/***************************************************************************/
#define CAN_START_SEC_VAR_NOINIT_UNSPECIFIED  /*---------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***************************************************************************************/
/* local data definitions   (need also INFIX because STATIC may be defined to nothing) */
/***************************************************************************************/
/* \trace SPEC-1585 */
/*! Semaphore to block reentrancy for Can_MainFunction_Read() */
V_DEF_VAR(CAN_STATIC, uint8, VAR_NOINIT) canIsRxTaskLocked; /* PRQA S 3408 */ /* MD_Can_GlobalScope */
#if defined(C_ENABLE_RX_QUEUE)
V_DEF_VAR(CAN_STATIC, uint16, VAR_NOINIT) canRxQueueMaxDataSize;  /* PRQA S 3218,3408 */ /* MD_Can_GlobalScope */
#endif




#define CAN_STOP_SEC_VAR_NOINIT_UNSPECIFIED  /*----------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

# define CAN_START_SEC_VAR_INIT_UNSPECIFIED  /*-----------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/* ! Mark module to be initialized (used to check double/none initialization) */
V_DEF_VAR(CAN_STATIC, uint8, VAR_INIT) canConfigInitFlag = CAN_STATUS_UNINIT;
# define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED  /*------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* not static because of debug/test usage */
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
# define CAN_START_SEC_VAR_INIT_UNSPECIFIED  /*-----------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! Pointer to the current configuration */
V_DEF_P2CONST (V_NONE, Can_ConfigType, VAR_INIT, CONST_PBCFG) Can_ConfigDataPtr = NULL_PTR; /* UREQ00035484 */ /* PRQA S 3408 */ /* MD_Can_ExternalScope */
# define CAN_STOP_SEC_VAR_INIT_UNSPECIFIED  /*------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#else
# define CAN_START_SEC_CONST_UNSPECIFIED  /*--------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*! Pointer to the current configuration */
V_DEF_CONSTP2CONST(V_NONE, Can_ConfigType, CONST, CONST_PBCFG) Can_ConfigDataPtr = NULL_PTR; /* PRQA S 3408,1514 */ /* MD_Can_ExternalScope */
# define CAN_STOP_SEC_CONST_UNSPECIFIED  /*---------------------------------*/
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#endif

/***************************************************************************/
/*  Safe Check                                                             */
/***************************************************************************/
#if !defined(CAN_SAFE_BSW) /* COV_CAN_COMPATIBILITY */
# define CAN_SAFE_BSW   STD_OFF
#else
# if (CAN_SAFE_BSW == STD_ON) /* COV_CAN_SAFE_BSW */
#  if (CAN_DEV_ERROR_DETECT == STD_OFF) || (CAN_AMD_RUNTIME_MEASUREMENT == STD_ON) /* COV_CAN_SAFE_BSW_EXCLUSION */
#   error "Unsupported Feature activated for SafeBSW"
#  endif
# endif
#endif

/***************************************************************************/
/*  Error Check                                                            */
/***************************************************************************/
# if (CAN_SLEEP_SUPPORT == STD_ON) && (CAN_WAKEUP_SUPPORT == STD_ON)
#  error "C_ENABLE_SLEEP_WAKEUP organified but generated like supported"
# endif
#if (CAN_WAKEUP_SUPPORT == STD_ON) && (CAN_SLEEP_SUPPORT == STD_OFF)
# error "activated CAN_WAKEUP_SUPPORT need activated CAN_SLEEP_SUPPORT"
#endif
#if defined(C_ENABLE_HW_LOOP_TIMER)
# if (CAN_LOOP_MAX == 0)
#  error "CAN_LOOP_MAX should not be generated as 0"
# endif
#else
# if (CAN_HARDWARE_CANCELLATION == STD_ON)
#  error "C_ENABLE_HW_LOOP_TIMER organified but generated like supported"
# endif
#endif
# if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
#  error "C_ENABLE_CANCEL_IN_HW organified but generated like supported"
# endif
#if (CAN_MIRROR_MODE == STD_ON) && (!defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2) || (CAN_GENERIC_PRECOPY == STD_OFF))
# error "CAN_MIRROR_MODE need CAN_GENERIC_CONFIRMATION with CAN_API2 and CAN_GENERIC_PRECOPY as STD_ON"
#endif
#if (CAN_MULTIPLE_BASICCAN_TX == STD_ON)
# if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON)
/* cancellation does not work in CanHL_WritePrepareCancelTx for multiple BasicCAN messages, and is not useful for FIFO queue in CanIf (normally combined with multiple BCAN)*/
# error "CAN_MULTIPLE_BASICCAN_TX and CAN_HW_TRANSMIT_CANCELLATION are STD_ON but this combination is not supported"
# endif
#endif


/***************************************************************************/
/*  Functions                                                              */
/***************************************************************************/
#define CAN_START_SEC_STATIC_CODE  /*--------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# if defined( C_SINGLE_RECEIVE_CHANNEL )
#  define CanHL_ApplCanTimerStart( timerIdx )  ApplCanTimerStart( timerIdx );
#  define CanHL_ApplCanTimerEnd( timerIdx )    ApplCanTimerEnd( timerIdx );
# else
#  define CanHL_ApplCanTimerStart( timerIdx )  ApplCanTimerStart( channel, (timerIdx) );
#  define CanHL_ApplCanTimerEnd( timerIdx )    ApplCanTimerEnd( channel, (timerIdx) );
# endif
# define CanHL_ApplCanTimerLoop( timerIdx )   if (ApplCanTimerLoop(CAN_CHANNEL_CANPARA_FIRST (timerIdx)) != CAN_OK) \
                                              { \
                                                break; \
                                              }

# if (CAN_HW_LOOP_SUPPORT_API == STD_OFF)
/* Internal handling of HW loops (like AutoSar) - otherwise ApplCanTimer... is defined an implemented by Application */
/****************************************************************************
| NAME:             ApplCanTimerStart
****************************************************************************/
/* Used as macro to save runtime and code */
#  if defined( C_SINGLE_RECEIVE_CHANNEL )
/* \trace SPEC-1640 */
#    define ApplCanTimerStart(source)     ((void)GetCounterValue( CAN_OS_COUNTER_ID, &Can_GetCanLoopTimeout(0, (source)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  else
#    define ApplCanTimerStart(ch, source) ((void)GetCounterValue( CAN_OS_COUNTER_ID, &Can_GetCanLoopTimeout((ch), (source)))) /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */
#  endif
/****************************************************************************
| NAME:             ApplCanTimerLoop
****************************************************************************/
/*
|<DataModelStart>| ApplCanTimerLoop
Relation_Context:
# from mode transition + any LL #
HardwareLoopCheck, HardwareCancelByAppl
Relation:
DevErrorDetect, OneChOpt
HardwareLoopCheck
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) ApplCanTimerLoop( CAN_CHANNEL_CANTYPE_FIRST uint8 source )
{
  /* ----- Local Variables ---------------------------------------------- */
  Can_ReturnType retval;
  uint8 errorId;
  uint8 apiId;
  errorId = CAN_E_NO_ERROR;
  apiId = CAN_HW_ACCESS_ID;
  retval = CAN_NOT_OK;

  /* ----- Development Error Checks ------------------------------------- */
#  if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller and source is valid (no INIT check because may be used inside power on INIT) */
  if (source > CAN_LOOP_MAX) /* CM_CAN_HL22 */
  {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#   if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#   endif
#  endif
  {
    /* ----- Implementation ----------------------------------------------- */
    TickType elapsedTime;
    TickType startTime;
    /* #110 Calculate the elapsed since time the start of this hardware loop (identified by parameter source). */
    /* Get start time (set by ApplCanTimerStart - temporary variable because GetElapsedValue modify original data */
    startTime = Can_GetCanLoopTimeout(channel, source);
    /* Get elapsed time - from start time to now */
    /* #120 Throw DET error when GetElapsedValue() failed */
    if ( GetElapsedValue( CAN_OS_COUNTER_ID, &startTime, &elapsedTime ) != (StatusType)E_OK ) /* SBSW_CAN_HL37 */ /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_TIMEOUT_DET;
    }
    else
    {
      /* #130 Check if time out occurs for HW loop checks (none mode transition) \trace SPEC-1594 */
      if ( (TickType)CAN_OS_TICK2MS( elapsedTime ) < (TickType)CAN_TIMEOUT_DURATION ) /* COV_CAN_HARDWARE_FAILURE */
      { /* no time out occur return OK */
        retval = CAN_OK;
      }
#  if defined(C_ENABLE_HW_LOOP_TIMER)
      else
      { /* Mode Change synchronous & HW loop check */
        /* #140 Throw DET error and set hardware cancellation flag */
        if (source < CAN_LOOP_MAX) /* COV_CAN_HARDWARE_FAILURE */
        { 
          errorId = CAN_E_TIMEOUT_DET;
        }
      }
#  endif
    }
    CAN_DUMMY_STATEMENT(startTime); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }

  /* ----- Development Error Report --------------------------------------- */
#  if (CAN_DEV_ERROR_REPORT == STD_ON)  
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(apiId, errorId);
  }
#  else
  CAN_DUMMY_STATEMENT(apiId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#  endif
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
/****************************************************************************
| NAME:             ApplCanTimerEnd
****************************************************************************/
/* Used as macro to save runtime and code */
/* because of possible nested timers .. timer has to be reset */
#  define ApplCanTimerEnd ApplCanTimerStart
# endif /* (CAN_HW_LOOP_SUPPORT_API == STD_OFF) */


/****************************************************************************
| NAME:             CanHL_CleanUpSendState
****************************************************************************/
/*
|<DataModelStart>| CanHL_CleanUpSendState
Relation_Context:
# from CanLL_ModeTransition() #
Relation:
OneChOpt, ChannelAmount
MultiplexedTx
TxFullCANSupport
TxBasicAmount
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_CleanUpSendState( CAN_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  CanObjectHandle activeSendObject;
  CanObjectHandle mailboxHandle;
  Can_HwHandleType mailboxElement;
  /* ----- Implementation ----------------------------------------------- */
  /* parameter channel is already checked by caller */
  /* #10 set all BasicCAN TX Objects to state FREE to allow a new transmission */
  mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel);
# if defined(C_ENABLE_MULTIPLE_BASICCAN_TX)
  for (; mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
# endif
  {
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    for (mailboxElement = 0u; mailboxElement < Can_GetMailboxSize(mailboxHandle); mailboxElement++)
# else
    mailboxElement = 0u; /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
# endif
    {
      activeSendObject = CanHL_GetActiveSendObject(mailboxHandle, mailboxElement);
      Can_SetActiveSendState(activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
    }
  }
# if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  /* #30 set all FullCAN TX Objects to state FREE to allow a new transmission */
  for (mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
  {
    activeSendObject = CanHL_GetActiveSendObject(mailboxHandle, 0u);
    Can_SetActiveSendState(activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */ 
  }
# endif
  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}

/****************************************************************************
| NAME:             CanHL_ReInit
****************************************************************************/
/*
|<DataModelStart>| CanHL_ReInit
Relation_Context:
# from CanHL_ModeTransition() #
Wakeup, OneChOpt, ChannelAmount
Relation:
DevErrorDetect, OneChOpt, ChannelAmount
DevErrorDetect, Variant, ChannelAmount
RamCheck
TxFullCANSupport
RxFullCANSupport
RxBasicCANSupport
Wakeup, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_STATIC, uint8, STATIC_CODE) CanHL_ReInit( CAN_HW_CHANNEL_CANTYPE_FIRST uint8 doRamCheck )
{ /* \trace SPEC-1719, SPEC-1589, SPEC-1346, SPEC-1565 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanInitParaStruct initPara;
  CanHookBegin_CanHL_ReInit();
  errorId = CAN_E_NO_ERROR;
  initPara.isInitOk = kCanOk;
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller and Config pointer is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1718 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1713 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* \trace SPEC-1713 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #100 initialization controller states and initialization objects --- */
    initPara.initObject = Can_GetLastInitObject(channel);
#if defined(C_ENABLE_CAN_RAM_CHECK)
    initPara.doRamCheck = doRamCheck;
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    initPara.isChRamCheckFail = kCanFalse;
#endif
    /* #110 clean up status (do not activate communication and let SLEEP and initialization to detect ram-check request) */
#if defined(C_ENABLE_CAN_RAM_CHECK) && !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    if (doRamCheck == kCanExecuteRamCheck)
    { /* #112 standard RAM check will be performed so delete old status CAN_DEACTIVATE_CONTROLLER but leave CAN_STATUS_INIT (info about PowerOn) */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)CAN_STATUS_INIT);  /* SBSW_CAN_HL02 */
    }
    else
#endif
    { /* #114 extended RAM check may be performed so delete old status except CAN_DEACTIVATE_CONTROLLER and CAN_STATUS_INIT */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & ((uint8)(CAN_DEACTIVATE_CONTROLLER) | (uint8)((uint8)CAN_STATUS_INIT)));  /* SBSW_CAN_HL02 */
    }
    /* #125 begin initialization CanHL_InitBegin() */
    initPara.isInitOk &= CanHL_InitBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
    /* #130 block invalid hardware access (silent check) */
    if (initPara.isInitOk == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
    {
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
      /* #140 do TX FullCAN initialization CanHL_InitTxFullCAN()*/
      initPara.isInitOk &= CanHL_InitTxFullCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#endif
      /* #150 do TX BasicCAN initialization CanHL_InitTxBasicCAN() */
      initPara.isInitOk &= CanHL_InitTxBasicCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
      /* #170 do RX FullCAN initialization CanHL_InitRxFullCAN() */
      initPara.isInitOk &= CanHL_InitRxFullCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#endif
#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
      /* #180 do RX BasicCAN initialization CanHL_InitRxBasicCAN() */
      initPara.isInitOk &= CanHL_InitRxBasicCAN(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */
#endif
      /* #190 end initialization CanHL_InitEnd_InitMode() */
      initPara.isInitOk &= CanHL_InitEnd_InitMode(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &initPara); /* SBSW_CAN_HL31 */ /* PRQA S 2986 */ /* MD_Can_ConstValue */
#if defined(C_ENABLE_CAN_RAM_CHECK)
      if (doRamCheck == kCanExecuteRamCheck)
      { 
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
        /* #200 extended RamChecks new issue occur - notify corrupt register / deactivate controller */
        if (initPara.isChRamCheckFail == kCanTrue) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
        {
          CanIf_RamCheckCorruptController((uint8)Can_GetCanToCanIfChannelMapping(channel));
          Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_DEACTIVATE_CONTROLLER); /* SBSW_CAN_HL02 */
        }
# else
        if( (Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) == CAN_DEACTIVATE_CONTROLLER ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
        { /* #210 standard RAM check issue occur - call Appl_CanRamCheckFailed() (any mailbox fail) */
          if (Appl_CanRamCheckFailed((uint8)channel) != CAN_DEACTIVATE_CONTROLLER)
          { /* #220 let the application decide if communication stay disabled as set by RAM check or not */
            Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)(~(CAN_DEACTIVATE_CONTROLLER))); /* Application decide to activate communication in case RAM_CHECK failed */  /* SBSW_CAN_HL02 */
          }
        }
# endif
        CAN_RAM_CHECK_FINISHED_CTP(channel)
      }
#endif
    }
    if (initPara.isInitOk == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
    { /* #280 set controller init flag when no issue occure before */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | (CAN_STATUS_INIT)); /* SBSW_CAN_HL02 */
    }
    else
    { /* #275 set error when issue occure before */
      Can_SetLogStatus(channel, /* CAN_STATUS_UNINIT | */ (Can_GetLogStatus(channel) & (uint8)(CAN_DEACTIVATE_CONTROLLER))); /* SBSW_CAN_HL02 */
      errorId = CAN_E_UNINIT;
    }
  } /* controller active in multiple ECU configuration */

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_INITCTR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if !defined(C_ENABLE_CAN_RAM_CHECK)
  CAN_DUMMY_STATEMENT(doRamCheck); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_CanHL_ReInit();
  return initPara.isInitOk;
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */

/****************************************************************************
| NAME:             CanHL_ModeTransition
****************************************************************************/
/*
|<DataModelStart>| CanHL_ModeTransition
Relation_Context:
# from Can_Init #
ChannelAmount
# from Can_Mainfunction_BusOff, CanHL_ErrorHandling #
StatusPolling, ChannelAmount
# from Can_ChangeBaudrate #
ChannelAmount
# from Can_SetBaudrate #
ChannelAmount
# from Can_SetControllerMode #
Wakeup
RamCheck
# from Can_RamCheckExecute #
RamCheck
# from Can_RamCheckEnableController #
RamCheck
Relation:
OneChOpt, HardwareLoopCheck, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_ModeTransition( CAN_CHANNEL_CANTYPE_FIRST uint8 transitionRequest, uint8 busOffRecovery, uint8 doRamCheck )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 transitionState;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 request transition in LL */
  transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
  if(transitionState != kCanOk) /* COV_CAN_TRANSITION_REQUEST */
  { /* #20 first request fail so start Loop that wait short time for transition \trace SPEC-1642, SPEC-1635, SPEC-1630 */
    CanHL_ApplCanTimerStart((uint8)CAN_LOOP_MAX); /* SBSW_CAN_HL38 */
    do
    { /* #30 HW check mode reached (LL) */
      transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
      CanHL_ApplCanTimerLoop((uint8)CAN_LOOP_MAX); /* COV_CAN_TRANSITION_REQUEST */
    } while ( transitionState != kCanOk ); /* COV_CAN_TRANSITION_REQUEST */
    CanHL_ApplCanTimerEnd ((uint8)CAN_LOOP_MAX); /* SBSW_CAN_HL38 */
  }
  if ( transitionState == kCanRequested ) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_TRANSITION_REQUEST */
  {
    /* #50 transition requested so remember request to repeat it asynchronous */
    Can_SetModeTransitionRequest(channel, transitionRequest); /* SBSW_CAN_HL01 */
    Can_SetBusOffTransitionRequest(channel, busOffRecovery); /* SBSW_CAN_HL01 */
    Can_SetRamCheckTransitionRequest(channel, doRamCheck); /* SBSW_CAN_HL01 */
  }
  return transitionState;
}

/****************************************************************************
| NAME:             CanHL_NotifyTransition
****************************************************************************/
/*
|<DataModelStart>| CanHL_NotifyTransition
Relation_Context:
# from Can_SetControllerMode() #
Wakeup
RamCheck
Relation:
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_NotifyTransition( CAN_CHANNEL_CANTYPE_FIRST uint8 canState, CanIf_ControllerModeType canIfState, uint8 transitionState )
{
  /* #10 if mode changed successful */
  if ( transitionState == kCanOk ) /* COV_CAN_TRANSITION_REQUEST */
  {
    /* #20 transition finished change internal state */
    Can_SetLogStatus(channel, (uint8)((Can_GetLogStatus(channel) & CAN_STATUS_MASK_NOMODE) | canState)); /* SBSW_CAN_HL02 */
    /* #30 remove transition request */
    Can_SetModeTransitionRequest(channel, kCanModeNone); /* SBSW_CAN_HL01 */
    /* #40 call notification CanIf_ControllerModeIndication() \trace SPEC-1726, SPEC-1644, SPEC-60446 */
    CanIf_ControllerModeIndication( (uint8)Can_GetCanToCanIfChannelMapping(channel), canIfState );
  }
  CAN_DUMMY_STATEMENT(transitionState); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}


/****************************************************************************
| NAME:             CanHL_WritePrepare
****************************************************************************/
/*
|<DataModelStart>| CanHL_WritePrepare
Relation_Context:
# from Can_Write() #
Relation:
TxFullCANSupport
MultiplexedTx, TxHwFifo
MultiplexedTx, HwCancelTx, IdenticalIdCancel
ChannelAmount
OneChOpt
TxBasicAmount
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_WritePrepare( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 calculate logical TX mailbox handle for FullCAN or for BasicCAN (Multiplexed TX) as start value */
  txPara->mailboxElement = 0u; /* PRQA S 2982 */ /* MD_MSR_RetVal */ /* SBSW_CAN_HL42 */
  txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u); /* SBSW_CAN_HL42 */
#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  if ( Can_GetMailboxType(txPara->mailboxHandle) != CAN_TX_FULLCAN_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#endif
  { /* #20 BasicCAN preparation - search for hardware and logical transmit handle and do cancellation */
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    CanObjectHandle mailboxElement_max;
    mailboxElement_max = Can_GetMailboxSize(txPara->mailboxHandle); /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    /* \trace SPEC-1677, SPEC-1672, SPEC-1679, SPEC-1673, SPEC-1671 */
    { /* #27 if normal or Mux Tx search from first to last element 0..1 or 0..3 for free object or one to be cancelled */
      CanObjectHandle mailboxElementFound;
      CanObjectHandle activeSendObjectFound;
      mailboxElementFound = mailboxElement_max;
      activeSendObjectFound = mailboxElement_max;
      for (txPara->mailboxElement = 0u; txPara->mailboxElement < mailboxElement_max; txPara->mailboxElement++) /* SBSW_CAN_HL42 */ /* SBSW_CAN_HL42 */
      { /* #30 over all multiplexed TX objects: find free mailbox or mailbox with identical ID */
        if (Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree)
        { /* #60 None Identical ID: else priority 1 - find free mailbox (no cancellation) */
          mailboxElementFound = txPara->mailboxElement;
          activeSendObjectFound = txPara->activeSendObject;
          break;
        }
        txPara->activeSendObject++; /* SBSW_CAN_HL42 */
      }
      if (mailboxElementFound == mailboxElement_max)
      { /* #90 no free or cancel mailbox found: return values set to valid element or to found element and cancel */
        txPara->mailboxElement = 0u; /* SBSW_CAN_HL42 */
        txPara->activeSendObject = CanHL_GetActiveSendObject(txPara->mailboxHandle, 0u); /* SBSW_CAN_HL42 */
      }
      else
      {
        txPara->mailboxElement = mailboxElementFound; /* SBSW_CAN_HL42 */
        txPara->activeSendObject = activeSendObjectFound; /* SBSW_CAN_HL42 */
      }
    } /* normal or mux tx */
#endif
  } /* end BasicCAN handling */
  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  /* #200 no special FullCAN handling needed */
} /* PRQA S 6080 */ /* MD_MSR_STMIF */



/****************************************************************************
| NAME:             CanHL_WriteStart
****************************************************************************/
/*
|<DataModelStart>| Can_WriteStart
Relation_Context:
# from Can_Write #
Relation:
GenericPreTransmit
TxHwFifo, GenericConfirmation
IDType
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, Can_ReturnType, STATIC_CODE) CanHL_WriteStart( CAN_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  Can_ReturnType retval = CAN_OK;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 free TX mailbox found so start transmission \trace SPEC-1744 */
  if (Can_GetActiveSendState(txPara->activeSendObject) == kCanBufferFree)
  {
    uint8 llretval;
    /* #20 remember PDU and send state to use it in Confirmation function \trace SPEC-1675 */
    Can_SetActiveSendPdu(txPara->activeSendObject, txPara->pdu.swPduHandle); /* SBSW_CAN_HL05 */
    Can_SetActiveSendState(txPara->activeSendObject, kCanBufferSend); /* SBSW_CAN_HL04 */
#if defined(C_ENABLE_PRETRANSMIT_FCT)
    /* call pretransmit function ----------------------------------------------- */
    Appl_GenericPreTransmit( (uint8)channel, &(txPara->pdu) );  /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL24 */
#endif
    /* #50 HW prepare transmission */
    CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    /* #60 Set ID, ID type and DLC in HW register depend on ID type */
    txPara->dlcRaw = MK_TX_DLC(CAN_LEN2DLC(txPara->pdu.length)); /* SBSW_CAN_HL42 */
#if defined(C_ENABLE_EXTENDED_ID)
# if defined(C_ENABLE_MIXED_ID)
    if ( ((txPara->pdu.id) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    {
      SET_PARASTRUCT_IDRAW_TX_STD(txPara, txPara->pdu.id); /* SBSW_CAN_HL42 */
    }
    else
# endif
    {
      SET_PARASTRUCT_IDRAW_TX_EXT(txPara, txPara->pdu.id); /* SBSW_CAN_HL42 */
    }
#else
    {
      SET_PARASTRUCT_IDRAW_TX_STD(txPara, txPara->pdu.id); /* SBSW_CAN_HL42 */ /* PRQA S 4491 */ /* MD_Can_IntegerCast */
    }
#endif
    /* set id, dlc in hardware */
    CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    if(txPara->pdu.sdu != NULL_PTR)
    { /* #70 Set CAN data in HW register (LL) - only when data pointer is not null \trace SPEC-1680, SPEC-1572, SPEC-1678, SPEC-60421 */
      txPara->CanMemCopySrcPtr = txPara->pdu.sdu; /* SBSW_CAN_HL42 */
      CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    }
    /* #80 HW start transmission (LL) */
    llretval = CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    /* HW finish transmission (LL) */
    CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST txPara); /* SBSW_CAN_HL49 */
    CAN_DUMMY_STATEMENT(llretval); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }
  else
  { /* #200 no free TX mailbox found so return busy - also in case cancellation (BasicCAN) was possible \trace SPEC-1754, SPEC-1764, SPEC-1747 */
    retval = CAN_BUSY;
  }
  return retval;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

/****************************************************************************
| NAME:             CanHL_GetActiveSendObject
****************************************************************************/
/*
|<DataModelStart>| CanHL_GetActiveSendObject
Relation_Context:
# from CanHL_InitXXX() #
Wakeup, OneChOpt, ChannelAmount
# from CanHL_WritePrepare #
# from CanHL_TxTaskCancelationHandling #
HwCancelTx
# from CanHL_CleanUpSendState #
# from Can_CancelTx #
TransmitCancellationAPI
# from CanHL_TxConfirmation #
Relation:
DevErrorDetect
TxFullAmount
TxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, CanObjectHandle, STATIC_CODE) CanHL_GetActiveSendObject( Can_HwHandleType mailboxHandle, Can_HwHandleType mailboxElement )
{
  /* ----- Local Variables ---------------------------------------------- */
  CanObjectHandle activeSendObject;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 get logical handle from generated indirection table */
  activeSendObject = (CanObjectHandle) Can_GetMailboxActiveSendObject(mailboxHandle) + mailboxElement;
#if (CAN_SAFE_BSW == STD_ON)
  if (activeSendObject >= (Can_HwHandleType)Can_GetSizeOfActiveSendObject()) /* CM_CAN_HL03 */ /* COV_CAN_GENDATA_FAILURE */
  { /* #20 secure SilentBSW */
    activeSendObject = ((Can_HwHandleType)Can_GetSizeOfActiveSendObject() - (Can_HwHandleType)1u);
# if (CAN_DEV_ERROR_REPORT == STD_ON)  
    Can_CallDetReportError(CAN_WRITE_ID, CAN_E_PARAM_HANDLE);
# endif
  }
#endif
  return activeSendObject;
}


#if defined(C_ENABLE_CAN_RAM_CHECK)
/****************************************************************************
| NAME:             CanHL_RamCheckMailboxNotification
****************************************************************************/
/*
|<DataModelStart>| CanHL_RamCheckMailboxNotification
Relation_Context:
# CanHL_InitXXX() #
Wakeup, OneChOpt, ChannelAmount, RamCheck
Relation:
TxFullCANSupport
RxFullCANSupport
RxBasicCANSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RamCheckMailboxNotification( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
{
  /* ----- Local Variables ---------------------------------------------- */

  /* ----- Implementation ----------------------------------------------- */
  /* #10 deactivate mailbox */
  Can_SetMailboxState(initPara->mailboxHandle, kCanFailed); /* SBSW_CAN_HL34 */
  /* #20 deactivate controller */
  Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_DEACTIVATE_CONTROLLER); /* SBSW_CAN_HL02 */
  /* #30 notify application about corrupt mailbox */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
  CanIf_RamCheckCorruptMailbox((uint8)Can_GetCanToCanIfChannelMapping(channel), initPara->mailboxHandle);
# else
#  if defined(C_ENABLE_NOTIFY_CORRUPT_MAILBOX) /* with Mailbox Notification */
  Appl_CanCorruptMailbox((uint8)channel, (initPara->hwObjHandle));
#  endif
# endif
}
#endif

/****************************************************************************
| NAME:             CanHL_InitBegin
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitBegin
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount
Relation:
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitBegin( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanFailed; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  if (CanLL_InitBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara) == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL31 */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
  {
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    /* #20 Execute pattern RamCheck */
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      initPara->isChRamCheckFail |= CAN_RAM_CHECK_BEGIN_REG_RESULT(channel, initPara); /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL31 */ /* COV_CAN_HARDWARE_FAILURE */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
    } 
#endif
    /* #30 Initialize controller registers (Begin section) */
    initOk = CanLL_InitBeginSetRegisters(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
  }
  return initOk;
}

#if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
/****************************************************************************
| NAME:             CanHL_InitTxFullCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitTxFullCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount, TxFullCANSupport
Relation:
RamCheck
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxFullCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
  CanObjectHandle activeSendObject;
# if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
# endif
  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  /* #10 iterate over all FullCAN TX */
  for (initPara->mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL36 */
  { /* #20 initialize FullCAN TX mailboxes */
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle); /* SBSW_CAN_HL36 */
    activeSendObject = CanHL_GetActiveSendObject(initPara->mailboxHandle, 0u);
    Can_SetActiveSendState(activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #30 RAM check for FullCAN TX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* SBSW_CAN_HL31 */ /* COV_CAN_HARDWARE_FAILURE */
    } 
# endif
    /* TX initialization */
    mailboxState = CanLL_InitMailboxTx(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxTxDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
# endif
  }
  return initOk;
}
#endif

/****************************************************************************
| NAME:             CanHL_InitTxBasicCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitTxBasicCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount
Relation:
MultiplexedTx, TxHwFifo
TxHwFifo, GenericConfirmation, IfTxBuffer
TxBasicAmount
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitTxBasicCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
  CanObjectHandle activeSendObject;
#if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
#endif

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  initPara->mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel); /* SBSW_CAN_HL36 */
#if defined(C_ENABLE_MULTIPLE_BASICCAN_TX)
  for (; initPara->mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL36 */
#endif
  { /* #10 iterate over all logical BasicCAN TX */
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    CanObjectHandle activeSendObjectStop;
#endif
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */ /* SBSW_CAN_HL36 */
    activeSendObject = CanHL_GetActiveSendObject(initPara->mailboxHandle, 0u);
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
    activeSendObjectStop = activeSendObject + Can_GetMailboxSize(initPara->mailboxHandle);
    for (; activeSendObject < activeSendObjectStop; activeSendObject++)
#endif
    { /* #20 initialize BasicCAN TX mailboxes */
      Can_SetActiveSendState(activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
    }
#if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #30 RAM check for BasicCAN TX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* COV_CAN_HARDWARE_FAILURE */ /* SBSW_CAN_HL31 */
    } 
#endif
    /* TX initialization */
    mailboxState = CanLL_InitMailboxTx(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
#if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxTxDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
#endif
  }
  return initOk;
}


#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
/****************************************************************************
| NAME:             CanHL_InitRxFullCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitRxFullCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount, RxFullCANSupport
Relation:
RamCheck
IDType
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxFullCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
# if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
# endif

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  for (initPara->mailboxHandle = Can_GetRxFullHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetRxFullHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL36 */
  { /* #10 iterate over all FullCAN RX mailboxes */
    initPara->hwObjHandle=Can_GetMailboxHwHandle(initPara->mailboxHandle); /* SBSW_CAN_HL36 */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #20 RAM check for FullCAN RX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* COV_CAN_HARDWARE_FAILURE */ /* SBSW_CAN_HL31 */
    } 
# endif
    /* #30 set ID for FullCAN RX mailboxes (LL) */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
    if ( (Can_GetMailboxIDValue(initPara->mailboxHandle) & CAN_ID_IDE_MASK) != CAN_ID_IDE_MASK) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */
    {
      initPara->idType = kCanIdTypeStd; /* SBSW_CAN_HL36 */
      SET_PARASTRUCT_IDRAW_RX_STD(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle)); /* SBSW_CAN_HL36 */ /* PRQA S 4491 */ /* MD_Can_IntegerCast */
    }
    else
#  endif
    {
      initPara->idType = kCanIdTypeExt; /* SBSW_CAN_HL36 */ /* PRQA S 2880 */ /* MD_MSR_Unreachable */
      SET_PARASTRUCT_IDRAW_RX_EXT(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle)); /* SBSW_CAN_HL36 */
    }
# else
    initPara->idType = kCanIdTypeStd; /* SBSW_CAN_HL36 */
    SET_PARASTRUCT_IDRAW_RX_STD(initPara, Can_GetMailboxIDValue(initPara->mailboxHandle)); /* SBSW_CAN_HL36 */ /* PRQA S 4491 */ /* MD_Can_IntegerCast */
# endif
    /* #40 initialize FullCAN RX mailboxes */
    mailboxState = CanLL_InitMailboxRxFullCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */

# if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxRxFullCanDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
# endif
  }
  return initOk;
}
#endif

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/****************************************************************************
| NAME:             CanHL_InitRxBasicCAN
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitRxBasicCAN
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount, RxBasicCANSupport
Relation:
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitRxBasicCAN( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;
  uint8 mailboxState;
# if defined(C_ENABLE_CAN_RAM_CHECK)
  uint8 isMbRamCheckFail;
# endif

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;
  for (initPara->mailboxHandle = Can_GetRxBasicHandleStart(canHwChannel); initPara->mailboxHandle < Can_GetRxBasicHandleStop(canHwChannel); initPara->mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */ /* SBSW_CAN_HL36 */ /* SBSW_CAN_HL36 */
  { /* #10 iterate over all BasicCAN RX mailboxes */
    initPara->hwObjHandle = Can_GetMailboxHwHandle(initPara->mailboxHandle); /* SBSW_CAN_HL36 */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #20 RAM check for BasicCAN RX mailboxes */
    isMbRamCheckFail = kCanFalse;
    if (initPara->doRamCheck == kCanExecuteRamCheck)
    {
      isMbRamCheckFail = CAN_RAM_CHECK_MAILBOX_RESULT(channel, initPara); /* COV_CAN_HARDWARE_FAILURE */ /* SBSW_CAN_HL31 */
    } 
# endif
    /* #30 initialize BasicCAN RX mailboxes */
    mailboxState = CanLL_InitMailboxRxBasicCan(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
    initOk &= mailboxState; /* all mailboxes OK - otherwise return fail */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
# if defined(C_ENABLE_CAN_RAM_CHECK)
    if( (Can_GetLogStatus(channel) & CAN_STATUS_INIT) != CAN_STATUS_INIT )
    { /* PowerOn */
      Can_SetMailboxState(initPara->mailboxHandle, mailboxState); /* SBSW_CAN_HL34 */
    }
    if( (isMbRamCheckFail == kCanTrue) || (Can_GetMailboxState(initPara->mailboxHandle) == kCanFailed) ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    { /* #45 deactivate corrupt mailbox */
      CanLL_InitMailboxRxBasicCanDeactivate(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      if (isMbRamCheckFail == kCanTrue)
      {  /* #50 notify application about corrupt mailbox and deactivate controller */
        CanHL_RamCheckMailboxNotification(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */
      }
    }
# endif
  }
  return initOk;
}
#endif

/****************************************************************************
| NAME:             CanHL_InitEnd_InitMode
****************************************************************************/
/*
|<DataModelStart>| CanHL_InitEnd_InitMode
Relation_Context:
# CanHL_ReInit() #
Wakeup, OneChOpt, ChannelAmount
Relation:
RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_InitEnd_InitMode( CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 initOk;

  /* ----- Implementation ----------------------------------------------- */
  initOk = kCanOk;

  /* #20 HW specific initialization end */
  initOk &= CanLL_InitEndSetRegisters(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_HL31 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  initOk &= CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST initPara ); /* SBSW_CAN_HL31 */ /* PRQA S 2985 */ /* MD_Can_ConstValue */
  return initOk;
}

#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_RxBasicCanPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_RxBasicCanPolling
Relation_Context:
# from Can_MainFunction_Read #
RxBasicCANSupport, RxPolling
Relation:
IndividualPolling
OneChOpt
ChannelAmount
RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxBasicCanPolling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  tCanTaskParaStruct taskPara;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check global pending flag (over all mailboxes - if available) */
  if(CanLL_RxBasicIsGlobalIndPending(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanTrue) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
  {
    /* #20 loop over all BasicCAN mailboxes */
    for (taskPara.mailboxHandle = Can_GetRxBasicHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetRxBasicHandleStop(canHwChannel); taskPara.mailboxHandle++) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
    { /* loop over all BasicCAN mailboxes with gap */
      taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#  if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
      /* #30 check individual polling flag */
      if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#  endif
      {
        /* #40 call LL handling */
        CanLL_RxBasicProcessPendings(CAN_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
      }
    }
  }
}
# endif /* C_ENABLE_RX_BASICCAN_POLLING */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_RxFullCanPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_RxFullCanPolling
Relation_Context:
# from Can_MainFunction_Read #
RxFullCANSupport, RxPolling
Relation:
IndividualPolling
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxFullCanPolling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  tCanTaskParaStruct taskPara;

  /* ----- Implementation ----------------------------------------------- */
  /* #10 check global pending flag (over all mailboxes - if available) */
  if(CanLL_RxFullIsGlobalIndPending(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanTrue) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
  {
    /* #20 loop over all FullCAN mailboxes */
    for (taskPara.mailboxHandle = Can_GetRxFullHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetRxFullHandleStop(canHwChannel); taskPara.mailboxHandle++ ) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
    {
      taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#  if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
      /* #30 check individual polling flag */
      if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#  endif
      {
        /* #40 call LL handling */
        CanLL_RxFullProcessPendings(CAN_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
      }
    }
  }
}
# endif /* C_ENABLE_RX_FULLCAN_POLLING */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS) || defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
/****************************************************************************
| NAME:             CanHL_RxMsgReceivedNotification
****************************************************************************/
/*
|<DataModelStart>| CanHL_RxMsgReceivedNotification
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
RxQueue, GenericPreCopy, MirrorMode
RxQueue, DevErrorDetect
RxQueue, CanFdSupport
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanHL_RxMsgReceivedNotification( CAN_CHANNEL_CANTYPE_FIRST CanRxInfoStructPtr rxStructPtr ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  /* ----- Local Variables ---------------------------------------------- */
# if !defined(C_ENABLE_RX_QUEUE) && (CAN_GENERIC_PRECOPY == STD_ON)
  Can_ReturnType generic_retval;
# endif
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 RX queue */
# if defined(C_ENABLE_RX_QUEUE)
  /**************************** RxQueue handling **********************************/
    /* #20 EXCLUSIVE_AREA_4 secure RxQueue data handling */
  SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
  if (Can_GetRxQueueInfo().Count < Can_GetSizeOfRxQueueBuffer()) /* COV_CAN_GENDATA_FAILURE */
  { /* #30 Queue not full: */
    /* #45 copy HRH, ID, DLC and data to RX queue */
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).Hrh = rxStructPtr->localMailboxHandle; /* SBSW_CAN_HL18 */
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).id  = rxStructPtr->localId; /* SBSW_CAN_HL18 */
    Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).dlc = rxStructPtr->localDlc; /* SBSW_CAN_HL18 */

#  if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (canRxQueueMaxDataSize < rxStructPtr->localDlc) /* CM_CAN_HL17 */ /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_PARAM_DLC;
    }
    else
#  endif
    {
      /* #46 copy data with VStdLib optimized copy routine */
      VStdMemCpy((void*)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().WriteIndex).data, (void*)rxStructPtr->pChipData, rxStructPtr->localDlc); /* SBSW_CAN_HL19 */ /* PRQA S 0312,0314,0316 */ /* MD_Can_NoneVolatilePointerCast,MD_Can_PointerVoidCast,MD_Can_PointerVoidCast */
    }
      /* #47 increase pointer to next queue element */
    Can_GetRxQueueInfo().Count++; /* SBSW_CAN_HL55 */
    if (Can_GetRxQueueInfo().WriteIndex < ((uint16)Can_GetSizeOfRxQueueBuffer() - (uint16)1u) )
    {
      Can_GetRxQueueInfo().WriteIndex++; /* SBSW_CAN_HL55 */
    }
    else
    {
      Can_GetRxQueueInfo().WriteIndex = 0u; /* CM_CAN_HL24 */ /* SBSW_CAN_HL55 */
    }
  }
#  if (CAN_DEV_ERROR_REPORT == STD_ON)
  else 
  { /* #50 Queue full: last message will be lost -> overrun in queue do not change ReadIndex to override latest message because inconsistency problem (currently reading queue) */
    errorId = CAN_E_RXQUEUE;
  }
#  endif
  SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
# else /* C_ENABLE_RX_QUEUE */
  /* #100 no RX queue */
  /* -------------------------- Interface + APPL Notifications --- */
    /* #110 call Appl_GenericPrecopy() depend on configuration and if mirror mode is active */
#  if (CAN_GENERIC_PRECOPY == STD_ON)
#   if defined(C_ENABLE_MIRROR_MODE)
  if (Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
  { /* do not call Appl_GenericPrecopy() in case mirror mode was disabled */
    generic_retval = CAN_OK;
  }
  else
#   endif
  {
    generic_retval = Appl_GenericPrecopy((uint8)channel, (rxStructPtr->localId & CAN_ID_MASK_IN_GENERIC_CALLOUT), rxStructPtr->localDlc, (Can_DataPtrType)rxStructPtr->pChipData);  /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL07 */
  }
  if (generic_retval == CAN_OK) /* \trace SPEC-15119 */
#  endif
  { /* #120 call CanIf_RxIndication() if mirror mode is no active or Appl_GenericPrecopy() return OK \trace SPEC-1726, SPEC-1688, SPEC-1687, SPEC-1687 */
    CanIf_RxIndication(rxStructPtr->localMailboxHandle, rxStructPtr->localId, rxStructPtr->localDlc, (Can_DataPtrType)rxStructPtr->pChipData); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL07 */
  }
# endif
  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return errorId;
}
#endif

#if defined(C_ENABLE_RX_QUEUE)
/****************************************************************************
| NAME:             CanHL_RxQueueExecution
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/*
|<DataModelStart>| CanHL_RxQueueExecution
Relation_Context:
# from Can_Mainfunction_Read #
RxQueue
Relation:
GenericPreCopy, OneChOpt, DevErrorDetect
GenericPreCopy, MirrorMode
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_RxQueueExecution( void )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  /* ----- Implementation ----------------------------------------------- */
  /* #10 Execute RxQueue (over all channels) */
  while ( Can_GetRxQueueInfo().Count != (uint16)0 )
  { /* #20 over all filled RxQueue elements */
# if (CAN_GENERIC_PRECOPY == STD_ON)
    Can_ReturnType generic_retval;
    CAN_CHANNEL_CANTYPE_LOCAL
    generic_retval = CAN_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
#  if !defined( C_SINGLE_RECEIVE_CHANNEL ) /* otherwise 'channel' is a define */
    channel = Can_GetMailboxController(Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).Hrh);
#   if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
    { /* #30 Check controller is valid */
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#   endif
#  endif
#  if defined(C_ENABLE_MIRROR_MODE)
    if (Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
    { /* #40 MirrorMode: only when mirror is activated for this controller */
      generic_retval = CAN_OK;
    }
    else
#  endif
    { /* #50 call Appl_GenericPrecopy() */
      generic_retval = Appl_GenericPrecopy( (uint8)channel,
                (Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).id & CAN_ID_MASK_IN_GENERIC_CALLOUT),
                Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).dlc,
                (Can_DataPtrType)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).data ); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL06 */
    }
    if (generic_retval == CAN_OK)
# endif
    { /* #60 call CanIf_RxIndication() if Appl_GenericPrecopy() return OK or no generic precopy is used \trace SPEC-1726, SPEC-1688, SPEC-1687, SPEC-1687 */
      CanIf_RxIndication( Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).Hrh, /* SBSW_CAN_HL06 */
              Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).id,
              Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).dlc,
              (Can_DataPtrType)Can_GetRxQueueBuffer(Can_GetRxQueueInfo().ReadIndex).data ); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */
    }
    /* #70 EXCLUSIVE_AREA_4 secure RxQueue handling */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_4();
    /* #80 get next RxQueue element pointer */
    if (Can_GetRxQueueInfo().ReadIndex >= ((uint16)Can_GetSizeOfRxQueueBuffer() - (uint16)1u) ) /* CM_CAN_HL25 */
    {
      Can_GetRxQueueInfo().ReadIndex = 0u; /* CM_CAN_HL25 */ /* SBSW_CAN_HL55 */
    }
    else
    {
      Can_GetRxQueueInfo().ReadIndex++; /* SBSW_CAN_HL55 */
    }
    Can_GetRxQueueInfo().Count--; /* SBSW_CAN_HL55 */
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_4();
  }
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_READ_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}
#endif


/****************************************************************************
| NAME:             CanLL_WriteReg32
****************************************************************************/
/*
|<DataModelStart>| CanLL_WriteReg32
Relation_Context:
# CanLL_InitBeginSetRegisters() #
RamCheck
Relation:
OneChOpt, RamCheck
ChannelAmount, RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, uint8, STATIC_CODE) CanLL_WriteReg32( CAN_CHANNEL_CANTYPE_FIRST CanChipMsgPtr32 regPtr, uint32 value, uint32 readMask, CanInitParaStructPtr initPara )
{
  uint8 result = kCanFalse;
  /* #10 write register value */
  *regPtr = value; /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    /* #20 read back value for RamCheck */
    volatile uint32 readBack;
    readBack = *regPtr;
    if ((readBack & readMask) != (value & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue;  /* PRQA S 2982 */ /* MD_Can_2982_LL */
    }
    CAN_RAM_CHECK_READ_BACK_RESULT(channel)
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return result;
}

# if defined(C_ENABLE_USER_MODE_APPL) || defined(C_ENABLE_USER_MODE_OS)
/****************************************************************************
| NAME:             CanLL_WriteProtectedReg32
****************************************************************************/
/*
|<DataModelStart>| CanLL_WriteProtectedReg32
Relation_Context:
# CanHL_InitXXX() #
RamCheck
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_WriteProtectedReg32(CAN_CHANNEL_CANTYPE_FIRST uint16 area, CanChipMsgPtr32 regPtr, uint32 value, uint32 readMask, CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  uint8 result = kCanFalse;
  /* #10 write register value */
  CAN_WRITE_PROTECTED_REG32(area, regPtr, value); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_HL35 */
# if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) 
  if (initPara->doRamCheck == kCanExecuteRamCheck)
  {
    /* #20 read back value for RamCheck */
    volatile uint32 readBack;
    readBack = CAN_READ_PROTECTED_REG32(area, regPtr); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_HL35 */
    if ((readBack & readMask) != (value & readMask)) /* COV_CAN_HARDWARE_FAILURE */
    {
      /* #30 return issue when read back value differs */
      result = kCanTrue; /* PRQA S 2982 */ /* MD_Can_2982_LL */
    }
    CAN_RAM_CHECK_READ_BACK_RESULT(channel)
    initPara->isChRamCheckFail |= result; /* SBSW_CAN_HL36 */
  }
# else
  CAN_DUMMY_STATEMENT(readMask);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller);/* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  CAN_DUMMY_STATEMENT(area);      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return result;
} /* PRQA S 6060 */ /* MD_MSR_STPAR */
# endif /* User Mode */

/**********************************************************************************************************************
 *  CanLL_InitBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitBegin
Relation_Context:
# CanHL_InitBegin() #
OneChOpt, ChannelAmount
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBegin( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{

  CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  return(kCanOk);
}
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK_EXTENDED )
/**********************************************************************************************************************
 *  CanLL_InitBeginIsRegisterCorrupt
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitBeginIsRegisterCorrupt
Relation_Context:
# CanHL_InitBegin() #
OneChOpt, ChannelAmount, RamCheck
Relation:
OneChOpt, RamCheck,
ChannelAmount, HardwareLoopCheck, RamCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
/* PRQA S 0303 QAC_Can_0303_IsRegCorrupt */ /* MD_Can_HwAccess */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginIsRegisterCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{ 
  vuint8 indx;
  vuint8 ret_val;
  

# if defined ( C_MULTIPLE_RECEIVE_CHANNEL )
  assertUser(channel < kCanNumberOfChannels, kCanAllChannels, kCanErrorChannelHdlTooLarge); /* COV_CAN_GENDATA_FAILURE */
# endif

  /* ----- Implementation ----------------------------------------------- */

  /* assume the registers are not corrupt */
  ret_val = kCanFalse;

  /* Initialization */
  if ((Cn->CCCR & kCanCCCR_INIT) != kCanCCCR_INIT ) /* If Init-Bit is not set */
  {
    Cn->CCCR  = kCanCCCR_INIT; /* SBSW_CAN_LL__100 */ 
    CanLL_ApplCanTimerStart(kCanLoopClockStop ); /* PRQA S 2842 */ /* MD_Can_Assertion */ /* SBSW_CAN_LL__101 */
    while( ((Cn->CCCR & kCanCCCR_INIT) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopClockStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
    {/* Assure that INIT has been accepted. */}
    CanLL_ApplCanTimerEnd( kCanLoopClockStop ); /* SBSW_CAN_LL__101 */
  }

  /* Configuration Change Enable */
  Cn->CCCR |= kCanCCCR_CCE; /* SBSW_CAN_LL__100 */ 
  CanLL_ApplCanTimerStart(kCanLoopClockStop ); /* PRQA S 2842 */ /* MD_Can_Assertion */ /* SBSW_CAN_LL__101 */
  while( ((Cn->CCCR & kCanCCCR_CCE) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopClockStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
  {/* Assure that CCE has been accepted. */}
  CanLL_ApplCanTimerEnd( kCanLoopClockStop ); /* SBSW_CAN_LL__101 */
  
  Cn->IE  = 0x00000000u; /* SBSW_CAN_LL__100 */  /* Disable MCAN Interrupts */
  
  /* #10 Iterate test patterns */
  for(indx = 0x00u; indx < 4u; indx++)
    { 
      /* #20 Write pattern to controller register */
      
      /* CC Control Register (CCCR) */
      Cn->CCCR = (((kCanRegCheckMaskCCCR ^ kCanRegCheckMaskCCCR_RP) & CanRegCheckValues32bit[indx])|kCanRegCheckMaskCCCR_RP); /* SBSW_CAN_LL__100 */ 
       
      /* Data Bit Timing & Prescaler Register (FBTP),RP */ 
      Cn->FBTP = (kCanRegCheckMaskFBTP & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */ 

      /* RAM Watchdog (RWD), RP */
      Cn->RWD  = (kCanRegCheckMaskRWD  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */       
      /* Bit Timing and Prescaler Register (BTP/NBTP), RP */
      Cn->BTP = (kCanRegCheckMaskBTP  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      
      /* Timestamp Counter Configuration (TSCC), RP */
      Cn->TSCC = (kCanRegCheckMaskTSCC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */  /*! Not supported but initialized */
      /* Timeout Counter Configuration (TOCC), RP */
      Cn->TOCC = (kCanRegCheckMaskTOCC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */  /*! Not supported but initialized */
      /* Timeout Counter Value (TOCV), RC */ 
      
      /* Transmitter Delay Compensation Register (TDCR), RP */
      {
#  if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */ 
        Cn->TDCR = (kCanRegCheckMaskTDCR  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
#  endif /* MCAN Core Release < 0x0310UL */
      }
    
      /* Global Filter Configuration (GFC),RP */
      Cn->GFC = (kCanRegCheckMaskGFC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Standard ID Filter Configuration (SIDFC), RP */
      Cn->SIDFC = (kCanRegCheckMaskSIDFC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Extended ID Filter Configuration (XIDFC), RP */
      Cn->XIDFC = (kCanRegCheckMaskXIDFC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Extended ID AND Mask (XIDAM), RP */
      Cn->XIDAM = (kCanRegCheckMaskXIDAM  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Rx FIFO 0 Configuration (RXF0C), RP */
      Cn->RXF0C.R = (kCanRegCheckMaskRXF0C  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Rx FIFO 0 Acknowledge (RXF0A), RW */
      Cn->RXF0A = (kCanRegCheckMaskRXF0A  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Rx Buffer Configuration (RXBC), RP */ 
      Cn->RXBC = (kCanRegCheckMaskRXBC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Rx FIFO 1 Configuration (RXF1C), RP */
      Cn->RXF1C.R = (kCanRegCheckMaskRXF1C  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Rx FIFO 1 Acknowledge (RXF1A), RW */
      Cn->RXF1A = (kCanRegCheckMaskRXF1A  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Rx Buffer / FIFO Element Size Configuration (RXESC), RP */ 
      Cn->RXESC.R = (kCanRegCheckMaskRXESC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Tx Buffer Configuration (TXBC) */
      Cn->TXBC = (kCanRegCheckMaskTXBC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Tx Buffer Element Size Configuration (TXESC) */ 
      Cn->TXESC = (kCanRegCheckMaskTXESC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */
      /* Tx Buffer Transmission Interrupt Enable (TXBTIE), RW */
      Cn->TXBTIE = (kCanRegCheckMaskTXBTIE  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */  /* PRQA S 2986,4558 */ /* MD_Can_4558_RHsideEffect */
      /* Tx Event FIFO Configuration (TXEFC) */
      Cn->TXEFC = (kCanRegCheckMaskTXEFC  & CanRegCheckValues32bit[indx]); /* SBSW_CAN_LL__100 */  /* Not supported but initialized */
    
      /* #30 Check if register values are valid  */ 
      if(
          ( (Cn->FBTP    & kCanRegCheckMaskFBTP)  != (kCanRegCheckMaskFBTP  & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->CCCR & (kCanRegCheckMaskCCCR ^ kCanRegCheckMaskCCCR_RP))!= ((kCanRegCheckMaskCCCR ^ kCanRegCheckMaskCCCR_RP) & CanRegCheckValues32bit[indx]) ) ||
          ( (Cn->BTP     & kCanRegCheckMaskBTP)   != (kCanRegCheckMaskBTP   & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->CCCR & (kCanCCCR_CCE | kCanCCCR_INIT))                     != (kCanCCCR_CCE | kCanCCCR_INIT)) ||
          ( (Cn->RWD     & kCanRegCheckMaskRWD)   != (kCanRegCheckMaskRWD   & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->TSCC    & kCanRegCheckMaskTSCC)  != (kCanRegCheckMaskTSCC  & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->TOCC    & kCanRegCheckMaskTOCC)  != (kCanRegCheckMaskTOCC  & CanRegCheckValues32bit[indx]))   ||
# if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
          ( (Cn->TDCR    & kCanRegCheckMaskTDCR)  != (kCanRegCheckMaskTDCR  & CanRegCheckValues32bit[indx]))   ||
# endif /* MCAN Core Release < 0x0310UL */ 
          ( (Cn->GFC     & kCanRegCheckMaskGFC)   != (kCanRegCheckMaskGFC   & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->SIDFC   & kCanRegCheckMaskSIDFC) != (kCanRegCheckMaskSIDFC & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->XIDFC   & kCanRegCheckMaskXIDFC) != (kCanRegCheckMaskXIDFC & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->XIDAM   & kCanRegCheckMaskXIDAM) != (kCanRegCheckMaskXIDAM & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->RXF0C.R & kCanRegCheckMaskRXF0C) != (kCanRegCheckMaskRXF0C & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->RXF0A   & kCanRegCheckMaskRXF0A) != (kCanRegCheckMaskRXF0A & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->RXBC    & kCanRegCheckMaskRXBC)  != (kCanRegCheckMaskRXBC  & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->RXF1C.R & kCanRegCheckMaskRXF1C) != (kCanRegCheckMaskRXF1C & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->RXF1A   & kCanRegCheckMaskRXF1A) != (kCanRegCheckMaskRXF1A & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->RXESC.R & kCanRegCheckMaskRXESC) != (kCanRegCheckMaskRXESC & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->TXBC    & kCanRegCheckMaskTXBC)  != (kCanRegCheckMaskTXBC  & CanRegCheckValues32bit[indx]))   ||
          ( (Cn->TXESC   & kCanRegCheckMaskTXESC) != (kCanRegCheckMaskTXESC & CanRegCheckValues32bit[indx]))   || 
          ( (Cn->TXBTIE  & kCanRegCheckMaskTXBTIE)!= (kCanRegCheckMaskTXBTIE& CanRegCheckValues32bit[indx]))   ||  /* PRQA S 2986,4558 */ /* MD_Can_4558_RHsideEffect */
          ( (Cn->TXEFC   & kCanRegCheckMaskTXEFC) != (kCanRegCheckMaskTXEFC & CanRegCheckValues32bit[indx]))    ) /* COV_CAN_HARDWARE_FAILURE */
          {
            ret_val = kCanTrue; 
          }
    
      /* We need this extra case in order to check TDCR if Dynamic MCAN rev is configured for configuration with MCAN rev 3.0 but run on a > 3.0 target*/
    }

  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(ret_val); 
} /* PRQA S 6010,6030 */ /* MD_MSR_STPTH,MD_MSR_STCYC */
/* PRQA  L:QAC_Can_0303_IsRegCorrupt */
/* CODE CATEGORY 4 END */


#endif /* C_ENABLE_CAN_RAM_CHECK_EXTENDED */

/**********************************************************************************************************************
 *  CanLL_InitBeginSetRegisters
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitBeginSetRegisters
Relation_Context:
# CanHL_InitBegin() #
OneChOpt, ChannelAmount
Relation:
OneChOpt
ChannelAmount, StatusPolling
ChannelAmount, TxPolling
ChannelAmount, IndividualPolling
RxFullCANSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitBeginSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  vuint8 result;
  /* #10 set MCAN configuration registers */
  result = CanLL_SetAllRegister(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_LL__110 */ /* fill in all CAN registers */
  /* #20 set MCAN additional platform specific configuration registers */
  CanLL_SetExtraRegister(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_LL__110 */
  /* #30 set MCAN filter tables */
  result &= CanLL_SetAllFilter(CAN_CHANNEL_CANPARA_FIRST initPara); /* SBSW_CAN_LL__110 */ /* fill in CAN Message RAM */



  return(result);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMailboxTx
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanHL_InitMailboxTx
Relation_Context:
# CanHL_InitTxFullCAN() #
OneChOpt, ChannelAmount
# CanHL_InitTxBasicCAN() #
OneChOpt, ChannelAmount
Relation:
OneChOpt
ChannelAmount, MultiplexedTx
ChannelAmount, TxPolling, IndividualPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxTx( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* using CanLL_WriteReg32(&initPara) just to satisfy test is intentionally omitted */
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
  CanObjectHandle mboxElm = 0; /* PRQA S 2981 */ /* MD_Can_RedundantInit */
  for(mboxElm=0; mboxElm < Can_GetMailboxSize(initPara->mailboxHandle); mboxElm++)
#endif
  {
    /* #10 get the Message RAM location */
#if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
    initPara->pTXB =  (tTXBEType*) &ShmTXB(initPara->hwObjHandle + mboxElm); /* PRQA S 0303,0310,312,1891,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__109 */ 
#else
    initPara->pTXB =  (tTXBEType*) &ShmTXB(initPara->hwObjHandle);           /* PRQA S 0303,0310,312,1891,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__109 */ 
#endif
#if( CAN_SAFE_BSW == STD_ON ) 
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
    if( ((vuint32)initPara->pTXB < (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || ((vuint32)&ShmTXB(initPara->hwObjHandle + mboxElm +1u) >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) ) /* PRQA S 0303,4391 */ /* MD_Can_HwAccess,MD_Can_IntegerCast */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
# else
    if( ((vuint32)initPara->pTXB < (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || ((vuint32)&ShmTXB(initPara->hwObjHandle + 1u)          >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) ) /* PRQA S 0303,4391 */ /* MD_Can_HwAccess,MD_Can_IntegerCast */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
# endif
    { /* SilentBSW check */
      initPara->pTXB = &ShmTXB(0u); /* PRQA S 0303,4391,2985 */ /* MD_Can_HwAccess,MD_Can_IntegerCast,MD_Can_ConstValue */ /* SBSW_CAN_LL__109 */ 
      Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
    }
#endif
    /* #20 reset FD flags and Dlc */
    initPara->pTXB->T1 = 0x00000000UL;                     /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__103 */
#if defined( C_ENABLE_INDIVIDUAL_POLLING )
    if(Can_IsMailboxIndivPolling(initPara->mailboxHandle))   /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    { /* poll this object */
    }
    else
#endif
    {
#if !defined( C_ENABLE_TX_POLLING ) || defined( C_ENABLE_INDIVIDUAL_POLLING )
      /* #30 enable mailbox Tx interrupt if not in polling mode */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
      initPara->txbtie |= (vuint32)(kCanACTIVE << (initPara->hwObjHandle + mboxElm));  /* allow CAN Tx Buffer confirmation and cancelation INTs */ /* SBSW_CAN_LL__109 */ 
# else
      initPara->txbtie |= (vuint32)(kCanACTIVE << (initPara->hwObjHandle));            /* allow CAN Tx Buffer confirmation and cancelation INTs */ /* SBSW_CAN_LL__109 */ 
# endif
#endif
    }
  } /* end for loop */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

#if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxTxDeactivate
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanHL_InitMailboxTxDeactivate
Relation_Context:
# CanHL_InitTxFullCAN() #
OneChOpt, ChannelAmount
# CanHL_InitTxBasicCAN() #
OneChOpt, ChannelAmount
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxTxDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
{
  /* #10 no actions necessary */
  CAN_CHANNEL_DUMMY_STATEMENT;   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 4 END */
#endif


#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCan
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxFullCan
Relation_Context:
# CanHL_InitRxFullCAN() #
OneChOpt, ChannelAmount, RxFullCANSupport
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxFullCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* using CanLL_WriteReg32(&initPara) just to satisfy test is intentionally omitted */
  /* #10 no actions necessary */
  CAN_DUMMY_STATEMENT(initPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxFullCanDeactivate
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxFullCanDeactivate
Relation_Context:
# CanHL_InitRxFullCAN() #
OneChOpt, ChannelAmount, RxFullCANSupport, RamCheck
Relation:
OneChOpt
ChannelAmount, IDType
DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxFullCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
{
  vuint32 tmpVal;

#  if defined( C_ENABLE_STD_ID ) && (kCanNumberOfStandardFilter > 0)  
  for(tmpVal = 0; tmpVal < (Can_GetCanSIDFC_LSSOfCanSIDFC(canHwChannel)); tmpVal++)  /* SBSW_CAN_LL__109 */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    /*If the Filter Is Configured to the RxBuffer, And if the SFID2 defined offset to the Rx Buffer Start Adress matches the hwObjHandle*/
    if ( (((vuint32) (ShmSIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal)).S0 & kCanSFE_SFEC) == kCanSFE_SFEC ) && /* PRQA S 0303 */ /* MD_Can_HwAccess */
         (((vuint32) (ShmSIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal)).S0 & kCanSFE_SFID2_RBSA) == (vuint32)(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))) ) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_DISABLE_RX_MAILBOX */
    { /* Disable the filter element*/
#   if( CAN_SAFE_BSW == STD_ON )
      if( ((vuint32)&ShmSIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal).S0 <  (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
          ((vuint32)&ShmSIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal).S0 >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) )  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
      { /* SilentBSW check */
        Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
      }
      else
#   endif
      {
        (ShmSIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal)).S0 |= kCanSFE_SFTRes; /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__103 */
      }
    }
  }
#  endif  /* STD_FILTER */

#  if defined(C_ENABLE_EXTENDED_ID) && (kCanNumberOfExtendedFilter > 0)
  for(tmpVal = 0; tmpVal < (Can_GetCanXIDFC_LSEOfCanXIDFC(canHwChannel)); tmpVal++)  /* SBSW_CAN_LL__109 */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { 
    if ( (((vuint32) (ShmXIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal)).F0 & kCanEFE_EFEC)       == kCanEFE_EFEC ) && /* PRQA S 0303 */ /* MD_Can_HwAccess */
         (((vuint32) (ShmXIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal)).F1 & kCanEFE_EFID2_RBSA) == (vuint32)(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))) ) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_DISABLE_RX_MAILBOX */
    {/* Disable the Filter element */
#   if( CAN_SAFE_BSW == STD_ON )
      if( ((vuint32)&ShmXIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal).F0 <  (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
          ((vuint32)&ShmXIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal).F0 >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) )  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
      { /* SilentBSW check */
        Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
      }
      else
#   endif
      {
        (ShmXIDF(initPara->hwObjHandle - (vuint32)CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel) + tmpVal)).F0 &= ~kCanEFE_EFEC; /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__103 */
      }
    }
  }
#  endif /* EXT_FILTER */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* avoid qac-9.3.1-3673 "parameter could be const" */
}
/* CODE CATEGORY 4 END */
# endif

#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCan
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxBasicCan
Relation_Context:
# CanHL_InitRxBasicCAN() #
OneChOpt, ChannelAmount, RxBasicCANSupport
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitMailboxRxBasicCan( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )
{
  /* using CanLL_WriteReg32(&initPara) just to satisfy test is intentionally omitted */
  /* #10 no actions necessary */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

# if ((defined( C_ENABLE_CAN_RAM_CHECK )))
/**********************************************************************************************************************
 *  CanLL_InitMailboxRxBasicCanDeactivate
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMailboxRxBasicCanDeactivate
Relation_Context:
# CanHL_InitRxBasicCAN() #
OneChOpt, ChannelAmount, RxBasicCANSupport, RamCheck
Relation:
OneChOpt
ChannelAmount, DevErrorDetect, IDType
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMailboxRxBasicCanDeactivate( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
{
  vuint32 tmpVal;

#  if defined( C_ENABLE_STD_ID ) && (kCanNumberOfStandardFilter > 0)  /* at least one std filter is available */
  /* #10 disable STD filters */
  for(tmpVal = 0; tmpVal < (Can_GetCanSIDFC_LSSOfCanSIDFC(canHwChannel)); tmpVal++) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { 
    /* If Filter is configured to ( RXFIFO0 OR RXFIFO1) AND The filter offset matches the HwObjHandle*/
    if ( ( (((vuint32) (ShmSIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal)).S0 & kCanSFE_SFEC_F0) == kCanSFE_SFEC_F0 )   || /* PRQA S 0303 */ /* MD_Can_HwAccess */
           (((vuint32) (ShmSIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal)).S0 & kCanSFE_SFEC_F1) == kCanSFE_SFEC_F1 ) )    /* PRQA S 0303 */ /* MD_Can_HwAccess */
       ) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_DISABLE_RX_MAILBOX */
    { /* Disable the filter element*/
#    if( CAN_SAFE_BSW == STD_ON )
      if( ((vuint32)&ShmSIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal).S0 <  (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
          ((vuint32)&ShmSIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal).S0 >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) )  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
      { /* SilentBSW check */
        Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
      }
      else
#    endif
      {
      (ShmSIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal)).S0 |= kCanSFE_SFTRes; /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__103 */
      }
    }
  }
#  endif

#  if defined(C_ENABLE_EXTENDED_ID) && (kCanNumberOfExtendedFilter > 0)
  /* #20 disable EXT filters */
  for(tmpVal = 0; tmpVal < Can_GetCanXIDFC_LSEOfCanXIDFC(canHwChannel); tmpVal++) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { 
    /* If Filter is configured to ( RXFIFO0 OR RXFIFO1) AND The filter offset matches the HwObjHandle*/
    if ( ( (((vuint32) (ShmXIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal)).F0 & kCanEFE_EFEC_F0) == kCanEFE_EFEC_F0 )   || /* PRQA S 0303 */ /* MD_Can_HwAccess */
           (((vuint32) (ShmXIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal)).F0 & kCanEFE_EFEC_F1) == kCanEFE_EFEC_F1 ) )    /* PRQA S 0303 */ /* MD_Can_HwAccess */
       ) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_DISABLE_RX_MAILBOX */
    { /* Disable the filter element*/
#    if( CAN_SAFE_BSW == STD_ON )
      if( ((vuint32)&ShmXIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal).F0 <  (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
          ((vuint32)&ShmXIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal).F0 >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) )  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
      { /* SilentBSW check */
        Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
      }
      else
#    endif
      {
        (ShmXIDF(initPara->hwObjHandle-(vuint32)CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) + tmpVal)).F0 &= ~kCanEFE_EFEC; /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__103 */
      }
    }
  }
#  endif
}
/* CODE CATEGORY 4 END */
# endif
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */


/**********************************************************************************************************************
 *  CanLL_InitEndSetRegisters
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitEndSetRegisters
Relation_Context:
# CanHL_InitEnd_InitMode() #
OneChOpt, ChannelAmount
Relation:
ChannelAmount, GlobalInitPostProcess
ChannelAmount, IDType
RxBasicCANSupport
RxFullCANSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEndSetRegisters( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{

  /* #10 set STD filter configuration */
#if defined( C_ENABLE_STD_ID )
  /*  11-bit standard Message ID filtering */
# if( kCanNumberOfStandardFilter > 0 ) 
  /* BasicCAN filter available */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->SIDFC), (vuint32)( ((vuint32)(initPara->stdFeCount) << 16) | ((vuint32)Can_GetCanSIDFC_FLSSAOfCanSIDFC(canHwChannel)) ) , kCanRegCheckMaskSIDFC, initPara);     /* SBSW_CAN_LL__100 */     /* PRQA S 0303 */ /* MD_Can_HwAccess */
# else
  /* No BasicCAN filter available */
#  if( kCanNumberOfRxObjects > 0 ) /* COV_CAN_COMPATIBILITY */
  /* FullCAN filter available */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->SIDFC), (vuint32)( ((vuint32)(initPara->stdFeCount) << 16) | (((vuint32)(Can_GetCanShmAdr_SIDFAOfCanShmAdr(canHwChannel)) & 0x0000FFFFUL)) ) , kCanRegCheckMaskSIDFC, initPara);     /* SBSW_CAN_LL__100 */     /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->SIDFC), (vuint32)(0x00000000UL) , kCanRegCheckMaskSIDFC, initPara);    /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */  /* LSS zero means no standard filters at all available */
#  endif
# endif
#endif

  /* #20 set EXT filter configuration */
#if defined(C_ENABLE_EXTENDED_ID) 
  /*  29-bit extended Message ID filtering */
# if (kCanNumberOfExtendedFilter > 0) /* COV_CAN_COMPATIBILITY */
  /* BasicCAN filter available */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->XIDFC), (vuint32)( ((vuint32)(initPara->extFeCount) << 16) | ((vuint32)(Can_GetCanXIDFC_FLESAOfCanXIDFC(canHwChannel))) ), kCanRegCheckMaskXIDFC, initPara);     /* SBSW_CAN_LL__100 */     /* PRQA S 0303 */ /* MD_Can_HwAccess */
# else
  /* No BasicCAN filter available */
#  if( kCanNumberOfRxObjects > 0 ) /* COV_CAN_COMPATIBILITY */
  /* FullCAN filter available */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->XIDFC), (vuint32)( ((vuint32)(initPara->extFeCount) << 16) | ((vuint32)((Can_GetCanShmAdr_XIDFAOfCanShmAdr(canHwChannel)) & 0x0000FFFFUL)) ), kCanRegCheckMaskXIDFC, initPara);  /* PRQA S 0303 */ /* MD_Can_HwAccess */
  
#  else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->XIDFC), (vuint32)(0x00000000UL), kCanRegCheckMaskXIDFC, initPara);   /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* LSE zero means no extended filters at all available */
#  endif
# endif
#endif
   
  /* #30 set Interrupt configuration */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TXBTIE), (vuint32)(initPara->txbtie), kCanRegCheckMaskTXBTIE, initPara); /* allow CAN Tx Buffer confirmation INTs */ /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ 
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TXBCIE), (vuint32)(initPara->txbtie), kCan_ALL_ONE, initPara); /* allow CAN Tx Buffer cancellation INTs */ /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ 

  Can_GetCanIntEnable(channel) = initPara->ie;  /* SBSW_CAN_LL__112 */  /* keep for usage within ISR and SetControllerMode*/
  if(initPara->ie > 0UL)   /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {  
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->IE), (vuint32)(initPara->ie), kCanRegCheckMaskIE, initPara); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ 
  }
  else
  { 
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->IE), (vuint32)kCanIE_DISABLE_ALL, kCanRegCheckMaskIE, initPara); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ 
  }
      
#if ( CAN_BOSCH_ERRATUM_012 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
  /* The Protocol Exception Event is signalled via PSR.ACT (and PSR.PXE if MCAN Rev. >=3.1.0 ).
     Thus the status has to be monitored */
  {
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->IE), (vuint32)(Cn->IE | (kCanIR_TOO)), kCanRegCheckMaskIE, initPara); /* Enable timeout interrupt */ /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ 
  }
#endif

  /* #40 handle application callback */
#if defined( C_ENABLE_INIT_POST_PROCESS )
  /* The post processing function is called within the initialization mode of the CAN controller.
     The application can directly overwrite existing configuration in the CAN controller.
     Example: overwriting the baudrate settings with dynamic values, necessary macros are provided in the LL part */
  ApplCanInitPostProcessing(CAN_HW_CHANNEL_CANPARA_ONLY);
#endif
  CAN_MSG_RAM_SYNC(); /* PRQA S 1006 */ /* MD_Can_1006_inlineASM */
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitEnd
Relation_Context:
# CanHL_InitEnd_InitMode() #
OneChOpt, ChannelAmount
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitEnd( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara ) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  /* After resetting CCCR[INIT] the Bit Stream Processor (BSP) synchronizes itself to the data transfer 
     on the CAN bus by waiting for Bus_Idle (sequence of 11 consecutive recessive bits) .
     CCCR[CCE] is automatically reset when CCCR[INIT] is reset. */
  /* CCCR_: INIT, CCE, ASM, CSR, MON, DAR, TEST disabled (automated retransmission is enabled) */
  /* #10 return initialization status */
  /* try to avoid "3673  QAC9-CORE: hardware specific (param could be const)" */
  CAN_CHANNEL_DUMMY_STATEMENT;   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(initPara); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return(initPara->isInitOk);

}
/* CODE CATEGORY 4 END */

#if defined( C_ENABLE_CAN_RAM_CHECK )
/**********************************************************************************************************************
 *  CanLL_InitIsMailboxCorrupt
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitIsMailboxCorrupt
Relation_Context:
# CanHL_InitXXX() #
OneChOpt, ChannelAmount
Relation:
RamCheck
TxFullCANSupport
RxFullCANSupport, RxBasicCANSupport
DevErrorDetect
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_InitIsMailboxCorrupt( CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara )  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8   ret_val;
  volatile vuint32* p2Shm = V_NULL; /* PRQA S 2981 */ /* MD_Can_RedundantInit */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || (CAN_RX_BASICCAN_OBJECTS == STD_ON)
  vuint32 mboxElm;
# endif

  ret_val = kCanFalse; /* Mailbox is not corrupt */

  /* #10 identify Message RAM location */
# if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) 
  if(initPara->hwObjHandle < CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))
# elif defined( C_ENABLE_RX_BASICCAN_OBJECTS ) 
  if(initPara->hwObjHandle < CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel))
# endif
  { /* 32 Tx Buffers */
    p2Shm = (vuint32*) (pShmTXB(initPara->hwObjHandle));     /* PRQA S 0303,0310,312,1891,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_1891_LL,MD_Can_IntegerCast */
  }

  if(p2Shm == V_NULL)
  {
# if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) 
    if(initPara->hwObjHandle < CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel))
    { /* 64 Rx Buffers */
      p2Shm = (vuint32*) (ShmRXB( ((CanObjectHandle)(initPara->hwObjHandle - CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel))) )); /* PRQA S 0303,0310,312,1891,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_1891_LL,MD_Can_IntegerCast */
    }
    else
# endif
    { /* 2 FIFOs */
      if(initPara->hwObjHandle == CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        p2Shm = (vuint32*) (ShmRXF0( (CanObjectHandle)0 ));   /* PRQA S 0303,0310,312,2985,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_ConstValue,MD_Can_IntegerCast */
      }
      else
      {
        if(initPara->hwObjHandle == (CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) +1u) ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
        {
          p2Shm = (vuint32*) (ShmRXF1( (CanObjectHandle)0 ));  /* PRQA S 0303,0310,312,2985,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_ConstValue,MD_Can_IntegerCast */
        }
      }
    }
  }

  {
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || (CAN_RX_BASICCAN_OBJECTS == STD_ON)
    mboxElm = 0;
    do 
    {
# endif
      assertHardware( ((vuint32)p2Shm >= (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) && ((vuint32)p2Shm < (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ), canHwChannel, kCanErrorMcanMessageRAMOverflow); /* PRQA S 0306 */ /* MD_Can_0306_HWaccess_LL */ /* COV_CAN_GENDATA_FAILURE */
      if(p2Shm != V_NULL)  /* COV_CAN_GENDATA_FAILURE */
      { /* found valid handle */
        if( ((vuint32)p2Shm < (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || ((vuint32)p2Shm >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) ) /* PRQA S 0306,0303 */ /* MD_Can_0306_HWaccess_LL,MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
        { 
          ret_val = kCanTrue; /* address out of range assuming mailbox is corrupt */
        }
        else
        {
          vuint8 i;
          /* at this point the mailbox is not initialized therefore the contents are not saved! */
          /* #20 Iterate test patterns (check ID, Flags Dlc, Data) */
          for(i = 0u; (i < 3u) && (ret_val == kCanFalse); i++)                         /* COV_CAN_HARDWARE_FAILURE */
          { /* PRQA S 0303 QAC_Can_0303 */ /* MD_Can_HwAccess */
            vuint8 j;
# if defined (C_ENABLE_CAN_FD_FULL) 
            for(j=0u; (j < 18u) && (ret_val == kCanFalse);j++)  /* 72 byte per mbox */ /* COV_CAN_HARDWARE_FAILURE */
# else
            for(j=0u; (j <  4u) && (ret_val == kCanFalse);j++)  /* 16 byte per mbox */ /* COV_CAN_HARDWARE_FAILURE */
# endif
            {
              p2Shm[j] = CanMemCheckValues32bit[i];  /* SBSW_CAN_LL__103 */ /* T0/R0 */
              if(p2Shm[j] != CanMemCheckValues32bit[i])   /* COV_CAN_HARDWARE_FAILURE */
              {
                ret_val = kCanTrue; /* Mailbox is corrupt */
                /*no break allowed by QAC*/
              } 
            }
            /* no break allowed by QAC*/
          } 
          /* PRQA  L:QAC_Can_0303 */
        }
      }
      else
      { /* handle not found */
        ret_val = kCanTrue;
      }

# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) || (CAN_RX_BASICCAN_OBJECTS == STD_ON)
      if(ret_val != kCanTrue) /* COV_CAN_HARDWARE_FAILURE */
      {
        mboxElm++;
        if(Can_GetMailboxType(initPara->mailboxHandle) == CAN_TX_BASICCAN_MUX_TYPE)  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
        {
          p2Shm = (vuint32*) (pShmTXB(initPara->hwObjHandle + (CanObjectHandle) mboxElm));   /* PRQA S 0303,0310,312,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_IntegerCast */
        }
        else
        {
          if(Can_GetMailboxType(initPara->mailboxHandle) == CAN_RX_BASICCAN_TYPE) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
          {
            if(initPara->hwObjHandle == CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
            {
              p2Shm = (vuint32*) (ShmRXF0( (CanObjectHandle) mboxElm ));  /* PRQA S 0303,0310,312,2985,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_ConstValue,MD_Can_IntegerCast */
            }
            else
            {
              if(initPara->hwObjHandle == (CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel) +1u) ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
              {
                p2Shm = (vuint32*) (ShmRXF1( (CanObjectHandle) mboxElm ));  /* PRQA S 0303,0310,312,2985,4391 */ /* MD_Can_HwAccess,MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast,MD_Can_ConstValue,MD_Can_IntegerCast */
              }
            }
          }
        }
      }
    } while( (mboxElm < Can_GetMailboxSize(initPara->mailboxHandle)) && (ret_val != kCanTrue) ); /* COV_CAN_HARDWARE_FAILURE */
# endif
  }

  return(ret_val);
}  /* PRQA S 6010, 6030, 6080 */  /* MD_MSR_STPTH,MD_MSR_STCYC, MD_MSR_STMIF */
/* CODE CATEGORY 4 END */
#endif /* C_ENABLE_CAN_RAM_CHECK */


/**********************************************************************************************************************
 *  CanLL_InitPowerOn
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitPowerOn
Relation_Context:
# from Can_Init #
Relation:
OneChOpt
ChannelAmount, Variant
EccConfiguration
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOn(void)
{
CAN_ENDINIT_PROTECT_OFF();
# if defined( kCanPhysToLogChannelIndex_0 )  || defined( kCanPhysToLogChannelIndex_1 )  || defined( kCanPhysToLogChannelIndex_2 )  || defined( kCanPhysToLogChannelIndex_3 )   /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
  CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_GLOBAL,&(MCMCAN(MCMCAN_GLOBAL_ADDR_0)->CLC),0); /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_0)->MCR       = kCanSetMCR_prog_sequence_0; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_0)->MCR       = kCanSetMCR_prog_sequence_1; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_0)->MCR       = kCanSetMCR_prog_sequence_2; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_0)->BUFADR    = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_0)->MECR      = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_0)->MESTAT    = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_GLOBAL,&(MCMCAN(MCMCAN_GLOBAL_ADDR_0)->ACCENCTR0),kCanEnableMemAccess); /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
# endif 
# if defined( kCanPhysToLogChannelIndex_4 )  || defined( kCanPhysToLogChannelIndex_5 )  || defined( kCanPhysToLogChannelIndex_6 )  || defined( kCanPhysToLogChannelIndex_7 )   /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
  CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_GLOBAL,&(MCMCAN(MCMCAN_GLOBAL_ADDR_1)->CLC),0); /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_1)->MCR       = kCanSetMCR_prog_sequence_0; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_1)->MCR       = kCanSetMCR_prog_sequence_1; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_1)->MCR       = kCanSetMCR_prog_sequence_2; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_1)->BUFADR    = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_1)->MECR      = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_1)->MESTAT    = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_GLOBAL,&(MCMCAN(MCMCAN_GLOBAL_ADDR_1)->ACCENCTR0),kCanEnableMemAccess); /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
# endif 
# if defined( kCanPhysToLogChannelIndex_8 )  || defined( kCanPhysToLogChannelIndex_9 )  || defined( kCanPhysToLogChannelIndex_10 ) || defined( kCanPhysToLogChannelIndex_11 )  /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
  CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_GLOBAL,&(MCMCAN(MCMCAN_GLOBAL_ADDR_2)->CLC),0); /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_2)->MCR       = kCanSetMCR_prog_sequence_0; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_2)->MCR       = kCanSetMCR_prog_sequence_1; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_2)->MCR       = kCanSetMCR_prog_sequence_2; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_2)->BUFADR    = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_2)->MECR      = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  MCMCAN(MCMCAN_GLOBAL_ADDR_2)->MESTAT    = 0x00000000UL; /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
  CAN_WRITE_PROTECTED_REG32(CAN_PROTECTED_AREA_GLOBAL,&(MCMCAN(MCMCAN_GLOBAL_ADDR_2)->ACCENCTR0),kCanEnableMemAccess); /* PRQA S 0303 */ /* MD_Can_Hwaccess */ /* SBSW_CAN_LL__120 */
# endif
CAN_ENDINIT_PROTECT_ON();


#if defined( C_ENABLE_CAN_ECC_INIT_SHM ) /* COV_CAN_HW_SPECIFIC */
  /* #10 initialize the configured Message RAM area */
  Can_EccInit();
#endif  /* C_ENABLE_CAN_ECC_INIT_SHM */


  return(kCanOk);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitPowerOnChannelSpecific
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitPowerOnChannelSpecific
Relation_Context:
# from Can_Init #
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANTYPE_ONLY)
{
  /* #10 initialize local variables used for BusOff, Transmit and Interrupt handling */
  Can_GetCanBusOffNotification(canHwChannel) = 0; /* SBSW_CAN_LL__112 */ 
  Can_GetCanTXBRP(canHwChannel) = 0;              /* SBSW_CAN_LL__112 */ 
  Can_GetCanIntEnable(canHwChannel) = 0;          /* SBSW_CAN_LL__112 */ 
  Can_GetCanPrevMode(canHwChannel)  = 0xFF;       /* SBSW_CAN_LL__112 */ 
  Can_GetCanLastState(canHwChannel) = 0xFF;       /* SBSW_CAN_LL__112 */ 
  return(kCanOk);
}
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_InitMemoryPowerOn
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_InitMemoryPowerOn
Relation_Context:
# from Can_InitMemory #
Relation:
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_InitMemoryPowerOn(void)
{
  /* #10 no actions necessary */
}
/* CODE CATEGORY 4 END */




/**********************************************************************************************************************
 *  CanLL_TxBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxBegin
Relation_Context:
# from Can_Write #
Relation:
OneChOpt
ChannelAmount, DevErrorDetect
MultiplexedTx
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara)
{
  /* #10 initialize the pointer to the mailbox */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
  if(Can_GetMailboxType(txPara->mailboxHandle) == CAN_TX_BASICCAN_MUX_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    txPara->lpTXB = &ShmTXB((vuint32)(txPara->hwObjHandle) + (vuint32)(txPara->mailboxElement)); /* PRQA S 0303,1891,4391 */ /* MD_Can_HwAccess,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__113 */ 
  }
  else
# endif
  {
    txPara->lpTXB = &ShmTXB(txPara->hwObjHandle); /* PRQA S 0303,1891,4391 */ /* MD_Can_HwAccess,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__113 */ 
  }

  /* #20 check boundaries */
# if( CAN_SAFE_BSW == STD_ON ) 
  if( ((vuint32)txPara->lpTXB < (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || ((vuint32)&ShmTXB(txPara->hwObjHandle +1u) >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) ) /* PRQA S 0303,4391 */ /* MD_Can_HwAccess,MD_Can_IntegerCast */ /* CM_CAN_LL__103 */  /* COV_CAN_GENDATA_FAILURE */
  { /* SilentBSW check */
    Can_CallDetReportError(CAN_WRITE_ID, CAN_E_PARAM_HANDLE);
    txPara->lpTXB = (tTXBEType*)Can_GetStartAdrOfShmAdr(canHwChannel); /* assure no out of bounds access */ /* PRQA S 0303 */ /* MD_Can_HwAccess */  /* SBSW_CAN_LL__113 */
  }
# endif
  CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_TxSetMailbox
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxSetMailbox
Relation_Context:
# from Can_Write #
Relation:
OneChOpt
ChannelAmount, IDType
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxSetMailbox(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara)
{
  /* #10 set the mailbox control registers */
  txPara->lpTXB->T0 = txPara->idRaw0;                       /* SBSW_CAN_LL__103 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
# if defined(C_ENABLE_CAN_FD_USED)
  txPara->lpTXB->T1 =  ( ((vuint32) (((vuint32)txPara->dlcRaw) << 16)) | 
                         ((vuint32) (((vuint32)txPara->fdType) << 16)) | 
                         ((vuint32) (((vuint32)txPara->fdBrsType) << 16)) ); /* set DLC/FDF/BRS */  /* SBSW_CAN_LL__103 */  /* PRQA S 0303 */  /* MD_Can_HwAccess */
# else
  txPara->lpTXB->T1 = (vuint32) (((vuint32)txPara->dlcRaw) << 16);           /* set DLC/FDF/BRS */  /* SBSW_CAN_LL__103 */  /* PRQA S 0303 */  /* MD_Can_HwAccess */
# endif  /* C_ENABLE_CAN_FD_USED */
#else
  txPara->lpTXB->T1 = (vuint32) (((vuint32)txPara->dlcRaw) << 16);           /* set DLC */          /* SBSW_CAN_LL__103 */  /* PRQA S 0303 */  /* MD_Can_HwAccess */
#endif  /* CAN_MCAN_REVISION */
  CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */


/**********************************************************************************************************************
 *  CanLL_TxCopyToCan
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxCopyToCan
Relation_Context:
# from Can_Write #
Relation:
OneChOpt
ChannelAmount, CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxCopyToCan(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara)
{
#  if defined( C_CPUTYPE_BITORDER_LSB2MSB ) /* COV_CAN_CPUTYPE */
#  else
  vuint8 offset;
#  endif
  vuint8 curWord, curByte;
  tAlignCopyElem copyElem;  /* PRQA S 0759 */ /* MD_Can_Union */

  /* #10 copy the transmit data to a temporary buffer and set the mailbox data registers */
  curByte = 0u;
#  if defined (C_ENABLE_CAN_FD_FULL) 
  for (curWord = 0u; (curWord << 2u) < txPara->frameLen; curWord++) /* CM_CAN_LL__105 */ 
#  else
  for (curWord = 0u; (curWord) < 2u; curWord++) /* CM_CAN_LL__105 */ 
#  endif
  {
#  if defined( C_CPUTYPE_BITORDER_LSB2MSB ) /* COV_CAN_CPUTYPE */
    do
    { /* for each 32 bit word */
#   if defined (C_ENABLE_CAN_FD_FULL) 
      if(curByte < txPara->messageLen)  /* CM_CAN_LL__105 */ 
#   endif
      { /* either copy data */
        copyElem.b[curByte & 0x03u] = txPara->CanMemCopySrcPtr[curByte]; /* SBSW_CAN_LL__104 */ /* CM_CAN_LL__104 */
      }
#   if defined (C_ENABLE_CAN_FD_FULL) 
      else
      { /* or fill up with padding pattern */
        copyElem.b[curByte & 0x03u] = txPara->paddingVal;              /* SBSW_CAN_LL__104 */ /* CM_CAN_LL__104 */
      }
#   endif
      curByte++;
    } while((curByte & 0x03u) != 0u);                             /* CM_CAN_LL__104 */
#  else /* LSB2MSB */
    offset = 3u;
    do
    { /* for each 32 bit word */
#   if defined (C_ENABLE_CAN_FD_FULL) 
      if(curByte < txPara->messageLen) 
#   endif
      { /* either copy data */
        copyElem.b[offset] = txPara->CanMemCopySrcPtr[curByte]; /* SBSW_CAN_LL__104 */  
      }
#   if defined (C_ENABLE_CAN_FD_FULL) 
      else
      { /* or fill up with padding pattern */
        copyElem.b[offset] = txPara->paddingVal;              /* SBSW_CAN_LL__104 */
      }
#   endif
      curByte++;
      offset--;
    } while((curByte & 0x03u) != 0u);                     /* CM_CAN_LL__104 */  
#  endif /* LSB2MSB */
    /* move to Message RAM */
    txPara->lpTXB->Tn[curWord] = copyElem.dw; /* SBSW_CAN_LL__103 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  } /* end for loop */

  CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

} /* CanLL_TxCopyToCan */
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_TxStart
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxStart
Relation_Context:
# from Can_Write #
Relation:
OneChOpt
ChannelAmount, CanFdSupport, IDType, MultiplexedTx
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxStart(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8  retvalue = kCanOk;
  vuint32 txBRP;

  /* #10 get the corresponding Tx Buffer */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
  if(Can_GetMailboxType(txPara->mailboxHandle) == CAN_TX_BASICCAN_MUX_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    txBRP = (vuint32)(kCanACTIVE << ((txPara->hwObjHandle) + (txPara->mailboxElement)) );
  }
  else
# endif
  {
    txBRP = (vuint32)(kCanACTIVE << txPara->hwObjHandle);
  }

  /* Each Tx Buffer has its own Add Request bit. 
     Writing a '1' will set the corresponding Add Request bit (writing a '0' has no impact). 
     This enables the Host to set transmission requests for multiple Tx Buffers with one write to TXBAR. 
     TXBAR bits are set only for those Tx Buffers configured via TXBC. 
     When no Tx scan is running, the bits are reset immediately, else the bits remain set until the Tx scan process has completed. */
  {
    /* #20 set transmission request */
    CAN_MSG_RAM_SYNC(); /* PRQA S 1006 */ /* MD_Can_1006_inlineASM */
    Cn->TXBAR |= txBRP;   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */ 
    /* Each Tx Buffer has its own Transmission Request Pending bit. 
     The bits are set via register TXBAR. The bits are reset after a requested transmission has completed or has been cancelled via register TXBCR.
     TXBRP bits are set only for those Tx Buffers configured via TXBC. 
     After a TXBRP bit has been set, a Tx scan is started to check for the pending Tx request with the highest priority (lowest ID).
     A cancellation request resets the corresponding transmission request pending bit of register TXBRP. 
     In case a transmission has already been started when a cancellation is requested, this is done at the end of the transmission, 
     regardless whether the transmission was successful or not. The cancellation request bits are reset directly after the corresponding TXBRP bit has been reset. */
     /* #30 store the Tx Buffer number for confirmation handling */
     Can_GetCanTXBRP(canHwChannel) |= txBRP;   /* SBSW_CAN_LL__112 */ 
  }
  return(retvalue);
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_TxEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxEnd
Relation_Context:
# from Can_Write #
Relation:
OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxTransmissionParaStructPtr txPara)
{
  /* #10 no actions necessary */
  CAN_DUMMY_STATEMENT(txPara);     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

#if defined( C_ENABLE_TX_POLLING )
/**********************************************************************************************************************
 *  CanLL_TxIsGlobalConfPending
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxIsGlobalConfPending
Relation_Context:
# from Can_MainFunction_Write #
TxPolling, TxFullCANSupport
Relation:
OneChOpt, ChannelAmount
MultiplexedTx
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 retVal = kCanFalse;
  /* #10 check for pending transmit requests */
  if(Can_GetCanTXBRP(canHwChannel) != 0u)
  { /* Tx request is pending (do not check the HW Flags because reset is done only within next transmit request) */
    retVal = kCanTrue;
  }
  return retVal;
}
/* CODE CATEGORY 2 END */

/**********************************************************************************************************************
 *  CanLL_TxProcessPendings
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxProcessPendings
Relation_Context:
# from Can_MainFunction_Write #
TxPolling, TxFullCANSupport
Relation:
OneChOpt
ChannelAmount, MultiplexedTx
ChannelAmount, TxBasicAmount, TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara) /*PRQA S 3673*/ /* MD_Can_NoneConstParameterPointer */
{
  CanDeclareGlobalInterruptOldStatus
  vuint32 txBRP;
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
  CanObjectHandle mboxElm = 0;
# endif

  /* #10 get the corresponding Tx Buffer number to be confirmed */
  CanNestedGlobalInterruptDisable();
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION)
  if(Can_GetMailboxType(taskPara->mailboxHandle) == CAN_TX_BASICCAN_MUX_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    do 
    {
      txBRP = CanLL_if_TxIsObjConfPending(CAN_CHANNEL_CANPARA_FIRST ((vuint32)(kCanACTIVE << (taskPara->hwObjHandle + mboxElm))) );
      /* #20 confirmation handling for a specific Tx Buffer */
      if(txBRP == kCanOk) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* at least one Tx buffer is pending */
        CanHL_TxConfirmationPolling(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, mboxElm, taskPara->hwObjHandle + mboxElm);
      }
      mboxElm++;
    } while (mboxElm < Can_GetMailboxSize(taskPara->mailboxHandle)); /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  }
  else
# endif
  {
    txBRP = CanLL_if_TxIsObjConfPending(CAN_CHANNEL_CANPARA_FIRST ((vuint32)(kCanACTIVE << taskPara->hwObjHandle)));
    /* #22 confirmation handling for a specific Tx Buffer */
    if (txBRP == kCanOk)
    { /* at least one Tx buffer is pending */
      CanHL_TxConfirmationPolling(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, 0, taskPara->hwObjHandle);
    }
  }
  CanNestedGlobalInterruptRestore();

}
/* CODE CATEGORY 2 END */
#endif /* C_ENABLE_TX_POLLING */

/**********************************************************************************************************************
 *  CanLL_TxConfBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxConfBegin
Relation_Context:
# from CanHL_TxConfirmation #
Relation:
OneChOpt
ChannelAmount, TxBasicAmount, TxFullAmount
MultiplexedTx
IntLock, RxBasicCANSupport, RxPolling, RxFullCANSupport, TxPolling, IndividualPolling, StatusPolling, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara)  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint32 txBRP = (vuint32)(kCanACTIVE << (txConfPara->hwObjHandle));

  /* #10 check for unexpected confirmation */
  assertHardware( ((Can_GetCanTXBRP(canHwChannel) & txBRP) != 0UL), canHwChannel, kCanErrorUnexpectedConfirmation); /* COV_CAN_GENDATA_FAILURE */

  /* #20 clear pending flag for a specific Tx Buffer */
  CanNestedGlobalInterruptDisable();
  Can_GetCanTXBRP(canHwChannel)     &= ((vuint32)~txBRP);  /* SBSW_CAN_LL__112 */ 
  CanNestedGlobalInterruptRestore();
}
/* CODE CATEGORY 1 END */


#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/**********************************************************************************************************************
 *  CanLL_TxConfSetTxConfStruct
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxConfSetTxConfStruct
Relation_Context:
# from CanHL_TxConfirmation #
GenericConfirmation
Relation:
OneChOpt
ChannelAmount, MultiplexedTx, CanFdSupport, TxBasicAmount, TxFullCANSupport, TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara)
{
#if defined( C_ENABLE_CAN_FD_FULL )
  {
    vuint8 i;
    for(i=0u; i<16u; i++)
    {
      *(vuint32*)&txConfPara->tmpTXB.data[i] = ShmTXB(txConfPara->hwObjHandle).Tn[i];                  /* PRQA S 0303,0312,4391 */      /* MD_Can_HwAccess,MD_Can_NoneVolatilePointerCast,MD_Can_IntegerCast */                /* first transfer the 32 bit aligned Message RAM to a byte array */ /* SBSW_CAN_LL__109 */ 
      *(vuint32*)&txConfPara->tmpTXB.data[i] = CanBswap32(*(vuint32*)&txConfPara->tmpTXB.data[i]);     /* PRQA S 0303,0312,0404 */ /* MD_Can_HwAccess,MD_Can_NoneVolatilePointerCast,MD_Can_0404_LL */ /* then sort bytes depending on endianess */ /* SBSW_CAN_LL__109 */ 
    }
  }
#else
  *(vuint32*)&txConfPara->tmpTXB.data[0] = ShmTXB(txConfPara->hwObjHandle).Tn[0];                  /* PRQA S 0303,0312 */ /* MD_Can_HwAccess,MD_Can_NoneVolatilePointerCast */                     /* first transfer the 32 bit aligned Message RAM to a byte array */ /* SBSW_CAN_LL__109 */ 
  *(vuint32*)&txConfPara->tmpTXB.data[1] = ShmTXB(txConfPara->hwObjHandle).Tn[1];                  /* PRQA S 0303,0312 */ /* MD_Can_HwAccess,MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_LL__109 */ 
  *(vuint32*)&txConfPara->tmpTXB.data[0] = CanBswap32(*(vuint32*)&txConfPara->tmpTXB.data[0]);     /* PRQA S 0303,0312,0404 */ /* MD_Can_HwAccess,MD_Can_NoneVolatilePointerCast,MD_Can_0404_LL */ /* then sort bytes depending on endianess */ /* SBSW_CAN_LL__109 */ 
  *(vuint32*)&txConfPara->tmpTXB.data[1] = CanBswap32(*(vuint32*)&txConfPara->tmpTXB.data[1]);     /* PRQA S 0303,0312,0404 */ /* MD_Can_HwAccess,MD_Can_NoneVolatilePointerCast,MD_Can_0404_LL */  /* SBSW_CAN_LL__109 */ 
#endif

  /* #10 set pointers in the transmit structure */
  txConfPara->txStructConf->pChipData   = (CanChipDataPtr)&txConfPara->tmpTXB.data[0]; /* finally hand the byte pointer to the application */ /* SBSW_CAN_LL__109 */ 
  txConfPara->txStructConf->pChipMsgObj = (CanChipMsgPtr) &ShmTXB(txConfPara->hwObjHandle).T0;  /* PRQA S 0303,4391 */ /* MD_Can_HwAccess,MD_Can_IntegerCast */  /* SBSW_CAN_LL__109 */ 
}
/* CODE CATEGORY 1 END */
#endif

/**********************************************************************************************************************
 *  CanLL_TxConfEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_TxConfEnd
Relation_Context:
# from CanHL_TxConfirmation #
Relation:
OneChOpt,
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTxConfirmationParaStructPtr txConfPara)
{
  /* #10 no actions necessary */
  CAN_DUMMY_STATEMENT(txConfPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */



#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicMsgReceivedBegin
Relation_Context:
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
OneChOpt
ChannelAmount
HardwareLoopCheck
CanFdSupport
MultipleBasicCanObjects
Overrun
RxFullAmount
RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara)
{
  vuint8  indexL;
# if defined(C_ENABLE_CAN_FD_FULL)
  vuint8  fElmSize;
# endif

  /* #10 get the FIFO buffer */
# if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if(rxBasicPara->hwObjHandle > CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel))  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* point to Fifo-1 */
    rxBasicPara->pFifoAck    = &(Cn->RXF1A); /* SBSW_CAN_LL__109 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */
    rxBasicPara->pFifoStatus = &(Cn->RXF1S); /* SBSW_CAN_LL__109 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */
    rxBasicPara->fGetIndex   = (vuint8)(rxBasicPara->pFifoStatus->B.FnGI); /* SBSW_CAN_LL__109 */ 
    rxBasicPara->pShm        = ShmRXF1(rxBasicPara->fGetIndex);            /* PRQA S 0303,1891,4391 */ /* MD_Can_HwAccess,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__109 */ 
  }
  else
# endif
  { /* point to Fifo-0 */
    rxBasicPara->pFifoAck    = &(Cn->RXF0A); /* SBSW_CAN_LL__109 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */
    rxBasicPara->pFifoStatus = &(Cn->RXF0S); /* SBSW_CAN_LL__109 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */
    rxBasicPara->fGetIndex   = (vuint8)(rxBasicPara->pFifoStatus->B.FnGI); /* SBSW_CAN_LL__109 */ 
    rxBasicPara->pShm        = ShmRXF0(rxBasicPara->fGetIndex);            /* PRQA S 0303,1891,4391 */ /* MD_Can_HwAccess,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__109 */
  }

  /* #20 copy mailbox contents to temporary buffer */
  rxBasicPara->fElm.R0      = rxBasicPara->pShm->R0; /* SBSW_CAN_LL__109 */ 
  rxBasicPara->fElm.R1      = rxBasicPara->pShm->R1; /* SBSW_CAN_LL__109 */ 
# if defined(C_ENABLE_CAN_FD_FULL)
  fElmSize = CAN_DLC2LEN(((rxBasicPara->fElm.R1) & 0x000F0000UL) >> 16u); /* SBSW_CAN_LL__109 */
  for(indexL = 0u; (indexL << 2u) < fElmSize; indexL++)
#else
  for(indexL = 0u; indexL < 2u; indexL++)
#endif
  {
    rxBasicPara->fElm.data[indexL] = CanBswap32(rxBasicPara->pShm->data[indexL]);    /* PRQA S 0404 */  /* MD_Can_0404_LL */ /* SBSW_CAN_LL__109 */ 
  }

  /* #30 set pointers to the received message */
  rxBasicPara->rxStruct.pChipMsgObj = (CanChipMsgPtr)  &rxBasicPara->fElm.R0;      /* SBSW_CAN_LL__109 */ /* PRQA S 0310 */ /* MD_Can_PointerCast */
  rxBasicPara->rxStruct.pChipData   = (CanChipDataPtr) &rxBasicPara->fElm.data[0]; /* SBSW_CAN_LL__109 */ /* PRQA S 0310 */ /* MD_Can_PointerCast */

  return(kCanOk);
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_RxBasicReleaseObj
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicReleaseObj
Relation_Context:
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
OneChOpt
ChannelAmount, DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara)
{
  if( (((vuint32)*(vuint32*) rxBasicPara->pFifoStatus) & kCanRXFnS_FnFL) > 0UL)  /* PRQA S 0310,0312 */ /* MD_Can_PointerCast,MD_Can_NoneVolatilePointerCast */ /* COV_CAN_MCAN_SAFETY_CHECK */
  { /* Attention: ACK with Fill Level '0' will result in a endless read loop !!! */
    /* ACK: After the Host has read a message or a sequence of messages it has to write the buffer index of the last element read to FnAI. 
            This will set the Get Index RXFnS[FnGI] to FnAI+1 and update the FIFO Fill Level RXF0S[FnFL]. */
    /* #10 acknowledge the received messsage and go to the next one, if available */
    *rxBasicPara->pFifoAck    = (rxBasicPara->fGetIndex & 0x0000003FUL); /* SBSW_CAN_LL__109 */  
  }
  else
  {
    Can_CallDetReportError(CAN_HW_ACCESS_ID, CAN_E_PARAM_CONTROLLER);   /* COV_CAN_HARDWARE_FAILURE */
  }
  CAN_CHANNEL_DUMMY_STATEMENT;                     /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_RxBasicMsgReceivedEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicMsgReceivedEnd
Relation_Context:
# from CanHL_BasicCanMsgReceived #
RxBasicCANSupport
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxBasicParaStructPtr rxBasicPara)
{
  /* #10 no actions required */
  CAN_DUMMY_STATEMENT(rxBasicPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;       /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

# if defined( C_ENABLE_RX_BASICCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxBasicIsGlobalIndPending
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicIsGlobalIndPending
Relation_Context:
# from CanHL_RxBasicCanPolling #
RxBasicCANSupport, RxPolling
Relation:
OneChOpt
ChannelAmount, MultipleBasicCanObjects, RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
# CAN_BOSCH_ERRATUM_012 #
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8  retvalue = kCanFalse;
# if ( CAN_BOSCH_ERRATUM_012 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
#  if !defined( C_ENABLE_ISR_MANDATORY )  /* ISR not available, pure polling configuration */
  { /* check periodically for erratum12 */
    if( (Cn->IR  & kCanIR_TOO) != 0u)
    { /* timeout arrived */
      CanInterruptTimeoutCounter(CAN_HW_CHANNEL_CANPARA_ONLY);
    }
  }
#  endif
# endif

  /* #10 check the FIFO fill level for reception events */
#if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if( ((Cn->RXF0S.R & kCanRXFnS_FnFL) > 0u) || ((Cn->RXF1S.R & kCanRXFnS_FnFL) > 0u) ) /* PRQA S 0303 */ /* MD_Can_HwAccess */
#else
  if( ((Cn->RXF0S.R & kCanRXFnS_FnFL) > 0u) ) /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
  {
    retvalue = kCanTrue;
  }
  return retvalue;
}
/* CODE CATEGORY 2 END */

/**********************************************************************************************************************
 *  CanLL_RxBasicProcessPendings
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicProcessPendings
Relation_Context:
# from CanHL_RxBasicCanPolling #
RxBasicCANSupport, RxPolling
Relation:
OneChOpt
ChannelAmount, MultipleBasicCanObjects, RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxBasicProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint8 fillLevel;

  /* #10 get the corresponding FIFO buffer */
#if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if(taskPara->hwObjHandle > CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* point to Fifo-1 */
    fillLevel = Cn->RXF1S.B.FnFL;  /* PRQA S 1843,4558,0303 */ /* MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
  }
  else
#endif
  { /* point to Fifo-0 */
    fillLevel = Cn->RXF0S.B.FnFL;  /* PRQA S 1843,4558,0303 */ /* MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
  }
  
  /* #20 call the reception handling for each message until the FIFO buffer is empty */
  while( ((fillLevel) > 0u) ) 
  {
    fillLevel--;
    CanHL_BasicCanMsgReceivedPolling(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, taskPara->hwObjHandle);
  }

}
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_BASICCAN_POLLING */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullMsgReceivedBegin
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
Relation:
OneChOpt, ChannelAmount, HardwareLoopCheck
CanFdSupport
Overrun
RxFullCANSupport, RxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara)
{
# if defined(C_ENABLE_CAN_FD_FULL)
  vuint8 rElmSize, indexL;
# endif

  rxFullPara->rxStruct.pChipMsgObj = (CanChipMsgPtr)  &rxFullPara->bfElm;         /* SBSW_CAN_LL__109 */ /* PRQA S 0310 */ /* MD_Can_PointerCast */
  rxFullPara->rxStruct.pChipData   = (CanChipDataPtr) &rxFullPara->bfElm.data[0]; /* SBSW_CAN_LL__109 */ /* PRQA S 0310 */ /* MD_Can_PointerCast */ 

  /* #10 calculate the local rx object handle (zero-based) */
  rxFullPara->objectNumber = (CanObjectHandle) (rxFullPara->hwObjHandle - CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel)); /* SBSW_CAN_LL__109 */ 
  /* #20 get the pointer to the message object */
  rxFullPara->pShm = ShmRXB(rxFullPara->objectNumber); /* PRQA S 0303,1891,4391 */ /* MD_Can_HwAccess,MD_Can_1891_LL,MD_Can_IntegerCast */ /* SBSW_CAN_LL__109 */
  rxFullPara->bfElm.R0 = rxFullPara->pShm->R0; /* SBSW_CAN_LL__109 */ 
  rxFullPara->bfElm.R1 = rxFullPara->pShm->R1; /* SBSW_CAN_LL__109 */ 

# if defined(C_ENABLE_CAN_FD_FULL)
  rElmSize = CAN_DLC2LEN((vuint32)((rxFullPara->bfElm.R1) & 0x000F0000UL) >> 16u); /* SBSW_CAN_LL__109 */

  /* #30 copy the data */
  for(indexL = 0u; (indexL << 2u) < rElmSize; indexL++) /* SBSW_CAN_LL__109 */ /* SBSW_CAN_LL__109 */ 
  {
    rxFullPara->bfElm.data[indexL] = rxFullPara->pShm->data[indexL];  /* SBSW_CAN_LL__109 */ 
  }
#else /* C_ENABLE_CAN_FD_FULL */
  rxFullPara->bfElm.data[0] = rxFullPara->pShm->data[0]; /* SBSW_CAN_LL__109 */ 
  rxFullPara->bfElm.data[1] = rxFullPara->pShm->data[1]; /* SBSW_CAN_LL__109 */ 
#endif /* C_ENABLE_CAN_FD_FULL */

  /* #40 clear the New Data Flag  */
  Cn->NDATA[(rxFullPara->objectNumber>>0x05UL)] = (0x00000001UL << (rxFullPara->objectNumber & 0x1FUL));   /* SBSW_CAN_LL__100 */   
  
  /* While an Rx Buffer's New Data flag is set, a Message ID Filter Element referencing this specific Rx Buffer will not match, causing the acceptance filtering to continue. 
   Following Message ID Filter Elements may cause the received message to be stored 
   - into another Rx Buffer or
   - into an Rx FIFO or
   - the message may be rejected,
   depending on filter configuration. */
  return(kCanOk);
}
/* CODE CATEGORY 1 END */


/**********************************************************************************************************************
 *  CanLL_RxFullReleaseObj
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullReleaseObj
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
 V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara)
{
  /* #10 no actions required */
  CAN_DUMMY_STATEMENT(rxFullPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_RxFullMsgReceivedEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullMsgReceivedEnd
Relation_Context:
# from CanHL_FullCanMsgReceived #
RxFullCANSupport
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanRxFullParaStructPtr rxFullPara)
{
  /* #10 no actions required */
  CAN_DUMMY_STATEMENT(rxFullPara);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_CHANNEL_DUMMY_STATEMENT;      /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 1 END */


# if defined( C_ENABLE_RX_FULLCAN_POLLING )
/**********************************************************************************************************************
 *  CanLL_RxFullIsGlobalIndPending
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullIsGlobalIndPending
Relation_Context:
# from CanHL_RxFullCanPolling #
RxFullCANSupport, RxPolling
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
# CAN_BOSCH_ERRATUM_012 #
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxFullIsGlobalIndPending(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 retVal = kCanFalse;
# if ( CAN_BOSCH_ERRATUM_012 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
#  if !defined( C_ENABLE_ISR_MANDATORY )  /* ISR not available, pure polling configuration */
  { /* check periodically for erratum12 */
    if( (Cn->IR  & kCanIR_TOO) != 0u)
    { /* timeout arrived */
      CanInterruptTimeoutCounter(CAN_HW_CHANNEL_CANPARA_ONLY);
    }
  }
#  endif
# endif

  /* #10 check the receive buffer new data registers for reception events */
  if( (Cn->NDATA[0] != 0u) || (Cn->NDATA[1] != 0u) ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    retVal = kCanTrue;
  }
  return retVal;
}
/* CODE CATEGORY 2 END */

/**********************************************************************************************************************
 *  CanLL_RxFullProcessPendings
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxFullProcessPendings
Relation_Context:
# from CanHL_RxFullCanPolling #
RxFullCANSupport, RxPolling
Relation:
OneChOpt
ChannelAmount
RxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_RxFullProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST CanTaskParaStructPtr taskPara) /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  vuint32 ndfPos, shiftVal, ndata;

  /* #10 calculate the corresponding Tx Buffer */
  ndfPos = (vuint32)taskPara->hwObjHandle - CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel); 
  if(ndfPos >= 32u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    ndata = Cn->NDATA[1]; /* SBSW_CAN_LL__106 */
    ndfPos -= 32u;
  }
  else
  {
    ndata = Cn->NDATA[0]; /* SBSW_CAN_LL__106 */
  }

  shiftVal = (vuint32)(0x00000001UL << ndfPos);

  /* #20 call the reception handling for the mailbox which received a new message */
  if( (ndata & shiftVal) != 0u)
  {
    /* While an Rx Buffers NDF is set the belonging ID Filter will not match, causing the acceptance filtering to continue. 
       Following ID Filters may cause the received message to be stored into another Rx Buffer or into an Rx FIFO or the message may be rejected. */
    CanHL_FullCanMsgReceivedPolling(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST taskPara->mailboxHandle, taskPara->hwObjHandle);
  }
}
/* CODE CATEGORY 2 END */
# endif /* C_ENABLE_RX_FULLCAN_POLLING */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */




/**********************************************************************************************************************
 *  CanLL_ErrorHandlingBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_ErrorHandlingBegin
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling
Relation:
OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
# CAN_MCAN_REVISION #
# CAN_BOSCH_ERRATUM_011 #
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  /* ***
  If the CAN protocol controller has detected an error condition (e.g. CRC error), the message is 
  discarded with the following impact on the affected Rx Buffer or Rx FIFO:
  Rx Buffer: NDF of matching Rx Buffer is NOT set, but Rx Buffer (partly) overwritten with received data. 
  Rx FIFO:   Put index of FIFO is NOT updated,  but FIFO element (partly) overwritten with received data. 

  If the matching Rx FIFO is operated in overwrite mode, the boundary conditions have to be considered
  It might happen that a received message is written to the Message RAM (put index) while the CPU is 
  reading from the Message RAM (get index). 
  In this case inconsistent data may be read from the FIFO element.
  For error type see PSR.LEC respectively PSR.FLEC.
  *** */
#if ( CAN_MCAN_REVISION >= 0x0300UL )     /* COV_CAN_HW_SPECIFIC */
# if ( CAN_BOSCH_ERRATUM_011 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
  if((Cn->IR & kCanIR_MRAF) != 0)        /* COV_CAN_MCAN_NOT_SUPPORTED */
  {  /* IR.MRAF is erroneously set during frame reception while the M_CAN is in Error Passive state and 
        the Receive Error Counter has the value ECR.REC = 127.
        Workaround:
        The Message RAM Access Failure routine needs to check whether ECR.RP = '1' 
        (REC has reached the error passive level of 128) and ECR.REC = 127. 
        In this case reset IR.MRAF, no further action required. */
    /* #10 clear erroneous interrupt flag (see MCAN Erratum #11) */
    if( ((Cn->ECR & kCanECR_RP) != 0) && (((Cn->ECR & kCanECR_REC) >> 8) == 127) ) /* COV_CAN_HW_SPECIFIC */
    {
      Cn->IR = kCanIR_MRAF;   /* SBSW_CAN_LL__100 */    /* reset and forget */
    }
  }
# endif
#endif

#if ( CAN_MCAN_REVISION < 0x0300UL ) || ( CAN_BOSCH_ERRATUM_011 == STD_OFF )  /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
  CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}
/* CODE CATEGORY 2 END */

/**********************************************************************************************************************
 *  CanLL_BusOffOccured
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_BusOffOccured
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 retVal = kCanFalse;
  /* #10 check if a busoff occurred */
  if(CanErrorHandlingBusOff(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanOk) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    retVal = kCanTrue;
  }
  return(retVal);
}
/* CODE CATEGORY 2 END */

#if defined( C_HL_ENABLE_OVERRUN_IN_STATUS )    /* COV_CAN_OVERRUN_IN_STATUS */
# if defined( C_ENABLE_OVERRUN ) && defined(C_ENABLE_RX_BASICCAN_OBJECTS)
/**********************************************************************************************************************
 *  CanLL_RxBasicCanOverrun
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_RxBasicCanOverrun
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling, Overrun, RxBasicCANSupport
Relation:
OneChOpt
MultipleBasicCanObjects, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_RxBasicCanOverrun(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 ret_val = kCanFalse;

  /* #10 check if a receive FIFO buffer overrun occurred */
#  if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if( ((Cn->IR) & ((vuint32)(kCanIR_RF0L | kCanIR_RF1L)) ) != 0UL) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  else
  if( ((Cn->IR) & (kCanIR_RF0L) ) != 0UL)               /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  endif
  {
    /* #20 clear the overrun (and full) flag */
#  if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)(kCanIR_RF0L | kCanIR_RF0F | kCanIR_RF1L | kCanIR_RF1F));
#  else
    Cn->IR = (vuint32)(kCanIR_RF0L | kCanIR_RF0F | kCanIR_RF1L | kCanIR_RF1F);   /* SBSW_CAN_LL__100 */  /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  endif
    ret_val = kCanTrue;
  }
  return(ret_val);
}
/* CODE CATEGORY 2 END */
# endif

#endif /* C_HL_ENABLE_OVERRUN_IN_STATUS */

/**********************************************************************************************************************
 *  CanLL_ErrorHandlingEnd
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_ErrorHandlingEnd
Relation_Context:
# from CanHL_ErrorHandling() #
StatusPolling
Relation:
OneChOpt
MultipleBasicCanObjects, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 2 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
#if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if( ((Cn->IR) & (kCanIR_RF0L | kCanIR_RF1L) ) != 0UL) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#else
  if( ((Cn->IR) & (kCanIR_RF0L) ) != 0UL)               /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
  {
    /* #10 clear overrun (and full) flag */
#if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)(kCanIR_RF0L | kCanIR_RF0F | kCanIR_RF1L | kCanIR_RF1F));
#else
    Cn->IR = (vuint32)(kCanIR_RF0L | kCanIR_RF0F | kCanIR_RF1L | kCanIR_RF1F);   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
  }
}
/* CODE CATEGORY 2 END */

#if defined( C_ENABLE_EXTENDED_STATUS )
/**********************************************************************************************************************
 *  CanLL_GetStatusBegin
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_GetStatusBegin
Relation_Context:
# from Can_GetStatus
CanGetStatus
Relation:
OneChOpt,
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 3 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_GetStatusBegin(CAN_CHANNEL_CANTYPE_ONLY)
{
  /* #10 no actions required */
  CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
}
/* CODE CATEGORY 3 END */
#endif



/**********************************************************************************************************************
 *  CanLL_ModeTransition
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_ModeTransition
Relation_Context:
# from CanHL_ModeTransition() #
Wakeup, OneChOpt, HardwareLoopCheck, ChannelAmount
RamCheck, OneChOpt, HardwareLoopCheck, ChannelAmount
# from Can_Mainfunction_Mode() #
ChannelAmount
Relation:
OneChOpt
SilentMode, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_STATIC, vuint8, STATIC_CODE) CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST vuint8 mode, vuint8 busOffRecovery, vuint8 ramCheck)
{
  vuint8 ret = kCanFailed;

  switch(mode)
  {
    case kCanModeStartReinit:      /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    case kCanModeResetBusOffEnd:   /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      /* #10 START (reinit BusOffEnd) request  */
      /* perform BusOffEnd handling (delete pending BusOff), goto START  */
      /* #20 START (reinit) request */
      /* Reinit means that a call of CanHL_ReInit() should be included (after set to init mode) before the transition to final target mode */
      if( (Can_GetCanPrevMode(canHwChannel) == mode) && (Can_GetCanLastState(canHwChannel) == kCanRequested) ) /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
      { /* repeat requested mode change without repeating reinit */
        ret = CanLL_StartRequest(CAN_CHANNEL_CANPARA_ONLY);
      }
      else
      {
        ret = CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck);
        if(ret == kCanOk) /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
        {
          ret = CanLL_StartRequest(CAN_CHANNEL_CANPARA_ONLY);
        }
      }
      break;

    case kCanModeStart:   /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      /* #30 START request */
      /* if in stop mode, otherwise first go to stop mode */
      ret = CanLL_StartRequest(CAN_CHANNEL_CANPARA_ONLY);
      break;

#if defined(C_ENABLE_SILENT_MODE) 
    case kCanModeSilent:
      /* #40 START SILENT request */
      /* if in stop mode, otherwise first go to stop mode */
      if( (Can_GetCanPrevMode(canHwChannel) == mode) && (Can_GetCanLastState(canHwChannel) == kCanRequested) ) /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
      { /* repeat requested mode change without repeating reinit */
        ret = CanLL_StartSilentRequest(CAN_CHANNEL_CANPARA_ONLY);
      }
      else
      {
        ret = CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck);
        if(ret == kCanOk) /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
        {
          ret = CanLL_StartSilentRequest(CAN_CHANNEL_CANPARA_ONLY);
        }
      }
      break;
#endif

    case kCanModeResetBusOffStart:   /* ASR: kCanModeResetBusOffEnd or kCanModeResetBusOffStart should do a Reinit (short is ok, ASR: with CanHL_CleanUpSendState()) */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    case kCanModeStopReinit:
        /* #50 STOP (reinit BusOffStart) request */
        if( (Can_GetCanPrevMode(canHwChannel) == mode) && (Can_GetCanLastState(canHwChannel) == kCanRequested) ) /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
        { /* repeat requested mode change without repeating reinit */
          ret = CanLL_StopRequest(CAN_CHANNEL_CANPARA_ONLY);
        }
        else
        {
          ret = CanHL_ReInit(CAN_CHANNEL_CANPARA_FIRST ramCheck);
          if(ret == kCanOk) /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
          {
            ret = CanLL_StopRequest(CAN_CHANNEL_CANPARA_ONLY);
          }
        }
        if(ret == kCanOk) { /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
          ApplCanClockStop(CAN_HW_CHANNEL_CANPARA_ONLY); /* offer the application to turn off the clocks (CAN, Host) */
        }
        CanHL_CleanUpSendState(CAN_CHANNEL_CANPARA_ONLY);
      break;

    case kCanModeStopReinitFast:     /* distinguish for fast if applicable */
        /* #60 STOP FAST request */
        ret = CanLL_StopRequest(CAN_CHANNEL_CANPARA_ONLY);
        if(ret == kCanOk) {
          CanLL_StopReinit(CAN_HW_CHANNEL_CANPARA_ONLY);
          ApplCanClockStop(CAN_HW_CHANNEL_CANPARA_ONLY); /* offer the application to turn off the clocks (CAN, Host) */
          CanHL_CleanUpSendState(CAN_CHANNEL_CANPARA_ONLY);
        }
      break;

    default:
      /* ret is kCanFailed */
      break;
  }
  
  Can_GetCanPrevMode(canHwChannel) = mode; /* SBSW_CAN_LL__112 */ 
  Can_GetCanLastState(canHwChannel) = ret; /* SBSW_CAN_LL__112 */ 
  
  CAN_DUMMY_STATEMENT(busOffRecovery);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return ret;
}  /* PRQA S 6030 */  /* MD_MSR_STCYC */
/* CODE CATEGORY 4 END */

/**********************************************************************************************************************
 *  CanLL_StopReinit
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_StopReinit
Relation_Context:
# from CanLL_ModeTransition() #
OneChOpt, HardwareLoopCheck, ChannelAmount
Relation:
OneChOpt
ChannelAmount, RamCheck
RxFullCANSupport, RxBasicCANSupport, MultipleBasicCanObjects, CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
/* CODE CATEGORY 4 START */
/* PRQA S 0303 QAC_Can_0303_StopReinit */ /* MD_Can_HwAccess */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_StopReinit(CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint32 tmpECR; /* PRQA S 3203 */ /* MD_Can_3203_LL */

  /* #10 reset FullCAN flags */
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) 
  Cn->NDATA[0] = kCan_ALL_ONE;   /* SBSW_CAN_LL__100 */   
  Cn->NDATA[1] = kCan_ALL_ONE;   /* SBSW_CAN_LL__100 */   
#endif

  /* CAN error logging is reset by read access to ECR[CEL] */
  /* #20 reset error counter */
  tmpECR = Cn->ECR; /* CAN error logging is reset by read access to ECR[CEL] */  /* PRQA S 3198,3199 */ /* MD_MSR_14.2 */
  CAN_DUMMY_STATEMENT(tmpECR);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */

  /* CCCR[CCE] is automatically reset when CCCR[INIT] is reset */
  Cn->CCCR |= kCanCCCR_CCE;             /* SBSW_CAN_LL__100 */   

  /* #30 reset transmit requests */
  Can_GetCanTXBRP(canHwChannel)   = 0;  /* SBSW_CAN_LL__112 */ 
  
  /* If there are any pending Tx requests. */
  if ((Cn->TXBRP)!=0UL) /* COV_CAN_PENDING_TX_REQUEST */
  {
    Cn->TXBCR = (vuint32)(Cn->TXBRP); /* SBSW_CAN_LL__100 */ /* Cancel pending tx requests*/
  }

  /* #40 reset CAN FD bits */
#if defined(C_ENABLE_CAN_FD_USED)
  if(Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) != CAN_NONE)
  {
    if(Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_FD_RXTX)
    { /* CAN_FD_RXTX */
# if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
      Cn->CCCR |= (vuint32)(kCanCCCR_FDOE | kCanCCCR_BRSE);   /* SBSW_CAN_LL__100 */   /* FD operation, BRS enabled */
# else
      Cn->CCCR &= (vuint32)(~(kCanCCCR_CME_CAN20));           /* SBSW_CAN_LL__100 */   /* reset CME bits */
      Cn->CCCR |= kCanCCCR_CME_LONG_FAST;                     /* SBSW_CAN_LL__100 */   /* enable LONG and FAST */
# endif
    }
    else
    { /* CAN_FD_RXONLY */
# if ( CAN_MCAN_REVISION >= 0x0310UL ) /* COV_CAN_HW_SPECIFIC */
      Cn->CCCR &= (vuint32)(~(kCanCCCR_FDOE | kCanCCCR_BRSE)); /* SBSW_CAN_LL__100 */  /* reset FD bits */
      Cn->CCCR |= (vuint32)(kCanCCCR_FDOE);                    /* SBSW_CAN_LL__100 */  /* FD operation, BRS disabled */
# else
      Cn->CCCR &= (vuint32)(~(kCanCCCR_CME_CAN20));   /* SBSW_CAN_LL__100 */  /* reset CME bits */
      Cn->CCCR |= kCanCCCR_CME_LONG;                  /* SBSW_CAN_LL__100 */  /* enable LONG  */
# endif
    }
  }
  else
  { /* CAN_NONE */
# if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
    Cn->CCCR &= (vuint32)(~(kCanCCCR_FDOE | kCanCCCR_BRSE));   /* SBSW_CAN_LL__100 */    /* No FD operation, BRS disabled */
# else
    Cn->CCCR &= (vuint32)(~(kCanCCCR_CME_CAN20));              /* SBSW_CAN_LL__100 */    /* enable NORMAL CAN */
# endif
  }
#else
# if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
    /* FD operation disabled */
    Cn->CCCR &= (vuint32)(~(kCanCCCR_FDOE | kCanCCCR_BRSE));   /* SBSW_CAN_LL__100 */    /* No FD operation, BRS disabled */
# else
    Cn->CCCR &= (vuint32)(~(kCanCCCR_CME_CAN20));              /* SBSW_CAN_LL__100 */    /* enable NORMAL CAN */
# endif
#endif

  /* #50 clear pending FIFO messages */
  CanLL_ApplCanTimerStart(kCanLoopRxFifo ); /* SBSW_CAN_LL__102 */  
  while( (((Cn->RXF0S).B.FnFL) > 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopRxFifo) != CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    Cn->RXF0A = Cn->RXF0S.B.FnGI;   /* SBSW_CAN_LL__100 */   
  }
  CanLL_ApplCanTimerEnd( kCanLoopRxFifo); /* SBSW_CAN_LL__102 */  
#if defined( C_ENABLE_MULTIPLE_BASICCAN )
  CanLL_ApplCanTimerStart(kCanLoopRxFifo ); /* SBSW_CAN_LL__102 */  
  while( (((Cn->RXF1S).B.FnFL) > 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopRxFifo) != CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    Cn->RXF1A = Cn->RXF1S.B.FnGI;   /* SBSW_CAN_LL__100 */   
  }
  CanLL_ApplCanTimerEnd( kCanLoopRxFifo); /* SBSW_CAN_LL__102 */  
#endif

  /* #60 delete all pending interrupt requests */
  Cn->IR = kCanIR_CLEAR_ALL;   /* SBSW_CAN_LL__100 */   
}
/* PRQA  L:QAC_Can_0303_StopReinit */
/* CODE CATEGORY 4 END */



#if defined( C_ENABLE_CAN_CAN_INTERRUPT_CONTROL )   /* COV_CAN_LOCK_ISR_BY_APPL */
/**********************************************************************************************************************
 *  CanLL_CanInterruptDisable
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_CanInterruptDisable
Relation_Context:
# from Can_DisableControllerInterrupts #
IndividualPolling
TxPolling
RxPolling
StatusPolling
Relation:
IntLock
OneChOpt 
ChannelAmount, CanInterruptControl, IntLock, RxBasicCANSupport, RxPolling, RxFullCANSupport, TxPolling, IndividualPolling, StatusPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptDisable(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOldPtr localInterruptOldFlagPtr)
{
  /* #10 Save old state and disable interrupt */
#  if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)  /* COV_CAN_HW_SPECIFIC */
  boolean  retval;
  (void)osIsInterruptSourceEnabled(Can_GetIsrOsId(canHwChannel), &retval); /* SBSW_CAN_LL__121 */
  (void)osDisableInterruptSource(Can_GetIsrOsId(canHwChannel));
  *(localInterruptOldFlagPtr) = (vuint32) retval; /* SBSW_CAN_LL__122 */
#  else
#    if defined( V_CPU_TC3XX )              /* COV_CAN_HW_SPECIFIC */
  *(localInterruptOldFlagPtr) = (vuint32)(kCanSRCR_Mask & CAN_READ_SRN_PROTECTED_REG32(CAN_PROTECTED_AREA_SRN,Can_GetSRN_Address(canHwChannel))); /* PRQA S 0306,0303 */ /* MD_Can_0306_HWaccess_LL,MD_Can_HwAccess */ /* SBSW_CAN_HL16 */ /* SBSW_CAN_LL__119 */
  CAN_WRITE_SRN_PROTECTED_REG32(CAN_PROTECTED_AREA_SRN,Can_GetSRN_Address(canHwChannel),((*localInterruptOldFlagPtr) & kCanDisable_Service_Request) ); /* PRQA S 0306 */ /* MD_Can_0306_HWaccess_LL */ /* SBSW_CAN_LL__119 */ /* SBSW_CAN_LL__123 */
#    else
  *(localInterruptOldFlagPtr) = Cn->IE;   /* SBSW_CAN_HL16 */      /* PRQA S 0303 */ /* MD_Can_HwAccess */
  Cn->IE = 0;                             /* SBSW_CAN_LL__100 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */
#    endif
#  endif /* C_ENABLE_USE_OS_INTERRUPT_CONTROL */

} /* CanLL_CanInterruptDisable */
/* CODE CATEGORY 1 END */

/**********************************************************************************************************************
 *  CanLL_CanInterruptRestore
 *********************************************************************************************************************/
/*
|<DataModelStart>| CanLL_CanInterruptRestore
Relation_Context:
# from Can_EnableControllerInterrupts #
IndividualPolling
TxPolling
RxPolling
StatusPolling
Relation:
OneChOpt
ChannelAmount, CanInterruptControl, IntLock, RxBasicCANSupport, RxPolling, RxFullCANSupport, TxPolling, IndividualPolling, StatusPolling
IntLock
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_CanInterruptRestore(CAN_HW_CHANNEL_CANTYPE_FIRST tCanLLCanIntOld localInterruptOldFlag)
{
#  if defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL)    /* COV_CAN_HW_SPECIFIC */
  if( (vuint32)localInterruptOldFlag == TRUE ) /* COV_CAN_OS_INT_SOURCE */
  {
    (void)osEnableInterruptSource(Can_GetIsrOsId(canHwChannel), FALSE);
  }
#  else
  /* #10 restore previous state (before disabling interrupts) */
#   if defined( V_CPU_TC3XX )           /* COV_CAN_HW_SPECIFIC */
  CAN_WRITE_SRN_PROTECTED_REG32(CAN_PROTECTED_AREA_SRN,Can_GetSRN_Address(canHwChannel),(vuint32)(kCanSRCR_Mask & (CAN_READ_SRN_PROTECTED_REG32(CAN_PROTECTED_AREA_SRN,Can_GetSRN_Address(canHwChannel)) | localInterruptOldFlag)) ); /* PRQA S 0306 */ /* MD_Can_0306_HWaccess_LL */ /* SBSW_CAN_LL__119 */ /* SBSW_CAN_LL__123 */
#   else
  Cn->IE = (localInterruptOldFlag);   /* SBSW_CAN_LL__100 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#   endif
#  endif /* C_ENABLE_USE_OS_INTERRUPT_CONTROL */
} /* CanLL_CanInterruptRestore */
/* CODE CATEGORY 1 END */
#endif /*  C_ENABLE_CAN_CAN_INTERRUPT_CONTROL */









#if defined( C_ENABLE_CAN_ECC_INIT_SHM ) /* COV_CAN_HW_SPECIFIC */
/* **************************************************************************
| NAME:             Can_EccInit
| CALLED BY:        Can_Init()
| PRECONDITIONS:    MCAN clock must be available, Interrupts must be disabled
| INPUT PARAMETERS: none
| RETURN VALUES:    none
| DESCRIPTION:      The internal SRAM features Error Correcting Code (ECC). 
|                   Because these ECC bits can contain random data after the device is turned on, 
|                   all SRAM locations must be initialized before being read by application code. 
|                   Initialization is done by executing 64-bit writes to the entire SRAM block. 
|                   (The value written does not matter at this point.)
************************************************************************** */
/*************************************************************************
 *  Can_EccInit
 *********************************************************************** */
/*
|<DataModelStart>| Can_EccInit
Relation_Context:
# from Can_Init #
Relation:
OneChOpt
ChannelAmount
RxBasicCANSupport, RxPolling, RxFullCANSupport, TxPolling, IndividualPolling, StatusPolling, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
* Internal comment removed.
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) Can_EccInit(void)
{
  vuint16  ch, idx;
  vuint32  length;
  vuint32* dst;

  /* #10 initialize CAN Message RAM area for each channel */
  for(ch = 0; ch < kCanNumberOfChannels; ch++)
  {
    dst = (vuint32*) Can_GetStartAdrOfShmAdr(ch);   /* PRQA S 0306 */ /* MD_Can_0306_HWaccess_LL */
    length = (Can_GetStopAdrOfShmAdr(ch) - Can_GetStartAdrOfShmAdr(ch)) >> 2;  /* SMI-64561 */ 
    for(idx = 0; idx < length; idx++)
    {
      dst[idx] = 0x00000000UL; /* SBSW_CAN_LL__108 */ 
    }
  }
}
/* CODE CATEGORY 1 END */
#endif /* C_ENABLE_CAN_ECC_INIT_SHM */

#if defined( C_ENABLE_TX_POLLING )
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_if_TxIsObjConfPending
****************************************************************************/
/*
|<DataModelStart>| CanLL_if_TxIsObjConfPending
Relation_Context:
# from CanLL_TxProcessPendings #
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint32, STATIC_CODE) CanLL_if_TxIsObjConfPending( CAN_CHANNEL_CANTYPE_FIRST vuint32 txBuffer ) 
{
  vuint32 ret;

  ret = kCanOk; /* assume at least one Tx object confirmation is pending */

  /* #10 check for pending tx requests */
  if( ((Can_GetCanTXBRP(canHwChannel) & txBuffer) != 0u) && ((Cn->TXBTO & txBuffer) != 0u) )   /* COV_CAN_HW_SPECIFIC*/  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
  { /* #20 confirmation shows up */
  }
  else
  { /* #30 no request pending or outstanding confirmation */
    ret = kCanFailed;
  }
  return(ret);
}/* CanLL_if_TxIsObjConfPending */
/* CODE CATEGORY 4 END */
#endif

#if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
/****************************************************************************
| NAME:             CanLL_TriCoreErratum_AI_H001
****************************************************************************/
/*
|<DataModelStart>| CanLL_TriCoreErratum_AI_H001
Relation_Context:
# CanInterrupt() #
Relation:
OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
/* CODE CATEGORY 4 START */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANTYPE_FIRST vuint32 CanIrFlag)
{
  /* #10 Clear the interrupt flag */
  Cn->IR = (CanIrFlag); /* SBSW_CAN_LL__100 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  /* #20 Check if the clear is neglected */
  if ( (Cn->IR & CanIrFlag) != 0u ) /* COV_CAN_HARDWARE_FAILURE */
  {
    CanLL_ApplCanTimerStart(kCanLoopIrFlag); /* SBSW_CAN_LL__101 */
    do
    {
      /* #30 Repeat clearing until the flag reads zero */
      Cn->IR = (CanIrFlag); /* SBSW_CAN_LL__100 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    } while( ((Cn->IR & CanIrFlag) != 0u ) && (CanLL_ApplCanTimerLoop(kCanLoopIrFlag) !=  CAN_NOT_OK) ); /* PRQA S 1881,3415 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect */
    CanLL_ApplCanTimerEnd( kCanLoopIrFlag ); /* SBSW_CAN_LL__101 */
  }
} /* CanLL_TriCoreErratum_AI_H001 */
/* CODE CATEGORY 4 END */
#endif /* C_ENABLE_REGEXT_MCMCAN_COMMENT */

#if ( CAN_BOSCH_ERRATUM_010 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanBoschErratum_010
****************************************************************************/
/*
|<DataModelStart>| CanBoschErratum_010
Relation_Context:
# from CanLL_SetAllRegister #
Relation:
OneChOpt
ChannelAmount, HardwareLoopCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanBoschErratum_010( CAN_HW_CHANNEL_CANTYPE_ONLY )  /* PRQA S 3673 */ /* MD_Can_NoneConstParameterPointer */
{
  /* When CCCR.CCE is set while a Tx scan is in progress, the Tx Handler FSM stops. 
     After CCCR.INIT and CCCR.CCE are reset, the Tx Handler FSM does not execute transmission requests.
     Workaround:
     1) Cancel all pending transmission requests by writing 0hFFFF FFFF to register TXBCR
     2) Issue a clock stop request by setting bit CCCR.CSR
     3) Wait until the M_CAN sets CCCR.INIT and CCCR.CSA to one
     4) First reset CCCR.CSR
     5) Then reset CCCR.INIT
     6) Wait until CCCR.INIT is read as zero
     7) Issue a second clock stop request by setting bit CCCR.CSR
     8) Wait until the M_CAN sets CCCR.INIT and CCCR.CSA to one
     9) Set CCCR.CCE and reset CCCR.CSR */

  if((Cn->PSR & kCanPSR_ACT_TX) == kCanPSR_ACT_TX) /* #10 check operation */
  { /* operating as transmitter */
    Cn->TXBCR = kCan_ALL_ONE;   /* SBSW_CAN_LL__100 */    /* #20 cancel pending tx requests */
    Cn->CCCR |= kCanCCCR_CSR;   /* SBSW_CAN_LL__100 */    /* #30 issue clock stop request   */

    /* #40 await clock stop acknowledge */
    CanLL_ApplCanTimerStart(kCanLoopClockStop); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & kCanCCCR_CSA) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopClockStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
    { /* Assure that the previous value has been accepted. */ }
    CanLL_ApplCanTimerEnd( kCanLoopClockStop ); /* SBSW_CAN_LL__101 */  

    /* #50 return to normal mode */
    Cn->CCCR &= (vuint32)~(kCanCCCR_CSR | kCanCCCR_INIT);   /* SBSW_CAN_LL__100 */   
    CanLL_ApplCanTimerStart(kCanLoopInit ); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & kCanCCCR_INIT) != 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
    { /* Assure that the previous value written to INIT has been accepted. */ }
    CanLL_ApplCanTimerEnd( kCanLoopInit ); /* SBSW_CAN_LL__101 */  

    /* #60 issue 2'nd clock stop request */
    Cn->CCCR |= kCanCCCR_CSR;   /* SBSW_CAN_LL__100 */   
    CanLL_ApplCanTimerStart(kCanLoopClockStop ); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & kCanCCCR_CSA) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopClockStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
    { /* Assure that the previous value written to CSR has been accepted. */ }
    CanLL_ApplCanTimerEnd( kCanLoopClockStop ); /* SBSW_CAN_LL__101 */  

    /* #70 now CCE can be set */
    Cn->CCCR |= kCanCCCR_CCE;   /* SBSW_CAN_LL__100 */   
    CanLL_ApplCanTimerStart(kCanLoopInit ); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & kCanCCCR_CCE) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
    { /* Assure that the previous value written to CCE has been accepted. */ }
    CanLL_ApplCanTimerEnd( kCanLoopInit ); /* SBSW_CAN_LL__101 */  

    /* #80 reset clock stop request */
    Cn->CCCR &= (vuint32)(~kCanCCCR_CSR);   /* SBSW_CAN_LL__100 */   
  }
  else
  { /* #90 CCE can be set immediately */
    Cn->CCCR |= kCanCCCR_CCE;   /* SBSW_CAN_LL__100 */   
    CanLL_ApplCanTimerStart(kCanLoopInit); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & kCanCCCR_CCE) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
    { /* Assure that the previous value has been accepted. */ }
    CanLL_ApplCanTimerEnd( kCanLoopInit ); /* SBSW_CAN_LL__101 */  
  }
} /* CanBoschErratum_010 */
/* CODE CATEGORY 4 END */ 
#endif
  





/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanErrorHandlingBusOff
****************************************************************************/
/*
|<DataModelStart>| CanErrorHandlingBusOff
Relation_Context:
# from CanLL_BusOffOccured #
Relation:
OneChOpt
ChannelAmount, DynamicMcanRevision
Parameter_PreCompile:
Parameter_Data:
Constrain:
# CAN_BOSCH_ERRATUM_007 #
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanErrorHandlingBusOff(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 ret;
  /* The Bus_Off recovery sequence cannot be shortened by setting or resetting CCCR[INIT.] 
     If the device goes Bus_Off, it will set CCCR[INIT] of its own accord, stopping all bus activities. 
     Once CCCR[INIT] has been cleared by the CPU, the device will then wait for 129 occurrences of Bus Idle 
     (129 x 11 consecutive recessive bits) before resuming normal operation. 
     At the end of the Bus_Off recovery sequence, the Error Management Counters will be reset. 
     During the waiting time after the resetting of CCCR[INIT], each time a sequence of 11 recessive bits has been monitored, 
     a Bit 0 Error code is written to PSR[LEC], enabling the CPU to readily check up whether the CAN bus is stuck at dominant or continuously disturbed 
     and to monitor the Bus_Off recovery sequence. ECR[REC] is used to count these sequences. */
  /* Uncorrected Message RAM bit error detected: BEU sets CCCR[INIT] to '1' to avoid transmission of corrupted data.
     Controlled by Message RAM bit error input signal generated by an optional external ECC logic attached to the Message RAM. */
  /* #10 check error status */
  if( (((Cn->IR & kCanIR_BO)  != 0UL) && ((Cn->PSR & kCanPSR_BO) != 0UL)) /* PRQA S 0303 */ /* MD_Can_HwAccess */
#if ( CAN_MCAN_REVISION >= 0x0300UL ) /* COV_CAN_HW_SPECIFIC */
    || ((Cn->IR & kCanIR_MRAF) != 0UL)  /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
    ) /* COV_CAN_HW_SPECIFIC */
  { 
    /* #20 check for BusOff (BusOff state, Bit Error Uncorrected or Message RAM failure detected) */
    { /* BusOff status changed to BusOff OR Bit Error Uncorrected appeared */
      if(Can_GetCanBusOffNotification(canHwChannel) == kCanBusoff) /* COV_CAN_BUSOFFNOTIFICATION */
      { /* already detected */
      }
      else
      { 
        Can_GetCanBusOffNotification(canHwChannel) = kCanBusoff;  /* SBSW_CAN_LL__112 */ 
      }
    }

#if ( CAN_MCAN_REVISION >= 0x0300UL ) /* COV_CAN_HW_SPECIFIC */
    if(((Cn->IR & kCanIR_MRAF) != 0UL)) /* COV_CAN_MCAN_NOT_SUPPORTED */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    { /* Message RAM annoyance */
      /* #30 check for Restricted Mode, if so try to get back to normal mode */
      if((Cn->CCCR & kCanCCCR_ASM) != 0UL)  /* COV_CAN_MCAN_NOT_SUPPORTED */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
      { /* Regained in Restricted Mode, Tx Handler read problem assumed.
         In Restricted Operation Mode the node is able to receive data and remote frames and to give
         acknowledge to valid frames, but it does not send any frames (data, remote, active error or overload). 
         In case of an error or overload condition, it does not send dominant bits but waits for bus idle to resynchronize itself. */
# if ( CAN_BOSCH_ERRATUM_007 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
       /* Effects:
           With the next transmission after leaving Restricted Operation Mode (reset CCCR.ASM), a frame with an 
           unexpected identifier and control field is transmitted which accidentally might be accepted by another receiver.
           Workaround:
           To recover from Restricted Operation Mode proceed as follows:
           1) Cancel all pending transmission requests by writing 0hFFFF FFFF to register TXBCR
           2) Issue a clock stop request by setting bit CCCR.CSR
           3) Wait until the M_CAN sets CCCR.INIT and CCCR.CSA to one
           4) First reset CCCR.CSR
           5) Then reset CCCR.INIT
           6) Wait until CCCR.INIT is read as zero
           7) Issue a second clock stop request by setting bit CCCR.CSR
           8) Wait until the M_CAN sets CCCR.INIT and CCCR.CSA to one
           9) Set CCCR.CCE, reset CCCR.CSR, and reset CCCR.ASM
           10) Restart M_CAN by writing CCCR.INIT = '0'
           11) Configure the CAN operation mode by writing to CCCR.CMR
           12) Request the transmissions cancelled by step one */
        {
          Cn->TXBCR = kCan_ALL_ONE;          /* SBSW_CAN_LL__100 */  /* cancel all */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
          Cn->CCCR |= (vuint32)kCanCCCR_CSR; /* SBSW_CAN_LL__100 */  /* clock stop request */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
          /*  After CSR first INIT and then CSA will be set after all pending transfer requests have been completed and the CAN bus reached idle. */
          CanLL_ApplCanTimerStart(kCanLoopStop); /* SBSW_CAN_LL__101 */ 
          while( ((Cn->CCCR & kCanCCCR_CSA) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
          { /* Assure that CSA and thus also INIT has been accepted */ }
          CanLL_ApplCanTimerEnd(kCanLoopStop);    /* SBSW_CAN_LL__101 */  
          Cn->CCCR &= (vuint32)~(kCanCCCR_CSR | kCanCCCR_INIT);          /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
          CanLL_ApplCanTimerStart(kCanLoopInit);  /* SBSW_CAN_LL__101 */  
          while( ((Cn->CCCR & kCanCCCR_INIT) != 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
          { /* Assure that INIT has been accepted */ }
          CanLL_ApplCanTimerEnd(kCanLoopInit);    /* SBSW_CAN_LL__101 */  
          Cn->CCCR |= (vuint32)kCanCCCR_CSR;      /* SBSW_CAN_LL__100 */       /* 2'nd clock stop request */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
          CanLL_ApplCanTimerStart(kCanLoopStop); /* SBSW_CAN_LL__101 */  
          while( ((Cn->CCCR & kCanCCCR_CSA) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */
          { /* Assure that CSA and thus also INIT has been accepted */ }
          CanLL_ApplCanTimerEnd(kCanLoopStop);   /* SBSW_CAN_LL__101 */  
          Cn->CCCR |= (vuint32)kCanCCCR_CCE;      /* SBSW_CAN_LL__100 */   /* configuration change enabled */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
          Cn->CCCR &= (vuint32)(~kCanCCCR_CSR);   /* SBSW_CAN_LL__100 */   /* reset CSR  */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
          Cn->CCCR &= (vuint32)(~kCanCCCR_ASM);   /* SBSW_CAN_LL__100 */   /* now leave restricted mode  */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
          /* Step 10) and 11) is accomplished during start transition, 
             Step 12) has to be done by the application! */
        }
# else
        Cn->CCCR &= ( (~kCanCCCR_ASM) );     /* SBSW_CAN_LL__100 */    /* leave Restricted Mode */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
      }
      else
      { /* Rx Handler filtering or access to Message RAM access problem assumed */
        /* At least one message was discarded (kCanIR_UMD for MCAN < 3.0.0) */
      }
    }
    /* #40 reset flags */
#  if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)(kCanIR_BO | kCanIR_MRAF));
#  else
    Cn->IR = (vuint32)(kCanIR_BO | kCanIR_MRAF);                /* SBSW_CAN_LL__100 */    /* reset flags */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  endif
#else  /* CAN_MCAN_REVISION >= 0x0300UL */
    /* #40 reset flags */
#  if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_BO);
#  else
    Cn->IR = (vuint32)(kCanIR_BO);                /* SBSW_CAN_LL__100 */    /* reset flags */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  endif
#endif /* CAN_MCAN_REVISION >= 0x0300UL */
    ret = kCanOk;
  }
  else
  {
    ret = kCanFailed;
  }
  return(ret);
} /* CanErrorHandlingBusOff */
/* CODE CATEGORY 4 END */


/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_SetAllFilter
****************************************************************************/
/*
|<DataModelStart>| CanLL_SetAllFilter
Relation_Context:
# from CanLL_InitBeginSetRegisters #
Relation:
OneChOpt
ChannelAmount, HardwareLoopCheck, IDType, DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_SetAllFilter(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara)
{
#if( CAN_SAFE_BSW == STD_ON ) 
  vuint8 result = kCanOk;
#endif
  /* 10 set std id filter */
#if defined( C_ENABLE_STD_ID ) && (kCanNumberOfStandardFilter > 0)  /* at least one std filter is available */
  initPara->pFS = &Can_GetCanSIDFE(Can_GetCanSIDFEStartIndex(canHwChannel));  /* SBSW_CAN_LL__109 */ 
  for(initPara->tmpVal = 0; initPara->tmpVal < (Can_GetCanSIDFC_LSSOfCanSIDFC(canHwChannel)); (initPara->tmpVal)++) /* SBSW_CAN_LL__109 */  /* SBSW_CAN_LL__109 */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* copy std filter elements to SHM */
# if( CAN_SAFE_BSW == STD_ON ) 
    if( ((vuint32)&ShmSIDF(initPara->stdFeCount).S0 < (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || ((vuint32)&ShmSIDF(initPara->stdFeCount).S0 >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) ) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */  /* COV_CAN_GENDATA_FAILURE */
    { /* SilentBSW check */
      Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
      result = kCanFailed;
    }
    else
# endif
    {
      (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(ShmSIDF(initPara->stdFeCount).S0), (vuint32)(initPara->pFS[initPara->tmpVal]), kCanRegCheckMaskSMIDFE_S0, initPara);   /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__103 */
      (initPara->stdFeCount)++;  /* SBSW_CAN_LL__109 */ 
    }
  }
#endif  /* STD_FILTER */

  /* 20 set ext id filter */
#if defined(C_ENABLE_EXTENDED_ID) && (kCanNumberOfExtendedFilter > 0)
  for(initPara->tmpVal = 0; initPara->tmpVal < (Can_GetCanXIDFC_LSEOfCanXIDFC(canHwChannel)); (initPara->tmpVal)++) /* SBSW_CAN_LL__109 */  /* SBSW_CAN_LL__109 */ 
  { /* copy ext filter elements to SHM */
# if( CAN_SAFE_BSW == STD_ON ) 
    if( ((vuint32)&ShmXIDF(initPara->extFeCount).F0 < (vuint32)Can_GetStartAdrOfShmAdr(canHwChannel)) || ((vuint32)&ShmXIDF(initPara->extFeCount).F0 >= (vuint32)Can_GetStopAdrOfShmAdr(canHwChannel) ) ) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* CM_CAN_LL__103 */ /* COV_CAN_GENDATA_FAILURE */
    { /* SilentBSW check */
      Can_CallDetReportError(CAN_INIT_ID, CAN_E_GENDATA);
      result = kCanFailed;
    }
    else
# endif
    {
      (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(ShmXIDF(initPara->extFeCount).F0), (vuint32)(Can_GetCanXIDFEEIDFE_0OfCanXIDFE(Can_GetCanXIDFEStartIndex(canHwChannel) + initPara->tmpVal)), kCanRegCheckMaskEMIDFE_F0, initPara);  /* SBSW_CAN_LL__103 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
      (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(ShmXIDF(initPara->extFeCount).F1), (vuint32)(Can_GetCanXIDFEEIDFE_1OfCanXIDFE(Can_GetCanXIDFEStartIndex(canHwChannel) + initPara->tmpVal)), kCanRegCheckMaskEMIDFE_F1, initPara);  /* SBSW_CAN_LL__103 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
      (initPara->extFeCount)++; /* SBSW_CAN_LL__109 */ 
    }
  }
#endif /* EXT_FILTER */
#if (!defined( C_ENABLE_STD_ID ) || (kCanNumberOfStandardFilter <= 0u) ) && (!defined(C_ENABLE_EXTENDED_ID) || (kCanNumberOfExtendedFilter <= 0u))
  CAN_DUMMY_STATEMENT(initPara);   /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
CAN_CHANNEL_DUMMY_STATEMENT;  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#if( CAN_SAFE_BSW == STD_ON ) 
  return(result);
#else
  return(kCanOk);
#endif
} /* CanLL_SetAllFilter */
/* CODE CATEGORY 4 END */
 

/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_SetAllRegister
****************************************************************************/
/*
|<DataModelStart>| CanLL_SetAllRegister
Relation_Context:
# from CanLL_InitBeginSetRegisters #
Relation:
OneChOpt
ChannelAmount, IDType, CanFdSupport, RxFullCANSupport, RxBasicCANSupport, MultipleBasicCanObjects
ChannelAmount, HardwareLoopCheck, RxPolling, TxPolling, IndividualPolling, StatusPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
# CAN_BOSCH_ERRATUM_008 #
# CAN_BOSCH_ERRATUM_010 #
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_SetAllRegister(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr initPara)
{
  vuint32 LocalRegValue;
  initPara->tmpVal = 0;     /* SBSW_CAN_LL__109 */    /* PRQA S 2982 */ /* MD_Can_2982_LL */ 
#if defined( C_ENABLE_STD_ID )
  initPara->stdFeCount = 0; /* SBSW_CAN_LL__109 */    /* PRQA S 2982 */ /* MD_Can_2982_LL */
#endif
#if defined(C_ENABLE_EXTENDED_ID)
  initPara->extFeCount = 0; /* SBSW_CAN_LL__109 */    /* PRQA S 2982 */ /* MD_Can_2982_LL */
#endif
  
#if defined(C_ENABLE_STD_ID) 
  CAN_DUMMY_STATEMENT(initPara->stdFeCount);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* SBSW_CAN_LL__109 */ 
#endif
#if defined(C_ENABLE_EXTENDED_ID) 
  CAN_DUMMY_STATEMENT(initPara->extFeCount);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */ /* SBSW_CAN_LL__109 */ 
#endif

  /* #10 assure configuration enable mode */
  /* Initialization is started by setting CCCR[INIT]. This does not change any configuration register.
     M_CAN configuration register access is only enabled when CCCR[INIT] and CCCR[CCE] are set (protected write).
     While CCCR[INIT]==1: 
     - message transfer on CAN bus is stopped, 
     - CAN bus Tx output is recessive. */
  
#if ( CAN_BOSCH_ERRATUM_008 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
  /* When CCCR.INIT is set while the M_CAN is receiving a frame, the next received frame         
     after resetting CCCR.INIT will cause IR.MRAF to be set.
     Effects:
     IR.MRAF is set when the first frame after resetting CCCR.INIT is received although that
     frame is received correctly.
     Workaround:
     1) Issue a clock stop request by setting bit CCCR.CSR
        When clock stop is requested, first CCCR.INIT and then CCCR.CSA will be set 
        after all pending transfer requests have been completed and the CAN bus reached idle.
     2) Wait until the M_CAN sets CCCR.INIT and CCCR.CSA to one
     3) Before resetting CCCR.INIT first reset CCCR.CSR. */
  /*  When CSR is requested, first INIT and then CSA will be set after all pending transfer 
      requests have been completed and the CAN bus reached idle. */
  {
    Cn->CCCR |= kCanCCCR_CSR;   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
    CanLL_ApplCanTimerStart(kCanLoopClockStop ); /* SBSW_CAN_LL__101 */
    while( ((Cn->CCCR & kCanCCCR_CSA) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopClockStop) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
    { /* Assure that CSA/INIT has been accepted. */ }
    CanLL_ApplCanTimerEnd( kCanLoopClockStop ); /* SBSW_CAN_LL__101 */  
  }
#else
  Cn->CCCR = kCanCCCR_INIT;               /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  CanLL_ApplCanTimerStart(kCanLoopInit ); /* SBSW_CAN_LL__101 */  
  while( ((Cn->CCCR & kCanCCCR_INIT) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
  { /* Assure that INIT has been accepted. */ }
  CanLL_ApplCanTimerEnd( kCanLoopInit );  /* SBSW_CAN_LL__101 */  
#endif      
  
#if ( CAN_BOSCH_ERRATUM_010 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
  {
    CanBoschErratum_010(CAN_CHANNEL_CANPARA_ONLY);
  }
#else
  Cn->CCCR = (vuint32)(kCanCCCR_INIT | kCanCCCR_CCE);   /* set all zero */  /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  CanLL_ApplCanTimerStart(kCanLoopInit); /* SBSW_CAN_LL__101 */  
  while( ((Cn->CCCR & kCanCCCR_CCE) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
  { /* Assure that the previous value has been accepted. */ }
  CanLL_ApplCanTimerEnd( kCanLoopInit ); /* SBSW_CAN_LL__101 */  
#endif
  
  /* #20 support additional features via user config file */
  LocalRegValue = Cn->CCCR; /* PRQA S 0303 */ /* MD_Can_HwAccess */
  

  /* #30 support CAN-FD */
#if ( CAN_MCAN_REVISION >= 0x0315UL ) /* COV_CAN_HW_SPECIFIC */
# if ( Can_GetCAN_FD_NISO() == STD_ON)    /* COV_CAN_HW_SPECIFIC */
    LocalRegValue |= (vuint32) kCanCCCR_NISO;
# else
    LocalRegValue &= (vuint32)~kCanCCCR_NISO;
# endif
#endif
  
#if defined( C_ENABLE_CAN_FD_USED )
  if (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) != CAN_NONE)
  {
# if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
      LocalRegValue |= (vuint32)(  kCanCCCR_FDOE | kCanCCCR_BRSE);    /* FD operation, BRS enabled */
# else
      LocalRegValue |= kCanCCCR_CME_LONG_FAST;                       /* enable LONG and FAST */
# endif
  }
  else
  { 
# if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
    /* FD operation disabled */
    LocalRegValue &= (vuint32)(~(kCanCCCR_FDOE | kCanCCCR_BRSE));  /* reset FD bits */
# else
    LocalRegValue &= (vuint32)(~(kCanCCCR_CME_CAN20));            /* enable NORMAL CAN */
# endif
  }
#else
# if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
  /* FD operation disabled */
  LocalRegValue &= (vuint32)(~(kCanCCCR_FDOE | kCanCCCR_BRSE));    /* reset FD bits */
# else
  LocalRegValue &= (vuint32)(~(kCanCCCR_CME_CAN20));               /* enable NORMAL CAN */
# endif
#endif
  /* Write the accumulated CCCR Value to the CCCR Register*/
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->CCCR), (vuint32)LocalRegValue, kCan_ALL_ONE, initPara);  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ 

  /* #40 support Rx FullCAN */
  /* Delete all pending interrupt requests */
  Cn->IR       = kCanIR_CLEAR_ALL; /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS ) 
  Cn->NDATA[0] = kCan_ALL_ONE;     /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  Cn->NDATA[1] = kCan_ALL_ONE;     /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
  
  /* Start value of the Message RAM Watchdog Counter. 
     The RAM Watchdog Counter is clocked by the Host clock. 
     With the reset value of '0' the counter is disabled. */
#if ( CAN_MCAN_REVISION >= 0x0300UL ) /* COV_CAN_HW_SPECIFIC */
  /* Only with ( CAN_BOSCH_ERRATUM_013 == STD_ON )
     This Errata is not considered by the CAN driver (see "Note" below).
     When the M_CAN wants to store a received frame and the Message RAM does not respond in time, 
     this message cannot be stored completely and is discarded. Interrupt flag IR.MRAF is set. 
     It may happen that the next received message is stored incomplete, then the respective 
     Rx Buffer holds inconsistent data.
     Workaround:
     Configure the RAM Watchdog to the maximum expected Message RAM access delay. 
     In case the Watchdog Interrupt IR.WDI is set discard the frame received after IR.MRAF has been activated.
     Note:
     When the M_CAN has been integrated correctly, this can only occur in case of a Message RAM/Arbiter problem.
     if(IR.MRAF .AND. IR.WDI) then just Acknowledge and proceed for further messages. */
#endif
  /* Start value of the Message RAM Watchdog Counter. With the reset value of '0' the counter is disabled. 
     A Message RAM access via the M_CAN's Master Interface starts the Watchdog Counter with RWD.WDC. 
     The counter is reloaded with RWD.WDC when the Message RAM signals successful completion. 
     In case there is no response from the Message RAM until the counter has counted down to zero, 
     the counter stops and IR.WDI is set. 
     The RAM Watchdog Counter is clocked by the Host clock. */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RWD), (vuint32)kCan_RWD, kCanRegCheckMaskRWD, initPara);  /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  
# if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
#  if defined( C_ENABLE_CAN_FD_USED )
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->FBTP, Can_GetCanFBTP(initPara->initObject), kCan_ALL_ONE, initPara );  /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */   /* SBSW_CAN_HL36 */ /* Fast Bit Timing and Prescaler Register (FBTP) */ 
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->TDCR, Can_GetCanTDCR(initPara->initObject), kCan_ALL_ONE, initPara );  /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */   /* SBSW_CAN_HL36 */ /* Transmitter Delay Compensation Register (TDCR.[TDCO|TDCF]) */
#  else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->FBTP, kCanFBTP_TDC_Disable, kCan_ALL_ONE, initPara );                         /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */   /* SBSW_CAN_HL36 */ /* Transceiver Delay Compensation disabled */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->TDCR, kCanTDCR_TDC_Disable, kCan_ALL_ONE, initPara );                         /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */   /* SBSW_CAN_HL36 */ /* Transceiver Delay Compensation disabled */
#  endif
# else  /* MCAN Core Release < 0x310UL */
   
  {
#  if defined( C_ENABLE_CAN_FD_USED )
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->FBTP, Can_GetCanFBTP(initPara->initObject),kCan_ALL_ONE, initPara );  /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */  /* SBSW_CAN_HL36 */ /* Fast Bit Timing and Prescaler Register (FBTP) */
#  else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->FBTP, kCanFBTP_TDC_Disable, kCan_ALL_ONE, initPara );                        /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */  /* SBSW_CAN_HL36 */ /* Transceiver Delay Compensation disabled */
#   endif 
  }
# endif  /* CAN_MCAN_REVISION >= 0x310UL */
  
  /* Bit Timing and Prescaler Register (BTP) */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &Cn->BTP,Can_GetCanBTP(initPara->initObject),kCan_ALL_ONE, initPara );   /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */  /* SBSW_CAN_HL36 */

  /* TSCC-Timestamp Counter Configuration Register */
#if ( CAN_MCAN_REVISION >= 0x0200UL ) /* COV_CAN_HW_SPECIFIC */
# if defined ( C_ENABLE_CAN_FD_USED ) && (kCan_TSCC_TSS > 0)
#  error ">>> Note: With CAN FD an external counter is required for timestamp generation (TSCC.TSS = "10") <<<"
# endif
#endif
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TSCC), (vuint32)(kCan_TSCC_TCP|kCan_TSCC_TSS), kCanRegCheckMaskTSCC, initPara);    /* SBSW_CAN_LL__100 */  /* '0' = keep the counter quiet - otherwise use (kCan_TSCC_TCP|kCan_TSCC_TSS) */
  /* TSCV-Timestamp Counter Value Register 
     With TSCC[TSS] = '01' the Counter is incremented. The counter value is captured on start of frame (both Rx and Tx).
     A wrap around sets interrupt flag IR[TSW].
     Write access resets the counter to zero. */
  Cn->TSCV = 0x00000000UL;   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  
  /* TOCC-Timeout Counter Configuration Register */
  /* Note: If CAN FD BRS feature is used then the timeout counter is clocked differently in arbitration and data field. */
#if ( CAN_BOSCH_ERRATUM_012 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
  {
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TOCC), (vuint32)( (vuint32)(kCan_TOCC_TOP<<16) | kCan_TOCC_TOS | kCan_TOCC_ETOC ), kCanRegCheckMaskTOCC, initPara); /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  }
#else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TOCC), (vuint32)(0UL), kCanRegCheckMaskTOCC, initPara);  /* SBSW_CAN_LL__100 */     /* '0' = keep the counter quiet */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
  /* TOP[15:0]  Timeout Period - Start value of the Timeout Counter (down-counter).
     TOS[29:30] Timeout Select - When operating in Continuous mode, a write to TOCV presets the counter to TOCC[TOP] and continues down-counting. 
                                 00=Continuous operation, 01/10/11=controlled by Tx Event FIFO/by Rx FIFO 0/by Rx FIFO 1
     ETOC[31]   '1' = Enable Timeout Counter */
  /* TOCV-Timeout Counter Value Register
     The Timeout Counter is decremented in multiples of CAN bit times depending on the configuration of TSCC.TCP. 
     When decremented to zero, interrupt flag IR.TOO is set and the Timeout Counter is stopped. 
     Start and reset/restart conditions are configured via TOCC.TOS. */
  Cn->TOCV = 0x00000000UL;   /* SBSW_CAN_LL__100 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */ 
  
  /* The counters of the Error Management Logic EML are unchanged. */
  initPara->tmpVal = Cn->ECR; /* CAN error logging is reset by read access to ECR[CEL] */  /* PRQA S 3198,3199,0303 */ /* MD_MSR_14.2,MD_MSR_14.2,MD_Can_HwAccess */ /* SBSW_CAN_LL__109 */ 
  CAN_DUMMY_STATEMENT(initPara->tmpVal);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */  /* SBSW_CAN_LL__109 */ 
  /* Global settings for Message ID filtering. 
     The GFC controls the filter path for standard and extended messages */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST  &Cn->GFC,Can_GetCanGFC(canHwChannel), kCan_ALL_ONE, initPara );   /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */  /* SBSW_CAN_HL36 */ /* accept/reject non matching and remote (Std/Ext) frames */

  /* Acceptance filtering of ext. frames the "Ext-ID AND Mask (XIDAM)" is ANDed with the received Message ID */
  /* There are two possibilities when range filtering is used together with extended frames:
     EFT = '00': The ID of received frames is ANDed with XIDAM before the range filter is applied
     EFT = '11': XIDAM is not used for range filtering.
     Intended for masking of 29-bit IDs in SAE J1939. With the reset value of all bits set to one the mask is not active. */

  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST  &Cn->XIDAM,(Can_GetCanXIDAM(canHwChannel)), kCan_ALL_ONE, initPara );  /* PRQA S 0303,2986 */ /* MD_Can_HwAccess,MD_Can_ConstValue */  /* SBSW_CAN_HL36 */

#if ( CAN_MCAN_REVISION >= 0x0200UL ) /* COV_CAN_HW_SPECIFIC */
  /* Rx Buffer Start Address (RBSA) configures the start address of the Rx Buffers section in the Message RAM */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXBC), (vuint32)Can_GetCanRXBC(canHwChannel), kCanRegCheckMaskRXBC, initPara);   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */  /* Rx Buffer Start Address (RBSA) configures the start address of the Rx Buffers section in the Message RAM */
# if defined(C_ENABLE_CAN_FD_FULL)
  /* Rx Buffer/FIFO Element Size Configuration (RXESC): number of data bytes for an Rx element, sizes >8 bytes are for CAN FD only.
     RBDS: Rx Buffer Data Field Size = 8,12,16,20,24,32,48,64 byte
     F1DS: Rx FIFO 1 Data Field Size = 8,12,16,20,24,32,48,64 byte
     F0DS: Rx FIFO 0 Data Field Size = 8,12,16,20,24,32,48,64 byte
     Note: In case the data field size of an accepted CAN frame exceeds the data field size configured for the matching Rx element, 
           only the number of bytes as configured by RXESC are stored. The rest of the frame data field is ignored. */
  LocalRegValue = (vuint32)( (((vuint32)Can_GetRBDSOfShmElementSize(canHwChannel))<<8) | (((vuint32)Can_GetF1DSOfShmElementSize(canHwChannel))<<4) | ((vuint32)Can_GetF0DSOfShmElementSize(canHwChannel)) );
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXESC.R), (vuint32)LocalRegValue, kCanRegCheckMaskRXESC, initPara);    /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
# else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXESC.R), (vuint32)(0x00000000UL), kCanRegCheckMaskRXESC, initPara);    /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* Reset to default value */
# endif
#endif
  
  /* #60 support (Multiple) BasicCAN */
#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
  /* Rx FIFO 0 Configuration (RXF0C) */
  if(Can_GetRxBasicHandleMax(canHwChannel) > 0u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF0C.R), (vuint32)(Can_GetCanRXF0C(canHwChannel)), kCanRegCheckMaskRXF0C, initPara);    /* SBSW_CAN_LL__100 */  /* PRQA S 0303 */ /* MD_Can_HwAccess */  /* Using default value kCanRXFnOM_BLOCK */
  }
  else
  { 
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF0C.R), (vuint32)(0x00000000UL), kCanRegCheckMaskRXF0C, initPara);   /* SBSW_CAN_LL__100 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */ 
  }
  /* RXF0S-Rx FIFO 0 Status Register (reset with CCCR.INIT) */
  /* RXF0A-Rx FIFO 0 Acknowledge Register (reset with CCCR.INIT)
     After reading a message (or a sequence of messages) the buffer index of the last element read has to be written to F0AI. 
     This sets the Get Index to F0AI + 1 and updates the Fill Level */
  
# if defined( C_ENABLE_MULTIPLE_BASICCAN )
  /* Rx FIFO 1 Configuration (RXF1C) */
  if(Can_GetRxBasicHandleMax(canHwChannel) > 1u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF1C.R), (vuint32)(Can_GetCanRXF1C(canHwChannel)), kCanRegCheckMaskRXF1C, initPara);    /* SBSW_CAN_LL__100 */  /* PRQA S 0303 */ /* MD_Can_HwAccess */  /* Using default value kCanRXFnOM_BLOCK */
  }
  else
  { 
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF1C.R), (vuint32)(0x00000000UL), kCanRegCheckMaskRXF1C, initPara);   /* SBSW_CAN_LL__100 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */ 
  }
# else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF1C.R), (vuint32)(0x00000000UL), kCanRegCheckMaskRXF1C, initPara);    /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* Fifo 1 not supported */
# endif
  /* RXF1S-Rx FIFO 1 Status Register */
  /* RXF1A-Rx FIFO 1 Acknowledge Register 
     After reading a message (or a sequence of messages) the buffer index of the last element read has to be written to F0AI. 
     This sets the Get Index to F0AI + 1 and updates the Fill Level */
#else /* C_ENABLE_RX_BASICCAN_OBJECTS */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF0C.R), (vuint32)(0x00000000UL), kCanRegCheckMaskRXF0C, initPara);    /* SBSW_CAN_LL__100 */   /* Fifo 0 not supported */  /* PRQA S 0303 */ /* MD_Can_HwAccess */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->RXF1C.R), (vuint32)(0x00000000UL), kCanRegCheckMaskRXF1C, initPara);    /* SBSW_CAN_LL__100 */   /* Fifo 1 not supported */  /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */
  
  /* Tx Buffer Configuration (TXBC): */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TXBC), (vuint32)(Can_GetCanTXBC(canHwChannel)), kCanRegCheckMaskTXBC, initPara);   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  /* #70 support Tx side */
#if( CAN_MCAN_REVISION >= 0x0200UL ) /* COV_CAN_HW_SPECIFIC */
# if defined( C_ENABLE_CAN_FD_FULL )
  /* Tx Buffer Element Size Configuration (TXESC): number of data bytes for a Tx Buffer element, sizes >8 bytes are for CAN FD only. */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TXESC), (vuint32)(Can_GetTBDSOfShmElementSize(canHwChannel)), kCanRegCheckMaskTXESC, initPara);   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  /*  Tx Buffer Data Field Size = 8,12,16,20,24,32,48,64 byte
      Note: In case the data length code DLC of a Tx Buffer element is configured to a value higher than the Tx Buffer data field size, 
      the bytes not defined by the Tx Buffer are transmitted as '0xCC' (padding bytes). */
# else
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TXESC), (vuint32)(0x00000000UL), kCanRegCheckMaskTXESC, initPara);   /* SBSW_CAN_LL__100 */    /* 8 data bytes */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
#endif
  
  /* Tx Event FIFO Configuration (TXEFC) */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TXEFC), (vuint32)(0x00000000UL), kCanRegCheckMaskTXEFC, initPara);   /* SBSW_CAN_LL__100 */    /* No Tx Event Fifo supported */ /* PRQA S 0303 */ /* MD_Can_HwAccess */

  /* #80 interrupt control */
  /* Interrupt registers */
  initPara->ie     = kCanIE_DISABLE_ALL; /* SBSW_CAN_LL__109 */ 
  initPara->txbtie = kCanIE_DISABLE_ALL; /* SBSW_CAN_LL__109 */ 
  
#if !defined(C_ENABLE_RX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
  /* Note: for ASR C_ENABLE_RX_BASICCAN_POLLING is always defined together with C_ENABLE_RX_POLLING */
# if( (!defined( C_ENABLE_RX_BASICCAN_POLLING )) || (defined( C_ENABLE_INDIVIDUAL_POLLING )) )    /* COV_CAN_CBD_COMPATIBILITY */
  if(Can_GetRxBasicHandleMax(canHwChannel) > 0u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
#  if defined( C_ENABLE_INDIVIDUAL_POLLING )
    if(Can_IsMailboxIndivPolling(CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel)) == FALSE) /* PRQA S 1881 */ /* MD_MSR_AutosarBoolean */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#  endif
    {
      initPara->ie |= kCanIR_RF0N; /* SBSW_CAN_LL__109 */ /* use new msg */
    }
  }
#  if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if(Can_GetRxBasicHandleMax(canHwChannel) > 1u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
#   if defined( C_ENABLE_INDIVIDUAL_POLLING )
    if(Can_IsMailboxIndivPolling(CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel) + 1u) == FALSE) /* PRQA S 1881 */ /* MD_MSR_AutosarBoolean */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#   endif
    {
      initPara->ie |= kCanIR_RF1N; /* SBSW_CAN_LL__109 */   /* use new msg */
    }
  }
#  endif
# endif 
# if defined( C_ENABLE_RX_FULLCAN_OBJECTS )  
  /* C_ENABLE_RX_FULLCAN_POLLING is always defined together with C_ENABLE_RX_POLLING */
  initPara->ie |= (kCanIR_DRX); /* SBSW_CAN_LL__109 */   /*    Bit 12 DRX     Message stored to Dedicated Rx Buffer */
  /* After the last word of a matching Rx message has been written to the Message RAM the NDF within NDAT1,2 is set. 
     As long as the NDF is set, the respective Rx Buffer is locked. The NDF has to be reset by the Host.
     While a specific NDF is set the refering Filter Element will not match, causing the acceptance filtering to continue. 
     Subsequent Filter Elements may cause the received message to be stored into 
     - another Rx Buffer, or 
     - an Rx FIFO, or
     - the message may be rejected. */
# endif /* ( C_ENABLE_RX_FULLCAN_OBJECTS ) */
  
#endif  /* (!C_ENABLE_RX_POLLING) || ( C_ENABLE_INDIVIDUAL_POLLING ) */  
  
#if !defined(C_ENABLE_TX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
  /* Bit 19 TEFNE   Tx Event FIFO New Entry Interrupt Enable
     Bit 21 TCFE    Transmission Cancellation Finished Interrupt Enable
     Bit 22 TCE     Transmission Completed Interrupt Enable */
  initPara->ie |= (kCanIR_TC); /* SBSW_CAN_LL__109 */
#endif
#if !defined(C_ENABLE_ERROR_POLLING)
  initPara->ie |= (kCanIR_BO); /* SBSW_CAN_LL__109 */   /* BusOff */
#if ( CAN_MCAN_REVISION >= 0x0300UL ) /* COV_CAN_HW_SPECIFIC */
  initPara->ie |= (kCanIR_MRAF); /* SBSW_CAN_LL__109 */ 
#endif
  /* Bit 0  STEE    Stuff Error Interrupt Enable
     Bit 1  FOEE    Format Error Interrupt Enable
     Bit 2  ACKEE   Acknowledge Error Interrupt Enable
     Bit 3  BEE     Bit Error Interrupt Disable
     Bit 4  CRCEE   CRC Error Interrupt Enable
     Bit 5  WDIE    Watchdog Interrupt Enable
     Bit 6  BOE     Bus_Off Status Interrupt Enable
     Bit 7  EWE     Warning Status Interrupt Enable
     Bit 8  EPE     Error Passive Interrupt Enable
     Bit 9  ELO     Error Logging Overflow Enable
     Bit10  BEU     Bit Error Uncorrected Enable
     Bit11  BEC     Bit Error Corrected Enable
     Bit17  MRAF    Message RAM Access Failure (since MCAN 3.0.0)
     Bit27  PEA     Protocol Error in Arbitration Phase (since MCAN 3.1.0) */
# if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
  if(Can_GetRxBasicHandleMax(canHwChannel) > 0u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    initPara->ie |= kCanIR_RF0L;  /* use overrun */ /* SBSW_CAN_LL__109 */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  }
#  if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if(Can_GetRxBasicHandleMax(canHwChannel) > 1u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    initPara->ie |= kCanIR_RF1L;  /* use overrun */ /* SBSW_CAN_LL__109 */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  }
#  endif
# endif
#endif

  /* #90 if available keep TTCAN quiet */
#if defined ( C_ENABLE_TTCAN_AVAILABLE ) /* COV_CAN_HW_SPECIFIC */
  if(Can_IsIsTTCan(canHwChannel)) /* TTCAN */ /* COV_CAN_HW_SPECIFIC */
  {
    /* TT Operation Configuration Register:  Event-driven CAN communication, Application Watchdog disabled  */
    (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->TTOCF), (vuint32)(0x00000000UL), kCanRegCheckMaskTTOCF, initPara);   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
  }
#endif

  return(kCanOk); /* independent of RAM Check failure(s) returned within para struct */
} /* PRQA S 6010,6030,6050 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL */ 
/* CanLL_SetAllRegister */
/* CODE CATEGORY 4 END */

/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_SetExtraRegister
****************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanLL_SetExtraRegister(CAN_CHANNEL_CANTYPE_FIRST CanInitParaStructPtr localInfo)
{
  CAN_ENDINIT_PROTECT_OFF();
  /* Access Enable Register */
  CAN_SET_OSVALUE_32_CHANNEL(&(Cn->ACCENNODE0),(vuint32)(kCanEnableMemAccess),kCanRegCheckMaskMCMCAN_ACCENNODE0,localInfo); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  /* Start Address Register */
  CAN_SET_OSVALUE_32_CHANNEL(&(Cn->STARTADR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_STARTADR,localInfo); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  /* End Address Register */
  CAN_SET_OSVALUE_32_CHANNEL(&(Cn->ENDADR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_ENDADR,localInfo); /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  /* Interrupt routing */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->GRINT1),(vuint32)(Can_GetINT_RoutingGroup(canHwChannel)),kCanRegCheckMaskMCMCAN_GRINT, localInfo); /* select Interrupt output line INT_O0 */ /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->GRINT2),(vuint32)(Can_GetINT_RoutingGroup(canHwChannel)),kCanRegCheckMaskMCMCAN_GRINT, localInfo); /* for each CAN channel */ /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  /* Node Timer Clock Control Register */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->NTCCR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_NTCCR, localInfo); /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  /* Node Timer X Transmit Trigger Register */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->NTATTR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_NTXTTR, localInfo); /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->NTBTTR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_NTXTTR, localInfo); /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->NTCTTR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_NTXTTR, localInfo); /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
  /* Node Timer Receive Timeout Register */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->NTRTR),(vuint32)(0x00000000UL),kCanRegCheckMaskMCMCANCH_NTRTR, localInfo); /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */
 /* Node Port Control Register */
  (void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->NPCR),(vuint32)(Can_GetRxSelectionOfControllerConfig(canHwChannel)),kCanRegCheckMaskMCMCAN_NPCR, localInfo); /* SBSW_CAN_LL__100 */ /* SBSW_CAN_HL36 */

#  if !defined(C_ENABLE_USE_OS_INTERRUPT_CONTROL) /* COV_CAN_OS_INT_CONTROL */ 
#   if ( (((CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH))) )
#    if defined( C_ENABLE_ISR_MANDATORY )
  /* [0..7] ISRPrio, [10] Service Request enable, [11..12] TOS=TriCore interrupt: 0=CPU0, 1=DMA, 2=CPU1, 3=CPU2, 4=CPU3, 5=CPU4, 6=CPU5 */
  CAN_WRITE_SRN_PROTECTED_REG32(CAN_PROTECTED_AREA_SRN,Can_GetSRN_Address(canHwChannel),(vuint32)( (vuint32)kCanSRCR_Mask & ( ((vuint32)Can_GetINT_Priority(canHwChannel) | (1u << 10u)) | (Can_GetkCanUsedCore() << 11u) ) )); /* PRQA S 0306,2986,2985 */ /* MD_Can_0306_HWaccess_LL,MD_Can_ConstValue,MD_Can_ConstValue */ /* SBSW_CAN_LL__119 */
#    endif
#   endif
#  endif
  CAN_ENDINIT_PROTECT_ON();
  



#if defined( C_ENABLE_SHM_DATAQOS) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
(void)CanLL_WriteReg32(CAN_CHANNEL_CANPARA_FIRST &(Cn->MRCFG), (vuint32)(Can_GetCAN_DataQoS()), kCanRegCheckMaskMRCFG_DATAQOS, localInfo); /* Set Data Quality of Service */
#endif

}
/* CanLL_SetExtraRegister */
/* CODE CATEGORY 4 END */


#if ((defined( C_ENABLE_RX_BASICCAN_OBJECTS ) && !defined( C_ENABLE_RX_BASICCAN_POLLING )) || \
       defined( C_ENABLE_INDIVIDUAL_POLLING ) )        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanBasicInterruptRx
****************************************************************************/
/*
|<DataModelStart>| CanBasicInterruptRx
Relation_Context:
# CanInterrupt() #
Relation:
OneChOpt
ChannelAmount
RxBasicCANSupport, MultipleBasicCanObjects, RxPolling, TxPolling, IndividualPolling, HardwareLoopCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanBasicInterruptRx(CAN_HW_CHANNEL_CANTYPE_ONLY) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
{
  /* #30 check Fifo - 0 (BasicCAN0) for new data */
  if( ((Cn->IR) & kCanIR_RF0N) != 0UL)  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  { /* rcvd new msg in FIFO 0 */
# if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_RF0N);
# else
    Cn->IR = (kCanIR_RF0N);   /* SBSW_CAN_LL__100 */    /* clear */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
# if defined( C_ENABLE_INDIVIDUAL_POLLING )
    if(Can_IsMailboxIndivPolling(CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel)))  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    { 
      /* poll this object later on during the next read task cycle */ 
    }
    else
# endif
    {
      CanLL_ApplCanTimerStart(kCanLoopRxFifo ); /* SBSW_CAN_LL__102 */  
      while( (((Cn->RXF0S).B.FnFL) > 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopRxFifo) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        CanHL_BasicCanMsgReceived(CAN_HW_CHANNEL_CANPARA_FIRST (CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel)), (CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) );
      }
      CanLL_ApplCanTimerEnd( kCanLoopRxFifo); /* SBSW_CAN_LL__102 */  
    }
  }

# if defined( C_ENABLE_MULTIPLE_BASICCAN )
  /* #40 check Fifo - 1 (BasicCAN1) for new data */
  if( ((Cn->IR) & kCanIR_RF1N) != 0UL)  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* Rcvd new msg in FIFO 1 */
#  if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_RF1N);
#  else
    Cn->IR = (kCanIR_RF1N); /* SBSW_CAN_LL__100 */ /* Clear */
#  endif
#  if defined( C_ENABLE_INDIVIDUAL_POLLING )
    if(Can_IsMailboxIndivPolling(CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel) + 1u)) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    {
      /* poll this object later on during the next read task cycle */ 
    }
    else
#  endif
    {
      CanLL_ApplCanTimerStart(kCanLoopRxFifo ); /* SBSW_CAN_LL__102 */  
      while( (((Cn->RXF1S).B.FnFL) > 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopRxFifo) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
      {
        /* Increment the rxObjHandle. There is an  additional mailbox object for FIFO-1 */
        CanHL_BasicCanMsgReceived(CAN_HW_CHANNEL_CANPARA_FIRST (CAN_HL_MB_RX_BASIC_STARTINDEX(canHwChannel)), (CAN_HL_HW_RX_BASIC_STARTINDEX(canHwChannel)) + 1u); 
      }
      CanLL_ApplCanTimerEnd( kCanLoopRxFifo); /* SBSW_CAN_LL__102 */  
    }
  }
# endif /* C_ENABLE_MULTIPLE_BASICCAN */
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */  
/* CanBasicInterruptRx */
/* CODE CATEGORY 4 END */
#endif

#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
# if (!defined( C_ENABLE_RX_FULLCAN_POLLING ) || defined( C_ENABLE_INDIVIDUAL_POLLING ))        /* ISR necessary; no pure polling configuration*/
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanFullInterruptRx
****************************************************************************/
/*
|<DataModelStart>| CanFullInterruptRx
Relation_Context:
# CanInterrupt() #
Relation:
OneChOpt
ChannelAmount
RxFullCANSupport, RxPolling, TxPolling, IndividualPolling, HardwareLoopCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanFullInterruptRx(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint32 ndata[2], shiftVal;
  vuint8  ndf, idx, objNumber;

  /* #20 check RxBuffer (FullCAN) for new data */
  /* Rx Buffer Handling
    - Reset interrupt flag IR.DRX
    - Read New Data registers
    - Read messages from Message RAM
    - Reset New Data flags of processed messages */
  if( ((Cn->IR) & kCanIR_DRX ) != 0UL)  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* rcvd FullCAN msg(s) */
# if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_DRX);
# else
    Cn->IR = (kCanIR_DRX);   /* SBSW_CAN_LL__100 */  /* Reset interrupt flag */
# endif
    ndata[0] = Cn->NDATA[0]; /* SBSW_CAN_LL__106 */  /* Read New Data registers */
    ndata[1] = Cn->NDATA[1]; /* SBSW_CAN_LL__106 */
    /* After the last word of a matching received message has been written to the Message RAM, the respective New Data flag in register NDAT1,2 is set. 
       As long as the New Data flag is set, the respective Rx Buffer is locked against updates from received matching frames. */
    ndf = 0;
    idx = 0;
    objNumber = 0;
    while( ((ndata[0] | ndata[1]) > 0UL) && (idx < 2u) ) /* CM_CAN_LL__107 */  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    { /* at least one buffer not read yet AND first sweep */
      shiftVal = (vuint32)(0x00000001UL << ndf);
      if((ndata[idx] & shiftVal) != 0UL)
      { /* detected NDF */
#  if defined( C_ENABLE_INDIVIDUAL_POLLING )
        if(Can_IsMailboxIndivPolling(CAN_HL_MB_RX_FULL_STARTINDEX(canHwChannel) + objNumber))  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
        { 
          /* poll this object later on during the next read task cycle */ 
        }
        else
#  endif
        { /* Attention:
             While an Rx Buffers NDF is set the belonging ID Filter will not match, causing the acceptance filtering to continue. 
             Following ID Filters may cause the received message to be stored into another Rx Buffer or into an Rx FIFO or the message may be rejected. */
          CanHL_FullCanMsgReceived(CAN_HW_CHANNEL_CANPARA_FIRST (CAN_HL_MB_RX_FULL_STARTINDEX(canHwChannel)) +objNumber, ((CAN_HL_HW_RX_FULL_STARTINDEX(canHwChannel)) + objNumber) );
        }
        ndata[idx] &= (vuint32) (~shiftVal); /* reset NDF */  /* SBSW_CAN_LL__107 */
      }
      objNumber++;
      ndf++;
      if(ndf >= 32u)  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* next 32 FullCAN Buffers */
        ndf = 0u;
        idx += 1u;
      }
    } /* endwhile */
  } /* endif Rx FullCAN interrupt */
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */  
/* CanFullInterruptRx */
/* CODE CATEGORY 4 END */
# endif
#endif


/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanInterruptErrorHandling
****************************************************************************/
/*
|<DataModelStart>| CanInterruptErrorHandling
Relation_Context:
# CanInterrupt() #
Relation:
OneChOpt
ChannelAmount
StatusPolling, RxBasicCANSupport, MultipleBasicCanObjects
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
#if !defined(C_ENABLE_ERROR_POLLING)
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanInterruptErrorHandling(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 ret;
  vuint32 CanLocal_IR;

  /* #10 check error status and call error handling */
  CanLocal_IR = Cn->IR; /* PRQA S 0303 */ /* MD_Can_HwAccess */
  /* #20 check for Message Lost */
# if defined( C_ENABLE_MULTIPLE_BASICCAN )
  if(((CanLocal_IR & Cn->IE & kCanIR_RF0L) != 0UL) || ((CanLocal_IR & Cn->IE & kCanIR_RF1L) != 0UL)) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# else
  if( (CanLocal_IR & Cn->IE & kCanIR_RF0L) != 0UL)                                            /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
  { /* msg lost due to either FIFO 0/1 full or with size zero */
    CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY); /* call Interrupt handling with logical channel */
    /* #30 clear overflow flags */
# if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)(kCanIR_RF0L | kCanIR_RF0F | kCanIR_RF1L | kCanIR_RF1F));
# else
    Cn->IR = (vuint32)(kCanIR_RF0L | kCanIR_RF0F | kCanIR_RF1L | kCanIR_RF1F);   /* SBSW_CAN_LL__100 */   /* PRQA S 0303 */ /* MD_Can_HwAccess */     /* clear flag(s) */
# endif
  }

  ret = kCanFailed; /* do not proceed with further IR Flags evaluation */
  /* #40 check for Message RAM failure */
  if( (CanLocal_IR & Cn->IE & kCanIR_BO) != 0u) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  { /* Bus_Off status changed */
    CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY); /* call Interrupt handling with logical channel */
    /*  In contrast to Bus_Off neither Warning-/Error- status nor ACK or CRC errors are considered (kCanIR_EW,kCanIR_EP,kCanIR_ACKE, kCanIR_CRCE,) */
    /* #70 clear busoff error flags */
# if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_BO);
# else
    Cn->IR = (kCanIR_BO);   /* SBSW_CAN_LL__100 */    /* clear flag */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
  }
# if ( CAN_MCAN_REVISION >= 0x0300UL ) /* COV_CAN_HW_SPECIFIC */
  /* #80 check for access failure flags */
  else if( (CanLocal_IR & Cn->IE & kCanIR_MRAF) != 0UL) /* COV_CAN_MCAN_NOT_SUPPORTED */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  { /* Message RAM Access Failure
        The flag is set, when the Rx Handler
        - has not completed acceptance filtering or storage of an accepted message until the arbitration
        field of the following message has been received. In this case acceptance filtering or message
        storage is aborted and the Rx Handler starts processing of the following message.
        - was not able to write a message to the Message RAM. In this case message storage is aborted.
        In both cases the FIFO put index is not updated resp. the New Data flag for a dedicated Rx Buffer
        is not set, a partly stored message is overwritten when the next message is stored to this location.
        
        The flag is also set when the Tx Handler 
        - was not able to read a message from the Message RAM in time. 
        In this case message transmission is aborted. 
        In case of a Tx Handler access failure the M_CAN is switched into Restricted Operation Mode.  */
    CanHL_ErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY); /* call Interrupt handling with logical channel */
    /* #90 clear access failure flags */
#  if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_MRAF);
#  else
    Cn->IR = (kCanIR_MRAF);   /* SBSW_CAN_LL__100 */    /* clear flag */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#  endif
  } 
# endif /* CAN_MCAN_REVISION */
  else
  {
    ret = kCanOk;  /* PRQA S 2400 */ /* test_MD_Can_2004_14.10 */
  }
  return(ret);
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
/* CanInterruptErrorHandling */
/* CODE CATEGORY 4 END */
#endif


/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanInterruptTx
****************************************************************************/
/*
|<DataModelStart>| CanInterruptTx
Relation_Context:
# CanInterrupt() #
Relation:
OneChOpt
ChannelAmount, TxPolling, IndividualPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
#if !defined(C_ENABLE_TX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanInterruptTx(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8  hwObjHdl;
  vuint8  mboxHdl;
  vuint8  mboxElm; 
  vuint32 bPos;
  vuint32 CanLocal_IR;

  CanLocal_IR = Cn->IR; /* PRQA S 0303 */ /* MD_Can_HwAccess */
  /* #10 check transmit status */
  if( (CanLocal_IR & Cn->IE & kCanIR_TC) != 0UL) /* COV_CAN_TX_INTERRUPT */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  { /* Tx Confirmation */
    /* #20 clear flags */
# if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
    CanLL_TriCoreErratum_AI_H001(CAN_HW_CHANNEL_CANPARA_FIRST (vuint32)kCanIR_TC);
# else
    Cn->IR = (kCanIR_TC);   /* SBSW_CAN_LL__100 */    /* clear */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
# endif
    /* Each Tx Buffer has its own Transmission Occurred bit. 
       The bits are set when the corresponding TXBRP bit is cleared after a successful transmission. 
       The bits are reset when a new transmission is requested by writing a '1' to the corresponding bit of register TXBAR. */
    bPos = kCanACTIVE;
    hwObjHdl = 0;
    /* #30 check for Transmit Confirmation */
    while ( (hwObjHdl < kCanTXBC_NDTB) && (Can_GetCanTXBRP(canHwChannel) > 0UL) )
    { /* at least one transmission is pending */
      mboxHdl = Can_GetMailboxHandleOfMemorySectionObjects( Can_GetMemorySectionStartOfMemorySectionInfo(canHwChannel) + hwObjHdl);
      mboxElm = Can_GetMailboxElementOfMemorySectionObjects(Can_GetMemorySectionStartOfMemorySectionInfo(canHwChannel) + hwObjHdl);
      if( ((Can_GetCanTXBRP(canHwChannel) & bPos) != 0UL) && ( ((Cn->TXBTO & bPos) != 0UL) ) ) /* COV_CAN_HW_SPECIFIC */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
      { /* found requested confirmation */
# if defined( C_ENABLE_INDIVIDUAL_POLLING )
        if(Can_IsMailboxIndivPolling(mboxHdl)) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
        { /* poll this object */
        }
        else
# endif
        {
          CanHL_TxConfirmation(CAN_CHANNEL_CANPARA_FIRST mboxHdl, mboxElm, hwObjHdl);
        }
      }
      hwObjHdl++;
      bPos <<= 1;
    } /* end while */
  }  /* endif TC */

} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
/* CanInterruptTx */
/* CODE CATEGORY 4 END */
#endif



#if( CAN_BOSCH_ERRATUM_012 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanInterruptTimeoutCounter
****************************************************************************/
/*
|<DataModelStart>| CanInterruptTimeoutCounter
Relation_Context:
# CanInterrupt() #
Relation:
OneChOpt
ChannelAmount
HardwareLoopCheck
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanInterruptTimeoutCounter(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  /* timeout arrived */

  /* The erratum is limited to the case where a receiving M_CAN with PXHD enabled enters Bus Integration state 
     after detection of bits FDF and res both recessive.
     Effects:
     The receiver stops for an unpredictable amount of time.
     To leave Bus Integration state, at least one dominant bit has to be detected by a receiving
     M_CAN to start counting of 11 consecutive recessive bits.
     With Protocol Exception Handling enabled (CCCR.PXHD = '0'):
      - PSR.PXE (Protocol Exception Event) is signalled
      - Operation state changes from Receiver (PSR.ACT = '10') to Integrating (PSR.ACT = '00') at the next sample point.
      Workaround:
       R3.1.0: disable Protocol Exception Event Handling (CCCR.PXHD = '1')
       Other revisions: set and release INIT  */
  /* #10 check for protocol error */
#  if ( CAN_MCAN_REVISION >= 0x310UL ) /* COV_CAN_HW_SPECIFIC */
  if( ((Cn->CCCR & kCanCCCR_PXHD) == 0UL) && ((Cn->PSR & kCanPSR_PXE) != 0UL) && ((Cn->PSR & kCanPSR_ACT) == 0UL) ) /* COV_CAN_HW_SPECIFIC */
#  elif ( CAN_MCAN_REVISION >= 0x0300UL ) /* COV_CAN_HW_SPECIFIC */
  if( ((Cn->PSR & kCanPSR_BO) == 0UL) && ((Cn->PSR & kCanPSR_ACT) == 0UL) )
#  endif /* CAN_MCAN_REVISION */
  { /* PXE and ACT is reset on read.
       Note: Disable Protocol Exception Handling 'CCCR.PXHD = 1' generates an error frame thus we prefer this workaround */
    /* #20 accomplish propagated workaround */
    Cn->CCCR |= kCanCCCR_INIT; /* SBSW_CAN_LL__100 */  /* Setting INIT means the MCAN node is detached from the CAN Bus, the Tx Pin becomes recessive '1'.
                                                           During INIT = '1' the MCAN is stopped, all other nodes are not disturbed.) */
    CanLL_ApplCanTimerStart(kCanLoopInit ); /* SBSW_CAN_LL__102 */  
    while( ((Cn->CCCR & kCanCCCR_INIT) == 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopInit) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
    { /* Assure that INIT has been accepted */ }
    CanLL_ApplCanTimerEnd( kCanLoopInit );  /* SBSW_CAN_LL__102 */  
    Cn->CCCR &= (vuint32)(~kCanCCCR_INIT);  /* SBSW_CAN_LL__100 */   
  }

  /* #30 keep counter running for further supervision */
  /* further periodical interruption requested due to PSR monitoring */
  Cn->TOCV = 0; /* SBSW_CAN_LL__100 */ /* When the counter reaches zero IR.TOO is set. In Continuous Mode the counter is immediately restarted at TOCC.TOP.
                                           Thus reload counter once more NOW (before clearing the IR) with TOCC[TOP] and continue down counting */
  Cn->IR = kCanIR_TOO;   /* SBSW_CAN_LL__100 */    /* clear */
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
/* CanInterruptTimeoutCounter */
/* CODE CATEGORY 4 END */
#endif




/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_StartRequest
****************************************************************************/
/*
|<DataModelStart>| CanLL_StartRequest
Relation_Context:
# from CanLL_ModeTransition #
Relation:
OneChOpt
ChannelAmount
HardwareLoopCheck
DevErrorDetect	
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_StartRequest(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 transitionRequest;
  transitionRequest = kCanOk; /* PRQA S 2982 */ /* MD_Can_2982_LL */

  /* #10 requested mode already reached */
  if((Cn->CCCR & kCanCCCR_INIT) == 0UL)  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
  {
    transitionRequest = kCanOk;
  }
  else
  {
    /* #20 request mode transition if not reached yet */
    /* request RUNNING mode finish Power Down:
       a) Reset CCCR[CSR] (before resetting the CSR bit the module clocks must have been turned on by the application)
       b) M_CAN will acknowledge the reset of the CSR bit by resetting CCCR[CSA]. 
       c) Now the application can reset CCCR[INIT] to restart the CAN communication */
    ApplCanClockStart(CAN_HW_CHANNEL_CANPARA_ONLY);        /* request the application to turn on the clocks (CAN, Host) */
    Cn->CCCR &= (vuint32)~(kCanCCCR_CSR | kCanCCCR_INIT);   /* SBSW_CAN_LL__100 */   /* Cancel Power Down request and get back to Normal Mode */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    /* To leave power down mode, the application has to turn on the module clocks before resetting CCCR.CSR. 
       MCAN will acknowledge this by resetting CCCR.CSA. 
       Afterwards, the application can restart CAN communication by resetting bit CCCR.INIT. */
    /* After resetting CCCR[INIT] the Bit Stream Processor (BSP) synchronizes itself to the data transfer 
       on the CAN bus by waiting for Bus_Idle (sequence of 11 consecutive recessive bits) .
       CCCR[CCE] is automatically reset when CCCR[INIT] is reset. */
    /* CCCR_: INIT, CCE, ASM, CSR, MON, DAR, TEST disabled (automated retransmission is enabled) */

    /* #30 check current state: if already reached then avoid asynchronous all */
    CanLL_ApplCanTimerStart(kCanLoopStart); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & kCanCCCR_INIT) != 0UL) && (CanLL_ApplCanTimerLoop(kCanLoopStart) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */
    {/* Assure that INIT has been accepted. */}
    CanLL_ApplCanTimerEnd(kCanLoopStart); /* SBSW_CAN_LL__101 */  
    if ( (Cn->CCCR & kCanCCCR_INIT) != 0UL) /* COV_CAN_TRANSITION_REQUEST */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    {
      transitionRequest = kCanRequested; /* assure start mode request*/
    }
  }

  return(transitionRequest);
} /* CanLL_StartRequest */
/* CODE CATEGORY 4 END */


#if defined(C_ENABLE_SILENT_MODE) 
/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_StartSilentRequest
****************************************************************************/
/*
|<DataModelStart>| CanLL_StartRequest
Relation_Context:
# from CanLL_ModeTransition #
Relation:
OneChOpt
ChannelAmount
SilentMode, HardwareLoopCheck
DevErrorDetect	
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_StartSilentRequest(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 transitionRequest;
  transitionRequest = kCanOk; /* PRQA S 2982 */ /* MD_Can_2982_LL */

  /* #10 requested mode already reached */
  if( ((Cn->CCCR & (kCanCCCR_MON | kCanCCCR_ASM | kCanCCCR_INIT)) == (kCanCCCR_MON | kCanCCCR_ASM)) )   /* COV_CAN_HARDWARE_FAILURE */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
  {
  }
  else
  {
    /* #20 request mode transition if not reached yet */
    /* request RUNNING mode finish Power Down:
       a) Reset CCCR[CSR] (before resetting the CSR bit the module clocks must have been turned on by the application)
       b) M_CAN will acknowledge the reset of the CSR bit by resetting CCCR[CSA]. 
       c) Now the application can reset CCCR[INIT] to restart the CAN communication */
    ApplCanClockStart(CAN_HW_CHANNEL_CANPARA_ONLY);        /* request the application to turn on the clocks (CAN, Host) */
    { /* start in silent mode */
      Cn->CCCR |= kCanCCCR_INIT;                /* SBSW_CAN_LL__100 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
      Cn->CCCR |= kCanCCCR_CCE;                 /* SBSW_CAN_LL__100 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
      Cn->CCCR |= kCanCCCR_MON | kCanCCCR_ASM;  /* SBSW_CAN_LL__100 */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    }
    Cn->CCCR &= (vuint32)~(kCanCCCR_CSR | kCanCCCR_INIT);   /* SBSW_CAN_LL__100 */   /* Cancel Power Down request and get back to Normal Mode */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    /* To leave power down mode, the application has to turn on the module clocks before resetting CCCR.CSR. 
       MCAN will acknowledge this by resetting CCCR.CSA. 
       Afterwards, the application can restart CAN communication by resetting bit CCCR.INIT. */
    /* After resetting CCCR[INIT] the Bit Stream Processor (BSP) synchronizes itself to the data transfer
       on the CAN bus by waiting for Bus_Idle (sequence of 11 consecutive recessive bits) .
       CCCR[CCE] is automatically reset when CCCR[INIT] is reset. */
    /* CCCR_: INIT, CCE, ASM, CSR, MON, DAR, TEST disabled (automated retransmission is enabled) */

    /* #30 check current state: if already reached then avoid asynchronous all */
    CanLL_ApplCanTimerStart(kCanLoopStart); /* SBSW_CAN_LL__101 */  
    while( ((Cn->CCCR & (vuint32)(kCanCCCR_MON | kCanCCCR_ASM | kCanCCCR_INIT)) != (kCanCCCR_MON | kCanCCCR_ASM)) && (CanLL_ApplCanTimerLoop(kCanLoopStart) !=  CAN_NOT_OK) ) /* PRQA S 1881,4558,3415,0303 */ /* MD_MSR_AutosarBoolean,MD_Can_4558_RHsideEffect,MD_Can_4558_RHsideEffect,MD_Can_HwAccess */ /* COV_CAN_HW_SPECIFIC */ 
    {/* Assure that INIT/SILENT has been accepted. */}
    CanLL_ApplCanTimerEnd(kCanLoopStart); /* SBSW_CAN_LL__101 */  
    if( ((Cn->CCCR & (kCanCCCR_MON | kCanCCCR_ASM | kCanCCCR_INIT)) != (kCanCCCR_MON | kCanCCCR_ASM)) )   /* COV_CAN_HARDWARE_FAILURE */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    {
      transitionRequest = kCanRequested; /* assure silent mode request*/
    }
  }

  return(transitionRequest);
} /* CanLL_StartSilentRequest */
/* CODE CATEGORY 4 END */
#endif

/* CODE CATEGORY 4 START */
/****************************************************************************
| NAME:             CanLL_StopRequest
****************************************************************************/
/*
|<DataModelStart>| CanLL_StopRequest
Relation_Context:
# from CanLL_ModeTransition #
Relation:
OneChOpt
ChannelAmount
DevErrorDetect	
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, vuint8, STATIC_CODE) CanLL_StopRequest(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  vuint8 transitionRequest;
  transitionRequest = kCanFailed; /* PRQA S 2982 */ /* MD_Can_2982_LL */

  /* #10 check current state */
  if( (Cn->CCCR & kCanCCCR_INIT) == 0UL) /* PRQA S 0303 */ /* MD_Can_HwAccess */
  { /* in normal operating mode */
    Cn->TXBCR = kCan_ALL_ONE;   /* SBSW_CAN_LL__100 */ /* cancel any pending request */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
    /* While CCCR[INIT] is set, message transfer from and to the CAN bus is stopped, the status of the CAN bus transmit output is recessive (HIGH). 
       Setting CCCR[INIT] does not change any configuration register. 
       After resetting CCCR[INIT] the Bit Stream Processor (BSP) synchronizes itself to the data transfer on the CAN bus 
       by waiting for the occurrence of a sequence of 11 consecutive recessive bits (= Bus_Idle) before it can take part in bus activities and start the message transfer. */
#if ( CAN_BOSCH_ERRATUM_008 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
    /* When CCCR.INIT is set while the M_CAN is receiving a frame, the next received frame         
       after resetting CCCR.INIT will cause IR.MRAF to be set.
        Workaround:
        1) Issue a clock stop request by setting bit CCCR.CSR
        2) Wait until the M_CAN sets CCCR.INIT and CCCR.CSA to one
           Before resetting CCCR.INIT first reset CCCR.CSR. */
#endif
    /* #20 request mode transition if not reached yet */
    /* Put HW to halt mode, if it is not already there */
    /*  Power down:
        The M_CAN can be set into power down mode via CCCR[CSR]. 
        When clock stop is requested (CCCR[CSR]='1') first INIT and then CSA will be set after all pending transfer requests are completed and the CAN bus reached idle.
        1)  As long as the clock stop request signal is active, bit CCCR[CSR] is read as one. 
        1a) When all pending transmission requests have completed, 
        1b) then M_CAN waits until bus idle state is detected. 
        2)  The M_CAN sets CCCR[INIT] to one to prevent any further CAN transfers. 
        3)  Now M_CAN acknowledges that it is ready for power down by setting CCCR[CSA] to one. 
            In this state, before the clocks are switched off, further register accesses can be made. 
            A write access to CCCR[INIT] will have no effect. 
        4)  Now the module clock inputs (CAN clock and host clock) may be switched off. 
        5)  To leave power down mode, the application has to turn on the module clocks before resetting CCCR[CSR]. 
        5a) The M_CAN will acknowledge this by resetting CCCR[CSA]. 
        6)  Afterwards, the application can restart CAN communication by resetting bit CCCR[INIT]. */
#if ( CAN_BOSCH_ERRATUM_008 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
    Cn->CCCR |= kCanCCCR_CSR;   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
    /*  When clock stop is requested, first INIT then CSA will be set 
        after all pending transfer requests have been completed and the CAN bus reached idle. */
    if((Cn->CCCR & kCanCCCR_CSA) != kCanCCCR_CSA) /* COV_CAN_TRANSITION_REQUEST */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#else
    Cn->CCCR |= kCanCCCR_INIT;   /* SBSW_CAN_LL__100 */    /* PRQA S 0303 */ /* MD_Can_HwAccess */
    if((Cn->CCCR & kCanCCCR_INIT) != kCanCCCR_INIT) /* COV_CAN_TRANSITION_REQUEST */ /* PRQA S 0303 */ /* MD_Can_HwAccess */
#endif
    { /* Set clock stop request, then wait for acknowledge (CSA) */
      transitionRequest = kCanRequested;
    }
    else
    { /* Already in sleep mode. Nothing to be done */
      transitionRequest = kCanOk;
    }
  }
  else
  { /* Already in stop mode */
    transitionRequest = kCanOk;
  }
  return(transitionRequest);
} /* CanLL_StopRequest */
/* CODE CATEGORY 4 END */

#if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */
/****************************************************************************
| NAME:             CanHL_TxConfirmationPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_TxConfirmationPolling
Relation_Context:
# from CanLL_TxProcessPendings #
TxPolling
Relation:
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_TxConfirmationPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle )
{
  /* #10 Lock CAN controller interrupts. (avoid nested call of confirmation (individual polling) and CancelTx interrupt confirmation out of Can interrupt like TP) */
  Can_DisableControllerInterrupts((uint8)channel);
  /* #20 call CanHL_TxConfirmation() for handling */
  CanHL_TxConfirmation(CAN_HW_CHANNEL_CANPARA_FIRST mailboxHandle, mailboxElement, hwObjHandle);
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

/****************************************************************************
| NAME:             CanHL_TxConfirmation
****************************************************************************/
/*
|<DataModelStart>| CanHL_TxConfirmation
Relation_Context:
# from CanHL_TxConfirmationPolling #
# from Tx Interrupt #
TxPolling, IndividualPolling
Relation:
TxHwFifo, GenericConfirmation
DevErrorDetect, TxPolling, OneChOpt
TransmitCancellationAPI
GenericConfirmation, IfTxBuffer
HwCancelTx
GenericConfirmation, MirrorMode
HwCancelTx, TransmitCancellationAPI, GenericConfirmation
ChannelAmount
TxBasicAmount
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_TxConfirmation( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle mailboxHandle, CanObjectHandle mailboxElement, CanObjectHandle hwObjHandle )
{
  /* \trace SPEC-1574 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanTxConfirmationParaStruct txConfPara;
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  tCanTxConfInfoStruct txConfInfoStruct;
#endif
  CanHookBegin_CanHL_TxConfirmation();
  errorId = CAN_E_NO_ERROR; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  txConfPara.mailboxHandle = mailboxHandle;
  txConfPara.mailboxElement = mailboxElement; /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
  txConfPara.hwObjHandle = hwObjHandle; /* PRQA S 2983 */ /* MD_MSR_DummyStmt */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
  txConfPara.txStructConf = &txConfInfoStruct;
#endif
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
# if !defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING */
  /* #10 Check if parameter controller and hwObjHandle is valid (only for Interrupt system, polling do this by caller) */
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if ( 
#  if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
       ((txConfPara.mailboxHandle < Can_GetTxFullHandleStart(canHwChannel)) || (txConfPara.mailboxHandle >= Can_GetTxFullHandleStop(canHwChannel))) &&
#  endif
       ((txConfPara.mailboxHandle < Can_GetTxBasicHandleStart(canHwChannel)) || (txConfPara.mailboxHandle >= Can_GetTxBasicHandleStop(canHwChannel))) ) /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    PduIdType tmp_pdu;
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
    uint8_least tmp_state;
#endif
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    Can_ReturnType generic_retval;
#endif
#if (defined(CAN_USE_CRITICALSECTION_OVER_CONFIRMATION) && (CAN_TRANSMIT_BUFFER == STD_ON)) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    /* #100 EXCLUSIVE_AREA_3 needed to avoid another can_write while interface send out of queue (first send out of queue avoid inversion) or call GenericConfirmation2 (data consistency) */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_3();
#endif
    txConfPara.activeSendObject = CanHL_GetActiveSendObject(txConfPara.mailboxHandle, txConfPara.mailboxElement); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
    {
      /* #120 Pre Release HW transmit object (LL) */
      CanLL_TxConfBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara); /* SBSW_CAN_HL45 */
      /* #130 Remember PDU for confirmation parameter */
      tmp_pdu   = Can_GetActiveSendPdu(txConfPara.activeSendObject);
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
      /* #140 Remember SEND STATE which may be modified due to new transmit call in indication */
      tmp_state = (uint8_least)Can_GetActiveSendState(txConfPara.activeSendObject);
#endif
      { /* #200 Set send state to free to allow next TX out of confirmation or direct (reload queue) */
        /* #210 Notify the application by call Appl_GenericConfirmation() and CanIf_TxConfirmation() */
        /*      - Appl_GenericConfirmation() if configured and mirror mode is active
                and afterwards depend of return value
                - CanIf_TxConfirmation() if generic confirmation return OK, or no generic is used, and TX is not cancelled */
#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1)
        Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
        if (Appl_GenericConfirmation( tmp_pdu ) == CAN_OK)
#elif defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
# if defined(C_ENABLE_MIRROR_MODE)
        if (Can_GetMirrorModeState(channel) == CDDMIRROR_INACTIVE)
        { /* MirrorMode is inactive so call the following CanIf_TxConfirmation() */
          Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
          generic_retval = CAN_OK;
        }
        else
# endif
        { /* #230 For generic confirmation with API2 copy PDU data as parameter for Appl_GenericConfirmation() */
          { /* #250 in case of none FIFO get data out of CAN cell buffer (LL txStructConf) */
            Can_PduType canPdu;
            /* #260 get confirmation data out of hardware */
            CanLL_TxConfSetTxConfStruct(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara); /* SBSW_CAN_HL45 */
            CanHL_SetCanPduInfo(&canPdu, &txConfPara); /* SBSW_CAN_HL32 */ /* SBSW_CAN_HL45 */
            canPdu.swPduHandle = tmp_pdu;
            Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */ /* release after copy data to avoid data inconsistency */
            /* call Appl_GenericConfirmation() and in case of CAN_OK also the following CanIf_TxConfirmation() */
            generic_retval = Appl_GenericConfirmation( (uint8)channel, &canPdu ); /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL32 */
          }
        }
        /* #300 Appl_GenericConfirmation() decide to call Indication */
        if (generic_retval == CAN_OK)
#else /* no generic confirmation */
        Can_SetActiveSendState(txConfPara.activeSendObject, kCanBufferFree); /* SBSW_CAN_HL04 */
#endif
        {
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
          /* #310 If TX is SW cancelled call CanIf_CancelTxNotification() */
          if (tmp_state == kCanBufferCancelSw) /* COV_CAN_CANCEL_SW_STIMULATION */
          {
            CanIf_CancelTxNotification(tmp_pdu, FALSE);
          }
          else
#endif  /* #320 otherwise call CanIf_TxConfirmation() */
          {
            CanIf_TxConfirmation(tmp_pdu); /* \trace SPEC-1726, SPEC-1571 */
          }
        }
#if (defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)) && (CAN_TRANSMIT_BUFFER == STD_ON)
        /* #350 otherwise no CanIf_TxConfirmation() will be called so call CanIf_CancelTxNotification() just to notify IF to restart sending out of Queue */
        else
        {
# if defined(C_ENABLE_CANCEL_SUPPORT_API)
          CanIf_CancelTxNotification( tmp_pdu, FALSE );
# else
#  error "When using Generic Confirmation and Transmit buffer (If) the Cancel-support-api (if) has to be activated"
# endif
        }
#endif
      }
      /* #500 Post release HW transmit object (LL) */
      CanLL_TxConfEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &txConfPara); /* SBSW_CAN_HL45 */
    }

#if (defined(CAN_USE_CRITICALSECTION_OVER_CONFIRMATION) && (CAN_TRANSMIT_BUFFER == STD_ON)) || defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_3();
#endif
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
# if !defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING */
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_TXCNF_ID, errorId);
  }
# endif
#endif
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CanHookEnd_CanHL_TxConfirmation();
} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */


#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/****************************************************************************
| NAME:             CanHL_SetCanPduInfo
****************************************************************************/
/*
|<DataModelStart>| CanHL_SetCanPduInfo
Relation_Context:
# from CanHL_TxConfirmation #
GenericConfirmation
Relation:
IDType
CanFdSupport
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_SetCanPduInfo(Can_PduInfoPtrType_var PduInfo, CanTxConfirmationParaStructPtr txConfPara)
{
  /* #10 set data pointer */
  PduInfo->sdu = (Can_SduPtrType) txConfPara->txStructConf->pChipData; /* PRQA S 0312 */ /* MD_Can_NoneVolatilePointerCast */ /* SBSW_CAN_HL46 */
  /* #20 set data length */
  PduInfo->length = CanTxActualDLC(txConfPara->txStructConf); /* SBSW_CAN_HL46 */
  /* #30 set ID */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
  if ( CanTxActualIdType(txConfPara->txStructConf) == kCanIdTypeStd) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { /* Mixed ID */
    PduInfo->id = (Can_IdType)CanTxActualStdId(txConfPara->txStructConf); /* PRQA S 4391 */ /* MD_Can_IntegerCast */ /* SBSW_CAN_HL46 */
  }
  else
#  endif  /* pure Extended ID */
  { /* Extended ID */
    PduInfo->id = (Can_IdType)(CanTxActualExtId(txConfPara->txStructConf) | CAN_ID_IDE_MASK); /* SBSW_CAN_HL46 */
  }
# else    /* Standard ID */
  PduInfo->id = CanTxActualStdId(txConfPara->txStructConf); /* SBSW_CAN_HL46 */
# endif
# if defined(C_ENABLE_CAN_FD_USED)
  if ( CanTxActualFdType(txConfPara->txStructConf) == kCanFdTypeFd )
  {
    PduInfo->id |= (Can_IdType)CAN_ID_FD_MASK; /* SBSW_CAN_HL46 */
  }
# endif
  PduInfo->id &= CAN_ID_MASK_IN_GENERIC_CALLOUT; /* SBSW_CAN_HL46 */
}
#endif


#if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
# if defined(C_ENABLE_RX_BASICCAN_POLLING) /* COV_CAN_RX_BASICCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_BasicCanMsgReceivedPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_BasicCanMsgReceivedPolling
Relation_Context:
# from CanLL_RxBasicProcessPendings #
RxBasicCANSupport
Relation:
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_BasicCanMsgReceivedPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle )
{
  /* #10 Lock CAN controller interrupts. */
  Can_DisableControllerInterrupts((uint8)channel);
  /* #20 call CanHL_BasicCanMsgReceived() for handling */
  CanHL_BasicCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxMailboxHandle, hwObjHandle );
  Can_EnableControllerInterrupts((uint8)channel);
}
#endif

/****************************************************************************
| NAME:             CanHL_BasicCanMsgReceived
****************************************************************************/
/*
|<DataModelStart>| CanHL_BasicCanMsgReceived
Relation_Context:
# from CanHL_BasicCanMsgReceivedPolling #
RxBasicCANSupport
# from Rx Interrupt #
Relation:
DevErrorDetect, RxPolling, OneChOpt
RamCheck
Overrun
IDType
CanFdSupport
DevErrorDetect, RxPolling, IndividualPolling
ChannelAmount
RxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_BasicCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanRxBasicParaStruct rxBasicPara;
  CanHookBegin_CanHL_BasicCanMsgReceived();
  errorId = CAN_E_NO_ERROR;
  rxBasicPara.mailboxHandle = rxMailboxHandle;
  rxBasicPara.hwObjHandle = hwObjHandle;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON) && !defined(C_ENABLE_RX_BASICCAN_POLLING)
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  /* #10 Check if parameter controller is in expected limit (already checked in polling task - do it only for interrupt) */
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif 
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #25 receive handling begin CanLL_RxBasicMsgReceivedBegin() \trace SPEC-1682, SPEC-1694 */
    if (CanLL_RxBasicMsgReceivedBegin(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara) == kCanOk) /* SBSW_CAN_HL26 */ /* COV_CAN_RxBasicMsgReceivedBegin */
    {
# if defined(C_ENABLE_CAN_RAM_CHECK)
      /* -------------------------- RAM check failed --- */
      if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* COV_CAN_HARDWARE_FAILURE */
# endif
      { /* #30 RAM CHECK pass so continue reception */
# if defined(C_ENABLE_OVERRUN)
#  if !defined(C_HL_ENABLE_OVERRUN_IN_STATUS) /* COV_CAN_OVERRUN_IN_STATUS */
#  endif
# endif
        /* \trace SPEC-1346 */
        {
          /* -------------------------- Get DLC and Data Pointer --- */
          /* #60 get ID, DLC and data from HW \trace SPEC-1691, SPEC-1693 */
          rxBasicPara.rxStruct.localDlc = CanRxActualDLC((&(rxBasicPara.rxStruct)));
          /* -------------------------- Get ID  &  reject unwanted ID type --- */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
          if ( CanRxActualIdType((&(rxBasicPara.rxStruct))) == kCanIdTypeStd) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
          { /* mixed - standard ID */
            rxBasicPara.rxStruct.localId = (Can_IdType)CanRxActualStdId((&(rxBasicPara.rxStruct)));
          }
          else
#  endif 
          { /* mixed or pure - extended ID */
            rxBasicPara.rxStruct.localId = (Can_IdType)(CanRxActualExtId((&(rxBasicPara.rxStruct))) | CAN_ID_IDE_MASK);
          }
          {
# else 
          { /* pure - standard ID */
            rxBasicPara.rxStruct.localId = CanRxActualStdId((&(rxBasicPara.rxStruct)));
# endif
# if defined(C_ENABLE_CAN_FD_USED)
            if ( CanRxActualFdType((&(rxBasicPara.rxStruct))) == kCanFdTypeFd )
            { /* \trace SPEC-60428 */
              rxBasicPara.rxStruct.localId |= (Can_IdType)CAN_ID_FD_MASK;
            }
            /* DLC is not bigger than expected length (8) for CLASSIC CAN msg (additional to HashTag 145) */
            if ((CanRxActualFdType((&(rxBasicPara.rxStruct))) != kCanFdTypeFd) && (rxBasicPara.rxStruct.localDlc > 8u)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if (!defined(C_ENABLE_RX_BASICCAN_POLLING) || defined(C_ENABLE_INDIVIDUAL_POLLING))
            /* #140 Check HRH is BasicCAN (already checked in polling task - do it only for interrupt) */
            if ( (rxBasicPara.mailboxHandle < Can_GetRxBasicHandleStart(canHwChannel)) ||
                 (rxBasicPara.mailboxHandle >= Can_GetRxBasicHandleStop(canHwChannel)) ) /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* CM_CAN_HL18 */ /* COV_CAN_GENDATA_FAILURE */
            {
              errorId = CAN_E_PARAM_HANDLE;
            } 
            else
#  endif
# endif
            /* #145 DLC is not bigger than expected length from mailbox (MAX over all PDU for this mailbox) */
            if (rxBasicPara.rxStruct.localDlc > CAN_MAX_DATALEN_OBJ(rxBasicPara.mailboxHandle)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
            {
              /* -------------------------- Notification --- */
              /* #150 RX queue and notification handling CanHL_RxMsgReceivedNotification() */
              rxBasicPara.rxStruct.localMailboxHandle = rxBasicPara.mailboxHandle;
              errorId = CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANPARA_FIRST &(rxBasicPara.rxStruct)); /* SBSW_CAN_HL26 */
            }
          }
        }
      }
    }
    /* #160 receive handling end CanHL_RxBasicMsgReceivedEnd() */
    CanLL_RxBasicReleaseObj(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara); /* SBSW_CAN_HL26 */
    CanLL_RxBasicMsgReceivedEnd(CAN_CHANNEL_CANPARA_FIRST &rxBasicPara); /* SBSW_CAN_HL26 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_RXINDI_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  CanHookEnd_CanHL_BasicCanMsgReceived();
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */
#endif /* C_ENABLE_RX_BASICCAN_OBJECTS */

#if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
# if defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
/****************************************************************************
| NAME:             CanHL_FullCanMsgReceivedPolling
****************************************************************************/
/*
|<DataModelStart>| CanHL_FullCanMsgReceivedPolling
Relation_Context:
# from CanLL_RxFullProcessPendings #
RxFullCANSupport, RxPolling
Relation:
OneChOpt
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(CAN_LOCAL_INLINE, void, STATIC_CODE) CanHL_FullCanMsgReceivedPolling( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle )
{
  /* #10 Lock CAN controller interrupts. */
  Can_DisableControllerInterrupts((uint8)channel);
  /* #20 call CanHL_FullCanMsgReceived() for handling */
  CanHL_FullCanMsgReceived( CAN_HW_CHANNEL_CANPARA_FIRST rxMailboxHandle, hwObjHandle );
  Can_EnableControllerInterrupts((uint8)channel);
}
# endif

/****************************************************************************
| NAME:             CanHL_FullCanMsgReceived
****************************************************************************/
/*
|<DataModelStart>| CanHL_FullCanMsgReceived
Relation_Context:
# from CanLL_FullCanMsgReceivedPolling #
RxFullCANSupport
# from Rx Interrupt #
Relation:
OneChOpt
DevErrorDetect, RxPolling, OneChOpt
RamCheck
Overrun
IDType
CanFdSupport
DevErrorDetect, RxPolling, IndividualPolling
ChannelAmount
RxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_FullCanMsgReceived( CAN_HW_CHANNEL_CANTYPE_FIRST CanObjectHandle rxMailboxHandle, CanObjectHandle hwObjHandle ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  tCanRxFullParaStruct rxFullPara;
  CanHookBegin_CanHL_FullCanMsgReceived();
  errorId = CAN_E_NO_ERROR;
  rxFullPara.mailboxHandle = rxMailboxHandle;
  rxFullPara.hwObjHandle = hwObjHandle;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if !defined(C_ENABLE_RX_FULLCAN_POLLING) /* COV_CAN_RX_FULLCAN_POLLING */
#   if !defined( C_SINGLE_RECEIVE_CHANNEL )
  /* #10 Check if parameter controller is in expected limit (already checked in polling task - do it only for interrupt) */
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#   endif
#  endif
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #25 receive handling begin CanLL_RxFullMsgReceivedBegin() \trace SPEC-1682, SPEC-1694 */
    if (CanLL_RxFullMsgReceivedBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara) == kCanOk) /* SBSW_CAN_HL27 */ /* COV_CAN_RxFullMsgReceivedBegin */
    {
  /* -------------------------- RAM check failed --- */
# if defined(C_ENABLE_CAN_RAM_CHECK)
      if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* COV_CAN_HARDWARE_FAILURE */
# endif
      { /* #30 RAM CHECK pass so continue reception */
        /* -------------------------- Overrun --- */
        {
          /* -------------------------- Get DLC and Data Pointer --- */
          /* #60 get ID, DLC and data from HW \trace SPEC-1691, SPEC-1693 */
          rxFullPara.rxStruct.localDlc = CanRxActualDLC((&(rxFullPara.rxStruct)));
          /* -------------------------- Get ID  &  reject unwanted ID type --- */
# if defined(C_ENABLE_EXTENDED_ID)
#  if defined(C_ENABLE_MIXED_ID)
          if ( CanRxActualIdType((&(rxFullPara.rxStruct))) == kCanIdTypeStd) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
          { /* mixed - standard ID */
            rxFullPara.rxStruct.localId = (Can_IdType)CanRxActualStdId((&(rxFullPara.rxStruct)));
          }
          else
#  endif 
          { /* mixed or pure - extended ID */
            rxFullPara.rxStruct.localId = (Can_IdType)(CanRxActualExtId((&(rxFullPara.rxStruct))) | CAN_ID_IDE_MASK);
          }
# else 
          rxFullPara.rxStruct.localId = CanRxActualStdId((&(rxFullPara.rxStruct)));
# endif
          { /* ID has valid IdType */
# if defined(C_ENABLE_CAN_FD_USED)
            if ( CanRxActualFdType((&(rxFullPara.rxStruct))) == kCanFdTypeFd )
            { /* \trace SPEC-60428 */
              rxFullPara.rxStruct.localId |= (Can_IdType)CAN_ID_FD_MASK;
            }
            /* DLC is not bigger than expected length (8) for CLASSIC CAN msg (additional to HashTag 145) */
            if ((CanRxActualFdType((&(rxFullPara.rxStruct))) != kCanFdTypeFd) && (rxFullPara.rxStruct.localDlc > 8u)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if (!defined(C_ENABLE_RX_FULLCAN_POLLING) || defined(C_ENABLE_INDIVIDUAL_POLLING)) /* COV_CAN_RX_FULLCAN_POLLING */
            /* #140 Check HRH is FullCAN (already checked in polling task - do it only for interrupt) */
            if ( (rxFullPara.mailboxHandle < Can_GetRxFullHandleStart(canHwChannel)) ||
                 (rxFullPara.mailboxHandle >= Can_GetRxFullHandleStop(canHwChannel)) )  /* PRQA S 2991,2992,2995,2996 */ /* MD_Can_ConstValue */ /* CM_CAN_HL18 */ /* COV_CAN_GENDATA_FAILURE */
            {
              errorId = CAN_E_PARAM_HANDLE;
            }
            else
#  endif
# endif
            /* #145 DLC is not bigger than expected length from mailbox */
            if (rxFullPara.rxStruct.localDlc > CAN_MAX_DATALEN_OBJ(rxFullPara.mailboxHandle)) /* ESCAN00084263 */ /* COV_CAN_HARDWARE_FAILURE */
            {
              errorId = CAN_E_PARAM_DLC;
            }
            else
            {
              /* -------------------------- Notification --- */
              /* #150 RX queue and notification handling CanHL_RxMsgReceivedNotification() */
              rxFullPara.rxStruct.localMailboxHandle = rxFullPara.mailboxHandle;
              errorId = CanHL_RxMsgReceivedNotification(CAN_CHANNEL_CANPARA_FIRST &(rxFullPara.rxStruct)); /* SBSW_CAN_HL27 */
            }
          }
        }
      }
    }
    /* #160 receive handling end CanHL_RxFullMsgReceivedEnd() */
    CanLL_RxFullReleaseObj(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara); /* SBSW_CAN_HL27 */
    CanLL_RxFullMsgReceivedEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &rxFullPara); /* SBSW_CAN_HL27 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_RXINDI_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  CanHookEnd_CanHL_FullCanMsgReceived();
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */
#endif /* C_ENABLE_RX_FULLCAN_OBJECTS */

/****************************************************************************
| NAME:             CanHL_ErrorHandling
****************************************************************************/
/*
|<DataModelStart>| CanHL_ErrorHandling
Relation_Context:
# from Can_Mainfunction_BusOff() #
StatusPolling
# from BusOff Interrupt #
StatusPolling
Relation:
DevErrorDetect, StatusPolling, OneChOpt
Overrun
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
/* explicite not inline (big code + multiple calls) */
V_DEF_FUNC(CAN_STATIC, void, STATIC_CODE) CanHL_ErrorHandling( CAN_HW_CHANNEL_CANTYPE_ONLY )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
# if !defined(C_ENABLE_ERROR_POLLING) /* COV_CAN_ERROR_POLLING */
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  /* #10 Check if parameter controller is in expected limit */
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
#endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #20 Pre Error handling (LL) */
    CanLL_ErrorHandlingBegin(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
    if ( (CanLL_BusOffOccured(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue) && (!Can_IsIsBusOff(channel) /* avoid repeated call */)) /* COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG */
    {
      /* #90 EXCLUSIVE_AREA_6 secure mode changes */
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
      /* #100 BUSOFF occur -> ECU Manager restart Controller (no ResetBusOffStart/End needed) */
      Can_SetIsBusOff(channel, TRUE); /* SBSW_CAN_HL08 */
      /* #110 CanResetBusOffStart need when BUSOFF handled by Application */
      (void)CanHL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST kCanModeResetBusOffStart, kCanContinueBusOffRecovery, kCanSuppressRamCheck);
      /* #115 Controller is in STOP mode after CanResetBusOffStart \trace SPEC-1578, SPEC-1664, SPEC-1663 */
      /* #120 Status changed to STOP - no more call of STOP from CAN Interface */
      Can_SetLogStatus(channel, (uint8)((Can_GetLogStatus(channel) & CAN_STATUS_MASK_NOMODE) | CAN_STATUS_STOP)); /* SBSW_CAN_HL02 */
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
      /* #130 notify higher layer by call CanIf_ControllerBusOff() \trace SPEC-1726, SPEC-1578 */
      CanIf_ControllerBusOff((uint8)Can_GetCanToCanIfChannelMapping(channel));
    }
#if defined(C_HL_ENABLE_OVERRUN_IN_STATUS) /* COV_CAN_OVERRUN_IN_STATUS */
    /* #135 check for status register (overrun occur) */
# if defined(C_ENABLE_OVERRUN) && defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
    /* #140 notify BasicCAN overrun DET or Appl_CanOverrun() */
    if (CanLL_RxBasicCanOverrun(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue)
    {
#  if (CAN_OVERRUN_NOTIFICATION == CAN_DET)
      errorId = CAN_E_DATALOST; /* \trace SPEC-1686 */
#  else /* CAN_OVERRUN_NOTIFICATION == CAN_APPL */
      Appl_CanOverrun( (uint8)channel );
#  endif
    }
# endif
#endif
    /* #200 Post Error handling (LL) */
    CanLL_ErrorHandlingEnd(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_FAILURE */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_CTRBUSOFF_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


#define CAN_STOP_SEC_STATIC_CODE  /*---------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/*-------------------------------------------------------------------------*/

#define CAN_START_SEC_CODE  /*---------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CAN_VERSION_INFO_API == STD_ON) /* \trace SPEC-1716 */
/****************************************************************************
| NAME:             Can_GetVersionInfo
****************************************************************************/
/*
|<DataModelStart>| Can_GetVersionInfo
Relation_Context:
VersionInfoApi
Relation:
DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_GetVersionInfo( Can_VersionInfoPtrType VersionInfo )
{ /* \trace SPEC-1723 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter versionInfo is an illegal null pointer \trace SPEC-1721 */
  if (VersionInfo == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  { /* #100 copy version info to given pointer parameter \trace SPEC-1717 */
    /* ----- Implementation ----------------------------------------------- */
    VersionInfo->vendorID   = CAN_VENDOR_ID; /* SBSW_CAN_HL10 */
    VersionInfo->moduleID   = CAN_MODULE_ID; /* SBSW_CAN_HL10 */
    VersionInfo->sw_major_version = (uint8)CAN_SW_MAJOR_VERSION; /* SBSW_CAN_HL10 */
    VersionInfo->sw_minor_version = (uint8)CAN_SW_MINOR_VERSION; /* SBSW_CAN_HL10 */
    VersionInfo->sw_patch_version = (uint8)CAN_SW_PATCH_VERSION; /* SBSW_CAN_HL10 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_VERSION_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

/****************************************************************************
| NAME:             Can_InitMemory
****************************************************************************/
/*
|<DataModelStart>| Can_InitMemory
Relation_Context:
Relation:
Variant
DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_InitMemory( void )
{ /* BR:011 */
  /* ----- Local Variables ---------------------------------------------- */
  /* ----- Implementation ----------------------------------------------- */
  /* #10 mark driver as uninitialized \trace SPEC-1650 */
  canConfigInitFlag = CAN_STATUS_UNINIT;
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER)
  /* #20 reset global configuration pointer */
  Can_ConfigDataPtr = NULL_PTR;
#endif /* otherwise constant pointer is used */
  /* #30 HW reset memory */
  CanLL_InitMemoryPowerOn(); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
#if(CAN_DEV_ERROR_DETECT == STD_OFF)
  CAN_DUMMY_STATEMENT(canConfigInitFlag); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
}


#if ((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))
/****************************************************************************
| NAME:             Can_ChangeBaudrate
****************************************************************************/
/*
|<DataModelStart>| Can_ChangeBaudrate
Relation_Context:
Relation:
ChangeBaudrate, DevErrorDetect, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_ChangeBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate )
{ /* \trace SPEC-20314 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;
  uint8 errorId;
  retval = E_NOT_OK;
  errorId = CAN_E_PARAM_BAUDRATE; /* explicit default as Issue - remove when baud rate fit */ /* \trace SPEC-20321 */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT and STOP \trace SPEC-20338 */
  if ( canConfigInitFlag == CAN_STATUS_UNINIT )
  {
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if ( channel >= kCanNumberOfChannels ) /* CM_CAN_HL01 */
  { /* \trace SPEC-20331 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if ( (Can_GetLogStatus(channel) & CAN_STATUS_STOP) != CAN_STATUS_STOP )
  { /* \trace SPEC-1655, SPEC-20312 */
    errorId = CAN_E_TRANSITION;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    uint8_least baudrateIndex;
    for (baudrateIndex = Can_GetInitObjectStartIndex(channel); baudrateIndex < Can_GetInitObjectStartIndex(channel + 1u); baudrateIndex++)
    { /* #30 search for baud rate configuration */
      if (Can_GetInitObjectBaudrate(baudrateIndex) == Baudrate)
      { /* #40 set baud rate and reinitialize controller to activate baud rate \trace SPEC-1669 */
        uint8 transitionState;
        Can_SetLastInitObject(channel, (uint8)baudrateIndex); /* SBSW_CAN_HL11 */
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
        if (transitionState == kCanOk) /* COV_CAN_TRANSITION_REQUEST */
        { /* #50 check transition STOP (Reinit) is successful */
          Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
        }
        retval = E_OK;
        errorId = CAN_E_NO_ERROR;
        break;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_CHANGE_BR_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/****************************************************************************
| NAME:             Can_CheckBaudrate
****************************************************************************/
/*
|<DataModelStart>| Can_CheckBaudrate
Relation_Context:
ChangeBaudrate
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate )
{ /* \trace SPEC-20311 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;
  uint8 errorId;
  retval = E_NOT_OK;
  errorId = CAN_E_PARAM_BAUDRATE; /* \trace SPEC-20317 */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT \trace SPEC-20328, SPEC-20318 */
  if ( canConfigInitFlag == CAN_STATUS_UNINIT )
  {
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if ( channel >= kCanNumberOfChannels )
  { /* \trace SPEC-20335 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    uint8_least baudrateIndex;
    for (baudrateIndex = Can_GetInitObjectStartIndex(channel); baudrateIndex < Can_GetInitObjectStartIndex(channel + 1u); baudrateIndex++)
    { /* #30 search for baud rate configuration */
      if (Can_GetInitObjectBaudrate(baudrateIndex) == Baudrate)
      { /* #40 requested baud rate is set - return OK */
        retval = E_OK;
        errorId = CAN_E_NO_ERROR;
        break;
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_CHECK_BR_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
}
#endif /* CAN_CHANGE_BAUDRATE_API == STD_ON */

#if (CAN_SET_BAUDRATE_API == STD_ON)
/****************************************************************************
| NAME:             Can_SetBaudrate
****************************************************************************/
/*
|<DataModelStart>| Can_SetBaudrate
Relation_Context:
Relation:
ChangeBaudrate, DevErrorDetect, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID )
{ /* \trace SPEC-50605 */
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType retval;
  uint8 errorId;
  /* #5 return E_NOT_OK in case no fitting baudrate is found \trace-2622524 */
  retval = E_NOT_OK;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT and STOP \trace SPEC-50595 */
  if ( canConfigInitFlag == CAN_STATUS_UNINIT )
  {
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if ( channel >= kCanNumberOfChannels ) /* CM_CAN_HL01 */
  { /* \trace SPEC-50587 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if ( (Can_GetLogStatus(channel) & CAN_STATUS_STOP) != CAN_STATUS_STOP )
  { /* \trace SPEC-50584 */
    errorId = CAN_E_TRANSITION;
  }
  else
  if ( BaudRateConfigID >= (uint16)(Can_GetInitObjectStartIndex(channel + 1u) - Can_GetInitObjectStartIndex(channel)) ) /* PRQA S 4391 */ /* MD_Can_IntegerCast */
  { /* \trace SPEC-50625, SPEC-50563 */
    errorId = CAN_E_PARAM_BAUDRATE;
  }
  else
# endif
  { /* #50 set baud rate and reinitialize controller to activate baud rate */
    uint8 transitionState;
    /* ----- Implementation ----------------------------------------------- */
    Can_SetLastInitObject(channel, (uint8)(Can_GetInitObjectStartIndex(channel) + BaudRateConfigID)); /* SBSW_CAN_HL11 */
    transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
    /* #60 check if hardware cancellation appear while mode change, so for the baud rate set is not successful \trace SPEC-60434 */
    if (transitionState == kCanOk) /* COV_CAN_TRANSITION_REQUEST */
    {
      retval = E_OK;
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_SET_BR_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

/****************************************************************************
| NAME:             Can_Init
****************************************************************************/
/*
|<DataModelStart>| Can_Init
Relation_Context:
Relation:
Variant, DevErrorDetect
RxQueue
OneChOpt
Variant
Wakeup
MirrorMode
SilentMode
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_Init( Can_ConfigPtrType ConfigPtr ) /* PRQA S 3206 */ /* MD_MSR_DummyStmt */
{ /* \trace SPEC-1587, SPEC-1708 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  CAN_CHANNEL_CANTYPE_LOCAL
  CanHookBegin_Can_Init();
  errorId = CAN_E_NO_ERROR;
#if defined(CAN_ENABLE_USE_INIT_ROOT_POINTER) /* PostBuild (load+sel) */
  Can_ConfigDataPtr = ConfigPtr; /* \trace SPEC-1394, SPEC-1575 */
# if defined(CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK) /* PostBuildLoadable */
  if (ConfigPtr == NULL_PTR)
  { /* #10 EcuM null pointer configuration check and notification */
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_NULLPTR);
  }
  else
#  if (CAN_FINALMAGICNUMBER == STD_ON) /* COV_CAN_FINALMAGICNUMBER */
  if (Can_GetFinalMagicNumber() != 20510u) /* COV_CAN_GENDATA_FAILURE */
  { /* #20 EcuM wrong magic number check and notification */
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_MAGICNUMBER);
  }
  else
#  endif
# else
  
  /* ----- Development Error Checks ------------------------------------- */
#  if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #30 Check if all parameters are valid \trace SPEC-1724 */
  if (ConfigPtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
#  endif
# endif
#else
  CAN_DUMMY_STATEMENT(ConfigPtr);  /* PRQA S 1338, 2982, 2983, 3112 */ /* MD_MSR_DummyStmt */
# if defined(V_ENABLE_USE_DUMMY_STATEMENT) /* COV_CAN_COMPATIBILITY */
  ConfigPtr = Can_ConfigDataPtr;  /* PRQA S 2983,1338 */ /* MD_MSR_DummyStmt */
# endif
#endif /* CAN_ENABLE_USE_INIT_ROOT_POINTER */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag != CAN_STATUS_UNINIT)
  {
    /* #60 Check already initialized -> 2nd call is not allowed \trace SPEC-1712, SPEC-1722 */
    errorId = CAN_E_TRANSITION;
  }
  else
#endif
  if (  ( Can_GetBaseDll_GeneratorVersion()     != (uint16)CAN_GEN_BASE_CFG5_VERSION ) ||  /* PRQA S 2742 */ /* MD_Can_ConstValue */
        ( Can_GetPlatformDll_GeneratorVersion() != (uint16)CAN_GEN_Mpc5700McanAsr_VERSION ) ) /* COV_CAN_GENDATA_FAILURE */
  {
    /* #70 EcuM generator and compatibility version check and notification */
#if defined(CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK) /* not for PostBuildSelectable */
    EcuM_BswErrorHook((uint16) CAN_MODULE_ID, (uint8) ECUM_BSWERROR_COMPATIBILITYVERSION); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
#else
    errorId = CAN_E_UNINIT; /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
#endif
  }
  else
  {
    /* ----- Implementation ----------------------------------------------- */
    {
      canIsRxTaskLocked = kCanFalse;
#if defined(C_ENABLE_RX_QUEUE)
      /* #110 delete RxQueue (all channels) */
      Can_GetRxQueueInfo().WriteIndex = 0u;  /* CM_CAN_HL24 */ /* SBSW_CAN_HL55 */
      Can_GetRxQueueInfo().ReadIndex = 0u; /* SBSW_CAN_HL55 */
      Can_GetRxQueueInfo().Count = 0u; /* SBSW_CAN_HL55 */
      canRxQueueMaxDataSize = (uint16) (sizeof(Can_GetRxQueueBuffer(0).data) / sizeof(Can_GetRxQueueBuffer(0).data[0]));
#endif
      /* #120 Set active Identity */
      /* #130 HW specific power on (LL) */
      if (CanLL_InitPowerOn() == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
      {
        canConfigInitFlag = CAN_STATUS_INIT; /* \trace SPEC-1648 */ /* before Controller initialization begin */
#if !defined( C_SINGLE_RECEIVE_CHANNEL )
        for (channel = 0u; channel < kCanNumberOfChannels; channel++) /* CM_CAN_HL01 */
#endif
        { /* #132 for each controller */
#if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
          if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_FAILURE */
          { /* #134 not for inactive controller */
            continue;
          }
#endif
          /* #140 initialize start up values for each controllers */
          Can_SetLogStatus(channel, CAN_STATUS_UNINIT); /* PowerOn mark */ /* SBSW_CAN_HL02 */
          Can_SetModeTransitionRequest(channel, kCanModeNone); /* SBSW_CAN_HL01 */
          Can_SetBusOffTransitionRequest(channel, kCanFinishBusOffRecovery); /* SBSW_CAN_HL01 */
          Can_SetRamCheckTransitionRequest(channel, kCanSuppressRamCheck); /* SBSW_CAN_HL01 */
          Can_SetIsBusOff(channel, FALSE);  /* start up: no BUSOFF */ /* SBSW_CAN_HL08 */
          Can_SetCanInterruptCounter(channel, 0u); /* SBSW_CAN_HL12 */
#if defined(C_ENABLE_MIRROR_MODE)
          Can_SetMirrorModeState(channel, CDDMIRROR_INACTIVE); /* SBSW_CAN_HL20 */
#endif
#if defined(C_ENABLE_SILENT_MODE)
          Can_SetSilentModeState(channel, CAN_SILENT_INACTIVE); /* SBSW_CAN_HL20 */
#endif
          /* #155 HW channel specific power on */
          if (CanLL_InitPowerOnChannelSpecific(CAN_CHANNEL_CANPARA_ONLY) == kCanOk) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_HARDWARE_FAILURE */
          {
            uint8 transitionState;
            /* #160 set baud rate and initialize all CAN controllers \trace SPEC-1587, SPEC-1656 */
            Can_SetLastInitObject(channel, (uint8)(Can_GetInitObjectStartIndex(channel) + Can_GetCanControllerDefaultBaudrateIdx(CAN_HL_HW_CHANNEL_STARTINDEX(channel)))); /* SBSW_CAN_HL11 */
            transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanExecuteRamCheck);
            if (transitionState == kCanOk) /* COV_CAN_TRANSITION_REQUEST */
            { /* #170 check transition STOP (Reinit) is successful */
              Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached or issue */ /* SBSW_CAN_HL02 */
            }
#if (CAN_DEV_ERROR_DETECT == STD_ON)
            else
            {              
              errorId = CAN_E_TRANSITION;
            }
#endif
          }
        }
      } /* CanLL_InitPowerOn */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_INIT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_Init();
} /* PRQA S 6030,6050,6080 */ /* MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_SetControllerMode
****************************************************************************/
/*
|<DataModelStart>| Can_SetControllerMode
Relation_Context:
Relation:
DevErrorDetect, OneChOpt, ChannelAmount
DevErrorDetect, Variant, ChannelAmount
DevErrorDetect, TransitionCheck
RamCheck, ChannelAmount
SilentMode, ChannelAmount
ReInitStart
Wakeup
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition )
{ /* \trace SPEC-1715 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  Can_ReturnType retval;
  uint8 transitionRequest;
  uint8 busOffRecovery;
  uint8 doRamCheck;
  uint8 transitionState;
  CanHookBegin_Can_SetControllerMode();
  retval = CAN_NOT_OK;  /* \trace SPEC-1407 */ /* For successful transition it is set explicit to CAN_OK */
  transitionState = kCanFailed;
  errorId = CAN_E_NO_ERROR;
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller and Transition is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1731 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1732 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  { 
    errorId = CAN_E_PARAM_CONTROLLER; /* \trace SPEC3874 */
  }
  else
# endif
#endif
  { /* #50 second level check (modes and transitions) only valid when controller is in active ECU and valid */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
    if (!CanHL_IsControllerInit(channel))
    { /* #60 Check controller is initialized */
      errorId = CAN_E_UNINIT;
    }
    else
    if ((!CanHL_IsStop(channel)) && (Transition == CAN_T_START))
    { /* #70 Check No-STOP -> START-Req is invalid \trace SPEC-1637 */ /* ESCAN00073272 */
      errorId = CAN_E_TRANSITION;
    }
    else
# if (CAN_TRANSITION_CHECK == STD_ON)  /* SREQ00000291 */
    if ( ((!CanHL_IsStop(channel)) && (!CanHL_IsSleep(channel)) && ((Transition == CAN_T_WAKEUP) || (Transition == CAN_T_SLEEP))) ||
         ((CanHL_IsSleep(channel)) && (Transition == CAN_T_STOP)) )
    { /* #80 Check  No STOP Nor SLEEP -> SLEEP-Req   or   No SLEEP Nor STOP --> WAKEUP-Req   is invalid \trace SPEC-1654, SPEC-1649 */
      /* #90 Check  No START Nor STOP -> STOP-Req is invalid \trace SPEC-1652 */
      errorId = CAN_E_TRANSITION;
    }
    else
# endif
#endif
#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
    /* #95 controller is active (no RAM check issue): */
    if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */ /* COV_CAN_RAM_CHECK_NO_STIMULATION */
#endif
    {
      /* ----- Implementation ----------------------------------------------- */
      /* #100 EXCLUSIVE_AREA_6 avoid nesting mode changes (e.g. same API, initialization or BUSOFF) */
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
      /* #125 HW begin mode transition */
      switch(Transition)
      {
      case CAN_T_START:
        /* #200 Handle --- START --- transition */
        if (Can_IsIsBusOff(channel)) /* COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG */
        { /* #210 BUSOFF occur so finish BUSOFF handling and do START transition inside */
          transitionRequest = kCanModeResetBusOffEnd;
        } 
        else
        {
#if defined(C_ENABLE_SILENT_MODE)
          if (Can_GetSilentModeState(channel) == CAN_SILENT_ACTIVE)
          {
            transitionRequest = kCanModeSilent;
          }
          else
#endif
          {
#if (CAN_REINIT_START == STD_ON)
            transitionRequest = kCanModeStartReinit;
#else
            transitionRequest = kCanModeStart;
#endif
          }
        }
        busOffRecovery = kCanContinueBusOffRecovery;
        doRamCheck = kCanSuppressRamCheck;
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        if ( transitionState == kCanOk ) /* COV_CAN_TRANSITION_REQUEST */
        {
          Can_SetIsBusOff(channel, FALSE); /* SBSW_CAN_HL08 */
        }
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_START, CANIF_CS_STARTED, transitionState);
        break;

      case CAN_T_STOP:
        /* #300 Handle --- STOP --- transition */
        transitionRequest = kCanModeStopReinitFast;
        busOffRecovery = kCanContinueBusOffRecovery;
        doRamCheck = kCanSuppressRamCheck;
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
        break;

      case CAN_T_WAKEUP:
        /* #400 Handle --- WAKEUP --- transition */
#if defined(C_ENABLE_CAN_RAM_CHECK) && !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
        if (!CanHL_IsStop(channel)) { /* do not call RAM_CHECK again in case CanIf call wakeup a second time (buswakeup + stop transition afterwards) */
          /* #415 do standard RAM check CanHL_DoRamCheck() if controller is not in STOP mode */
          transitionRequest = kCanModeStopReinit;
          doRamCheck = kCanExecuteRamCheck;
        }
        else
#endif
        {
          transitionRequest = kCanModeStopReinitFast;
          doRamCheck = kCanSuppressRamCheck;
        }
        {
          busOffRecovery = kCanFinishBusOffRecovery;
        }
        transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
        break;

      case CAN_T_SLEEP: /* \trace SPEC-1639 */
        /* #500 Handle --- SLEEP --- transition */
        { /* #520 no WAKEUP-source-ref: do emulated SLEEP mode \trace SPEC-1629, SPEC-1641, SPEC-1645 */
          transitionState = kCanOk;
        }
        CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_SLEEP, CANIF_CS_SLEEP, transitionState);
        break;

      default:
        /* #600 check unknown transition, return NOT_OK \trace SPEC-1573, SPEC-1402, SPEC-1403 */
        errorId = CAN_E_TRANSITION; /* \trace SPEC-1733, SPEC-1407 */
        break;
      } /* switch */
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
    }
  }
  if ( transitionState != kCanFailed ) /* COV_CAN_TRANSITION_REQUEST */
  {
    retval = CAN_OK;
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_SETCTR_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_SetControllerMode();
  return retval;
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_DisableControllerInterrupts
****************************************************************************/
/*
|<DataModelStart>| Can_DisableControllerInterrupts
Relation_Context:
# from Can_Mainfunction_BusOff #
StatusPolling, ChannelAmount
# from CanHL_TxTaskCancelationHandling #
HwCancelTx, IndividualPolling
# from CanHL_TxConfirmationPolling #
TxPolling
# from Rx BasicCan FullCan #
RxPolling
RxBasicCANSupport
RxFullCANSupport
# from Error handling #
StatusPolling
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
IntLock
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_DisableControllerInterrupts( uint8 Controller )
{ /* \trace SPEC-1746 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1750 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1742 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
  if (!CanHL_IsControllerInit(channel))
  { /* #40 Check controller is initialized \trace SPEC-1750 */
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  { /* ----- Implementation ----------------------------------------------- */
    /* #100 EXCLUSIVE_AREA_1 secure interrupt lock handling */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
    if (Can_GetCanInterruptCounter(channel) == 0u)
    { /* #110 Disable only when not disabled before (count nesting) \trace SPEC-1735, SPEC-1745 */
#if (CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
      { /* #120 Disable CAN interrupt for each HW channel */
        CanLL_CanInterruptDisable(CAN_CHANNEL_CANPARA_FIRST  &Can_GetCanInterruptOldStatus(canHwChannel)); /* SBSW_CAN_HL16 */
      }
#endif
#if (CAN_INTLOCK == CAN_APPL) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
      /* #130 Let application Disable CAN interrupt ApplCanInterruptDisable() */
      ApplCanInterruptDisable((uint8)channel);
#endif
    }
    Can_SetCanInterruptCounter(channel, Can_GetCanInterruptCounter(channel) + 1u); /* \trace SPEC-1748 */ /* SBSW_CAN_HL12 */
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_DIINT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_EnableControllerInterrupts
****************************************************************************/
/*
|<DataModelStart>| Can_EnableControllerInterrupts
Relation_Context:
# from Can_Mainfunction_BusOff #
StatusPolling, ChannelAmount
# from CanHL_TxTaskCancelationHandling #
HwCancelTx, IndividualPolling
# from CanHL_TxConfirmationPolling #
TxPolling
# from Rx BasicCan FullCan #
RxPolling
RxBasicCANSupport
RxFullCANSupport
# from Error handling #
StatusPolling
Relation:
DevErrorDetect, OneChOpt 
DevErrorDetect, Variant
IntLock
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_EnableControllerInterrupts( uint8 Controller )
{ /* \trace SPEC-1741 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1739 */
    errorId = CAN_E_UNINIT;
  }
  else
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* \trace SPEC-1752 */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
# endif
  if (!CanHL_IsControllerInit(channel))
  { /* #40 Check controller is initialized \trace SPEC-1739 */
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  { /* ----- Implementation ----------------------------------------------- */
    /* #100 EXCLUSIVE_AREA_1 secure interrupt lock handling */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_1();
    if (Can_GetCanInterruptCounter(channel) != 0u)
    { /* #110 Enable only when disabled before (count nesting) \trace SPEC-1749, SPEC-1748 */
      Can_SetCanInterruptCounter(channel, Can_GetCanInterruptCounter(channel)-1u); /* SBSW_CAN_HL12 */
      if (Can_GetCanInterruptCounter(channel) == 0u) /* \trace SPEC-1736, SPEC-1756 */
      {
#if (CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
        { /* #120 Disable CAN interrupt for each HW channel */
          CanLL_CanInterruptRestore(CAN_CHANNEL_CANPARA_FIRST Can_GetCanInterruptOldStatus(canHwChannel));
        }
#endif
#if (CAN_INTLOCK == CAN_APPL) || (CAN_INTLOCK == CAN_BOTH) /* COV_CAN_LOCK_ISR_BY_APPL */
        /* #130 Let application Enable CAN interrupt ApplCanInterruptRestore() */
        ApplCanInterruptRestore((uint8)channel);
#endif
      }
    }
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_1();
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_ENINT_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
#if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_Write
****************************************************************************/
/*
|<DataModelStart>| Can_Write
Relation_Context:
Relation:
DevErrorDetect
OneChOpt
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
DevErrorDetect, TxFullCANSupport
DevErrorDetect, CanFdSupport
DevErrorDetect, MixedId
RamCheck
UseVectorCanIf
CanFdSupport
ChannelAmount
TxBasicAmount
TxFullAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_Write( Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo )
{ /* \trace SPEC-1751, SPEC-1760, SPEC-1406 */
  /* ----- Local Variables ---------------------------------------------- */
  Can_ReturnType retval;
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  CanHookBegin_Can_Write();
  errorId = CAN_E_NO_ERROR;
  retval = CAN_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* \trace SPEC-1759 */
    errorId = CAN_E_UNINIT;
  }
  else
  if (Hth >= Can_GetSizeOfMailbox()) {
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#endif
  {
#if !defined( C_SINGLE_RECEIVE_CHANNEL ) /* otherwise 'channel' is a define */
    channel = Can_GetMailboxController(Hth);
#endif
#if (CAN_DEV_ERROR_DETECT == STD_ON)
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
# endif
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_FAILURE */
    {
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
# endif
    if (!CanHL_IsControllerInit(channel))
    { /* #40 Check controller is initialized \trace SPEC-1407 */
      errorId = CAN_E_UNINIT;
    }
    else
# if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
    if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
# else
    if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
# endif
    { /* \trace SPEC-1763 */
      errorId = CAN_E_PARAM_HANDLE;
    }
    else
    if ((PduInfo == NULL_PTR) || ((PduInfo->sdu == NULL_PTR) && (PduInfo->length != 0u)))
    { /* \trace SPEC-1761 */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
# if !defined(C_ENABLE_CAN_FD_USED)
    if ( CanHL_IsFdMessage(PduInfo->id) )
    { /* no CAN_FD: Check parameter PduInfo->id should not have FD bit in ID */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
# endif
# if defined(C_ENABLE_CAN_FD_FULL)
    if ( ((PduInfo->length > 8u) && (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE)) ||
         (PduInfo->length > CAN_MAX_DATALEN_OBJ(Hth)) ) /* COV_CAN_GENDATA_FAILURE */
         { /* \trace SPEC-1758 */
      /* \trace SPEC-60433 */ /* CAN_FD: Check parameter PduInfo->length is smaller than 9 for none FD configuration
         If development error detection for the CAN module is enabled and the CAN Controller is not in CAN FD mode (no CanControllerFdBaudrateConfig):
         The function Can_Write shall raise the error CAN_E_PARAM_DLC and shall return CAN_NOT_OK if the length is more than 8 byte.() */
      /* CAN_FD: Check parameter PduInfo->length against PDU maximum size */
      errorId = CAN_E_PARAM_DLC;
    }
    else
# else
    if ( PduInfo->length > CAN_MAX_DATALEN_OBJ(Hth) ) /* CM_CAN_HL20 */
    { /* \trace SPEC-1758 */ /* Check parameter PduInfo->length against maximum buffer size */
      errorId = CAN_E_PARAM_DLC;
    }
    else
# endif
# if defined(C_ENABLE_MIXED_ID)
    if ( ((PduInfo->id & (Can_IdType)CAN_ID_IDE_MASK) != (Can_IdType)CAN_ID_IDE_MASK ) && ( (PduInfo->id & (Can_IdType)CAN_ID_MASK) > (Can_IdType)CAN_ID_MASK_STD ) ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
    { /* Check parameter PduInfo->id for STD ID is in STD range (EXT is always in range) */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
# endif
    if ( (PduInfo->id & (Can_IdType)CAN_ID_UNUSED_MASK) != (Can_IdType)0UL )
    { /* Check parameter PduInfo->id contains illegal bits (e.g. bigger ID value than MAX for given type) */
      errorId = CAN_E_PARAM_POINTER;
    }
    else
#endif
    /* ----- Implementation ----------------------------------------------- */
#if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #150 reject deactivated mailbox (by RamCheck) */
    if (Can_GetMailboxState(Hth) == kCanFailed) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    {
      retval = CAN_NOT_OK;
    }
    else
#endif
    /* #180 check Hardware is in BUSOFF recovery state and is not able to handle a request: return BUSY \trace SPEC-1764 */
    if (Can_IsIsBusOff(channel)) /* COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG */
    {
      retval = CAN_NOT_OK; /* ESCAN00096369 */
    }
    else
#if defined(C_ENABLE_CAN_RAM_CHECK)
    /* #200 controller is active (no RAM check issue): */
    if ((Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) != CAN_DEACTIVATE_CONTROLLER) /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */ /* COV_CAN_HARDWARE_FAILURE */
#endif
    {
      /* #205 temporary pdu buffer to avoid data modification on constant data (modification in generic pretransmit) */
      tCanTxTransmissionParaStruct txPara;
      /* #210 EXCLUSIVE_AREA_2: Interrupts may not be locked and re-entrant call may occur. */
      /*                        Time in between ID search and lock of mailbox is critical 
                                (only when no Vector Interface used otherwise CanIf EXCLUSIVE_AREA is used instead) 
                                Can_Write() could be called re-entrant, there for also for polling systems the interrupts have to be locked  
                                this is essential while check for mailbox is free (in between if (free) and set to not free) and save PDU handle */
#if !defined(CAN_USE_VECTOR_IF)
      SchM_Enter_Can_CAN_EXCLUSIVE_AREA_2();
#endif
      txPara.mailboxHandle = Hth;
      txPara.hwObjHandle = Can_GetMailboxHwHandle(Hth); 
      txPara.pdu.id = PduInfo->id;
      txPara.pdu.length = PduInfo->length;
      txPara.pdu.sdu = PduInfo->sdu;
      txPara.pdu.swPduHandle = PduInfo->swPduHandle;
#if defined(C_ENABLE_CAN_FD_USED)
      if (txPara.pdu.length <= 8u) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        if (Can_GetInitObjectFdBrsConfig(Can_GetLastInitObject(channel)) == CAN_NONE)
        { /* #220 remove FD flag when no FD support is activated in this initialization structure and DLC not greater than 8 */
          /* CAN FD also support an extended payload which allows the transmission of up to 64 bytes.
          This feature also depends on the CAN FD configuration (see CanControllerFdBaudrateConfig).
          Therefore, if the CAN FD feature is enabled and the CAN FD flag is set in CanId passed to
           Can_Write(), CanDrv supports the transmission of PDUs with a length up to 64 bytes.
          If there is a request to transmit a CAN FD frame without the CAN FD feature enabled the
          frame is sent as conventional CAN frame as long as the PDU length <= 8 bytes. */
          txPara.pdu.id = txPara.pdu.id & ((Can_IdType)(CAN_ID_IDE_MASK | CAN_ID_MASK)); /* CAN_FD_   mask out the FD bit */
        }
      }
      txPara.fdBrsType = kCanFdBrsTypeFalse;
      if (CanHL_IsFdMessage(txPara.pdu.id))
      {
        txPara.fdType = kCanFdTypeFd;
        if (CanHL_IsFdTxBrs(channel))
        {
          txPara.fdBrsType = kCanFdBrsTypeTrue;
        }
      } else {
        txPara.fdType = kCanFdTypeClassic;
      }
      txPara.messageLen = txPara.pdu.length;
      txPara.frameLen = CAN_DLC2LEN(CAN_LEN2DLC(txPara.messageLen));
# if defined(C_ENABLE_CAN_FD_FULL)
      txPara.paddingVal = Can_GetMailboxFdPadding(txPara.mailboxHandle);
# endif
#endif
      /* #230 search for BasicCAN object handle to transmit (Multiplexed TX) and backup data for cancel TX object if necessary */
      CanHL_WritePrepare(CAN_CHANNEL_CANPARA_FIRST &txPara); /* SBSW_CAN_HL49 */
      /* #240 start transmission for given handle (if free) and return state */
      retval = CanHL_WriteStart(CAN_CHANNEL_CANPARA_FIRST &txPara); /* SBSW_CAN_HL49 */

#if !defined(CAN_USE_VECTOR_IF) /* No Vector Interface used, Interrupts may not be locked */
      /* avoid change of PDU information due to TX interrupt while changing */
      SchM_Exit_Can_CAN_EXCLUSIVE_AREA_2();
#endif
    }
  }
  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_WRITE_ID, errorId);
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_Write();
  return retval;
} /* PRQA S 6010,6030,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             ASR4.x - Can_CheckWakeup
****************************************************************************/
/*
|<DataModelStart>| Can_CheckWakeup
Relation_Context:
Relation:
Wakeup, DevErrorDetect, OneChOpt
Wakeup, DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
# define CAN_CHECKWAKEUP_RETTYPE Std_ReturnType
# define CAN_CHECKWAKEUP_RETVAL_OK     E_OK
# define CAN_CHECKWAKEUP_RETVAL_NOT_OK E_NOT_OK
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckWakeup( uint8 Controller )
{ /* \trace SPEC-1740 */
  /* ----- Local Variables ---------------------------------------------- */
  CAN_CHECKWAKEUP_RETTYPE retval;
  retval = CAN_CHECKWAKEUP_RETVAL_NOT_OK; /* \trace SPEC-1407 */
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  return retval;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_MainFunction_Write
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Write
Relation_Context:
Relation:
TxPolling, HwCancelTx, DevErrorDetect
TxPolling, HwCancelTx, OneChOpt
TxPolling, HwCancelTx, Variant
TxPolling, HwCancelTx, Wakeup
TxPolling, IndividualPolling
TxPolling, TxFullCANSupport, IndividualPolling
TxFullCANSupport, HwCancelTx
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Write( void )
{ /* \trace SPEC-1766 */
  /* ----- Local Variables ---------------------------------------------- */
#if defined(C_ENABLE_TX_POLLING) 
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  CanHookBegin_Can_MainFunction_Write();
  /* canSendSemaphor no more needed because of ControllerInterrupts disabled while Can_Write() */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized \trace SPEC-1767 */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  {  
    /* ----- Implementation ----------------------------------------------- */
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++)
# endif
    { /* #20 over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON) /* \trace SPEC-1573, SPEC-1402, SPEC-1403 */
      if (!CanHL_IsControllerInit(channel))
      { /* #50 Check controller is initialized */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        if ( !CanHL_IsSleep(channel) )
        { /* #60 do not access CAN hardware in SLEEP */
          tCanTaskParaStruct taskPara;
# if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */ /* always true when no hw-cancel is supported */
          /* #100 do confirmation handling for pending mailboxes */
          if ( CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue ) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
          { /* #110 is at least one mailbox pending */
            for ( taskPara.mailboxHandle = Can_GetTxBasicHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetTxBasicHandleStop(canHwChannel); taskPara.mailboxHandle++ ) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
            { /* #120 iterate over all TxBasicCAN */
              taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#  if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
              if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#  endif
              { /* #130 is mailbox handled by polling (individual) */
                /* #140 call LL confirmation handling */
                CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
              }
            }
          }
# endif
# if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
#  if defined(C_ENABLE_TX_POLLING) /* COV_CAN_TX_POLLING TX */ /* always true when no hw-cancel is supported */
          /* #200 do confirmation handling for pending mailboxes */
          if ( CanLL_TxIsGlobalConfPending(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY) == kCanTrue ) /* PRQA S 2991,2995 */ /* MD_Can_ConstValue */ /* COV_CAN_LL_HARDWARE_BEHAVIOUR */
          { /* #210 is at least one mailbox pending */
            for ( taskPara.mailboxHandle = Can_GetTxFullHandleStart(canHwChannel); taskPara.mailboxHandle < Can_GetTxFullHandleStop(canHwChannel); taskPara.mailboxHandle++ ) /* PRQA S 2994,2996 */ /* MD_Can_ConstValue */
            { /* #220 iterate over all TxFullCAN */
              taskPara.hwObjHandle = Can_GetMailboxHwHandle(taskPara.mailboxHandle);
#   if defined(C_ENABLE_INDIVIDUAL_POLLING) /* COV_CAN_HWOBJINDIVPOLLING */
              if ( Can_IsMailboxIndivPolling(taskPara.mailboxHandle)) /* COV_CAN_HWOBJINDIVPOLLING */
#   endif
              { /* #230 is mailbox handled by polling (individual) */
                /* #240 call LL confirmation handling */
                CanLL_TxProcessPendings(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST &taskPara); /* SBSW_CAN_HL44 */
              }
            }
          }
#  endif
# endif
        } /* !IsSleep */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_WRITE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif

#else
  CanHookBegin_Can_MainFunction_Write();
#endif /* C_ENABLE_TX_POLLING */
  CanHookEnd_Can_MainFunction_Write();
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_MainFunction_Read
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Read
Relation_Context:
Relation:
DevErrorDetect
RxPolling, OneChOpt
RxPolling, Variant
RxPolling, DevErrorDetect
RxPolling, Wakeup
RxPolling, RxFullCANSupport
RxPolling, RxBasicCANSupport
RxQueue
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Read( void )
{ /* \trace SPEC-1776 */
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  CanHookBegin_Can_MainFunction_Read();
  errorId = CAN_E_NO_ERROR; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
#if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check Driver is initialized \trace SPEC-1784 */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  {
    errorId = CAN_E_UNINIT;
  }
  else
#endif
  /* ----- Implementation ----------------------------------------------- */
  /* #20 semaphore to secure parallel access to RX buffers interrupt or polling \trace SPEC-1569 */
  if ( canIsRxTaskLocked == kCanFalse )  /* PRQA S 2004 */ /* MD_Can_NoElseAfterIf */
  {
#if defined(C_ENABLE_RX_POLLING) /* COV_CAN_RX_POLLING */
    CAN_CHANNEL_CANTYPE_LOCAL
#endif
    canIsRxTaskLocked = kCanTrue; /* PRQA S 2982 */ /* MD_MSR_RetVal */
#if defined(C_ENABLE_RX_POLLING) /* \trace SPEC-1782 */ /* COV_CAN_RX_POLLING */
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++)
# endif
    { /* #30 iterate over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
      if (!CanHL_IsControllerInit(channel))
      { /* #60 Check controller is initialized */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        if ( !CanHL_IsSleep(channel) )
        { /* #70 do not access CAN hardware in SLEEP */
          /* #80 over all HW channel \trace SPEC-1774 */
# if defined(C_ENABLE_RX_FULLCAN_OBJECTS)
          /* #90 search for all pending FullCAN mailbox objects and call notification */
          CanHL_RxFullCanPolling(CAN_HW_CHANNEL_CANPARA_ONLY);
# endif
# if defined(C_ENABLE_RX_BASICCAN_OBJECTS) /* COV_CAN_MULTIPLE_BASICCAN */
          /* #100 search for all pending BasicCAN mailbox objects and call notification */
          CanHL_RxBasicCanPolling(CAN_HW_CHANNEL_CANPARA_ONLY);
# endif
        }
      }
    }
#endif /* C_ENABLE_RX_POLLING */
#if defined(C_ENABLE_RX_QUEUE)
    /* #200 execute RxQueue CanHL_RxQueueExecution() */
    CanHL_RxQueueExecution(); 
#endif
    canIsRxTaskLocked = kCanFalse;
  }

  /* ----- Development Error Report --------------------------------------- */
#if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR) /* PRQA S 2992,2996 */ /* MD_Can_ConstValue */
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_READ_ID, errorId); /* PRQA S 2880 */ /*  MD_MSR_Unreachable */
  }
#else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif
  CanHookEnd_Can_MainFunction_Read();
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_MainFunction_BusOff
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_BusOff
Relation_Context:
Relation:
StatusPolling, DevErrorDetect, ChannelAmount
StatusPolling, OneChOpt
StatusPolling, Variant, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_BusOff( void )
{ /* \trace SPEC-1783 */
  /* ----- Local Variables ---------------------------------------------- */
#if defined(C_ENABLE_ERROR_POLLING) /* \trace SPEC-1778 */ /* COV_CAN_ERROR_POLLING */
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized \trace SPEC-1780 */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  {  
    /* ----- Implementation ----------------------------------------------- */
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++)
# endif
    { /* #20 over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
      if (!CanHL_IsControllerInit(channel))
      { /* #50 Check controller is initialized */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        if ( !CanHL_IsSleep(channel) )
        { /* #60 do not access CAN hardware in SLEEP */
          /* #80 disable CAN interrupts */
          Can_DisableControllerInterrupts((uint8)channel);
          /* #90 call CanHL_ErrorHandling */
          CanHL_ErrorHandling( CAN_HW_CHANNEL_CANPARA_ONLY );
          Can_EnableControllerInterrupts((uint8)channel);
        }
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_BO_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
#endif /* C_ENABLE_ERROR_POLLING */
}


/****************************************************************************
| NAME:             Can_MainFunction_Wakeup
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Wakeup
Relation_Context:
Relation:
WakeupPolling, Wakeup, DevErrorDetect
WakeupPolling, Wakeup, OneChOpt
WakeupPolling, Wakeup, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Wakeup( void )
{ /* \trace SPEC-1770 */
  /* ----- Local Variables ---------------------------------------------- */
}

/****************************************************************************
| NAME:             Can_MainFunction_Mode
****************************************************************************/
/*
|<DataModelStart>| Can_MainFunction_Mode
Relation_Context:
Relation:
DevErrorDetect
OneChOpt, ChannelAmount
Variant, ChannelAmount
DevErrorDetect, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_MainFunction_Mode( void )
{ /* \trace SPEC-1775 */
  /* ----- Local Variables ---------------------------------------------- */
  CAN_CHANNEL_CANTYPE_LOCAL
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized \trace SPEC-1779 */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  { /* #15 EXCLUSIVE_AREA_6 avoid nesting mode changes (e.g. same API, initialization or BUSOFF) */
    /* ----- Implementation ----------------------------------------------- */
    SchM_Enter_Can_CAN_EXCLUSIVE_AREA_6();
# if !defined( C_SINGLE_RECEIVE_CHANNEL )
    for (channel = 0u; channel < kCanNumberOfChannels; channel++) /* CM_CAN_HL01 */
# endif
    { /* #20 over all active controller */
# if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON) /* one controller optimization is always off */
      if ( Can_GetCanIfChannelId(channel) == kCanChannelNotUsed ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      { /* not for inactive controller */
        continue;
      }
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
      if (!CanHL_IsControllerInit(channel))
      { /* #50 Check controller is initialized */ /* \trace SPEC-1779 */
        errorId = CAN_E_UNINIT;
      }
      else
# endif
      {
        uint8 transitionRequest;
        uint8 busOffRecovery;
        uint8 doRamCheck;
        uint8 transitionState;
        transitionRequest = Can_GetModeTransitionRequest(channel);
        busOffRecovery = Can_GetBusOffTransitionRequest(channel);
        doRamCheck = Can_GetRamCheckTransitionRequest(channel);
        /* #55 only one transition request at one time is possible - execute it \trace SPEC-1771 */
        if(transitionRequest != kCanModeNone)
        {
          transitionState = CanLL_ModeTransition(CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST transitionRequest, busOffRecovery, doRamCheck);
          switch(transitionRequest)
          {
            case kCanModeStopReinitFast: /* COV_CAN_TRANSITION_REQUEST */
            case kCanModeStopReinit: /* COV_CAN_TRANSITION_REQUEST */
              CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_STOP, CANIF_CS_STOPPED, transitionState);
              break;
            case kCanModeStart: /* COV_CAN_TRANSITION_REQUEST */
            case kCanModeStartReinit: /* COV_CAN_TRANSITION_REQUEST */
            case kCanModeResetBusOffEnd: /* COV_CAN_TRANSITION_REQUEST */
# if defined(C_ENABLE_SILENT_MODE)
            case kCanModeSilent: /* COV_CAN_TRANSITION_REQUEST */
# endif
              CanHL_NotifyTransition(CAN_CHANNEL_CANPARA_FIRST CAN_STATUS_START, CANIF_CS_STARTED, transitionState);
              if ( transitionState == kCanOk ) /* COV_CAN_TRANSITION_REQUEST */
              {
                Can_SetIsBusOff(channel, FALSE); /* SBSW_CAN_HL08 */
              }
              break;
            case kCanModeResetBusOffStart: /* COV_CAN_TRANSITION_REQUEST */ /* not expected, no repetition request */
            default: /* COV_CAN_TRANSITION_REQUEST */
              break;
          }
        }
      }
    } /* over all channels */
    SchM_Exit_Can_CAN_EXCLUSIVE_AREA_6();
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_MAINFCT_MODE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */


/****************************************************************************
| NAME:             Can_CancelTx
****************************************************************************/
/*
|<DataModelStart>| Can_CancelTx
Relation_Context:
TransmitCancellationAPI
Relation:
DevErrorDetect, TxFullCANSupport
OneChOpt
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
TxFullCANSupport, HwCancelTx
ChannelAmount
TxFullAmount
TxBasicAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_CancelTx( Can_HwHandleType Hth, PduIdType PduId )
{
  /* ----- Local Variables ---------------------------------------------- */
#if defined(C_ENABLE_CANCEL_SUPPORT_API)
  CAN_CHANNEL_CANTYPE_LOCAL
  tCanTxCancellationParaStruct txCancellationPara;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (Hth >= Can_GetSizeOfMailbox())
  { /* #20 Check Hth is in range */
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
#  if defined(C_ENABLE_TX_FULLCAN_OBJECTS)
  if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
#  else
  if ((Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_MUX_TYPE) && (Can_GetMailboxType(Hth) != CAN_TX_BASICCAN_FIFO_TYPE)) /* COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG */
#  endif
  { /* #30 Check Hth is FullCAN or BasicCAN */
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
# endif
  {
# if !defined( C_SINGLE_RECEIVE_CHANNEL ) /* otherwise 'channel' is a define */
    channel = Can_GetMailboxController(Hth);
# endif
# if (CAN_DEV_ERROR_DETECT == STD_ON)
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
    if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */ /* COV_CAN_GENDATA_FAILURE */
    { /* #40 Check parameter controller is in range */
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
    if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_FAILURE */
    { /* #60 Check parameter controller is valid */
      errorId = CAN_E_PARAM_CONTROLLER;
    }
    else
#  endif
    if (!CanHL_IsControllerInit(channel))
    { /* #70 Check controller is initialized */
      errorId = CAN_E_UNINIT;
    }
    else
# endif
    {
      /* ----- Implementation ----------------------------------------------- */
      txCancellationPara.mailboxHandle = Hth;
      txCancellationPara.mailboxElement = 0u;
      txCancellationPara.activeSendObject = CanHL_GetActiveSendObject(txCancellationPara.mailboxHandle, txCancellationPara.mailboxElement);

# if defined (C_ENABLE_TX_FULLCAN_OBJECTS)
      if ( Can_GetMailboxType(Hth) != CAN_TX_FULLCAN_TYPE ) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
# endif
      { /* #100 is BasicCAN */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
        for (; txCancellationPara.mailboxElement < Can_GetMailboxSize(Hth); txCancellationPara.mailboxElement++, txCancellationPara.activeSendObject++) /* PRQA S 3418 */ /* MD_Can_IncompleteForLoop */
# endif
        { /* #110 over all Multiplexed TX objects - search for handle */
          if (Can_GetActiveSendPdu(txCancellationPara.activeSendObject) == PduId)
          {
            if ((Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferSend)
                )  /* COV_CAN_CANCEL_SW_STIMULATION */
            { /* #120 PDU found in active send list - handle found */
              /* #130 CANCEL_IN_HW is active - just suppress TX confirmation */
              Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw); /* mark as cancelled by SW */ /* SBSW_CAN_HL04 */
# if defined(C_ENABLE_MULTIPLEXED_TRANSMISSION) 
              break;
# endif
            }
          }
        }
      }
# if defined (C_ENABLE_TX_FULLCAN_OBJECTS)
      else
      { /* #200 is FullCAN */
        if (Can_GetActiveSendPdu(txCancellationPara.activeSendObject) == PduId)
        {
          if ((Can_GetActiveSendState(txCancellationPara.activeSendObject) == kCanBufferSend)
             )  /* COV_CAN_CANCEL_SW_STIMULATION */
          { /* #210 mailbox to cancel is valid (PDU, handle, send state OK) */
            /* #220 CANCEL_FULLCAN_IN_HW is active - just suppress TX confirmation */
            Can_SetActiveSendState(txCancellationPara.activeSendObject, kCanBufferCancelSw); /* mark as cancelled by SW */ /* SBSW_CAN_HL04 */
          }
        }
      }
# endif
    }
    CAN_CHANNEL_DUMMY_STATEMENT; /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_WRITE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
#else /* CAN_ENABLE_CANCEL_SUPPORT_API */
  CAN_DUMMY_STATEMENT(Hth); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
  CAN_DUMMY_STATEMENT(PduId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif /* CAN_ENABLE_CANCEL_SUPPORT_API */
} /* PRQA S 6030,6080 */ /* MD_MSR_STCYC,MD_MSR_STMIF */

#if (CAN_GET_STATUS == STD_ON)
/****************************************************************************
| NAME:             Can_GetStatus
****************************************************************************/
/*
|<DataModelStart>| Can_GetStatus
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, uint8, CODE) Can_GetStatus( uint8 Controller )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = CAN_STATUS_INCONSISTENT; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #20 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* #50 Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    CanLL_GetStatusBegin(CAN_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
    /* #100 set logical state as return value */
    canReturnCode = (uint8)Can_GetLogStatus(channel);
    if ( CanLL_HwIsBusOff(channel) ) /* COV_CAN_HARDWARE_FAILURE */
    { /* #150 set BUSOFF - BUSOFF can only happen on first HW channel (with TX objects) */
      canReturnCode |= CAN_STATUS_BUSOFF;
    }
# if defined(C_ENABLE_EXTENDED_STATUS) /* COV_CAN_EXTENDED_STATUS */
    {    
      if ( CanLL_HwIsPassive(channel) ) /* COV_CAN_HARDWARE_FAILURE */
      { /* #160 set Error Passive */
        canReturnCode |= CAN_STATUS_PASSIVE;
      }    
      if ( CanLL_HwIsWarning(channel) ) /* COV_CAN_HARDWARE_FAILURE */
      { /* #170 set Error Warning */
        canReturnCode |= CAN_STATUS_WARNING;
      }
    }
# endif /* C_ENABLE_EXTENDED_STATUS */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return (uint8)canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerMode
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerMode
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerMode( uint8 Controller, Can_ControllerStatePtrType ControllerModePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameters are valid */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #20 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (ControllerModePtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 get logical controller mode from state machine variable */
    if (!CanHL_IsControllerInit(channel))
    {
      *ControllerModePtr = CAN_CS_UNINIT; /* SBSW_CAN_HL51 */
    }
    else if (CanHL_IsStart(channel))
    {
      *ControllerModePtr = CAN_CS_STARTED; /* SBSW_CAN_HL51 */
    } 
    else if (CanHL_IsSleep(channel))
    {
      *ControllerModePtr = CAN_CS_SLEEP; /* SBSW_CAN_HL51 */
    }
    else /* default is:   if (CanHL_IsStop(channel)) */
    {
      *ControllerModePtr = CAN_CS_STOPPED; /* SBSW_CAN_HL51 */
    }
    canReturnCode = E_OK;
  }
  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_MODE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerErrorState
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerErrorState
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerErrorState( uint8 Controller, Can_ErrorStatePtrType ErrorStatePtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (ErrorStatePtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    CanLL_GetStatusBegin(CAN_CHANNEL_CANPARA_ONLY); /* PRQA S 2987 */ /* MD_Can_EmptyFunction */
    if ( CanLL_HwIsBusOff(channel) ) /* COV_CAN_HARDWARE_FAILURE */
    { /* #40 set BUSOFF */
      *ErrorStatePtr = CAN_ERRORSTATE_BUSOFF; /* SBSW_CAN_HL52 */
    } 
# if defined(C_ENABLE_EXTENDED_STATUS) /* COV_CAN_EXTENDED_STATUS */
    else if ( CanLL_HwIsPassive(channel) ) /* COV_CAN_HARDWARE_FAILURE */
    { /* #50 set Error Passive */
      *ErrorStatePtr = CAN_ERRORSTATE_PASSIVE; /* SBSW_CAN_HL52 */
    }
# endif /* C_ENABLE_EXTENDED_STATUS */
    else
    { /* #60 default return is ACTIVE */
      *ErrorStatePtr = CAN_ERRORSTATE_ACTIVE; /* SBSW_CAN_HL52 */
    }
    canReturnCode = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_STATE_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerTxErrorCounter
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerTxErrorCounter
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerTxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType TxErrorCounterPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (TxErrorCounterPtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 get error counter from hardware */
# if defined( C_SINGLE_RECEIVE_CHANNEL )
    *TxErrorCounterPtr = CanTxActualErrorCounter(); /* SBSW_CAN_HL53 */
# else
    *TxErrorCounterPtr = CanTxActualErrorCounter(channel); /* SBSW_CAN_HL53 */
# endif
    canReturnCode = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_TXCNT_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

/****************************************************************************
| NAME:             Can_GetControllerRxErrorCounter
****************************************************************************/
/*
|<DataModelStart>| Can_GetControllerRxErrorCounter
Relation_Context:
CanGetStatus
Relation:
DevErrorDetect, OneChOpt
DevErrorDetect, Variant
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerRxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType RxErrorCounterPtr )
{
  /* ----- Local Variables ---------------------------------------------- */
  Std_ReturnType canReturnCode;
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  canReturnCode = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  /* #10 Check if parameter controller is valid and state is INIT */
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
#  if (CAN_POSTBUILD_VARIANT_SUPPORT == STD_ON)
  if (Can_GetCanIfChannelId(channel) == kCanChannelNotUsed) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
  {
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
  if (!CanHL_IsControllerInit(channel))
  { /* Check controller is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (RxErrorCounterPtr == NULL_PTR)
  {
    errorId = CAN_E_PARAM_POINTER;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #40 get error counter from hardware */
# if defined( C_SINGLE_RECEIVE_CHANNEL )
    *RxErrorCounterPtr = CanRxActualErrorCounter(); /* SBSW_CAN_HL54 */
# else
    *RxErrorCounterPtr = CanRxActualErrorCounter(channel); /* SBSW_CAN_HL54 */
# endif
    canReturnCode = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_GETCTR_RXCNT_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return canReturnCode;
} /* PRQA S 6080 */ /* MD_MSR_STMIF */

#endif

#if defined(C_ENABLE_MIRROR_MODE)
/****************************************************************************
| NAME:             Can_SetMirrorMode
****************************************************************************/
/*
|<DataModelStart>| Can_SetMirrorMode
Relation_Context:
MirrorMode
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_SetMirrorMode( uint8 Controller, CddMirror_MirrorModeType mirrorMode )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  { /* #30 set mirror mode for given controller */
    /* ----- Implementation ----------------------------------------------- */
    Can_SetMirrorModeState(channel, mirrorMode); /* SBSW_CAN_HL20 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif

#if defined(C_ENABLE_SILENT_MODE)
/****************************************************************************
| NAME:             Can_SetSilentMode
****************************************************************************/
/*
|<DataModelStart>| Can_SetSilentMode
Relation_Context:
SilentMode
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetSilentMode( uint8 Controller, Can_SilentModeType silentMode )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  Std_ReturnType retval;
  errorId = CAN_E_NO_ERROR;
  retval = E_NOT_OK; /* PRQA S 2982 */ /* MD_MSR_RetVal */
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  { /* #30 set silent mode for given controller */
    /* ----- Implementation ----------------------------------------------- */
    Can_SetSilentModeState(channel, silentMode); /* SBSW_CAN_HL20 */
    retval = E_OK;
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
  return retval;
}
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
/****************************************************************************
| NAME:             Can_RamCheckExecute
****************************************************************************/
/*
|<DataModelStart>| Can_RamCheckExecute
Relation_Context:
Relation:
RamCheck, DevErrorDetect, OneChOpt, ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckExecute( uint8 Controller )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  { /* #30 Do RamCheck by execute reinitialization with activated check */
    uint8 transitionState;
    /* ----- Implementation ----------------------------------------------- */
    transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanExecuteRamCheck);
    if (transitionState == kCanOk) /* COV_CAN_TRANSITION_REQUEST */
    { /* #40 check transition STOP (Reinit) is successful */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             Can_RamCheckEnableMailbox
****************************************************************************/
/*
|<DataModelStart>| Can_RamCheckEnableMailbox
Relation_Context:
Relation:
RamCheck, DevErrorDetect
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableMailbox( Can_HwHandleType htrh )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
  if (htrh >= Can_GetSizeOfMailbox()) { /* CM_CAN_HL28 */
    errorId = CAN_E_PARAM_HANDLE;
  }
  else
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #15 disable controller to force reinitialization afterwards in Can_RamCheckEnableController() */
    Can_SetLogStatus(Can_GetMailboxController(htrh), CAN_DEACTIVATE_CONTROLLER); /* SBSW_CAN_HL40 */
    /* #20 reactivate mailbox */
    Can_SetMailboxState(htrh, kCanOk); /* SBSW_CAN_HL34 */
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}

/****************************************************************************
| NAME:             Can_RamCheckEnableController
****************************************************************************/
/*
|<DataModelStart>| Can_RamCheckEnableController
Relation_Context:
RamCheck
Relation:
DevErrorDetect, OneChOpt
ChannelAmount
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableController( uint8 Controller )
{
  /* ----- Local Variables ---------------------------------------------- */
  uint8 errorId;
  errorId = CAN_E_NO_ERROR;
  
  /* ----- Development Error Checks ------------------------------------- */
# if (CAN_DEV_ERROR_DETECT == STD_ON)
  if (canConfigInitFlag == CAN_STATUS_UNINIT)
  { /* #10 Check Driver is initialized */
    errorId = CAN_E_UNINIT;
  }
  else
#  if !defined( C_SINGLE_RECEIVE_CHANNEL )
  if (channel >= kCanNumberOfChannels) /* CM_CAN_HL01 */
  { /* #20 Check parameter controller is in range */
    errorId = CAN_E_PARAM_CONTROLLER;
  }
  else
#  endif
# endif
  {
    /* ----- Implementation ----------------------------------------------- */
    /* #30 activate controller only when currently disabled */
    if ( (Can_GetLogStatus(channel) & CAN_DEACTIVATE_CONTROLLER) == CAN_DEACTIVATE_CONTROLLER ) /* COV_CAN_RAM_CHECK_NO_STIMULATION */
    {
      uint8 transitionState;
      /* #40 re-initialize to activate mailboxes and controller after RAM check issue */
      Can_SetLogStatus(channel, Can_GetLogStatus(channel) & (uint8)(~(CAN_DEACTIVATE_CONTROLLER))); /* SBSW_CAN_HL02 */
      transitionState = CanHL_ModeTransition(CAN_CHANNEL_CANPARA_FIRST kCanModeStopReinit, kCanFinishBusOffRecovery, kCanSuppressRamCheck);
      if (transitionState == kCanOk) /* COV_CAN_TRANSITION_REQUEST */
      { /* #40 check transition STOP (Reinit) is successful */
        Can_SetLogStatus(channel, Can_GetLogStatus(channel) | CAN_STATUS_STOP); /* STOP mode reached */ /* SBSW_CAN_HL02 */
      }
    }
  }

  /* ----- Development Error Report --------------------------------------- */
# if (CAN_DEV_ERROR_REPORT == STD_ON)
  if (errorId != CAN_E_NO_ERROR)
  { /* Throw DET if an error detected before */
    Can_CallDetReportError(CAN_HW_ACCESS_ID, errorId);
  }
# else
  CAN_DUMMY_STATEMENT(errorId); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
# if defined( C_SINGLE_RECEIVE_CHANNEL )
  CAN_DUMMY_STATEMENT(Controller); /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
# endif
}
#endif



#if defined( C_ENABLE_ISR_MANDATORY )  /* ISR necessary; no pure polling configuration*/

/* **************************************************************************
| NAME:             CanInterrupt
| CALLED BY:        CanIsr_<physicalChannelIndex>()
| PRECONDITIONS:
| INPUT PARAMETERS: canHwChannel
| RETURN VALUES:    none
| DESCRIPTION:      Interrupt service functions according to the CAN controller
|                   interrupt structure
|                   - check for the interrupt reason ( interrupt source )
|                   - work appropriate interrupt:
|                     + status/error interrupt (BUSOFF, wakeup, error warning)
|                     + basic can receive
|                     + full can receive
|                     + can transmit
|
|                   If an RX-Interrupt occurs while the CAN controller is in Sleep mode, 
|                   a wakeup has to be generated. 
|
|                   If an TX-Interrupt occurs while the CAN controller is in Sleep mode, 
|                   an assertion has to be called and the interrupt has to be ignored.
|
|                   The name of BrsTimeStrt...() and BrsTimeStop...() can be adapted to 
|                   really used name of the interrupt functions.
|
* ************************************************************************* */
/*
|<DataModelStart>| CanInterrupt
Relation_Context:
Relation:
OneChOpt
ChannelAmount, RxBasicCANSupport, MultipleBasicCanObjects, RxFullCANSupport, RxPolling, TxPolling, StatusPolling, IndividualPolling
Parameter_PreCompile:
Parameter_Data:
Constrain:
|<DataModelEnd>|
*/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
*/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(V_NONE, void, CODE) CanInterrupt(CAN_HW_CHANNEL_CANTYPE_ONLY)
{
  {
#if !defined ( C_SINGLE_RECEIVE_CHANNEL ) 
    CAN_DUMMY_STATEMENT(canHwChannel);  /* PRQA S 1338, 2983, 3112 */ /* MD_MSR_DummyStmt */
#endif

    /* #10 check for interrupt sources */
#if !defined(C_ENABLE_ERROR_POLLING)
    /* #20 handle error interrupt */
    if(CanInterruptErrorHandling(CAN_HW_CHANNEL_CANPARA_ONLY) == kCanOk) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#endif
    {
#if !defined(C_ENABLE_TX_POLLING) || defined( C_ENABLE_INDIVIDUAL_POLLING )
      CanInterruptTx(CAN_HW_CHANNEL_CANPARA_ONLY);
#endif

#if ( CAN_BOSCH_ERRATUM_012 == STD_ON ) /* COV_CAN_ERRATUM_OFF */
    /* #30 handle timeout interrupt */
      if( (Cn->IR & kCanIR_TOO) != 0UL)
      { /* timeout arrived */
        CanInterruptTimeoutCounter(CAN_HW_CHANNEL_CANPARA_ONLY);
      }
#endif

#if defined( C_ENABLE_RX_BASICCAN_OBJECTS )
      /* #40 handle BasicCAN (FIFO) interrupt */
# if( (!defined( C_ENABLE_RX_BASICCAN_POLLING )) || (defined( C_ENABLE_INDIVIDUAL_POLLING )) ) /* ISR necessary; no pure polling configuration*/
#  if defined( C_ENABLE_MULTIPLE_BASICCAN )
      if( (Can_GetCanIntEnable(canHwChannel) & (kCanIR_RF0N | kCanIR_RF1N)) != 0UL) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        if( (Cn->IR & (kCanIR_RF0N | kCanIR_RF1N)) != 0UL) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#  else
      if( (Can_GetCanIntEnable(canHwChannel) &  kCanIR_RF0N) != 0UL) /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        if( (Cn->IR &  kCanIR_RF0N) != 0UL)  /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
#  endif
        { /* Rx FIFO(0,1) */
          CanBasicInterruptRx(CAN_HW_CHANNEL_CANPARA_ONLY); /* call Interrupt handling with logical channel */
        }
      }
# endif
#endif
#if defined( C_ENABLE_RX_FULLCAN_OBJECTS )
# if ( (!defined( C_ENABLE_RX_FULLCAN_POLLING )) || (defined( C_ENABLE_INDIVIDUAL_POLLING )) )          /* ISR necessary; no pure polling configuration*/
      /*Rx Buffer Handling
        - Reset interrupt flag IR.DRX
        - Read New Data registers
        - Read messages from Message RAM
        - Reset New Data flags of processed messages */
      /* #50 handle FullCAN interrupt */
      if( (Can_GetCanIntEnable(canHwChannel) & kCanIR_DRX) != 0UL)  /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
      {
        if( (Cn->IR & kCanIR_DRX) != 0UL) /* PRQA S 0303 */ /* MD_Can_HwAccess */ /* COV_CAN_GENDATA_NOT_IN_ALL_CONFIG */
        { /* rcvd FullCAN msg(s) */
          CanFullInterruptRx(CAN_HW_CHANNEL_CANPARA_ONLY);     /* call Interrupt handling with logical channel */
        }
      }
# endif
#endif
    }
  } /* end else DET check */

} /* PRQA S 6010,6030,6050,6080 */ /* MD_MSR_STPTH,MD_MSR_STCYC,MD_MSR_STCAL,MD_MSR_STMIF */
/* CanInterrupt */
#endif /* End of ISR_MANDATORY */
/* CODE CATEGORY 1 END */

#define CAN_STOP_SEC_CODE  /*----------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
/****************************************************************************/

/****************************************************************************/
/*  excluded Requirements                                                   */
/****************************************************************************/
/* part of other component: SPEC-1597 */
/* Currently no use-case / not supported: SPEC-1601, SPEC-1592, SPEC-1582 */

/****************************************************************************/
/*  MISRA deviations                                                        */
/****************************************************************************/
/* Justification for module-specific MISRA deviations:

MD_Can_Goto:
PRQA message 2001
  Reason: 'goto' statements are used to reduce code complexity.
  Risk: Incorrect jump.
  Prevention: Code inspection and runtime tests.

MD_Can_MultipleReturn:
PRQA message 2889
  Reason: Multiple return paths are used to reduce code complexity.
  Risk: Return a function too soon.
  Prevention: Code inspection and runtime tests.

MD_Can_ParameterName:
PRQA message 0784
  Reason: API parameter that is also used as a macro name is accepted for compatibility reasons.
  Risk: The macro can change the declaration unintentionally.
  Prevention: Relevant inconsistencies in function declarations, definitions and calls are detected by the compiler.

MD_Can_ConstValue:
PRQA message 2741, 2742, 2880, 2985, 2986, 2990, 2991, 2992, 2993, 2994, 2995, 2996
  Reason: Value is constant depending on configuration aspects or platform specific implementation. This leads to constant control expressions, unreachable code or redundant operations.
  Risk: Wrong or missing functionality.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_EmptyFunction:
PRQA message 2987
  Reason: Function is empty depending on configuration aspects and platform specific implementation.
  Risk: Function implementation missing.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_NoneConstParameterPointer:
PRQA message 3673
  Reason: Non-const pointer parameter is required by the internal interface or compatibility reasons but depending on the configuration or specific platform implementation the target may not always be modified.
  Risk: Read only data could be modified without intention.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_ModuleDefine:
PRQA message 0602, 0603
  Reason: Usage of reserved identifiers with leading underscores is accepted for compatibility reasons.
  Risk: Name conflicts.
  Prevention: Compile and link of the different variants in the component and integration test.

MD_Can_RedundantInit:
PRQA message 2981
  Reason: Reduce code complexity by using an explicit variable initializer that may be always modified before being used in some configurations.
  Risk: Unintended change of value.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_GlobalScope:
PRQA message 3218
  Reason: The usage of variables depends on configuration aspects and they may be used only once or defined globally to improve overview.
  Risk: None.
  Prevention: None.

MD_Can_ExternalScope:
PRQA message 1514, 3408, 3447, 3451, 3210
  Reason: The variable is used by other modules and can't be declared static.
  Risk: Name conflicts.
  Prevention: Compile and link of the different variants in the component and integration test.

MD_Can_GenData:
PRQA message 1533
  Reason: These constants are defined in a generated file and cannot be moved to the static source file.
  Risk: None.
  Prevention: None.

MD_Can_Union:
PRQA message 0750, 0759
  Reason: Using union type to handle different data accesses.
  Risk: Misinterpreted data.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_Assertion:
PRQA message 2842
  Reason: Assertion leads to apparent out of bounds indexing.
  Risk: Undefined behaviour.
  Prevention: Code inspection. Assertion itself detects out of bounds indexing.

MD_Can_PointerVoidCast:
PRQA message 0314, 0316
  Reason: API is defined with pointer to void parameter, so pointer has to be casted to or from void.
  Risk: Wrong data access or undefiend behavior for platforms where the byte alignment is not arbitrary.
  Prevention: Code inspection and test with the target compiler/platform in the component test.

MD_Can_PointerCast:
PRQA message 0310
  Reason: Different pointer type is used to access data.
  Risk: Wrong memory is accessed or alignment is incorrect.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_NoneVolatilePointerCast:
PRQA message 0312
  Reason: Cast to none volatile pointer.
  Risk: Incorrect multiple context access.
  Prevention: Code inspection checks that the value is not multiple accessed.

MD_Can_HwAccess:
PRQA message 0303
  Reason: Hardware access needs cast between a pointer to volatile object and an integral type.
  Risk: Access of unknown memory.
  Prevention: Runtime tests.

MD_Can_MixedSigns:
PRQA message 4393, 4394
  Reason: Casting from signed to unsigned types and vice versa is needed as different types are intentionally used.
  Risk: Value is changed during cast.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_IntegerCast:
PRQA message 4391, 4398, 4399, 4491
  Reason: Explicit cast to a different integer type.
  Risk: Value is changed during cast.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_CompilerAbstraction:
PRQA message 0342
  Reason: Glue operator used for compiler abstraction.
  Risk: Only K&R compiler support glue operator.
  Prevention: Compile test show whether compiler accept glue operator.

MD_Can_NoElseAfterIf:
PRQA message 2004
  Reason: No default handling needed for if-else-if here.
  Risk: Missing default handling.
  Prevention: Code inspection and test of different variants in the component test.

MD_Can_IncompleteForLoop:
PRQA message 3418
  Reason: Comma operator in for-loop header is used to get a compact code.
  Risk: Uninitialized variable.
  Prevention: Code inspection and test of different variants in the component test.


MD_Can_HL_UndefTypes:
ID 0841
  Reason: CBD types defined for CAN driver usage but should be not seen in other modules to avoid MSR-CBD mixture problems.
  Risk: None
  Prevention: None


MD_Can_0404_LL:
Misra Rule 13.2
  Reason:  Byte swap macro used.
  Risk: None
  Prevention: Code inspection assuring that there is no other access to the data during several accesses than by the swap macro.

MD_Can_1891_LL:
Misra Rule 10.8
  Reason: Due to configuration specific types.
  Risk: None
  Prevention: Code inspection.

MD_Can_3197_LL:
Misra Rule 0.0
  Reason: Due to fragmented source code it is more safe to do a pre initialization
  Risk: None
  Prevention: Code inspection. Assure that the variable is always assigned before used.

MD_Can_3205_LL:
No Misra-C 2004 Rule applicable
  Reason: potentially unused variable
  Risk: uninitialized pointer and wrong memory access
  Prevention: Code inspection and component test.

MD_Can_3305_LL:
Misra Rule 0.0
  Reason: Generic access macro for normal and extended CAN-IDs
  Risk: Memory access exception error.
  Prevention: Code inspection. Alignment is checked for each specific platform.

MD_Can_1006_inlineASM:
Misra Rule 1.1
  Reason: Improve performance by using (platform specific) inline assembler.
  Risk: None
  Prevention: None

MD_Can_0777_LL:
Misra Rule 5.1
  Reason: Identifiers rely on the significance of more than 31 characters.
  Risk: compile or linker error
  Prevention: None

MD_Can_0306_HWaccess_LL:
Misra Rule 11.3
  Reason: Hardware access need pointer to CAN Message RAM.
  Risk: Access of unknown memory.
  Prevention: Runtime tests.

MD_Can_4558_RHsideEffect:
Misra Rule 10.1
  Reason: Right hand side evaluation does not need to take place in the case where the left hand side evaluates to false.
  Risk: None
  Prevention: None

MD_Can_3325_LL:
Misra Rule 14.1
  Reason: Configuration or platform specific dependent constant control expression and thus unreachable code.
  Risk: Incorrect behavior depend on settings.
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_0635:
Misra Rule 6.4
  Reason: Using unsigned int as approved by MISRA
  Risk: None
  Prevention: Code inspection and test of the different variants in the component test.

MD_Can_3431_LL:
Misra Rule 19.4
  Reason: This control statement definition is explicitly the intention here.
  Risk: None
  Prevention: None

MD_Can_3614_LL:
Preprocessor
  Reason: Defined within a block due to code repetition mechanism.
  Risk: None
  Prevention: Code inspection, compile tests and runtime tests.


  MD_Can_2982_LL:
Major
  Reason: Preset with default value or read to reset the hardware.
  Risk:   None
  Prevention: None

MD_Can_3203_LL:
Redundancy
  Reason: Used for hardware access due to reset at read.
  Risk:   None
  Prevention: None

MD_Can_0488_LL:
Misra Rule 17.4
  Reason: performing pointer arithmetic
  Risk: Segmentation faults or storage violations
  Prevention: Code review and runtime tests
  
MD_Can_0841:
Misra Rule 19.6
  Reason: Rarely used and always for test purpose.
  Risk: None.
  Prevention: Code inspection and multiple configuration aspects used in component test.

*/

/****************************************************************************/
/*  Silent deviations                                                       */
/****************************************************************************/
/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_CAN_HL01
 \DESCRIPTION Write access to CanModeTransitionRequest with controller as index. Controller index is checked against sizeof CanModeTransitionRequest in Can_SetControllerMode(), Can_RamCheckExecute(), Can_MainFunction_Mode(), Can_Init() and Can_InitController().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL02
 \DESCRIPTION Write access to CanLogStatus with controller as index. Controller index is checked against sizeof CanLogStatus in Can_SetControllerMode(), CanHL_ErrorHandling(), Can_RamCheckEnableController(), Can_MainFunction_Mode(), Can_Init() and Can_InitController().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL04
 \DESCRIPTION Write access to CanActiveSendState with activeSendObject as index. activeSendObject is checked against size of ActiveSendObject in Can_CleanUpSendState(), CanHL_WritePrepare(), CanHL_InitTxFullCAN(), CanHL_InitTxBasicCAN(), CanHL_TxTaskCancelationHandling(), CanHL_TxConfirmation() and Can_CancelTx().
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL05
 \DESCRIPTION Write access to CanActiveSendPdu with activeSendObject as index. activeSendObject is checked against size of ActiveSendObject.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL06
 \DESCRIPTION Call Can_GenericPrecopy() and CanIf_RxIndication() with parameter RX Queue data pointer. The data pointer is only used for read access and it is always a valid pointer (module local defined).
 \COUNTERMEASURE \R [CM_CAN_HL25]

\ID SBSW_CAN_HL07
 \DESCRIPTION Call Can_GenericPrecopy() and CanIf_RxIndication() with parameter Rx Struct data pointer. The data pointer is only used for read access. Parameter is of type P2CONST in API.
 \COUNTERMEASURE \N [CM_CAN_HL31]

\ID SBSW_CAN_HL08
 \DESCRIPTION Write access to CanIsBusOff with controller as index. Controller index is checked against sizeof CanIsBusOff in Can_SetControllerMode(), CanHL_ErrorHandling() and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL09
 \DESCRIPTION Write access to CanIsWakeup with controller as index. Controller index is checked against sizeof CanIsWakeup in CanHL_WakeUpHandling(), Can_CheckWakeup(), reinitialization and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL10
 \DESCRIPTION Write access to VersionInfo pointer within function Can_GetVersionInfo()
 \COUNTERMEASURE \N caller of Can_GetVersionInfo() has to ensure that VersionInfo pointer is valid. (global description available)

\ID SBSW_CAN_HL11
 \DESCRIPTION Write access to CanLastInitObject with controller as index. Controller index is checked against sizeof CanLastInitObject in Can_InitStruct(), Can_ChangeBaudrate(), Can_SetBaudrate() and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL12
 \DESCRIPTION Write access to CanInterruptCounter with controller as index. Controller index is checked against sizeof CanInterruptCounter in Can_Init(), Can_EnableControllerInterrupts() and Can_DisableControllerInterrupts()
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL16
 \DESCRIPTION Call CanLL_CanInterruptDisable() with parameter CanInterruptOldStatus as pointer (compiler secures used type in function declaration fitting to given pointer parameter type).
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL18
 \DESCRIPTION Write access to CanRxQueueBuffer with queue write index. Write index is checked against size of CanRxQueueBuffer.
 \COUNTERMEASURE \R [CM_CAN_HL24]

\ID SBSW_CAN_HL19
 \DESCRIPTION Write access to CanRxQueueBuffer.data with queue write index and data index. Write index is checked against size of CanRxQueueBuffer. (see also generator CM_CAN_HL04 qualified use case CSL02)
 \COUNTERMEASURE \R [CM_CAN_HL24]
                 \R [CM_CAN_HL17]

\ID SBSW_CAN_HL20
 \DESCRIPTION Write access to CanMirrorModeState with controller as index. Controller is checked against size of CanMirrorModeState.
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL22
 \DESCRIPTION Write access to ActiveSendData with activeSendData + length as index. Index is checked against size of table.
 \COUNTERMEASURE \R [CM_CAN_HL20]

\ID SBSW_CAN_HL23
 \DESCRIPTION Write access to ActiveSendObject stuct with activeSendObject as index. activeSendObject is checked against size of CanActiveSendObject.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL24
 \DESCRIPTION Call Appl_GenericPreTransmit() with parameter PduInfoPtr_var pointer (module local defined).
 \COUNTERMEASURE \N The pointer is static and always valid.

\ID SBSW_CAN_HL25
 \DESCRIPTION Call CanIf_CancelTxConfirmation() with parameter CanActiveSendObject.PduInfo[activeSendObject] as pointer with activeSendObject as index. activeSendObject is checked against size of CanActiveSendObject.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL26
 \DESCRIPTION Call CanHL_RxBasicMsgReceivedBegin(), CanHL_RxMsgReceivedNotification() and CanHL_RxBasicMsgReceivedEnd() with parameter rxBasicPara pointer (module local defined).
 \COUNTERMEASURE \N The pointer is static and always valid.

\ID SBSW_CAN_HL27
 \DESCRIPTION Call CanHL_RxFullMsgReceivedBegin(), CanHL_RxFullReceivedNotification() and CanHL_RxFullMsgReceivedEnd() with parameter rxFullPara pointer (module local defined).
 \COUNTERMEASURE \N The pointer is static and always valid.

\ID SBSW_CAN_HL29
 \DESCRIPTION Write access to rxBasicPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL30
 \DESCRIPTION Write access to rxFullPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL31
 \DESCRIPTION Call Initialization subroutines with initPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL32
 \DESCRIPTION Call Appl_GenericConfirmation and CanHL_SetCanPduInfo with canPdu pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL33
 \DESCRIPTION Write access to CanBusOffCounter with controller as index. Controller index is checked against sizeof CanBusOffCounter in Can_SetControllerMode(), CanHL_ErrorHandling() and Can_Init().
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_HL34
 \DESCRIPTION Write access to CanMailboxState with mailbox handle as index. Index secured by ComStackLib [CM_CAN_HL29] and [CM_CAN_HL30] and checked against size of CanMailboxState.
 \COUNTERMEASURE \R [CM_CAN_HL28]

\ID SBSW_CAN_HL35
 \DESCRIPTION Call with pointer to CAN cell register for write and read access.
 \COUNTERMEASURE \N Caller ensures validity of pointer parameter.

\ID SBSW_CAN_HL36
 \DESCRIPTION Write access to initPara structure as pointer (local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL37
 \DESCRIPTION Call GetElapsedValue with timer value pointers as parameter (module local defined).
 \COUNTERMEASURE \N The timer values are static and always valid.

\ID SBSW_CAN_HL38
 \DESCRIPTION Call GetCounterValue with timer value (LoopTimeout) pointers as parameter. Controller index is checked against size of ControllerData, kCanLoopXXX as index in LoopTimeout table is always smaller than the dimension of the table given as static user type in ComStackLib and checked against this value.
 \COUNTERMEASURE \R [CM_CAN_HL01]
                 \R [CM_CAN_HL22]

\ID SBSW_CAN_HL39
 \DESCRIPTION Undefine preprocessor switch to stimulate user defined feature (only test purpose).
 \COUNTERMEASURE \N Redefinement activates a none documented feature.

\ID SBSW_CAN_HL40
 \DESCRIPTION Write access to CanLogStatus with controller as index. Controller is secured by qualified use-case CSL03 of ComStackLib.
 \COUNTERMEASURE \N [CM_CAN_HL02]

\ID SBSW_CAN_HL41
 \DESCRIPTION Write access to CanActiveSendState with activeSendObject as index. activeSendObject is temporary stored in a list of [1,3] elements where each element is initialized to a valid value and always written with size check before.
 \COUNTERMEASURE \R [CM_CAN_HL03]

\ID SBSW_CAN_HL42
 \DESCRIPTION Write access to txPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL43
 \DESCRIPTION Write access to taskPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL44
 \DESCRIPTION Call task subroutines with taskPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL45
 \DESCRIPTION Call confirmation subroutines with txConfPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL46
 \DESCRIPTION Write access to txConfPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL47
 \DESCRIPTION Call cancellation subroutines with txCancellationPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL48
 \DESCRIPTION Write access to txCancellationPara (module local defined).
 \COUNTERMEASURE \N The structure is static and always valid.

\ID SBSW_CAN_HL49
 \DESCRIPTION Call transmit subroutines with txPara pointer as parameter (local defined).
 \COUNTERMEASURE \N The structure is static and always valid (pointer to a local stack variable)

\ID SBSW_CAN_HL50
 \DESCRIPTION Write access to TxHwFifo member FillCount, WriteIndex and ReadIndex with Mailbox member TxHwFifo as Index. Index is checked against size of TxHwFifo array.
 \COUNTERMEASURE \R [CM_CAN_HL32]

\ID SBSW_CAN_HL51
 \DESCRIPTION Write access to ControllerModePtr pointer within function Can_GetControllerMode()
 \COUNTERMEASURE \N caller of Can_GetControllerMode() has to ensure that ControllerModePtr pointer is valid. (global description available)

\ID SBSW_CAN_HL52
 \DESCRIPTION Write access to ErrorStatePtr pointer within function Can_GetControllerErrorState()
 \COUNTERMEASURE \N caller of Can_GetControllerErrorState() has to ensure that ErrorStatePtr pointer is valid. (global description available)

\ID SBSW_CAN_HL53
 \DESCRIPTION Write access to TxErrorCounterPtr pointer within function Can_GetControllerTxErrorCounter()
 \COUNTERMEASURE \N caller of Can_GetControllerTxErrorCounter() has to ensure that TxErrorCounterPtr pointer is valid. (global description available)

\ID SBSW_CAN_HL54
 \DESCRIPTION Write access to RxErrorCounterPtr pointer within function Can_GetControllerRxErrorCounter()
 \COUNTERMEASURE \N caller of Can_GetControllerRxErrorCounter() has to ensure that RxErrorCounterPtr pointer is valid. (global description available)

\ID SBSW_CAN_HL55
 \DESCRIPTION A ComStackLib generated variable is accessed.
 \COUNTERMEASURE \N The variable is written using a generated macro of the CSL. It immediately dereferences the variables address without pointer arithmetic.


\ID SBSW_CAN_LL__100
 \DESCRIPTION       Accessing the MCAN Registers via the channel specific Base Address and a static (typedef) offset always being valid.
 \COUNTERMEASURE \S The Base Address is assured via  user review (see Safety Manual SMI-64562), the channel is assured via Core/ComStackLib.

\ID SBSW_CAN_LL__101
 \DESCRIPTION       The channel parameter and timer value is used as index for array access.
 \COUNTERMEASURE \R [CM_CAN_HL22]
                 \R [CM_CAN_HL01]

\ID SBSW_CAN_LL__102
 \DESCRIPTION       The channel parameter (assured via the caller software) and timer index (assured via error directive) used for array access.
 \COUNTERMEASURE \R [CM_CAN_LL__102]

\ID SBSW_CAN_LL__103
 \DESCRIPTION       Pointer access to the Message RAM (assured via a runtime check).
 \COUNTERMEASURE \R [CM_CAN_LL__103]

\ID SBSW_CAN_LL__104
 \DESCRIPTION       The dimension values used for the variable access are assured with the loop end condition and the modulo operation (bit operator ampersand).
 \COUNTERMEASURE \R [CM_CAN_LL__104]
                 \R [CM_CAN_LL__105]

\ID SBSW_CAN_LL__106
 \DESCRIPTION       The array access is assured using a constant index.
 \COUNTERMEASURE \N Constant index assures correct access.

\ID SBSW_CAN_LL__107
 \DESCRIPTION       The dimension values used for the variable access are assured with a limited index.
 \COUNTERMEASURE \R [CM_CAN_LL__107]

\ID SBSW_CAN_LL__108
 \DESCRIPTION       Initialization within the address range of the Message RAM (assured via  user review, see Safety Manual), the channel is assured via Core/ComStackLib.
 \COUNTERMEASURE \S Message RAM begin and end address must be verified by the user (see Safety Manual SMI-64561), the number of CAN channels must be verified together with the Base Address (see Safety Manual SMI-64562).

\ID SBSW_CAN_LL__109
 \DESCRIPTION       Write access to Init/Basic/Full structures.
 \COUNTERMEASURE \R [CM_CAN_LL__109]

 \ID SBSW_CAN_LL__110
 \DESCRIPTION       Call Initialization subroutines with initInfo pointer as parameter.
 \COUNTERMEASURE \S The structure is static and has to be assured with a review and thus it is always valid (pointer to a local stack variable even already assured by the caller).

\ID SBSW_CAN_LL__111
 \DESCRIPTION       The channel parameter is provided (assured via a runtime check).
 \COUNTERMEASURE \R [CM_CAN_LL__111]

\ID SBSW_CAN_LL__112
 \DESCRIPTION       The channel parameter is used as index for array access.
 \COUNTERMEASURE \R [CM_CAN_HL01]

\ID SBSW_CAN_LL__113
 \DESCRIPTION       Local variable assignment.
 \COUNTERMEASURE \N The local variable is always available.

\ID SBSW_CAN_LL__114
 \DESCRIPTION       Local array variable assignment.
 \COUNTERMEASURE \N The array index cannot become greater than 16 and 4*16 elements are always available with CAN_FD_FULL.

\ID SBSW_CAN_LL__115
 \DESCRIPTION       Accessing the SICANFD Functional Safety Registers via the channel specific Base Address and a static (defined) offset.
 \COUNTERMEASURE \S The Base Address and offset is assured via  user review (see Safety Manual SMI-153796), the channel is assured via Core/ComStackLib.
 
\ID SBSW_CAN_LL__116
 \DESCRIPTION       Accessing the Traveo2 (TTCANFD) Receive FIFO Top control register via the channel specific Base Address and a static (defined) offset.
 \COUNTERMEASURE \S The Base Address and offset is assured via  user review (see Safety Manual SMI-183990), the channel is assured via Core/ComStackLib.
 
\ID SBSW_CAN_LL__117
 \DESCRIPTION       Accessing the Global CAN registers via subsystem specific base address. The hardware structure is assured by review. The table access is executed using ComStackLib (Qualified use-case CSL01).
 \COUNTERMEASURE \S The Base Address is assured via user review (see Safety Manual SMI-183991).
 
\ID SBSW_CAN_LL__118
 \DESCRIPTION       Assembler instruction is inserted.
 \COUNTERMEASURE \N Always valid because there is no memory access.
 
\ID SBSW_CAN_LL__119
 \DESCRIPTION Write access via pointer to interrupt controller register.
 \COUNTERMEASURE \N In case of SafeBSW 'OS interrupt control' has to be enabled and this code is never active. This is ensured by a MSSV check and compiler error directive.

\ID SBSW_CAN_LL__120
 \DESCRIPTION       Accessing the Global CAN registers via subsystem specific base address. The hardware structure is assured by review.
 \COUNTERMEASURE \S The Base Address is assured via user review (see Safety Manual SMI-224606).

\ID SBSW_CAN_LL__121
 \DESCRIPTION Call a function with pointer to retVal.
 \COUNTERMEASURE \N The pointer has a static type and always references a local variable.
 
\ID SBSW_CAN_LL__122
 \DESCRIPTION Write access via pointer to CanInterruptOldStatus (compiler secures used type in function declaration fitting to given pointer parameter type).
 \COUNTERMEASURE \N This local function is only called with valid pointers.

\ID SBSW_CAN_LL__123
 \DESCRIPTION Read access via pointer to interrupt controller register.
 \COUNTERMEASURE \N In case of SafeBSW 'OS interrupt control' has to be enabled and this code is never active. This is ensured by a MSSV check and compiler error directive.

SBSW_JUSTIFICATION_END */

/* Counter measurement description

\CM CM_CAN_HL01 A runtime check ensures controller index is always smaller than number of elements in arrays with controller amount as dimension (Qualified use-case CSL01 of ComStackLib size of ControllerData).
\CM CM_CAN_HL02 Qualified use-case CSL03 of ComStackLib (CanMailbox.ControllerConfigIdx is always in range of controller ControllerData)
\CM CM_CAN_HL03 A runtime check ensures activeSendObject index is in valid range for Can_ActiveSendObject table (Qualified use-case CSL01 of ComStackLib - Can_ActiveSendObject size is extended by CAN_MULTIPLEXED_TX_MAX within generator to allow an access to logObjHandle+CAN_MULTIPLEXED_TX_MAX).
\CM CM_CAN_HL17 A runtime check ensures DLC index is always smaller than the dimension of CanRxQueueBuffer.data.
\CM CM_CAN_HL18 A runtime check ensures HRH values is always in range of start stop index of the given mailbox type. (Qualified use-case CSL03 of ComStackLib - start-stop index fit to mailbox entrys)
\CM CM_CAN_HL20 A runtime check ensures size of ActiveSendData (dataByte). For CAN-FD it is checked against the size of the table. For none CAN-FD size is checked against 8 as defined.
\CM CM_CAN_HL22 A runtime check ensures source index for LoopTimeout array is always smaller than the dimension of LoopTimeout.
\CM CM_CAN_HL24 A runtime check ensures RxQueue write index is always smaller than the dimension of RxQueue (Qualified use-case CSL01 of ComStackLib).
\CM CM_CAN_HL25 A runtime check ensures RxQueue read index is always smaller than the dimension of RxQueue (Qualified use-case CSL01 of ComStackLib).
\CM CM_CAN_HL28 A runtime check ensures htrh index is always smaller than the dimension of CanMailboxState (Qualified use-case CSL01 of ComStackLib).
\CM CM_CAN_HL29 Qualified use-case CSL02 of ComStackLib (size of CanMailboxState == size of CanMailbox) 
\CM CM_CAN_HL30 Qualified use-case CSL03 of ComStackLib (CanMailbox - CanController Start/Stop HtrhIndex).
\CM CM_CAN_HL31 valid mailbox data area is assigned to rxStruct.pChipData pointer (Has to be given by LL implementation part).
\CM CM_CAN_HL32 A runtime check ensures TxHwFifo index is always smaller than the dimension of TxHwFifo (Qualified use-case CSL01 of ComStackLib).


\CM CM_CAN_LL__102 A runtime DET check ensures controller index is always smaller than the number of elements in arrays using controller amount as dimension (Qualified use-case CSL01 of ComStackLib size of ControllerData).
\CM CM_CAN_LL__103 A runtime DET check ensures pointer access is always in the correct memory area.
\CM CM_CAN_LL__104 Using the bit operator "&" assures the maximum length of the index to guarantee that the dimension is sufficient.
\CM CM_CAN_LL__105 The loop end condition guarantees that the dimension is sufficient.
\CM CM_CAN_LL__107 The limited index ('0' or '1') guarantees that the dimension is sufficient.
\CM CM_CAN_LL__109 The static structure(element) address is assured via a fix typedef and thus always valid.
\CM CM_CAN_LL__111 A runtime DET check ensures that the channel parameter is always in the correct range.


*/

/****************************************************************************/
/*  Coverage Justification                                                  */
/****************************************************************************/
/* START_COVERAGE_JUSTIFICATION

\ID COV_CAN_COMPATIBILITY
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT TX xf xf
  \ACCEPT XF tf tf
  \REASON The condition checks whether a switch is defined and conditionally assigns a default value. This is used to ensure compatibility to older AUTOSAR/Component versions. 

\ID COV_CAN_INTERNAL
  \ACCEPT XF
  \ACCEPT TX
  \REASON This switch is always active within CAN driver context. Secure visibility of internal interface and cannot be stimulated to off while test. The code is verified by code inspection.

\ID COV_CAN_CANCEL_SW_STIMULATION
  \ACCEPT TF
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XX
  \ACCEPT TF tf xf
  \REASON It is not possible to stimulate a sw cancellation while the message is already start to send when hw cancellation is active. The code is verified by code inspection.

\ID COV_CAN_AMD_RUNTIME_MEASUREMENT
  \ACCEPT XF
  \REASON The feature AMD Runtime Measurement is not supported for SafeBSW. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_FINALMAGICNUMBER
  \ACCEPT TX
  \REASON Switch is always true is OK here no side effect will occur when switch is false verified by review.

\ID COV_CAN_SAFE_BSW_EXCLUSION
  \ACCEPT XF xf xf
  \REASON SafeBsw restricted feature will not be enforced to be deactivated or activated.

\ID COV_CAN_BUSOFF_NOT_IN_ALL_CONFIG
  \ACCEPT X
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT TF tf tx
  \ACCEPT TX tx tx
  \REASON BUSOFF not stimulated in each configruation. The behavior does not depend on each configuration variant but TCASE-274 takes long runtime and will not be executed for each configuration.   

\ID COV_CAN_WAKEUP_CHANNEL_NOT_IN_ALL_CONFIG
  \ACCEPT XF
  \ACCEPT TX
  \REASON Wakeup may be always activated or deactivated depend on configuration. Not all configurations contain activated or deactivated wakeup for at least one controller, but is sufficiantly tested in some configuations with both settings.

\ID COV_IMPLICITE_TXCANCEL
  \ACCEPT TX
  \REASON In some configurations there will be no recancellation but for this case there is no active code (empty else), so this is not really a test case.

---------------- LL ------------------

\ID COV_CAN_MISRA
  \ACCEPT XF
  \ACCEPT TX
  \REASON only used for MISRA analysis not active in production code.

\ID COV_CAN_MICROSAR_VERSION
  \ACCEPT XF
  \ACCEPT TX
  \REASON The feature is supported different for MicroSar4 and MicroSar3.  The code is verified by code inspection.

\ID COV_CAN_MULTI_ECU_CONFIG
  \ACCEPT XF
  \REASON The feature is supported different for MicroSar4 and MicroSar3.  The code is verified by code inspection.

\ID COV_CAN_GEN_HW_START_STOP_IDX
  \ACCEPT TX
  \REASON The feature GEN_HW_START_STOP is always supported for SafeBSW but may be not used in MSR3. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_PARTIAL_NETWORK
  \ACCEPT XF
  \REASON The feature Partial Network is not supported for SafeBSW but be used in MSR3. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_MULTIPLE_BASICCAN_TX
  \ACCEPT TF
  \ACCEPT TF tf tf
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_SLEEP_SUPPORT
  \ACCEPT XF
  \REASON The feature is platform specific - always IN-active.

\ID COV_CAN_WAKEUP_SUPPORT
  \ACCEPT XF
  \REASON The feature is platform specific - always IN-active.

\ID COV_CAN_EMULATE_SLEEP
  \ACCEPT TX
  \ACCEPT TX tf tx
  \ACCEPT TX tx tx
  \ACCEPT TX xf tx
  \ACCEPT XF
  \REASON The feature Emulated Sleep is always supported for SafeBSW but used in MSR3. A MSSV plugin enforces this configuration for SafeBSW.

\ID COV_CAN_TX_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_BASICCAN_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_FULLCAN_POLLING
  \ACCEPT TF
  \REASON The feature configuration specific - fully supported.

\ID COV_CAN_ERROR_POLLING
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_WAKEUP_POLLING
  \ACCEPT XF
  \REASON The feature is platform specific - fully NOT supported.

\ID COV_CAN_INDIVIDUAL_POLLING
  \ACCEPT TF
  \REASON The feature is platform and Project specific.

\ID COV_CAN_TX_POLLING_OR_CANCEL_IN_HW_TASK
  \ACCEPT TF tf tf tx
  \ACCEPT TF tf tf xf
  \REASON The feature is platform specific - C_HL_ENABLE_CANCEL_IN_HW_TASK is always true or false.

\ID COV_CAN_GENERIC_CONFIRMATION_API2
  \ACCEPT TF
  \REASON The feature is platform and Project specific - fully supported.

\ID COV_CAN_FD_SUPPORT
  \ACCEPT TF
  \REASON The feature is platform and Project specific - fully supported.

\ID COV_CAN_MULTIPLE_BASICCAN
  \ACCEPT TF
  \REASON The feature is platform and Project specific - fully supported.

\ID COV_CAN_TX_FULLCAN_OBJECTS
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_FULLCAN_OBJECTS
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_HW_TRANSMIT_CANCELLATION
  \ACCEPT XF
  \REASON The feature is platform specific - fully NOT supported.

\ID COV_CAN_CANCEL_IN_HW
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT TF xf tf
  \ACCEPT XF xf tf
  \ACCEPT XF xf xf
  \ACCEPT TF tf xf
  \REASON The feature is platform specific - (temporarily) not supported.

\ID COV_CAN_HARDWARE_CANCELLATION
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_EXTENDED_ID
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_MIXED_ID
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_OVERRUN_NOTIFICATION
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_MULTIPLEXED_TRANSMISSION
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RX_QUEUE
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_TX_HW_FIFO
  \ACCEPT XF
  \REASON The feature is platform specific - fully NOT supported.

\ID COV_CAN_TXINDIRECTIONHWTOLOG
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_HW_LAYOUT_TXBASIC_FIRST
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_TX_FULLCAN_HWHANDLE_REVERSE
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_RX_FULLCAN_HWHANDLE_REVERSE
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_BASICCAN_HWHANDLE_REVERSE
  \ACCEPT XF
  \REASON The feature is platform specific - always deactivated.

\ID COV_CAN_EXTENDED_STATUS
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_OVERRUN_IN_STATUS
  \ACCEPT TX
  \REASON The feature is platform specific - always activated.

\ID COV_CAN_RxBasicMsgReceivedBegin
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_RxFullMsgReceivedBegin
  \ACCEPT TX
  \REASON The feature is platform specific - always active.

\ID COV_CAN_HW_EXIT_TRANSMIT
  \ACCEPT TX
  \REASON The feature is platform specific - always active.


\ID COV_CAN_LL_HARDWARE_BEHAVIOUR
  \ACCEPT TX
  \ACCEPT XF xf xx
  \ACCEPT XX xx xx
  \ACCEPT XX xx xx xx
  \ACCEPT XF xf xx xx
  \ACCEPT XF tf xf xf
  \ACCEPT XF tf xf
  \REASON The condition checks for hardware failures that cannot be stimulated. The code is verified by code inspection.


\ID COV_CAN_HARDWARE_FAILURE
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XF tf xf
  \ACCEPT XF xf xf
  \ACCEPT XF tx xf
  \ACCEPT XF xf xx
  \ACCEPT XF xf xx xx
  \ACCEPT XF xf xf xf xf
  \ACCEPT XF tx tx tx tx
  \ACCEPT XF tf xf xf
  \ACCEPT TF tf xf
  \ACCEPT TF tf tx
  \ACCEPT TF tf tx tx
  \ACCEPT XF xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf
  \ACCEPT XF xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf xf
  \REASON The condition checks for hardware failures that cannot be stimulated. The code is verified by code inspection.

\ID COV_CAN_GENDATA_FAILURE
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XX
  \ACCEPT XF xf xf
  \ACCEPT XF tx tx
  \ACCEPT XF tx tx tx tx 
  \ACCEPT TF tf xf
  \ACCEPT TF xf tf
  \ACCEPT TF xf tf xf tf
  \REASON The condition checks for generated data failures that cannot be simulated. The code is verified by code inspection.

\ID COV_CAN_GENDATA_NOT_IN_ALL_CONFIG
  \ACCEPT X
  \ACCEPT TX
  \ACCEPT TF
  \ACCEPT XF
  \ACCEPT XF xf xf
  \ACCEPT XF xf xx
  \ACCEPT TF tf tx
  \ACCEPT TF tf xf
  \ACCEPT TF tf tf xf xf
  \ACCEPT XF xf xx xf xf
  \ACCEPT XF xf xx xx xx
  \REASON Generated data does not contain all data sets but checked in code. Not encapsulated with preprocessor switch to simplify code.

\ID COV_CAN_OS_USAGE
  \ACCEPT TX
  \ACCEPT TX xf tx
  \ACCEPT TX tx xf
  \ACCEPT XF
  \ACCEPT XF xf tx
  \ACCEPT XF tx xf
  \ACCEPT XF tf tf
  \ACCEPT XF xf tf
  \ACCEPT TF tx tf
  \ACCEPT TF xf xf
  \REASON not all OS types used in component test. The code is verified by code inspection.

\ID COV_CAN_LOCK_ISR_BY_APPL
  \ACCEPT TX tf tf
  \ACCEPT TF xf tf 
  \REASON CAN interrupts never locked by application only within tests. It is not part of the component test to check application code. The code is verified by code inspection.

\ID COV_CAN_RAM_CHECK
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_RAM_CHECK_EXTENDED
  \ACCEPT XF
  \REASON The feature is platform specific - fully NOT supported.

\ID COV_CAN_TIMEOUT_DURATION
  \ACCEPT TF
  \REASON Hardware loop time out is platform specific never reached.

\ID COV_CAN_TRANSITION_REQUEST
  \ACCEPT TF
  \ACCEPT TF tf tf
  \ACCEPT X
  \ACCEPT XX
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT TX tx tx
  \REASON Mode transition is platform specific always true or false.

\ID COV_CAN_TRANSITION_PROCESSED
  \ACCEPT TF
  \ACCEPT TX
  \ACCEPT XF
  \REASON StartProcessed are only called in the case where the asynchronous mode change did go to normal mode when requested. This is timing dependent and depends on the configured baud rate. The code is verified by code inspection. 

\ID COV_CAN_TRANSITION_REQUEST_WAKEUP
  \ACCEPT TF
  \ACCEPT TF tf tf
  \REASON Mode transition is platform specific always true or false.

\ID COV_CAN_TRANSITION_REQUEST_SLEEP
  \ACCEPT TF
  \ACCEPT TF tf tf
  \REASON Mode transition is platform specific always true or false.

\ID COV_CAN_BASICCAN_SEARCH_LINEAR
  \ACCEPT TX
  \ACCEPT TF tx tf
  \REASON Received BasicCAN mailbox is always a valid object and found while search.

\ID COV_CAN_FULLCAN_SEARCH_LINEAR
  \ACCEPT TX
  \ACCEPT TF tx tf
  \REASON Received FullCAN mailbox is always a valid object and found while search.

\ID COV_CAN_RAM_CHECK_NO_STIMULATION
  \ACCEPT X
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \REASON some configurations do not stimulate RamCheck by test suite, to check the standard CAN driver behaviour.

\ID COV_CAN_HWOBJINDIVPOLLING
  \ACCEPT TF
  \ACCEPT TX
  \ACCEPT XF
  \REASON Not all configurations stimulate this (e.g. Individual polling is set but all objects are polled). 
 
\ID COV_CAN_SAFE_BSW
  \ACCEPT TF
  \REASON The feature is platform specific - fully supported.

\ID COV_CAN_OSCAT_CONFIG_CHECK
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XF tx xf
  \ACCEPT XF xf xf
  \REASON The 'osdISrCan_xx' define is only available in case OSEK OS is used. Only used to verify correct configuration and does not influence the runtime code.

\ID COV_CAN_MCAN_SAFETY_CHECK
  \ACCEPT TX
  \REASON The condition checks for unexpected behaviour that cannot be stimulated. The code is verified by code inspection.

\ID COV_CAN_MCAN_NOT_SUPPORTED
  \ACCEPT XF tx xf xx
  \ACCEPT XF
  \REASON The condition checks for unexpected behaviour that cannot be stimulated. The code is verified by code inspection.

\ID COV_CAN_VERSION_CHECK
  \ACCEPT TX
  \REASON Only allowed resp. requested for a specific MCAN Revision 
  
\ID COV_CAN_HW_SPECIFIC
  \ACCEPT XX
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT TF
  \ACCEPT XF xf xf xf xf
  \ACCEPT XF xf xx xf xf
  \ACCEPT TF tf tf xf xf
  \ACCEPT XF xf xf
  \ACCEPT XF xf xx
  \ACCEPT XF tx 
  \ACCEPT XF xf xx xf
  \ACCEPT TF xf tf
  \ACCEPT TF tx tf
  \ACCEPT TF tf tx
  \ACCEPT TX tx tx
  \ACCEPT TX xf
  \ACCEPT TF tf tf xf
  \ACCEPT TF tx tf xf 
  \ACCEPT TX tx xf xf
  \ACCEPT TF tx tf xf xf
  \REASON The condition checks for revision/hardware specific defines which do not change. The code is verified by code inspection.

\ID COV_CAN_HW_SPECIFIC_FUNCTIONALITY
  \ACCEPT TF
  \ACCEPT XF
  \ACCEPT TX xf xf tx
  \ACCEPT XF xf xf xf xf
  \ACCEPT TX xf tx
  \ACCEPT TX tx xf xf
  \ACCEPT TX xf xf xf tx
  \REASON The condition checks for hardware specific functionality which do not change. The code is verified by code inspection.
  
\ID COV_CAN_OS_INT_CONTROL
  \ACCEPT TF
  \ACCEPT XF
  \REASON The condition checks for hardware specific functionality which do not change. The code is verified by code inspection.

\ID COV_CAN_OS_INT_SOURCE
  \ACCEPT TX
  \ACCEPT XF
  \REASON The condition checks if the interrupts should be restored. This depends on if the configuration uses interrupts or not. The code is verified by code inspection.

\ID COV_CAN_NOT_IN_ALL_CFG_AND_HW_SPECIFIC
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \ACCEPT TX tx tx
  \ACCEPT XF xf xx
  \ACCEPT X
  \REASON The condition checks as well for timing as also for revision/hardware specific defines which do not change. The code is verified by code inspection.

\ID COV_CAN_GENDATA_TX_NOT_IN_ALL_CONFIG
  \ACCEPT TF tf tx tf
  \ACCEPT TF tx tf tf
  \ACCEPT TF tx tf tx
  \ACCEPT TF tf tx
  \ACCEPT TF tx tf
  \ACCEPT TF tf tf tx tf
  \ACCEPT TF tf tf tx tx tf
  \ACCEPT TF tx tf tx tf
  \ACCEPT TF tf tx tx
  \ACCEPT TF tf tx tx tf
  \ACCEPT TF tf tf tx
  \REASON No BasicCAN  The code is verified by code inspection.

\ID COV_CAN_DISABLE_RX_MAILBOX
  \ACCEPT TF tf xf tx
  \ACCEPT TF tf xf tf
  \ACCEPT TF tx xx tf
  \ACCEPT TF xf tf tx
  \ACCEPT TX tx xx tx
  \ACCEPT TX tx xx
  \ACCEPT TF tf xf
  \ACCEPT TF xf tf
  \ACCEPT XF tf xf
  \ACCEPT XF xf xx
  \ACCEPT XX xx xx
  \REASON The condition checks whether the filter belongs to the corrupt mailbox. This depends on the mailbox configuration. The code is verified by code inspection.

\ID COV_CAN_INTERRUPT
  \ACCEPT TX
  \REASON The condition checks whether an interrupt has occured AND that the interrupt is enabled in HW. The condition occurs in interrupt context. The code is verified by code inspection.

\ID COV_CAN_TX_INTERRUPT
  \ACCEPT TX
  \ACCEPT XF
  \REASON The condition checks whether an TX interrupt has occured AND that the interrupt is enabled in HW. The condition occurs in  TX interrupt and should therefore not be false when tx interrupt is enabled. "XF" acceptance is due to "IndivPollALL" configurations, where interrupts are enabled but no TX interrupt is expected. The deviation is correct and is verified by code inspection.

\ID COV_CAN_ISR_PROTOTYPE
  \ACCEPT TX xf xf
  \REASON The condition checks whether the ISR prototype is disabled by user config and is used to reassure that the ISR prototype is enabled if not explicitly disabled. Deviations are correct and assured with code inspection.

\ID COV_CAN_BUSOFFNOTIFICATION
  \ACCEPT XF
\REASON The condition checks if a bus-off notification is already sent to the application. This is timing depended and related to unexpected behavior, therefore, it cannot be stimulated. The code is verified by code inspection.

\ID COV_CAN_CHANNEL_USED
  \ACCEPT TX
  \ACCEPT XF
  \REASON The test is executed with a defined channels. Due to variant handling, a channel can be defined, however, not used. The code is verified by code inspection.
  
\ID COV_CAN_CBD_COMPATIBILITY
  \ACCEPT TX tf tf
  \REASON The condition checks whether interrupt or polling handling is requested. This is used to ensure compatibility to CANbedded. 

\ID COV_CAN_ERRATUM_OFF
  \ACCEPT XX
  \ACCEPT XF
  \ACCEPT TX
  \REASON Specific Errata only used for specific MCAN Revisions. If the Revision is not under test then the erratum is always inactive.
  
\ID COV_CAN_CPUTYPE
  \ACCEPT XF
  \ACCEPT TX
  \REASON Feature depends on the platform specific invariant endianness

\ID COV_CAN_EQUAL_CHANNEL_LAYOUT
  \ACCEPT TX
  \ACCEPT XF
  \ACCEPT XF tx tf xf xf xf xf 
  \ACCEPT TX tx xf xf xf
  \ACCEPT TF tf xf xf xf
  \ACCEPT XF xf xf xf xf
  \REASON The test is executed on defined channels. The channel layout is equal for each channel.

\ID COV_CAN_DEFINED_CHANNELS
  \ACCEPT XF tx tf xf xf xf xf 
  \REASON The tests are extecuted on specific channels and does not cover all available channels in the hardware. The code is verified by code inspection.

\ID COV_CAN_DERIVATIVE_SWITCH
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \REASON Only one derivative can be tested for one time. To check supported derivatives, please look for the "Equivalent Hardware Checklist"

\ID COV_CAN_COMPILER_SWITCH
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \ACCEPT TX tx xf
  \ACCEPT TX xf tx
  \REASON Only one compiler can be tested for one time.

\ID COV_CAN_GENTOOL_SPECIFIC
  \ACCEPT XF
  \ACCEPT TX
  \ACCEPT XF xf xf
  \ACCEPT XF xf xx
  \ACCEPT TF xf tf
  \ACCEPT TX tx tx
  \ACCEPT  TX tx xf xf
  \REASON Feature is only relevant for a specific generation tool (e.g. GENy, CFG5, ...)

\ID COV_CAN_SICANFD_KEY_FAILURE
  \ACCEPT TX
  \REASON The condition checks if static key described in HW manual for SICANFD is accepted. Failure cannot be stimulated. The code is verified by code inspection.
  
\ID COV_CAN_PENDING_TX_REQUEST
  \ACCEPT XF
  \REASON The condition checks if there are any pending TX requests when Stop mode is called. Test of functionality is performed with debugger. The code is verified by code inspection.

\ID COV_CAN_SAFE_BSW_EXCLUSION_LL
  \ACCEPT XF xf
  \REASON SafeBsw restricted feature will not be enforced to be deactivated or activated.

END_COVERAGE_JUSTIFICATION */ 


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

