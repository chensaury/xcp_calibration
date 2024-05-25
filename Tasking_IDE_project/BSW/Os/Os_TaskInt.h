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
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Task Task
 *  \brief       Task management.
 *  \details
 *  This module provides the task management interface defined by OSEK/AUTOSAR OS.
 *
 *  In MICROSAR OS a task is a thread, which is scheduled by the scheduler. A task extends a thread with
 *  scheduling information.
 *
 *  The task module uses the scheduler as a lookup data base for ready tasks. The scheduler itself does not actively
 *  perform scheduling or task switching. It is always part of a higher level concept, e.g. tasks, events or resources.
 *
 *  ![Task Activation](Task_Activation.png)
 *
 *  ![Task Termination](Task_Termination.png)
 *
 *
 *  \see \ref Os_Thread
 *  \see \ref Os_Scheduler
 *  \see \ref Inheritance
 *
 *
 *  \trace CREQ-30, CREQ-89, CREQ-20, CREQ-58
 *  \trace SPEC-63925
 *
 *
 *  \{
 *
 *  \file
 *  \brief       OS internal functions to work with tasks.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TASKINT_H
# define OS_TASKINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Task_Types.h"
# include "Os_Task_Lcfg.h"

/* Os module dependencies */
# include "Os_CommonInt.h"
# include "Os_Thread_Types.h"
# include "Os_ThreadInt.h"
# include "Os_Scheduler_Types.h"
# include "Os_Application_Types.h"
# include "Os_EventInt.h"
# include "Os_XSignalInt.h"
# include "Os_AccessCheck_Types.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/*! Type cast from Os_TaskConfigType to Os_TaskType by use of base element addressing. */
#define OS_TASK_CASTDYN_TASK_2_THREAD(task)                      (&((task).Thread))                                     /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_TaskConfigType to Os_TaskConfigType by use of base element addressing. */
#define OS_TASK_CASTCONFIG_TASK_2_TASK(task)                     (&(task))                                              /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
typedef uint8_least Os_ActivationCntType;

/*! Marks whether calling Schedule is supported by a task or not. */
typedef enum
{
  /*! Calling Schedule is allowed for the task. */
  OS_TASKSCHEDULE_ALLOWED,
  /*! Calling Schedule is prohibited for the task. */
  OS_TASKSCHEDULE_PROHIBITED
}Os_TaskScheduleType;

/*! Dynamic management information of a task
 * \extends Os_ThreadType_Tag
 */
struct Os_TaskType_Tag
{
  /*! The dynamic thread information of this task.
   * This attribute must come first! */
  Os_ThreadType Thread;

  /*! Event management state. */
  Os_EventStateType Events;

  /*! Current scheduling state. */
  TaskStateType State;

  /*! Current scheduling priority. */
  Os_TaskPrioType Priority;

  /*! Counts how many times a task may be activated. */
  Os_ActivationCntType ActivationsAllowed;
};

/*! Configuration information of a task.
 * \details
 * The dynamic data pointer a task can be fetched with Os_TaskGetDyn().
 * \extends Os_ThreadConfigType_Tag
 */
struct Os_TaskConfigType_Tag
{
  /*! The thread attributes of this task.
   * This attribute must come first! */
  Os_ThreadConfigType Thread;

  /*! The configured priority of a task. If a task is activated, it is scheduled at this priority. */
  Os_TaskPrioType HomePriority;

  /*! The ID for this task. */
  TaskType TaskId;

  /*! The priority which the task is running at, if it is scheduled.
   *  It is used to implement internal resources and non-preemptive tasks. */
  Os_TaskPrioType RunningPriority;

  /*! The maximum number of multiple activation requests in parallel.
   * Multiple activation is only allowed for basic tasks! */
  Os_ActivationCntType MaxActivations;

  /*! Application modes where the task shall be activated during OS initialization. */
  AppModeType AutostartModes;

  /*! Reference to applications which have an access to this object. */
  Os_AppAccessMaskType AccessingApplications;

  /*! Tells whether a task is extended (TRUE) or not (FALSE). */
  boolean IsExtended;

  /*! Tells whether the Schedule may be called from the given task. */
  Os_TaskScheduleType Reschedule;
};


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_TaskIsPostTaskHookEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether the PostTaskHook enabled or not.
 *  \details      This allows user to trace task switches.
 *
 *  \retval       !0    PostTaskHook is enabled.
 *  \retval       0     PostTaskHook is disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskIsPostTaskHookEnabled,
( void ));

