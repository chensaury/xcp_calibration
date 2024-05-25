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
 *              File: Os_Scheduler_Lcfg.c
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

/* PRQA S 0777, 0779, 0828 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */

#define OS_SCHEDULER_LCFG_SOURCE

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Scheduler_Cfg.h"
#include "Os_Scheduler_Lcfg.h"
#include "Os_Scheduler.h"

/* Os kernel module dependencies */
#include "Os_BitArray.h"
#include "Os_Common.h"
#include "Os_Deque.h"

/* Os hal dependencies */


/**********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic scheduler data: OsCore0 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore0_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore0_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore0_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore0 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore0_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore0_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS];

#define OS_STOP_SEC_CORE0_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic scheduler data: OsCore1 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore1_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore1_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore1_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore1 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE1_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore1_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore1_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE1_SLOTS];

#define OS_STOP_SEC_CORE1_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic scheduler data: OsCore2 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore2_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore2_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore2_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore2 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE2_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore2_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore2_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE2_SLOTS];

#define OS_STOP_SEC_CORE2_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic scheduler data: OsCore3 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore3_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore3_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore3_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore3 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE3_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore3_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore3_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE3_SLOTS];

#define OS_STOP_SEC_CORE3_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic scheduler data: OsCore4 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore4_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore4_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore4_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore4 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE4_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore4_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore4_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE4_SLOTS];

#define OS_STOP_SEC_CORE4_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Dynamic scheduler data: OsCore5 */
OS_LOCAL VAR(Os_SchedulerType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore5_Dyn;
OS_LOCAL VAR(Os_BitArrayType, OS_VAR_NOINIT) OsCfg_Scheduler_OsCore5_BitArray_Dyn;
OS_LOCAL OS_BITARRAY_DECLARE(OsCfg_Scheduler_OsCore5_BitField_Dyn, OS_CFG_NUM_TASKQUEUES, OS_VAR_NOINIT);

/*! Dynamic task queues data: OsCore5 */
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue0_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes0_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE0_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue1_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes1_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE1_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue2_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes2_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE2_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue3_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes3_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE3_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue4_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes4_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE4_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue5_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes5_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE5_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue6_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes6_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE6_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue7_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes7_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE7_OSCORE5_SLOTS];
OS_LOCAL VAR(Os_DequeType, OS_VAR_NOINIT) OsCfg_TaskQueue8_OsCore5_Dyn;
OS_LOCAL VAR(Os_DequeNodeType, OS_VAR_NOINIT)
  OsCfg_TaskQueueNodes8_OsCore5_Dyn[OS_CFG_NUM_TASKQUEUE8_OSCORE5_SLOTS];

#define OS_STOP_SEC_CORE5_VAR_NOINIT_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT DATA
 *********************************************************************************************************************/

#define OS_START_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task queues configuration data: OsCore0 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore0_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE0_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE0_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE0_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE0_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE0_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE0_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE0_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE0_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore0_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore0_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE0_SLOTS
  }
};

/*! Scheduler configuration data: OsCore0 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore0 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore0_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore0_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore0_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore0_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE0_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task queues configuration data: OsCore1 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore1_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE1_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE1_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE1_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE1_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE1_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE1_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE1_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE1_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore1_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore1_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE1_SLOTS
  }
};

/*! Scheduler configuration data: OsCore1 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore1 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore1_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore1_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore1_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore1_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE1_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task queues configuration data: OsCore2 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore2_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE2_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE2_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE2_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE2_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE2_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE2_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE2_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE2_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore2_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore2_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE2_SLOTS
  }
};

/*! Scheduler configuration data: OsCore2 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore2 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore2_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore2_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore2_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore2_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE2_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task queues configuration data: OsCore3 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore3_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE3_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE3_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE3_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE3_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE3_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE3_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE3_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE3_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore3_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore3_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE3_SLOTS
  }
};

/*! Scheduler configuration data: OsCore3 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore3 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore3_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore3_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore3_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore3_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE3_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task queues configuration data: OsCore4 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore4_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE4_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE4_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE4_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE4_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE4_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE4_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE4_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE4_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore4_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore4_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE4_SLOTS
  }
};

/*! Scheduler configuration data: OsCore4 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore4 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore4_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore4_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore4_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore4_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE4_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


#define OS_START_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/*! Task queues configuration data: OsCore5 */
OS_LOCAL CONST(Os_DequeConfigType, OS_CONST) OsCfg_Scheduler_OsCore5_TaskQueues[OS_CFG_NUM_TASKQUEUES] =
{
  /* [0] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue0_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes0_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE0_OSCORE5_SLOTS
  },
  /* [1] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue1_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes1_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE1_OSCORE5_SLOTS
  },
  /* [2] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue2_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes2_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE2_OSCORE5_SLOTS
  },
  /* [3] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue3_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes3_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE3_OSCORE5_SLOTS
  },
  /* [4] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue4_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes4_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE4_OSCORE5_SLOTS
  },
  /* [5] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue5_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes5_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE5_OSCORE5_SLOTS
  },
  /* [6] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue6_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes6_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE6_OSCORE5_SLOTS
  },
  /* [7] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue7_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes7_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE7_OSCORE5_SLOTS
  },
  /* [8] = */
  {
    /* .Dyn    = */ &OsCfg_TaskQueue8_OsCore5_Dyn,
    /* .Buffer = */ OsCfg_TaskQueueNodes8_OsCore5_Dyn,
    /* .Size   = */ OS_CFG_NUM_TASKQUEUE8_OSCORE5_SLOTS
  }
};

/*! Scheduler configuration data: OsCore5 */
CONST(Os_SchedulerConfigType, OS_CONST) OsCfg_Scheduler_OsCore5 =
{
  /* .BitArray           = */
  {
    /* .Dyn       = */ &OsCfg_Scheduler_OsCore5_BitArray_Dyn,
    /* .Data      = */ OsCfg_Scheduler_OsCore5_BitField_Dyn,
    /* .Size      = */ (uint16)OS_BITARRAY_SIZE(OS_CFG_NUM_TASKQUEUES),
    /* .BitLength = */ (uint16)OS_BITARRAY_LENGTH(OS_CFG_NUM_TASKQUEUES),
  },
  /* .Dyn                = */ &OsCfg_Scheduler_OsCore5_Dyn,
  /* .TaskQueues         = */ OsCfg_Scheduler_OsCore5_TaskQueues,
  /* .NumberOfPriorities = */ OS_CFG_NUM_TASKQUEUES
};

#define OS_STOP_SEC_CORE5_CONST_UNSPECIFIED
#include "Os_MemMap_OsSections.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */


/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Lcfg.c
 *********************************************************************************************************************/
