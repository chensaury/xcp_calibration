/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2017 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \ingroup     Os_Hal
 * \addtogroup  Os_Hal_Core
 * \brief   Primitives definition for TriCore Processor Core TC1.6.2P
 *
 * \{
 *
 * \file       Os_Hal_Core_162_PInt.h
 * \brief      This file contains hardware specific addresses for TriCore Processor Core TC1.6.2P
 *
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
 *********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os_Hal_Os.h.
 **********************************************************************************************************************/


#ifndef OS_HAL_CORE_162_PINT_H
# define OS_HAL_CORE_162_PINT_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*! Address of core id register. Read only register */
# define OS_HAL_CORE_ID_REGISTER          0xFE1C


/*! Address of the ICR register. */
# define OS_HAL_ICR_OFFSET                0xFE2C
/*! Bit mask (bit 15) for global interrupt flag */
# define OS_HAL_ICR_INT_MASK              0x00008000uL
/*! Bit mask (bits 7..0) for interrupt level */
# define OS_HAL_ICR_INT_LEVEL_MASK        0x000000FFuL
/*! Bit mask for globbaly disabled interrupt */
# define OS_HAL_ICR_INT_GLOBAL_DISABLED   0x00000000uL
/*! Bit mask for globbaly enabled interrupt */
# define OS_HAL_ICR_INT_GLOBAL_ENABLED    0x00008000uL


/*! Address of the SYSCON register. */
# define OS_HAL_SYSCON_OFFSET             0xFE14
/*! Bit mask (bit 2) for timing protection exception flag */
# define OS_HAL_SYSCON_TP_MASK            0x00000004uL
/*! Bit mask (bit 1) for memory protection exception flag */
# define OS_HAL_SYSCON_MP_MASK            0x00000002uL
/*! Bit mask (bit 3) for initial state for PSW.S bit in trap handler */
# define OS_HAL_SYSCON_IS_MASK            0x00000008uL
/*! Bit mask (bit 4) for initial state of PSW.S bit in interrupt handler */
# define OS_HAL_SYSCON_TS_MASK            0x00000010uL
/*! Bit mask (bit 24) for boot halt status */
# define OS_HAL_SYSCON_BHALT_MASK         0x01000000uL


/*! Address of the PCXI register. */
# define OS_HAL_PCXI_OFFSET               0xFE00
/*! Bit mask (bits 29..22) for previous CPU priority number */
# define OS_HAL_PCXI_PCPN_MASK            0x3FC00000uL
/*! Start bit position of PCPN for shift operation */
# define OS_HAL_PCXI_PCPN_BIT_POSITION    (22u)
/*! Start bit position of PIE for shift operation */
# define OS_HAL_PCXI_PIE_BIT_POSITION     (21u)
/*! Bit mask (bit 21) for previous interrupt state */
# define OS_HAL_PCXI_PIE_MASK             0x00200000uL
/*! Bit value (bit 21) for previous interrupt state as disabled */
# define OS_HAL_PCXI_PIE_DISABLED         0x00000000uL
/*! Bit value (bit 21) for previous interrupt state as enabled */
# define OS_HAL_PCXI_PIE_ENABLED          0x00200000uL
/*! Bit mask (bit 20) for previous context type (lower or upper) */
# define OS_HAL_PCXI_UL_MASK              0x00100000uL
/*! Bit mask (bits 19..0) for linked address */
# define OS_HAL_PCXI_PCX_MASK             0x000FFFFFuL
/*! Bit mask (bits 19..16) for linked address */
# define OS_HAL_PCXI_PCXS_MASK            0x000F0000uL
/*! Bit mask (bits 15..0) for linked address */
# define OS_HAL_PCXI_PCXO_MASK            0x0000FFFFuL
/*! The difference in bit position between ICR.IE and PCXI.PIE. ICR.IE should be shifted leftwards */
# define OS_HAL_PCXI_IE_TO_PIE            (6u)
/*! The difference in bit position between ICR.CCPN and PCXI.PCPN. ICR.CCPN should be shifted leftwards */
# define OS_HAL_PCXI_CCPN_TO_PCPN         (22u)


/*! Address of the FCX register. */
# define OS_HAL_FCX_OFFSET               0xFE38


/*! Address of the LCX register. */
# define OS_HAL_LCX_OFFSET               0xFE3C


/*! Address of the PSW register. */
# define OS_HAL_PSW_OFFSET               0xFE04
/*! Bit mask (bit 7) for CDE (Call Depth Enable) */
# define OS_HAL_PSW_CDE_MASK             0x00000080uL
/*! Bit value (bits 6..0) when CDC (Call Depth Counter) is 1 */
# define OS_HAL_PSW_CDC_1                0x00000001uL
/*! Bit mask (bit 8) for GW (Global Address Register Write Permission) */
# define OS_HAL_PSW_GW_MASK              0x00000100uL
/*! Bit mask (bit 14) for safety task identifier */
# define OS_HAL_PSW_S_MASK               0x00004000uL
/*! Bit mask (bit 9) for IS (Interrupt Stack Control) */
# define OS_HAL_PSW_IS_MASK              0x00000200uL
/*! Bit mask (bits 11,10) for IO (Access Privilege Level Control) */
# define OS_HAL_PSW_IO_MASK              0x00000C00uL
/*! Bit value (bits 11,10) for supervisor mode */
# define OS_HAL_PSW_IO_SUPERVISOR        0x00000800uL
/*! Bit value (bits 11,10) for user mode */
# define OS_HAL_PSW_IO_USER              0x00000400uL
/*! Bit mask (bit 15,13,12) for PRS (Protection Register Set) */
# define OS_HAL_PSW_PRS_MASK             0x0000B000uL
/*! Bit value (bits 15,13,12) for PRS0 (Protection Register Set 0) */
# define OS_HAL_PSW_PRS_PS0              0x00000000uL
/*! Bit value (bits 15,13,12) for PRS1 (Protection Register Set 1) */
# define OS_HAL_PSW_PRS_PS1              0x00001000uL
/*! Bit value (bits 15,13,12) for PRS2 (Protection Register Set 2) */
# define OS_HAL_PSW_PRS_PS2              0x00002000uL
/*! Bit value (bits 15,13,12) for PRS3 (Protection Register Set 3) */
# define OS_HAL_PSW_PRS_PS3              0x00003000uL
/*! Bit value (bits 15,13,12) for PRS0 (Protection Register Set 4) */
# define OS_HAL_PSW_PRS_PS4              0x00008000uL
/*! Bit value (bits 15,13,12) for PRS1 (Protection Register Set 5) */
# define OS_HAL_PSW_PRS_PS5              0x00009000uL
/*! Bit value (bits 15,13,12) for PRS2 (Protection Register Set 6) */
# define OS_HAL_PSW_PRS_PS6              0x0000A000uL
/*! Bit value (bits 15,13,12) for PRS3 (Protection Register Set 7) */
# define OS_HAL_PSW_PRS_PS7              0x0000B000uL

/*! Offset of PCXI in CSA upper context. */
# define OS_HAL_CSA_PCXI_OFFSET          (0u)
/*! Offset of PSW in CSA upper context. */
# define OS_HAL_CSA_PSW_OFFSET           (4u)
/*! Offset of stack pointer A10 (SP) in CSA upper context. */
# define OS_HAL_CSA_SP_OFFSET            (8u)
/*! Offset of return address A11 (RA) in CSA upper context. */
# define OS_HAL_CSA_RA_UPPER_OFFSET      (12u)
/*! Offset of return address D8 in CSA upper context. */
# define OS_HAL_CSA_D8_OFFSET            (16u)
/*! Offset of return address D9 in CSA upper context. */
# define OS_HAL_CSA_D9_OFFSET            (20u)
/*! Offset of return address D10 in CSA upper context. */
# define OS_HAL_CSA_D10_OFFSET           (24u)
/*! Offset of return address D11 in CSA upper context. */
# define OS_HAL_CSA_D11_OFFSET           (28u)
/*! Offset of return address A12 in CSA upper context. */
# define OS_HAL_CSA_A12_OFFSET           (32u)
/*! Offset of return address A13 in CSA upper context. */
# define OS_HAL_CSA_A13_OFFSET           (36u)
/*! Offset of return address A14 in CSA upper context. */
# define OS_HAL_CSA_A14_OFFSET           (40u)
/*! Offset of return address A15 in CSA upper context. */
# define OS_HAL_CSA_A15_OFFSET           (44u)
/*! Offset of return address D12 in CSA upper context. */
# define OS_HAL_CSA_D12_OFFSET           (48u)
/*! Offset of return address D13 in CSA upper context. */
# define OS_HAL_CSA_D13_OFFSET           (52u)
/*! Offset of return address D14 in CSA upper context. */
# define OS_HAL_CSA_D14_OFFSET           (56u)
/*! Offset of return address D15 (TIN) in CSA upper context. */
# define OS_HAL_CSA_D15_OFFSET           (60u)

/*! Offset of A11 (RA) in CSA lower context. */
# define OS_HAL_CSA_RA_LOWER_OFFSET      (4u)
/*! Offset of stack pointer A2 in CSA lower context. */
# define OS_HAL_CSA_A2_OFFSET            (8u)
/*! Offset of return address A3 in CSA lower context. */
# define OS_HAL_CSA_A3_OFFSET            (12u)
/*! Offset of return address D0 in CSA lower context. */
# define OS_HAL_CSA_D0_OFFSET            (16u)
/*! Offset of return address D1 in CSA lower context. */
# define OS_HAL_CSA_D1_OFFSET            (20u)
/*! Offset of return address D2 in CSA lower context. */
# define OS_HAL_CSA_D2_OFFSET            (24u)
/*! Offset of return address D3 in CSA lower context. */
# define OS_HAL_CSA_D3_OFFSET            (28u)
/*! Offset of return address A4 in CSA lower context. */
# define OS_HAL_CSA_A4_OFFSET            (32u)
/*! Offset of return address A5 in CSA lower context. */
# define OS_HAL_CSA_A5_OFFSET            (36u)
/*! Offset of return address A6 in CSA lower context. */
# define OS_HAL_CSA_A6_OFFSET            (40u)
/*! Offset of return address A7 in CSA lower context. */
# define OS_HAL_CSA_A7_OFFSET            (44u)
/*! Offset of return address D4 in CSA lower context. */
# define OS_HAL_CSA_D4_OFFSET            (48u)
/*! Offset of return address D5 in CSA lower context. */
# define OS_HAL_CSA_D5_OFFSET            (52u)
/*! Offset of return address D6 in CSA lower context. */
# define OS_HAL_CSA_D6_OFFSET            (56u)
/*! Offset of return address D7 in CSA lower context. */
# define OS_HAL_CSA_D7_OFFSET            (60u)

/*! Core special function register for multicore start */
# define OS_HAL_CORE_162_P_CORE0_CSFR_BASE        0xF8810000uL
# define OS_HAL_CORE_162_P_CORE0_SFR_BASE         0xF8800000uL
# define OS_HAL_CORE_162_P_CORE1_CSFR_BASE        0xF8830000uL
# define OS_HAL_CORE_162_P_CORE1_SFR_BASE         0xF8820000uL
# define OS_HAL_CORE_162_P_CORE2_CSFR_BASE        0xF8850000uL
# define OS_HAL_CORE_162_P_CORE2_SFR_BASE         0xF8840000uL
# define OS_HAL_CORE_162_P_CORE3_CSFR_BASE        0xF8870000uL
# define OS_HAL_CORE_162_P_CORE3_SFR_BASE         0xF8860000uL
# define OS_HAL_CORE_162_P_CORE4_CSFR_BASE        0xF8890000uL
# define OS_HAL_CORE_162_P_CORE4_SFR_BASE         0xF8880000uL
# define OS_HAL_CORE_162_P_CORE6_CSFR_BASE        0xF88D0000uL
# define OS_HAL_CORE_162_P_CORE6_SFR_BASE         0xF88C0000uL
# define OS_HAL_CORE0_PC                          (OS_HAL_CORE_162_P_CORE0_CSFR_BASE + 0xFE08uL)
# define OS_HAL_CORE0_DBGSR                       (OS_HAL_CORE_162_P_CORE0_CSFR_BASE + 0xFD00uL)
# define OS_HAL_CORE0_SYSCON                      (OS_HAL_CORE_162_P_CORE0_CSFR_BASE + 0xFE14uL)
# define OS_HAL_CORE1_PC                          (OS_HAL_CORE_162_P_CORE1_CSFR_BASE + 0xFE08uL)
# define OS_HAL_CORE1_DBGSR                       (OS_HAL_CORE_162_P_CORE1_CSFR_BASE + 0xFD00uL)
# define OS_HAL_CORE1_SYSCON                      (OS_HAL_CORE_162_P_CORE1_CSFR_BASE + 0xFE14uL)
# define OS_HAL_CORE2_PC                          (OS_HAL_CORE_162_P_CORE2_CSFR_BASE + 0xFE08uL)
# define OS_HAL_CORE2_DBGSR                       (OS_HAL_CORE_162_P_CORE2_CSFR_BASE + 0xFD00uL)
# define OS_HAL_CORE2_SYSCON                      (OS_HAL_CORE_162_P_CORE2_CSFR_BASE + 0xFE14uL)
# define OS_HAL_CORE3_PC                          (OS_HAL_CORE_162_P_CORE3_CSFR_BASE + 0xFE08uL)
# define OS_HAL_CORE3_DBGSR                       (OS_HAL_CORE_162_P_CORE3_CSFR_BASE + 0xFD00uL)
# define OS_HAL_CORE3_SYSCON                      (OS_HAL_CORE_162_P_CORE3_CSFR_BASE + 0xFE14uL)
# define OS_HAL_CORE4_PC                          (OS_HAL_CORE_162_P_CORE4_CSFR_BASE + 0xFE08uL)
# define OS_HAL_CORE4_DBGSR                       (OS_HAL_CORE_162_P_CORE4_CSFR_BASE + 0xFD00uL)
# define OS_HAL_CORE4_SYSCON                      (OS_HAL_CORE_162_P_CORE4_CSFR_BASE + 0xFE14uL)
# define OS_HAL_CORE6_PC                          (OS_HAL_CORE_162_P_CORE6_CSFR_BASE + 0xFE08uL)
# define OS_HAL_CORE6_DBGSR                       (OS_HAL_CORE_162_P_CORE6_CSFR_BASE + 0xFD00uL)
# define OS_HAL_CORE6_SYSCON                      (OS_HAL_CORE_162_P_CORE6_CSFR_BASE + 0xFE14uL)
# define OS_HAL_DBGSR_START_CORE                  (0x00000004uL)

/*! Define the number of protection sets */
# define OS_HAL_COREMPU_NUM_OF_PS        6

/*! Core MPU registers to specify regions for data protection */
# define OS_HAL_COREMPU_DPR_BASE         0xC000
/*! Register for lower boundary */
# define OS_HAL_COREMPU_DPR_LOW0         0xC000
# define OS_HAL_COREMPU_DPR_LOW1         0xC008
# define OS_HAL_COREMPU_DPR_LOW2         0xC010
# define OS_HAL_COREMPU_DPR_LOW3         0xC018
# define OS_HAL_COREMPU_DPR_LOW4         0xC020
# define OS_HAL_COREMPU_DPR_LOW5         0xC028
# define OS_HAL_COREMPU_DPR_LOW6         0xC030
# define OS_HAL_COREMPU_DPR_LOW7         0xC038
# define OS_HAL_COREMPU_DPR_LOW8         0xC040
# define OS_HAL_COREMPU_DPR_LOW9         0xC048
# define OS_HAL_COREMPU_DPR_LOW10        0xC050
# define OS_HAL_COREMPU_DPR_LOW11        0xC058
# define OS_HAL_COREMPU_DPR_LOW12        0xC060
# define OS_HAL_COREMPU_DPR_LOW13        0xC068
# define OS_HAL_COREMPU_DPR_LOW14        0xC070
# define OS_HAL_COREMPU_DPR_LOW15        0xC078
# define OS_HAL_COREMPU_DPR_LOW16        0xC080
# define OS_HAL_COREMPU_DPR_LOW17        0xC088
/*! Register for upper boundary */
# define OS_HAL_COREMPU_DPR_UPPER0       0xC004
# define OS_HAL_COREMPU_DPR_UPPER1       0xC00C
# define OS_HAL_COREMPU_DPR_UPPER2       0xC014
# define OS_HAL_COREMPU_DPR_UPPER3       0xC01C
# define OS_HAL_COREMPU_DPR_UPPER4       0xC024
# define OS_HAL_COREMPU_DPR_UPPER5       0xC02C
# define OS_HAL_COREMPU_DPR_UPPER6       0xC034
# define OS_HAL_COREMPU_DPR_UPPER7       0xC03C
# define OS_HAL_COREMPU_DPR_UPPER8       0xC044
# define OS_HAL_COREMPU_DPR_UPPER9       0xC04C
# define OS_HAL_COREMPU_DPR_UPPER10      0xC054
# define OS_HAL_COREMPU_DPR_UPPER11      0xC05C
# define OS_HAL_COREMPU_DPR_UPPER12      0xC064
# define OS_HAL_COREMPU_DPR_UPPER13      0xC06C
# define OS_HAL_COREMPU_DPR_UPPER14      0xC074
# define OS_HAL_COREMPU_DPR_UPPER15      0xC07C
# define OS_HAL_COREMPU_DPR_UPPER16      0xC084
# define OS_HAL_COREMPU_DPR_UPPER17      0xC08C


/*! Core MPU registers to specify regions for data protection */
# define OS_HAL_COREMPU_CPR_BASE         0xD000
/*! Register for lower boundary */
# define OS_HAL_COREMPU_CPR_LOW0         0xD000
# define OS_HAL_COREMPU_CPR_LOW1         0xD008
# define OS_HAL_COREMPU_CPR_LOW2         0xD010
# define OS_HAL_COREMPU_CPR_LOW3         0xD018
# define OS_HAL_COREMPU_CPR_LOW4         0xD020
# define OS_HAL_COREMPU_CPR_LOW5         0xD028
# define OS_HAL_COREMPU_CPR_LOW6         0xD030
# define OS_HAL_COREMPU_CPR_LOW7         0xD038
# define OS_HAL_COREMPU_CPR_LOW8         0xD040
# define OS_HAL_COREMPU_CPR_LOW9         0xD048
/*! Register for upper boundary */
# define OS_HAL_COREMPU_CPR_UPPER0       0xD004
# define OS_HAL_COREMPU_CPR_UPPER1       0xD00C
# define OS_HAL_COREMPU_CPR_UPPER2       0xD014
# define OS_HAL_COREMPU_CPR_UPPER3       0xD01C
# define OS_HAL_COREMPU_CPR_UPPER4       0xD024
# define OS_HAL_COREMPU_CPR_UPPER5       0xD02C
# define OS_HAL_COREMPU_CPR_UPPER6       0xD034
# define OS_HAL_COREMPU_CPR_UPPER7       0xD03C
# define OS_HAL_COREMPU_CPR_UPPER8       0xD044
# define OS_HAL_COREMPU_CPR_UPPER9       0xD04C


/*! Core MPU registers to specify access rights.
 *  Note that the offsets for protection set 4 and 5 are unusual.
 *  The offsets can be found in AURIXTC3XX_ts_part1_V2.5.1
 *  V2.5.1, 2018-04, Table 90
 */
/*! Read access rights */
# define OS_HAL_COREMPU_DPRE0            0xE010
# define OS_HAL_COREMPU_DPRE1            0xE014
# define OS_HAL_COREMPU_DPRE2            0xE018
# define OS_HAL_COREMPU_DPRE3            0xE01C
# define OS_HAL_COREMPU_DPRE4            0xE050
# define OS_HAL_COREMPU_DPRE5            0xE054
/*! Write access rights */
# define OS_HAL_COREMPU_DPWE0            0xE020
# define OS_HAL_COREMPU_DPWE1            0xE024
# define OS_HAL_COREMPU_DPWE2            0xE028
# define OS_HAL_COREMPU_DPWE3            0xE02C
# define OS_HAL_COREMPU_DPWE4            0xE060
# define OS_HAL_COREMPU_DPWE5            0xE064
/*! Execution access rights */
# define OS_HAL_COREMPU_CPXE0            0xE000
# define OS_HAL_COREMPU_CPXE1            0xE004
# define OS_HAL_COREMPU_CPXE2            0xE008
# define OS_HAL_COREMPU_CPXE3            0xE00C
# define OS_HAL_COREMPU_CPXE4            0xE040
# define OS_HAL_COREMPU_CPXE5            0xE044


/*! Predefined value to enable individual MPU region */
# define OS_HAL_COREMPU_ENABLE_REGION0   (0x00000001uL)
# define OS_HAL_COREMPU_ENABLE_REGION1   (0x00000002uL)
# define OS_HAL_COREMPU_ENABLE_REGION2   (0x00000004uL)
# define OS_HAL_COREMPU_ENABLE_REGION3   (0x00000008uL)
# define OS_HAL_COREMPU_ENABLE_REGION4   (0x00000010uL)
# define OS_HAL_COREMPU_ENABLE_REGION5   (0x00000020uL)
# define OS_HAL_COREMPU_ENABLE_REGION6   (0x00000040uL)
# define OS_HAL_COREMPU_ENABLE_REGION7   (0x00000080uL)
# define OS_HAL_COREMPU_ENABLE_REGION8   (0x00000100uL)
# define OS_HAL_COREMPU_ENABLE_REGION9   (0x00000200uL)
# define OS_HAL_COREMPU_ENABLE_REGION10  (0x00000400uL)
# define OS_HAL_COREMPU_ENABLE_REGION11  (0x00000800uL)
# define OS_HAL_COREMPU_ENABLE_REGION12  (0x00001000uL)
# define OS_HAL_COREMPU_ENABLE_REGION13  (0x00002000uL)
# define OS_HAL_COREMPU_ENABLE_REGION14  (0x00004000uL)
# define OS_HAL_COREMPU_ENABLE_REGION15  (0x00008000uL)
# define OS_HAL_COREMPU_ENABLE_REGION16  (0x00010000uL)
# define OS_HAL_COREMPU_ENABLE_REGION17  (0x00020000uL)


/*! Predefined value to disable individual MPU region */
# define OS_HAL_COREMPU_DISABLE_REGION0  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION1  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION2  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION3  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION4  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION5  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION6  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION7  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION8  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION9  (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION10 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION11 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION12 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION13 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION14 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION15 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION16 (0x00000000uL)
# define OS_HAL_COREMPU_DISABLE_REGION17 (0x00000000uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_Hal_GetCsaAddress()
 **********************************************************************************************************************/
/*! \brief          This function decodes the physical address of the CSA frame from the encoded pointer x.
 *
 *  \param[in]      x        Encoded pointer to the CSA frame, e.g.: raw value read from PCXI.
 *
 *  \return         The physical memory address of the CSA frame pointed by x.
 *
 *  \context        ANY
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
# define Os_Hal_GetCsaAddress(x)            (                                                                           /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */ \
                                              (((x) & OS_HAL_PCXI_PCXS_MASK) << 12) |   \
                                              (((x) & OS_HAL_PCXI_PCXO_MASK) << 6)      \
                                            )