/***********************************************************************************************************************
 *  Os_TaskId2Task()
 **********************************************************************************************************************/
/*! \brief          Returns the task belonging to the given id.
 *  \details        --no details--
 *
 *  \param[in]      TaskId        The id of the searched task. Parameter must be < OS_TASKID_COUNT.
 *
 *  \return         The task belonging to the given id.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TaskId2Task,
(
  TaskType TaskId
));


/***********************************************************************************************************************
 *  Os_TaskGetThread()
 **********************************************************************************************************************/
/*! \brief          Returns the thread of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the task's thread.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_ThreadConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TaskGetThread,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskThread2Task()
 **********************************************************************************************************************/
/*! \brief          Returns the task corresponding to a thread.
 *  \details        The caller has to ensure, that the thread actually belongs to a task.
 *
 *  \param[in]      Thread      Thread to query. Thread must be a Task thread. Parameter must not be NULL.
 *
 *  \return         The Task corresponding to the given thread.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TaskThread2Task,
(
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_TaskGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the task's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_TaskType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_TaskGetDyn,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskSetState()
 **********************************************************************************************************************/
/*! \brief          Sets the current priority of a task.
 *  \details        --no details--
 *
 *  \param[in,out]  Task    Task to query. Parameter must not be NULL.
 *  \param[in]      State   New task state.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskSetState,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  TaskStateType State
));


/***********************************************************************************************************************
 *  Os_TaskGetPriority()
 **********************************************************************************************************************/
/*! \brief          Returns the current priority of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Current priority of a task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TaskPrioType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskGetPriority,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskSetPriority()
 **********************************************************************************************************************/
/*! \brief          Set the current priority of a task.
 *  \details        --no details--
 *
 *  \param[in,out]  Task        Task to modify. Parameter must not be NULL.
 *  \param[in]      Priority    New priority. Parameter must be < Scheduler->NumberOfPriorities.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            After initialization, this function shall only be called by the scheduler.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskSetPriority,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  Os_TaskPrioType Priority
));


/***********************************************************************************************************************
 *  Os_TaskGetRunningPriority()
 **********************************************************************************************************************/
/*! \brief          Returns the running priority of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Running priority of a task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TaskPrioType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskGetRunningPriority,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskGetHomePriority()
 **********************************************************************************************************************/
/*! \brief          Returns the home priority of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Home priority of a task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TaskPrioType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskGetHomePriority,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskGetId()
 **********************************************************************************************************************/
/*! \brief          Returns the id of the given task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Id of the task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE TaskType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskGetId,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));

/***********************************************************************************************************************
 *  Os_TaskGetMaxActivations()
 **********************************************************************************************************************/
/*! \brief          Returns the configured maximum number of activations of the given task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Maximum activations of the task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_ActivationCntType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskGetMaxActivations,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief          Get applications which have access to the given object.
 *  \details        --no details--
 *
 *  \param[in,out]  Task  The object to query. Parameter must not be NULL.
 *
 *  \return         Reference to applications which have access to this object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskGetAccessingApplications,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskGetScheduler()
 **********************************************************************************************************************/
/*! \brief          Returns the scheduler of a task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Scheduler of a task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TaskGetScheduler,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskGetEvent()
 **********************************************************************************************************************/
/*! \brief          Returns the event state object of the given task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         Task's event state object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_EventStateType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_TaskGetEvent,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskGetCore()
 **********************************************************************************************************************/
