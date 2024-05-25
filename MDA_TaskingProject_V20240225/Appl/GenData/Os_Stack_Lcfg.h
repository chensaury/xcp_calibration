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
 *              File: Os_Stack_Lcfg.h
 *   Generation Time: 2024-01-08 16:27:33
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

#ifndef OS_STACK_LCFG_H
# define OS_STACK_LCFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Stack_Cfg.h"
# include "Os_Stack_Types.h"

/* Os kernel module dependencies */
# include "Os_Lcfg.h"

/* Os hal dependencies */


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

# define OS_START_SEC_STACK_CORE_OSTASK_IOHW_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: Core_OsTask_IOHW */
/* User: [Core_OsTask_IOHW] */
extern OS_STACK_DECLARE(OsCfg_Stack_Core_OsTask_IOHW_Dyn, OS_CFG_SIZE_CORE_OSTASK_IOHW_STACK);

# define OS_STOP_SEC_STACK_CORE_OSTASK_IOHW_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_CORE_OSTASK_PT2000_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: Core_OsTask_PT2000 */
/* User: [Core_OsTask_PT2000] */
extern OS_STACK_DECLARE(OsCfg_Stack_Core_OsTask_PT2000_Dyn, OS_CFG_SIZE_CORE_OSTASK_PT2000_STACK);