/***********************************************************************************************************************
 *  Os_Hal_SetDataRegion()
 **********************************************************************************************************************/
/*! \brief          Set a data MPU region
 *  \param[in]      Slot           Region slot. It must be in range [0, 17].
 *  \param[in]      LowerValue     Lower boundary of the region
 *  \param[in]      UpperValue     Upper boundary of the region
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
# define Os_Hal_SetDataRegion(Slot, LowerValue, UpperValue)                                                 \
         switch(Slot)                                                                                       \
         {                                                                                                  \
           case 0:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW0, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER0, (UpperValue));                                          \
             break;                                                                                         \
           case 1:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW1, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER1, (UpperValue));                                          \
             break;                                                                                         \
           case 2:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW2, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER2, (UpperValue));                                          \
             break;                                                                                         \
           case 3:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW3, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER3, (UpperValue));                                          \
             break;                                                                                         \
           case 4:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW4, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER4, (UpperValue));                                          \
             break;                                                                                         \
           case 5:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW5, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER5, (UpperValue));                                          \
             break;                                                                                         \
           case 6:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW6, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER6, (UpperValue));                                          \
             break;                                                                                         \
           case 7:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW7, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER7, (UpperValue));                                          \
             break;                                                                                         \
           case 8:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW8, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER8, (UpperValue));                                          \
             break;                                                                                         \
           case 9:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW9, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER9, (UpperValue));                                          \
             break;                                                                                         \
           case 10:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW10, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER10, (UpperValue));                                         \
             break;                                                                                         \
           case 11:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW11, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER11, (UpperValue));                                         \
             break;                                                                                         \
           case 12:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW12, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER12, (UpperValue));                                         \
             break;                                                                                         \
           case 13:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW13, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER13, (UpperValue));                                         \
             break;                                                                                         \
           case 14:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW14, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER14, (UpperValue));                                         \
             break;                                                                                         \
           case 15:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW15, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER15, (UpperValue));                                         \
             break;                                                                                         \
           case 16:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW16, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER16, (UpperValue));                                         \
             break;                                                                                         \
           case 17:                                                                                         \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_LOW17, (LowerValue));                                           \
             Os_Hal_Mtcr(OS_HAL_COREMPU_DPR_UPPER17, (UpperValue));                                         \
             break;                                                                                         \
           default:                                                                                         \
             break;                                                                                         \
         }


/***********************************************************************************************************************
 *  Os_Hal_SetCodeRegion()
 **********************************************************************************************************************/
