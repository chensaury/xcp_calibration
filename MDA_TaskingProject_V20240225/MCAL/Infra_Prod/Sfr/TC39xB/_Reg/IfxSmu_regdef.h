/**
 * \file IfxSmu_regdef.h
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
 * \defgroup IfxSfr_Smu_Registers Smu Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Smu_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Smu_Registers
 * 
 * \defgroup IfxSfr_Smu_Registers_union Register unions
 * \ingroup IfxSfr_Smu_Registers
 * 
 * \defgroup IfxSfr_Smu_Registers_struct Memory map
 * \ingroup IfxSfr_Smu_Registers
 */
#ifndef IFXSMU_REGDEF_H
#define IFXSMU_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Smu_Registers_Bitfields
 * \{  */
/** \brief SMU_core Access Enable Register 0 */
typedef struct _Ifx_SMU_ACCEN0_Bits
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
} Ifx_SMU_ACCEN0_Bits;

/** \brief SMU_core Access Enable Register 1 */
typedef struct _Ifx_SMU_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_SMU_ACCEN1_Bits;

/** \brief Alarm Debug Register */
typedef struct _Ifx_SMU_AD_Bits
{
    Ifx_UReg_32Bit DF0:1;             /**< \brief [0:0] Diagnosis flag for alarm 0 belonging to alarm group i. - DF0 (rh) */
    Ifx_UReg_32Bit DF1:1;             /**< \brief [1:1] Diagnosis flag for alarm 1 belonging to alarm group i. - DF1 (rh) */
    Ifx_UReg_32Bit DF2:1;             /**< \brief [2:2] Diagnosis flag for alarm 2 belonging to alarm group i. - DF2 (rh) */
    Ifx_UReg_32Bit reserved_3:1;      /**< \brief [3:3] \internal Reserved */
    Ifx_UReg_32Bit DF4:1;             /**< \brief [4:4] Diagnosis flag for alarm 4 belonging to alarm group i. - DF4 (rh) */
    Ifx_UReg_32Bit DF5:1;             /**< \brief [5:5] Diagnosis flag for alarm 5 belonging to alarm group i. - DF5 (rh) */
    Ifx_UReg_32Bit DF6:1;             /**< \brief [6:6] Diagnosis flag for alarm 6 belonging to alarm group i. - DF6 (rh) */
    Ifx_UReg_32Bit DF7:1;             /**< \brief [7:7] Diagnosis flag for alarm 7 belonging to alarm group i. - DF7 (rh) */
    Ifx_UReg_32Bit DF8:1;             /**< \brief [8:8] Diagnosis flag for alarm 8 belonging to alarm group i. - DF8 (rh) */
    Ifx_UReg_32Bit DF9:1;             /**< \brief [9:9] Diagnosis flag for alarm 9 belonging to alarm group i. - DF9 (rh) */
    Ifx_UReg_32Bit DF10:1;            /**< \brief [10:10] Diagnosis flag for alarm 10 belonging to alarm group i. - DF10 (rh) */
    Ifx_UReg_32Bit DF11:1;            /**< \brief [11:11] Diagnosis flag for alarm 11 belonging to alarm group i. - DF11 (rh) */
    Ifx_UReg_32Bit DF12:1;            /**< \brief [12:12] Diagnosis flag for alarm 12 belonging to alarm group i. - DF12 (rh) */
    Ifx_UReg_32Bit DF13:1;            /**< \brief [13:13] Diagnosis flag for alarm 13 belonging to alarm group i. - DF13 (rh) */
    Ifx_UReg_32Bit DF14:1;            /**< \brief [14:14] Diagnosis flag for alarm 14 belonging to alarm group i. - DF14 (rh) */
    Ifx_UReg_32Bit reserved_15:1;     /**< \brief [15:15] \internal Reserved */
    Ifx_UReg_32Bit reserved_16:1;     /**< \brief [16:16] \internal Reserved */
    Ifx_UReg_32Bit reserved_17:1;     /**< \brief [17:17] \internal Reserved */
    Ifx_UReg_32Bit reserved_18:1;     /**< \brief [18:18] \internal Reserved */
    Ifx_UReg_32Bit reserved_19:1;     /**< \brief [19:19] \internal Reserved */
    Ifx_UReg_32Bit reserved_20:1;     /**< \brief [20:20] \internal Reserved */
    Ifx_UReg_32Bit reserved_21:1;     /**< \brief [21:21] \internal Reserved */
    Ifx_UReg_32Bit DF22:1;            /**< \brief [22:22] Diagnosis flag for alarm 22 belonging to alarm group i. - DF22 (rh) */
    Ifx_UReg_32Bit DF23:1;            /**< \brief [23:23] Diagnosis flag for alarm 23 belonging to alarm group i. - DF23 (rh) */
    Ifx_UReg_32Bit DF24:1;            /**< \brief [24:24] Diagnosis flag for alarm 24 belonging to alarm group i. - DF24 (rh) */
    Ifx_UReg_32Bit reserved_25:1;     /**< \brief [25:25] \internal Reserved */
    Ifx_UReg_32Bit reserved_26:1;     /**< \brief [26:26] \internal Reserved */
    Ifx_UReg_32Bit reserved_27:1;     /**< \brief [27:27] \internal Reserved */
    Ifx_UReg_32Bit reserved_28:1;     /**< \brief [28:28] \internal Reserved */
    Ifx_UReg_32Bit reserved_29:1;     /**< \brief [29:29] \internal Reserved */
    Ifx_UReg_32Bit reserved_30:1;     /**< \brief [30:30] \internal Reserved */
    Ifx_UReg_32Bit reserved_31:1;     /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_AD_Bits;

/** \brief Alarm Executed Status Register */
typedef struct _Ifx_SMU_AEX_Bits
{
    Ifx_UReg_32Bit IRQ0STS:1;         /**< \brief [0:0] IRQ0 Request Status - IRQ0STS (rh) */
    Ifx_UReg_32Bit IRQ1STS:1;         /**< \brief [1:1] IRQ1 Request Status - IRQ1STS (rh) */
    Ifx_UReg_32Bit IRQ2STS:1;         /**< \brief [2:2] IRQ2 Request Status - IRQ2STS (rh) */
    Ifx_UReg_32Bit RST0STS:1;         /**< \brief [3:3] RST0 Request Status - RST0STS (rh) */
    Ifx_UReg_32Bit RST1STS:1;         /**< \brief [4:4] RST1 Request Status - RST1STS (rh) */
    Ifx_UReg_32Bit RST2STS:1;         /**< \brief [5:5] RST2 Request Status - RST2STS (rh) */
    Ifx_UReg_32Bit RST3STS:1;         /**< \brief [6:6] RST3 Request Status - RST3STS (rh) */
    Ifx_UReg_32Bit RST4STS:1;         /**< \brief [7:7] RST4 Request Status - RST4STS (rh) */
    Ifx_UReg_32Bit RST5STS:1;         /**< \brief [8:8] RST5 Request Status - RST5STS (rh) */
    Ifx_UReg_32Bit NMISTS:1;          /**< \brief [9:9] NMI Request Status - NMISTS (rh) */
    Ifx_UReg_32Bit reserved_10:1;     /**< \brief [10:10] \internal Reserved */
    Ifx_UReg_32Bit EMSSTS:1;          /**< \brief [11:11] EMS Request Status - EMSSTS (rh) */
    Ifx_UReg_32Bit reserved_12:4;     /**< \brief [15:12] \internal Reserved */
    Ifx_UReg_32Bit IRQ0AEM:1;         /**< \brief [16:16] IRQ0 AEM - IRQ0AEM (rh) */
    Ifx_UReg_32Bit IRQ1AEM:1;         /**< \brief [17:17] IRQ1 AEM - IRQ1AEM (rh) */
    Ifx_UReg_32Bit IRQ2AEM:1;         /**< \brief [18:18] IRQ2 AEM - IRQ2AEM (rh) */
    Ifx_UReg_32Bit RST0AEM:1;         /**< \brief [19:19] RST0 AEM - RST0AEM (rh) */
    Ifx_UReg_32Bit RST1AEM:1;         /**< \brief [20:20] RST1 AEM - RST1AEM (rh) */
    Ifx_UReg_32Bit RST2AEM:1;         /**< \brief [21:21] RST2 AEM - RST2AEM (rh) */
    Ifx_UReg_32Bit RST3AEM:1;         /**< \brief [22:22] RST3 AEM - RST3AEM (rh) */
    Ifx_UReg_32Bit RST4AEM:1;         /**< \brief [23:23] RST4 AEM - RST4AEM (rh) */
    Ifx_UReg_32Bit RST5AEM:1;         /**< \brief [24:24] RST5 AEM - RST5AEM (rh) */
    Ifx_UReg_32Bit NMIAEM:1;          /**< \brief [25:25] NMI AEM - NMIAEM (rh) */
    Ifx_UReg_32Bit reserved_26:1;     /**< \brief [26:26] \internal Reserved */
    Ifx_UReg_32Bit EMSAEM:1;          /**< \brief [27:27] EMS AEM - EMSAEM (rh) */
    Ifx_UReg_32Bit reserved_28:4;     /**< \brief [31:28] \internal Reserved */
} Ifx_SMU_AEX_Bits;

/** \brief Alarm Executed Status Clear Register */
typedef struct _Ifx_SMU_AEXCLR_Bits
{
    Ifx_Strict_32Bit IRQ0CLR:1;       /**< \brief [0:0] IRQ0 Request Status Clear - IRQ0CLR (w) */
    Ifx_Strict_32Bit IRQ1CLR:1;       /**< \brief [1:1] IRQ1 Request Status Clear - IRQ1CLR (w) */
    Ifx_Strict_32Bit IRQ2CLR:1;       /**< \brief [2:2] IRQ2 Request Status Clear - IRQ2CLR (w) */
    Ifx_Strict_32Bit RST0CLR:1;       /**< \brief [3:3] RST0 Request Status Clear - RST0CLR (w) */
    Ifx_Strict_32Bit RST1CLR:1;       /**< \brief [4:4] RST1 Request Status Clear - RST1CLR (w) */
    Ifx_Strict_32Bit RST2CLR:1;       /**< \brief [5:5] RST2 Request Status Clear - RST2CLR (w) */
    Ifx_Strict_32Bit RST3CLR:1;       /**< \brief [6:6] RST3 Request Status Clear - RST3CLR (w) */
    Ifx_Strict_32Bit RST4CLR:1;       /**< \brief [7:7] RST4 Request Status Clear - RST4CLR (w) */
    Ifx_Strict_32Bit RST5CLR:1;       /**< \brief [8:8] RST5 Request Status Clear - RST5CLR (w) */
    Ifx_Strict_32Bit NMICLR:1;        /**< \brief [9:9] NMI Request Status Clear - NMICLR (w) */
    Ifx_Strict_32Bit reserved_10:1;    /**< \brief [10:10] \internal Reserved */
    Ifx_Strict_32Bit EMSCLR:1;        /**< \brief [11:11] EMS Request Status Clear - EMSCLR (w) */
    Ifx_Strict_32Bit reserved_12:4;    /**< \brief [15:12] \internal Reserved */
    Ifx_Strict_32Bit IRQ0AEMCLR:1;    /**< \brief [16:16] IRQ0 AEM Status Clear - IRQ0AEMCLR (w) */
    Ifx_Strict_32Bit IRQ1AEMCLR:1;    /**< \brief [17:17] IRQ1 AEM Status Clear - IRQ1AEMCLR (w) */
    Ifx_Strict_32Bit IRQ2AEMCLR:1;    /**< \brief [18:18] IRQ2 AEM Status Clear - IRQ2AEMCLR (w) */
    Ifx_Strict_32Bit RST0AEMCLR:1;    /**< \brief [19:19] RST0 AEM Status Clear - RST0AEMCLR (w) */
    Ifx_Strict_32Bit RST1AEMCLR:1;    /**< \brief [20:20] RST1 AEM Status Clear - RST1AEMCLR (w) */
    Ifx_Strict_32Bit RST2AEMCLR:1;    /**< \brief [21:21] RST2 AEM Status Clear - RST2AEMCLR (w) */
    Ifx_Strict_32Bit RST3AEMCLR:1;    /**< \brief [22:22] RST3 AEM Status Clear - RST3AEMCLR (w) */
    Ifx_Strict_32Bit RST4AEMCLR:1;    /**< \brief [23:23] RST4 AEM Status Clear - RST4AEMCLR (w) */
    Ifx_Strict_32Bit RST5AEMCLR:1;    /**< \brief [24:24] RST5 AEM Status Clear - RST5AEMCLR (w) */
    Ifx_Strict_32Bit NMIAEMCLR:1;     /**< \brief [25:25] NMI AEM Status Clear - NMIAEMCLR (w) */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit EMSAEMCLR:1;     /**< \brief [27:27] EMS AEM Status Clear - EMSAEMCLR (w) */
    Ifx_Strict_32Bit reserved_28:4;    /**< \brief [31:28] \internal Reserved */
} Ifx_SMU_AEXCLR_Bits;

/** \brief Alarm and Fault Counter */
typedef struct _Ifx_SMU_AFCNT_Bits
{
    Ifx_UReg_32Bit FCNT:4;            /**< \brief [3:0] Fault Counter. - FCNT (rh) */
    Ifx_UReg_32Bit ACNT:12;           /**< \brief [15:4] Alarm Counter. - ACNT (rh) */
    Ifx_UReg_32Bit reserved_16:14;    /**< \brief [29:16] \internal Reserved */
    Ifx_UReg_32Bit FCO:1;             /**< \brief [30:30] Fault Counter Overflow. - FCO (rh) */
    Ifx_UReg_32Bit ACO:1;             /**< \brief [31:31] Alarm Counter Overflow. - ACO (rh) */
} Ifx_SMU_AFCNT_Bits;

/** \brief Alarm Status Register */
typedef struct _Ifx_SMU_AG_Bits
{
    Ifx_Strict_32Bit SF0:1;           /**< \brief [0:0] Status flag for alarm 0 belonging to alarm group i. - SF0 (rwh) */
    Ifx_Strict_32Bit SF1:1;           /**< \brief [1:1] Status flag for alarm 1 belonging to alarm group i. - SF1 (rwh) */
    Ifx_Strict_32Bit SF2:1;           /**< \brief [2:2] Status flag for alarm 2 belonging to alarm group i. - SF2 (rwh) */
    Ifx_Strict_32Bit reserved_3:1;    /**< \brief [3:3] \internal Reserved */
    Ifx_Strict_32Bit SF4:1;           /**< \brief [4:4] Status flag for alarm 4 belonging to alarm group i. - SF4 (rwh) */
    Ifx_Strict_32Bit SF5:1;           /**< \brief [5:5] Status flag for alarm 5 belonging to alarm group i. - SF5 (rwh) */
    Ifx_Strict_32Bit SF6:1;           /**< \brief [6:6] Status flag for alarm 6 belonging to alarm group i. - SF6 (rwh) */
    Ifx_Strict_32Bit SF7:1;           /**< \brief [7:7] Status flag for alarm 7 belonging to alarm group i. - SF7 (rwh) */
    Ifx_Strict_32Bit SF8:1;           /**< \brief [8:8] Status flag for alarm 8 belonging to alarm group i. - SF8 (rwh) */
    Ifx_Strict_32Bit SF9:1;           /**< \brief [9:9] Status flag for alarm 9 belonging to alarm group i. - SF9 (rwh) */
    Ifx_Strict_32Bit SF10:1;          /**< \brief [10:10] Status flag for alarm 10 belonging to alarm group i. - SF10 (rwh) */
    Ifx_Strict_32Bit SF11:1;          /**< \brief [11:11] Status flag for alarm 11 belonging to alarm group i. - SF11 (rwh) */
    Ifx_Strict_32Bit SF12:1;          /**< \brief [12:12] Status flag for alarm 12 belonging to alarm group i. - SF12 (rwh) */
    Ifx_Strict_32Bit SF13:1;          /**< \brief [13:13] Status flag for alarm 13 belonging to alarm group i. - SF13 (rwh) */
    Ifx_Strict_32Bit SF14:1;          /**< \brief [14:14] Status flag for alarm 14 belonging to alarm group i. - SF14 (rwh) */
    Ifx_Strict_32Bit reserved_15:1;    /**< \brief [15:15] \internal Reserved */
    Ifx_Strict_32Bit reserved_16:1;    /**< \brief [16:16] \internal Reserved */
    Ifx_Strict_32Bit reserved_17:1;    /**< \brief [17:17] \internal Reserved */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit reserved_19:1;    /**< \brief [19:19] \internal Reserved */
    Ifx_Strict_32Bit reserved_20:1;    /**< \brief [20:20] \internal Reserved */
    Ifx_Strict_32Bit reserved_21:1;    /**< \brief [21:21] \internal Reserved */
    Ifx_Strict_32Bit SF22:1;          /**< \brief [22:22] Status flag for alarm 22 belonging to alarm group i. - SF22 (rwh) */
    Ifx_Strict_32Bit SF23:1;          /**< \brief [23:23] Status flag for alarm 23 belonging to alarm group i. - SF23 (rwh) */
    Ifx_Strict_32Bit SF24:1;          /**< \brief [24:24] Status flag for alarm 24 belonging to alarm group i. - SF24 (rwh) */
    Ifx_Strict_32Bit reserved_25:1;    /**< \brief [25:25] \internal Reserved */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit reserved_27:1;    /**< \brief [27:27] \internal Reserved */
    Ifx_Strict_32Bit reserved_28:1;    /**< \brief [28:28] \internal Reserved */
    Ifx_Strict_32Bit reserved_29:1;    /**< \brief [29:29] \internal Reserved */
    Ifx_Strict_32Bit reserved_30:1;    /**< \brief [30:30] \internal Reserved */
    Ifx_Strict_32Bit reserved_31:1;    /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_AG_Bits;

/** \brief Alarm Global Configuration */
typedef struct _Ifx_SMU_AGC_Bits
{
    Ifx_Strict_32Bit IGCS0:3;         /**< \brief [2:0] Interrupt Generation Configuration Set 0 - IGCS0 (rw) */
    Ifx_Strict_32Bit reserved_3:1;    /**< \brief [3:3] \internal Reserved */
    Ifx_Strict_32Bit IGCS1:3;         /**< \brief [6:4] Interrupt Generation Configuration Set 1 - IGCS1 (rw) */
    Ifx_Strict_32Bit reserved_7:1;    /**< \brief [7:7] \internal Reserved */
    Ifx_Strict_32Bit IGCS2:3;         /**< \brief [10:8] Interrupt Generation Configuration Set 2 - IGCS2 (rw) */
    Ifx_Strict_32Bit reserved_11:5;    /**< \brief [15:11] \internal Reserved */
    Ifx_Strict_32Bit RCS:6;           /**< \brief [21:16] CPU Reset Configuration Set - RCS (rw) */
    Ifx_Strict_32Bit reserved_22:2;    /**< \brief [23:22] \internal Reserved */
    Ifx_Strict_32Bit PES:5;           /**< \brief [28:24] Port Emergency Stop - PES (rw) */
    Ifx_Strict_32Bit EFRST:1;         /**< \brief [29:29] Enable FAULT to RUN State Transition - EFRST (rw) */
    Ifx_Strict_32Bit reserved_30:2;    /**< \brief [31:30] \internal Reserved */
} Ifx_SMU_AGC_Bits;

/** \brief Alarm Configuration Register */
typedef struct _Ifx_SMU_AGCF_Bits
{
    Ifx_Strict_32Bit CF0:1;           /**< \brief [0:0] Configuration flag x (x=0-2) for alarm 0 belonging to alarm group i. - CF0 (rw) */
    Ifx_Strict_32Bit CF1:1;           /**< \brief [1:1] Configuration flag x (x=0-2) for alarm 1 belonging to alarm group i. - CF1 (rw) */
    Ifx_Strict_32Bit CF2:1;           /**< \brief [2:2] Configuration flag x (x=0-2) for alarm 2 belonging to alarm group i. - CF2 (rw) */
    Ifx_Strict_32Bit reserved_3:1;    /**< \brief [3:3] \internal Reserved */
    Ifx_Strict_32Bit CF4:1;           /**< \brief [4:4] Configuration flag x (x=0-2) for alarm 4 belonging to alarm group i. - CF4 (rw) */
    Ifx_Strict_32Bit CF5:1;           /**< \brief [5:5] Configuration flag x (x=0-2) for alarm 5 belonging to alarm group i. - CF5 (rw) */
    Ifx_Strict_32Bit CF6:1;           /**< \brief [6:6] Configuration flag x (x=0-2) for alarm 6 belonging to alarm group i. - CF6 (rw) */
    Ifx_Strict_32Bit CF7:1;           /**< \brief [7:7] Configuration flag x (x=0-2) for alarm 7 belonging to alarm group i. - CF7 (rw) */
    Ifx_Strict_32Bit CF8:1;           /**< \brief [8:8] Configuration flag x (x=0-2) for alarm 8 belonging to alarm group i. - CF8 (rw) */
    Ifx_Strict_32Bit CF9:1;           /**< \brief [9:9] Configuration flag x (x=0-2) for alarm 9 belonging to alarm group i. - CF9 (rw) */
    Ifx_Strict_32Bit CF10:1;          /**< \brief [10:10] Configuration flag x (x=0-2) for alarm 10 belonging to alarm group i. - CF10 (rw) */
    Ifx_Strict_32Bit CF11:1;          /**< \brief [11:11] Configuration flag x (x=0-2) for alarm 11 belonging to alarm group i. - CF11 (rw) */
    Ifx_Strict_32Bit CF12:1;          /**< \brief [12:12] Configuration flag x (x=0-2) for alarm 12 belonging to alarm group i. - CF12 (rw) */
    Ifx_Strict_32Bit CF13:1;          /**< \brief [13:13] Configuration flag x (x=0-2) for alarm 13 belonging to alarm group i. - CF13 (rw) */
    Ifx_Strict_32Bit CF14:1;          /**< \brief [14:14] Configuration flag x (x=0-2) for alarm 14 belonging to alarm group i. - CF14 (rw) */
    Ifx_Strict_32Bit reserved_15:1;    /**< \brief [15:15] \internal Reserved */
    Ifx_Strict_32Bit reserved_16:1;    /**< \brief [16:16] \internal Reserved */
    Ifx_Strict_32Bit reserved_17:1;    /**< \brief [17:17] \internal Reserved */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit reserved_19:1;    /**< \brief [19:19] \internal Reserved */
    Ifx_Strict_32Bit reserved_20:1;    /**< \brief [20:20] \internal Reserved */
    Ifx_Strict_32Bit reserved_21:1;    /**< \brief [21:21] \internal Reserved */
    Ifx_Strict_32Bit CF22:1;          /**< \brief [22:22] Configuration flag x (x=0-2) for alarm 22 belonging to alarm group i. - CF22 (rw) */
    Ifx_Strict_32Bit CF23:1;          /**< \brief [23:23] Configuration flag x (x=0-2) for alarm 23 belonging to alarm group i. - CF23 (rw) */
    Ifx_Strict_32Bit CF24:1;          /**< \brief [24:24] Configuration flag x (x=0-2) for alarm 24 belonging to alarm group i. - CF24 (rw) */
    Ifx_Strict_32Bit reserved_25:1;    /**< \brief [25:25] \internal Reserved */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit reserved_27:1;    /**< \brief [27:27] \internal Reserved */
    Ifx_Strict_32Bit reserved_28:1;    /**< \brief [28:28] \internal Reserved */
    Ifx_Strict_32Bit reserved_29:1;    /**< \brief [29:29] \internal Reserved */
    Ifx_Strict_32Bit reserved_30:1;    /**< \brief [30:30] \internal Reserved */
    Ifx_Strict_32Bit reserved_31:1;    /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_AGCF_Bits;

/** \brief SMU_core FSP Configuration Register */
typedef struct _Ifx_SMU_AGFSP_Bits
{
    Ifx_Strict_32Bit FE0:1;           /**< \brief [0:0] Fault signaling configuration flag for alarm 0 belonging to alarm group i. - FE0 (rw) */
    Ifx_Strict_32Bit FE1:1;           /**< \brief [1:1] Fault signaling configuration flag for alarm 1 belonging to alarm group i. - FE1 (rw) */
    Ifx_Strict_32Bit FE2:1;           /**< \brief [2:2] Fault signaling configuration flag for alarm 2 belonging to alarm group i. - FE2 (rw) */
    Ifx_Strict_32Bit reserved_3:1;    /**< \brief [3:3] \internal Reserved */
    Ifx_Strict_32Bit FE4:1;           /**< \brief [4:4] Fault signaling configuration flag for alarm 4 belonging to alarm group i. - FE4 (rw) */
    Ifx_Strict_32Bit FE5:1;           /**< \brief [5:5] Fault signaling configuration flag for alarm 5 belonging to alarm group i. - FE5 (rw) */
    Ifx_Strict_32Bit FE6:1;           /**< \brief [6:6] Fault signaling configuration flag for alarm 6 belonging to alarm group i. - FE6 (rw) */
    Ifx_Strict_32Bit FE7:1;           /**< \brief [7:7] Fault signaling configuration flag for alarm 7 belonging to alarm group i. - FE7 (rw) */
    Ifx_Strict_32Bit FE8:1;           /**< \brief [8:8] Fault signaling configuration flag for alarm 8 belonging to alarm group i. - FE8 (rw) */
    Ifx_Strict_32Bit FE9:1;           /**< \brief [9:9] Fault signaling configuration flag for alarm 9 belonging to alarm group i. - FE9 (rw) */
    Ifx_Strict_32Bit FE10:1;          /**< \brief [10:10] Fault signaling configuration flag for alarm 10 belonging to alarm group i. - FE10 (rw) */
    Ifx_Strict_32Bit FE11:1;          /**< \brief [11:11] Fault signaling configuration flag for alarm 11 belonging to alarm group i. - FE11 (rw) */
    Ifx_Strict_32Bit FE12:1;          /**< \brief [12:12] Fault signaling configuration flag for alarm 12 belonging to alarm group i. - FE12 (rw) */
    Ifx_Strict_32Bit FE13:1;          /**< \brief [13:13] Fault signaling configuration flag for alarm 13 belonging to alarm group i. - FE13 (rw) */
    Ifx_Strict_32Bit FE14:1;          /**< \brief [14:14] Fault signaling configuration flag for alarm 14 belonging to alarm group i. - FE14 (rw) */
    Ifx_Strict_32Bit reserved_15:1;    /**< \brief [15:15] \internal Reserved */
    Ifx_Strict_32Bit reserved_16:1;    /**< \brief [16:16] \internal Reserved */
    Ifx_Strict_32Bit reserved_17:1;    /**< \brief [17:17] \internal Reserved */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit reserved_19:1;    /**< \brief [19:19] \internal Reserved */
    Ifx_Strict_32Bit reserved_20:1;    /**< \brief [20:20] \internal Reserved */
    Ifx_Strict_32Bit reserved_21:1;    /**< \brief [21:21] \internal Reserved */
    Ifx_Strict_32Bit FE22:1;          /**< \brief [22:22] Fault signaling configuration flag for alarm 22 belonging to alarm group i. - FE22 (rw) */
    Ifx_Strict_32Bit FE23:1;          /**< \brief [23:23] Fault signaling configuration flag for alarm 23 belonging to alarm group i. - FE23 (rw) */
    Ifx_Strict_32Bit FE24:1;          /**< \brief [24:24] Fault signaling configuration flag for alarm 24 belonging to alarm group i. - FE24 (rw) */
    Ifx_Strict_32Bit reserved_25:1;    /**< \brief [25:25] \internal Reserved */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit reserved_27:1;    /**< \brief [27:27] \internal Reserved */
    Ifx_Strict_32Bit reserved_28:1;    /**< \brief [28:28] \internal Reserved */
    Ifx_Strict_32Bit reserved_29:1;    /**< \brief [29:29] \internal Reserved */
    Ifx_Strict_32Bit reserved_30:1;    /**< \brief [30:30] \internal Reserved */
    Ifx_Strict_32Bit reserved_31:1;    /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_AGFSP_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_SMU_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Sleep Mode Enable Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_SMU_CLC_Bits;

/** \brief Command Register */
typedef struct _Ifx_SMU_CMD_Bits
{
    Ifx_Strict_32Bit CMD:4;           /**< \brief [3:0] Implements the SMU_core Command Interface. - CMD (w) */
    Ifx_Strict_32Bit ARG:4;           /**< \brief [7:4] Implements the SMU_core Command Interface. - ARG (w) */
    Ifx_Strict_32Bit reserved_8:24;    /**< \brief [31:8] \internal Reserved */
} Ifx_SMU_CMD_Bits;

/** \brief Debug Register */
typedef struct _Ifx_SMU_DBG_Bits
{
    Ifx_UReg_32Bit SSM:2;             /**< \brief [1:0] Running state of the SMU_core State Machine - SSM (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_SMU_DBG_Bits;

/** \brief Fault Signaling Protocol */
typedef struct _Ifx_SMU_FSP_Bits
{
    Ifx_Strict_32Bit PRE1:3;          /**< \brief [2:0] Prescaler1 - PRE1 (rw) */
    Ifx_Strict_32Bit PRE2:2;          /**< \brief [4:3] Prescaler2 - PRE2 (rw) */
    Ifx_Strict_32Bit MODE:2;          /**< \brief [6:5] Fault Signaling Protocol configuration - MODE (rw) */
    Ifx_Strict_32Bit PES:1;           /**< \brief [7:7] Port Emergency Stop (PES) - PES (rw) */
    Ifx_Strict_32Bit TFSP_LOW:14;     /**< \brief [21:8] Specifies the FSP fault state duration - TFSP_LOW (r) */
    Ifx_Strict_32Bit TFSP_HIGH:10;    /**< \brief [31:22] Specifies the FSP fault state duration - TFSP_HIGH (rw) */
} Ifx_SMU_FSP_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_SMU_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number Value - MOD_NUMBER (r) */
} Ifx_SMU_ID_Bits;

/** \brief Key Register */
typedef struct _Ifx_SMU_KEYS_Bits
{
    Ifx_Strict_32Bit CFGLCK:8;        /**< \brief [7:0] Configuration Lock - CFGLCK (rw) */
    Ifx_Strict_32Bit PERLCK:8;        /**< \brief [15:8] Permanent Lock - PERLCK (rw) */
    Ifx_Strict_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_SMU_KEYS_Bits;

/** \brief OCDS Control and Status */
typedef struct _Ifx_SMU_OCS_Bits
{
    Ifx_UReg_32Bit TGS:2;             /**< \brief [1:0] Trigger Set for OTGB0/1 - TGS (rw) */
    Ifx_UReg_32Bit TGB:1;             /**< \brief [2:2] OTGB0/1 Bus Select - TGB (rw) */
    Ifx_UReg_32Bit TG_P:1;            /**< \brief [3:3] TGS, TGB Write Protection - TG_P (w) */
    Ifx_UReg_32Bit reserved_4:20;     /**< \brief [23:4] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_SMU_OCS_Bits;

/** \brief Port Control */
typedef struct _Ifx_SMU_PCTL_Bits
{
    Ifx_Strict_32Bit HWDIR:2;         /**< \brief [1:0] Port Direction. - HWDIR (rw) */
    Ifx_Strict_32Bit HWEN:2;          /**< \brief [3:2] Port Enable - HWEN (rw) */
    Ifx_Strict_32Bit GFSCU_EN:1;      /**< \brief [4:4] Glitch Filter for ErrorPin SMU_FSP0 to SCU enable - GFSCU_EN (rw) */
    Ifx_Strict_32Bit GFSTS_EN:1;      /**< \brief [5:5] Glitch Filter for ErrorPin SMU_FSP0 to register SMU_STS enable - GFSTS_EN (rw) */
    Ifx_Strict_32Bit reserved_6:1;    /**< \brief [6:6] \internal Reserved */
    Ifx_Strict_32Bit PCS:1;           /**< \brief [7:7] PAD Configuration Select - PCS (rw) */
    Ifx_Strict_32Bit reserved_8:6;    /**< \brief [13:8] \internal Reserved */
    Ifx_Strict_32Bit reserved_14:9;    /**< \brief [22:14] \internal Reserved */
    Ifx_Strict_32Bit reserved_23:9;    /**< \brief [31:23] \internal Reserved */
} Ifx_SMU_PCTL_Bits;

/** \brief Register Monitor Control */
typedef struct _Ifx_SMU_RMCTL_Bits
{
    Ifx_Strict_32Bit TE0:1;           /**< \brief [0:0] Test Enable. - TE0 (rw) */
    Ifx_Strict_32Bit TE1:1;           /**< \brief [1:1] Test Enable. - TE1 (rw) */
    Ifx_Strict_32Bit TE2:1;           /**< \brief [2:2] Test Enable. - TE2 (rw) */
    Ifx_Strict_32Bit TE3:1;           /**< \brief [3:3] Test Enable. - TE3 (rw) */
    Ifx_Strict_32Bit TE4:1;           /**< \brief [4:4] Test Enable. - TE4 (rw) */
    Ifx_Strict_32Bit TE5:1;           /**< \brief [5:5] Test Enable. - TE5 (rw) */
    Ifx_Strict_32Bit TE6:1;           /**< \brief [6:6] Test Enable. - TE6 (rw) */
    Ifx_Strict_32Bit TE7:1;           /**< \brief [7:7] Test Enable. - TE7 (rw) */
    Ifx_Strict_32Bit TE8:1;           /**< \brief [8:8] Test Enable. - TE8 (rw) */
    Ifx_Strict_32Bit TE9:1;           /**< \brief [9:9] Test Enable. - TE9 (rw) */
    Ifx_Strict_32Bit TE10:1;          /**< \brief [10:10] Test Enable. - TE10 (rw) */
    Ifx_Strict_32Bit reserved_11:1;    /**< \brief [11:11] \internal Reserved */
    Ifx_Strict_32Bit reserved_12:1;    /**< \brief [12:12] \internal Reserved */
    Ifx_Strict_32Bit reserved_13:1;    /**< \brief [13:13] \internal Reserved */
    Ifx_Strict_32Bit reserved_14:1;    /**< \brief [14:14] \internal Reserved */
    Ifx_Strict_32Bit reserved_15:1;    /**< \brief [15:15] \internal Reserved */
    Ifx_Strict_32Bit reserved_16:1;    /**< \brief [16:16] \internal Reserved */
    Ifx_Strict_32Bit reserved_17:1;    /**< \brief [17:17] \internal Reserved */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit reserved_19:1;    /**< \brief [19:19] \internal Reserved */
    Ifx_Strict_32Bit reserved_20:1;    /**< \brief [20:20] \internal Reserved */
    Ifx_Strict_32Bit reserved_21:1;    /**< \brief [21:21] \internal Reserved */
    Ifx_Strict_32Bit reserved_22:1;    /**< \brief [22:22] \internal Reserved */
    Ifx_Strict_32Bit reserved_23:1;    /**< \brief [23:23] \internal Reserved */
    Ifx_Strict_32Bit reserved_24:1;    /**< \brief [24:24] \internal Reserved */
    Ifx_Strict_32Bit reserved_25:1;    /**< \brief [25:25] \internal Reserved */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit reserved_27:1;    /**< \brief [27:27] \internal Reserved */
    Ifx_Strict_32Bit reserved_28:1;    /**< \brief [28:28] \internal Reserved */
    Ifx_Strict_32Bit reserved_29:1;    /**< \brief [29:29] \internal Reserved */
    Ifx_Strict_32Bit reserved_30:1;    /**< \brief [30:30] \internal Reserved */
    Ifx_Strict_32Bit reserved_31:1;    /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_RMCTL_Bits;

/** \brief Register Monitor Error Flags */
typedef struct _Ifx_SMU_RMEF_Bits
{
    Ifx_Strict_32Bit EF0:1;           /**< \brief [0:0] Status flag related to the different instances of the register monitor safety mechanism. - EF0 (rwh) */
    Ifx_Strict_32Bit EF1:1;           /**< \brief [1:1] Status flag related to the different instances of the register monitor safety mechanism. - EF1 (rwh) */
    Ifx_Strict_32Bit EF2:1;           /**< \brief [2:2] Status flag related to the different instances of the register monitor safety mechanism. - EF2 (rwh) */
    Ifx_Strict_32Bit EF3:1;           /**< \brief [3:3] Status flag related to the different instances of the register monitor safety mechanism. - EF3 (rwh) */
    Ifx_Strict_32Bit EF4:1;           /**< \brief [4:4] Status flag related to the different instances of the register monitor safety mechanism. - EF4 (rwh) */
    Ifx_Strict_32Bit EF5:1;           /**< \brief [5:5] Status flag related to the different instances of the register monitor safety mechanism. - EF5 (rwh) */
    Ifx_Strict_32Bit EF6:1;           /**< \brief [6:6] Status flag related to the different instances of the register monitor safety mechanism. - EF6 (rwh) */
    Ifx_Strict_32Bit EF7:1;           /**< \brief [7:7] Status flag related to the different instances of the register monitor safety mechanism. - EF7 (rwh) */
    Ifx_Strict_32Bit EF8:1;           /**< \brief [8:8] Status flag related to the different instances of the register monitor safety mechanism. - EF8 (rwh) */
    Ifx_Strict_32Bit EF9:1;           /**< \brief [9:9] Status flag related to the different instances of the register monitor safety mechanism. - EF9 (rwh) */
    Ifx_Strict_32Bit EF10:1;          /**< \brief [10:10] Status flag related to the different instances of the register monitor safety mechanism. - EF10 (rwh) */
    Ifx_Strict_32Bit reserved_11:1;    /**< \brief [11:11] \internal Reserved */
    Ifx_Strict_32Bit reserved_12:1;    /**< \brief [12:12] \internal Reserved */
    Ifx_Strict_32Bit reserved_13:1;    /**< \brief [13:13] \internal Reserved */
    Ifx_Strict_32Bit reserved_14:1;    /**< \brief [14:14] \internal Reserved */
    Ifx_Strict_32Bit reserved_15:1;    /**< \brief [15:15] \internal Reserved */
    Ifx_Strict_32Bit reserved_16:1;    /**< \brief [16:16] \internal Reserved */
    Ifx_Strict_32Bit reserved_17:1;    /**< \brief [17:17] \internal Reserved */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit reserved_19:1;    /**< \brief [19:19] \internal Reserved */
    Ifx_Strict_32Bit reserved_20:1;    /**< \brief [20:20] \internal Reserved */
    Ifx_Strict_32Bit reserved_21:1;    /**< \brief [21:21] \internal Reserved */
    Ifx_Strict_32Bit reserved_22:1;    /**< \brief [22:22] \internal Reserved */
    Ifx_Strict_32Bit reserved_23:1;    /**< \brief [23:23] \internal Reserved */
    Ifx_Strict_32Bit reserved_24:1;    /**< \brief [24:24] \internal Reserved */
    Ifx_Strict_32Bit reserved_25:1;    /**< \brief [25:25] \internal Reserved */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit reserved_27:1;    /**< \brief [27:27] \internal Reserved */
    Ifx_Strict_32Bit reserved_28:1;    /**< \brief [28:28] \internal Reserved */
    Ifx_Strict_32Bit reserved_29:1;    /**< \brief [29:29] \internal Reserved */
    Ifx_Strict_32Bit reserved_30:1;    /**< \brief [30:30] \internal Reserved */
    Ifx_Strict_32Bit reserved_31:1;    /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_RMEF_Bits;

/** \brief Register Monitor Self Test Status */
typedef struct _Ifx_SMU_RMSTS_Bits
{
    Ifx_Strict_32Bit STS0:1;          /**< \brief [0:0] Ready flag related to the different instances of the register monitor safety mechanism. - STS0 (rwh) */
    Ifx_Strict_32Bit STS1:1;          /**< \brief [1:1] Ready flag related to the different instances of the register monitor safety mechanism. - STS1 (rwh) */
    Ifx_Strict_32Bit STS2:1;          /**< \brief [2:2] Ready flag related to the different instances of the register monitor safety mechanism. - STS2 (rwh) */
    Ifx_Strict_32Bit STS3:1;          /**< \brief [3:3] Ready flag related to the different instances of the register monitor safety mechanism. - STS3 (rwh) */
    Ifx_Strict_32Bit STS4:1;          /**< \brief [4:4] Ready flag related to the different instances of the register monitor safety mechanism. - STS4 (rwh) */
    Ifx_Strict_32Bit STS5:1;          /**< \brief [5:5] Ready flag related to the different instances of the register monitor safety mechanism. - STS5 (rwh) */
    Ifx_Strict_32Bit STS6:1;          /**< \brief [6:6] Ready flag related to the different instances of the register monitor safety mechanism. - STS6 (rwh) */
    Ifx_Strict_32Bit STS7:1;          /**< \brief [7:7] Ready flag related to the different instances of the register monitor safety mechanism. - STS7 (rwh) */
    Ifx_Strict_32Bit STS8:1;          /**< \brief [8:8] Ready flag related to the different instances of the register monitor safety mechanism. - STS8 (rwh) */
    Ifx_Strict_32Bit STS9:1;          /**< \brief [9:9] Ready flag related to the different instances of the register monitor safety mechanism. - STS9 (rwh) */
    Ifx_Strict_32Bit STS10:1;         /**< \brief [10:10] Ready flag related to the different instances of the register monitor safety mechanism. - STS10 (rwh) */
    Ifx_Strict_32Bit reserved_11:1;    /**< \brief [11:11] \internal Reserved */
    Ifx_Strict_32Bit reserved_12:1;    /**< \brief [12:12] \internal Reserved */
    Ifx_Strict_32Bit reserved_13:1;    /**< \brief [13:13] \internal Reserved */
    Ifx_Strict_32Bit reserved_14:1;    /**< \brief [14:14] \internal Reserved */
    Ifx_Strict_32Bit reserved_15:1;    /**< \brief [15:15] \internal Reserved */
    Ifx_Strict_32Bit reserved_16:1;    /**< \brief [16:16] \internal Reserved */
    Ifx_Strict_32Bit reserved_17:1;    /**< \brief [17:17] \internal Reserved */
    Ifx_Strict_32Bit reserved_18:1;    /**< \brief [18:18] \internal Reserved */
    Ifx_Strict_32Bit reserved_19:1;    /**< \brief [19:19] \internal Reserved */
    Ifx_Strict_32Bit reserved_20:1;    /**< \brief [20:20] \internal Reserved */
    Ifx_Strict_32Bit reserved_21:1;    /**< \brief [21:21] \internal Reserved */
    Ifx_Strict_32Bit reserved_22:1;    /**< \brief [22:22] \internal Reserved */
    Ifx_Strict_32Bit reserved_23:1;    /**< \brief [23:23] \internal Reserved */
    Ifx_Strict_32Bit reserved_24:1;    /**< \brief [24:24] \internal Reserved */
    Ifx_Strict_32Bit reserved_25:1;    /**< \brief [25:25] \internal Reserved */
    Ifx_Strict_32Bit reserved_26:1;    /**< \brief [26:26] \internal Reserved */
    Ifx_Strict_32Bit reserved_27:1;    /**< \brief [27:27] \internal Reserved */
    Ifx_Strict_32Bit reserved_28:1;    /**< \brief [28:28] \internal Reserved */
    Ifx_Strict_32Bit reserved_29:1;    /**< \brief [29:29] \internal Reserved */
    Ifx_Strict_32Bit reserved_30:1;    /**< \brief [30:30] \internal Reserved */
    Ifx_Strict_32Bit reserved_31:1;    /**< \brief [31:31] \internal Reserved */
} Ifx_SMU_RMSTS_Bits;

/** \brief Recovery Timer 0 Alarm Configuration 0 */
typedef struct _Ifx_SMU_RTAC00_Bits
{
    Ifx_Strict_32Bit GID0:4;          /**< \brief [3:0] Group Index 0. - GID0 (rw) */
    Ifx_Strict_32Bit ALID0:5;         /**< \brief [8:4] Alarm Identifier 0. - ALID0 (rw) */
    Ifx_Strict_32Bit reserved_9:7;    /**< \brief [15:9] \internal Reserved */
    Ifx_Strict_32Bit GID1:4;          /**< \brief [19:16] Group Index 1. - GID1 (rw) */
    Ifx_Strict_32Bit ALID1:5;         /**< \brief [24:20] Alarm Identifier 1. - ALID1 (rw) */
    Ifx_Strict_32Bit reserved_25:7;    /**< \brief [31:25] \internal Reserved */
} Ifx_SMU_RTAC00_Bits;

/** \brief Recovery Timer 0 Alarm Configuration 1 */
typedef struct _Ifx_SMU_RTAC01_Bits
{
    Ifx_Strict_32Bit GID2:4;          /**< \brief [3:0] Group Index 2. - GID2 (rw) */
    Ifx_Strict_32Bit ALID2:5;         /**< \brief [8:4] Alarm Identifier 0. - ALID2 (rw) */
    Ifx_Strict_32Bit reserved_9:7;    /**< \brief [15:9] \internal Reserved */
    Ifx_Strict_32Bit GID3:4;          /**< \brief [19:16] Group Index 3. - GID3 (rw) */
    Ifx_Strict_32Bit ALID3:5;         /**< \brief [24:20] Alarm Identifier 1. - ALID3 (rw) */
    Ifx_Strict_32Bit reserved_25:7;    /**< \brief [31:25] \internal Reserved */
} Ifx_SMU_RTAC01_Bits;

/** \brief Recovery Timer 1 Alarm Configuration 0 */
typedef struct _Ifx_SMU_RTAC10_Bits
{
    Ifx_Strict_32Bit GID0:4;          /**< \brief [3:0] Group Index 0. - GID0 (rw) */
    Ifx_Strict_32Bit ALID0:5;         /**< \brief [8:4] Alarm Identifier 0. - ALID0 (rw) */
    Ifx_Strict_32Bit reserved_9:7;    /**< \brief [15:9] \internal Reserved */
    Ifx_Strict_32Bit GID1:4;          /**< \brief [19:16] Group Index 1. - GID1 (rw) */
    Ifx_Strict_32Bit ALID1:5;         /**< \brief [24:20] Alarm Identifier 1. - ALID1 (rw) */
    Ifx_Strict_32Bit reserved_25:7;    /**< \brief [31:25] \internal Reserved */
} Ifx_SMU_RTAC10_Bits;

/** \brief Recovery Timer 1 Alarm Configuration 1 */
typedef struct _Ifx_SMU_RTAC11_Bits
{
    Ifx_Strict_32Bit GID2:4;          /**< \brief [3:0] Group Index 2. - GID2 (rw) */
    Ifx_Strict_32Bit ALID2:5;         /**< \brief [8:4] Alarm Identifier 2. - ALID2 (rw) */
    Ifx_Strict_32Bit reserved_9:7;    /**< \brief [15:9] \internal Reserved */
    Ifx_Strict_32Bit GID3:4;          /**< \brief [19:16] Group Index 3. - GID3 (rw) */
    Ifx_Strict_32Bit ALID3:5;         /**< \brief [24:20] Alarm Identifier 3. - ALID3 (rw) */
    Ifx_Strict_32Bit reserved_25:7;    /**< \brief [31:25] \internal Reserved */
} Ifx_SMU_RTAC11_Bits;

/** \brief Recovery Timer Configuration */
typedef struct _Ifx_SMU_RTC_Bits
{
    Ifx_Strict_32Bit RT0E:1;          /**< \brief [0:0] RT0 Enable Bit - RT0E (rw) */
    Ifx_Strict_32Bit RT1E:1;          /**< \brief [1:1] RT1 Enable Bit - RT1E (rw) */
    Ifx_Strict_32Bit reserved_2:6;    /**< \brief [7:2] \internal Reserved */
    Ifx_Strict_32Bit RTD:24;          /**< \brief [31:8] Recovery Timer Duration - RTD (rw) */
} Ifx_SMU_RTC_Bits;

/** \brief Status Register */
typedef struct _Ifx_SMU_STS_Bits
{
    Ifx_Strict_32Bit CMD:4;           /**< \brief [3:0] Last command received - CMD (rwh) */
    Ifx_Strict_32Bit ARG:4;           /**< \brief [7:4] Last command argument received - ARG (rwh) */
    Ifx_Strict_32Bit RES:1;           /**< \brief [8:8] Result of last received command - RES (rwh) */
    Ifx_Strict_32Bit ASCE:1;          /**< \brief [9:9] Alarm Status Clear Enable - ASCE (rwh) */
    Ifx_Strict_32Bit FSP:2;           /**< \brief [11:10] Fault Signaling Protocol status - FSP (rh) */
    Ifx_Strict_32Bit FSTS:1;          /**< \brief [12:12] Fault State Timing Status - FSTS (rwh) */
    Ifx_Strict_32Bit reserved_13:3;    /**< \brief [15:13] \internal Reserved */
    Ifx_Strict_32Bit RTS0:1;          /**< \brief [16:16] Recovery Timer 0 Status - RTS0 (rwh) */
    Ifx_Strict_32Bit RTME0:1;         /**< \brief [17:17] Recovery Timer 0 Missed Event - RTME0 (rwh) */
    Ifx_Strict_32Bit RTS1:1;          /**< \brief [18:18] Recovery Timer 1 Status - RTS1 (rwh) */
    Ifx_Strict_32Bit RTME1:1;         /**< \brief [19:19] Recovery Timer 1 Missed Event - RTME1 (rwh) */
    Ifx_Strict_32Bit reserved_20:12;    /**< \brief [31:20] \internal Reserved */
} Ifx_SMU_STS_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_smu_Registers_union
 * \{   */
/** \brief SMU_core Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_ACCEN0_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_ACCEN0;

/** \brief SMU_core Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_ACCEN1_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_ACCEN1;

/** \brief Alarm Debug Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AD_Bits B;                /**< \brief Bitfield access */
} Ifx_SMU_AD;

/** \brief Alarm Executed Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AEX_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_AEX;

/** \brief Alarm Executed Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AEXCLR_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_AEXCLR;

/** \brief Alarm and Fault Counter   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AFCNT_Bits B;             /**< \brief Bitfield access */
} Ifx_SMU_AFCNT;

/** \brief Alarm Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AG_Bits B;                /**< \brief Bitfield access */
} Ifx_SMU_AG;

/** \brief Alarm Global Configuration   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AGC_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_AGC;

/** \brief Alarm Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AGCF_Bits B;              /**< \brief Bitfield access */
} Ifx_SMU_AGCF;

/** \brief SMU_core FSP Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_AGFSP_Bits B;             /**< \brief Bitfield access */
} Ifx_SMU_AGFSP;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_CLC_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_CLC;

/** \brief Command Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_CMD_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_CMD;

/** \brief Debug Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_DBG_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_DBG;

/** \brief Fault Signaling Protocol   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_FSP_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_FSP;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_ID_Bits B;                /**< \brief Bitfield access */
} Ifx_SMU_ID;

/** \brief Key Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_KEYS_Bits B;              /**< \brief Bitfield access */
} Ifx_SMU_KEYS;

/** \brief OCDS Control and Status   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_OCS_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_OCS;

/** \brief Port Control   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_PCTL_Bits B;              /**< \brief Bitfield access */
} Ifx_SMU_PCTL;

/** \brief Register Monitor Control   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RMCTL_Bits B;             /**< \brief Bitfield access */
} Ifx_SMU_RMCTL;

