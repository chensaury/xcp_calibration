
/*******************************************************************************
**                                                                            **
** Copyright (C) Infineon Technologies (2018)                                 **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to Infineon       **
** Technologies. Passing on and copying of this document, and communication   **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME  : Dio_Cfg.h                                                     **
**                                                                            **
**  VERSION   : 1.0.0                                                         **
**                                                                            **
**  DATE, TIME: 2023-03-21, 20:00:22                                      **
**                                                                            **
**  GENERATOR : Build b170330-0431                                          ** 
**                                                                            **
**  BSW MODULE DECRIPTION : Dio.bmd                                           **
**                                                                            **
**  VARIANT   : Variant LT                                                    **
**                                                                            **
**  PLATFORM  : Infineon AURIX2G                                              **
**                                                                            **
**  AUTHOR    : DL-AUTOSAR-Engineering                                        **
**                                                                            **
**  VENDOR    : Infineon Technologies                                         **
**                                                                            **
**  DESCRIPTION  : Dio configuration generated out of ECUC file               **
**                                                                            **
**  SPECIFICATION(S) : Specification of Dio Driver, AUTOSAR Release 4.2.2     **
**                                                                            **
**  MAY BE CHANGED BY USER : no                                               **
**                                                                            **
*******************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H
/*
 Notes:
 - The runtime configuration is handled by the Port Driver Module.
 - The configuration and usage of the DIO Driver Module is adapted to
   the microcontroller and ECU.

*/

/*Version check macros */
#define DIO_AR_RELEASE_MAJOR_VERSION     (4U)
#define DIO_AR_RELEASE_MINOR_VERSION     (2U)
#define DIO_AR_RELEASE_REVISION_VERSION  (2U)


#define DIO_SW_MAJOR_VERSION  (3U)
#define DIO_SW_MINOR_VERSION  (0U)
#define DIO_SW_PATCH_VERSION  (0U)

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/

/*******************************************************************************
**                      Global Macro Definitions                              **
*******************************************************************************/

/*                          Container: DioGeneral                            */
/*

  Pre-processor switch to enable/disable detection of Development errors.
  - if defined ON, Development error detection is enabled
  - if defined OFF, Development error detection is disabled
*/
 /* [cover parentID={77FB036C-3267-4076-BF13-2B2A1E6213E3}] [/cover]*/
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/*
  Pre-Compiler switch to include the API Dio_GetVersionInfo()
  - if defined ON, Dio_GetVersionInfo API available
  - if defined OFF, Dio_GetVersionInfo API not available
*/
#define DIO_VERSION_INFO_API                (STD_OFF)

/*
  Pre-Compiler switch to include the API Dio_FlipChannel()
  - if defined ON, Dio_FlipChannel API available
  - if defined OFF, Dio_FlipChannel API not available
*/
#define DIO_FLIP_CHANNEL_API                (STD_OFF)

/*
  Pre-Compiler switch to include the Safety Check
*/  
#define DIO_SAFETY_ENABLE                (STD_ON)

/* The following macros are available only if development error detection
    is enabled */
/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
#define DIO_PORTS_AVAILABLE_00_31           (0x00f0fc07U)

/* Definition to specify the ports available on the microcontroller
   Bit value = 0 implies the port is not available
   Bit value = 1 implies the port is available
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 31 is for Port 63 */
#define DIO_PORTS_AVAILABLE_32_63           (0x00000107U)

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 0, Bit 1 is for Port 1, ... , Bit 31 is for Port 31 */
#define DIO_PORTS_READONLY_00_31             (0x00000000U)

/* Definition to specify the ports that are read only ports on the
   microcontroller
   Bit value = 0 implies the port readable/writable
   Bit value = 1 implies the port is read only port
   Bit 0 is for Port 32, Bit 1 is for Port 33, ... , Bit 31 is for Port 63 */
#define DIO_PORTS_READONLY_32_63             (0x00000100U)

/* Value of the most significant pin on the port
   Note: In case of no pins on a port, the value is kept 0 */
