/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                                  All rights reserved.
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
 * \brief       Implementation of \ref Os_Scheduler.
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_SCHEDULER_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Scheduler_Cfg.h"
# include "Os_Scheduler.h"

/* Os module dependencies */
# include "Os_BitArray.h"
# include "Os_Deque.h"
# include "Os_Task.h"


/***********************************************************************************************************************
 *  LOCAL CONSTANT MACROS
 **********************************************************************************************************************/
#define OS_TASKPRIO_HIGHEST           ((Os_TaskPrioType)0)


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
 *  Os_SchedulerPriority2Deque()
 **********************************************************************************************************************/
/*! \brief          Returns the task queue (deque) of a given scheduling priority.
 *  \details        --no details--
 *
 *  \param[in]      Scheduler     The scheduler to query. Parameter must not be NULL.
 *  \param[in]      Priority      The priority of the TaskQueue. Priority must be < Scheduler->NumberOfPriorities.
 *
 *  \return         The deque.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerPriority2Deque,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType Priority
));


/***********************************************************************************************************************
 *  Os_SchedulerDequeueTask()
 **********************************************************************************************************************/
/*! \brief          Dequeue the front task from the given task queue and clear bit in bit array,
 *                  if queue gets empty.
 *  \details        --no details--
 *
 *  \param[in]      Scheduler     The scheduler to modify. Parameter must not be NULL.
 *  \param[in]      Priority      The priority of the TaskQueue. Priority must be < Scheduler->NumberOfPriorities.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerDequeueTask,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType Priority
));


/***********************************************************************************************************************
 *  Os_SchedulerDeleteTask()
 **********************************************************************************************************************/
/*! \brief          Delete all instances of the given task from the given task queue and clear bit in bit array,
 *                  if queue gets empty.
 *  \details        --no details--
 *
 *  \param[in]      Scheduler     The scheduler to query. Parameter must not be NULL.
 *  \param[in]      Priority      The priority of the TaskQueue. Priority must be < Scheduler->NumberOfPriorities.
 *  \param[in]      Task          Task which shall be deleted. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerDeleteTask,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType Priority,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
));


/***********************************************************************************************************************
 *  Os_SchedulerSchedule()
 **********************************************************************************************************************/
/*! \brief          Determine the next task.
 *  \details        Set the next task priority according to the non-empty task queue with highest priority.
 *                  Set the next task according to the front element of this task queue.
 *
 *  \param[in,out]  Scheduler   Scheduler which shall update its new task. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerSchedule,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
));


/***********************************************************************************************************************
 *  Os_SchedulerTaskMoveDown()
 **********************************************************************************************************************/
/*! \brief          Move a task down from a task queue of higher priority to a task queue with lower priority.
 *  \details        The task is inserted at the front of the lower priority task queue.
 *
 *  \param[in]      Scheduler             The scheduler to query. Parameter must not be NULL.
 *  \param[in,out]  HighPrioTaskPriority  The priority level where the task shall be removed from.
 *                                        HighPrioTaskPriority must be < Scheduler->NumberOfPriorities.
 *  \param[in,out]  LowPrioTaskPriority   The priority level where the task shall be moved to.
 *                                        LowPrioTaskPriority must be < Scheduler->NumberOfPriorities.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerTaskMoveDown,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType HighPrioTaskPriority,
  Os_TaskPrioType LowPrioTaskPriority
));


/***********************************************************************************************************************
 *  Os_SchedulerTaskMoveUp()
 **********************************************************************************************************************/
