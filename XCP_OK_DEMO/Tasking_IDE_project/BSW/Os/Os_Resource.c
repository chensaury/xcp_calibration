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
 * \addtogroup Os_Resource
 * \{
 *
 * \file
 * \brief       Resource API.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_RESOURCE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Resource.h"
#include "Os_Resource_Lcfg.h"

/* Os kernel module dependencies */
#include "Os_Lcfg.h"
#include "Os_Core.h"
#include "Os_Scheduler.h"
#include "Os_Task.h"
#include "Os_Isr.h"
#include "Os_Thread.h"
#include "Os_Trace.h"
#include "Os_Common_Types.h"
#include "Os_Error.h"
#include "Os_Interrupt.h"


/* Os hal dependencies */
#include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL DATA
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  Os_ResourceIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether any Resources are configured (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0  Resource module is enabled.
 *  \retval         0   Resource module is disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ResourceIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_ResourceGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic part of a resource.
 *  \details        --no details--
 *
 *  \param[in]      Resource  The resource to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_ResourceType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceGetDyn,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
));


/***********************************************************************************************************************
 *  Os_ResourceInterruptGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic part of a interrupt resource.
 *  \details        --no details--
 *
 *  \param[in]      Resource  The resource to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_ResourceInterruptType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceInterruptGetDyn,
(
  P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) Resource
));


/***********************************************************************************************************************
 *  Os_ResourceIsIntResource()
 **********************************************************************************************************************/
/*! \brief          Returns whether a resource is of type interrupt resource.
 *  \details        --no details--
 *
 *  \param[in]      Resource    The resource to query. Parameter must not be NULL.
 *
 *  \retval         !0  Given resource is an interrupt resource.
 *  \retval         0   Given resource is not an interrupt resource.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceIsIntResource,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
));


/***********************************************************************************************************************
 *  Os_ResourceCheckPrio()
 **********************************************************************************************************************/
/*! \brief          Returns whether the statically assigned scheduling priority of the current thread is logically
 *                  lower than or equal to the ceiling priority of the given resource.
 *  \details        Passes result of Os_ResourceIsCeilingPrioGe() to Os_ErrExtendedCheck().
 *
 *  \param[in]      Resource      The resource to query. Parameter must not be NULL.
 *  \param[in]      CurrentThread The current thread. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Priorities are okay.
 *  \retval         OS_CHECK_FAILED       Threads static priority is higher than ceiling priority of the resource.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceCheckPrio,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
));


/***********************************************************************************************************************
 *  Os_ResourceIsCeilingPrioGe()
 **********************************************************************************************************************/
/*! \brief          Returns whether the statically assigned priority of the given resource is logically
 *                  greater than or equal to the ceiling priority of the thread.
 *  \details        --no details--
 *
 *  \param[in]      Resource      The resource to query. Parameter must not be NULL.
 *  \param[in]      CurrentThread The current thread. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Priorities are okay.
 *  \retval         OS_CHECK_FAILED       Ceiling priority of the resource is lower than thread's home priority.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceIsCeilingPrioGe,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
));


/***********************************************************************************************************************
 *  Os_ResourceBaseIsCeilingPrioGe()
 **********************************************************************************************************************/
/*! \brief          Returns whether the statically assigned priority of the given resource is logically
 *                  greater than or equal to the ceiling scheduling priority of the thread.
 *  \details        --no details--
 *
 *  \param[in]      Resource      The resource to query. Parameter must not be NULL.
 *  \param[in]      CurrentThread The current thread. Parameter must not be NULL.
 *
 *  \retval         !0  The given thread is a task and its home priority is higher than the
 *                      ceiling priority of the resource.
 *  \retval         0   Ceiling priority of the resource is lower than thread's home priority.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceBaseIsCeilingPrioGe,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
));


/***********************************************************************************************************************
 *  Os_ResourceInterruptIsCeilingPrioGe()
 **********************************************************************************************************************/
/*! \brief          Returns whether the statically assigned priority of the given resource is logically
 *                  greater than or equal to the ceiling interrupt priority of the thread.
 *  \details        --no details--
 *
 *  \param[in]      Resource      The resource to query. Parameter must not be NULL.
 *  \param[in]      CurrentThread The current thread. Parameter must not be NULL.
 *
 *  \retval         !0  Priorities are okay.
 *  \retval         0   Ceiling priority of the resource is lower than thread's home priority.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceInterruptIsCeilingPrioGe,
(
  P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
));


/***********************************************************************************************************************
 *  Os_ResourceSaveAndIncrease()
 **********************************************************************************************************************/
