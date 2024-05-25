/* Kernbauer Version: 1.16 Konfiguration: DrvCan_TricoreMcanAsr Erzeugungsgangnummer: 608 */

/*        STARTSINGLE_OF_MULTIPLE_COMMENT      */

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
/*  \file     Can.h
 *  \brief    Interface header file of the CAN-Driver
 *  \details  Declaration of functions, variables, and constants as user API.
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
| 2019-03-14 5.00.00  Her - STORYC-7220  : from CBD/RI2.0 to AR/R21,22 adaptation
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

/*****************************************************************************
|-----------------------------------------------------------------------------
|               A U T H O R   I D E N T I T Y
|-----------------------------------------------------------------------------
| Initials     Name                      Company
| --------     ---------------------     -------------------------------------
| Bir          Holger Birke              Vector Informatik GmbH
| Wr           Hans Waaser               Vector Informatik GmbH
| Ces          Senol Cendere             Vector Informatik GmbH
| Pl           Georg Pfluegel            Vector Informatik GmbH
| Tvi          Timo Vanoni               Vector Informatik GmbH
|-----------------------------------------------------------------------------
|       C O R E    R E V I S I O N   H I S T O R Y
|-----------------------------------------------------------------------------
| Date       Ver  Author  Description
| ---------  ---  ------  ----------------------------------------------------
| 2005-09-15 0.01.00 Bir  - Creation
| 2005-11-17 1.00.00 Bir  - Finish CANoe, M32C
|                         - Change include structure and naming
| 2005-11-23 1.01.00 Bir  - some minor changes
| 2005-12-01 1.02.00 Bir  - Global Interrupt handling via OSEK supported
| 2006-01-19 1.03.00 Bir  - Wrong handle found and DET occur in CanHL_FullCanMsgReceived
|                         - C_DISABLE_RESET_CAN_BUSOFF set (baud rate out of CANoe)
| 2006-03-16 1.04.00 Wr   - Added channel compatibility defines
|                         - Removed local parameter canHwChannels
|                         - Changed order of CanLL_TransmitLocalParameter
|                           and CanLL_TxTransmissionLocalParameter in Can_Write()
|                         - Rename CanWakeup() to CanHL_WakeupHandling()
|                         - Added support for NEC V850 aFCAN
|                         - Added CanLL_GeneratedStructureH for platform C_COMP_GHS_V85X  
|                         - Added general return value defines
|                         - Defined APPL_CAN_WAKEUP() to CanHL_WakeUpHandling()
|                         - Mapping of CanWakeUp() to Can_SetControllerMode(Controller, CAN_T_WAKEUP)
| 2006-04-19 1.05.00 Wr   - Added V850 specific handling for transition to SLEEP
|                         - Add switches to enable OSEK ISR handling for platform C_COMP_GHS_V85X
| 2006-05-22 2.00.00 Bir  - Support for AutoSar 2.0
|                         - Can.h and can_types.h connected
|                         - Include structure update
|                         - DET - switch change
|                         - API changes Can_Init(), Can_Write()
|                         - add Can_GetVersionInfo()
| 2006-06-06 2.01.00 Bir  - internal naming corrections for version defines
|                         - API for Det_ReportError changed (add parameter)
| 2006-06-12 2.02.00 Bir  - CaninitObject calculation changed
|                         - TriCore update for Interrupt priority defines
| 2006-06-12 2.03.00 Bir  - SetControllerMode return OK for unsupported STOP/START or SLEEP/WAKEUP
|                         - CaninitObject calculation changed
| 2006-06-12 2.04.00 Bir  - kCanNotSupported defined to 0x02 to avoid CAN_NOT_OK for that case
|                         - define for MEMORY_ROM (compatibility)
| 2006-07-05 2.05.00 Bir  - Can_HwHandleType as uint8
|                         - Review rework
| 2006-07-10 2.06.00 Bir  - Can_Write try/send also in case busy
| 2006-08-15 2.07.00 Bir  - mapping of CanSingleGlobalInterruptX changed
| 2006-09-04 2.08.00 Bir  - minor change in Can.h: ControllerName length expand to 20
| 2006-09-04 2.09.00 Bir  - minor change for MISRA compliance
|                         - add canStatus for initialization info
|                         - minor changes for MAC71xx
|                         - No interrupt lock inside "CanHL_BasicCanMsgReceived"
|                         - Add FullCAN TX
|                         - Add TX Polling
|                         - Add Hardware Loop and DEM call
|                         - DET call for initialized call of Can_Init()
|                         - Add Can_InitMemory function
| 2006-11-06 2.10.00 Bir  - review rework
| 2006-11-08 2.11.00 Ces/Bir - Add Platform Mcs12x
|                         - Add local variable Controller in function Can_InitMemory()
|                         - Add define C_ENABLE_COPY_TX_DATA in header
| 2006-11-09 2.12.00 Bir  - Prepare for Post-build structure (ORGANI switch "C_HL_ENABLE_ASR_POSTBUILD_STRUCT" added)
| 2006-11-11 2.13.00 Pl   - Add Platform TMS470_DCAN
|                    Bir  - Move FullCAN Overrun notification token behind FullCAN Begin token
| 2006-11-15 2.14.00 Bir  - Post-build changes
|                         - Review changes
|                         - change CAN_HL_TX_OFFSET_HW_TO_LOG and logTxObjHandle value
|                         - ESCAN00018785: Send out of confirmation (TX Queue)
|                         - ESCAN00018915: Change multiple-include define
| 2007-01-15 2.15.00 Bir  - ESCAN00018896: wrong call to Dem_SetEventStatus
|                         - deactivate "CanOverrunNotification" due to no more need since ASR2.0
|                         - Support "Can_MainFunction_BusOff"
|                         - call Can_InitController in case of change mode from BUSOFF to START
|                         - Add SchM_Enter_Can_), SchM_Exit_Can_) / interrupt mapping over VStdLib or SchM
|                         - Change Version Scan Information
|                         - Remove V850 specific parts (shift to LL)
|                         - Remove Re-initialize DET report out of Can_InitController()
| 2007-02-20 2.16.00 Bir  - minor improvements
|                         - ESCAN00019720: WAKEUP does not appear after set SLEEP mode
| 2007-03-09 2.20.00 Bir  - ESCAN00019889: Update to ASR2.1
|                         - ESCAN00019889: change calculation of CAN_HL_TX_OFFSET_HW_TO_LOG (because multiplexed TX)
|                         - remove FullCAN switches to secure Post-build functionality without compile with FullCANs
|                         - ESCAN00020129: Compiler error: identifier "i" is undefined
|                         - Reduce BasicCAN logical mailbox to real BasicCAN (DLC_FIFO include size of Basic CAN)
|                         - Reduce Unused mailboxes logical mailbox to amount of sections (DLC_FIFO include size)
|                         - Move all version defines from Proto.h to Can.h (license scanning)
|                         - Add CAN_AR_*_VERSION
|                         - remove PduId out of mailbox (old from CANIf)
|                         - set "C_ENABLE_OSEK_OS_INTCAT2" if not defined "C_ENABLE_INT_OSCAT1"
|                         - set DLC also for FullCAN TX objects
|                         - generated Tables: CanActiveSendPdu,CanActiveSendState (size matter at link time)
|                         - return not OK for try to set SLEEP mode but failed in HW
|                         - move multichannel API define to Can.h
|                         - set "C_ENABLE_OSEK_OS_INTCAT2" if not defined "C_ENABLE_INT_OSCAT1"
|                         - do "CanLL_InitPowerOn" before "CanLL_InitPowerOnChannelSpecific"
|                         - move OSEK-switches out of irq.c
|                         - add CanLL_InitMemoryPowerOn token for special ll initialization
| 2007-08-28 2.21.00 Bir  - ESCAN00022112: RX Basic CAN used with wrong stop index
|                         - renaming "CaninitObject" to "Can_Init_CtrlIdx" (no runtime effect)
|                         - ESCAN00022168: Driver does not enter STOP mode for Sleep request (when SLEEP is not sup.)
|                         - ESCAN00022232: Add STOP-mode compatibility for FNOS-RP migration
|                         - ESCAN00022262: CanResetBusOffEnd() used with only one parameter
|                         - Add new Token "CanLL_RxFull_SearchHandle" for special HW-support (XGate)
|                         - ESCAN00022390: HW start-stop-index changed to RAM-table
| 2007-10-15 2.22.00 Bir  - ESCAN00022773: use of #ifndef instead of #if !defined
|                         - ESCAN00022774: improve runtime while change mode (STOP to SLEEP)
|                         - ESCAN00023040: minor improvements (add SPEC-1721, SPEC-1767, SPEC-1784, SPEC-1780, SPEC-1781)
|                         - ESCAN00023040: remove Interrupt locking in Can_Write() due to CanIf do this
|                         - ESCAN00023038: Multiple ECU
|                         - ESCAN00023047: Add version check
|                         - ESCAN00023049: change API of Can_Init() to one parameter, Add constant in Can_InitController() + Add Can_InitStruct API
|                         - ESCAN00023127: compiler warnings due to dummy assignments (used to satisfy other compilers)
|                         - ESCAN00023265: remove brackets around Can_EnterCritical
|                         - QAC / MISRA reworks
|                         - Add memory qualifiers
|                         - add v_def.h include (remove define of V_MEM..)
|                         - Review reworks
| 2007-12-14 2.23.00 Bir  - ESCAN00023442: Add extended Id support
|                         - some small changes for cancellation (cancel only less priority objects - more efficient)
|                         - protect Can_MainFunction_Read against re-entrant (ASR specification)
|                         - ESCAN00024354: Ignore API call with controller deactivated by identity
|                         - review rework
| 2008-02-06 3.00.00 Bir  - ESCAN00024406: ASR3.0
| 2008-03-25 3.01.00 Bir  - Add dummy assignment in "ResetBusOffEnd" avoid compiler warnings
|                         - ESCAN00025672: review reworks
|                         - ESCAN00025664: Message send with wrong ID type
|                         - ESCAN00026087: Case sensitive naming for all File names (and includes)
|                         - ESCAN00026186: Extension for MSR3.0 Link-time checks
|                         - ESCAN00025957: No access on "DEM-events" via DEM created and exported constant values
|                         - Move compatibility section (switches needed earlier)
| 2008-05-14 3.02.00 Bir  - ESCAN00026859: V_MEMRAM0 not allowed for type cast
|                         - ESCAN00026861: Token external declaration added
|                         - ESCAN00026990: Add LL-Token to reject Remote frames
|                         - (see ES_CAN00029839) Change naming: "INTERRUPT" and "POLLING" add prefix "CAN_*"
|                         - (see ES_CAN00029826) Remove include of v_cfg.h and v_def.h (will be generated)
|                         - ESCAN00030521: Linker error because of missing Interrupt service routine
|                         - Move include section to top of file (need before version defines)
| 2008-06-30 3.03.00 Bir  - ESCAN00027986 +(ESCAN00025773): Code optimization (save ROM and runtime)
|                           + Start/StopLoop as macro
|                           + Max Loop counter define move to LL
|                           + Add some FullCAN switches to ORGANI Basic CAN controllers
|                           + Multiple Search for Basic CAN HW object
|                           + CanInterrupt Lock only in nested interrupt case (CAN_NESTED_INTERRUPTS)
|                           + remove some HW-start/stop indexes and there calculation use instead info from mailbox-table
|                         - ESCAN00028069: change controller amount to library capable setting
|                         - ESCAN00026596: Extension for MSR3.0 generator version checks
| 2008-08-19 3.03.01 Bir  - minor review changes
|                         - ESCAN00029385: change naming finishFullCan to finishRxFullCan (CAN-bedded compliance)
| 2008-09-11 3.04.00 Bir  - ESCAN00029942: Generator Version Check failed
| 2008-09-18 3.05.00 Bir  - ESCAN00029830: Add Link-time/Post-build configure CRC check
|                         - ESCAN00029434: rename "INTERRUPT" and "POLLING" switch
| 2008-10-15 3.06.00 Bir  - remove CAN_HL_HW_x_STOPINDEX -> not used in HL and does not work for LL
|                         - ESCAN00029707: change transition from uninitialized->START->STOP to uninitialized->STOP
|                         - ESCAN00029129: Source of HW loop timer is not available to application
|                         - ESCAN00030728: move platform typedefs to Can.h
| 2008-10-28 3.06.01 Bir  - ESCAN00030926: lock interrupts while TX confirmation.
|                         - Add include protection for canproto.h
| 2008-10-28 3.07.00 Bir  - ESCAN00032401: CAN driver stays in an endless loop
|                         - ESCAN00032291: BUSOFF handling took some time with locked interrupts
|                         - ESCAN00032612: Support Individual Polling
|                         - ESCAN00032614: Add new memory qualifier V_MEMROM4_CFG for Post-build data access
| 2009-03-16 3.07.01 Bir  - ESCAN00033874: Add LL-token "CanLL_tCanRxInfoStruct" for structure tCanRxInfoStruct
| 2009-04-03 3.07.02 Bir  - ESCAN00034409: Add PRQA comments for MISRA justification
|                         - ESCAN00034551: Add support for reverse RX Basic CAN polling
|                         - ESCAN00034552: Optimize RX Basic CAN polling loop
|                         - ESCAN00034773: Add cancel TX in Hardware within TX polling task
| 2009-04-20 3.08.00 Bir  - ESCAN00034118: Add compiler abstraction
|                         - ESCAN00034119: Add memory abstraction
|                         - ESCAN00035606: Report DEM as DET "CAN_DEV_TIMEOUT_DETECT"
|                         - (see ES_CAN00035490) Report DEM as DET "CAN_DEV_TIMEOUT_DETECT"
|                         - ESCAN00036041: compiler warning label not referenced
| 2009-07-08 3.09.00 Bir  - ESCAN00034780: Confirmation without critical section
| 2009-07-22 3.09.01 Bir  - ESCAN00036593: compile error (variable declaration after assignment)
| 2009-08-03 3.09.02 Bir  - ESCAN00036822: TX data inconsistency
| 2009-08-24 3.09.03 Bir  - ESCAN00037276: Compiler warning "function declared implicitly"
| 2009-09-15 3.10.00 Bir  - ESCAN00037784: Add Generic Confirmation function
|                         - ESCAN00037789: Add feature RX Queue
|                         - change order of RX-DLC and "CanLL_RxBasicGetCANDataPtr" (support for mailbox in RAM)
|                         - ESCAN00038814: Wrong pointer class for TX data used
| 2010-01-19 3.11.00 Bir  - ESCAN00040258: Use Can_HwHandleType instead of uint8
|                         - ESCAN00040432: Code optimization for 1 controller systems
|                         - ESCAN00040433: Support dynamic FullCAN id
|                         - ESCAN00040234: remove v_cfg.h include (already done in can_cfg.h)
| 2010-03-03 3.11.01 Bir  - small review reworks
|                         - ESCAN00041364: Optimize Runtime of Can_SetControllerMode
|                         - ESCAN00041432: Declaration for ISRs missing in case of Full Polling with Individual Polling
| 2010-03-03 3.12.00 Bir  - ESCAN00041791: Suppress unexpected WAKEUP notification
|                         - ESCAN00041984: Support Common CAN
|                         - ESCAN00041996: Split Critical Sections
|                         - ESCAN00042333: Add Hardware assertion notification to DET
|                         - ESCAN00042459: Support WAKEUP-switch-off (no SLEEP mode - STOP mode instead)
|                         - ESCAN00043085: Compiler warnings due to missing cast
|                         - ESCAN00043224: New API Can_GetStatus()
|                         - ESCAN00043250: Add Application Interrupt lock functions
|                         - canWakeUp() call changed to CAN_WAKEUP() - used for LL
|                         - ESCAN00047602: compiler warning: "comparison between signed and unsigned"
|                         - ESCAN00044114: Stop sending messages after transition to STOP mode (and back to started)
| 2010-11-23 3.13.00 Bir  - ESCAN00043999: Support usage without v_def.h
|                         - ESCAN00044276: Reject unwanted ID types (software Filter)
|                         - ESCAN00045682: Compiler warning: dead assignment to "X" eliminated
|                         - ESCAN00045883: Can_SetControllerMode doesn't return CAN_NOT_OK when called with invalid Transition parameter
|                         - ESCAN00045884: Can_CheckWakeup doesn't raise the CAN_E_UNINIT development error
|                         - ESCAN00046363: Adapt AUTOSAR version check
|                         - rename "canInterruptCounter" to "canCanInterruptCounter" CBD compatibility
|                         - ESCAN00047875: Add support for partial network
|                         - ESCAN00047951: Compile error, if the feature "Optimize for one controller" is used
| 2011-03-11 4.00.00  Bir - ESCAN00043688: Support AUTOSAR 4.0 R1
|                         - ESCAN00043998: Add GenData checker
|                         - ESCAN00044010: Add Notification for Overrun detection
|                         - ESCAN00047111: Support RAM check
|                         - ESCAN00046778: Support Multiple Identity Configuration
| 2011-04-05 4.00.01  Bir - void cast DET call for MSR40 + review reworks (minors)
|                         - ESCAN00049572: RAM-check: communication is not deactivated
|                         - ESCAN00050862: EcuM_CheckWakeup is not called in case of WAKEUP Polling
|                         - ESCAN00051562: Remove the AUTOSAR Release Version Check
|                         - ESCAN00047929: Can_Init() does not initialize CAN controllers - but Can Interface do this
|                         - ESCAN00049613: AR Version is not correct (2.2.0 instead of 2.2.1)
| 2011-06-21 4.01.00  Bir - ESCAN00050960: Provide API for Generic Pretransmit (AR3-1654 )
|                         - ESCAN00051102: Compiler warning: narrowing or signed-to-unsigned type conversion found: int to unsigned char
|                         - ESCAN00052324: Compile error if the feature "Optimize for one controller" and "RX Queue" is used
|                         - ESCAN00054829: Fault tolerant API: Do not throw DET in case of MultipleEcuConfig inactive controller for 'Can_CheckWakeup'
|                         - ESCAN00053648: Wrong Define name used "CAN_DEACTIVATE_COMMUNICATION"
|                         - ESCAN00053270: AR3-1698: Add MISRA justifications in source code for automatic generation of MISRA reports
|                         - ESCAN00053263: AR3-2069: Remove non-SchM code for critical section handling
|                         - ESCAN00054038: Compiler warning: variable "canApiContext" was set but never used
|                         - ESCAN00054813: Add Mirror functionality
| 2011-11-21 4.01.01  Bir - ESCAN00055001: Support Transition HW-Loops for MSR30
|                         - ESCAN00055076: MISRA compliance
| 2011-12-14 4.01.02  Bir - ESCAN00055566: Include of DET with camel case spelling
| 2011-12-15 4.01.03  Bir - ESCAN00055589: SPEC-1761
|                         - ESCAN00056004: Add Code Trace ability to AutoSar SWS
|                         - Add explicit type casts to satisfy COSMIC compilers (MCS12x)
|                         - ESCAN00056185: Change Version Check
| 2012-01-20 4.02.00  Bir - ESCAN00055076: MISRA compliance
|                         - Use !CAN_USE_VECTOR_IF instead of VGEN_GENERATOR_GENY (also support CFG5 in mixed systems)
|                         - ESCAN00057438: AR3-2383: Implement handling of call to Dem_ReportErrorStatus
|                         - ESCAN00057164: WAKEUP while Re-Initialization ASR3.2.1
|                         - ESCAN00054830: Can_SetControllerMode() return failed
| 2012-05-31 4.02.01  Bir - ESCAN00059203: Compiler error: missing variable canHwChannel in Can_CleanUpSendState()
|                         - ESCAN00059265: Compiler error: hardware loop index is not available as define for API
| 2012-06-12 4.03.00  Bir - ESCAN00057437: AR3-2374: Implement Silent BSW
|                         - ESCAN00059412: AR4-135: support MSR 4 R5
|                         - ESCAN00059488: Compiler error: identifier "Can_ConfigDataPtr" is undefined
|                         - ESCAN00060494: Compiler error: SchM_Enter_Can((area)) causes Compiler Error with external SchM Usage
| 2012-09-03 4.03.01  Bir - Improve MISRA compliance
|                         - ESCAN00061352: Endless Loop
| 2012-09-03 4.04.00  Bir - ESCAN00061042: AR3-2378: Implement AMD time measurement support
|                         - ESCAN00060586: AR3-2446: Update Code analysis and change analysis UUIDs (like described in Silent design)
|                         - ESCAN00060554: AR3-2443: Implement Silent Checks in BSW module code
|                         - Add support for FullCAN TX cancellation only
|                         - ESCAN00062679: Add source defines according to MICROSAR template source file
| 2012-12-10 4.04.01  Bir - Rework Silent BSW
| 2013-01-28 4.04.02  Bir - ESCAN00064474: Modify Hook_On (code can be removed by integration ORGANI)
| 2013-02-02 4.05.00  Bir - optimize token StopReinit usage
|                         - move some global compatibility defines from proto.h to Can.h
|                         - ESCAN00063652: RxQueue extension to 16bit size
|                         - ESCAN00064324: AR4-325: Implement Post-Build Loadable
|                         - ESCAN00066278: Incorrect comment description for function Can_CheckWakeup / Can_Cbk_CheckWakeup
| 2013-06-11 4.05.01  Bir - ESCAN00067936: Can_GetStatus wrongly returns CAN_STATUS_INCONSISTENT
|                         - Add QAC deviations for 6010, 6030, 6050, 6080
| 2013-06-12 4.06.00  Tvi/Bir - ESCAN00069107: AR4-397: Implement support for CAN-FD according to ASR4.1.1
|                         - ESCAN00070197: Compiler warning: variable Can_ConfigDataPtr was declared but never referenced
|                         - ESCAN00068900: Compiler warning
|                         - ESCAN00067711: AR4-328 / RTM measurement R8
|                         - ESCAN00070625: Adapt usage of CanResetBusOffEnd
|                         - ESCAN00071048: Support null_ptr data in Can_Write() for DLC==0
|                         - Add DOXYGEN comments to be used by API scanner
|                         - move some global compatibility defines from proto.h to Can.h
| 2013-10-25 4.06.01  Bir - R9 version / some minor MISRA improvements
|                         - ESCAN00073272: Support Can_InitController() failure in LL
|                         - ESCAN00073676: Its not possible to switch off MIRROR mode for reception when using RxQueue
|                         - ESCAN00073516: MIRROR_MODE add CAN interrupt lock around confirmation
| 2014-06-23 4.06.02  Bir - ESCAN00076374: Add TX Request cancellation in case of HW-loop break
| 2014-06-23 4.07.00  Bir - R10 ComStackLibAbtraction
|                         - ESCAN00074371: AR4-457: Support CAN-FD mode 2
| 2014-07-01 5.00.00  Bir - R11
|                         - ESCAN00076631: Post-build selectable (+loadable)
|                         - ESCAN00076498: CAN FD mode2
|                         - ESCAN00076634: Multiple CAN driver support
|                         - ESCAN00078089: RAM Check also for emulated SLEEP
|                         - ESCAN00079232: rename canProto.h to Can_Local.h
| 2014-11-24 5.00.01  Bir - coverage improvements
|                         - ESCAN00079480: support GENy (ComStackLib abstraction)
| 2014-12-14 5.01.00  Bir - ESCAN00079794: CAN-FD configured padding
|                         - ESCAN00080453: mask out FD-Bit in GenericPrecopy
|                         - ESCAN00080757: Limit DLC to 8 for Classic CAN RX-Frames
|                         - Support TxIndirectionHwToLog and LogToHw (platforms that use hwHandles for TX shadow buffers)
|                         - ESCAN00081930: DET error (CAN_INITCTR_ID, CAN_E_PARAM_CONTROLLER) occur
|                         - ESCAN00082533: BasicCAN message cancelled out of hardware but is not configured
| 2015-01-19 5.02.00  Bir - ESCAN00080306: FEAT-427 SafeBSW
|                           ESCAN00081793: FEAT-1275 SafeBSW step2
|                           + Merge API and Core history and move it to Can.h
|                           + add code design comments / rework comments in general
|                           + rework DET and SilentDet handling (SilentDet is now DET, no more MACRO)
|                           + split large functions in INLINE functions to reduce CYC
|                           ESCAN00073798: disable CAN interrupts while polling
|                           ESCAN00082042: API description Appl_GenericPrecopy
|                           ESCAN00082274: FEAT-1379: Optimized copy operation for large data
|                           ESCAN00082688: DET error (CAN_MAINFCT_*_ID, CAN_E_PARAM_CONTROLLER) occur
| 2015-07-30 5.02.01  Bir - remove goto/labels for HL - add it for LL
|                           shift CanLL_DefinesDataTypesStructsUnions from Can.c to Can_Local.h
|                           typedef Can_ControllerConfigPtrType from Can_Cfg.h in case of postbuild
|                           include det.h only for report level not detection (from 5.02.00)
|                           ESCAN00084263, ESCAN00084264: reject illegal DLC
| 2015-11-09 5.02.02  Bir - ESCAN00086345: BasicCAN RX message not received
| 2015-10-27 5.03.00  Bir - ESCAN00085666: Gateway - multiple BasicCAN Tx
|                           Add CanHL_StopReinit, CanHL_RxBasicCanPolling, CanHL_RxFullCanPolling
|                           remove Copyright info from Core use LL Copyright instead
| 2015-12-21 5.03.01  Bir - ESCAN00087253: preprocessor directives error in CanHL_WakeupTransition() or CanHL_SleepTransition()
| 2016-01-15 5.03.02  Bir - ESCAN00087518: Illegal pointer access when driver is not initialized
|                           test coverage improvements / minor MISRA improvements
|                           remove some _COMMEN_T postfixes for ORGANI (HW-layout may be TOOL dependent)
| 2016-01-29 5.04.00  Bir - test coverage improvements / minor MISRA improvements
|                           ESCAN00088335: FEAT-598: Extended RAM Check / SelfDiag
|                           ESCAN00087810: FEAT-1688: SafeBSW Step 4
|                           ESCAN00089399: Compiler error: 0=0 assignment
| 2016-04-14 5.04.01  Bir - review rework from 5.04.00
|                           rework traceability, rework coverage comments
|                           ESCAN00089754: Compile error overrun notification by DET without DET enabled (MSR401 only)
| 2016-06-21 5.05.00  Bir - ESCAN00089632: FEAT-1908: Access to Interrupt Control Register via OS
|                           ESCAN00089592: FEAT-1513: Release of CAN-FD
|                           FEAT-1602: Release of MultiBasicCAN-Tx (Gateway)
| 2016-08-24 5.05.01  Bir - ESCAN00091600: support MultiBasicCanTx with HW size > 1
| 2016-08-25 5.05.02  Bir - minor design improvement because of SafetyCheck
|                           ESCAN00091764: mode transition will be fully synchronous
| 2016-10-13 5.05.03  Bir - Add infix for local data and code (test without static to stimulate internal interfaces)
|                         - some minor COV comment improvements
| 2017-02-17 5.05.04  Bir - ESCAN00094060: Define CAN_H renamed (linux reuse)
|                           add infix to CAN_DUMMY_STATEMENT
|                           add coverage comment for Flexcan2 usage
|                           split in Can_MainFunction_Write -> add CanHL_TxTaskConfirmationHandling and CanHL_TxTaskCancelationHandling
| 2017-02-23 5.05.05  Bir - Minor Improvements relating COV and MISRA deviations
| 2017-03-29 5.06.00  Bir - FEATC-382: remove saturation
|                           ESCAN00094638: MICROSAR3 only: No RAM Check during wakeup or explicite call of Can_RamCheckExecute()
|                           ESCAN00095298: No transmit cancellation when calling Can_CancelTx() / CanIf_TransmitCancellation()
| 2017-05-29 5.07.00  Bir - STORYC-140: support silent mode
|                           STORYC-645: selective MultiplexedTx
| 2017-08-22 5.07.01  Bir - ESCAN00096086: compiler error: undefined Symbol Can_GetMailbox*IdxOfControllerConfig
|                           ESCAN00096369: Can_Write() return CAN_NOT_OK instead of CAN_BUSY in case of BO
|                           ESCAN00096391: Compiler error: function "CanHL_WakeupProcessed" / "CanHL_SleepProcessed" was referenced but not defined
| 2017-09-04 6.00.00  Bir - STORYC-2176: Remove "Tracing" feature
|                           ESCAN00096367: CAN driver does not recover from BusOff and stop communication.
|                           ESCAN00097096: Compiler error calling VStdMemCpy
|                           FEAT: Compiler error calling VStdMemCpy
|                           STORYC-3057 / ESCAN00098096: GenericPrecopy with FD-bit, GenericConfirmation(API2) with Len (instead of DLC) and FD-bit
|                                         ESCAN00098095: GenericConfirmation(API2) with Len instead of DLC
|                           STORYC-3329: MICROSAR3 Core Adaptation
|                           ESCAN00098892: Compiler warning: transitionRequest
| 2018-04-19 6.00.01  Bir - Minor Improvements relating COV
| 2018-04-23 7.00.00  Bir - Support new functional LL interface / support reduced to MSR403 only
|                           STORYC-4934: TxHwFifo
|                           STORYC-4935: TxHwFifo
|                           ESCAN00095187: support CAN_BUSY enum
| 2018-04-23 7.00.01  Bir - R21 final SafeBSW
| 2018-09-24 8.00.00  Bir - R22
|                           reworks because of QAC metrics
|                           ESCAN00094289: Can_CheckWakeup has to return CAN_OK/CAN_NOT_OK (CAN360)
|                           TASK-91350: Review reworks
|                           ESCAN00101151: internal PIA failed
|                           STORYC-6510: Accept longer DLCs
|                           STORYC-6843: support more than 3 Baudrate configurations 
|                           STORYC-7257: BusMirroring - GetControllerMode/State/ErrorCounter
|                           STORYC-6846: MISRA 2012
| 2019-03-27 8.00.01  Bir - minor platform specific QAC findings fixed
|                           CM syntax fixed
|                           STORYC-8102: reduce STPH in CanHL_TxConfirmation
|****************************************************************************/

