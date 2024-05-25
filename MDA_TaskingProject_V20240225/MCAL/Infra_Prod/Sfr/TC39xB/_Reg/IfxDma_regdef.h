/**
 * \file IfxDma_regdef.h
 * \brief
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 * Version: TC39XB_UM_V1.0.0.R0
 * Specification: TC3xx User Manual V1.0.0
 * MAY BE CHANGED BY USER [yes/no]: No
 *
 *                                 IMPORTANT NOTICE
 *
 *
 * Infineon Technologies AG (Infineon) is supplying this file for use
 * exclusively with Infineon's microcontroller products. This file can be freely
 * distributed within development tools that are supporting such microcontroller
 * products.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * INFINEON SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 * \defgroup IfxSfr_Dma_Registers Dma Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Dma_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Dma_Registers
 * 
 * \defgroup IfxSfr_Dma_Registers_union Register unions
 * \ingroup IfxSfr_Dma_Registers
 * 
 * \defgroup IfxSfr_Dma_Registers_struct Memory map
 * \ingroup IfxSfr_Dma_Registers
 */
#ifndef IFXDMA_REGDEF_H
#define IFXDMA_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Dma_Registers_Bitfields
 * \{  */
/** \brief RP ${r} Access Enable Register 0 */
typedef struct _Ifx_DMA_ACCEN_ACCENR0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID q - ENq (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID q - ENq (rw) */
} Ifx_DMA_ACCEN_ACCENR0_Bits;

/** \brief RP ${r} Access Enable Register 1 */
typedef struct _Ifx_DMA_ACCEN_ACCENR1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_DMA_ACCEN_ACCENR1_Bits;

/** \brief DMARAM Channel ${c} Address and Interrupt Control Register */
typedef struct _Ifx_DMA_CH_ADICR_Bits
{
    Ifx_UReg_32Bit SMF:3;             /**< \brief [2:0] Source Address Modification Factor - SMF (rwh) */
    Ifx_UReg_32Bit INCS:1;            /**< \brief [3:3] Increment of Source Address - INCS (rwh) */
    Ifx_UReg_32Bit DMF:3;             /**< \brief [6:4] Destination Address Modification Factor - DMF (rwh) */
    Ifx_UReg_32Bit INCD:1;            /**< \brief [7:7] Increment of Destination Address - INCD (rwh) */
    Ifx_UReg_32Bit CBLS:4;            /**< \brief [11:8] Circular Buffer Length Source - CBLS (rw) */
    Ifx_UReg_32Bit CBLD:4;            /**< \brief [15:12] Circular Buffer Length Destination - CBLD (rw) */
    Ifx_UReg_32Bit SHCT:4;            /**< \brief [19:16] Shadow Control - SHCT (rwh) */
    Ifx_UReg_32Bit SCBE:1;            /**< \brief [20:20] Source Circular Buffer Enable - SCBE (rwh) */
    Ifx_UReg_32Bit DCBE:1;            /**< \brief [21:21] Destination Circular Buffer Enable - DCBE (rwh) */
    Ifx_UReg_32Bit STAMP:1;           /**< \brief [22:22] Time Stamp - STAMP (rwh) */
    Ifx_UReg_32Bit reserved_23:1;     /**< \brief [23:23] \internal Reserved */
    Ifx_UReg_32Bit WRPSE:1;           /**< \brief [24:24] Wrap Source Enable - WRPSE (rwh) */
    Ifx_UReg_32Bit WRPDE:1;           /**< \brief [25:25] Wrap Destination Enable - WRPDE (rwh) */
    Ifx_UReg_32Bit INTCT:2;           /**< \brief [27:26] Interrupt Control - INTCT (rwh) */
    Ifx_UReg_32Bit IRDV:4;            /**< \brief [31:28] Interrupt Raise Detect Value - IRDV (rwh) */
} Ifx_DMA_CH_ADICR_Bits;

/** \brief DMARAM Channel ${c} Configuration Register */
typedef struct _Ifx_DMA_CH_CHCFGR_Bits
{
    Ifx_UReg_32Bit TREL:14;           /**< \brief [13:0] Transfer Reload Value - TREL (rwh) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit BLKM:3;            /**< \brief [18:16] Block Mode - BLKM (rwh) */
    Ifx_UReg_32Bit RROAT:1;           /**< \brief [19:19] Reset Request Only After Transaction - RROAT (rwh) */
    Ifx_UReg_32Bit CHMODE:1;          /**< \brief [20:20] Channel Operation Mode - CHMODE (rwh) */
    Ifx_UReg_32Bit CHDW:3;            /**< \brief [23:21] Channel Data Width - CHDW (rwh) */
    Ifx_UReg_32Bit PATSEL:3;          /**< \brief [26:24] Pattern Select - PATSEL (rwh) */
    Ifx_UReg_32Bit SWAP:1;            /**< \brief [27:27] Swap Data CRC Byte Order - SWAP (rw) */
    Ifx_UReg_32Bit PRSEL:1;           /**< \brief [28:28] Peripheral Request Select - PRSEL (rwh) */
    Ifx_UReg_32Bit reserved_29:3;     /**< \brief [31:29] \internal Reserved */
} Ifx_DMA_CH_CHCFGR_Bits;

/** \brief DMARAM Channel ${c} Control and Status Register */
typedef struct _Ifx_DMA_CH_CHCSR_Bits
{
    Ifx_UReg_32Bit TCOUNT:14;         /**< \brief [13:0] Transfer Count - TCOUNT (rh) */
    Ifx_UReg_32Bit reserved_14:1;     /**< \brief [14:14] \internal Reserved */
    Ifx_UReg_32Bit LXO:1;             /**< \brief [15:15] Old Value of Pattern Detection - LXO (rh) */
    Ifx_UReg_32Bit WRPS:1;            /**< \brief [16:16] Wrap Source Buffer - WRPS (rh) */
    Ifx_UReg_32Bit WRPD:1;            /**< \brief [17:17] Wrap Destination Buffer - WRPD (rh) */
    Ifx_UReg_32Bit ICH:1;             /**< \brief [18:18] Interrupt from Channel - ICH (rh) */
    Ifx_UReg_32Bit IPM:1;             /**< \brief [19:19] Pattern Detection from Channel - IPM (rh) */
    Ifx_UReg_32Bit reserved_20:2;     /**< \brief [21:20] \internal Reserved */
    Ifx_UReg_32Bit BUFFER:1;          /**< \brief [22:22] DMA Double Buffering Active Buffer - BUFFER (rh) */
    Ifx_UReg_32Bit FROZEN:1;          /**< \brief [23:23] DMA Double Buffering Frozen Buffer - FROZEN (rwh) */
    Ifx_UReg_32Bit SWB:1;             /**< \brief [24:24] DMA Double Buffering Switch Buffer - SWB (w) */
    Ifx_UReg_32Bit CWRP:1;            /**< \brief [25:25] Clear Wrap Buffer Interrupt - CWRP (w) */
    Ifx_UReg_32Bit CICH:1;            /**< \brief [26:26] Clear Interrupt for DMA Channel - CICH (w) */
    Ifx_UReg_32Bit SIT:1;             /**< \brief [27:27] Set Interrupt Trigger for DMA Channel - SIT (w) */
    Ifx_UReg_32Bit reserved_28:3;     /**< \brief [30:28] \internal Reserved */
    Ifx_UReg_32Bit SCH:1;             /**< \brief [31:31] Set Transaction Request - SCH (w) */
} Ifx_DMA_CH_CHCSR_Bits;

/** \brief DMARAM Channel ${c} Destination Address Register */
typedef struct _Ifx_DMA_CH_DADR_Bits
{
    Ifx_UReg_32Bit DADR:32;           /**< \brief [31:0] Destination Address - DADR (rwh) */
} Ifx_DMA_CH_DADR_Bits;

/** \brief DMARAM Channel ${c} Read Data CRC Register */
typedef struct _Ifx_DMA_CH_RDCRCR_Bits
{
    Ifx_UReg_32Bit RDCRC:32;          /**< \brief [31:0] Read Data CRC - RDCRC (rwh) */
} Ifx_DMA_CH_RDCRCR_Bits;

/** \brief DMARAM Channel ${c} Source Address Register */
typedef struct _Ifx_DMA_CH_SADR_Bits
{
    Ifx_UReg_32Bit SADR:32;           /**< \brief [31:0] Source Address - SADR (rwh) */
} Ifx_DMA_CH_SADR_Bits;

/** \brief DMARAM Channel ${c} Source and Destination Address CRC Register */
typedef struct _Ifx_DMA_CH_SDCRCR_Bits
{
    Ifx_UReg_32Bit SDCRC:32;          /**< \brief [31:0] Source and Destination Address CRC - SDCRC (rwh) */
} Ifx_DMA_CH_SDCRCR_Bits;

/** \brief DMARAM Channel ${c} Shadow Address Register */
typedef struct _Ifx_DMA_CH_SHADR_Bits
{
    Ifx_UReg_32Bit SHADR:32;          /**< \brief [31:0] Shadowed Address - SHADR (rwh) */
} Ifx_DMA_CH_SHADR_Bits;

/** \brief DMA Clock Control Register */
typedef struct _Ifx_DMA_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_DMA_CLC_Bits;

/** \brief RP ${r} Error Interrupt Set Register */
typedef struct _Ifx_DMA_ERRINTR_Bits
{
    Ifx_UReg_32Bit SIT:1;             /**< \brief [0:0] Set Error Interrupt Service Request - SIT (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_DMA_ERRINTR_Bits;

/** \brief DMA Channel ${c} Resource Partition Register */
typedef struct _Ifx_DMA_HRR_Bits
{
    Ifx_UReg_32Bit HRP:2;             /**< \brief [1:0] DMA Channel Resource Partition - HRP (rw) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_DMA_HRR_Bits;

/** \brief DMA Identification Register */
typedef struct _Ifx_DMA_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number Value - MOD_NUMBER (r) */
} Ifx_DMA_ID_Bits;

/** \brief ME ${m} Channel Address and Interrupt Control Register */
typedef struct _Ifx_DMA_ME_ADICR_Bits
{
    Ifx_UReg_32Bit SMF:3;             /**< \brief [2:0] Source Address Modification Factor - SMF (rh) */
    Ifx_UReg_32Bit INCS:1;            /**< \brief [3:3] Increment of Source Address - INCS (rh) */
    Ifx_UReg_32Bit DMF:3;             /**< \brief [6:4] Destination Address Modification Factor - DMF (rh) */
    Ifx_UReg_32Bit INCD:1;            /**< \brief [7:7] Increment of Destination Address - INCD (rh) */
    Ifx_UReg_32Bit CBLS:4;            /**< \brief [11:8] Circular Buffer Length Source - CBLS (rh) */
    Ifx_UReg_32Bit CBLD:4;            /**< \brief [15:12] Circular Buffer Length Destination - CBLD (rh) */
    Ifx_UReg_32Bit SHCT:4;            /**< \brief [19:16] Shadow Control - SHCT (rh) */
    Ifx_UReg_32Bit SCBE:1;            /**< \brief [20:20] Source Circular Buffer Enable - SCBE (rh) */
    Ifx_UReg_32Bit DCBE:1;            /**< \brief [21:21] Destination Circular Buffer Enable - DCBE (rh) */
    Ifx_UReg_32Bit STAMP:1;           /**< \brief [22:22] Time Stamp - STAMP (rh) */
    Ifx_UReg_32Bit reserved_23:1;     /**< \brief [23:23] \internal Reserved */
    Ifx_UReg_32Bit WRPSE:1;           /**< \brief [24:24] Wrap Source Enable - WRPSE (rh) */
    Ifx_UReg_32Bit WRPDE:1;           /**< \brief [25:25] Wrap Destination Enable - WRPDE (rh) */
    Ifx_UReg_32Bit INTCT:2;           /**< \brief [27:26] Interrupt Control - INTCT (rh) */
    Ifx_UReg_32Bit IRDV:4;            /**< \brief [31:28] Interrupt Raise Detect Value - IRDV (rh) */
} Ifx_DMA_ME_ADICR_Bits;

/** \brief ME ${m} Channel Control Register */
typedef struct _Ifx_DMA_ME_CHCR_Bits
{
    Ifx_UReg_32Bit TREL:14;           /**< \brief [13:0] Transfer Reload Value - TREL (rh) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit BLKM:3;            /**< \brief [18:16] Block Mode - BLKM (rh) */
    Ifx_UReg_32Bit RROAT:1;           /**< \brief [19:19] Reset Request Only After Transaction - RROAT (rh) */
    Ifx_UReg_32Bit CHMODE:1;          /**< \brief [20:20] Channel Operation Mode - CHMODE (rh) */
    Ifx_UReg_32Bit CHDW:3;            /**< \brief [23:21] Channel Data Width - CHDW (rh) */
    Ifx_UReg_32Bit PATSEL:3;          /**< \brief [26:24] Pattern Select - PATSEL (rh) */
    Ifx_UReg_32Bit SWAP:1;            /**< \brief [27:27] Swap Data CRC byte order - SWAP (rh) */
    Ifx_UReg_32Bit PRSEL:1;           /**< \brief [28:28] Peripheral Request Select - PRSEL (rh) */
    Ifx_UReg_32Bit reserved_29:3;     /**< \brief [31:29] \internal Reserved */
} Ifx_DMA_ME_CHCR_Bits;

/** \brief ME ${m} Channel Status Register */
typedef struct _Ifx_DMA_ME_CHSR_Bits
{
    Ifx_UReg_32Bit TCOUNT:14;         /**< \brief [13:0] Transfer Count Status - TCOUNT (rh) */
    Ifx_UReg_32Bit reserved_14:1;     /**< \brief [14:14] \internal Reserved */
    Ifx_UReg_32Bit LXO:1;             /**< \brief [15:15] Old Value of Pattern Detection - LXO (rh) */
    Ifx_UReg_32Bit WRPS:1;            /**< \brief [16:16] Wrap Source Buffer - WRPS (rh) */
    Ifx_UReg_32Bit WRPD:1;            /**< \brief [17:17] Wrap Destination Buffer - WRPD (rh) */
    Ifx_UReg_32Bit ICH:1;             /**< \brief [18:18] Interrupt from Channel - ICH (rh) */
    Ifx_UReg_32Bit IPM:1;             /**< \brief [19:19] Pattern Detection from Channel - IPM (rh) */
    Ifx_UReg_32Bit reserved_20:2;     /**< \brief [21:20] \internal Reserved */
    Ifx_UReg_32Bit BUFFER:1;          /**< \brief [22:22] DMA Double Buffering Active Buffer - BUFFER (rh) */
    Ifx_UReg_32Bit FROZEN:1;          /**< \brief [23:23] DMA Double Buffering Frozen Buffer - FROZEN (rh) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_DMA_ME_CHSR_Bits;

/** \brief ME ${m} Clear Error Register */
typedef struct _Ifx_DMA_ME_CLRE_Bits
{
    Ifx_UReg_32Bit reserved_0:16;     /**< \brief [15:0] \internal Reserved */
    Ifx_UReg_32Bit CSER:1;            /**< \brief [16:16] Clear ME Source Error - CSER (w) */
    Ifx_UReg_32Bit CDER:1;            /**< \brief [17:17] Clear ME Destination Error - CDER (w) */
    Ifx_UReg_32Bit reserved_18:2;     /**< \brief [19:18] \internal Reserved */
    Ifx_UReg_32Bit CSPBER:1;          /**< \brief [20:20] Clear SPB Error - CSPBER (w) */
    Ifx_UReg_32Bit CSRIER:1;          /**< \brief [21:21] Clear SRI Error - CSRIER (w) */
    Ifx_UReg_32Bit reserved_22:2;     /**< \brief [23:22] \internal Reserved */
    Ifx_UReg_32Bit CRAMER:1;          /**< \brief [24:24] Clear RAM Error - CRAMER (w) */
    Ifx_UReg_32Bit CSLLER:1;          /**< \brief [25:25] Clear SLL Error - CSLLER (w) */
    Ifx_UReg_32Bit CDLLER:1;          /**< \brief [26:26] Clear DLL Error - CDLLER (w) */
    Ifx_UReg_32Bit reserved_27:5;     /**< \brief [31:27] \internal Reserved */
} Ifx_DMA_ME_CLRE_Bits;

/** \brief ME ${m} Channel Destination Address Register */
typedef struct _Ifx_DMA_ME_DADR_Bits
{
    Ifx_UReg_32Bit DADR:32;           /**< \brief [31:0] Destination Address - DADR (rh) */
} Ifx_DMA_ME_DADR_Bits;

/** \brief ME ${m} Enable Error Register */
typedef struct _Ifx_DMA_ME_EER_Bits
{
    Ifx_UReg_32Bit reserved_0:16;     /**< \brief [15:0] \internal Reserved */
    Ifx_UReg_32Bit ESER:1;            /**< \brief [16:16] Enable ME Source Error - ESER (rw) */
    Ifx_UReg_32Bit EDER:1;            /**< \brief [17:17] Enable ME Destination Error - EDER (rw) */
    Ifx_UReg_32Bit reserved_18:8;     /**< \brief [25:18] \internal Reserved */
    Ifx_UReg_32Bit ELER:1;            /**< \brief [26:26] Enable ME DMA Linked List Error - ELER (rw) */
    Ifx_UReg_32Bit reserved_27:5;     /**< \brief [31:27] \internal Reserved */
} Ifx_DMA_ME_EER_Bits;

/** \brief ME ${m} Error Status Register */
typedef struct _Ifx_DMA_ME_ERRSR_Bits
{
    Ifx_UReg_32Bit LEC:7;             /**< \brief [6:0] ME Last Error Channel - LEC (rh) */
    Ifx_UReg_32Bit reserved_7:9;      /**< \brief [15:7] \internal Reserved */
    Ifx_UReg_32Bit SER:1;             /**< \brief [16:16] ME Source Error - SER (rh) */
    Ifx_UReg_32Bit DER:1;             /**< \brief [17:17] ME Destination Error - DER (rh) */
    Ifx_UReg_32Bit reserved_18:2;     /**< \brief [19:18] \internal Reserved */
    Ifx_UReg_32Bit SPBER:1;           /**< \brief [20:20] ME SPB Bus Error - SPBER (rh) */
    Ifx_UReg_32Bit SRIER:1;           /**< \brief [21:21] ME SRI Bus Error - SRIER (rh) */
    Ifx_UReg_32Bit reserved_22:2;     /**< \brief [23:22] \internal Reserved */
    Ifx_UReg_32Bit RAMER:1;           /**< \brief [24:24] ME RAM Error - RAMER (rh) */
    Ifx_UReg_32Bit SLLER:1;           /**< \brief [25:25] ME Safe Linked List Error - SLLER (rh) */
    Ifx_UReg_32Bit DLLER:1;           /**< \brief [26:26] ME DMA Linked List Error - DLLER (rh) */
    Ifx_UReg_32Bit reserved_27:5;     /**< \brief [31:27] \internal Reserved */
} Ifx_DMA_ME_ERRSR_Bits;

/** \brief ME ${m} Read Register 0 */
typedef struct _Ifx_DMA_ME_R0_Bits
{
    Ifx_UReg_32Bit RD00:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD00 (rh) */
    Ifx_UReg_32Bit RD01:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD01 (rh) */
    Ifx_UReg_32Bit RD02:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD02 (rh) */
    Ifx_UReg_32Bit RD03:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD03 (rh) */
} Ifx_DMA_ME_R0_Bits;

/** \brief ME ${m} Read Register 1 */
typedef struct _Ifx_DMA_ME_R1_Bits
{
    Ifx_UReg_32Bit RD10:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD10 (rh) */
    Ifx_UReg_32Bit RD11:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD11 (rh) */
    Ifx_UReg_32Bit RD12:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD12 (rh) */
    Ifx_UReg_32Bit RD13:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD13 (rh) */
} Ifx_DMA_ME_R1_Bits;

/** \brief ME ${m} Read Register 2 */
typedef struct _Ifx_DMA_ME_R2_Bits
{
    Ifx_UReg_32Bit RD20:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD20 (rh) */
    Ifx_UReg_32Bit RD21:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD21 (rh) */
    Ifx_UReg_32Bit RD22:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD22 (rh) */
    Ifx_UReg_32Bit RD23:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD23 (rh) */
} Ifx_DMA_ME_R2_Bits;

/** \brief ME ${m} Read Register 3 */
typedef struct _Ifx_DMA_ME_R3_Bits
{
    Ifx_UReg_32Bit RD30:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD30 (rh) */
    Ifx_UReg_32Bit RD31:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD31 (rh) */
    Ifx_UReg_32Bit RD32:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD32 (rh) */
    Ifx_UReg_32Bit RD33:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD33 (rh) */
} Ifx_DMA_ME_R3_Bits;

/** \brief ME ${m} Read Register 4 */
typedef struct _Ifx_DMA_ME_R4_Bits
{
    Ifx_UReg_32Bit RD40:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD40 (rh) */
    Ifx_UReg_32Bit RD41:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD41 (rh) */
    Ifx_UReg_32Bit RD42:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD42 (rh) */
    Ifx_UReg_32Bit RD43:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD43 (rh) */
} Ifx_DMA_ME_R4_Bits;

/** \brief ME ${m} Read Register 5 */
typedef struct _Ifx_DMA_ME_R5_Bits
{
    Ifx_UReg_32Bit RD50:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD50 (rh) */
    Ifx_UReg_32Bit RD51:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD51 (rh) */
    Ifx_UReg_32Bit RD52:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD52 (rh) */
    Ifx_UReg_32Bit RD53:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD53 (rh) */
} Ifx_DMA_ME_R5_Bits;

/** \brief ME ${m} Read Register 6 */
typedef struct _Ifx_DMA_ME_R6_Bits
{
    Ifx_UReg_32Bit RD60:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD60 (rh) */
    Ifx_UReg_32Bit RD61:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD61 (rh) */
    Ifx_UReg_32Bit RD62:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD62 (rh) */
    Ifx_UReg_32Bit RD63:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD63 (rh) */
} Ifx_DMA_ME_R6_Bits;

/** \brief ME ${m} Read Register 7 */
typedef struct _Ifx_DMA_ME_R7_Bits
{
    Ifx_UReg_32Bit RD70:8;            /**< \brief [7:0] DMA Read Move Data Byte - RD70 (rh) */
    Ifx_UReg_32Bit RD71:8;            /**< \brief [15:8] DMA Read Move Data Byte - RD71 (rh) */
    Ifx_UReg_32Bit RD72:8;            /**< \brief [23:16] DMA Read Move Data Byte - RD72 (rh) */
    Ifx_UReg_32Bit RD73:8;            /**< \brief [31:24] DMA Read Move Data Byte - RD73 (rh) */
} Ifx_DMA_ME_R7_Bits;

/** \brief ME ${m} Channel Read Data CRC Register */
typedef struct _Ifx_DMA_ME_RDCRC_Bits
{
    Ifx_UReg_32Bit RDCRC:32;          /**< \brief [31:0] Read Data CRC - RDCRC (rh) */
} Ifx_DMA_ME_RDCRC_Bits;

/** \brief ME ${m} Channel Source Address Register */
typedef struct _Ifx_DMA_ME_SADR_Bits
{
    Ifx_UReg_32Bit SADR:32;           /**< \brief [31:0] Source Address - SADR (rh) */
} Ifx_DMA_ME_SADR_Bits;

/** \brief ME ${m} Channel Source and Destination Address CRC Register */
typedef struct _Ifx_DMA_ME_SDCRC_Bits
{
    Ifx_UReg_32Bit SDCRC:32;          /**< \brief [31:0] Source and Destination Address CRC - SDCRC (rh) */
} Ifx_DMA_ME_SDCRC_Bits;

/** \brief ME ${m} Channel Shadow Address Register */
typedef struct _Ifx_DMA_ME_SHADR_Bits
{
    Ifx_UReg_32Bit SHADR:32;          /**< \brief [31:0] Shadowed Address - SHADR (rh) */
} Ifx_DMA_ME_SHADR_Bits;

/** \brief ME ${m} Status Register */
typedef struct _Ifx_DMA_ME_SR_Bits
{
    Ifx_UReg_32Bit RS:1;              /**< \brief [0:0] ME Read Status - RS (rh) */
    Ifx_UReg_32Bit reserved_1:3;      /**< \brief [3:1] \internal Reserved */
    Ifx_UReg_32Bit WS:1;              /**< \brief [4:4] ME Write Status - WS (rh) */
    Ifx_UReg_32Bit reserved_5:11;     /**< \brief [15:5] \internal Reserved */
    Ifx_UReg_32Bit CH:7;              /**< \brief [22:16] ME Active Channel - CH (rh) */
    Ifx_UReg_32Bit reserved_23:9;     /**< \brief [31:23] \internal Reserved */
} Ifx_DMA_ME_SR_Bits;

/** \brief RP ${r} Mode Register */
typedef struct _Ifx_DMA_MODE_Bits
{
    Ifx_UReg_32Bit MODE:1;            /**< \brief [0:0] Resource Partition Supervisor Mode - MODE (rw) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_DMA_MODE_Bits;

/** \brief DMA OCDS Trigger Set Select */
typedef struct _Ifx_DMA_OTSS_Bits
{
    Ifx_UReg_32Bit TGS:4;             /**< \brief [3:0] Trigger Set for OTGB0 or OTGB1 - TGS (rw) */
    Ifx_UReg_32Bit reserved_4:3;      /**< \brief [6:4] \internal Reserved */
    Ifx_UReg_32Bit BS:1;              /**< \brief [7:7] OTGB0 or OTGB1 Bus Select - BS (rw) */
    Ifx_UReg_32Bit reserved_8:24;     /**< \brief [31:8] \internal Reserved */
} Ifx_DMA_OTSS_Bits;

/** \brief DMA Pattern Read Register 0 */
typedef struct _Ifx_DMA_PRR0_Bits
{
    Ifx_UReg_32Bit PAT00:8;           /**< \brief [7:0] Pattern Data Byte - PAT00 (rw) */
    Ifx_UReg_32Bit PAT01:8;           /**< \brief [15:8] Pattern Data Byte - PAT01 (rw) */
    Ifx_UReg_32Bit PAT02:8;           /**< \brief [23:16] Pattern Data Byte - PAT02 (rw) */
    Ifx_UReg_32Bit PAT03:8;           /**< \brief [31:24] Pattern Data Byte - PAT03 (rw) */
} Ifx_DMA_PRR0_Bits;

/** \brief DMA Pattern Read Register 1 */
typedef struct _Ifx_DMA_PRR1_Bits
{
    Ifx_UReg_32Bit PAT10:8;           /**< \brief [7:0] Pattern Data Byte - PAT10 (rw) */
    Ifx_UReg_32Bit PAT11:8;           /**< \brief [15:8] Pattern Data Byte - PAT11 (rw) */
    Ifx_UReg_32Bit PAT12:8;           /**< \brief [23:16] Pattern Data Byte - PAT12 (rw) */
    Ifx_UReg_32Bit PAT13:8;           /**< \brief [31:24] Pattern Data Byte - PAT13 (rw) */
} Ifx_DMA_PRR1_Bits;

/** \brief DMA Channel ${c} Suspend Acknowledge Register */
typedef struct _Ifx_DMA_SUSACR_Bits
{
    Ifx_UReg_32Bit SUSAC:1;           /**< \brief [0:0] DMA Channel Suspend State or Frozen State Active for DMA Channel - SUSAC (rh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_DMA_SUSACR_Bits;

/** \brief DMA Channel ${c} Suspend Enable Register */
typedef struct _Ifx_DMA_SUSENR_Bits
{
    Ifx_UReg_32Bit SUSEN:1;           /**< \brief [0:0] Channel Suspend Enable for DMA Channel - SUSEN (rw) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_DMA_SUSENR_Bits;

/** \brief DMA Time Register */
typedef struct _Ifx_DMA_TIME_Bits
{
    Ifx_UReg_32Bit COUNT:32;          /**< \brief [31:0] Timestamp Count - COUNT (r) */
} Ifx_DMA_TIME_Bits;

/** \brief DMA Channel ${c} Transaction State Register */
typedef struct _Ifx_DMA_TSR_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] DMA Channel Reset - RST (rwh) */
    Ifx_UReg_32Bit HTRE:1;            /**< \brief [1:1] DMA Channel Hardware Request Enable - HTRE (rh) */
    Ifx_UReg_32Bit TRL:1;             /**< \brief [2:2] DMA Channel Transaction/Transfer Request Lost - TRL (rh) */
    Ifx_UReg_32Bit CH:1;              /**< \brief [3:3] DMA Channel Transaction Request State - CH (rh) */
    Ifx_UReg_32Bit ETRL:1;            /**< \brief [4:4] Enable DMA Channel Transaction/Transfer Request Lost Interrupt - ETRL (rw) */
    Ifx_UReg_32Bit reserved_5:3;      /**< \brief [7:5] \internal Reserved */
    Ifx_UReg_32Bit HLTREQ:1;          /**< \brief [8:8] DMA Channel Halt Request - HLTREQ (rwh) */
    Ifx_UReg_32Bit HLTACK:1;          /**< \brief [9:9] DMA Channel Halt Acknowledge - HLTACK (rh) */
    Ifx_UReg_32Bit reserved_10:6;     /**< \brief [15:10] \internal Reserved */
    Ifx_UReg_32Bit ECH:1;             /**< \brief [16:16] Enable DMA Channel Hardware Transaction Request - ECH (w) */
    Ifx_UReg_32Bit DCH:1;             /**< \brief [17:17] Disable DMA Channel Hardware Transaction Request - DCH (w) */
    Ifx_UReg_32Bit CTL:1;             /**< \brief [18:18] Clear DMA Channel Transaction/Transfer Request Lost - CTL (w) */
    Ifx_UReg_32Bit reserved_19:5;     /**< \brief [23:19] \internal Reserved */
    Ifx_UReg_32Bit HLTCLR:1;          /**< \brief [24:24] Clear DMA Channel Halt Request and Acknowledge - HLTCLR (w) */
    Ifx_UReg_32Bit reserved_25:7;     /**< \brief [31:25] \internal Reserved */
} Ifx_DMA_TSR_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_dma_Registers_union
 * \{   */
/** \brief RP ${r} Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ACCEN_ACCENR0_Bits B;     /**< \brief Bitfield access */
} Ifx_DMA_ACCEN_ACCENR0;

/** \brief RP ${r} Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ACCEN_ACCENR1_Bits B;     /**< \brief Bitfield access */
} Ifx_DMA_ACCEN_ACCENR1;

/** \brief DMARAM Channel ${c} Address and Interrupt Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_ADICR_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_CH_ADICR;

/** \brief DMARAM Channel ${c} Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_CHCFGR_Bits B;         /**< \brief Bitfield access */
} Ifx_DMA_CH_CHCFGR;

/** \brief DMARAM Channel ${c} Control and Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_CHCSR_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_CH_CHCSR;

/** \brief DMARAM Channel ${c} Destination Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_DADR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_CH_DADR;

/** \brief DMARAM Channel ${c} Read Data CRC Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_RDCRCR_Bits B;         /**< \brief Bitfield access */
} Ifx_DMA_CH_RDCRCR;

/** \brief DMARAM Channel ${c} Source Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_SADR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_CH_SADR;

/** \brief DMARAM Channel ${c} Source and Destination Address CRC Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_SDCRCR_Bits B;         /**< \brief Bitfield access */
} Ifx_DMA_CH_SDCRCR;

