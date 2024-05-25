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
 * \addtogroup Os_Task
 * \{
 *
 * \file
 * \brief       Implementation of task module.
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


#define OS_TASK_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"
# include "Os_Task.h"
# include "Os_Task_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_Application.h"
# include "Os_Common.h"
# include "Os_Core.h"
# include "Os_Error.h"
# include "Os_Interrupt.h"
# include "Os_Scheduler.h"
# include "Os_Thread.h"
# include "Os_Trace.h"
# include "Os_XSignal.h"
# include "Os_Event.h"
# include "Os.h"

/* Os HAL dependencies */
# include "Os_Hal_Core.h"
# include "Os_Hal_MemoryProtection.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION MACROS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  LOCAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/**********************************************************************************************************************
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
 *  Os_TaskIsPreTaskHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the PreTaskHook enabled or not.
 *  \details      This allows user to trace task switches.
 *
 *  \retval       !0    PreTaskHook is enabled.
 *  \retval       0     PreTaskHook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskIsPreTaskHookEnabled,
( void ));


/***********************************************************************************************************************
 *  Os_TaskCheckIsScheduleAllowed()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given task has a private stack (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        --no details--
 *
 *  \param[in]      Task        The task to check. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given task has a private stack.
 *  \retval         OS_CHECK_FAILED       If the given task has a shared stack.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskCheckIsScheduleAllowed,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskCheckIsActivationAllowed()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given task may be activated again (Not OS_CHECK_FAILED)
 *  \details        --no details--
 *                  or not (OS_CHECK_FAILED).
 *
 *  \param[in]      Task        The task to check. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given task may be activated again.
 *  \retval         OS_CHECK_FAILED       If the given task may not be activated.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskCheckIsActivationAllowed,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskReset()
 **********************************************************************************************************************/
/*! \brief          Reset the given task for the next run.
 *  \details        Sets all dynamic data of the given task to their configured startup settings, except
 *                  ActivationsAllowed and current priority.
 *
 *  \param[in,out]  Task    The task which shall be reset. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            ActivationsAllowed has been adapted (incremented or set to maximum value) before.
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_TaskReset
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_TaskInternalInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given task for the first time.
 *  \details        The kernel uses this function to initialize all tasks during OS initialization.
 *                  It sets all dynamic data of the given task to its configured startup settings.
 *                  Thus, it will perform a fresh start, when the kernel resumes the task the next time.
 *                  The function is called for the prestart task and the idle task in Init-Step3 and for all tasks in
 *                  Init-Step4.
 *
 *  \param[in,out]  Task      The task which shall be initialized. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_LOCAL FUNC(void, OS_CODE) Os_TaskInternalInit
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_TaskIsPreTaskHookEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskIsPreTaskHookEnabled,
( void ))
{
  return (Os_StdReturnType)(OS_CFG_PRETASKHOOK == STD_ON);                                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_TaskCheckIsScheduleAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskCheckIsScheduleAllowed,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(Task->Reschedule == OS_TASKSCHEDULE_ALLOWED));                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_TaskCheckIsActivationAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskCheckIsActivationAllowed,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
))
{
  return ((Os_StdReturnType)Os_TaskGetDyn(Task)->ActivationsAllowed);                                                   /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TaskReset()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 * Internal comment removed.
 *
 *
 */
