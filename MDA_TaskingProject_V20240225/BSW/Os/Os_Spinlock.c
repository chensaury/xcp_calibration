/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 * \addtogroup Os_Spinlock
 * \{
 *
 * \file
 * \brief       Provides the spinlock implementation.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_SPINLOCK_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Spinlock_Types.h"
#include "Os_Spinlock_Lcfg.h"
#include "Os_Spinlock.h"

/* Os kernel module dependencies */
#include "Os_Cfg.h"
#include "Os_Thread.h"
#include "Os_Application.h"
#include "Os_Trap.h"
#include "Os_Core.h"
#include "Os_Task.h"

/* Os hal dependencies */


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
 *  Os_SpinlockTraceOwnerGet()
 **********************************************************************************************************************/
/*! \brief          Locks the given spinlock and adds the spinlock to the lock list of the thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \return         The spinlock.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockTraceOwnerGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockTraceOwnerRelease()
 **********************************************************************************************************************/
/*! \brief          Releases the given spinlock and removes the spinlock from the lock list of the thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \return         The spinlock.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockTraceOwnerRelease,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockTraceOwnerTryGet()
 **********************************************************************************************************************/
/*! \brief          Try to get the the given spinlock and adds the spinlock to the lock list of the thread if locking
 *                  succeeded.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock          The spinlock to query. Parameter must not be NULL.
 *
 *  \retval         OS_HAL_SPINLOCKSUCCEEDED    If getting the spinlock succeeded.
 *  \retval         !OS_HAL_SPINLOCKSUCCEEDED   If getting the spinlock failed.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockTraceOwnerTryGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockSuspendByMethod()
 **********************************************************************************************************************/
/*! \brief          Disables the context switching up to the spinlock method.
 *  \details        --no details--
 *
 *  \param[in]      Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \return         The priority of the owner task before the spinlock was locked.
 *  \retval         0   If current thread is ISR.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TaskPrioType, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockSuspendByMethod,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockResumeByMethod()
 **********************************************************************************************************************/
/*! \brief          Enables context switching.
 *  \details        --no details--
 *
 *  \param[in]      Spinlock          The spinlock to query. Parameter must not be NULL.
 *  \param[in]      PreviousPriority  The priority of the owner task before the spinlock was locked.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockResumeByMethod,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock,
  Os_TaskPrioType PreviousPriority
));


/***********************************************************************************************************************
 *  Os_SpinlockListPush()
 **********************************************************************************************************************/
/*! \brief          Insert a spinlock into a linked list of locks and the linked list of spinlocks.
 *  \details        --no details--
 *
 *  \param[in,out]  Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockListPush,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockListPop()
 **********************************************************************************************************************/
/*! \brief          Removes the top spinlock from a linked list of locks and the list of spinlocks from the current
 *                  thread.
 *  \details        --no details--
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SpinlockListPop, (void));


/***********************************************************************************************************************
 *  Os_SpinlockIsNotLockedLocal()
 **********************************************************************************************************************/
/*! \brief        Returns whether the spinlock is not allocated by the current core.
 *  \details      --no details--
 *
 *  \param[in]    Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \retval       !0  The current core does not lock the spinlock.
 *  \retval       0   The current core locks the spinlock.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockIsNotLockedLocal,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));

/***********************************************************************************************************************
 *  Os_SpinlockCheckIsNotLockedLocal()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given spinlock is not assigned to the calling core.
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \retval       Not OS_CHECK_FAILED   The spinlock is not locked by any thread of the local core.
 *  \retval       OS_CHECK_FAILED       The spinlock is lock by a thread which belongs to the local core.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockCheckIsNotLockedLocal,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockIsOwnerThread()
 **********************************************************************************************************************/
/*! \brief        Returns whether the spinlock is allocate by the current thread (!0) or not (0).
 *  \details      --no details--
 *
 *  \param[in]    Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \retval       !0  The current thread locks the spinlock.
 *  \retval       0   The current thread does not lock the spinlock.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockIsOwnerThread,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockCheckThreadIsOwner()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given spinlock is assigned to the current thread.
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *  \retval       Not OS_CHECK_FAILED   The spinlock is locked by the current thread.
 *  \retval       OS_CHECK_FAILED       The spinlock is not locked by the current thread.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockCheckThreadIsOwner,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockIsLockOrderValid()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given spinlock is locked in the correct order.
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *
 *  \retval       0        The spinlock is locked in an invalid order.
 *  \retval       !0       The spinlock is locked in the correct order.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        SPEC-63593
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockIsLockOrderValid,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockCheckIsLockOrderValid()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given spinlock may be locked by the task.
 *  \details      In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                returned.
 *
 *  \param[in]    Spinlock  The spinlock to query. Parameter must not be NULL.
 *
 *
 *  \retval       Not OS_CHECK_FAILED   The spinlock is locked in an correct order.
 *  \retval       OS_CHECK_FAILED       The spinlock is locked in the invalid order.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockCheckIsLockOrderValid,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
));


/***********************************************************************************************************************
 *  Os_SpinlockGetSpinlockIdCount()
 **********************************************************************************************************************/
/*! \brief          Get the number of configured spinlocks.
 *  \details        --no details--
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE SpinlockIdType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockGetSpinlockIdCount,
(
  void
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_SpinlockSuspendByMethod()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TaskPrioType, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockSuspendByMethod,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  Os_TaskPrioType previousPriority = 0;

  switch(Spinlock->Method)                                                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  {
    /* #10 If OS_SPINLOCKMETHOD_ALL_INT: Suspend all interrupts. */
    case OS_SPINLOCKMETHOD_ALL_INT:
      Os_Api_SuspendAllInterrupts();
      break;

    /* #20 If OS_SPINLOCKMETHOD_CAT2: Suspend OS interrupts. */
    case OS_SPINLOCKMETHOD_CAT2:
      Os_Api_SuspendOSInterrupts();
      break;

    /* #30 If OS_SPINLOCKMETHOD_SCHEDULER: Increase to highest scheduling priority. */
    case OS_SPINLOCKMETHOD_SCHEDULER:                                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /*! \note This simulates RES_SCHEDULER allocation, so TP has to be considered. */
      P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

      currentThread = Os_CoreGetThread();

      /* #40 If this function is called from task level: */
      if(Os_ThreadIsTask(currentThread) != 0u)                                                                          /* SBSW_OS_SL_THREADISTASK_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        /* #50 Get the task priority. */
        previousPriority = Os_TaskGetPriority(Os_TaskThread2Task(currentThread));                                       /* SBSW_OS_SL_TASKGETPRIORITY_001 */ /* SBSW_OS_SL_TASKTHREAD2TASK_001 */

        if(Os_SchedulerPriorityIsHigher(Spinlock->CeilingPriority, previousPriority) != 0u)                             /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
        {
          P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
          P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler;
          Os_IntStateType interruptState;

          core = Os_ThreadGetCore(currentThread);                                                                       /* SBSW_OS_SL_THREADGETCORE_001 */
          scheduler = Os_CoreGetScheduler(core);                                                                        /* SBSW_OS_SL_COREGETSCHEDULER_001 */

          /* #55 Enter critical section. */
          Os_IntSuspend(&interruptState);                                                                               /* SBSW_OS_FC_POINTER2LOCAL */

          /* #60 Increase the task priority to the core specific spinlock priority. */
          Os_SchedulerIncreasePrio(scheduler, Spinlock->CeilingPriority);                                               /* SBSW_OS_SL_SCHEDULERINCREASEPRIO_001 */

          /* #65 Leave critical section. */
          Os_IntResume(&interruptState);                                                                                /* SBSW_OS_FC_POINTER2LOCAL */
        }

        /*! \attention
         * Do not write the previous task priority to the spinlock, because we do not have the spinlock yet.
         * The spinlock may already be occupied by another task. */
      }
      break;
    }

    /* #70 If OS_SPINLOCKMETHOD_NOTHING: Do nothing. */
    case OS_SPINLOCKMETHOD_NOTHING:                                                                                     /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      /* Nothing to be done */
      break;

    /* #80 Else: freeze (invalid configuration). */
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }

  return previousPriority;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_SpinlockResumeByMethod()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockResumeByMethod,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock,
  Os_TaskPrioType PreviousPriority
))
{
  switch(Spinlock->Method)                                                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  {
    /* #10 If OS_SPINLOCKMETHOD_ALL_INT: Resume all interrupts. */
    case OS_SPINLOCKMETHOD_ALL_INT:
      Os_Api_ResumeAllInterrupts();
      break;

    /* #20 If OS_SPINLOCKMETHOD_CAT2: Resume OS interrupts. */
    case OS_SPINLOCKMETHOD_CAT2:
      Os_Api_ResumeOSInterrupts();
      break;

    /* #30 If OS_SPINLOCKMETHOD_SCHEDULER: Restore scheduling priority. */
    case OS_SPINLOCKMETHOD_SCHEDULER:                                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /*! \note This simulates RES_SCHEDULER allocation, so TP has to be considered. */
      P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

      currentThread = Os_CoreGetThread();

      /* #40 If this function is called from task level: */
      if(Os_ThreadIsTask(currentThread) != 0u)                                                                          /* SBSW_OS_SL_THREADISTASK_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_TaskPrioType currentPriority;

        currentPriority = Os_TaskGetPriority(Os_TaskThread2Task(currentThread));                                        /* SBSW_OS_SL_TASKGETPRIORITY_001 */ /* SBSW_OS_SL_TASKTHREAD2TASK_001 */

        if(Os_SchedulerPriorityIsLower(PreviousPriority, currentPriority) != 0u)
        {
          P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
          P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler;
          Os_IntStateType interruptState;

          core = Os_ThreadGetCore(currentThread);                                                                       /* SBSW_OS_SL_THREADGETCORE_001 */
          scheduler = Os_CoreGetScheduler(core);                                                                        /* SBSW_OS_SL_COREGETSCHEDULER_001 */

          /* #45 Enter critical section. */
          Os_IntSuspend(&interruptState);                                                                               /* SBSW_OS_FC_POINTER2LOCAL */

          /* #50 Decrease the task priority to stored previous task priority. */
          Os_SchedulerDecreasePrio(scheduler, PreviousPriority);                                                        /* SBSW_OS_SL_SCHEDULERDECREASEPRIO_001 */

          /* #60 Switch to higher priority tasks if required. */
          if((Os_SchedulerTaskSwitchIsNeeded(scheduler) != 0u))                                                         /* SBSW_OS_SL_SCHEDULERTASKSWITCHISNEEDED_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
          {
            Os_TaskSwitch(scheduler, currentThread);                                                                    /* SBSW_OS_SL_TASKSWITCH_001 */
          }

          /* #65 Leave critical section. */
          Os_IntResume(&interruptState);                                                                                /* SBSW_OS_FC_POINTER2LOCAL */
        }
      }
      break;
    }

    /* #50 If OS_SPINLOCKMETHOD_NOTHING: Do nothing. */
    case OS_SPINLOCKMETHOD_NOTHING:                                                                                     /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      /* Nothing to be done */
      break;

    /* #60 Else: freeze (invalid configuration). */
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_SpinlockTraceOwnerGet()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockTraceOwnerGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 Inform the trace module. */
  Os_TraceSpinlockRequested(Spinlock->TimingHookTrace);                                                                 /* SBSW_OS_SL_TRACESPINLOCKREQUESTED_001 */

  /* #20 Loop: */
  do
  {
    /* #30 Spin while the spinlock is locked. */
    while(Os_Hal_SpinIsLocked(&(spinlockDyn->Spinlock)) != 0u)                                                          /* SBSW_OS_SL_HAL_SPINISLOCKED_001 */
    {
      Os_Hal_CoreNop();
    }

    /* #40 Try to get the lock atomic. */
    /* #50 Loop until the current thread becomes the owner. */
  }while(Os_SpinlockTraceOwnerTryGet(Spinlock) != OS_HAL_SPINLOCKSUCCEEDED);                                            /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_HALPLATFORMGETSPINLOCK */

}


