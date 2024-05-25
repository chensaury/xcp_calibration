/**
 * \file IfxEdsadc_reg.h
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
 * \defgroup IfxSfr_Edsadc_Registers_Cfg Edsadc address
 * \ingroup IfxSfr_Edsadc_Registers
 * 
 * \defgroup IfxSfr_Edsadc_Registers_Cfg_BaseAddress Base address
 * \ingroup IfxSfr_Edsadc_Registers_Cfg
 *
 * \defgroup IfxSfr_Edsadc_Registers_Cfg_Edsadc 2-EDSADC
 * \ingroup IfxSfr_Edsadc_Registers_Cfg
 *
 *
 */
#ifndef IFXEDSADC_REG_H
#define IFXEDSADC_REG_H 1
/******************************************************************************/
#include "IfxEdsadc_regdef.h"
/******************************************************************************/

/******************************************************************************/

/******************************************************************************/

/** \addtogroup IfxSfr_Edsadc_Registers_Cfg_BaseAddress
 * \{  */

/** \brief EDSADC object */
#define MODULE_EDSADC /*lint --e(923, 9078)*/ ((*(Ifx_EDSADC*)0xF0024000u))
/** \}  */


/******************************************************************************/
/******************************************************************************/
/** \addtogroup IfxSfr_Edsadc_Registers_Cfg_Edsadc
 * \{  */
/** \brief 0, Clock Control Register */
#define EDSADC_CLC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CLC*)0xF0024000u)

/** \brief 8, Module Identification Register */
#define EDSADC_ID /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_ID*)0xF0024008u)

/** \brief 28, OCDS Control and Status Register */
#define EDSADC_OCS /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_OCS*)0xF0024028u)

/** \brief 2C, Kernel Reset Status Clear Register */
#define EDSADC_KRSTCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_KRSTCLR*)0xF002402Cu)

/** \brief 30, Kernel Reset Register 1 */
#define EDSADC_KRST1 /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_KRST1*)0xF0024030u)

/** \brief 34, Kernel Reset Register 0 */
#define EDSADC_KRST0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_KRST0*)0xF0024034u)

/** \brief 3C, Access Enable Register 0 */
#define EDSADC_ACCEN0 /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_ACCEN0*)0xF002403Cu)

/** \brief 80, Global Configuration Register */
#define EDSADC_GLOBCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_GLOBCFG*)0xF0024080u)

/** \brief 88, Global Run Control Register */
#define EDSADC_GLOBRC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_GLOBRC*)0xF0024088u)

/** \brief 90, Access Protection Register */
#define EDSADC_ACCPROT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_ACCPROT*)0xF0024090u)

/** \brief A0, Carrier Generator Configuration Register */
#define EDSADC_CGCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CGCFG*)0xF00240A0u)

/** \brief E0, Event Flag Register */
#define EDSADC_EVFLAG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_EVFLAG*)0xF00240E0u)

/** \brief E4, Event Flag Clear Register */
#define EDSADC_EVFLAGCLR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_EVFLAGCLR*)0xF00240E4u)

/** \brief 100, Modulator Configuration Register 0 */
#define EDSADC_CH0_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024100u)
/** Alias (User Manual Name) for EDSADC_CH0_MODCFG.
* To use register names with standard convension, please use EDSADC_CH0_MODCFG.
*/
#define EDSADC_MODCFG0 (EDSADC_CH0_MODCFG)

/** \brief 108, Demodulator Input Config. Register 0 */
#define EDSADC_CH0_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024108u)
/** Alias (User Manual Name) for EDSADC_CH0_DICFG.
* To use register names with standard convension, please use EDSADC_CH0_DICFG.
*/
#define EDSADC_DICFG0 (EDSADC_CH0_DICFG)

/** \brief 110, Filter Configuration Register 0, Main */
#define EDSADC_CH0_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024110u)
/** Alias (User Manual Name) for EDSADC_CH0_FCFGM.
* To use register names with standard convension, please use EDSADC_CH0_FCFGM.
*/
#define EDSADC_FCFGM0 (EDSADC_CH0_FCFGM)

/** \brief 114, Filter Configuration Register 0, CIC Filter */
#define EDSADC_CH0_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024114u)
/** Alias (User Manual Name) for EDSADC_CH0_FCFGC.
* To use register names with standard convension, please use EDSADC_CH0_FCFGC.
*/
#define EDSADC_FCFGC0 (EDSADC_CH0_FCFGC)

/** \brief 118, Filter Counter Register 0, CIC Filter */
#define EDSADC_CH0_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024118u)
/** Alias (User Manual Name) for EDSADC_CH0_FCNTC.
* To use register names with standard convension, please use EDSADC_CH0_FCNTC.
*/
#define EDSADC_FCNTC0 (EDSADC_CH0_FCNTC)

/** \brief 11C, Overshoot Compensation Cfg. Register 0 */
#define EDSADC_CH0_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002411Cu)
/** Alias (User Manual Name) for EDSADC_CH0_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH0_OVSCFG.
*/
#define EDSADC_OVSCFG0 (EDSADC_CH0_OVSCFG)

/** \brief 120, Integration Window Control Register 0 */
#define EDSADC_CH0_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024120u)
/** Alias (User Manual Name) for EDSADC_CH0_IWCTR.
* To use register names with standard convension, please use EDSADC_CH0_IWCTR.
*/
#define EDSADC_IWCTR0 (EDSADC_CH0_IWCTR)

/** \brief 124, Intermediate Integration Value */
#define EDSADC_CH0_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024124u)
/** Alias (User Manual Name) for EDSADC_CH0_IIVAL.
* To use register names with standard convension, please use EDSADC_CH0_IIVAL.
*/
#define EDSADC_IIVAL0 (EDSADC_CH0_IIVAL)

/** \brief 128, Integrator Status Register 0 */
#define EDSADC_CH0_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024128u)
/** Alias (User Manual Name) for EDSADC_CH0_ISTAT.
* To use register names with standard convension, please use EDSADC_CH0_ISTAT.
*/
#define EDSADC_ISTAT0 (EDSADC_CH0_ISTAT)

/** \brief 12C, Result FIFO Control Register 0 */
#define EDSADC_CH0_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002412Cu)
/** Alias (User Manual Name) for EDSADC_CH0_RFC.
* To use register names with standard convension, please use EDSADC_CH0_RFC.
*/
#define EDSADC_RFC0 (EDSADC_CH0_RFC)

/** \brief 130, Result Register 0 Main */
#define EDSADC_CH0_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024130u)
/** Alias (User Manual Name) for EDSADC_CH0_RESM.
* To use register names with standard convension, please use EDSADC_CH0_RESM.
*/
#define EDSADC_RESM0 (EDSADC_CH0_RESM)

/** \brief 138, Offset Compensation Register 0 */
#define EDSADC_CH0_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024138u)
/** Alias (User Manual Name) for EDSADC_CH0_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH0_OFFCOMP.
*/
#define EDSADC_OFFCOMP0 (EDSADC_CH0_OFFCOMP)

/** \brief 13C, Gain Calibration Register 0 */
#define EDSADC_CH0_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002413Cu)
/** Alias (User Manual Name) for EDSADC_CH0_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH0_GAINCAL.
*/
#define EDSADC_GAINCAL0 (EDSADC_CH0_GAINCAL)

/** \brief 140, Gain Control Register 0 */
#define EDSADC_CH0_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024140u)
/** Alias (User Manual Name) for EDSADC_CH0_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH0_GAINCTR.
*/
#define EDSADC_GAINCTR0 (EDSADC_CH0_GAINCTR)

/** \brief 144, Gain Correction Register 0 */
#define EDSADC_CH0_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024144u)
/** Alias (User Manual Name) for EDSADC_CH0_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH0_GAINCORR.
*/
#define EDSADC_GAINCORR0 (EDSADC_CH0_GAINCORR)

/** \brief 150, Time-Stamp Register 0 */
#define EDSADC_CH0_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024150u)
/** Alias (User Manual Name) for EDSADC_CH0_TSTMP.
* To use register names with standard convension, please use EDSADC_CH0_TSTMP.
*/
#define EDSADC_TSTMP0 (EDSADC_CH0_TSTMP)

/** \brief 154, Time-Stamp Counter 0 */
#define EDSADC_CH0_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024154u)
/** Alias (User Manual Name) for EDSADC_CH0_TSCNT.
* To use register names with standard convension, please use EDSADC_CH0_TSCNT.
*/
#define EDSADC_TSCNT0 (EDSADC_CH0_TSCNT)

/** \brief 170, Auxiliary Filter Configuration Register 0 */
#define EDSADC_CH0_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024170u)
/** Alias (User Manual Name) for EDSADC_CH0_FCFGA.
* To use register names with standard convension, please use EDSADC_CH0_FCFGA.
*/
#define EDSADC_FCFGA0 (EDSADC_CH0_FCFGA)

/** \brief 178, Boundary Select Register 0 */
#define EDSADC_CH0_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024178u)
/** Alias (User Manual Name) for EDSADC_CH0_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH0_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL0 (EDSADC_CH0_BOUNDSEL)

/** \brief 180, Result Register 0 Auxiliary */
#define EDSADC_CH0_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024180u)
/** Alias (User Manual Name) for EDSADC_CH0_RESA.
* To use register names with standard convension, please use EDSADC_CH0_RESA.
*/
#define EDSADC_RESA0 (EDSADC_CH0_RESA)

/** \brief 1A0, Carrier Generator Synchronization Reg. 0 */
#define EDSADC_CH0_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00241A0u)
/** Alias (User Manual Name) for EDSADC_CH0_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH0_CGSYNC.
*/
#define EDSADC_CGSYNC0 (EDSADC_CH0_CGSYNC)

/** \brief 1A8, Rectification Configuration Register 0 */
#define EDSADC_CH0_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00241A8u)
/** Alias (User Manual Name) for EDSADC_CH0_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH0_RECTCFG.
*/
#define EDSADC_RECTCFG0 (EDSADC_CH0_RECTCFG)

/** \brief 1B0, Common Mode Voltage Register 0 */
#define EDSADC_CH0_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00241B0u)
/** Alias (User Manual Name) for EDSADC_CH0_VCM.
* To use register names with standard convension, please use EDSADC_CH0_VCM.
*/
#define EDSADC_VCM0 (EDSADC_CH0_VCM)

/** \brief 200, Modulator Configuration Register 1 */
#define EDSADC_CH1_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024200u)
/** Alias (User Manual Name) for EDSADC_CH1_MODCFG.
* To use register names with standard convension, please use EDSADC_CH1_MODCFG.
*/
#define EDSADC_MODCFG1 (EDSADC_CH1_MODCFG)

/** \brief 208, Demodulator Input Config. Register 1 */
#define EDSADC_CH1_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024208u)
/** Alias (User Manual Name) for EDSADC_CH1_DICFG.
* To use register names with standard convension, please use EDSADC_CH1_DICFG.
*/
#define EDSADC_DICFG1 (EDSADC_CH1_DICFG)

/** \brief 210, Filter Configuration Register 1, Main */
#define EDSADC_CH1_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024210u)
/** Alias (User Manual Name) for EDSADC_CH1_FCFGM.
* To use register names with standard convension, please use EDSADC_CH1_FCFGM.
*/
#define EDSADC_FCFGM1 (EDSADC_CH1_FCFGM)

/** \brief 214, Filter Configuration Register 1, CIC Filter */
#define EDSADC_CH1_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024214u)
/** Alias (User Manual Name) for EDSADC_CH1_FCFGC.
* To use register names with standard convension, please use EDSADC_CH1_FCFGC.
*/
#define EDSADC_FCFGC1 (EDSADC_CH1_FCFGC)

/** \brief 218, Filter Counter Register 1, CIC Filter */
#define EDSADC_CH1_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024218u)
/** Alias (User Manual Name) for EDSADC_CH1_FCNTC.
* To use register names with standard convension, please use EDSADC_CH1_FCNTC.
*/
#define EDSADC_FCNTC1 (EDSADC_CH1_FCNTC)

/** \brief 21C, Overshoot Compensation Cfg. Register 1 */
#define EDSADC_CH1_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002421Cu)
/** Alias (User Manual Name) for EDSADC_CH1_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH1_OVSCFG.
*/
#define EDSADC_OVSCFG1 (EDSADC_CH1_OVSCFG)

/** \brief 220, Integration Window Control Register 1 */
#define EDSADC_CH1_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024220u)
/** Alias (User Manual Name) for EDSADC_CH1_IWCTR.
* To use register names with standard convension, please use EDSADC_CH1_IWCTR.
*/
#define EDSADC_IWCTR1 (EDSADC_CH1_IWCTR)

/** \brief 224, Intermediate Integration Value */
#define EDSADC_CH1_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024224u)
/** Alias (User Manual Name) for EDSADC_CH1_IIVAL.
* To use register names with standard convension, please use EDSADC_CH1_IIVAL.
*/
#define EDSADC_IIVAL1 (EDSADC_CH1_IIVAL)

/** \brief 228, Integrator Status Register 1 */
#define EDSADC_CH1_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024228u)
/** Alias (User Manual Name) for EDSADC_CH1_ISTAT.
* To use register names with standard convension, please use EDSADC_CH1_ISTAT.
*/
#define EDSADC_ISTAT1 (EDSADC_CH1_ISTAT)