/** \brief DMARAM Channel ${c} Shadow Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CH_SHADR_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_CH_SHADR;

/** \brief DMA Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_CLC_Bits B;               /**< \brief Bitfield access */
} Ifx_DMA_CLC;

/** \brief RP ${r} Error Interrupt Set Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ERRINTR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_ERRINTR;

/** \brief DMA Channel ${c} Resource Partition Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_HRR_Bits B;               /**< \brief Bitfield access */
} Ifx_DMA_HRR;

/** \brief DMA Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ID_Bits B;                /**< \brief Bitfield access */
} Ifx_DMA_ID;

/** \brief ME ${m} Channel Address and Interrupt Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_ADICR_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_ME_ADICR;

/** \brief ME ${m} Channel Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_CHCR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_ME_CHCR;

/** \brief ME ${m} Channel Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_CHSR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_ME_CHSR;

/** \brief ME ${m} Clear Error Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_CLRE_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_ME_CLRE;

/** \brief ME ${m} Channel Destination Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_DADR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_ME_DADR;

/** \brief ME ${m} Enable Error Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_EER_Bits B;            /**< \brief Bitfield access */
} Ifx_DMA_ME_EER;

/** \brief ME ${m} Error Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_ERRSR_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_ME_ERRSR;

/** \brief ME ${m} Read Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R0_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R0;

/** \brief ME ${m} Read Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R1_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R1;

/** \brief ME ${m} Read Register 2   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R2_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R2;

/** \brief ME ${m} Read Register 3   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R3_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R3;

/** \brief ME ${m} Read Register 4   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R4_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R4;

/** \brief ME ${m} Read Register 5   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R5_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R5;

/** \brief ME ${m} Read Register 6   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R6_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R6;

/** \brief ME ${m} Read Register 7   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_R7_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_R7;

/** \brief ME ${m} Channel Read Data CRC Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_RDCRC_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_ME_RDCRC;

/** \brief ME ${m} Channel Source Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_SADR_Bits B;           /**< \brief Bitfield access */
} Ifx_DMA_ME_SADR;

