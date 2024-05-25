/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                 This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                 Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                 All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  LICENSE
 *  -------------------------------------------------------------------------------------------------------------------
 *            Module: Os
 *           Program: MSR_Vector_SLP4
 *          Customer: Aptiv (China) Technology Company Ltd.
 *       Expiry Date: Not restricted
 *  Ordered Derivat.: Aurix 2G/TC397 B-Step
 *    License Scope : The usage is restricted to CBD1900078_D01
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *              File: Os_Link_Core0.lsl
 *   Generation Time: 2024-01-08 16:27:32
 *           Project: Bsw_Project - Version 1.0
 *          Delivery: CBD1900078_D01
 *      Tool Version: DaVinci Configurator (beta) 5.18.42 SP2
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 ! BETA VERSION                                                                                                       !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 ! This version of DaVinci Configurator Pro and/or the related Basic Software Package is BETA software.               !
 ! BETA Software is basically operable, but not sufficiently tested, verified and/or qualified for use in series      !
 ! production and/or in vehicles operating on public or non-public roads.                                             !
 ! In particular, without limitation, BETA Software may cause unpredictable ECU behavior, may not provide all         !
 ! functions necessary for use in series production and/or may not comply with quality requirements which are         !
 ! necessary according to the state of the art. BETA Software must not be used in series production.                  !
 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
**********************************************************************************************************************/