#if !defined(CAN_API_H)
#define CAN_API_H /* refer to ESCAN00094060 */

/***************************************************************************/
/* Include                                                                 */
/***************************************************************************/
/* \trace SPEC-1408 */
#include "Can_Cfg.h"

#if (CAN_MIRROR_MODE == STD_ON)
# include "CDDMirror.h"
# define C_ENABLE_MIRROR_MODE
#endif

/***************************************************************************/
/* Version                                                                 */
/***************************************************************************/
/* Vector module version */
/* ##V_CFG_MANAGEMENT ##CQProject : DrvCan_MPC5700MCANASR CQComponent : Implementation */
#define DRVCAN_MPC5700MCANASR_VERSION         0x0501u
#define DRVCAN_MPC5700MCANASR_RELEASE_VERSION 0x00u

/* internal Core Version */
#define CAN_COREVERSION           0x0800u
#define CAN_RELEASE_COREVERSION   0x01u

/* AutoSar Version for API */
/* BR:013, BR:014 */
#define CAN_AR_RELEASE_MAJOR_VERSION      4u
#define CAN_AR_RELEASE_MINOR_VERSION      0u
#define CAN_AR_RELEASE_REVISION_VERSION   3u

/* AutoSar module version */
#define CAN_SW_MAJOR_VERSION   ((DRVCAN_MPC5700MCANASR_VERSION & 0xFF00u) >> 8)
#define CAN_SW_MINOR_VERSION   (DRVCAN_MPC5700MCANASR_VERSION & 0x00FFu)
#define CAN_SW_PATCH_VERSION   (DRVCAN_MPC5700MCANASR_RELEASE_VERSION & 0xFFu)

