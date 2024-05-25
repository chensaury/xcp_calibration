/**
 * \file IfxEdsadc_regdef.h
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
 * \defgroup IfxSfr_Edsadc_Registers Edsadc Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Edsadc_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Edsadc_Registers
 * 
 * \defgroup IfxSfr_Edsadc_Registers_union Register unions
 * \ingroup IfxSfr_Edsadc_Registers
 * 
 * \defgroup IfxSfr_Edsadc_Registers_struct Memory map
 * \ingroup IfxSfr_Edsadc_Registers
 */
#ifndef IFXEDSADC_REGDEF_H
#define IFXEDSADC_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Edsadc_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_EDSADC_ACCEN0_Bits
{
    Ifx_UReg_32Bit EN0:1;             /**< \brief [0:0] Access Enable for Master TAG ID 0 - EN0 (rw) */
    Ifx_UReg_32Bit EN1:1;             /**< \brief [1:1] Access Enable for Master TAG ID 1 - EN1 (rw) */
    Ifx_UReg_32Bit EN2:1;             /**< \brief [2:2] Access Enable for Master TAG ID 2 - EN2 (rw) */
    Ifx_UReg_32Bit EN3:1;             /**< \brief [3:3] Access Enable for Master TAG ID 3 - EN3 (rw) */
    Ifx_UReg_32Bit EN4:1;             /**< \brief [4:4] Access Enable for Master TAG ID 4 - EN4 (rw) */
    Ifx_UReg_32Bit EN5:1;             /**< \brief [5:5] Access Enable for Master TAG ID 5 - EN5 (rw) */
    Ifx_UReg_32Bit EN6:1;             /**< \brief [6:6] Access Enable for Master TAG ID 6 - EN6 (rw) */
    Ifx_UReg_32Bit EN7:1;             /**< \brief [7:7] Access Enable for Master TAG ID 7 - EN7 (rw) */
    Ifx_UReg_32Bit EN8:1;             /**< \brief [8:8] Access Enable for Master TAG ID 8 - EN8 (rw) */
    Ifx_UReg_32Bit EN9:1;             /**< \brief [9:9] Access Enable for Master TAG ID 9 - EN9 (rw) */
    Ifx_UReg_32Bit EN10:1;            /**< \brief [10:10] Access Enable for Master TAG ID 10 - EN10 (rw) */
    Ifx_UReg_32Bit EN11:1;            /**< \brief [11:11] Access Enable for Master TAG ID 11 - EN11 (rw) */
    Ifx_UReg_32Bit EN12:1;            /**< \brief [12:12] Access Enable for Master TAG ID 12 - EN12 (rw) */
    Ifx_UReg_32Bit EN13:1;            /**< \brief [13:13] Access Enable for Master TAG ID 13 - EN13 (rw) */
    Ifx_UReg_32Bit EN14:1;            /**< \brief [14:14] Access Enable for Master TAG ID 14 - EN14 (rw) */
    Ifx_UReg_32Bit EN15:1;            /**< \brief [15:15] Access Enable for Master TAG ID 15 - EN15 (rw) */
    Ifx_UReg_32Bit EN16:1;            /**< \brief [16:16] Access Enable for Master TAG ID 16 - EN16 (rw) */
    Ifx_UReg_32Bit EN17:1;            /**< \brief [17:17] Access Enable for Master TAG ID 17 - EN17 (rw) */
    Ifx_UReg_32Bit EN18:1;            /**< \brief [18:18] Access Enable for Master TAG ID 18 - EN18 (rw) */
    Ifx_UReg_32Bit EN19:1;            /**< \brief [19:19] Access Enable for Master TAG ID 19 - EN19 (rw) */
    Ifx_UReg_32Bit EN20:1;            /**< \brief [20:20] Access Enable for Master TAG ID 20 - EN20 (rw) */
    Ifx_UReg_32Bit EN21:1;            /**< \brief [21:21] Access Enable for Master TAG ID 21 - EN21 (rw) */
    Ifx_UReg_32Bit EN22:1;            /**< \brief [22:22] Access Enable for Master TAG ID 22 - EN22 (rw) */
    Ifx_UReg_32Bit EN23:1;            /**< \brief [23:23] Access Enable for Master TAG ID 23 - EN23 (rw) */
    Ifx_UReg_32Bit EN24:1;            /**< \brief [24:24] Access Enable for Master TAG ID 24 - EN24 (rw) */
    Ifx_UReg_32Bit EN25:1;            /**< \brief [25:25] Access Enable for Master TAG ID 25 - EN25 (rw) */
    Ifx_UReg_32Bit EN26:1;            /**< \brief [26:26] Access Enable for Master TAG ID 26 - EN26 (rw) */
    Ifx_UReg_32Bit EN27:1;            /**< \brief [27:27] Access Enable for Master TAG ID 27 - EN27 (rw) */
    Ifx_UReg_32Bit EN28:1;            /**< \brief [28:28] Access Enable for Master TAG ID 28 - EN28 (rw) */
    Ifx_UReg_32Bit EN29:1;            /**< \brief [29:29] Access Enable for Master TAG ID 29 - EN29 (rw) */
    Ifx_UReg_32Bit EN30:1;            /**< \brief [30:30] Access Enable for Master TAG ID 30 - EN30 (rw) */
    Ifx_UReg_32Bit EN31:1;            /**< \brief [31:31] Access Enable for Master TAG ID 31 - EN31 (rw) */
} Ifx_EDSADC_ACCEN0_Bits;

/** \brief Access Protection Register */
typedef struct _Ifx_EDSADC_ACCPROT_Bits
{
    Ifx_UReg_32Bit RG00:1;            /**< \brief [0:0] Register Group 0 - RG00 (rw) */
    Ifx_UReg_32Bit RG01:1;            /**< \brief [1:1] Register Group 1 - RG01 (rw) */
    Ifx_UReg_32Bit RG02:1;            /**< \brief [2:2] Register Group 2 - RG02 (rw) */
    Ifx_UReg_32Bit RG03:1;            /**< \brief [3:3] Register Group 3 - RG03 (rw) */
    Ifx_UReg_32Bit RG04:1;            /**< \brief [4:4] Register Group 4 - RG04 (rw) */
    Ifx_UReg_32Bit RG05:1;            /**< \brief [5:5] Register Group 5 - RG05 (rw) */
    Ifx_UReg_32Bit RG06:1;            /**< \brief [6:6] Register Group 6 - RG06 (rw) */
    Ifx_UReg_32Bit RG07:1;            /**< \brief [7:7] Register Group 7 - RG07 (rw) */
    Ifx_UReg_32Bit reserved_8:8;      /**< \brief [15:8] \internal Reserved */
    Ifx_UReg_32Bit RG10:1;            /**< \brief [16:16] Register Group 10 - RG10 (rw) */
    Ifx_UReg_32Bit reserved_17:14;    /**< \brief [30:17] \internal Reserved */
    Ifx_UReg_32Bit RGG:1;             /**< \brief [31:31] Register Group Global - RGG (rw) */
} Ifx_EDSADC_ACCPROT_Bits;