/**********************************************************************************************************************
 *  CODE SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_INTVEC_CODE )
if (exists(".text.OS_INTVEC_CORE0_CODE"))
{
  group OS_INTVEC_CORE0_CODE_GROUP(align=32)
  {
    select ".text.OS_INTVEC_CORE0_CODE";
  }
  "_OS_INTVEC_CORE0_CODE_START" = "_lc_gb_OS_INTVEC_CORE0_CODE_GROUP";
  "_OS_INTVEC_CORE0_CODE_END" = "_lc_ge_OS_INTVEC_CORE0_CODE_GROUP";
}
else
{
  "_OS_INTVEC_CORE0_CODE_START" = 0;
  "_OS_INTVEC_CORE0_CODE_END" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CODE )
if (exists(".text.OS_EXCVEC_CORE0_CODE"))
{
  group OS_EXCVEC_CORE0_CODE_GROUP(align=32)
  {
    select ".text.OS_EXCVEC_CORE0_CODE";
  }
  "_OS_EXCVEC_CORE0_CODE_START" = "_lc_gb_OS_EXCVEC_CORE0_CODE_GROUP";
  "_OS_EXCVEC_CORE0_CODE_END" = "_lc_ge_OS_EXCVEC_CORE0_CODE_GROUP";
}
else
{
  "_OS_EXCVEC_CORE0_CODE_START" = 0;
  "_OS_EXCVEC_CORE0_CODE_END" = 0;
}
#endif

#if defined ( OS_LINK_CALLOUT_CODE )
if (exists(".text.OS_ADC0SR0_ISR_CODE"))
{
  group OS_ADC0SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_ADC0SR0_ISR_CODE";
  }
  "_OS_ADC0SR0_ISR_CODE_START" = "_lc_gb_OS_ADC0SR0_ISR_CODE_GROUP";
  "_OS_ADC0SR0_ISR_CODE_END" = "_lc_ge_OS_ADC0SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_ADC0SR0_ISR_CODE_START" = 0;
  "_OS_ADC0SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_ADC1SR0_ISR_CODE"))
{
  group OS_ADC1SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_ADC1SR0_ISR_CODE";
  }
  "_OS_ADC1SR0_ISR_CODE_START" = "_lc_gb_OS_ADC1SR0_ISR_CODE_GROUP";
  "_OS_ADC1SR0_ISR_CODE_END" = "_lc_ge_OS_ADC1SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_ADC1SR0_ISR_CODE_START" = 0;
  "_OS_ADC1SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_ADC2SR0_ISR_CODE"))
{
  group OS_ADC2SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_ADC2SR0_ISR_CODE";
  }
  "_OS_ADC2SR0_ISR_CODE_START" = "_lc_gb_OS_ADC2SR0_ISR_CODE_GROUP";
  "_OS_ADC2SR0_ISR_CODE_END" = "_lc_ge_OS_ADC2SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_ADC2SR0_ISR_CODE_START" = 0;
  "_OS_ADC2SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_ADC3SR0_ISR_CODE"))
{
  group OS_ADC3SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_ADC3SR0_ISR_CODE";
  }
  "_OS_ADC3SR0_ISR_CODE_START" = "_lc_gb_OS_ADC3SR0_ISR_CODE_GROUP";
  "_OS_ADC3SR0_ISR_CODE_END" = "_lc_ge_OS_ADC3SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_ADC3SR0_ISR_CODE_START" = 0;
  "_OS_ADC3SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_ADC8SR0_ISR_CODE"))
{
  group OS_ADC8SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_ADC8SR0_ISR_CODE";
  }
  "_OS_ADC8SR0_ISR_CODE_START" = "_lc_gb_OS_ADC8SR0_ISR_CODE_GROUP";
  "_OS_ADC8SR0_ISR_CODE_END" = "_lc_ge_OS_ADC8SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_ADC8SR0_ISR_CODE_START" = 0;
  "_OS_ADC8SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_APP_Task_Core0_CODE"))
{
  group OS_APP_Task_Core0_CODE_GROUP(align=8)
  {
    select ".text.OS_APP_Task_Core0_CODE";
  }
  "_OS_APP_Task_Core0_CODE_START" = "_lc_gb_OS_APP_Task_Core0_CODE_GROUP";
  "_OS_APP_Task_Core0_CODE_END" = "_lc_ge_OS_APP_Task_Core0_CODE_GROUP";
}
else
{
  "_OS_APP_Task_Core0_CODE_START" = 0;
  "_OS_APP_Task_Core0_CODE_END" = 0;
}
if (exists(".text.OS_CanIsr_4_CODE"))
{
  group OS_CanIsr_4_CODE_GROUP(align=8)
  {
    select ".text.OS_CanIsr_4_CODE";
  }
  "_OS_CanIsr_4_CODE_START" = "_lc_gb_OS_CanIsr_4_CODE_GROUP";
  "_OS_CanIsr_4_CODE_END" = "_lc_ge_OS_CanIsr_4_CODE_GROUP";
}
else
{
  "_OS_CanIsr_4_CODE_START" = 0;
  "_OS_CanIsr_4_CODE_END" = 0;
}
if (exists(".text.OS_CanIsr_5_CODE"))
{
  group OS_CanIsr_5_CODE_GROUP(align=8)
  {
    select ".text.OS_CanIsr_5_CODE";
  }
  "_OS_CanIsr_5_CODE_START" = "_lc_gb_OS_CanIsr_5_CODE_GROUP";
  "_OS_CanIsr_5_CODE_END" = "_lc_ge_OS_CanIsr_5_CODE_GROUP";
}
else
{
  "_OS_CanIsr_5_CODE_START" = 0;
  "_OS_CanIsr_5_CODE_END" = 0;
}
if (exists(".text.OS_Core_OsTask_CDD_CODE"))
{
  group OS_Core_OsTask_CDD_CODE_GROUP(align=8)
  {
    select ".text.OS_Core_OsTask_CDD_CODE";
  }
  "_OS_Core_OsTask_CDD_CODE_START" = "_lc_gb_OS_Core_OsTask_CDD_CODE_GROUP";
  "_OS_Core_OsTask_CDD_CODE_END" = "_lc_ge_OS_Core_OsTask_CDD_CODE_GROUP";
}
else
{
  "_OS_Core_OsTask_CDD_CODE_START" = 0;
  "_OS_Core_OsTask_CDD_CODE_END" = 0;
}
if (exists(".text.OS_Core_OsTask_IOHW_CODE"))
{
  group OS_Core_OsTask_IOHW_CODE_GROUP(align=8)
  {
    select ".text.OS_Core_OsTask_IOHW_CODE";
  }
  "_OS_Core_OsTask_IOHW_CODE_START" = "_lc_gb_OS_Core_OsTask_IOHW_CODE_GROUP";
  "_OS_Core_OsTask_IOHW_CODE_END" = "_lc_ge_OS_Core_OsTask_IOHW_CODE_GROUP";
}
else
{
  "_OS_Core_OsTask_IOHW_CODE_START" = 0;
  "_OS_Core_OsTask_IOHW_CODE_END" = 0;
}
if (exists(".text.OS_Core_OsTask_PSI5_CODE"))
{
  group OS_Core_OsTask_PSI5_CODE_GROUP(align=8)
  {
    select ".text.OS_Core_OsTask_PSI5_CODE";
  }
  "_OS_Core_OsTask_PSI5_CODE_START" = "_lc_gb_OS_Core_OsTask_PSI5_CODE_GROUP";
  "_OS_Core_OsTask_PSI5_CODE_END" = "_lc_ge_OS_Core_OsTask_PSI5_CODE_GROUP";
}
else
{
  "_OS_Core_OsTask_PSI5_CODE_START" = 0;
  "_OS_Core_OsTask_PSI5_CODE_END" = 0;
}
if (exists(".text.OS_Core_OsTask_PT2000_CODE"))
{
  group OS_Core_OsTask_PT2000_CODE_GROUP(align=8)
  {
    select ".text.OS_Core_OsTask_PT2000_CODE";
  }
  "_OS_Core_OsTask_PT2000_CODE_START" = "_lc_gb_OS_Core_OsTask_PT2000_CODE_GROUP";
  "_OS_Core_OsTask_PT2000_CODE_END" = "_lc_ge_OS_Core_OsTask_PT2000_CODE_GROUP";
}
else
{
  "_OS_Core_OsTask_PT2000_CODE_START" = 0;
  "_OS_Core_OsTask_PT2000_CODE_END" = 0;
}
if (exists(".text.OS_DMACH0SR_ISR_CODE"))
{
  group OS_DMACH0SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH0SR_ISR_CODE";
  }
  "_OS_DMACH0SR_ISR_CODE_START" = "_lc_gb_OS_DMACH0SR_ISR_CODE_GROUP";
  "_OS_DMACH0SR_ISR_CODE_END" = "_lc_ge_OS_DMACH0SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH0SR_ISR_CODE_START" = 0;
  "_OS_DMACH0SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH3SR_ISR_CODE"))
{
  group OS_DMACH3SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH3SR_ISR_CODE";
  }
  "_OS_DMACH3SR_ISR_CODE_START" = "_lc_gb_OS_DMACH3SR_ISR_CODE_GROUP";
  "_OS_DMACH3SR_ISR_CODE_END" = "_lc_ge_OS_DMACH3SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH3SR_ISR_CODE_START" = 0;
  "_OS_DMACH3SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH4SR_ISR_CODE"))
{
  group OS_DMACH4SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH4SR_ISR_CODE";
  }
  "_OS_DMACH4SR_ISR_CODE_START" = "_lc_gb_OS_DMACH4SR_ISR_CODE_GROUP";
  "_OS_DMACH4SR_ISR_CODE_END" = "_lc_ge_OS_DMACH4SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH4SR_ISR_CODE_START" = 0;
  "_OS_DMACH4SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH5SR_ISR_CODE"))
{
  group OS_DMACH5SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH5SR_ISR_CODE";
  }
  "_OS_DMACH5SR_ISR_CODE_START" = "_lc_gb_OS_DMACH5SR_ISR_CODE_GROUP";
  "_OS_DMACH5SR_ISR_CODE_END" = "_lc_ge_OS_DMACH5SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH5SR_ISR_CODE_START" = 0;
  "_OS_DMACH5SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH6SR_ISR_CODE"))
{
  group OS_DMACH6SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH6SR_ISR_CODE";
  }
  "_OS_DMACH6SR_ISR_CODE_START" = "_lc_gb_OS_DMACH6SR_ISR_CODE_GROUP";
  "_OS_DMACH6SR_ISR_CODE_END" = "_lc_ge_OS_DMACH6SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH6SR_ISR_CODE_START" = 0;
  "_OS_DMACH6SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH7SR_ISR_CODE"))
{
  group OS_DMACH7SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH7SR_ISR_CODE";
  }
  "_OS_DMACH7SR_ISR_CODE_START" = "_lc_gb_OS_DMACH7SR_ISR_CODE_GROUP";
  "_OS_DMACH7SR_ISR_CODE_END" = "_lc_ge_OS_DMACH7SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH7SR_ISR_CODE_START" = 0;
  "_OS_DMACH7SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH8SR_ISR_CODE"))
{
  group OS_DMACH8SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH8SR_ISR_CODE";
  }
  "_OS_DMACH8SR_ISR_CODE_START" = "_lc_gb_OS_DMACH8SR_ISR_CODE_GROUP";
  "_OS_DMACH8SR_ISR_CODE_END" = "_lc_ge_OS_DMACH8SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH8SR_ISR_CODE_START" = 0;
  "_OS_DMACH8SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMACH9SR_ISR_CODE"))
{
  group OS_DMACH9SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMACH9SR_ISR_CODE";
  }
  "_OS_DMACH9SR_ISR_CODE_START" = "_lc_gb_OS_DMACH9SR_ISR_CODE_GROUP";
  "_OS_DMACH9SR_ISR_CODE_END" = "_lc_ge_OS_DMACH9SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMACH9SR_ISR_CODE_START" = 0;
  "_OS_DMACH9SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_DMAERR0SR_ISR_CODE"))
{
  group OS_DMAERR0SR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_DMAERR0SR_ISR_CODE";
  }
  "_OS_DMAERR0SR_ISR_CODE_START" = "_lc_gb_OS_DMAERR0SR_ISR_CODE_GROUP";
  "_OS_DMAERR0SR_ISR_CODE_END" = "_lc_ge_OS_DMAERR0SR_ISR_CODE_GROUP";
}
else
{
  "_OS_DMAERR0SR_ISR_CODE_START" = 0;
  "_OS_DMAERR0SR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMATOM0SR0_ISR_CODE"))
{
  group OS_GTMATOM0SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMATOM0SR0_ISR_CODE";
  }
  "_OS_GTMATOM0SR0_ISR_CODE_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_CODE_GROUP";
  "_OS_GTMATOM0SR0_ISR_CODE_END" = "_lc_ge_OS_GTMATOM0SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMATOM0SR0_ISR_CODE_START" = 0;
  "_OS_GTMATOM0SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMATOM1SR0_ISR_CODE"))
{
  group OS_GTMATOM1SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMATOM1SR0_ISR_CODE";
  }
  "_OS_GTMATOM1SR0_ISR_CODE_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_CODE_GROUP";
  "_OS_GTMATOM1SR0_ISR_CODE_END" = "_lc_ge_OS_GTMATOM1SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMATOM1SR0_ISR_CODE_START" = 0;
  "_OS_GTMATOM1SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMATOM2SR0_ISR_CODE"))
{
  group OS_GTMATOM2SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMATOM2SR0_ISR_CODE";
  }
  "_OS_GTMATOM2SR0_ISR_CODE_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_CODE_GROUP";
  "_OS_GTMATOM2SR0_ISR_CODE_END" = "_lc_ge_OS_GTMATOM2SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMATOM2SR0_ISR_CODE_START" = 0;
  "_OS_GTMATOM2SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMATOM4SR0_ISR_CODE"))
{
  group OS_GTMATOM4SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMATOM4SR0_ISR_CODE";
  }
  "_OS_GTMATOM4SR0_ISR_CODE_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_CODE_GROUP";
  "_OS_GTMATOM4SR0_ISR_CODE_END" = "_lc_ge_OS_GTMATOM4SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMATOM4SR0_ISR_CODE_START" = 0;
  "_OS_GTMATOM4SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMTIM2SR3_ISR_CODE"))
{
  group OS_GTMTIM2SR3_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMTIM2SR3_ISR_CODE";
  }
  "_OS_GTMTIM2SR3_ISR_CODE_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_CODE_GROUP";
  "_OS_GTMTIM2SR3_ISR_CODE_END" = "_lc_ge_OS_GTMTIM2SR3_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMTIM2SR3_ISR_CODE_START" = 0;
  "_OS_GTMTIM2SR3_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMTIM2SR5_ISR_CODE"))
{
  group OS_GTMTIM2SR5_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMTIM2SR5_ISR_CODE";
  }
  "_OS_GTMTIM2SR5_ISR_CODE_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_CODE_GROUP";
  "_OS_GTMTIM2SR5_ISR_CODE_END" = "_lc_ge_OS_GTMTIM2SR5_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMTIM2SR5_ISR_CODE_START" = 0;
  "_OS_GTMTIM2SR5_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMTOM0SR0_ISR_CODE"))
{
  group OS_GTMTOM0SR0_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMTOM0SR0_ISR_CODE";
  }
  "_OS_GTMTOM0SR0_ISR_CODE_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_CODE_GROUP";
  "_OS_GTMTOM0SR0_ISR_CODE_END" = "_lc_ge_OS_GTMTOM0SR0_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMTOM0SR0_ISR_CODE_START" = 0;
  "_OS_GTMTOM0SR0_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMTOM0SR1_ISR_CODE"))
{
  group OS_GTMTOM0SR1_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMTOM0SR1_ISR_CODE";
  }
  "_OS_GTMTOM0SR1_ISR_CODE_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_CODE_GROUP";
  "_OS_GTMTOM0SR1_ISR_CODE_END" = "_lc_ge_OS_GTMTOM0SR1_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMTOM0SR1_ISR_CODE_START" = 0;
  "_OS_GTMTOM0SR1_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMTOM0SR2_ISR_CODE"))
{
  group OS_GTMTOM0SR2_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMTOM0SR2_ISR_CODE";
  }
  "_OS_GTMTOM0SR2_ISR_CODE_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_CODE_GROUP";
  "_OS_GTMTOM0SR2_ISR_CODE_END" = "_lc_ge_OS_GTMTOM0SR2_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMTOM0SR2_ISR_CODE_START" = 0;
  "_OS_GTMTOM0SR2_ISR_CODE_END" = 0;
}
if (exists(".text.OS_GTMTOM0SR3_ISR_CODE"))
{
  group OS_GTMTOM0SR3_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_GTMTOM0SR3_ISR_CODE";
  }
  "_OS_GTMTOM0SR3_ISR_CODE_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_CODE_GROUP";
  "_OS_GTMTOM0SR3_ISR_CODE_END" = "_lc_ge_OS_GTMTOM0SR3_ISR_CODE_GROUP";
}
else
{
  "_OS_GTMTOM0SR3_ISR_CODE_START" = 0;
  "_OS_GTMTOM0SR3_ISR_CODE_END" = 0;
}
if (exists(".text.OS_Init_Core0_CODE"))
{
  group OS_Init_Core0_CODE_GROUP(align=8)
  {
    select ".text.OS_Init_Core0_CODE";
  }
  "_OS_Init_Core0_CODE_START" = "_lc_gb_OS_Init_Core0_CODE_GROUP";
  "_OS_Init_Core0_CODE_END" = "_lc_ge_OS_Init_Core0_CODE_GROUP";
}
else
{
  "_OS_Init_Core0_CODE_START" = 0;
  "_OS_Init_Core0_CODE_END" = 0;
}
if (exists(".text.OS_QSPI0ERR_ISR_CODE"))
{
  group OS_QSPI0ERR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI0ERR_ISR_CODE";
  }
  "_OS_QSPI0ERR_ISR_CODE_START" = "_lc_gb_OS_QSPI0ERR_ISR_CODE_GROUP";
  "_OS_QSPI0ERR_ISR_CODE_END" = "_lc_ge_OS_QSPI0ERR_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI0ERR_ISR_CODE_START" = 0;
  "_OS_QSPI0ERR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI0PT_ISR_CODE"))
{
  group OS_QSPI0PT_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI0PT_ISR_CODE";
  }
  "_OS_QSPI0PT_ISR_CODE_START" = "_lc_gb_OS_QSPI0PT_ISR_CODE_GROUP";
  "_OS_QSPI0PT_ISR_CODE_END" = "_lc_ge_OS_QSPI0PT_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI0PT_ISR_CODE_START" = 0;
  "_OS_QSPI0PT_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI1ERR_ISR_CODE"))
{
  group OS_QSPI1ERR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI1ERR_ISR_CODE";
  }
  "_OS_QSPI1ERR_ISR_CODE_START" = "_lc_gb_OS_QSPI1ERR_ISR_CODE_GROUP";
  "_OS_QSPI1ERR_ISR_CODE_END" = "_lc_ge_OS_QSPI1ERR_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI1ERR_ISR_CODE_START" = 0;
  "_OS_QSPI1ERR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI1PT_ISR_CODE"))
{
  group OS_QSPI1PT_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI1PT_ISR_CODE";
  }
  "_OS_QSPI1PT_ISR_CODE_START" = "_lc_gb_OS_QSPI1PT_ISR_CODE_GROUP";
  "_OS_QSPI1PT_ISR_CODE_END" = "_lc_ge_OS_QSPI1PT_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI1PT_ISR_CODE_START" = 0;
  "_OS_QSPI1PT_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI2ERR_ISR_CODE"))
{
  group OS_QSPI2ERR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI2ERR_ISR_CODE";
  }
  "_OS_QSPI2ERR_ISR_CODE_START" = "_lc_gb_OS_QSPI2ERR_ISR_CODE_GROUP";
  "_OS_QSPI2ERR_ISR_CODE_END" = "_lc_ge_OS_QSPI2ERR_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI2ERR_ISR_CODE_START" = 0;
  "_OS_QSPI2ERR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI2PT_ISR_CODE"))
{
  group OS_QSPI2PT_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI2PT_ISR_CODE";
  }
  "_OS_QSPI2PT_ISR_CODE_START" = "_lc_gb_OS_QSPI2PT_ISR_CODE_GROUP";
  "_OS_QSPI2PT_ISR_CODE_END" = "_lc_ge_OS_QSPI2PT_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI2PT_ISR_CODE_START" = 0;
  "_OS_QSPI2PT_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI3ERR_ISR_CODE"))
{
  group OS_QSPI3ERR_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI3ERR_ISR_CODE";
  }
  "_OS_QSPI3ERR_ISR_CODE_START" = "_lc_gb_OS_QSPI3ERR_ISR_CODE_GROUP";
  "_OS_QSPI3ERR_ISR_CODE_END" = "_lc_ge_OS_QSPI3ERR_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI3ERR_ISR_CODE_START" = 0;
  "_OS_QSPI3ERR_ISR_CODE_END" = 0;
}
if (exists(".text.OS_QSPI3PT_ISR_CODE"))
{
  group OS_QSPI3PT_ISR_CODE_GROUP(align=8)
  {
    select ".text.OS_QSPI3PT_ISR_CODE";
  }
  "_OS_QSPI3PT_ISR_CODE_START" = "_lc_gb_OS_QSPI3PT_ISR_CODE_GROUP";
  "_OS_QSPI3PT_ISR_CODE_END" = "_lc_ge_OS_QSPI3PT_ISR_CODE_GROUP";
}
else
{
  "_OS_QSPI3PT_ISR_CODE_START" = 0;
  "_OS_QSPI3PT_ISR_CODE_END" = 0;
}
if (exists(".text.OS_SchM_Core0_CODE"))
{
  group OS_SchM_Core0_CODE_GROUP(align=8)
  {
    select ".text.OS_SchM_Core0_CODE";
  }
  "_OS_SchM_Core0_CODE_START" = "_lc_gb_OS_SchM_Core0_CODE_GROUP";
  "_OS_SchM_Core0_CODE_END" = "_lc_ge_OS_SchM_Core0_CODE_GROUP";
}
else
{
  "_OS_SchM_Core0_CODE_START" = 0;
  "_OS_SchM_Core0_CODE_END" = 0;
}
#endif

#ifdef OS_LINK_INTVEC_CODE
# undef OS_LINK_INTVEC_CODE
#endif

#ifdef OS_LINK_EXCVEC_CODE
# undef OS_LINK_EXCVEC_CODE
#endif

#ifdef OS_LINK_CALLOUT_CODE
# undef OS_LINK_CALLOUT_CODE
#endif


/**********************************************************************************************************************
 *  CONST SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_FAR )
if (exists(".rodata.OS_CORE0_CONST"))
{
  group OS_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CORE0_CONST";
  }
  "_OS_CORE0_CONST_START" = "_lc_gb_OS_CORE0_CONST_GROUP";
  "_OS_CORE0_CONST_END" = "_lc_ge_OS_CORE0_CONST_GROUP";
}
else
{
  "_OS_CORE0_CONST_START" = 0;
  "_OS_CORE0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_KERNEL ) || defined ( OS_LINK_CONST_KERNEL_NEAR )
if (exists(".zrodata.OS_CORE0_CONST_FAST"))
{
  group OS_CORE0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CORE0_CONST_FAST";
  }
  "_OS_CORE0_CONST_FAST_START" = "_lc_gb_OS_CORE0_CONST_FAST_GROUP";
  "_OS_CORE0_CONST_FAST_END" = "_lc_ge_OS_CORE0_CONST_FAST_GROUP";
}
else
{
  "_OS_CORE0_CONST_FAST_START" = 0;
  "_OS_CORE0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_INTVEC_CONST )
if (exists(".rodata.OS_INTVEC_CORE0_CONST"))
{
  group OS_INTVEC_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_INTVEC_CORE0_CONST";
  }
  "_OS_INTVEC_CORE0_CONST_START" = "_lc_gb_OS_INTVEC_CORE0_CONST_GROUP";
  "_OS_INTVEC_CORE0_CONST_END" = "_lc_ge_OS_INTVEC_CORE0_CONST_GROUP";
}
else
{
  "_OS_INTVEC_CORE0_CONST_START" = 0;
  "_OS_INTVEC_CORE0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_EXCVEC_CONST )
if (exists(".rodata.OS_EXCVEC_CORE0_CONST"))
{
  group OS_EXCVEC_CORE0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_EXCVEC_CORE0_CONST";
  }
  "_OS_EXCVEC_CORE0_CONST_START" = "_lc_gb_OS_EXCVEC_CORE0_CONST_GROUP";
  "_OS_EXCVEC_CORE0_CONST_END" = "_lc_ge_OS_EXCVEC_CORE0_CONST_GROUP";
}
else
{
  "_OS_EXCVEC_CORE0_CONST_START" = 0;
  "_OS_EXCVEC_CORE0_CONST_END" = 0;
}
#endif


#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR )
if (exists(".rodata.OS_SystemApplication_OsCore0_CONST"))
{
  group OS_SystemApplication_OsCore0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_SystemApplication_OsCore0_CONST";
  }
  "_OS_SystemApplication_OsCore0_CONST_START" = "_lc_gb_OS_SystemApplication_OsCore0_CONST_GROUP";
  "_OS_SystemApplication_OsCore0_CONST_END" = "_lc_ge_OS_SystemApplication_OsCore0_CONST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_CONST_START" = 0;
  "_OS_SystemApplication_OsCore0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR )
if (exists(".zrodata.OS_SystemApplication_OsCore0_CONST_FAST"))
{
  group OS_SystemApplication_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_SystemApplication_OsCore0_CONST_FAST";
  }
  "_OS_SystemApplication_OsCore0_CONST_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore0_CONST_FAST_GROUP";
  "_OS_SystemApplication_OsCore0_CONST_FAST_END" = "_lc_ge_OS_SystemApplication_OsCore0_CONST_FAST_GROUP";
}
else
{
  "_OS_SystemApplication_OsCore0_CONST_FAST_START" = 0;
  "_OS_SystemApplication_OsCore0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_APP ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT )
















#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
# undef OS_LINK_CONST_APP_SYSTEMAPPLICATION_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APP_TASK_CORE0_FAR )
if (exists(".rodata.OS_APP_Task_Core0_CONST"))
{
  group OS_APP_Task_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_APP_Task_Core0_CONST";
  }
  "_OS_APP_Task_Core0_CONST_START" = "_lc_gb_OS_APP_Task_Core0_CONST_GROUP";
  "_OS_APP_Task_Core0_CONST_END" = "_lc_ge_OS_APP_Task_Core0_CONST_GROUP";
}
else
{
  "_OS_APP_Task_Core0_CONST_START" = 0;
  "_OS_APP_Task_Core0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APP_TASK_CORE0_NEAR )
if (exists(".zrodata.OS_APP_Task_Core0_CONST_FAST"))
{
  group OS_APP_Task_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_APP_Task_Core0_CONST_FAST";
  }
  "_OS_APP_Task_Core0_CONST_FAST_START" = "_lc_gb_OS_APP_Task_Core0_CONST_FAST_GROUP";
  "_OS_APP_Task_Core0_CONST_FAST_END" = "_lc_ge_OS_APP_Task_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_APP_Task_Core0_CONST_FAST_START" = 0;
  "_OS_APP_Task_Core0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_CONST_TASK_APP_TASK_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_APP_TASK_CORE0
# undef OS_LINK_CONST_TASK_APP_TASK_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_APP_TASK_CORE0_FAR
# undef OS_LINK_CONST_TASK_APP_TASK_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_APP_TASK_CORE0_NEAR
# undef OS_LINK_CONST_TASK_APP_TASK_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_APP_TASK_CORE0_INIT
# undef OS_LINK_CONST_TASK_APP_TASK_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_CDD_FAR )
if (exists(".rodata.OS_Core_OsTask_CDD_CONST"))
{
  group OS_Core_OsTask_CDD_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Core_OsTask_CDD_CONST";
  }
  "_OS_Core_OsTask_CDD_CONST_START" = "_lc_gb_OS_Core_OsTask_CDD_CONST_GROUP";
  "_OS_Core_OsTask_CDD_CONST_END" = "_lc_ge_OS_Core_OsTask_CDD_CONST_GROUP";
}
else
{
  "_OS_Core_OsTask_CDD_CONST_START" = 0;
  "_OS_Core_OsTask_CDD_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_CDD_NEAR )
if (exists(".zrodata.OS_Core_OsTask_CDD_CONST_FAST"))
{
  group OS_Core_OsTask_CDD_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Core_OsTask_CDD_CONST_FAST";
  }
  "_OS_Core_OsTask_CDD_CONST_FAST_START" = "_lc_gb_OS_Core_OsTask_CDD_CONST_FAST_GROUP";
  "_OS_Core_OsTask_CDD_CONST_FAST_END" = "_lc_ge_OS_Core_OsTask_CDD_CONST_FAST_GROUP";
}
else
{
  "_OS_Core_OsTask_CDD_CONST_FAST_START" = 0;
  "_OS_Core_OsTask_CDD_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_CDD_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_CDD
# undef OS_LINK_CONST_TASK_CORE_OSTASK_CDD
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_CDD_FAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_CDD_FAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_CDD_NEAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_CDD_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_CDD_INIT
# undef OS_LINK_CONST_TASK_CORE_OSTASK_CDD_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_FAR )
if (exists(".rodata.OS_Core_OsTask_IOHW_CONST"))
{
  group OS_Core_OsTask_IOHW_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Core_OsTask_IOHW_CONST";
  }
  "_OS_Core_OsTask_IOHW_CONST_START" = "_lc_gb_OS_Core_OsTask_IOHW_CONST_GROUP";
  "_OS_Core_OsTask_IOHW_CONST_END" = "_lc_ge_OS_Core_OsTask_IOHW_CONST_GROUP";
}
else
{
  "_OS_Core_OsTask_IOHW_CONST_START" = 0;
  "_OS_Core_OsTask_IOHW_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_NEAR )
if (exists(".zrodata.OS_Core_OsTask_IOHW_CONST_FAST"))
{
  group OS_Core_OsTask_IOHW_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Core_OsTask_IOHW_CONST_FAST";
  }
  "_OS_Core_OsTask_IOHW_CONST_FAST_START" = "_lc_gb_OS_Core_OsTask_IOHW_CONST_FAST_GROUP";
  "_OS_Core_OsTask_IOHW_CONST_FAST_END" = "_lc_ge_OS_Core_OsTask_IOHW_CONST_FAST_GROUP";
}
else
{
  "_OS_Core_OsTask_IOHW_CONST_FAST_START" = 0;
  "_OS_Core_OsTask_IOHW_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW
# undef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_FAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_FAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_NEAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_INIT
# undef OS_LINK_CONST_TASK_CORE_OSTASK_IOHW_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_FAR )
if (exists(".rodata.OS_Core_OsTask_PSI5_CONST"))
{
  group OS_Core_OsTask_PSI5_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Core_OsTask_PSI5_CONST";
  }
  "_OS_Core_OsTask_PSI5_CONST_START" = "_lc_gb_OS_Core_OsTask_PSI5_CONST_GROUP";
  "_OS_Core_OsTask_PSI5_CONST_END" = "_lc_ge_OS_Core_OsTask_PSI5_CONST_GROUP";
}
else
{
  "_OS_Core_OsTask_PSI5_CONST_START" = 0;
  "_OS_Core_OsTask_PSI5_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_NEAR )
if (exists(".zrodata.OS_Core_OsTask_PSI5_CONST_FAST"))
{
  group OS_Core_OsTask_PSI5_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Core_OsTask_PSI5_CONST_FAST";
  }
  "_OS_Core_OsTask_PSI5_CONST_FAST_START" = "_lc_gb_OS_Core_OsTask_PSI5_CONST_FAST_GROUP";
  "_OS_Core_OsTask_PSI5_CONST_FAST_END" = "_lc_ge_OS_Core_OsTask_PSI5_CONST_FAST_GROUP";
}
else
{
  "_OS_Core_OsTask_PSI5_CONST_FAST_START" = 0;
  "_OS_Core_OsTask_PSI5_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_FAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_FAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_NEAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_INIT
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PSI5_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_FAR )
if (exists(".rodata.OS_Core_OsTask_PT2000_CONST"))
{
  group OS_Core_OsTask_PT2000_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Core_OsTask_PT2000_CONST";
  }
  "_OS_Core_OsTask_PT2000_CONST_START" = "_lc_gb_OS_Core_OsTask_PT2000_CONST_GROUP";
  "_OS_Core_OsTask_PT2000_CONST_END" = "_lc_ge_OS_Core_OsTask_PT2000_CONST_GROUP";
}
else
{
  "_OS_Core_OsTask_PT2000_CONST_START" = 0;
  "_OS_Core_OsTask_PT2000_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_NEAR )
if (exists(".zrodata.OS_Core_OsTask_PT2000_CONST_FAST"))
{
  group OS_Core_OsTask_PT2000_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Core_OsTask_PT2000_CONST_FAST";
  }
  "_OS_Core_OsTask_PT2000_CONST_FAST_START" = "_lc_gb_OS_Core_OsTask_PT2000_CONST_FAST_GROUP";
  "_OS_Core_OsTask_PT2000_CONST_FAST_END" = "_lc_ge_OS_Core_OsTask_PT2000_CONST_FAST_GROUP";
}
else
{
  "_OS_Core_OsTask_PT2000_CONST_FAST_START" = 0;
  "_OS_Core_OsTask_PT2000_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_FAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_FAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_NEAR
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_INIT
# undef OS_LINK_CONST_TASK_CORE_OSTASK_PT2000_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR )
if (exists(".rodata.OS_IdleTask_OsCore0_CONST"))
{
  group OS_IdleTask_OsCore0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_IdleTask_OsCore0_CONST";
  }
  "_OS_IdleTask_OsCore0_CONST_START" = "_lc_gb_OS_IdleTask_OsCore0_CONST_GROUP";
  "_OS_IdleTask_OsCore0_CONST_END" = "_lc_ge_OS_IdleTask_OsCore0_CONST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_CONST_START" = 0;
  "_OS_IdleTask_OsCore0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR )
if (exists(".zrodata.OS_IdleTask_OsCore0_CONST_FAST"))
{
  group OS_IdleTask_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_IdleTask_OsCore0_CONST_FAST";
  }
  "_OS_IdleTask_OsCore0_CONST_FAST_START" = "_lc_gb_OS_IdleTask_OsCore0_CONST_FAST_GROUP";
  "_OS_IdleTask_OsCore0_CONST_FAST_END" = "_lc_ge_OS_IdleTask_OsCore0_CONST_FAST_GROUP";
}
else
{
  "_OS_IdleTask_OsCore0_CONST_FAST_START" = 0;
  "_OS_IdleTask_OsCore0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
# undef OS_LINK_CONST_TASK_IDLETASK_OSCORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_INIT_CORE0 ) || defined ( OS_LINK_CONST_TASK_INIT_CORE0_FAR )
if (exists(".rodata.OS_Init_Core0_CONST"))
{
  group OS_Init_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_Init_Core0_CONST";
  }
  "_OS_Init_Core0_CONST_START" = "_lc_gb_OS_Init_Core0_CONST_GROUP";
  "_OS_Init_Core0_CONST_END" = "_lc_ge_OS_Init_Core0_CONST_GROUP";
}
else
{
  "_OS_Init_Core0_CONST_START" = 0;
  "_OS_Init_Core0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_INIT_CORE0 ) || defined ( OS_LINK_CONST_TASK_INIT_CORE0_NEAR )
if (exists(".zrodata.OS_Init_Core0_CONST_FAST"))
{
  group OS_Init_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_Init_Core0_CONST_FAST";
  }
  "_OS_Init_Core0_CONST_FAST_START" = "_lc_gb_OS_Init_Core0_CONST_FAST_GROUP";
  "_OS_Init_Core0_CONST_FAST_END" = "_lc_ge_OS_Init_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_Init_Core0_CONST_FAST_START" = 0;
  "_OS_Init_Core0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_INIT_CORE0 ) || defined ( OS_LINK_CONST_TASK_INIT_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_INIT_CORE0
# undef OS_LINK_CONST_TASK_INIT_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_INIT_CORE0_FAR
# undef OS_LINK_CONST_TASK_INIT_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_INIT_CORE0_NEAR
# undef OS_LINK_CONST_TASK_INIT_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_INIT_CORE0_INIT
# undef OS_LINK_CONST_TASK_INIT_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_SCHM_CORE0 ) || defined ( OS_LINK_CONST_TASK_SCHM_CORE0_FAR )
if (exists(".rodata.OS_SchM_Core0_CONST"))
{
  group OS_SchM_Core0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_SchM_Core0_CONST";
  }
  "_OS_SchM_Core0_CONST_START" = "_lc_gb_OS_SchM_Core0_CONST_GROUP";
  "_OS_SchM_Core0_CONST_END" = "_lc_ge_OS_SchM_Core0_CONST_GROUP";
}
else
{
  "_OS_SchM_Core0_CONST_START" = 0;
  "_OS_SchM_Core0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_SCHM_CORE0 ) || defined ( OS_LINK_CONST_TASK_SCHM_CORE0_NEAR )
if (exists(".zrodata.OS_SchM_Core0_CONST_FAST"))
{
  group OS_SchM_Core0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_SchM_Core0_CONST_FAST";
  }
  "_OS_SchM_Core0_CONST_FAST_START" = "_lc_gb_OS_SchM_Core0_CONST_FAST_GROUP";
  "_OS_SchM_Core0_CONST_FAST_END" = "_lc_ge_OS_SchM_Core0_CONST_FAST_GROUP";
}
else
{
  "_OS_SchM_Core0_CONST_FAST_START" = 0;
  "_OS_SchM_Core0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_TASK ) || defined ( OS_LINK_CONST_TASK_SCHM_CORE0 ) || defined ( OS_LINK_CONST_TASK_SCHM_CORE0_INIT )













#endif

#ifdef OS_LINK_CONST_TASK_SCHM_CORE0
# undef OS_LINK_CONST_TASK_SCHM_CORE0
#endif

#ifdef OS_LINK_CONST_TASK_SCHM_CORE0_FAR
# undef OS_LINK_CONST_TASK_SCHM_CORE0_FAR
#endif

#ifdef OS_LINK_CONST_TASK_SCHM_CORE0_NEAR
# undef OS_LINK_CONST_TASK_SCHM_CORE0_NEAR
#endif

#ifdef OS_LINK_CONST_TASK_SCHM_CORE0_INIT
# undef OS_LINK_CONST_TASK_SCHM_CORE0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0SR0_ISR_FAR )
if (exists(".rodata.OS_ADC0SR0_ISR_CONST"))
{
  group OS_ADC0SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_ADC0SR0_ISR_CONST";
  }
  "_OS_ADC0SR0_ISR_CONST_START" = "_lc_gb_OS_ADC0SR0_ISR_CONST_GROUP";
  "_OS_ADC0SR0_ISR_CONST_END" = "_lc_ge_OS_ADC0SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_ADC0SR0_ISR_CONST_START" = 0;
  "_OS_ADC0SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0SR0_ISR_NEAR )
if (exists(".zrodata.OS_ADC0SR0_ISR_CONST_FAST"))
{
  group OS_ADC0SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_ADC0SR0_ISR_CONST_FAST";
  }
  "_OS_ADC0SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_ADC0SR0_ISR_CONST_FAST_GROUP";
  "_OS_ADC0SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_ADC0SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_ADC0SR0_ISR_CONST_FAST_START" = 0;
  "_OS_ADC0SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC0SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_ADC0SR0_ISR
# undef OS_LINK_CONST_ISR_ADC0SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC0SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC0SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC0SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC0SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC0SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC0SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1SR0_ISR_FAR )
if (exists(".rodata.OS_ADC1SR0_ISR_CONST"))
{
  group OS_ADC1SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_ADC1SR0_ISR_CONST";
  }
  "_OS_ADC1SR0_ISR_CONST_START" = "_lc_gb_OS_ADC1SR0_ISR_CONST_GROUP";
  "_OS_ADC1SR0_ISR_CONST_END" = "_lc_ge_OS_ADC1SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_ADC1SR0_ISR_CONST_START" = 0;
  "_OS_ADC1SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1SR0_ISR_NEAR )
if (exists(".zrodata.OS_ADC1SR0_ISR_CONST_FAST"))
{
  group OS_ADC1SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_ADC1SR0_ISR_CONST_FAST";
  }
  "_OS_ADC1SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_ADC1SR0_ISR_CONST_FAST_GROUP";
  "_OS_ADC1SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_ADC1SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_ADC1SR0_ISR_CONST_FAST_START" = 0;
  "_OS_ADC1SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC1SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_ADC1SR0_ISR
# undef OS_LINK_CONST_ISR_ADC1SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC1SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC1SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC1SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC1SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC1SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC1SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC2SR0_ISR_FAR )
if (exists(".rodata.OS_ADC2SR0_ISR_CONST"))
{
  group OS_ADC2SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_ADC2SR0_ISR_CONST";
  }
  "_OS_ADC2SR0_ISR_CONST_START" = "_lc_gb_OS_ADC2SR0_ISR_CONST_GROUP";
  "_OS_ADC2SR0_ISR_CONST_END" = "_lc_ge_OS_ADC2SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_ADC2SR0_ISR_CONST_START" = 0;
  "_OS_ADC2SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC2SR0_ISR_NEAR )
if (exists(".zrodata.OS_ADC2SR0_ISR_CONST_FAST"))
{
  group OS_ADC2SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_ADC2SR0_ISR_CONST_FAST";
  }
  "_OS_ADC2SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_ADC2SR0_ISR_CONST_FAST_GROUP";
  "_OS_ADC2SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_ADC2SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_ADC2SR0_ISR_CONST_FAST_START" = 0;
  "_OS_ADC2SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC2SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_ADC2SR0_ISR
# undef OS_LINK_CONST_ISR_ADC2SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC2SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC2SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC2SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC2SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC2SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC2SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC3SR0_ISR_FAR )
if (exists(".rodata.OS_ADC3SR0_ISR_CONST"))
{
  group OS_ADC3SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_ADC3SR0_ISR_CONST";
  }
  "_OS_ADC3SR0_ISR_CONST_START" = "_lc_gb_OS_ADC3SR0_ISR_CONST_GROUP";
  "_OS_ADC3SR0_ISR_CONST_END" = "_lc_ge_OS_ADC3SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_ADC3SR0_ISR_CONST_START" = 0;
  "_OS_ADC3SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC3SR0_ISR_NEAR )
if (exists(".zrodata.OS_ADC3SR0_ISR_CONST_FAST"))
{
  group OS_ADC3SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_ADC3SR0_ISR_CONST_FAST";
  }
  "_OS_ADC3SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_ADC3SR0_ISR_CONST_FAST_GROUP";
  "_OS_ADC3SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_ADC3SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_ADC3SR0_ISR_CONST_FAST_START" = 0;
  "_OS_ADC3SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC3SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_ADC3SR0_ISR
# undef OS_LINK_CONST_ISR_ADC3SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC3SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC3SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC3SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC3SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC3SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC3SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC8SR0_ISR_FAR )
if (exists(".rodata.OS_ADC8SR0_ISR_CONST"))
{
  group OS_ADC8SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_ADC8SR0_ISR_CONST";
  }
  "_OS_ADC8SR0_ISR_CONST_START" = "_lc_gb_OS_ADC8SR0_ISR_CONST_GROUP";
  "_OS_ADC8SR0_ISR_CONST_END" = "_lc_ge_OS_ADC8SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_ADC8SR0_ISR_CONST_START" = 0;
  "_OS_ADC8SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC8SR0_ISR_NEAR )
if (exists(".zrodata.OS_ADC8SR0_ISR_CONST_FAST"))
{
  group OS_ADC8SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_ADC8SR0_ISR_CONST_FAST";
  }
  "_OS_ADC8SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_ADC8SR0_ISR_CONST_FAST_GROUP";
  "_OS_ADC8SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_ADC8SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_ADC8SR0_ISR_CONST_FAST_START" = 0;
  "_OS_ADC8SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_CONST_ISR_ADC8SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_ADC8SR0_ISR
# undef OS_LINK_CONST_ISR_ADC8SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_ADC8SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_ADC8SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC8SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_ADC8SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_ADC8SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_ADC8SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_4 ) || defined ( OS_LINK_CONST_ISR_CANISR_4_FAR )
if (exists(".rodata.OS_CanIsr_4_CONST"))
{
  group OS_CanIsr_4_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CanIsr_4_CONST";
  }
  "_OS_CanIsr_4_CONST_START" = "_lc_gb_OS_CanIsr_4_CONST_GROUP";
  "_OS_CanIsr_4_CONST_END" = "_lc_ge_OS_CanIsr_4_CONST_GROUP";
}
else
{
  "_OS_CanIsr_4_CONST_START" = 0;
  "_OS_CanIsr_4_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_4 ) || defined ( OS_LINK_CONST_ISR_CANISR_4_NEAR )
if (exists(".zrodata.OS_CanIsr_4_CONST_FAST"))
{
  group OS_CanIsr_4_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CanIsr_4_CONST_FAST";
  }
  "_OS_CanIsr_4_CONST_FAST_START" = "_lc_gb_OS_CanIsr_4_CONST_FAST_GROUP";
  "_OS_CanIsr_4_CONST_FAST_END" = "_lc_ge_OS_CanIsr_4_CONST_FAST_GROUP";
}
else
{
  "_OS_CanIsr_4_CONST_FAST_START" = 0;
  "_OS_CanIsr_4_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_4 ) || defined ( OS_LINK_CONST_ISR_CANISR_4_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_CANISR_4
# undef OS_LINK_CONST_ISR_CANISR_4
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_4_FAR
# undef OS_LINK_CONST_ISR_CANISR_4_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_4_NEAR
# undef OS_LINK_CONST_ISR_CANISR_4_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_4_INIT
# undef OS_LINK_CONST_ISR_CANISR_4_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_5 ) || defined ( OS_LINK_CONST_ISR_CANISR_5_FAR )
if (exists(".rodata.OS_CanIsr_5_CONST"))
{
  group OS_CanIsr_5_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CanIsr_5_CONST";
  }
  "_OS_CanIsr_5_CONST_START" = "_lc_gb_OS_CanIsr_5_CONST_GROUP";
  "_OS_CanIsr_5_CONST_END" = "_lc_ge_OS_CanIsr_5_CONST_GROUP";
}
else
{
  "_OS_CanIsr_5_CONST_START" = 0;
  "_OS_CanIsr_5_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_5 ) || defined ( OS_LINK_CONST_ISR_CANISR_5_NEAR )
if (exists(".zrodata.OS_CanIsr_5_CONST_FAST"))
{
  group OS_CanIsr_5_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CanIsr_5_CONST_FAST";
  }
  "_OS_CanIsr_5_CONST_FAST_START" = "_lc_gb_OS_CanIsr_5_CONST_FAST_GROUP";
  "_OS_CanIsr_5_CONST_FAST_END" = "_lc_ge_OS_CanIsr_5_CONST_FAST_GROUP";
}
else
{
  "_OS_CanIsr_5_CONST_FAST_START" = 0;
  "_OS_CanIsr_5_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_CANISR_5 ) || defined ( OS_LINK_CONST_ISR_CANISR_5_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_CANISR_5
# undef OS_LINK_CONST_ISR_CANISR_5
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_5_FAR
# undef OS_LINK_CONST_ISR_CANISR_5_FAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_5_NEAR
# undef OS_LINK_CONST_ISR_CANISR_5_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_CANISR_5_INIT
# undef OS_LINK_CONST_ISR_CANISR_5_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_FAR )
if (exists(".rodata.OS_CounterIsr_SystemTimer0_CONST"))
{
  group OS_CounterIsr_SystemTimer0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_CounterIsr_SystemTimer0_CONST";
  }
  "_OS_CounterIsr_SystemTimer0_CONST_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_CONST_GROUP";
  "_OS_CounterIsr_SystemTimer0_CONST_END" = "_lc_ge_OS_CounterIsr_SystemTimer0_CONST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer0_CONST_START" = 0;
  "_OS_CounterIsr_SystemTimer0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_NEAR )
if (exists(".zrodata.OS_CounterIsr_SystemTimer0_CONST_FAST"))
{
  group OS_CounterIsr_SystemTimer0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_CounterIsr_SystemTimer0_CONST_FAST";
  }
  "_OS_CounterIsr_SystemTimer0_CONST_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_CONST_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer0_CONST_FAST_END" = "_lc_ge_OS_CounterIsr_SystemTimer0_CONST_FAST_GROUP";
}
else
{
  "_OS_CounterIsr_SystemTimer0_CONST_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_FAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_FAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_NEAR
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_INIT
# undef OS_LINK_CONST_ISR_COUNTERISR_SYSTEMTIMER0_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH0SR_ISR_FAR )
if (exists(".rodata.OS_DMACH0SR_ISR_CONST"))
{
  group OS_DMACH0SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH0SR_ISR_CONST";
  }
  "_OS_DMACH0SR_ISR_CONST_START" = "_lc_gb_OS_DMACH0SR_ISR_CONST_GROUP";
  "_OS_DMACH0SR_ISR_CONST_END" = "_lc_ge_OS_DMACH0SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH0SR_ISR_CONST_START" = 0;
  "_OS_DMACH0SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH0SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH0SR_ISR_CONST_FAST"))
{
  group OS_DMACH0SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH0SR_ISR_CONST_FAST";
  }
  "_OS_DMACH0SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH0SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH0SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH0SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH0SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH0SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH0SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH0SR_ISR
# undef OS_LINK_CONST_ISR_DMACH0SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH0SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH0SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH0SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH0SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH0SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH0SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH3SR_ISR_FAR )
if (exists(".rodata.OS_DMACH3SR_ISR_CONST"))
{
  group OS_DMACH3SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH3SR_ISR_CONST";
  }
  "_OS_DMACH3SR_ISR_CONST_START" = "_lc_gb_OS_DMACH3SR_ISR_CONST_GROUP";
  "_OS_DMACH3SR_ISR_CONST_END" = "_lc_ge_OS_DMACH3SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH3SR_ISR_CONST_START" = 0;
  "_OS_DMACH3SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH3SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH3SR_ISR_CONST_FAST"))
{
  group OS_DMACH3SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH3SR_ISR_CONST_FAST";
  }
  "_OS_DMACH3SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH3SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH3SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH3SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH3SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH3SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH3SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH3SR_ISR
# undef OS_LINK_CONST_ISR_DMACH3SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH3SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH3SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH3SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH3SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH3SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH3SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH4SR_ISR_FAR )
if (exists(".rodata.OS_DMACH4SR_ISR_CONST"))
{
  group OS_DMACH4SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH4SR_ISR_CONST";
  }
  "_OS_DMACH4SR_ISR_CONST_START" = "_lc_gb_OS_DMACH4SR_ISR_CONST_GROUP";
  "_OS_DMACH4SR_ISR_CONST_END" = "_lc_ge_OS_DMACH4SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH4SR_ISR_CONST_START" = 0;
  "_OS_DMACH4SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH4SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH4SR_ISR_CONST_FAST"))
{
  group OS_DMACH4SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH4SR_ISR_CONST_FAST";
  }
  "_OS_DMACH4SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH4SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH4SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH4SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH4SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH4SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH4SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH4SR_ISR
# undef OS_LINK_CONST_ISR_DMACH4SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH4SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH4SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH4SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH4SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH4SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH4SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH5SR_ISR_FAR )
if (exists(".rodata.OS_DMACH5SR_ISR_CONST"))
{
  group OS_DMACH5SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH5SR_ISR_CONST";
  }
  "_OS_DMACH5SR_ISR_CONST_START" = "_lc_gb_OS_DMACH5SR_ISR_CONST_GROUP";
  "_OS_DMACH5SR_ISR_CONST_END" = "_lc_ge_OS_DMACH5SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH5SR_ISR_CONST_START" = 0;
  "_OS_DMACH5SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH5SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH5SR_ISR_CONST_FAST"))
{
  group OS_DMACH5SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH5SR_ISR_CONST_FAST";
  }
  "_OS_DMACH5SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH5SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH5SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH5SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH5SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH5SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH5SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH5SR_ISR
# undef OS_LINK_CONST_ISR_DMACH5SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH5SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH5SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH5SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH5SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH5SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH5SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH6SR_ISR_FAR )
if (exists(".rodata.OS_DMACH6SR_ISR_CONST"))
{
  group OS_DMACH6SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH6SR_ISR_CONST";
  }
  "_OS_DMACH6SR_ISR_CONST_START" = "_lc_gb_OS_DMACH6SR_ISR_CONST_GROUP";
  "_OS_DMACH6SR_ISR_CONST_END" = "_lc_ge_OS_DMACH6SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH6SR_ISR_CONST_START" = 0;
  "_OS_DMACH6SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH6SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH6SR_ISR_CONST_FAST"))
{
  group OS_DMACH6SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH6SR_ISR_CONST_FAST";
  }
  "_OS_DMACH6SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH6SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH6SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH6SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH6SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH6SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH6SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH6SR_ISR
# undef OS_LINK_CONST_ISR_DMACH6SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH6SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH6SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH6SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH6SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH6SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH6SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH7SR_ISR_FAR )
if (exists(".rodata.OS_DMACH7SR_ISR_CONST"))
{
  group OS_DMACH7SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH7SR_ISR_CONST";
  }
  "_OS_DMACH7SR_ISR_CONST_START" = "_lc_gb_OS_DMACH7SR_ISR_CONST_GROUP";
  "_OS_DMACH7SR_ISR_CONST_END" = "_lc_ge_OS_DMACH7SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH7SR_ISR_CONST_START" = 0;
  "_OS_DMACH7SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH7SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH7SR_ISR_CONST_FAST"))
{
  group OS_DMACH7SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH7SR_ISR_CONST_FAST";
  }
  "_OS_DMACH7SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH7SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH7SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH7SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH7SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH7SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH7SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH7SR_ISR
# undef OS_LINK_CONST_ISR_DMACH7SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH7SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH7SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH7SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH7SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH7SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH7SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH8SR_ISR_FAR )
if (exists(".rodata.OS_DMACH8SR_ISR_CONST"))
{
  group OS_DMACH8SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH8SR_ISR_CONST";
  }
  "_OS_DMACH8SR_ISR_CONST_START" = "_lc_gb_OS_DMACH8SR_ISR_CONST_GROUP";
  "_OS_DMACH8SR_ISR_CONST_END" = "_lc_ge_OS_DMACH8SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH8SR_ISR_CONST_START" = 0;
  "_OS_DMACH8SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH8SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH8SR_ISR_CONST_FAST"))
{
  group OS_DMACH8SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH8SR_ISR_CONST_FAST";
  }
  "_OS_DMACH8SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH8SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH8SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH8SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH8SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH8SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH8SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH8SR_ISR
# undef OS_LINK_CONST_ISR_DMACH8SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH8SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH8SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH8SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH8SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH8SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH8SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH9SR_ISR_FAR )
if (exists(".rodata.OS_DMACH9SR_ISR_CONST"))
{
  group OS_DMACH9SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMACH9SR_ISR_CONST";
  }
  "_OS_DMACH9SR_ISR_CONST_START" = "_lc_gb_OS_DMACH9SR_ISR_CONST_GROUP";
  "_OS_DMACH9SR_ISR_CONST_END" = "_lc_ge_OS_DMACH9SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMACH9SR_ISR_CONST_START" = 0;
  "_OS_DMACH9SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH9SR_ISR_NEAR )
if (exists(".zrodata.OS_DMACH9SR_ISR_CONST_FAST"))
{
  group OS_DMACH9SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMACH9SR_ISR_CONST_FAST";
  }
  "_OS_DMACH9SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMACH9SR_ISR_CONST_FAST_GROUP";
  "_OS_DMACH9SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMACH9SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMACH9SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMACH9SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMACH9SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMACH9SR_ISR
# undef OS_LINK_CONST_ISR_DMACH9SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH9SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMACH9SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH9SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMACH9SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMACH9SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMACH9SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMAERR0SR_ISR_FAR )
if (exists(".rodata.OS_DMAERR0SR_ISR_CONST"))
{
  group OS_DMAERR0SR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_DMAERR0SR_ISR_CONST";
  }
  "_OS_DMAERR0SR_ISR_CONST_START" = "_lc_gb_OS_DMAERR0SR_ISR_CONST_GROUP";
  "_OS_DMAERR0SR_ISR_CONST_END" = "_lc_ge_OS_DMAERR0SR_ISR_CONST_GROUP";
}
else
{
  "_OS_DMAERR0SR_ISR_CONST_START" = 0;
  "_OS_DMAERR0SR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMAERR0SR_ISR_NEAR )
if (exists(".zrodata.OS_DMAERR0SR_ISR_CONST_FAST"))
{
  group OS_DMAERR0SR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_DMAERR0SR_ISR_CONST_FAST";
  }
  "_OS_DMAERR0SR_ISR_CONST_FAST_START" = "_lc_gb_OS_DMAERR0SR_ISR_CONST_FAST_GROUP";
  "_OS_DMAERR0SR_ISR_CONST_FAST_END" = "_lc_ge_OS_DMAERR0SR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_DMAERR0SR_ISR_CONST_FAST_START" = 0;
  "_OS_DMAERR0SR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_CONST_ISR_DMAERR0SR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_DMAERR0SR_ISR
# undef OS_LINK_CONST_ISR_DMAERR0SR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_DMAERR0SR_ISR_FAR
# undef OS_LINK_CONST_ISR_DMAERR0SR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_DMAERR0SR_ISR_NEAR
# undef OS_LINK_CONST_ISR_DMAERR0SR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_DMAERR0SR_ISR_INIT
# undef OS_LINK_CONST_ISR_DMAERR0SR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_FAR )
if (exists(".rodata.OS_GTMATOM0SR0_ISR_CONST"))
{
  group OS_GTMATOM0SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMATOM0SR0_ISR_CONST";
  }
  "_OS_GTMATOM0SR0_ISR_CONST_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_CONST_GROUP";
  "_OS_GTMATOM0SR0_ISR_CONST_END" = "_lc_ge_OS_GTMATOM0SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMATOM0SR0_ISR_CONST_START" = 0;
  "_OS_GTMATOM0SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_NEAR )
if (exists(".zrodata.OS_GTMATOM0SR0_ISR_CONST_FAST"))
{
  group OS_GTMATOM0SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMATOM0SR0_ISR_CONST_FAST";
  }
  "_OS_GTMATOM0SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_CONST_FAST_GROUP";
  "_OS_GTMATOM0SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMATOM0SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMATOM0SR0_ISR_CONST_FAST_START" = 0;
  "_OS_GTMATOM0SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR
# undef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMATOM0SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_FAR )
if (exists(".rodata.OS_GTMATOM1SR0_ISR_CONST"))
{
  group OS_GTMATOM1SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMATOM1SR0_ISR_CONST";
  }
  "_OS_GTMATOM1SR0_ISR_CONST_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_CONST_GROUP";
  "_OS_GTMATOM1SR0_ISR_CONST_END" = "_lc_ge_OS_GTMATOM1SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMATOM1SR0_ISR_CONST_START" = 0;
  "_OS_GTMATOM1SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_NEAR )
if (exists(".zrodata.OS_GTMATOM1SR0_ISR_CONST_FAST"))
{
  group OS_GTMATOM1SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMATOM1SR0_ISR_CONST_FAST";
  }
  "_OS_GTMATOM1SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_CONST_FAST_GROUP";
  "_OS_GTMATOM1SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMATOM1SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMATOM1SR0_ISR_CONST_FAST_START" = 0;
  "_OS_GTMATOM1SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR
# undef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMATOM1SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_FAR )
if (exists(".rodata.OS_GTMATOM2SR0_ISR_CONST"))
{
  group OS_GTMATOM2SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMATOM2SR0_ISR_CONST";
  }
  "_OS_GTMATOM2SR0_ISR_CONST_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_CONST_GROUP";
  "_OS_GTMATOM2SR0_ISR_CONST_END" = "_lc_ge_OS_GTMATOM2SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMATOM2SR0_ISR_CONST_START" = 0;
  "_OS_GTMATOM2SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_NEAR )
if (exists(".zrodata.OS_GTMATOM2SR0_ISR_CONST_FAST"))
{
  group OS_GTMATOM2SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMATOM2SR0_ISR_CONST_FAST";
  }
  "_OS_GTMATOM2SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_CONST_FAST_GROUP";
  "_OS_GTMATOM2SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMATOM2SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMATOM2SR0_ISR_CONST_FAST_START" = 0;
  "_OS_GTMATOM2SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR
# undef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMATOM2SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_FAR )
if (exists(".rodata.OS_GTMATOM4SR0_ISR_CONST"))
{
  group OS_GTMATOM4SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMATOM4SR0_ISR_CONST";
  }
  "_OS_GTMATOM4SR0_ISR_CONST_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_CONST_GROUP";
  "_OS_GTMATOM4SR0_ISR_CONST_END" = "_lc_ge_OS_GTMATOM4SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMATOM4SR0_ISR_CONST_START" = 0;
  "_OS_GTMATOM4SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_NEAR )
if (exists(".zrodata.OS_GTMATOM4SR0_ISR_CONST_FAST"))
{
  group OS_GTMATOM4SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMATOM4SR0_ISR_CONST_FAST";
  }
  "_OS_GTMATOM4SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_CONST_FAST_GROUP";
  "_OS_GTMATOM4SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMATOM4SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMATOM4SR0_ISR_CONST_FAST_START" = 0;
  "_OS_GTMATOM4SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR
# undef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMATOM4SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_FAR )
if (exists(".rodata.OS_GTMTIM2SR3_ISR_CONST"))
{
  group OS_GTMTIM2SR3_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMTIM2SR3_ISR_CONST";
  }
  "_OS_GTMTIM2SR3_ISR_CONST_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_CONST_GROUP";
  "_OS_GTMTIM2SR3_ISR_CONST_END" = "_lc_ge_OS_GTMTIM2SR3_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMTIM2SR3_ISR_CONST_START" = 0;
  "_OS_GTMTIM2SR3_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_NEAR )
if (exists(".zrodata.OS_GTMTIM2SR3_ISR_CONST_FAST"))
{
  group OS_GTMTIM2SR3_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMTIM2SR3_ISR_CONST_FAST";
  }
  "_OS_GTMTIM2SR3_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_CONST_FAST_GROUP";
  "_OS_GTMTIM2SR3_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMTIM2SR3_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMTIM2SR3_ISR_CONST_FAST_START" = 0;
  "_OS_GTMTIM2SR3_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR
# undef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMTIM2SR3_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_FAR )
if (exists(".rodata.OS_GTMTIM2SR5_ISR_CONST"))
{
  group OS_GTMTIM2SR5_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMTIM2SR5_ISR_CONST";
  }
  "_OS_GTMTIM2SR5_ISR_CONST_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_CONST_GROUP";
  "_OS_GTMTIM2SR5_ISR_CONST_END" = "_lc_ge_OS_GTMTIM2SR5_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMTIM2SR5_ISR_CONST_START" = 0;
  "_OS_GTMTIM2SR5_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_NEAR )
if (exists(".zrodata.OS_GTMTIM2SR5_ISR_CONST_FAST"))
{
  group OS_GTMTIM2SR5_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMTIM2SR5_ISR_CONST_FAST";
  }
  "_OS_GTMTIM2SR5_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_CONST_FAST_GROUP";
  "_OS_GTMTIM2SR5_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMTIM2SR5_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMTIM2SR5_ISR_CONST_FAST_START" = 0;
  "_OS_GTMTIM2SR5_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR
# undef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMTIM2SR5_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_FAR )
if (exists(".rodata.OS_GTMTOM0SR0_ISR_CONST"))
{
  group OS_GTMTOM0SR0_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMTOM0SR0_ISR_CONST";
  }
  "_OS_GTMTOM0SR0_ISR_CONST_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_CONST_GROUP";
  "_OS_GTMTOM0SR0_ISR_CONST_END" = "_lc_ge_OS_GTMTOM0SR0_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMTOM0SR0_ISR_CONST_START" = 0;
  "_OS_GTMTOM0SR0_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_NEAR )
if (exists(".zrodata.OS_GTMTOM0SR0_ISR_CONST_FAST"))
{
  group OS_GTMTOM0SR0_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMTOM0SR0_ISR_CONST_FAST";
  }
  "_OS_GTMTOM0SR0_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_CONST_FAST_GROUP";
  "_OS_GTMTOM0SR0_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMTOM0SR0_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMTOM0SR0_ISR_CONST_FAST_START" = 0;
  "_OS_GTMTOM0SR0_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR
# undef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMTOM0SR0_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_FAR )
if (exists(".rodata.OS_GTMTOM0SR1_ISR_CONST"))
{
  group OS_GTMTOM0SR1_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMTOM0SR1_ISR_CONST";
  }
  "_OS_GTMTOM0SR1_ISR_CONST_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_CONST_GROUP";
  "_OS_GTMTOM0SR1_ISR_CONST_END" = "_lc_ge_OS_GTMTOM0SR1_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMTOM0SR1_ISR_CONST_START" = 0;
  "_OS_GTMTOM0SR1_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_NEAR )
if (exists(".zrodata.OS_GTMTOM0SR1_ISR_CONST_FAST"))
{
  group OS_GTMTOM0SR1_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMTOM0SR1_ISR_CONST_FAST";
  }
  "_OS_GTMTOM0SR1_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_CONST_FAST_GROUP";
  "_OS_GTMTOM0SR1_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMTOM0SR1_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMTOM0SR1_ISR_CONST_FAST_START" = 0;
  "_OS_GTMTOM0SR1_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR
# undef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMTOM0SR1_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_FAR )
if (exists(".rodata.OS_GTMTOM0SR2_ISR_CONST"))
{
  group OS_GTMTOM0SR2_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMTOM0SR2_ISR_CONST";
  }
  "_OS_GTMTOM0SR2_ISR_CONST_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_CONST_GROUP";
  "_OS_GTMTOM0SR2_ISR_CONST_END" = "_lc_ge_OS_GTMTOM0SR2_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMTOM0SR2_ISR_CONST_START" = 0;
  "_OS_GTMTOM0SR2_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_NEAR )
if (exists(".zrodata.OS_GTMTOM0SR2_ISR_CONST_FAST"))
{
  group OS_GTMTOM0SR2_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMTOM0SR2_ISR_CONST_FAST";
  }
  "_OS_GTMTOM0SR2_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_CONST_FAST_GROUP";
  "_OS_GTMTOM0SR2_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMTOM0SR2_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMTOM0SR2_ISR_CONST_FAST_START" = 0;
  "_OS_GTMTOM0SR2_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR
# undef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMTOM0SR2_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_FAR )
if (exists(".rodata.OS_GTMTOM0SR3_ISR_CONST"))
{
  group OS_GTMTOM0SR3_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_GTMTOM0SR3_ISR_CONST";
  }
  "_OS_GTMTOM0SR3_ISR_CONST_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_CONST_GROUP";
  "_OS_GTMTOM0SR3_ISR_CONST_END" = "_lc_ge_OS_GTMTOM0SR3_ISR_CONST_GROUP";
}
else
{
  "_OS_GTMTOM0SR3_ISR_CONST_START" = 0;
  "_OS_GTMTOM0SR3_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_NEAR )
if (exists(".zrodata.OS_GTMTOM0SR3_ISR_CONST_FAST"))
{
  group OS_GTMTOM0SR3_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_GTMTOM0SR3_ISR_CONST_FAST";
  }
  "_OS_GTMTOM0SR3_ISR_CONST_FAST_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_CONST_FAST_GROUP";
  "_OS_GTMTOM0SR3_ISR_CONST_FAST_END" = "_lc_ge_OS_GTMTOM0SR3_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_GTMTOM0SR3_ISR_CONST_FAST_START" = 0;
  "_OS_GTMTOM0SR3_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR
# undef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_FAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_NEAR
# undef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_INIT
# undef OS_LINK_CONST_ISR_GTMTOM0SR3_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0ERR_ISR_FAR )
if (exists(".rodata.OS_QSPI0ERR_ISR_CONST"))
{
  group OS_QSPI0ERR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI0ERR_ISR_CONST";
  }
  "_OS_QSPI0ERR_ISR_CONST_START" = "_lc_gb_OS_QSPI0ERR_ISR_CONST_GROUP";
  "_OS_QSPI0ERR_ISR_CONST_END" = "_lc_ge_OS_QSPI0ERR_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI0ERR_ISR_CONST_START" = 0;
  "_OS_QSPI0ERR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0ERR_ISR_NEAR )
if (exists(".zrodata.OS_QSPI0ERR_ISR_CONST_FAST"))
{
  group OS_QSPI0ERR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI0ERR_ISR_CONST_FAST";
  }
  "_OS_QSPI0ERR_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI0ERR_ISR_CONST_FAST_GROUP";
  "_OS_QSPI0ERR_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI0ERR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI0ERR_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI0ERR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0ERR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI0ERR_ISR
# undef OS_LINK_CONST_ISR_QSPI0ERR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI0ERR_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI0ERR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI0ERR_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI0ERR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI0ERR_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI0ERR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0PT_ISR_FAR )
if (exists(".rodata.OS_QSPI0PT_ISR_CONST"))
{
  group OS_QSPI0PT_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI0PT_ISR_CONST";
  }
  "_OS_QSPI0PT_ISR_CONST_START" = "_lc_gb_OS_QSPI0PT_ISR_CONST_GROUP";
  "_OS_QSPI0PT_ISR_CONST_END" = "_lc_ge_OS_QSPI0PT_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI0PT_ISR_CONST_START" = 0;
  "_OS_QSPI0PT_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0PT_ISR_NEAR )
if (exists(".zrodata.OS_QSPI0PT_ISR_CONST_FAST"))
{
  group OS_QSPI0PT_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI0PT_ISR_CONST_FAST";
  }
  "_OS_QSPI0PT_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI0PT_ISR_CONST_FAST_GROUP";
  "_OS_QSPI0PT_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI0PT_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI0PT_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI0PT_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI0PT_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI0PT_ISR
# undef OS_LINK_CONST_ISR_QSPI0PT_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI0PT_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI0PT_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI0PT_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI0PT_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI0PT_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI0PT_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1ERR_ISR_FAR )
if (exists(".rodata.OS_QSPI1ERR_ISR_CONST"))
{
  group OS_QSPI1ERR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI1ERR_ISR_CONST";
  }
  "_OS_QSPI1ERR_ISR_CONST_START" = "_lc_gb_OS_QSPI1ERR_ISR_CONST_GROUP";
  "_OS_QSPI1ERR_ISR_CONST_END" = "_lc_ge_OS_QSPI1ERR_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI1ERR_ISR_CONST_START" = 0;
  "_OS_QSPI1ERR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1ERR_ISR_NEAR )
if (exists(".zrodata.OS_QSPI1ERR_ISR_CONST_FAST"))
{
  group OS_QSPI1ERR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI1ERR_ISR_CONST_FAST";
  }
  "_OS_QSPI1ERR_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI1ERR_ISR_CONST_FAST_GROUP";
  "_OS_QSPI1ERR_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI1ERR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI1ERR_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI1ERR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1ERR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI1ERR_ISR
# undef OS_LINK_CONST_ISR_QSPI1ERR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI1ERR_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI1ERR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI1ERR_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI1ERR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI1ERR_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI1ERR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1PT_ISR_FAR )
if (exists(".rodata.OS_QSPI1PT_ISR_CONST"))
{
  group OS_QSPI1PT_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI1PT_ISR_CONST";
  }
  "_OS_QSPI1PT_ISR_CONST_START" = "_lc_gb_OS_QSPI1PT_ISR_CONST_GROUP";
  "_OS_QSPI1PT_ISR_CONST_END" = "_lc_ge_OS_QSPI1PT_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI1PT_ISR_CONST_START" = 0;
  "_OS_QSPI1PT_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1PT_ISR_NEAR )
if (exists(".zrodata.OS_QSPI1PT_ISR_CONST_FAST"))
{
  group OS_QSPI1PT_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI1PT_ISR_CONST_FAST";
  }
  "_OS_QSPI1PT_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI1PT_ISR_CONST_FAST_GROUP";
  "_OS_QSPI1PT_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI1PT_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI1PT_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI1PT_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI1PT_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI1PT_ISR
# undef OS_LINK_CONST_ISR_QSPI1PT_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI1PT_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI1PT_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI1PT_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI1PT_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI1PT_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI1PT_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2ERR_ISR_FAR )
if (exists(".rodata.OS_QSPI2ERR_ISR_CONST"))
{
  group OS_QSPI2ERR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI2ERR_ISR_CONST";
  }
  "_OS_QSPI2ERR_ISR_CONST_START" = "_lc_gb_OS_QSPI2ERR_ISR_CONST_GROUP";
  "_OS_QSPI2ERR_ISR_CONST_END" = "_lc_ge_OS_QSPI2ERR_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI2ERR_ISR_CONST_START" = 0;
  "_OS_QSPI2ERR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2ERR_ISR_NEAR )
if (exists(".zrodata.OS_QSPI2ERR_ISR_CONST_FAST"))
{
  group OS_QSPI2ERR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI2ERR_ISR_CONST_FAST";
  }
  "_OS_QSPI2ERR_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI2ERR_ISR_CONST_FAST_GROUP";
  "_OS_QSPI2ERR_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI2ERR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI2ERR_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI2ERR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2ERR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI2ERR_ISR
# undef OS_LINK_CONST_ISR_QSPI2ERR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI2ERR_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI2ERR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI2ERR_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI2ERR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI2ERR_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI2ERR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2PT_ISR_FAR )
if (exists(".rodata.OS_QSPI2PT_ISR_CONST"))
{
  group OS_QSPI2PT_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI2PT_ISR_CONST";
  }
  "_OS_QSPI2PT_ISR_CONST_START" = "_lc_gb_OS_QSPI2PT_ISR_CONST_GROUP";
  "_OS_QSPI2PT_ISR_CONST_END" = "_lc_ge_OS_QSPI2PT_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI2PT_ISR_CONST_START" = 0;
  "_OS_QSPI2PT_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2PT_ISR_NEAR )
if (exists(".zrodata.OS_QSPI2PT_ISR_CONST_FAST"))
{
  group OS_QSPI2PT_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI2PT_ISR_CONST_FAST";
  }
  "_OS_QSPI2PT_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI2PT_ISR_CONST_FAST_GROUP";
  "_OS_QSPI2PT_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI2PT_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI2PT_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI2PT_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI2PT_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI2PT_ISR
# undef OS_LINK_CONST_ISR_QSPI2PT_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI2PT_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI2PT_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI2PT_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI2PT_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI2PT_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI2PT_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3ERR_ISR_FAR )
if (exists(".rodata.OS_QSPI3ERR_ISR_CONST"))
{
  group OS_QSPI3ERR_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI3ERR_ISR_CONST";
  }
  "_OS_QSPI3ERR_ISR_CONST_START" = "_lc_gb_OS_QSPI3ERR_ISR_CONST_GROUP";
  "_OS_QSPI3ERR_ISR_CONST_END" = "_lc_ge_OS_QSPI3ERR_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI3ERR_ISR_CONST_START" = 0;
  "_OS_QSPI3ERR_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3ERR_ISR_NEAR )
if (exists(".zrodata.OS_QSPI3ERR_ISR_CONST_FAST"))
{
  group OS_QSPI3ERR_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI3ERR_ISR_CONST_FAST";
  }
  "_OS_QSPI3ERR_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI3ERR_ISR_CONST_FAST_GROUP";
  "_OS_QSPI3ERR_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI3ERR_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI3ERR_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI3ERR_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3ERR_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI3ERR_ISR
# undef OS_LINK_CONST_ISR_QSPI3ERR_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI3ERR_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI3ERR_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI3ERR_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI3ERR_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI3ERR_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI3ERR_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3PT_ISR_FAR )
if (exists(".rodata.OS_QSPI3PT_ISR_CONST"))
{
  group OS_QSPI3PT_ISR_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_QSPI3PT_ISR_CONST";
  }
  "_OS_QSPI3PT_ISR_CONST_START" = "_lc_gb_OS_QSPI3PT_ISR_CONST_GROUP";
  "_OS_QSPI3PT_ISR_CONST_END" = "_lc_ge_OS_QSPI3PT_ISR_CONST_GROUP";
}
else
{
  "_OS_QSPI3PT_ISR_CONST_START" = 0;
  "_OS_QSPI3PT_ISR_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3PT_ISR_NEAR )
if (exists(".zrodata.OS_QSPI3PT_ISR_CONST_FAST"))
{
  group OS_QSPI3PT_ISR_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_QSPI3PT_ISR_CONST_FAST";
  }
  "_OS_QSPI3PT_ISR_CONST_FAST_START" = "_lc_gb_OS_QSPI3PT_ISR_CONST_FAST_GROUP";
  "_OS_QSPI3PT_ISR_CONST_FAST_END" = "_lc_ge_OS_QSPI3PT_ISR_CONST_FAST_GROUP";
}
else
{
  "_OS_QSPI3PT_ISR_CONST_FAST_START" = 0;
  "_OS_QSPI3PT_ISR_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_CONST_ISR_QSPI3PT_ISR_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_QSPI3PT_ISR
# undef OS_LINK_CONST_ISR_QSPI3PT_ISR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI3PT_ISR_FAR
# undef OS_LINK_CONST_ISR_QSPI3PT_ISR_FAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI3PT_ISR_NEAR
# undef OS_LINK_CONST_ISR_QSPI3PT_ISR_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_QSPI3PT_ISR_INIT
# undef OS_LINK_CONST_ISR_QSPI3PT_ISR_INIT
#endif



#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_FAR )
if (exists(".rodata.OS_XSignalIsr_OsCore0_CONST"))
{
  group OS_XSignalIsr_OsCore0_CONST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".rodata.OS_XSignalIsr_OsCore0_CONST";
  }
  "_OS_XSignalIsr_OsCore0_CONST_START" = "_lc_gb_OS_XSignalIsr_OsCore0_CONST_GROUP";
  "_OS_XSignalIsr_OsCore0_CONST_END" = "_lc_ge_OS_XSignalIsr_OsCore0_CONST_GROUP";
}
else
{
  "_OS_XSignalIsr_OsCore0_CONST_START" = 0;
  "_OS_XSignalIsr_OsCore0_CONST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_NEAR )
if (exists(".zrodata.OS_XSignalIsr_OsCore0_CONST_FAST"))
{
  group OS_XSignalIsr_OsCore0_CONST_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    select ".zrodata.OS_XSignalIsr_OsCore0_CONST_FAST";
  }
  "_OS_XSignalIsr_OsCore0_CONST_FAST_START" = "_lc_gb_OS_XSignalIsr_OsCore0_CONST_FAST_GROUP";
  "_OS_XSignalIsr_OsCore0_CONST_FAST_END" = "_lc_ge_OS_XSignalIsr_OsCore0_CONST_FAST_GROUP";
}
else
{
  "_OS_XSignalIsr_OsCore0_CONST_FAST_START" = 0;
  "_OS_XSignalIsr_OsCore0_CONST_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_CONST ) || defined ( OS_LINK_CONST_ISR ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_INIT )













#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0
#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_FAR
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_FAR
#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_NEAR
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_NEAR
#endif

#ifdef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_INIT
# undef OS_LINK_CONST_ISR_XSIGNALISR_OSCORE0_INIT
#endif



#ifdef OS_LINK_CONST
# undef OS_LINK_CONST
#endif

#ifdef OS_LINK_CONST_APP
# undef OS_LINK_CONST_APP
#endif

#ifdef OS_LINK_CONST_TASK
# undef OS_LINK_CONST_TASK
#endif

#ifdef OS_LINK_CONST_ISR
# undef OS_LINK_CONST_ISR
#endif

#ifdef OS_LINK_CONST_KERNEL
# undef OS_LINK_CONST_KERNEL
#endif

#ifdef OS_LINK_CONST_KERNEL_FAR
# undef OS_LINK_CONST_KERNEL_FAR
#endif

#ifdef OS_LINK_CONST_KERNEL_NEAR
# undef OS_LINK_CONST_KERNEL_NEAR
#endif

#ifdef OS_LINK_INTVEC_CONST
# undef OS_LINK_INTVEC_CONST
#endif

#ifdef OS_LINK_EXCVEC_CONST
# undef OS_LINK_EXCVEC_CONST
#endif


/**********************************************************************************************************************
 *  VAR SECTIONS
 *********************************************************************************************************************/

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_INIT )
if (exists(".data.OS_CORE0_VAR"))
{
  group OS_CORE0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CORE0_VAR";
    }
    reserved ".pad.OS_CORE0_VAR" (size=16);
  }
  "_OS_CORE0_VAR_START" = "_lc_gb_OS_CORE0_VAR_GROUP";
  "_OS_CORE0_VAR_END" = "_lc_ub__pad_OS_CORE0_VAR";
}
else
{
  "_OS_CORE0_VAR_START" = 0;
  "_OS_CORE0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CORE0_VAR_NOINIT"))
{
  group OS_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORE0_VAR_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_NOINIT";
}
else
{
  "_OS_CORE0_VAR_NOINIT_START" = 0;
  "_OS_CORE0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CORE0_VAR_FAST"))
{
  group OS_CORE0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CORE0_VAR_FAST";
    }
    reserved ".pad.OS_CORE0_VAR_FAST" (size=16);
  }
  "_OS_CORE0_VAR_FAST_START" = "_lc_gb_OS_CORE0_VAR_FAST_GROUP";
  "_OS_CORE0_VAR_FAST_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST";
}
else
{
  "_OS_CORE0_VAR_FAST_START" = 0;
  "_OS_CORE0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CORE0_VAR_FAST_NOINIT"))
{
  group OS_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CORE0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOINIT";
}
else
{
  "_OS_CORE0_VAR_FAST_NOINIT_START" = 0;
  "_OS_CORE0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT )
if (exists(".data.OS_CORE0_VAR_NOCACHE"))
{
  group OS_CORE0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CORE0_VAR_NOCACHE";
    }
    reserved ".pad.OS_CORE0_VAR_NOCACHE" (size=16);
  }
  "_OS_CORE0_VAR_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_GROUP";
  "_OS_CORE0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE";
}
else
{
  "_OS_CORE0_VAR_NOCACHE_START" = 0;
  "_OS_CORE0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_FAR ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CORE0_VAR_FAST_NOCACHE"))
{
  group OS_CORE0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CORE0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CORE0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_KERNEL ) || defined ( OS_LINK_VAR_KERNEL_NEAR ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_FAR )