/*! \brief          Returns the core of the given task.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \return         The task's core.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TaskGetCore,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskIsCoreLocal()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given task belongs to the local core (!0) or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *
 *  \retval         !0   If the given task is assigned to the local core.
 *  \retval         0    If the given task is not assigned to the local core.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskIsCoreLocal,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      TaskId        The ID to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given ID is valid.
 *  \retval         OS_CHECK_FAILED       If the given ID is not valid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskCheckId,
(
  TaskType TaskId
));


/***********************************************************************************************************************
 *  Os_TaskCheckIsExtendedTask()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given task ID is an extended task (Not OS_CHECK_FAILED)
 *                  or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Task        The task to test. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given task is an extended task.
 *  \retval         OS_CHECK_FAILED       If the given task is not an extended task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskCheckIsExtendedTask,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskCheckIsNotSuspended()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given task is in suspended state (Not OS_CHECK_FAILED)
 *                  or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Task        The task to test. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given task is not in suspended state.
 *  \retval         OS_CHECK_FAILED       If the given task is is in suspended state.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskCheckIsNotSuspended,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskIsWaiting()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given task is waiting (!0) or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Task        The task to query. Parameter must not be NULL.
 *
 *  \retval         0    If the given task is not in waiting state.
 *  \retval         !0   If the given task is is in waiting state.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE uint32, OS_CODE, OS_ALWAYS_INLINE, Os_TaskIsWaiting,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskIsSuspended()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given task is suspended (!0) or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Task        The task to query. Parameter must not be NULL.
 *
 *  \retval         0    If the given task is not in suspended state.
 *  \retval         !0   If the given task is is in suspended state.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskIsSuspended,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskActivateLocalTask()
 **********************************************************************************************************************/
/*! \brief          Internal function to activate a task.
 *  \details
 *  This function checks the state of the given task, and returns an error code,
 *  if activation is currently not allowed.
 *  This function performs no error reporting. This is up to the caller.
 *  Because, this function could be called as part of a cross core activation,
 *  where error reporting shall be performed on the calling core.
 *  This function performs no task switch. This is up to the caller.
 *  Because this function may be called on interrupt and on task level.
 *  This function may call the protection hook with E_OS_PROTECTION_ARRIVAL,
 *  if the task's interarrival time is not met.
 *
 *  \param[in,out]  Task        The task which shall be activated. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No errors.<br>
 *                                            Interarrival time not met.
 *  \retval         OS_STATUS_LIMIT           Too many task activations.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        TASK|ISR2
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given task is assigned to the local core.
 *
 *  \trace          CREQ-846, CREQ-28
 *  \trace          SPEC-63968, SPEC-63732, SPEC-64009
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_TaskActivateLocalTask
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_TaskActivateRestartTask()
 **********************************************************************************************************************/
/*! \brief          Internal function to activate a restart task.
 *  \details        See Os_TaskActivateLocalTask()
 *
 *  \param[in,out]  Task        The task which shall be activated. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK      No errors.<br>
 *                                    Interarrival time not met.
 *  \retval         OS_STATUS_LIMIT   Too many task activations.
 *
 *  \context        TASK|ISR2|ERRHOOK|PROTHOOK
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given task is assigned to the local core.
 *  \pre            Task activation allowed.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_TaskActivateRestartTask
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_TaskSwitch()
 **********************************************************************************************************************/
/*! \brief          Continues the next task.
 *  \details        --no details--
 *
 *  \param[in]      Scheduler     The scheduler to determine the next task. Parameter must not be NULL.
 *  \param[in]      CallerThread  Reference to the current thread. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given thread is the current thread.
 *  \pre            The current thread is a task.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskSwitch,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) CallerThread
));


/***********************************************************************************************************************
 *  Os_TaskResume()
 **********************************************************************************************************************/
/*! \brief          Resumes the next task. The current task may not be continued.
 *  \details        Function never returns.
 *
 *  \param[in]      Scheduler     The scheduler to determine the next task. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Current thread is a task.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE, Os_TaskResume,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
));


/***********************************************************************************************************************
 *  Os_TaskWait()
 **********************************************************************************************************************/
/*! \brief          Turns a task into the waiting state
 *  \details        --no details--
 *
 *  \param[in]      Task     The task to turn into the waiting state. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different Tasks
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The given Task's thread is the current thread.
 *
 *  \trace          SPEC-64030
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskWait,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskLeaveWaitingState()
 **********************************************************************************************************************/
/*! \brief          Resumes a waiting task.
 *  \details        --no details--
 *
 *  \param[in]      Task     The waiting task. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Task is in waiting state.
 *  \pre            Task is not scheduled.
 *
 *  \trace          CREQ-846
 *  \trace          SPEC-63968, SPEC-64043, SPEC-63848
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskLeaveWaitingState,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskReturnToTaskLevel()
 **********************************************************************************************************************/