/** \brief Carrier Generator Configuration Register */
typedef struct _Ifx_EDSADC_CGCFG_Bits
{
    Ifx_UReg_32Bit CGMOD:2;           /**< \brief [1:0] Carrier Generator Operating Mode - CGMOD (rw) */
    Ifx_UReg_32Bit BREV:1;            /**< \brief [2:2] Bit-Reverse PWM Generation - BREV (rw) */
    Ifx_UReg_32Bit SIGPOL:1;          /**< \brief [3:3] Signal Polarity - SIGPOL (rw) */
    Ifx_UReg_32Bit DIVCG:4;           /**< \brief [7:4] Divider Factor for the PWM Pattern Signal Generator - DIVCG (rw) */
    Ifx_UReg_32Bit reserved_8:7;      /**< \brief [14:8] \internal Reserved */
    Ifx_UReg_32Bit RUN:1;             /**< \brief [15:15] Run Indicator - RUN (rh) */
    Ifx_UReg_32Bit BITCOUNT:5;        /**< \brief [20:16] Bit Counter - BITCOUNT (rh) */
    Ifx_UReg_32Bit reserved_21:3;     /**< \brief [23:21] \internal Reserved */
    Ifx_UReg_32Bit STEPCOUNT:3;       /**< \brief [26:24] Step Counter - STEPCOUNT (rh) */
    Ifx_UReg_32Bit reserved_27:1;     /**< \brief [27:27] \internal Reserved */
    Ifx_UReg_32Bit STEPS:1;           /**< \brief [28:28] Step Counter Sign - STEPS (rh) */
    Ifx_UReg_32Bit STEPD:1;           /**< \brief [29:29] Step Counter Direction - STEPD (rh) */
    Ifx_UReg_32Bit SGNCG:1;           /**< \brief [30:30] Sign Signal from Carrier Generator - SGNCG (rh) */
    Ifx_UReg_32Bit reserved_31:1;     /**< \brief [31:31] \internal Reserved */
} Ifx_EDSADC_CGCFG_Bits;

/** \brief Boundary Select Register ${x} */
typedef struct _Ifx_EDSADC_CH_BOUNDSEL_Bits
{
    Ifx_UReg_32Bit BOUNDARYL:16;      /**< \brief [15:0] Lower Boundary Value for Limit Checking - BOUNDARYL (rw) */
    Ifx_UReg_32Bit BOUNDARYU:16;      /**< \brief [31:16] Upper Boundary Value for Limit Checking - BOUNDARYU (rw) */
} Ifx_EDSADC_CH_BOUNDSEL_Bits;

/** \brief Carrier Generator Synchronization Reg. ${x} */
typedef struct _Ifx_EDSADC_CH_CGSYNC_Bits
{
    Ifx_UReg_32Bit SDCOUNT:8;         /**< \brief [7:0] Sign Delay Counter - SDCOUNT (rh) */
    Ifx_UReg_32Bit SDCAP:8;           /**< \brief [15:8] Sign Delay Capture Value - SDCAP (rh) */
    Ifx_UReg_32Bit SDPOS:8;           /**< \brief [23:16] Sign Delay Value for Positive Halfwave - SDPOS (rw) */
    Ifx_UReg_32Bit SDNEG:8;           /**< \brief [31:24] Sign Delay Value for Negative Halfwave - SDNEG (rw) */
} Ifx_EDSADC_CH_CGSYNC_Bits;

/** \brief Demodulator Input Config. Register ${x} */
typedef struct _Ifx_EDSADC_CH_DICFG_Bits
{
    Ifx_UReg_32Bit DSS:3;             /**< \brief [2:0] Data Stream Select - DSS (rw) */
    Ifx_UReg_32Bit reserved_3:1;      /**< \brief [3:3] \internal Reserved */
    Ifx_UReg_32Bit DSRCEX:3;          /**< \brief [6:4] Data Source for External Modulator - DSRCEX (rw) */
    Ifx_UReg_32Bit reserved_7:1;      /**< \brief [7:7] \internal Reserved */
    Ifx_UReg_32Bit CSRCEX:3;          /**< \brief [10:8] Clock Source for External Modulator - CSRCEX (rw) */
    Ifx_UReg_32Bit reserved_11:4;     /**< \brief [14:11] \internal Reserved */
    Ifx_UReg_32Bit DSWC:1;            /**< \brief [15:15] Write Control for Data Stream Selection - DSWC (w) */
    Ifx_UReg_32Bit TRSEL:4;           /**< \brief [19:16] Trigger Select - TRSEL (rw) */
    Ifx_UReg_32Bit ITRMODE:2;         /**< \brief [21:20] Integrator Trigger Mode - ITRMODE (rw) */
    Ifx_UReg_32Bit TSTRMODE:2;        /**< \brief [23:22] Timestamp Trigger Mode - TSTRMODE (rw) */
    Ifx_UReg_32Bit reserved_24:2;     /**< \brief [25:24] \internal Reserved */
    Ifx_UReg_32Bit DRM:2;             /**< \brief [27:26] Data Read Mode - DRM (rw) */
    Ifx_UReg_32Bit TSM:1;             /**< \brief [28:28] Time-Stamp Mode - TSM (rw) */
    Ifx_UReg_32Bit RDM:1;             /**< \brief [29:29] Result Display Mode - RDM (rw) */
    Ifx_UReg_32Bit reserved_30:1;     /**< \brief [30:30] \internal Reserved */
    Ifx_UReg_32Bit MSWC:1;            /**< \brief [31:31] Write Control for Mode Settings - MSWC (w) */
} Ifx_EDSADC_CH_DICFG_Bits;

