/**
 * \file IfxHsct_regdef.h
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
 * \defgroup IfxSfr_Hsct_Registers Hsct Registers
 * \ingroup IfxSfr
 * 
 * \defgroup IfxSfr_Hsct_Registers_Bitfields Bitfields
 * \ingroup IfxSfr_Hsct_Registers
 * 
 * \defgroup IfxSfr_Hsct_Registers_union Register unions
 * \ingroup IfxSfr_Hsct_Registers
 * 
 * \defgroup IfxSfr_Hsct_Registers_struct Memory map
 * \ingroup IfxSfr_Hsct_Registers
 */
#ifndef IFXHSCT_REGDEF_H
#define IFXHSCT_REGDEF_H 1
/******************************************************************************/
#include "Ifx_TypesReg.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/


/** \addtogroup IfxSfr_Hsct_Registers_Bitfields
 * \{  */
/** \brief Access Enable Register 0 */
typedef struct _Ifx_HSCT_ACCEN0_Bits
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
} Ifx_HSCT_ACCEN0_Bits;

/** \brief Access Enable Register 1 */
typedef struct _Ifx_HSCT_ACCEN1_Bits
{
    Ifx_UReg_32Bit reserved_0:32;     /**< \brief [31:0] \internal Reserved */
} Ifx_HSCT_ACCEN1_Bits;

