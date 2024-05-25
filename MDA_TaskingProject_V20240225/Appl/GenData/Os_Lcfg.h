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
 *              File: Os_Lcfg.h
 *   Generation Time: 2024-01-08 16:27:31
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

#ifndef OS_LCFG_H
# define OS_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Cfg.h"
# include "Os_Types.h"
# include "Os_Types_Lcfg.h"

/* Os kernel module dependencies */

/* Os hal dependencies */
# include "Os_Hal_Lcfg.h"

/* User file includes */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_APP_Task_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE0_CODE) Os_Task_APP_Task_Core0(void);

# define OS_STOP_SEC_APP_Task_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE1_CODE) Os_Task_APP_Task_Core1(void);

# define OS_STOP_SEC_APP_Task_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE2_CODE) Os_Task_APP_Task_Core2(void);

# define OS_STOP_SEC_APP_Task_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core3()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE3_CODE) Os_Task_APP_Task_Core3(void);

# define OS_STOP_SEC_APP_Task_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core4()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE4_CODE) Os_Task_APP_Task_Core4(void);

# define OS_STOP_SEC_APP_Task_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_APP_Task_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  APP_Task_Core5()
 *********************************************************************************************************************/
extern FUNC(void, OS_APP_TASK_CORE5_CODE) Os_Task_APP_Task_Core5(void);

# define OS_STOP_SEC_APP_Task_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Core_OsTask_CDD_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Core_OsTask_CDD()
 *********************************************************************************************************************/
extern FUNC(void, OS_CORE_OSTASK_CDD_CODE) Os_Task_Core_OsTask_CDD(void);

# define OS_STOP_SEC_Core_OsTask_CDD_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Core_OsTask_IOHW_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Core_OsTask_IOHW()
 *********************************************************************************************************************/
extern FUNC(void, OS_CORE_OSTASK_IOHW_CODE) Os_Task_Core_OsTask_IOHW(void);

# define OS_STOP_SEC_Core_OsTask_IOHW_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Core_OsTask_PSI5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Core_OsTask_PSI5()
 *********************************************************************************************************************/
extern FUNC(void, OS_CORE_OSTASK_PSI5_CODE) Os_Task_Core_OsTask_PSI5(void);

# define OS_STOP_SEC_Core_OsTask_PSI5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Core_OsTask_PT2000_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Core_OsTask_PT2000()
 *********************************************************************************************************************/
extern FUNC(void, OS_CORE_OSTASK_PT2000_CODE) Os_Task_Core_OsTask_PT2000(void);

# define OS_STOP_SEC_Core_OsTask_PT2000_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE0_CODE) Os_Task_Init_Core0(void);

# define OS_STOP_SEC_Init_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE1_CODE) Os_Task_Init_Core1(void);

# define OS_STOP_SEC_Init_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE2_CODE) Os_Task_Init_Core2(void);

# define OS_STOP_SEC_Init_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core3()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE3_CODE) Os_Task_Init_Core3(void);

# define OS_STOP_SEC_Init_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core4()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE4_CODE) Os_Task_Init_Core4(void);

# define OS_STOP_SEC_Init_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_Init_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  Init_Core5()
 *********************************************************************************************************************/
extern FUNC(void, OS_INIT_CORE5_CODE) Os_Task_Init_Core5(void);

# define OS_STOP_SEC_Init_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core0()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE0_CODE) Os_Task_SchM_Core0(void);

# define OS_STOP_SEC_SchM_Core0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core1()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE1_CODE) Os_Task_SchM_Core1(void);

# define OS_STOP_SEC_SchM_Core1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core2()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE2_CODE) Os_Task_SchM_Core2(void);

# define OS_STOP_SEC_SchM_Core2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core3()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE3_CODE) Os_Task_SchM_Core3(void);

# define OS_STOP_SEC_SchM_Core3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core4()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE4_CODE) Os_Task_SchM_Core4(void);

# define OS_STOP_SEC_SchM_Core4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_SchM_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  SchM_Core5()
 *********************************************************************************************************************/
extern FUNC(void, OS_SCHM_CORE5_CODE) Os_Task_SchM_Core5(void);

# define OS_STOP_SEC_SchM_Core5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC0SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC0SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC0SR0_ISR_CODE) Os_Isr_ADC0SR0_ISR(void);

# define OS_STOP_SEC_ADC0SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC1SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC1SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC1SR0_ISR_CODE) Os_Isr_ADC1SR0_ISR(void);

# define OS_STOP_SEC_ADC1SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC2SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC2SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC2SR0_ISR_CODE) Os_Isr_ADC2SR0_ISR(void);

# define OS_STOP_SEC_ADC2SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC3SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC3SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC3SR0_ISR_CODE) Os_Isr_ADC3SR0_ISR(void);

# define OS_STOP_SEC_ADC3SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_ADC8SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  ADC8SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_ADC8SR0_ISR_CODE) Os_Isr_ADC8SR0_ISR(void);

# define OS_STOP_SEC_ADC8SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_0()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_0_CODE) Os_Isr_CanIsr_0(void);

# define OS_STOP_SEC_CanIsr_0_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_1()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_1_CODE) Os_Isr_CanIsr_1(void);

# define OS_STOP_SEC_CanIsr_1_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_2()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_2_CODE) Os_Isr_CanIsr_2(void);

# define OS_STOP_SEC_CanIsr_2_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_3()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_3_CODE) Os_Isr_CanIsr_3(void);