/*! \brief          Increases the priority of the task to the ceiling priority of the given resource.
 *  \details        The priority is not changed, if the current priority is already logically higher or equal.
 *
 *  \param[in,out]  Resource    The resource to occupy. Parameter must not be NULL.
 *  \param[in,out]  Task        The task thread which wants the resource. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given thread is a task.
 *  \pre            Given thread is the current thread.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceSaveAndIncrease,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_ResourceRestore()
 **********************************************************************************************************************/
/*! \brief          Restores the previous priority before the task has occupied the resource.
 *  \details        The priority is not changed, if the previous priority is not logically lower than the
 *                  current priority.
 *
 *  \param[in,out]  Resource    The resource to query. Parameter must not be NULL.
 *  \param[in,out]  Task        The task which releases the resource. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given Task is the current task.
 *  \pre            Os_ResourceSaveAndIncrease was called before.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceRestore,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_ResourceInterruptSaveAndIncrease()
 **********************************************************************************************************************/
/*! \brief          Save the current interrupt priority in the given resource and increases the current interrupt
 *                  priority level to the interrupt priority level of the given interrupt resource.
 *  \details        The interrupt priority level is not changed, if the current level is already logically higher or
 *                  equal.
 *
 *  \param[in,out]  Resource              The resource to occupy. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceInterruptSaveAndIncrease,
(
  P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) Resource
));



/***********************************************************************************************************************
 *  Os_ResourceGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data of a resource.
 *  \details        --no details--
 *
 *  \param[in]      Resource    The resource to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The given object is a resource lock.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_ResourceType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceGetDyn,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
));


/***********************************************************************************************************************
 *  Os_ResourceLock2Resource()
 **********************************************************************************************************************/
/*! \brief        Returns the given lock as resource.
 *  \details      --no details--
 *
 *  \param[in]    Lock  The lock to query. Parameter must not be NULL.
 *
 *  \return       The given lock as resource.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given lock is resource.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceLock2Resource,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
));


/***********************************************************************************************************************
 *  Os_ResourceForceReleaseLocal()
 **********************************************************************************************************************/
/*! \brief          Releases the first lock of the given list as a resource.
 *  \details        --no details--
 *
 *  \param[in]      LockList  The LockList to query. Parameter must not be NULL.
 *  \param[in,out]  Thread    The thread which is forcibly terminated and needs its resources to be released.
 *                            Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      FALSE
 *  \synchronous    TRUE
 *
 *  \pre            The top element of the given lock is resource.
 *  \pre            Concurrent access to given objects is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceForceReleaseLocal,
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_Resource2ResourceInterrupt()
 **********************************************************************************************************************/
/*! \brief        Returns the given resource as an interrupt resource.
 *  \details      --no details--
 *
 *  \param[in]    Resource  The Resource to query. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          The given resource is interrupt resource.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Resource2ResourceInterrupt,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_ResourceIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_ResourceIsEnabled,
(
  void
))
{
   return (Os_StdReturnType)((uint16)OS_RESOURCEID_COUNT > 0u);                                                                 /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_ResourceGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_ResourceType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceGetDyn,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
))
{
  return (P2VAR(Os_ResourceType, AUTOMATIC, OS_VAR_NOINIT))Os_LockGetDyn(&(Resource->Lock));                            /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */

}