#define DIO_PORT_0_MSPIN                     (12U)
#define DIO_PORT_1_MSPIN                     (7U)
#define DIO_PORT_2_MSPIN                     (11U)
#define DIO_PORT_3_MSPIN                     (0U)
#define DIO_PORT_4_MSPIN                     (0U)
#define DIO_PORT_5_MSPIN                     (0U)
#define DIO_PORT_6_MSPIN                     (0U)
#define DIO_PORT_7_MSPIN                     (0U)
#define DIO_PORT_8_MSPIN                     (0U)
#define DIO_PORT_9_MSPIN                     (0U)
#define DIO_PORT_10_MSPIN                     (8U)
#define DIO_PORT_11_MSPIN                     (15U)
#define DIO_PORT_12_MSPIN                     (1U)
#define DIO_PORT_13_MSPIN                     (3U)
#define DIO_PORT_14_MSPIN                     (10U)
#define DIO_PORT_15_MSPIN                     (8U)
#define DIO_PORT_16_MSPIN                     (0U)
#define DIO_PORT_17_MSPIN                     (0U)
#define DIO_PORT_18_MSPIN                     (0U)
#define DIO_PORT_19_MSPIN                     (0U)
#define DIO_PORT_20_MSPIN                     (14U)
#define DIO_PORT_21_MSPIN                     (7U)
#define DIO_PORT_22_MSPIN                     (11U)
#define DIO_PORT_23_MSPIN                     (7U)
#define DIO_PORT_24_MSPIN                     (0U)
#define DIO_PORT_25_MSPIN                     (0U)
#define DIO_PORT_26_MSPIN                     (0U)
#define DIO_PORT_27_MSPIN                     (0U)
#define DIO_PORT_28_MSPIN                     (0U)
#define DIO_PORT_29_MSPIN                     (0U)
#define DIO_PORT_30_MSPIN                     (0U)
#define DIO_PORT_31_MSPIN                     (0U)
#define DIO_PORT_32_MSPIN                     (7U)
#define DIO_PORT_33_MSPIN                     (15U)
#define DIO_PORT_34_MSPIN                     (5U)
#define DIO_PORT_35_MSPIN                     (0U)
#define DIO_PORT_36_MSPIN                     (0U)
#define DIO_PORT_37_MSPIN                     (0U)
#define DIO_PORT_38_MSPIN                     (0U)
#define DIO_PORT_39_MSPIN                     (0U)
#define DIO_PORT_40_MSPIN                     (14U)


/* Macro to define the maximum port available */
#define MAX_AVAILABLE_PORT                  (40U)

/* Values to mask the undefined port pins within a port */
#define DIO_MASK_ALL_PINS_PORT0             (0x1fffU)
#define DIO_MASK_ALL_PINS_PORT1             (0x00f8U)
#define DIO_MASK_ALL_PINS_PORT2             (0x0fffU)
#define DIO_MASK_ALL_PINS_PORT3             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT4             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT5             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT6             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT7             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT8             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT9             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT10             (0x01ffU)
#define DIO_MASK_ALL_PINS_PORT11             (0xffffU)
#define DIO_MASK_ALL_PINS_PORT12             (0x0003U)
#define DIO_MASK_ALL_PINS_PORT13             (0x000fU)
#define DIO_MASK_ALL_PINS_PORT14             (0x07ffU)
#define DIO_MASK_ALL_PINS_PORT15             (0x01ffU)
#define DIO_MASK_ALL_PINS_PORT16             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT17             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT18             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT19             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT20             (0x7fcfU)
#define DIO_MASK_ALL_PINS_PORT21             (0x00ffU)
#define DIO_MASK_ALL_PINS_PORT22             (0x0fffU)
#define DIO_MASK_ALL_PINS_PORT23             (0x00ffU)
#define DIO_MASK_ALL_PINS_PORT24             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT25             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT26             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT27             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT28             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT29             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT30             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT31             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT32             (0x00ffU)
#define DIO_MASK_ALL_PINS_PORT33             (0xffffU)
#define DIO_MASK_ALL_PINS_PORT34             (0x003eU)
#define DIO_MASK_ALL_PINS_PORT35             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT36             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT37             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT38             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT39             (0x0000U)
#define DIO_MASK_ALL_PINS_PORT40             (0x7fffU)

/* Macro to define the No of channel groups configured */
#define DIO_CHANNELGROUPCOUNT               (0U)


/*******************************************************************************
**                           Global Symbols                                   **
*******************************************************************************/

/*
 Symbolic names for DIO Channels, Port & Channel groups
*/