/*! \brief          Move a task up from a task queue of low priority to a task queue with higher priority.
 *  \details        The task is inserted at the front of the higher priority task queue.
 *
 *  \param[in]      Scheduler               The scheduler to query. Parameter must not be NULL.
 *  \param[in]      Task                    Task which shall be moved. Parameter must not be NULL.
 *  \param[in,out]  LowPrioTaskPriority     The priority of the task that shall be dequeued from.
 *                                          LowPrioTaskPriority must be < Scheduler->NumberOfPriorities.
 *                                          HighPrioTaskPriority must be logically > LowPrioTaskPriority.
 *  \param[in,out]  HighPrioTaskPriority    The priority of the task that shall be prepended to.
 *                                          HighPrioTaskPriority must be < Scheduler->NumberOfPriorities.
 *                                          HighPrioTaskPriority must be logically > LowPrioTaskPriority.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerTaskMoveUp,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  Os_TaskPrioType LowPrioTaskPriority,
  Os_TaskPrioType HighPrioTaskPriority
));


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_SchedulerPriority2Deque()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerPriority2Deque,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType Priority
))
{
  Os_Assert((Os_StdReturnType)(Priority < Scheduler->NumberOfPriorities));                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  return &(Scheduler->TaskQueues[Priority]);
}


/***********************************************************************************************************************
 *  Os_SchedulerDequeueTask()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerDequeueTask,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType Priority
))
{
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST) taskQueue;
  taskQueue = Os_SchedulerPriority2Deque(Scheduler, Priority);                                                          /* SBSW_OS_FC_PRECONDITION */

  Os_DequeDeleteTop(taskQueue);                                                                                         /* SBSW_OS_SDR_DEQUEDELETETOP_001  */
  if(Os_DequeIsEmpty(taskQueue) != 0u)                                                                                  /* SBSW_OS_SDR_DEQUEISEMPTY_001 */
  {
    Os_BitArrayClearBit(&Scheduler->BitArray, (Os_BitArrayIndexType)Priority);                                          /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_SchedulerDeleteTask()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerDeleteTask,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType Priority,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
))
{
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST) taskQueue;
  taskQueue = Os_SchedulerPriority2Deque(Scheduler, Priority);                                                          /* SBSW_OS_FC_PRECONDITION */

  Os_DequeDelete(taskQueue, Task);                                                                                      /* SBSW_OS_SDR_DEQUEDELETE_001 */
  if(Os_DequeIsEmpty(taskQueue) != 0u)                                                                                  /* SBSW_OS_SDR_DEQUEISEMPTY_001 */
  {
    Os_BitArrayClearBit(&Scheduler->BitArray, (Os_BitArrayIndexType)Priority);                                          /* SBSW_OS_FC_PRECONDITION */
  }
}

/***********************************************************************************************************************
 *  Os_SchedulerSchedule()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,  Os_SchedulerSchedule,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
))
{
  Scheduler->Dyn->NextPriority = Os_BitArrayCountLeadingZeros(&Scheduler->BitArray);                                    /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */ /* SBSW_OS_FC_PRECONDITION */
  Scheduler->Dyn->NextTask = Os_DequePeek(Os_SchedulerPriority2Deque(Scheduler, Scheduler->Dyn->NextPriority));         /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */ /* SBSW_OS_SDR_DEQUEPEEK_001 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchedulerTaskMoveDown()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerTaskMoveDown,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType HighPrioTaskPriority,
  Os_TaskPrioType LowPrioTaskPriority
))
{
  if(Os_SchedulerPriorityIsHigher(HighPrioTaskPriority, LowPrioTaskPriority) != 0u)
  {
    Os_SchedulerDequeueTask(Scheduler, HighPrioTaskPriority);                                                           /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_SchedulerTaskMoveUp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerTaskMoveUp,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task,
  Os_TaskPrioType LowPrioTaskPriority,
  Os_TaskPrioType HighPrioTaskPriority
))
{
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST) taskQueueHighPrio;
  taskQueueHighPrio = Os_SchedulerPriority2Deque(Scheduler, HighPrioTaskPriority);                                      /* SBSW_OS_FC_PRECONDITION */

  Os_Assert(Os_SchedulerPriorityIsHigher(HighPrioTaskPriority, LowPrioTaskPriority));

  Os_Assert((Os_StdReturnType)(Os_DequeIsEmpty(taskQueueHighPrio) != 0u));                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_SDR_DEQUEISEMPTY_001 */
  Os_BitArraySetBit(&Scheduler->BitArray, (Os_BitArrayIndexType)HighPrioTaskPriority);                                  /* SBSW_OS_FC_PRECONDITION */
  (void)Os_DequePrepend(taskQueueHighPrio, Task);                                                                       /* SBSW_OS_SDR_DEQUEPREPEND_001 */
}