OS_LOCAL FUNC(void, OS_CODE) Os_TaskReset
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  /* #10 Reset task state */
  if(Os_TaskGetDyn(Task)->ActivationsAllowed == Task->MaxActivations)                                                   /* SBSW_OS_FC_PRECONDITION */
  {
    Os_TaskSetState(Task, SUSPENDED);                                                                                   /* SBSW_OS_FC_PRECONDITION */
  }
  else
  {
    Os_TaskSetState(Task, READY);                                                                                       /* SBSW_OS_FC_PRECONDITION */
  }

  /* #20 Clear all events */
  Os_EventInit(&(Os_TaskGetDyn(Task)->Events));                                                                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_EVENTINIT_001 */

  /* #30 Reset thread attributes */
  Os_ThreadKill(Os_TaskGetThread(Task));                                                                                /* SBSW_OS_TASK_THREADKILL_001 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TaskInternalInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_LOCAL FUNC(void, OS_CODE) Os_TaskInternalInit
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  /* #10 Assert all assumptions on configured data (e.g. running prio logically higher than home prio). */
  Os_Assert((Os_StdReturnType)(Task != NULL_PTR));                                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(Os_TaskGetThread(Task) != NULL_PTR));                                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
  Os_Assert(Os_ErrIsValueLo((uint32)(Os_TaskGetId(Task)), (uint32)(OS_TASKID_COUNT)));                                  /* PRQA S 2995 */ /* MD_Os_Rule2.2_2995 */ /* SBSW_OS_FC_PRECONDITION */
  Os_Assert(Os_SchedulerPriorityIsHigherOrEqual(Os_TaskGetRunningPriority(Task), Os_TaskGetHomePriority(Task)));        /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */
  Os_Assert((Os_StdReturnType)(Os_TaskGetMaxActivations(Task) > 0u ));                                                  /* PRQA S 2812, 4304 */ /* MD_Os_Dir4.1_2812, MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
  Os_Assert((Os_StdReturnType)(Os_TaskGetDyn(Task) != NULL_PTR));                                                       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize all task attributes and all its children. */
  Os_TaskGetDyn(Task)->ActivationsAllowed = Os_TaskGetMaxActivations(Task);                                             /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_TASKGETDYN_002 */
  Os_TaskSetState(Task, SUSPENDED);                                                                                     /* SBSW_OS_FC_PRECONDITION */
  Os_TaskSetPriority(Task, Os_TaskGetHomePriority(Task));                                                               /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

  Os_EventInit(&(Os_TaskGetDyn(Task)->Events));                                                                         /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_EVENTINIT_001 */

  /* #30 Initialize thread. */
  Os_ThreadInit(Os_TaskGetThread(Task));                                                                                /* SBSW_OS_TASK_THREADINIT_001 */ /* SBSW_OS_FC_PRECONDITION */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_Api_ActivateTask()
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
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_ActivateTask
(
  TaskType TaskID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_ACTIVATETASK) == OS_CHECK_FAILED))              /* SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_TaskCheckId(TaskID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) targetThread;
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) targetTask;
    Os_AppAccessMaskType permittedApplications;

    targetTask = Os_TaskId2Task(TaskID);
    targetThread = Os_TaskGetThread(targetTask);                                                                        /* SBSW_OS_TASK_TASKGETTHREAD_001 */
    permittedApplications = Os_TaskGetAccessingApplications(targetTask);                                                /* SBSW_OS_TASK_TASKGETACCESSINGAPPLICATIONS_001 */

    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_TASK_THREADGETCURRENTAPPLICATION_001 */

    if( OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED) )                  /* SBSW_OS_TASK_APPCHECKACCESS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) targetCore;
      targetCore = Os_ThreadGetCore(targetThread);                                                                      /* SBSW_OS_TASK_THREADGETCORE_002 */

      /* #20 If the given task belongs to the local core, */
      if(OS_LIKELY(Os_CoreAsrIsCoreLocal(targetCore) != 0u))                                                            /* SBSW_OS_TASK_COREASRISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        /* #30 Suspend interrupts. */
        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        /* #40 Call internal function to activate the given task. */
        status = Os_TaskActivateLocalTask(targetTask);                                                                  /* SBSW_OS_TASK_TASKACTIVATELOCALTASK_001 */

        /* #50 If the caller is a task and activation leads to a task switch: */
        if(OS_LIKELY(status == OS_STATUS_OK))
        {
          if(Os_ThreadIsTask(currentThread) != 0u)                                                                      /* SBSW_OS_TASK_THREADISTASK_001 */
          {
            P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore = Os_ThreadGetCore(currentThread);             /* SBSW_OS_TASK_THREADGETCORE_001 */
            P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler = Os_CoreGetScheduler(localCore);            /* SBSW_OS_TASK_COREGETSCHEDULER_001 */

            if((Os_SchedulerTaskSwitchIsNeeded(scheduler) != 0u))                                                       /* SBSW_OS_TASK_SCHEDULERTASKSWITCHISNEEDED_001 */
            {
              /* #60 Perform a task switch. */
              Os_TaskSwitch(scheduler, currentThread);                                                                  /* SBSW_OS_TASK_TASKSWITCH_001 */
            }
          }
        }

        /* #70 Resume interrupts. */
        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      /* #80 If the task belongs to a foreign core: */
      else
      {
        /* #90 Signal the responsible core to activate the task. */
        status = Os_XSigSend_ActivateTask(targetCore, currentThread, TaskID);                                           /* SBSW_OS_TASK_XSIGSEND_001 */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_TaskActivateLocalTask()
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
 */
FUNC(Os_StatusType, OS_CODE) Os_TaskActivateLocalTask
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) taskThread;
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) timingProtection;

  taskThread = Os_TaskGetThread(Task);                                                                                  /* SBSW_OS_FC_PRECONDITION */
  timingProtection = Os_CoreAsrGetTimingProtection(Os_ThreadGetCore(taskThread));                                       /* SBSW_OS_TASK_COREASRGETTIMINGPROTECTION_001 */ /* SBSW_OS_TASK_THREADGETCORE_002 */

  /* #10 Check whether the given task's activation counter allows further activation. */
  if(OS_UNLIKELY(Os_TaskCheckIsActivationAllowed(Task) == OS_CHECK_FAILED))                                             /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_LIMIT;
    /* #20 Inform the trace object about this. */
    Os_TraceTaskActivateLimit(Os_ThreadGetTrace(taskThread));                                                           /* SBSW_OS_TASK_TRACETASKACTIVATELIMIT_001 */ /* SBSW_OS_TASK_THREADGETTRACE_001 */
  }
  /*  #30 Check whether the owner application of the given task is accessible. */
  else if(OS_UNLIKELY(Os_AppCheckIsAccessible(Os_ThreadGetOwnerApplication(taskThread)) == OS_CHECK_FAILED))            /* SBSW_OS_TASK_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_TASK_THREADGETOWNERAPPLICATION_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  /* #40 Check whether inter-arrival time is okay. */
  else if(OS_UNLIKELY(Os_TpCheckInterArrival(timingProtection, Os_ThreadGetTpConfig(taskThread)) == OS_CHECK_FAILED))   /* SBSW_OS_TASK_TPCHECKINTERARRIVAL_001 */ /* SBSW_OS_TASK_THREADGETTPCONFIG_001 */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    status = OS_STATUS_OK;
  }
  else
  {
    P2VAR(Os_TaskType, AUTOMATIC, OS_VAR_NOINIT) taskDyn;

    taskDyn = Os_TaskGetDyn(Task);                                                                                      /* SBSW_OS_FC_PRECONDITION */
    /* #50 Decrement the task's activation counter. */
    --(taskDyn->ActivationsAllowed);                                                                                    /* SBSW_OS_TASK_TASKGETDYN_002 */

    /* #60 Set the task's scheduling state to READY. */
    if(taskDyn->State == SUSPENDED)
    {
      Os_TaskSetState(Task, READY);                                                                                     /* SBSW_OS_FC_PRECONDITION */
    }

    /* #70 Tell the scheduler to schedule the task. */
    Os_SchedulerInsert(Os_TaskGetScheduler(Task), Task);                                                                /* SBSW_OS_TASK_SCHEDULERINSERT_001 */ /* SBSW_OS_FC_PRECONDITION */

    /* #80 Inform the trace object */
    Os_TraceTaskActivate(Os_ThreadGetTrace(taskThread));                                                                /* SBSW_OS_TASK_TRACETASKACTIVATE_001 */ /* SBSW_OS_TASK_THREADGETTRACE_001 */

    status = OS_STATUS_OK;
  }
  /* #90 Return whether a task switch is needed. */
  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_TaskActivateRestartTask()
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
FUNC(Os_StatusType, OS_CODE) Os_TaskActivateRestartTask
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) taskThread = Os_TaskGetThread(Task);                                /* SBSW_OS_FC_PRECONDITION */
  P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) timingProtection;

  Os_Assert((Os_StdReturnType)((Os_TaskGetDyn(Task)->ActivationsAllowed) > 0u));                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */

  timingProtection = Os_CoreAsrGetTimingProtection(Os_ThreadGetCore(taskThread));                                       /* SBSW_OS_TASK_COREASRGETTIMINGPROTECTION_001 */ /* SBSW_OS_TASK_THREADGETCORE_002 */

  /* #10 Check whether inter-arrival time is okay. */
  if(OS_UNLIKELY(Os_TpCheckInterArrival(timingProtection, Os_ThreadGetTpConfig(taskThread)) == OS_CHECK_FAILED))        /* SBSW_OS_TASK_TPCHECKINTERARRIVAL_001 */ /* SBSW_OS_TASK_THREADGETTPCONFIG_001 */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    status = OS_STATUS_OK;
  }
  else
  {
    /* #20 Inform the trace object. */
    Os_TraceTaskActivate(Os_ThreadGetTrace(taskThread));                                                                /* SBSW_OS_TASK_TRACETASKACTIVATE_001 */ /* SBSW_OS_TASK_THREADGETTRACE_001 */

    /* #30 Decrement the task's activation counter. */
    --(Os_TaskGetDyn(Task)->ActivationsAllowed);                                                                        /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_TASKGETDYN_002 */

    /* #40 Set the task's scheduling state to READY. */
    Os_TaskSetState(Task, READY);                                                                                       /* SBSW_OS_FC_PRECONDITION */

    /* #50 Tell the scheduler to schedule the task. */
    Os_SchedulerInsert(Os_TaskGetScheduler(Task), Task);                                                                /* SBSW_OS_TASK_SCHEDULERINSERT_001 */ /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Api_TerminateTask()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_TerminateTask(void)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();                                                                                   /* PRQA S 1527 */ /* MD_Os_Rule5.9_1527 */

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_TERMINATETASK) == OS_CHECK_FAILED))             /* SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckResourcesReleased(currentThread) == OS_CHECK_FAILED))                               /* SBSW_OS_TASK_THREADCHECKRESOURCESRELEASED_001 */
  {
    status = OS_STATUS_RESOURCE;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckSpinlocksReleased(currentThread) == OS_CHECK_FAILED))                               /* SBSW_OS_TASK_THREADCHECKSPINLOCKSRELEASED_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    status = OS_STATUS_SPINLOCK;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;
    P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) localScheduler;

    currentTask = Os_TaskThread2Task(currentThread);                                                                    /* SBSW_OS_TASK_TASKTHREAD2TASK_001 */
    localScheduler = Os_TaskGetScheduler(currentTask);                                                                  /* SBSW_OS_TASK_TASKGETSCHEDULER_001 */

    /* #20 Disable interrupts. */
    Os_IntDisable();

    /* #30 Reset the current task for the next time. */
    ++(Os_TaskGetDyn(currentTask)->ActivationsAllowed);                                                                 /* SBSW_OS_TASK_TASKGETDYN_003 */ /* SBSW_OS_TASK_TASKGETDYN_002 */
    Os_TaskReset(currentTask);                                                                                          /* SBSW_OS_TASK_TASKRESET_001 */

    /* #40 Tell the scheduler to remove the current activation instance of the running task. */
    (void)Os_SchedulerRemoveCurrentTask(localScheduler);                                                                /* SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_001 */

    /* #50 Resume the next task. */
    Os_TaskResume(localScheduler);                                                                                      /* SBSW_OS_TASK_TASKRESUME_001 */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */



/***********************************************************************************************************************
 *  Os_Api_ChainTask()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_ChainTask
(
  TaskType TaskID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();                                                                                   /* PRQA S 1527 */ /* MD_Os_Rule5.9_1527 */

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_CHAINTASK) == OS_CHECK_FAILED))                 /* SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_TaskCheckId(TaskID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckResourcesReleased(currentThread) == OS_CHECK_FAILED))                               /* SBSW_OS_TASK_THREADCHECKRESOURCESRELEASED_001 */
  {
    status = OS_STATUS_RESOURCE;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckSpinlocksReleased(currentThread) == OS_CHECK_FAILED))                               /* SBSW_OS_TASK_THREADCHECKSPINLOCKSRELEASED_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    status = OS_STATUS_SPINLOCK;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) targetTask;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    targetTask = Os_TaskId2Task(TaskID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_TASK_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_TaskGetAccessingApplications(targetTask);                                                /* SBSW_OS_TASK_TASKGETACCESSINGAPPLICATIONS_001 */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED))                    /* SBSW_OS_TASK_APPCHECKACCESS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;
      P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) localScheduler;
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore;
      boolean startNextTask;
      Os_IntStateType interruptState;

      currentTask = Os_TaskThread2Task(currentThread);                                                                  /* SBSW_OS_TASK_TASKTHREAD2TASK_001 */
      localCore = Os_ThreadGetCore(currentThread);                                                                      /* SBSW_OS_TASK_THREADGETCORE_001 */
      localScheduler = Os_TaskGetScheduler(currentTask);                                                                /* SBSW_OS_TASK_TASKGETSCHEDULER_001 */
      startNextTask = TRUE;

      /* #20 If the task is self chaining */
      if(currentTask == targetTask)
      {
        P2CONST(Os_TpConfigType, TYPEDEF, OS_CONST) timingProtection;
        timingProtection = Os_CoreAsrGetTimingProtection(localCore);                                                    /* SBSW_OS_TASK_COREASRGETTIMINGPROTECTION_001 */

        /* #30 Suspend interrupts. */
        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        /* #40 In case of arrival time violation. */
        if(OS_UNLIKELY(Os_TpCheckInterArrival(timingProtection, Os_ThreadGetTpConfig(currentThread)                     /* SBSW_OS_TASK_TPCHECKINTERARRIVAL_001 */ /* SBSW_OS_TASK_THREADGETTPCONFIG_001 */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
                                              ) == OS_CHECK_FAILED))
        {
          /* This code is only executed if protection hook reaction is PRO_IGNORE */

          /* #50 Do not restart the self chaining task */
          startNextTask = FALSE;

          /* #60 set status to OS_STATUS_OK and return to the calling task at the end of the function */
          status = OS_STATUS_OK;
        }
        /* #70 else */
        else
        {
          /* #80 Remove it from the scheduler. */
          /* Necessary as the task may not run on it's home priority. */
          (void)Os_SchedulerRemoveCurrentTask(localScheduler);                                                          /* SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_001 */

          /* #90 Inform the trace object. */
          Os_TraceTaskActivate(Os_ThreadGetTrace(currentThread));                                                       /* SBSW_OS_TASK_TRACETASKACTIVATE_001 */ /* SBSW_OS_TASK_THREADGETTRACE_002 */

          /* #100 Reset the task. */
          Os_TaskReset(currentTask);                                                                                    /* SBSW_OS_TASK_TASKRESET_001 */

          /* #110 Re-insert it to the scheduler. */
          /* Add the task to the scheduler on it's home priority. */
          Os_SchedulerInsert(localScheduler, currentTask);                                                              /* SBSW_OS_TASK_SCHEDULERINSERT_002 */

          status = OS_STATUS_OK;
        }

      }
      /* #120 Otherwise: */
      else
      {
        /* #130 If the given task belongs to the local core: */
        if(OS_LIKELY(Os_TaskIsCoreLocal(targetTask) != 0u))                                                             /* SBSW_OS_TASK_TASKISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
        {
          /* #140 Suspend interrupts. */
          Os_IntSuspend(&interruptState);                                                                               /* SBSW_OS_FC_POINTER2LOCAL */

          /* #150 Call internal function to activate the given task. */
          status = Os_TaskActivateLocalTask(targetTask);                                                                /* SBSW_OS_TASK_TASKACTIVATELOCALTASK_001 */
        }
        /* #160 If the task belongs to a foreign core: */
        else
        {
          /* #170 Signal the responsible core to activate the task. */
          status = Os_XSigSend_ActivateTask(Os_TaskGetCore(targetTask), currentThread, TaskID);                         /* SBSW_OS_TASK_XSIGSEND_001 */ /* SBSW_OS_TASK_TASKGETCORE_001 */

          /* #180 Suspend interrupts. */
          Os_IntSuspend(&interruptState);                                                                               /* SBSW_OS_FC_POINTER2LOCAL */
        }

        if(OS_LIKELY(status == OS_STATUS_OK))
        {
          /* #190 Reset the current task for the next time. */
          ++(Os_TaskGetDyn(currentTask)->ActivationsAllowed);                                                           /* SBSW_OS_TASK_TASKGETDYN_003 */ /* SBSW_OS_TASK_TASKGETDYN_002 */
          Os_TaskReset(currentTask);                                                                                    /* SBSW_OS_TASK_TASKRESET_001 */

          /* #200 Tell the scheduler to remove the current activation instance of the running task. */
          (void)Os_SchedulerRemoveCurrentTask(localScheduler);                                                          /* SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_001 */
        }
      }

      /* #210 If task activation could be performed */
      if(OS_LIKELY((status == OS_STATUS_OK) && (startNextTask == TRUE)))
      {
        /* #220 Resume the next thread (by a function call which never returns!). */
        Os_TaskResume(localScheduler);                                                                                  /* SBSW_OS_TASK_TASKRESUME_001 */
      }
      /* #230 else */
      else
      {
        /* #240 Resume interrupts. */
        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
    }
  }
  /* #250 Return the status value (error code). */
  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */



/***********************************************************************************************************************
 * Os_Api_Schedule()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_Schedule(void)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;

  currentThread = Os_CoreGetThread();                                                                                   /* PRQA S 1527 */ /* MD_Os_Rule5.9_1527 */
  currentTask = Os_TaskThread2Task(currentThread);                                                                      /* SBSW_OS_TASK_TASKTHREAD2TASK_001 */

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_SCHEDULE) == OS_CHECK_FAILED))                  /* SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_TaskCheckIsScheduleAllowed(currentTask) == OS_CHECK_FAILED))                                   /* SBSW_OS_TASK_TASKCHECKISSCHEDULEALLOWED_001 */
  {
    status = OS_STATUS_CALLEVEL_SHARED_STACK;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckResourcesReleased(currentThread) == OS_CHECK_FAILED))                               /* SBSW_OS_TASK_THREADCHECKRESOURCESRELEASED_001 */
  {
    status = OS_STATUS_RESOURCE;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckSpinlocksReleased(currentThread) == OS_CHECK_FAILED))                               /* SBSW_OS_TASK_THREADCHECKSPINLOCKSRELEASED_001 */ /* COV_OS_HALPLATFORMTESTEDASMULTICORE */
  {
    status = OS_STATUS_SPINLOCK;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) localScheduler;
    Os_IntStateType interruptState;

    localScheduler = Os_TaskGetScheduler(currentTask);                                                                  /* SBSW_OS_TASK_TASKGETSCHEDULER_001 */

    /* #20  Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    /* #30 Go to home prio and check whether higher prio tasks want to run. */
    /* #40 If there is a higher prio task: */
    if(Os_SchedulerReleaseRunningPrio(localScheduler) != 0u)                                                            /* SBSW_OS_TASK_SCHEDULERRELEASERUNNINGPRIO_001 */
    {
      /* #50 Perform a task switch to the next task. */
      Os_TaskSwitch(localScheduler, currentThread);                                                                     /* SBSW_OS_TASK_TASKSWITCH_002 */
    }
    /* #60 Otherwise, bring us back to running priority. */
    else
    {
      (void)Os_SchedulerInternalSchedule(localScheduler);                                                               /* SBSW_OS_TASK_SCHEDULERINTERNALSCHEDULE_001 */
    }

    /* #70 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_TaskInit()
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
FUNC(void, OS_CODE) Os_TaskInit
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  AppModeType AppMode
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) taskThread;
  taskThread = Os_TaskGetThread(Task);                                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #10 If the given task is not the idle task (idle task initialization is handled differently.): */
  if(Task != Os_CoreGetIdleTask(Os_ThreadGetCore(taskThread)))                                                          /* SBSW_OS_TASK_COREGETIDLETASK_001 */ /* SBSW_OS_TASK_THREADGETCORE_001 */
  {
    /* #20 Initialize task. */
    Os_TaskInternalInit(Task);                                                                                          /* SBSW_OS_FC_PRECONDITION */

    /* #30 If the given mode is one of the given task's autostart modes: */
    if((Task->AutostartModes & AppMode) != 0u)
    {
      /* #40 Inform the trace object. */
      Os_TraceTaskActivate(Os_ThreadGetTrace(taskThread));                                                              /* SBSW_OS_TASK_TRACETASKACTIVATE_001 */ /* SBSW_OS_TASK_THREADGETTRACE_001 */

      /* #50 Decrement the task's activation counter. */
      --(Os_TaskGetDyn(Task)->ActivationsAllowed);                                                                      /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_TASKGETDYN_002 */

      /* #60 Set the task's scheduling state to READY. */
      Os_TaskSetState(Task, READY);                                                                                     /* SBSW_OS_FC_PRECONDITION */

      /* #70 Tell the scheduler to schedule the task. */
      Os_SchedulerInsert(Os_TaskGetScheduler(Task), Task);                                                              /* SBSW_OS_TASK_SCHEDULERINSERT_001 */ /* SBSW_OS_FC_PRECONDITION */
    }
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_TaskIdleTaskInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_TaskIdleTaskInit
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  /* #10 Initialize task. */
  Os_TaskInternalInit(Task);                                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #20 Decrement the task's activation counter. */
  --(Os_TaskGetDyn(Task)->ActivationsAllowed);                                                                          /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_TASKGETDYN_002 */

  /* #30 Set the task's scheduling state to READY. */
  Os_TaskSetState(Task, READY);                                                                                         /* SBSW_OS_FC_PRECONDITION */

  /* #40 Tell the scheduler to schedule the task. */
  Os_SchedulerInsert(Os_TaskGetScheduler(Task), Task);                                                                  /* SBSW_OS_TASK_SCHEDULERINSERT_001 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TaskKillAll()
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
FUNC(void, OS_CODE) Os_TaskKillAll
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) thread;

  thread = Os_TaskGetThread(Task);                                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 Assert that the given task is assigned to the local core. */
  Os_Assert((Os_StdReturnType)(Os_ThreadGetCore(Os_CoreGetThread()) == Os_ThreadGetCore(thread)));                      /* PRQA S 1527, 4304 */ /* MD_Os_Rule5.9_1527, MD_Os_C90BooleanCompatibility */ /* SBSW_OS_TASK_THREADGETCORE_002 */ /* SBSW_OS_TASK_THREADGETCORE_001 */

  /* #20 Assert that the given task is not the idle loop or any other OS task. */
  Os_Assert((Os_StdReturnType)(Os_TaskGetId(Task) != INVALID_TASK));                                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */

  /* #30 Inform the trace object about the killing. */
  Os_TraceTaskKill(Os_ThreadGetTrace(thread), Os_TaskIsSuspended(Task));                                                /* SBSW_OS_TASK_TRACETASKKILL_001 */ /* SBSW_OS_TASK_THREADGETTRACE_001 */ /* SBSW_OS_FC_PRECONDITION */

  /* #40 Initialize the given task, so it can be activated again. */
  Os_TaskGetDyn(Task)->ActivationsAllowed = Task->MaxActivations;                                                       /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_TASKGETDYN_002 */
  Os_TaskReset(Task);                                                                                                   /* SBSW_OS_FC_PRECONDITION */

  /* #50 Tell the scheduler to remove all instances of the given task. */
  (void)Os_SchedulerRemoveTaskAll(Os_TaskGetScheduler(Task), Task);                                                     /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_TASK_SCHEDULERREMOVETASKALL_001 */

}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_TaskGetStateInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_TaskGetStateInternal
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  TaskStateRefType State
)
{
  Os_StatusType status;

  /* #10 If the given task belongs to the local core, */
  if(OS_LIKELY(Os_TaskIsCoreLocal(Task) != 0u))                                                                         /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  {
    /* #20 Call local function to get the current task state. */
    status = Os_TaskGetStateLocal(Task, State);                                                                         /* SBSW_OS_FC_PRECONDITION */
  }
  /* #30 If the task belongs to a foreign core, */
  else
  {
    /* #40 Signal the responsible core to get the current task state. */
    status = Os_XSigSend_GetTaskState(Os_TaskGetCore(Task), Os_CoreGetThread(), Task->TaskId, State);                   /* SBSW_OS_TASK_XSIGSEND_001 */ /* SBSW_OS_FC_PRECONDITION */
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_TaskKill()
 **********************************************************************************************************************/
/*!
 *
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_TaskKill(void)
{
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) targetTask;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler;

  currentThread = Os_CoreGetThread();                                                                                   /* PRQA S 1527 */ /* MD_Os_Rule5.9_1527 */
  core = Os_ThreadGetCore(currentThread);                                                                               /* SBSW_OS_TASK_THREADGETCORE_001 */
  scheduler = Os_CoreGetScheduler(core);                                                                                /* SBSW_OS_TASK_COREGETSCHEDULER_001 */
  targetTask = Os_SchedulerGetCurrentTask(scheduler);                                                                   /* SBSW_OS_TASK_SCHEDULERGETCURRENTTASK_001 */

  /* #10 Assert that the current task is not the local idle loop or any other OS task. */
  Os_Assert((Os_StdReturnType)(Os_CoreGetIdleTask(core) != targetTask));                                                /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_TASK_COREGETIDLETASK_001 */

  /* #20 Inform the trace object about the killing. */
  Os_TraceTaskKill(Os_ThreadGetTrace(currentThread), Os_TaskIsSuspended(targetTask));                                   /* SBSW_OS_TASK_TRACETASKKILL_001 */ /* SBSW_OS_TASK_THREADGETTRACE_001 */ /* SBSW_OS_TASK_TASKISSUPENDED_001 */

  /* #30 Reset the given task, so it can be activated again. */
  ++(Os_TaskGetDyn(targetTask)->ActivationsAllowed);                                                                    /* SBSW_OS_TASK_TASKGETDYN_001 */ /* SBSW_OS_TASK_TASKGETDYN_002 */
  Os_TaskReset(targetTask);                                                                                             /* SBSW_OS_TASK_TASKRESET_002 */

  /* #40 Tell the scheduler to remove the given task. */
  (void)Os_SchedulerRemoveCurrentTask(scheduler);                                                                       /* SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_002 */

}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */



/***********************************************************************************************************************
 *  Os_Api_GetTaskID()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetTaskID(TaskRefType TaskID)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();                                                                                   /* PRQA S 1527 */ /* MD_Os_Rule5.9_1527 */

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETTASKID) == OS_CHECK_FAILED))                 /* SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) core;
    P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler;
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;

    core = Os_ThreadGetCore(currentThread);                                                                             /* SBSW_OS_TASK_THREADGETCORE_001 */
    scheduler = Os_CoreGetScheduler(core);                                                                              /* SBSW_OS_TASK_COREGETSCHEDULER_001 */
    currentTask = Os_SchedulerGetCurrentTask(scheduler);                                                                /* SBSW_OS_TASK_SCHEDULERGETCURRENTTASK_001 */

    /* #20 Write the task's ID to the given pointer. */
    (*TaskID) = Os_TaskGetId(currentTask);                                                                              /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_TASK_TASKGETID_001 */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_GetTaskState()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetTaskState
(
  TaskType TaskID,
  TaskStateRefType State
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();                                                                                   /* PRQA S 1527 */ /* MD_Os_Rule5.9_1527 */

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_TaskCheckId(TaskID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETTASKSTATE) == OS_CHECK_FAILED))         /* SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) targetTask;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_AppAccessMaskType permittedApplications;

    targetTask = Os_TaskId2Task(TaskID);

    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_TASK_THREADGETCURRENTAPPLICATION_001 */
    permittedApplications = Os_TaskGetAccessingApplications(targetTask);                                                /* SBSW_OS_TASK_TASKGETACCESSINGAPPLICATIONS_001 */

    if( OS_UNLIKELY(Os_AppCheckAccess(currentApplication, permittedApplications) == OS_CHECK_FAILED) )                  /* SBSW_OS_TASK_APPCHECKACCESS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* #20 Call internal function to get the task state. */
      status = Os_TaskGetStateInternal(targetTask, State);                                                              /* SBSW_OS_TASK_TASKGETSTATEINTERNAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_TaskMissingTerminateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(void, OS_CODE, OS_NORETURN, Os_TaskMissingTerminateTask, (void))
{
  /* #10 Report the Error. */
  (void)Os_ErrReportTerminateTask(OS_STATUS_MISSINGEND);

  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;
    P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) localScheduler;

    currentThread = Os_CoreGetThread();
    currentTask = Os_TaskThread2Task(currentThread);                                                                    /* SBSW_OS_TASK_TASKTHREAD2TASK_001 */
    localScheduler = Os_TaskGetScheduler(currentTask);                                                                  /* SBSW_OS_TASK_TASKGETSCHEDULER_001 */

    Os_IntDisable();

    /* #20 Reset the current task and increment allowed activations. */
    ++(Os_TaskGetDyn(currentTask)->ActivationsAllowed);                                                                 /* SBSW_OS_TASK_TASKGETDYN_001 */ /* SBSW_OS_TASK_TASKGETDYN_002 */
    Os_TaskReset(currentTask);                                                                                          /* SBSW_OS_TASK_TASKRESET_001 */

    /* #30 Remove the current task from the scheduler. */
    (void)Os_SchedulerRemoveCurrentTask(localScheduler);                                                                /* SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_001 */

    /* #40 Resume the next task. */
    Os_TaskResume(localScheduler);                                                                                      /* SBSW_OS_TASK_TASKRESUME_001 */
  }

  Os_ErrKernelPanic();
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_TaskCallPreTaskHook()
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
FUNC(void, OS_CODE) Os_TaskCallPreTaskHook(void)
{
  /* #10 If PreTaskHook is enabled: */
  if(Os_TaskIsPreTaskHookEnabled() != 0u)                                                                               /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;
    Os_CallContextType prevCallContext;

    currentThread = Os_CoreGetThread();

    /* #20 Save current call context and set new call context. */
    prevCallContext = Os_ThreadSwitchType(currentThread, OS_CALLCONTEXT_PRETASKHOOK);                                   /* SBSW_OS_TASK_THREADSWITCHTYPE_001 */

    /* #30 Enter the critical user section. */
    Os_CoreCriticalUserSectionEnter(Os_ThreadGetCore(currentThread));                                                   /* SBSW_OS_CORE_THREADGETCORE_001 */ /* SBSW_OS_TASK_CORECRITICALUSERSECTIONENTER_001 */

    /* #40 Call PreTaskHook. */
    OS_TASK_PRETASKHOOK();

    /* #50 Leave the critical user section. */
    Os_CoreCriticalUserSectionLeave(Os_ThreadGetCore(currentThread));                                                   /* SBSW_OS_CORE_THREADGETCORE_001 */ /* SBSW_OS_TASK_CORECRITICALUSERSECTIONLEAVE_001 */

    /* #60 Restore previous call context. */
    (void)Os_ThreadSwitchType(currentThread, prevCallContext);                                                          /* SBSW_OS_TASK_THREADSWITCHTYPE_001 */
  }
}


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_TASK_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION    Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_TASKGETTHREAD_001
 \DESCRIPTION    Os_TaskGetThread is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_TASK_TASKGETTHREAD_002
 \DESCRIPTION    Os_TaskGetThread is called with the return value of Os_SchedulerInternalSchedule.
 \COUNTERMEASURE \T [CM_SCHEDULERINTERNALSCHEDULE_T]