/*! \brief          Set a code MPU region
 *  \param[in]      Slot           Region slot. It must be in range [0, 9].
 *  \param[in]      LowerValue     Lower boundary of the region
 *  \param[in]      UpperValue     Upper boundary of the region
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
# define Os_Hal_SetCodeRegion(Slot, LowerValue, UpperValue)                                                 \
         switch(Slot)                                                                                       \
         {                                                                                                  \
           case 0:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW0, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER0, (UpperValue));                                          \
             break;                                                                                         \
           case 1:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW1, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER1, (UpperValue));                                          \
             break;                                                                                         \
           case 2:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW2, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER2, (UpperValue));                                          \
             break;                                                                                         \
           case 3:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW3, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER3, (UpperValue));                                          \
             break;                                                                                         \
           case 4:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW4, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER4, (UpperValue));                                          \
             break;                                                                                         \
           case 5:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW5, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER5, (UpperValue));                                          \
             break;                                                                                         \
           case 6:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW6, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER6, (UpperValue));                                          \
             break;                                                                                         \
           case 7:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW7, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER7, (UpperValue));                                          \
             break;                                                                                         \
           case 8:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW8, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER8, (UpperValue));                                          \
             break;                                                                                         \
           case 9:                                                                                          \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_LOW9, (LowerValue));                                            \
             Os_Hal_Mtcr(OS_HAL_COREMPU_CPR_UPPER9, (UpperValue));                                          \
             break;                                                                                         \
           default:                                                                                         \
             break;                                                                                         \
         }

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPRE()
 **********************************************************************************************************************/