if (exists(".bss.OS_PUBLIC_CORE0_VAR_NOINIT"))
{
  group OS_PUBLIC_CORE0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_PUBLIC_CORE0_VAR_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE0_VAR_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_NOINIT";
}
else
{
  "_OS_PUBLIC_CORE0_VAR_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_TRACE ) || defined ( OS_LINK_KERNEL_TRACE_NEAR )
if (exists(".bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT"))
{
  group OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_PUBLIC_CORE0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_PUBLIC_CORE0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_GROUP";
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_PUBLIC_CORE0_VAR_FAST_NOINIT";
}
else
{
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_START" = 0;
  "_OS_PUBLIC_CORE0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_FAR )
if (exists(".bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_BARRIERS ) || defined ( OS_LINK_KERNEL_BARRIERS_NEAR )
if (exists(".bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_BARRIER_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_FAR )
if (exists(".bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_KERNEL_CORESTATUS ) || defined ( OS_LINK_KERNEL_CORESTATUS_NEAR )
if (exists(".bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CORESTATUS_CORE0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif


#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
group OS_SystemApplication_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore0_VAR"))
{
  group OS_SystemApplication_OsCore0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_SystemApplication_OsCore0_VAR";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore0_VAR_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss") || exists(".data.OS_SystemApplication_OsCore0_VAR_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore0_VAR_ZERO_INIT_bss";
      select ".data.OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_SystemApplication_OsCore0_VAR_FAST";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_SystemApplication_OsCore0_VAR_NOCACHE"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_SystemApplication_OsCore0_VAR_NOCACHE";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOCACHE" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_APP ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0 ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SystemApplication_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
reserved ".pad.OS_SystemApplication_OsCore0_VAR_ALL_GROUP" (size=16);
} /* OS_SystemApplication_OsCore0_VAR_ALL_GROUP */
"_OS_SystemApplication_OsCore0_VAR_ALL_START" = "_lc_gb_OS_SystemApplication_OsCore0_VAR_ALL_GROUP";
"_OS_SystemApplication_OsCore0_VAR_ALL_END" = "_lc_ub__pad_OS_SystemApplication_OsCore0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_APP_SYSTEMAPPLICATION_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0
group OS_APP_Task_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_APP_Task_Core0_VAR"))
{
  group OS_APP_Task_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_APP_Task_Core0_VAR";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_START" = "_lc_gb_OS_APP_Task_Core0_VAR_GROUP";
  "_OS_APP_Task_Core0_VAR_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR";
}
else
{
  "_OS_APP_Task_Core0_VAR_START" = 0;
  "_OS_APP_Task_Core0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_APP_Task_Core0_VAR_NOINIT"))
{
  group OS_APP_Task_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_APP_Task_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_NOINIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_NOINIT_GROUP";
  "_OS_APP_Task_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_NOINIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_NOINIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_APP_Task_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_APP_Task_Core0_VAR_ZERO_INIT"))
{
  group OS_APP_Task_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_APP_Task_Core0_VAR_ZERO_INIT_bss";
      select ".data.OS_APP_Task_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_APP_Task_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_APP_Task_Core0_VAR_FAST"))
{
  group OS_APP_Task_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_APP_Task_Core0_VAR_FAST";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_FAST" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_FAST_START" = "_lc_gb_OS_APP_Task_Core0_VAR_FAST_GROUP";
  "_OS_APP_Task_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_FAST";
}
else
{
  "_OS_APP_Task_Core0_VAR_FAST_START" = 0;
  "_OS_APP_Task_Core0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_APP_Task_Core0_VAR_FAST_NOINIT"))
{
  group OS_APP_Task_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_APP_Task_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_APP_Task_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_APP_Task_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_APP_Task_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_APP_Task_Core0_VAR_NOCACHE"))
{
  group OS_APP_Task_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_APP_Task_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_APP_Task_Core0_VAR_NOCACHE_GROUP";
  "_OS_APP_Task_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_NOCACHE";
}
else
{
  "_OS_APP_Task_Core0_VAR_NOCACHE_START" = 0;
  "_OS_APP_Task_Core0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_APP_Task_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_APP_Task_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_APP_Task_Core0_VAR_FAST_NOCACHE"))
{
  group OS_APP_Task_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_APP_Task_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_APP_Task_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0 ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_APP_Task_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0
reserved ".pad.OS_APP_Task_Core0_VAR_ALL_GROUP" (size=16);
} /* OS_APP_Task_Core0_VAR_ALL_GROUP */
"_OS_APP_Task_Core0_VAR_ALL_START" = "_lc_gb_OS_APP_Task_Core0_VAR_ALL_GROUP";
"_OS_APP_Task_Core0_VAR_ALL_END" = "_lc_ub__pad_OS_APP_Task_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_APP_TASK_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_APP_TASK_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD
group OS_Core_OsTask_CDD_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_INIT )
if (exists(".data.OS_Core_OsTask_CDD_VAR"))
{
  group OS_Core_OsTask_CDD_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_CDD_VAR";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_GROUP";
  "_OS_Core_OsTask_CDD_VAR_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_CDD_VAR_NOINIT"))
{
  group OS_Core_OsTask_CDD_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_CDD_VAR_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_NOINIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_NOINIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_NOINIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_NOINIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_CDD_VAR_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_CDD_VAR_ZERO_INIT"))
{
  group OS_Core_OsTask_CDD_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_CDD_VAR_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_CDD_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_CDD_VAR_FAST"))
{
  group OS_Core_OsTask_CDD_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_CDD_VAR_FAST";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_FAST" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_FAST_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_FAST_GROUP";
  "_OS_Core_OsTask_CDD_VAR_FAST_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_FAST";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_FAST_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_CDD_VAR_FAST_NOINIT"))
{
  group OS_Core_OsTask_CDD_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_CDD_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_FAST_NOINIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_FAST_NOINIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_FAST_NOINIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT"))
{
  group OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_INIT )
if (exists(".data.OS_Core_OsTask_CDD_VAR_NOCACHE"))
{
  group OS_Core_OsTask_CDD_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_CDD_VAR_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_NOCACHE_GROUP";
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_NOCACHE";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE"))
{
  group OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_GROUP";
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_CDD_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD
reserved ".pad.OS_Core_OsTask_CDD_VAR_ALL_GROUP" (size=16);
} /* OS_Core_OsTask_CDD_VAR_ALL_GROUP */
"_OS_Core_OsTask_CDD_VAR_ALL_START" = "_lc_gb_OS_Core_OsTask_CDD_VAR_ALL_GROUP";
"_OS_Core_OsTask_CDD_VAR_ALL_END" = "_lc_ub__pad_OS_Core_OsTask_CDD_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_CDD_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW
group OS_Core_OsTask_IOHW_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_INIT )
if (exists(".data.OS_Core_OsTask_IOHW_VAR"))
{
  group OS_Core_OsTask_IOHW_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_IOHW_VAR";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_IOHW_VAR_NOINIT"))
{
  group OS_Core_OsTask_IOHW_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_IOHW_VAR_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_NOINIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_NOINIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_NOINIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_NOINIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_IOHW_VAR_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_IOHW_VAR_ZERO_INIT"))
{
  group OS_Core_OsTask_IOHW_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_IOHW_VAR_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_IOHW_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_IOHW_VAR_FAST"))
{
  group OS_Core_OsTask_IOHW_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_IOHW_VAR_FAST";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_FAST" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_FAST_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_FAST_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_FAST_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_FAST";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_FAST_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_IOHW_VAR_FAST_NOINIT"))
{
  group OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_IOHW_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_FAST_NOINIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT"))
{
  group OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_INIT )
if (exists(".data.OS_Core_OsTask_IOHW_VAR_NOCACHE"))
{
  group OS_Core_OsTask_IOHW_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_IOHW_VAR_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_NOCACHE_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_NOCACHE";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE"))
{
  group OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_IOHW_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW
reserved ".pad.OS_Core_OsTask_IOHW_VAR_ALL_GROUP" (size=16);
} /* OS_Core_OsTask_IOHW_VAR_ALL_GROUP */
"_OS_Core_OsTask_IOHW_VAR_ALL_START" = "_lc_gb_OS_Core_OsTask_IOHW_VAR_ALL_GROUP";
"_OS_Core_OsTask_IOHW_VAR_ALL_END" = "_lc_ub__pad_OS_Core_OsTask_IOHW_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_IOHW_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5
group OS_Core_OsTask_PSI5_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_INIT )
if (exists(".data.OS_Core_OsTask_PSI5_VAR"))
{
  group OS_Core_OsTask_PSI5_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_PSI5_VAR";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_PSI5_VAR_NOINIT"))
{
  group OS_Core_OsTask_PSI5_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PSI5_VAR_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_NOINIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_NOINIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_NOINIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_PSI5_VAR_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_PSI5_VAR_ZERO_INIT"))
{
  group OS_Core_OsTask_PSI5_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PSI5_VAR_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_PSI5_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_PSI5_VAR_FAST"))
{
  group OS_Core_OsTask_PSI5_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_PSI5_VAR_FAST";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_FAST" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_FAST_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_FAST_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_FAST_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_FAST";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_FAST_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_PSI5_VAR_FAST_NOINIT"))
{
  group OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PSI5_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_FAST_NOINIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT"))
{
  group OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_INIT )
if (exists(".data.OS_Core_OsTask_PSI5_VAR_NOCACHE"))
{
  group OS_Core_OsTask_PSI5_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_PSI5_VAR_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_NOCACHE_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_NOCACHE";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE"))
{
  group OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PSI5_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5
reserved ".pad.OS_Core_OsTask_PSI5_VAR_ALL_GROUP" (size=16);
} /* OS_Core_OsTask_PSI5_VAR_ALL_GROUP */
"_OS_Core_OsTask_PSI5_VAR_ALL_START" = "_lc_gb_OS_Core_OsTask_PSI5_VAR_ALL_GROUP";
"_OS_Core_OsTask_PSI5_VAR_ALL_END" = "_lc_ub__pad_OS_Core_OsTask_PSI5_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PSI5_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000
group OS_Core_OsTask_PT2000_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_INIT )
if (exists(".data.OS_Core_OsTask_PT2000_VAR"))
{
  group OS_Core_OsTask_PT2000_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_PT2000_VAR";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_PT2000_VAR_NOINIT"))
{
  group OS_Core_OsTask_PT2000_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PT2000_VAR_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_NOINIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_NOINIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_NOINIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_PT2000_VAR_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_PT2000_VAR_ZERO_INIT"))
{
  group OS_Core_OsTask_PT2000_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PT2000_VAR_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_PT2000_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_PT2000_VAR_FAST"))
{
  group OS_Core_OsTask_PT2000_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_PT2000_VAR_FAST";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_FAST" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_FAST_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_FAST_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_FAST_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_FAST";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_FAST_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_PT2000_VAR_FAST_NOINIT"))
{
  group OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PT2000_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_FAST_NOINIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT"))
{
  group OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_INIT )
if (exists(".data.OS_Core_OsTask_PT2000_VAR_NOCACHE"))
{
  group OS_Core_OsTask_PT2000_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Core_OsTask_PT2000_VAR_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_NOCACHE_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_NOCACHE";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE"))
{
  group OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000 ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Core_OsTask_PT2000_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000
reserved ".pad.OS_Core_OsTask_PT2000_VAR_ALL_GROUP" (size=16);
} /* OS_Core_OsTask_PT2000_VAR_ALL_GROUP */
"_OS_Core_OsTask_PT2000_VAR_ALL_START" = "_lc_gb_OS_Core_OsTask_PT2000_VAR_ALL_GROUP";
"_OS_Core_OsTask_PT2000_VAR_ALL_END" = "_lc_ub__pad_OS_Core_OsTask_PT2000_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_CORE_OSTASK_PT2000_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
group OS_IdleTask_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore0_VAR"))
{
  group OS_IdleTask_OsCore0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_IdleTask_OsCore0_VAR";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_GROUP";
  "_OS_IdleTask_OsCore0_VAR_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore0_VAR_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore0_VAR_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore0_VAR_ZERO_INIT_bss";
      select ".data.OS_IdleTask_OsCore0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_IdleTask_OsCore0_VAR_FAST";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_IdleTask_OsCore0_VAR_NOCACHE"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_IdleTask_OsCore0_VAR_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0 ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_IdleTask_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
reserved ".pad.OS_IdleTask_OsCore0_VAR_ALL_GROUP" (size=16);
} /* OS_IdleTask_OsCore0_VAR_ALL_GROUP */
"_OS_IdleTask_OsCore0_VAR_ALL_START" = "_lc_gb_OS_IdleTask_OsCore0_VAR_ALL_GROUP";
"_OS_IdleTask_OsCore0_VAR_ALL_END" = "_lc_ub__pad_OS_IdleTask_OsCore0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_IDLETASK_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_INIT_CORE0
group OS_Init_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_Init_Core0_VAR"))
{
  group OS_Init_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Init_Core0_VAR";
    }
    reserved ".pad.OS_Init_Core0_VAR" (size=16);
  }
  "_OS_Init_Core0_VAR_START" = "_lc_gb_OS_Init_Core0_VAR_GROUP";
  "_OS_Init_Core0_VAR_END" = "_lc_ub__pad_OS_Init_Core0_VAR";
}
else
{
  "_OS_Init_Core0_VAR_START" = 0;
  "_OS_Init_Core0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_Init_Core0_VAR_NOINIT"))
{
  group OS_Init_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Init_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_Init_Core0_VAR_NOINIT_START" = "_lc_gb_OS_Init_Core0_VAR_NOINIT_GROUP";
  "_OS_Init_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_NOINIT";
}
else
{
  "_OS_Init_Core0_VAR_NOINIT_START" = 0;
  "_OS_Init_Core0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_Init_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_Init_Core0_VAR_ZERO_INIT"))
{
  group OS_Init_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Init_Core0_VAR_ZERO_INIT_bss";
      select ".data.OS_Init_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_Init_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_Init_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_Init_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_Init_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_Init_Core0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_Init_Core0_VAR_FAST"))
{
  group OS_Init_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Init_Core0_VAR_FAST";
    }
    reserved ".pad.OS_Init_Core0_VAR_FAST" (size=16);
  }
  "_OS_Init_Core0_VAR_FAST_START" = "_lc_gb_OS_Init_Core0_VAR_FAST_GROUP";
  "_OS_Init_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_Init_Core0_VAR_FAST";
}
else
{
  "_OS_Init_Core0_VAR_FAST_START" = 0;
  "_OS_Init_Core0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_Init_Core0_VAR_FAST_NOINIT"))
{
  group OS_Init_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Init_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_Init_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_Init_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_Init_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_Init_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_Init_Core0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_Init_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_Init_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_Init_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Init_Core0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_Init_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_Init_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_Init_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_Init_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_Init_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_Init_Core0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_Init_Core0_VAR_NOCACHE"))
{
  group OS_Init_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_Init_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_Init_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_Init_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_Init_Core0_VAR_NOCACHE_GROUP";
  "_OS_Init_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_Init_Core0_VAR_NOCACHE";
}
else
{
  "_OS_Init_Core0_VAR_NOCACHE_START" = 0;
  "_OS_Init_Core0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_Init_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_Init_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Init_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Init_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_Init_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_Init_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_Init_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_Init_Core0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_Init_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_Init_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Init_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_Init_Core0_VAR_FAST_NOCACHE"))
{
  group OS_Init_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_Init_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_Init_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_Init_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_Init_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_Init_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_Init_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_Init_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_Init_Core0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_Init_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0 ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_Init_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0
reserved ".pad.OS_Init_Core0_VAR_ALL_GROUP" (size=16);
} /* OS_Init_Core0_VAR_ALL_GROUP */
"_OS_Init_Core0_VAR_ALL_START" = "_lc_gb_OS_Init_Core0_VAR_ALL_GROUP";
"_OS_Init_Core0_VAR_ALL_END" = "_lc_ub__pad_OS_Init_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_INIT_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_INIT_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_TASK_SCHM_CORE0
group OS_SchM_Core0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_INIT )
if (exists(".data.OS_SchM_Core0_VAR"))
{
  group OS_SchM_Core0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_SchM_Core0_VAR";
    }
    reserved ".pad.OS_SchM_Core0_VAR" (size=16);
  }
  "_OS_SchM_Core0_VAR_START" = "_lc_gb_OS_SchM_Core0_VAR_GROUP";
  "_OS_SchM_Core0_VAR_END" = "_lc_ub__pad_OS_SchM_Core0_VAR";
}
else
{
  "_OS_SchM_Core0_VAR_START" = 0;
  "_OS_SchM_Core0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_SchM_Core0_VAR_NOINIT"))
{
  group OS_SchM_Core0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SchM_Core0_VAR_NOINIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_NOINIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_NOINIT_START" = "_lc_gb_OS_SchM_Core0_VAR_NOINIT_GROUP";
  "_OS_SchM_Core0_VAR_NOINIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_NOINIT";
}
else
{
  "_OS_SchM_Core0_VAR_NOINIT_START" = 0;
  "_OS_SchM_Core0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_SchM_Core0_VAR_ZERO_INIT_bss") || exists(".data.OS_SchM_Core0_VAR_ZERO_INIT"))
{
  group OS_SchM_Core0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SchM_Core0_VAR_ZERO_INIT_bss";
      select ".data.OS_SchM_Core0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_ZERO_INIT_START" = "_lc_gb_OS_SchM_Core0_VAR_ZERO_INIT_GROUP";
  "_OS_SchM_Core0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_ZERO_INIT";
}
else
{
  "_OS_SchM_Core0_VAR_ZERO_INIT_START" = 0;
  "_OS_SchM_Core0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_SchM_Core0_VAR_FAST"))
{
  group OS_SchM_Core0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_SchM_Core0_VAR_FAST";
    }
    reserved ".pad.OS_SchM_Core0_VAR_FAST" (size=16);
  }
  "_OS_SchM_Core0_VAR_FAST_START" = "_lc_gb_OS_SchM_Core0_VAR_FAST_GROUP";
  "_OS_SchM_Core0_VAR_FAST_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_FAST";
}
else
{
  "_OS_SchM_Core0_VAR_FAST_START" = 0;
  "_OS_SchM_Core0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_SchM_Core0_VAR_FAST_NOINIT"))
{
  group OS_SchM_Core0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SchM_Core0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_SchM_Core0_VAR_FAST_NOINIT_GROUP";
  "_OS_SchM_Core0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_FAST_NOINIT";
}
else
{
  "_OS_SchM_Core0_VAR_FAST_NOINIT_START" = 0;
  "_OS_SchM_Core0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_SchM_Core0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_SchM_Core0_VAR_FAST_ZERO_INIT"))
{
  group OS_SchM_Core0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SchM_Core0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_SchM_Core0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_SchM_Core0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_SchM_Core0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_SchM_Core0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_SchM_Core0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_SchM_Core0_VAR_NOCACHE"))
{
  group OS_SchM_Core0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_SchM_Core0_VAR_NOCACHE";
    }
    reserved ".pad.OS_SchM_Core0_VAR_NOCACHE" (size=16);
  }
  "_OS_SchM_Core0_VAR_NOCACHE_START" = "_lc_gb_OS_SchM_Core0_VAR_NOCACHE_GROUP";
  "_OS_SchM_Core0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_NOCACHE";
}
else
{
  "_OS_SchM_Core0_VAR_NOCACHE_START" = 0;
  "_OS_SchM_Core0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_SchM_Core0_VAR_NOCACHE_NOINIT"))
{
  group OS_SchM_Core0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SchM_Core0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_SchM_Core0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_SchM_Core0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_SchM_Core0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_SchM_Core0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SchM_Core0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_SchM_Core0_VAR_FAST_NOCACHE"))
{
  group OS_SchM_Core0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_SchM_Core0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_SchM_Core0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_SchM_Core0_VAR_FAST_NOCACHE_GROUP";
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_TASK ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0 ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_SchM_Core0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0
reserved ".pad.OS_SchM_Core0_VAR_ALL_GROUP" (size=16);
} /* OS_SchM_Core0_VAR_ALL_GROUP */
"_OS_SchM_Core0_VAR_ALL_START" = "_lc_gb_OS_SchM_Core0_VAR_ALL_GROUP";
"_OS_SchM_Core0_VAR_ALL_END" = "_lc_ub__pad_OS_SchM_Core0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_TASK_SCHM_CORE0
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_TASK_SCHM_CORE0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR
group OS_ADC0SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_ADC0SR0_ISR_VAR"))
{
  group OS_ADC0SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC0SR0_ISR_VAR";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_GROUP";
  "_OS_ADC0SR0_ISR_VAR_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ADC0SR0_ISR_VAR_NOINIT"))
{
  group OS_ADC0SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC0SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ADC0SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_ADC0SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_ADC0SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC0SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_ADC0SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ADC0SR0_ISR_VAR_FAST"))
{
  group OS_ADC0SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC0SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_FAST_GROUP";
  "_OS_ADC0SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_FAST";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_FAST_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ADC0SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_ADC0SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC0SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_ADC0SR0_ISR_VAR_NOCACHE"))
{
  group OS_ADC0SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC0SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR
reserved ".pad.OS_ADC0SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_ADC0SR0_ISR_VAR_ALL_GROUP */
"_OS_ADC0SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_ADC0SR0_ISR_VAR_ALL_GROUP";
"_OS_ADC0SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_ADC0SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_ADC0SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC0SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR
group OS_ADC1SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_ADC1SR0_ISR_VAR"))
{
  group OS_ADC1SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC1SR0_ISR_VAR";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_GROUP";
  "_OS_ADC1SR0_ISR_VAR_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ADC1SR0_ISR_VAR_NOINIT"))
{
  group OS_ADC1SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC1SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ADC1SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_ADC1SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_ADC1SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC1SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_ADC1SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ADC1SR0_ISR_VAR_FAST"))
{
  group OS_ADC1SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC1SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_FAST_GROUP";
  "_OS_ADC1SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_FAST";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_FAST_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ADC1SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_ADC1SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC1SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_ADC1SR0_ISR_VAR_NOCACHE"))
{
  group OS_ADC1SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC1SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR
reserved ".pad.OS_ADC1SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_ADC1SR0_ISR_VAR_ALL_GROUP */
"_OS_ADC1SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_ADC1SR0_ISR_VAR_ALL_GROUP";
"_OS_ADC1SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_ADC1SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_ADC1SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC1SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR
group OS_ADC2SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_ADC2SR0_ISR_VAR"))
{
  group OS_ADC2SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC2SR0_ISR_VAR";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_GROUP";
  "_OS_ADC2SR0_ISR_VAR_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ADC2SR0_ISR_VAR_NOINIT"))
{
  group OS_ADC2SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC2SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ADC2SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_ADC2SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_ADC2SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC2SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_ADC2SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ADC2SR0_ISR_VAR_FAST"))
{
  group OS_ADC2SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC2SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_FAST_GROUP";
  "_OS_ADC2SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_FAST";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_FAST_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ADC2SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_ADC2SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC2SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_ADC2SR0_ISR_VAR_NOCACHE"))
{
  group OS_ADC2SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC2SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR
reserved ".pad.OS_ADC2SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_ADC2SR0_ISR_VAR_ALL_GROUP */
"_OS_ADC2SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_ADC2SR0_ISR_VAR_ALL_GROUP";
"_OS_ADC2SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_ADC2SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_ADC2SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC2SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR
group OS_ADC3SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_ADC3SR0_ISR_VAR"))
{
  group OS_ADC3SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC3SR0_ISR_VAR";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_GROUP";
  "_OS_ADC3SR0_ISR_VAR_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ADC3SR0_ISR_VAR_NOINIT"))
{
  group OS_ADC3SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC3SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ADC3SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_ADC3SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_ADC3SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC3SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_ADC3SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ADC3SR0_ISR_VAR_FAST"))
{
  group OS_ADC3SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC3SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_FAST_GROUP";
  "_OS_ADC3SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_FAST";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_FAST_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ADC3SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_ADC3SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC3SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_ADC3SR0_ISR_VAR_NOCACHE"))
{
  group OS_ADC3SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC3SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC3SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR
reserved ".pad.OS_ADC3SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_ADC3SR0_ISR_VAR_ALL_GROUP */
"_OS_ADC3SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_ADC3SR0_ISR_VAR_ALL_GROUP";
"_OS_ADC3SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_ADC3SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_ADC3SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC3SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR
group OS_ADC8SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_ADC8SR0_ISR_VAR"))
{
  group OS_ADC8SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC8SR0_ISR_VAR";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_GROUP";
  "_OS_ADC8SR0_ISR_VAR_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_ADC8SR0_ISR_VAR_NOINIT"))
{
  group OS_ADC8SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC8SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_ADC8SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_ADC8SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_ADC8SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC8SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_ADC8SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_ADC8SR0_ISR_VAR_FAST"))
{
  group OS_ADC8SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC8SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_FAST_GROUP";
  "_OS_ADC8SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_FAST";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_FAST_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_ADC8SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_ADC8SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC8SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_ADC8SR0_ISR_VAR_NOCACHE"))
{
  group OS_ADC8SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_ADC8SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_ADC8SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR
reserved ".pad.OS_ADC8SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_ADC8SR0_ISR_VAR_ALL_GROUP */
"_OS_ADC8SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_ADC8SR0_ISR_VAR_ALL_GROUP";
"_OS_ADC8SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_ADC8SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_ADC8SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_ADC8SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISR_4
group OS_CanIsr_4_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_INIT )
if (exists(".data.OS_CanIsr_4_VAR"))
{
  group OS_CanIsr_4_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CanIsr_4_VAR";
    }
    reserved ".pad.OS_CanIsr_4_VAR" (size=16);
  }
  "_OS_CanIsr_4_VAR_START" = "_lc_gb_OS_CanIsr_4_VAR_GROUP";
  "_OS_CanIsr_4_VAR_END" = "_lc_ub__pad_OS_CanIsr_4_VAR";
}
else
{
  "_OS_CanIsr_4_VAR_START" = 0;
  "_OS_CanIsr_4_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CanIsr_4_VAR_NOINIT"))
{
  group OS_CanIsr_4_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_4_VAR_NOINIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_NOINIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_NOINIT_START" = "_lc_gb_OS_CanIsr_4_VAR_NOINIT_GROUP";
  "_OS_CanIsr_4_VAR_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_NOINIT";
}
else
{
  "_OS_CanIsr_4_VAR_NOINIT_START" = 0;
  "_OS_CanIsr_4_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_4_VAR_ZERO_INIT_bss") || exists(".data.OS_CanIsr_4_VAR_ZERO_INIT"))
{
  group OS_CanIsr_4_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_4_VAR_ZERO_INIT_bss";
      select ".data.OS_CanIsr_4_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_4_VAR_ZERO_INIT_GROUP";
  "_OS_CanIsr_4_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_ZERO_INIT";
}
else
{
  "_OS_CanIsr_4_VAR_ZERO_INIT_START" = 0;
  "_OS_CanIsr_4_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CanIsr_4_VAR_FAST"))
{
  group OS_CanIsr_4_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CanIsr_4_VAR_FAST";
    }
    reserved ".pad.OS_CanIsr_4_VAR_FAST" (size=16);
  }
  "_OS_CanIsr_4_VAR_FAST_START" = "_lc_gb_OS_CanIsr_4_VAR_FAST_GROUP";
  "_OS_CanIsr_4_VAR_FAST_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_FAST";
}
else
{
  "_OS_CanIsr_4_VAR_FAST_START" = 0;
  "_OS_CanIsr_4_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_4_VAR_FAST_NOINIT"))
{
  group OS_CanIsr_4_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_4_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CanIsr_4_VAR_FAST_NOINIT_GROUP";
  "_OS_CanIsr_4_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_FAST_NOINIT";
}
else
{
  "_OS_CanIsr_4_VAR_FAST_NOINIT_START" = 0;
  "_OS_CanIsr_4_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_4_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_4_VAR_FAST_ZERO_INIT"))
{
  group OS_CanIsr_4_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_4_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_CanIsr_4_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_4_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CanIsr_4_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CanIsr_4_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CanIsr_4_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_INIT )
if (exists(".data.OS_CanIsr_4_VAR_NOCACHE"))
{
  group OS_CanIsr_4_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CanIsr_4_VAR_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_4_VAR_NOCACHE" (size=16);
  }
  "_OS_CanIsr_4_VAR_NOCACHE_START" = "_lc_gb_OS_CanIsr_4_VAR_NOCACHE_GROUP";
  "_OS_CanIsr_4_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_NOCACHE";
}
else
{
  "_OS_CanIsr_4_VAR_NOCACHE_START" = 0;
  "_OS_CanIsr_4_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CanIsr_4_VAR_NOCACHE_NOINIT"))
{
  group OS_CanIsr_4_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_4_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_4_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_4_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_4_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_4_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_4_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CanIsr_4_VAR_FAST_NOCACHE"))
{
  group OS_CanIsr_4_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CanIsr_4_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_4_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CanIsr_4_VAR_FAST_NOCACHE_GROUP";
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_4 ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_4_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4
reserved ".pad.OS_CanIsr_4_VAR_ALL_GROUP" (size=16);
} /* OS_CanIsr_4_VAR_ALL_GROUP */
"_OS_CanIsr_4_VAR_ALL_START" = "_lc_gb_OS_CanIsr_4_VAR_ALL_GROUP";
"_OS_CanIsr_4_VAR_ALL_END" = "_lc_ub__pad_OS_CanIsr_4_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_CANISR_4
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR
# undef OS_LINK_VAR_ISR_CANISR_4_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_4_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_CANISR_5
group OS_CanIsr_5_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_INIT )
if (exists(".data.OS_CanIsr_5_VAR"))
{
  group OS_CanIsr_5_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CanIsr_5_VAR";
    }
    reserved ".pad.OS_CanIsr_5_VAR" (size=16);
  }
  "_OS_CanIsr_5_VAR_START" = "_lc_gb_OS_CanIsr_5_VAR_GROUP";
  "_OS_CanIsr_5_VAR_END" = "_lc_ub__pad_OS_CanIsr_5_VAR";
}
else
{
  "_OS_CanIsr_5_VAR_START" = 0;
  "_OS_CanIsr_5_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CanIsr_5_VAR_NOINIT"))
{
  group OS_CanIsr_5_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_5_VAR_NOINIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_NOINIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_NOINIT_START" = "_lc_gb_OS_CanIsr_5_VAR_NOINIT_GROUP";
  "_OS_CanIsr_5_VAR_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_NOINIT";
}
else
{
  "_OS_CanIsr_5_VAR_NOINIT_START" = 0;
  "_OS_CanIsr_5_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_5_VAR_ZERO_INIT_bss") || exists(".data.OS_CanIsr_5_VAR_ZERO_INIT"))
{
  group OS_CanIsr_5_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_5_VAR_ZERO_INIT_bss";
      select ".data.OS_CanIsr_5_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_5_VAR_ZERO_INIT_GROUP";
  "_OS_CanIsr_5_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_ZERO_INIT";
}
else
{
  "_OS_CanIsr_5_VAR_ZERO_INIT_START" = 0;
  "_OS_CanIsr_5_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CanIsr_5_VAR_FAST"))
{
  group OS_CanIsr_5_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CanIsr_5_VAR_FAST";
    }
    reserved ".pad.OS_CanIsr_5_VAR_FAST" (size=16);
  }
  "_OS_CanIsr_5_VAR_FAST_START" = "_lc_gb_OS_CanIsr_5_VAR_FAST_GROUP";
  "_OS_CanIsr_5_VAR_FAST_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_FAST";
}
else
{
  "_OS_CanIsr_5_VAR_FAST_START" = 0;
  "_OS_CanIsr_5_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_5_VAR_FAST_NOINIT"))
{
  group OS_CanIsr_5_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_5_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CanIsr_5_VAR_FAST_NOINIT_GROUP";
  "_OS_CanIsr_5_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_FAST_NOINIT";
}
else
{
  "_OS_CanIsr_5_VAR_FAST_NOINIT_START" = 0;
  "_OS_CanIsr_5_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_5_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_5_VAR_FAST_ZERO_INIT"))
{
  group OS_CanIsr_5_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_5_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_CanIsr_5_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_5_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CanIsr_5_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CanIsr_5_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CanIsr_5_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_INIT )