/** \brief 22C, Result FIFO Control Register 1 */
#define EDSADC_CH1_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002422Cu)
/** Alias (User Manual Name) for EDSADC_CH1_RFC.
* To use register names with standard convension, please use EDSADC_CH1_RFC.
*/
#define EDSADC_RFC1 (EDSADC_CH1_RFC)

/** \brief 230, Result Register 1 Main */
#define EDSADC_CH1_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024230u)
/** Alias (User Manual Name) for EDSADC_CH1_RESM.
* To use register names with standard convension, please use EDSADC_CH1_RESM.
*/
#define EDSADC_RESM1 (EDSADC_CH1_RESM)

/** \brief 238, Offset Compensation Register 1 */
#define EDSADC_CH1_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024238u)
/** Alias (User Manual Name) for EDSADC_CH1_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH1_OFFCOMP.
*/
#define EDSADC_OFFCOMP1 (EDSADC_CH1_OFFCOMP)

/** \brief 23C, Gain Calibration Register 1 */
#define EDSADC_CH1_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002423Cu)
/** Alias (User Manual Name) for EDSADC_CH1_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH1_GAINCAL.
*/
#define EDSADC_GAINCAL1 (EDSADC_CH1_GAINCAL)

/** \brief 240, Gain Control Register 1 */
#define EDSADC_CH1_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024240u)
/** Alias (User Manual Name) for EDSADC_CH1_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH1_GAINCTR.
*/
#define EDSADC_GAINCTR1 (EDSADC_CH1_GAINCTR)

/** \brief 244, Gain Correction Register 1 */
#define EDSADC_CH1_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024244u)
/** Alias (User Manual Name) for EDSADC_CH1_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH1_GAINCORR.
*/
#define EDSADC_GAINCORR1 (EDSADC_CH1_GAINCORR)

/** \brief 250, Time-Stamp Register 1 */
#define EDSADC_CH1_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024250u)
/** Alias (User Manual Name) for EDSADC_CH1_TSTMP.
* To use register names with standard convension, please use EDSADC_CH1_TSTMP.
*/
#define EDSADC_TSTMP1 (EDSADC_CH1_TSTMP)

/** \brief 254, Time-Stamp Counter 1 */
#define EDSADC_CH1_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024254u)
/** Alias (User Manual Name) for EDSADC_CH1_TSCNT.
* To use register names with standard convension, please use EDSADC_CH1_TSCNT.
*/
#define EDSADC_TSCNT1 (EDSADC_CH1_TSCNT)

/** \brief 270, Auxiliary Filter Configuration Register 1 */
#define EDSADC_CH1_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024270u)
/** Alias (User Manual Name) for EDSADC_CH1_FCFGA.
* To use register names with standard convension, please use EDSADC_CH1_FCFGA.
*/
#define EDSADC_FCFGA1 (EDSADC_CH1_FCFGA)

/** \brief 278, Boundary Select Register 1 */
#define EDSADC_CH1_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024278u)
/** Alias (User Manual Name) for EDSADC_CH1_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH1_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL1 (EDSADC_CH1_BOUNDSEL)

/** \brief 280, Result Register 1 Auxiliary */
#define EDSADC_CH1_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024280u)
/** Alias (User Manual Name) for EDSADC_CH1_RESA.
* To use register names with standard convension, please use EDSADC_CH1_RESA.
*/
#define EDSADC_RESA1 (EDSADC_CH1_RESA)

/** \brief 2A0, Carrier Generator Synchronization Reg. 1 */
#define EDSADC_CH1_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00242A0u)
/** Alias (User Manual Name) for EDSADC_CH1_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH1_CGSYNC.
*/
#define EDSADC_CGSYNC1 (EDSADC_CH1_CGSYNC)

/** \brief 2A8, Rectification Configuration Register 1 */
#define EDSADC_CH1_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00242A8u)
/** Alias (User Manual Name) for EDSADC_CH1_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH1_RECTCFG.
*/
#define EDSADC_RECTCFG1 (EDSADC_CH1_RECTCFG)

/** \brief 2B0, Common Mode Voltage Register 1 */
#define EDSADC_CH1_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00242B0u)
/** Alias (User Manual Name) for EDSADC_CH1_VCM.
* To use register names with standard convension, please use EDSADC_CH1_VCM.
*/
#define EDSADC_VCM1 (EDSADC_CH1_VCM)

/** \brief 300, Modulator Configuration Register 2 */
#define EDSADC_CH2_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024300u)
/** Alias (User Manual Name) for EDSADC_CH2_MODCFG.
* To use register names with standard convension, please use EDSADC_CH2_MODCFG.
*/
#define EDSADC_MODCFG2 (EDSADC_CH2_MODCFG)

/** \brief 308, Demodulator Input Config. Register 2 */
#define EDSADC_CH2_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024308u)
/** Alias (User Manual Name) for EDSADC_CH2_DICFG.
* To use register names with standard convension, please use EDSADC_CH2_DICFG.
*/
#define EDSADC_DICFG2 (EDSADC_CH2_DICFG)

/** \brief 310, Filter Configuration Register 2, Main */
#define EDSADC_CH2_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024310u)
/** Alias (User Manual Name) for EDSADC_CH2_FCFGM.
* To use register names with standard convension, please use EDSADC_CH2_FCFGM.
*/
#define EDSADC_FCFGM2 (EDSADC_CH2_FCFGM)

/** \brief 314, Filter Configuration Register 2, CIC Filter */
#define EDSADC_CH2_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024314u)
/** Alias (User Manual Name) for EDSADC_CH2_FCFGC.
* To use register names with standard convension, please use EDSADC_CH2_FCFGC.
*/
#define EDSADC_FCFGC2 (EDSADC_CH2_FCFGC)

/** \brief 318, Filter Counter Register 2, CIC Filter */
#define EDSADC_CH2_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024318u)
/** Alias (User Manual Name) for EDSADC_CH2_FCNTC.
* To use register names with standard convension, please use EDSADC_CH2_FCNTC.
*/
#define EDSADC_FCNTC2 (EDSADC_CH2_FCNTC)

/** \brief 31C, Overshoot Compensation Cfg. Register 2 */
#define EDSADC_CH2_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002431Cu)
/** Alias (User Manual Name) for EDSADC_CH2_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH2_OVSCFG.
*/
#define EDSADC_OVSCFG2 (EDSADC_CH2_OVSCFG)

/** \brief 320, Integration Window Control Register 2 */
#define EDSADC_CH2_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024320u)
/** Alias (User Manual Name) for EDSADC_CH2_IWCTR.
* To use register names with standard convension, please use EDSADC_CH2_IWCTR.
*/
#define EDSADC_IWCTR2 (EDSADC_CH2_IWCTR)

/** \brief 324, Intermediate Integration Value */
#define EDSADC_CH2_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024324u)
/** Alias (User Manual Name) for EDSADC_CH2_IIVAL.
* To use register names with standard convension, please use EDSADC_CH2_IIVAL.
*/
#define EDSADC_IIVAL2 (EDSADC_CH2_IIVAL)

/** \brief 328, Integrator Status Register 2 */
#define EDSADC_CH2_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024328u)
/** Alias (User Manual Name) for EDSADC_CH2_ISTAT.
* To use register names with standard convension, please use EDSADC_CH2_ISTAT.
*/
#define EDSADC_ISTAT2 (EDSADC_CH2_ISTAT)

/** \brief 32C, Result FIFO Control Register 2 */
#define EDSADC_CH2_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002432Cu)
/** Alias (User Manual Name) for EDSADC_CH2_RFC.
* To use register names with standard convension, please use EDSADC_CH2_RFC.
*/
#define EDSADC_RFC2 (EDSADC_CH2_RFC)

/** \brief 330, Result Register 2 Main */
#define EDSADC_CH2_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024330u)
/** Alias (User Manual Name) for EDSADC_CH2_RESM.
* To use register names with standard convension, please use EDSADC_CH2_RESM.
*/
#define EDSADC_RESM2 (EDSADC_CH2_RESM)

/** \brief 338, Offset Compensation Register 2 */
#define EDSADC_CH2_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024338u)
/** Alias (User Manual Name) for EDSADC_CH2_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH2_OFFCOMP.
*/
#define EDSADC_OFFCOMP2 (EDSADC_CH2_OFFCOMP)

/** \brief 33C, Gain Calibration Register 2 */
#define EDSADC_CH2_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002433Cu)
/** Alias (User Manual Name) for EDSADC_CH2_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH2_GAINCAL.
*/
#define EDSADC_GAINCAL2 (EDSADC_CH2_GAINCAL)

/** \brief 340, Gain Control Register 2 */
#define EDSADC_CH2_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024340u)
/** Alias (User Manual Name) for EDSADC_CH2_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH2_GAINCTR.
*/
#define EDSADC_GAINCTR2 (EDSADC_CH2_GAINCTR)

/** \brief 344, Gain Correction Register 2 */
#define EDSADC_CH2_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024344u)
/** Alias (User Manual Name) for EDSADC_CH2_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH2_GAINCORR.
*/
#define EDSADC_GAINCORR2 (EDSADC_CH2_GAINCORR)

/** \brief 350, Time-Stamp Register 2 */
#define EDSADC_CH2_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024350u)
/** Alias (User Manual Name) for EDSADC_CH2_TSTMP.
* To use register names with standard convension, please use EDSADC_CH2_TSTMP.
*/
#define EDSADC_TSTMP2 (EDSADC_CH2_TSTMP)

/** \brief 354, Time-Stamp Counter 2 */
#define EDSADC_CH2_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024354u)
/** Alias (User Manual Name) for EDSADC_CH2_TSCNT.
* To use register names with standard convension, please use EDSADC_CH2_TSCNT.
*/
#define EDSADC_TSCNT2 (EDSADC_CH2_TSCNT)

/** \brief 370, Auxiliary Filter Configuration Register 2 */
#define EDSADC_CH2_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024370u)
/** Alias (User Manual Name) for EDSADC_CH2_FCFGA.
* To use register names with standard convension, please use EDSADC_CH2_FCFGA.
*/
#define EDSADC_FCFGA2 (EDSADC_CH2_FCFGA)

/** \brief 378, Boundary Select Register 2 */
#define EDSADC_CH2_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024378u)
/** Alias (User Manual Name) for EDSADC_CH2_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH2_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL2 (EDSADC_CH2_BOUNDSEL)

/** \brief 380, Result Register 2 Auxiliary */
#define EDSADC_CH2_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024380u)
/** Alias (User Manual Name) for EDSADC_CH2_RESA.
* To use register names with standard convension, please use EDSADC_CH2_RESA.
*/
#define EDSADC_RESA2 (EDSADC_CH2_RESA)

/** \brief 3A0, Carrier Generator Synchronization Reg. 2 */
#define EDSADC_CH2_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00243A0u)
/** Alias (User Manual Name) for EDSADC_CH2_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH2_CGSYNC.
*/
#define EDSADC_CGSYNC2 (EDSADC_CH2_CGSYNC)

/** \brief 3A8, Rectification Configuration Register 2 */
#define EDSADC_CH2_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00243A8u)
/** Alias (User Manual Name) for EDSADC_CH2_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH2_RECTCFG.
*/
#define EDSADC_RECTCFG2 (EDSADC_CH2_RECTCFG)

/** \brief 3B0, Common Mode Voltage Register 2 */
#define EDSADC_CH2_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00243B0u)
/** Alias (User Manual Name) for EDSADC_CH2_VCM.
* To use register names with standard convension, please use EDSADC_CH2_VCM.
*/
#define EDSADC_VCM2 (EDSADC_CH2_VCM)

/** \brief 400, Modulator Configuration Register 3 */
#define EDSADC_CH3_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024400u)
/** Alias (User Manual Name) for EDSADC_CH3_MODCFG.
* To use register names with standard convension, please use EDSADC_CH3_MODCFG.
*/
#define EDSADC_MODCFG3 (EDSADC_CH3_MODCFG)

/** \brief 408, Demodulator Input Config. Register 3 */
#define EDSADC_CH3_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024408u)
/** Alias (User Manual Name) for EDSADC_CH3_DICFG.
* To use register names with standard convension, please use EDSADC_CH3_DICFG.
*/
#define EDSADC_DICFG3 (EDSADC_CH3_DICFG)

/** \brief 410, Filter Configuration Register 3, Main */
#define EDSADC_CH3_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024410u)
/** Alias (User Manual Name) for EDSADC_CH3_FCFGM.
* To use register names with standard convension, please use EDSADC_CH3_FCFGM.
*/
#define EDSADC_FCFGM3 (EDSADC_CH3_FCFGM)

/** \brief 414, Filter Configuration Register 3, CIC Filter */
#define EDSADC_CH3_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024414u)
/** Alias (User Manual Name) for EDSADC_CH3_FCFGC.
* To use register names with standard convension, please use EDSADC_CH3_FCFGC.
*/
#define EDSADC_FCFGC3 (EDSADC_CH3_FCFGC)

/** \brief 418, Filter Counter Register 3, CIC Filter */
#define EDSADC_CH3_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024418u)
/** Alias (User Manual Name) for EDSADC_CH3_FCNTC.
* To use register names with standard convension, please use EDSADC_CH3_FCNTC.
*/
#define EDSADC_FCNTC3 (EDSADC_CH3_FCNTC)

/** \brief 41C, Overshoot Compensation Cfg. Register 3 */
#define EDSADC_CH3_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002441Cu)
/** Alias (User Manual Name) for EDSADC_CH3_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH3_OVSCFG.
*/
#define EDSADC_OVSCFG3 (EDSADC_CH3_OVSCFG)