/*
                       Symbolic names for Channels
*/
#define DIO_CHANNEL_0_0                    ((Dio_ChannelType)0x000)
#define DIO_CHANNEL_0_1                    ((Dio_ChannelType)0x001)
#define DIO_CHANNEL_0_2                    ((Dio_ChannelType)0x002)
#define DIO_CHANNEL_0_3                    ((Dio_ChannelType)0x003)
#define DIO_CHANNEL_0_4                    ((Dio_ChannelType)0x004)
#define DIO_CHANNEL_0_5                    ((Dio_ChannelType)0x005)
#define DIO_CHANNEL_0_6                    ((Dio_ChannelType)0x006)
#define DIO_CHANNEL_0_7                    ((Dio_ChannelType)0x007)
#define DIO_CHANNEL_0_8                    ((Dio_ChannelType)0x008)
#define DIO_CHANNEL_0_9                    ((Dio_ChannelType)0x009)
#define DIO_CHANNEL_0_10                    ((Dio_ChannelType)0x00a)
#define DIO_CHANNEL_0_11                    ((Dio_ChannelType)0x00b)
#define DIO_CHANNEL_0_12                    ((Dio_ChannelType)0x00c)
#define DIO_CHANNEL_1_3                    ((Dio_ChannelType)0x013)
#define DIO_CHANNEL_1_4                    ((Dio_ChannelType)0x014)
#define DIO_CHANNEL_1_5                    ((Dio_ChannelType)0x015)
#define DIO_CHANNEL_1_6                    ((Dio_ChannelType)0x016)
#define DIO_CHANNEL_1_7                    ((Dio_ChannelType)0x017)
#define DIO_CHANNEL_2_0                    ((Dio_ChannelType)0x020)
#define DIO_CHANNEL_2_1                    ((Dio_ChannelType)0x021)
#define DIO_CHANNEL_2_2                    ((Dio_ChannelType)0x022)
#define DIO_CHANNEL_2_3                    ((Dio_ChannelType)0x023)
#define DIO_CHANNEL_2_4                    ((Dio_ChannelType)0x024)
#define DIO_CHANNEL_2_5                    ((Dio_ChannelType)0x025)
#define DIO_CHANNEL_2_6                    ((Dio_ChannelType)0x026)
#define DIO_CHANNEL_2_7                    ((Dio_ChannelType)0x027)
#define DIO_CHANNEL_2_8                    ((Dio_ChannelType)0x028)
#define DIO_CHANNEL_2_9                    ((Dio_ChannelType)0x029)
#define DIO_CHANNEL_2_10                    ((Dio_ChannelType)0x02a)
#define DIO_CHANNEL_2_11                    ((Dio_ChannelType)0x02b)
#define DIO_CHANNEL_10_0                    ((Dio_ChannelType)0x0a0)
#define DIO_CHANNEL_10_1                    ((Dio_ChannelType)0x0a1)
#define DIO_CHANNEL_10_2                    ((Dio_ChannelType)0x0a2)
#define DIO_CHANNEL_10_3                    ((Dio_ChannelType)0x0a3)
#define DIO_CHANNEL_10_4                    ((Dio_ChannelType)0x0a4)
#define DIO_CHANNEL_10_5                    ((Dio_ChannelType)0x0a5)
#define DIO_CHANNEL_10_6                    ((Dio_ChannelType)0x0a6)
#define DIO_CHANNEL_10_7                    ((Dio_ChannelType)0x0a7)
#define DIO_CHANNEL_10_8                    ((Dio_ChannelType)0x0a8)
#define DIO_CHANNEL_11_0                    ((Dio_ChannelType)0x0b0)
#define DIO_CHANNEL_11_1                    ((Dio_ChannelType)0x0b1)
#define DIO_CHANNEL_11_2                    ((Dio_ChannelType)0x0b2)
#define DIO_CHANNEL_11_3                    ((Dio_ChannelType)0x0b3)
#define DIO_CHANNEL_11_4                    ((Dio_ChannelType)0x0b4)
#define DIO_CHANNEL_11_5                    ((Dio_ChannelType)0x0b5)
#define DIO_CHANNEL_11_6                    ((Dio_ChannelType)0x0b6)
#define DIO_CHANNEL_11_7                    ((Dio_ChannelType)0x0b7)
#define DIO_CHANNEL_11_8                    ((Dio_ChannelType)0x0b8)
#define DIO_CHANNEL_11_9                    ((Dio_ChannelType)0x0b9)
#define DIO_CHANNEL_11_10                    ((Dio_ChannelType)0x0ba)
#define DIO_CHANNEL_11_11                    ((Dio_ChannelType)0x0bb)
#define DIO_CHANNEL_11_12                    ((Dio_ChannelType)0x0bc)
#define DIO_CHANNEL_11_13                    ((Dio_ChannelType)0x0bd)
#define DIO_CHANNEL_11_14                    ((Dio_ChannelType)0x0be)
#define DIO_CHANNEL_11_15                    ((Dio_ChannelType)0x0bf)
#define DIO_CHANNEL_12_0                    ((Dio_ChannelType)0x0c0)
#define DIO_CHANNEL_12_1                    ((Dio_ChannelType)0x0c1)
#define DIO_CHANNEL_13_0                    ((Dio_ChannelType)0x0d0)
#define DIO_CHANNEL_13_1                    ((Dio_ChannelType)0x0d1)
#define DIO_CHANNEL_13_2                    ((Dio_ChannelType)0x0d2)
#define DIO_CHANNEL_13_3                    ((Dio_ChannelType)0x0d3)
#define DIO_CHANNEL_14_0                    ((Dio_ChannelType)0x0e0)
#define DIO_CHANNEL_14_1                    ((Dio_ChannelType)0x0e1)
#define DIO_CHANNEL_14_2                    ((Dio_ChannelType)0x0e2)
#define DIO_CHANNEL_14_3                    ((Dio_ChannelType)0x0e3)
#define DIO_CHANNEL_14_4                    ((Dio_ChannelType)0x0e4)
#define DIO_CHANNEL_14_5                    ((Dio_ChannelType)0x0e5)
#define DIO_CHANNEL_14_6                    ((Dio_ChannelType)0x0e6)
#define DIO_CHANNEL_14_7                    ((Dio_ChannelType)0x0e7)
#define DIO_CHANNEL_14_8                    ((Dio_ChannelType)0x0e8)
#define DIO_CHANNEL_14_9                    ((Dio_ChannelType)0x0e9)
#define DIO_CHANNEL_14_10                    ((Dio_ChannelType)0x0ea)
#define DIO_CHANNEL_15_0                    ((Dio_ChannelType)0x0f0)
#define DIO_CHANNEL_15_1                    ((Dio_ChannelType)0x0f1)
#define DIO_CHANNEL_15_2                    ((Dio_ChannelType)0x0f2)
#define DIO_CHANNEL_15_3                    ((Dio_ChannelType)0x0f3)
#define DIO_CHANNEL_15_4                    ((Dio_ChannelType)0x0f4)
#define DIO_CHANNEL_15_5                    ((Dio_ChannelType)0x0f5)
#define DIO_CHANNEL_15_6                    ((Dio_ChannelType)0x0f6)
#define DIO_CHANNEL_15_7                    ((Dio_ChannelType)0x0f7)
#define DIO_CHANNEL_15_8                    ((Dio_ChannelType)0x0f8)
#define DIO_CHANNEL_20_0                    ((Dio_ChannelType)0x140)
#define DIO_CHANNEL_20_1                    ((Dio_ChannelType)0x141)
#define DIO_CHANNEL_20_2                    ((Dio_ChannelType)0x142)
#define DIO_CHANNEL_20_3                    ((Dio_ChannelType)0x143)
#define DIO_CHANNEL_20_6                    ((Dio_ChannelType)0x146)
#define DIO_CHANNEL_20_7                    ((Dio_ChannelType)0x147)
#define DIO_CHANNEL_20_8                    ((Dio_ChannelType)0x148)
#define DIO_CHANNEL_20_9                    ((Dio_ChannelType)0x149)
#define DIO_CHANNEL_20_10                    ((Dio_ChannelType)0x14a)
#define DIO_CHANNEL_20_11                    ((Dio_ChannelType)0x14b)
#define DIO_CHANNEL_20_12                    ((Dio_ChannelType)0x14c)
#define DIO_CHANNEL_20_13                    ((Dio_ChannelType)0x14d)
#define DIO_CHANNEL_20_14                    ((Dio_ChannelType)0x14e)
#define DIO_CHANNEL_21_0                    ((Dio_ChannelType)0x150)
#define DIO_CHANNEL_21_1                    ((Dio_ChannelType)0x151)
#define DIO_CHANNEL_21_2                    ((Dio_ChannelType)0x152)
#define DIO_CHANNEL_21_3                    ((Dio_ChannelType)0x153)
#define DIO_CHANNEL_21_4                    ((Dio_ChannelType)0x154)
#define DIO_CHANNEL_21_5                    ((Dio_ChannelType)0x155)
#define DIO_CHANNEL_21_6                    ((Dio_ChannelType)0x156)
#define DIO_CHANNEL_21_7                    ((Dio_ChannelType)0x157)
#define DIO_CHANNEL_22_0                    ((Dio_ChannelType)0x160)
#define DIO_CHANNEL_22_1                    ((Dio_ChannelType)0x161)
#define DIO_CHANNEL_22_2                    ((Dio_ChannelType)0x162)
#define DIO_CHANNEL_22_3                    ((Dio_ChannelType)0x163)
#define DIO_CHANNEL_22_4                    ((Dio_ChannelType)0x164)
#define DIO_CHANNEL_22_5                    ((Dio_ChannelType)0x165)
#define DIO_CHANNEL_22_6                    ((Dio_ChannelType)0x166)
#define DIO_CHANNEL_22_7                    ((Dio_ChannelType)0x167)
#define DIO_CHANNEL_22_8                    ((Dio_ChannelType)0x168)
#define DIO_CHANNEL_22_9                    ((Dio_ChannelType)0x169)
#define DIO_CHANNEL_22_10                    ((Dio_ChannelType)0x16a)
#define DIO_CHANNEL_22_11                    ((Dio_ChannelType)0x16b)
#define DIO_CHANNEL_23_0                    ((Dio_ChannelType)0x170)
#define DIO_CHANNEL_23_1                    ((Dio_ChannelType)0x171)
#define DIO_CHANNEL_23_2                    ((Dio_ChannelType)0x172)
#define DIO_CHANNEL_23_3                    ((Dio_ChannelType)0x173)
#define DIO_CHANNEL_23_4                    ((Dio_ChannelType)0x174)
#define DIO_CHANNEL_23_5                    ((Dio_ChannelType)0x175)
#define DIO_CHANNEL_23_6                    ((Dio_ChannelType)0x176)
#define DIO_CHANNEL_23_7                    ((Dio_ChannelType)0x177)
#define DIO_CHANNEL_32_0                    ((Dio_ChannelType)0x200)
#define DIO_CHANNEL_32_1                    ((Dio_ChannelType)0x201)
#define DIO_CHANNEL_32_2                    ((Dio_ChannelType)0x202)
#define DIO_CHANNEL_32_3                    ((Dio_ChannelType)0x203)
#define DIO_CHANNEL_32_4                    ((Dio_ChannelType)0x204)
#define DIO_CHANNEL_32_5                    ((Dio_ChannelType)0x205)
#define DIO_CHANNEL_32_6                    ((Dio_ChannelType)0x206)
#define DIO_CHANNEL_32_7                    ((Dio_ChannelType)0x207)
#define DIO_CHANNEL_33_0                    ((Dio_ChannelType)0x210)
#define DIO_CHANNEL_33_1                    ((Dio_ChannelType)0x211)
#define DIO_CHANNEL_33_2                    ((Dio_ChannelType)0x212)
#define DIO_CHANNEL_33_3                    ((Dio_ChannelType)0x213)
#define DIO_CHANNEL_33_4                    ((Dio_ChannelType)0x214)
#define DIO_CHANNEL_33_5                    ((Dio_ChannelType)0x215)
#define DIO_CHANNEL_33_6                    ((Dio_ChannelType)0x216)
#define DIO_CHANNEL_33_7                    ((Dio_ChannelType)0x217)
#define DIO_CHANNEL_33_8                    ((Dio_ChannelType)0x218)
#define DIO_CHANNEL_33_9                    ((Dio_ChannelType)0x219)
#define DIO_CHANNEL_33_10                    ((Dio_ChannelType)0x21a)
#define DIO_CHANNEL_33_11                    ((Dio_ChannelType)0x21b)
#define DIO_CHANNEL_33_12                    ((Dio_ChannelType)0x21c)
#define DIO_CHANNEL_33_13                    ((Dio_ChannelType)0x21d)
#define DIO_CHANNEL_33_14                    ((Dio_ChannelType)0x21e)
#define DIO_CHANNEL_33_15                    ((Dio_ChannelType)0x21f)
#define DIO_CHANNEL_34_1                    ((Dio_ChannelType)0x221)
#define DIO_CHANNEL_34_2                    ((Dio_ChannelType)0x222)
#define DIO_CHANNEL_34_3                    ((Dio_ChannelType)0x223)
#define DIO_CHANNEL_34_4                    ((Dio_ChannelType)0x224)
#define DIO_CHANNEL_34_5                    ((Dio_ChannelType)0x225)
#define DIO_CHANNEL_40_0                    ((Dio_ChannelType)0x280)
#define DIO_CHANNEL_40_1                    ((Dio_ChannelType)0x281)
#define DIO_CHANNEL_40_2                    ((Dio_ChannelType)0x282)
#define DIO_CHANNEL_40_3                    ((Dio_ChannelType)0x283)
#define DIO_CHANNEL_40_4                    ((Dio_ChannelType)0x284)
#define DIO_CHANNEL_40_5                    ((Dio_ChannelType)0x285)
#define DIO_CHANNEL_40_6                    ((Dio_ChannelType)0x286)
#define DIO_CHANNEL_40_7                    ((Dio_ChannelType)0x287)
#define DIO_CHANNEL_40_8                    ((Dio_ChannelType)0x288)
#define DIO_CHANNEL_40_9                    ((Dio_ChannelType)0x289)
#define DIO_CHANNEL_40_10                    ((Dio_ChannelType)0x28a)
#define DIO_CHANNEL_40_11                    ((Dio_ChannelType)0x28b)
#define DIO_CHANNEL_40_12                    ((Dio_ChannelType)0x28c)
#define DIO_CHANNEL_40_13                    ((Dio_ChannelType)0x28d)
#define DIO_CHANNEL_40_14                    ((Dio_ChannelType)0x28e)