/** \brief ME ${m} Channel Source and Destination Address CRC Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_SDCRC_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_ME_SDCRC;

/** \brief ME ${m} Channel Shadow Address Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_SHADR_Bits B;          /**< \brief Bitfield access */
} Ifx_DMA_ME_SHADR;

/** \brief ME ${m} Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_ME_SR_Bits B;             /**< \brief Bitfield access */
} Ifx_DMA_ME_SR;

/** \brief RP ${r} Mode Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_MODE_Bits B;              /**< \brief Bitfield access */
} Ifx_DMA_MODE;

/** \brief DMA OCDS Trigger Set Select   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_OTSS_Bits B;              /**< \brief Bitfield access */
} Ifx_DMA_OTSS;

/** \brief DMA Pattern Read Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_PRR0_Bits B;              /**< \brief Bitfield access */
} Ifx_DMA_PRR0;

/** \brief DMA Pattern Read Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_PRR1_Bits B;              /**< \brief Bitfield access */
} Ifx_DMA_PRR1;

/** \brief DMA Channel ${c} Suspend Acknowledge Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_SUSACR_Bits B;            /**< \brief Bitfield access */
} Ifx_DMA_SUSACR;

/** \brief DMA Channel ${c} Suspend Enable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_SUSENR_Bits B;            /**< \brief Bitfield access */
} Ifx_DMA_SUSENR;

