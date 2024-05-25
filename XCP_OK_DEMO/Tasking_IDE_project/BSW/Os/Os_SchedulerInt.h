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
 *  \defgroup    Os_Scheduler Scheduler
 *  \brief       The scheduler is responsible to manage ready tasks and determine which task should be running next.
 *  \details
 *  MICROSAR OS implements fixed-priority pre-emptive scheduling: If several tasks with different priority are
 *  ready to run, the one with highest priority will become running. All other tasks have to wait until this one has
 *  finished. In order to find the task with highest priority, the OS uses a priority queue.
 *
 *  When different tasks with identical priority are ready to run, these tasks are scheduled first in - first out
 *  (the task which was activated first is scheduled first). In order to find the task which was activated first,
 *  the OS uses a FIFO queue.
 *
 *  OSEK scheduling allows multiple activation of tasks. Such multiple activations are scheduled first-in first-out by
 *  the order of activation. Therefore, the FIFO queue must be able to hold several task activation instances per task.
 *  Fortunately, that number is limited to a configured maximum.
 *
 *  In summary the scheduler needs two data structures:
 *   1. a **Priority Queue**, which holds FIFO queues, sorted by priority
 *   2. one **Task Queue** per priority, which holds the task activations, sorted by activation order.
 *
 *  ![Scheduler Data Structures](SchedulerDataStructures.png)
 *
 *  Different implementations of such data structures are possible:
 *
 *  ###Priority Queue
 *  ####Binary Heap
 *  - Binary heap may also be used for job management, so code could be reused.
 *  - All insert/remove operations in O(log n), finding top element in O(1)
 *
 *  ####Bit-Array
 *  - All insert/remove operations in O(1), finding the top element in O(1).
 *  - In order to allow this implementation, priorities should be gap-less with highest priority 0 and
 *    higher priority values should represent lower priorities.
 *  - As a result of the last point, OSEK priorities would need a translation into internal priorities.
 *
 *  ####Decision
 *  The first implementation used a binary heap. In order to allow a switch to the bit-array implementation, the OSEK
 *  priorities where already translated to internal priorities in the generator, as needed by the bit-array
 *  implementation.
 *  After the first performance measurements, the decision was taken to switch to the bit array implementation
 *  immediately. So, for performance reasons the scheduler uses a bit array.
 *
 *  ###Task Queue
 *  ####Ring Buffer
 *  - With ring buffer we mean an array of defined size with two pointers that define the positions to read and write.
 *  - This implementation can also be used in IOC.
 *  - For priority ceiling it is useful to be able to add a task not only at the end of a FIFO but also at its head.
 *    Such a data structure is called double-ended queue (*deque*) in the literature. Therefore, the data structure we
 *    use here is a deque but often also called synonymously FIFO.
 *  - Implementations with (double-) linked lists (which are used in several other OS implementations) are not suitable
 *    for OSEK based scheduling, because of multiple activation.
 *
 *
 *  ###Task References
 *  The scheduler manages two task references:
 *  - The **current task**, which points to the task which is currently in RUNNING state.
 *  - The **next task**, which points to the task with the highest priority. This task will become the current task,
 *    if the kernel reaches the next task switching point.
 *
 *  For performance reasons, the scheduler also holds references to the task queues.
 *
 *  ###Calculation of required queue size
 *
 *  X denotes the priority of interest.
 *
 *  Name              | Description
 *  ------------------|-------------------------------------------------------------------------------------------
 *  TaskInstance(X)   | Sum of MaxActivations of all tasks with priority == X.
 *  RunningPriority(X)| Equals 1, if there is at least one task with running priority == X, otherwise 0.
 *  LockPriority(X)   | Equals 1, if there is at least one Spinlock or Resource with ceiling priority == X, otherwise 0.
 *  AdditionalSlot(X) | Equals always 1, due to queue implementation.
 *
 *  > QueueSize(X) = TaskInstance(X) + RunningPriority(X) + LockPriority(X) + AdditionalSlot(X)
 *
 *
 *  \see \ref Os_BitArray
 *  \see \ref Os_Deque
 *  \see [Bit-Array](http:\\en.wikipedia.org/wiki/Bit_array)
 *  \see [Fixed-priority pre-emptive scheduling](http:\\en.wikipedia.org/wiki/Fixed-priority_pre-emptive_scheduling)
 *
 *
 *  \trace CREQ-124, CREQ-30, CREQ-86
 *  \trace SPEC-63925
 *
 *
 *  \{
 *  \file
 *  \brief       Interface of \ref Os_Scheduler.
 *  \details     --no details--
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SCHEDULERINT_H
# define OS_SCHEDULERINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Scheduler_Types.h"

/* Os module dependencies */
# include "Os_CommonInt.h"
# include "Os_Task_Types.h"
# include "Os_BitArrayInt.h"
# include "Os_DequeInt.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Dynamic management information of a scheduler. */
struct Os_SchedulerType_Tag
{
  /*! Priority of the next task to become running (defines the next queue to take task from). */
  Os_TaskPrioType NextPriority;
  /*! The next task to become running. */
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) NextTask;

  /*! Priority of the currently running task (defines the queue of the current task). */
  Os_TaskPrioType CurrentPriority;

  /*! The currently running task. */
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) CurrentTask;
};