/** \brief 420, Integration Window Control Register 3 */
#define EDSADC_CH3_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024420u)
/** Alias (User Manual Name) for EDSADC_CH3_IWCTR.
* To use register names with standard convension, please use EDSADC_CH3_IWCTR.
*/
#define EDSADC_IWCTR3 (EDSADC_CH3_IWCTR)

/** \brief 424, Intermediate Integration Value */
#define EDSADC_CH3_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024424u)
/** Alias (User Manual Name) for EDSADC_CH3_IIVAL.
* To use register names with standard convension, please use EDSADC_CH3_IIVAL.
*/
#define EDSADC_IIVAL3 (EDSADC_CH3_IIVAL)

/** \brief 428, Integrator Status Register 3 */
#define EDSADC_CH3_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024428u)
/** Alias (User Manual Name) for EDSADC_CH3_ISTAT.
* To use register names with standard convension, please use EDSADC_CH3_ISTAT.
*/
#define EDSADC_ISTAT3 (EDSADC_CH3_ISTAT)

/** \brief 42C, Result FIFO Control Register 3 */
#define EDSADC_CH3_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002442Cu)
/** Alias (User Manual Name) for EDSADC_CH3_RFC.
* To use register names with standard convension, please use EDSADC_CH3_RFC.
*/
#define EDSADC_RFC3 (EDSADC_CH3_RFC)

/** \brief 430, Result Register 3 Main */
#define EDSADC_CH3_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024430u)
/** Alias (User Manual Name) for EDSADC_CH3_RESM.
* To use register names with standard convension, please use EDSADC_CH3_RESM.
*/
#define EDSADC_RESM3 (EDSADC_CH3_RESM)

/** \brief 438, Offset Compensation Register 3 */
#define EDSADC_CH3_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024438u)
/** Alias (User Manual Name) for EDSADC_CH3_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH3_OFFCOMP.
*/
#define EDSADC_OFFCOMP3 (EDSADC_CH3_OFFCOMP)

/** \brief 43C, Gain Calibration Register 3 */
#define EDSADC_CH3_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002443Cu)
/** Alias (User Manual Name) for EDSADC_CH3_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH3_GAINCAL.
*/
#define EDSADC_GAINCAL3 (EDSADC_CH3_GAINCAL)

/** \brief 440, Gain Control Register 3 */
#define EDSADC_CH3_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024440u)
/** Alias (User Manual Name) for EDSADC_CH3_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH3_GAINCTR.
*/
#define EDSADC_GAINCTR3 (EDSADC_CH3_GAINCTR)

/** \brief 444, Gain Correction Register 3 */
#define EDSADC_CH3_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024444u)
/** Alias (User Manual Name) for EDSADC_CH3_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH3_GAINCORR.
*/
#define EDSADC_GAINCORR3 (EDSADC_CH3_GAINCORR)

/** \brief 450, Time-Stamp Register 3 */
#define EDSADC_CH3_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024450u)
/** Alias (User Manual Name) for EDSADC_CH3_TSTMP.
* To use register names with standard convension, please use EDSADC_CH3_TSTMP.
*/
#define EDSADC_TSTMP3 (EDSADC_CH3_TSTMP)

/** \brief 454, Time-Stamp Counter 3 */
#define EDSADC_CH3_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024454u)
/** Alias (User Manual Name) for EDSADC_CH3_TSCNT.
* To use register names with standard convension, please use EDSADC_CH3_TSCNT.
*/
#define EDSADC_TSCNT3 (EDSADC_CH3_TSCNT)

/** \brief 470, Auxiliary Filter Configuration Register 3 */
#define EDSADC_CH3_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024470u)
/** Alias (User Manual Name) for EDSADC_CH3_FCFGA.
* To use register names with standard convension, please use EDSADC_CH3_FCFGA.
*/
#define EDSADC_FCFGA3 (EDSADC_CH3_FCFGA)

/** \brief 478, Boundary Select Register 3 */
#define EDSADC_CH3_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024478u)
/** Alias (User Manual Name) for EDSADC_CH3_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH3_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL3 (EDSADC_CH3_BOUNDSEL)

/** \brief 480, Result Register 3 Auxiliary */
#define EDSADC_CH3_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024480u)
/** Alias (User Manual Name) for EDSADC_CH3_RESA.
* To use register names with standard convension, please use EDSADC_CH3_RESA.
*/
#define EDSADC_RESA3 (EDSADC_CH3_RESA)

/** \brief 4A0, Carrier Generator Synchronization Reg. 3 */
#define EDSADC_CH3_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00244A0u)
/** Alias (User Manual Name) for EDSADC_CH3_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH3_CGSYNC.
*/
#define EDSADC_CGSYNC3 (EDSADC_CH3_CGSYNC)

/** \brief 4A8, Rectification Configuration Register 3 */
#define EDSADC_CH3_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00244A8u)
/** Alias (User Manual Name) for EDSADC_CH3_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH3_RECTCFG.
*/
#define EDSADC_RECTCFG3 (EDSADC_CH3_RECTCFG)

/** \brief 4B0, Common Mode Voltage Register 3 */
#define EDSADC_CH3_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00244B0u)
/** Alias (User Manual Name) for EDSADC_CH3_VCM.
* To use register names with standard convension, please use EDSADC_CH3_VCM.
*/
#define EDSADC_VCM3 (EDSADC_CH3_VCM)

/** \brief 500, Modulator Configuration Register 4 */
#define EDSADC_CH4_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024500u)
/** Alias (User Manual Name) for EDSADC_CH4_MODCFG.
* To use register names with standard convension, please use EDSADC_CH4_MODCFG.
*/
#define EDSADC_MODCFG4 (EDSADC_CH4_MODCFG)

/** \brief 508, Demodulator Input Config. Register 4 */
#define EDSADC_CH4_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024508u)
/** Alias (User Manual Name) for EDSADC_CH4_DICFG.
* To use register names with standard convension, please use EDSADC_CH4_DICFG.
*/
#define EDSADC_DICFG4 (EDSADC_CH4_DICFG)

/** \brief 510, Filter Configuration Register 4, Main */
#define EDSADC_CH4_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024510u)
/** Alias (User Manual Name) for EDSADC_CH4_FCFGM.
* To use register names with standard convension, please use EDSADC_CH4_FCFGM.
*/
#define EDSADC_FCFGM4 (EDSADC_CH4_FCFGM)

/** \brief 514, Filter Configuration Register 4, CIC Filter */
#define EDSADC_CH4_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024514u)
/** Alias (User Manual Name) for EDSADC_CH4_FCFGC.
* To use register names with standard convension, please use EDSADC_CH4_FCFGC.
*/
#define EDSADC_FCFGC4 (EDSADC_CH4_FCFGC)

/** \brief 518, Filter Counter Register 4, CIC Filter */
#define EDSADC_CH4_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024518u)
/** Alias (User Manual Name) for EDSADC_CH4_FCNTC.
* To use register names with standard convension, please use EDSADC_CH4_FCNTC.
*/
#define EDSADC_FCNTC4 (EDSADC_CH4_FCNTC)

/** \brief 51C, Overshoot Compensation Cfg. Register 4 */
#define EDSADC_CH4_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002451Cu)
/** Alias (User Manual Name) for EDSADC_CH4_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH4_OVSCFG.
*/
#define EDSADC_OVSCFG4 (EDSADC_CH4_OVSCFG)

/** \brief 520, Integration Window Control Register 4 */
#define EDSADC_CH4_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024520u)
/** Alias (User Manual Name) for EDSADC_CH4_IWCTR.
* To use register names with standard convension, please use EDSADC_CH4_IWCTR.
*/
#define EDSADC_IWCTR4 (EDSADC_CH4_IWCTR)

/** \brief 524, Intermediate Integration Value */
#define EDSADC_CH4_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024524u)
/** Alias (User Manual Name) for EDSADC_CH4_IIVAL.
* To use register names with standard convension, please use EDSADC_CH4_IIVAL.
*/
#define EDSADC_IIVAL4 (EDSADC_CH4_IIVAL)

/** \brief 528, Integrator Status Register 4 */
#define EDSADC_CH4_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024528u)
/** Alias (User Manual Name) for EDSADC_CH4_ISTAT.
* To use register names with standard convension, please use EDSADC_CH4_ISTAT.
*/
#define EDSADC_ISTAT4 (EDSADC_CH4_ISTAT)

/** \brief 52C, Result FIFO Control Register 4 */
#define EDSADC_CH4_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002452Cu)
/** Alias (User Manual Name) for EDSADC_CH4_RFC.
* To use register names with standard convension, please use EDSADC_CH4_RFC.
*/
#define EDSADC_RFC4 (EDSADC_CH4_RFC)

/** \brief 530, Result Register 4 Main */
#define EDSADC_CH4_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024530u)
/** Alias (User Manual Name) for EDSADC_CH4_RESM.
* To use register names with standard convension, please use EDSADC_CH4_RESM.
*/
#define EDSADC_RESM4 (EDSADC_CH4_RESM)

/** \brief 538, Offset Compensation Register 4 */
#define EDSADC_CH4_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024538u)
/** Alias (User Manual Name) for EDSADC_CH4_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH4_OFFCOMP.
*/
#define EDSADC_OFFCOMP4 (EDSADC_CH4_OFFCOMP)

/** \brief 53C, Gain Calibration Register 4 */
#define EDSADC_CH4_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002453Cu)
/** Alias (User Manual Name) for EDSADC_CH4_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH4_GAINCAL.
*/
#define EDSADC_GAINCAL4 (EDSADC_CH4_GAINCAL)

/** \brief 540, Gain Control Register 4 */
#define EDSADC_CH4_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024540u)
/** Alias (User Manual Name) for EDSADC_CH4_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH4_GAINCTR.
*/
#define EDSADC_GAINCTR4 (EDSADC_CH4_GAINCTR)

/** \brief 544, Gain Correction Register 4 */
#define EDSADC_CH4_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024544u)
/** Alias (User Manual Name) for EDSADC_CH4_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH4_GAINCORR.
*/
#define EDSADC_GAINCORR4 (EDSADC_CH4_GAINCORR)

/** \brief 550, Time-Stamp Register 4 */
#define EDSADC_CH4_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024550u)
/** Alias (User Manual Name) for EDSADC_CH4_TSTMP.
* To use register names with standard convension, please use EDSADC_CH4_TSTMP.
*/
#define EDSADC_TSTMP4 (EDSADC_CH4_TSTMP)

/** \brief 554, Time-Stamp Counter 4 */
#define EDSADC_CH4_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024554u)
/** Alias (User Manual Name) for EDSADC_CH4_TSCNT.
* To use register names with standard convension, please use EDSADC_CH4_TSCNT.
*/
#define EDSADC_TSCNT4 (EDSADC_CH4_TSCNT)

/** \brief 570, Auxiliary Filter Configuration Register 4 */
#define EDSADC_CH4_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024570u)
/** Alias (User Manual Name) for EDSADC_CH4_FCFGA.
* To use register names with standard convension, please use EDSADC_CH4_FCFGA.
*/
#define EDSADC_FCFGA4 (EDSADC_CH4_FCFGA)

/** \brief 578, Boundary Select Register 4 */
#define EDSADC_CH4_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024578u)
/** Alias (User Manual Name) for EDSADC_CH4_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH4_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL4 (EDSADC_CH4_BOUNDSEL)

/** \brief 580, Result Register 4 Auxiliary */
#define EDSADC_CH4_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024580u)
/** Alias (User Manual Name) for EDSADC_CH4_RESA.
* To use register names with standard convension, please use EDSADC_CH4_RESA.
*/
#define EDSADC_RESA4 (EDSADC_CH4_RESA)

/** \brief 5A0, Carrier Generator Synchronization Reg. 4 */
#define EDSADC_CH4_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00245A0u)
/** Alias (User Manual Name) for EDSADC_CH4_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH4_CGSYNC.
*/
#define EDSADC_CGSYNC4 (EDSADC_CH4_CGSYNC)

/** \brief 5A8, Rectification Configuration Register 4 */
#define EDSADC_CH4_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00245A8u)
/** Alias (User Manual Name) for EDSADC_CH4_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH4_RECTCFG.
*/
#define EDSADC_RECTCFG4 (EDSADC_CH4_RECTCFG)

/** \brief 5B0, Common Mode Voltage Register 4 */
#define EDSADC_CH4_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00245B0u)
/** Alias (User Manual Name) for EDSADC_CH4_VCM.
* To use register names with standard convension, please use EDSADC_CH4_VCM.
*/
#define EDSADC_VCM4 (EDSADC_CH4_VCM)

/** \brief 600, Modulator Configuration Register 5 */
#define EDSADC_CH5_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024600u)
/** Alias (User Manual Name) for EDSADC_CH5_MODCFG.
* To use register names with standard convension, please use EDSADC_CH5_MODCFG.
*/
#define EDSADC_MODCFG5 (EDSADC_CH5_MODCFG)

/** \brief 608, Demodulator Input Config. Register 5 */
#define EDSADC_CH5_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024608u)
/** Alias (User Manual Name) for EDSADC_CH5_DICFG.
* To use register names with standard convension, please use EDSADC_CH5_DICFG.
*/
#define EDSADC_DICFG5 (EDSADC_CH5_DICFG)

