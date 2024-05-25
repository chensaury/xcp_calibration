/***********************************************************************************************************************
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain wi:wth Vector Informatik GmbH.
 *  \endverbatim
 *  --------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup      Os_Kernel
 *  \defgroup     Os_TimingProtection Timing Protection
 *  \brief        Timing protection mechanism
 *  \details
 *
 *  Timing protection consists of the following parts:
 *
 *  - Execution time protection
 *  - Inter-arrival time protection
 *  - Locking time protection
 *
 *  Timing protection monitors the threads:
 *
 *  - Tasks
 *  - ISRs
 *
 *  Other entities (e.g. ISR1, hooks, trusted functions, ...) are not monitored by timing protection and consume
 *  the budget of the currently active Task/ISR.
 *
 *  ### Monitored Thread
 *  Each task and ISR thread has own budgets. Whenever a task or ISR switch occurs, the currently monitored
 *  thread is switch to the new thread.
 *
 *  Hook threads and timing protection ISR threads do not have own budgets. Instead those threads inherit the
 *  timing protection setting from the preceding thread. So if a switch from any thread to an inheriting thread occurs,
 *  the monitored thread does not change.
 *
 *  ### Execution time protection
 *  Each thread has a configured maximum execution time - the *execution budget*.
 *  The execution budget is part of the thread's context.
 *
 *  The OS *resets* the execution budget if:
 *  - a thread is initialized.
 *  - a thread is terminated.
 *  - a task enters waiting state.
 *
 *  The OS *resumes* monitoring whenever a thread:
 *  - is started
 *  - is resumed
 *
 *  The OS *suspend* monitoring whenever a thread:
 *  - is suspended
 *
 *  Execution time is reset, if a task enters waiting state. A task is also considered to enter/leave waiting state,
 *  even if it has not been waiting, because the event already has been set and it immediately became running again.
 *
 *  ### Updating of the monitored thread
 *  The monitored thread may be updated while switching or returning to another thread.
 *  The following tables describe the cases where updating of the monitored thread is needed.
 *
 *  The following table shows which thread types have their own budgets.
 *  | TP thread type | Thread type                 | Description                    |
 *  |:---------------|:----------------------------|:-------------------------------|
 *  | Owner          | Task or ISR                 | see \ref OS_TPTHREADKIND_OWNER |
 *  | Heir           | Hook                        | see \ref OS_TPTHREADKIND_HEIR  |
 *  | TpIsr          | Timing protection interrupt | see \ref OS_TPTHREADKIND_TPISR |
 *  \n
 *
 *  **Switch**\n
 *  The switch method is used in case that the timing protection is switched to a newly started thread.
 *  |Current \ Next | Owner | Heir | TpIsr |
 *  |:--------------|:-----:|:----:|:-----:|
 *  | **Owner**     | yes   | no   | no    |
 *  | **Heir**      | n/a   | no   | no    |
 *  | **TpIsr**     | n/a   | no   | n/a   |
 *  \n
 *
 *  **Reset And Resume**\n
 *  The reset and resume method is used in case that the timing protection returns to a previously suspended thread.
 *  |Current \ Next | Owner | Heir | TpIsr |
 *  |:--------------|:-----:|:----:|:-----:|
 *  | **Owner**     | yes   | n/a  | n/a   |
 *  | **Heir**      | k/r   | no   | no    |
 *  | **TpIsr**     | k/r   | no   | n/a   |
 *  \n
 *
 *  | Symbol | Description                                                                               |
 *  |:-------|:------------------------------------------------------------------------------------------|
 *  | yes    | update monitored thread                                                                   |
 *  | no     | keep monitored thread                                                                     |
 *  | n/a    | transition not possible                                                                   |
 *  | k/r    | update monitored thread if current thread has changed (in case of killing) otherwise keep |
 *
 *  ### Inter-arrival time protection
 *  Each thread has a configured minimum for the inter-arrival time - the *time frame*.
 *  The time frame defines the minimum time between thread arrivals.
 *
 *  Whenever an arrival occurs, the OS stores the current time and checks whether there is an inter-arrival time
 *  violation.
 *
 *  An *arrival* is one of the following situations:
 *
 *  - A task is activated.
 *  - A task is released from waiting.
 *  - The occurrence of an ISR is detected.
 *
 *  A task is considered as activated by means of ActivateTask(), ChainTask() or as an activation event of an alarm
 *  or schedule table. In case of multiple activation each activation is considered as one arrival.
 *
 *
 *  #### Long inter-arrival time
 *  The time between inter-arrivals is not limited by AUTOSAR. To handle long inter-arrival times, the OS uses
 *  a 64 bit data type for inter-arrival time.
 *
 *
 *  ### Locking time protection
 *  Each thread has configured maximum for the locking time of a lock (interrupt or resource lock) - the *lock budget*.
 *  Internal resources do not have locking time protection, because they are identical to the task's execution time.
 *
 *  Lock budget monitoring is started, if a thread:
 *
 *  - disables/suspends all interrupts
 *  - disables/suspends OS interrupts
 *  - gets a resource
 *
 *  Lock budget monitoring is suspended, if a thread:
 *
 *  - enables/resumes all interrupts
 *  - enables/resumes OS interrupts
 *  - releases a resource
 *
 *  In case, pairs of 'Suspend*Interrupts()' and 'Resume*Interrupts() are called in a nested way, the first call of
 *  'Suspend*Interrupts()' starts monitoring and the last call of 'Resume*Interrupts()' stops monitoring.
 *
 *  As locks can be occupied stack based, multiple locking budgets have to be monitored simultaneously.
 *  After releasing a lock, the next deadline has to be programmed to the hardware timer.
 *
 *  If a thread switch occurs while a lock is occupied, the current budget is suspended. The locking time budget is
 *  resumed, if the thread is resumed again.
 *
 *
 *  ### ISR1 Problem
 *  ISR1 bypass the OS. For this reason an ISR1 may get terminated in case it is executed, while
 *  the budget of a monitored entity is exhausted.
 *
 *  \note AUTOSAR does not specify any behavior for this situation.
 *        AUTOSAR advises against usage of ISR1 in systems with timing protection.
 *
 *
 *  ### Delayed Timing Protection Report
 *  Timing protection reporting can be delayed for selected applications
 *  (BSWMD parameter 'OsTrustedApplicationDelayTimingViolationCall').
 *
 *  This allows to delay the protection handling until a trusted function has finished execution.
 *
 *
 *  ## Timing Protection ISR
 *  Execution time and locking time protection requires a hardware timer and a high priority interrupt.
 *  The interrupt has to be raised when a budget is exhausted.
 *
 *  Timing protection supervises the timing behavior. For this reason the timing protection ISR must be executed with
 *  the highest interrupt priority level. To be able to detect locking time violations, the ISR has to be executed even
 *  if the user has disabled interrupts using the interrupt API. The interrupt APIs must not effect the timing
 *  protection ISR. Depending on the hardware there are two ways to achieve this:
 *
 *  - Using the highest interrupt priority level.
 *  - Using a NMI as the timing protection ISR source.
 *
 * ### Timing Protection Violation Handling ###
 * ![Timing Protection Violation Handling](TimingProtection_Violation.png)
 *
 *
 * ### Limitation Solutions ###
 * Limitation 1:
 * Description: Cat. 1 ISRs may not be used, if timing protection is enabled.
 * Reason: If a Cat. 1 ISR is interrupted by the TP interrupt and kills the current thread, the Cat. 1 ISR is
 *         also killed
 *
 * Limitation 2:
 * Description: Cat. 1 ISRs may not be used, if timing protection and memory protection is enabled.
 * Reason: If a Cat. 1 ISR is interrupted by the TP interrupt the TP interrupt modifies the current MPU settings,
 *         and restores the setting of the caller when returning. Instead the TP ISR should restore, the settings of
 *         the ISR.
 *
 *
 * Solutions:
 * 1. Use two interrupts:
 *    - Interrupt 1 is used as timer interrupt.
 *        - The interrupt monitors the interrupt lock budget.
 *        - The interrupt has the highest priority (higher than Cat. 1 interrupts or is an NMI).
 *        - It checks whether the interrupt occurred because of an interrupt lock budget on system level was exceeded:
 *            - If this is the case, there is currently no Cat. 1 ISR running and the caller may be killed.
 *            - Otherwise, Interrupt 2 is triggered.
 *        - It stores the current MPU configuration on entry and restores it on return.
 *    - Interrupt 2 is used for any other budgets.
 *        - The timer ISR is implemented as Cat. 2 interrupt.
 *        - The interrupt has a higher priority than each Cat. 2 ISR.
 *
 * 2. Use two timers:
 *   - Timer 1 is used for interrupt lock monitoring on system level.
 *        - The interrupt has the highest priority (higher than Cat. 1 interrupts or is an NMI).
 *        - As a Cat. 1 interrupt may not occur, storing the current MPU settings is not required.
 *        - If there is no Cat. 1 interrupt configured, system level monitoring is handled by interrupt 2.
 *   - Timer 2 is used for any other budget.
 *        - The timer ISR is implemented as Cat. 2 interrupt.
 *        - The interrupt has a higher priority than any Cat. 2 ISR.
 *
 *
 *  \trace SPEC-63833, SPEC-63779, SPEC-63760
 *
 *
 *  \{
 *
 *  \file
 *  \brief
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TIMINGPROTECTIONINT_H
# define OS_TIMINGPROTECTIONINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_TimingProtection_Cfg.h"
# include "Os_TimingProtection_Types.h"

/* Os module dependencies */
# include "Os_CommonInt.h"
# include "Os_ErrorInt.h"
# include "Os_Cfg.h"
# include "Os_CounterInt.h"
# include "Os_TimerInt.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"
# include "Os_Hal_TimerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! Type cast from Os_TpOwnerThreadConfigType to Os_TpThreadConfigType by use of base element addressing. */
#define OS_TP_CASTCONFIG_TPOWNERTHREAD_2_TPTHREAD(tpOwnerThread)  (&((tpOwnerThread).Base))                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_TpThreadConfigType to Os_TpThreadConfigType* (for symmetry reasons and to ease generation. */
#define OS_TP_CASTCONFIG_TPTHREAD_2_TPTHREAD(tpThread)            (&((tpThread)))                                       /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Data type for different thread related timing protection configurations types. */
typedef enum
{
  OS_TPTHREADKIND_OWNER,        /*!< The thread is monitored and has own budgets. */
  OS_TPTHREADKIND_HEIR,         /*!< The thread is monitored and uses the budgets of its host. */
  OS_TPTHREADKIND_TPISR         /*!< The thread is the timing protection interrupt. */
}Os_TpMonitoringKindType;