/*! Configuration information of a scheduler. */
struct Os_SchedulerConfigType_Tag
{
  /*! References to not empty task queues, sorted by priority. */
  Os_BitArrayConfigType BitArray;

  /*! Dynamic part of the scheduler. */
  P2VAR(Os_SchedulerType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! List of task queues (one per priority). */
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_CONST) TaskQueues;

  /*! Number of task queues. */
  Os_TaskPrioType NumberOfPriorities;
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
 *  Os_SchedulerInit()
 **********************************************************************************************************************/
/*! \brief          Initialize scheduler data structures.
 *  \details        The kernel uses this function to initialize schedulers during OS initialization.
 *                  After calling this function, the scheduler is initialized and contains only the given idle task.
 *                  Other scheduler functions assume that there is always a valid task, the idle task.
 *                  This function is called in Init-Step3 and Init-Step4 in order to handle the situation that
 *                  Init-Step3 is optional.
 *
 *  \param[in,out]  Scheduler   Reference to the scheduler configuration structure. Parameter must not be NULL.
 *  \param[in]      IdleTask    Reference to the task which shall be the idle task of this scheduler.
 *                              Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchedulerInit
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) IdleTask
);


/***********************************************************************************************************************
 *  Os_SchedulerPriorityIsHigher()
 **********************************************************************************************************************/
/*! \brief          Return whether given priority PrioX is logically higher than PrioY.
 *  \details        --no details--
 *
 *  \param[in]      PrioX
 *  \param[in]      PrioY
 *
 *  \retval         !0  If PrioX is logically higher than PrioY.
 *  \retval         0   If PrioX is logically lower or equal to PrioY.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchedulerPriorityIsHigher,
(
  Os_TaskPrioType PrioX,
  Os_TaskPrioType PrioY
));


/***********************************************************************************************************************
 *  Os_SchedulerPriorityIsHigherOrEqual()
 **********************************************************************************************************************/
/*! \brief          Return whether given priority PrioX is logically higher than or equal to PrioY.
 *  \details        --no details--
 *
 *  \param[in]      PrioX
 *  \param[in]      PrioY
 *
 *  \retval         !0  If PrioX is logically higher than or equal to PrioY.
 *  \retval         0   If PrioX is logically lower or equal to PrioY.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchedulerPriorityIsHigherOrEqual,
(
  Os_TaskPrioType PrioX,
  Os_TaskPrioType PrioY
));


/***********************************************************************************************************************
 *  Os_SchedulerPriorityIsLower()
 **********************************************************************************************************************/
/*! \brief          Return whether given priority PrioX is logically lower than PrioY.
 *  \details        --no details--
 *
 *  \param[in]      PrioX
 *  \param[in]      PrioY
 *
 *  \retval         !0  If PrioX is logically lower than PrioY.
 *  \retval         0   If PrioX is not logically lower than PrioY.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchedulerPriorityIsLower,
(
  Os_TaskPrioType PrioX,
  Os_TaskPrioType PrioY
));


/***********************************************************************************************************************
 *  Os_SchedulerInsert()
 **********************************************************************************************************************/
/*! \brief          Add the given task into scheduling.
 *  \details        Add the given task into the scheduler data structures.
 *                  Update next task reference, if given task has higher priority.
 *                  Current task reference is not modified.
 *
 *  \param[in,out]  Scheduler   Reference to the scheduler configuration structure. Parameter must not be NULL.
 *  \param[in]      Task        The task to add. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Task data has already been updated.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchedulerInsert
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_SchedulerRemoveCurrentTask()
 **********************************************************************************************************************/
/*! \brief          Remove current activation instance of the current task and return next task.
 *  \details        This service is used for task termination.
 *
 *  \param[in,out]  Scheduler    Reference to the scheduler configuration structure. Parameter must not be NULL.
 *
 *  \return         Next task (may be identical to the current because of multiple activation)
 *
 *  \context        TASK|ISR2|PROTHOOK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The current tasks priority is identical to the running priority
 *                  (all spinlocks and resources released).
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC_P2CONST(Os_TaskConfigType, OS_CONST, OS_CODE) Os_SchedulerRemoveCurrentTask
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
);


/***********************************************************************************************************************
 *  Os_SchedulerRemoveTaskAll()
 **********************************************************************************************************************/
/*! \brief          Remove all entries of the given task and return next task.
 *  \details        This service is used for application termination.
 *
 *  \param[in,out]  Scheduler    Reference to the scheduler configuration structure. Parameter must not be NULL.
 *  \param[in]      Task         The task to remove. Parameter must not be NULL.
 *
 *  \return         Next task (may be identical to the current task)
 *
 *  \context        TASK|ISR2|ERRHOOK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The tasks current priority is identical to the running priority
 *                  (all spinlocks and resources released).
 *  \pre            The task is contained in the deque at the given priority
 *                  (task has just changed from RUNNING or READY to SUSPENDED state).
 **********************************************************************************************************************/
FUNC_P2CONST(Os_TaskConfigType, OS_CONST, OS_CODE) Os_SchedulerRemoveTaskAll
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task
);