#define CAN_VENDOR_ID   30u
#define CAN_MODULE_ID   80u

/***************************************************************************/
/* Defines and Macros                                                      */
/***************************************************************************/
/* Module Id's */
#define CAN_INIT_ID            0x00u
#define CAN_INITCTR_ID         0x02u
#define CAN_SETCTR_ID          0x03u
#define CAN_DIINT_ID           0x04u
#define CAN_ENINT_ID           0x05u
#define CAN_WRITE_ID           0x06u
#define CAN_VERSION_ID         0x07u
#define CAN_MAINFCT_WRITE_ID   0x01u
#define CAN_MAINFCT_READ_ID    0x08u
#define CAN_MAINFCT_BO_ID      0x09u
#define CAN_MAINFCT_WU_ID      0x0Au
#define CAN_MAINFCT_MODE_ID    0x0Cu
#define CAN_CKWAKEUP_ID        0x0Bu
#define CAN_CHANGE_BR_ID       0x0Du
#define CAN_CHECK_BR_ID        0x0Eu
#define CAN_SET_BR_ID          0x0Fu
#define CAN_GETCTR_STATE_ID    0x11u
#define CAN_GETCTR_MODE_ID     0x12u
#define CAN_GETCTR_RXCNT_ID    0x30u
#define CAN_GETCTR_TXCNT_ID    0x31u

/* Internal Id's */
#define CAN_RXINDI_ID          0x50u
#define CAN_TXCNF_ID           0x51u
#define CAN_CTRWAKEUP_ID       0x52u
#define CAN_CTRBUSOFF_ID       0x53u
#define CAN_HW_ACCESS_ID       0x60u


/* \trace SPEC-1702, SPEC-1401, SPEC-50568, SPEC-1568 */
/* Error Codes */
#define CAN_E_NO_ERROR              (uint8)0x00u
#define CAN_E_PARAM_POINTER         (uint8)0x01u
#define CAN_E_PARAM_HANDLE          (uint8)0x02u
#define CAN_E_PARAM_DLC             (uint8)0x03u
#define CAN_E_PARAM_CONTROLLER      (uint8)0x04u
#define CAN_E_UNINIT                (uint8)0x05u
#define CAN_E_TRANSITION            (uint8)0x06u
#define CAN_E_DATALOST              (uint8)0x07u   /* for MSR30 extension */
#define CAN_E_PARAM_BAUDRATE        (uint8)0x08u   /* MRS403 only */
#define CAN_E_RXQUEUE               (uint8)0x10u   /* extension */
#define CAN_E_TIMEOUT_DET           (uint8)0x11u   /* extension */
#define CAN_E_GENDATA               (uint8)0x12u   /* extension - used by LL to throw standardized issue for inconsistent generated data */

/* Return values Can_GetStatus() */
#define CAN_STATUS_UNINIT           ((uint8)0x00u) /* ASR extension */
#define CAN_STATUS_START            ((uint8)0x01u) /* ASR extension (kCanTxOn) */
#define CAN_STATUS_STOP             ((uint8)0x02u) /* STOP */
#define CAN_STATUS_INIT             ((uint8)0x04u) /* Initialized */
#define CAN_STATUS_INCONSISTENT     ((uint8)0x08u) /* Inconsistent      used for common CAN */
#define CAN_STATUS_WARNING          ((uint8)0x10u) /* WARNING */
#define CAN_STATUS_PASSIVE          ((uint8)0x20u) /* PASSIVE */
#define CAN_STATUS_BUSOFF           ((uint8)0x40u) /* BUSOFF */
#define CAN_STATUS_SLEEP            ((uint8)0x80u) /* SLEEP */
#define CAN_STATUS_MASK_NOMODE      ((uint8)0x0Cu) /* Initialized & Inconsistent/DEACTIVATE */

#if defined(C_DRV_INTERNAL) /* just for internal usage */ /* COV_CAN_INTERNAL */
/* mode transition requests */
# define kCanModeSleep                 ((uint8)0x01u)
/* used by HLL: define kCanModeWakeupStart          ((uint8)0x02u) */
# define kCanModeStopReinitFast        ((uint8)0x03u)
# define kCanModeStopReinit            ((uint8)0x04u)
# define kCanModeStart                 ((uint8)0x05u)
# define kCanModeStartReinit           ((uint8)0x06u)
# define kCanModeWakeupStopReinit      ((uint8)0x07u)
# define kCanModeSilent                ((uint8)0x08u)
# define kCanModeResetBusOffStart      ((uint8)0x09u)
# define kCanModeResetBusOffEnd        ((uint8)0x0Au)
# define kCanModeNone                  ((uint8)0x10u)
/* precondition for mode transition */
# define kCanContinueBusOffRecovery    ((uint8)0x00u)
# define kCanFinishBusOffRecovery      ((uint8)0x01u)
/* re-initialization */
# define kCanExecuteRamCheck           kCanTrue
# define kCanSuppressRamCheck          kCanFalse

#endif

/* Macros to use Can_GetStatus() */
/* PRQA S 3453 FctLikeMacroLabel */ /* MD_MSR_FctLikeMacro */
#define CAN_HW_IS_OK(state)                     (((state) & (CAN_STATUS_WARNING |  \
                                                          CAN_STATUS_PASSIVE |  \
                                                          CAN_STATUS_BUSOFF) )    == 0u)
#define CAN_HW_IS_WARNING(state)                (((state) & CAN_STATUS_WARNING)      != (uint8)0u)
#define CAN_HW_IS_PASSIVE(state)                (((state) & CAN_STATUS_PASSIVE)      != (uint8)0u)
#define CAN_HW_IS_BUSOFF(state)                 (((state) & CAN_STATUS_BUSOFF)       != (uint8)0u)
#define CAN_HW_IS_WAKEUP(state)                 (((state) & CAN_STATUS_SLEEP)        == (uint8)0u)
#define CAN_HW_IS_SLEEP(state)                  (((state) & CAN_STATUS_SLEEP)        != (uint8)0u)
#define CAN_HW_IS_STOP(state)                   (((state) & CAN_STATUS_STOP)         != (uint8)0u)
#define CAN_HW_IS_START(state)                  (((state) & CAN_STATUS_START)        != (uint8)0u)
#define CAN_HW_IS_INCONSISTENT(state)           (((state) & CAN_STATUS_INCONSISTENT) != (uint8)0u)
/* PRQA L:FctLikeMacroLabel */

/* Hardware Loop defines used by LowLevel for documentation (Core use it for loop check) */
#define kCanLoopMode CAN_LOOP_MAX

/* compatibility (LL may need this for check against current status)  */
#define kCanHwIsInit CAN_STATUS_INIT
#define kCanHwIsSleep CAN_STATUS_SLEEP

/* results of CAN RAM check */
#define CAN_DEACTIVATE_CONTROLLER               CAN_STATUS_INCONSISTENT
#define CAN_ACTIVATE_CONTROLLER                 ((uint8)0x00u)

/***************************************************************************/
/* GenTool abstraction                                                     */
/***************************************************************************/

#define C_ENABLE_STOP /* COV_CAN_COMPATIBILITY */
#if defined(V_OSTYPE_OSEK) || defined(V_OSTYPE_AUTOSAR) /* COV_CAN_OS_USAGE */
# define C_ENABLE_OSEK_OS
#endif
#if (CAN_TX_PROCESSING == CAN_POLLING) /* COV_CAN_TX_POLLING */
# define C_ENABLE_TX_POLLING
#endif
#if (CAN_RX_PROCESSING == CAN_POLLING) /* COV_CAN_RX_POLLING */
# define C_ENABLE_RX_BASICCAN_POLLING
# define C_ENABLE_RX_FULLCAN_POLLING
# define C_ENABLE_RX_POLLING
#endif
#if (CAN_BUSOFF_PROCESSING == CAN_POLLING) /* COV_CAN_ERROR_POLLING */
# define C_ENABLE_ERROR_POLLING
#endif
#if (CAN_WAKEUP_PROCESSING == CAN_POLLING) /* COV_CAN_WAKEUP_POLLING */
# define C_ENABLE_WAKEUP_POLLING
#endif
#if (CAN_INDIVIDUAL_PROCESSING == STD_ON) /* COV_CAN_INDIVIDUAL_POLLING */
# define C_ENABLE_INDIVIDUAL_POLLING
#endif
#if (CAN_MULTIPLE_BASICCAN == STD_ON) /* COV_CAN_MULTIPLE_BASICCAN */
# define C_ENABLE_MULTIPLE_BASICCAN
#endif
#if (CAN_MULTIPLE_BASICCAN_TX == STD_ON) /* COV_CAN_MULTIPLE_BASICCAN_TX */
# define C_ENABLE_MULTIPLE_BASICCAN_TX
#endif
#if (CAN_TX_FULLCAN_OBJECTS == STD_ON) /* COV_CAN_TX_FULLCAN_OBJECTS */
# define C_ENABLE_TX_FULLCAN_OBJECTS
#endif
#if (CAN_RX_FULLCAN_OBJECTS == STD_ON) /* COV_CAN_RX_FULLCAN_OBJECTS */
# define C_ENABLE_RX_FULLCAN_OBJECTS
#endif
#if (CAN_RX_BASICCAN_OBJECTS == STD_ON)
# define C_ENABLE_RX_BASICCAN_OBJECTS
#endif
#if (CAN_HW_TRANSMIT_CANCELLATION == STD_ON) /* COV_CAN_HW_TRANSMIT_CANCELLATION */
# define C_ENABLE_CANCEL_IN_HW
#endif
/* C_ENABLE_CANCEL_FULLCAN_IN_HW may be user defined */
#if (CAN_CANCEL_SUPPORT_API == STD_ON)
# define C_ENABLE_CANCEL_SUPPORT_API
#endif
#if (CAN_HARDWARE_CANCELLATION == STD_ON) /* COV_CAN_HARDWARE_CANCELLATION */
#define C_ENABLE_HW_LOOP_TIMER
#endif
#if (CAN_EXTENDED_ID == STD_ON) /* COV_CAN_EXTENDED_ID */
# define C_ENABLE_EXTENDED_ID
#endif
#if (CAN_MIXED_ID == STD_ON) /* COV_CAN_MIXED_ID */
# define C_ENABLE_MIXED_ID
#endif
#if (CAN_SLEEP_SUPPORT == STD_ON) /* COV_CAN_SLEEP_SUPPORT */
# if (CAN_WAKEUP_SUPPORT == STD_ON) /* COV_CAN_WAKEUP_SUPPORT */
/* before version 3.12 this switches occur always synchronous both to ON or OFF (C_ENABLE_WAKEUP no more used) */
/* if CAN_WAKEUP_SUPPORT is switched off, STOP mode will be used instead of SLEEP (see AUTOSAR specification) */
# define C_ENABLE_SLEEP_WAKEUP
# endif
#endif
#if (CAN_OVERRUN_NOTIFICATION == CAN_APPL) /* COV_CAN_OVERRUN_NOTIFICATION */
# define C_ENABLE_OVERRUN
# define C_ENABLE_FULLCAN_OVERRUN
#endif
#if (CAN_OVERRUN_NOTIFICATION == CAN_DET) /* COV_CAN_OVERRUN_NOTIFICATION */
# define C_ENABLE_OVERRUN
# define C_ENABLE_FULLCAN_OVERRUN
# if (CAN_DEV_ERROR_REPORT != STD_ON) /* COV_CAN_COMPATIBILITY */
#  error "CAN_OVERRUN_NOTIFICATION == CAN_DET need CAN_DEV_ERROR_REPORT == STD_ON"
# endif
#endif
#if (CAN_MULTIPLEXED_TRANSMISSION == STD_ON) /* COV_CAN_MULTIPLEXED_TRANSMISSION */
# define C_ENABLE_MULTIPLEXED_TRANSMISSION
#endif
#if (CAN_TX_HW_FIFO == STD_ON) /* COV_CAN_TX_HW_FIFO */
# define C_ENABLE_TX_HW_FIFO
#endif
#if (CAN_RX_QUEUE == STD_ON) /* COV_CAN_RX_QUEUE */
# define C_ENABLE_RX_QUEUE
#endif
#if (CAN_GENERIC_CONFIRMATION == STD_ON)
# define CAN_ENABLE_GENERIC_CONFIRMATION_API1
#endif
#if (CAN_GENERIC_CONFIRMATION == CAN_API2) /* COV_CAN_GENERIC_CONFIRMATION_API2 */
# define CAN_ENABLE_GENERIC_CONFIRMATION_API2
#endif
#if (CAN_GENERIC_PRETRANSMIT == STD_ON)
# define C_ENABLE_PRETRANSMIT_FCT
#endif
#if (CAN_ONE_CONTROLLER_OPTIMIZATION == STD_ON)
# define C_SINGLE_RECEIVE_CHANNEL
# define C_DISABLE_MULTICHANNEL_API
# define CAN_CHANNEL_CANTYPE_ONLY         void
# define CAN_CHANNEL_CANTYPE_FIRST
# define CAN_CHANNEL_CANTYPE_LOCAL
# define CAN_CHANNEL_CANPARA_ONLY
# define CAN_CHANNEL_CANPARA_FIRST
# define CAN_HW_CHANNEL_CANTYPE_ONLY      void
# define CAN_HW_CHANNEL_CANTYPE_FIRST
# define CAN_HW_CHANNEL_CANTYPE_LOCAL
# define CAN_HW_CHANNEL_CANPARA_ONLY
# define CAN_HW_CHANNEL_CANPARA_FIRST
# define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY    void
# define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST
# define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY
# define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST
# define CAN_CHANNEL_DUMMY_STATEMENT
# define CAN_HW_CHANNEL_DUMMY_STATEMENT
# define CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT
#else
# define C_MULTIPLE_RECEIVE_CHANNEL
# define C_ENABLE_MULTICHANNEL_API
# define CAN_CHANNEL_CANTYPE_ONLY         CanChannelHandle  Controller
# define CAN_CHANNEL_CANTYPE_FIRST        CanChannelHandle  Controller,
# define CAN_CHANNEL_CANTYPE_LOCAL        CanChannelHandle  Controller;
# define CAN_CHANNEL_CANPARA_ONLY         (CanChannelHandle) Controller
# define CAN_CHANNEL_CANPARA_FIRST        (CanChannelHandle) Controller,
# define CAN_HW_CHANNEL_CANTYPE_ONLY      CanChannelHandle  Controller
# define CAN_HW_CHANNEL_CANTYPE_FIRST     CanChannelHandle  Controller,
# define CAN_HW_CHANNEL_CANTYPE_LOCAL     CanChannelHandle  Controller;
# define CAN_HW_CHANNEL_CANPARA_ONLY      (CanChannelHandle) Controller
# define CAN_HW_CHANNEL_CANPARA_FIRST     (CanChannelHandle) Controller,
# define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_ONLY   CanChannelHandle Controller
# define CAN_CHANNEL_AND_HW_CHANNEL_CANTYPE_FIRST  CanChannelHandle Controller,
# define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_ONLY   Controller
# define CAN_CHANNEL_AND_HW_CHANNEL_CANPARA_FIRST  Controller,
# define CAN_CHANNEL_DUMMY_STATEMENT                 CAN_DUMMY_STATEMENT(Controller)
# define CAN_HW_CHANNEL_DUMMY_STATEMENT              CAN_DUMMY_STATEMENT(Controller)
# define CAN_CHANNEL_AND_HW_CHANNEL_DUMMY_STATEMENT  CAN_DUMMY_STATEMENT(Controller)
#endif
#if (CAN_GET_STATUS == STD_ON)
# define C_ENABLE_EXTENDED_STATUS
#endif
#if (CAN_RAM_CHECK == CAN_NOTIFY_ISSUE) /* COV_CAN_RAM_CHECK */
# define C_ENABLE_CAN_RAM_CHECK
# define C_ENABLE_CAN_RAM_CHECK_WAKEUP
#endif
#if (CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX) /* COV_CAN_RAM_CHECK */
# define C_ENABLE_CAN_RAM_CHECK
# define C_ENABLE_CAN_RAM_CHECK_WAKEUP
# define C_ENABLE_NOTIFY_CORRUPT_MAILBOX
#endif
#if (CAN_RAM_CHECK == CAN_EXTENDED) /* COV_CAN_RAM_CHECK_EXTENDED */
# define C_ENABLE_CAN_RAM_CHECK
# define C_ENABLE_CAN_RAM_CHECK_EXTENDED
#endif
#if (CAN_FD_SUPPORT != CAN_NONE) /* COV_CAN_FD_SUPPORT */
# define C_ENABLE_CAN_FD_USED
# if (CAN_FD_SUPPORT == CAN_BRS) /* COV_CAN_FD_SUPPORT */
#  define C_ENABLE_CAN_FD_BRS
# endif
# if (CAN_FD_SUPPORT == CAN_FULL) /* COV_CAN_FD_SUPPORT */
#  define C_ENABLE_CAN_FD_FULL
# endif
#endif
#if (CAN_USE_INIT_POINTER == STD_ON) /* InitPointer may not be used in variant system for symmetric configuration */
# define CAN_ENABLE_USE_INIT_ROOT_POINTER
#endif
#if (CAN_USE_ECUM_BSW_ERROR_HOOK == STD_ON)
# define CAN_ENABLE_USE_ECUM_BSW_ERROR_HOOK
#endif
#if (CAN_USE_OS_INTERRUPT_CONTROL == STD_ON) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_USE_OS_INTERRUPT_CONTROL
#endif
#if (CAN_SILENT_MODE == STD_ON) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_SILENT_MODE
#endif
#if ((CAN_INTLOCK == CAN_DRIVER) || (CAN_INTLOCK == CAN_BOTH)) /* COV_CAN_LOCK_ISR_BY_APPL */
# define C_ENABLE_CAN_CAN_INTERRUPT_CONTROL
#endif  
#if ( CAN_PROTECTED_MODE == STD_ON ) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_USER_MODE_OS
#endif
#if ( CAN_FD_HW_BUFFER_OPTIMIZATION == STD_ON ) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_CAN_FD_HW_BUFFER_OPTIMIZATION
#endif
#if (CAN_CHECK_WAKEUP_CAN_RET_TYPE == STD_ON) /* COV_CAN_COMPATIBILITY */
# define C_ENABLE_CHECK_WAKEUP_CAN_RET_TYPE
#endif