/***********************************************************************************************************************
 *  Os_ResourceInterruptGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_ResourceInterruptType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceInterruptGetDyn,
(
  P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) Resource
))
{
  return (P2VAR(Os_ResourceInterruptType, AUTOMATIC, OS_VAR_NOINIT))Os_ResourceGetDyn(&(Resource->Resource));           /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ResourceIsIntResource()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceIsIntResource,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
))
{
  return Os_LockIsIntResource(&(Resource->Lock));                                                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ResourceCheckPrio()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceCheckPrio,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
))
{
  return Os_ErrExtendedCheck(Os_ResourceIsCeilingPrioGe(Resource, CurrentThread));                                      /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ResourceIsCeilingPrioGe()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceIsCeilingPrioGe,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
))
{
  Os_StdReturnType result;
  Os_StdReturnType isInterruptResource;

  isInterruptResource = Os_ResourceIsIntResource(Resource);                                                             /* SBSW_OS_FC_PRECONDITION */

  if(isInterruptResource != 0u)
  {
    result = Os_ResourceInterruptIsCeilingPrioGe(Os_Resource2ResourceInterrupt(Resource), CurrentThread);               /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_RES_RESOURCEINTERRUPTISCEILINGPRIOGE_001 */
  }
  else
  {
    result = Os_ResourceBaseIsCeilingPrioGe(Resource, CurrentThread);                                                   /* SBSW_OS_FC_PRECONDITION */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_ResourceBaseIsCeilingPrioGe()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_ResourceBaseIsCeilingPrioGe,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
))
{
  Os_StdReturnType result;

  /* #10 If the current thread is no task: */
  if(OS_UNLIKELY(Os_ThreadIsTask(CurrentThread) == 0u))                                                                 /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Return check not okay. Resource's ceiling priority is always lower than the ISR's home priority. */
    result = 0;
  }
  /* #30 Otherwise */
  else
  {
    /* #40 Return whether the resource's ceiling priority is logically higher than or equal to the current task's
     *     home priority (!0) or not (0). */
    Os_TaskPrioType homePrio = Os_TaskGetHomePriority(Os_TaskThread2Task(CurrentThread));                               /* SBSW_OS_RES_TASKGETHOMEPRIORITY_001 */ /* SBSW_OS_FC_PRECONDITION */

    result = Os_SchedulerPriorityIsHigherOrEqual(Resource->CeilingPriority, homePrio);
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_ResourceInterruptIsCeilingPrioGe()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceInterruptIsCeilingPrioGe,
(
  P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CurrentThread
))
{
  Os_StdReturnType result;

  /* #10 If the current thread is no ISR: */
  if(Os_ThreadIsIsr(CurrentThread) == 0u )                                                                              /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Return check okay. Interrupt resource's ceiling priority is always higher than task's home priority. */
    result = !0u;                                                                                                       /* PRQA S 4404, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  }
  /* #30 Otherwise (the current thread is an ISR): */
  else
  {
    Os_IntLevelType intLevel;

    Os_IsrHalIntLevel2CoreIntLevel(&intLevel, Resource->InterruptLevel);                                                /* SBSW_OS_RES_ISRHALINTLEVEL2COREINTLEVEL_001 */

    /* #40 Return whether the resource's interrupt priority level is logically higher than or equal to the
     *     ISR's configured interrupt priority level (!0) or not (0). */
    result = Os_IsrLevelIsLe(Os_IsrThread2Isr(CurrentThread), &intLevel);                                               /* SBSW_OS_RES_ISRLEVELISLE_001 */ /* SBSW_OS_FC_PRECONDITION */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_ResourceSaveAndIncrease()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceSaveAndIncrease,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
))
{
  Os_TaskPrioType currentPrio;

  currentPrio = Os_TaskGetPriority(Task);                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #10 Save current task priority in resource. */
  Os_ResourceGetDyn(Resource)->PreviousPriority = currentPrio;                                                          /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_RES_RESOURCEGETDYN_001 */

  /* #20 If the resource's ceiling priority is higher than the current priority of the task: */
  if(Os_SchedulerPriorityIsHigher(Resource->CeilingPriority, currentPrio) != 0u)
  {
    /* #30 Increase task to resource's ceiling priority. */
    Os_SchedulerIncreasePrio(Os_TaskGetScheduler(Task), Resource->CeilingPriority);                                     /* SBSW_OS_RES_SCHEDULERINCREASEPRIO_001 */ /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ResourceRestore()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ResourceRestore,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
))
{
  Os_TaskPrioType currentPrio;
  Os_TaskPrioType previousPrio;

  currentPrio = Os_TaskGetPriority(Task);                                                                               /* SBSW_OS_FC_PRECONDITION */
  previousPrio = Os_ResourceGetDyn(Resource)->PreviousPriority;                                                         /* SBSW_OS_FC_PRECONDITION */

  /* #10 If the previous priority is lower than the current priority of the task: */
  if(Os_SchedulerPriorityIsHigher(currentPrio, previousPrio) != 0u)
  {
    /* #20 Restore the previous priority. */
    Os_SchedulerDecreasePrio(Os_TaskGetScheduler(Task), previousPrio);                                                  /* SBSW_OS_RES_SCHEDULERDECREASEPRIO_001 */ /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_ResourceInterruptSaveAndIncrease()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceInterruptSaveAndIncrease,
(
  P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) Resource
))
{
  P2VAR(Os_ResourceInterruptType, AUTOMATIC, OS_VAR_NOINIT) resourceDyn;
  resourceDyn = Os_ResourceInterruptGetDyn(Resource);                                                                   /* SBSW_OS_FC_PRECONDITION */

  /* #10 Read back and update the interrupt state according to the resources interrupt level. */
  Os_InterruptSaveAndIncrease(&(resourceDyn->PreviousInterruptState), Resource->InterruptLevel);                        /* SBSW_OS_RES_RESOURCEINTERRUPTGETDYN_001 */ /* SBSW_OS_FC_PRECONDITION */
}



