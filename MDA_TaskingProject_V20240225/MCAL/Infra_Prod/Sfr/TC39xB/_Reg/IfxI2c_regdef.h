/**
 * \file IfxI2c_regdef.h
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
 * \defgroup IfxSfr_I2c_Registers I2c Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_I2c_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_I2c_Registers
 * 
 * \defgroup IfxSfr_I2c_Registers_union Register unions
 * \ingroup IfxSfr_I2c_Registers
 * 
 * \defgroup IfxSfr_I2c_Registers_struct Memory map
 * \ingroup IfxSfr_I2c_Registers
 */
#ifndef IFXI2C_REGDEF_H
#define IFXI2C_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_I2c_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_I2C_ACCEN0_Bits
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
} Ifx_I2C_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_I2C_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_I2C_ACCEN1_Bits;

/** \brief Address Configuration Register */
typedef struct _Ifx_I2C_ADDRCFG_Bits
{
    Ifx_UReg_32Bit ADR:10;            /**< \brief [9:0] I2C-bus Device Address - ADR (rw) */
    Ifx_UReg_32Bit reserved_10:6;     /**< \brief [15:10] \internal Reserved */
    Ifx_UReg_32Bit TBAM:1;            /**< \brief [16:16] Ten Bit Address Mode - TBAM (rw) */
    Ifx_UReg_32Bit GCE:1;             /**< \brief [17:17] General Call Enable - GCE (rw) */
    Ifx_UReg_32Bit MCE:1;             /**< \brief [18:18] Master Code Enable - MCE (rw) */
    Ifx_UReg_32Bit MNS:1;             /**< \brief [19:19] Master / not Slave - MnS (rw) */
    Ifx_UReg_32Bit SONA:1;            /**< \brief [20:20] Stop on Not-acknowledge - SONA (rw) */
    Ifx_UReg_32Bit SOPE:1;            /**< \brief [21:21] Stop on Packet End - SOPE (rw) */
    Ifx_UReg_32Bit reserved_22:10;    /**< \brief [31:22] \internal Reserved */
} Ifx_I2C_ADDRCFG_Bits;

/** \brief Bus Status Register */
typedef struct _Ifx_I2C_BUSSTAT_Bits
{
    Ifx_UReg_32Bit BS:2;              /**< \brief [1:0] Bus Status - BS (rh) */
    Ifx_UReg_32Bit RNW:1;             /**< \brief [2:2] Read/not Write - RnW (rh) */
    Ifx_UReg_32Bit reserved_3:29;     /**< \brief [31:3] \internal Reserved */
} Ifx_I2C_BUSSTAT_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_I2C_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_I2C_CLC_Bits;

/** \brief Clock Control 1 Register */
typedef struct _Ifx_I2C_CLC1_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (rh) */
    Ifx_UReg_32Bit SPEN:1;            /**< \brief [2:2] Module Suspend Enable Bit for OCDS - SPEN (rw) */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] External Request Disable - EDIS (rw) */
    Ifx_UReg_32Bit SBWE:1;            /**< \brief [4:4] Module Suspend Bit Write Enable for OCDS - SBWE (w) */
    Ifx_UReg_32Bit FSOE:1;            /**< \brief [5:5] Fast Switch Off Enable - FSOE (rw) */
    Ifx_UReg_32Bit reserved_6:2;      /**< \brief [7:6] \internal Reserved */
    Ifx_UReg_32Bit RMC:8;             /**< \brief [15:8] Clock Divider for Standard Run Mode - RMC (rwh) */
    Ifx_UReg_32Bit reserved_16:8;     /**< \brief [23:16] \internal Reserved */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_I2C_CLC1_Bits;