/*
                      Symbolic names for DIO ports
*/
#define DIO_PORT_0                          ((Dio_PortType)0)
#define DIO_PORT_1                          ((Dio_PortType)1)
#define DIO_PORT_2                          ((Dio_PortType)2)
#define DIO_PORT_10                          ((Dio_PortType)10)
#define DIO_PORT_11                          ((Dio_PortType)11)
#define DIO_PORT_12                          ((Dio_PortType)12)
#define DIO_PORT_13                          ((Dio_PortType)13)
#define DIO_PORT_14                          ((Dio_PortType)14)
#define DIO_PORT_15                          ((Dio_PortType)15)
#define DIO_PORT_20                          ((Dio_PortType)20)
#define DIO_PORT_21                          ((Dio_PortType)21)
#define DIO_PORT_22                          ((Dio_PortType)22)
#define DIO_PORT_23                          ((Dio_PortType)23)
#define DIO_PORT_32                          ((Dio_PortType)32)
#define DIO_PORT_33                          ((Dio_PortType)33)
#define DIO_PORT_34                          ((Dio_PortType)34)
#define DIO_PORT_40                          ((Dio_PortType)40)

/*
     User Defined Symbolic Names for the DIO Ports, Channels & Channel Groups
*/

/*
  DIO PORT : (DioPort_13)
*/