/***************************************************************************/
/* Compiler abstraction                                                    */
/***************************************************************************/

#if !defined(V_NULL) /* COV_CAN_COMPATIBILITY */
# define V_NULL          NULL_PTR
#endif
#if !defined(V_NONE) /* COV_CAN_COMPATIBILITY */
# define V_NONE       /* empty used instead of external, STATIC, volatile... */
# define CAN_AUTOMATIC    AUTOMATIC
# define CAN_TYPEDEF      TYPEDEF
#endif
#if !defined(CAN_STATIC) /* COV_CAN_COMPATIBILITY */
# if defined(STATIC) /* COV_CAN_COMPATIBILITY */
#  define CAN_STATIC  STATIC   /* standard by AutoSar 3.x */
# else
#  define CAN_STATIC  static   /* standard AutoSar 4.x define */
# endif
#endif
#if !defined(CAN_LOCAL_INLINE) /* COV_CAN_COMPATIBILITY */
# if defined(LOCAL_INLINE) /* COV_CAN_COMPATIBILITY */
#  define CAN_LOCAL_INLINE  LOCAL_INLINE
# else
#  define CAN_LOCAL_INLINE  
# endif
#endif

/* PRQA S 0342,3453 CompilerAbstractionLabel */ /* MD_Can_CompilerAbstraction,MD_MSR_FctLikeMacro */
#define V_DEF_VAR(storage, vartype, memclass)                    storage VAR(vartype, CAN_##memclass)
#define V_DEF_VAR_FAR(storage, vartype)                          storage VAR(vartype, CAN_VAR_FAR)
#define V_DEF_VAR_NEAR(storage, vartype)                         storage VAR(vartype, CAN_VAR_NEAR)
#define V_DEF_VAR_TYPE(storage, vartype)                         typedef storage VAR(vartype, TYPEDEF)
#define V_DEF_P2VAR(storage, ptrtype, memclass, ptrclass)        storage P2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_P2VAR_TYPE(storage, ptrtype, ptrclass)             typedef storage P2VAR(ptrtype, TYPEDEF, CAN_##ptrclass )
#define V_DEF_P2VAR_PARA(storage, ptrtype, memclass, ptrclass)   storage P2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_P2SFR_CAN(storage, ptrtype, memclass)              storage P2VAR(ptrtype, CAN_##memclass, CAN_REG_CANCELL)
#define V_DEF_P2SFR_CAN_TYPE(storage, ptrtype)                   typedef storage P2VAR(ptrtype, TYPEDEF, CAN_REG_CANCELL)
#define V_DEF_CONSTP2VAR(storage, ptrtype, memclass, ptrclass)   storage CONSTP2VAR(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_CONST(storage, type, memclass)                     storage CONST(type, CAN_##memclass)
#define V_DEF_CONST_TYPE(storage, type, memclass)                typedef storage CONST(type, TYPEDEF)
#define V_DEF_P2CONST(storage, ptrtype, memclass, ptrclass)      storage P2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_P2CONST_TYPE(storage, ptrtype, ptrclass)           typedef storage P2CONST(ptrtype, TYPEDEF, CAN_##ptrclass)
#define V_DEF_P2CONST_PARA(storage, ptrtype, memclass, ptrclass) storage P2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_CONSTP2CONST(storage, ptrtype, memclass, ptrclass) storage CONSTP2CONST(ptrtype, CAN_##memclass, CAN_##ptrclass)
#define V_DEF_CONSTP2CONST_TYPE(storage, ptrtype, ptrclass)      typedef storage CONSTP2CONST(ptrtype, TYPEDEF, CAN_##ptrclass)
#define V_DEF_FUNC(storage, rettype, memclass)                   storage FUNC(rettype, CAN_##memclass)
#define V_DEF_FUNC_API(storage, rettype, memclass)               storage FUNC(rettype, CAN_##memclass)
#define V_DEF_FUNC_CBK(storage, rettype, memclass)               storage FUNC(rettype, CAN_##memclass)
#define V_DEF_P2FUNC(storage, rettype, ptrclass, fctname)        storage P2FUNC(rettype, CAN_##ptrclass, fctname)
/* PRQA L:CompilerAbstractionLabel */

/* only use internal when not defined before */
#if !defined(vuint8) /* COV_CAN_COMPATIBILITY */
# define CAN_HL_NO_V_DEF
# define vuint8 uint8
#endif
#if !defined(vsint8) /* COV_CAN_COMPATIBILITY */
# define vsint8 sint8
#endif
#if !defined(vuint16) /* COV_CAN_COMPATIBILITY */
# define vuint16 uint16
#endif
#if !defined(vsint16) /* COV_CAN_COMPATIBILITY */
# define vsint16 sint16
#endif
#if !defined(vuint32) /* COV_CAN_COMPATIBILITY */
# define vuint32 uint32
#endif
#if !defined(vsint32) /* COV_CAN_COMPATIBILITY */
# define vsint32 sint32
#endif

/***************************************************************************/
/* LL return values                                                        */
/***************************************************************************/

/* return values of CanRxActualIdType */
#define kCanIdTypeStd       (0x00U)
#define kCanIdTypeExt       (0x40000000UL)
#define kCanFdTypeClassic   ((vuint8)0x00U)
#define kCanFdTypeFd        ((vuint8)0x20U)   /* EDL(FDF) */
#define kCanFdBrsTypeTrue   ((vuint8)0x10u)   /* BRS */
#define kCanFdBrsTypeFalse  ((vuint8)0x00u)


/* Switches are generated directly with Geny */

#if defined (CAN_REGEXT_MCMCAN)    /* COV_CAN_HW_SPECIFIC */
# if (CAN_REGEXT_MCMCAN == STD_ON) /* COV_CAN_HW_SPECIFIC */
#  define C_ENABLE_REGEXT_MCMCAN
# else
#  define C_DISABLE_REGEXT_MCMCAN
# endif
#else
#  define C_DISABLE_REGEXT_MCMCAN
#endif


#if defined (CAN_REGEXT_MCANSS)    /* COV_CAN_HW_SPECIFIC */
# if (CAN_REGEXT_MCANSS == STD_ON) /* COV_CAN_HW_SPECIFIC */
#  define C_ENABLE_REGEXT_MCANSS
# else
#  define C_DISABLE_REGEXT_MCANSS
# endif
#else
# define C_DISABLE_REGEXT_MCANSS
#endif

#if defined (CAN_REGEXT_SICANFD)    /* COV_CAN_HW_SPECIFIC */
# if (CAN_REGEXT_SICANFD == STD_ON) /* COV_CAN_HW_SPECIFIC */
#  define C_ENABLE_REGEXT_SICANFD
# else
#  define C_DISABLE_REGEXT_SICANFD
# endif
#else
# define C_DISABLE_REGEXT_SICANFD
#endif

#if defined (CAN_REGEXT_TTCANFD)    /* COV_CAN_HW_SPECIFIC */
# if (CAN_REGEXT_TTCANFD == STD_ON) /* COV_CAN_HW_SPECIFIC */
#   define C_ENABLE_REGEXT_TTCANFD
# else
#   define C_DISABLE_REGEXT_TTCANFD
# endif
#else
#  define C_DISABLE_REGEXT_TTCANFD
#endif

#if defined (CAN_SHM_DATAQOS) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
# if (CAN_SHM_DATAQOS == STD_ON) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
#  define C_ENABLE_SHM_DATAQOS
# else
#  define C_DISABLE_SHM_DATAQOS
# endif
#else
# define C_DISABLE_SHM_DATAQOS
#endif

# if defined (CAN_TRICORE_ERRATUM_AI_H001) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
#  if (CAN_TRICORE_ERRATUM_AI_H001 == STD_ON) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
#   define C_ENABLE_TRICORE_ERRATUM_AI_H001
#  else
#   define C_DISABLE_TRICORE_ERRATUM_AI_H001
#  endif
# else
#  define C_DISABLE_TRICORE_ERRATUM_AI_H001
# endif



/***************************************************************************/
/* LL parameter values                                                     */
/***************************************************************************/

/* PRQA S 3453 EOF */ /* MD_MSR_FctLikeMacro */
/* parameter for ApplCanTimerStart(),-End(), -Loop() */
# define kCanLoopInit          ((vuint8)0x00u)
# define kCanLoopRxFifo        ((vuint8)0x01u)
# define kCanLoopClockStop     ((vuint8)0x02u)
# define kCanLoopStart         ((vuint8)0x03u)
# define kCanLoopStop          ((vuint8)0x04u)
#if defined(C_ENABLE_TRICORE_ERRATUM_AI_H001)
# define kCanLoopIrFlag        ((vuint8)0x05u)
#endif

/* \trace SPEC-1399 */
/***************************************************************************/
/* data types need for API                                                 */
/***************************************************************************/
V_DEF_P2VAR_TYPE(V_NONE, Std_VersionInfoType, APPL_VAR) Can_VersionInfoPtrType;
V_DEF_P2CONST_TYPE(V_NONE, Can_ConfigType, CONST_PBCFG) Can_ConfigPtrType;
V_DEF_P2CONST_TYPE(V_NONE, Can_PduType, APPL_VAR)           Can_PduInfoPtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_PduType, APPL_VAR)             Can_PduInfoPtrType_var;
V_DEF_P2CONST_TYPE(V_NONE, uint8, RX_TX_DATA)               Can_DataPtrType;
V_DEF_P2VAR_TYPE(V_NONE, uint8, APPL_VAR)                   Can_ErrorCounterPtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_ControllerStateType, APPL_VAR) Can_ControllerStatePtrType;
V_DEF_P2VAR_TYPE(V_NONE, Can_ErrorStateType, APPL_VAR)      Can_ErrorStatePtrType;

/* data types for driver function parameters */

/* CanObjectHandle has to be unsigned! */
# define CanObjectHandle  Can_HwHandleType

V_DEF_VAR_TYPE(V_NONE, vuint16) CanTransmitHandle;
V_DEF_VAR_TYPE(V_NONE, vuint16) CanReceiveHandle;

V_DEF_VAR_TYPE(V_NONE, vuint16) CanInitHandle;

V_DEF_VAR_TYPE(V_NONE, vuint32) tCanRxId0;
V_DEF_VAR_TYPE(V_NONE, vuint32) tCanTxId0;


/* Pointer to msg object and message data used in precopy functions */

V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipDataPtr;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint32) CanChipMsgPtr;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipDataPtr8;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint8)  CanChipMsgPtr8;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint16) CanChipDataPtr16;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint16) CanChipMsgPtr16;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint32) CanChipDataPtr32;
V_DEF_P2SFR_CAN_TYPE(volatile, vuint32) CanChipMsgPtr32;

typedef vuint32           tCanDlc;

typedef struct tShiftMultiplyValueTypeTag 
{ /* CAN FD calculation values */
  vuint8 v1;
  vuint8 v2;
  vuint8 v3;
} tShiftMultiplyValueType;

typedef volatile struct tSIFETypeTag 
{ /* Std filter element */
  volatile vuint32 S0;
} tSIFEType;

typedef volatile struct tXIFETypeTag 
{ /* Ext filter element */
  volatile vuint32 F0;
  volatile vuint32 F1;
} tXIFEType;

typedef union 
{ /* PRQA S 0750 1 */ /* MD_MSR_18.4 */
  vuint8   b[4];
  vuint16  w[2];
  vuint32  dw;
} tAlignCopyElem;

typedef union 
{ /* PRQA S 0750 1 */ /* MD_MSR_18.4 */
  vuint32  dw[2];
#if defined(C_ENABLE_CAN_FD_FULL)
volatile vuint32  data[64/4]; /* this address must 32-bit aligned */
# else
volatile vuint32  data[8/4];  /* this address must 32-bit aligned */
#endif
} tAlign32bit;

typedef volatile struct tRxElmTypeTag
{ /* Rx Buffer and Fifo element */
 volatile vuint32 R0;               /* +0  Bit 31     ESI: Error State Indicator (0=Transmitting node is error active, 1=Transmitting node is error passive)
                                           Bit 30     XTD: 0=11-bit standard identifier, 1=29-bit extended identifier
                                           Bit 29     RTR: 0=data frame, 1=remote frame 
                                           Bit 28:0   ID[28:0]: ExtId, ID[28:18] StdId (depending on bit XTD) */
 volatile vuint32 R1;               /* +4  Bit 31     ANMF: 0=Received frame matching filter index FIDX, 1=Received frame did not match any Rx filter element
                                           Bit 30:24  FIDX[6:0]: 0-127=Index of matching Rx acceptance filter element (invalid if ANMF = '1')
                                           Bit 21     EDL: Extended Data Length, (0=Standard frame format, 1=CAN FD frame format (new DLC-coding and CRC))
                                           Bit 20     BRS: Bit Rate Switch (0=Frame received without bit rate switching, 1=Frame received with bit rate switching)
                                           Bit 19:16  DLC[3:0] : 0-8  =Received frame has 0-8 data bytes, 9-15 =Received frame has 8 data bytes
                                           Bit 15:0   RXTS[15:0]: Rx Timestamp Counter value captured on start of frame reception (Resolution depends on Prescaler TSCC[TCP] */
#if defined(C_ENABLE_CAN_FD_FULL)
volatile vuint32  data[64/4];      /* +8  R2: Data byte 3-0 ... */
# else
volatile vuint32  data[8/4];       /* +8  R2: Data byte 3-0 ... */
#endif
} tRxElmType;