/** \brief Register Monitor Error Flags   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RMEF_Bits B;              /**< \brief Bitfield access */
} Ifx_SMU_RMEF;

/** \brief Register Monitor Self Test Status   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RMSTS_Bits B;             /**< \brief Bitfield access */
} Ifx_SMU_RMSTS;

/** \brief Recovery Timer 0 Alarm Configuration 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RTAC00_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_RTAC00;

/** \brief Recovery Timer 0 Alarm Configuration 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RTAC01_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_RTAC01;

/** \brief Recovery Timer 1 Alarm Configuration 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RTAC10_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_RTAC10;

/** \brief Recovery Timer 1 Alarm Configuration 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RTAC11_Bits B;            /**< \brief Bitfield access */
} Ifx_SMU_RTAC11;

/** \brief Recovery Timer Configuration   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_RTC_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_RTC;

/** \brief Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_SMU_STS_Bits B;               /**< \brief Bitfield access */
} Ifx_SMU_STS;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Smu_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief SMU object */
typedef volatile struct _Ifx_SMU
{
       Ifx_SMU_CLC                         CLC;                    /**< \brief 0, Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_SMU_ID                          ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[20];         /**< \brief C, \internal Reserved */
       Ifx_SMU_CMD                         CMD;                    /**< \brief 20, Command Register*/
       Ifx_SMU_STS                         STS;                    /**< \brief 24, Status Register*/
       Ifx_SMU_FSP                         FSP;                    /**< \brief 28, Fault Signaling Protocol*/
       Ifx_SMU_AGC                         AGC;                    /**< \brief 2C, Alarm Global Configuration*/
       Ifx_SMU_RTC                         RTC;                    /**< \brief 30, Recovery Timer Configuration*/
       Ifx_SMU_KEYS                        KEYS;                   /**< \brief 34, Key Register*/
       Ifx_SMU_DBG                         DBG;                    /**< \brief 38, Debug Register*/
       Ifx_SMU_PCTL                        PCTL;                   /**< \brief 3C, Port Control*/
       Ifx_SMU_AFCNT                       AFCNT;                  /**< \brief 40, Alarm and Fault Counter*/
       Ifx_UReg_8Bit                       reserved_44[28];        /**< \brief 44, \internal Reserved */
       Ifx_SMU_RTAC00                      RTAC00;                 /**< \brief 60, Recovery Timer 0 Alarm Configuration 0*/
       Ifx_SMU_RTAC01                      RTAC01;                 /**< \brief 64, Recovery Timer 0 Alarm Configuration 1*/
       Ifx_SMU_RTAC10                      RTAC10;                 /**< \brief 68, Recovery Timer 1 Alarm Configuration 0*/
       Ifx_SMU_RTAC11                      RTAC11;                 /**< \brief 6C, Recovery Timer 1 Alarm Configuration 1*/
       Ifx_SMU_AEX                         AEX;                    /**< \brief 70, Alarm Executed Status Register*/
       Ifx_SMU_AEXCLR                      AEXCLR;                 /**< \brief 74, Alarm Executed Status Clear Register*/
       Ifx_UReg_8Bit                       reserved_78[136];       /**< \brief 78, \internal Reserved */
       Ifx_SMU_AGCF                        AGCF[12][3];            /**< \brief 100, */
       Ifx_SMU_AGFSP                       AGFSP[12];              /**< \brief 190, SMU_core FSP Configuration Register*/
       Ifx_SMU_AG                          AG[12];                 /**< \brief 1C0, Alarm Status Register*/
       Ifx_UReg_8Bit                       reserved_1F0[16];       /**< \brief 1F0, \internal Reserved */
       Ifx_SMU_AD                          AD[12];                 /**< \brief 200, Alarm Debug Register*/
       Ifx_UReg_8Bit                       reserved_230[208];      /**< \brief 230, \internal Reserved */
       Ifx_SMU_RMCTL                       RMCTL;                  /**< \brief 300, Register Monitor Control*/
       Ifx_SMU_RMEF                        RMEF;                   /**< \brief 304, Register Monitor Error Flags*/
       Ifx_SMU_RMSTS                       RMSTS;                  /**< \brief 308, Register Monitor Self Test Status*/
       Ifx_UReg_8Bit                       reserved_30C[1244];     /**< \brief 30C, \internal Reserved */
       Ifx_SMU_OCS                         OCS;                    /**< \brief 7E8, OCDS Control and Status*/
       Ifx_UReg_8Bit                       reserved_7EC[12];       /**< \brief 7EC, \internal Reserved */
       Ifx_SMU_ACCEN1                      ACCEN1;                 /**< \brief 7F8, SMU_core Access Enable Register 1*/
       Ifx_SMU_ACCEN0                      ACCEN0;                 /**< \brief 7FC, SMU_core Access Enable Register 0*/
} Ifx_SMU;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXSMU_REGDEF_H */