typedef uint8_least Os_TpDelayLevelType;

/*! Dynamic information of a timing protection budget. */
struct Os_TpBudgetType_Tag
{
  /*! Remaining time until budget is exhausted. */
  Os_TickType Remaining;

  /*! Previous budget. */
  P2CONST(Os_TpBudgetConfigType, TYPEDEF, OS_CONST) Previous;
};


/*! Configured information about a timing protection budget. */
struct Os_TpBudgetConfigType_Tag
{
  /*! Dynamic data of a timing protection budget. */
  P2VAR(Os_TpBudgetType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! Specifies the type of this execution budget. */
  Os_TpMonitoringType BudgetKind;

  /*! Initial budget. */
  Os_TickType Budget;
};


/*! Dynamic timing protection data. */
struct Os_TpOwnerThreadType_Tag
{
  /*! Time stamp of the next arrival allowed. */
  Os_InterArrivalTimeType EarliestArrival;

  /*! The number of ongoing delay requests. */
  Os_TpDelayLevelType DelayLevel;

  /*! Stack of currently monitored budgets. Sorted by earliest deadline first.
   * Budgets which have a later deadline than budgets that are already monitored, are not monitored.
   * We can do this, because locks have to be acquired and released in a stack based manner. */
  P2CONST(Os_TpBudgetConfigType, TYPEDEF, OS_CONST) MonitoredBudgets;