/** \brief Clock Control Register */
typedef struct _Ifx_HSCT_CLC_Bits
{
    Ifx_UReg_32Bit DISR:1;            /**< \brief [0:0] Module Disable Request Bit - DISR (rw) */
    Ifx_UReg_32Bit DISS:1;            /**< \brief [1:1] Module Disable Status Bit - DISS (r) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit EDIS:1;            /**< \brief [3:3] Chip System Sleep Mode Control - EDIS (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_HSCT_CLC_Bits;

/** \brief Configuration Physical Layer Register */
typedef struct _Ifx_HSCT_CONFIGPHY_Bits
{
    Ifx_UReg_32Bit PON:1;             /**< \brief [0:0] Physical Layer Power On. - PON (rw) */
    Ifx_UReg_32Bit reserved_1:15;     /**< \brief [15:1] \internal Reserved */
    Ifx_UReg_32Bit CORCEN:5;          /**< \brief [20:16] Correlator phase enable - allows to enable/disable each of the 5 Phase outputs separately. - CORCEN (rw) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_HSCT_CONFIGPHY_Bits;

/** \brief Clear To Send Control Register */
typedef struct _Ifx_HSCT_CTSCTRL_Bits
{
    Ifx_UReg_32Bit CTS_FRAME:1;       /**< \brief [0:0] Transmit CTS Frame Generation - CTS_FRAME (rw) */
    Ifx_UReg_32Bit CTS_TXD:1;         /**< \brief [1:1] Disable TX CTS signaling - CTS_TXD (rw) */
    Ifx_UReg_32Bit CTS_RXD:1;         /**< \brief [2:2] Disable RX CTS detection - CTS_RXD (rw) */
    Ifx_UReg_32Bit HSSL_CTS_FBD:1;    /**< \brief [3:3] Disable HSSL interface CTS Frame Blocking - HSSL_CTS_FBD (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_HSCT_CTSCTRL_Bits;

/** \brief Transmission Disable Register */
typedef struct _Ifx_HSCT_DISABLE_Bits
{
    Ifx_UReg_32Bit TX_DIS:1;          /**< \brief [0:0] Disable HSCT Transmit path in Master interface - TX_DIS (rw) */
    Ifx_UReg_32Bit RX_DIS:1;          /**< \brief [1:1] Disable HSCT Receive path in Master interface - RX_DIS (rw) */
    Ifx_UReg_32Bit RX_HEPD:1;         /**< \brief [2:2] Disable RX Header Error Discard Payload data. - RX_HEPD (rw) */
    Ifx_UReg_32Bit reserved_3:29;     /**< \brief [31:3] \internal Reserved */
} Ifx_HSCT_DISABLE_Bits;

/** \brief Module Identification Register */
typedef struct _Ifx_HSCT_ID_Bits
{
    Ifx_UReg_32Bit MOD_REV:8;         /**< \brief [7:0] Module Revision Number - MOD_REV (r) */
    Ifx_UReg_32Bit MOD_TYPE:8;        /**< \brief [15:8] Module Number Type - MOD_TYPE (r) */
    Ifx_UReg_32Bit MOD_NUM:16;        /**< \brief [31:16] Module Number for module identification - MOD_NUM (r) */
} Ifx_HSCT_ID_Bits;

/** \brief Interface Control Register */
typedef struct _Ifx_HSCT_IFCTRL_Bits
{
    Ifx_UReg_32Bit IFCVS:8;           /**< \brief [7:0] Master Mode - Trigger for Interface Control Value to be send to Slave interface - IFCVS (rw) */
    Ifx_UReg_32Bit SIFCV:1;           /**< \brief [8:8] Master Mode - Slave IF control frame trigger - SIFCV (w) */
    Ifx_UReg_32Bit reserved_9:7;      /**< \brief [15:9] \internal Reserved */
    Ifx_UReg_32Bit MRXSPEED:2;        /**< \brief [17:16] Master Mode RX speed - MRXSPEED (rw) */
    Ifx_UReg_32Bit MTXSPEED:2;        /**< \brief [19:18] Master Mode TX speed - MTXSPEED (rw) */
    Ifx_UReg_32Bit IFTESTMD:1;        /**< \brief [20:20] Interface TX Test Mode - IFTESTMD (rw) */
    Ifx_UReg_32Bit reserved_21:11;    /**< \brief [31:21] \internal Reserved */
} Ifx_HSCT_IFCTRL_Bits;

/** \brief Interface Status Register */
typedef struct _Ifx_HSCT_IFSTAT_Bits
{
    Ifx_UReg_32Bit RX_STAT:3;         /**< \brief [2:0] HSCT Slave interface Status for RX link - RX_STAT (rh) */
    Ifx_UReg_32Bit TX_STAT:2;         /**< \brief [4:3] HSCT Slave interface Status for TX link - TX_STAT (rh) */
    Ifx_UReg_32Bit TX_EN:1;           /**< \brief [5:5] HSCT LVDS Slave interface TX enable - TX_EN (rh) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_HSCT_IFSTAT_Bits;

/** \brief Initialization Register */
typedef struct _Ifx_HSCT_INIT_Bits
{
    Ifx_UReg_32Bit reserved_0:1;      /**< \brief [0:0] \internal Reserved */
    Ifx_UReg_32Bit SYS_CLK_EN:1;      /**< \brief [1:1] Enable HSCT SysClk in Master interface - SYS_CLK_EN (rw) */
    Ifx_UReg_32Bit reserved_2:1;      /**< \brief [2:2] \internal Reserved */
    Ifx_UReg_32Bit IFM:1;             /**< \brief [3:3] Select Interface Mode - IFM (rw) */
    Ifx_UReg_32Bit SRCF:2;            /**< \brief [5:4] Select Reference Clock Frequency Divider - SRCF (rw) */
    Ifx_UReg_32Bit SSCF:2;            /**< \brief [7:6] Select SysClk Frequency Divider - SSCF (rw) */
    Ifx_UReg_32Bit reserved_8:8;      /**< \brief [15:8] \internal Reserved */
    Ifx_UReg_32Bit TXHD:3;            /**< \brief [18:16] Transmit High Speed Divider. - TXHD (rw) */
    Ifx_UReg_32Bit RXHD:3;            /**< \brief [21:19] Receive High Speed Divider. - RXHD (rw) */
    Ifx_UReg_32Bit reserved_22:10;    /**< \brief [31:22] \internal Reserved */
} Ifx_HSCT_INIT_Bits;

/** \brief Interrupt register */
typedef struct _Ifx_HSCT_IRQ_Bits
{
    Ifx_UReg_32Bit reserved_0:1;      /**< \brief [0:0] \internal Reserved */
    Ifx_UReg_32Bit HER:1;             /**< \brief [1:1] Header error detected - HER (rh) */
    Ifx_UReg_32Bit PYER:1;            /**< \brief [2:2] Payload error detected - PYER (rh) */
    Ifx_UReg_32Bit CER:1;             /**< \brief [3:3] HSCT command error - CER (rh) */
    Ifx_UReg_32Bit IFCFS:1;           /**< \brief [4:4] HSCT interface control frame send - IFCFS (rh) */
    Ifx_UReg_32Bit SMER:1;            /**< \brief [5:5] Speed Mode Switch Error (Master Mode only) - SMER (rh) */
    Ifx_UReg_32Bit USMSF:1;           /**< \brief [6:6] Unsolicited message frame send finished - USMSF (rh) */
    Ifx_UReg_32Bit PLER:1;            /**< \brief [7:7] PLL lost lock error - PLER (rh) */
    Ifx_UReg_32Bit USM:1;             /**< \brief [8:8] Unsolicited Message Received - USM (rh) */
    Ifx_UReg_32Bit PAR:1;             /**< \brief [9:9] PING Answer Received - PAR (rh) */
    Ifx_UReg_32Bit TXTE:1;            /**< \brief [10:10] TX transfer error occurred on a disabled TX channel. - TXTE (rh) */
    Ifx_UReg_32Bit SFO:1;             /**< \brief [11:11] Synchronization FIFO overflow (in RX direction) - SFO (rh) */
    Ifx_UReg_32Bit SFU:1;             /**< \brief [12:12] Synchronization FIFO underflow (in TX direction) - SFU (rh) */
    Ifx_UReg_32Bit MSCE:1;            /**< \brief [13:13] Multi Slave scenario Command Error - MSCE (rh) */
    Ifx_UReg_32Bit reserved_14:18;    /**< \brief [31:14] \internal Reserved */
} Ifx_HSCT_IRQ_Bits;

/** \brief Interrupt Clear Register */
typedef struct _Ifx_HSCT_IRQCLR_Bits
{
    Ifx_UReg_32Bit reserved_0:1;      /**< \brief [0:0] \internal Reserved */
    Ifx_UReg_32Bit HERCLR:1;          /**< \brief [1:1] Header error detected interrupt clear - HERCLR (w) */
    Ifx_UReg_32Bit PYERCLR:1;         /**< \brief [2:2] Payload error detected interrupt clear - PYERCLR (w) */
    Ifx_UReg_32Bit CERCLR:1;          /**< \brief [3:3] HSCT command error interrupt clear - CERCLR (w) */
    Ifx_UReg_32Bit IFCFSCLR:1;        /**< \brief [4:4] HSCT interface control command send interrupt clear - IFCFSCLR (w) */
    Ifx_UReg_32Bit SMERCLR:1;         /**< \brief [5:5] Speed Mode Switch Error interrupt clear - SMERCLR (w) */
    Ifx_UReg_32Bit USMSFCLR:1;        /**< \brief [6:6] Unsolicited message frame send finished interrupt clear - USMSFCLR (w) */
    Ifx_UReg_32Bit PLERCLR:1;         /**< \brief [7:7] PLL lost lock error interrupt clear - PLERCLR (w) */
    Ifx_UReg_32Bit USMCLR:1;          /**< \brief [8:8] Unsolicited Message received clear - USMCLR (w) */
    Ifx_UReg_32Bit PARCLR:1;          /**< \brief [9:9] PING Answer received clear - PARCLR (w) */
    Ifx_UReg_32Bit TXTECLR:1;         /**< \brief [10:10] TX disable error interrupt clear - TXTECLR (w) */
    Ifx_UReg_32Bit SFOCLR:1;          /**< \brief [11:11] Synchronization FIFO overflow (in RX direction) interrupt clear - SFOCLR (w) */
    Ifx_UReg_32Bit SFUCLR:1;          /**< \brief [12:12] Synchronization FIFO underflow (in TX direction) interrupt clear - SFUCLR (w) */
    Ifx_UReg_32Bit MSCELR:1;          /**< \brief [13:13] Multi Slave scenario Command Error interrupt clear - MSCELR (w) */
    Ifx_UReg_32Bit reserved_14:18;    /**< \brief [31:14] \internal Reserved */
} Ifx_HSCT_IRQCLR_Bits;

/** \brief Interrupt Enable Register */
typedef struct _Ifx_HSCT_IRQEN_Bits
{
    Ifx_UReg_32Bit reserved_0:1;      /**< \brief [0:0] \internal Reserved */
    Ifx_UReg_32Bit HEREN:1;           /**< \brief [1:1] Header error detected interrupt enable - HEREN (rw) */
    Ifx_UReg_32Bit PYEREN:1;          /**< \brief [2:2] Payload error detected interrupt enable - PYEREN (rw) */
    Ifx_UReg_32Bit CEREN:1;           /**< \brief [3:3] HSCT command error interrupt enable - CEREN (rw) */
    Ifx_UReg_32Bit IFCFSEN:1;         /**< \brief [4:4] HSCT interface control command send enable - IFCFSEN (rw) */
    Ifx_UReg_32Bit SMEREN:1;          /**< \brief [5:5] Speed Mode Switch Error interrupt enable - SMEREN (rw) */
    Ifx_UReg_32Bit USMSFEN:1;         /**< \brief [6:6] Unsolicited message frame send finished - USMSFEN (rw) */
    Ifx_UReg_32Bit PLEREN:1;          /**< \brief [7:7] PLL lost lock error interrupt enable - PLEREN (rw) */
    Ifx_UReg_32Bit USMEN:1;           /**< \brief [8:8] Unsolicited Message received enable - USMEN (rw) */
    Ifx_UReg_32Bit PAREN:1;           /**< \brief [9:9] PING Answer Received enable - PAREN (rw) */
    Ifx_UReg_32Bit TXTEEN:1;          /**< \brief [10:10] TX disable error interrupt enable - TXTEEN (rw) */
    Ifx_UReg_32Bit SFOEN:1;           /**< \brief [11:11] Synchronization FIFO overflow (in RX direction) interrupt enable - SFOEN (rw) */
    Ifx_UReg_32Bit SFUEN:1;           /**< \brief [12:12] Synchronization FIFO underflow (in TX direction) interrupt enable - SFUEN (rw) */
    Ifx_UReg_32Bit MSCEEN:1;          /**< \brief [13:13] Multi Slave scenario Command Error interrupt enable - MSCEEN (rw) */
    Ifx_UReg_32Bit reserved_14:18;    /**< \brief [31:14] \internal Reserved */
} Ifx_HSCT_IRQEN_Bits;

/** \brief Reset Register 0 */
typedef struct _Ifx_HSCT_KRST0_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit RSTSTAT:1;         /**< \brief [1:1] Kernel Reset Status - RSTSTAT (rh) */
    Ifx_UReg_32Bit reserved_2:30;     /**< \brief [31:2] \internal Reserved */
} Ifx_HSCT_KRST0_Bits;

/** \brief Reset Register 1 */
typedef struct _Ifx_HSCT_KRST1_Bits
{
    Ifx_UReg_32Bit RST:1;             /**< \brief [0:0] Kernel Reset - RST (rwh) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_HSCT_KRST1_Bits;

/** \brief Reset Status Clear Register */
typedef struct _Ifx_HSCT_KRSTCLR_Bits
{
    Ifx_UReg_32Bit CLR:1;             /**< \brief [0:0] Kernel Reset Status Clear - CLR (w) */
    Ifx_UReg_32Bit reserved_1:31;     /**< \brief [31:1] \internal Reserved */
} Ifx_HSCT_KRSTCLR_Bits;

/** \brief OCDS Control and Status */
typedef struct _Ifx_HSCT_OCS_Bits
{
    Ifx_UReg_32Bit TGS:2;             /**< \brief [1:0] Trigger Set for OTGB0/1 - TGS (rw) */
    Ifx_UReg_32Bit TGB:1;             /**< \brief [2:2] OTGB0/1 Bus Select - TGB (rw) */
    Ifx_UReg_32Bit TG_P:1;            /**< \brief [3:3] TGS, TGB Write Protection - TG_P (w) */
    Ifx_UReg_32Bit reserved_4:20;     /**< \brief [23:4] \internal Reserved */
    Ifx_UReg_32Bit SUS:4;             /**< \brief [27:24] OCDS Suspend Control - SUS (rw) */
    Ifx_UReg_32Bit SUS_P:1;           /**< \brief [28:28] SUS Write Protection - SUS_P (w) */
    Ifx_UReg_32Bit SUSSTA:1;          /**< \brief [29:29] Suspend State - SUSSTA (rh) */
    Ifx_UReg_32Bit reserved_30:2;     /**< \brief [31:30] \internal Reserved */
} Ifx_HSCT_OCS_Bits;

/** \brief Sleep Control Register */
typedef struct _Ifx_HSCT_SLEEPCTRL_Bits
{
    Ifx_UReg_32Bit SLPEN:1;           /**< \brief [0:0] Sleep mode enabled - SLPEN (rw) */
    Ifx_UReg_32Bit SLPCLKG:1;         /**< \brief [1:1] Clock Gating in Sleep Mode - SLPCLKG (rw) */
    Ifx_UReg_32Bit reserved_2:14;     /**< \brief [15:2] \internal Reserved */
    Ifx_UReg_32Bit WKUPCNT:8;         /**< \brief [23:16] Counter Value for Determining the Wake-up Time of the LVDS Line Driver - WKUPCNT (rw) */
    Ifx_UReg_32Bit reserved_24:8;     /**< \brief [31:24] \internal Reserved */
} Ifx_HSCT_SLEEPCTRL_Bits;

/** \brief Status Register */
typedef struct _Ifx_HSCT_STAT_Bits
{
    Ifx_UReg_32Bit RX_PSIZE:3;        /**< \brief [2:0] RX (Receiving) Payload Size - RX_PSIZE (rh) */
    Ifx_UReg_32Bit RX_CHANNEL:4;      /**< \brief [6:3] RX (Receiving) Logical Channel Type - RX_CHANNEL (rh) */
    Ifx_UReg_32Bit RX_SLEEP:1;        /**< \brief [7:7] RX (Receiving) Sleep Mode Status - RX_SLEEP (rh) */
    Ifx_UReg_32Bit TX_SLEEP:1;        /**< \brief [8:8] TX (Transmission) Sleep Mode Status - TX_SLEEP (rh) */
    Ifx_UReg_32Bit reserved_9:3;      /**< \brief [11:9] \internal Reserved */
    Ifx_UReg_32Bit TX_PSIZE:3;        /**< \brief [14:12] Transmission Payload Size - TX_PSIZE (rh) */
    Ifx_UReg_32Bit reserved_15:1;     /**< \brief [15:15] \internal Reserved */
    Ifx_UReg_32Bit TX_CHANNEL_TYPE:4;    /**< \brief [19:16] Transmission Logical Channel Type - TX_CHANNEL_TYPE (rh) */
    Ifx_UReg_32Bit reserved_20:4;     /**< \brief [23:20] \internal Reserved */
    Ifx_UReg_32Bit LIFCCMDR:8;        /**< \brief [31:24] Last Interface Control Command Received - LIFCCMDR (rh) */
} Ifx_HSCT_STAT_Bits;

/** \brief STATPHY */
typedef struct _Ifx_HSCT_STATPHY_Bits
{
    Ifx_UReg_32Bit PLOCK:1;           /**< \brief [0:0] PLL locked - PLOCK (rh) */
    Ifx_UReg_32Bit reserved_1:1;      /**< \brief [1:1] \internal Reserved */
    Ifx_UReg_32Bit TXSA:2;            /**< \brief [3:2] Transmitter speed - TXSA (rh) */
    Ifx_UReg_32Bit RXSA:2;            /**< \brief [5:4] Receiver speed - RXSA (rh) */
    Ifx_UReg_32Bit reserved_6:26;     /**< \brief [31:6] \internal Reserved */
} Ifx_HSCT_STATPHY_Bits;

/** \brief Test Control Register */
typedef struct _Ifx_HSCT_TESTCTRL_Bits
{
    Ifx_UReg_32Bit TXENS:1;           /**< \brief [0:0] Enable Slave TX path (Slave interface mode only) - TXENS (w) */
    Ifx_UReg_32Bit TXDISS:1;          /**< \brief [1:1] Disable Slave TX path (Slave Interface mode only) - TXDISS (w) */
    Ifx_UReg_32Bit LLOPTXRX:1;        /**< \brief [2:2] LVDS loop back TX to RX enable - LLOPTXRX (rw) */
    Ifx_UReg_32Bit PRBSEN:1;          /**< \brief [3:3] PRBS Pattern enable - PRBSEN (rw) */
    Ifx_UReg_32Bit reserved_4:28;     /**< \brief [31:4] \internal Reserved */
} Ifx_HSCT_TESTCTRL_Bits;

/** \brief Unsolicited Status Message Received */
typedef struct _Ifx_HSCT_USMR_Bits
{
    Ifx_UReg_32Bit USMR:32;           /**< \brief [31:0] Unsolicited status message received - USMR (rh) */
} Ifx_HSCT_USMR_Bits;

/** \brief Unsolicited Status Message Send */
typedef struct _Ifx_HSCT_USMS_Bits
{
    Ifx_UReg_32Bit USMS:32;           /**< \brief [31:0] Unsolicited status message send - USMS (rw) */
} Ifx_HSCT_USMS_Bits;

/** \}  */
/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_hsct_Registers_union
 * \{   */
/** \brief Access Enable Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_ACCEN0_Bits B;           /**< \brief Bitfield access */
} Ifx_HSCT_ACCEN0;

/** \brief Access Enable Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_ACCEN1_Bits B;           /**< \brief Bitfield access */
} Ifx_HSCT_ACCEN1;

/** \brief Clock Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_CLC_Bits B;              /**< \brief Bitfield access */
} Ifx_HSCT_CLC;

/** \brief Configuration Physical Layer Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_CONFIGPHY_Bits B;        /**< \brief Bitfield access */
} Ifx_HSCT_CONFIGPHY;

/** \brief Clear To Send Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_CTSCTRL_Bits B;          /**< \brief Bitfield access */
} Ifx_HSCT_CTSCTRL;