\ID SBSW_OS_TASK_XSIGSEND_001
 \DESCRIPTION    A cross core send function is called, with the return values of Os_ThreadGetCore() and
                 Os_CoreGetThread(). Correctness of Os_CoreGetThread() is ensured by preconditions.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_TASKGETCORE_001
 \DESCRIPTION    Os_TaskGetCore is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_TASK_TASKGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_TaskGetAccessingApplications is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_TASK_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_TASK_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADGETCORE_002
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_TASKACTIVATELOCALTASK_001
 \DESCRIPTION    Os_TaskActivateLocalTask is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_TASK_THREADISTASK_001
 \DESCRIPTION    Os_ThreadIsTask is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_COREGETSCHEDULER_001
 \DESCRIPTION    Os_CoreGetScheduler is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_SCHEDULERTASKSWITCHISNEEDED_001
 \DESCRIPTION    Os_SchedulerTaskSwitchIsNeeded is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_TASK_SCHEDULERTASKSWITCHISNEEDED_002
 \DESCRIPTION    Os_SchedulerTaskSwitchIsNeeded is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKSWITCH_001
 \DESCRIPTION    Os_TaskSwitch is called with the return values of Os_CoreGetScheduler and Os_CoreGetThread.
                 The return value of Os_CoreGetThread is always valid (ensured by precondition).
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKSWITCH_002
 \DESCRIPTION    Os_TaskSwitch is called with the return values of Os_TaskGetScheduler and Os_CoreGetThread.
                 The return value of Os_CoreGetThread is always valid (ensured by precondition).
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKSWITCH_003
 \DESCRIPTION    Os_TaskSwitch is called with the return values of Os_TaskGetScheduler and Os_TaskGetThread.
                 The return value of Os_TaskGetThread is always valid (ensured by precondition).
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKGETDYN_001
 \DESCRIPTION    Os_TaskGetDyn is called with the return value of Os_SchedulerGetCurrentTask.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_TASK_TASKGETDYN_002
 \DESCRIPTION    Write access to the return value of Os_TaskGetDyn.
 \COUNTERMEASURE \M [CM_OS_TASKGETDYN_M]