/*! \brief        Initial read access rights for all protection sets.
 *  \details      This function initializes the DPRE register for all protection sets.
 *  \param[in]    Value[OS_HAL_COREMPU_NUM_OF_PS]        The access right values for all protection sets.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_InitializeAccessDPRE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
));


/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessDPWE()
 **********************************************************************************************************************/
/*! \brief        Initial write access rights for all protection sets.
 *  \details      This function initializes the DPWE register for all protection sets.
 *  \param[in]    Value[OS_HAL_COREMPU_NUM_OF_PS]        The access right values for all protection sets.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_InitializeAccessDPWE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
));


/***********************************************************************************************************************
 *  Os_Hal_InitializeAccessCPXE()
 **********************************************************************************************************************/
/*! \brief        Initial execution rights for all protection sets.
 *  \details      This function initializes the CPXE register for all protection sets.
 *  \param[in]    Value[OS_HAL_COREMPU_NUM_OF_PS]        The access right values for all protection sets.
 *  \context      ANY
 *  \reentrant    FALSE
 *  \synchronous  TRUE
 *  \pre          Supervisor mode.
 *  \pre          Interrupts disabled.
 *  \pre          Concurrent access to given data shall be prevented.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_InitializeAccessCPXE,
(
  CONST(uint32, AUTOMATIC) Value[OS_HAL_COREMPU_NUM_OF_PS]
));


/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPRE()
 **********************************************************************************************************************/