/*! \brief          Resume the next task after returning from an ISR/Hook.
 *  \details        --no details--
 *
 *  \param[in]      InterruptedTask     The interrupted task. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The current thread is no task thread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE, Os_TaskReturnToTaskLevel,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) InterruptedTask
));


/***********************************************************************************************************************
 *  Os_TaskPreStartTaskEnter()
 **********************************************************************************************************************/
/*! \brief          Starts the pre-start task after OS initialization is complete.
 *  \details        Copies the current interrupt state into the pre-start task thread context.
 *
 *  \param[in]      PreStartTask     Pointer to the pre-start task. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given Task is the pre-start task of the local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskPreStartTaskEnter,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) PreStartTask
));


/***********************************************************************************************************************
 *  Os_TaskGetStateLocal()
 **********************************************************************************************************************/
/*! \brief          Returns the current task state.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *  \param[out]     State       Current state of a task. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No Error.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given task's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            The given task has to be assigned to the current core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_TaskGetStateLocal,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  TaskStateRefType State
));


/***********************************************************************************************************************
 *  Os_TaskInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given task for the first time.
 *  \details        The kernel uses this function to initialize all tasks during OS initialization.
 *                  It sets all dynamic data of the given task to its configured startup settings.
 *                  Thus, it will perform a fresh start, when the kernel resumes the task the next time.
 *                  If the given application mode is one of the task's autostart modes, this function activates
 *                  the given task.
 *                  If the given task is the idle task, initialization is skipped.
 *                  The function is called for the prestart task in Init-Step3 and for all tasks in Init-Step4.
 *
 *  \param[in,out]  Task    The task which shall be initialized. Parameter must not be NULL.
 *  \param[in]      AppMode The current application mode.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TaskInit
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  AppModeType AppMode
);


/***********************************************************************************************************************
 *  Os_TaskIdleTaskInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given idle task.
 *  \details        This function is called in Init-Step3 and Init-Step4 in order to handle the situation that
 *                  Init-Step3 is optional.
 *
 *  \param[in,out]  Task    The task which shall be initialized. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different tasks.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TaskIdleTaskInit
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_TaskKillAll()
 **********************************************************************************************************************/
/*! \brief          Forcibly terminate all instances of the given task.
 *  \details        The kernel uses this function to implement application termination.
 *
 *  \param[in,out]  Task    The task which shall be terminated. Parameter must not be NULL.
 *
 *  \context        TASK|ISR2|ERRHOOK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given task is not the Idle Task.
 *  \pre            Given task is assigned to the local core.
 *
 *  \trace          CREQ-70
 *  \trace          SPEC-64039, SPEC-63992
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TaskKillAll
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_TaskGetStateInternal()
 **********************************************************************************************************************/
/*! \brief          Returns the current task state.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to query. Parameter must not be NULL.
 *  \param[out]     State       The state of the task. Parameter must not be NULL.
 *
 *  \return         The status of the call.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given task's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The given task has to be assigned to the current core.
 *  \pre            Interrupts enabled.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_TaskGetStateInternal
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  TaskStateRefType State
);


/***********************************************************************************************************************
 *  Os_TaskKill()
 **********************************************************************************************************************/
/*! \brief          Forcibly terminate the current task.
 *  \details        The kernel uses this function to forcibly terminate tasks as a protection reaction.
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Currently scheduled task is not the Idle Task.
 *  \pre            Concurrent access is prevented by caller.
 *
 *  \trace          CREQ-70
 *  \trace          SPEC-63880, SPEC-63992
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TaskKill(void);


/***********************************************************************************************************************
 *  Os_TaskSuicide()
 **********************************************************************************************************************/
/*! \brief          Determines the next task and performs a thread reset and resume.
 *  \details        Asks scheduler for the next task and resumes to it.
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access is prevented by caller.
 *  \pre            Task has already been killed (call of Os_TaskKill() or Os_TaskKillAll()).
 *  \pre            Current thread is a task.
 *  \pre            Current task is not scheduled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE, Os_TaskSuicide, (void));


/***********************************************************************************************************************
 *  Os_TaskActivateTaskInternal()
 **********************************************************************************************************************/