/** \brief 610, Filter Configuration Register 5, Main */
#define EDSADC_CH5_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024610u)
/** Alias (User Manual Name) for EDSADC_CH5_FCFGM.
* To use register names with standard convension, please use EDSADC_CH5_FCFGM.
*/
#define EDSADC_FCFGM5 (EDSADC_CH5_FCFGM)

/** \brief 614, Filter Configuration Register 5, CIC Filter */
#define EDSADC_CH5_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024614u)
/** Alias (User Manual Name) for EDSADC_CH5_FCFGC.
* To use register names with standard convension, please use EDSADC_CH5_FCFGC.
*/
#define EDSADC_FCFGC5 (EDSADC_CH5_FCFGC)

/** \brief 618, Filter Counter Register 5, CIC Filter */
#define EDSADC_CH5_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024618u)
/** Alias (User Manual Name) for EDSADC_CH5_FCNTC.
* To use register names with standard convension, please use EDSADC_CH5_FCNTC.
*/
#define EDSADC_FCNTC5 (EDSADC_CH5_FCNTC)

/** \brief 61C, Overshoot Compensation Cfg. Register 5 */
#define EDSADC_CH5_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002461Cu)
/** Alias (User Manual Name) for EDSADC_CH5_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH5_OVSCFG.
*/
#define EDSADC_OVSCFG5 (EDSADC_CH5_OVSCFG)

/** \brief 620, Integration Window Control Register 5 */
#define EDSADC_CH5_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024620u)
/** Alias (User Manual Name) for EDSADC_CH5_IWCTR.
* To use register names with standard convension, please use EDSADC_CH5_IWCTR.
*/
#define EDSADC_IWCTR5 (EDSADC_CH5_IWCTR)

/** \brief 624, Intermediate Integration Value */
#define EDSADC_CH5_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024624u)
/** Alias (User Manual Name) for EDSADC_CH5_IIVAL.
* To use register names with standard convension, please use EDSADC_CH5_IIVAL.
*/
#define EDSADC_IIVAL5 (EDSADC_CH5_IIVAL)

/** \brief 628, Integrator Status Register 5 */
#define EDSADC_CH5_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024628u)
/** Alias (User Manual Name) for EDSADC_CH5_ISTAT.
* To use register names with standard convension, please use EDSADC_CH5_ISTAT.
*/
#define EDSADC_ISTAT5 (EDSADC_CH5_ISTAT)

/** \brief 62C, Result FIFO Control Register 5 */
#define EDSADC_CH5_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002462Cu)
/** Alias (User Manual Name) for EDSADC_CH5_RFC.
* To use register names with standard convension, please use EDSADC_CH5_RFC.
*/
#define EDSADC_RFC5 (EDSADC_CH5_RFC)

/** \brief 630, Result Register 5 Main */
#define EDSADC_CH5_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024630u)
/** Alias (User Manual Name) for EDSADC_CH5_RESM.
* To use register names with standard convension, please use EDSADC_CH5_RESM.
*/
#define EDSADC_RESM5 (EDSADC_CH5_RESM)

/** \brief 638, Offset Compensation Register 5 */
#define EDSADC_CH5_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024638u)
/** Alias (User Manual Name) for EDSADC_CH5_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH5_OFFCOMP.
*/
#define EDSADC_OFFCOMP5 (EDSADC_CH5_OFFCOMP)

/** \brief 63C, Gain Calibration Register 5 */
#define EDSADC_CH5_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002463Cu)
/** Alias (User Manual Name) for EDSADC_CH5_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH5_GAINCAL.
*/
#define EDSADC_GAINCAL5 (EDSADC_CH5_GAINCAL)

/** \brief 640, Gain Control Register 5 */
#define EDSADC_CH5_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024640u)
/** Alias (User Manual Name) for EDSADC_CH5_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH5_GAINCTR.
*/
#define EDSADC_GAINCTR5 (EDSADC_CH5_GAINCTR)

/** \brief 644, Gain Correction Register 5 */
#define EDSADC_CH5_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024644u)
/** Alias (User Manual Name) for EDSADC_CH5_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH5_GAINCORR.
*/
#define EDSADC_GAINCORR5 (EDSADC_CH5_GAINCORR)

/** \brief 650, Time-Stamp Register 5 */
#define EDSADC_CH5_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024650u)
/** Alias (User Manual Name) for EDSADC_CH5_TSTMP.
* To use register names with standard convension, please use EDSADC_CH5_TSTMP.
*/
#define EDSADC_TSTMP5 (EDSADC_CH5_TSTMP)

/** \brief 654, Time-Stamp Counter 5 */
#define EDSADC_CH5_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024654u)
/** Alias (User Manual Name) for EDSADC_CH5_TSCNT.
* To use register names with standard convension, please use EDSADC_CH5_TSCNT.
*/
#define EDSADC_TSCNT5 (EDSADC_CH5_TSCNT)

/** \brief 670, Auxiliary Filter Configuration Register 5 */
#define EDSADC_CH5_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024670u)
/** Alias (User Manual Name) for EDSADC_CH5_FCFGA.
* To use register names with standard convension, please use EDSADC_CH5_FCFGA.
*/
#define EDSADC_FCFGA5 (EDSADC_CH5_FCFGA)

/** \brief 678, Boundary Select Register 5 */
#define EDSADC_CH5_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024678u)
/** Alias (User Manual Name) for EDSADC_CH5_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH5_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL5 (EDSADC_CH5_BOUNDSEL)

/** \brief 680, Result Register 5 Auxiliary */
#define EDSADC_CH5_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024680u)
/** Alias (User Manual Name) for EDSADC_CH5_RESA.
* To use register names with standard convension, please use EDSADC_CH5_RESA.
*/
#define EDSADC_RESA5 (EDSADC_CH5_RESA)

/** \brief 6A0, Carrier Generator Synchronization Reg. 5 */
#define EDSADC_CH5_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00246A0u)
/** Alias (User Manual Name) for EDSADC_CH5_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH5_CGSYNC.
*/
#define EDSADC_CGSYNC5 (EDSADC_CH5_CGSYNC)

/** \brief 6A8, Rectification Configuration Register 5 */
#define EDSADC_CH5_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00246A8u)
/** Alias (User Manual Name) for EDSADC_CH5_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH5_RECTCFG.
*/
#define EDSADC_RECTCFG5 (EDSADC_CH5_RECTCFG)

/** \brief 6B0, Common Mode Voltage Register 5 */
#define EDSADC_CH5_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00246B0u)
/** Alias (User Manual Name) for EDSADC_CH5_VCM.
* To use register names with standard convension, please use EDSADC_CH5_VCM.
*/
#define EDSADC_VCM5 (EDSADC_CH5_VCM)

/** \brief 700, Modulator Configuration Register 6 */
#define EDSADC_CH6_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024700u)
/** Alias (User Manual Name) for EDSADC_CH6_MODCFG.
* To use register names with standard convension, please use EDSADC_CH6_MODCFG.
*/
#define EDSADC_MODCFG6 (EDSADC_CH6_MODCFG)

/** \brief 708, Demodulator Input Config. Register 6 */
#define EDSADC_CH6_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024708u)
/** Alias (User Manual Name) for EDSADC_CH6_DICFG.
* To use register names with standard convension, please use EDSADC_CH6_DICFG.
*/
#define EDSADC_DICFG6 (EDSADC_CH6_DICFG)

/** \brief 710, Filter Configuration Register 6, Main */
#define EDSADC_CH6_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024710u)
/** Alias (User Manual Name) for EDSADC_CH6_FCFGM.
* To use register names with standard convension, please use EDSADC_CH6_FCFGM.
*/
#define EDSADC_FCFGM6 (EDSADC_CH6_FCFGM)

/** \brief 714, Filter Configuration Register 6, CIC Filter */
#define EDSADC_CH6_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024714u)
/** Alias (User Manual Name) for EDSADC_CH6_FCFGC.
* To use register names with standard convension, please use EDSADC_CH6_FCFGC.
*/
#define EDSADC_FCFGC6 (EDSADC_CH6_FCFGC)

/** \brief 718, Filter Counter Register 6, CIC Filter */
#define EDSADC_CH6_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024718u)
/** Alias (User Manual Name) for EDSADC_CH6_FCNTC.
* To use register names with standard convension, please use EDSADC_CH6_FCNTC.
*/
#define EDSADC_FCNTC6 (EDSADC_CH6_FCNTC)

/** \brief 71C, Overshoot Compensation Cfg. Register 6 */
#define EDSADC_CH6_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002471Cu)
/** Alias (User Manual Name) for EDSADC_CH6_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH6_OVSCFG.
*/
#define EDSADC_OVSCFG6 (EDSADC_CH6_OVSCFG)

/** \brief 720, Integration Window Control Register 6 */
#define EDSADC_CH6_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024720u)
/** Alias (User Manual Name) for EDSADC_CH6_IWCTR.
* To use register names with standard convension, please use EDSADC_CH6_IWCTR.
*/
#define EDSADC_IWCTR6 (EDSADC_CH6_IWCTR)

/** \brief 724, Intermediate Integration Value */
#define EDSADC_CH6_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024724u)
/** Alias (User Manual Name) for EDSADC_CH6_IIVAL.
* To use register names with standard convension, please use EDSADC_CH6_IIVAL.
*/
#define EDSADC_IIVAL6 (EDSADC_CH6_IIVAL)

/** \brief 728, Integrator Status Register 6 */
#define EDSADC_CH6_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024728u)
/** Alias (User Manual Name) for EDSADC_CH6_ISTAT.
* To use register names with standard convension, please use EDSADC_CH6_ISTAT.
*/
#define EDSADC_ISTAT6 (EDSADC_CH6_ISTAT)

/** \brief 72C, Result FIFO Control Register 6 */
#define EDSADC_CH6_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002472Cu)
/** Alias (User Manual Name) for EDSADC_CH6_RFC.
* To use register names with standard convension, please use EDSADC_CH6_RFC.
*/
#define EDSADC_RFC6 (EDSADC_CH6_RFC)

/** \brief 730, Result Register 6 Main */
#define EDSADC_CH6_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024730u)
/** Alias (User Manual Name) for EDSADC_CH6_RESM.
* To use register names with standard convension, please use EDSADC_CH6_RESM.
*/
#define EDSADC_RESM6 (EDSADC_CH6_RESM)

/** \brief 738, Offset Compensation Register 6 */
#define EDSADC_CH6_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024738u)
/** Alias (User Manual Name) for EDSADC_CH6_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH6_OFFCOMP.
*/
#define EDSADC_OFFCOMP6 (EDSADC_CH6_OFFCOMP)

/** \brief 73C, Gain Calibration Register 6 */
#define EDSADC_CH6_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002473Cu)
/** Alias (User Manual Name) for EDSADC_CH6_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH6_GAINCAL.
*/
#define EDSADC_GAINCAL6 (EDSADC_CH6_GAINCAL)

/** \brief 740, Gain Control Register 6 */
#define EDSADC_CH6_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024740u)
/** Alias (User Manual Name) for EDSADC_CH6_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH6_GAINCTR.
*/
#define EDSADC_GAINCTR6 (EDSADC_CH6_GAINCTR)

/** \brief 744, Gain Correction Register 6 */
#define EDSADC_CH6_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024744u)
/** Alias (User Manual Name) for EDSADC_CH6_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH6_GAINCORR.
*/
#define EDSADC_GAINCORR6 (EDSADC_CH6_GAINCORR)

/** \brief 750, Time-Stamp Register 6 */
#define EDSADC_CH6_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024750u)
/** Alias (User Manual Name) for EDSADC_CH6_TSTMP.
* To use register names with standard convension, please use EDSADC_CH6_TSTMP.
*/
#define EDSADC_TSTMP6 (EDSADC_CH6_TSTMP)

/** \brief 754, Time-Stamp Counter 6 */
#define EDSADC_CH6_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024754u)
/** Alias (User Manual Name) for EDSADC_CH6_TSCNT.
* To use register names with standard convension, please use EDSADC_CH6_TSCNT.
*/
#define EDSADC_TSCNT6 (EDSADC_CH6_TSCNT)

/** \brief 770, Auxiliary Filter Configuration Register 6 */
#define EDSADC_CH6_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024770u)
/** Alias (User Manual Name) for EDSADC_CH6_FCFGA.
* To use register names with standard convension, please use EDSADC_CH6_FCFGA.
*/
#define EDSADC_FCFGA6 (EDSADC_CH6_FCFGA)

/** \brief 778, Boundary Select Register 6 */
#define EDSADC_CH6_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024778u)
/** Alias (User Manual Name) for EDSADC_CH6_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH6_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL6 (EDSADC_CH6_BOUNDSEL)

/** \brief 780, Result Register 6 Auxiliary */
#define EDSADC_CH6_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024780u)
/** Alias (User Manual Name) for EDSADC_CH6_RESA.
* To use register names with standard convension, please use EDSADC_CH6_RESA.
*/
#define EDSADC_RESA6 (EDSADC_CH6_RESA)

/** \brief 7A0, Carrier Generator Synchronization Reg. 6 */
#define EDSADC_CH6_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00247A0u)
/** Alias (User Manual Name) for EDSADC_CH6_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH6_CGSYNC.
*/
#define EDSADC_CGSYNC6 (EDSADC_CH6_CGSYNC)

/** \brief 7A8, Rectification Configuration Register 6 */
#define EDSADC_CH6_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00247A8u)
/** Alias (User Manual Name) for EDSADC_CH6_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH6_RECTCFG.
*/
#define EDSADC_RECTCFG6 (EDSADC_CH6_RECTCFG)