/*! \brief          Modify the read access rights for a particular protection set.
 *  \details        This function modifies the DPRE register for all protection sets.
 *  \param[in]      ProtectionSet  Target protection set. It must be in range [0, 5].
 *  \param[in]      Mask           Mask of the involved regions
 *  \param[in]      Value          Access rights of the involved regions.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ReadModifyAccessDPRE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
));


/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessDPWE()
 **********************************************************************************************************************/
/*! \brief          Modify the write access rights for a particular protection set.
 *  \details        This function modifies the DPWE register for all protection sets.
 *  \param[in]      ProtectionSet  Target protection set. It must be in range [0, 5].
 *  \param[in]      Mask           Mask of the involved regions
 *  \param[in]      Value          Access rights of the involved regions.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ReadModifyAccessDPWE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
));


/***********************************************************************************************************************
 *  Os_Hal_ReadModifyAccessCPXE()
 **********************************************************************************************************************/
/*! \brief          Modify execution access rights for a particular protection set.
 *  \details        This function modifies the CPXE register for all protection sets.
 *  \param[in]      ProtectionSet  Target protection set. It must be in range [0, 5].
 *  \param[in]      Mask           Mask of the involved regions
 *  \param[in]      Value          Access rights of the involved regions.
 *  \context        OS_INTERNAL
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_Hal_ReadModifyAccessCPXE,
(
  CONST(uint8, AUTOMATIC) ProtectionSet,
  CONST(uint32, AUTOMATIC) Mask,
  CONST(uint32, AUTOMATIC) Value
));

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

#endif /* OS_HAL_CORE_162_PINT_H */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_Hal_Core_162_PInt.h
 *********************************************************************************************************************/