/** \brief DMA Time Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_TIME_Bits B;              /**< \brief Bitfield access */
} Ifx_DMA_TIME;

/** \brief DMA Channel ${c} Transaction State Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_DMA_TSR_Bits B;               /**< \brief Bitfield access */
} Ifx_DMA_TSR;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Dma_ACCEN_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief ACCEN object */
typedef volatile struct _Ifx_DMA_ACCEN
{
       Ifx_DMA_ACCEN_ACCENR0               ACCENR0;                /**< \brief 0, RP ${r} Access Enable Register 0*/
       Ifx_DMA_ACCEN_ACCENR1               ACCENR1;                /**< \brief 4, RP ${r} Access Enable Register 1*/
} Ifx_DMA_ACCEN;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Dma_ME_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief ME object */
typedef volatile struct _Ifx_DMA_ME
{
       Ifx_DMA_ME_EER                      EER;                    /**< \brief 0, ME ${m} Enable Error Register*/
       Ifx_DMA_ME_ERRSR                    ERRSR;                  /**< \brief 4, ME ${m} Error Status Register*/
       Ifx_DMA_ME_CLRE                     CLRE;                   /**< \brief 8, ME ${m} Clear Error Register*/
       Ifx_UReg_8Bit                       reserved_C[4];          /**< \brief C, \internal Reserved */
       Ifx_DMA_ME_SR                       SR;                     /**< \brief 10, ME ${m} Status Register*/
       Ifx_UReg_8Bit                       reserved_14[12];        /**< \brief 14, \internal Reserved */
       Ifx_DMA_ME_R0                       R0;                     /**< \brief 20, ME ${m} Read Register 0*/
       Ifx_DMA_ME_R1                       R1;                     /**< \brief 24, ME ${m} Read Register 1*/
       Ifx_DMA_ME_R2                       R2;                     /**< \brief 28, ME ${m} Read Register 2*/
       Ifx_DMA_ME_R3                       R3;                     /**< \brief 2C, ME ${m} Read Register 3*/
       Ifx_DMA_ME_R4                       R4;                     /**< \brief 30, ME ${m} Read Register 4*/
       Ifx_DMA_ME_R5                       R5;                     /**< \brief 34, ME ${m} Read Register 5*/
       Ifx_DMA_ME_R6                       R6;                     /**< \brief 38, ME ${m} Read Register 6*/
       Ifx_DMA_ME_R7                       R7;                     /**< \brief 3C, ME ${m} Read Register 7*/
       Ifx_UReg_8Bit                       reserved_40[32];        /**< \brief 40, \internal Reserved */
       Ifx_DMA_ME_RDCRC                    RDCRC;                  /**< \brief 60, ME ${m} Channel Read Data CRC Register*/
       Ifx_DMA_ME_SDCRC                    SDCRC;                  /**< \brief 64, ME ${m} Channel Source and Destination Address CRC Register*/
       Ifx_DMA_ME_SADR                     SADR;                   /**< \brief 68, ME ${m} Channel Source Address Register*/
       Ifx_DMA_ME_DADR                     DADR;                   /**< \brief 6C, ME ${m} Channel Destination Address Register*/
       Ifx_DMA_ME_ADICR                    ADICR;                  /**< \brief 70, ME ${m} Channel Address and Interrupt Control Register*/
       Ifx_DMA_ME_CHCR                     CHCR;                   /**< \brief 74, ME ${m} Channel Control Register*/
       Ifx_DMA_ME_SHADR                    SHADR;                  /**< \brief 78, ME ${m} Channel Shadow Address Register*/
       Ifx_DMA_ME_CHSR                     CHSR;                   /**< \brief 7C, ME ${m} Channel Status Register*/
} Ifx_DMA_ME;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Dma_CH_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief CH object */
typedef volatile struct _Ifx_DMA_CH
{
       Ifx_DMA_CH_RDCRCR                   RDCRCR;                 /**< \brief 0, DMARAM Channel ${c} Read Data CRC Register*/
       Ifx_DMA_CH_SDCRCR                   SDCRCR;                 /**< \brief 4, DMARAM Channel ${c} Source and Destination Address CRC Register*/
       Ifx_DMA_CH_SADR                     SADR;                   /**< \brief 8, DMARAM Channel ${c} Source Address Register*/
       Ifx_DMA_CH_DADR                     DADR;                   /**< \brief C, DMARAM Channel ${c} Destination Address Register*/
       Ifx_DMA_CH_ADICR                    ADICR;                  /**< \brief 10, DMARAM Channel ${c} Address and Interrupt Control Register*/
       Ifx_DMA_CH_CHCFGR                   CHCFGR;                 /**< \brief 14, DMARAM Channel ${c} Configuration Register*/
       Ifx_DMA_CH_SHADR                    SHADR;                  /**< \brief 18, DMARAM Channel ${c} Shadow Address Register*/
       Ifx_DMA_CH_CHCSR                    CHCSR;                  /**< \brief 1C, DMARAM Channel ${c} Control and Status Register*/
} Ifx_DMA_CH;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxSfr_Dma_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief DMA object */
typedef volatile struct _Ifx_DMA
{
       Ifx_DMA_CLC                         CLC;                    /**< \brief 0, DMA Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_DMA_ID                          ID;                     /**< \brief 8, DMA Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[52];         /**< \brief C, \internal Reserved */
       Ifx_DMA_ACCEN                       ACCEN[4];               /**< \brief 40, RP ${r} Access Enable Register 1*/
       Ifx_UReg_8Bit                       reserved_60[192];       /**< \brief 60, \internal Reserved */
       Ifx_DMA_ME                          ME0;                    /**< \brief 120, */
       Ifx_UReg_8Bit                       reserved_1A0[3968];     /**< \brief 1A0, \internal Reserved */
       Ifx_DMA_ME                          ME1;                    /**< \brief 1120, */
       Ifx_UReg_8Bit                       reserved_11A0[96];      /**< \brief 11A0, \internal Reserved */
       Ifx_DMA_OTSS                        OTSS;                   /**< \brief 1200, DMA OCDS Trigger Set Select*/
       Ifx_UReg_8Bit                       reserved_1204[4];       /**< \brief 1204, \internal Reserved */
       Ifx_DMA_PRR0                        PRR0;                   /**< \brief 1208, DMA Pattern Read Register 0*/
       Ifx_DMA_PRR1                        PRR1;                   /**< \brief 120C, DMA Pattern Read Register 1*/
       Ifx_DMA_TIME                        TIME;                   /**< \brief 1210, DMA Time Register*/
       Ifx_UReg_8Bit                       reserved_1214[236];     /**< \brief 1214, \internal Reserved */
       Ifx_DMA_MODE                        MODE[4];                /**< \brief 1300, RP ${r} Mode Register*/
       Ifx_UReg_8Bit                       reserved_1310[16];      /**< \brief 1310, \internal Reserved */
       Ifx_DMA_ERRINTR                     ERRINTR[4];             /**< \brief 1320, RP ${r} Error Interrupt Set Register*/
       Ifx_UReg_8Bit                       reserved_1330[1232];    /**< \brief 1330, \internal Reserved */
       Ifx_DMA_HRR                         HRR[128];               /**< \brief 1800, DMA Channel ${c} Resource Partition Register*/
       Ifx_DMA_SUSENR                      SUSENR[128];            /**< \brief 1A00, DMA Channel ${c} Suspend Enable Register*/
       Ifx_DMA_SUSACR                      SUSACR[128];            /**< \brief 1C00, DMA Channel ${c} Suspend Acknowledge Register*/
       Ifx_DMA_TSR                         TSR[128];               /**< \brief 1E00, DMA Channel ${c} Transaction State Register*/
       Ifx_DMA_CH                          CH[128];                /**< \brief 2000, DMARAM Channel ${c} Control and Status Register*/
       Ifx_UReg_8Bit                       reserved_3000[4096];    /**< \brief 3000, \internal Reserved */
} Ifx_DMA;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXDMA_REGDEF_H */