/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_SchedulerInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SchedulerInit
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) IdleTask
)
{
  Os_TaskPrioType  priority;

  /* #10 Initialize scheduler's bit array. */
  Os_BitArrayInit(&(Scheduler->BitArray));                                                                              /* SBSW_OS_FC_PRECONDITION */

  /* #20 Initialize scheduler's task queues. */
  for(priority = 0; priority < Scheduler->NumberOfPriorities; priority++)
  {
    Os_DequeInit(Os_SchedulerPriority2Deque(Scheduler, priority));                                                      /* SBSW_OS_SDR_DEQUEINIT_001 */ /* SBSW_OS_FC_PRECONDITION */
  }

  /* #30 Set scheduler's next and current task and queue references to given task. */
  Scheduler->Dyn->NextTask = IdleTask;                                                                                  /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */
  Scheduler->Dyn->NextPriority = Os_TaskGetHomePriority(IdleTask);                                                      /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */ /* SBSW_OS_FC_PRECONDITION */
  Scheduler->Dyn->CurrentTask = IdleTask;                                                                               /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */
  Scheduler->Dyn->CurrentPriority = Os_TaskGetHomePriority(IdleTask);                                                   /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */ /* SBSW_OS_FC_PRECONDITION */

  /* #40 Initialize the idle task. */
  Os_TaskIdleTaskInit(IdleTask);                                                                                        /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchedulerInsert()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SchedulerInsert
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  Os_TaskPrioType taskHomePriority;
  Os_TaskPrioType nextTaskPriority;
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST) taskQueue;

  taskHomePriority = Os_TaskGetHomePriority(Task);                                                                      /* SBSW_OS_FC_PRECONDITION */
  taskQueue = Os_SchedulerPriority2Deque(Scheduler, taskHomePriority);                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #10 Insert the task at the tail of this task queue. */
  Os_DequeEnqueue(taskQueue, Task);                                                                                     /* SBSW_OS_SDR_DEQUEENQUEUE_001 */

  /* #20 Remember in bit array, that task queue contains ready tasks. */
  Os_BitArraySetBit(&(Scheduler->BitArray), (Os_BitArrayIndexType)taskHomePriority);                                    /* SBSW_OS_FC_PRECONDITION */

  /* #30 If the inserted task has higher priority than the next task: */
  nextTaskPriority = Os_TaskGetPriority(Scheduler->Dyn->NextTask);                                                      /* SBSW_OS_SDR_TASKGETPRIORITY_001 */
  if(Os_SchedulerPriorityIsHigher(taskHomePriority, nextTaskPriority) != 0u)
  {
    /* #40 Set the next task and the next priority in accordance to the inserted task. */
    Scheduler->Dyn->NextTask = Task;                                                                                    /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */
    Scheduler->Dyn->NextPriority = taskHomePriority;                                                                    /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */
  }
}


/***********************************************************************************************************************
 *  Os_SchedulerRemoveCurrentTask()
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
FUNC_P2CONST(Os_TaskConfigType, OS_CONST, OS_CODE) Os_SchedulerRemoveCurrentTask
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
)
{
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) task;
  Os_TaskPrioType currentPriority;
  Os_TaskPrioType homePriority;

  task = Os_SchedulerGetCurrentTask(Scheduler);                                                                         /* SBSW_OS_FC_PRECONDITION */

  Os_Assert((Os_StdReturnType)(task != NULL_PTR));                                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  currentPriority = Scheduler->Dyn->CurrentPriority;                                                                    /* SBSW_OS_FC_PRECONDITION */
  homePriority = Os_TaskGetHomePriority(task);                                                                          /* SBSW_OS_SDR_TASKGETPRIORITY_002 */

  /* #05 Inform the task object about the priority change. */
  Os_TaskSetPriority(task, homePriority);                                                                               /* SBSW_OS_SDR_TASKSETPRIORITY_001 */

  /* #10 Dequeue the current task from queue on current priority and clear bit in bit array, if queue gets empty. */
  Os_SchedulerDequeueTask(Scheduler, currentPriority);                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* #20 If the task's current priority differs from its home priority: */
  if(currentPriority != homePriority)
  {
    /* #30 Dequeue the current task from queue on home priority and clear bit in bit array, if queue gets empty. */
    Os_SchedulerDequeueTask(Scheduler, homePriority);                                                                   /* SBSW_OS_FC_PRECONDITION */
  }

  /* #40 Determine next task and next priority. */
  Os_SchedulerSchedule(Scheduler);                                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #50 Return next task. */
  return Scheduler->Dyn->NextTask;
}