/*! \brief          Api for activating a task from within the OS.
 *  \details        --no details--
 *
 *  \param[in]      Task        Task to activate. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No errors.<br>
 *                                            Interarrival time not met.
 *  \retval         OS_STATUS_LIMIT           Too many task activations.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_TaskActivateTaskInternal,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskPreTaskHook()
 **********************************************************************************************************************/
/*! \brief        Intentionally empty function as a replacement of the user PreTaskHook.
 *  \details      Only used to prevent linker error messages in case no PreTaskHook is configured.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskPreTaskHook, (void));


/***********************************************************************************************************************
 *  Os_TaskPostTaskHook()
 **********************************************************************************************************************/
/*! \brief        Intentionally empty function as a replacement of the user PreTaskHook.
 *  \details      Only used to prevent linker error messages in case no PostTaskHook is configured.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskPostTaskHook, (void));


/***********************************************************************************************************************
 *  Os_TaskCallPreTaskHook()
 **********************************************************************************************************************/
/*! \brief        Calls the global pre-task hook.
 *  \details      --no details--
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-71
 *  \trace        SPEC-67583, SPEC-67584
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TaskCallPreTaskHook(void);


/***********************************************************************************************************************
 *  Os_TaskCallPostTaskHook()
 **********************************************************************************************************************/
/*! \brief        Calls the global post-task hook.
 *  \details      --no details--
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access is prevented by caller.
 *
 *  \trace        CREQ-165
 *  \trace        SPEC-67585, SPEC-67586
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TaskCallPostTaskHook, (void));


/***********************************************************************************************************************
 *  Os_TaskGetAccessRights()
 **********************************************************************************************************************/
/*! \brief          Returns the access rights of the given task.
 *  \details        --no details--
 *
 *  \param[in]      Task         Task to query. Parameter must not be NULL.
 *
 *  \return         Pointer to the task's access rights.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AccessCheckConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TaskGetAccessRights,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_TaskBeginScheduling()
 **********************************************************************************************************************/
/*! \brief          Begins scheduling.
 *  \details        This function is called by the InitHook, after OS initialization is done.
 *
 *  \context        TASK|OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Called from InitHook during StartOS.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_NORETURN OS_ALWAYS_INLINE, Os_TaskBeginScheduling,
(
  void
));


/***********************************************************************************************************************
 *  Os_TaskMissingTerminateTask()
 **********************************************************************************************************************/
/*! \brief          Behavior in case a task did forget to terminate and simply returns.
 *  \details        --no details--
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 *
 *  \trace          SPEC-63756, SPEC-63768, SPEC-63935, SPEC-64025
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(void, OS_CODE, OS_NORETURN, Os_TaskMissingTerminateTask, (void));


/***********************************************************************************************************************
 *  Os_Api_ActivateTask()
 **********************************************************************************************************************/
/*! \brief        OS service ActivateTask().
 *  \details      For further details see ActivateTask().
 *
 *  \param[in]    TaskID            See ActivateTask()
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_LIMIT           Too many task activations.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid TaskID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given TaskID belongs to local core.
 *
 *  \pre          See ActivateTask().
 *
 *  \trace        CREQ-42, CREQ-40, CREQ-846
 *  \trace        SPEC-64339, SPEC-64309, SPEC-64319, SPEC-64355, SPEC-64359, SPEC-64363, SPEC-64017, SPEC-63709
 *  \trace        SPEC-63752, SPEC-64009, SPEC-63980, SPEC-63783
 *  \trace        SPEC-63926 If asynchronous XSignal is enabled this requirement is not fulfilled.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_ActivateTask(TaskType TaskID);


/***********************************************************************************************************************
 *  Os_Api_TerminateTask()
 **********************************************************************************************************************/