/***********************************************************************************************************************
 *  Os_ResourceLock2Resource()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_ResourceLock2Resource,
(
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) Lock
))
{
  return (P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST))(Lock);                                                   /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_ResourceForceReleaseLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_ResourceForceReleaseLocal,             /* PRQA S 3673 */ /* MD_MSR_Rule8.13 */
(
  P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) LockList,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) resource;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) configTp;
  P2CONST(Os_LockConfigType, AUTOMATIC, OS_CONST) lock;

  lock = Os_LockListGetTop(LockList);                                                                                   /* SBSW_OS_FC_PRECONDITION */

  Os_Assert((Os_StdReturnType)(Os_LockIsResource(lock) != 0u));                                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_RES_LOCKISRESOURCE_001 */

  localCore = Os_ThreadGetCore(Thread);                                                                                 /* SBSW_OS_FC_PRECONDITION */
  resource = Os_ResourceLock2Resource(lock);                                                                            /* SBSW_OS_RES_RESOURCELOCK2RESOURCE_001 */

  /* Restoring of previous interrupt level in case of interrupt resources is not performed:
   * This function is called with interrupts disabled. */

  /* #10 If the terminated thread is a task: */
  if(Os_ThreadIsTask(Thread) != 0u)                                                                                     /* SBSW_OS_FC_PRECONDITION */
  {
    /* #20 Restore scheduling priority. */
    Os_ResourceRestore(resource, Os_TaskThread2Task(Thread));                                                           /* SBSW_OS_RES_RESOURCERESTORE_001 */ /* SBSW_OS_FC_PRECONDITION */
  }

  /* #30 Delete resource from thread's list of occupied locks. */
  Os_LockListPop(LockList);                                                                                             /* SBSW_OS_FC_PRECONDITION */

  configTp = Os_CoreAsrGetTimingProtection(localCore);                                                                  /* SBSW_OS_RES_COREASRGETTIMINGPROTECTION_001 */

  /* #40 Stop blocking time measurement. */
  Os_TpStopResource(configTp, Os_ThreadGetTpConfig(Thread), resource->ResourceId);                                      /* SBSW_OS_RES_TPSTOPRESOURCE_001 */ /* SBSW_OS_FC_PRECONDITION */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Resource2ResourceInterrupt()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_Resource2ResourceInterrupt,
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
))
{
  Os_Assert((Os_StdReturnType)(Os_LockIsIntResource(&(Resource->Lock)) != 0u));                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
  return (P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST))(Resource);                                      /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_ResourceInit()
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_ResourceInit
(
  P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) Resource
)
{
  Os_LockInit(&Resource->Lock);                                                                                         /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_ResourceForciblyReleaseLocks()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_ResourceForciblyReleaseLocks
(
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
)
{
  /* #10 If the module is enabled: */
  if(Os_ResourceIsEnabled() != 0u)                                                                                      /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) it;

    /* #15 Get the thread's lock list. */
    it = Os_ThreadGetLocks(Thread);                                                                                     /* SBSW_OS_FC_PRECONDITION */

    /* #20 Iterate over the lock list. */
    while(Os_LockListIsEmpty(it) == 0u)                                                                                 /* SBSW_OS_RES_LOCKLISTISEMPTY_001 */
    {
      /* #30 If the lock is a resource, release it. */
      if(Os_LockListIsTopRes(it) != 0u)                                                                                 /* SBSW_OS_RES_LOCKLISTISTOPRES_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
      {
        Os_ResourceForceReleaseLocal(it, Thread);                                                                       /* SBSW_OS_RES_RESOURCEFORCERELEASELOCAL_001 */
      }
      else
      {
        it = Os_LockListNextIterator(it);                                                                               /* SBSW_OS_RES_LOCKLISTNEXTITERATOR_001 */
      }
    }
  }
}


/***********************************************************************************************************************
 *  Os_Api_GetResource()
 **********************************************************************************************************************/