/***********************************************************************************************************************
 *  Os_SchedulerRemoveTaskAll()
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
FUNC_P2CONST(Os_TaskConfigType, OS_CONST, OS_CODE) Os_SchedulerRemoveTaskAll
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
)
{
  Os_TaskPrioType currentPriority = Os_TaskGetPriority(Task);                                                           /* SBSW_OS_FC_PRECONDITION */
  Os_TaskPrioType homePriority = Os_TaskGetHomePriority(Task);                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #05 Inform the task object about the priority change. */
  Os_TaskSetPriority(Task, homePriority);                                                                               /* SBSW_OS_SDR_TASKSETPRIORITY_001 */

  /* #10 If the task's current priority differs from its home priority: */
  if(currentPriority != homePriority)
  {
    /* #20 Remove the entry of the given task from the task queue on the current priority of this task. */
    Os_SchedulerDeleteTask(Scheduler, currentPriority, Task);                                                           /* SBSW_OS_FC_PRECONDITION */
  }

  /* #30 Remove pending multiple activations. */
  Os_SchedulerDeleteTask(Scheduler, homePriority, Task);                                                                /* SBSW_OS_FC_PRECONDITION */

  /* #40 Determine next task and next priority. */
  Os_SchedulerSchedule(Scheduler);                                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #50 Return next task. */
  return Scheduler->Dyn->NextTask;
}


/***********************************************************************************************************************
 *  Os_SchedulerIncreasePrio()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SchedulerIncreasePrio
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType NewPriority
)
{
  Os_TaskPrioType currentPrio;
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;

  currentTask = Os_SchedulerGetCurrentTask(Scheduler);                                                                  /* SBSW_OS_FC_PRECONDITION */
  currentPrio = Os_TaskGetPriority(currentTask);                                                                        /* SBSW_OS_SDR_TASKGETPRIORITY_002 */

  Os_Assert(Os_SchedulerPriorityIsHigher(NewPriority, currentPrio));
  Os_Assert((Os_StdReturnType)(NewPriority < Scheduler->NumberOfPriorities));                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(Scheduler->Dyn->CurrentPriority == currentPrio));                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 Move the current task up to the given priority. */
  Os_SchedulerTaskMoveUp(Scheduler, currentTask, Scheduler->Dyn->CurrentPriority, NewPriority);                         /* SBSW_OS_SDR_SCHEDULERTASKMOVEUP_001 */
  Scheduler->Dyn->CurrentPriority = NewPriority;                                                                        /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */

  /* #20 Set current task's priority to its new priority. */
  Os_TaskSetPriority(currentTask, NewPriority);                                                                         /* SBSW_OS_SDR_TASKSETPRIORITY_001 */
}


/***********************************************************************************************************************
 *  Os_SchedulerDecreasePrio()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SchedulerDecreasePrio
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType NewPriority
)
{
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;
  Os_TaskPrioType currentPrio;

  currentTask = Os_SchedulerGetCurrentTask(Scheduler);                                                                  /* SBSW_OS_FC_PRECONDITION */
  currentPrio = Os_TaskGetPriority(currentTask);                                                                        /* SBSW_OS_SDR_TASKGETPRIORITY_002 */

  Os_Assert(Os_SchedulerPriorityIsHigher(currentPrio, NewPriority));
  Os_Assert((Os_StdReturnType)(NewPriority < Scheduler->NumberOfPriorities));                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 Move the current task down to the given priority. */
  Os_SchedulerTaskMoveDown(Scheduler, Scheduler->Dyn->CurrentPriority, NewPriority);                                    /* SBSW_OS_FC_PRECONDITION */
  Scheduler->Dyn->CurrentPriority = NewPriority;                                                                        /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */

  /* #20 Set current task's priority to its new priority. */
  Os_TaskSetPriority(currentTask, NewPriority);                                                                         /* SBSW_OS_SDR_TASKSETPRIORITY_001 */

  /* #30 Determine next task and next priority. */
  Os_SchedulerSchedule(Scheduler);                                                                                      /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchedulerInternalSchedule()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST), OS_CODE) Os_SchedulerInternalSchedule
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
)
{
  Os_TaskPrioType runningPriority = Os_TaskGetRunningPriority(Scheduler->Dyn->NextTask);                                /* SBSW_OS_SDR_TASKGETRUNNINGPRIORITY_001 */

  /* #10 If the next task's running priority is higher than its current priority: */
  if(Os_SchedulerPriorityIsHigher(runningPriority, Os_TaskGetPriority(Scheduler->Dyn->NextTask)) != 0u)                 /* SBSW_OS_SDR_TASKGETPRIORITY_001 */
  {
     /* #20 Move the next task up to its running priority. */
     Os_SchedulerTaskMoveUp(Scheduler, Scheduler->Dyn->NextTask, Scheduler->Dyn->NextPriority, runningPriority);        /* SBSW_OS_SDR_SCHEDULERTASKMOVEUP_002 */
     Scheduler->Dyn->NextPriority = runningPriority;                                                                    /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */

     /* #30 Set next task's priority to its running priority. */
     Os_TaskSetPriority(Scheduler->Dyn->NextTask, runningPriority);                                                     /* SBSW_OS_SDR_TASKSETPRIORITY_002 */
  }

  /* #40 Set current task and priority in accordance to next task and priority. Return the new current task. */
  Scheduler->Dyn->CurrentTask = Scheduler->Dyn->NextTask;                                                               /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */
  Scheduler->Dyn->CurrentPriority = Scheduler->Dyn->NextPriority;                                                       /* SBSW_OS_SDR_SCHEDULERGETDYN_001 */

  return Scheduler->Dyn->CurrentTask;
}