/***********************************************************************************************************************
 *  Os_SpinlockTraceOwnerRelease()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockTraceOwnerRelease,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;
  Os_IntStateType interruptState;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 Suspend timing protection interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Remove the lock from the list of locks. */
  Os_SpinlockListPop();

  /* #30 Clear the lock owner. */
  spinlockDyn->OwnerThread = NULL_PTR;                                                                                  /* SBSW_OS_SL_SPINLOCKGETDYN_001 */

  /* #40 Inform the trace module. */
  Os_TraceSpinlockReleased(Spinlock->TimingHookTrace);                                                                  /* SBSW_OS_SL_TRACESPINLOCKRELEASED_001 */

  /* #50 Release the lock. */
  Os_Hal_SpinUnlock(&(spinlockDyn->Spinlock));                                                                          /* SBSW_OS_SL_HAL_SPINUNLOCKED_001 */

  /* #60 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */

}


/***********************************************************************************************************************
 *  Os_SpinlockTraceOwnerTryGet()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_Hal_SpinlockResultType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockTraceOwnerTryGet,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_VAR_NOINIT) Spinlock
))
{
  P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;
  Os_StdReturnType result;
  Os_IntStateType interruptState;

  spinlockDyn = Os_SpinlockGetDyn(Spinlock);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 Suspend timing protection interrupts. */
  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #20 Try to get the lock. */
  result = Os_Hal_SpinTryLock(&(spinlockDyn->Spinlock));                                                                /* SBSW_OS_SL_HAL_SPINTRYLOCK_001 */

  /* #30 On success: */
  if(result == OS_HAL_SPINLOCKSUCCEEDED)
  {

    /* #40 Inform the tracing module first in order to get high quality tracing data. */
    Os_TraceSpinlockTaken(Spinlock->TimingHookTrace);                                                                   /* SBSW_OS_SL_TRACESPINLOCKTAKEN_001 */

    /* #50 Set the lock owner. */
    spinlockDyn->OwnerThread = Os_CoreGetThread();                                                                      /* SBSW_OS_SL_SPINLOCKGETDYN_001 */

    /* #60 Add the lock to the list of locks. */
    Os_SpinlockListPush(Spinlock);                                                                                      /* SBSW_OS_FC_PRECONDITION */
  }

  /* #70 Resume interrupts. */
  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */

  return result;
}