\ID SBSW_OS_TASK_TASKGETDYN_003
 \DESCRIPTION    Os_TaskGetDyn is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_TASK_SCHEDULERGETCURRENTTASK_001
 \DESCRIPTION    Os_SchedulerGetCurrentTask is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_TASK_SCHEDULERGETCURRENTTASK_002
 \DESCRIPTION    Os_SchedulerGetCurrentTask is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_COREGETIDLETASK_001
 \DESCRIPTION    Os_CoreGetIdleTask is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_COREASRGETTIMINGPROTECTION_001
 \DESCRIPTION    Os_CoreAsrGetTimingProtection is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_THREADGETOWNERAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetOwnerApplication is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_APPCHECKISACCESSIBLE_001
 \DESCRIPTION    Os_AppCheckIsAccessible is called with the return value of Os_ThreadGetOwnerApplication.
 \COUNTERMEASURE \M [CM_OS_THREADGETOWNERAPPLICATION_M]

\ID SBSW_OS_TASK_THREADGETTPCONFIG_001
 \DESCRIPTION    Os_ThreadGetTpConfig is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_TPCHECKINTERARRIVAL_001
 \DESCRIPTION    Os_TpCheckInterArrival is called with the return values of Os_CoreAsrGetTimingProtection and
                 Os_ThreadGetTpConfig.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TASK_THREADGETTRACE_001
 \DESCRIPTION    Os_ThreadGetTrace is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_THREADGETTRACE_002
 \DESCRIPTION    Os_ThreadGetTrace is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_TRACETASKACTIVATE_001
 \DESCRIPTION    Os_TraceTaskActivate is called with the return value of Os_ThreadGetTrace.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_TRACETASKACTIVATELIMIT_001
 \DESCRIPTION    Os_TraceTaskActivateLimit is called with the return value of Os_ThreadGetTrace.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_TRACETASKKILL_001
 \DESCRIPTION    Os_TraceTaskKill is called with the return value of Os_ThreadGetTrace.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_THREADCHECKRESOURCESRELEASED_001
 \DESCRIPTION    Os_ThreadCheckResourcesReleased is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADCHECKSPINLOCKSRELEASED_001
 \DESCRIPTION    Os_ThreadCheckSpinlocksReleased is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_TASKTHREAD2TASK_001
 \DESCRIPTION    Os_TaskThread2Task is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_TASKGETSCHEDULER_001
 \DESCRIPTION   Os_TaskGetScheduler is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_TASK_TASKGETSCHEDULER_002
 \DESCRIPTION   Os_TaskGetScheduler is called with the return value of Os_CoreGetIdleTask.
 \COUNTERMEASURE \M [CM_OS_COREASR_IDLETASK_M]

\ID SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_001
 \DESCRIPTION    Os_SchedulerRemoveCurrentTask is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_SCHEDULERREMOVECURRENTTASK_002
 \DESCRIPTION    Os_SchedulerRemoveCurrentTask is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKRESUME_001
 \DESCRIPTION    Os_TaskResume is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKRESET_001
 \DESCRIPTION    Os_TaskReset is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_TASK_TASKRESET_002
 \DESCRIPTION    Os_TaskReset is called with the return value of Os_SchedulerGetCurrentTask.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERGETCURRENTTASK_M]
                 \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_TASK_TASKCHECKISSCHEDULEALLOWED_001
 \DESCRIPTION    Os_TaskCheckIsScheduleAllowed is called with the return value of Os_TaskThread2Task.
 \COUNTERMEASURE \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_TASK_SCHEDULERRELEASERUNNINGPRIO_001
 \DESCRIPTION    Os_SchedulerReleaseRunningPrio is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_SCHEDULERINTERNALSCHEDULE_001
 \DESCRIPTION    Os_SchedulerInternalSchedule is called with the return value of Os_TaskGetScheduler.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_EVENTINIT_001
 \DESCRIPTION    Os_EventInit is called with a pointer derived from the return value of Os_TaskGetDyn.
 \COUNTERMEASURE \M [CM_OS_TASKGETDYN_M]

\ID SBSW_OS_TASK_THREADINIT_001
 \DESCRIPTION    Os_ThreadInit is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_THREADKILL_001
 \DESCRIPTION    Os_ThreadKill is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_SCHEDULERREMOVETASKALL_001
 \DESCRIPTION    Os_SchedulerRemoveTaskAll is called with the return value of Os_TaskGetScheduler and a value
                 passed as argument to the caller.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_TASKGETID_001
 \DESCRIPTION    Os_TaskGetId is called with the return value of Os_SchedulerGetCurrentTask.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_TASK_TASKGETSTATEINTERNAL_001
 \DESCRIPTION    Os_TaskGetStateInternal is called with the return value of Os_TaskId2Task and a value passed
                 as argument to the caller function. Precondition ensures that the argument
                 pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