/** \brief Transmission Disable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_DISABLE_Bits B;          /**< \brief Bitfield access */
} Ifx_HSCT_DISABLE;

/** \brief Module Identification Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_ID_Bits B;               /**< \brief Bitfield access */
} Ifx_HSCT_ID;

/** \brief Interface Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_IFCTRL_Bits B;           /**< \brief Bitfield access */
} Ifx_HSCT_IFCTRL;

/** \brief Interface Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_IFSTAT_Bits B;           /**< \brief Bitfield access */
} Ifx_HSCT_IFSTAT;

/** \brief Initialization Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_INIT_Bits B;             /**< \brief Bitfield access */
} Ifx_HSCT_INIT;

/** \brief Interrupt register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_IRQ_Bits B;              /**< \brief Bitfield access */
} Ifx_HSCT_IRQ;

/** \brief Interrupt Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_IRQCLR_Bits B;           /**< \brief Bitfield access */
} Ifx_HSCT_IRQCLR;

/** \brief Interrupt Enable Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_IRQEN_Bits B;            /**< \brief Bitfield access */
} Ifx_HSCT_IRQEN;

/** \brief Reset Register 0   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_KRST0_Bits B;            /**< \brief Bitfield access */
} Ifx_HSCT_KRST0;

/** \brief Reset Register 1   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_KRST1_Bits B;            /**< \brief Bitfield access */
} Ifx_HSCT_KRST1;