  /*! Indicates whether at least one budget has already been expired.
   * (Info needed for delayed timing protection reporting). */
  Os_TpMonitoringType Violation;
};


/*! Configured Timing protection settings. */
struct Os_TpThreadConfigType_Tag
{
  /*! Defines the kind of monitoring that is applied to the thread. */
  Os_TpMonitoringKindType ThreadKind;
};


/*! Configuration information of a monitored thread.
 * \details
 * \extends Os_TpThreadConfigType_Tag
 */
struct Os_TpOwnerThreadConfigType_Tag
{
  /*! The thread attributes of this task.
   * This attribute must come first! */
  Os_TpThreadConfigType Base;

  /*! Minimum allowed time between successive activations. */
  Os_InterArrivalTimeType TimeFrame;

  /*! Execution budget. */
  Os_TpBudgetConfigType ExecutionBudget;

  /*! All interrupt lock time budget. */
  Os_TpBudgetConfigType AllInterruptLockBudget;

  /*! OS interrupt lock time budget. */
  Os_TpBudgetConfigType OsInterruptLockBudget;

  /*! Resource lock time budgets. */
  P2CONST(Os_TpBudgetConfigRefType, TYPEDEF, OS_CONST) ResourceLockBudgets;

  /*! Dynamic data of the timing protection settings.
   * \details As there is no Dyn object within the base class, the Dyn pointer is located here. */
  P2VAR(Os_TpOwnerThreadType, TYPEDEF, OS_VAR_NOINIT) Dyn;
};


/*! Dynamic data of timing protection object. */
struct Os_TpType_Tag
{
  /*! A snapshot of the range extended timing protection counter value.
   * Needed to check inter arrival time. */
  Os_InterArrivalTimeType Snapshot;