typedef volatile struct tTxEventFifoElmTypeTag
{ /* Tx Event Fifo element */
 volatile vuint32 E0;               /* +0  Bit 30     XTD: 0=11-bit standard identifier, 1=29-bit extended identifier
                                           Bit 29     RTR: 0=Data frame transmitted, 1=Remote frame transmitted
                                           Bit 28:0   ID[28:0]= ExtId, ID[28:18]= StdId (depending on bit XTD) */
 volatile vuint32 E1;               /* +4  Bit 31:24  MM[7:0]: Message Marker - Copied from Tx Buffer into Tx Event FIFO element for identification of Tx message status
                                           Bit 23:22  ET[1:0]: Event Type - 00,11=Reserved, 01=Tx event, 10=Transmission in spite of cancellation (always set for transmissions in DAR mode)
                                           Bit 19:16  DLC[3:0] 0-8 =Frame with 0-8 data bytes transmitted, 9-15 =Frame with 8 data bytes transmitted
                                           Bit 15:0   TXTS[15:0]: Tx Timestamp Counter value captured on start of frame transmission (Resolution depends on Prescaler TSCC[TCP] */
} tTxEventFifoElmType;

typedef volatile struct tTXBETypeTag                  
{ /* Tx buffer element */
  volatile vuint32 T0;                                /* T0 Bit 30 XTD: Extended Identifier, Bit 29 RTR: Remote Transmission Request, Bits 28:0 ID[28:0]: Identifier */
  volatile vuint32 T1;                                /* T1 Bits 31:24 MM[7:0]: Message Marker, Bit 23 EFC: Event FIFO Control, Bits 19:16 DLC[3:0]: Data Length Code */    
#if defined(C_ENABLE_CAN_FD_FULL)                         
  volatile vuint32 Tn[64/4];                          /* Data bytes */
# else
  volatile vuint32 Tn[8/4];                           /* Data bytes */
#endif
} tTXBEType;

/* type of variable for ID type kCanIdTypeExt or kCanIdTypeStd will be assigned to 
   a variable of this type */
V_DEF_VAR_TYPE(V_NONE, vuint32) tCanIdType;
V_DEF_VAR_TYPE(V_NONE, vuint32) tCanFdType;
V_DEF_VAR_TYPE(V_NONE, vuint32) tCanFdBrsType;

typedef tCanLLCanIntOld *tCanLLCanIntOldPtr;


/* CAN Macro accessor */
#define Cn          ((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(channel)))
#if defined( C_SINGLE_RECEIVE_CHANNEL )
# define CnX(ch)    ((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr(0)))
#else
# define CnX(ch)    ((V_DEF_P2SFR_CAN(V_NONE, tCanObjType, AUTOMATIC))(Can_GetCanBasisAdr((ch))))
#endif

#if defined( C_ENABLE_REGEXT_MCMCAN ) /* COV_CAN_HW_SPECIFIC */
# define MCMCAN(subsystemaddr)   ((V_DEF_P2SFR_CAN(V_NONE, tCanGlobalObjType, AUTOMATIC))(subsystemaddr)) /* MCMCAN SFR */
#endif




#define GET_SIDF_OFFSET(num) ((vuint32)(num) << 2u)
#define GET_XIDF_OFFSET(num) ((vuint32)(num) << 3u)
#define GET_TXEF_OFFSET(num) ((vuint32)(num) << 3u)


/* PRQA S 0635 QAC_Can_635 */ /* MD_Can_0635 */
/* PRQA S 0750 QAC_Can_635 */ /* MD_MSR_18.4 */

typedef struct tRXMsgTag { /*! MCAN Message RAM Rx Buffer R0 structure */
  union {
    struct {
      vuint32 ID:29;  /*! CAN Identifier */
      vuint32 RTR:1;  /*! Remote Transmission Request */
      vuint32 XTD:1;  /*! Extended Identifier */
      vuint32 ESI:1;  /*! Error State Indicator */
    } R0;
    vuint32 r0;
  } uR0;
  union {
    struct { /*! MCAN Message RAM Rx Buffer R1 structure */
      vuint32 RXTS:16;/*! Rx Timestamp */
      vuint32 DLC:4;  /*! Data Length Code */
      vuint32 BRS:1;  /*! Bit Rate Switch */
      vuint32 FDF:1;  /*! FD Format */
      vuint32 r0:2;   /*! reserved */
      vuint32 FIDX:7; /*! Filter Index */
      vuint32 ANMF:1; /*! Accepted Non-matching Frame */
    } R1;
    vuint32 r1;
  } uR1;
# if defined( C_ENABLE_CAN_FD_FULL )
volatile vuint32  data[64/4];      /* +8  R2: Data byte 3-0 ... */
# else
volatile vuint32  data[8/4];       /* +8  R2: Data byte 3-0 ... */
# endif
} tRXMsg;

typedef struct tTXMsgTag {  /*! MCAN Message RAM Tx Buffer structure */
  union {
    struct { /*! MCAN Message RAM Tx Buffer T0 structure */
      vuint32 ID:29;  /*! CAN Identifier */
      vuint32 RTR:1;  /*! Remote Transmission Request */
      vuint32 XTD:1;  /*! Extended Identifier */
      vuint32 ESI:1;  /*! Error State Indicator */
    } T0;
    vuint32 t0;
  } uT0;
  union {
    struct { /*! MCAN Message RAM Tx Buffer T1 structure */
      vuint32 r1:16;  /*! reserved */
      vuint32 DLC:4;  /*! Data Length Code */
      vuint32 BRS:1;  /*! Bit Rate Switch */
      vuint32 FDF:1;  /*! FD Format */
      vuint32 r0:1;   /*! reserved */
      vuint32 EFC:1;  /*! Event Fifo Control */
      vuint32 MM:8;   /*! Message Marker */
    } T1;
    vuint32 t1;
  } uT1;
# if defined( C_ENABLE_CAN_FD_FULL )
volatile vuint32  data[64/4];      /* +8  R2: Data byte 3-0 ... */
# else
volatile vuint32  data[8/4];       /* +8  R2: Data byte 3-0 ... */
# endif
} tTXMsg;

typedef union tRXFnSTag { /*! MCAN RXF(0/1)S register Fifo structure */
  vuint32 R;
  struct {
    vuint32 FnFL:7; /*! Fifo Fill Level */
    vuint32 r2:1;   /*! reserved */
    vuint32 FnGI:6; /*! Fifo Get index */
    vuint32 r1:10;  /*! reserved (F(0/1)PI unused) */
    vuint32 FnF:1;  /*! Fifo Full */
    vuint32 RFnL:1; /*! Fifo Message Lost */
    vuint32 r0:6;   /*! reserved */
  } B;
} tRXFnS;

typedef union tRXFnCTag { /*! MCAN RXF(0/1)C register Fifo structure */
  vuint32 R;
  struct {
    vuint32:2;        /*! reserved */
    vuint32 FOSA:14;  /*! Fifo Start Address */
    vuint32 F0S:7;    /*! Fifo Size */
    vuint32:1;        /*! reserved */
    vuint32 F0WM:7;   /*! Fifo Watermark */
    vuint32:1;        /*! FIFO 0 Operation Mode */
  } B;
} tRXFnC;


typedef union tRXESCTag { /*! Rx Buffer/Fifo Element Size Configuration */
  vuint32 R;
  struct {
    vuint32 F0DS:3; /*! Rx FIFO 0 Data Field Size */
    vuint32:1;      /*! reserved */
    vuint32 F1DS:3; /*! Rx FIFO 1 Data Field Size */
    vuint32:1;      /*! reserved */
    vuint32 RBDS:3; /*! Rx Buffer Data Field Size */
    vuint32:21;     /*! reserved */
  } B;
} tRXESC;

typedef union tTXEFSTag {  /*! Tx Event FIFO Status */
  vuint32 R;
  struct {
      vuint32 EFFL:6; /*! Event FIFO Fill Level */
      vuint32 r1:2;   /*! reserved */
      vuint32 EFGI:5; /*! Event FIFO Get Index */
      vuint32:11;     /*! Event FIFO Put Index, reserved  */
      vuint32 EFF:1;  /*! Event FIFO Full */
      vuint32 TEFL:1; /*! Tx Event FIFO Element Lost */
      vuint32 r0:6;   /*! reserved */
  } B;
} tTXEFS;

/* PRQA  L:QAC_Can_635 */

typedef volatile struct tCanGlobalObjTypeTag
{ /*! MC MCAN global register structure */
  volatile vuint32 CLC;             /*!                Clock Control Register */
  volatile vuint32 unused1[11];     /*!                Reserved */ 
  volatile vuint32 MCR;             /*!                Module Control Register */
  volatile vuint32 BUFADR;          /*!                Buffer Receive Address and Transmit Address */
  volatile vuint32 unused2[2];      /*!                Reserved */
  volatile vuint32 MECR;            /*!                Measure Control Register */
  volatile vuint32 MESTAT;          /*!                Measure Status Register */
  volatile vuint32 unused3[37];     /*!                Reserved */
  volatile vuint32 ACCENCTR0;       /*!                Access Enable Control Register */
  volatile vuint32 unused4[2];      /*!                Reserved */
  volatile vuint32 OCS;             /*!                OCDS Control and Status */
  volatile vuint32 KRSTCLR;         /*!                Kernel Reset Status Clear Register */
  volatile vuint32 KRST1;           /*!                Kernel Reset Register 1 */
  volatile vuint32 KRST0;           /*!                Kernel Reset Register 0 */
  volatile vuint32 unused5;         /*!                Reserved */
  volatile vuint32 ACCEN0;          /*!                Access Enable Register 0 */
}tCanGlobalObjType;

typedef volatile struct tCanObjTypeTag
{ /*! Can module structure */
  /*! MC MCAN register structure */
  volatile vuint32 ACCENNODE0;      /*!                Access Enable Register */
  volatile vuint32 unused1;         /*!                Reserved */
  volatile vuint32 STARTADR;        /*!                Start Address Register */ 
  volatile vuint32 ENDADR;          /*!                End Address Register */
  volatile vuint32 ISREG;           /*!                Interrupt Signaling Register  */  
  volatile vuint32 GRINT1;          /*!                Interrupt routing for Groups 1 */
  volatile vuint32 GRINT2;          /*!                Interrupt routing for Groups 2 */  
  volatile vuint32 unused2;         /*!                Reserved */  
  volatile vuint32 NTCCR;           /*!                Node Timer Clock Control Register */ 
  volatile vuint32 NTATTR;          /*!                Node Timer A Transmit Trigger Register */ 
  volatile vuint32 NTBTTR;          /*!                Node Timer B Transmit Trigger Register */
  volatile vuint32 NTCTTR;          /*!                Node Timer C Transmit Trigger Register */
  volatile vuint32 NTRTR;           /*!                Node Timer Receive Timeout Register */ 
  volatile vuint32 unused3[3];      /*!                Reserved */
  volatile vuint32 NPCR;            /*!                Node Port Control Register */ 
  volatile vuint32 unused4[47];     /*!                Reserved */
  volatile vuint32 CREL;            /*! 0x0000         Core Release Register  */
  volatile vuint32 ENDN;            /*! 0x0004         Endian Register        */
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 1u ) /* PRQA S 0883 */ /* Appears only while testing */ /* COV_CAN_HW_SPECIFIC */
  volatile vuint32 res0[2];         /*! 0x0008-0x000C  Reserved */
#elif ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 2u ) /* COV_CAN_HW_SPECIFIC */
# if defined(C_ENABLE_SHM_DATAQOS) /* COV_CAN_HW_SPECIFIC_FUNCTIONALITY */
  volatile vuint32 MRCFG;           /*! 0x0008         Message RAM Configuration */
# else
  volatile vuint32 res0[1];         /*! 0x0008         Reserved */
# endif
  volatile vuint32 FBTP;            /*! 0x000C(RP)     Fast Bit Timing and Prescaler Register
                                                       Since MCAN Rev. 3.1.0: FBTP renamed to DBTP and restructured
                                                       - TDCO (bit 28:24) moved to new register TDCR
                                                       - increased confguration range for data bit timing */
#endif
  volatile vuint32 TEST;            /*! 0x0010         Test Register          */
  volatile vuint32 RWD;             /*! 0x0014(RP)     RAM Watchdog Register  */
  volatile vuint32 CCCR;            /*! 0x0018(RP)     CC Control Register    */
  volatile vuint32 BTP;             /*! 0x001C(RP)     Bit Timing and Prescaler Register, renamed to NBTP with Revision 3.1.0 */
  volatile vuint32 TSCC;            /*! 0x0020(RP)     Timestamp Counter Configuration    */ 
  volatile vuint32 TSCV;            /*! 0x0024         Timestamp Counter Value Register   */
  volatile vuint32 TOCC;            /*! 0x0028(RP)     Timeout Counter Configuration      */
  volatile vuint32 TOCV;            /*! 0x002C         Timeout Counter Value Register     */
           vuint32 res1[4];         /*! 0x0030-0x003C  Reserved */
  volatile vuint32 ECR;             /*! 0x0040         Error Counter Register    */
  volatile vuint32 PSR;             /*! 0x0044         Protocol Status Register  */
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 3u ) && ( Can_GetC_ENABLE_MPC5700_MCAN_CREL_STEP() >= 1u ) /* COV_CAN_HW_SPECIFIC */
  /*! since MCAN Rev. 3.1.0 TDCO moved to new register TDCR */
  volatile vuint32 TDCR;            /*! 0x0048         Transmitter Delay Compensation     */
           vuint32 res2;            /*! 0x004C         Reserved */
#else
           vuint32 res2[2];         /*! 0x0048-0x004C  Reserved */
#endif
  volatile vuint32 IR;              /*! 0x0050         Interrupt Register        */
  volatile vuint32 IE;              /*! 0x0054         Interrupt Enable Register */
  volatile vuint32 resIL[2];        /*! 0x0058-0x005C  Reserved in Tricore. ILS and ILE unavailable */
           vuint32 res3[8];         /*! 0x0060-0x007C  Reserved */
  volatile vuint32 GFC;             /*! 0x0080(RP)     Global Filter Configuration        */
  volatile vuint32 SIDFC;           /*! 0x0084(RP)     Standard ID Filter Configuration   */
  volatile vuint32 XIDFC;           /*! 0x0088(RP)     Extended ID Filter Configuration   */
           vuint32 res4;            /*! 0x008C         Reserved */
  volatile vuint32 XIDAM;           /*! 0x0090(RP)     Extended ID AND Mask               */
  volatile vuint32 HPMS;            /*! 0x0094         High Priority Message Status       */
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 1u ) /* COV_CAN_HW_SPECIFIC */
           vuint32 res5[2];         /*! 0x0098-0x009C  Reserved  */
#elif ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 2u ) /* COV_CAN_HW_SPECIFIC */
  volatile vuint32 NDATA[2];        /*! 0x0098         NDAT1-New Data 1 Register          */
                                    /*! 0x009C         NDAT2-New Data 2 Register          */
#endif
  volatile tRXFnC  RXF0C;           /*! 0x00A0(RP)     Rx FIFO 0 Configuration            */
  volatile tRXFnS  RXF0S;           /*! 0x00A4         Rx FIFO 0 Status                   */
  volatile vuint32 RXF0A;           /*! 0x00A8         Rx FIFO 0 Acknowledge              */
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() == 1u ) /* COV_CAN_HW_SPECIFIC */
           vuint32 res6;            /*! 0x00AC         Reserved */
#elif ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 2u ) /* COV_CAN_HW_SPECIFIC */
  volatile vuint32 RXBC;            /*! 0x00AC         Rx Buffer Configuration Register */
