/**
 * \file IfxLmu_reg.h
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
 * \defgroup IfxSfr_Lmu_Registers_Cfg Lmu address
 * \ingroup IfxSfr_Lmu_Registers
 * 
 * \defgroup IfxSfr_Lmu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Lmu_Registers_Cfg
 *
 * \defgroup IfxSfr_Lmu_Registers_Cfg_Lmu0 2-LMU0
 * \ingroup IfxSfr_Lmu_Registers_Cfg
 *
 * \defgroup IfxSfr_Lmu_Registers_Cfg_Lmu1 2-LMU1
 * \ingroup IfxSfr_Lmu_Registers_Cfg
 *
 * \defgroup IfxSfr_Lmu_Registers_Cfg_Lmu2 2-LMU2
 * \ingroup IfxSfr_Lmu_Registers_Cfg
 *
 *
 */
#ifndef IFXLMU_REG_H
#define IFXLMU_REG_H 1
/******************************************************************************/
#include "IfxLmu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Lmu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief LMU object */
#define MODULE_LMU0 /*lint --e(923, 9078)*/ ((*(Ifx_LMU*)0xF8100000u))
#define MODULE_LMU1 /*lint --e(923, 9078)*/ ((*(Ifx_LMU*)0xF8110000u))
#define MODULE_LMU2 /*lint --e(923, 9078)*/ ((*(Ifx_LMU*)0xF8120000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Lmu_Registers_Cfg_Lmu0
 * \{  */
/** \brief 0, LMU Clock Control Register */
#define LMU0_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_CLC*)0xF8100000u)

/** \brief 8, LMU Module ID Register */
#define LMU0_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_MODID*)0xF8100008u)

/** \brief 10, LMU Access Enable Register 0 */
#define LMU0_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_ACCEN0*)0xF8100010u)

/** \brief 14, LMU Access Enable Register 1 */
#define LMU0_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_ACCEN1*)0xF8100014u)

/** \brief 20, LMU Memory Control Register */
#define LMU0_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_MEMCON*)0xF8100020u)

/** \brief 24, LMU Safety Control Register */
#define LMU0_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_SCTRL*)0xF8100024u)

/** \brief 50, LMU Region Lower Address Register */
#define LMU0_RGN0_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100050u)
/** Alias (User Manual Name) for LMU0_RGN0_LA.
* To use register names with standard convension, please use LMU0_RGN0_LA.
*/
#define LMU0_RGNLA0 (LMU0_RGN0_LA)

/** \brief 54, LMU Region Upper Address Register */
#define LMU0_RGN0_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100054u)
/** Alias (User Manual Name) for LMU0_RGN0_UA.
* To use register names with standard convension, please use LMU0_RGN0_UA.
*/
#define LMU0_RGNUA0 (LMU0_RGN0_UA)

/** \brief 58, LMU Region Write Access Enable Register A */
#define LMU0_RGN0_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100058u)
/** Alias (User Manual Name) for LMU0_RGN0_ACCENA.
* To use register names with standard convension, please use LMU0_RGN0_ACCENA.
*/
#define LMU0_RGNACCENWA0 (LMU0_RGN0_ACCENA)

/** \brief 5C, LMU Region Write Access Enable Register B */
#define LMU0_RGN0_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810005Cu)
/** Alias (User Manual Name) for LMU0_RGN0_ACCENB.
* To use register names with standard convension, please use LMU0_RGN0_ACCENB.
*/
#define LMU0_RGNACCENWB0 (LMU0_RGN0_ACCENB)

/** \brief 60, LMU Region Lower Address Register */
#define LMU0_RGN1_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100060u)
/** Alias (User Manual Name) for LMU0_RGN1_LA.
* To use register names with standard convension, please use LMU0_RGN1_LA.
*/
#define LMU0_RGNLA1 (LMU0_RGN1_LA)

/** \brief 64, LMU Region Upper Address Register */
#define LMU0_RGN1_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100064u)
/** Alias (User Manual Name) for LMU0_RGN1_UA.
* To use register names with standard convension, please use LMU0_RGN1_UA.
*/
#define LMU0_RGNUA1 (LMU0_RGN1_UA)

/** \brief 68, LMU Region Write Access Enable Register A */
#define LMU0_RGN1_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100068u)
/** Alias (User Manual Name) for LMU0_RGN1_ACCENA.
* To use register names with standard convension, please use LMU0_RGN1_ACCENA.
*/
#define LMU0_RGNACCENWA1 (LMU0_RGN1_ACCENA)

/** \brief 6C, LMU Region Write Access Enable Register B */
#define LMU0_RGN1_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810006Cu)
/** Alias (User Manual Name) for LMU0_RGN1_ACCENB.
* To use register names with standard convension, please use LMU0_RGN1_ACCENB.
*/
#define LMU0_RGNACCENWB1 (LMU0_RGN1_ACCENB)

/** \brief 70, LMU Region Lower Address Register */
#define LMU0_RGN2_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100070u)
/** Alias (User Manual Name) for LMU0_RGN2_LA.
* To use register names with standard convension, please use LMU0_RGN2_LA.
*/
#define LMU0_RGNLA2 (LMU0_RGN2_LA)

/** \brief 74, LMU Region Upper Address Register */
#define LMU0_RGN2_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100074u)
/** Alias (User Manual Name) for LMU0_RGN2_UA.
* To use register names with standard convension, please use LMU0_RGN2_UA.
*/
#define LMU0_RGNUA2 (LMU0_RGN2_UA)

/** \brief 78, LMU Region Write Access Enable Register A */
#define LMU0_RGN2_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100078u)
/** Alias (User Manual Name) for LMU0_RGN2_ACCENA.
* To use register names with standard convension, please use LMU0_RGN2_ACCENA.
*/
#define LMU0_RGNACCENWA2 (LMU0_RGN2_ACCENA)

/** \brief 7C, LMU Region Write Access Enable Register B */
#define LMU0_RGN2_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810007Cu)
/** Alias (User Manual Name) for LMU0_RGN2_ACCENB.
* To use register names with standard convension, please use LMU0_RGN2_ACCENB.
*/
#define LMU0_RGNACCENWB2 (LMU0_RGN2_ACCENB)

/** \brief 80, LMU Region Lower Address Register */
#define LMU0_RGN3_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100080u)
/** Alias (User Manual Name) for LMU0_RGN3_LA.
* To use register names with standard convension, please use LMU0_RGN3_LA.
*/
#define LMU0_RGNLA3 (LMU0_RGN3_LA)

/** \brief 84, LMU Region Upper Address Register */
#define LMU0_RGN3_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100084u)
/** Alias (User Manual Name) for LMU0_RGN3_UA.
* To use register names with standard convension, please use LMU0_RGN3_UA.
*/
#define LMU0_RGNUA3 (LMU0_RGN3_UA)

/** \brief 88, LMU Region Write Access Enable Register A */
#define LMU0_RGN3_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100088u)
/** Alias (User Manual Name) for LMU0_RGN3_ACCENA.
* To use register names with standard convension, please use LMU0_RGN3_ACCENA.
*/
#define LMU0_RGNACCENWA3 (LMU0_RGN3_ACCENA)

/** \brief 8C, LMU Region Write Access Enable Register B */
#define LMU0_RGN3_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810008Cu)
/** Alias (User Manual Name) for LMU0_RGN3_ACCENB.
* To use register names with standard convension, please use LMU0_RGN3_ACCENB.
*/
#define LMU0_RGNACCENWB3 (LMU0_RGN3_ACCENB)

/** \brief 90, LMU Region Lower Address Register */
#define LMU0_RGN4_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100090u)
/** Alias (User Manual Name) for LMU0_RGN4_LA.
* To use register names with standard convension, please use LMU0_RGN4_LA.
*/
#define LMU0_RGNLA4 (LMU0_RGN4_LA)

/** \brief 94, LMU Region Upper Address Register */
#define LMU0_RGN4_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100094u)
/** Alias (User Manual Name) for LMU0_RGN4_UA.
* To use register names with standard convension, please use LMU0_RGN4_UA.
*/
#define LMU0_RGNUA4 (LMU0_RGN4_UA)

/** \brief 98, LMU Region Write Access Enable Register A */
#define LMU0_RGN4_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100098u)
/** Alias (User Manual Name) for LMU0_RGN4_ACCENA.
* To use register names with standard convension, please use LMU0_RGN4_ACCENA.
*/
#define LMU0_RGNACCENWA4 (LMU0_RGN4_ACCENA)

/** \brief 9C, LMU Region Write Access Enable Register B */
#define LMU0_RGN4_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810009Cu)
/** Alias (User Manual Name) for LMU0_RGN4_ACCENB.
* To use register names with standard convension, please use LMU0_RGN4_ACCENB.
*/
#define LMU0_RGNACCENWB4 (LMU0_RGN4_ACCENB)

/** \brief A0, LMU Region Lower Address Register */
#define LMU0_RGN5_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81000A0u)
/** Alias (User Manual Name) for LMU0_RGN5_LA.
* To use register names with standard convension, please use LMU0_RGN5_LA.
*/
#define LMU0_RGNLA5 (LMU0_RGN5_LA)

/** \brief A4, LMU Region Upper Address Register */
#define LMU0_RGN5_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81000A4u)
/** Alias (User Manual Name) for LMU0_RGN5_UA.
* To use register names with standard convension, please use LMU0_RGN5_UA.
*/
#define LMU0_RGNUA5 (LMU0_RGN5_UA)

/** \brief A8, LMU Region Write Access Enable Register A */
#define LMU0_RGN5_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81000A8u)
/** Alias (User Manual Name) for LMU0_RGN5_ACCENA.
* To use register names with standard convension, please use LMU0_RGN5_ACCENA.
*/
#define LMU0_RGNACCENWA5 (LMU0_RGN5_ACCENA)

/** \brief AC, LMU Region Write Access Enable Register B */
#define LMU0_RGN5_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81000ACu)
/** Alias (User Manual Name) for LMU0_RGN5_ACCENB.
* To use register names with standard convension, please use LMU0_RGN5_ACCENB.
*/
#define LMU0_RGNACCENWB5 (LMU0_RGN5_ACCENB)

/** \brief B0, LMU Region Lower Address Register */
#define LMU0_RGN6_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81000B0u)
/** Alias (User Manual Name) for LMU0_RGN6_LA.
* To use register names with standard convension, please use LMU0_RGN6_LA.
*/
#define LMU0_RGNLA6 (LMU0_RGN6_LA)

/** \brief B4, LMU Region Upper Address Register */
#define LMU0_RGN6_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81000B4u)
/** Alias (User Manual Name) for LMU0_RGN6_UA.
* To use register names with standard convension, please use LMU0_RGN6_UA.
*/
#define LMU0_RGNUA6 (LMU0_RGN6_UA)

/** \brief B8, LMU Region Write Access Enable Register A */
#define LMU0_RGN6_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81000B8u)
/** Alias (User Manual Name) for LMU0_RGN6_ACCENA.
* To use register names with standard convension, please use LMU0_RGN6_ACCENA.
*/
#define LMU0_RGNACCENWA6 (LMU0_RGN6_ACCENA)

/** \brief BC, LMU Region Write Access Enable Register B */
#define LMU0_RGN6_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81000BCu)
/** Alias (User Manual Name) for LMU0_RGN6_ACCENB.
* To use register names with standard convension, please use LMU0_RGN6_ACCENB.
*/
#define LMU0_RGNACCENWB6 (LMU0_RGN6_ACCENB)

/** \brief C0, LMU Region Lower Address Register */
#define LMU0_RGN7_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81000C0u)
/** Alias (User Manual Name) for LMU0_RGN7_LA.
* To use register names with standard convension, please use LMU0_RGN7_LA.
*/
#define LMU0_RGNLA7 (LMU0_RGN7_LA)

/** \brief C4, LMU Region Upper Address Register */
#define LMU0_RGN7_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81000C4u)
/** Alias (User Manual Name) for LMU0_RGN7_UA.
* To use register names with standard convension, please use LMU0_RGN7_UA.
*/
#define LMU0_RGNUA7 (LMU0_RGN7_UA)

/** \brief C8, LMU Region Write Access Enable Register A */
#define LMU0_RGN7_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81000C8u)
/** Alias (User Manual Name) for LMU0_RGN7_ACCENA.
* To use register names with standard convension, please use LMU0_RGN7_ACCENA.
*/
#define LMU0_RGNACCENWA7 (LMU0_RGN7_ACCENA)

/** \brief CC, LMU Region Write Access Enable Register B */
#define LMU0_RGN7_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81000CCu)
/** Alias (User Manual Name) for LMU0_RGN7_ACCENB.
* To use register names with standard convension, please use LMU0_RGN7_ACCENB.
*/
#define LMU0_RGNACCENWB7 (LMU0_RGN7_ACCENB)

/** \brief D0, LMU Region Lower Address Register */
#define LMU0_RGN8_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81000D0u)
/** Alias (User Manual Name) for LMU0_RGN8_LA.
* To use register names with standard convension, please use LMU0_RGN8_LA.
*/
#define LMU0_RGNLA8 (LMU0_RGN8_LA)

/** \brief D4, LMU Region Upper Address Register */
#define LMU0_RGN8_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81000D4u)
/** Alias (User Manual Name) for LMU0_RGN8_UA.
* To use register names with standard convension, please use LMU0_RGN8_UA.
*/
#define LMU0_RGNUA8 (LMU0_RGN8_UA)

/** \brief D8, LMU Region Write Access Enable Register A */
#define LMU0_RGN8_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81000D8u)
/** Alias (User Manual Name) for LMU0_RGN8_ACCENA.
* To use register names with standard convension, please use LMU0_RGN8_ACCENA.
*/
#define LMU0_RGNACCENWA8 (LMU0_RGN8_ACCENA)

/** \brief DC, LMU Region Write Access Enable Register B */
#define LMU0_RGN8_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81000DCu)
/** Alias (User Manual Name) for LMU0_RGN8_ACCENB.
* To use register names with standard convension, please use LMU0_RGN8_ACCENB.
*/
#define LMU0_RGNACCENWB8 (LMU0_RGN8_ACCENB)

/** \brief E0, LMU Region Lower Address Register */
#define LMU0_RGN9_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81000E0u)
/** Alias (User Manual Name) for LMU0_RGN9_LA.
* To use register names with standard convension, please use LMU0_RGN9_LA.
*/
#define LMU0_RGNLA9 (LMU0_RGN9_LA)

/** \brief E4, LMU Region Upper Address Register */
#define LMU0_RGN9_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81000E4u)
/** Alias (User Manual Name) for LMU0_RGN9_UA.
* To use register names with standard convension, please use LMU0_RGN9_UA.
*/
#define LMU0_RGNUA9 (LMU0_RGN9_UA)

/** \brief E8, LMU Region Write Access Enable Register A */
#define LMU0_RGN9_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81000E8u)
/** Alias (User Manual Name) for LMU0_RGN9_ACCENA.
* To use register names with standard convension, please use LMU0_RGN9_ACCENA.
*/
#define LMU0_RGNACCENWA9 (LMU0_RGN9_ACCENA)

/** \brief EC, LMU Region Write Access Enable Register B */
#define LMU0_RGN9_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81000ECu)
/** Alias (User Manual Name) for LMU0_RGN9_ACCENB.
* To use register names with standard convension, please use LMU0_RGN9_ACCENB.
*/
#define LMU0_RGNACCENWB9 (LMU0_RGN9_ACCENB)

/** \brief F0, LMU Region Lower Address Register */
#define LMU0_RGN10_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81000F0u)
/** Alias (User Manual Name) for LMU0_RGN10_LA.
* To use register names with standard convension, please use LMU0_RGN10_LA.
*/
#define LMU0_RGNLA10 (LMU0_RGN10_LA)

/** \brief F4, LMU Region Upper Address Register */
#define LMU0_RGN10_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81000F4u)
/** Alias (User Manual Name) for LMU0_RGN10_UA.
* To use register names with standard convension, please use LMU0_RGN10_UA.
*/
#define LMU0_RGNUA10 (LMU0_RGN10_UA)

/** \brief F8, LMU Region Write Access Enable Register A */
#define LMU0_RGN10_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81000F8u)
/** Alias (User Manual Name) for LMU0_RGN10_ACCENA.
* To use register names with standard convension, please use LMU0_RGN10_ACCENA.
*/
#define LMU0_RGNACCENWA10 (LMU0_RGN10_ACCENA)

/** \brief FC, LMU Region Write Access Enable Register B */
#define LMU0_RGN10_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81000FCu)
/** Alias (User Manual Name) for LMU0_RGN10_ACCENB.
* To use register names with standard convension, please use LMU0_RGN10_ACCENB.
*/
#define LMU0_RGNACCENWB10 (LMU0_RGN10_ACCENB)

/** \brief 100, LMU Region Lower Address Register */
#define LMU0_RGN11_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100100u)
/** Alias (User Manual Name) for LMU0_RGN11_LA.
* To use register names with standard convension, please use LMU0_RGN11_LA.
*/
#define LMU0_RGNLA11 (LMU0_RGN11_LA)

/** \brief 104, LMU Region Upper Address Register */
#define LMU0_RGN11_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100104u)
/** Alias (User Manual Name) for LMU0_RGN11_UA.
* To use register names with standard convension, please use LMU0_RGN11_UA.
*/
#define LMU0_RGNUA11 (LMU0_RGN11_UA)

/** \brief 108, LMU Region Write Access Enable Register A */
#define LMU0_RGN11_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100108u)
/** Alias (User Manual Name) for LMU0_RGN11_ACCENA.
* To use register names with standard convension, please use LMU0_RGN11_ACCENA.
*/
#define LMU0_RGNACCENWA11 (LMU0_RGN11_ACCENA)

/** \brief 10C, LMU Region Write Access Enable Register B */
#define LMU0_RGN11_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810010Cu)
/** Alias (User Manual Name) for LMU0_RGN11_ACCENB.
* To use register names with standard convension, please use LMU0_RGN11_ACCENB.
*/
#define LMU0_RGNACCENWB11 (LMU0_RGN11_ACCENB)

/** \brief 110, LMU Region Lower Address Register */
#define LMU0_RGN12_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100110u)
/** Alias (User Manual Name) for LMU0_RGN12_LA.
* To use register names with standard convension, please use LMU0_RGN12_LA.
*/
#define LMU0_RGNLA12 (LMU0_RGN12_LA)

/** \brief 114, LMU Region Upper Address Register */
#define LMU0_RGN12_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100114u)
/** Alias (User Manual Name) for LMU0_RGN12_UA.
* To use register names with standard convension, please use LMU0_RGN12_UA.
*/
#define LMU0_RGNUA12 (LMU0_RGN12_UA)

/** \brief 118, LMU Region Write Access Enable Register A */
#define LMU0_RGN12_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100118u)
/** Alias (User Manual Name) for LMU0_RGN12_ACCENA.
* To use register names with standard convension, please use LMU0_RGN12_ACCENA.
*/
#define LMU0_RGNACCENWA12 (LMU0_RGN12_ACCENA)

/** \brief 11C, LMU Region Write Access Enable Register B */
#define LMU0_RGN12_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810011Cu)
/** Alias (User Manual Name) for LMU0_RGN12_ACCENB.
* To use register names with standard convension, please use LMU0_RGN12_ACCENB.
*/
#define LMU0_RGNACCENWB12 (LMU0_RGN12_ACCENB)

/** \brief 120, LMU Region Lower Address Register */
#define LMU0_RGN13_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100120u)
/** Alias (User Manual Name) for LMU0_RGN13_LA.
* To use register names with standard convension, please use LMU0_RGN13_LA.
*/
#define LMU0_RGNLA13 (LMU0_RGN13_LA)

/** \brief 124, LMU Region Upper Address Register */
#define LMU0_RGN13_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100124u)
/** Alias (User Manual Name) for LMU0_RGN13_UA.
* To use register names with standard convension, please use LMU0_RGN13_UA.
*/
#define LMU0_RGNUA13 (LMU0_RGN13_UA)

/** \brief 128, LMU Region Write Access Enable Register A */
#define LMU0_RGN13_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100128u)
/** Alias (User Manual Name) for LMU0_RGN13_ACCENA.
* To use register names with standard convension, please use LMU0_RGN13_ACCENA.
*/
#define LMU0_RGNACCENWA13 (LMU0_RGN13_ACCENA)

/** \brief 12C, LMU Region Write Access Enable Register B */
#define LMU0_RGN13_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810012Cu)
/** Alias (User Manual Name) for LMU0_RGN13_ACCENB.
* To use register names with standard convension, please use LMU0_RGN13_ACCENB.
*/
#define LMU0_RGNACCENWB13 (LMU0_RGN13_ACCENB)

/** \brief 130, LMU Region Lower Address Register */
#define LMU0_RGN14_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100130u)
/** Alias (User Manual Name) for LMU0_RGN14_LA.
* To use register names with standard convension, please use LMU0_RGN14_LA.
*/
#define LMU0_RGNLA14 (LMU0_RGN14_LA)

/** \brief 134, LMU Region Upper Address Register */
#define LMU0_RGN14_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100134u)
/** Alias (User Manual Name) for LMU0_RGN14_UA.
* To use register names with standard convension, please use LMU0_RGN14_UA.
*/
#define LMU0_RGNUA14 (LMU0_RGN14_UA)

/** \brief 138, LMU Region Write Access Enable Register A */
#define LMU0_RGN14_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100138u)
/** Alias (User Manual Name) for LMU0_RGN14_ACCENA.
* To use register names with standard convension, please use LMU0_RGN14_ACCENA.
*/
#define LMU0_RGNACCENWA14 (LMU0_RGN14_ACCENA)

/** \brief 13C, LMU Region Write Access Enable Register B */
#define LMU0_RGN14_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810013Cu)
/** Alias (User Manual Name) for LMU0_RGN14_ACCENB.
* To use register names with standard convension, please use LMU0_RGN14_ACCENB.
*/
#define LMU0_RGNACCENWB14 (LMU0_RGN14_ACCENB)

/** \brief 140, LMU Region Lower Address Register */
#define LMU0_RGN15_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8100140u)
/** Alias (User Manual Name) for LMU0_RGN15_LA.
* To use register names with standard convension, please use LMU0_RGN15_LA.
*/
#define LMU0_RGNLA15 (LMU0_RGN15_LA)

/** \brief 144, LMU Region Upper Address Register */
#define LMU0_RGN15_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8100144u)
/** Alias (User Manual Name) for LMU0_RGN15_UA.
* To use register names with standard convension, please use LMU0_RGN15_UA.
*/
#define LMU0_RGNUA15 (LMU0_RGN15_UA)

/** \brief 148, LMU Region Write Access Enable Register A */
#define LMU0_RGN15_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8100148u)
/** Alias (User Manual Name) for LMU0_RGN15_ACCENA.
* To use register names with standard convension, please use LMU0_RGN15_ACCENA.
*/
#define LMU0_RGNACCENWA15 (LMU0_RGN15_ACCENA)

/** \brief 14C, LMU Region Write Access Enable Register B */
#define LMU0_RGN15_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF810014Cu)
/** Alias (User Manual Name) for LMU0_RGN15_ACCENB.
* To use register names with standard convension, please use LMU0_RGN15_ACCENB.
*/
#define LMU0_RGNACCENWB15 (LMU0_RGN15_ACCENB)

/** \brief 158, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN0_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100158u)
/** Alias (User Manual Name) for LMU0_RGNACCEN0_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN0_RA.
*/
#define LMU0_RGNACCENRA0 (LMU0_RGNACCEN0_RA)

/** \brief 15C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN0_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810015Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN0_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN0_RB.
*/
#define LMU0_RGNACCENRB0 (LMU0_RGNACCEN0_RB)

/** \brief 168, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN1_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100168u)
/** Alias (User Manual Name) for LMU0_RGNACCEN1_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN1_RA.
*/
#define LMU0_RGNACCENRA1 (LMU0_RGNACCEN1_RA)

/** \brief 16C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN1_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810016Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN1_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN1_RB.
*/
#define LMU0_RGNACCENRB1 (LMU0_RGNACCEN1_RB)

/** \brief 178, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN2_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100178u)
/** Alias (User Manual Name) for LMU0_RGNACCEN2_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN2_RA.
*/
#define LMU0_RGNACCENRA2 (LMU0_RGNACCEN2_RA)

/** \brief 17C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN2_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810017Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN2_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN2_RB.
*/
#define LMU0_RGNACCENRB2 (LMU0_RGNACCEN2_RB)

/** \brief 188, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN3_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100188u)
/** Alias (User Manual Name) for LMU0_RGNACCEN3_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN3_RA.
*/
#define LMU0_RGNACCENRA3 (LMU0_RGNACCEN3_RA)

/** \brief 18C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN3_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810018Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN3_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN3_RB.
*/
#define LMU0_RGNACCENRB3 (LMU0_RGNACCEN3_RB)

/** \brief 198, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN4_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100198u)
/** Alias (User Manual Name) for LMU0_RGNACCEN4_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN4_RA.
*/
#define LMU0_RGNACCENRA4 (LMU0_RGNACCEN4_RA)

/** \brief 19C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN4_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810019Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN4_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN4_RB.
*/
#define LMU0_RGNACCENRB4 (LMU0_RGNACCEN4_RB)

/** \brief 1A8, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN5_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81001A8u)
/** Alias (User Manual Name) for LMU0_RGNACCEN5_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN5_RA.
*/
#define LMU0_RGNACCENRA5 (LMU0_RGNACCEN5_RA)

/** \brief 1AC, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN5_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81001ACu)
/** Alias (User Manual Name) for LMU0_RGNACCEN5_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN5_RB.
*/
#define LMU0_RGNACCENRB5 (LMU0_RGNACCEN5_RB)

/** \brief 1B8, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN6_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81001B8u)
/** Alias (User Manual Name) for LMU0_RGNACCEN6_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN6_RA.
*/
#define LMU0_RGNACCENRA6 (LMU0_RGNACCEN6_RA)

/** \brief 1BC, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN6_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81001BCu)
/** Alias (User Manual Name) for LMU0_RGNACCEN6_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN6_RB.
*/
#define LMU0_RGNACCENRB6 (LMU0_RGNACCEN6_RB)

/** \brief 1C8, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN7_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81001C8u)
/** Alias (User Manual Name) for LMU0_RGNACCEN7_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN7_RA.
*/
#define LMU0_RGNACCENRA7 (LMU0_RGNACCEN7_RA)

/** \brief 1CC, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN7_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81001CCu)
/** Alias (User Manual Name) for LMU0_RGNACCEN7_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN7_RB.
*/
#define LMU0_RGNACCENRB7 (LMU0_RGNACCEN7_RB)

/** \brief 1D8, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN8_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81001D8u)
/** Alias (User Manual Name) for LMU0_RGNACCEN8_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN8_RA.
*/
#define LMU0_RGNACCENRA8 (LMU0_RGNACCEN8_RA)

/** \brief 1DC, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN8_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81001DCu)
/** Alias (User Manual Name) for LMU0_RGNACCEN8_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN8_RB.
*/
#define LMU0_RGNACCENRB8 (LMU0_RGNACCEN8_RB)

/** \brief 1E8, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN9_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81001E8u)
/** Alias (User Manual Name) for LMU0_RGNACCEN9_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN9_RA.
*/
#define LMU0_RGNACCENRA9 (LMU0_RGNACCEN9_RA)

/** \brief 1EC, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN9_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81001ECu)
/** Alias (User Manual Name) for LMU0_RGNACCEN9_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN9_RB.
*/
#define LMU0_RGNACCENRB9 (LMU0_RGNACCEN9_RB)

/** \brief 1F8, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN10_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81001F8u)
/** Alias (User Manual Name) for LMU0_RGNACCEN10_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN10_RA.
*/
#define LMU0_RGNACCENRA10 (LMU0_RGNACCEN10_RA)

/** \brief 1FC, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN10_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81001FCu)
/** Alias (User Manual Name) for LMU0_RGNACCEN10_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN10_RB.
*/
#define LMU0_RGNACCENRB10 (LMU0_RGNACCEN10_RB)

/** \brief 208, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN11_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100208u)
/** Alias (User Manual Name) for LMU0_RGNACCEN11_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN11_RA.
*/
#define LMU0_RGNACCENRA11 (LMU0_RGNACCEN11_RA)

/** \brief 20C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN11_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810020Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN11_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN11_RB.
*/
#define LMU0_RGNACCENRB11 (LMU0_RGNACCEN11_RB)

/** \brief 218, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN12_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100218u)
/** Alias (User Manual Name) for LMU0_RGNACCEN12_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN12_RA.
*/
#define LMU0_RGNACCENRA12 (LMU0_RGNACCEN12_RA)

/** \brief 21C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN12_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810021Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN12_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN12_RB.
*/
#define LMU0_RGNACCENRB12 (LMU0_RGNACCEN12_RB)

/** \brief 228, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN13_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100228u)
/** Alias (User Manual Name) for LMU0_RGNACCEN13_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN13_RA.
*/
#define LMU0_RGNACCENRA13 (LMU0_RGNACCEN13_RA)

/** \brief 22C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN13_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810022Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN13_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN13_RB.
*/
#define LMU0_RGNACCENRB13 (LMU0_RGNACCEN13_RB)

/** \brief 238, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN14_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100238u)
/** Alias (User Manual Name) for LMU0_RGNACCEN14_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN14_RA.
*/
#define LMU0_RGNACCENRA14 (LMU0_RGNACCEN14_RA)

/** \brief 23C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN14_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810023Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN14_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN14_RB.
*/
#define LMU0_RGNACCENRB14 (LMU0_RGNACCEN14_RB)

/** \brief 248, LMU Region Read Access Enable Register A */
#define LMU0_RGNACCEN15_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8100248u)
/** Alias (User Manual Name) for LMU0_RGNACCEN15_RA.
* To use register names with standard convension, please use LMU0_RGNACCEN15_RA.
*/
#define LMU0_RGNACCENRA15 (LMU0_RGNACCEN15_RA)

/** \brief 24C, LMU Region Read Access Enable Register B */
#define LMU0_RGNACCEN15_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF810024Cu)
/** Alias (User Manual Name) for LMU0_RGNACCEN15_RB.
* To use register names with standard convension, please use LMU0_RGNACCEN15_RB.
*/
#define LMU0_RGNACCENRB15 (LMU0_RGNACCEN15_RB)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Lmu_Registers_Cfg_Lmu1
 * \{  */
/** \brief 0, LMU Clock Control Register */
#define LMU1_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_CLC*)0xF8110000u)

/** \brief 8, LMU Module ID Register */
#define LMU1_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_MODID*)0xF8110008u)

/** \brief 10, LMU Access Enable Register 0 */
#define LMU1_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_ACCEN0*)0xF8110010u)

/** \brief 14, LMU Access Enable Register 1 */
#define LMU1_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_ACCEN1*)0xF8110014u)

/** \brief 20, LMU Memory Control Register */
#define LMU1_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_MEMCON*)0xF8110020u)

/** \brief 24, LMU Safety Control Register */
#define LMU1_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_SCTRL*)0xF8110024u)

/** \brief 50, LMU Region Lower Address Register */
#define LMU1_RGN0_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110050u)
/** Alias (User Manual Name) for LMU1_RGN0_LA.
* To use register names with standard convension, please use LMU1_RGN0_LA.
*/
#define LMU1_RGNLA0 (LMU1_RGN0_LA)

/** \brief 54, LMU Region Upper Address Register */
#define LMU1_RGN0_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110054u)
/** Alias (User Manual Name) for LMU1_RGN0_UA.
* To use register names with standard convension, please use LMU1_RGN0_UA.
*/
#define LMU1_RGNUA0 (LMU1_RGN0_UA)

/** \brief 58, LMU Region Write Access Enable Register A */
#define LMU1_RGN0_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110058u)
/** Alias (User Manual Name) for LMU1_RGN0_ACCENA.
* To use register names with standard convension, please use LMU1_RGN0_ACCENA.
*/
#define LMU1_RGNACCENWA0 (LMU1_RGN0_ACCENA)

/** \brief 5C, LMU Region Write Access Enable Register B */
#define LMU1_RGN0_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811005Cu)
/** Alias (User Manual Name) for LMU1_RGN0_ACCENB.
* To use register names with standard convension, please use LMU1_RGN0_ACCENB.
*/
#define LMU1_RGNACCENWB0 (LMU1_RGN0_ACCENB)

/** \brief 60, LMU Region Lower Address Register */
#define LMU1_RGN1_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110060u)
/** Alias (User Manual Name) for LMU1_RGN1_LA.
* To use register names with standard convension, please use LMU1_RGN1_LA.
*/
#define LMU1_RGNLA1 (LMU1_RGN1_LA)

/** \brief 64, LMU Region Upper Address Register */
#define LMU1_RGN1_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110064u)
/** Alias (User Manual Name) for LMU1_RGN1_UA.
* To use register names with standard convension, please use LMU1_RGN1_UA.
*/
#define LMU1_RGNUA1 (LMU1_RGN1_UA)

/** \brief 68, LMU Region Write Access Enable Register A */
#define LMU1_RGN1_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110068u)
/** Alias (User Manual Name) for LMU1_RGN1_ACCENA.
* To use register names with standard convension, please use LMU1_RGN1_ACCENA.
*/
#define LMU1_RGNACCENWA1 (LMU1_RGN1_ACCENA)

/** \brief 6C, LMU Region Write Access Enable Register B */
#define LMU1_RGN1_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811006Cu)
/** Alias (User Manual Name) for LMU1_RGN1_ACCENB.
* To use register names with standard convension, please use LMU1_RGN1_ACCENB.
*/
#define LMU1_RGNACCENWB1 (LMU1_RGN1_ACCENB)

/** \brief 70, LMU Region Lower Address Register */
#define LMU1_RGN2_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110070u)
/** Alias (User Manual Name) for LMU1_RGN2_LA.
* To use register names with standard convension, please use LMU1_RGN2_LA.
*/
#define LMU1_RGNLA2 (LMU1_RGN2_LA)

/** \brief 74, LMU Region Upper Address Register */
#define LMU1_RGN2_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110074u)
/** Alias (User Manual Name) for LMU1_RGN2_UA.
* To use register names with standard convension, please use LMU1_RGN2_UA.
*/
#define LMU1_RGNUA2 (LMU1_RGN2_UA)

/** \brief 78, LMU Region Write Access Enable Register A */
#define LMU1_RGN2_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110078u)
/** Alias (User Manual Name) for LMU1_RGN2_ACCENA.
* To use register names with standard convension, please use LMU1_RGN2_ACCENA.
*/
#define LMU1_RGNACCENWA2 (LMU1_RGN2_ACCENA)

/** \brief 7C, LMU Region Write Access Enable Register B */
#define LMU1_RGN2_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811007Cu)
/** Alias (User Manual Name) for LMU1_RGN2_ACCENB.
* To use register names with standard convension, please use LMU1_RGN2_ACCENB.
*/
#define LMU1_RGNACCENWB2 (LMU1_RGN2_ACCENB)

/** \brief 80, LMU Region Lower Address Register */
#define LMU1_RGN3_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110080u)
/** Alias (User Manual Name) for LMU1_RGN3_LA.
* To use register names with standard convension, please use LMU1_RGN3_LA.
*/
#define LMU1_RGNLA3 (LMU1_RGN3_LA)

/** \brief 84, LMU Region Upper Address Register */
#define LMU1_RGN3_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110084u)
/** Alias (User Manual Name) for LMU1_RGN3_UA.
* To use register names with standard convension, please use LMU1_RGN3_UA.
*/
#define LMU1_RGNUA3 (LMU1_RGN3_UA)

/** \brief 88, LMU Region Write Access Enable Register A */
#define LMU1_RGN3_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110088u)
/** Alias (User Manual Name) for LMU1_RGN3_ACCENA.
* To use register names with standard convension, please use LMU1_RGN3_ACCENA.
*/
#define LMU1_RGNACCENWA3 (LMU1_RGN3_ACCENA)

/** \brief 8C, LMU Region Write Access Enable Register B */
#define LMU1_RGN3_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811008Cu)
/** Alias (User Manual Name) for LMU1_RGN3_ACCENB.
* To use register names with standard convension, please use LMU1_RGN3_ACCENB.
*/
#define LMU1_RGNACCENWB3 (LMU1_RGN3_ACCENB)

/** \brief 90, LMU Region Lower Address Register */
#define LMU1_RGN4_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110090u)
/** Alias (User Manual Name) for LMU1_RGN4_LA.
* To use register names with standard convension, please use LMU1_RGN4_LA.
*/
#define LMU1_RGNLA4 (LMU1_RGN4_LA)

/** \brief 94, LMU Region Upper Address Register */
#define LMU1_RGN4_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110094u)
/** Alias (User Manual Name) for LMU1_RGN4_UA.
* To use register names with standard convension, please use LMU1_RGN4_UA.
*/
#define LMU1_RGNUA4 (LMU1_RGN4_UA)

/** \brief 98, LMU Region Write Access Enable Register A */
#define LMU1_RGN4_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110098u)
/** Alias (User Manual Name) for LMU1_RGN4_ACCENA.
* To use register names with standard convension, please use LMU1_RGN4_ACCENA.
*/
#define LMU1_RGNACCENWA4 (LMU1_RGN4_ACCENA)

/** \brief 9C, LMU Region Write Access Enable Register B */
#define LMU1_RGN4_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811009Cu)
/** Alias (User Manual Name) for LMU1_RGN4_ACCENB.
* To use register names with standard convension, please use LMU1_RGN4_ACCENB.
*/
#define LMU1_RGNACCENWB4 (LMU1_RGN4_ACCENB)

/** \brief A0, LMU Region Lower Address Register */
#define LMU1_RGN5_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81100A0u)
/** Alias (User Manual Name) for LMU1_RGN5_LA.
* To use register names with standard convension, please use LMU1_RGN5_LA.
*/
#define LMU1_RGNLA5 (LMU1_RGN5_LA)

/** \brief A4, LMU Region Upper Address Register */
#define LMU1_RGN5_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81100A4u)
/** Alias (User Manual Name) for LMU1_RGN5_UA.
* To use register names with standard convension, please use LMU1_RGN5_UA.
*/
#define LMU1_RGNUA5 (LMU1_RGN5_UA)

/** \brief A8, LMU Region Write Access Enable Register A */
#define LMU1_RGN5_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81100A8u)
/** Alias (User Manual Name) for LMU1_RGN5_ACCENA.
* To use register names with standard convension, please use LMU1_RGN5_ACCENA.
*/
#define LMU1_RGNACCENWA5 (LMU1_RGN5_ACCENA)

/** \brief AC, LMU Region Write Access Enable Register B */
#define LMU1_RGN5_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81100ACu)
/** Alias (User Manual Name) for LMU1_RGN5_ACCENB.
* To use register names with standard convension, please use LMU1_RGN5_ACCENB.
*/
#define LMU1_RGNACCENWB5 (LMU1_RGN5_ACCENB)

/** \brief B0, LMU Region Lower Address Register */
#define LMU1_RGN6_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81100B0u)
/** Alias (User Manual Name) for LMU1_RGN6_LA.
* To use register names with standard convension, please use LMU1_RGN6_LA.
*/
#define LMU1_RGNLA6 (LMU1_RGN6_LA)

/** \brief B4, LMU Region Upper Address Register */
#define LMU1_RGN6_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81100B4u)
/** Alias (User Manual Name) for LMU1_RGN6_UA.
* To use register names with standard convension, please use LMU1_RGN6_UA.
*/
#define LMU1_RGNUA6 (LMU1_RGN6_UA)

/** \brief B8, LMU Region Write Access Enable Register A */
#define LMU1_RGN6_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81100B8u)
/** Alias (User Manual Name) for LMU1_RGN6_ACCENA.
* To use register names with standard convension, please use LMU1_RGN6_ACCENA.
*/
#define LMU1_RGNACCENWA6 (LMU1_RGN6_ACCENA)

/** \brief BC, LMU Region Write Access Enable Register B */
#define LMU1_RGN6_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81100BCu)
/** Alias (User Manual Name) for LMU1_RGN6_ACCENB.
* To use register names with standard convension, please use LMU1_RGN6_ACCENB.
*/
#define LMU1_RGNACCENWB6 (LMU1_RGN6_ACCENB)

/** \brief C0, LMU Region Lower Address Register */
#define LMU1_RGN7_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81100C0u)
/** Alias (User Manual Name) for LMU1_RGN7_LA.
* To use register names with standard convension, please use LMU1_RGN7_LA.
*/
#define LMU1_RGNLA7 (LMU1_RGN7_LA)

/** \brief C4, LMU Region Upper Address Register */
#define LMU1_RGN7_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81100C4u)
/** Alias (User Manual Name) for LMU1_RGN7_UA.
* To use register names with standard convension, please use LMU1_RGN7_UA.
*/
#define LMU1_RGNUA7 (LMU1_RGN7_UA)

/** \brief C8, LMU Region Write Access Enable Register A */
#define LMU1_RGN7_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81100C8u)
/** Alias (User Manual Name) for LMU1_RGN7_ACCENA.
* To use register names with standard convension, please use LMU1_RGN7_ACCENA.
*/
#define LMU1_RGNACCENWA7 (LMU1_RGN7_ACCENA)

/** \brief CC, LMU Region Write Access Enable Register B */
#define LMU1_RGN7_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81100CCu)
/** Alias (User Manual Name) for LMU1_RGN7_ACCENB.
* To use register names with standard convension, please use LMU1_RGN7_ACCENB.
*/
#define LMU1_RGNACCENWB7 (LMU1_RGN7_ACCENB)

/** \brief D0, LMU Region Lower Address Register */
#define LMU1_RGN8_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81100D0u)
/** Alias (User Manual Name) for LMU1_RGN8_LA.
* To use register names with standard convension, please use LMU1_RGN8_LA.
*/
#define LMU1_RGNLA8 (LMU1_RGN8_LA)

/** \brief D4, LMU Region Upper Address Register */
#define LMU1_RGN8_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81100D4u)
/** Alias (User Manual Name) for LMU1_RGN8_UA.
* To use register names with standard convension, please use LMU1_RGN8_UA.
*/
#define LMU1_RGNUA8 (LMU1_RGN8_UA)

/** \brief D8, LMU Region Write Access Enable Register A */
#define LMU1_RGN8_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81100D8u)
/** Alias (User Manual Name) for LMU1_RGN8_ACCENA.
* To use register names with standard convension, please use LMU1_RGN8_ACCENA.
*/
#define LMU1_RGNACCENWA8 (LMU1_RGN8_ACCENA)

/** \brief DC, LMU Region Write Access Enable Register B */
#define LMU1_RGN8_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81100DCu)
/** Alias (User Manual Name) for LMU1_RGN8_ACCENB.
* To use register names with standard convension, please use LMU1_RGN8_ACCENB.
*/
#define LMU1_RGNACCENWB8 (LMU1_RGN8_ACCENB)

/** \brief E0, LMU Region Lower Address Register */
#define LMU1_RGN9_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81100E0u)
/** Alias (User Manual Name) for LMU1_RGN9_LA.
* To use register names with standard convension, please use LMU1_RGN9_LA.
*/
#define LMU1_RGNLA9 (LMU1_RGN9_LA)

/** \brief E4, LMU Region Upper Address Register */
#define LMU1_RGN9_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81100E4u)
/** Alias (User Manual Name) for LMU1_RGN9_UA.
* To use register names with standard convension, please use LMU1_RGN9_UA.
*/
#define LMU1_RGNUA9 (LMU1_RGN9_UA)

/** \brief E8, LMU Region Write Access Enable Register A */
#define LMU1_RGN9_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81100E8u)
/** Alias (User Manual Name) for LMU1_RGN9_ACCENA.
* To use register names with standard convension, please use LMU1_RGN9_ACCENA.
*/
#define LMU1_RGNACCENWA9 (LMU1_RGN9_ACCENA)

/** \brief EC, LMU Region Write Access Enable Register B */
#define LMU1_RGN9_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81100ECu)
/** Alias (User Manual Name) for LMU1_RGN9_ACCENB.
* To use register names with standard convension, please use LMU1_RGN9_ACCENB.
*/
#define LMU1_RGNACCENWB9 (LMU1_RGN9_ACCENB)

/** \brief F0, LMU Region Lower Address Register */
#define LMU1_RGN10_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81100F0u)
/** Alias (User Manual Name) for LMU1_RGN10_LA.
* To use register names with standard convension, please use LMU1_RGN10_LA.
*/
#define LMU1_RGNLA10 (LMU1_RGN10_LA)

/** \brief F4, LMU Region Upper Address Register */
#define LMU1_RGN10_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81100F4u)
/** Alias (User Manual Name) for LMU1_RGN10_UA.
* To use register names with standard convension, please use LMU1_RGN10_UA.
*/
#define LMU1_RGNUA10 (LMU1_RGN10_UA)

/** \brief F8, LMU Region Write Access Enable Register A */
#define LMU1_RGN10_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81100F8u)
/** Alias (User Manual Name) for LMU1_RGN10_ACCENA.
* To use register names with standard convension, please use LMU1_RGN10_ACCENA.
*/
#define LMU1_RGNACCENWA10 (LMU1_RGN10_ACCENA)

/** \brief FC, LMU Region Write Access Enable Register B */
#define LMU1_RGN10_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81100FCu)
/** Alias (User Manual Name) for LMU1_RGN10_ACCENB.
* To use register names with standard convension, please use LMU1_RGN10_ACCENB.
*/
#define LMU1_RGNACCENWB10 (LMU1_RGN10_ACCENB)

/** \brief 100, LMU Region Lower Address Register */
#define LMU1_RGN11_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110100u)
/** Alias (User Manual Name) for LMU1_RGN11_LA.
* To use register names with standard convension, please use LMU1_RGN11_LA.
*/
#define LMU1_RGNLA11 (LMU1_RGN11_LA)

/** \brief 104, LMU Region Upper Address Register */
#define LMU1_RGN11_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110104u)
/** Alias (User Manual Name) for LMU1_RGN11_UA.
* To use register names with standard convension, please use LMU1_RGN11_UA.
*/
#define LMU1_RGNUA11 (LMU1_RGN11_UA)

/** \brief 108, LMU Region Write Access Enable Register A */
#define LMU1_RGN11_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110108u)
/** Alias (User Manual Name) for LMU1_RGN11_ACCENA.
* To use register names with standard convension, please use LMU1_RGN11_ACCENA.
*/
#define LMU1_RGNACCENWA11 (LMU1_RGN11_ACCENA)

/** \brief 10C, LMU Region Write Access Enable Register B */
#define LMU1_RGN11_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811010Cu)
/** Alias (User Manual Name) for LMU1_RGN11_ACCENB.
* To use register names with standard convension, please use LMU1_RGN11_ACCENB.
*/
#define LMU1_RGNACCENWB11 (LMU1_RGN11_ACCENB)

/** \brief 110, LMU Region Lower Address Register */
#define LMU1_RGN12_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110110u)
/** Alias (User Manual Name) for LMU1_RGN12_LA.
* To use register names with standard convension, please use LMU1_RGN12_LA.
*/
#define LMU1_RGNLA12 (LMU1_RGN12_LA)

/** \brief 114, LMU Region Upper Address Register */
#define LMU1_RGN12_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110114u)
/** Alias (User Manual Name) for LMU1_RGN12_UA.
* To use register names with standard convension, please use LMU1_RGN12_UA.
*/
#define LMU1_RGNUA12 (LMU1_RGN12_UA)

/** \brief 118, LMU Region Write Access Enable Register A */
#define LMU1_RGN12_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110118u)
/** Alias (User Manual Name) for LMU1_RGN12_ACCENA.
* To use register names with standard convension, please use LMU1_RGN12_ACCENA.
*/
#define LMU1_RGNACCENWA12 (LMU1_RGN12_ACCENA)

/** \brief 11C, LMU Region Write Access Enable Register B */
#define LMU1_RGN12_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811011Cu)
/** Alias (User Manual Name) for LMU1_RGN12_ACCENB.
* To use register names with standard convension, please use LMU1_RGN12_ACCENB.
*/
#define LMU1_RGNACCENWB12 (LMU1_RGN12_ACCENB)

/** \brief 120, LMU Region Lower Address Register */
#define LMU1_RGN13_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110120u)
/** Alias (User Manual Name) for LMU1_RGN13_LA.
* To use register names with standard convension, please use LMU1_RGN13_LA.
*/
#define LMU1_RGNLA13 (LMU1_RGN13_LA)

/** \brief 124, LMU Region Upper Address Register */
#define LMU1_RGN13_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110124u)
/** Alias (User Manual Name) for LMU1_RGN13_UA.
* To use register names with standard convension, please use LMU1_RGN13_UA.
*/
#define LMU1_RGNUA13 (LMU1_RGN13_UA)

/** \brief 128, LMU Region Write Access Enable Register A */
#define LMU1_RGN13_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110128u)
/** Alias (User Manual Name) for LMU1_RGN13_ACCENA.
* To use register names with standard convension, please use LMU1_RGN13_ACCENA.
*/
#define LMU1_RGNACCENWA13 (LMU1_RGN13_ACCENA)

/** \brief 12C, LMU Region Write Access Enable Register B */
#define LMU1_RGN13_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811012Cu)
/** Alias (User Manual Name) for LMU1_RGN13_ACCENB.
* To use register names with standard convension, please use LMU1_RGN13_ACCENB.
*/
#define LMU1_RGNACCENWB13 (LMU1_RGN13_ACCENB)

/** \brief 130, LMU Region Lower Address Register */
#define LMU1_RGN14_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110130u)
/** Alias (User Manual Name) for LMU1_RGN14_LA.
* To use register names with standard convension, please use LMU1_RGN14_LA.
*/
#define LMU1_RGNLA14 (LMU1_RGN14_LA)

/** \brief 134, LMU Region Upper Address Register */
#define LMU1_RGN14_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110134u)
/** Alias (User Manual Name) for LMU1_RGN14_UA.
* To use register names with standard convension, please use LMU1_RGN14_UA.
*/
#define LMU1_RGNUA14 (LMU1_RGN14_UA)

/** \brief 138, LMU Region Write Access Enable Register A */
#define LMU1_RGN14_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110138u)
/** Alias (User Manual Name) for LMU1_RGN14_ACCENA.
* To use register names with standard convension, please use LMU1_RGN14_ACCENA.
*/
#define LMU1_RGNACCENWA14 (LMU1_RGN14_ACCENA)

/** \brief 13C, LMU Region Write Access Enable Register B */
#define LMU1_RGN14_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811013Cu)
/** Alias (User Manual Name) for LMU1_RGN14_ACCENB.
* To use register names with standard convension, please use LMU1_RGN14_ACCENB.
*/
#define LMU1_RGNACCENWB14 (LMU1_RGN14_ACCENB)

/** \brief 140, LMU Region Lower Address Register */
#define LMU1_RGN15_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8110140u)
/** Alias (User Manual Name) for LMU1_RGN15_LA.
* To use register names with standard convension, please use LMU1_RGN15_LA.
*/
#define LMU1_RGNLA15 (LMU1_RGN15_LA)

/** \brief 144, LMU Region Upper Address Register */
#define LMU1_RGN15_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8110144u)
/** Alias (User Manual Name) for LMU1_RGN15_UA.
* To use register names with standard convension, please use LMU1_RGN15_UA.
*/
#define LMU1_RGNUA15 (LMU1_RGN15_UA)

/** \brief 148, LMU Region Write Access Enable Register A */
#define LMU1_RGN15_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8110148u)
/** Alias (User Manual Name) for LMU1_RGN15_ACCENA.
* To use register names with standard convension, please use LMU1_RGN15_ACCENA.
*/
#define LMU1_RGNACCENWA15 (LMU1_RGN15_ACCENA)

/** \brief 14C, LMU Region Write Access Enable Register B */
#define LMU1_RGN15_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF811014Cu)
/** Alias (User Manual Name) for LMU1_RGN15_ACCENB.
* To use register names with standard convension, please use LMU1_RGN15_ACCENB.
*/
#define LMU1_RGNACCENWB15 (LMU1_RGN15_ACCENB)

/** \brief 158, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN0_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110158u)
/** Alias (User Manual Name) for LMU1_RGNACCEN0_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN0_RA.
*/
#define LMU1_RGNACCENRA0 (LMU1_RGNACCEN0_RA)

/** \brief 15C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN0_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811015Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN0_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN0_RB.
*/
#define LMU1_RGNACCENRB0 (LMU1_RGNACCEN0_RB)

/** \brief 168, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN1_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110168u)
/** Alias (User Manual Name) for LMU1_RGNACCEN1_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN1_RA.
*/
#define LMU1_RGNACCENRA1 (LMU1_RGNACCEN1_RA)

/** \brief 16C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN1_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811016Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN1_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN1_RB.
*/
#define LMU1_RGNACCENRB1 (LMU1_RGNACCEN1_RB)

/** \brief 178, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN2_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110178u)
/** Alias (User Manual Name) for LMU1_RGNACCEN2_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN2_RA.
*/
#define LMU1_RGNACCENRA2 (LMU1_RGNACCEN2_RA)

/** \brief 17C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN2_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811017Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN2_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN2_RB.
*/
#define LMU1_RGNACCENRB2 (LMU1_RGNACCEN2_RB)

/** \brief 188, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN3_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110188u)
/** Alias (User Manual Name) for LMU1_RGNACCEN3_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN3_RA.
*/
#define LMU1_RGNACCENRA3 (LMU1_RGNACCEN3_RA)

/** \brief 18C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN3_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811018Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN3_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN3_RB.
*/
#define LMU1_RGNACCENRB3 (LMU1_RGNACCEN3_RB)

/** \brief 198, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN4_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110198u)
/** Alias (User Manual Name) for LMU1_RGNACCEN4_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN4_RA.
*/
#define LMU1_RGNACCENRA4 (LMU1_RGNACCEN4_RA)

/** \brief 19C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN4_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811019Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN4_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN4_RB.
*/
#define LMU1_RGNACCENRB4 (LMU1_RGNACCEN4_RB)

/** \brief 1A8, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN5_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81101A8u)
/** Alias (User Manual Name) for LMU1_RGNACCEN5_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN5_RA.
*/
#define LMU1_RGNACCENRA5 (LMU1_RGNACCEN5_RA)

/** \brief 1AC, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN5_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81101ACu)
/** Alias (User Manual Name) for LMU1_RGNACCEN5_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN5_RB.
*/
#define LMU1_RGNACCENRB5 (LMU1_RGNACCEN5_RB)

/** \brief 1B8, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN6_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81101B8u)
/** Alias (User Manual Name) for LMU1_RGNACCEN6_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN6_RA.
*/
#define LMU1_RGNACCENRA6 (LMU1_RGNACCEN6_RA)

/** \brief 1BC, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN6_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81101BCu)
/** Alias (User Manual Name) for LMU1_RGNACCEN6_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN6_RB.
*/
#define LMU1_RGNACCENRB6 (LMU1_RGNACCEN6_RB)

/** \brief 1C8, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN7_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81101C8u)
/** Alias (User Manual Name) for LMU1_RGNACCEN7_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN7_RA.
*/
#define LMU1_RGNACCENRA7 (LMU1_RGNACCEN7_RA)

/** \brief 1CC, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN7_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81101CCu)
/** Alias (User Manual Name) for LMU1_RGNACCEN7_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN7_RB.
*/
#define LMU1_RGNACCENRB7 (LMU1_RGNACCEN7_RB)

/** \brief 1D8, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN8_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81101D8u)
/** Alias (User Manual Name) for LMU1_RGNACCEN8_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN8_RA.
*/
#define LMU1_RGNACCENRA8 (LMU1_RGNACCEN8_RA)

/** \brief 1DC, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN8_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81101DCu)
/** Alias (User Manual Name) for LMU1_RGNACCEN8_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN8_RB.
*/
#define LMU1_RGNACCENRB8 (LMU1_RGNACCEN8_RB)

/** \brief 1E8, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN9_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81101E8u)
/** Alias (User Manual Name) for LMU1_RGNACCEN9_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN9_RA.
*/
#define LMU1_RGNACCENRA9 (LMU1_RGNACCEN9_RA)

/** \brief 1EC, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN9_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81101ECu)
/** Alias (User Manual Name) for LMU1_RGNACCEN9_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN9_RB.
*/
#define LMU1_RGNACCENRB9 (LMU1_RGNACCEN9_RB)

/** \brief 1F8, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN10_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81101F8u)
/** Alias (User Manual Name) for LMU1_RGNACCEN10_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN10_RA.
*/
#define LMU1_RGNACCENRA10 (LMU1_RGNACCEN10_RA)

/** \brief 1FC, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN10_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81101FCu)
/** Alias (User Manual Name) for LMU1_RGNACCEN10_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN10_RB.
*/
#define LMU1_RGNACCENRB10 (LMU1_RGNACCEN10_RB)

/** \brief 208, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN11_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110208u)
/** Alias (User Manual Name) for LMU1_RGNACCEN11_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN11_RA.
*/
#define LMU1_RGNACCENRA11 (LMU1_RGNACCEN11_RA)

/** \brief 20C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN11_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811020Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN11_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN11_RB.
*/
#define LMU1_RGNACCENRB11 (LMU1_RGNACCEN11_RB)

/** \brief 218, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN12_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110218u)
/** Alias (User Manual Name) for LMU1_RGNACCEN12_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN12_RA.
*/
#define LMU1_RGNACCENRA12 (LMU1_RGNACCEN12_RA)

/** \brief 21C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN12_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811021Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN12_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN12_RB.
*/
#define LMU1_RGNACCENRB12 (LMU1_RGNACCEN12_RB)

/** \brief 228, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN13_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110228u)
/** Alias (User Manual Name) for LMU1_RGNACCEN13_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN13_RA.
*/
#define LMU1_RGNACCENRA13 (LMU1_RGNACCEN13_RA)

/** \brief 22C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN13_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811022Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN13_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN13_RB.
*/
#define LMU1_RGNACCENRB13 (LMU1_RGNACCEN13_RB)

/** \brief 238, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN14_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110238u)
/** Alias (User Manual Name) for LMU1_RGNACCEN14_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN14_RA.
*/
#define LMU1_RGNACCENRA14 (LMU1_RGNACCEN14_RA)

/** \brief 23C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN14_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811023Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN14_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN14_RB.
*/
#define LMU1_RGNACCENRB14 (LMU1_RGNACCEN14_RB)

/** \brief 248, LMU Region Read Access Enable Register A */
#define LMU1_RGNACCEN15_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8110248u)
/** Alias (User Manual Name) for LMU1_RGNACCEN15_RA.
* To use register names with standard convension, please use LMU1_RGNACCEN15_RA.
*/
#define LMU1_RGNACCENRA15 (LMU1_RGNACCEN15_RA)

/** \brief 24C, LMU Region Read Access Enable Register B */
#define LMU1_RGNACCEN15_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF811024Cu)
/** Alias (User Manual Name) for LMU1_RGNACCEN15_RB.
* To use register names with standard convension, please use LMU1_RGNACCEN15_RB.
*/
#define LMU1_RGNACCENRB15 (LMU1_RGNACCEN15_RB)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Lmu_Registers_Cfg_Lmu2
 * \{  */
/** \brief 0, LMU Clock Control Register */
#define LMU2_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_CLC*)0xF8120000u)

/** \brief 8, LMU Module ID Register */
#define LMU2_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_MODID*)0xF8120008u)

/** \brief 10, LMU Access Enable Register 0 */
#define LMU2_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_ACCEN0*)0xF8120010u)

/** \brief 14, LMU Access Enable Register 1 */
#define LMU2_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_ACCEN1*)0xF8120014u)

/** \brief 20, LMU Memory Control Register */
#define LMU2_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_MEMCON*)0xF8120020u)

/** \brief 24, LMU Safety Control Register */
#define LMU2_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_SCTRL*)0xF8120024u)

/** \brief 50, LMU Region Lower Address Register */
#define LMU2_RGN0_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120050u)
/** Alias (User Manual Name) for LMU2_RGN0_LA.
* To use register names with standard convension, please use LMU2_RGN0_LA.
*/
#define LMU2_RGNLA0 (LMU2_RGN0_LA)

/** \brief 54, LMU Region Upper Address Register */
#define LMU2_RGN0_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120054u)
/** Alias (User Manual Name) for LMU2_RGN0_UA.
* To use register names with standard convension, please use LMU2_RGN0_UA.
*/
#define LMU2_RGNUA0 (LMU2_RGN0_UA)

/** \brief 58, LMU Region Write Access Enable Register A */
#define LMU2_RGN0_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120058u)
/** Alias (User Manual Name) for LMU2_RGN0_ACCENA.
* To use register names with standard convension, please use LMU2_RGN0_ACCENA.
*/
#define LMU2_RGNACCENWA0 (LMU2_RGN0_ACCENA)

/** \brief 5C, LMU Region Write Access Enable Register B */
#define LMU2_RGN0_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812005Cu)
/** Alias (User Manual Name) for LMU2_RGN0_ACCENB.
* To use register names with standard convension, please use LMU2_RGN0_ACCENB.
*/
#define LMU2_RGNACCENWB0 (LMU2_RGN0_ACCENB)

/** \brief 60, LMU Region Lower Address Register */
#define LMU2_RGN1_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120060u)
/** Alias (User Manual Name) for LMU2_RGN1_LA.
* To use register names with standard convension, please use LMU2_RGN1_LA.
*/
#define LMU2_RGNLA1 (LMU2_RGN1_LA)

/** \brief 64, LMU Region Upper Address Register */
#define LMU2_RGN1_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120064u)
/** Alias (User Manual Name) for LMU2_RGN1_UA.
* To use register names with standard convension, please use LMU2_RGN1_UA.
*/
#define LMU2_RGNUA1 (LMU2_RGN1_UA)

/** \brief 68, LMU Region Write Access Enable Register A */
#define LMU2_RGN1_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120068u)
/** Alias (User Manual Name) for LMU2_RGN1_ACCENA.
* To use register names with standard convension, please use LMU2_RGN1_ACCENA.
*/
#define LMU2_RGNACCENWA1 (LMU2_RGN1_ACCENA)

/** \brief 6C, LMU Region Write Access Enable Register B */
#define LMU2_RGN1_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812006Cu)
/** Alias (User Manual Name) for LMU2_RGN1_ACCENB.
* To use register names with standard convension, please use LMU2_RGN1_ACCENB.
*/
#define LMU2_RGNACCENWB1 (LMU2_RGN1_ACCENB)

/** \brief 70, LMU Region Lower Address Register */
#define LMU2_RGN2_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120070u)
/** Alias (User Manual Name) for LMU2_RGN2_LA.
* To use register names with standard convension, please use LMU2_RGN2_LA.
*/
#define LMU2_RGNLA2 (LMU2_RGN2_LA)

/** \brief 74, LMU Region Upper Address Register */
#define LMU2_RGN2_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120074u)
/** Alias (User Manual Name) for LMU2_RGN2_UA.
* To use register names with standard convension, please use LMU2_RGN2_UA.
*/
#define LMU2_RGNUA2 (LMU2_RGN2_UA)

/** \brief 78, LMU Region Write Access Enable Register A */
#define LMU2_RGN2_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120078u)
/** Alias (User Manual Name) for LMU2_RGN2_ACCENA.
* To use register names with standard convension, please use LMU2_RGN2_ACCENA.
*/
#define LMU2_RGNACCENWA2 (LMU2_RGN2_ACCENA)

/** \brief 7C, LMU Region Write Access Enable Register B */
#define LMU2_RGN2_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812007Cu)
/** Alias (User Manual Name) for LMU2_RGN2_ACCENB.
* To use register names with standard convension, please use LMU2_RGN2_ACCENB.
*/
#define LMU2_RGNACCENWB2 (LMU2_RGN2_ACCENB)

/** \brief 80, LMU Region Lower Address Register */
#define LMU2_RGN3_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120080u)
/** Alias (User Manual Name) for LMU2_RGN3_LA.
* To use register names with standard convension, please use LMU2_RGN3_LA.
*/
#define LMU2_RGNLA3 (LMU2_RGN3_LA)

/** \brief 84, LMU Region Upper Address Register */
#define LMU2_RGN3_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120084u)
/** Alias (User Manual Name) for LMU2_RGN3_UA.
* To use register names with standard convension, please use LMU2_RGN3_UA.
*/
#define LMU2_RGNUA3 (LMU2_RGN3_UA)

/** \brief 88, LMU Region Write Access Enable Register A */
#define LMU2_RGN3_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120088u)
/** Alias (User Manual Name) for LMU2_RGN3_ACCENA.
* To use register names with standard convension, please use LMU2_RGN3_ACCENA.
*/
#define LMU2_RGNACCENWA3 (LMU2_RGN3_ACCENA)

/** \brief 8C, LMU Region Write Access Enable Register B */
#define LMU2_RGN3_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812008Cu)
/** Alias (User Manual Name) for LMU2_RGN3_ACCENB.
* To use register names with standard convension, please use LMU2_RGN3_ACCENB.
*/
#define LMU2_RGNACCENWB3 (LMU2_RGN3_ACCENB)

/** \brief 90, LMU Region Lower Address Register */
#define LMU2_RGN4_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120090u)
/** Alias (User Manual Name) for LMU2_RGN4_LA.
* To use register names with standard convension, please use LMU2_RGN4_LA.
*/
#define LMU2_RGNLA4 (LMU2_RGN4_LA)

/** \brief 94, LMU Region Upper Address Register */
#define LMU2_RGN4_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120094u)
/** Alias (User Manual Name) for LMU2_RGN4_UA.
* To use register names with standard convension, please use LMU2_RGN4_UA.
*/
#define LMU2_RGNUA4 (LMU2_RGN4_UA)

/** \brief 98, LMU Region Write Access Enable Register A */
#define LMU2_RGN4_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120098u)
/** Alias (User Manual Name) for LMU2_RGN4_ACCENA.
* To use register names with standard convension, please use LMU2_RGN4_ACCENA.
*/
#define LMU2_RGNACCENWA4 (LMU2_RGN4_ACCENA)

/** \brief 9C, LMU Region Write Access Enable Register B */
#define LMU2_RGN4_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812009Cu)
/** Alias (User Manual Name) for LMU2_RGN4_ACCENB.
* To use register names with standard convension, please use LMU2_RGN4_ACCENB.
*/
#define LMU2_RGNACCENWB4 (LMU2_RGN4_ACCENB)

/** \brief A0, LMU Region Lower Address Register */
#define LMU2_RGN5_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81200A0u)
/** Alias (User Manual Name) for LMU2_RGN5_LA.
* To use register names with standard convension, please use LMU2_RGN5_LA.
*/
#define LMU2_RGNLA5 (LMU2_RGN5_LA)

/** \brief A4, LMU Region Upper Address Register */
#define LMU2_RGN5_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81200A4u)
/** Alias (User Manual Name) for LMU2_RGN5_UA.
* To use register names with standard convension, please use LMU2_RGN5_UA.
*/
#define LMU2_RGNUA5 (LMU2_RGN5_UA)

/** \brief A8, LMU Region Write Access Enable Register A */
#define LMU2_RGN5_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81200A8u)
/** Alias (User Manual Name) for LMU2_RGN5_ACCENA.
* To use register names with standard convension, please use LMU2_RGN5_ACCENA.
*/
#define LMU2_RGNACCENWA5 (LMU2_RGN5_ACCENA)

/** \brief AC, LMU Region Write Access Enable Register B */
#define LMU2_RGN5_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81200ACu)
/** Alias (User Manual Name) for LMU2_RGN5_ACCENB.
* To use register names with standard convension, please use LMU2_RGN5_ACCENB.
*/
#define LMU2_RGNACCENWB5 (LMU2_RGN5_ACCENB)

/** \brief B0, LMU Region Lower Address Register */
#define LMU2_RGN6_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81200B0u)
/** Alias (User Manual Name) for LMU2_RGN6_LA.
* To use register names with standard convension, please use LMU2_RGN6_LA.
*/
#define LMU2_RGNLA6 (LMU2_RGN6_LA)

/** \brief B4, LMU Region Upper Address Register */
#define LMU2_RGN6_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81200B4u)
/** Alias (User Manual Name) for LMU2_RGN6_UA.
* To use register names with standard convension, please use LMU2_RGN6_UA.
*/
#define LMU2_RGNUA6 (LMU2_RGN6_UA)

/** \brief B8, LMU Region Write Access Enable Register A */
#define LMU2_RGN6_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81200B8u)
/** Alias (User Manual Name) for LMU2_RGN6_ACCENA.
* To use register names with standard convension, please use LMU2_RGN6_ACCENA.
*/
#define LMU2_RGNACCENWA6 (LMU2_RGN6_ACCENA)

/** \brief BC, LMU Region Write Access Enable Register B */
#define LMU2_RGN6_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81200BCu)
/** Alias (User Manual Name) for LMU2_RGN6_ACCENB.
* To use register names with standard convension, please use LMU2_RGN6_ACCENB.
*/
#define LMU2_RGNACCENWB6 (LMU2_RGN6_ACCENB)

/** \brief C0, LMU Region Lower Address Register */
#define LMU2_RGN7_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81200C0u)
/** Alias (User Manual Name) for LMU2_RGN7_LA.
* To use register names with standard convension, please use LMU2_RGN7_LA.
*/
#define LMU2_RGNLA7 (LMU2_RGN7_LA)

/** \brief C4, LMU Region Upper Address Register */
#define LMU2_RGN7_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81200C4u)
/** Alias (User Manual Name) for LMU2_RGN7_UA.
* To use register names with standard convension, please use LMU2_RGN7_UA.
*/
#define LMU2_RGNUA7 (LMU2_RGN7_UA)

/** \brief C8, LMU Region Write Access Enable Register A */
#define LMU2_RGN7_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81200C8u)
/** Alias (User Manual Name) for LMU2_RGN7_ACCENA.
* To use register names with standard convension, please use LMU2_RGN7_ACCENA.
*/
#define LMU2_RGNACCENWA7 (LMU2_RGN7_ACCENA)

/** \brief CC, LMU Region Write Access Enable Register B */
#define LMU2_RGN7_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81200CCu)
/** Alias (User Manual Name) for LMU2_RGN7_ACCENB.
* To use register names with standard convension, please use LMU2_RGN7_ACCENB.
*/
#define LMU2_RGNACCENWB7 (LMU2_RGN7_ACCENB)

/** \brief D0, LMU Region Lower Address Register */
#define LMU2_RGN8_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81200D0u)
/** Alias (User Manual Name) for LMU2_RGN8_LA.
* To use register names with standard convension, please use LMU2_RGN8_LA.
*/
#define LMU2_RGNLA8 (LMU2_RGN8_LA)

/** \brief D4, LMU Region Upper Address Register */
#define LMU2_RGN8_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81200D4u)
/** Alias (User Manual Name) for LMU2_RGN8_UA.
* To use register names with standard convension, please use LMU2_RGN8_UA.
*/
#define LMU2_RGNUA8 (LMU2_RGN8_UA)

/** \brief D8, LMU Region Write Access Enable Register A */
#define LMU2_RGN8_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81200D8u)
/** Alias (User Manual Name) for LMU2_RGN8_ACCENA.
* To use register names with standard convension, please use LMU2_RGN8_ACCENA.
*/
#define LMU2_RGNACCENWA8 (LMU2_RGN8_ACCENA)

/** \brief DC, LMU Region Write Access Enable Register B */
#define LMU2_RGN8_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81200DCu)
/** Alias (User Manual Name) for LMU2_RGN8_ACCENB.
* To use register names with standard convension, please use LMU2_RGN8_ACCENB.
*/
#define LMU2_RGNACCENWB8 (LMU2_RGN8_ACCENB)

/** \brief E0, LMU Region Lower Address Register */
#define LMU2_RGN9_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81200E0u)
/** Alias (User Manual Name) for LMU2_RGN9_LA.
* To use register names with standard convension, please use LMU2_RGN9_LA.
*/
#define LMU2_RGNLA9 (LMU2_RGN9_LA)

/** \brief E4, LMU Region Upper Address Register */
#define LMU2_RGN9_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81200E4u)
/** Alias (User Manual Name) for LMU2_RGN9_UA.
* To use register names with standard convension, please use LMU2_RGN9_UA.
*/
#define LMU2_RGNUA9 (LMU2_RGN9_UA)

/** \brief E8, LMU Region Write Access Enable Register A */
#define LMU2_RGN9_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81200E8u)
/** Alias (User Manual Name) for LMU2_RGN9_ACCENA.
* To use register names with standard convension, please use LMU2_RGN9_ACCENA.
*/
#define LMU2_RGNACCENWA9 (LMU2_RGN9_ACCENA)

/** \brief EC, LMU Region Write Access Enable Register B */
#define LMU2_RGN9_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81200ECu)
/** Alias (User Manual Name) for LMU2_RGN9_ACCENB.
* To use register names with standard convension, please use LMU2_RGN9_ACCENB.
*/
#define LMU2_RGNACCENWB9 (LMU2_RGN9_ACCENB)

/** \brief F0, LMU Region Lower Address Register */
#define LMU2_RGN10_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF81200F0u)
/** Alias (User Manual Name) for LMU2_RGN10_LA.
* To use register names with standard convension, please use LMU2_RGN10_LA.
*/
#define LMU2_RGNLA10 (LMU2_RGN10_LA)

/** \brief F4, LMU Region Upper Address Register */
#define LMU2_RGN10_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF81200F4u)
/** Alias (User Manual Name) for LMU2_RGN10_UA.
* To use register names with standard convension, please use LMU2_RGN10_UA.
*/
#define LMU2_RGNUA10 (LMU2_RGN10_UA)

/** \brief F8, LMU Region Write Access Enable Register A */
#define LMU2_RGN10_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF81200F8u)
/** Alias (User Manual Name) for LMU2_RGN10_ACCENA.
* To use register names with standard convension, please use LMU2_RGN10_ACCENA.
*/
#define LMU2_RGNACCENWA10 (LMU2_RGN10_ACCENA)

/** \brief FC, LMU Region Write Access Enable Register B */
#define LMU2_RGN10_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF81200FCu)
/** Alias (User Manual Name) for LMU2_RGN10_ACCENB.
* To use register names with standard convension, please use LMU2_RGN10_ACCENB.
*/
#define LMU2_RGNACCENWB10 (LMU2_RGN10_ACCENB)

/** \brief 100, LMU Region Lower Address Register */
#define LMU2_RGN11_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120100u)
/** Alias (User Manual Name) for LMU2_RGN11_LA.
* To use register names with standard convension, please use LMU2_RGN11_LA.
*/
#define LMU2_RGNLA11 (LMU2_RGN11_LA)

/** \brief 104, LMU Region Upper Address Register */
#define LMU2_RGN11_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120104u)
/** Alias (User Manual Name) for LMU2_RGN11_UA.
* To use register names with standard convension, please use LMU2_RGN11_UA.
*/
#define LMU2_RGNUA11 (LMU2_RGN11_UA)

/** \brief 108, LMU Region Write Access Enable Register A */
#define LMU2_RGN11_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120108u)
/** Alias (User Manual Name) for LMU2_RGN11_ACCENA.
* To use register names with standard convension, please use LMU2_RGN11_ACCENA.
*/
#define LMU2_RGNACCENWA11 (LMU2_RGN11_ACCENA)

/** \brief 10C, LMU Region Write Access Enable Register B */
#define LMU2_RGN11_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812010Cu)
/** Alias (User Manual Name) for LMU2_RGN11_ACCENB.
* To use register names with standard convension, please use LMU2_RGN11_ACCENB.
*/
#define LMU2_RGNACCENWB11 (LMU2_RGN11_ACCENB)

/** \brief 110, LMU Region Lower Address Register */
#define LMU2_RGN12_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120110u)
/** Alias (User Manual Name) for LMU2_RGN12_LA.
* To use register names with standard convension, please use LMU2_RGN12_LA.
*/
#define LMU2_RGNLA12 (LMU2_RGN12_LA)

/** \brief 114, LMU Region Upper Address Register */
#define LMU2_RGN12_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120114u)
/** Alias (User Manual Name) for LMU2_RGN12_UA.
* To use register names with standard convension, please use LMU2_RGN12_UA.
*/
#define LMU2_RGNUA12 (LMU2_RGN12_UA)

/** \brief 118, LMU Region Write Access Enable Register A */
#define LMU2_RGN12_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120118u)
/** Alias (User Manual Name) for LMU2_RGN12_ACCENA.
* To use register names with standard convension, please use LMU2_RGN12_ACCENA.
*/
#define LMU2_RGNACCENWA12 (LMU2_RGN12_ACCENA)

/** \brief 11C, LMU Region Write Access Enable Register B */
#define LMU2_RGN12_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812011Cu)
/** Alias (User Manual Name) for LMU2_RGN12_ACCENB.
* To use register names with standard convension, please use LMU2_RGN12_ACCENB.
*/
#define LMU2_RGNACCENWB12 (LMU2_RGN12_ACCENB)

/** \brief 120, LMU Region Lower Address Register */
#define LMU2_RGN13_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120120u)
/** Alias (User Manual Name) for LMU2_RGN13_LA.
* To use register names with standard convension, please use LMU2_RGN13_LA.
*/
#define LMU2_RGNLA13 (LMU2_RGN13_LA)

/** \brief 124, LMU Region Upper Address Register */
#define LMU2_RGN13_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120124u)
/** Alias (User Manual Name) for LMU2_RGN13_UA.
* To use register names with standard convension, please use LMU2_RGN13_UA.
*/
#define LMU2_RGNUA13 (LMU2_RGN13_UA)

/** \brief 128, LMU Region Write Access Enable Register A */
#define LMU2_RGN13_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120128u)
/** Alias (User Manual Name) for LMU2_RGN13_ACCENA.
* To use register names with standard convension, please use LMU2_RGN13_ACCENA.
*/
#define LMU2_RGNACCENWA13 (LMU2_RGN13_ACCENA)

/** \brief 12C, LMU Region Write Access Enable Register B */
#define LMU2_RGN13_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812012Cu)
/** Alias (User Manual Name) for LMU2_RGN13_ACCENB.
* To use register names with standard convension, please use LMU2_RGN13_ACCENB.
*/
#define LMU2_RGNACCENWB13 (LMU2_RGN13_ACCENB)

/** \brief 130, LMU Region Lower Address Register */
#define LMU2_RGN14_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120130u)
/** Alias (User Manual Name) for LMU2_RGN14_LA.
* To use register names with standard convension, please use LMU2_RGN14_LA.
*/
#define LMU2_RGNLA14 (LMU2_RGN14_LA)

/** \brief 134, LMU Region Upper Address Register */
#define LMU2_RGN14_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120134u)
/** Alias (User Manual Name) for LMU2_RGN14_UA.
* To use register names with standard convension, please use LMU2_RGN14_UA.
*/
#define LMU2_RGNUA14 (LMU2_RGN14_UA)

/** \brief 138, LMU Region Write Access Enable Register A */
#define LMU2_RGN14_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120138u)
/** Alias (User Manual Name) for LMU2_RGN14_ACCENA.
* To use register names with standard convension, please use LMU2_RGN14_ACCENA.
*/
#define LMU2_RGNACCENWA14 (LMU2_RGN14_ACCENA)

/** \brief 13C, LMU Region Write Access Enable Register B */
#define LMU2_RGN14_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812013Cu)
/** Alias (User Manual Name) for LMU2_RGN14_ACCENB.
* To use register names with standard convension, please use LMU2_RGN14_ACCENB.
*/
#define LMU2_RGNACCENWB14 (LMU2_RGN14_ACCENB)

/** \brief 140, LMU Region Lower Address Register */
#define LMU2_RGN15_LA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_LA*)0xF8120140u)
/** Alias (User Manual Name) for LMU2_RGN15_LA.
* To use register names with standard convension, please use LMU2_RGN15_LA.
*/
#define LMU2_RGNLA15 (LMU2_RGN15_LA)

/** \brief 144, LMU Region Upper Address Register */
#define LMU2_RGN15_UA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_UA*)0xF8120144u)
/** Alias (User Manual Name) for LMU2_RGN15_UA.
* To use register names with standard convension, please use LMU2_RGN15_UA.
*/
#define LMU2_RGNUA15 (LMU2_RGN15_UA)

/** \brief 148, LMU Region Write Access Enable Register A */
#define LMU2_RGN15_ACCENA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENA*)0xF8120148u)
/** Alias (User Manual Name) for LMU2_RGN15_ACCENA.
* To use register names with standard convension, please use LMU2_RGN15_ACCENA.
*/
#define LMU2_RGNACCENWA15 (LMU2_RGN15_ACCENA)

/** \brief 14C, LMU Region Write Access Enable Register B */
#define LMU2_RGN15_ACCENB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGN_ACCENB*)0xF812014Cu)
/** Alias (User Manual Name) for LMU2_RGN15_ACCENB.
* To use register names with standard convension, please use LMU2_RGN15_ACCENB.
*/
#define LMU2_RGNACCENWB15 (LMU2_RGN15_ACCENB)

/** \brief 158, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN0_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120158u)
/** Alias (User Manual Name) for LMU2_RGNACCEN0_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN0_RA.
*/
#define LMU2_RGNACCENRA0 (LMU2_RGNACCEN0_RA)

/** \brief 15C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN0_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812015Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN0_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN0_RB.
*/
#define LMU2_RGNACCENRB0 (LMU2_RGNACCEN0_RB)

/** \brief 168, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN1_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120168u)
/** Alias (User Manual Name) for LMU2_RGNACCEN1_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN1_RA.
*/
#define LMU2_RGNACCENRA1 (LMU2_RGNACCEN1_RA)

/** \brief 16C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN1_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812016Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN1_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN1_RB.
*/
#define LMU2_RGNACCENRB1 (LMU2_RGNACCEN1_RB)

/** \brief 178, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN2_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120178u)
/** Alias (User Manual Name) for LMU2_RGNACCEN2_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN2_RA.
*/
#define LMU2_RGNACCENRA2 (LMU2_RGNACCEN2_RA)

/** \brief 17C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN2_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812017Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN2_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN2_RB.
*/
#define LMU2_RGNACCENRB2 (LMU2_RGNACCEN2_RB)

/** \brief 188, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN3_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120188u)
/** Alias (User Manual Name) for LMU2_RGNACCEN3_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN3_RA.
*/
#define LMU2_RGNACCENRA3 (LMU2_RGNACCEN3_RA)

/** \brief 18C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN3_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812018Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN3_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN3_RB.
*/
#define LMU2_RGNACCENRB3 (LMU2_RGNACCEN3_RB)

/** \brief 198, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN4_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120198u)
/** Alias (User Manual Name) for LMU2_RGNACCEN4_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN4_RA.
*/
#define LMU2_RGNACCENRA4 (LMU2_RGNACCEN4_RA)

/** \brief 19C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN4_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812019Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN4_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN4_RB.
*/
#define LMU2_RGNACCENRB4 (LMU2_RGNACCEN4_RB)

/** \brief 1A8, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN5_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81201A8u)
/** Alias (User Manual Name) for LMU2_RGNACCEN5_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN5_RA.
*/
#define LMU2_RGNACCENRA5 (LMU2_RGNACCEN5_RA)

/** \brief 1AC, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN5_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81201ACu)
/** Alias (User Manual Name) for LMU2_RGNACCEN5_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN5_RB.
*/
#define LMU2_RGNACCENRB5 (LMU2_RGNACCEN5_RB)

/** \brief 1B8, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN6_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81201B8u)
/** Alias (User Manual Name) for LMU2_RGNACCEN6_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN6_RA.
*/
#define LMU2_RGNACCENRA6 (LMU2_RGNACCEN6_RA)

/** \brief 1BC, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN6_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81201BCu)
/** Alias (User Manual Name) for LMU2_RGNACCEN6_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN6_RB.
*/
#define LMU2_RGNACCENRB6 (LMU2_RGNACCEN6_RB)

/** \brief 1C8, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN7_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81201C8u)
/** Alias (User Manual Name) for LMU2_RGNACCEN7_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN7_RA.
*/
#define LMU2_RGNACCENRA7 (LMU2_RGNACCEN7_RA)

/** \brief 1CC, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN7_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81201CCu)
/** Alias (User Manual Name) for LMU2_RGNACCEN7_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN7_RB.
*/
#define LMU2_RGNACCENRB7 (LMU2_RGNACCEN7_RB)

/** \brief 1D8, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN8_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81201D8u)
/** Alias (User Manual Name) for LMU2_RGNACCEN8_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN8_RA.
*/
#define LMU2_RGNACCENRA8 (LMU2_RGNACCEN8_RA)

/** \brief 1DC, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN8_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81201DCu)
/** Alias (User Manual Name) for LMU2_RGNACCEN8_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN8_RB.
*/
#define LMU2_RGNACCENRB8 (LMU2_RGNACCEN8_RB)

/** \brief 1E8, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN9_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81201E8u)
/** Alias (User Manual Name) for LMU2_RGNACCEN9_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN9_RA.
*/
#define LMU2_RGNACCENRA9 (LMU2_RGNACCEN9_RA)

/** \brief 1EC, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN9_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81201ECu)
/** Alias (User Manual Name) for LMU2_RGNACCEN9_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN9_RB.
*/
#define LMU2_RGNACCENRB9 (LMU2_RGNACCEN9_RB)

/** \brief 1F8, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN10_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF81201F8u)
/** Alias (User Manual Name) for LMU2_RGNACCEN10_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN10_RA.
*/
#define LMU2_RGNACCENRA10 (LMU2_RGNACCEN10_RA)

/** \brief 1FC, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN10_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF81201FCu)
/** Alias (User Manual Name) for LMU2_RGNACCEN10_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN10_RB.
*/
#define LMU2_RGNACCENRB10 (LMU2_RGNACCEN10_RB)

/** \brief 208, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN11_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120208u)
/** Alias (User Manual Name) for LMU2_RGNACCEN11_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN11_RA.
*/
#define LMU2_RGNACCENRA11 (LMU2_RGNACCEN11_RA)

/** \brief 20C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN11_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812020Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN11_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN11_RB.
*/
#define LMU2_RGNACCENRB11 (LMU2_RGNACCEN11_RB)

/** \brief 218, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN12_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120218u)
/** Alias (User Manual Name) for LMU2_RGNACCEN12_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN12_RA.
*/
#define LMU2_RGNACCENRA12 (LMU2_RGNACCEN12_RA)

/** \brief 21C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN12_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812021Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN12_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN12_RB.
*/
#define LMU2_RGNACCENRB12 (LMU2_RGNACCEN12_RB)

/** \brief 228, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN13_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120228u)
/** Alias (User Manual Name) for LMU2_RGNACCEN13_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN13_RA.
*/
#define LMU2_RGNACCENRA13 (LMU2_RGNACCEN13_RA)

/** \brief 22C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN13_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812022Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN13_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN13_RB.
*/
#define LMU2_RGNACCENRB13 (LMU2_RGNACCEN13_RB)

/** \brief 238, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN14_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120238u)
/** Alias (User Manual Name) for LMU2_RGNACCEN14_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN14_RA.
*/
#define LMU2_RGNACCENRA14 (LMU2_RGNACCEN14_RA)

/** \brief 23C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN14_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812023Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN14_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN14_RB.
*/
#define LMU2_RGNACCENRB14 (LMU2_RGNACCEN14_RB)

/** \brief 248, LMU Region Read Access Enable Register A */
#define LMU2_RGNACCEN15_RA /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RA*)0xF8120248u)
/** Alias (User Manual Name) for LMU2_RGNACCEN15_RA.
* To use register names with standard convension, please use LMU2_RGNACCEN15_RA.
*/
#define LMU2_RGNACCENRA15 (LMU2_RGNACCEN15_RA)

/** \brief 24C, LMU Region Read Access Enable Register B */
#define LMU2_RGNACCEN15_RB /*lint --e(923, 9078)*/ (*(volatile Ifx_LMU_RGNACCEN_RB*)0xF812024Cu)
/** Alias (User Manual Name) for LMU2_RGNACCEN15_RB.
* To use register names with standard convension, please use LMU2_RGNACCEN15_RB.
*/
#define LMU2_RGNACCENRB15 (LMU2_RGNACCEN15_RB)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXLMU_REG_H */