if (exists(".data.OS_CanIsr_5_VAR_NOCACHE"))
{
  group OS_CanIsr_5_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CanIsr_5_VAR_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_5_VAR_NOCACHE" (size=16);
  }
  "_OS_CanIsr_5_VAR_NOCACHE_START" = "_lc_gb_OS_CanIsr_5_VAR_NOCACHE_GROUP";
  "_OS_CanIsr_5_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_NOCACHE";
}
else
{
  "_OS_CanIsr_5_VAR_NOCACHE_START" = 0;
  "_OS_CanIsr_5_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CanIsr_5_VAR_NOCACHE_NOINIT"))
{
  group OS_CanIsr_5_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_5_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_5_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_5_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_5_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_5_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_5_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CanIsr_5_VAR_FAST_NOCACHE"))
{
  group OS_CanIsr_5_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CanIsr_5_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CanIsr_5_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CanIsr_5_VAR_FAST_NOCACHE_GROUP";
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_CANISR_5 ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CanIsr_5_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5
reserved ".pad.OS_CanIsr_5_VAR_ALL_GROUP" (size=16);
} /* OS_CanIsr_5_VAR_ALL_GROUP */
"_OS_CanIsr_5_VAR_ALL_START" = "_lc_gb_OS_CanIsr_5_VAR_ALL_GROUP";
"_OS_CanIsr_5_VAR_ALL_END" = "_lc_ub__pad_OS_CanIsr_5_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_CANISR_5
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR
# undef OS_LINK_VAR_ISR_CANISR_5_FAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_CANISR_5_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0
group OS_CounterIsr_SystemTimer0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer0_VAR"))
{
  group OS_CounterIsr_SystemTimer0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CounterIsr_SystemTimer0_VAR";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer0_VAR_NOINIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer0_VAR_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_bss";
      select ".data.OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST"))
{
  group OS_CounterIsr_SystemTimer0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_FAST" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_FAST_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_FAST";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_INIT )