/** \brief 7B0, Common Mode Voltage Register 6 */
#define EDSADC_CH6_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00247B0u)
/** Alias (User Manual Name) for EDSADC_CH6_VCM.
* To use register names with standard convension, please use EDSADC_CH6_VCM.
*/
#define EDSADC_VCM6 (EDSADC_CH6_VCM)

/** \brief 800, Modulator Configuration Register 7 */
#define EDSADC_CH7_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024800u)
/** Alias (User Manual Name) for EDSADC_CH7_MODCFG.
* To use register names with standard convension, please use EDSADC_CH7_MODCFG.
*/
#define EDSADC_MODCFG7 (EDSADC_CH7_MODCFG)

/** \brief 808, Demodulator Input Config. Register 7 */
#define EDSADC_CH7_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024808u)
/** Alias (User Manual Name) for EDSADC_CH7_DICFG.
* To use register names with standard convension, please use EDSADC_CH7_DICFG.
*/
#define EDSADC_DICFG7 (EDSADC_CH7_DICFG)

/** \brief 810, Filter Configuration Register 7, Main */
#define EDSADC_CH7_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024810u)
/** Alias (User Manual Name) for EDSADC_CH7_FCFGM.
* To use register names with standard convension, please use EDSADC_CH7_FCFGM.
*/
#define EDSADC_FCFGM7 (EDSADC_CH7_FCFGM)

/** \brief 814, Filter Configuration Register 7, CIC Filter */
#define EDSADC_CH7_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024814u)
/** Alias (User Manual Name) for EDSADC_CH7_FCFGC.
* To use register names with standard convension, please use EDSADC_CH7_FCFGC.
*/
#define EDSADC_FCFGC7 (EDSADC_CH7_FCFGC)

/** \brief 818, Filter Counter Register 7, CIC Filter */
#define EDSADC_CH7_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024818u)
/** Alias (User Manual Name) for EDSADC_CH7_FCNTC.
* To use register names with standard convension, please use EDSADC_CH7_FCNTC.
*/
#define EDSADC_FCNTC7 (EDSADC_CH7_FCNTC)

/** \brief 81C, Overshoot Compensation Cfg. Register 7 */
#define EDSADC_CH7_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002481Cu)
/** Alias (User Manual Name) for EDSADC_CH7_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH7_OVSCFG.
*/
#define EDSADC_OVSCFG7 (EDSADC_CH7_OVSCFG)

/** \brief 820, Integration Window Control Register 7 */
#define EDSADC_CH7_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024820u)
/** Alias (User Manual Name) for EDSADC_CH7_IWCTR.
* To use register names with standard convension, please use EDSADC_CH7_IWCTR.
*/
#define EDSADC_IWCTR7 (EDSADC_CH7_IWCTR)

/** \brief 824, Intermediate Integration Value */
#define EDSADC_CH7_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024824u)
/** Alias (User Manual Name) for EDSADC_CH7_IIVAL.
* To use register names with standard convension, please use EDSADC_CH7_IIVAL.
*/
#define EDSADC_IIVAL7 (EDSADC_CH7_IIVAL)

/** \brief 828, Integrator Status Register 7 */
#define EDSADC_CH7_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024828u)
/** Alias (User Manual Name) for EDSADC_CH7_ISTAT.
* To use register names with standard convension, please use EDSADC_CH7_ISTAT.
*/
#define EDSADC_ISTAT7 (EDSADC_CH7_ISTAT)

/** \brief 82C, Result FIFO Control Register 7 */
#define EDSADC_CH7_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002482Cu)
/** Alias (User Manual Name) for EDSADC_CH7_RFC.
* To use register names with standard convension, please use EDSADC_CH7_RFC.
*/
#define EDSADC_RFC7 (EDSADC_CH7_RFC)

/** \brief 830, Result Register 7 Main */
#define EDSADC_CH7_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024830u)
/** Alias (User Manual Name) for EDSADC_CH7_RESM.
* To use register names with standard convension, please use EDSADC_CH7_RESM.
*/
#define EDSADC_RESM7 (EDSADC_CH7_RESM)

/** \brief 838, Offset Compensation Register 7 */
#define EDSADC_CH7_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024838u)
/** Alias (User Manual Name) for EDSADC_CH7_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH7_OFFCOMP.
*/
#define EDSADC_OFFCOMP7 (EDSADC_CH7_OFFCOMP)

/** \brief 83C, Gain Calibration Register 7 */
#define EDSADC_CH7_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002483Cu)
/** Alias (User Manual Name) for EDSADC_CH7_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH7_GAINCAL.
*/
#define EDSADC_GAINCAL7 (EDSADC_CH7_GAINCAL)

/** \brief 840, Gain Control Register 7 */
#define EDSADC_CH7_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024840u)
/** Alias (User Manual Name) for EDSADC_CH7_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH7_GAINCTR.
*/
#define EDSADC_GAINCTR7 (EDSADC_CH7_GAINCTR)

/** \brief 844, Gain Correction Register 7 */
#define EDSADC_CH7_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024844u)
/** Alias (User Manual Name) for EDSADC_CH7_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH7_GAINCORR.
*/
#define EDSADC_GAINCORR7 (EDSADC_CH7_GAINCORR)

/** \brief 850, Time-Stamp Register 7 */
#define EDSADC_CH7_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024850u)
/** Alias (User Manual Name) for EDSADC_CH7_TSTMP.
* To use register names with standard convension, please use EDSADC_CH7_TSTMP.
*/
#define EDSADC_TSTMP7 (EDSADC_CH7_TSTMP)

/** \brief 854, Time-Stamp Counter 7 */
#define EDSADC_CH7_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024854u)
/** Alias (User Manual Name) for EDSADC_CH7_TSCNT.
* To use register names with standard convension, please use EDSADC_CH7_TSCNT.
*/
#define EDSADC_TSCNT7 (EDSADC_CH7_TSCNT)

/** \brief 870, Auxiliary Filter Configuration Register 7 */
#define EDSADC_CH7_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024870u)
/** Alias (User Manual Name) for EDSADC_CH7_FCFGA.
* To use register names with standard convension, please use EDSADC_CH7_FCFGA.
*/
#define EDSADC_FCFGA7 (EDSADC_CH7_FCFGA)

/** \brief 878, Boundary Select Register 7 */
#define EDSADC_CH7_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024878u)
/** Alias (User Manual Name) for EDSADC_CH7_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH7_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL7 (EDSADC_CH7_BOUNDSEL)

/** \brief 880, Result Register 7 Auxiliary */
#define EDSADC_CH7_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024880u)
/** Alias (User Manual Name) for EDSADC_CH7_RESA.
* To use register names with standard convension, please use EDSADC_CH7_RESA.
*/
#define EDSADC_RESA7 (EDSADC_CH7_RESA)

/** \brief 8A0, Carrier Generator Synchronization Reg. 7 */
#define EDSADC_CH7_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00248A0u)
/** Alias (User Manual Name) for EDSADC_CH7_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH7_CGSYNC.
*/
#define EDSADC_CGSYNC7 (EDSADC_CH7_CGSYNC)

/** \brief 8A8, Rectification Configuration Register 7 */
#define EDSADC_CH7_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00248A8u)
/** Alias (User Manual Name) for EDSADC_CH7_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH7_RECTCFG.
*/
#define EDSADC_RECTCFG7 (EDSADC_CH7_RECTCFG)

/** \brief 8B0, Common Mode Voltage Register 7 */
#define EDSADC_CH7_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00248B0u)
/** Alias (User Manual Name) for EDSADC_CH7_VCM.
* To use register names with standard convension, please use EDSADC_CH7_VCM.
*/
#define EDSADC_VCM7 (EDSADC_CH7_VCM)

/** \brief 900, Modulator Configuration Register 8 */
#define EDSADC_CH8_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024900u)
/** Alias (User Manual Name) for EDSADC_CH8_MODCFG.
* To use register names with standard convension, please use EDSADC_CH8_MODCFG.
*/
#define EDSADC_MODCFG8 (EDSADC_CH8_MODCFG)

/** \brief 908, Demodulator Input Config. Register 8 */
#define EDSADC_CH8_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024908u)
/** Alias (User Manual Name) for EDSADC_CH8_DICFG.
* To use register names with standard convension, please use EDSADC_CH8_DICFG.
*/
#define EDSADC_DICFG8 (EDSADC_CH8_DICFG)

/** \brief 910, Filter Configuration Register 8, Main */
#define EDSADC_CH8_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024910u)
/** Alias (User Manual Name) for EDSADC_CH8_FCFGM.
* To use register names with standard convension, please use EDSADC_CH8_FCFGM.
*/
#define EDSADC_FCFGM8 (EDSADC_CH8_FCFGM)

/** \brief 914, Filter Configuration Register 8, CIC Filter */
#define EDSADC_CH8_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024914u)
/** Alias (User Manual Name) for EDSADC_CH8_FCFGC.
* To use register names with standard convension, please use EDSADC_CH8_FCFGC.
*/
#define EDSADC_FCFGC8 (EDSADC_CH8_FCFGC)

/** \brief 918, Filter Counter Register 8, CIC Filter */
#define EDSADC_CH8_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024918u)
/** Alias (User Manual Name) for EDSADC_CH8_FCNTC.
* To use register names with standard convension, please use EDSADC_CH8_FCNTC.
*/
#define EDSADC_FCNTC8 (EDSADC_CH8_FCNTC)

/** \brief 91C, Overshoot Compensation Cfg. Register 8 */
#define EDSADC_CH8_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF002491Cu)
/** Alias (User Manual Name) for EDSADC_CH8_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH8_OVSCFG.
*/
#define EDSADC_OVSCFG8 (EDSADC_CH8_OVSCFG)

/** \brief 920, Integration Window Control Register 8 */
#define EDSADC_CH8_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024920u)
/** Alias (User Manual Name) for EDSADC_CH8_IWCTR.
* To use register names with standard convension, please use EDSADC_CH8_IWCTR.
*/
#define EDSADC_IWCTR8 (EDSADC_CH8_IWCTR)

/** \brief 924, Intermediate Integration Value */
#define EDSADC_CH8_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024924u)
/** Alias (User Manual Name) for EDSADC_CH8_IIVAL.
* To use register names with standard convension, please use EDSADC_CH8_IIVAL.
*/
#define EDSADC_IIVAL8 (EDSADC_CH8_IIVAL)

/** \brief 928, Integrator Status Register 8 */
#define EDSADC_CH8_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024928u)
/** Alias (User Manual Name) for EDSADC_CH8_ISTAT.
* To use register names with standard convension, please use EDSADC_CH8_ISTAT.
*/
#define EDSADC_ISTAT8 (EDSADC_CH8_ISTAT)

/** \brief 92C, Result FIFO Control Register 8 */
#define EDSADC_CH8_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF002492Cu)
/** Alias (User Manual Name) for EDSADC_CH8_RFC.
* To use register names with standard convension, please use EDSADC_CH8_RFC.
*/
#define EDSADC_RFC8 (EDSADC_CH8_RFC)

/** \brief 930, Result Register 8 Main */
#define EDSADC_CH8_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024930u)
/** Alias (User Manual Name) for EDSADC_CH8_RESM.
* To use register names with standard convension, please use EDSADC_CH8_RESM.
*/
#define EDSADC_RESM8 (EDSADC_CH8_RESM)

/** \brief 938, Offset Compensation Register 8 */
#define EDSADC_CH8_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024938u)
/** Alias (User Manual Name) for EDSADC_CH8_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH8_OFFCOMP.
*/
#define EDSADC_OFFCOMP8 (EDSADC_CH8_OFFCOMP)

/** \brief 93C, Gain Calibration Register 8 */
#define EDSADC_CH8_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF002493Cu)
/** Alias (User Manual Name) for EDSADC_CH8_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH8_GAINCAL.
*/
#define EDSADC_GAINCAL8 (EDSADC_CH8_GAINCAL)

/** \brief 940, Gain Control Register 8 */
#define EDSADC_CH8_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024940u)
/** Alias (User Manual Name) for EDSADC_CH8_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH8_GAINCTR.
*/
#define EDSADC_GAINCTR8 (EDSADC_CH8_GAINCTR)

/** \brief 944, Gain Correction Register 8 */
#define EDSADC_CH8_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024944u)
/** Alias (User Manual Name) for EDSADC_CH8_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH8_GAINCORR.
*/
#define EDSADC_GAINCORR8 (EDSADC_CH8_GAINCORR)

/** \brief 950, Time-Stamp Register 8 */
#define EDSADC_CH8_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024950u)
/** Alias (User Manual Name) for EDSADC_CH8_TSTMP.
* To use register names with standard convension, please use EDSADC_CH8_TSTMP.
*/
#define EDSADC_TSTMP8 (EDSADC_CH8_TSTMP)

/** \brief 954, Time-Stamp Counter 8 */
#define EDSADC_CH8_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024954u)
/** Alias (User Manual Name) for EDSADC_CH8_TSCNT.
* To use register names with standard convension, please use EDSADC_CH8_TSCNT.
*/
#define EDSADC_TSCNT8 (EDSADC_CH8_TSCNT)