# define OS_STOP_SEC_CanIsr_3_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_4()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_4_CODE) Os_Isr_CanIsr_4(void);

# define OS_STOP_SEC_CanIsr_4_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CanIsr_5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  CanIsr_5()
 *********************************************************************************************************************/
extern FUNC(void, OS_CANISR_5_CODE) Os_Isr_CanIsr_5(void);

# define OS_STOP_SEC_CanIsr_5_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH0SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH0SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH0SR_ISR_CODE) Os_Isr_DMACH0SR_ISR(void);

# define OS_STOP_SEC_DMACH0SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH3SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH3SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH3SR_ISR_CODE) Os_Isr_DMACH3SR_ISR(void);

# define OS_STOP_SEC_DMACH3SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH4SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH4SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH4SR_ISR_CODE) Os_Isr_DMACH4SR_ISR(void);

# define OS_STOP_SEC_DMACH4SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH5SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH5SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH5SR_ISR_CODE) Os_Isr_DMACH5SR_ISR(void);

# define OS_STOP_SEC_DMACH5SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH6SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH6SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH6SR_ISR_CODE) Os_Isr_DMACH6SR_ISR(void);

# define OS_STOP_SEC_DMACH6SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH7SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH7SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH7SR_ISR_CODE) Os_Isr_DMACH7SR_ISR(void);

# define OS_STOP_SEC_DMACH7SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH8SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH8SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH8SR_ISR_CODE) Os_Isr_DMACH8SR_ISR(void);

# define OS_STOP_SEC_DMACH8SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMACH9SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMACH9SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMACH9SR_ISR_CODE) Os_Isr_DMACH9SR_ISR(void);

# define OS_STOP_SEC_DMACH9SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_DMAERR0SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  DMAERR0SR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_DMAERR0SR_ISR_CODE) Os_Isr_DMAERR0SR_ISR(void);

# define OS_STOP_SEC_DMAERR0SR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMATOM0SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMATOM0SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMATOM0SR0_ISR_CODE) Os_Isr_GTMATOM0SR0_ISR(void);

# define OS_STOP_SEC_GTMATOM0SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMATOM1SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMATOM1SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMATOM1SR0_ISR_CODE) Os_Isr_GTMATOM1SR0_ISR(void);

# define OS_STOP_SEC_GTMATOM1SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMATOM2SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMATOM2SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMATOM2SR0_ISR_CODE) Os_Isr_GTMATOM2SR0_ISR(void);

# define OS_STOP_SEC_GTMATOM2SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMATOM4SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMATOM4SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMATOM4SR0_ISR_CODE) Os_Isr_GTMATOM4SR0_ISR(void);

# define OS_STOP_SEC_GTMATOM4SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTIM2SR3_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTIM2SR3_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTIM2SR3_ISR_CODE) Os_Isr_GTMTIM2SR3_ISR(void);

# define OS_STOP_SEC_GTMTIM2SR3_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTIM2SR5_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTIM2SR5_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTIM2SR5_ISR_CODE) Os_Isr_GTMTIM2SR5_ISR(void);

# define OS_STOP_SEC_GTMTIM2SR5_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTOM0SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTOM0SR0_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTOM0SR0_ISR_CODE) Os_Isr_GTMTOM0SR0_ISR(void);

# define OS_STOP_SEC_GTMTOM0SR0_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTOM0SR1_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTOM0SR1_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTOM0SR1_ISR_CODE) Os_Isr_GTMTOM0SR1_ISR(void);

# define OS_STOP_SEC_GTMTOM0SR1_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTOM0SR2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTOM0SR2_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTOM0SR2_ISR_CODE) Os_Isr_GTMTOM0SR2_ISR(void);

# define OS_STOP_SEC_GTMTOM0SR2_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_GTMTOM0SR3_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  GTMTOM0SR3_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_GTMTOM0SR3_ISR_CODE) Os_Isr_GTMTOM0SR3_ISR(void);

# define OS_STOP_SEC_GTMTOM0SR3_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI0ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI0ERR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI0ERR_ISR_CODE) Os_Isr_QSPI0ERR_ISR(void);

# define OS_STOP_SEC_QSPI0ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI0PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI0PT_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI0PT_ISR_CODE) Os_Isr_QSPI0PT_ISR(void);

# define OS_STOP_SEC_QSPI0PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI1ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI1ERR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI1ERR_ISR_CODE) Os_Isr_QSPI1ERR_ISR(void);

# define OS_STOP_SEC_QSPI1ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI1PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI1PT_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI1PT_ISR_CODE) Os_Isr_QSPI1PT_ISR(void);

# define OS_STOP_SEC_QSPI1PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI2ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI2ERR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI2ERR_ISR_CODE) Os_Isr_QSPI2ERR_ISR(void);

# define OS_STOP_SEC_QSPI2ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI2PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI2PT_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI2PT_ISR_CODE) Os_Isr_QSPI2PT_ISR(void);

# define OS_STOP_SEC_QSPI2PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI3ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI3ERR_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI3ERR_ISR_CODE) Os_Isr_QSPI3ERR_ISR(void);

# define OS_STOP_SEC_QSPI3ERR_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_QSPI3PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 *  QSPI3PT_ISR()
 *********************************************************************************************************************/
extern FUNC(void, OS_QSPI3PT_ISR_CODE) Os_Isr_QSPI3PT_ISR(void);

# define OS_STOP_SEC_QSPI3PT_ISR_CODE
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Lcfg.h
 *********************************************************************************************************************/