/***********************************************************************************************************************
 *  Os_SpinlockListPush()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,
OS_ALWAYS_INLINE, Os_SpinlockListPush,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) thread;
  P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT) spinlockList;

  thread = Os_CoreGetThread();
  spinlockList = Os_ThreadGetSpinlocks(thread);                                                                         /* SBSW_OS_SL_THREADGETSPINLOCKS_001 */

  /* #10 Insert the Spinlock at the top of the spinlock order list. */
  Os_SpinlockGetDyn(Spinlock)->PreviousSpinlock = *spinlockList;                                                        /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_SL_SPINLOCKGETDYN_001 */
  *spinlockList = Spinlock;                                                                                             /* SBSW_OS_SL_THREADGETSPINLOCKS_002 */

  /* #20 Push the spinlock into the list of locks. */
  Os_LockListPush(Os_ThreadGetLocks(thread), &(Spinlock->Lock));                                                        /* SBSW_OS_SL_LOCKLISTPUSH_001 */ /* SBSW_OS_SL_THREADGETLOCKS_001 */
}


/***********************************************************************************************************************
 *  Os_SpinlockListPop()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SpinlockListPop, (void))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) thread;
  P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT) spinlockList;
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) topSpinlock;

  thread = Os_CoreGetThread();
  spinlockList = Os_ThreadGetSpinlocks(thread);                                                                         /* SBSW_OS_SL_THREADGETSPINLOCKS_001 */

  /* #10 Pop the Spinlock from the top of the spinlock order list. */
  topSpinlock = *spinlockList;
  *spinlockList = Os_SpinlockGetDyn(topSpinlock)->PreviousSpinlock;                                                     /* SBSW_OS_SL_THREADGETSPINLOCKS_002 */ /* SBSW_OS_SL_SPINLOCKGETDYN_002 */

  /* #20 Pop the spinlock from the list of locks. */
  Os_LockListPop(Os_ThreadGetLocks(thread));                                                                            /* SBSW_OS_SL_LOCKLISTPOP_001 */ /* SBSW_OS_SL_THREADGETLOCKS_001 */
}