/***********************************************************************************************************************
 *  Os_SchedulerIncreasePrio()
 **********************************************************************************************************************/
/*! \brief          Increase the priority of the current task.
 *  \details        This service is used for priority ceiling on resources, spinlocks and semaphores.
 *
 *  \param[in,out]  Scheduler     Reference to the scheduler configuration structure. Parameter must not be NULL.
 *  \param[in]      NewPriority   The new priority of the task.
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE for different schedulers
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Task data has already been updated.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchedulerIncreasePrio
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType NewPriority
);


/***********************************************************************************************************************
 *  Os_SchedulerDecreasePrio()
 **********************************************************************************************************************/
/*! \brief          Decrease the priority of the current task and determine the next task.
 *  \details        This service is used for priority ceiling on resources, spinlocks and semaphores.
 *
 *  \param[in,out]  Scheduler    Reference to the scheduler configuration structure. Parameter must not be NULL.
 *  \param[in]      NewPriority  The new priority of the task.
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE for different schedulers
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Task data has already been updated.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchedulerDecreasePrio
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler,
  Os_TaskPrioType NewPriority
);


/***********************************************************************************************************************
 *  Os_SchedulerInternalSchedule()
 **********************************************************************************************************************/
/*! \brief          Set the current task according to next task.
 *  \details        Increase the priority to the running priority of that task (get internal resource, prevent
 *                  preemption).
 *
 *  \param[in,out]  Scheduler    Reference to the scheduler configuration structure. Parameter must not be NULL.
 *
 *  \return         The new current task.
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Task data has already been updated.
 *
 *  \trace          CREQ-66
 **********************************************************************************************************************/
FUNC(P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST), OS_CODE) Os_SchedulerInternalSchedule
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
);


/***********************************************************************************************************************
 *  Os_SchedulerGetCurrentTask()
 **********************************************************************************************************************/
/*! \brief          Return current task.
 *  \details        This service is used to determine the task which is in RUNNING state, e.g. in GetTaskID().
 *
 *  \param[in]      Scheduler   Reference to the scheduler configuration structure. Parameter must not be NULL.
 *
 *  \return         Current task
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Current task is set to a valid value.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchedulerGetCurrentTask,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
));


/***********************************************************************************************************************
 *  Os_SchedulerTaskSwitchIsNeeded()
 **********************************************************************************************************************/
/*! \brief          Calculate whether a task switch is needed.
 *  \details        Return whether or not the next task differs from the current task.
 *
 *  \param[in]      Scheduler   Reference to the scheduler configuration structure. Parameter must not be NULL.
 *
 *  \retval         0!  Task switch is needed.
 *  \retval         0   Task switch is not needed.
 *
 *  \context        OS_INTERNAL|ISR2|TASK|ERRHOOK|PROTHOOK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType,
OS_CODE, OS_ALWAYS_INLINE, Os_SchedulerTaskSwitchIsNeeded,
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
));


/***********************************************************************************************************************
 *  Os_SchedulerReleaseRunningPrio()
 **********************************************************************************************************************/
/*! \brief          Bring the current task down from its running priority to its home priority
 *                  and return whether there is a task with higher priority.
 *  \details        --no details--
 *
 *  \param[in]      Scheduler   Reference to the scheduler configuration structure. Parameter must not be NULL.
 *
 *  \retval         !0  There is a task which has higher priority than the current task's home priority.
 *  \retval         0   There is no task which has higher priority than the current task's home priority.
 *
 *  \context        TASK
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          CREQ-66
 **********************************************************************************************************************/
FUNC(Os_StdReturnType, OS_CONST) Os_SchedulerReleaseRunningPrio
(
  P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) Scheduler
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_SCHEDULERINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_SchedulerInt.h
 **********************************************************************************************************************/