#ifndef DioConf_DioPort_DioPort_13
#define DioConf_DioPort_DioPort_13 (DIO_PORT_13)
#endif

/* DIO Channel : (LED0) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_LED0
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_LED0 (DIO_CHANNEL_13_0)
#endif

/* DIO Channel : (LED1) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_LED1
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_LED1 (DIO_CHANNEL_13_1)
#endif

/* DIO Channel : (LED2) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_LED2
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_LED2 (DIO_CHANNEL_13_2)
#endif

/* DIO Channel : (LED3) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_LED3
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_LED3 (DIO_CHANNEL_13_3)
#endif

/*
  DIO PORT : (DioPort_23)
*/

#ifndef DioConf_DioPort_DioPort_23
#define DioConf_DioPort_DioPort_23 (DIO_PORT_23)
#endif

/* DIO Channel : (Tick0) */
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#ifndef DioConf_DioChannel_Tick0
/* MISRA2012_RULE_5_1_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_2_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_4_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
/* MISRA2012_RULE_5_5_JUSTIFICATION: External identifiers are defined
 according to requirement ecuc_sws_2108*/
#define DioConf_DioChannel_Tick0 (DIO_CHANNEL_23_4)
#endif




/*******************************************************************************
**                      Global Constant Declarations                          **
*******************************************************************************/
#define DIO_START_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
#include "Dio_MemMap.h"

extern const struct Dio_ConfigType Dio_Config; 
#define DIO_STOP_SEC_CONFIG_DATA_ASIL_B_GLOBAL_UNSPECIFIED
/* MISRA2012_RULE_4_10_JUSTIFICATION: To be compliant with autosar guidelines 
Dio_Memmap.h header is included without safegaurd.*/
#include "Dio_MemMap.h"
/*******************************************************************************
**                      Global Data Type                                      **
*******************************************************************************/

/* End of DIO_CFG_H */
#endif