if (exists(".data.OS_CounterIsr_SystemTimer0_VAR_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_CounterIsr_SystemTimer0_VAR_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_NOCACHE";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE"))
{
  group OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0 ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_CounterIsr_SystemTimer0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0
reserved ".pad.OS_CounterIsr_SystemTimer0_VAR_ALL_GROUP" (size=16);
} /* OS_CounterIsr_SystemTimer0_VAR_ALL_GROUP */
"_OS_CounterIsr_SystemTimer0_VAR_ALL_START" = "_lc_gb_OS_CounterIsr_SystemTimer0_VAR_ALL_GROUP";
"_OS_CounterIsr_SystemTimer0_VAR_ALL_END" = "_lc_ub__pad_OS_CounterIsr_SystemTimer0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_COUNTERISR_SYSTEMTIMER0_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR
group OS_DMACH0SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH0SR_ISR_VAR"))
{
  group OS_DMACH0SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH0SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_GROUP";
  "_OS_DMACH0SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH0SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH0SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH0SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH0SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH0SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH0SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH0SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH0SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH0SR_ISR_VAR_FAST"))
{
  group OS_DMACH0SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH0SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH0SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH0SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH0SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH0SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH0SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH0SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH0SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR
reserved ".pad.OS_DMACH0SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH0SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH0SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH0SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH0SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH0SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH0SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH0SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR
group OS_DMACH3SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH3SR_ISR_VAR"))
{
  group OS_DMACH3SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH3SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_GROUP";
  "_OS_DMACH3SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH3SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH3SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH3SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH3SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH3SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH3SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH3SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH3SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH3SR_ISR_VAR_FAST"))
{
  group OS_DMACH3SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH3SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH3SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH3SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH3SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH3SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH3SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH3SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH3SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH3SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR
reserved ".pad.OS_DMACH3SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH3SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH3SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH3SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH3SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH3SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH3SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH3SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR
group OS_DMACH4SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH4SR_ISR_VAR"))
{
  group OS_DMACH4SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH4SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_GROUP";
  "_OS_DMACH4SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH4SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH4SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH4SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH4SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH4SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH4SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH4SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH4SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH4SR_ISR_VAR_FAST"))
{
  group OS_DMACH4SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH4SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH4SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH4SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH4SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH4SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH4SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH4SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH4SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH4SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR
reserved ".pad.OS_DMACH4SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH4SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH4SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH4SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH4SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH4SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH4SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH4SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR
group OS_DMACH5SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH5SR_ISR_VAR"))
{
  group OS_DMACH5SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH5SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_GROUP";
  "_OS_DMACH5SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH5SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH5SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH5SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH5SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH5SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH5SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH5SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH5SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH5SR_ISR_VAR_FAST"))
{
  group OS_DMACH5SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH5SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH5SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH5SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH5SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH5SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH5SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH5SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH5SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH5SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR
reserved ".pad.OS_DMACH5SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH5SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH5SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH5SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH5SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH5SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH5SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH5SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR
group OS_DMACH6SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH6SR_ISR_VAR"))
{
  group OS_DMACH6SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH6SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_GROUP";
  "_OS_DMACH6SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH6SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH6SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH6SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH6SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH6SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH6SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH6SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH6SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH6SR_ISR_VAR_FAST"))
{
  group OS_DMACH6SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH6SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH6SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH6SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH6SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH6SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH6SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH6SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH6SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH6SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR
reserved ".pad.OS_DMACH6SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH6SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH6SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH6SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH6SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH6SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH6SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH6SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR
group OS_DMACH7SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH7SR_ISR_VAR"))
{
  group OS_DMACH7SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH7SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_GROUP";
  "_OS_DMACH7SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH7SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH7SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH7SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH7SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH7SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH7SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH7SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH7SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH7SR_ISR_VAR_FAST"))
{
  group OS_DMACH7SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH7SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH7SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH7SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH7SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH7SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH7SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH7SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH7SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH7SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR
reserved ".pad.OS_DMACH7SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH7SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH7SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH7SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH7SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH7SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH7SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH7SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR
group OS_DMACH8SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH8SR_ISR_VAR"))
{
  group OS_DMACH8SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH8SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_GROUP";
  "_OS_DMACH8SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH8SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH8SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH8SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH8SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH8SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH8SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH8SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH8SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH8SR_ISR_VAR_FAST"))
{
  group OS_DMACH8SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH8SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH8SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH8SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH8SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH8SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH8SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH8SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH8SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH8SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR
reserved ".pad.OS_DMACH8SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH8SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH8SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH8SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH8SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH8SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH8SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH8SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR
group OS_DMACH9SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMACH9SR_ISR_VAR"))
{
  group OS_DMACH9SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH9SR_ISR_VAR";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_GROUP";
  "_OS_DMACH9SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMACH9SR_ISR_VAR_NOINIT"))
{
  group OS_DMACH9SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH9SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH9SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMACH9SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMACH9SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH9SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMACH9SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMACH9SR_ISR_VAR_FAST"))
{
  group OS_DMACH9SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH9SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_FAST_GROUP";
  "_OS_DMACH9SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMACH9SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMACH9SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH9SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMACH9SR_ISR_VAR_NOCACHE"))
{
  group OS_DMACH9SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMACH9SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMACH9SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR
reserved ".pad.OS_DMACH9SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMACH9SR_ISR_VAR_ALL_GROUP */
"_OS_DMACH9SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMACH9SR_ISR_VAR_ALL_GROUP";
"_OS_DMACH9SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMACH9SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMACH9SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMACH9SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR
group OS_DMAERR0SR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_DMAERR0SR_ISR_VAR"))
{
  group OS_DMAERR0SR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMAERR0SR_ISR_VAR";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_DMAERR0SR_ISR_VAR_NOINIT"))
{
  group OS_DMAERR0SR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMAERR0SR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_NOINIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_NOINIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_NOINIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_DMAERR0SR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_DMAERR0SR_ISR_VAR_ZERO_INIT"))
{
  group OS_DMAERR0SR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMAERR0SR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_DMAERR0SR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_DMAERR0SR_ISR_VAR_FAST"))
{
  group OS_DMAERR0SR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMAERR0SR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_FAST" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_FAST_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_FAST_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_FAST";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_FAST_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_DMAERR0SR_ISR_VAR_FAST_NOINIT"))
{
  group OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMAERR0SR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_DMAERR0SR_ISR_VAR_NOCACHE"))
{
  group OS_DMAERR0SR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_DMAERR0SR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_NOCACHE_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_DMAERR0SR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR
reserved ".pad.OS_DMAERR0SR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_DMAERR0SR_ISR_VAR_ALL_GROUP */
"_OS_DMAERR0SR_ISR_VAR_ALL_START" = "_lc_gb_OS_DMAERR0SR_ISR_VAR_ALL_GROUP";
"_OS_DMAERR0SR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_DMAERR0SR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_DMAERR0SR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR
group OS_GTMATOM0SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMATOM0SR0_ISR_VAR"))
{
  group OS_GTMATOM0SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM0SR0_ISR_VAR";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMATOM0SR0_ISR_VAR_NOINIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM0SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST"))
{
  group OS_GTMATOM0SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_FAST_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_FAST";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMATOM0SR0_ISR_VAR_NOCACHE"))
{
  group OS_GTMATOM0SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM0SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR
reserved ".pad.OS_GTMATOM0SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMATOM0SR0_ISR_VAR_ALL_GROUP */
"_OS_GTMATOM0SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMATOM0SR0_ISR_VAR_ALL_GROUP";
"_OS_GTMATOM0SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMATOM0SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM0SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR
group OS_GTMATOM1SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMATOM1SR0_ISR_VAR"))
{
  group OS_GTMATOM1SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM1SR0_ISR_VAR";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMATOM1SR0_ISR_VAR_NOINIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM1SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST"))
{
  group OS_GTMATOM1SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_FAST_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_FAST";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMATOM1SR0_ISR_VAR_NOCACHE"))
{
  group OS_GTMATOM1SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM1SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM1SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR
reserved ".pad.OS_GTMATOM1SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMATOM1SR0_ISR_VAR_ALL_GROUP */
"_OS_GTMATOM1SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMATOM1SR0_ISR_VAR_ALL_GROUP";
"_OS_GTMATOM1SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMATOM1SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM1SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR
group OS_GTMATOM2SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMATOM2SR0_ISR_VAR"))
{
  group OS_GTMATOM2SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM2SR0_ISR_VAR";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMATOM2SR0_ISR_VAR_NOINIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM2SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST"))
{
  group OS_GTMATOM2SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_FAST_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_FAST";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMATOM2SR0_ISR_VAR_NOCACHE"))
{
  group OS_GTMATOM2SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM2SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM2SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR
reserved ".pad.OS_GTMATOM2SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMATOM2SR0_ISR_VAR_ALL_GROUP */
"_OS_GTMATOM2SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMATOM2SR0_ISR_VAR_ALL_GROUP";
"_OS_GTMATOM2SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMATOM2SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM2SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR
group OS_GTMATOM4SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMATOM4SR0_ISR_VAR"))
{
  group OS_GTMATOM4SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM4SR0_ISR_VAR";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMATOM4SR0_ISR_VAR_NOINIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM4SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST"))
{
  group OS_GTMATOM4SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_FAST_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_FAST";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMATOM4SR0_ISR_VAR_NOCACHE"))
{
  group OS_GTMATOM4SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMATOM4SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMATOM4SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR
reserved ".pad.OS_GTMATOM4SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMATOM4SR0_ISR_VAR_ALL_GROUP */
"_OS_GTMATOM4SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMATOM4SR0_ISR_VAR_ALL_GROUP";
"_OS_GTMATOM4SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMATOM4SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMATOM4SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR
group OS_GTMTIM2SR3_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMTIM2SR3_ISR_VAR"))
{
  group OS_GTMTIM2SR3_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTIM2SR3_ISR_VAR";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMTIM2SR3_ISR_VAR_NOINIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR3_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST"))
{
  group OS_GTMTIM2SR3_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_FAST_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_FAST";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMTIM2SR3_ISR_VAR_NOCACHE"))
{
  group OS_GTMTIM2SR3_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTIM2SR3_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR
reserved ".pad.OS_GTMTIM2SR3_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMTIM2SR3_ISR_VAR_ALL_GROUP */
"_OS_GTMTIM2SR3_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMTIM2SR3_ISR_VAR_ALL_GROUP";
"_OS_GTMTIM2SR3_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMTIM2SR3_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR3_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR
group OS_GTMTIM2SR5_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMTIM2SR5_ISR_VAR"))
{
  group OS_GTMTIM2SR5_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTIM2SR5_ISR_VAR";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMTIM2SR5_ISR_VAR_NOINIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR5_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST"))
{
  group OS_GTMTIM2SR5_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_FAST_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_FAST";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMTIM2SR5_ISR_VAR_NOCACHE"))
{
  group OS_GTMTIM2SR5_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTIM2SR5_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTIM2SR5_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR
reserved ".pad.OS_GTMTIM2SR5_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMTIM2SR5_ISR_VAR_ALL_GROUP */
"_OS_GTMTIM2SR5_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMTIM2SR5_ISR_VAR_ALL_GROUP";
"_OS_GTMTIM2SR5_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMTIM2SR5_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTIM2SR5_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR
group OS_GTMTOM0SR0_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMTOM0SR0_ISR_VAR"))
{
  group OS_GTMTOM0SR0_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR0_ISR_VAR";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR0_ISR_VAR_NOINIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR0_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST"))
{
  group OS_GTMTOM0SR0_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_FAST_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_FAST";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMTOM0SR0_ISR_VAR_NOCACHE"))
{
  group OS_GTMTOM0SR0_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR0_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR0_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR
reserved ".pad.OS_GTMTOM0SR0_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMTOM0SR0_ISR_VAR_ALL_GROUP */
"_OS_GTMTOM0SR0_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMTOM0SR0_ISR_VAR_ALL_GROUP";
"_OS_GTMTOM0SR0_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMTOM0SR0_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR0_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR
group OS_GTMTOM0SR1_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMTOM0SR1_ISR_VAR"))
{
  group OS_GTMTOM0SR1_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR1_ISR_VAR";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR1_ISR_VAR_NOINIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR1_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST"))
{
  group OS_GTMTOM0SR1_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_FAST_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_FAST";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMTOM0SR1_ISR_VAR_NOCACHE"))
{
  group OS_GTMTOM0SR1_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR1_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR1_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR
reserved ".pad.OS_GTMTOM0SR1_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMTOM0SR1_ISR_VAR_ALL_GROUP */
"_OS_GTMTOM0SR1_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMTOM0SR1_ISR_VAR_ALL_GROUP";
"_OS_GTMTOM0SR1_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMTOM0SR1_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR1_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR
group OS_GTMTOM0SR2_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMTOM0SR2_ISR_VAR"))
{
  group OS_GTMTOM0SR2_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR2_ISR_VAR";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR2_ISR_VAR_NOINIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR2_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST"))
{
  group OS_GTMTOM0SR2_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_FAST_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_FAST";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMTOM0SR2_ISR_VAR_NOCACHE"))
{
  group OS_GTMTOM0SR2_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR2_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR2_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR
reserved ".pad.OS_GTMTOM0SR2_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMTOM0SR2_ISR_VAR_ALL_GROUP */
"_OS_GTMTOM0SR2_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMTOM0SR2_ISR_VAR_ALL_GROUP";
"_OS_GTMTOM0SR2_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMTOM0SR2_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR2_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR
group OS_GTMTOM0SR3_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_GTMTOM0SR3_ISR_VAR"))
{
  group OS_GTMTOM0SR3_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR3_ISR_VAR";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR3_ISR_VAR_NOINIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR3_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_NOINIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_NOINIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_NOINIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST"))
{
  group OS_GTMTOM0SR3_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_FAST" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_FAST_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_FAST";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_GTMTOM0SR3_ISR_VAR_NOCACHE"))
{
  group OS_GTMTOM0SR3_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_GTMTOM0SR3_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE"))
{
  group OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_GTMTOM0SR3_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR
reserved ".pad.OS_GTMTOM0SR3_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_GTMTOM0SR3_ISR_VAR_ALL_GROUP */
"_OS_GTMTOM0SR3_ISR_VAR_ALL_START" = "_lc_gb_OS_GTMTOM0SR3_ISR_VAR_ALL_GROUP";
"_OS_GTMTOM0SR3_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_GTMTOM0SR3_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_GTMTOM0SR3_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR
group OS_QSPI0ERR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI0ERR_ISR_VAR"))
{
  group OS_QSPI0ERR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI0ERR_ISR_VAR";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI0ERR_ISR_VAR_NOINIT"))
{
  group OS_QSPI0ERR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0ERR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI0ERR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI0ERR_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI0ERR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0ERR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI0ERR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI0ERR_ISR_VAR_FAST"))
{
  group OS_QSPI0ERR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI0ERR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_FAST_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI0ERR_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0ERR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI0ERR_ISR_VAR_NOCACHE"))
{
  group OS_QSPI0ERR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI0ERR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI0ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR
reserved ".pad.OS_QSPI0ERR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI0ERR_ISR_VAR_ALL_GROUP */
"_OS_QSPI0ERR_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI0ERR_ISR_VAR_ALL_GROUP";
"_OS_QSPI0ERR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI0ERR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0ERR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR
group OS_QSPI0PT_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI0PT_ISR_VAR"))
{
  group OS_QSPI0PT_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI0PT_ISR_VAR";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_GROUP";
  "_OS_QSPI0PT_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI0PT_ISR_VAR_NOINIT"))
{
  group OS_QSPI0PT_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0PT_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI0PT_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI0PT_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI0PT_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0PT_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI0PT_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI0PT_ISR_VAR_FAST"))
{
  group OS_QSPI0PT_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI0PT_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_FAST_GROUP";
  "_OS_QSPI0PT_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI0PT_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI0PT_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0PT_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI0PT_ISR_VAR_NOCACHE"))
{
  group OS_QSPI0PT_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI0PT_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI0PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR
reserved ".pad.OS_QSPI0PT_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI0PT_ISR_VAR_ALL_GROUP */
"_OS_QSPI0PT_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI0PT_ISR_VAR_ALL_GROUP";
"_OS_QSPI0PT_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI0PT_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI0PT_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI0PT_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR
group OS_QSPI1ERR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI1ERR_ISR_VAR"))
{
  group OS_QSPI1ERR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI1ERR_ISR_VAR";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI1ERR_ISR_VAR_NOINIT"))
{
  group OS_QSPI1ERR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1ERR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI1ERR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI1ERR_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI1ERR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1ERR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI1ERR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI1ERR_ISR_VAR_FAST"))
{
  group OS_QSPI1ERR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI1ERR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_FAST_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI1ERR_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1ERR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI1ERR_ISR_VAR_NOCACHE"))
{
  group OS_QSPI1ERR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI1ERR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI1ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR
reserved ".pad.OS_QSPI1ERR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI1ERR_ISR_VAR_ALL_GROUP */
"_OS_QSPI1ERR_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI1ERR_ISR_VAR_ALL_GROUP";
"_OS_QSPI1ERR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI1ERR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1ERR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR
group OS_QSPI1PT_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI1PT_ISR_VAR"))
{
  group OS_QSPI1PT_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI1PT_ISR_VAR";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_GROUP";
  "_OS_QSPI1PT_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI1PT_ISR_VAR_NOINIT"))
{
  group OS_QSPI1PT_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1PT_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI1PT_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI1PT_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI1PT_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1PT_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI1PT_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI1PT_ISR_VAR_FAST"))
{
  group OS_QSPI1PT_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI1PT_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_FAST_GROUP";
  "_OS_QSPI1PT_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI1PT_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI1PT_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1PT_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI1PT_ISR_VAR_NOCACHE"))
{
  group OS_QSPI1PT_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI1PT_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI1PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR
reserved ".pad.OS_QSPI1PT_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI1PT_ISR_VAR_ALL_GROUP */
"_OS_QSPI1PT_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI1PT_ISR_VAR_ALL_GROUP";
"_OS_QSPI1PT_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI1PT_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI1PT_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI1PT_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR
group OS_QSPI2ERR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI2ERR_ISR_VAR"))
{
  group OS_QSPI2ERR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI2ERR_ISR_VAR";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI2ERR_ISR_VAR_NOINIT"))
{
  group OS_QSPI2ERR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2ERR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI2ERR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI2ERR_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI2ERR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2ERR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI2ERR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI2ERR_ISR_VAR_FAST"))
{
  group OS_QSPI2ERR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI2ERR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_FAST_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI2ERR_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2ERR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI2ERR_ISR_VAR_NOCACHE"))
{
  group OS_QSPI2ERR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI2ERR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI2ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR
reserved ".pad.OS_QSPI2ERR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI2ERR_ISR_VAR_ALL_GROUP */
"_OS_QSPI2ERR_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI2ERR_ISR_VAR_ALL_GROUP";
"_OS_QSPI2ERR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI2ERR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2ERR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR
group OS_QSPI2PT_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI2PT_ISR_VAR"))
{
  group OS_QSPI2PT_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI2PT_ISR_VAR";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_GROUP";
  "_OS_QSPI2PT_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI2PT_ISR_VAR_NOINIT"))
{
  group OS_QSPI2PT_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2PT_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI2PT_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI2PT_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI2PT_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2PT_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI2PT_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI2PT_ISR_VAR_FAST"))
{
  group OS_QSPI2PT_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI2PT_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_FAST_GROUP";
  "_OS_QSPI2PT_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI2PT_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI2PT_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2PT_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI2PT_ISR_VAR_NOCACHE"))
{
  group OS_QSPI2PT_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI2PT_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI2PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR
reserved ".pad.OS_QSPI2PT_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI2PT_ISR_VAR_ALL_GROUP */
"_OS_QSPI2PT_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI2PT_ISR_VAR_ALL_GROUP";
"_OS_QSPI2PT_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI2PT_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI2PT_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI2PT_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR
group OS_QSPI3ERR_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI3ERR_ISR_VAR"))
{
  group OS_QSPI3ERR_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI3ERR_ISR_VAR";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI3ERR_ISR_VAR_NOINIT"))
{
  group OS_QSPI3ERR_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3ERR_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI3ERR_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI3ERR_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI3ERR_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3ERR_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI3ERR_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI3ERR_ISR_VAR_FAST"))
{
  group OS_QSPI3ERR_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI3ERR_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_FAST_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI3ERR_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3ERR_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI3ERR_ISR_VAR_NOCACHE"))
{
  group OS_QSPI3ERR_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI3ERR_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI3ERR_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR
reserved ".pad.OS_QSPI3ERR_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI3ERR_ISR_VAR_ALL_GROUP */
"_OS_QSPI3ERR_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI3ERR_ISR_VAR_ALL_GROUP";
"_OS_QSPI3ERR_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI3ERR_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3ERR_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR
group OS_QSPI3PT_ISR_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_INIT )
if (exists(".data.OS_QSPI3PT_ISR_VAR"))
{
  group OS_QSPI3PT_ISR_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI3PT_ISR_VAR";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_GROUP";
  "_OS_QSPI3PT_ISR_VAR_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_NOINIT )
if (exists(".bss.OS_QSPI3PT_ISR_VAR_NOINIT"))
{
  group OS_QSPI3PT_ISR_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3PT_ISR_VAR_NOINIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_NOINIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_NOINIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_NOINIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_NOINIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_NOINIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_NOINIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI3PT_ISR_VAR_ZERO_INIT_bss") || exists(".data.OS_QSPI3PT_ISR_VAR_ZERO_INIT"))
{
  group OS_QSPI3PT_ISR_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3PT_ISR_VAR_ZERO_INIT_bss";
      select ".data.OS_QSPI3PT_ISR_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_ZERO_INIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_ZERO_INIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_ZERO_INIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_ZERO_INIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_INIT )
if (exists(".zdata.OS_QSPI3PT_ISR_VAR_FAST"))
{
  group OS_QSPI3PT_ISR_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI3PT_ISR_VAR_FAST";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_FAST" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_FAST_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_FAST_GROUP";
  "_OS_QSPI3PT_ISR_VAR_FAST_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_FAST";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_FAST_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_QSPI3PT_ISR_VAR_FAST_NOINIT"))
{
  group OS_QSPI3PT_ISR_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3PT_ISR_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_FAST_NOINIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_FAST_NOINIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_FAST_NOINIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_FAST_NOINIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT"))
{
  group OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_INIT )
if (exists(".data.OS_QSPI3PT_ISR_VAR_NOCACHE"))
{
  group OS_QSPI3PT_ISR_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_QSPI3PT_ISR_VAR_NOCACHE";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_NOCACHE" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_NOCACHE_GROUP";
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_NOCACHE";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT"))
{
  group OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE"))
{
  group OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_GROUP";
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_QSPI3PT_ISR_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR
reserved ".pad.OS_QSPI3PT_ISR_VAR_ALL_GROUP" (size=16);
} /* OS_QSPI3PT_ISR_VAR_ALL_GROUP */
"_OS_QSPI3PT_ISR_VAR_ALL_START" = "_lc_gb_OS_QSPI3PT_ISR_VAR_ALL_GROUP";
"_OS_QSPI3PT_ISR_VAR_ALL_END" = "_lc_ub__pad_OS_QSPI3PT_ISR_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_QSPI3PT_ISR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_QSPI3PT_ISR_NEAR_NOCACHE_ZERO_INIT
#endif



#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0
group OS_XSignalIsr_OsCore0_VAR_ALL_GROUP(ordered, contiguous, fill, align=8)
{
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_INIT )
if (exists(".data.OS_XSignalIsr_OsCore0_VAR"))
{
  group OS_XSignalIsr_OsCore0_VAR_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_XSignalIsr_OsCore0_VAR";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_NOINIT )
if (exists(".bss.OS_XSignalIsr_OsCore0_VAR_NOINIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_XSignalIsr_OsCore0_VAR_NOINIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_NOINIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_NOINIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_NOINIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_NOINIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_NOINIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_NOINIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_ZERO_INIT )
if (exists(".bss.OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_bss") || exists(".data.OS_XSignalIsr_OsCore0_VAR_ZERO_INIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_bss";
      select ".data.OS_XSignalIsr_OsCore0_VAR_ZERO_INIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_ZERO_INIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_ZERO_INIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_INIT )
if (exists(".zdata.OS_XSignalIsr_OsCore0_VAR_FAST"))
{
  group OS_XSignalIsr_OsCore0_VAR_FAST_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_FAST_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_XSignalIsr_OsCore0_VAR_FAST";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_FAST" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_FAST_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_FAST_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_FAST_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_FAST";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_FAST_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_FAST_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_NOINIT )
if (exists(".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_ZERO_INIT )
if (exists(".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_bss") || exists(".zdata.OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_bss";
      select ".zdata.OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_FAST_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_INIT )
if (exists(".data.OS_XSignalIsr_OsCore0_VAR_NOCACHE"))
{
  group OS_XSignalIsr_OsCore0_VAR_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".data.OS_XSignalIsr_OsCore0_VAR_NOCACHE";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_NOCACHE" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_NOCACHE_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_NOCACHE";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_NOINIT )
if (exists(".bss.OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_ZERO_INIT )
if (exists(".bss.OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_bss") || exists(".data.OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".bss.OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_bss";
      select ".data.OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_INIT )
if (exists(".zdata.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE"))
{
  group OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zdata.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_NOINIT )
if (exists(".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_NOINIT_END" = 0;
}
#endif

#if defined ( OS_LINK_VAR ) || defined ( OS_LINK_VAR_ISR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0 ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE ) || defined ( OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_ZERO_INIT )
if (exists(".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss") || exists(".zdata.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT"))
{
  group OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP(ordered, contiguous, fill, align=8)
  {
    section "OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_SECTION" (blocksize=2, attributes=rw)
    {
      select ".zbss.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_bss";
      select ".zdata.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
    }
    reserved ".pad.OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT" (size=16);
  }
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_GROUP";
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT";
}
else
{
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_START" = 0;
  "_OS_XSignalIsr_OsCore0_VAR_FAST_NOCACHE_ZERO_INIT_END" = 0;
}
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0
reserved ".pad.OS_XSignalIsr_OsCore0_VAR_ALL_GROUP" (size=16);
} /* OS_XSignalIsr_OsCore0_VAR_ALL_GROUP */
"_OS_XSignalIsr_OsCore0_VAR_ALL_START" = "_lc_gb_OS_XSignalIsr_OsCore0_VAR_ALL_GROUP";
"_OS_XSignalIsr_OsCore0_VAR_ALL_END" = "_lc_ub__pad_OS_XSignalIsr_OsCore0_VAR_ALL_GROUP";

# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_FAR_NOCACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_CACHE_ZERO_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_ZERO_INIT
# undef OS_LINK_VAR_ISR_XSIGNALISR_OSCORE0_NEAR_NOCACHE_ZERO_INIT
#endif


#ifdef OS_LINK_VAR
# undef OS_LINK_VAR
#endif

#ifdef OS_LINK_VAR_APP
# undef OS_LINK_VAR_APP
#endif

#ifdef OS_LINK_VAR_TASK
# undef OS_LINK_VAR_TASK
#endif

#ifdef OS_LINK_VAR_ISR
# undef OS_LINK_VAR_ISR
#endif

#ifdef OS_LINK_KERNEL_TRACE
# undef OS_LINK_KERNEL_TRACE
#endif

#ifdef OS_LINK_KERNEL_TRACE_FAR
# undef OS_LINK_KERNEL_TRACE_FAR
#endif

#ifdef OS_LINK_KERNEL_TRACE_NEAR
# undef OS_LINK_KERNEL_TRACE_NEAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS
# undef OS_LINK_KERNEL_BARRIERS
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_FAR
# undef OS_LINK_KERNEL_BARRIERS_FAR
#endif

#ifdef OS_LINK_KERNEL_BARRIERS_NEAR
# undef OS_LINK_KERNEL_BARRIERS_NEAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS
# undef OS_LINK_KERNEL_CORESTATUS
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_FAR
# undef OS_LINK_KERNEL_CORESTATUS_FAR
#endif

#ifdef OS_LINK_KERNEL_CORESTATUS_NEAR
# undef OS_LINK_KERNEL_CORESTATUS_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL
# undef OS_LINK_VAR_KERNEL
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR
# undef OS_LINK_VAR_KERNEL_FAR
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE
# undef OS_LINK_VAR_KERNEL_FAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_FAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR
# undef OS_LINK_VAR_KERNEL_NEAR
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
# undef OS_LINK_VAR_KERNEL_NEAR_NOCACHE_NOINIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif

#ifdef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
# undef OS_LINK_VAR_KERNEL_NEAR_CACHE_INIT
#endif


