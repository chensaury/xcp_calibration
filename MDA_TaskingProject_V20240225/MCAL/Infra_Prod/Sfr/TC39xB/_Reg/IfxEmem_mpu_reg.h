/**
 * \file IfxEmem_mpu_reg.h
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
 * \defgroup IfxSfr_Emem_mpu_Registers_Cfg Emem_mpu address
 * \ingroup IfxSfr_Emem_mpu_Registers
 * 
 * \defgroup IfxSfr_Emem_mpu_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Emem_mpu_Registers_Cfg
 *
 * \defgroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu0 2-EMEMMPU0
 * \ingroup IfxSfr_Emem_mpu_Registers_Cfg
 *
 * \defgroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu1 2-EMEMMPU1
 * \ingroup IfxSfr_Emem_mpu_Registers_Cfg
 *
 * \defgroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu2 2-EMEMMPU2
 * \ingroup IfxSfr_Emem_mpu_Registers_Cfg
 *
 * \defgroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu3 2-EMEMMPU3
 * \ingroup IfxSfr_Emem_mpu_Registers_Cfg
 *
 *
 */
#ifndef IFXEMEM_MPU_REG_H
#define IFXEMEM_MPU_REG_H 1
/******************************************************************************/
#include "IfxEmem_mpu_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Emem_mpu_Registers_Cfg_BaseAddress
 * \{  */

/** \brief EMEM_MPU object */
#define MODULE_EMEMMPU0 /*lint --e(923, 9078)*/ ((*(Ifx_EMEM_MPU*)0xFB000000u))
#define MODULE_EMEMMPU1 /*lint --e(923, 9078)*/ ((*(Ifx_EMEM_MPU*)0xFB010000u))
#define MODULE_EMEMMPU2 /*lint --e(923, 9078)*/ ((*(Ifx_EMEM_MPU*)0xFB020000u))
#define MODULE_EMEMMPU3 /*lint --e(923, 9078)*/ ((*(Ifx_EMEM_MPU*)0xFB030000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu0
 * \{  */
/** \brief 0, EMEM Module Clock Control Register */
#define EMEMMPU0_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_CLC*)0xFB000000u)

/** \brief 8, EMEM Module ID Register */
#define EMEMMPU0_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MODID*)0xFB000008u)

/** \brief 10, EMEM Module Access Enable Register 0 */
#define EMEMMPU0_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN0*)0xFB000010u)

/** \brief 14, EMEM Module Access Enable Register 1 */
#define EMEMMPU0_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN1*)0xFB000014u)

/** \brief 20, EMEM Module Memory Control Register */
#define EMEMMPU0_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MEMCON*)0xFB000020u)

/** \brief 24, EMEM Module Safety Control Register */
#define EMEMMPU0_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_SCTRL*)0xFB000024u)

/** \brief 50, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN0_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB000050u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN0_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN0_RGNLA.
*/
#define EMEMMPU0_RGNLA0 (EMEMMPU0_RGNWRN0_RGNLA)

/** \brief 54, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN0_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB000054u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN0_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN0_RGNUA.
*/
#define EMEMMPU0_RGNUA0 (EMEMMPU0_RGNWRN0_RGNUA)

/** \brief 58, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN0_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB000058u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN0_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN0_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA0 (EMEMMPU0_RGNWRN0_RGNACCENWA)

/** \brief 5C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN0_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB00005Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN0_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN0_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB0 (EMEMMPU0_RGNWRN0_RGNACCENWB)

/** \brief 60, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN1_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB000060u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN1_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN1_RGNLA.
*/
#define EMEMMPU0_RGNLA1 (EMEMMPU0_RGNWRN1_RGNLA)

/** \brief 64, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN1_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB000064u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN1_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN1_RGNUA.
*/
#define EMEMMPU0_RGNUA1 (EMEMMPU0_RGNWRN1_RGNUA)

/** \brief 68, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN1_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB000068u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN1_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN1_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA1 (EMEMMPU0_RGNWRN1_RGNACCENWA)

/** \brief 6C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN1_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB00006Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN1_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN1_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB1 (EMEMMPU0_RGNWRN1_RGNACCENWB)

/** \brief 70, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN2_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB000070u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN2_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN2_RGNLA.
*/
#define EMEMMPU0_RGNLA2 (EMEMMPU0_RGNWRN2_RGNLA)

/** \brief 74, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN2_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB000074u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN2_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN2_RGNUA.
*/
#define EMEMMPU0_RGNUA2 (EMEMMPU0_RGNWRN2_RGNUA)

/** \brief 78, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN2_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB000078u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN2_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN2_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA2 (EMEMMPU0_RGNWRN2_RGNACCENWA)

/** \brief 7C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN2_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB00007Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN2_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN2_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB2 (EMEMMPU0_RGNWRN2_RGNACCENWB)

/** \brief 80, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN3_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB000080u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN3_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN3_RGNLA.
*/
#define EMEMMPU0_RGNLA3 (EMEMMPU0_RGNWRN3_RGNLA)

/** \brief 84, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN3_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB000084u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN3_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN3_RGNUA.
*/
#define EMEMMPU0_RGNUA3 (EMEMMPU0_RGNWRN3_RGNUA)

/** \brief 88, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN3_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB000088u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN3_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN3_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA3 (EMEMMPU0_RGNWRN3_RGNACCENWA)

/** \brief 8C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN3_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB00008Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN3_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN3_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB3 (EMEMMPU0_RGNWRN3_RGNACCENWB)

/** \brief 90, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN4_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB000090u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN4_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN4_RGNLA.
*/
#define EMEMMPU0_RGNLA4 (EMEMMPU0_RGNWRN4_RGNLA)

/** \brief 94, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN4_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB000094u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN4_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN4_RGNUA.
*/
#define EMEMMPU0_RGNUA4 (EMEMMPU0_RGNWRN4_RGNUA)

/** \brief 98, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN4_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB000098u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN4_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN4_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA4 (EMEMMPU0_RGNWRN4_RGNACCENWA)

/** \brief 9C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN4_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB00009Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN4_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN4_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB4 (EMEMMPU0_RGNWRN4_RGNACCENWB)

/** \brief A0, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN5_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0000A0u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN5_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN5_RGNLA.
*/
#define EMEMMPU0_RGNLA5 (EMEMMPU0_RGNWRN5_RGNLA)

/** \brief A4, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN5_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0000A4u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN5_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN5_RGNUA.
*/
#define EMEMMPU0_RGNUA5 (EMEMMPU0_RGNWRN5_RGNUA)

/** \brief A8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN5_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0000A8u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN5_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN5_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA5 (EMEMMPU0_RGNWRN5_RGNACCENWA)

/** \brief AC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN5_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0000ACu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN5_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN5_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB5 (EMEMMPU0_RGNWRN5_RGNACCENWB)

/** \brief B0, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN6_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0000B0u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN6_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN6_RGNLA.
*/
#define EMEMMPU0_RGNLA6 (EMEMMPU0_RGNWRN6_RGNLA)

/** \brief B4, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN6_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0000B4u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN6_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN6_RGNUA.
*/
#define EMEMMPU0_RGNUA6 (EMEMMPU0_RGNWRN6_RGNUA)

/** \brief B8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN6_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0000B8u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN6_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN6_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA6 (EMEMMPU0_RGNWRN6_RGNACCENWA)

/** \brief BC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN6_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0000BCu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN6_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN6_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB6 (EMEMMPU0_RGNWRN6_RGNACCENWB)

/** \brief C0, EMEM Module Region i Lower Address Register */
#define EMEMMPU0_RGNWRN7_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0000C0u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN7_RGNLA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN7_RGNLA.
*/
#define EMEMMPU0_RGNLA7 (EMEMMPU0_RGNWRN7_RGNLA)

/** \brief C4, EMEM Module Region i Upper Address Register */
#define EMEMMPU0_RGNWRN7_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0000C4u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN7_RGNUA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN7_RGNUA.
*/
#define EMEMMPU0_RGNUA7 (EMEMMPU0_RGNWRN7_RGNUA)

/** \brief C8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU0_RGNWRN7_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0000C8u)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN7_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN7_RGNACCENWA.
*/
#define EMEMMPU0_RGNACCENWA7 (EMEMMPU0_RGNWRN7_RGNACCENWA)

/** \brief CC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU0_RGNWRN7_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0000CCu)
/** Alias (User Manual Name) for EMEMMPU0_RGNWRN7_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU0_RGNWRN7_RGNACCENWB.
*/
#define EMEMMPU0_RGNACCENWB7 (EMEMMPU0_RGNWRN7_RGNACCENWB)

/** \brief D8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN0_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0000D8u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN0_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN0_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA0 (EMEMMPU0_RGNACCEN0_RGNACCENRA)

/** \brief DC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN0_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0000DCu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN0_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN0_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB0 (EMEMMPU0_RGNACCEN0_RGNACCENRB)

/** \brief E8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN1_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0000E8u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN1_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN1_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA1 (EMEMMPU0_RGNACCEN1_RGNACCENRA)

/** \brief EC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN1_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0000ECu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN1_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN1_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB1 (EMEMMPU0_RGNACCEN1_RGNACCENRB)

/** \brief F8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN2_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0000F8u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN2_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN2_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA2 (EMEMMPU0_RGNACCEN2_RGNACCENRA)

/** \brief FC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN2_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0000FCu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN2_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN2_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB2 (EMEMMPU0_RGNACCEN2_RGNACCENRB)

/** \brief 108, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN3_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB000108u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN3_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN3_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA3 (EMEMMPU0_RGNACCEN3_RGNACCENRA)

/** \brief 10C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN3_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB00010Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN3_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN3_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB3 (EMEMMPU0_RGNACCEN3_RGNACCENRB)

/** \brief 118, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN4_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB000118u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN4_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN4_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA4 (EMEMMPU0_RGNACCEN4_RGNACCENRA)

/** \brief 11C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN4_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB00011Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN4_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN4_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB4 (EMEMMPU0_RGNACCEN4_RGNACCENRB)

/** \brief 128, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN5_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB000128u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN5_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN5_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA5 (EMEMMPU0_RGNACCEN5_RGNACCENRA)

/** \brief 12C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN5_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB00012Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN5_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN5_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB5 (EMEMMPU0_RGNACCEN5_RGNACCENRB)

/** \brief 138, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN6_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB000138u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN6_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN6_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA6 (EMEMMPU0_RGNACCEN6_RGNACCENRA)

/** \brief 13C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN6_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB00013Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN6_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN6_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB6 (EMEMMPU0_RGNACCEN6_RGNACCENRB)

/** \brief 148, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU0_RGNACCEN7_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB000148u)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN7_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN7_RGNACCENRA.
*/
#define EMEMMPU0_RGNACCENRA7 (EMEMMPU0_RGNACCEN7_RGNACCENRA)

/** \brief 14C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU0_RGNACCEN7_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB00014Cu)
/** Alias (User Manual Name) for EMEMMPU0_RGNACCEN7_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU0_RGNACCEN7_RGNACCENRB.
*/
#define EMEMMPU0_RGNACCENRB7 (EMEMMPU0_RGNACCEN7_RGNACCENRB)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu1
 * \{  */
/** \brief 0, EMEM Module Clock Control Register */
#define EMEMMPU1_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_CLC*)0xFB010000u)

/** \brief 8, EMEM Module ID Register */
#define EMEMMPU1_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MODID*)0xFB010008u)

/** \brief 10, EMEM Module Access Enable Register 0 */
#define EMEMMPU1_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN0*)0xFB010010u)

/** \brief 14, EMEM Module Access Enable Register 1 */
#define EMEMMPU1_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN1*)0xFB010014u)

/** \brief 20, EMEM Module Memory Control Register */
#define EMEMMPU1_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MEMCON*)0xFB010020u)

/** \brief 24, EMEM Module Safety Control Register */
#define EMEMMPU1_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_SCTRL*)0xFB010024u)

/** \brief 50, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN0_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB010050u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN0_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN0_RGNLA.
*/
#define EMEMMPU1_RGNLA0 (EMEMMPU1_RGNWRN0_RGNLA)

/** \brief 54, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN0_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB010054u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN0_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN0_RGNUA.
*/
#define EMEMMPU1_RGNUA0 (EMEMMPU1_RGNWRN0_RGNUA)

/** \brief 58, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN0_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB010058u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN0_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN0_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA0 (EMEMMPU1_RGNWRN0_RGNACCENWA)

/** \brief 5C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN0_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB01005Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN0_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN0_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB0 (EMEMMPU1_RGNWRN0_RGNACCENWB)

/** \brief 60, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN1_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB010060u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN1_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN1_RGNLA.
*/
#define EMEMMPU1_RGNLA1 (EMEMMPU1_RGNWRN1_RGNLA)

/** \brief 64, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN1_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB010064u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN1_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN1_RGNUA.
*/
#define EMEMMPU1_RGNUA1 (EMEMMPU1_RGNWRN1_RGNUA)

/** \brief 68, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN1_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB010068u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN1_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN1_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA1 (EMEMMPU1_RGNWRN1_RGNACCENWA)

/** \brief 6C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN1_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB01006Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN1_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN1_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB1 (EMEMMPU1_RGNWRN1_RGNACCENWB)

/** \brief 70, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN2_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB010070u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN2_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN2_RGNLA.
*/
#define EMEMMPU1_RGNLA2 (EMEMMPU1_RGNWRN2_RGNLA)

/** \brief 74, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN2_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB010074u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN2_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN2_RGNUA.
*/
#define EMEMMPU1_RGNUA2 (EMEMMPU1_RGNWRN2_RGNUA)

/** \brief 78, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN2_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB010078u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN2_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN2_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA2 (EMEMMPU1_RGNWRN2_RGNACCENWA)

/** \brief 7C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN2_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB01007Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN2_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN2_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB2 (EMEMMPU1_RGNWRN2_RGNACCENWB)

/** \brief 80, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN3_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB010080u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN3_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN3_RGNLA.
*/
#define EMEMMPU1_RGNLA3 (EMEMMPU1_RGNWRN3_RGNLA)

/** \brief 84, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN3_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB010084u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN3_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN3_RGNUA.
*/
#define EMEMMPU1_RGNUA3 (EMEMMPU1_RGNWRN3_RGNUA)

/** \brief 88, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN3_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB010088u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN3_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN3_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA3 (EMEMMPU1_RGNWRN3_RGNACCENWA)

/** \brief 8C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN3_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB01008Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN3_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN3_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB3 (EMEMMPU1_RGNWRN3_RGNACCENWB)

/** \brief 90, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN4_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB010090u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN4_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN4_RGNLA.
*/
#define EMEMMPU1_RGNLA4 (EMEMMPU1_RGNWRN4_RGNLA)

/** \brief 94, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN4_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB010094u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN4_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN4_RGNUA.
*/
#define EMEMMPU1_RGNUA4 (EMEMMPU1_RGNWRN4_RGNUA)

/** \brief 98, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN4_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB010098u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN4_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN4_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA4 (EMEMMPU1_RGNWRN4_RGNACCENWA)

/** \brief 9C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN4_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB01009Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN4_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN4_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB4 (EMEMMPU1_RGNWRN4_RGNACCENWB)

/** \brief A0, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN5_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0100A0u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN5_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN5_RGNLA.
*/
#define EMEMMPU1_RGNLA5 (EMEMMPU1_RGNWRN5_RGNLA)

/** \brief A4, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN5_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0100A4u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN5_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN5_RGNUA.
*/
#define EMEMMPU1_RGNUA5 (EMEMMPU1_RGNWRN5_RGNUA)

/** \brief A8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN5_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0100A8u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN5_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN5_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA5 (EMEMMPU1_RGNWRN5_RGNACCENWA)

/** \brief AC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN5_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0100ACu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN5_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN5_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB5 (EMEMMPU1_RGNWRN5_RGNACCENWB)

/** \brief B0, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN6_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0100B0u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN6_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN6_RGNLA.
*/
#define EMEMMPU1_RGNLA6 (EMEMMPU1_RGNWRN6_RGNLA)

/** \brief B4, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN6_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0100B4u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN6_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN6_RGNUA.
*/
#define EMEMMPU1_RGNUA6 (EMEMMPU1_RGNWRN6_RGNUA)

/** \brief B8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN6_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0100B8u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN6_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN6_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA6 (EMEMMPU1_RGNWRN6_RGNACCENWA)

/** \brief BC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN6_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0100BCu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN6_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN6_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB6 (EMEMMPU1_RGNWRN6_RGNACCENWB)

/** \brief C0, EMEM Module Region i Lower Address Register */
#define EMEMMPU1_RGNWRN7_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0100C0u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN7_RGNLA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN7_RGNLA.
*/
#define EMEMMPU1_RGNLA7 (EMEMMPU1_RGNWRN7_RGNLA)

/** \brief C4, EMEM Module Region i Upper Address Register */
#define EMEMMPU1_RGNWRN7_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0100C4u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN7_RGNUA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN7_RGNUA.
*/
#define EMEMMPU1_RGNUA7 (EMEMMPU1_RGNWRN7_RGNUA)

/** \brief C8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU1_RGNWRN7_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0100C8u)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN7_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN7_RGNACCENWA.
*/
#define EMEMMPU1_RGNACCENWA7 (EMEMMPU1_RGNWRN7_RGNACCENWA)

/** \brief CC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU1_RGNWRN7_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0100CCu)
/** Alias (User Manual Name) for EMEMMPU1_RGNWRN7_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU1_RGNWRN7_RGNACCENWB.
*/
#define EMEMMPU1_RGNACCENWB7 (EMEMMPU1_RGNWRN7_RGNACCENWB)

/** \brief D8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN0_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0100D8u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN0_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN0_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA0 (EMEMMPU1_RGNACCEN0_RGNACCENRA)

/** \brief DC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN0_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0100DCu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN0_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN0_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB0 (EMEMMPU1_RGNACCEN0_RGNACCENRB)

/** \brief E8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN1_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0100E8u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN1_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN1_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA1 (EMEMMPU1_RGNACCEN1_RGNACCENRA)

/** \brief EC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN1_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0100ECu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN1_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN1_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB1 (EMEMMPU1_RGNACCEN1_RGNACCENRB)

/** \brief F8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN2_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0100F8u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN2_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN2_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA2 (EMEMMPU1_RGNACCEN2_RGNACCENRA)

/** \brief FC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN2_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0100FCu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN2_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN2_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB2 (EMEMMPU1_RGNACCEN2_RGNACCENRB)

/** \brief 108, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN3_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB010108u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN3_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN3_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA3 (EMEMMPU1_RGNACCEN3_RGNACCENRA)

/** \brief 10C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN3_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB01010Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN3_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN3_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB3 (EMEMMPU1_RGNACCEN3_RGNACCENRB)

/** \brief 118, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN4_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB010118u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN4_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN4_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA4 (EMEMMPU1_RGNACCEN4_RGNACCENRA)

/** \brief 11C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN4_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB01011Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN4_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN4_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB4 (EMEMMPU1_RGNACCEN4_RGNACCENRB)

/** \brief 128, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN5_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB010128u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN5_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN5_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA5 (EMEMMPU1_RGNACCEN5_RGNACCENRA)

/** \brief 12C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN5_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB01012Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN5_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN5_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB5 (EMEMMPU1_RGNACCEN5_RGNACCENRB)

/** \brief 138, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN6_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB010138u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN6_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN6_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA6 (EMEMMPU1_RGNACCEN6_RGNACCENRA)

/** \brief 13C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN6_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB01013Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN6_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN6_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB6 (EMEMMPU1_RGNACCEN6_RGNACCENRB)

/** \brief 148, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU1_RGNACCEN7_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB010148u)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN7_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN7_RGNACCENRA.
*/
#define EMEMMPU1_RGNACCENRA7 (EMEMMPU1_RGNACCEN7_RGNACCENRA)

/** \brief 14C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU1_RGNACCEN7_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB01014Cu)
/** Alias (User Manual Name) for EMEMMPU1_RGNACCEN7_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU1_RGNACCEN7_RGNACCENRB.
*/
#define EMEMMPU1_RGNACCENRB7 (EMEMMPU1_RGNACCEN7_RGNACCENRB)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu2
 * \{  */
/** \brief 0, EMEM Module Clock Control Register */
#define EMEMMPU2_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_CLC*)0xFB020000u)

/** \brief 8, EMEM Module ID Register */
#define EMEMMPU2_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MODID*)0xFB020008u)

/** \brief 10, EMEM Module Access Enable Register 0 */
#define EMEMMPU2_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN0*)0xFB020010u)

/** \brief 14, EMEM Module Access Enable Register 1 */
#define EMEMMPU2_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN1*)0xFB020014u)

/** \brief 20, EMEM Module Memory Control Register */
#define EMEMMPU2_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MEMCON*)0xFB020020u)

/** \brief 24, EMEM Module Safety Control Register */
#define EMEMMPU2_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_SCTRL*)0xFB020024u)

/** \brief 50, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN0_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB020050u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN0_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN0_RGNLA.
*/
#define EMEMMPU2_RGNLA0 (EMEMMPU2_RGNWRN0_RGNLA)

/** \brief 54, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN0_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB020054u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN0_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN0_RGNUA.
*/
#define EMEMMPU2_RGNUA0 (EMEMMPU2_RGNWRN0_RGNUA)

/** \brief 58, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN0_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB020058u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN0_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN0_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA0 (EMEMMPU2_RGNWRN0_RGNACCENWA)

/** \brief 5C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN0_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB02005Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN0_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN0_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB0 (EMEMMPU2_RGNWRN0_RGNACCENWB)

/** \brief 60, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN1_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB020060u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN1_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN1_RGNLA.
*/
#define EMEMMPU2_RGNLA1 (EMEMMPU2_RGNWRN1_RGNLA)

/** \brief 64, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN1_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB020064u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN1_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN1_RGNUA.
*/
#define EMEMMPU2_RGNUA1 (EMEMMPU2_RGNWRN1_RGNUA)

/** \brief 68, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN1_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB020068u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN1_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN1_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA1 (EMEMMPU2_RGNWRN1_RGNACCENWA)

/** \brief 6C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN1_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB02006Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN1_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN1_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB1 (EMEMMPU2_RGNWRN1_RGNACCENWB)

/** \brief 70, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN2_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB020070u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN2_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN2_RGNLA.
*/
#define EMEMMPU2_RGNLA2 (EMEMMPU2_RGNWRN2_RGNLA)

/** \brief 74, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN2_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB020074u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN2_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN2_RGNUA.
*/
#define EMEMMPU2_RGNUA2 (EMEMMPU2_RGNWRN2_RGNUA)

/** \brief 78, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN2_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB020078u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN2_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN2_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA2 (EMEMMPU2_RGNWRN2_RGNACCENWA)

/** \brief 7C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN2_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB02007Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN2_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN2_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB2 (EMEMMPU2_RGNWRN2_RGNACCENWB)

/** \brief 80, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN3_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB020080u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN3_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN3_RGNLA.
*/
#define EMEMMPU2_RGNLA3 (EMEMMPU2_RGNWRN3_RGNLA)

/** \brief 84, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN3_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB020084u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN3_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN3_RGNUA.
*/
#define EMEMMPU2_RGNUA3 (EMEMMPU2_RGNWRN3_RGNUA)

/** \brief 88, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN3_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB020088u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN3_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN3_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA3 (EMEMMPU2_RGNWRN3_RGNACCENWA)

/** \brief 8C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN3_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB02008Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN3_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN3_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB3 (EMEMMPU2_RGNWRN3_RGNACCENWB)

/** \brief 90, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN4_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB020090u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN4_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN4_RGNLA.
*/
#define EMEMMPU2_RGNLA4 (EMEMMPU2_RGNWRN4_RGNLA)

/** \brief 94, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN4_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB020094u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN4_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN4_RGNUA.
*/
#define EMEMMPU2_RGNUA4 (EMEMMPU2_RGNWRN4_RGNUA)

/** \brief 98, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN4_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB020098u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN4_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN4_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA4 (EMEMMPU2_RGNWRN4_RGNACCENWA)

/** \brief 9C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN4_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB02009Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN4_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN4_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB4 (EMEMMPU2_RGNWRN4_RGNACCENWB)

/** \brief A0, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN5_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0200A0u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN5_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN5_RGNLA.
*/
#define EMEMMPU2_RGNLA5 (EMEMMPU2_RGNWRN5_RGNLA)

/** \brief A4, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN5_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0200A4u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN5_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN5_RGNUA.
*/
#define EMEMMPU2_RGNUA5 (EMEMMPU2_RGNWRN5_RGNUA)

/** \brief A8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN5_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0200A8u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN5_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN5_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA5 (EMEMMPU2_RGNWRN5_RGNACCENWA)

/** \brief AC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN5_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0200ACu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN5_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN5_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB5 (EMEMMPU2_RGNWRN5_RGNACCENWB)

/** \brief B0, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN6_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0200B0u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN6_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN6_RGNLA.
*/
#define EMEMMPU2_RGNLA6 (EMEMMPU2_RGNWRN6_RGNLA)

/** \brief B4, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN6_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0200B4u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN6_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN6_RGNUA.
*/
#define EMEMMPU2_RGNUA6 (EMEMMPU2_RGNWRN6_RGNUA)

/** \brief B8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN6_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0200B8u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN6_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN6_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA6 (EMEMMPU2_RGNWRN6_RGNACCENWA)

/** \brief BC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN6_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0200BCu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN6_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN6_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB6 (EMEMMPU2_RGNWRN6_RGNACCENWB)

/** \brief C0, EMEM Module Region i Lower Address Register */
#define EMEMMPU2_RGNWRN7_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0200C0u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN7_RGNLA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN7_RGNLA.
*/
#define EMEMMPU2_RGNLA7 (EMEMMPU2_RGNWRN7_RGNLA)

/** \brief C4, EMEM Module Region i Upper Address Register */
#define EMEMMPU2_RGNWRN7_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0200C4u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN7_RGNUA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN7_RGNUA.
*/
#define EMEMMPU2_RGNUA7 (EMEMMPU2_RGNWRN7_RGNUA)

/** \brief C8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU2_RGNWRN7_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0200C8u)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN7_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN7_RGNACCENWA.
*/
#define EMEMMPU2_RGNACCENWA7 (EMEMMPU2_RGNWRN7_RGNACCENWA)

/** \brief CC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU2_RGNWRN7_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0200CCu)
/** Alias (User Manual Name) for EMEMMPU2_RGNWRN7_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU2_RGNWRN7_RGNACCENWB.
*/
#define EMEMMPU2_RGNACCENWB7 (EMEMMPU2_RGNWRN7_RGNACCENWB)

/** \brief D8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN0_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0200D8u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN0_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN0_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA0 (EMEMMPU2_RGNACCEN0_RGNACCENRA)

/** \brief DC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN0_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0200DCu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN0_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN0_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB0 (EMEMMPU2_RGNACCEN0_RGNACCENRB)

/** \brief E8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN1_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0200E8u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN1_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN1_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA1 (EMEMMPU2_RGNACCEN1_RGNACCENRA)

/** \brief EC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN1_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0200ECu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN1_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN1_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB1 (EMEMMPU2_RGNACCEN1_RGNACCENRB)

/** \brief F8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN2_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0200F8u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN2_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN2_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA2 (EMEMMPU2_RGNACCEN2_RGNACCENRA)

/** \brief FC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN2_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0200FCu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN2_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN2_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB2 (EMEMMPU2_RGNACCEN2_RGNACCENRB)

/** \brief 108, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN3_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB020108u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN3_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN3_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA3 (EMEMMPU2_RGNACCEN3_RGNACCENRA)

/** \brief 10C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN3_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB02010Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN3_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN3_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB3 (EMEMMPU2_RGNACCEN3_RGNACCENRB)

/** \brief 118, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN4_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB020118u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN4_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN4_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA4 (EMEMMPU2_RGNACCEN4_RGNACCENRA)

/** \brief 11C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN4_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB02011Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN4_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN4_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB4 (EMEMMPU2_RGNACCEN4_RGNACCENRB)

/** \brief 128, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN5_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB020128u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN5_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN5_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA5 (EMEMMPU2_RGNACCEN5_RGNACCENRA)

/** \brief 12C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN5_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB02012Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN5_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN5_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB5 (EMEMMPU2_RGNACCEN5_RGNACCENRB)

/** \brief 138, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN6_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB020138u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN6_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN6_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA6 (EMEMMPU2_RGNACCEN6_RGNACCENRA)

/** \brief 13C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN6_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB02013Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN6_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN6_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB6 (EMEMMPU2_RGNACCEN6_RGNACCENRB)

/** \brief 148, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU2_RGNACCEN7_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB020148u)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN7_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN7_RGNACCENRA.
*/
#define EMEMMPU2_RGNACCENRA7 (EMEMMPU2_RGNACCEN7_RGNACCENRA)

/** \brief 14C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU2_RGNACCEN7_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB02014Cu)
/** Alias (User Manual Name) for EMEMMPU2_RGNACCEN7_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU2_RGNACCEN7_RGNACCENRB.
*/
#define EMEMMPU2_RGNACCENRB7 (EMEMMPU2_RGNACCEN7_RGNACCENRB)

/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Emem_mpu_Registers_Cfg_Ememmpu3
 * \{  */
/** \brief 0, EMEM Module Clock Control Register */
#define EMEMMPU3_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_CLC*)0xFB030000u)

/** \brief 8, EMEM Module ID Register */
#define EMEMMPU3_MODID /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MODID*)0xFB030008u)

/** \brief 10, EMEM Module Access Enable Register 0 */
#define EMEMMPU3_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN0*)0xFB030010u)

/** \brief 14, EMEM Module Access Enable Register 1 */
#define EMEMMPU3_ACCEN1 /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_ACCEN1*)0xFB030014u)

/** \brief 20, EMEM Module Memory Control Register */
#define EMEMMPU3_MEMCON /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_MEMCON*)0xFB030020u)

/** \brief 24, EMEM Module Safety Control Register */
#define EMEMMPU3_SCTRL /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_SCTRL*)0xFB030024u)

/** \brief 50, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN0_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB030050u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN0_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN0_RGNLA.
*/
#define EMEMMPU3_RGNLA0 (EMEMMPU3_RGNWRN0_RGNLA)

/** \brief 54, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN0_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB030054u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN0_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN0_RGNUA.
*/
#define EMEMMPU3_RGNUA0 (EMEMMPU3_RGNWRN0_RGNUA)

/** \brief 58, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN0_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB030058u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN0_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN0_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA0 (EMEMMPU3_RGNWRN0_RGNACCENWA)

/** \brief 5C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN0_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB03005Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN0_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN0_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB0 (EMEMMPU3_RGNWRN0_RGNACCENWB)

/** \brief 60, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN1_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB030060u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN1_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN1_RGNLA.
*/
#define EMEMMPU3_RGNLA1 (EMEMMPU3_RGNWRN1_RGNLA)

/** \brief 64, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN1_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB030064u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN1_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN1_RGNUA.
*/
#define EMEMMPU3_RGNUA1 (EMEMMPU3_RGNWRN1_RGNUA)

/** \brief 68, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN1_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB030068u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN1_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN1_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA1 (EMEMMPU3_RGNWRN1_RGNACCENWA)

/** \brief 6C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN1_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB03006Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN1_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN1_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB1 (EMEMMPU3_RGNWRN1_RGNACCENWB)

/** \brief 70, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN2_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB030070u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN2_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN2_RGNLA.
*/
#define EMEMMPU3_RGNLA2 (EMEMMPU3_RGNWRN2_RGNLA)

/** \brief 74, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN2_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB030074u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN2_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN2_RGNUA.
*/
#define EMEMMPU3_RGNUA2 (EMEMMPU3_RGNWRN2_RGNUA)

/** \brief 78, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN2_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB030078u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN2_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN2_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA2 (EMEMMPU3_RGNWRN2_RGNACCENWA)

/** \brief 7C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN2_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB03007Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN2_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN2_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB2 (EMEMMPU3_RGNWRN2_RGNACCENWB)

/** \brief 80, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN3_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB030080u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN3_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN3_RGNLA.
*/
#define EMEMMPU3_RGNLA3 (EMEMMPU3_RGNWRN3_RGNLA)

/** \brief 84, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN3_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB030084u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN3_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN3_RGNUA.
*/
#define EMEMMPU3_RGNUA3 (EMEMMPU3_RGNWRN3_RGNUA)

/** \brief 88, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN3_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB030088u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN3_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN3_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA3 (EMEMMPU3_RGNWRN3_RGNACCENWA)

/** \brief 8C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN3_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB03008Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN3_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN3_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB3 (EMEMMPU3_RGNWRN3_RGNACCENWB)

/** \brief 90, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN4_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB030090u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN4_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN4_RGNLA.
*/
#define EMEMMPU3_RGNLA4 (EMEMMPU3_RGNWRN4_RGNLA)

/** \brief 94, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN4_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB030094u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN4_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN4_RGNUA.
*/
#define EMEMMPU3_RGNUA4 (EMEMMPU3_RGNWRN4_RGNUA)

/** \brief 98, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN4_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB030098u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN4_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN4_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA4 (EMEMMPU3_RGNWRN4_RGNACCENWA)

/** \brief 9C, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN4_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB03009Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN4_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN4_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB4 (EMEMMPU3_RGNWRN4_RGNACCENWB)

/** \brief A0, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN5_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0300A0u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN5_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN5_RGNLA.
*/
#define EMEMMPU3_RGNLA5 (EMEMMPU3_RGNWRN5_RGNLA)

/** \brief A4, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN5_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0300A4u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN5_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN5_RGNUA.
*/
#define EMEMMPU3_RGNUA5 (EMEMMPU3_RGNWRN5_RGNUA)

/** \brief A8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN5_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0300A8u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN5_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN5_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA5 (EMEMMPU3_RGNWRN5_RGNACCENWA)

/** \brief AC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN5_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0300ACu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN5_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN5_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB5 (EMEMMPU3_RGNWRN5_RGNACCENWB)

/** \brief B0, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN6_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0300B0u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN6_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN6_RGNLA.
*/
#define EMEMMPU3_RGNLA6 (EMEMMPU3_RGNWRN6_RGNLA)

/** \brief B4, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN6_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0300B4u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN6_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN6_RGNUA.
*/
#define EMEMMPU3_RGNUA6 (EMEMMPU3_RGNWRN6_RGNUA)

/** \brief B8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN6_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0300B8u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN6_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN6_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA6 (EMEMMPU3_RGNWRN6_RGNACCENWA)

/** \brief BC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN6_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0300BCu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN6_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN6_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB6 (EMEMMPU3_RGNWRN6_RGNACCENWB)

/** \brief C0, EMEM Module Region i Lower Address Register */
#define EMEMMPU3_RGNWRN7_RGNLA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNLA*)0xFB0300C0u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN7_RGNLA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN7_RGNLA.
*/
#define EMEMMPU3_RGNLA7 (EMEMMPU3_RGNWRN7_RGNLA)

/** \brief C4, EMEM Module Region i Upper Address Register */
#define EMEMMPU3_RGNWRN7_RGNUA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNUA*)0xFB0300C4u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN7_RGNUA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN7_RGNUA.
*/
#define EMEMMPU3_RGNUA7 (EMEMMPU3_RGNWRN7_RGNUA)

/** \brief C8, EMEM Module Region i Write Access Enable Register 0 */
#define EMEMMPU3_RGNWRN7_RGNACCENWA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWA*)0xFB0300C8u)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN7_RGNACCENWA.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN7_RGNACCENWA.
*/
#define EMEMMPU3_RGNACCENWA7 (EMEMMPU3_RGNWRN7_RGNACCENWA)

/** \brief CC, EMEM Module Region i Write Access Enable Register 1 */
#define EMEMMPU3_RGNWRN7_RGNACCENWB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNWRN_RGNACCENWB*)0xFB0300CCu)
/** Alias (User Manual Name) for EMEMMPU3_RGNWRN7_RGNACCENWB.
* To use register names with standard convension, please use EMEMMPU3_RGNWRN7_RGNACCENWB.
*/
#define EMEMMPU3_RGNACCENWB7 (EMEMMPU3_RGNWRN7_RGNACCENWB)

/** \brief D8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN0_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0300D8u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN0_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN0_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA0 (EMEMMPU3_RGNACCEN0_RGNACCENRA)

/** \brief DC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN0_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0300DCu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN0_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN0_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB0 (EMEMMPU3_RGNACCEN0_RGNACCENRB)

/** \brief E8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN1_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0300E8u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN1_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN1_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA1 (EMEMMPU3_RGNACCEN1_RGNACCENRA)

/** \brief EC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN1_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0300ECu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN1_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN1_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB1 (EMEMMPU3_RGNACCEN1_RGNACCENRB)

/** \brief F8, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN2_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB0300F8u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN2_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN2_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA2 (EMEMMPU3_RGNACCEN2_RGNACCENRA)

/** \brief FC, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN2_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB0300FCu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN2_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN2_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB2 (EMEMMPU3_RGNACCEN2_RGNACCENRB)

/** \brief 108, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN3_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB030108u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN3_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN3_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA3 (EMEMMPU3_RGNACCEN3_RGNACCENRA)

/** \brief 10C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN3_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB03010Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN3_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN3_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB3 (EMEMMPU3_RGNACCEN3_RGNACCENRB)

/** \brief 118, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN4_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB030118u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN4_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN4_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA4 (EMEMMPU3_RGNACCEN4_RGNACCENRA)

/** \brief 11C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN4_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB03011Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN4_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN4_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB4 (EMEMMPU3_RGNACCEN4_RGNACCENRB)

/** \brief 128, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN5_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB030128u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN5_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN5_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA5 (EMEMMPU3_RGNACCEN5_RGNACCENRA)

/** \brief 12C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN5_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB03012Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN5_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN5_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB5 (EMEMMPU3_RGNACCEN5_RGNACCENRB)

/** \brief 138, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN6_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB030138u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN6_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN6_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA6 (EMEMMPU3_RGNACCEN6_RGNACCENRA)

/** \brief 13C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN6_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB03013Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN6_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN6_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB6 (EMEMMPU3_RGNACCEN6_RGNACCENRB)

/** \brief 148, EMEM Module Region i Read Access Enable Register 0 */
#define EMEMMPU3_RGNACCEN7_RGNACCENRA /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRA*)0xFB030148u)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN7_RGNACCENRA.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN7_RGNACCENRA.
*/
#define EMEMMPU3_RGNACCENRA7 (EMEMMPU3_RGNACCEN7_RGNACCENRA)

/** \brief 14C, EMEM Module Region i Read Access Enable Register 1 */
#define EMEMMPU3_RGNACCEN7_RGNACCENRB /*lint --e(923, 9078)*/ (*(volatile Ifx_EMEM_MPU_RGNACCEN_RGNACCENRB*)0xFB03014Cu)
/** Alias (User Manual Name) for EMEMMPU3_RGNACCEN7_RGNACCENRB.
* To use register names with standard convension, please use EMEMMPU3_RGNACCEN7_RGNACCENRB.
*/
#define EMEMMPU3_RGNACCENRB7 (EMEMMPU3_RGNACCEN7_RGNACCENRB)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXEMEM_MPU_REG_H */