/** \brief Auxiliary Filter Configuration Register ${x} */
typedef struct _Ifx_EDSADC_CH_FCFGA_Bits
{
    Ifx_UReg_32Bit CFAEN:1;           /**< \brief [0:0] CIC Filter (Auxiliary) Enable (rw) */
    Ifx_UReg_32Bit CFADF:1;           /**< \brief [1:1] CIC Filter (Auxiliary) Decimation Factor (rw) */
    Ifx_UReg_32Bit reserved_2:14;     /**< \brief [15:2] \internal Reserved */
    Ifx_UReg_32Bit CFACNT:5;          /**< \brief [20:16] CIC Filter (Auxiliary) Decimation Counter (rh) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_EDSADC_CH_FCFGA_Bits;

/** \brief Filter Configuration Register ${x}, CIC Filter */
typedef struct _Ifx_EDSADC_CH_FCFGC_Bits
{
    Ifx_UReg_32Bit CFMDF:9;           /**< \brief [8:0] CIC Filter Decimation Factor - CFMDF (rw) */
    Ifx_UReg_32Bit reserved_9:7;      /**< \brief [15:9] \internal Reserved */
    Ifx_UReg_32Bit CFMSV:9;           /**< \brief [24:16] CIC Filter Start Value - CFMSV (rw) */
    Ifx_UReg_32Bit reserved_25:7;     /**< \brief [31:25] \internal Reserved */
} Ifx_EDSADC_CH_FCFGC_Bits;

/** \brief Filter Configuration Register ${x}, Main */
typedef struct _Ifx_EDSADC_CH_FCFGM_Bits
{
    Ifx_UReg_32Bit FIR0EN:1;          /**< \brief [0:0] FIR0 Filter Enable - FIR0EN (rw) */
    Ifx_UReg_32Bit FIR1EN:1;          /**< \brief [1:1] FIR1 Filter Enable - FIR1EN (rw) */
    Ifx_UReg_32Bit OVCEN:1;           /**< \brief [2:2] Overshoot Compensation Enable (rw) */
    Ifx_UReg_32Bit FIR1DEC:1;         /**< \brief [3:3] FIR1 Filter Decimation Rate - FIR1DEC (rw) */
    Ifx_UReg_32Bit CICMOD:1;          /**< \brief [4:4] CIC Filter Mode - CICMOD (rw) */
    Ifx_UReg_32Bit PFEN:1;            /**< \brief [5:5] Prefilter Enable - PFEN (rw) */
    Ifx_UReg_32Bit reserved_6:2;      /**< \brief [7:6] \internal Reserved */
    Ifx_UReg_32Bit OCEN:3;            /**< \brief [10:8] Offset Compensation Filter Enable - OCEN (rw) */
    Ifx_UReg_32Bit OFFPROT:1;         /**< \brief [11:11] Offset Protection - OFFPROT (rw) */
    Ifx_UReg_32Bit reserved_12:3;     /**< \brief [14:12] \internal Reserved */
    Ifx_UReg_32Bit FMWC:1;            /**< \brief [15:15] Write Control for Filter Modes - FMWC (w) */
    Ifx_UReg_32Bit SRGM:2;            /**< \brief [17:16] Service Request Generation for Main Service Request - SRGM (rw) */
    Ifx_UReg_32Bit reserved_18:2;     /**< \brief [19:18] \internal Reserved */
    Ifx_UReg_32Bit SRGA:2;            /**< \brief [21:20] Service Request Generation for Alternate Service Request - SRGA (rw) */
    Ifx_UReg_32Bit ESEL:2;            /**< \brief [23:22] Event Select - ESEL (rw) */
    Ifx_UReg_32Bit EGT:1;             /**< \brief [24:24] Event Gating (rw) */
    Ifx_UReg_32Bit reserved_25:3;     /**< \brief [27:25] \internal Reserved */
    Ifx_UReg_32Bit CALIB:1;           /**< \brief [28:28] Calibration Trigger - CALIB (w) */
    Ifx_UReg_32Bit AUTOCAL:1;         /**< \brief [29:29] Automatic Calibration Control - AUTOCAL (rw) */
    Ifx_UReg_32Bit reserved_30:1;     /**< \brief [30:30] \internal Reserved */
    Ifx_UReg_32Bit CSRWC:1;           /**< \brief [31:31] Write Control for Calibration and Service Request Modes - CSRWC (w) */
} Ifx_EDSADC_CH_FCFGM_Bits;

/** \brief Filter Counter Register ${x}, CIC Filter */
typedef struct _Ifx_EDSADC_CH_FCNTC_Bits
{
    Ifx_UReg_32Bit CFMDCNT:9;         /**< \brief [8:0] CIC Filter Decimation Counter - CFMDCNT (rh) */
    Ifx_UReg_32Bit reserved_9:21;     /**< \brief [29:9] \internal Reserved */
    Ifx_UReg_32Bit CAL:2;             /**< \brief [31:30] Calibration Status Flag - CAL (rh) */
} Ifx_EDSADC_CH_FCNTC_Bits;

/** \brief Gain Calibration Register ${x} */
typedef struct _Ifx_EDSADC_CH_GAINCAL_Bits
{
    Ifx_UReg_32Bit CALFACTOR:13;      /**< \brief [12:0] Multiplication Factor for Gain Calibration - CALFACTOR (rwh) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit CALTARGET:15;      /**< \brief [30:16] Target Value for Calibrated Fullscale - CALTARGET (rw) */
    Ifx_UReg_32Bit reserved_31:1;     /**< \brief [31:31] \internal Reserved */
} Ifx_EDSADC_CH_GAINCAL_Bits;

/** \brief Gain Correction Register ${x} */
typedef struct _Ifx_EDSADC_CH_GAINCORR_Bits
{
    Ifx_UReg_32Bit GAINFACTOR:13;     /**< \brief [12:0] Multiplication Factor for Gain Correction - GAINFACTOR (rw) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit CICSHIFT:5;        /**< \brief [20:16] Position of the CIC Filter Output Shifter (rw) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_EDSADC_CH_GAINCORR_Bits;

/** \brief Gain Control Register ${x} */
typedef struct _Ifx_EDSADC_CH_GAINCTR_Bits
{
    Ifx_UReg_32Bit GAINFACTOR:13;     /**< \brief [12:0] Multiplication Factor for Gain Correction During Calibration - GAINFACTOR (rw) */
    Ifx_UReg_32Bit reserved_13:3;     /**< \brief [15:13] \internal Reserved */
    Ifx_UReg_32Bit CICSHIFT:5;        /**< \brief [20:16] Position of the CIC Filter Output Shifter During Calibration - CICSHIFT (rw) */
    Ifx_UReg_32Bit reserved_21:3;     /**< \brief [23:21] \internal Reserved */
    Ifx_UReg_32Bit CICDEC:3;          /**< \brief [26:24] Decimation Rate of the CIC Filter During Calibration - CICDEC (rw) */
    Ifx_UReg_32Bit reserved_27:5;     /**< \brief [31:27] \internal Reserved */
} Ifx_EDSADC_CH_GAINCTR_Bits;

/** \brief Intermediate Integration Value */
typedef struct _Ifx_EDSADC_CH_IIVAL_Bits
{
    Ifx_UReg_32Bit IVAL:26;           /**< \brief [25:0] Result of most recent accumulation - IVAL (rh) */
    Ifx_UReg_32Bit reserved_26:6;     /**< \brief [31:26] \internal Reserved */
} Ifx_EDSADC_CH_IIVAL_Bits;

/** \brief Integrator Status Register ${x} */
typedef struct _Ifx_EDSADC_CH_ISTAT_Bits
{
    Ifx_UReg_32Bit NVALCNT:6;         /**< \brief [5:0] Number of Values Counted - NVALCNT (rh) */
    Ifx_UReg_32Bit reserved_6:2;      /**< \brief [7:6] \internal Reserved */
    Ifx_UReg_32Bit REPCNT:4;          /**< \brief [11:8] Integration Cycle Counter - REPCNT (rh) */
    Ifx_UReg_32Bit reserved_12:3;     /**< \brief [14:12] \internal Reserved */
    Ifx_UReg_32Bit INTEN:1;           /**< \brief [15:15] Integration Enable - INTEN (rh) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_EDSADC_CH_ISTAT_Bits;

/** \brief Integration Window Control Register ${x} */
typedef struct _Ifx_EDSADC_CH_IWCTR_Bits
{
    Ifx_UReg_32Bit ISC:3;             /**< \brief [2:0] Integrator Shift Control - ISC (rw) */
    Ifx_UReg_32Bit reserved_3:1;      /**< \brief [3:3] \internal Reserved */
    Ifx_UReg_32Bit IWS:1;             /**< \brief [4:4] Integration Window Size - IWS (rw) */
    Ifx_UReg_32Bit FRC:1;             /**< \brief [5:5] Filter Chain Restart Control (rw) */
    Ifx_UReg_32Bit reserved_6:2;      /**< \brief [7:6] \internal Reserved */
    Ifx_UReg_32Bit REPVAL:4;          /**< \brief [11:8] Number of Integration Cycles - REPVAL (rw) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit NVALDIS:6;         /**< \brief [21:16] Number of Values Discarded - NVALDIS (rw) */
    Ifx_UReg_32Bit reserved_22:2;     /**< \brief [23:22] \internal Reserved */
    Ifx_UReg_32Bit NVALINT:6;         /**< \brief [29:24] Number of Values to be Accumulated - NVALINT (rw) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_EDSADC_CH_IWCTR_Bits;

/** \brief Modulator Configuration Register ${x} */
typedef struct _Ifx_EDSADC_CH_MODCFG_Bits
{
    Ifx_UReg_32Bit INCFGP:2;          /**< \brief [1:0] Configuration of Positive Input Line - INCFGP (rw) */
    Ifx_UReg_32Bit INCFGN:2;          /**< \brief [3:2] Configuration of Negative Input Line - INCFGN (rw) */
    Ifx_UReg_32Bit GAINSEL:4;         /**< \brief [7:4] Gain Select of Analog Input Path - GAINSEL (rw) */
    Ifx_UReg_32Bit INSEL:2;           /**< \brief [9:8] Input Pin Selection - INSEL (rw) */
    Ifx_UReg_32Bit INMUX:2;           /**< \brief [11:10] Input Multiplexer Setting - INMUX (rh) */
    Ifx_UReg_32Bit INMODE:2;          /**< \brief [13:12] Input Multiplexer Control Mode - INMODE (rw) */
    Ifx_UReg_32Bit INMAC:1;           /**< \brief [14:14] Input Multiplexer Action Control - INMAC (rw) */
    Ifx_UReg_32Bit INCWC:1;           /**< \brief [15:15] Write Control for Input Parameters - INCWC (w) */
    Ifx_UReg_32Bit DIVM:3;            /**< \brief [18:16] Modulator Clock Period - DIVM (rw) */
    Ifx_UReg_32Bit reserved_19:1;     /**< \brief [19:19] \internal Reserved */
    Ifx_UReg_32Bit ACSD:3;            /**< \brief [22:20] Analog Clock Synchronization Delay - ACSD (rw) */
    Ifx_UReg_32Bit reserved_23:3;     /**< \brief [25:23] \internal Reserved */
    Ifx_UReg_32Bit DITHEN:1;          /**< \brief [26:26] Dithering Function Enable - DITHEN (rw) */
    Ifx_UReg_32Bit IREN:1;            /**< \brief [27:27] Integrator Reset Enable - IREN (rw) */
    Ifx_UReg_32Bit APC:2;             /**< \brief [29:28] Automatic Power Control - APC (rw) */
    Ifx_UReg_32Bit reserved_30:1;     /**< \brief [30:30] \internal Reserved */
    Ifx_UReg_32Bit MMWC:1;            /**< \brief [31:31] Write Control for Modulator Mode Settings - MMWC (w) */
} Ifx_EDSADC_CH_MODCFG_Bits;

/** \brief Offset Compensation Register ${x} */
typedef struct _Ifx_EDSADC_CH_OFFCOMP_Bits
{
    Ifx_UReg_32Bit OFFSET:16;         /**< \brief [15:0] Offset Value - OFFSET (rwh) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_EDSADC_CH_OFFCOMP_Bits;

/** \brief Overshoot Compensation Cfg. Register ${x} */
typedef struct _Ifx_EDSADC_CH_OVSCFG_Bits
{
    Ifx_UReg_32Bit SRFS:2;            /**< \brief [1:0] Slew Rate Filter Strength (rw) */
    Ifx_UReg_32Bit SRFRT:2;           /**< \brief [3:2] Slew Rate Filter Run Time (rw) */
    Ifx_UReg_32Bit SDM:1;             /**< \brief [4:4] Step Detection Mode (rw) */
    Ifx_UReg_32Bit reserved_5:11;     /**< \brief [15:5] \internal Reserved */
    Ifx_UReg_32Bit SDTH:11;           /**< \brief [26:16] Step Detection Threshold (rw) */
    Ifx_UReg_32Bit reserved_27:5;     /**< \brief [31:27] \internal Reserved */
} Ifx_EDSADC_CH_OVSCFG_Bits;

/** \brief Rectification Configuration Register ${x} */
typedef struct _Ifx_EDSADC_CH_RECTCFG_Bits
{
    Ifx_UReg_32Bit RFEN:1;            /**< \brief [0:0] Rectification Enable - RFEN (rw) */
    Ifx_UReg_32Bit reserved_1:3;      /**< \brief [3:1] \internal Reserved */
    Ifx_UReg_32Bit SSRC:2;            /**< \brief [5:4] Sign Source (rw) */
    Ifx_UReg_32Bit reserved_6:2;      /**< \brief [7:6] \internal Reserved */
    Ifx_UReg_32Bit SSCH:4;            /**< \brief [11:8] Sign Source Channel (rw) */
    Ifx_UReg_32Bit reserved_12:3;     /**< \brief [14:12] \internal Reserved */
    Ifx_UReg_32Bit SDCVAL:1;          /**< \brief [15:15] Valid Flag - SDCVAL (rh) */
    Ifx_UReg_32Bit reserved_16:14;    /**< \brief [29:16] \internal Reserved */
    Ifx_UReg_32Bit SGNCS:1;           /**< \brief [30:30] Selected Carrier Sign Signal - SGNCS (rh) */
    Ifx_UReg_32Bit SGND:1;            /**< \brief [31:31] Sign Signal Delayed - SGND (rh) */
} Ifx_EDSADC_CH_RECTCFG_Bits;

/** \brief Result Register ${x} Auxiliary */
typedef struct _Ifx_EDSADC_CH_RESA_Bits
{
    Ifx_UReg_32Bit RESULT:16;         /**< \brief [15:0] Most Recent Result of Auxiliary Filter (rh) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_EDSADC_CH_RESA_Bits;

/** \brief Result Register ${x} Main */
typedef struct _Ifx_EDSADC_CH_RESM_Bits
{
    Ifx_UReg_32Bit RESULTLO:16;       /**< \brief [15:0] Result Value Lower Part - RESULTLO (rh) */
    Ifx_UReg_32Bit RESULTHI:16;       /**< \brief [31:16] Result Value Higher Part - RESULTHI (rh) */
} Ifx_EDSADC_CH_RESM_Bits;

/** \brief Result FIFO Control Register ${x} */
typedef struct _Ifx_EDSADC_CH_RFC_Bits
{
    Ifx_UReg_32Bit SRLVL:2;           /**< \brief [1:0] Service Request FIFO Level (rw) */
    Ifx_UReg_32Bit reserved_2:2;      /**< \brief [3:2] \internal Reserved */
    Ifx_UReg_32Bit RDEC:1;            /**< \brief [4:4] Read Error Flag Clear (w) */
    Ifx_UReg_32Bit WREC:1;            /**< \brief [5:5] Write Error Flag Clear (w) */
    Ifx_UReg_32Bit FIFL:1;            /**< \brief [6:6] FIFO Flush (w) */
    Ifx_UReg_32Bit reserved_7:9;      /**< \brief [15:7] \internal Reserved */
    Ifx_UReg_32Bit FILL:3;            /**< \brief [18:16] FIFO Fill Level (rh) */
    Ifx_UReg_32Bit reserved_19:1;     /**< \brief [19:19] \internal Reserved */
    Ifx_UReg_32Bit RDERR:1;           /**< \brief [20:20] Read Error Flag (rh) */
    Ifx_UReg_32Bit WRERR:1;           /**< \brief [21:21] Write Error Flag (rh) */
    Ifx_UReg_32Bit reserved_22:10;    /**< \brief [31:22] \internal Reserved */
} Ifx_EDSADC_CH_RFC_Bits;

/** \brief Time-Stamp Counter ${x} */
typedef struct _Ifx_EDSADC_CH_TSCNT_Bits
{
    Ifx_UReg_32Bit TSCOUNT:16;        /**< \brief [15:0] Timestamp Counter Value - TSCOUNT (rh) */
    Ifx_UReg_32Bit TSCLK:2;           /**< \brief [17:16] Timestamp Counter Clock Selection - TSCLK (rw) */
    Ifx_UReg_32Bit reserved_18:1;     /**< \brief [18:18] \internal Reserved */
    Ifx_UReg_32Bit TSCRUN:1;          /**< \brief [19:19] Timestamp Counter Run Control - TSCRUN (rw) */
    Ifx_UReg_32Bit AMXCOPY:1;         /**< \brief [20:20] Analog MUX Setting Copy Enable - AMXCOPY (rw) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_EDSADC_CH_TSCNT_Bits;

/** \brief Time-Stamp Register ${x} */
typedef struct _Ifx_EDSADC_CH_TSTMP_Bits
{
    Ifx_UReg_32Bit TIMESTAMP:16;      /**< \brief [15:0] The Most Recent Captured Timestamp Value - TIMESTAMP (rh) */
    Ifx_UReg_32Bit AMX:2;             /**< \brief [17:16] Analog Multiplexer Setting - AMX (rh) */
    Ifx_UReg_32Bit reserved_18:13;    /**< \brief [30:18] \internal Reserved */
    Ifx_UReg_32Bit TSVAL:1;           /**< \brief [31:31] Timestamp Valid - TSVAL (rh) */
} Ifx_EDSADC_CH_TSTMP_Bits;

/** \brief Common Mode Voltage Register ${x} */
typedef struct _Ifx_EDSADC_CH_VCM_Bits
{
    Ifx_UReg_32Bit VREFXSEL:2;        /**< \brief [1:0] Fractional Reference Voltage Selection - VREFXSEL (rw) */
    Ifx_UReg_32Bit VXON:1;            /**< \brief [2:2] Fractional Reference Voltage Enable - VXON (rw) */
    Ifx_UReg_32Bit reserved_3:13;     /**< \brief [15:3] \internal Reserved */
    Ifx_UReg_32Bit INPVC0:1;          /**< \brief [16:16] Voltage Control of Positive Inputs 0 of CH0 (rw) */
    Ifx_UReg_32Bit INPVC1:1;          /**< \brief [17:17] Voltage Control of Positive Inputs 1 of CH0 (rw) */
    Ifx_UReg_32Bit INPVC2:1;          /**< \brief [18:18] Voltage Control of Positive Inputs 2 of CH0 (rw) */
    Ifx_UReg_32Bit INPVC3:1;          /**< \brief [19:19] Voltage Control of Positive Inputs 3 of CH0 (rw) */
    Ifx_UReg_32Bit INNVC0:1;          /**< \brief [20:20] Voltage Control of Negative Inputs 0 of CH0 (rw) */
    Ifx_UReg_32Bit INNVC1:1;          /**< \brief [21:21] Voltage Control of Negative Inputs 1 of CH0 (rw) */
    Ifx_UReg_32Bit INNVC2:1;          /**< \brief [22:22] Voltage Control of Negative Inputs 2 of CH0 (rw) */
    Ifx_UReg_32Bit INNVC3:1;          /**< \brief [23:23] Voltage Control of Negative Inputs 3 of CH0 (rw) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_EDSADC_CH_VCM_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_EDSADC_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (r) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_EDSADC_CLC_Bits;

/** \brief Event Flag Register */
typedef struct _Ifx_EDSADC_EVFLAG_Bits
{
    Ifx_UReg_32Bit RESEV0:1;          /**< \brief [0:0] Result Event - RESEV0 (rwh) */
    Ifx_UReg_32Bit RESEV1:1;          /**< \brief [1:1] Result Event - RESEV1 (rwh) */
    Ifx_UReg_32Bit RESEV2:1;          /**< \brief [2:2] Result Event - RESEV2 (rwh) */
    Ifx_UReg_32Bit RESEV3:1;          /**< \brief [3:3] Result Event - RESEV3 (rwh) */
    Ifx_UReg_32Bit RESEV4:1;          /**< \brief [4:4] Result Event - RESEV4 (rwh) */
    Ifx_UReg_32Bit RESEV5:1;          /**< \brief [5:5] Result Event - RESEV5 (rwh) */
    Ifx_UReg_32Bit RESEV6:1;          /**< \brief [6:6] Result Event - RESEV6 (rwh) */
    Ifx_UReg_32Bit RESEV7:1;          /**< \brief [7:7] Result Event - RESEV7 (rwh) */
    Ifx_UReg_32Bit RESEV8:1;          /**< \brief [8:8] Result Event - RESEV8 (rwh) */
    Ifx_UReg_32Bit RESEV9:1;          /**< \brief [9:9] Result Event - RESEV9 (rwh) */
    Ifx_UReg_32Bit RESEV10:1;         /**< \brief [10:10] Result Event - RESEV10 (rwh) */
    Ifx_UReg_32Bit RESEV11:1;         /**< \brief [11:11] Result Event - RESEV11 (rwh) */
    Ifx_UReg_32Bit RESEV12:1;         /**< \brief [12:12] Result Event - RESEV12 (rwh) */
    Ifx_UReg_32Bit RESEV13:1;         /**< \brief [13:13] Result Event - RESEV13 (rwh) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit ALEV0:1;           /**< \brief [16:16] Alarm Event - ALEV0 (rwh) */
    Ifx_UReg_32Bit ALEV1:1;           /**< \brief [17:17] Alarm Event - ALEV1 (rwh) */
    Ifx_UReg_32Bit ALEV2:1;           /**< \brief [18:18] Alarm Event - ALEV2 (rwh) */
    Ifx_UReg_32Bit ALEV3:1;           /**< \brief [19:19] Alarm Event - ALEV3 (rwh) */
    Ifx_UReg_32Bit ALEV4:1;           /**< \brief [20:20] Alarm Event - ALEV4 (rwh) */
    Ifx_UReg_32Bit ALEV5:1;           /**< \brief [21:21] Alarm Event - ALEV5 (rwh) */
    Ifx_UReg_32Bit ALEV6:1;           /**< \brief [22:22] Alarm Event - ALEV6 (rwh) */
    Ifx_UReg_32Bit ALEV7:1;           /**< \brief [23:23] Alarm Event - ALEV7 (rwh) */
    Ifx_UReg_32Bit ALEV8:1;           /**< \brief [24:24] Alarm Event - ALEV8 (rwh) */
    Ifx_UReg_32Bit ALEV9:1;           /**< \brief [25:25] Alarm Event - ALEV9 (rwh) */
    Ifx_UReg_32Bit ALEV10:1;          /**< \brief [26:26] Alarm Event - ALEV10 (rwh) */
    Ifx_UReg_32Bit ALEV11:1;          /**< \brief [27:27] Alarm Event - ALEV11 (rwh) */
    Ifx_UReg_32Bit ALEV12:1;          /**< \brief [28:28] Alarm Event - ALEV12 (rwh) */
    Ifx_UReg_32Bit ALEV13:1;          /**< \brief [29:29] Alarm Event - ALEV13 (rwh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_EDSADC_EVFLAG_Bits;

/** \brief Event Flag Clear Register */
typedef struct _Ifx_EDSADC_EVFLAGCLR_Bits
{
    Ifx_UReg_32Bit RESEC0:1;          /**< \brief [0:0] Result Event Clear - RESEC0 (w) */
    Ifx_UReg_32Bit RESEC1:1;          /**< \brief [1:1] Result Event Clear - RESEC1 (w) */
    Ifx_UReg_32Bit RESEC2:1;          /**< \brief [2:2] Result Event Clear - RESEC2 (w) */
    Ifx_UReg_32Bit RESEC3:1;          /**< \brief [3:3] Result Event Clear - RESEC3 (w) */
    Ifx_UReg_32Bit RESEC4:1;          /**< \brief [4:4] Result Event Clear - RESEC4 (w) */
    Ifx_UReg_32Bit RESEC5:1;          /**< \brief [5:5] Result Event Clear - RESEC5 (w) */
    Ifx_UReg_32Bit RESEC6:1;          /**< \brief [6:6] Result Event Clear - RESEC6 (w) */
    Ifx_UReg_32Bit RESEC7:1;          /**< \brief [7:7] Result Event Clear - RESEC7 (w) */
    Ifx_UReg_32Bit RESEC8:1;          /**< \brief [8:8] Result Event Clear - RESEC8 (w) */
    Ifx_UReg_32Bit RESEC9:1;          /**< \brief [9:9] Result Event Clear - RESEC9 (w) */
    Ifx_UReg_32Bit RESEC10:1;         /**< \brief [10:10] Result Event Clear - RESEC10 (w) */
    Ifx_UReg_32Bit RESEC11:1;         /**< \brief [11:11] Result Event Clear - RESEC11 (w) */
    Ifx_UReg_32Bit RESEC12:1;         /**< \brief [12:12] Result Event Clear - RESEC12 (w) */
    Ifx_UReg_32Bit RESEC13:1;         /**< \brief [13:13] Result Event Clear - RESEC13 (w) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit ALEC0:1;           /**< \brief [16:16] Alarm Event Clear - ALEC0 (w) */
    Ifx_UReg_32Bit ALEC1:1;           /**< \brief [17:17] Alarm Event Clear - ALEC1 (w) */
    Ifx_UReg_32Bit ALEC2:1;           /**< \brief [18:18] Alarm Event Clear - ALEC2 (w) */
    Ifx_UReg_32Bit ALEC3:1;           /**< \brief [19:19] Alarm Event Clear - ALEC3 (w) */
    Ifx_UReg_32Bit ALEC4:1;           /**< \brief [20:20] Alarm Event Clear - ALEC4 (w) */
    Ifx_UReg_32Bit ALEC5:1;           /**< \brief [21:21] Alarm Event Clear - ALEC5 (w) */
    Ifx_UReg_32Bit ALEC6:1;           /**< \brief [22:22] Alarm Event Clear - ALEC6 (w) */
    Ifx_UReg_32Bit ALEC7:1;           /**< \brief [23:23] Alarm Event Clear - ALEC7 (w) */
    Ifx_UReg_32Bit ALEC8:1;           /**< \brief [24:24] Alarm Event Clear - ALEC8 (w) */
    Ifx_UReg_32Bit ALEC9:1;           /**< \brief [25:25] Alarm Event Clear - ALEC9 (w) */
    Ifx_UReg_32Bit ALEC10:1;          /**< \brief [26:26] Alarm Event Clear - ALEC10 (w) */
    Ifx_UReg_32Bit ALEC11:1;          /**< \brief [27:27] Alarm Event Clear - ALEC11 (w) */
    Ifx_UReg_32Bit ALEC12:1;          /**< \brief [28:28] Alarm Event Clear - ALEC12 (w) */
    Ifx_UReg_32Bit ALEC13:1;          /**< \brief [29:29] Alarm Event Clear - ALEC13 (w) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_EDSADC_EVFLAGCLR_Bits;

/** \brief Global Configuration Register */
typedef struct _Ifx_EDSADC_GLOBCFG_Bits
{
    Ifx_UReg_32Bit reserved_0:8;      /**< \brief [7:0] \internal Reserved */
    Ifx_UReg_32Bit DITRIM:3;          /**< \brief [10:8] Trimming Value for the Dithering Function - DITRIM (rw) */
    Ifx_UReg_32Bit reserved_11:1;     /**< \brief [11:11] \internal Reserved */
    Ifx_UReg_32Bit USC:1;             /**< \brief [12:12] Unsynchronized Clock Generation - USC (rw) */
    Ifx_UReg_32Bit SUPLEV:2;          /**< \brief [14:13] Supply Voltage Level (rw) */
    Ifx_UReg_32Bit CPWC:1;            /**< \brief [15:15] Write Control for Clock Parameters - CPWC (w) */
    Ifx_UReg_32Bit reserved_16:8;     /**< \brief [23:16] \internal Reserved */
    Ifx_UReg_32Bit SVCH:4;            /**< \brief [27:24] Supervision Channel Select (rw) */
    Ifx_UReg_32Bit SVSIG:2;           /**< \brief [29:28] Supervision Signal Select (rw) */
    Ifx_UReg_32Bit reserved_30:1;     /**< \brief [30:30] \internal Reserved */
    Ifx_UReg_32Bit SVWC:1;            /**< \brief [31:31] Write Control for Supervision Parameters (w) */
} Ifx_EDSADC_GLOBCFG_Bits;

/** \brief Global Run Control Register */
typedef struct _Ifx_EDSADC_GLOBRC_Bits
{
    Ifx_UReg_32Bit CH0RUN:1;          /**< \brief [0:0] Channel 0 Run Control - CH0RUN (rw) */
    Ifx_UReg_32Bit CH1RUN:1;          /**< \brief [1:1] Channel 1 Run Control - CH1RUN (rw) */
    Ifx_UReg_32Bit CH2RUN:1;          /**< \brief [2:2] Channel 2 Run Control - CH2RUN (rw) */
    Ifx_UReg_32Bit CH3RUN:1;          /**< \brief [3:3] Channel 3 Run Control - CH3RUN (rw) */
    Ifx_UReg_32Bit CH4RUN:1;          /**< \brief [4:4] Channel 4 Run Control - CH4RUN (rw) */
    Ifx_UReg_32Bit CH5RUN:1;          /**< \brief [5:5] Channel 5 Run Control - CH5RUN (rw) */
    Ifx_UReg_32Bit CH6RUN:1;          /**< \brief [6:6] Channel 6 Run Control - CH6RUN (rw) */
    Ifx_UReg_32Bit CH7RUN:1;          /**< \brief [7:7] Channel 7 Run Control - CH7RUN (rw) */
    Ifx_UReg_32Bit CH8RUN:1;          /**< \brief [8:8] Channel 8 Run Control - CH8RUN (rw) */
    Ifx_UReg_32Bit CH9RUN:1;          /**< \brief [9:9] Channel 9 Run Control - CH9RUN (rw) */
    Ifx_UReg_32Bit CH10RUN:1;         /**< \brief [10:10] Channel 10 Run Control - CH10RUN (rw) */
    Ifx_UReg_32Bit CH11RUN:1;         /**< \brief [11:11] Channel 11 Run Control - CH11RUN (rw) */
    Ifx_UReg_32Bit CH12RUN:1;         /**< \brief [12:12] Channel 12 Run Control - CH12RUN (rw) */
    Ifx_UReg_32Bit CH13RUN:1;         /**< \brief [13:13] Channel 13 Run Control - CH13RUN (rw) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit M0RUN:1;           /**< \brief [16:16] Modulator 0 Run Control - M0RUN (rw) */
    Ifx_UReg_32Bit M1RUN:1;           /**< \brief [17:17] Modulator 1 Run Control - M1RUN (rw) */
    Ifx_UReg_32Bit M2RUN:1;           /**< \brief [18:18] Modulator 2 Run Control - M2RUN (rw) */
    Ifx_UReg_32Bit M3RUN:1;           /**< \brief [19:19] Modulator 3 Run Control - M3RUN (rw) */
    Ifx_UReg_32Bit M4RUN:1;           /**< \brief [20:20] Modulator 4 Run Control - M4RUN (rw) */
    Ifx_UReg_32Bit M5RUN:1;           /**< \brief [21:21] Modulator 5 Run Control - M5RUN (rw) */
    Ifx_UReg_32Bit M6RUN:1;           /**< \brief [22:22] Modulator 6 Run Control - M6RUN (rw) */
    Ifx_UReg_32Bit M7RUN:1;           /**< \brief [23:23] Modulator 7 Run Control - M7RUN (rw) */
    Ifx_UReg_32Bit M8RUN:1;           /**< \brief [24:24] Modulator 8 Run Control - M8RUN (rw) */
    Ifx_UReg_32Bit M9RUN:1;           /**< \brief [25:25] Modulator 9 Run Control - M9RUN (rw) */
    Ifx_UReg_32Bit M10RUN:1;          /**< \brief [26:26] Modulator 10 Run Control - M10RUN (rw) */
    Ifx_UReg_32Bit M11RUN:1;          /**< \brief [27:27] Modulator 11 Run Control - M11RUN (rw) */
    Ifx_UReg_32Bit M12RUN:1;          /**< \brief [28:28] Modulator 12 Run Control - M12RUN (rw) */
    Ifx_UReg_32Bit M13RUN:1;          /**< \brief [29:29] Modulator 13 Run Control - M13RUN (rw) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_EDSADC_GLOBRC_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_EDSADC_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number - MOD_NUMBER (r) */
} Ifx_EDSADC_ID_Bits;

/** \brief Kernel Reset Register 0 */
typedef struct _Ifx_EDSADC_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_EDSADC_KRST0_Bits;

/** \brief Kernel Reset Register 1 */
typedef struct _Ifx_EDSADC_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_EDSADC_KRST1_Bits;

/** \brief Kernel Reset Status Clear Register */
typedef struct _Ifx_EDSADC_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_EDSADC_KRSTCLR_Bits;

/** \brief OCDS Control and Status Register */
typedef struct _Ifx_EDSADC_OCS_Bits
{
    Ifx_UReg_32Bit reserved_0:24;     /**< \brief [23:0] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_EDSADC_OCS_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_edsadc_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_ACCEN0_Bits B;         /**< \brief Bitfield access */
} Ifx_EDSADC_ACCEN0;

/** \brief Access Protection Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_ACCPROT_Bits B;        /**< \brief Bitfield access */
} Ifx_EDSADC_ACCPROT;

/** \brief Carrier Generator Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CGCFG_Bits B;          /**< \brief Bitfield access */
} Ifx_EDSADC_CGCFG;

/** \brief Boundary Select Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_BOUNDSEL_Bits B;    /**< \brief Bitfield access */
} Ifx_EDSADC_CH_BOUNDSEL;

/** \brief Carrier Generator Synchronization Reg. ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_CGSYNC_Bits B;      /**< \brief Bitfield access */
} Ifx_EDSADC_CH_CGSYNC;

/** \brief Demodulator Input Config. Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_DICFG_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_DICFG;

/** \brief Auxiliary Filter Configuration Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_FCFGA_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_FCFGA;

/** \brief Filter Configuration Register ${x}, CIC Filter   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_FCFGC_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_FCFGC;

/** \brief Filter Configuration Register ${x}, Main   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_FCFGM_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_FCFGM;

/** \brief Filter Counter Register ${x}, CIC Filter   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_FCNTC_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_FCNTC;

/** \brief Gain Calibration Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_GAINCAL_Bits B;     /**< \brief Bitfield access */
} Ifx_EDSADC_CH_GAINCAL;

/** \brief Gain Correction Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_GAINCORR_Bits B;    /**< \brief Bitfield access */
} Ifx_EDSADC_CH_GAINCORR;

/** \brief Gain Control Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_GAINCTR_Bits B;     /**< \brief Bitfield access */
} Ifx_EDSADC_CH_GAINCTR;

/** \brief Intermediate Integration Value   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_IIVAL_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_IIVAL;

/** \brief Integrator Status Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_ISTAT_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_ISTAT;

/** \brief Integration Window Control Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_IWCTR_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_IWCTR;

/** \brief Modulator Configuration Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_MODCFG_Bits B;      /**< \brief Bitfield access */
} Ifx_EDSADC_CH_MODCFG;

/** \brief Offset Compensation Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_OFFCOMP_Bits B;     /**< \brief Bitfield access */
} Ifx_EDSADC_CH_OFFCOMP;

/** \brief Overshoot Compensation Cfg. Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_OVSCFG_Bits B;      /**< \brief Bitfield access */
} Ifx_EDSADC_CH_OVSCFG;

