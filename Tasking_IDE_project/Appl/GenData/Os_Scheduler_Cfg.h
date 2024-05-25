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
 *              File: Os_Scheduler_Cfg.h
 *   Generation Time: 2023-03-21 20:44:22
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

#ifndef OS_SCHEDULER_CFG_H
# define OS_SCHEDULER_CFG_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*! Defines the number of all task queues. */
# define OS_CFG_NUM_TASKQUEUES                   (4u)

/* Number of task queue activation slots: OsCore0 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS     (2u)

/* Number of task queue activation slots: OsCore1 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE1_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE1_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE1_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE1_SLOTS     (2u)

/* Number of task queue activation slots: OsCore2 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE2_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE2_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE2_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE2_SLOTS     (2u)

/* Number of task queue activation slots: OsCore3 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE3_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE3_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE3_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE3_SLOTS     (2u)

/* Number of task queue activation slots: OsCore4 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE4_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE4_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE4_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE4_SLOTS     (2u)

/* Number of task queue activation slots: OsCore5 */
# define OS_CFG_NUM_TASKQUEUE0_OSCORE5_SLOTS     (3u)
# define OS_CFG_NUM_TASKQUEUE1_OSCORE5_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE2_OSCORE5_SLOTS     (2u)
# define OS_CFG_NUM_TASKQUEUE3_OSCORE5_SLOTS     (2u)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


#endif /* OS_SCHEDULER_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Cfg.h
 *********************************************************************************************************************/