/*!
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
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetResource
(
  ResourceType ResID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(Os_ResourceIsEnabled() == 0u)                                                                                      /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ResourceCheckId(ResID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETRESOURCE) == OS_CHECK_FAILED))          /* SBSW_OS_RES_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_RES_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) me;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    me = Os_ResourceId2Resource(ResID);

    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_RES_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(me->Core) == OS_CHECK_FAILED))                                            /* SBSW_OS_RES_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_CORE;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(                                                                              /* SBSW_OS_RES_APPCHECKACCESS_001 */ /* SBSW_OS_RES_RESOURCEGETACCESSINGAPPLICATIONS_001 */
              currentApplication, Os_ResourceGetAccessingApplications(me)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_LockCheckIsAvailable(&(me->Lock)) == OS_CHECK_FAILED))                                       /* SBSW_OS_RES_LOCKCHECKISAVAILABLE_001 */
    {
      status = OS_STATUS_LOCKED;
    }
    else if(OS_UNLIKELY(Os_ResourceCheckPrio(me, currentThread) == OS_CHECK_FAILED))                                    /* SBSW_OS_RES_RESOURCECHECKPRIO_001 */
    {
      status = OS_STATUS_PRIORITY;
    }
    else
    {
      Os_IntStateType intState;
      P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) configTp;
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;

      localCore = Os_ThreadGetCore(currentThread);                                                                      /* SBSW_OS_RES_THREADGETCORE_001 */
      configTp = Os_CoreAsrGetTimingProtection(localCore);                                                              /* SBSW_OS_RES_COREASRGETTIMINGPROTECTION_001 */

      /* #20 If the resource is an interrupt resource: */
      if(Os_ResourceIsIntResource(me) != 0u)                                                                            /* SBSW_OS_RES_RESOURCEISINTRESOURCE_001 */
      {
        /* #30 Increase interrupt priority level. */
        Os_ResourceInterruptSaveAndIncrease(Os_Resource2ResourceInterrupt(me));                                         /* SBSW_OS_RES_RESOURCEINTERRUPTSAVEANDINCREASE_001 */ /* SBSW_OS_RES_RESOURCE2RESOURCEINTERRUPT_001 */
      }

      /* #40 Enter critical section (core local). */
      Os_IntSuspend(&intState);                                                                                         /* SBSW_OS_FC_POINTER2LOCAL */

      /* #50 Start blocking time measurement. */
      Os_TpStartResource(configTp, ResID);                                                                              /* SBSW_OS_RES_TPSTARTRESOURCE_001 */

      /* #60 Insert resource to thread's list of occupied locks. */
      Os_LockListPush(Os_ThreadGetLocks(currentThread), &(me->Lock));                                                   /* SBSW_OS_RES_LOCKLISTPUSH_001 */ /* SBSW_OS_RES_THREADGETLOCKS_001 */

      /* #65 Inform the trace module */
      Os_TraceResourceTaken(ResID);

      /* #70 If the current thread is a task: */
      if(Os_ThreadIsTask(currentThread) != 0u)                                                                          /* SBSW_OS_RES_THREADISTASK_001 */
      {
        /* #80 Increase scheduling priority. */
        Os_ResourceSaveAndIncrease(me, Os_TaskThread2Task(currentThread));                                              /* SBSW_OS_RES_RESOURCESAVEANDINCREASE_001 */ /* SBSW_OS_RES_TASKTHREAD2TASK_001 */
      }

      /* #90 Leave critical section. */
      Os_IntResume(&intState);                                                                                          /* SBSW_OS_FC_POINTER2LOCAL */

      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_ReleaseResource()
 **********************************************************************************************************************/