/** \brief Reset Status Clear Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_KRSTCLR_Bits B;          /**< \brief Bitfield access */
} Ifx_HSCT_KRSTCLR;

/** \brief OCDS Control and Status   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_OCS_Bits B;              /**< \brief Bitfield access */
} Ifx_HSCT_OCS;

/** \brief Sleep Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_SLEEPCTRL_Bits B;        /**< \brief Bitfield access */
} Ifx_HSCT_SLEEPCTRL;

/** \brief Status Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_STAT_Bits B;             /**< \brief Bitfield access */
} Ifx_HSCT_STAT;

/** \brief STATPHY   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_STATPHY_Bits B;          /**< \brief Bitfield access */
} Ifx_HSCT_STATPHY;

/** \brief Test Control Register   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_TESTCTRL_Bits B;         /**< \brief Bitfield access */
} Ifx_HSCT_TESTCTRL;

/** \brief Unsolicited Status Message Received   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_USMR_Bits B;             /**< \brief Bitfield access */
} Ifx_HSCT_USMR;

/** \brief Unsolicited Status Message Send   */
typedef union
{
    Ifx_UReg_32Bit U;                 /**< \brief Unsigned access */
    Ifx_SReg_32Bit I;                 /**< \brief Signed access */
    Ifx_HSCT_USMS_Bits B;             /**< \brief Bitfield access */
} Ifx_HSCT_USMS;