/***********************************************************************************************************************
 *  Os_SpinlockIsNotLockedLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockIsNotLockedLocal,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  Os_StdReturnType result;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) spinlockOwner;

  spinlockOwner = Os_SpinlockGetDyn(Spinlock)->OwnerThread;                                                             /* SBSW_OS_FC_PRECONDITION */

  /* #10 If spinlock is not owned at all, return !0. */
  if(spinlockOwner == NULL_PTR)
  {
    result = !0u;                                                                                                       /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  }
  /* #20 Otherwise: */
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) ownerCore;

    localCore = Os_ThreadGetCore(Os_CoreGetThread());                                                                   /* SBSW_OS_SL_THREADGETCORE_001 */
    ownerCore = Os_ThreadGetCore(spinlockOwner);                                                                        /* SBSW_OS_SL_THREADGETCORE_002 */

    /* #10 If spinlock owner is not on local core return !0, otherwise 0. */
    result = (Os_StdReturnType)(ownerCore != localCore);                                                                /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SpinlockCheckIsNotLockedLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockCheckIsNotLockedLocal,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  /* #10 If extended status checks enabled, return result of internal function. */
  return Os_ErrExtendedCheck(Os_SpinlockIsNotLockedLocal(Spinlock));                                                    /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockIsOwnerThread()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockIsOwnerThread,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  return (Os_StdReturnType)(Os_SpinlockGetDyn(Spinlock)->OwnerThread == currentThread);                                 /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockCheckThreadIsOwner()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockCheckThreadIsOwner,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  return Os_ErrExtendedCheck(Os_SpinlockIsOwnerThread(Spinlock) != 0u);                                                 /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockIsLockOrderValid()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockIsLockOrderValid,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  Os_StdReturnType result;
  P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT) spinlockList;
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) previousSpinlock;

  spinlockList = Os_ThreadGetSpinlocks(Os_CoreGetThread());                                                             /* SBSW_OS_SL_THREADGETSPINLOCKS_001 */

  previousSpinlock = *spinlockList;

  /* #10 Return whether the order of the first element in the list of spinlocks is lower than the order of
   *     the given spinlock. */

  if(previousSpinlock != NULL_PTR)
  {
    result = (previousSpinlock->Order < Spinlock->Order);                                                               /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
  }
  else
  {
    result = !0u;                                                                                                       /* PRQA S 4404, 4558 */ /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SpinlockCheckIsLockOrderValid()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockCheckIsLockOrderValid,
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
))
{
  /* #10 If extended status checks enabled, return result of internal function. */
  return Os_ErrExtendedCheck(Os_SpinlockIsLockOrderValid(Spinlock));                                                    /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SpinlockGetSpinlockIdCount()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE SpinlockIdType, OS_CODE, OS_ALWAYS_INLINE,
Os_SpinlockGetSpinlockIdCount,
(
  void
))
{
  /* #10 Return OS_SPINLOCKID_COUNT. */
  return (SpinlockIdType)OS_SPINLOCKID_COUNT;
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
/* This suppresses the warning with regard to "condition always false" by checking against OS_SPINLOCKID_COUNT.
 * This can be suppressed here, since this warning is only reported by the compiler if no spinlock is configured.
 * In this case Os_SpinlockForciblyReleaseThreadLocks will never be used during run-time.
 */
#  pragma warning 547, 549                                                                                              /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif
/***********************************************************************************************************************
 *  Os_SpinlockForciblyReleaseThreadLocks()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SpinlockForciblyReleaseThreadLocks
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
)
{
  if(Os_SpinlockIsEnabled() != 0u)
  {
    {
      P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) locks;

      SpinlockIdType idx;

      locks = Os_ThreadGetLocks(Thread);                                                                                /* SBSW_OS_FC_PRECONDITION */

      /* #10 Iterate over all spinlocks. */
      for(idx = (SpinlockIdType)0; idx < Os_SpinlockGetSpinlockIdCount(); ++idx)                                        /* PRQA S 4332, 4527 */ /* MD_Os_Rule10.5_4332, MD_Os_Rule10.1_4527 */
      {
        P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) spinlock;
        P2VAR(Os_SpinlockType, AUTOMATIC, OS_VAR_NOINIT) spinlockDyn;

        spinlock = Os_SpinlockId2Spinlock(idx);
        spinlockDyn = Os_SpinlockGetDyn(spinlock);                                                                      /* SBSW_OS_SL_SPINLOCKGETDYN_003 */

        /* #20 If a spinlock is assigned to the given thread, release it. */
        if(OS_UNLIKELY(spinlockDyn->OwnerThread == Thread))                                                             /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
        {
          spinlockDyn->OwnerThread = NULL_PTR;                                                                          /* SBSW_OS_SL_SPINLOCKGETDYN_001 */

          Os_LockListDelete(locks, &(spinlock->Lock));                                                                  /* SBSW_OS_SL_LOCKLISTDELETE_001 */

          Os_Hal_SpinUnlock(&(spinlockDyn->Spinlock));                                                                  /* SBSW_OS_SL_HAL_SPINUNLOCKED_001 */
        }
      }
    }

    {
      /* #30 Empty thread's spinlock order list. */
      P2VAR(Os_SpinlockListType, AUTOMATIC, OS_VAR_NOINIT) spinlockOrderList;

      spinlockOrderList = Os_ThreadGetSpinlocks(Thread);                                                                /* SBSW_OS_FC_PRECONDITION */

      *spinlockOrderList = OS_SPINLOCK_LIST_END;                                                                        /* SBSW_OS_SL_THREADGETSPINLOCKS_002 */
    }
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */
# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
#  pragma warning restore                                                                                               /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif

/***********************************************************************************************************************
 *  Os_SpinlockGet()
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
 */
FUNC(Os_StatusType, OS_CODE) Os_SpinlockGet
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
)
{
  Os_StatusType status;

  status = OS_STATUS_OK;

  /* #10 If the module is not enabled: KernelPanic. */
  if(Os_SpinlockIsEnabled() == 0u)                                                                                      /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #15 Perform error checks, if required by the spinlock. */
  /* Enhance performance of spinlocks without checks by using OS_UNLIKELY. */
  if(OS_UNLIKELY(Spinlock->Checks == OS_SPINLOCKCHECK_ENABLED))
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    currentThread = Os_CoreGetThread();
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SL_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_SpinlockCheckIsNotLockedLocal(Spinlock) == OS_CHECK_FAILED))                                      /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_STATUS_INTERFERENCE_DEADLOCK;
    }
    else if(OS_UNLIKELY(Os_SpinlockCheckIsLockOrderValid(Spinlock) == OS_CHECK_FAILED))                                 /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_STATUS_NESTING_DEADLOCK;
    }
    else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETSPINLOCK) == OS_CHECK_FAILED))        /* SBSW_OS_SL_THREADCHECKCALLCONTEXT_001 */
    {
      status = OS_STATUS_CALLEVEL;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                           /* SBSW_OS_SL_APPCHECKACCESS_001 */ /* SBSW_OS_FC_PRECONDITION */
                                          Os_SpinlockGetAccessingApplications(Spinlock)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* No error occurred. MISRA 14.10 */
    }
  }

  if(OS_LIKELY(status == OS_STATUS_OK))
  {
    /* #20 Lock the configured interrupt/task level. */
    Os_TaskPrioType previousPriority;

    previousPriority = Os_SpinlockSuspendByMethod(Spinlock);                                                            /* SBSW_OS_FC_PRECONDITION */

    /* #30 If the spinlock owner is traced: */
    if(Spinlock->Trace == OS_SPINLOCKTRACE_ENABLED)                                                                     /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      /* #40 Get the spinlock with owner tracing. */
      Os_SpinlockTraceOwnerGet(Spinlock);                                                                               /* SBSW_OS_FC_PRECONDITION */
    }
    /* #50 Otherwise: */
    else
    {
      /* #60 Get the spinlock. */
      Os_SpinlockInternalGet(Spinlock);                                                                                 /* SBSW_OS_FC_PRECONDITION */
    }

    Os_SpinlockGetDyn(Spinlock)->PreviousPriority = previousPriority;                                                   /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_SL_SPINLOCKGETDYN_001 */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_SpinlockRelease()
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
 */
FUNC(Os_StatusType, OS_CODE) Os_SpinlockRelease
(
 P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock
)
{
  Os_StatusType status;

  status = OS_STATUS_OK;

  /* #10 If the module is not enabled: KernelPanic. */
  if(Os_SpinlockIsEnabled() == 0u)                                                                                      /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #15 Perform error checks if required by the spinlock. */
  /* Enhance performance of spinlocks without checks by using OS_UNLIKELY. */
  if(OS_UNLIKELY(Spinlock->Checks == OS_SPINLOCKCHECK_ENABLED))
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApplication;
    P2VAR(Os_LockListType, AUTOMATIC, OS_VAR_NOINIT) locks;

    currentThread = Os_CoreGetThread();
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SL_THREADGETCURRENTAPPLICATION_001 */
    locks = Os_ThreadGetLocks(currentThread);                                                                           /* SBSW_OS_SL_THREADGETLOCKS_001 */

    if(OS_UNLIKELY(Os_SpinlockCheckThreadIsOwner(Spinlock) == OS_CHECK_FAILED))                                         /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_STATUS_STATE_1;
    }
    else if(OS_UNLIKELY(Os_LockListCheckTopIsSpinlock(locks) == OS_CHECK_FAILED))                                       /* SBSW_OS_SL_LOCKLISTCHECKTOPISSPINLOCK_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      status = OS_STATUS_LIFO_TOP_IS_RESOURCE;
    }
    else if(OS_UNLIKELY(Os_LockListCheckIsListTop(locks, &(Spinlock->Lock)) == OS_CHECK_FAILED))                        /* SBSW_OS_SL_LOCKLISTCHECKISLISTTOP_001 */
    {
      status = OS_STATUS_SPINLOCK_ORDER;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                           /* SBSW_OS_SL_APPCHECKACCESS_001 */ /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
                                          Os_SpinlockGetAccessingApplications(Spinlock)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* No error occurred. MISRA 14.10 */
    }
  }

  if(OS_LIKELY(status == OS_STATUS_OK))
  {
    Os_TaskPrioType previousPriority;

    previousPriority = Os_SpinlockGetDyn(Spinlock)->PreviousPriority;                                                   /* SBSW_OS_FC_PRECONDITION */

    /* #20 If the spinlock owner is traced: */
    if(Spinlock->Trace == OS_SPINLOCKTRACE_ENABLED)                                                                     /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      /* #30 Release the spinlock with owner tracing. */
      Os_SpinlockTraceOwnerRelease(Spinlock);                                                                           /* SBSW_OS_FC_PRECONDITION */
    }
    /* #40 Otherwise: */
    else
    {
      /* #50 Release the spinlock. */
      Os_SpinlockInternalRelease(Spinlock);                                                                             /* SBSW_OS_FC_PRECONDITION */
    }

    /* #60 Release the configured interrupt/task level. */
    Os_SpinlockResumeByMethod(Spinlock, previousPriority);                                                              /* SBSW_OS_FC_PRECONDITION */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_SpinlockTryGet()
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
 */