/** \brief Rectification Configuration Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_RECTCFG_Bits B;     /**< \brief Bitfield access */
} Ifx_EDSADC_CH_RECTCFG;

/** \brief Result Register ${x} Auxiliary   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_RESA_Bits B;        /**< \brief Bitfield access */
} Ifx_EDSADC_CH_RESA;

/** \brief Result Register ${x} Main   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_RESM_Bits B;        /**< \brief Bitfield access */
} Ifx_EDSADC_CH_RESM;

/** \brief Result FIFO Control Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_RFC_Bits B;         /**< \brief Bitfield access */
} Ifx_EDSADC_CH_RFC;

/** \brief Time-Stamp Counter ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_TSCNT_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_TSCNT;

/** \brief Time-Stamp Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_TSTMP_Bits B;       /**< \brief Bitfield access */
} Ifx_EDSADC_CH_TSTMP;

/** \brief Common Mode Voltage Register ${x}   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CH_VCM_Bits B;         /**< \brief Bitfield access */
} Ifx_EDSADC_CH_VCM;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_CLC_Bits B;            /**< \brief Bitfield access */
} Ifx_EDSADC_CLC;

/** \brief Event Flag Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_EVFLAG_Bits B;         /**< \brief Bitfield access */
} Ifx_EDSADC_EVFLAG;