/***********************************************************************************************************************
 *  Os_SchedulerReleaseRunPrio()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(Os_StdReturnType, OS_CONST) Os_SchedulerReleaseRunningPrio
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
)
{
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) currentTask;
  P2VAR(Os_SchedulerType, TYPEDEF, OS_VAR_NOINIT) dyn;
  Os_TaskPrioType currentTaskHomePrio;

  dyn = Scheduler->Dyn;

  currentTask = Os_SchedulerGetCurrentTask(Scheduler);                                                                  /* SBSW_OS_FC_PRECONDITION */
  currentTaskHomePrio = Os_TaskGetHomePriority(currentTask);                                                            /* SBSW_OS_SDR_TASKGETHOMEPRIORITY_001 */

  /* #10 Check that current task's priority is its running priority. */
  Os_Assert((Os_StdReturnType)(Os_TaskGetPriority(currentTask) == Os_TaskGetRunningPriority(currentTask)));             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_SDR_TASKGETPRIORITY_003 */ /* SBSW_OS_SDR_TASKGETRUNNINGPRIORITY_002 */

  /* #20 Move current task down to its home priority. */
  Os_SchedulerTaskMoveDown(Scheduler, dyn->CurrentPriority, currentTaskHomePrio);                                       /* SBSW_OS_FC_PRECONDITION */
  Os_TaskSetPriority(currentTask, currentTaskHomePrio);                                                                 /* SBSW_OS_SDR_TASKSETPRIORITY_001 */

  /* #30 Determine next task. */
  Os_SchedulerSchedule(Scheduler);                                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #40 Return whether a task switch is needed. */
  return Os_SchedulerTaskSwitchIsNeeded(Scheduler);                                                                     /* SBSW_OS_FC_PRECONDITION */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */



#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_SDR_DEQUEDELETETOP_001
 \DESCRIPTION    Os_DequeDeleteTop is called with the return value of Os_SchedulerPriority2Deque.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_DEQUEISEMPTY_001
 \DESCRIPTION    Os_DequeIsEmpty is called with the return value of Os_SchedulerPriority2Deque.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_DEQUEDELETE_001
 \DESCRIPTION    Os_DequeDelete is called with the return value of Os_SchedulerPriority2Deque.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_DEQUEPREPEND_001
 \DESCRIPTION    Os_DequePrepend is called with the return value of Os_SchedulerPriority2Deque and a value passed as
                 pointer to the caller function. Precondition ensures that the pointer is valid. The compliance of
                 the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_SCHEDULERGETDYN_001
 \DESCRIPTION    Write access to the Dyn element of a scheduler object.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERGETDYN_M]

