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
 *              File: Os_Stack_Cfg.h
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

#ifndef OS_STACK_CFG_H
# define OS_STACK_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether stack monitoring is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMONITORING                  (STD_ON)

/*! Defines whether stack measurement is active (STD_ON) or not (STD_OFF). */
# define OS_CFG_STACKMEASUREMENT                 (STD_OFF)

/* Configured stack sizes (Total: 52224 Byte) */
# define OS_CFG_SIZE_CORE_OSTASK_IOHW_STACK     (1024uL)
# define OS_CFG_SIZE_CORE_OSTASK_PT2000_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_LEVEL22_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_LEVEL23_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_LEVEL24_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_LEVEL25_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_ISR_LEVEL48_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO100_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO56_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO59_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE0_TASK_PRIO60_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_TASK_PRIO100_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_TASK_PRIO20_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE1_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_TASK_PRIO100_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_TASK_PRIO20_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE2_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_TASK_PRIO100_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_TASK_PRIO20_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE3_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_TASK_PRIO100_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_TASK_PRIO20_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE4_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_INIT_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_ISR_CORE_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_KERNEL_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_TASK_PRIO100_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_TASK_PRIO20_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_TASK_PRIO4294967295_STACK     (1024uL)
# define OS_CFG_SIZE_OSCORE5_TASK_PRIO50_STACK     (1024uL)
# define OS_CFG_SIZE_SCHM_CORE0_STACK     (1024uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_STACK_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Stack_Cfg.h
 *********************************************************************************************************************/