  /*! A snapshot of the underlying counter value. */
  Os_TickType LastCounterValue;

  /*! The currently monitored thread. */
  P2CONST(Os_ThreadConfigType, TYPEDEF, OS_CONST) MonitoredThread;
};


/*! Data type for timing protection timer configuration. */
struct Os_TpConfigType_Tag
{
  /*! Pointer to timer hardware configuration. */
  P2CONST(Os_TimerHrtConfigType, TYPEDEF, OS_CONST) Timer;

  /*! Dynamic data of timing protection object. */
  P2VAR(Os_TpType, TYPEDEF, OS_VAR_NOINIT) Dyn;
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
 *  Os_TpThread2TpOwnerThread()
 **********************************************************************************************************************/
/*! \brief          Returns the monitored thread of a timing protected thread.
 *  \details        --no details--
 *
 *  \param[in]      TpThread    The TP thread to query. Parameter must not be NULL.
 *
 *  \return         Pointer to a monitored thread.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            TpThread is a TpOwnerThread.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_TpThread2TpOwnerThread,
(
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) TpThread
));


/***********************************************************************************************************************
 *  Os_TpGetCurrentTpOwnerThread()
 **********************************************************************************************************************/
/*! \brief          Returns the configuration of the currently monitored thread.
 *  \details        --no details--
 *
 *  \param[in]      Config    The timing protection configuration to query Parameter must not be NULL..
 *
 *  \return         Pointer to a monitored thread.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            OwnerThread is set.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TpGetCurrentTpOwnerThread,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpThreadInit()
 **********************************************************************************************************************/
/*! \brief        Initialize given timing protection settings.
 *  \details      Reset thread budgets to configured ones. The function is called in Init-Step3 for the idle task and
 *                for all threads in Init-Step4.
 *
 *  \param[in,out]  Config   The Timing protection configuration.
 *                           Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Current  Timing protection budgets.
 *                           Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          The timing protection of the owner core is initialized.
 *
 *  \trace        CREQ-49, CREQ-845
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpThreadInit,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current
));


/***********************************************************************************************************************
 *  Os_TpThreadKill()
 **********************************************************************************************************************/
/*! \brief        Reset timing protection settings.
 *  \details      Cancel all budget monitoring and reset budgets to configured values.
 *                The EarliestArrival is not modified.
 *
 *  \param[in,out]  Thread  Timing protection budgets.
 *                          Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          The timing protection of the owner core is initialized.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpThreadKill,
(
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Thread
));


/***********************************************************************************************************************
 *  Os_TpReducedInit()
 **********************************************************************************************************************/
/*! \brief        Performs reduced initialization of timing protection module.
 *  \details      This function enables to call the timing protection API. API calls have no effect before calling
 *                \ref Os_TpInit().
 *                This function is called in Init-Step2.
 *
 *  \param[in,out]  Config          The timing protection configuration of the current core.
 *                                  Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  InitialThread   The initial monitored thread.
 *                                  Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TpReducedInit
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_ThreadConfigType, TYPEDEF, OS_CONST) InitialThread
);


/***********************************************************************************************************************
 *  Os_TpInit()
 **********************************************************************************************************************/
/*! \brief        Initialize timing protection module and hardware timer.
 *  \details      This function is called in Init-Step3 and Init-Step4 in order to handle the situation that
 *                Init-Step3 is optional.
 *
 *  \param[in,out]  Config          The timing protection configuration of the current core.
 *                                  Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TpInit
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
);


/***********************************************************************************************************************
 *  Os_TpStart()
 **********************************************************************************************************************/
/*! \brief        Start the timing protection hardware timer.
 *  \details      --no details--
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_TpStart(void);


/***********************************************************************************************************************
 *  Os_TpResume()
 **********************************************************************************************************************/
/*! \brief        Let the timing protection interrupt occur in RemainingTime ticks.
 *  \details        --no details--
 *
 *  \param[in,out]  Config            The timing protection configuration of the current core.
 *                                    Parameter must not be NULL.
 *  \param[in]      Now               The current point in time.
 *  \param[in]      RemainingTime     The time of the next expiration relative to now. RemainingTime must be <=
 *                                    Config->Timer->Counter.CounterMaxAllowedValue.MaxAllowedValue.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpResume,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  Os_TickType Now,
  Os_TickType RemainingTime
));


/***********************************************************************************************************************
 *  Os_TpSuspend()
 **********************************************************************************************************************/
/*! \brief        Update the remaining time of the current thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Config            The timing protection configuration of the current core.
 *                                    Parameter must not be NULL.
 *  \param[in,out]  Current           Budgets of current thread.
 *                                    Parameter must not be NULL.
 *  \param[in]      Now               The current point in time.
 *  \param[in]      Deadline          The absolute deadline of the current budget.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpSuspend,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  Os_TickType Now,
  Os_TickType Deadline
));


/***********************************************************************************************************************
 *  Os_TpSub()
 **********************************************************************************************************************/
/*! \brief        Calculate the difference between Value and Sub.
 *  \details        --no details--
 *
 *  \param[in,out]  Config            The timing protection configuration of the current core.
 *                                    Parameter must not be NULL.
 *  \param[in]      Value             A timer value.
 *                                    Value has to be in range 0 <= Value <= MaxCountingValue.
 *  \param[in]      Sub               The counter value to be subtracted.
 *                                    Value has to be in range 0 <= Sub   <= MaxAllowedValue.
 *
 *  \return       The difference between Value and Sub.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TpSub,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  Os_TickType Value,
  Os_TickType Sub
));


/***********************************************************************************************************************
 *  Os_TpAdd()
 **********************************************************************************************************************/
/*! \brief        Calculate the sum of Value and Add.
 *  \details        --no details--
 *
 *  \param[in,out]  Config            The timing protection configuration of the current core.
 *                                    Parameter must not be NULL.
 *  \param[in]      Value             A timer value.
 *                                    Value has to be in range 0 <= Value <= MaxCountingValue.
 *  \param[in]      Add               The counter value to be added.
 *                                    Value has to be in range 0 <= Add   <= MaxAllowedValue.
 *
 *  \return       The sum of Value and Add.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_TpAdd,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  Os_TickType Value,
  Os_TickType Add
));


/***********************************************************************************************************************
 *  Os_TpGetArrivalTimeStamp()
 **********************************************************************************************************************/
/*! \brief        Returns the current time of the counter for inter-arrival time measurement.
 *  \details        --no details--
 *
 *  \param[in,out]  Config            The timing protection configuration of the current core.
 *                                    Parameter must not be NULL.
 *
 *  \return       Current The current time of the counter for inter-arrival time measurement.
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          Function has to be called at least one time in a hardware timer cycle.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_InterArrivalTimeType, OS_CODE,
OS_ALWAYS_INLINE, Os_TpGetArrivalTimeStamp,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpSwitch()
 **********************************************************************************************************************/
/*! \brief        Switch timing protection budgets.
 *  \details      Restore monitoring budgets of next thread.
 *                Preempt remaining time of currently monitored budget and store it into timing protection settings
 *                of current thread.
 *
 *  \param[in,out]  Config      The timing protection configuration of the current core.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Current     Budgets of current thread.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Next        Budgets of next thread.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in]      NextThread  The next thread to monitor.
 *                              Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          Given Current thread is an owner thread, if Next is an owner thread.
 *
 *  \trace        CREQ-49, CREQ-845
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpSwitch,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Next,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) NextThread
));


/***********************************************************************************************************************
 *  Os_TpResetAndResume()
 **********************************************************************************************************************/
/*! \brief        Reset timing protection budgets and resume given budgets.
 *  \details      Stops and resets the current execution budget. So when the budget is resumed the next time,
 *                the full time is available again. Resumes the execution and lock budget. Reprogram hardware timer.
 *
 *  \param[in,out]  Config      The timing protection configuration of the current core.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Current     Budgets of current thread.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Next        Budgets of next thread.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in]      NextThread  The next thread to monitor.
 *                              Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          Next and NextThread belong together.
 *
 *  \trace        CREQ-49, CREQ-845
 *  \trace        SPEC-64030, SPEC-64061
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpResetAndResume,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Next,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) NextThread
));


/***********************************************************************************************************************
 *  Os_TpResetAfterWait()
 **********************************************************************************************************************/
/*! \brief        Reset timing protection budgets and resume given budgets after leaving the wait state.
 *  \details      Stops and resets the current execution budget after a task leaves the WAITING state.
 *                Reprograms the hardware timer. see /ref Os_TaskWait().
 *
 *  \param[in,out]  Config      The timing protection configuration of the current core.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Current     Budgets of current thread.
 *                              Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *
 *  \trace        CREQ-49, CREQ-845
 *  \trace        SPEC-64030
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpResetAfterWait,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current
));


/***********************************************************************************************************************
 *  Os_TpCheckInterArrival()
 **********************************************************************************************************************/
/*! \brief        Check inter-arrival time, if violation detected report protection violation.
 *  \details      If an inter-arrival time violation is detected (OS_CHECK_FAILED), the protection hook is called.
 *                If there is no inter-arrival time violation (Not OS_CHECK_FAILED), the arrival time is recorded for
 *                the next time.
 *
 *  \param[in,out]  Config      The timing protection configuration of the current core.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  TpThread    The timing protection configuration to check.
 *                              Parameter must not be NULL if timing protection is enabled.
 *
 *  \retval       OS_CHECK_FAILED      Inter-arrival time violation.
 *  \retval       Not OS_CHECK_FAILED  Arrival allowed.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *
 *  \trace        CREQ-85, CREQ-846
 *  \trace        SPEC-63968, SPEC-64009, SPEC-63848, SPEC-63775, SPEC-63851, SPEC-64022, SPEC-63997
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_TpCheckInterArrival,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) TpThread
));


/***********************************************************************************************************************
 *  Os_TpUpdateViolation()
 **********************************************************************************************************************/
/*! \brief        Sets the current violation to the given violation, if the given violation has a higher priority than
 *                the current one.
 *  \details        --no details--
 *
 *  \param[in,out]  Current     Budgets of the current thread. Parameter must not be NULL.
 *  \param[in]      Violation   The violation to be be checked.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpUpdateViolation,
(
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  Os_TpMonitoringType Violation
));


/***********************************************************************************************************************
 *  Os_TpStartResource()
 **********************************************************************************************************************/
/*! \brief        Start locking time monitoring for given resource.
 *  \see          Os_TpBudgetStart()
 *  \details        --no details--
 *
 *  \param[in,out]  Config    The timing protection configuration of the current core.
 *                            Parameter must not be NULL if timing protection is enabled.
 *  \param[in]      Resource  Resource ID the locking time monitoring shall be started for.
 *                            Resource must be < OS_RESOURCEID_COUNT.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *
 *  \trace        CREQ-847, CREQ-31
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStartResource,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  ResourceType Resource
));


/***********************************************************************************************************************
 *  Os_TpGetResourceBudget()
 **********************************************************************************************************************/
/*! \brief        Return the lock budget of the given resource corresponding to the given thread.
 *  \details        --no details--
 *
 *  \param[in,out]  Current   Timing protection settings which shall be used. Parameter must not be NULL
 *  \param[in]      Resource  The ID of the resource. Resource must be < OS_RESOURCEID_COUNT.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TpBudgetConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_TpGetResourceBudget,
(
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  ResourceType Resource
));


/***********************************************************************************************************************
 *  Os_TpStopResource()
 **********************************************************************************************************************/
/*! \brief        Stop locking time monitoring for last occupied resource.
 *  \details        --no details--
 *  \see          Os_TpBudgetStop()
 *
 *  \param[in,out]  Config    The timing protection configuration of the current core.
 *                            Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  TpThread  The TP thread, which releases the resource.
 *                            Parameter must not be NULL if timing protection is enabled.
 *  \param[in]      Resource  Resource ID the locking time monitoring shall be stopped for.
 *                            Resource must be < OS_RESOURCEID_COUNT.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          The given TpThread is an owner thread.
 *
 *  \trace        CREQ-847, CREQ-31
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStopResource,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) TpThread,
  ResourceType Resource
));


/***********************************************************************************************************************
 *  Os_TpStartDelay()
 **********************************************************************************************************************/
/*! \brief        Tell the timing protection to delay timing protection reporting until call of Os_TpStopDelay().
 *  \details      Delay requests can be done multiple times.
 *
 *  \param[in,out]  Config   The timing protection of the current core.
 *                           Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *
 *  \trace        SPEC-64022, SPEC-63997
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStartDelay,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpStopDelay()
 **********************************************************************************************************************/
/*! \brief        Tell the timing protection that a delay request is done.
 *  \details        --no details--
 *
 *  \param[in,out]  Config   The timing protection of the current core.
 *                           Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          \ref Os_TpStartDelay() was at least called once more than \ref Os_TpStopDelay().
 *
 *  \trace        SPEC-64022, SPEC-63997
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStopDelay,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpStartAllInterrupt()
 **********************************************************************************************************************/
/*! \brief        Start locking time monitoring for "all-interrupt" lock.
 *  \details      Same behavior as in Os_TpLockingStartResource but for "all-interrupt" lock.
 *
 *  \param[in,out]  Config     The timing protection configuration of the current core.
 *                             Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-847, CREQ-31
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStartAllInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpStopAllInterrupt()
 **********************************************************************************************************************/
/*! \brief        Stop locking time monitoring for "all-interrupt" lock.
 *  \details      Same behavior as in Os_TpLockingStopResource but for "all-interrupt" lock.
 *
 *  \param[in,out]  Config     The timing protection configuration of the current core.
 *                             Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-847, CREQ-31
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStopAllInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpStartOsInterrupt()
 **********************************************************************************************************************/
/*! \brief        Start locking time monitoring for "OS-interrupt" lock.
 *  \details      Same behavior as in Os_TpLockingStartResource but for "OS-interrupt" lock.
 *
 *  \param[in,out]  Config     The timing protection configuration of the current core.
 *                             Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-847, CREQ-31
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStartOsInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpStopOsInterrupt()
 **********************************************************************************************************************/
/*! \brief        Stop locking time monitoring for "OS-interrupt" lock.
 *  \details      Same behavior as in Os_TpLockingStopResource but for "OS-interrupt" lock.
 *
 *  \param[in,out]  Config     The timing protection configuration of the current core.
 *                             Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          -
 *
 *  \trace        CREQ-847, CREQ-31
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpStopOsInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
));


/***********************************************************************************************************************
 *  Os_TpBudgetStart()
 **********************************************************************************************************************/
/*! \brief        Start monitoring given budget.
 *  \details      If there has been further monitoring on going before, the remaining budgets are compared
 *                and the smaller one is used to program the hardware timer.
 *
 *  \param[in,out]  Config     The timing protection configuration of the current core.
 *                             Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Current    Timing protection settings which shall be used.
 *                             Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Budget     Budget to monitor.
 *                             Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Current is the budget owner.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpBudgetStart,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpBudgetConfigType, AUTOMATIC, OS_CONST) Budget
));


/***********************************************************************************************************************
 *  Os_TpBudgetStop()
 **********************************************************************************************************************/
/*! \brief        Stop monitoring given budget.
 *  \details      If there has been further monitoring on going before, the previous monitoring is continued.
 *
 *  \param[in,out]  Config      The timing protection configuration of the current core.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Current     Timing protection settings which shall be used.
 *                              Parameter must not be NULL if timing protection is enabled.
 *  \param[in,out]  Budget      Budget to monitor.
 *                              Parameter must not be NULL if timing protection is enabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different objects.
 *  \synchronous  TRUE
 *
 *  \pre          Current is the budget owner.
 *  \pre          The given Budget is either not in the list or the Budget is on top of the list of monitored budgets.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_TpBudgetStop,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpBudgetConfigType, AUTOMATIC, OS_CONST) Budget
));


/***********************************************************************************************************************
 *  Os_TpIsEnabled()
 **********************************************************************************************************************/
/*! \brief        Returns whether Timing Protection is enabled (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval       !0  Timing Protection enabled.
 *  \retval       0   Timing Protection disabled.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_TpIsEnabled, (void));


/***********************************************************************************************************************
 *  ISR(Os_TpIsr)
 **********************************************************************************************************************/
/*! \brief        Timing protection ISR which handles timing protection violations.
 *  \details      This function handles execution time violations and locking time violations.
 *
 *  \context      ISR2|OS_INTERNAL
 *
 *  \reentrant    TRUE, for different timers.
 *  \synchronous  TRUE
 *
 *  \pre          Timer belongs to the local core.
 *
 *  \trace        CREQ-31, CREQ-845
 *  \trace        SPEC-63906, SPEC-63806, SPEC-63990, SPEC-63867, SPEC-64022, SPEC-63997
 **********************************************************************************************************************/
ISR(Os_TpIsr);



/***********************************************************************************************************************
 *  GLOBAL FUNCTION
 **********************************************************************************************************************/


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_TIMINGPROTECTIONINT_H */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_TimingProtectionInt.h
 **********************************************************************************************************************/