FUNC(Os_StatusType, OS_CODE) Os_SpinlockTryGet
(
  P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) Spinlock,
  TryToGetSpinlockType* Success
)
{
  Os_StatusType status;

  status = OS_STATUS_OK;

  /* #10 If the module is not enabled: KernelPanic. */
  if(Os_SpinlockIsEnabled() == 0u)                                                                                      /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #15 Perform error checks if required by the spinlock. */
  /* Enhance performance of spinlocks without checks by using OS_UNLIKELY. */
  if(OS_UNLIKELY(Spinlock->Checks == OS_SPINLOCKCHECK_ENABLED))
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    currentThread = Os_CoreGetThread();
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SL_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_SpinlockCheckIsNotLockedLocal(Spinlock) == OS_CHECK_FAILED))                                      /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_STATUS_INTERFERENCE_DEADLOCK;
    }
    else if(OS_UNLIKELY(Os_SpinlockCheckIsLockOrderValid(Spinlock) == OS_CHECK_FAILED))                                 /* SBSW_OS_FC_PRECONDITION */
    {
      status = OS_STATUS_NESTING_DEADLOCK;
    }
    else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_TRYTOGETSPINLOCK) == OS_CHECK_FAILED))   /* SBSW_OS_SL_THREADCHECKCALLCONTEXT_001 */
    {
      status = OS_STATUS_CALLEVEL;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                           /* SBSW_OS_SL_APPCHECKACCESS_001 */  /* SBSW_OS_FC_PRECONDITION */
                                          Os_SpinlockGetAccessingApplications(Spinlock)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* No error occurred. MISRA 14.10 */
    }
  }

  if(OS_LIKELY(status == OS_STATUS_OK))
  {
    Os_StdReturnType result;
    Os_TaskPrioType previousPriority;

    /* #20 Lock the configured interrupt/task level. */
    previousPriority = Os_SpinlockSuspendByMethod(Spinlock);                                                            /* SBSW_OS_FC_PRECONDITION */

    /* #30 If the spinlock owner is traced: */
    /* Enhance performance of spinlocks without tracing by using OS_UNLIKELY. */
    if(OS_UNLIKELY(Spinlock->Trace == OS_SPINLOCKTRACE_ENABLED))                                                        /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
    {
      /* #40 Try to get the spinlock with owner tracing. */
      result = Os_SpinlockTraceOwnerTryGet(Spinlock);                                                                   /* SBSW_OS_FC_PRECONDITION */
    }
    /* #50 Otherwise: */
    else
    {
      /* #60 Try to get the spinlock. */
      result = Os_SpinlockInternalTryGet(Spinlock);                                                                     /* SBSW_OS_FC_PRECONDITION */
    }


    /* #70 If get lock succeeded: */
    if(OS_LIKELY(result == OS_HAL_SPINLOCKSUCCEEDED))                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /* #80 Save task priority. */
      Os_SpinlockGetDyn(Spinlock)->PreviousPriority = previousPriority;                                                 /* SBSW_OS_SL_SPINLOCKGETDYN_001 */ /* SBSW_OS_FC_PRECONDITION */
      *Success = TRYTOGETSPINLOCK_SUCCESS;                                                                              /* SBSW_OS_PWA_PRECONDITION */
    }
    /* #90 Otherwise: */
    else
    {
      /* #100 Resume interrupt/task level. */
      Os_SpinlockResumeByMethod(Spinlock, previousPriority);                                                            /* SBSW_OS_FC_PRECONDITION */
      *Success = TRYTOGETSPINLOCK_NOSUCCESS;                                                                            /* SBSW_OS_PWA_PRECONDITION */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_GetSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetSpinlock
(
  SpinlockIdType SpinlockId
)
{
  Os_StatusType status;

  /* #10 Check the Id. */
  if(Os_SpinlockIsEnabled() == 0u)                                                                                      /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_SpinlockCheckId(SpinlockId) == OS_CHECK_FAILED))                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  {
    status = OS_STATUS_ID_1;
  }
  /* #20 If check succeeded: */
  else
  {
    P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) spinlock;

    spinlock = Os_SpinlockId2Spinlock(SpinlockId);

    /* #30 If the lock is an user lock, get the base spinlock. */
    /* Use OS_LIKELY in order to enhance the performance of user locks. */
    if(OS_LIKELY(spinlock->Mode == OS_SPINLOCKMODE_USER))                                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      Os_SpinlockInternalGet(spinlock);                                                                                 /* SBSW_OS_SL_SPINLOCKINTERNALGET_001 */
      status = OS_STATUS_OK;
    }
    /* #40 Otherwise use the internal trap function to get the spinlock. */
    else
    {
      status = Os_TrapSpinlockGet(spinlock);                                                                            /* SBSW_OS_SL_TRAPSPINLOCKGET_001 */
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Api_ReleaseSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_ReleaseSpinlock(SpinlockIdType SpinlockId)
{
  Os_StatusType status;

  /* #10 Check the Id. */
  if(Os_SpinlockIsEnabled() == 0u)                                                                                      /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_SpinlockCheckId(SpinlockId) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  /* #20 If check succeeded: */
  else
  {
    P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) spinlock;

    spinlock = Os_SpinlockId2Spinlock(SpinlockId);

    /* #30 If the lock is a user lock release the base spinlock. */
    /* Use OS_LIKELY in order to enhance the performance of user locks. */
    if(OS_LIKELY(spinlock->Mode == OS_SPINLOCKMODE_USER))                                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /* #30 If the lock is a user lock release the base spinlock. */
      Os_SpinlockInternalRelease(spinlock);                                                                             /* SBSW_OS_SL_SPINLOCKINTERNALRELEASE_001 */
      status = OS_STATUS_OK;
    }
    /* #40 Otherwise use the internal trap function to release the spinlock. */
    else
    {
      status = Os_TrapSpinlockRelease(spinlock);                                                                        /* SBSW_OS_SL_TRAPSPINLOCKRELEASE_001 */
    }
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Api_TryToGetSpinlock()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_TryToGetSpinlock
(
  SpinlockIdType SpinlockId,
  TryToGetSpinlockType* Success
)
{
  Os_StatusType status;

  /* #10 Check the Id. */
  if(Os_SpinlockIsEnabled() == 0u)                                                                                      /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_SpinlockCheckId(SpinlockId) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  /* #20 If check succeeded: */
  else
  {
    P2CONST(Os_SpinlockConfigType, AUTOMATIC, OS_CONST) spinlock;

    spinlock = Os_SpinlockId2Spinlock(SpinlockId);

    /*  #30 If the lock is a user lock try to get the base spinlock. */
    /* Use OS_LIKELY in order to enhance the performance of user locks. */
    if(OS_LIKELY(spinlock->Mode == OS_SPINLOCKMODE_USER))                                                               /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      Os_StdReturnType result;
      result = Os_SpinlockInternalTryGet(spinlock);                                                                     /* SBSW_OS_SL_SPINLOCKINTERNALTRYGET_001 */

      if(result == OS_HAL_SPINLOCKSUCCEEDED)                                                                            /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        *Success = TRYTOGETSPINLOCK_SUCCESS;                                                                            /* SBSW_OS_PWA_PRECONDITION */
      }
      else
      {
        *Success = TRYTOGETSPINLOCK_NOSUCCESS;                                                                          /* SBSW_OS_PWA_PRECONDITION */
      }

      status = OS_STATUS_OK;
    }
    /* #40 Otherwise use the internal trap function try-get function. */
    else
    {
      status = Os_TrapSpinlockTryGet(spinlock, Success);                                                                /* SBSW_OS_SL_TRAPSPINLOCKTRYGET_001 */
    }
  }

  return status;
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_SL_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with an OwnerThread derived from the return value of Os_SpinlockGetDyn.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKGETDYN_M]
                 \R [CM_OS_SPINLOCK_OWNERTHREAD_R]