/** \brief Event Flag Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_EVFLAGCLR_Bits B;      /**< \brief Bitfield access */
} Ifx_EDSADC_EVFLAGCLR;

/** \brief Global Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_GLOBCFG_Bits B;        /**< \brief Bitfield access */
} Ifx_EDSADC_GLOBCFG;

/** \brief Global Run Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_GLOBRC_Bits B;         /**< \brief Bitfield access */
} Ifx_EDSADC_GLOBRC;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_ID_Bits B;             /**< \brief Bitfield access */
} Ifx_EDSADC_ID;

/** \brief Kernel Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_KRST0_Bits B;          /**< \brief Bitfield access */
} Ifx_EDSADC_KRST0;

/** \brief Kernel Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_KRST1_Bits B;          /**< \brief Bitfield access */
} Ifx_EDSADC_KRST1;

/** \brief Kernel Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_KRSTCLR_Bits B;        /**< \brief Bitfield access */
} Ifx_EDSADC_KRSTCLR;

/** \brief OCDS Control and Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_EDSADC_OCS_Bits B;            /**< \brief Bitfield access */
} Ifx_EDSADC_OCS;

/** \}  */

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Edsadc_CH_struct
 * \{  */
/******************************************************************************/
/** \name Object L1
 * \{  */
/** \brief CH object */
typedef volatile struct _Ifx_EDSADC_CH
{
       Ifx_EDSADC_CH_MODCFG                MODCFG;                 /**< \brief 0, Modulator Configuration Register ${x}*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_EDSADC_CH_DICFG                 DICFG;                  /**< \brief 8, Demodulator Input Config. Register ${x}*/
       Ifx_UReg_8Bit                       reserved_C[4];          /**< \brief C, \internal Reserved */
       Ifx_EDSADC_CH_FCFGM                 FCFGM;                  /**< \brief 10, Filter Configuration Register ${x}, Main*/
       Ifx_EDSADC_CH_FCFGC                 FCFGC;                  /**< \brief 14, Filter Configuration Register ${x}, CIC Filter*/
       Ifx_EDSADC_CH_FCNTC                 FCNTC;                  /**< \brief 18, Filter Counter Register ${x}, CIC Filter*/
       Ifx_EDSADC_CH_OVSCFG                OVSCFG;                 /**< \brief 1C, Overshoot Compensation Cfg. Register ${x}*/
       Ifx_EDSADC_CH_IWCTR                 IWCTR;                  /**< \brief 20, Integration Window Control Register ${x}*/
       Ifx_EDSADC_CH_IIVAL                 IIVAL;                  /**< \brief 24, Intermediate Integration Value*/
       Ifx_EDSADC_CH_ISTAT                 ISTAT;                  /**< \brief 28, Integrator Status Register ${x}*/
       Ifx_EDSADC_CH_RFC                   RFC;                    /**< \brief 2C, Result FIFO Control Register ${x}*/
       Ifx_EDSADC_CH_RESM                  RESM;                   /**< \brief 30, Result Register ${x} Main*/
       Ifx_UReg_8Bit                       reserved_34[4];         /**< \brief 34, \internal Reserved */
       Ifx_EDSADC_CH_OFFCOMP               OFFCOMP;                /**< \brief 38, Offset Compensation Register ${x}*/
       Ifx_EDSADC_CH_GAINCAL               GAINCAL;                /**< \brief 3C, Gain Calibration Register ${x}*/
       Ifx_EDSADC_CH_GAINCTR               GAINCTR;                /**< \brief 40, Gain Control Register ${x}*/
       Ifx_EDSADC_CH_GAINCORR              GAINCORR;               /**< \brief 44, Gain Correction Register ${x}*/
       Ifx_UReg_8Bit                       reserved_48[8];         /**< \brief 48, \internal Reserved */
       Ifx_EDSADC_CH_TSTMP                 TSTMP;                  /**< \brief 50, Time-Stamp Register ${x}*/
       Ifx_EDSADC_CH_TSCNT                 TSCNT;                  /**< \brief 54, Time-Stamp Counter ${x}*/
       Ifx_UReg_8Bit                       reserved_58[24];        /**< \brief 58, \internal Reserved */
       Ifx_EDSADC_CH_FCFGA                 FCFGA;                  /**< \brief 70, Auxiliary Filter Configuration Register ${x}*/
       Ifx_UReg_8Bit                       reserved_74[4];         /**< \brief 74, \internal Reserved */
       Ifx_EDSADC_CH_BOUNDSEL              BOUNDSEL;               /**< \brief 78, Boundary Select Register ${x}*/
       Ifx_UReg_8Bit                       reserved_7C[4];         /**< \brief 7C, \internal Reserved */
       Ifx_EDSADC_CH_RESA                  RESA;                   /**< \brief 80, Result Register ${x} Auxiliary*/
       Ifx_UReg_8Bit                       reserved_84[28];        /**< \brief 84, \internal Reserved */
       Ifx_EDSADC_CH_CGSYNC                CGSYNC;                 /**< \brief A0, Carrier Generator Synchronization Reg. ${x}*/
       Ifx_UReg_8Bit                       reserved_A4[4];         /**< \brief A4, \internal Reserved */
       Ifx_EDSADC_CH_RECTCFG               RECTCFG;                /**< \brief A8, Rectification Configuration Register ${x}*/
       Ifx_UReg_8Bit                       reserved_AC[4];         /**< \brief AC, \internal Reserved */
       Ifx_EDSADC_CH_VCM                   VCM;                    /**< \brief B0, Common Mode Voltage Register ${x}*/
       Ifx_UReg_8Bit                       reserved_B4[76];        /**< \brief B4, \internal Reserved */
} Ifx_EDSADC_CH;
/** \}  */
/******************************************************************************/
/** \}  */
/******************************************************************************/
/******************************************************************************/

/******************************************************************************/
/** \addtogroup IfxSfr_Edsadc_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief EDSADC object */
typedef volatile struct _Ifx_EDSADC
{
       Ifx_EDSADC_CLC                      CLC;                    /**< \brief 0, Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_EDSADC_ID                       ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[28];         /**< \brief C, \internal Reserved */
       Ifx_EDSADC_OCS                      OCS;                    /**< \brief 28, OCDS Control and Status Register*/
       Ifx_EDSADC_KRSTCLR                  KRSTCLR;                /**< \brief 2C, Kernel Reset Status Clear Register*/
       Ifx_EDSADC_KRST1                    KRST1;                  /**< \brief 30, Kernel Reset Register 1*/
       Ifx_EDSADC_KRST0                    KRST0;                  /**< \brief 34, Kernel Reset Register 0*/
       Ifx_UReg_8Bit                       reserved_38[4];         /**< \brief 38, \internal Reserved */
       Ifx_EDSADC_ACCEN0                   ACCEN0;                 /**< \brief 3C, Access Enable Register 0*/
       Ifx_UReg_8Bit                       reserved_40[64];        /**< \brief 40, \internal Reserved */
       Ifx_EDSADC_GLOBCFG                  GLOBCFG;                /**< \brief 80, Global Configuration Register*/
       Ifx_UReg_8Bit                       reserved_84[4];         /**< \brief 84, \internal Reserved */
       Ifx_EDSADC_GLOBRC                   GLOBRC;                 /**< \brief 88, Global Run Control Register*/
       Ifx_UReg_8Bit                       reserved_8C[4];         /**< \brief 8C, \internal Reserved */
       Ifx_EDSADC_ACCPROT                  ACCPROT;                /**< \brief 90, Access Protection Register*/
       Ifx_UReg_8Bit                       reserved_94[12];        /**< \brief 94, \internal Reserved */
       Ifx_EDSADC_CGCFG                    CGCFG;                  /**< \brief A0, Carrier Generator Configuration Register*/
       Ifx_UReg_8Bit                       reserved_A4[60];        /**< \brief A4, \internal Reserved */
       Ifx_EDSADC_EVFLAG                   EVFLAG;                 /**< \brief E0, Event Flag Register*/
       Ifx_EDSADC_EVFLAGCLR                EVFLAGCLR;              /**< \brief E4, Event Flag Clear Register*/
       Ifx_UReg_8Bit                       reserved_E8[24];        /**< \brief E8, \internal Reserved */
       Ifx_EDSADC_CH                       CH[14];                 /**< \brief 100, */
       Ifx_UReg_8Bit                       reserved_F00[256];      /**< \brief F00, \internal Reserved */
} Ifx_EDSADC;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXEDSADC_REGDEF_H */