/*!
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
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_ReleaseResource
(
  ResourceType ResID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(Os_ResourceIsEnabled() == 0u)                                                                                      /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ResourceCheckId(ResID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_RELEASERESOURCE) == OS_CHECK_FAILED))      /* SBSW_OS_RES_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_RES_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_ResourceConfigType, AUTOMATIC, OS_CONST) me;
    P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) lockList;
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApplication;

    me = Os_ResourceId2Resource(ResID);
    lockList = Os_ThreadGetLocks(currentThread);                                                                        /* SBSW_OS_RES_THREADGETLOCKS_001 */
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_RES_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(me->Core) == OS_CHECK_FAILED))                                            /* SBSW_OS_RES_COREASRCHECKISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_CORE;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, Os_ResourceGetAccessingApplications(me))                  /* SBSW_OS_RES_APPCHECKACCESS_001 */ /* SBSW_OS_RES_RESOURCEGETACCESSINGAPPLICATIONS_001 */
        == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_LockCheckIsOccupied(&(me->Lock)) == OS_CHECK_FAILED))                                        /* SBSW_OS_RES_LOCKCHECKISOCCUPIED_001 */
    {
      status = OS_STATUS_UNLOCKED;
    }
    else if(OS_UNLIKELY(Os_LockListCheckTopIsRes(lockList) == OS_CHECK_FAILED))                                         /* SBSW_OS_RES_LOCKLISTCHECKTOPISRES_002 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      status = OS_STATUS_LIFO_TOP_IS_SPINLOCK;
    }
    else if(OS_UNLIKELY(Os_LockListCheckIsListTop(lockList, &(me->Lock)) == OS_CHECK_FAILED))                           /* SBSW_OS_RES_LOCKLISTCHECKISLISTTOP_001 */
    {
      status = OS_STATUS_ORDER;
    }
    else
    {
      Os_IntStateType intState;
      P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) configTp;
      P2CONST(Os_TpThreadConfigType, TYPEDEF, OS_CONST) configTpThread;
      Os_IntStateType previousInterruptState;
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;

      localCore = Os_ThreadGetCore(currentThread);                                                                      /* SBSW_OS_RES_THREADGETCORE_001 */
      configTp = Os_CoreAsrGetTimingProtection(localCore);                                                              /* SBSW_OS_RES_COREASRGETTIMINGPROTECTION_001 */
      configTpThread = Os_ThreadGetTpConfig(currentThread);                                                             /* SBSW_OS_RES_THREADGETTPCONFIG_001 */

      /* #20 Enter critical section (core local). */
      Os_IntSuspend(&intState);                                                                                         /* SBSW_OS_FC_POINTER2LOCAL */

      /* #30 Fetch the previous interrupt level into a local variable in case of an interrupt resource. */
      if(Os_ResourceIsIntResource(me) != 0u)                                                                            /* SBSW_OS_RES_RESOURCEISINTRESOURCE_001 */
      {
        P2CONST(Os_ResourceInterruptConfigType, AUTOMATIC, OS_CONST) resource;

        resource = Os_Resource2ResourceInterrupt(me);                                                                   /* SBSW_OS_RES_RESOURCE2RESOURCEINTERRUPT_001 */
        previousInterruptState = Os_ResourceInterruptGetDyn(resource)->PreviousInterruptState;                          /* SBSW_OS_RES_RESOURCEINTERRUPTGETDYN_001 */
      }

      /* #40 Inform the trace module */
      Os_TraceResourceReleased(ResID);

      /* #50 Delete resource from thread's list of occupied locks. */
      Os_LockListPop(lockList);                                                                                         /* SBSW_OS_RES_LOCKLISTPOP_001 */

      /* #60 Stop blocking time measurement. */
      Os_TpStopResource(configTp, configTpThread, ResID);                                                               /* SBSW_OS_RES_TPSTOPRESOURCE_001 */


      /* #70 If the current thread is a task: */
      if(Os_ThreadIsTask(currentThread) != 0u)                                                                          /* SBSW_OS_RES_THREADISTASK_001 */
      {
        P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler = Os_CoreGetScheduler(me->Core);                 /* SBSW_OS_RES_COREGETSCHEDULER_001 */

        /* #80 Restore scheduling priority. */
        Os_ResourceRestore(me, Os_TaskThread2Task(currentThread));                                                      /* SBSW_OS_RES_RESOURCERESTORE_002 */ /* SBSW_OS_RES_TASKTHREAD2TASK_001 */

        /* #90 If the caller is a task and releasing the resource leads to a task switch: */
        if((Os_SchedulerTaskSwitchIsNeeded(scheduler) != 0u))                                                           /* SBSW_OS_RES_SCHEDULERTASKSWITCHISNEEDED_001 */
        {
          /* #100 Perform a task switch. */
          Os_TaskSwitch(scheduler, currentThread);                                                                      /* SBSW_OS_RES_TASKSWITCH_001 */
        }
      }

      /* #110 Leave critical section. */
      Os_IntResume(&intState);                                                                                          /* SBSW_OS_FC_POINTER2LOCAL */

      /* #120 If the resource is an interrupt resource: */
      if(Os_ResourceIsIntResource(me) != 0u)                                                                            /* SBSW_OS_RES_RESOURCEISINTRESOURCE_001 */
      {
        /* #130 Restore interrupt priority level. */
        Os_InterruptRestore(&previousInterruptState);                                                                   /* PRQA S 2972 */ /* MD_Os_Rule9.1_2972 */ /* SBSW_OS_FC_POINTER2LOCAL */
      }

      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_RES_TASKTHREAD2TASK_001
 \DESCRIPTION     Os_TaskThread2Task is called is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE  \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_RESOURCEINTERRUPTISCEILINGPRIOGE_001
 \DESCRIPTION     Os_ResourceInterruptIsCeilingPrioGe is called with the return value of Os_Resource2ResourceInterrupt
                  and CurrentThread. CurrentThread is passed as argument. Precondition ensures that the CurrentThread
                  pointer is valid. The compliance of the precondition is check during review.
                  Os_ThreadGetOwnerApplication.
 \COUNTERMEASURE  \R [CM_RESOURCE2RESOURCEINTERRUPT_R]