/** \brief 970, Auxiliary Filter Configuration Register 8 */
#define EDSADC_CH8_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024970u)
/** Alias (User Manual Name) for EDSADC_CH8_FCFGA.
* To use register names with standard convension, please use EDSADC_CH8_FCFGA.
*/
#define EDSADC_FCFGA8 (EDSADC_CH8_FCFGA)

/** \brief 978, Boundary Select Register 8 */
#define EDSADC_CH8_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024978u)
/** Alias (User Manual Name) for EDSADC_CH8_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH8_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL8 (EDSADC_CH8_BOUNDSEL)

/** \brief 980, Result Register 8 Auxiliary */
#define EDSADC_CH8_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024980u)
/** Alias (User Manual Name) for EDSADC_CH8_RESA.
* To use register names with standard convension, please use EDSADC_CH8_RESA.
*/
#define EDSADC_RESA8 (EDSADC_CH8_RESA)

/** \brief 9A0, Carrier Generator Synchronization Reg. 8 */
#define EDSADC_CH8_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF00249A0u)
/** Alias (User Manual Name) for EDSADC_CH8_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH8_CGSYNC.
*/
#define EDSADC_CGSYNC8 (EDSADC_CH8_CGSYNC)

/** \brief 9A8, Rectification Configuration Register 8 */
#define EDSADC_CH8_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF00249A8u)
/** Alias (User Manual Name) for EDSADC_CH8_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH8_RECTCFG.
*/
#define EDSADC_RECTCFG8 (EDSADC_CH8_RECTCFG)

/** \brief 9B0, Common Mode Voltage Register 8 */
#define EDSADC_CH8_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF00249B0u)
/** Alias (User Manual Name) for EDSADC_CH8_VCM.
* To use register names with standard convension, please use EDSADC_CH8_VCM.
*/
#define EDSADC_VCM8 (EDSADC_CH8_VCM)

/** \brief A00, Modulator Configuration Register 9 */
#define EDSADC_CH9_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024A00u)
/** Alias (User Manual Name) for EDSADC_CH9_MODCFG.
* To use register names with standard convension, please use EDSADC_CH9_MODCFG.
*/
#define EDSADC_MODCFG9 (EDSADC_CH9_MODCFG)

/** \brief A08, Demodulator Input Config. Register 9 */
#define EDSADC_CH9_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024A08u)
/** Alias (User Manual Name) for EDSADC_CH9_DICFG.
* To use register names with standard convension, please use EDSADC_CH9_DICFG.
*/
#define EDSADC_DICFG9 (EDSADC_CH9_DICFG)

/** \brief A10, Filter Configuration Register 9, Main */
#define EDSADC_CH9_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024A10u)
/** Alias (User Manual Name) for EDSADC_CH9_FCFGM.
* To use register names with standard convension, please use EDSADC_CH9_FCFGM.
*/
#define EDSADC_FCFGM9 (EDSADC_CH9_FCFGM)

/** \brief A14, Filter Configuration Register 9, CIC Filter */
#define EDSADC_CH9_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024A14u)
/** Alias (User Manual Name) for EDSADC_CH9_FCFGC.
* To use register names with standard convension, please use EDSADC_CH9_FCFGC.
*/
#define EDSADC_FCFGC9 (EDSADC_CH9_FCFGC)

/** \brief A18, Filter Counter Register 9, CIC Filter */
#define EDSADC_CH9_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024A18u)
/** Alias (User Manual Name) for EDSADC_CH9_FCNTC.
* To use register names with standard convension, please use EDSADC_CH9_FCNTC.
*/
#define EDSADC_FCNTC9 (EDSADC_CH9_FCNTC)

/** \brief A1C, Overshoot Compensation Cfg. Register 9 */
#define EDSADC_CH9_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF0024A1Cu)
/** Alias (User Manual Name) for EDSADC_CH9_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH9_OVSCFG.
*/
#define EDSADC_OVSCFG9 (EDSADC_CH9_OVSCFG)

/** \brief A20, Integration Window Control Register 9 */
#define EDSADC_CH9_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024A20u)
/** Alias (User Manual Name) for EDSADC_CH9_IWCTR.
* To use register names with standard convension, please use EDSADC_CH9_IWCTR.
*/
#define EDSADC_IWCTR9 (EDSADC_CH9_IWCTR)

/** \brief A24, Intermediate Integration Value */
#define EDSADC_CH9_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024A24u)
/** Alias (User Manual Name) for EDSADC_CH9_IIVAL.
* To use register names with standard convension, please use EDSADC_CH9_IIVAL.
*/
#define EDSADC_IIVAL9 (EDSADC_CH9_IIVAL)

/** \brief A28, Integrator Status Register 9 */
#define EDSADC_CH9_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024A28u)
/** Alias (User Manual Name) for EDSADC_CH9_ISTAT.
* To use register names with standard convension, please use EDSADC_CH9_ISTAT.
*/
#define EDSADC_ISTAT9 (EDSADC_CH9_ISTAT)

/** \brief A2C, Result FIFO Control Register 9 */
#define EDSADC_CH9_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF0024A2Cu)
/** Alias (User Manual Name) for EDSADC_CH9_RFC.
* To use register names with standard convension, please use EDSADC_CH9_RFC.
*/
#define EDSADC_RFC9 (EDSADC_CH9_RFC)

/** \brief A30, Result Register 9 Main */
#define EDSADC_CH9_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024A30u)
/** Alias (User Manual Name) for EDSADC_CH9_RESM.
* To use register names with standard convension, please use EDSADC_CH9_RESM.
*/
#define EDSADC_RESM9 (EDSADC_CH9_RESM)

/** \brief A38, Offset Compensation Register 9 */
#define EDSADC_CH9_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024A38u)
/** Alias (User Manual Name) for EDSADC_CH9_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH9_OFFCOMP.
*/
#define EDSADC_OFFCOMP9 (EDSADC_CH9_OFFCOMP)

/** \brief A3C, Gain Calibration Register 9 */
#define EDSADC_CH9_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF0024A3Cu)
/** Alias (User Manual Name) for EDSADC_CH9_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH9_GAINCAL.
*/
#define EDSADC_GAINCAL9 (EDSADC_CH9_GAINCAL)

/** \brief A40, Gain Control Register 9 */
#define EDSADC_CH9_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024A40u)
/** Alias (User Manual Name) for EDSADC_CH9_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH9_GAINCTR.
*/
#define EDSADC_GAINCTR9 (EDSADC_CH9_GAINCTR)

/** \brief A44, Gain Correction Register 9 */
#define EDSADC_CH9_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024A44u)
/** Alias (User Manual Name) for EDSADC_CH9_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH9_GAINCORR.
*/
#define EDSADC_GAINCORR9 (EDSADC_CH9_GAINCORR)

/** \brief A50, Time-Stamp Register 9 */
#define EDSADC_CH9_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024A50u)
/** Alias (User Manual Name) for EDSADC_CH9_TSTMP.
* To use register names with standard convension, please use EDSADC_CH9_TSTMP.
*/
#define EDSADC_TSTMP9 (EDSADC_CH9_TSTMP)

/** \brief A54, Time-Stamp Counter 9 */
#define EDSADC_CH9_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024A54u)
/** Alias (User Manual Name) for EDSADC_CH9_TSCNT.
* To use register names with standard convension, please use EDSADC_CH9_TSCNT.
*/
#define EDSADC_TSCNT9 (EDSADC_CH9_TSCNT)

/** \brief A70, Auxiliary Filter Configuration Register 9 */
#define EDSADC_CH9_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024A70u)
/** Alias (User Manual Name) for EDSADC_CH9_FCFGA.
* To use register names with standard convension, please use EDSADC_CH9_FCFGA.
*/
#define EDSADC_FCFGA9 (EDSADC_CH9_FCFGA)

/** \brief A78, Boundary Select Register 9 */
#define EDSADC_CH9_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024A78u)
/** Alias (User Manual Name) for EDSADC_CH9_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH9_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL9 (EDSADC_CH9_BOUNDSEL)

/** \brief A80, Result Register 9 Auxiliary */
#define EDSADC_CH9_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024A80u)
/** Alias (User Manual Name) for EDSADC_CH9_RESA.
* To use register names with standard convension, please use EDSADC_CH9_RESA.
*/
#define EDSADC_RESA9 (EDSADC_CH9_RESA)

/** \brief AA0, Carrier Generator Synchronization Reg. 9 */
#define EDSADC_CH9_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF0024AA0u)
/** Alias (User Manual Name) for EDSADC_CH9_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH9_CGSYNC.
*/
#define EDSADC_CGSYNC9 (EDSADC_CH9_CGSYNC)

/** \brief AA8, Rectification Configuration Register 9 */
#define EDSADC_CH9_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF0024AA8u)
/** Alias (User Manual Name) for EDSADC_CH9_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH9_RECTCFG.
*/
#define EDSADC_RECTCFG9 (EDSADC_CH9_RECTCFG)

/** \brief AB0, Common Mode Voltage Register 9 */
#define EDSADC_CH9_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF0024AB0u)
/** Alias (User Manual Name) for EDSADC_CH9_VCM.
* To use register names with standard convension, please use EDSADC_CH9_VCM.
*/
#define EDSADC_VCM9 (EDSADC_CH9_VCM)

/** \brief B00, Modulator Configuration Register 10 */
#define EDSADC_CH10_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024B00u)
/** Alias (User Manual Name) for EDSADC_CH10_MODCFG.
* To use register names with standard convension, please use EDSADC_CH10_MODCFG.
*/
#define EDSADC_MODCFG10 (EDSADC_CH10_MODCFG)

/** \brief B08, Demodulator Input Config. Register 10 */
#define EDSADC_CH10_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024B08u)
/** Alias (User Manual Name) for EDSADC_CH10_DICFG.
* To use register names with standard convension, please use EDSADC_CH10_DICFG.
*/
#define EDSADC_DICFG10 (EDSADC_CH10_DICFG)

/** \brief B10, Filter Configuration Register 10, Main */
#define EDSADC_CH10_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024B10u)
/** Alias (User Manual Name) for EDSADC_CH10_FCFGM.
* To use register names with standard convension, please use EDSADC_CH10_FCFGM.
*/
#define EDSADC_FCFGM10 (EDSADC_CH10_FCFGM)

/** \brief B14, Filter Configuration Register 10, CIC Filter */
#define EDSADC_CH10_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024B14u)
/** Alias (User Manual Name) for EDSADC_CH10_FCFGC.
* To use register names with standard convension, please use EDSADC_CH10_FCFGC.
*/
#define EDSADC_FCFGC10 (EDSADC_CH10_FCFGC)

/** \brief B18, Filter Counter Register 10, CIC Filter */
#define EDSADC_CH10_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024B18u)
/** Alias (User Manual Name) for EDSADC_CH10_FCNTC.
* To use register names with standard convension, please use EDSADC_CH10_FCNTC.
*/
#define EDSADC_FCNTC10 (EDSADC_CH10_FCNTC)

/** \brief B1C, Overshoot Compensation Cfg. Register 10 */
#define EDSADC_CH10_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF0024B1Cu)
/** Alias (User Manual Name) for EDSADC_CH10_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH10_OVSCFG.
*/
#define EDSADC_OVSCFG10 (EDSADC_CH10_OVSCFG)

/** \brief B20, Integration Window Control Register 10 */
#define EDSADC_CH10_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024B20u)
/** Alias (User Manual Name) for EDSADC_CH10_IWCTR.
* To use register names with standard convension, please use EDSADC_CH10_IWCTR.
*/
#define EDSADC_IWCTR10 (EDSADC_CH10_IWCTR)

/** \brief B24, Intermediate Integration Value */
#define EDSADC_CH10_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024B24u)
/** Alias (User Manual Name) for EDSADC_CH10_IIVAL.
* To use register names with standard convension, please use EDSADC_CH10_IIVAL.
*/
#define EDSADC_IIVAL10 (EDSADC_CH10_IIVAL)

/** \brief B28, Integrator Status Register 10 */
#define EDSADC_CH10_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024B28u)
/** Alias (User Manual Name) for EDSADC_CH10_ISTAT.
* To use register names with standard convension, please use EDSADC_CH10_ISTAT.
*/
#define EDSADC_ISTAT10 (EDSADC_CH10_ISTAT)

/** \brief B2C, Result FIFO Control Register 10 */
#define EDSADC_CH10_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF0024B2Cu)
/** Alias (User Manual Name) for EDSADC_CH10_RFC.
* To use register names with standard convension, please use EDSADC_CH10_RFC.
*/
#define EDSADC_RFC10 (EDSADC_CH10_RFC)

/** \brief B30, Result Register 10 Main */
#define EDSADC_CH10_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024B30u)
/** Alias (User Manual Name) for EDSADC_CH10_RESM.
* To use register names with standard convension, please use EDSADC_CH10_RESM.
*/
#define EDSADC_RESM10 (EDSADC_CH10_RESM)

/** \brief B38, Offset Compensation Register 10 */
#define EDSADC_CH10_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024B38u)
/** Alias (User Manual Name) for EDSADC_CH10_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH10_OFFCOMP.
*/
#define EDSADC_OFFCOMP10 (EDSADC_CH10_OFFCOMP)

/** \brief B3C, Gain Calibration Register 10 */
#define EDSADC_CH10_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF0024B3Cu)
/** Alias (User Manual Name) for EDSADC_CH10_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH10_GAINCAL.
*/
#define EDSADC_GAINCAL10 (EDSADC_CH10_GAINCAL)