#endif
  volatile tRXFnC  RXF1C;           /*! 0x00B0(RP)     Rx FIFO 1 Configuration            */
  volatile tRXFnS  RXF1S;           /*! 0x00B4         Rx FIFO 1 Status                   */
  volatile vuint32 RXF1A;           /*! 0x00B8         Rx FIFO 1 Acknowledge              */
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 2u ) /* COV_CAN_HW_SPECIFIC */
  volatile tRXESC  RXESC;           /*! 0x00BC         Rx element size configuration      */
#else
           vuint32 res7;            /*! 0x00BC         Reserved */
#endif
  volatile vuint32 TXBC;            /*! 0x00C0(RP)     Tx Buffer Configuration            */
  volatile vuint32 TXFQS;           /*! 0x00C4         Tx FIFO/Queue Status               */
#if ( Can_GetC_ENABLE_MPC5700_MCAN_MAJOR_CREL() >= 2u ) /* COV_CAN_HW_SPECIFIC */
  volatile vuint32 TXESC;           /*! 0x00C8         Tx element size configuration      */
#else
           vuint32 res8;            /*! 0x00C8         Reserved */
#endif
  volatile vuint32 TXBRP;           /*! 0x00CC         Tx Buffer Request Pending          */
  volatile vuint32 TXBAR;           /*! 0x00D0         Tx Buffer Add Request              */
  volatile vuint32 TXBCR;           /*! 0x00D4         Tx Buffer Cancellation             */
  volatile vuint32 TXBTO;           /*! 0x00D8         Tx Buffer Transmission Occurred    */
  volatile vuint32 TXBCF;           /*! 0x00DC         Tx Buffer Cancellation Finished    */
  volatile vuint32 TXBTIE;          /*! 0x00E0         Tx Buffer Transmission Interrupt Enable */
  volatile vuint32 TXBCIE;          /*! 0x00E4         Tx Buffer Cancellation Finished Interrupt Enable */
           vuint32 res9[2];         /*! 0x00E8-0x00EC  Reserved */
  volatile vuint32 TXEFC;           /*! 0x00F0(RP)     Tx Event FIFO Configuration        */
  volatile tTXEFS  TXEFS;           /*! 0x00F4         Tx Event FIFO Status               */
  volatile vuint32 TXEFA;           /*! 0x00F8         Tx Event FIFO Acknowledge          */
           vuint32 resA;            /*! 0x00FC         Reserved */
  volatile vuint32 TTTMC;           /*! 0x100          Trigger Memory Configuration, start of NOT SUPPORTED TTCAN registers */
  volatile vuint32 TTRMC;           /*! 0x104          Reference Message Configuration    */
  volatile vuint32 TTOCF;           /*! 0x108          Operation Configuration Register   */
}tCanObjType;




/* Internal Flags */

/* \trace SPEC-1400 */
/***************************************************************************/
/* function prototypes / API                                               */
/***************************************************************************/
#define CAN_START_SEC_CODE  /*---------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/************************************************************************************************************
 *  Can_InitMemory()
 ***********************************************************************************************************/
/*! \brief         Power-up memory initialization
 *  \details       Initializes component variables in *_INIT_* sections at power up. \n
 *                 Use this to re-run the system without performing a new start from power on. \n
 *                 (E.g.: used to support an ongoing debug session without a complete re-initialization.) \n
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Use this function in case these variables are not initialized by the 
 *                 start up code. \n
 *                 Must be followed by a call to "Can_Init()".
 *  \trace         CREQ-970
************************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_InitMemory( void );

/************************************************************************************************************
 *  Can_Init()
 ***********************************************************************************************************/
/*! \brief         Initializes component
 *  \details       Initializes all component variables and sets the component state to initialized.
 *  \param[in]     ConfigPtr          Component configuration structure
 *  \pre           Interrupts are disabled.
 *  \pre           Module is uninitialized.
 *  \pre           Can_InitMemory() has been called unless CAN Module is initialized by start up code.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Parameter "ConfigPtr" will be taken into account only for "Multiple ECU Configuration" and in Post-Build variant. \n
 *  \trace         CREQ-969
************************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_Init( Can_ConfigPtrType ConfigPtr );

#if ((CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF))
/************************************************************************************************************
 *  Can_ChangeBaudrate()
 ***********************************************************************************************************/
/*! \brief         Change baud rate
 *  \details       This service shall change the baud rate and reinitialize the CAN controller.
 *  \param[in]     Controller    CAN controller to be changed
 *  \param[in]     Baudrate      Baud rate to be set
 *  \return        E_NOT_OK      Baud rate is not set
 *  \return        E_OK          Baud rate is set
 *  \pre           The CAN controller must be in "STOP Mode".
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        (CAN_CHANGE_BAUDRATE_API == STD_ON) || (CAN_SET_BAUDRATE_API == STD_OFF)
 *  \notes         Has to be called during the start up sequence before CAN communication takes place but after calling "Can_Init()".
 *  \trace         CREQ-995
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_ChangeBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate );
#endif

#if (CAN_CHANGE_BAUDRATE_API == STD_ON)
/************************************************************************************************************
 *  Can_CheckBaudrate()
 ***********************************************************************************************************/
/*! \brief         Checks baud rate
 *  \details       This service shall check if the given baud rate is supported of the CAN controller.
 *  \param[in]     Controller    CAN controller to be checked
 *  \param[in]     Baudrate      Baud rate to be checked
 *  \return        E_NOT_OK      Baud rate is not available
 *  \return        E_OK          Baud rate is available
 *  \pre           The CAN controller must be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_CHANGE_BAUDRATE_API == STD_ON
 *  \trace         CREQ-995
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckBaudrate( uint8 Controller, V_DEF_CONST(V_NONE, uint16, APPL_CONST) Baudrate );
#endif

#if (CAN_SET_BAUDRATE_API == STD_ON)
/************************************************************************************************************
 *  Can_SetBaudrate()
 ***********************************************************************************************************/
/*! \brief         Set baud rate
 *  \details       This service shall change the baud rate and reinitialize the CAN controller. \n
 *                 (Similar to Can_ChangeBaudrate() but used when identical baud rates are used for different CAN FD settings).
 *  \param[in]     Controller        CAN controller to be set
 *  \param[in]     BaudRateConfigID  Identity of the configured baud rate (available as Symbolic Name)
 *  \return        E_NOT_OK      Baud rate is not set
 *  \return        E_OK          Baud rate is set
 *  \pre           The CAN controller must be in "STOP Mode".
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_SET_BAUDRATE_API == STD_ON
 *  \trace         CREQ-995
***********************************************************************************************************/
/* \trace SPEC-50605 */
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetBaudrate( uint8 Controller, uint16 BaudRateConfigID );
#endif


#if (CAN_VERSION_INFO_API == STD_ON) /* BR:007 */
/************************************************************************************************************
 *  Can_GetVersionInfo()
 ***********************************************************************************************************/
/*! \brief         Returns the version information
 *  \details       Returns version information (MICROSAR3: BCD coded), vendor ID and AUTOSAR module ID.
 *  \param[out]    VersionInfo    Pointer to where to store the version information. Parameter must not be NULL.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_VERSION_INFO_API == STD_ON
 *  \trace         CREQ-991
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_GetVersionInfo( Can_VersionInfoPtrType VersionInfo );
#endif

#if (CAN_GET_STATUS == STD_ON)
/************************************************************************************************************
 *  Can_GetStatus()
 ***********************************************************************************************************/
/*! \brief         Get status/mode of the given controller
 *  \details       Delivers the status of the hardware, as a bit coded value where multiple bits may be set.
 *  \param[in]     Controller   CAN controller requested for status information
 *  \return        CAN_STATUS_START            START mode
 *  \return        CAN_STATUS_STOP             STOP mode
 *  \return        CAN_STATUS_INIT             Initialized controller
 *  \return        CAN_STATUS_INCONSISTENT     STOP or SLEEP are inconsistent over common CAN controllers
 *  \return        CAN_DEACTIVATE_CONTROLLER   RAM check failed CAN controller is deactivated
 *  \return        CAN_STATUS_WARNING          WARNING state
 *  \return        CAN_STATUS_PASSIVE          PASSIVE state
 *  \return        CAN_STATUS_BUSOFF           BUSOFF mode
 *  \return        CAN_STATUS_SLEEP            SLEEP mode
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_GET_STATUS == STD_ON
 *  \notes         the return value can be analysed using the provided API macros: \n
                   CAN_HW_IS_OK(), CAN_HW_IS_WARNING(), CAN_HW_IS_PASSIVE() \n
                   CAN_HW_IS_BUSOFF(), CAN_HW_IS_WAKEUP(), CAN_HW_IS_SLEEP()\n
                   CAN_HW_IS_STOP(), CAN_HW_IS_START(), CAN_HW_IS_INCONSISTENT()\n
                   None AUTOSAR API
 *  \trace         CREQ-978
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, uint8, CODE) Can_GetStatus( uint8 Controller );

/************************************************************************************************************
 *  Can_GetControllerMode()
 ***********************************************************************************************************/
/*! \brief         Get mode of the given controller
 *  \details       Delivers the controllers mode.
 *  \param[in]     Controller         CAN controller requested for status information
 *  \param[out]    ControllerModePtr  pointer to variable to store CAN controllers mode. Parameter must not be NULL.
 *  \return        E_NOT_OK           Controller mode request has not been accepted
 *  \return        E_OK               Controller mode request has been accepted
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_GET_STATUS == STD_ON
 *  \trace         CREQ-178460
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerMode( uint8 Controller, Can_ControllerStatePtrType ControllerModePtr );

/************************************************************************************************************
 *  Can_GetControllerErrorState()
 ***********************************************************************************************************/
/*! \brief         Get status of the given controller
 *  \details       Delivers the controllers error state.
 *  \param[in]     Controller         CAN controller requested for status information
 *  \param[out]    ErrorStatePtr      pointer to variable to store AN controllers error state. Parameter must not be NULL.
 *  \return        E_NOT_OK           Controller state request has not been accepted
 *  \return        E_OK               Controller state request has been accepted
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_GET_STATUS == STD_ON
 *  \trace         CREQ-178459
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerErrorState( uint8 Controller, Can_ErrorStatePtrType ErrorStatePtr );

/************************************************************************************************************
 *  Can_GetControllerTxErrorCounter()
 ***********************************************************************************************************/
/*! \brief         Get status of the given controller
 *  \details       Delivers the controllers TX error counter.
 *  \param[in]     Controller         CAN controller requested for TX error counter.
 *  \param[out]    TxErrorCounterPtr  pointer to variable to store CAN controllers TX error counter. Parameter must not be NULL.
 *  \return        E_NOT_OK           Controller TX error counter not available
 *  \return        E_OK               Controller TX error counter available
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_GET_STATUS == STD_ON
 *  \trace         CREQ-178459
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerTxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType TxErrorCounterPtr );

/************************************************************************************************************
 *  Can_GetControllerRxErrorCounter()
 ***********************************************************************************************************/
/*! \brief         Get status of the given controller
 *  \details       Delivers the controllers RX error counter.
 *  \param[in]     Controller         CAN controller requested for RX error counter.
 *  \param[out]    RxErrorCounterPtr  pointer to variable to store CAN controllers RX error counter. Parameter must not be NULL.
 *  \return        E_NOT_OK           Controller RX error counter not available
 *  \return        E_OK               Controller RX error counter available
 *  \pre           -
 *  \context       ANY
 *  \reentrant     TRUE
 *  \synchronous   TRUE
 *  \config        CAN_GET_STATUS == STD_ON
 *  \trace         CREQ-178459
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_GetControllerRxErrorCounter( uint8 Controller, Can_ErrorCounterPtrType RxErrorCounterPtr );

#endif

/************************************************************************************************************
 *  Can_SetControllerMode()
 ***********************************************************************************************************/
/*! \brief         Change the controller mode
 *  \details       Request a mode transition that will be processed a short time synchronous, \n
 *                 (may be finished ansynconous in Can_Mainfunction_Mode()) and call a notification when successful. \n
 *                 BUSOFF, WAKEUP and RAM check will be handled as well.
 *  \param[in]     Controller    CAN controller to be set
 *  \param[in]     Transition    Requested transition to destination mode CAN_T_START, CAN_T_STOP, CAN_T_SLEEP, CAN_T_WAKEUP
 *  \return        CAN_NOT_OK    transition request rejected
 *  \return        CAN_OK        transition request accepted
 *  \pre           Interrupts locked
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   FALSE
 *  \notes         Must not be called within CAN driver context like RX, TX or BUSOFF call out.
 *  \trace         CREQ-978
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_SetControllerMode( uint8 Controller, Can_StateTransitionType Transition );

/************************************************************************************************************
 *  Can_Write()
 ***********************************************************************************************************/
/*! \brief         Send a CAN message
 *  \details       copy data, DLC and ID to the send mailbox and request a transmission.
 *  \param[in]     Hth           Handle of the mailbox intended to send the message
 *  \param[in]     PduInfo       Information about the outgoing message (ID, dataLength, data)
 *  \return        CAN_NOT_OK    transmit request rejected
 *  \return        CAN_OK        transmit request successful
 *  \return        CAN_BUSY      transmit request could not be accomplished due to the controller is busy.
 *  \pre           disabled CAN interrupts / interrupts locked (Refer to critical section).
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-971
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Can_ReturnType, CODE) Can_Write( Can_HwHandleType Hth, Can_PduInfoPtrType PduInfo );

/************************************************************************************************************
 *  Can_CancelTx()
 ***********************************************************************************************************/
/*! \brief         Cancel TX message
 *  \details       Cancel the TX message in the hardware buffer (if possible) or mark the message as not to be confirmed \n
 *                 in case of the cancellation is unsuccessful.
 *  \param[in]     Hth     Handle of the mailbox intended to be cancelled.
 *  \param[in]     PduId   PDU identifier
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Do not call this API within TX confirmation context. Otherwise confirmation will occur for already
 *                 cancelled messages. Only one message will be cancelled, if there are multiple requests also multiple cancellations expected.\n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_CancelTx( Can_HwHandleType Hth, PduIdType PduId );

#if defined(C_ENABLE_MIRROR_MODE)
/************************************************************************************************************
 *  Can_SetMirrorMode()
 ***********************************************************************************************************/
/*! \brief         Activate mirror mode 
 *  \details       Switch the Appl_GenericPreCopy/Confirmation function ON or OFF.
 *  \param[in]     Controller   CAN controller
 *  \param[in]     mirrorMode   Activate or deactivate the mirror mode.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        C_ENABLE_MIRROR_MODE (user configuration file)
 *  \notes         Called by "Mirror Mode" CDD.\n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_SetMirrorMode( uint8 Controller, CddMirror_MirrorModeType mirrorMode );
#endif

#if defined(C_ENABLE_SILENT_MODE)
/************************************************************************************************************
 *  Can_SetSilentMode()
 ***********************************************************************************************************/
/*! \brief         Activate and deactivate the silent mode
 *  \details       Switch to silent mode, as a listen only mode without ACK. Also deactivate this mode again.
 *  \param[in]     Controller   CAN controller
 *  \param[in]     silentMode   Activate or deactivate the silent mode CAN_SILENT_INACTIVE, CAN_SILENT_ACTIVE (Enumaration).
 *  \return        E_OK         mode change successful
 *  \return        CAN_OK       mode change failed
 *  \pre           The CAN controller must be in "STOP Mode".
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_SILENT_MODE == STD_ON
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_SetSilentMode( uint8 Controller, Can_SilentModeType silentMode );
#endif

/************************************************************************************************************
 *  Can_CheckWakeup()
 ***********************************************************************************************************/