\ID SBSW_OS_RES_TASKGETHOMEPRIORITY_001
 \DESCRIPTION     Os_TaskGetHomePriority is called is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE  \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_RES_ISRLEVELISLE_001
 \DESCRIPTION     Os_IsrLevelIsLe is called with the return value of Os_IsrThread2Isr and a pointer to a
                  local variable.
 \COUNTERMEASURE  \M [CM_OS_ISRTHREAD2ISR_01_02_M]
                  \M [CM_OS_ISRTHREAD2ISR_02_02_M]

\ID SBSW_OS_RES_RESOURCEGETDYN_001
 \DESCRIPTION     Write access to a Dyn element returned by Os_ResourceGetDyn.
 \COUNTERMEASURE  \M [CM_OS_RESOURCEGETDYN_M]

\ID SBSW_OS_RES_RESOURCEINTERRUPTGETDYN_001
 \DESCRIPTION     Write access to a Dyn element returned by Os_ResourceInterruptGetDyn.
 \COUNTERMEASURE  \M [CM_OS_RESOURCEINTERRUPTGETDYN_M]

\ID SBSW_OS_RES_RESOURCEINTERRUPTGETDYN_002
 \DESCRIPTION     Os_ResourceInterruptGetDyn is called with the return value of Os_Resource2ResourceInterrupt.
 \COUNTERMEASURE  \R [CM_RESOURCE2RESOURCEINTERRUPT_R]

\ID SBSW_OS_RES_TASKGETSCHEDULER_001
 \DESCRIPTION     Os_TaskGetScheduler is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE  \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_RES_SCHEDULERINCREASEPRIO_001
 \DESCRIPTION    Os_SchedulerIncreasePrio is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_RES_SCHEDULERDECREASEPRIO_001
 \DESCRIPTION    Os_SchedulerDecreasePrio is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_RES_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_THREADGETLOCKS_001
 \DESCRIPTION    Os_ThreadGetLocks is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_RESOURCERESTORE_001
 \DESCRIPTION    Os_ResourceRestore is called with the return value of Os_ResourceLock2Resource and Os_TaskThread2Task.
                 The correctness of the return value of Os_ResourceLock2Resource is ensured by precondition.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_RES_RESOURCERESTORE_002
 \DESCRIPTION    Os_ResourceRestore is called with the return value of Os_ResourceId2Resource and Os_TaskThread2Task
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]
                 \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_RES_LOCKLISTPOP_001
 \DESCRIPTION    Os_LockListPop is called with the return value of Os_ThreadGetLocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_RES_LOCKLISTPUSH_001
 \DESCRIPTION    Os_LockListPush is called with the return value of Os_ThreadGetLocks and a value derived from the
                 return value of Os_ResourceId2Resource. Precondition ensures that the return value of
                 Os_ThreadGetLocks is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_COREASRGETTIMINGPROTECTION_001
 \DESCRIPTION    Os_CoreAsrGetTimingProtection is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_RES_TPSTOPRESOURCE_001
 \DESCRIPTION    Os_TpStopResource is called with the return value of Os_CoreAsrGetTimingProtection and
                 Os_ThreadGetTpConfig.
 \COUNTERMEASURE \M [CM_OS_THREADGETTPCONFIG_M]
                 \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_RES_THREADGETTPCONFIG_001
 \DESCRIPTION    Os_ThreadGetTpConfig is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_LOCKLISTISEMPTY_001
 \DESCRIPTION    Os_LockListIsEmpty is called with an iterator pointer which was initialized with a value passed
                 as argument to the caller function. The iterator is changed in a loop.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_RES_RESOURCEFORCERELEASELOCAL_001
 \DESCRIPTION    Os_ResourceForceReleaseLocal is called with an iterator.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_RES_RESOURCELOCK2RESOURCE_001
 \DESCRIPTION    Os_ResourceLock2Resource is called with the return value of Os_LockListGetTop.
 \COUNTERMEASURE \R [CM_LOCKLISTGETTOP_R]

\ID SBSW_OS_RES_LOCKLISTISTOPRES_001
 \DESCRIPTION    Os_LockListIsTopRes is called with an iterator.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_RES_LOCKLISTCHECKTOPISRES_002
 \DESCRIPTION    Os_LockListCheckTopIsRes is called with the return value of Os_ThreadGetLocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_RES_LOCKISRESOURCE_001
 \DESCRIPTION    Os_LockIsResource is called with the return value of Os_LockListGetTop.
 \COUNTERMEASURE \R [CM_LOCKLISTGETTOP_R]

\ID SBSW_OS_RES_LOCKLISTNEXTITERATOR_001
 \DESCRIPTION    Os_LockListNextIterator is called with an iterator.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_RES_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION    Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_RES_COREASRCHECKISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal is called with a Core value derived from the return value of
                 Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]
                 \M [CM_OS_RESOURCE_CORE_M]

