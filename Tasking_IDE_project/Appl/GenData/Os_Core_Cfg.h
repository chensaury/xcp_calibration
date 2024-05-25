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
 *              File: Os_Core_Cfg.h
 *   Generation Time: 2023-04-13 21:53:52
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

#ifndef OS_CORE_CFG_H
# define OS_CORE_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines whether all the threads use the FPU unit (STD_ON) or not (STD_OFF). */
# define OS_CFG_THREAD_FPU_CONTEXT_FOR_ALL_THREADS_ENABLED       (STD_OFF)

/*! Defines whether the FPU context support is enabled (STD_ON) or not (STD_OFF). */
# define OS_CFG_THREAD_FPU_CONTEXT_ENABLED                       (STD_OFF)

/*! Defines whether at least for one core a PreStartTask is configured (STD_ON) or not (STD_OFF). */
# define OS_CFG_OS_PRESTARTTASK                                  (STD_OFF)

/*! Number of user barriers. */
# define OS_CFG_NUM_BARRIERS                                     (0uL)

/*! Number of ISR2 nesting levels. */
# define OS_CFG_NUM_ISRLEVELS                                    (3uL)

/*! Number of all spinlocks. */
# define OS_CFG_NUM_SYSTEM_SPINLOCKS                             (0uL)

/*! Number of physical core identifiers. */
# define OS_CFG_COREPHYSICALID_COUNT                             (7uL)

/* Number of core objects: OsCore0 */
# define OS_CFG_NUM_CORE_OSCORE0_APPS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE0_HOOKS            (2uL)
# define OS_CFG_NUM_CORE_OSCORE0_IOCS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE0_RESOURCES        (1uL)
# define OS_CFG_NUM_CORE_OSCORE0_STACKS           (8uL)
# define OS_CFG_NUM_CORE_OSCORE0_ISRS             (3uL)

/* Number of core objects: OsCore1 */
# define OS_CFG_NUM_CORE_OSCORE1_APPS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE1_HOOKS            (2uL)
# define OS_CFG_NUM_CORE_OSCORE1_IOCS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE1_RESOURCES        (1uL)
# define OS_CFG_NUM_CORE_OSCORE1_STACKS           (8uL)
# define OS_CFG_NUM_CORE_OSCORE1_ISRS             (2uL)

/* Number of core objects: OsCore2 */
# define OS_CFG_NUM_CORE_OSCORE2_APPS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE2_HOOKS            (2uL)
# define OS_CFG_NUM_CORE_OSCORE2_IOCS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE2_RESOURCES        (1uL)
# define OS_CFG_NUM_CORE_OSCORE2_STACKS           (8uL)
# define OS_CFG_NUM_CORE_OSCORE2_ISRS             (2uL)

/* Number of core objects: OsCore3 */
# define OS_CFG_NUM_CORE_OSCORE3_APPS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE3_HOOKS            (2uL)
# define OS_CFG_NUM_CORE_OSCORE3_IOCS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE3_RESOURCES        (1uL)
# define OS_CFG_NUM_CORE_OSCORE3_STACKS           (8uL)
# define OS_CFG_NUM_CORE_OSCORE3_ISRS             (2uL)

/* Number of core objects: OsCore4 */
# define OS_CFG_NUM_CORE_OSCORE4_APPS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE4_HOOKS            (2uL)
# define OS_CFG_NUM_CORE_OSCORE4_IOCS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE4_RESOURCES        (1uL)
# define OS_CFG_NUM_CORE_OSCORE4_STACKS           (8uL)
# define OS_CFG_NUM_CORE_OSCORE4_ISRS             (2uL)

/* Number of core objects: OsCore5 */
# define OS_CFG_NUM_CORE_OSCORE5_APPS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE5_HOOKS            (2uL)
# define OS_CFG_NUM_CORE_OSCORE5_IOCS             (0uL)
# define OS_CFG_NUM_CORE_OSCORE5_RESOURCES        (1uL)
# define OS_CFG_NUM_CORE_OSCORE5_STACKS           (8uL)
# define OS_CFG_NUM_CORE_OSCORE5_ISRS             (2uL)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_CORE_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Core_Cfg.h
 *********************************************************************************************************************/