/** \brief B40, Gain Control Register 10 */
#define EDSADC_CH10_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024B40u)
/** Alias (User Manual Name) for EDSADC_CH10_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH10_GAINCTR.
*/
#define EDSADC_GAINCTR10 (EDSADC_CH10_GAINCTR)

/** \brief B44, Gain Correction Register 10 */
#define EDSADC_CH10_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024B44u)
/** Alias (User Manual Name) for EDSADC_CH10_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH10_GAINCORR.
*/
#define EDSADC_GAINCORR10 (EDSADC_CH10_GAINCORR)

/** \brief B50, Time-Stamp Register 10 */
#define EDSADC_CH10_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024B50u)
/** Alias (User Manual Name) for EDSADC_CH10_TSTMP.
* To use register names with standard convension, please use EDSADC_CH10_TSTMP.
*/
#define EDSADC_TSTMP10 (EDSADC_CH10_TSTMP)

/** \brief B54, Time-Stamp Counter 10 */
#define EDSADC_CH10_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024B54u)
/** Alias (User Manual Name) for EDSADC_CH10_TSCNT.
* To use register names with standard convension, please use EDSADC_CH10_TSCNT.
*/
#define EDSADC_TSCNT10 (EDSADC_CH10_TSCNT)

/** \brief B70, Auxiliary Filter Configuration Register 10 */
#define EDSADC_CH10_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024B70u)
/** Alias (User Manual Name) for EDSADC_CH10_FCFGA.
* To use register names with standard convension, please use EDSADC_CH10_FCFGA.
*/
#define EDSADC_FCFGA10 (EDSADC_CH10_FCFGA)

/** \brief B78, Boundary Select Register 10 */
#define EDSADC_CH10_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024B78u)
/** Alias (User Manual Name) for EDSADC_CH10_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH10_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL10 (EDSADC_CH10_BOUNDSEL)

/** \brief B80, Result Register 10 Auxiliary */
#define EDSADC_CH10_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024B80u)
/** Alias (User Manual Name) for EDSADC_CH10_RESA.
* To use register names with standard convension, please use EDSADC_CH10_RESA.
*/
#define EDSADC_RESA10 (EDSADC_CH10_RESA)

/** \brief BA0, Carrier Generator Synchronization Reg. 10 */
#define EDSADC_CH10_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF0024BA0u)
/** Alias (User Manual Name) for EDSADC_CH10_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH10_CGSYNC.
*/
#define EDSADC_CGSYNC10 (EDSADC_CH10_CGSYNC)

/** \brief BA8, Rectification Configuration Register 10 */
#define EDSADC_CH10_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF0024BA8u)
/** Alias (User Manual Name) for EDSADC_CH10_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH10_RECTCFG.
*/
#define EDSADC_RECTCFG10 (EDSADC_CH10_RECTCFG)

/** \brief BB0, Common Mode Voltage Register 10 */
#define EDSADC_CH10_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF0024BB0u)
/** Alias (User Manual Name) for EDSADC_CH10_VCM.
* To use register names with standard convension, please use EDSADC_CH10_VCM.
*/
#define EDSADC_VCM10 (EDSADC_CH10_VCM)

/** \brief C00, Modulator Configuration Register 11 */
#define EDSADC_CH11_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024C00u)
/** Alias (User Manual Name) for EDSADC_CH11_MODCFG.
* To use register names with standard convension, please use EDSADC_CH11_MODCFG.
*/
#define EDSADC_MODCFG11 (EDSADC_CH11_MODCFG)

/** \brief C08, Demodulator Input Config. Register 11 */
#define EDSADC_CH11_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024C08u)
/** Alias (User Manual Name) for EDSADC_CH11_DICFG.
* To use register names with standard convension, please use EDSADC_CH11_DICFG.
*/
#define EDSADC_DICFG11 (EDSADC_CH11_DICFG)

/** \brief C10, Filter Configuration Register 11, Main */
#define EDSADC_CH11_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024C10u)
/** Alias (User Manual Name) for EDSADC_CH11_FCFGM.
* To use register names with standard convension, please use EDSADC_CH11_FCFGM.
*/
#define EDSADC_FCFGM11 (EDSADC_CH11_FCFGM)

/** \brief C14, Filter Configuration Register 11, CIC Filter */
#define EDSADC_CH11_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024C14u)
/** Alias (User Manual Name) for EDSADC_CH11_FCFGC.
* To use register names with standard convension, please use EDSADC_CH11_FCFGC.
*/
#define EDSADC_FCFGC11 (EDSADC_CH11_FCFGC)

/** \brief C18, Filter Counter Register 11, CIC Filter */
#define EDSADC_CH11_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024C18u)
/** Alias (User Manual Name) for EDSADC_CH11_FCNTC.
* To use register names with standard convension, please use EDSADC_CH11_FCNTC.
*/
#define EDSADC_FCNTC11 (EDSADC_CH11_FCNTC)

/** \brief C1C, Overshoot Compensation Cfg. Register 11 */
#define EDSADC_CH11_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF0024C1Cu)
/** Alias (User Manual Name) for EDSADC_CH11_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH11_OVSCFG.
*/
#define EDSADC_OVSCFG11 (EDSADC_CH11_OVSCFG)

/** \brief C20, Integration Window Control Register 11 */
#define EDSADC_CH11_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024C20u)
/** Alias (User Manual Name) for EDSADC_CH11_IWCTR.
* To use register names with standard convension, please use EDSADC_CH11_IWCTR.
*/
#define EDSADC_IWCTR11 (EDSADC_CH11_IWCTR)

/** \brief C24, Intermediate Integration Value */
#define EDSADC_CH11_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024C24u)
/** Alias (User Manual Name) for EDSADC_CH11_IIVAL.
* To use register names with standard convension, please use EDSADC_CH11_IIVAL.
*/
#define EDSADC_IIVAL11 (EDSADC_CH11_IIVAL)

/** \brief C28, Integrator Status Register 11 */
#define EDSADC_CH11_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024C28u)
/** Alias (User Manual Name) for EDSADC_CH11_ISTAT.
* To use register names with standard convension, please use EDSADC_CH11_ISTAT.
*/
#define EDSADC_ISTAT11 (EDSADC_CH11_ISTAT)

/** \brief C2C, Result FIFO Control Register 11 */
#define EDSADC_CH11_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF0024C2Cu)
/** Alias (User Manual Name) for EDSADC_CH11_RFC.
* To use register names with standard convension, please use EDSADC_CH11_RFC.
*/
#define EDSADC_RFC11 (EDSADC_CH11_RFC)

/** \brief C30, Result Register 11 Main */
#define EDSADC_CH11_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024C30u)
/** Alias (User Manual Name) for EDSADC_CH11_RESM.
* To use register names with standard convension, please use EDSADC_CH11_RESM.
*/
#define EDSADC_RESM11 (EDSADC_CH11_RESM)

/** \brief C38, Offset Compensation Register 11 */
#define EDSADC_CH11_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024C38u)
/** Alias (User Manual Name) for EDSADC_CH11_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH11_OFFCOMP.
*/
#define EDSADC_OFFCOMP11 (EDSADC_CH11_OFFCOMP)

/** \brief C3C, Gain Calibration Register 11 */
#define EDSADC_CH11_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF0024C3Cu)
/** Alias (User Manual Name) for EDSADC_CH11_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH11_GAINCAL.
*/
#define EDSADC_GAINCAL11 (EDSADC_CH11_GAINCAL)

/** \brief C40, Gain Control Register 11 */
#define EDSADC_CH11_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024C40u)
/** Alias (User Manual Name) for EDSADC_CH11_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH11_GAINCTR.
*/
#define EDSADC_GAINCTR11 (EDSADC_CH11_GAINCTR)

/** \brief C44, Gain Correction Register 11 */
#define EDSADC_CH11_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024C44u)
/** Alias (User Manual Name) for EDSADC_CH11_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH11_GAINCORR.
*/
#define EDSADC_GAINCORR11 (EDSADC_CH11_GAINCORR)

/** \brief C50, Time-Stamp Register 11 */
#define EDSADC_CH11_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024C50u)
/** Alias (User Manual Name) for EDSADC_CH11_TSTMP.
* To use register names with standard convension, please use EDSADC_CH11_TSTMP.
*/
#define EDSADC_TSTMP11 (EDSADC_CH11_TSTMP)

/** \brief C54, Time-Stamp Counter 11 */
#define EDSADC_CH11_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024C54u)
/** Alias (User Manual Name) for EDSADC_CH11_TSCNT.
* To use register names with standard convension, please use EDSADC_CH11_TSCNT.
*/
#define EDSADC_TSCNT11 (EDSADC_CH11_TSCNT)

/** \brief C70, Auxiliary Filter Configuration Register 11 */
#define EDSADC_CH11_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024C70u)
/** Alias (User Manual Name) for EDSADC_CH11_FCFGA.
* To use register names with standard convension, please use EDSADC_CH11_FCFGA.
*/
#define EDSADC_FCFGA11 (EDSADC_CH11_FCFGA)

/** \brief C78, Boundary Select Register 11 */
#define EDSADC_CH11_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024C78u)
/** Alias (User Manual Name) for EDSADC_CH11_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH11_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL11 (EDSADC_CH11_BOUNDSEL)

/** \brief C80, Result Register 11 Auxiliary */
#define EDSADC_CH11_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024C80u)
/** Alias (User Manual Name) for EDSADC_CH11_RESA.
* To use register names with standard convension, please use EDSADC_CH11_RESA.
*/
#define EDSADC_RESA11 (EDSADC_CH11_RESA)

/** \brief CA0, Carrier Generator Synchronization Reg. 11 */
#define EDSADC_CH11_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF0024CA0u)
/** Alias (User Manual Name) for EDSADC_CH11_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH11_CGSYNC.
*/
#define EDSADC_CGSYNC11 (EDSADC_CH11_CGSYNC)

/** \brief CA8, Rectification Configuration Register 11 */
#define EDSADC_CH11_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF0024CA8u)
/** Alias (User Manual Name) for EDSADC_CH11_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH11_RECTCFG.
*/
#define EDSADC_RECTCFG11 (EDSADC_CH11_RECTCFG)

/** \brief CB0, Common Mode Voltage Register 11 */
#define EDSADC_CH11_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF0024CB0u)
/** Alias (User Manual Name) for EDSADC_CH11_VCM.
* To use register names with standard convension, please use EDSADC_CH11_VCM.
*/
#define EDSADC_VCM11 (EDSADC_CH11_VCM)

/** \brief D00, Modulator Configuration Register 12 */
#define EDSADC_CH12_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024D00u)
/** Alias (User Manual Name) for EDSADC_CH12_MODCFG.
* To use register names with standard convension, please use EDSADC_CH12_MODCFG.
*/
#define EDSADC_MODCFG12 (EDSADC_CH12_MODCFG)

/** \brief D08, Demodulator Input Config. Register 12 */
#define EDSADC_CH12_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024D08u)
/** Alias (User Manual Name) for EDSADC_CH12_DICFG.
* To use register names with standard convension, please use EDSADC_CH12_DICFG.
*/
#define EDSADC_DICFG12 (EDSADC_CH12_DICFG)

/** \brief D10, Filter Configuration Register 12, Main */
#define EDSADC_CH12_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024D10u)
/** Alias (User Manual Name) for EDSADC_CH12_FCFGM.
* To use register names with standard convension, please use EDSADC_CH12_FCFGM.
*/
#define EDSADC_FCFGM12 (EDSADC_CH12_FCFGM)

/** \brief D14, Filter Configuration Register 12, CIC Filter */
#define EDSADC_CH12_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024D14u)
/** Alias (User Manual Name) for EDSADC_CH12_FCFGC.
* To use register names with standard convension, please use EDSADC_CH12_FCFGC.
*/
#define EDSADC_FCFGC12 (EDSADC_CH12_FCFGC)

/** \brief D18, Filter Counter Register 12, CIC Filter */
#define EDSADC_CH12_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024D18u)
/** Alias (User Manual Name) for EDSADC_CH12_FCNTC.
* To use register names with standard convension, please use EDSADC_CH12_FCNTC.
*/
#define EDSADC_FCNTC12 (EDSADC_CH12_FCNTC)

/** \brief D1C, Overshoot Compensation Cfg. Register 12 */
#define EDSADC_CH12_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF0024D1Cu)
/** Alias (User Manual Name) for EDSADC_CH12_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH12_OVSCFG.
*/
#define EDSADC_OVSCFG12 (EDSADC_CH12_OVSCFG)

/** \brief D20, Integration Window Control Register 12 */
#define EDSADC_CH12_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024D20u)
/** Alias (User Manual Name) for EDSADC_CH12_IWCTR.
* To use register names with standard convension, please use EDSADC_CH12_IWCTR.
*/
#define EDSADC_IWCTR12 (EDSADC_CH12_IWCTR)

/** \brief D24, Intermediate Integration Value */
#define EDSADC_CH12_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024D24u)
/** Alias (User Manual Name) for EDSADC_CH12_IIVAL.
* To use register names with standard convension, please use EDSADC_CH12_IIVAL.
*/
#define EDSADC_IIVAL12 (EDSADC_CH12_IIVAL)

/** \brief D28, Integrator Status Register 12 */
#define EDSADC_CH12_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024D28u)
/** Alias (User Manual Name) for EDSADC_CH12_ISTAT.
* To use register names with standard convension, please use EDSADC_CH12_ISTAT.
*/
#define EDSADC_ISTAT12 (EDSADC_CH12_ISTAT)