/*! \brief         Check WAKEUP occur
 *  \details       Check the occurrence of WAKEUP events for the given controller \n
 *                 (used as WAKEUP callback for higher layers).
 *  \param[in]     Controller           CAN controller to be checked for WAKEUP events.
 *  \return        E_OK/CAN_OK          the given controller caused a WAKEUP before.
 *  \return        E_NOT_OK/CAN_NOT_OK  the given controller caused no WAKEUP before.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-983
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Std_ReturnType, CODE) Can_CheckWakeup( uint8 Controller );

/************************************************************************************************************
 *  Can_DisableControllerInterrupts()
 ***********************************************************************************************************/
/*! \brief         Disable CAN interrupts
 *  \details       Disable the CAN interrupt for the given controller (e.g. due to data consistency reasons).
 *  \param[in]     Controller    CAN controller to disable interrupts for.
 *  \pre           Must not be called while CAN controller is in SLEEP mode.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Called within Critical Area handling or out of Application code.
 *  \trace         CREQ-988
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_DisableControllerInterrupts( uint8 Controller );

/************************************************************************************************************
 *  Can_EnableControllerInterrupts()
 ***********************************************************************************************************/
/*! \brief         Enable CAN interrupts
 *  \details       Re-enable the CAN interrupt for the given controller (e.g. due to data consistency reasons).
 *  \param[in]     Controller    CAN controller to enable interrupts for.
 *  \pre           Must not be called while CAN controller is in SLEEP mode.
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Called within Critical Area handling or out of Application code.
 *  \trace         CREQ-988
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_EnableControllerInterrupts( uint8 Controller );

/* polling functions (always available for non polled systems also) */
/************************************************************************************************************
 *  Can_MainFunction_Write()
 ***********************************************************************************************************/
/*! \brief         TX message observation
 *  \details       Polling TX events (confirmation, cancellation) for all controllers and all TX mailboxes \n
 *                 to accomplish the TX confirmation handling (like CanInterface notification).
 *  \pre           Must not interrupt the call of Can_Write(). CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Write( void );

/************************************************************************************************************
 *  Can_MainFunction_Read()
 ***********************************************************************************************************/
/*! \brief         RX message observation
 *  \details       Polling RX events for all controllers and all RX mailboxes to accomplish the \n
 *                 RX indication handling (like CanInterface notification). \n
 *                 Also used for a delayed read (from task level) of the RX Queue messages which were queued from interrupt context.
 *  \pre           CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Read( void );

/************************************************************************************************************
 *  Can_MainFunction_BusOff()
 ***********************************************************************************************************/
/*! \brief         BUSOFF observation
 *  \details       Polling of BUSOFF events to accomplish the BUSOFF handling.
 *                 Service function to poll BUSOFF events for all controllers to accomplish the BUSOFF handling \n
 *                 (like calling of CanIf_ControllerBusOff() in case of BUSOFF occurrence).
 *  \pre           CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_BusOff( void );

/************************************************************************************************************
 *  Can_MainFunction_Wakeup()
 ***********************************************************************************************************/
/*! \brief         WAKEUP observation
 *  \details       Polling WAKEUP events for all controllers to accomplish the WAKEUP handling \n
 *                 (like calling of "CanIf_SetWakeupEvent()" in case of WAKEUP occurrence).
 *  \pre           CAN driver has to be initialized.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         Empty function in case no polling is active.
 *  \trace         CREQ-983
 *  \trace         CREQ-979
***********************************************************************************************************/
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Wakeup( void );

/************************************************************************************************************
 *  Can_MainFunction_Mode()
 ***********************************************************************************************************/
/*! \brief         Mode transition observation
 *  \details       Polling Mode changes over all controllers. \n
                   (This is handled asynchronous if not accomplished in "Can_SetControllerMode()")
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \trace         CREQ-978
***********************************************************************************************************/
V_DEF_FUNC(extern, void, CODE) Can_MainFunction_Mode( void );

#if defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED)
/************************************************************************************************************
 *  Can_RamCheckExecute()
 ***********************************************************************************************************/
/*! \brief         Start checking the CAN cells RAM
 *  \details       Check all controller specific and mailbox specific registers by write patterns and read back.
 *                 Issue notification will appear in this context.
 *  \param[in]     Controller    CAN controller to be checked.
 *  \pre           Has to be called within STOP mode.
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_EXTENDED
 *  \trace         CREQ-106641
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckExecute( uint8 Controller );

/************************************************************************************************************
 *  Can_RamCheckEnableMailbox()
 ***********************************************************************************************************/
/*! \brief         Reactivate a mailbox after RamCheck failed.
 *  \details       Mailbox will be reactivated by clear deactivation flag.
 *  \param[in]     htrh    CAN mailbox to be reactivated.
 *  \pre           Has to be called within STOP mode after RamCheck failed (controller is deactivated).
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \notes         must be followed by Can_RamCheckEnableController() to activate mailbox and controller.
 *  \config        CAN_RAM_CHECK == CAN_EXTENDED
 *  \trace         CREQ-106641
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableMailbox( Can_HwHandleType htrh );

/************************************************************************************************************
 *  Can_RamCheckEnableController()
 ***********************************************************************************************************/
/*! \brief         Reactivate CAN cells after RamCheck failed.
 *  \details       CAN cell will be reactivated by execute reinitialization.
 *  \param[in]     Controller    CAN controller to be reactivated.
 *  \pre           Has to be called within STOP mode after RamCheck failed (controller is deactivated).
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_EXTENDED
 *  \trace         CREQ-106641
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) Can_RamCheckEnableController( uint8 Controller );
#endif

/* Platform specific API */


/* ISR prototypes (see can_irq.c) */

/* Possibility to disable the prototypes of interrupt service routines in the driver configuration header file.  */

/* Default switch C_ENABLE_ISR_PROTOTYPE is located here due only this token is used in the specific ASR header file. */
#if ( (!defined( C_ENABLE_ISR_PROTOTYPE )) && (!defined( C_DISABLE_ISR_PROTOTYPE )) ) /* COV_CAN_ISR_PROTOTYPE */
# define C_ENABLE_ISR_PROTOTYPE  /* default while not overwritten by user config */
#endif

#if defined( C_ENABLE_TX_POLLING )          && \
    defined( C_ENABLE_RX_BASICCAN_POLLING ) && \
    defined( C_ENABLE_RX_FULLCAN_POLLING )  && \
    defined( C_ENABLE_RX_POLLING )          && \
    defined( C_ENABLE_ERROR_POLLING )       && \
    !defined( C_ENABLE_INDIVIDUAL_POLLING )
# define C_DISABLE_ISR_MANDATORY
#else
# define C_ENABLE_ISR_MANDATORY
#endif

#if defined( CAN_GEN_COM_STACK_LIB )  /* COV_CAN_COMPATIBILITY */
# if (CAN_ISR_ALL_CHAN == STD_ON)      /* COV_CAN_HW_SPECIFIC */
#  define C_ENABLE_CAN_ISR_ALL_CHAN
#  if defined(CAN_IRQ_SOURCE) /* COV_CAN_INTERNAL */
#   define Can_GetCanBasisAdr(hwch)                           Can_GetBasisAdrOfControllerConfig(hwch)  /* only required for this specific additional channel detection */
#  endif
# else
#  define C_DISABLE_CAN_ISR_ALL_CHAN
# endif
#endif /* CAN_GEN_COM_STACK_LIB */

#if defined (C_ENABLE_ISR_PROTOTYPE) /* COV_CAN_HW_SPECIFIC */
# if defined(C_ENABLE_OSEK_OS)&&  defined(C_ENABLE_OSEK_OS_INTCAT2) /* COV_CAN_OS_USAGE */
/* ISR prototypes must be provided by OSEK header file */
# else   /* (C_ENABLE_OSEK_OS) && (C_ENABLE_OSEK_OS_INTCAT2) */
#  if defined( C_ENABLE_ISR_MANDATORY ) /* ISR necessary; no pure polling configuration */
/************************************************************************************************************
 *  CanIsr_0
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_0.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_0 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_0( void );
#    endif
/************************************************************************************************************
 *  CanIsr_1
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_1.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_1 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_1( void );
#    endif
/************************************************************************************************************
 *  CanIsr_2
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_2.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_2 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_2( void );
#    endif
/************************************************************************************************************
 *  CanIsr_3
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_3.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_3 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_3( void );
#    endif
/************************************************************************************************************
 *  CanIsr_4
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_4.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_4 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_4( void );
#    endif
/************************************************************************************************************
 *  CanIsr_5
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_5.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_5 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_5( void );
#    endif
/************************************************************************************************************
 *  CanIsr_6
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_6.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_6 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_6( void );
#    endif
/************************************************************************************************************
 *  CanIsr_7
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_7.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_7 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_7( void );
#    endif
/************************************************************************************************************
 *  CanIsr_8
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_8.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_8 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_8( void );
#    endif
/************************************************************************************************************
 *  CanIsr_9
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_9.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_9 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_9( void );
#    endif
/************************************************************************************************************
 *  CanIsr_10
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_10.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_10 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_10( void );
#    endif
/************************************************************************************************************
 *  CanIsr_11
 ***********************************************************************************************************/
/*! \brief         Interrupt service function for MCAN interrupts on CAN_11.
 *  \details       Calls the interrupt handler.
 *  \context       ISR1|ISR2
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \pre           -
 ***********************************************************************************************************/
#    if defined( kCanPhysToLogChannelIndex_11 ) /* COV_CAN_EQUAL_CHANNEL_LAYOUT */
V_DEF_FUNC(V_NONE, void, CODE) CanIsr_11( void );
#    endif
#  endif /* C_ENABLE_ISR_MANDATORY no pure polling configuration */
# endif /* C_ENABLE_OSEK_OS && C_ENABLE_OSEK_OS_INTCAT2 */
#endif /* C_ENABLE_ISR_PROTOTYPE */

/************************************************************************************************************
 *  CanInterrupt()
 ***********************************************************************************************************/
/*! \brief         Handles channel specific interrupts.
 *  \details       Calls the confirmation, indication, error handling and wakeup functions.
 *  \param[in]     canHwChannel        CAN channel (configuration dependent)
 *  \context       ISR1|ISR2
 *  \reentrant     TRUE for different handles
 *  \synchronous   TRUE
 *  \config        Interrupt configurations.
 *  \pre           -
 ***********************************************************************************************************/
/* CODE CATEGORY 1 START */
V_DEF_FUNC(V_NONE, void, CODE) CanInterrupt(CAN_HW_CHANNEL_CANTYPE_ONLY);
/* CODE CATEGORY 1 END */

#define CAN_STOP_SEC_CODE  /*------------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#define CAN_START_SEC_CODE_APPL  /*----------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if (CAN_GENERIC_PRECOPY == STD_ON)
/************************************************************************************************************
 *  Appl_GenericPrecopy()
 ***********************************************************************************************************/
/*! \brief         Common RX indication callback that will be called before message specific callback will be called.
 *  \details       Application callback function which informs about all incoming RX messages including the contained data. \n
 *                 It can be used to block notification to upper layer. E.g. to filter incoming messages or route it for special handling.
 *  \param[in]     Controller   CAN controller which received the message.
 *  \param[in]     ID           ID of the received message (include IDE,FD). \n
 *                              In case of extended or mixed ID systems the highest bit (bit 31) is set to mark an extended ID. \n
 *                              FD-bit (bit 30) can be masked out with a define CAN_ID_MASK_IN_GENERIC_CALLOUT in the user config file.
 *  \param[in]     DataLength   Data length of the received message.
 *  \param[in]     pData        Pointer to the data of the received message (read only).
 *  \return        CAN_OK       Higher layer indication will be called afterwards (CanIf_RxIndication()).
 *  \return        CAN_NOT_OK   Higher layer indication will not be called afterwards.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_PRECOPY == STD_ON
 *  \notes         "pData" is read only and must not be accessed for further write operations. \n
 *                 The parameter DataLength refers to the received data length by the CAN controller hardware.\n
 *                 Note, that the CAN protocol allows the usage of data length values greater than eight (CAN-FD).\n
 *                 Depending on the implementation of this callback it may be necessary to consider this special case (e.g. if the data length is used as index value in a buffer write access).
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericPrecopy( uint8 Controller, Can_IdType ID, uint8 DataLength, Can_DataPtrType DataPtr );
#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API1)
/************************************************************************************************************
 *  Appl_GenericConfirmation()
 ***********************************************************************************************************/
/*! \brief         Common TX notification callback that will be called before message specific callback will be called.
 *  \details       Application callback function which informs about TX messages being sent to the CAN bus.
 *                 It can be used to block confirmation or route the information to other layer as well.
 *  \param[in]     PduId       Handle of the PDU specifying the message.
 *  \return        CAN_OK      Higher layer confirmation will be called afterwards (CanIf_TxConfirmation()).
 *  \return        CAN_NOT_OK  Higher layer confirmation will not be called afterwards.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_CONFIRMATION == STD_ON
 *  \notes         "PduId" is read only and must not be accessed for further write operations. \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericConfirmation( PduIdType PduId );
#endif

#if defined(CAN_ENABLE_GENERIC_CONFIRMATION_API2)
/************************************************************************************************************
 *  Appl_GenericConfirmation()
 ***********************************************************************************************************/
/*! \brief         Common TX notification callback that will be called before message specific callback will be called.
 *  \details       Application callback function which informs about TX messages being sent to the CAN bus.
 *                 It can be used to block confirmation or route the information to other layer as well.
 *  \param[in]     Controller  CAN controller which send the message.
 *  \param[in]     DataPtr     Pointer to a Can_PduType structure including ID (include IDE,FD), DataLength, PDU and data pointer.
 *  \return        CAN_OK      Higher layer (CanInterface) confirmation will be called.
 *  \return        CAN_NOT_OK  No further higher layer (CanInterface) confirmation will be called.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_CONFIRMATION == CAN_API2
 *  \notes         A new transmission within this call out will corrupt the DataPtr context. \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, Can_ReturnType, APPL_CODE) Appl_GenericConfirmation( uint8 Controller, Can_PduInfoPtrType DataPtr );
#endif

#if defined(C_ENABLE_PRETRANSMIT_FCT)
/************************************************************************************************************
 *  Appl_GenericPreTransmit()
 ***********************************************************************************************************/
/*! \brief         Common transmit callback.
 *  \details       Application callback function allowing the modification of the data to be transmitted (e.g.: add CRC).
 *  \param[in]     Controller  CAN controller on which the message will be send.
 *  \param[in]     DataPtr     Pointer to a Can_PduType structure including ID (include IDE,FD), DataLength, PDU and data pointer.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_GENERIC_PRETRANSMIT == STD_ON
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_GenericPreTransmit( uint8 Controller, Can_PduInfoPtrType_var DataPtr );
#endif

# if (CAN_HW_LOOP_SUPPORT_API == STD_ON)
/************************************************************************************************************
 *  ApplCanTimerStart()
 ***********************************************************************************************************/
/*! \brief         Start time out monitoring
 *  \details       Service function to start an observation timer.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        (CAN_HW_LOOP_SUPPORT_API == STD_ON) && (CAN_HW_LOOP_SUPPORT_API == STD_ON)
 *  \notes         Please refer to chapter "Hardware Loop Check". \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanTimerStart( CAN_CHANNEL_CANTYPE_FIRST uint8 source );

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
 *  \config        (CAN_HW_LOOP_SUPPORT_API == STD_ON) && (CAN_HW_LOOP_SUPPORT_API == STD_ON)
 *  \notes         Please refer to chapter "Hardware Loop Check". \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, Can_ReturnType, APPL_CODE) ApplCanTimerLoop( CAN_CHANNEL_CANTYPE_FIRST uint8 source );

/************************************************************************************************************
 *  ApplCanTimerEnd()
 ***********************************************************************************************************/