\ID SBSW_OS_RES_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_RES_RESOURCEGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_ResourceGetAccessingApplications is called with the return value of Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_LOCKCHECKISAVAILABLE_001
 \DESCRIPTION    Os_LockCheckIsAvailable is called with a value derived from the return value of Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_RESOURCECHECKPRIO_001
 \DESCRIPTION    Os_ResourceCheckPrio is called with the return values of Os_ResourceId2Resource and Os_CoreGetThread.
                 Precondition ensures that the pointer return by Os_CoreGetThread is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_TPSTARTRESOURCE_001
 \DESCRIPTION    Os_TpStartResource is called with the return value of Os_CoreAsrGetTimingProtection.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]

\ID SBSW_OS_RES_RESOURCEISINTRESOURCE_001
 \DESCRIPTION    Os_ResourceIsIntResource is called with the return value of Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_RESOURCE2RESOURCEINTERRUPT_001
 \DESCRIPTION    Os_Resource2ResourceInterrupt is called with the return value of Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_RESOURCEINTERRUPTSAVEANDINCREASE_001
 \DESCRIPTION    Os_ResourceInterruptSaveAndIncrease is called with the return value of Os_Resource2ResourceInterrupt.
 \COUNTERMEASURE \R [CM_RESOURCE2RESOURCEINTERRUPT_R]

\ID SBSW_OS_RES_RESOURCESAVEANDINCREASE_001
 \DESCRIPTION    Os_ResourceSaveAndIncrease is called with the return value of Os_ResourceId2Resource and
                 Os_TaskThread2Task.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]
                 \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_RES_LOCKCHECKISOCCUPIED_001
 \DESCRIPTION    Os_LockCheckIsOccupied is called with a value derived from the return value of Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_LOCKLISTCHECKISLISTTOP_001
 \DESCRIPTION    Os_LockListCheckIsListTop is called with the return value of Os_ThreadGetLocks and a value derived
                 from the return value of Os_ResourceId2Resource.
                 Precondition ensures that the pointer returned by Os_ThreadGetLocks is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]

\ID SBSW_OS_RES_COREGETSCHEDULER_001
 \DESCRIPTION    Os_CoreGetScheduler is called with a Core object derived from the return value of
                 Os_ResourceId2Resource.
 \COUNTERMEASURE \M [CM_OS_RESOURCEID2RESOURCE_M]
                 \M [CM_OS_RESOURCE_CORE_M]

\ID SBSW_OS_RES_SCHEDULERTASKSWITCHISNEEDED_001
 \DESCRIPTION    Os_SchedulerTaskSwitchIsNeeded is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_RES_TASKSWITCH_001
 \DESCRIPTION    Os_TaskSwitch is called with the return values of Os_CoreGetScheduler and Os_CoreGetThread.
                 Precondition ensures that the pointer return by Os_CoreGetThread is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_RES_ISRHALINTLEVEL2COREINTLEVEL_001
 \DESCRIPTION    Os_IsrHalIntLevel2CoreIntLevel is called with a pointer to a local variable and the interrupt level
                 of a resource. Precondition ensures that the argument passed to the caller is valid. The compliance
                 of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_RESOURCEINTERRUPT_INTERRUPTLEVEL_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_RESOURCEID2RESOURCE_M
      Verify that:
        1. each resource pointer in OsCfg_ResourceRefs is no NULL_PTR,
        2. the size of OsCfg_ResourceRefs is equal to OS_RESOURCEID_COUNT + 1 and
        3. each element in ResourceType has a lower value than OS_RESOURCEID_COUNT.

\CM CM_OS_RESOURCEGETDYN_M
      Verify that the Dyn pointer of each Os_ResourceConfigType object is a non NULL_PTR.

\CM CM_OS_RESOURCEINTERRUPTGETDYN_M
      Verify that the Lock Dyn pointer of each Os_ResourceInterruptConfigType object is initialized with a
      dynamic resource derived from an Os_ResourceInterruptType object.

\CM CM_OS_RESOURCEINTERRUPT_INTERRUPTLEVEL_M
      Verify that the InterruptLevel pointer of each Os_ResourceInterruptConfigType object is initialized with a
      valid Os_Hal_IntLevelType object.

\CM CM_RESOURCE2RESOURCEINTERRUPT_R
      The caller ensures by runtime check, that the object passed to Os_Resource2ResourceInterrupt is a interrupt
      resource. Therefore the return pointer of Os_Resource2ResourceInterrupt is valid.

\CM CM_OS_RESOURCE_CORE_M
      Verify that the Core pointer of each Os_ResourceConfigType object is initialized with a non NULL_PTR.


*/


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Resource.c
 **********************************************************************************************************************/