\ID SBSW_OS_TASK_THREADHASRESOURCESLOCKED_001
 \DESCRIPTION    Os_ThreadHasResourcesLocked is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADHASSPINLOCKLOCKED_001
 \DESCRIPTION    Os_ThreadHasSpinlockLocked is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADRESOURCEFORCERELEASE_001
 \DESCRIPTION    Os_ThreadResourceForceRelease is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADSPINLOCKFORCERELEASE_001
 \DESCRIPTION    Os_ThreadSpinlockForceRelease is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADSWITCH_001
 \DESCRIPTION    Os_ThreadSwitch is called with the return value of Os_TaskGetThread and an
                 argument passed to the caller function. Precondition ensures that the argument
                 pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_THREADSWITCH_002
 \DESCRIPTION    Os_ThreadSwitch is called with the return values of Os_TaskGetThread and Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N] [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_TRACETHREADSWITCH_001
 \DESCRIPTION    Os_TraceThreadSwitch is called with the return values of two Os_ThreadGetTrace calls.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_TRACETHREADINITANDSTART_001
 \DESCRIPTION    Os_TraceThreadInitAndStart is called with the return value of Os_ThreadGetTrace call.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_TRACETHREADRESETANDRESUME_001
 \DESCRIPTION    Os_TraceThreadResetAndResume is called with the return values of two Os_ThreadGetTrace calls.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_THREADRESETANDRESUME_001
 \DESCRIPTION    Os_ThreadResetAndResume is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_TPRESETANDRESUME_001
 \DESCRIPTION    Os_TpResetAndResume is called with the return values of Os_CoreAsrGetTimingProtection,
                 Os_ThreadGetTpConfig and Os_TaskGetThread. Precondition ensures that the pointer return by
                 Os_TaskGetThread is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TASK_TPRESETAFTERWAIT_001
 \DESCRIPTION    Os_TpResetAfterWait is called with the return values of Os_CoreAsrGetTimingProtection,
                 Os_ThreadGetTpConfig and Os_TaskGetThread. Precondition ensures that the pointer return by
                 Os_TaskGetThread is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTIMINGPROTECTION_M]
                 \M [CM_OS_THREADGETTPCONFIG_M]

\ID SBSW_OS_TASK_SCHEDULERINSERT_001
 \DESCRIPTION    Os_SchedulerInsert is called with the return value of Os_TaskGetScheduler and a value passed as
                 argument to the caller function. Precondition ensures that the argument
                 pointer is valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]

\ID SBSW_OS_TASK_SCHEDULERINSERT_002
 \DESCRIPTION    Os_SchedulerInsert is called with the return value of Os_TaskGetScheduler and the return value of
                 Os_TaskThread2Task.
 \COUNTERMEASURE \M [CM_OS_TASKGETSCHEDULER_M]
                 \R [CM_OS_TASKTHREAD2TASK_R]

\ID SBSW_OS_TASK_TRACETHREADCLEANUPANDRESUME_001
 \DESCRIPTION    Os_TraceThreadCleanupAndResume is called with the return values of two Os_ThreadGetTrace calls.
 \COUNTERMEASURE \M [CM_OS_THREADGETTRACE_M]

\ID SBSW_OS_TASK_THREADCLEANUPANDRESUME_001
 \DESCRIPTION    Os_ThreadCleanupAndResume is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_THREADSTARTFIRST_001
 \DESCRIPTION    Os_ThreadStartFirst is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_COREID2CORE_001
 \DESCRIPTION    Os_Core2AsrCore is called, with the return values of Os_CoreId2Core().
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]. [CM_OS_COREGETTHREAD_N].

\ID SBSW_OS_TASK_THREADGETACCESSRIGHTS_001
 \DESCRIPTION    Os_ThreadGetAccessRights is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_THREADSWITCHTYPE_001
 \DESCRIPTION    Os_ThreadSwitchType is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_THREADGETTPCONFIG_001
 \DESCRIPTION    Os_ThreadGetTpConfig is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_THREADISANYINITIALCONTEXT_001
 \DESCRIPTION    Os_ThreadIsAnyInitialContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TASK_THREADSETINTERRUPTSTATE_001
 \DESCRIPTION    Os_ThreadSetInterruptState is called with the return value of Os_TaskGetThread.
 \COUNTERMEASURE \N [CM_OS_TASKGETTHREAD_N]

\ID SBSW_OS_TASK_TASKISSUPENDED_001
 \DESCRIPTION    Os_TaskIsSuspended is called with the return value of Os_SchedulerGetCurrentTask.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_TASK_CORECRITICALUSERSECTIONENTER_001
 \DESCRIPTION    Os_CoreCriticalUserSectionEnter is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_CORECRITICALUSERSECTIONLEAVE_001
 \DESCRIPTION    Os_CoreCriticalUserSectionLeave is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_COREASRISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrIsCoreLocal is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_TASK_COREASRISCORELOCAL_002
 \DESCRIPTION    Os_CoreAsrIsCoreLocal is called with the return value of Os_TaskGetCore.
 \COUNTERMEASURE \M [CM_OS_TASKGETCORE_M]

\ID SBSW_OS_TASK_TASKISCORELOCAL_001
 \DESCRIPTION    Os_TaskIsCoreLocal is called with the return value of Os_TaskId2Task.
 \COUNTERMEASURE \M [CM_OS_TASKID2TASK_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_TASKID2TASK_M
      Verify that:
        1. each task pointer in OsCfg_TaskRefs except the last is no NULL_PTR,
        2. the size of OsCfg_TaskRefs is equal to OS_TASKID_COUNT + 1 and
        3. each element in TaskType has a lower value than OS_TASKID_COUNT.

\CM CM_OS_TASKGETTHREAD_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_TASKTHREAD2TASK_R
      Implementation ensures, that the given thread is a task.

\CM CM_OS_TASKGETDYN_M
      Verify that the Task Dyn pointer of each Os_TaskConfigType object is initialized with a
      dynamic Task derived from an Os_TaskType object.

\CM CM_OS_TASKGETSCHEDULER_M
      [CM_OS_COREGETSCHEDULER_M]

\CM CM_OS_TASKGETCORE_M
      [CM_OS_THREADGETCORE_M]

\CM CM_OS_TASKGETEVENT_M
      Verify that the Task Dyn pointer of each Os_TaskConfigType object is initialized with a
      dynamic Task derived from an Os_TaskType object.

\CM CM_OS_TASKGETACCESSRIGHTS_M
      [CM_OS_THREADGETACCESSRIGHTS_M]
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Task.c
 **********************************************************************************************************************/