# define OS_STOP_SEC_STACK_CORE_OSTASK_PT2000_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore0_Init */
/* User: [OsCore0, Os_CoreInitHook_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Init_Dyn, OS_CFG_SIZE_OSCORE0_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore0_Isr_Core */
/* User: [CanIsr_4, CanIsr_5, CounterIsr_SystemTimer0, DMACH0SR_ISR, DMACH3SR_ISR, DMACH4SR_ISR, DMACH5SR_ISR, DMACH6SR_ISR, DMACH7SR_ISR, DMACH8SR_ISR, DMACH9SR_ISR, DMAERR0SR_ISR, GTMATOM0SR0_ISR, GTMATOM1SR0_ISR, GTMATOM2SR0_ISR, GTMATOM4SR0_ISR, GTMTIM2SR3_ISR, GTMTIM2SR5_ISR, GTMTOM0SR0_ISR, GTMTOM0SR1_ISR, GTMTOM0SR2_ISR, GTMTOM0SR3_ISR, QSPI0ERR_ISR, QSPI0PT_ISR, QSPI1ERR_ISR, QSPI1PT_ISR, QSPI2ERR_ISR, QSPI2PT_ISR, QSPI3ERR_ISR, QSPI3PT_ISR, XSignalIsr_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_LEVEL22_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared ISR level stack: OsCore0_Isr_Level22 */
/* User: [ADC0SR0_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Level22_Dyn, OS_CFG_SIZE_OSCORE0_ISR_LEVEL22_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_LEVEL22_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_LEVEL23_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared ISR level stack: OsCore0_Isr_Level23 */
/* User: [ADC1SR0_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Level23_Dyn, OS_CFG_SIZE_OSCORE0_ISR_LEVEL23_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_LEVEL23_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_LEVEL24_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared ISR level stack: OsCore0_Isr_Level24 */
/* User: [ADC2SR0_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Level24_Dyn, OS_CFG_SIZE_OSCORE0_ISR_LEVEL24_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_LEVEL24_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_LEVEL25_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared ISR level stack: OsCore0_Isr_Level25 */
/* User: [ADC3SR0_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Level25_Dyn, OS_CFG_SIZE_OSCORE0_ISR_LEVEL25_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_LEVEL25_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_ISR_LEVEL48_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared ISR level stack: OsCore0_Isr_Level48 */
/* User: [ADC8SR0_ISR] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Isr_Level48_Dyn, OS_CFG_SIZE_OSCORE0_ISR_LEVEL48_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_ISR_LEVEL48_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore0_Kernel */
/* User: [OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Kernel_Dyn, OS_CFG_SIZE_OSCORE0_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio100 */
/* User: [Init_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio4294967295 */
/* User: [IdleTask_OsCore0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO56_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio56 */
/* User: [Core_OsTask_CDD] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio56_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO56_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO56_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO59_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio59 */
/* User: [Core_OsTask_PSI5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio59_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO59_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO59_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE0_TASK_PRIO60_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore0_Task_Prio60 */
/* User: [APP_Task_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore0_Task_Prio60_Dyn, OS_CFG_SIZE_OSCORE0_TASK_PRIO60_STACK);

# define OS_STOP_SEC_STACK_OSCORE0_TASK_PRIO60_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore1_Init */
/* User: [OsCore1, Os_CoreInitHook_OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Init_Dyn, OS_CFG_SIZE_OSCORE1_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore1_Isr_Core */
/* User: [CanIsr_0, CounterIsr_SystemTimer1, XSignalIsr_OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE1_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore1_Kernel */
/* User: [OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Kernel_Dyn, OS_CFG_SIZE_OSCORE1_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio100 */
/* User: [Init_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio20 */
/* User: [SchM_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO20_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio4294967295 */
/* User: [IdleTask_OsCore1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore1_Task_Prio50 */
/* User: [APP_Task_Core1] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore1_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE1_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE1_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore2_Init */
/* User: [OsCore2, Os_CoreInitHook_OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Init_Dyn, OS_CFG_SIZE_OSCORE2_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore2_Isr_Core */
/* User: [CanIsr_1, CounterIsr_SystemTimer2, XSignalIsr_OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE2_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore2_Kernel */
/* User: [OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Kernel_Dyn, OS_CFG_SIZE_OSCORE2_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore2_Task_Prio100 */
/* User: [Init_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE2_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore2_Task_Prio20 */
/* User: [SchM_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE2_TASK_PRIO20_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore2_Task_Prio4294967295 */
/* User: [IdleTask_OsCore2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE2_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore2_Task_Prio50 */
/* User: [APP_Task_Core2] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore2_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE2_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE2_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore3_Init */
/* User: [OsCore3, Os_CoreInitHook_OsCore3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Init_Dyn, OS_CFG_SIZE_OSCORE3_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore3_Isr_Core */
/* User: [CanIsr_2, CounterIsr_SystemTimer3, XSignalIsr_OsCore3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE3_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore3_Kernel */
/* User: [OsCore3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Kernel_Dyn, OS_CFG_SIZE_OSCORE3_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore3_Task_Prio100 */
/* User: [Init_Core3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE3_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore3_Task_Prio20 */
/* User: [SchM_Core3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE3_TASK_PRIO20_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore3_Task_Prio4294967295 */
/* User: [IdleTask_OsCore3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE3_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE3_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore3_Task_Prio50 */
/* User: [APP_Task_Core3] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore3_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE3_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE3_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore4_Init */
/* User: [OsCore4, Os_CoreInitHook_OsCore4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Init_Dyn, OS_CFG_SIZE_OSCORE4_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore4_Isr_Core */
/* User: [CanIsr_3, CounterIsr_SystemTimer4, XSignalIsr_OsCore4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE4_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore4_Kernel */
/* User: [OsCore4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Kernel_Dyn, OS_CFG_SIZE_OSCORE4_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore4_Task_Prio100 */
/* User: [Init_Core4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE4_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore4_Task_Prio20 */
/* User: [SchM_Core4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE4_TASK_PRIO20_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore4_Task_Prio4294967295 */
/* User: [IdleTask_OsCore4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE4_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore4_Task_Prio50 */
/* User: [APP_Task_Core4] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore4_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE4_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE4_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core init stack: OsCore5_Init */
/* User: [OsCore5, Os_CoreInitHook_OsCore5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Init_Dyn, OS_CFG_SIZE_OSCORE5_INIT_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_INIT_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* ISR core global stack: OsCore5_Isr_Core */
/* User: [CounterIsr_SystemTimer5, XSignalIsr_OsCore5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Isr_Core_Dyn, OS_CFG_SIZE_OSCORE5_ISR_CORE_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_ISR_CORE_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Core kernel stack: OsCore5_Kernel */
/* User: [OsCore5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Kernel_Dyn, OS_CFG_SIZE_OSCORE5_KERNEL_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_KERNEL_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore5_Task_Prio100 */
/* User: [Init_Core5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Task_Prio100_Dyn, OS_CFG_SIZE_OSCORE5_TASK_PRIO100_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_TASK_PRIO100_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore5_Task_Prio20 */
/* User: [SchM_Core5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Task_Prio20_Dyn, OS_CFG_SIZE_OSCORE5_TASK_PRIO20_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_TASK_PRIO20_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore5_Task_Prio4294967295 */
/* User: [IdleTask_OsCore5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Task_Prio4294967295_Dyn, OS_CFG_SIZE_OSCORE5_TASK_PRIO4294967295_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_TASK_PRIO4294967295_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_OSCORE5_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: OsCore5_Task_Prio50 */
/* User: [APP_Task_Core5] */
extern OS_STACK_DECLARE(OsCfg_Stack_OsCore5_Task_Prio50_Dyn, OS_CFG_SIZE_OSCORE5_TASK_PRIO50_STACK);