\ID SBSW_OS_SDR_DEQUEPEEK_001
 \DESCRIPTION    Os_DequePrepend is called with the return value of Os_SchedulerPriority2Deque.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_DEQUEINIT_001
 \DESCRIPTION    Os_DequeInit is called with the return value of Os_SchedulerPriority2Deque.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_DEQUEENQUEUE_001
 \DESCRIPTION    Os_DequeEnqueue is called with the return value of Os_SchedulerPriority2Deque which is called with an
                 index returned from Os_TaskGetHomePriority. Precondition of Os_TaskGetHomePriority ensures, that the
                 returned value is in a valid range. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SCHEDULERPRIORITY2DEQUE_M]

\ID SBSW_OS_SDR_TASKGETPRIORITY_001
 \DESCRIPTION    Os_TaskGetPriority is called with the Next task. The Next task is derived from the Dyn object of a
                 Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_NEXT_T]

\ID SBSW_OS_SDR_TASKGETPRIORITY_002
 \DESCRIPTION    Os_TaskGetHomePriority is called with the return value of Os_SchedulerGetCurrentTask.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_SDR_TASKGETPRIORITY_003
 \DESCRIPTION    Os_TaskGetHomePriority is called with the current task of a scheduler. The Current task is derived from
                 the Dyn object of a Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_SDR_TASKGETHOMEPRIORITY_001
 \DESCRIPTION    Os_TaskGetHomePriority is called with the current task of a scheduler. The Current task is derived from
                 the Dyn object of a Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_SDR_TASKSETPRIORITY_001
 \DESCRIPTION    Os_TaskSetPriority is called with the return value of Os_SchedulerGetCurrentTask.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_SDR_TASKSETPRIORITY_002
 \DESCRIPTION    Os_TaskSetPriority is called with the Next task. The Next task is derived from the Dyn object of
                 a Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_NEXT_T]

\ID SBSW_OS_SDR_SCHEDULERTASKMOVEUP_001
 \DESCRIPTION    Os_SchedulerTaskMoveUp is called with the return value of Os_SchedulerGetCurrentTask and the
                 Scheduler an argument of the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

\ID SBSW_OS_SDR_SCHEDULERTASKMOVEUP_002
 \DESCRIPTION    Os_SchedulerTaskMoveUp is called with the Next task. The Next task is derived from the Dyn object of
                 a Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_NEXT_T]

\ID SBSW_OS_SDR_TASKGETRUNNINGPRIORITY_001
 \DESCRIPTION    Os_TaskGetRunningPriority is called with the Next task. The Next task is derived from the Dyn object of
                 a Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_NEXT_T]

\ID SBSW_OS_SDR_TASKGETRUNNINGPRIORITY_002
 \DESCRIPTION    Os_TaskGetRunningPriority is called with the current task of a scheduler. The Current task is derived
                 from the Dyn object of a Scheduler object passed as argument to the caller function.
                 Precondition ensures, that the returned Scheduler object is valid. The compliance of the precondition
                 is check during review.
 \COUNTERMEASURE \T [CM_OS_SCHEDULER_CURRENT_T]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_SCHEDULERPRIORITY2DEQUE_M
      Precondition ensures that the given index is in range. The compliance of the precondition is check during review.
      Verify that:
        1. the TaskQueues pointer of each scheduler  is no NULL_PTR,
        2. the size of the TaskQueues is equal to OS_CFG_NUM_TASKQUEUES and
        3. the NumberOfPriorities value in each scheduler is equal to OS_CFG_NUM_TASKQUEUES.

\CM CM_OS_SCHEDULERGETCURRENTTASK_M
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.
      Verify that the Dyn reference in each application instance is a non NULL_PTR.

\CM CM_OS_SCHEDULERGETDYN_M
      Verify that the Dyn pointer of the Os_SchedulerConfigType object is a non NULL_PTR.

\CM CM_OS_SCHEDULER_NEXT_T
      TCASE-345830 ensures, that Next is initialized during scheduler initialization, and never set to an invalid value.

\CM CM_OS_SCHEDULER_CURRENT_T
      TCASE-345830 ensures, that Current is initialized during scheduler initialization, and never set to an invalid
      value.

\CM CM_SCHEDULERINTERNALSCHEDULE_T
      [CM_OS_SCHEDULER_CURRENT_T]

\CM CM_OS_SCHEDULERREMOVECURRENTTASK_R
      Idle task may not be unscheduled, so there is at least the Idle Task which is returned as NextTask.

 */

/*!
 * \}
 */

/**********************************************************************************************************************
 *  END OF FILE: Os_Scheduler.c
 *********************************************************************************************************************/