/** \brief D2C, Result FIFO Control Register 12 */
#define EDSADC_CH12_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF0024D2Cu)
/** Alias (User Manual Name) for EDSADC_CH12_RFC.
* To use register names with standard convension, please use EDSADC_CH12_RFC.
*/
#define EDSADC_RFC12 (EDSADC_CH12_RFC)

/** \brief D30, Result Register 12 Main */
#define EDSADC_CH12_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024D30u)
/** Alias (User Manual Name) for EDSADC_CH12_RESM.
* To use register names with standard convension, please use EDSADC_CH12_RESM.
*/
#define EDSADC_RESM12 (EDSADC_CH12_RESM)

/** \brief D38, Offset Compensation Register 12 */
#define EDSADC_CH12_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024D38u)
/** Alias (User Manual Name) for EDSADC_CH12_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH12_OFFCOMP.
*/
#define EDSADC_OFFCOMP12 (EDSADC_CH12_OFFCOMP)

/** \brief D3C, Gain Calibration Register 12 */
#define EDSADC_CH12_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF0024D3Cu)
/** Alias (User Manual Name) for EDSADC_CH12_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH12_GAINCAL.
*/
#define EDSADC_GAINCAL12 (EDSADC_CH12_GAINCAL)

/** \brief D40, Gain Control Register 12 */
#define EDSADC_CH12_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024D40u)
/** Alias (User Manual Name) for EDSADC_CH12_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH12_GAINCTR.
*/
#define EDSADC_GAINCTR12 (EDSADC_CH12_GAINCTR)

/** \brief D44, Gain Correction Register 12 */
#define EDSADC_CH12_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024D44u)
/** Alias (User Manual Name) for EDSADC_CH12_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH12_GAINCORR.
*/
#define EDSADC_GAINCORR12 (EDSADC_CH12_GAINCORR)

/** \brief D50, Time-Stamp Register 12 */
#define EDSADC_CH12_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024D50u)
/** Alias (User Manual Name) for EDSADC_CH12_TSTMP.
* To use register names with standard convension, please use EDSADC_CH12_TSTMP.
*/
#define EDSADC_TSTMP12 (EDSADC_CH12_TSTMP)

/** \brief D54, Time-Stamp Counter 12 */
#define EDSADC_CH12_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024D54u)
/** Alias (User Manual Name) for EDSADC_CH12_TSCNT.
* To use register names with standard convension, please use EDSADC_CH12_TSCNT.
*/
#define EDSADC_TSCNT12 (EDSADC_CH12_TSCNT)

/** \brief D70, Auxiliary Filter Configuration Register 12 */
#define EDSADC_CH12_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024D70u)
/** Alias (User Manual Name) for EDSADC_CH12_FCFGA.
* To use register names with standard convension, please use EDSADC_CH12_FCFGA.
*/
#define EDSADC_FCFGA12 (EDSADC_CH12_FCFGA)

/** \brief D78, Boundary Select Register 12 */
#define EDSADC_CH12_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024D78u)
/** Alias (User Manual Name) for EDSADC_CH12_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH12_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL12 (EDSADC_CH12_BOUNDSEL)

/** \brief D80, Result Register 12 Auxiliary */
#define EDSADC_CH12_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024D80u)
/** Alias (User Manual Name) for EDSADC_CH12_RESA.
* To use register names with standard convension, please use EDSADC_CH12_RESA.
*/
#define EDSADC_RESA12 (EDSADC_CH12_RESA)

/** \brief DA0, Carrier Generator Synchronization Reg. 12 */
#define EDSADC_CH12_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF0024DA0u)
/** Alias (User Manual Name) for EDSADC_CH12_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH12_CGSYNC.
*/
#define EDSADC_CGSYNC12 (EDSADC_CH12_CGSYNC)

/** \brief DA8, Rectification Configuration Register 12 */
#define EDSADC_CH12_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF0024DA8u)
/** Alias (User Manual Name) for EDSADC_CH12_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH12_RECTCFG.
*/
#define EDSADC_RECTCFG12 (EDSADC_CH12_RECTCFG)

/** \brief DB0, Common Mode Voltage Register 12 */
#define EDSADC_CH12_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF0024DB0u)
/** Alias (User Manual Name) for EDSADC_CH12_VCM.
* To use register names with standard convension, please use EDSADC_CH12_VCM.
*/
#define EDSADC_VCM12 (EDSADC_CH12_VCM)

/** \brief E00, Modulator Configuration Register 13 */
#define EDSADC_CH13_MODCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_MODCFG*)0xF0024E00u)
/** Alias (User Manual Name) for EDSADC_CH13_MODCFG.
* To use register names with standard convension, please use EDSADC_CH13_MODCFG.
*/
#define EDSADC_MODCFG13 (EDSADC_CH13_MODCFG)

/** \brief E08, Demodulator Input Config. Register 13 */
#define EDSADC_CH13_DICFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_DICFG*)0xF0024E08u)
/** Alias (User Manual Name) for EDSADC_CH13_DICFG.
* To use register names with standard convension, please use EDSADC_CH13_DICFG.
*/
#define EDSADC_DICFG13 (EDSADC_CH13_DICFG)

/** \brief E10, Filter Configuration Register 13, Main */
#define EDSADC_CH13_FCFGM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGM*)0xF0024E10u)
/** Alias (User Manual Name) for EDSADC_CH13_FCFGM.
* To use register names with standard convension, please use EDSADC_CH13_FCFGM.
*/
#define EDSADC_FCFGM13 (EDSADC_CH13_FCFGM)

/** \brief E14, Filter Configuration Register 13, CIC Filter */
#define EDSADC_CH13_FCFGC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGC*)0xF0024E14u)
/** Alias (User Manual Name) for EDSADC_CH13_FCFGC.
* To use register names with standard convension, please use EDSADC_CH13_FCFGC.
*/
#define EDSADC_FCFGC13 (EDSADC_CH13_FCFGC)

/** \brief E18, Filter Counter Register 13, CIC Filter */
#define EDSADC_CH13_FCNTC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCNTC*)0xF0024E18u)
/** Alias (User Manual Name) for EDSADC_CH13_FCNTC.
* To use register names with standard convension, please use EDSADC_CH13_FCNTC.
*/
#define EDSADC_FCNTC13 (EDSADC_CH13_FCNTC)

/** \brief E1C, Overshoot Compensation Cfg. Register 13 */
#define EDSADC_CH13_OVSCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OVSCFG*)0xF0024E1Cu)
/** Alias (User Manual Name) for EDSADC_CH13_OVSCFG.
* To use register names with standard convension, please use EDSADC_CH13_OVSCFG.
*/
#define EDSADC_OVSCFG13 (EDSADC_CH13_OVSCFG)

/** \brief E20, Integration Window Control Register 13 */
#define EDSADC_CH13_IWCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IWCTR*)0xF0024E20u)
/** Alias (User Manual Name) for EDSADC_CH13_IWCTR.
* To use register names with standard convension, please use EDSADC_CH13_IWCTR.
*/
#define EDSADC_IWCTR13 (EDSADC_CH13_IWCTR)

/** \brief E24, Intermediate Integration Value */
#define EDSADC_CH13_IIVAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_IIVAL*)0xF0024E24u)
/** Alias (User Manual Name) for EDSADC_CH13_IIVAL.
* To use register names with standard convension, please use EDSADC_CH13_IIVAL.
*/
#define EDSADC_IIVAL13 (EDSADC_CH13_IIVAL)

/** \brief E28, Integrator Status Register 13 */
#define EDSADC_CH13_ISTAT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_ISTAT*)0xF0024E28u)
/** Alias (User Manual Name) for EDSADC_CH13_ISTAT.
* To use register names with standard convension, please use EDSADC_CH13_ISTAT.
*/
#define EDSADC_ISTAT13 (EDSADC_CH13_ISTAT)

/** \brief E2C, Result FIFO Control Register 13 */
#define EDSADC_CH13_RFC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RFC*)0xF0024E2Cu)
/** Alias (User Manual Name) for EDSADC_CH13_RFC.
* To use register names with standard convension, please use EDSADC_CH13_RFC.
*/
#define EDSADC_RFC13 (EDSADC_CH13_RFC)

/** \brief E30, Result Register 13 Main */
#define EDSADC_CH13_RESM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESM*)0xF0024E30u)
/** Alias (User Manual Name) for EDSADC_CH13_RESM.
* To use register names with standard convension, please use EDSADC_CH13_RESM.
*/
#define EDSADC_RESM13 (EDSADC_CH13_RESM)

/** \brief E38, Offset Compensation Register 13 */
#define EDSADC_CH13_OFFCOMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_OFFCOMP*)0xF0024E38u)
/** Alias (User Manual Name) for EDSADC_CH13_OFFCOMP.
* To use register names with standard convension, please use EDSADC_CH13_OFFCOMP.
*/
#define EDSADC_OFFCOMP13 (EDSADC_CH13_OFFCOMP)

/** \brief E3C, Gain Calibration Register 13 */
#define EDSADC_CH13_GAINCAL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCAL*)0xF0024E3Cu)
/** Alias (User Manual Name) for EDSADC_CH13_GAINCAL.
* To use register names with standard convension, please use EDSADC_CH13_GAINCAL.
*/
#define EDSADC_GAINCAL13 (EDSADC_CH13_GAINCAL)

/** \brief E40, Gain Control Register 13 */
#define EDSADC_CH13_GAINCTR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCTR*)0xF0024E40u)
/** Alias (User Manual Name) for EDSADC_CH13_GAINCTR.
* To use register names with standard convension, please use EDSADC_CH13_GAINCTR.
*/
#define EDSADC_GAINCTR13 (EDSADC_CH13_GAINCTR)

/** \brief E44, Gain Correction Register 13 */
#define EDSADC_CH13_GAINCORR /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_GAINCORR*)0xF0024E44u)
/** Alias (User Manual Name) for EDSADC_CH13_GAINCORR.
* To use register names with standard convension, please use EDSADC_CH13_GAINCORR.
*/
#define EDSADC_GAINCORR13 (EDSADC_CH13_GAINCORR)

/** \brief E50, Time-Stamp Register 13 */
#define EDSADC_CH13_TSTMP /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSTMP*)0xF0024E50u)
/** Alias (User Manual Name) for EDSADC_CH13_TSTMP.
* To use register names with standard convension, please use EDSADC_CH13_TSTMP.
*/
#define EDSADC_TSTMP13 (EDSADC_CH13_TSTMP)

/** \brief E54, Time-Stamp Counter 13 */
#define EDSADC_CH13_TSCNT /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_TSCNT*)0xF0024E54u)
/** Alias (User Manual Name) for EDSADC_CH13_TSCNT.
* To use register names with standard convension, please use EDSADC_CH13_TSCNT.
*/
#define EDSADC_TSCNT13 (EDSADC_CH13_TSCNT)

/** \brief E70, Auxiliary Filter Configuration Register 13 */
#define EDSADC_CH13_FCFGA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_FCFGA*)0xF0024E70u)
/** Alias (User Manual Name) for EDSADC_CH13_FCFGA.
* To use register names with standard convension, please use EDSADC_CH13_FCFGA.
*/
#define EDSADC_FCFGA13 (EDSADC_CH13_FCFGA)

/** \brief E78, Boundary Select Register 13 */
#define EDSADC_CH13_BOUNDSEL /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_BOUNDSEL*)0xF0024E78u)
/** Alias (User Manual Name) for EDSADC_CH13_BOUNDSEL.
* To use register names with standard convension, please use EDSADC_CH13_BOUNDSEL.
*/
#define EDSADC_BOUNDSEL13 (EDSADC_CH13_BOUNDSEL)

/** \brief E80, Result Register 13 Auxiliary */
#define EDSADC_CH13_RESA /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RESA*)0xF0024E80u)
/** Alias (User Manual Name) for EDSADC_CH13_RESA.
* To use register names with standard convension, please use EDSADC_CH13_RESA.
*/
#define EDSADC_RESA13 (EDSADC_CH13_RESA)

/** \brief EA0, Carrier Generator Synchronization Reg. 13 */
#define EDSADC_CH13_CGSYNC /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_CGSYNC*)0xF0024EA0u)
/** Alias (User Manual Name) for EDSADC_CH13_CGSYNC.
* To use register names with standard convension, please use EDSADC_CH13_CGSYNC.
*/
#define EDSADC_CGSYNC13 (EDSADC_CH13_CGSYNC)

/** \brief EA8, Rectification Configuration Register 13 */
#define EDSADC_CH13_RECTCFG /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_RECTCFG*)0xF0024EA8u)
/** Alias (User Manual Name) for EDSADC_CH13_RECTCFG.
* To use register names with standard convension, please use EDSADC_CH13_RECTCFG.
*/
#define EDSADC_RECTCFG13 (EDSADC_CH13_RECTCFG)

/** \brief EB0, Common Mode Voltage Register 13 */
#define EDSADC_CH13_VCM /*lint --e(923, 9078)*/ (*(volatile Ifx_EDSADC_CH_VCM*)0xF0024EB0u)
/** Alias (User Manual Name) for EDSADC_CH13_VCM.
* To use register names with standard convension, please use EDSADC_CH13_VCM.
*/
#define EDSADC_VCM13 (EDSADC_CH13_VCM)


/** \}  */

/******************************************************************************/

/******************************************************************************/

#endif /* IFXEDSADC_REG_H */