# define OS_STOP_SEC_STACK_OSCORE5_TASK_PRIO50_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_STACK_SCHM_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* Shared Task stack: SchM_Core0 */
/* User: [SchM_Core0] */
extern OS_STACK_DECLARE(OsCfg_Stack_SchM_Core0_Dyn, OS_CFG_SIZE_SCHM_CORE0_STACK);

# define OS_STOP_SEC_STACK_SCHM_CORE0_VAR_NOINIT_UNSPECIFIED
# include "Os_MemMap_Stacks.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA PROTOTYPES
 *********************************************************************************************************************/

# define OS_START_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: Core_OsTask_IOHW */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Core_OsTask_IOHW;

/*! Stack configuration data: Core_OsTask_PT2000 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_Core_OsTask_PT2000;

/*! Stack configuration data: OsCore0_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Init;

/*! Stack configuration data: OsCore0_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Core;

/*! Stack configuration data: OsCore0_Isr_Level22 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Level22;

/*! Stack configuration data: OsCore0_Isr_Level23 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Level23;

/*! Stack configuration data: OsCore0_Isr_Level24 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Level24;

/*! Stack configuration data: OsCore0_Isr_Level25 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Level25;

/*! Stack configuration data: OsCore0_Isr_Level48 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Isr_Level48;

/*! Stack configuration data: OsCore0_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Kernel;

/*! Stack configuration data: OsCore0_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio100;

/*! Stack configuration data: OsCore0_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio4294967295;

/*! Stack configuration data: OsCore0_Task_Prio56 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio56;

/*! Stack configuration data: OsCore0_Task_Prio59 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio59;

/*! Stack configuration data: OsCore0_Task_Prio60 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore0_Task_Prio60;

/*! Stack configuration data: SchM_Core0 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_SchM_Core0;

# define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore1_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Init;

/*! Stack configuration data: OsCore1_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Isr_Core;

/*! Stack configuration data: OsCore1_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Kernel;

/*! Stack configuration data: OsCore1_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio100;

/*! Stack configuration data: OsCore1_Task_Prio20 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio20;

/*! Stack configuration data: OsCore1_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio4294967295;

/*! Stack configuration data: OsCore1_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore1_Task_Prio50;

# define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore2_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Init;

/*! Stack configuration data: OsCore2_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Isr_Core;

/*! Stack configuration data: OsCore2_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Kernel;

/*! Stack configuration data: OsCore2_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Task_Prio100;

/*! Stack configuration data: OsCore2_Task_Prio20 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Task_Prio20;

/*! Stack configuration data: OsCore2_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Task_Prio4294967295;

/*! Stack configuration data: OsCore2_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore2_Task_Prio50;

# define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore3_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Init;

/*! Stack configuration data: OsCore3_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Isr_Core;

/*! Stack configuration data: OsCore3_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Kernel;

/*! Stack configuration data: OsCore3_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Task_Prio100;

/*! Stack configuration data: OsCore3_Task_Prio20 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Task_Prio20;

/*! Stack configuration data: OsCore3_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Task_Prio4294967295;

/*! Stack configuration data: OsCore3_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore3_Task_Prio50;

# define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore4_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Init;

/*! Stack configuration data: OsCore4_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Isr_Core;

/*! Stack configuration data: OsCore4_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Kernel;

/*! Stack configuration data: OsCore4_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Task_Prio100;

/*! Stack configuration data: OsCore4_Task_Prio20 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Task_Prio20;

/*! Stack configuration data: OsCore4_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Task_Prio4294967295;

/*! Stack configuration data: OsCore4_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore4_Task_Prio50;

# define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


# define OS_START_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Stack configuration data: OsCore5_Init */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Init;

/*! Stack configuration data: OsCore5_Isr_Core */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Isr_Core;

/*! Stack configuration data: OsCore5_Kernel */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Kernel;

/*! Stack configuration data: OsCore5_Task_Prio100 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Task_Prio100;

/*! Stack configuration data: OsCore5_Task_Prio20 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Task_Prio20;

/*! Stack configuration data: OsCore5_Task_Prio4294967295 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Task_Prio4294967295;

/*! Stack configuration data: OsCore5_Task_Prio50 */
extern CONST(Os_StackConfigType, OS_CONST) OsCfg_Stack_OsCore5_Task_Prio50;

# define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
# include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* OS_STACK_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Lcfg.h
 *********************************************************************************************************************/