/*! \brief         Stop time out monitoring
 *  \details       Service function to to end an observation timer.
 *  \param[in]     Controller  CAN controller on which the hardware observation takes place. \n
 *                             (only if not using "Optimize for one controller")
 *  \param[in]     source      Source for the hardware observation.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        (CAN_HW_LOOP_SUPPORT_API == STD_ON) && (CAN_HW_LOOP_SUPPORT_API == STD_ON)
 *  \notes         Please refer to chapter "Hardware Loop Check". \n
 *                 None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanTimerEnd( CAN_CHANNEL_CANTYPE_FIRST uint8 source );
# endif

#if (CAN_INTLOCK != CAN_DRIVER)
/************************************************************************************************************
 *  ApplCanInterruptDisable()
 ***********************************************************************************************************/
/*! \brief         CAN interrupt disabling by application
 *  \details       Disabling of CAN Interrupts by the application. \n
 *                 E.g.: the CAN driver itself should not access the common Interrupt Controller due to application \n
 *                 specific restrictions (like security level). Or the application like to be informed because of \n
 *                 an CAN interrupt lock. called by Can_DisableControllerInterrupts().
 *  \param[in]     Controller   CAN controller for the CAN interrupt lock.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_INTLOCK == CAN_APPL || CAN_INTLOCK == CAN_BOTH
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanInterruptDisable( uint8 Controller );

/************************************************************************************************************
 *  ApplCanInterruptRestore()
 ***********************************************************************************************************/
/*! \brief         CAN interrupt restore by application
 *  \details       Re-enabling of CAN Interrupts by the application. \n
                   E.g.: the CAN driver itself should not access the common Interrupt Controller due to application \n
                   specific restrictions (like security level). Or the application like to be informed because of \n
                   an CAN interrupt lock. called by Can_EnableControllerInterrupts().
 *  \param[in]     Controller   CAN controller for the CAN interrupt unlock.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_INTLOCK == CAN_APPL || CAN_INTLOCK == CAN_BOTH
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanInterruptRestore( uint8 Controller );
#endif

#if (CAN_OVERRUN_NOTIFICATION == CAN_APPL)
/************************************************************************************************************
 *  Appl_CanOverrun()
 ***********************************************************************************************************/
/*! \brief         Overrun detection
 *  \details       Called when an overrun is detected for a BasicCAN mailbox. \n
 *                 Alternatively a DET call can be selected instead of ("CanOverrunNotification" is set to "DET").
 *  \param[in]     Controller   CAN controller for which the overrun was detected.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_OVERRUN_NOTIFICATION == CAN_APPL
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanOverrun ( uint8 Controller );

/************************************************************************************************************
 *  Appl_CanFullCanOverrun()
 ***********************************************************************************************************/
/*! \brief         Overrun detection
 *  \details       Called when an overrun is detected for a FullCAN mailbox. \n
 *                 Alternatively a DET call can be selected instead of ("CanOverrunNotification" is set to "DET").
 *  \param[in]     Controller   CAN controller for which the overrun was detected.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_OVERRUN_NOTIFICATION == CAN_APPL
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanFullCanOverrun ( uint8 Controller );
#endif

#if defined(C_ENABLE_CAN_RAM_CHECK)
# if !defined(C_ENABLE_CAN_RAM_CHECK_EXTENDED) /* standard RAM_CHECK */
#  if defined(C_ENABLE_NOTIFY_CORRUPT_MAILBOX)
/************************************************************************************************************
 *  Appl_CanCorruptMailbox()
 ***********************************************************************************************************/
/*! \brief         Mailbox notification in case of RAM check failure.
 *  \details       Will notify the application (during re-initialization) about a defect mailbox within the CAN cell.
 *  \param[in]     Controller   CAN controller for which the check failed.
 *  \param[in]     hwObjHandle  Hardware handle of the defect mailbox.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) Appl_CanCorruptMailbox(uint8 Controller, Can_HwHandleType hwObjHandle);
#  endif

/************************************************************************************************************
 *  Appl_CanRamCheckFailed()
 ***********************************************************************************************************/
/*! \brief         CAN controller notification in case of RAM check failure
 *  \details       will notify the application (during re-initialization) about a defect CAN controller \n
 *                 due to a previous failed mailbox check. The return value decide how to proceed with the initialization.
 *  \param[in]     Controller   CAN controller for which the check failed.
 *  \return        CAN_DEACTIVATE_CONTROLLER   deactivate the controller
 *  \return        CAN_ACTIVATE_CONTROLLER     activate the controller
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        CAN_RAM_CHECK == CAN_NOTIFY_MAILBOX / CAN_NOTIFY_ISSUE
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, uint8, APPL_CODE) Appl_CanRamCheckFailed(uint8 Controller);
# endif /* standard RAM_CHECK */
#endif

# if defined ( C_ENABLE_USER_MODE_APPL )
/************************************************************************************************************
 *  ApplCanWriteProtectedRegister()
 ***********************************************************************************************************/
/*! \brief         Callback to write protected registers.
 *  \details       Application function which is called by the CAN driver to write special protected registers,
 *                 when CAN driver runs in user mode. 
 *  \param[in]     regPtr   Pointer to the register which has to be written.
 *  \param[in]     mask     The mask specifies the bits of the register to be written.
 *  \param[in]     value    The value which has to be written to the register.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        define C_ENABLE_USER_MODE_APPL via user configuration file
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanWriteProtectedRegister8(CanChipMsgPtr8 regPtr, uint8 mask, uint8 value);
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanWriteProtectedRegister16(CanChipMsgPtr16 regPtr, uint16 mask, uint16 value);
V_DEF_FUNC(extern, void, APPL_CODE) ApplCanWriteProtectedRegister32(CanChipMsgPtr32 regPtr, uint32 mask, uint32 value);
/************************************************************************************************************
 *  ApplCanReadProtectedRegister()
 ***********************************************************************************************************/
/*! \brief         Callback to read protected registers.
 *  \details       Application function which is called by the CAN driver to read special protected registers,
 *                 when CAN driver runs in user mode.
 *  \return        value    Returns the value of the register that was read
 *  \param[in]     regPtr   Pointer to the register which has to be written.
 *  \pre           -
 *  \context       ANY
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        define C_ENABLE_USER_MODE_APPL via user configuration file
 *  \notes         None AUTOSAR API
***********************************************************************************************************/
V_DEF_FUNC(extern, uint8, APPL_CODE) ApplCanReadProtectedRegister8(CanChipMsgPtr8 regPtr);
V_DEF_FUNC(extern, uint16, APPL_CODE) ApplCanReadProtectedRegister16(CanChipMsgPtr16 regPtr);
V_DEF_FUNC(extern, uint32, APPL_CODE) ApplCanReadProtectedRegister32(CanChipMsgPtr32 regPtr);
# endif


/* \trace SPEC-1588 */

#if !defined ApplCanClockStop
# define C_DISABLE_APPL_CAN_CLOCK_STOP
# define ApplCanClockStop(hwCh)     /* unused user callback */
#else
# define C_ENABLE_APPL_CAN_CLOCK_STOP
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  ApplCanClockStop()
 ***********************************************************************************************************/
/*! \brief         Application call to turn off MCAN clock
 *  \details       This will be called when the application is allowed to turn off the clocks for CAN and Host.
 *  \param[in]     channel       CAN controller
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) ApplCanClockStop(CAN_HW_CHANNEL_CANTYPE_ONLY);   /* PRQA S 3408 */ /* MD_Can_ExternalScope */
/* CODE CATEGORY 4 END */
#endif

#if !defined ApplCanClockStart
# define ApplCanClockStart(hwCh)    /* unused user callback */
#else
/* CODE CATEGORY 4 START */
/************************************************************************************************************
 *  ApplCanClockStart()
 ***********************************************************************************************************/
/*! \brief         Application call to turn on MCAN clock
 *  \details       This will be called when the application shall turn on the clocks for CAN and Host before communication is started.
 *  \param[in]     channel       CAN controller
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
***********************************************************************************************************/
V_DEF_FUNC(V_NONE, void, CODE) ApplCanClockStart(CAN_HW_CHANNEL_CANTYPE_ONLY);  /* PRQA S 3408 */ /* MD_Can_ExternalScope */
/* CODE CATEGORY 4 END */
#endif


# define CanBtpReg(ch)               (*(V_DEF_P2SFR_CAN(V_NONE, vuint32, AUTOMATIC))((Can_GetCanBasisAdr((ch)))+0x1C)) /* PRQA S 3453  */ /* MD_MSR_FctLikeMacro */
# define CanRxBCReg(ch)              (*(V_DEF_P2SFR_CAN(V_NONE, vuint32, AUTOMATIC))((Can_GetCanBasisAdr((ch)))+0xAC)) /* PRQA S 3453  */ /* MD_MSR_FctLikeMacro */
# define CanRxESCReg(ch)             (*(V_DEF_P2SFR_CAN(V_NONE, vuint32, AUTOMATIC))((Can_GetCanBasisAdr((ch)))+0xBC)) /* PRQA S 3453  */ /* MD_MSR_FctLikeMacro */
# define CanTxESCReg(ch)             (*(V_DEF_P2SFR_CAN(V_NONE, vuint32, AUTOMATIC))((Can_GetCanBasisAdr((ch)))+0xC8)) /* PRQA S 3453  */ /* MD_MSR_FctLikeMacro */

# if defined( C_ENABLE_INIT_POST_PROCESS )
/************************************************************************************************************
 *  ApplCanInitPostProcessing()
 ***********************************************************************************************************/
/*! \brief          Service function to overwrite the previously set initialization values
 *  \details        Service function to overwrite the previously set initialization values for the bit timing, taken from the generated data, \n
 *                  with customer specific values. \n
 *                  For your convenience the following access function is supported: \n
 *                  - CanBtpReg(controller):  -  the BTP register of the specified CAN channel can be set according to the register definition \n
 *                  as specified in the Hardware Manufacturer Document ((see ch. 2).  \n
 *                  Example: CanBtpReg(Controller) = 0x00070F70u;  \n
 *                  or    CanBtpReg(0)             = 0x00070F70u; (when using 'Optimize for one controller')
 *  \param[in]      Controller  Number of the controller for which the check failed
 *  \note           Called by CAN driver.
 *  \pre            -
 *  \context        ANY
 *  \reentrant      FALSE
 *  \synchronous    FALSE
 *  \notes          Called within controller initialization.
 *  \availability   Only available if  'C_ENABLE_INIT_POST_PROCESS' is defined via a user-config file.
 *  \warning        None AUTOSAR API \n
 *                  It is the responsibility of the application to assure that the register values are consistent with the release of the underlying derivative.
**********************************************************************************************************************/
V_DEF_FUNC(V_NONE, void, APPL_CODE) ApplCanInitPostProcessing(CAN_HW_CHANNEL_CANTYPE_ONLY);
# endif


#if defined( C_ENABLE_REGEXT_MCMCAN ) /* COV_CAN_HW_SPECIFIC */
/************************************************************************************************************
 *  Appl_UnlockEndinit()
 ***********************************************************************************************************/
/*! \brief         Set the ENDINIT Control Bit
 *  \details       This function must be implemented by application. The callback function needs to set the ENDINIT
 *                 Control Bit.
 *  \param[in]     -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        -
 *  \notes         None AUTOSAR API. Called within controller initialization while the registers CLC and FDR need to be set
 ***********************************************************************************************************/  
V_DEF_FUNC_CBK(V_NONE, void, APPL_CODE) Appl_UnlockEndinit(void);

/************************************************************************************************************
 *  Appl_LockEndinit()
 ***********************************************************************************************************/
/*! \brief         Reset the ENDINIT Control Bit
 *  \details       This function must be implemented by application. The callback function needs to reset the ENDINIT
 *                 Control Bit.
 *  \param[in]     -
 *  \pre           -
 *  \context       TASK
 *  \reentrant     FALSE
 *  \synchronous   TRUE
 *  \config        -
 *  \notes         None AUTOSAR API. Called within controller initialization while the registers CLC and FDR need to be set
 ***********************************************************************************************************/  
V_DEF_FUNC_CBK(V_NONE, void, APPL_CODE) Appl_LockEndinit(void);
#endif   /* C_ENABLE_REGEXT_MCMCAN */


#define CAN_STOP_SEC_CODE_APPL  /*-----------------------------------------*/
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

#if !defined(C_DRV_INTERNAL) /* COV_CAN_INTERNAL */
# if defined(CAN_HL_NO_V_DEF) /* COV_CAN_INTERNAL */
/* only use internal when not defined before - undef to get no conflict in CBD - MSR mixed systems */
#  undef vuint8   /* PRQA S 0841 */ /* MD_Can_HL_UndefTypes */
#  undef vsint8   /* PRQA S 0841 */ /* MD_Can_HL_UndefTypes */
#  undef vuint16  /* PRQA S 0841 */ /* MD_Can_HL_UndefTypes */
#  undef vsint16  /* PRQA S 0841 */ /* MD_Can_HL_UndefTypes */
#  undef vuint32  /* PRQA S 0841 */ /* MD_Can_HL_UndefTypes */
#  undef vsint32  /* PRQA S 0841 */ /* MD_Can_HL_UndefTypes */
# endif
#endif

/*!
 * \exclusivearea CAN_EXCLUSIVE_AREA_1
 * Ensures consistency while modifying the interrupt counter and CAN interrupt lock registers.
 * \protects canCanInterruptCounter, CAN interrupt registers
 * \usedin Can_EnableControllerInterrupts, Can_DisableControllerInterrupts
 * \exclude All functions provided by Can.
 * \length SHORT The interrupt registers and a counter variable are modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_2
 * Ensures consistency while modifying the TX mailbox states and lock registers.
 * \protects Can_ActiveSendState, CAN mailbox registers
 * \usedin Can_Write
 * \exclude Can_Write, Can_Mainfunction_Write, Can TX Interrupt
 * \length MEDIUM Multiplexed TX and cancellation handling. Cancellation handling by CAN Interface triggered. CAN TX mailbox registers and semaphore for locked mailbox modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_3
 * Ensures consistency while modifying the TX mailbox states and lock registers in case of cancellation or generic confirmation used.
 * \protects Can_ActiveSendState, CAN mailbox registers
 * \usedin Can_Mainfunction_Write, Can TX Interrupt
 * \exclude Can_Write, Can_Mainfunction_Write, Can TX Interrupt
 * \length MEDIUM Confirmation TX and cancellation handling. Cancellation handling by CAN Interface triggered. CAN TX mailbox registers and states modified.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_4
 * Ensures consistency of RX Queue.
 * \protects RX Queue counter and data
 * \usedin Can_Mainfunction_Read, Can RX Interrupt
 * \exclude Can_Mainfunction_Read, Can RX Interrupt
 * \length SHORT Modify queue counter and copy data to queue.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_5
 * Ensures atomic wakeup mode transition. Do not use CAN interrupt locks because CAN interrupt status may be changed within.
 * \protects wakeup transition
 * \usedin Can_Mainfunction_Wakeup
 * \exclude Can_SetControllerMode, Can BusOff Interrupt, Can Wakeup, Can_Mainfunction_Wakeup.
 * \length MEDIUM wakeup mode transition will be performed.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_6
 * Ensures atomic mode transition.
 * \protects mode transition
 * \usedin Can_Mainfunction_Mode, Can_SetControllerMode, Can_MainFunction_BusOff, Can BusOff Interrupt
 * \exclude Can_Mainfunction_Mode, Can_SetControllerMode, Can_MainFunction_BusOff, Can BusOff Interrupt, Can_Mainfunction_Wakeup.
 * \length MEDIUM mode transition will be performed.
 * \endexclusivearea
 *
 * \exclusivearea CAN_EXCLUSIVE_AREA_7
 * Ensures consistency of TX HW FIFO.
 * \protects TX FIFO counter and data
 * \usedin Can_Mainfunction_Write, Can TX Interrupt
 * \exclude Can_Mainfunction_Write, Can TX Interrupt
 * \length SHORT Modify queue counter and copy data to queue.
 * \endexclusivearea
 */

#endif /* end file */
/*  STOPSINGLE_OF_MULTIPLE_COMMENT  */

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