/** \}  */

/******************************************************************************/
/** \addtogroup IfxSfr_Hsct_Registers_struct
 * \{  */
/******************************************************************************/
/** \name Object L0
 * \{  */

/** \brief HSCT object */
typedef volatile struct _Ifx_HSCT
{
       Ifx_HSCT_CLC                        CLC;                    /**< \brief 0, Clock Control Register*/
       Ifx_UReg_8Bit                       reserved_4[4];          /**< \brief 4, \internal Reserved */
       Ifx_HSCT_ID                         ID;                     /**< \brief 8, Module Identification Register*/
       Ifx_UReg_8Bit                       reserved_C[4];          /**< \brief C, \internal Reserved */
       Ifx_HSCT_INIT                       INIT;                   /**< \brief 10, Initialization Register*/
       Ifx_HSCT_IFCTRL                     IFCTRL;                 /**< \brief 14, Interface Control Register*/
       Ifx_HSCT_SLEEPCTRL                  SLEEPCTRL;              /**< \brief 18, Sleep Control Register*/
       Ifx_HSCT_CTSCTRL                    CTSCTRL;                /**< \brief 1C, Clear To Send Control Register*/
       Ifx_HSCT_DISABLE                    DISABLE;                /**< \brief 20, Transmission Disable Register*/
       Ifx_HSCT_STAT                       STAT;                   /**< \brief 24, Status Register*/
       Ifx_HSCT_IFSTAT                     IFSTAT;                 /**< \brief 28, Interface Status Register*/
       Ifx_UReg_8Bit                       reserved_2C[4];         /**< \brief 2C, \internal Reserved */
       Ifx_HSCT_CONFIGPHY                  CONFIGPHY;              /**< \brief 30, Configuration Physical Layer Register*/
       Ifx_HSCT_STATPHY                    STATPHY;                /**< \brief 34, STATPHY*/
       Ifx_UReg_8Bit                       reserved_38[8];         /**< \brief 38, \internal Reserved */
       Ifx_HSCT_IRQ                        IRQ;                    /**< \brief 40, Interrupt register*/
       Ifx_HSCT_IRQEN                      IRQEN;                  /**< \brief 44, Interrupt Enable Register*/
       Ifx_HSCT_IRQCLR                     IRQCLR;                 /**< \brief 48, Interrupt Clear Register*/
       Ifx_UReg_8Bit                       reserved_4C[4];         /**< \brief 4C, \internal Reserved */
       Ifx_HSCT_USMR                       USMR;                   /**< \brief 50, Unsolicited Status Message Received*/
       Ifx_HSCT_USMS                       USMS;                   /**< \brief 54, Unsolicited Status Message Send*/
       Ifx_UReg_8Bit                       reserved_58[8];         /**< \brief 58, \internal Reserved */
       Ifx_HSCT_TESTCTRL                   TESTCTRL;               /**< \brief 60, Test Control Register*/
       Ifx_UReg_8Bit                       reserved_64[65412];     /**< \brief 64, \internal Reserved */
       Ifx_HSCT_OCS                        OCS;                    /**< \brief FFE8, OCDS Control and Status*/
       Ifx_HSCT_KRSTCLR                    KRSTCLR;                /**< \brief FFEC, Reset Status Clear Register*/
       Ifx_HSCT_KRST1                      KRST1;                  /**< \brief FFF0, Reset Register 1*/
       Ifx_HSCT_KRST0                      KRST0;                  /**< \brief FFF4, Reset Register 0*/
       Ifx_HSCT_ACCEN1                     ACCEN1;                 /**< \brief FFF8, Access Enable Register 1*/
       Ifx_HSCT_ACCEN0                     ACCEN0;                 /**< \brief FFFC, Access Enable Register 0*/
} Ifx_HSCT;

/** \}  */
/******************************************************************************/
/** \}  */


/******************************************************************************/

/******************************************************************************/

#endif /* IFXHSCT_REGDEF_H */