/** \brief End Data Control Register */
typedef struct _Ifx_I2C_ENDDCTRL_Bits
{
    Ifx_UReg_32Bit SETRSC:1;          /**< \brief [0:0] Set Restart Condition - SETRSC (w) */
    Ifx_UReg_32Bit SETEND:1;          /**< \brief [1:1] Set End of Transmission - SETEND (w) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_I2C_ENDDCTRL_Bits;

/** \brief Error Interrupt Request Source Clear Register */
typedef struct _Ifx_I2C_ERRIRQSC_Bits
{
    Ifx_UReg_32Bit RXF_UFL:1;         /**< \brief [0:0] RX FIFO Underflow - RXF_UFL (w) */
    Ifx_UReg_32Bit RXF_OFL:1;         /**< \brief [1:1] RX FIFO Overflow - RXF_OFL (w) */
    Ifx_UReg_32Bit TXF_UFL:1;         /**< \brief [2:2] TX FIFO Underflow - TXF_UFL (w) */
    Ifx_UReg_32Bit TXF_OFL:1;         /**< \brief [3:3] TX FIFO Overflow - TXF_OFL (w) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_I2C_ERRIRQSC_Bits;

/** \brief Error Interrupt Request Source Mask Register */
typedef struct _Ifx_I2C_ERRIRQSM_Bits
{
    Ifx_UReg_32Bit RXF_UFL:1;         /**< \brief [0:0] RX FIFO Underflow - RXF_UFL (rw) */
    Ifx_UReg_32Bit RXF_OFL:1;         /**< \brief [1:1] RX FIFO Overflow - RXF_OFL (rw) */
    Ifx_UReg_32Bit TXF_UFL:1;         /**< \brief [2:2] TX FIFO Underflow - TXF_UFL (rw) */
    Ifx_UReg_32Bit TXF_OFL:1;         /**< \brief [3:3] TX FIFO Overflow - TXF_OFL (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_I2C_ERRIRQSM_Bits;

/** \brief Error Interrupt Request Source Status Register */
typedef struct _Ifx_I2C_ERRIRQSS_Bits
{
    Ifx_UReg_32Bit RXF_UFL:1;         /**< \brief [0:0] RX FIFO Underflow - RXF_UFL (rh) */
    Ifx_UReg_32Bit RXF_OFL:1;         /**< \brief [1:1] RX FIFO Overflow - RXF_OFL (rh) */
    Ifx_UReg_32Bit TXF_UFL:1;         /**< \brief [2:2] TX FIFO Underflow - TXF_UFL (rh) */
    Ifx_UReg_32Bit TXF_OFL:1;         /**< \brief [3:3] TX FIFO Overflow - TXF_OFL (rh) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_I2C_ERRIRQSS_Bits;

/** \brief Fractional Divider Configuration Register */
typedef struct _Ifx_I2C_FDIVCFG_Bits
{
    Ifx_UReg_32Bit DEC:11;            /**< \brief [10:0] Decrement Value of Fractional Divider - DEC (rw) */
    Ifx_UReg_32Bit reserved_11:5;     /**< \brief [15:11] \internal Reserved */
    Ifx_UReg_32Bit INC:8;             /**< \brief [23:16] Increment Value of Fractional Divider - INC (rw) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_I2C_FDIVCFG_Bits;

/** \brief Fractional Divider High-speed Mode Configuration Register */
typedef struct _Ifx_I2C_FDIVHIGHCFG_Bits
{
    Ifx_UReg_32Bit DEC:11;            /**< \brief [10:0] Decrement Value of Fractional Divider - DEC (rw) */
    Ifx_UReg_32Bit reserved_11:5;     /**< \brief [15:11] \internal Reserved */
    Ifx_UReg_32Bit INC:8;             /**< \brief [23:16] Increment Value of Fractional Divider - INC (rw) */
    Ifx_UReg_32Bit reserved_24:7;     /**< \brief [30:24] \internal Reserved */
    Ifx_UReg_32Bit reserved_31:1;     /**< \brief [31:31] \internal Reserved */
} Ifx_I2C_FDIVHIGHCFG_Bits;

/** \brief Filled FIFO Stages Status Register */
typedef struct _Ifx_I2C_FFSSTAT_Bits
{
    Ifx_UReg_32Bit FFS:6;             /**< \brief [5:0] Filled FIFO Stages - FFS (rh) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_I2C_FFSSTAT_Bits;

/** \brief FIFO Configuration Register */
typedef struct _Ifx_I2C_FIFOCFG_Bits
{
    Ifx_UReg_32Bit RXBS:2;            /**< \brief [1:0] RX Burst Size - RXBS (rw) */
    Ifx_UReg_32Bit reserved_2:2;      /**< \brief [3:2] \internal Reserved */
    Ifx_UReg_32Bit TXBS:2;            /**< \brief [5:4] TX Burst Size - TXBS (rw) */
    Ifx_UReg_32Bit reserved_6:2;      /**< \brief [7:6] \internal Reserved */
    Ifx_UReg_32Bit RXFA:2;            /**< \brief [9:8] RX FIFO Alignment - RXFA (rw) */
    Ifx_UReg_32Bit reserved_10:2;     /**< \brief [11:10] \internal Reserved */
    Ifx_UReg_32Bit TXFA:2;            /**< \brief [13:12] TX FIFO Alignment - TXFA (rw) */
    Ifx_UReg_32Bit reserved_14:2;     /**< \brief [15:14] \internal Reserved */
    Ifx_UReg_32Bit RXFC:1;            /**< \brief [16:16] RX FIFO Flow Control - RXFC (rw) */
    Ifx_UReg_32Bit TXFC:1;            /**< \brief [17:17] TX FIFO Flow Control - TXFC (rw) */
    Ifx_UReg_32Bit CRBC:1;            /**< \brief [18:18] Clear Request Behavior Configuration - CRBC (rw) */
    Ifx_UReg_32Bit reserved_19:13;    /**< \brief [31:19] \internal Reserved */
} Ifx_I2C_FIFOCFG_Bits;

/** \brief General Purpose Control Register */
typedef struct _Ifx_I2C_GPCTL_Bits
{
    Ifx_UReg_32Bit PISEL:3;           /**< \brief [2:0] Port Input Select - PISEL (rw) */
    Ifx_UReg_32Bit reserved_3:29;     /**< \brief [31:3] \internal Reserved */
} Ifx_I2C_GPCTL_Bits;

/** \brief Interrupt Clear Register */
typedef struct _Ifx_I2C_ICR_Bits
{
    Ifx_UReg_32Bit LSREQ_INT:1;       /**< \brief [0:0] Last Single Request Interrupt - LSREQ_INT (w) */
    Ifx_UReg_32Bit SREQ_INT:1;        /**< \brief [1:1] Single Request Interrupt - SREQ_INT (w) */
    Ifx_UReg_32Bit LBREQ_INT:1;       /**< \brief [2:2] Last Burst Request Interrupt - LBREQ_INT (w) */
    Ifx_UReg_32Bit BREQ_INT:1;        /**< \brief [3:3] Burst Request Interrupt - BREQ_INT (w) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_I2C_ICR_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_I2C_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_NUMBER:8;      /**< \brief [15:8] Module Number - MOD_NUMBER (r) */
    Ifx_UReg_32Bit reserved_16:16;    /**< \brief [31:16] \internal Reserved */
} Ifx_I2C_ID_Bits;

/** \brief Interrupt Mask Control Register */
typedef struct _Ifx_I2C_IMSC_Bits
{
    Ifx_UReg_32Bit LSREQ_INT:1;       /**< \brief [0:0] Last Single Request Interrupt - LSREQ_INT (rw) */
    Ifx_UReg_32Bit SREQ_INT:1;        /**< \brief [1:1] Single Request Interrupt - SREQ_INT (rw) */
    Ifx_UReg_32Bit LBREQ_INT:1;       /**< \brief [2:2] Last Burst Request Interrupt - LBREQ_INT (rw) */
    Ifx_UReg_32Bit BREQ_INT:1;        /**< \brief [3:3] Burst Request Interrupt - BREQ_INT (rw) */
    Ifx_UReg_32Bit I2C_ERR_INT:1;     /**< \brief [4:4] I2C Error Interrupt - I2C_ERR_INT (rw) */
    Ifx_UReg_32Bit I2C_P_INT:1;       /**< \brief [5:5] I2C Protocol Interrupt - I2C_P_INT (rw) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_I2C_IMSC_Bits;

/** \brief Interrupt Set Register */
typedef struct _Ifx_I2C_ISR_Bits
{
    Ifx_UReg_32Bit LSREQ_INT:1;       /**< \brief [0:0] Last Single Request Interrupt - LSREQ_INT (w) */
    Ifx_UReg_32Bit SREQ_INT:1;        /**< \brief [1:1] Single Request Interrupt - SREQ_INT (w) */
    Ifx_UReg_32Bit LBREQ_INT:1;       /**< \brief [2:2] Last Burst Request Interrupt - LBREQ_INT (w) */
    Ifx_UReg_32Bit BREQ_INT:1;        /**< \brief [3:3] Burst Request Interrupt - BREQ_INT (w) */
    Ifx_UReg_32Bit I2C_ERR_INT:1;     /**< \brief [4:4] I2C Error Interrupt - I2C_ERR_INT (w) */
    Ifx_UReg_32Bit I2C_P_INT:1;       /**< \brief [5:5] I2C Protocol Interrupt - I2C_P_INT (w) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_I2C_ISR_Bits;

/** \brief Kernel Reset Register 0 */
typedef struct _Ifx_I2C_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_I2C_KRST0_Bits;

/** \brief Kernel Reset Register 1 */
typedef struct _Ifx_I2C_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_I2C_KRST1_Bits;

/** \brief Kernel Reset Status Clear Register */
typedef struct _Ifx_I2C_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_I2C_KRSTCLR_Bits;

/** \brief Masked Interrupt Status Register */
typedef struct _Ifx_I2C_MIS_Bits
{
    Ifx_UReg_32Bit LSREQ_INT:1;       /**< \brief [0:0] Last Single Request Interrupt - LSREQ_INT (rh) */
    Ifx_UReg_32Bit SREQ_INT:1;        /**< \brief [1:1] Single Request Interrupt - SREQ_INT (rh) */
    Ifx_UReg_32Bit LBREQ_INT:1;       /**< \brief [2:2] Last Burst Request Interrupt - LBREQ_INT (rh) */
    Ifx_UReg_32Bit BREQ_INT:1;        /**< \brief [3:3] Burst Request Interrupt - BREQ_INT (rh) */
    Ifx_UReg_32Bit I2C_ERR_INT:1;     /**< \brief [4:4] I2C Error Interrupt - I2C_ERR_INT (rh) */
    Ifx_UReg_32Bit I2C_P_INT:1;       /**< \brief [5:5] I2C Protocol Interrupt - I2C_P_INT (rh) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_I2C_MIS_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_I2C_MODID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUMBER:16;     /**< \brief [31:16] Module Number Value - MOD_NUMBER (r) */
} Ifx_I2C_MODID_Bits;

/** \brief Maximum Received Packet Size Control Register */
typedef struct _Ifx_I2C_MRPSCTRL_Bits
{
    Ifx_UReg_32Bit MRPS:14;           /**< \brief [13:0] Maximum Received Packet Size - MRPS (rwh) */
    Ifx_UReg_32Bit reserved_14:18;    /**< \brief [31:14] \internal Reserved */
} Ifx_I2C_MRPSCTRL_Bits;

/** \brief Protocol Interrupt Request Source Clear Register */
typedef struct _Ifx_I2C_PIRQSC_Bits
{
    Ifx_UReg_32Bit AM:1;              /**< \brief [0:0] Address Match - AM (w) */
    Ifx_UReg_32Bit GC:1;              /**< \brief [1:1] General Call - GC (w) */
    Ifx_UReg_32Bit MC:1;              /**< \brief [2:2] Master Code - MC (w) */
    Ifx_UReg_32Bit AL:1;              /**< \brief [3:3] Arbitration Lost - AL (w) */
    Ifx_UReg_32Bit NACK:1;            /**< \brief [4:4] Not-acknowledge Received - NACK (w) */
    Ifx_UReg_32Bit TX_END:1;          /**< \brief [5:5] Transmission End - TX_END (w) */
    Ifx_UReg_32Bit RX:1;              /**< \brief [6:6] Receive Mode - RX (w) */
    Ifx_UReg_32Bit reserved_7:25;     /**< \brief [31:7] \internal Reserved */
} Ifx_I2C_PIRQSC_Bits;

/** \brief Protocol Interrupt Request Source Mask Register */
typedef struct _Ifx_I2C_PIRQSM_Bits
{
    Ifx_UReg_32Bit AM:1;              /**< \brief [0:0] Address Match - AM (rw) */
    Ifx_UReg_32Bit GC:1;              /**< \brief [1:1] General Call - GC (rw) */
    Ifx_UReg_32Bit MC:1;              /**< \brief [2:2] Master Code - MC (rw) */
    Ifx_UReg_32Bit AL:1;              /**< \brief [3:3] Arbitration Lost - AL (rw) */
    Ifx_UReg_32Bit NACK:1;            /**< \brief [4:4] Not-acknowledge Received - NACK (rw) */
    Ifx_UReg_32Bit TX_END:1;          /**< \brief [5:5] Transmission End - TX_END (rw) */
    Ifx_UReg_32Bit RX:1;              /**< \brief [6:6] Receive Mode - RX (rw) */
    Ifx_UReg_32Bit reserved_7:25;     /**< \brief [31:7] \internal Reserved */
} Ifx_I2C_PIRQSM_Bits;

/** \brief Protocol Interrupt Request Source Status Register */
typedef struct _Ifx_I2C_PIRQSS_Bits
{
    Ifx_UReg_32Bit AM:1;              /**< \brief [0:0] Address Match - AM (rh) */
    Ifx_UReg_32Bit GC:1;              /**< \brief [1:1] General Call - GC (rh) */
    Ifx_UReg_32Bit MC:1;              /**< \brief [2:2] Master Code - MC (rh) */
    Ifx_UReg_32Bit AL:1;              /**< \brief [3:3] Arbitration Lost - AL (rh) */
    Ifx_UReg_32Bit NACK:1;            /**< \brief [4:4] Not-acknowledge Received - NACK (rh) */
    Ifx_UReg_32Bit TX_END:1;          /**< \brief [5:5] Transmission End - TX_END (rh) */
    Ifx_UReg_32Bit RX:1;              /**< \brief [6:6] Receive Mode - RX (rh) */
    Ifx_UReg_32Bit reserved_7:25;     /**< \brief [31:7] \internal Reserved */
} Ifx_I2C_PIRQSS_Bits;

/** \brief Raw Interrupt Status Register */
typedef struct _Ifx_I2C_RIS_Bits
{
    Ifx_UReg_32Bit LSREQ_INT:1;       /**< \brief [0:0] Last Single Request Interrupt - LSREQ_INT (rh) */
    Ifx_UReg_32Bit SREQ_INT:1;        /**< \brief [1:1] Single Request Interrupt - SREQ_INT (rh) */
    Ifx_UReg_32Bit LBREQ_INT:1;       /**< \brief [2:2] Last Burst Request Interrupt - LBREQ_INT (rh) */
    Ifx_UReg_32Bit BREQ_INT:1;        /**< \brief [3:3] Burst Request Interrupt - BREQ_INT (rh) */
    Ifx_UReg_32Bit I2C_ERR_INT:1;     /**< \brief [4:4] I2C Error Interrupt - I2C_ERR_INT (rh) */
    Ifx_UReg_32Bit I2C_P_INT:1;       /**< \brief [5:5] I2C Protocol Interrupt - I2C_P_INT (rh) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_I2C_RIS_Bits;

/** \brief Received Packet Size Status Register */
typedef struct _Ifx_I2C_RPSSTAT_Bits
{
    Ifx_UReg_32Bit RPS:14;            /**< \brief [13:0] Received Packet Size - RPS (rh) */
    Ifx_UReg_32Bit reserved_14:18;    /**< \brief [31:14] \internal Reserved */
} Ifx_I2C_RPSSTAT_Bits;

/** \brief RUN Control Register */
typedef struct _Ifx_I2C_RUNCTRL_Bits
{
    Ifx_UReg_32Bit RUN:1;             /**< \brief [0:0] Enable I2C-bus Interface - RUN (rw) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_I2C_RUNCTRL_Bits;

/** \brief Reception Data Register */
typedef struct _Ifx_I2C_RXD_Bits
{
    Ifx_UReg_32Bit RXD:32;            /**< \brief [31:0] Reception Data - RXD (rh) */
} Ifx_I2C_RXD_Bits;

/** \brief Timing Configuration Register */
typedef struct _Ifx_I2C_TIMCFG_Bits
{
    Ifx_UReg_32Bit SDA_DEL_HD_DAT:6;    /**< \brief [5:0] SDA Delay Stages for Data Hold Time in Standard and Fast modes - SDA_DEL_HD_DAT (rw) */
    Ifx_UReg_32Bit HS_SDA_DEL_HD_DAT:3;    /**< \brief [8:6] SDA Delay Stages for Data Hold Time in High-speed Mode - HS_SDA_DEL_HD_DAT (rw) */
    Ifx_UReg_32Bit SCL_DEL_HD_STA:3;    /**< \brief [11:9] SCL Delay Stages for Hold Time Start (Restart) Bit - SCL_DEL_HD_STA (rw) */
    Ifx_UReg_32Bit reserved_12:2;     /**< \brief [13:12] \internal Reserved */
    Ifx_UReg_32Bit EN_SCL_LOW_LEN:1;    /**< \brief [14:14] Enable Direct Configuration of SCL Low Period Length in Fast Mode - EN_SCL_LOW_LEN (rw) */
    Ifx_UReg_32Bit FS_SCL_LOW:1;      /**< \brief [15:15] Set Fast Mode SCL Low Period Timing - FS_SCL_LOW (rw) */
    Ifx_UReg_32Bit HS_SDA_DEL:5;      /**< \brief [20:16] SDA Delay Stages for Start/Stop bit in High-speed Mode - HS_SDA_DEL (rw) */
    Ifx_UReg_32Bit reserved_21:3;     /**< \brief [23:21] \internal Reserved */
    Ifx_UReg_32Bit SCL_LOW_LEN:8;     /**< \brief [31:24] SCL Low Length in Fast Mode - SCL_LOW_LEN (rw) */
} Ifx_I2C_TIMCFG_Bits;

/** \brief Transmit Packet Size Control Register */
typedef struct _Ifx_I2C_TPSCTRL_Bits
{
    Ifx_UReg_32Bit TPS:14;            /**< \brief [13:0] Transmit Packet Size - TPS (rwh) */
    Ifx_UReg_32Bit reserved_14:18;    /**< \brief [31:14] \internal Reserved */
} Ifx_I2C_TPSCTRL_Bits;

/** \brief Transmission Data Register */
typedef struct _Ifx_I2C_TXD_Bits
{
    Ifx_UReg_32Bit TXD:32;            /**< \brief [31:0] Transmission Data - TXD (w) */
} Ifx_I2C_TXD_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_i2c_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ACCEN0_Bits B;            /**< \brief Bitfield access */
} Ifx_I2C_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ACCEN1_Bits B;            /**< \brief Bitfield access */
} Ifx_I2C_ACCEN1;

/** \brief Address Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ADDRCFG_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_ADDRCFG;

/** \brief Bus Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_BUSSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_BUSSTAT;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_CLC_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_CLC;

/** \brief Clock Control 1 Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_CLC1_Bits B;              /**< \brief Bitfield access */
} Ifx_I2C_CLC1;

/** \brief End Data Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ENDDCTRL_Bits B;          /**< \brief Bitfield access */
} Ifx_I2C_ENDDCTRL;

/** \brief Error Interrupt Request Source Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ERRIRQSC_Bits B;          /**< \brief Bitfield access */
} Ifx_I2C_ERRIRQSC;

/** \brief Error Interrupt Request Source Mask Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ERRIRQSM_Bits B;          /**< \brief Bitfield access */
} Ifx_I2C_ERRIRQSM;

/** \brief Error Interrupt Request Source Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ERRIRQSS_Bits B;          /**< \brief Bitfield access */
} Ifx_I2C_ERRIRQSS;

/** \brief Fractional Divider Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_FDIVCFG_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_FDIVCFG;

/** \brief Fractional Divider High-speed Mode Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_FDIVHIGHCFG_Bits B;       /**< \brief Bitfield access */
} Ifx_I2C_FDIVHIGHCFG;

/** \brief Filled FIFO Stages Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_FFSSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_FFSSTAT;

/** \brief FIFO Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_FIFOCFG_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_FIFOCFG;

/** \brief General Purpose Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_GPCTL_Bits B;             /**< \brief Bitfield access */
} Ifx_I2C_GPCTL;

/** \brief Interrupt Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ICR_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_ICR;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ID_Bits B;                /**< \brief Bitfield access */
} Ifx_I2C_ID;