\ID SBSW_OS_SL_TASKTHREAD2TASK_001
 \DESCRIPTION   Os_TaskThread2Task is called is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_TASKGETPRIORITY_001
 \DESCRIPTION   Os_TaskGetPriority is called is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_SL_COREGETSCHEDULER_001
 \DESCRIPTION    Os_CoreGetScheduler is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_SL_SCHEDULERINCREASEPRIO_001
 \DESCRIPTION    Os_SchedulerIncreasePrio is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_SL_SCHEDULERDECREASEPRIO_001
 \DESCRIPTION    Os_SchedulerDecreasePrio is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_SL_SCHEDULERTASKSWITCHISNEEDED_001
 \DESCRIPTION    Os_SchedulerTaskSwitchIsNeeded is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_SL_TASKSWITCH_001
 \DESCRIPTION    Os_TaskSwitch is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_SL_HAL_SPINISLOCKED_001
 \DESCRIPTION    Os_Hal_SpinIsLocked is called with a pointer derived from the return value of Os_SpinlockGetDyn.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKGETDYN_M]

\ID SBSW_OS_SL_SPINLOCKGETDYN_001
 \DESCRIPTION    Write access to the return value of Os_SpinlockGetDyn.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKGETDYN_M]

\ID SBSW_OS_SL_SPINLOCKGETDYN_002
 \DESCRIPTION    Os_SpinlockGetDyn is called with the return value of Os_ThreadGetSpinlocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETSPINLOCKS_N]

\ID SBSW_OS_SL_SPINLOCKGETDYN_003
 \DESCRIPTION    Os_SpinlockGetDyn is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]

