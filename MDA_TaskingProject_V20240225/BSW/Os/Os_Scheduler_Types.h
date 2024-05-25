/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Scheduler
 * \{
 *
 * \file
 * \brief       Data types provided by \ref Os_Scheduler.
 *  \details    --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SCHEDULER_TYPES_H
# define OS_SCHEDULER_TYPES_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Scheduling priority of a task:
 * - higher values represent lower priorities.
 * - Zero means top task priority
 * - Priorities are used by:
 *   - Tasks
 *   - Resources
 *   - Semaphores
 *   - Spinlocks
 * - ready tasks are scheduled at their home priority
 * - running tasks which hold no lock (resource, semaphore, spinlock) are scheduled on their running priority, which
 *    reflects:
 *   - The resource priority of an internal resource, configured for the task
 *   - The preemptiveness of the task (non-preemptive tasks run at highest priority: 0)
 * - running tasks which hold a resource, semaphore or spinlock are scheduled on their current priority which is the
 *   highest priority of:
 *   - the running priority
 *   - the priorities of all resources, semaphores and spinlocks, the task currently holds
 * - Resources share their priority with the highest priority task on this core which is allowed to access the resource
 * - Semaphores/spinlocks may share their priority with the globally highest priority task which is allowed to access
 *   the semaphore/spinlock
 * - Semaphores/spinlocks may have even higher priority than described above because of priority boost
 */
typedef uint16 Os_TaskPrioType;


struct Os_SchedulerType_Tag;
struct Os_SchedulerConfigType_Tag;

/*! Dynamic management information of a scheduler. */
typedef struct Os_SchedulerType_Tag Os_SchedulerType;

/*! Configuration information of a scheduler. */
typedef struct Os_SchedulerConfigType_Tag Os_SchedulerConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/



#endif /* OS_SCHEDULER_TYPES_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Scheduler_Types.h
 **********************************************************************************************************************/