/** \brief Interrupt Mask Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_IMSC_Bits B;              /**< \brief Bitfield access */
} Ifx_I2C_IMSC;

/** \brief Interrupt Set Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_ISR_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_ISR;

/** \brief Kernel Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_KRST0_Bits B;             /**< \brief Bitfield access */
} Ifx_I2C_KRST0;

/** \brief Kernel Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_KRST1_Bits B;             /**< \brief Bitfield access */
} Ifx_I2C_KRST1;

/** \brief Kernel Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_KRSTCLR_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_KRSTCLR;

/** \brief Masked Interrupt Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_MIS_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_MIS;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_MODID_Bits B;             /**< \brief Bitfield access */
} Ifx_I2C_MODID;

/** \brief Maximum Received Packet Size Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_MRPSCTRL_Bits B;          /**< \brief Bitfield access */
} Ifx_I2C_MRPSCTRL;

/** \brief Protocol Interrupt Request Source Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_PIRQSC_Bits B;            /**< \brief Bitfield access */
} Ifx_I2C_PIRQSC;

/** \brief Protocol Interrupt Request Source Mask Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_PIRQSM_Bits B;            /**< \brief Bitfield access */
} Ifx_I2C_PIRQSM;

/** \brief Protocol Interrupt Request Source Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_PIRQSS_Bits B;            /**< \brief Bitfield access */
} Ifx_I2C_PIRQSS;