\ID SBSW_OS_SL_HAL_SPINTRYLOCK_001
 \DESCRIPTION    Os_Hal_SpinTryLock is called with a pointer derived from the return value of Os_SpinlockGetDyn.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKGETDYN_M]

\ID SBSW_OS_SL_HAL_SPININIT_001
 \DESCRIPTION    Os_Hal_SpinInit is called with a pointer derived from the return value of Os_SpinlockGetDyn.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKGETDYN_M]

\ID SBSW_OS_SL_THREADGETSPINLOCKS_001
 \DESCRIPTION    Os_ThreadGetSpinlocks is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_THREADGETSPINLOCKS_002
 \DESCRIPTION    Write access to the return value of Os_ThreadGetSpinlocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETSPINLOCKS_N]

\ID SBSW_OS_SL_LOCKLISTPUSH_001
 \DESCRIPTION    Os_LockListPush is called with the return value of Os_ThreadGetLocks and a value derived from an
                 argument which is passed to the caller. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_SL_LOCKLISTPOP_001
 \DESCRIPTION    Os_LockListPop is called with the return value of Os_ThreadGetLocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_SL_THREADGETLOCKS_001
 \DESCRIPTION    Os_ThreadGetLocks is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_LOCKLISTDELETE_001
 \DESCRIPTION    Os_LockListDelete is called with the return value of Os_ThreadGetLocks and a value derived from the
                 return value of Os_SpinlockId2Spinlock. Precondition ensures that the return value of
                 Os_ThreadGetLocks is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_HAL_SPINUNLOCKED_001
 \DESCRIPTION    Os_Hal_SpinUnlock is called with a pointer derived from the return value of Os_SpinlockGetDyn.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKGETDYN_M]

\ID SBSW_OS_SL_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_SL_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SL_LOCKLISTCHECKTOPISSPINLOCK_001
 \DESCRIPTION    Os_LockListCheckTopIsSpinlock is called with the return value of Os_ThreadGetLocks.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_SL_LOCKLISTCHECKISLISTTOP_001
 \DESCRIPTION    Os_LockListCheckIsListTop is called with the return value of Os_ThreadGetLocks and a pointer derived
                 from an argument of the caller function. Precondition ensures that the argument pointer is valid.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_THREADGETLOCKS_N]

\ID SBSW_OS_SL_SPINLOCKINTERNALGET_001
 \DESCRIPTION    Os_SpinlockInternalGet is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_SPINLOCKINTERNALTRYGET_001
 \DESCRIPTION    Os_SpinlockInternalTryGet is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_SPINLOCKINTERNALRELEASE_001
 \DESCRIPTION    Os_SpinlockInternalRelease is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_TRAPSPINLOCKRELEASE_001
 \DESCRIPTION    Os_TrapSpinlockRelease is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_TRAPSPINLOCKGET_001
 \DESCRIPTION    Os_TrapSpinlockGet is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_TRAPSPINLOCKTRYGET_001
 \DESCRIPTION    Os_TrapSpinlockTryGet is called with the return value of Os_SpinlockId2Spinlock.
 \COUNTERMEASURE \M [CM_OS_SPINLOCKID2SPINLOCK_M]
                 \R [CM_OS_SPINLOCK_ID_R]

\ID SBSW_OS_SL_TRACESPINLOCKREQUESTED_001
 \DESCRIPTION    Os_TraceSpinlockRequested is called with a pointer derived from an argument of the caller function.
                 Precondition ensures that the argument pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_SL_SPINLOCK_TIMINGHOOKTRACE_M]

\ID SBSW_OS_SL_TRACESPINLOCKTAKEN_001
 \DESCRIPTION    Os_TraceSpinlockTaken is called with a pointer derived from an argument of the caller function.
                 Precondition ensures that the argument pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_SL_SPINLOCK_TIMINGHOOKTRACE_M]

\ID SBSW_OS_SL_TRACESPINLOCKRELEASED_001
 \DESCRIPTION    Os_TraceSpinlockReleased is called with a pointer derived from an argument of the caller function.
                 Precondition ensures that the argument pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_SL_SPINLOCK_TIMINGHOOKTRACE_M]


SBSW_JUSTIFICATION_END */


/*
\CM CM_OS_SPINLOCKID2SPINLOCK_M
      Verify that:
        1. each spinlock pointer in OsCfg_SpinlockRefs is not NULL_PTR,
        2. each the size of OsCfg_SpinlockRefs is equal to OS_SPINLOCKID_COUNT + 1 and
        3. each element in SpinlockIdType has a lower value than OS_SPINLOCKID_COUNT.

\CM CM_OS_SPINLOCKGETDYN_M
      Verify that the Dyn pointer of each Spinlock is a non NULL_PTR.

\CM CM_OS_SPINLOCK_OWNERTHREAD_R
      Implementation ensures that the OwnerThread is a non NULL_PTR.

\CM CM_OS_SPINLOCK_ID_R
      Implementation ensures that the given spinlock ID is in range.

\CM CM_OS_SL_SPINLOCK_TIMINGHOOKTRACE_M
      Verify that the TimingHookTrace of each Spinlock is a non NULL_PTR, if Tracing is enabled.

*/


/* START_COVERAGE_JUSTIFICATION
 *
\ID COV_OS_SPINLOCKRACECONDITION
   \ACCEPT XF
   \REASON [COV_MSR_INV_STATE]


END_COVERAGE_JUSTIFICATION */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Spinlock.c
 **********************************************************************************************************************/