/*! \brief        OS service TerminateTask().
 *  \details      For further details see TerminateTask().
 *
 *  \retval       OS_STATUS_CALLEVEL    (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_RESOURCE    (EXTENDED status:) Called from a task which holds an OS resource.
 *  \retval       OS_STATUS_SPINLOCK    (EXTENDED status:) Called from a task which holds a spinlock.
 *  \retval       OS_STATUS_DISABLEDINT (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See TerminateTask().
 *
 *  \trace        CREQ-101, CREQ-40
 *  \trace        SPEC-64300, SPEC-64317, SPEC-64336, SPEC-64315, SPEC-64324, SPEC-64329, SPEC-64364, SPEC-63804
 *  \trace        SPEC-64017, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_TerminateTask(void);


/***********************************************************************************************************************
 *  Os_Api_ChainTask()
 **********************************************************************************************************************/
/*! \brief        OS service ChainTask().
 *  \details      See ChainTask().
 *
 *  \param[in]    TaskID            The task which shall be activated.
 *
 *  \retval       OS_STATUS_LIMIT           Too many task activations.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_RESOURCE        (EXTENDED status:) Task still occupies resources.
 *  \retval       OS_STATUS_SPINLOCK        (EXTENDED status:) Task still holds spinlocks.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid TaskID.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given TaskID belongs to local core.
 *
 *  \pre          See ChainTask().
 *
 *  \trace        CREQ-121, CREQ-40, CREQ-846
 *  \trace        SPEC-64296, SPEC-64299, SPEC-64330, SPEC-64335, SPEC-64338, SPEC-64341, SPEC-64345, SPEC-64347
 *  \trace        SPEC-64349, SPEC-64351, SPEC-64362, SPEC-63804, SPEC-64017, SPEC-63709, SPEC-63752, SPEC-64009
 *  \trace        SPEC-63980, SPEC-63784
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_ChainTask(TaskType TaskID);



/***********************************************************************************************************************
 *  Os_Api_Schedule()
 **********************************************************************************************************************/
/*! \brief        OS service Schedule().
 *  \details      For further details see Schedule().
 *
 *  \retval   OS_STATUS_OK           No Error.
 *  \retval   OS_STATUS_CALLEVEL     (EXTENDED status:) The service was called from any context which is not allowed.
 *  \retval   OS_STATUS_CALLEVEL_SHARED_STACK (EXTENDED status:) The service was called from a Task does not have a
 *                                   private stack.
 *  \retval   OS_STATUS_RESOURCE     (EXTENDED status:) The service was called from a task which holds an OS resource.
 *  \retval   OS_STATUS_SPINLOCK     (EXTENDED status:) The service was called from a task which holds a spinlock.
 *  \retval   OS_STATUS_DISABLEDINT  (Service Protection:) The service was called with disabled interrupts.
 *
 *  \context      TASK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See Schedule().
 *
 *  \trace        CREQ-126, CREQ-40
 *  \trace        SPEC-64307, SPEC-64310, SPEC-64311, SPEC-64360, SPEC-64017, SPEC-63886, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_Schedule(void);


/***********************************************************************************************************************
 *  Os_Api_GetTaskID()
 **********************************************************************************************************************/
/*! \brief        OS service GetTaskID().
 *  \details      For further details see GetTaskID().
 *
 *  \param[out]   TaskID              See GetTaskID().
 *
 *  \retval       OS_STATUS_OK             No error.
 *  \retval       OS_STATUS_CALLEVEL       (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT    (Service Protection:) Caller is in interrupt API sequence.
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK|PROTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetTaskID().
 *
 *  \trace        CREQ-80, CREQ-40
 *  \trace        SPEC-64298, SPEC-64327, SPEC-64356, SPEC-64017, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetTaskID(TaskRefType TaskID);


/***********************************************************************************************************************
 *  Os_Api_GetTaskState()
 **********************************************************************************************************************/
/*! \brief        OS service GetTaskState().
 *  \details      For further details see GetTaskState().
 *
 *  \param[in]    TaskID          See GetTaskState().
 *  \param[out]   State           See GetTaskState().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid TaskID.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *
 *  \context      TASK|ISR2|ERRHOOK|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetTaskState().
 *
 *  \trace        CREQ-74, CREQ-40
 *  \trace        SPEC-64325, SPEC-64343, SPEC-64352, SPEC-64357, SPEC-64017, SPEC-63709, SPEC-63752, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetTaskState(TaskType TaskID, TaskStateRefType State);


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */



#endif /* OS_TASKINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_TaskInt.h
 **********************************************************************************************************************/