/** \brief Raw Interrupt Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_RIS_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_RIS;

/** \brief Received Packet Size Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_RPSSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_RPSSTAT;

/** \brief RUN Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_RUNCTRL_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_RUNCTRL;

/** \brief Reception Data Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_RXD_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_RXD;

/** \brief Timing Configuration Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_TIMCFG_Bits B;            /**< \brief Bitfield access */
} Ifx_I2C_TIMCFG;

/** \brief Transmit Packet Size Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_TPSCTRL_Bits B;           /**< \brief Bitfield access */
} Ifx_I2C_TPSCTRL;

/** \brief Transmission Data Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_I2C_TXD_Bits B;               /**< \brief Bitfield access */
} Ifx_I2C_TXD;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_I2c_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief I2C object */
typedef volatile struct _Ifx_I2C
{
       Ifx_I2C_CLC1                        CLC1;                   /**< \brief 0, Clock Control 1 Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_I2C_ID                          ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[4];          /**< \brief C, \internal Reserved */
       Ifx_I2C_RUNCTRL                     RUNCTRL;                /**< \brief 10, RUN Control Register*/
       Ifx_I2C_ENDDCTRL                    ENDDCTRL;               /**< \brief 14, End Data Control Register*/
       Ifx_I2C_FDIVCFG                     FDIVCFG;                /**< \brief 18, Fractional Divider Configuration Register*/
       Ifx_I2C_FDIVHIGHCFG                 FDIVHIGHCFG;            /**< \brief 1C, Fractional Divider High-speed Mode Configuration Register*/
       Ifx_I2C_ADDRCFG                     ADDRCFG;                /**< \brief 20, Address Configuration Register*/
       Ifx_I2C_BUSSTAT                     BUSSTAT;                /**< \brief 24, Bus Status Register*/
       Ifx_I2C_FIFOCFG                     FIFOCFG;                /**< \brief 28, FIFO Configuration Register*/
       Ifx_I2C_MRPSCTRL                    MRPSCTRL;               /**< \brief 2C, Maximum Received Packet Size Control Register*/
       Ifx_I2C_RPSSTAT                     RPSSTAT;                /**< \brief 30, Received Packet Size Status Register*/
       Ifx_I2C_TPSCTRL                     TPSCTRL;                /**< \brief 34, Transmit Packet Size Control Register*/
       Ifx_I2C_FFSSTAT                     FFSSTAT;                /**< \brief 38, Filled FIFO Stages Status Register*/
       Ifx_UReg_8Bit                       reserved_3C[4];         /**< \brief 3C, \internal Reserved */
       Ifx_I2C_TIMCFG                      TIMCFG;                 /**< \brief 40, Timing Configuration Register*/
       Ifx_UReg_8Bit                       reserved_44[28];        /**< \brief 44, \internal Reserved */
       Ifx_I2C_ERRIRQSM                    ERRIRQSM;               /**< \brief 60, Error Interrupt Request Source Mask Register*/
       Ifx_I2C_ERRIRQSS                    ERRIRQSS;               /**< \brief 64, Error Interrupt Request Source Status Register*/
       Ifx_I2C_ERRIRQSC                    ERRIRQSC;               /**< \brief 68, Error Interrupt Request Source Clear Register*/
       Ifx_UReg_8Bit                       reserved_6C[4];         /**< \brief 6C, \internal Reserved */
       Ifx_I2C_PIRQSM                      PIRQSM;                 /**< \brief 70, Protocol Interrupt Request Source Mask Register*/
       Ifx_I2C_PIRQSS                      PIRQSS;                 /**< \brief 74, Protocol Interrupt Request Source Status Register*/
       Ifx_I2C_PIRQSC                      PIRQSC;                 /**< \brief 78, Protocol Interrupt Request Source Clear Register*/
       Ifx_UReg_8Bit                       reserved_7C[4];         /**< \brief 7C, \internal Reserved */
       Ifx_I2C_RIS                         RIS;                    /**< \brief 80, Raw Interrupt Status Register*/
       Ifx_I2C_IMSC                        IMSC;                   /**< \brief 84, Interrupt Mask Control Register*/
       Ifx_I2C_MIS                         MIS;                    /**< \brief 88, Masked Interrupt Status Register*/
       Ifx_I2C_ICR                         ICR;                    /**< \brief 8C, Interrupt Clear Register*/
       Ifx_I2C_ISR                         ISR;                    /**< \brief 90, Interrupt Set Register*/
       Ifx_UReg_8Bit                       reserved_94[32620];     /**< \brief 94, \internal Reserved */
       Ifx_I2C_TXD                         TXD;                    /**< \brief 8000, Transmission Data Register*/
       Ifx_UReg_8Bit                       reserved_8004[16380];    /**< \brief 8004, \internal Reserved */
       Ifx_I2C_RXD                         RXD;                    /**< \brief C000, Reception Data Register*/
       Ifx_UReg_8Bit                       reserved_C004[16380];    /**< \brief C004, \internal Reserved */
       Ifx_I2C_CLC                         CLC;                    /**< \brief 10000, Clock Control Register*/
       Ifx_I2C_MODID                       MODID;                  /**< \brief 10004, Module Identification Register*/
       Ifx_I2C_GPCTL                       GPCTL;                  /**< \brief 10008, General Purpose Control Register*/
       Ifx_I2C_ACCEN0                      ACCEN0;                 /**< \brief 1000C, Access Enable Register 0*/
       Ifx_I2C_ACCEN1                      ACCEN1;                 /**< \brief 10010, Access Enable Register 1*/
       Ifx_I2C_KRST0                       KRST0;                  /**< \brief 10014, Kernel Reset Register 0*/
       Ifx_I2C_KRST1                       KRST1;                  /**< \brief 10018, Kernel Reset Register 1*/
       Ifx_I2C_KRSTCLR                     KRSTCLR;                /**< \brief 1001C, Kernel Reset Status Clear Register*/
       Ifx_UReg_8Bit                       reserved_10020[222];    /**< \brief 10020, \internal Reserved */
} Ifx_I2C;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXI2C_REGDEF_H */
