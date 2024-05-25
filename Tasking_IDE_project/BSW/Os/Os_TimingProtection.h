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
 *  \addtogroup Os_TimingProtection
 *  \{
 *
 *  \file
 *  \brief          -
 *  \details        --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/


#ifndef OS_TIMINGPROTECTION_H
# define OS_TIMINGPROTECTION_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_TimingProtection_Lcfg.h"
# include "Os_TimingProtection_Cfg.h"
# include "Os_TimingProtection_Types.h"
# include "Os_TimingProtectionInt.h"

/* Os module dependencies */
# include "Os_Common.h"
# include "Os_Error.h"
# include "Os_Cfg.h"
# include "Os_Counter.h"
# include "Os_Timer.h"
# include "Os_Isr.h"
# include "Os_XSignalChannel.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Timer.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/

# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */

/***********************************************************************************************************************
 *  GLOBAL FUNCTION
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_TpThread2TpOwnerThread()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_TpThread2TpOwnerThread,
(
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) TpThread
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  Os_Assert((Os_StdReturnType)(TpThread->ThreadKind == OS_TPTHREADKIND_OWNER));                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  return (P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST))(TpThread);                                          /* PRQA S 0310, 3305 */ /* MD_Os_Rule11.3_0310, MD_Os_Rule11.3_3305 */
}


/***********************************************************************************************************************
 *  Os_TpGetCurrentTpOwnerThread()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_TpGetCurrentTpOwnerThread,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  return Os_TpThread2TpOwnerThread(Os_ThreadGetTpConfig(Config->Dyn->MonitoredThread));                                 /* SBSW_OS_TP_TPTHREAD2TPOWNERTHREAD_001 */ /* SBSW_OS_TP_THREADGETTPCONFIG_001 */
}


/***********************************************************************************************************************
 *  Os_TpThreadInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpThreadInit,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current
))
{
  /* #10 Call the internal initialization function if timing protection is enabled. */
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    FUNC(void, OS_CODE) Os_TpThreadInitInternal
    (
      P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
      P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current
    );

    Os_TpThreadInitInternal(Config, Current);                                                                           /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_TpThreadKill()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpThreadKill,
(
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Thread
))
{
  /* #10 Call the internal kill function if timing protection is enabled. */
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    FUNC(void, OS_CODE) Os_TpThreadKillInternal
    (
      P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Thread
    );

    Os_TpThreadKillInternal(Thread);                                                                                    /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_TpResume()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpResume,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  Os_TickType Now,
  Os_TickType RemainingTime
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  Os_TickType compareValue;

  /* #10 Set compare value of hardware timer to (now + RemainingTime) % maxCountingValue. */
  compareValue = Os_TpAdd(Config, Now, RemainingTime);                                                                  /* SBSW_OS_FC_PRECONDITION */
  Os_TimerHrtSetCompareValue(Config->Timer, compareValue);                                                              /* SBSW_OS_TP_TIMERHRTSETCOMPAREVALUE_001 */
}


/***********************************************************************************************************************
 *  Os_TpSuspend()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpSuspend,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  Os_TickType Now,
  Os_TickType Deadline
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  /* #10 If the deadline is in the future, store the remaining budget. */
  if(Os_CounterIsFutureValue(Os_TimerHrtGetCounter(Config->Timer), Deadline, Now) != 0u)                                /* SBSW_OS_TP_COUNTERISFUTUREVALUE_001 */ /* SBSW_OS_TP_TIMERHRTGETCOUNTER_001 */
  {
    Current->Dyn->MonitoredBudgets->Dyn->Remaining = Os_TpSub(Config, Deadline, Now);                                   /* SBSW_OS_TP_TPBUDGET_GETDYN_001 */ /* SBSW_OS_FC_PRECONDITION */
  }
  /* #20 Otherwise the remaining budget is 0. */
  else
  {
    Current->Dyn->MonitoredBudgets->Dyn->Remaining = 0;                                                                 /* SBSW_OS_TP_THREADGETTPCONFIG_001 */
  }
}


/***********************************************************************************************************************
 *  Os_TpSub()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpSub,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  Os_TickType Value,
  Os_TickType Sub
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) counter;
  Os_TickType maxCountingValue;

  counter = Os_TimerHrtGetCounter(Config->Timer);                                                                       /* SBSW_OS_TP_TIMERHRTGETCOUNTER_001 */

  maxCountingValue = Os_CounterGetMaxCountingValue(counter);                                                            /* SBSW_OS_TP_COUNTERGETMAXCOUNTINGVALUE_001 */

  /* #10 Calculate the difference. */
  return Os_TimerSub(maxCountingValue, Value, Sub);
}


/***********************************************************************************************************************
 *  Os_TpAdd()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpAdd,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  Os_TickType Value,
  Os_TickType Add
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) counter;
  Os_TickType maxAllowedValue;
  Os_TickType maxCountingValue;

  counter = Os_TimerHrtGetCounter(Config->Timer);                                                                       /* SBSW_OS_TP_TIMERHRTGETCOUNTER_001 */

  maxAllowedValue = Os_CounterGetMaxAllowedValue(counter);                                                              /* SBSW_OS_TP_COUNTERGETMAXALLOWEDVALUE_001 */
  maxCountingValue = Os_CounterGetMaxCountingValue(counter);                                                            /* SBSW_OS_TP_COUNTERGETMAXCOUNTINGVALUE_001 */

  /* #10 Calculate the sum. */
  return Os_TimerAdd(maxAllowedValue, maxCountingValue, Value, Add);
}


/***********************************************************************************************************************
 *  Os_TpGetArrivalTimeStamp()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_InterArrivalTimeType, OS_CODE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
OS_ALWAYS_INLINE, Os_TpGetArrivalTimeStamp,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  Os_TickType now;
  Os_TickType timePassed;

  /* #10 Get the current hardware counter value. */
  now = Os_TimerHrtGetValue(Config->Timer);                                                                             /* SBSW_OS_TP_TIMERHRTGETVALUE_001 */

  /* #20 Calculate how much time has passed, since the last read from the hardware. */
  timePassed = now - Config->Dyn->LastCounterValue;
  Config->Dyn->LastCounterValue = now;                                                                                  /* SBSW_OS_TP_TPGETDYN_001 */

  /* #30 Add this time to the current counter value and return it. */
  Config->Dyn->Snapshot += (Os_InterArrivalTimeType)timePassed;                                                         /* SBSW_OS_TP_TPGETDYN_001 */

  return Config->Dyn->Snapshot;
}


/***********************************************************************************************************************
 *  Os_TpSwitch()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpSwitch,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Next,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) NextThread
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    /* #10 If the next thread is a timing protection owner. */
    if(Next->ThreadKind == OS_TPTHREADKIND_OWNER)
    {
      P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) nextOwner;
      P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;
      Os_TickType now;
      Os_TickType deadline;

      /* It is expected that this function is never called to switch from a
       * Hook to a timing protected thread. */
      Os_Assert((Os_StdReturnType)(Current->ThreadKind == OS_TPTHREADKIND_OWNER));                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

      nextOwner = Os_TpThread2TpOwnerThread(Next);                                                                      /* SBSW_OS_FC_PRECONDITION */
      currentOwner = Os_TpThread2TpOwnerThread(Current);                                                                /* SBSW_OS_FC_PRECONDITION */

      deadline = Os_TimerHrtGetCompareValue(Config->Timer);                                                             /* SBSW_OS_TP_TIMERHRTGETCOMPAREVALUE_002 */
      now = Os_TimerHrtGetValue(Config->Timer);                                                                         /* SBSW_OS_TP_TIMERHRTGETVALUE_001 */

      /* If there is an execution budget, there has to be a monitored budget. */
      Os_Assert((Os_StdReturnType)                                                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
            (     (nextOwner->ExecutionBudget.BudgetKind == OS_TPMONITORINGTYPE_NONE)
              ||  (nextOwner->Dyn->MonitoredBudgets != NULL_PTR)));                                                     /* COV_OS_INVSTATE */

      Os_Assert((Os_StdReturnType)                                                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
            (     (currentOwner->ExecutionBudget.BudgetKind == OS_TPMONITORINGTYPE_NONE)
              ||  (currentOwner->Dyn->MonitoredBudgets != NULL_PTR)));                                                  /* COV_OS_INVSTATE */

      /* #20 If there are budgets monitored for next thread: */
      if(nextOwner->Dyn->MonitoredBudgets != NULL_PTR)
      {
        /* #30 Update the compare value. */
        Os_TpResume(Config, now, nextOwner->Dyn->MonitoredBudgets->Dyn->Remaining);                                     /* SBSW_OS_FC_PRECONDITION */
      }

      /* Otherwise keep the value as periodic interrupts are required. */

      /* #40 Update the monitored thread. */
      Config->Dyn->MonitoredThread = NextThread;                                                                        /* SBSW_OS_TP_TPGETDYN_001 */

      /* #50 If there are budgets monitored for current thread: */
      if(currentOwner->Dyn->MonitoredBudgets != NULL_PTR)
      {
        /* #60 Suspend the monitoring of the previous thread. */
        Os_TpSuspend(Config, currentOwner, now, deadline);                                                              /* SBSW_OS_TP_TPSUSPEND_001 */
      }
    }
    /*
     * else:
     *   The next thread inherits the timing protection settings of its predecessor.
     */
  }
}


/***********************************************************************************************************************
 *  Os_TpResetAndResume()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpResetAndResume,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Next,
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) NextThread
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    /* #10 If the next thread is an owner: */
    if(Next->ThreadKind == OS_TPTHREADKIND_OWNER)
    {
      P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;
      P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) nextOwner;

      currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                              /* SBSW_OS_FC_PRECONDITION */
      nextOwner = Os_TpThread2TpOwnerThread(Next);                                                                      /* SBSW_OS_FC_PRECONDITION */

      /* #20 If the monitored thread changes or the same thread is restarted: */
      if ((currentOwner != nextOwner) || (Current == Next))
      {
        /* #30 If the current thread is a budget owner. */
        if(Current->ThreadKind == OS_TPTHREADKIND_OWNER)
        {
          /* Check that current is the currently monitored owner. */
          Os_Assert((Os_StdReturnType)(Os_TpThread2TpOwnerThread(Current) == currentOwner));                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */

          /* #40 If there are budgets monitored for current thread: */
          if(currentOwner->Dyn->MonitoredBudgets != NULL_PTR)
          {
            /* Check that this is the execution budget. */
            Os_Assert((Os_StdReturnType)(currentOwner->Dyn->MonitoredBudgets == &currentOwner->ExecutionBudget));       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

            /* #50 Reset monitored budget. */
            currentOwner->Dyn->MonitoredBudgets->Dyn->Remaining = currentOwner->Dyn->MonitoredBudgets->Budget;          /* SBSW_OS_TP_TPBUDGET_GETDYN_003 */
          }
        }

        /* #60 Resume the next thread. */
        if(nextOwner->Dyn->MonitoredBudgets != NULL_PTR)
        {
          Os_TickType now;

          now = Os_TimerHrtGetValue(Config->Timer);                                                                     /* SBSW_OS_TP_TIMERHRTGETVALUE_001 */
          Os_TpResume(Config, now, nextOwner->Dyn->MonitoredBudgets->Dyn->Remaining);                                   /* SBSW_OS_FC_PRECONDITION */
        }

        Config->Dyn->MonitoredThread = NextThread;                                                                      /* SBSW_OS_TP_TPGETDYN_001 */
      }
    }
  }
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_TpResetAfterWait()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpResetAfterWait,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) Current
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                             /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    /* #10 If the current thread is an owner: */
    if(Current->ThreadKind == OS_TPTHREADKIND_OWNER)
    {
      P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

      currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                              /* SBSW_OS_FC_PRECONDITION */

      /* Check that current is the currently monitored owner. */
      Os_Assert((Os_StdReturnType)(Os_TpThread2TpOwnerThread(Current) == currentOwner));                                /* SBSW_OS_FC_PRECONDITION */ /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

      /* #20 If there are budgets monitored for current thread: */
      if(currentOwner->Dyn->MonitoredBudgets != NULL_PTR)
      {
        /* Check that this is the execution budget. */
        Os_Assert((Os_StdReturnType)(currentOwner->Dyn->MonitoredBudgets == &currentOwner->ExecutionBudget));           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

        /* #30 If the current thread has remaining execution budget: */
        if(currentOwner->Dyn->MonitoredBudgets->Dyn->Remaining > 0u)
        {
          Os_TickType now;
          
          /* #40 Reset the monitored budget. */
          currentOwner->Dyn->MonitoredBudgets->Dyn->Remaining = currentOwner->Dyn->MonitoredBudgets->Budget;            /* SBSW_OS_TP_TPBUDGET_GETDYN_003 */

          /* #50 Update the timing protection. */
          now = Os_TimerHrtGetValue(Config->Timer);                                                                     /* SBSW_OS_TP_TIMERHRTGETVALUE_001 */
          Os_TpResume(Config, now, currentOwner->Dyn->MonitoredBudgets->Dyn->Remaining);                                /* SBSW_OS_FC_PRECONDITION */
        }
      }
    }
  }
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_TpCheckInterArrival()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpCheckInterArrival,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) TpThread
))
{
  Os_StdReturnType status;

  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    if(OS_LIKELY(TpThread->ThreadKind == OS_TPTHREADKIND_OWNER))
    {
      P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) tpThreadOwner;

      tpThreadOwner = Os_TpThread2TpOwnerThread(TpThread);                                                              /* SBSW_OS_FC_PRECONDITION */

      /* #10 If inter-arrival time shall be monitored: */
      if(tpThreadOwner->TimeFrame != 0u)
      {
        Os_InterArrivalTimeType now;
        Os_IntStateType interruptState;

        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        /* #20 Get current time stamp. */
        now = Os_TpGetArrivalTimeStamp(Config);                                                                         /* SBSW_OS_FC_PRECONDITION */

        /* #30 If earliest arrival time has not yet been reached: */
        if(tpThreadOwner->Dyn->EarliestArrival > now)
        {
          /* #40 Report protection error. This may lead to shutdown. */
          Os_ErrProtectionError(OS_STATUS_PROTECTION_ARRIVAL);

          status = OS_CHECK_FAILED;
          /* No new earliest arrival needs to be computed as the current arrival was not successful. */
        }
        /* #50 else */
        else
        {
          /* #60 Calculate next earliest arrival. */
          tpThreadOwner->Dyn->EarliestArrival = now + tpThreadOwner->TimeFrame;                                         /* SBSW_OS_TP_TPUPDATEVIOLATION_001 */

          status = !OS_CHECK_FAILED;                                                                                    /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
        }

        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      else
      {
        status = !OS_CHECK_FAILED;                                                                                      /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
      }
    }
    else
    {
      status = !OS_CHECK_FAILED;                                                                                        /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
    }
  }
  else
  {
    status = !OS_CHECK_FAILED;                                                                                          /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_TpUpdateViolation()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpUpdateViolation,
(
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  Os_TpMonitoringType Violation
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  static CONST(uint8, OS_CONST) Os_TpMonitorPriority[OS_TPMONITORINGTYPE_COUNT] =
  {
    /* OS_TPMONITORINGTYPE_NONE       */ 0,
    /* OS_TPMONITORINGTYPE_LOCK       */ 2,
    /* OS_TPMONITORINGTYPE_EXECUTION  */ 2,
    /* OS_TPMONITORINGTYPE_ARRIVAL    */ 1
  };

  /* #10 If the given violation has a higher priority: */
  if(Os_TpMonitorPriority[Violation] > Os_TpMonitorPriority[Current->Dyn->Violation])                                   /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
  {
    /* #20 Update the current violation. */
    Current->Dyn->Violation = Violation;                                                                                /* SBSW_OS_TP_TPGETDYN_001 */
  }
}


/***********************************************************************************************************************
 *  Os_TpGetResourceBudget()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
P2CONST(Os_TpBudgetConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_TpGetResourceBudget,
(
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  ResourceType Resource
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  Os_Assert(Os_ErrIsValueLo((uint32)Resource, (uint32)OS_RESOURCEID_COUNT));

  return (Current->ResourceLockBudgets[Resource]);
}


/***********************************************************************************************************************
 *  Os_TpStartResource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpStartResource,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  ResourceType Resource
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    P2CONST(Os_TpBudgetConfigType, TYPEDEF, OS_CONST) resourceBudget;
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    resourceBudget = Os_TpGetResourceBudget(currentOwner, Resource);                                                    /* SBSW_OS_TP_TPGETRESOURCEBUDGET_001 */

    /* #10 If there is a locking budget for the given resource: */
    if(resourceBudget != NULL_PTR)
    {
      /* #20 Start monitoring the locking budget. */
      Os_TpBudgetStart(Config, currentOwner, resourceBudget);                                                           /* SBSW_OS_TP_TPBUDGETSTART_001 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpStopResource()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpStopResource,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpThreadConfigType, AUTOMATIC, OS_CONST) TpThread,
  ResourceType Resource
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    P2CONST(Os_TpBudgetConfigType, TYPEDEF, OS_CONST) resourceBudget;
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpThread2TpOwnerThread(TpThread);                                                                 /* SBSW_OS_FC_PRECONDITION */

    resourceBudget = Os_TpGetResourceBudget(currentOwner, Resource);                                                    /* SBSW_OS_TP_TPGETRESOURCEBUDGET_001 */

    /* #10 If there is a locking budget for the given resource: */
    if(resourceBudget != NULL_PTR)
    {
      /* #20 Stop monitoring the locking budget. */
      /* List consistency is ensured by design and verified by unit test -> Precondition fulfilled. */
      Os_TpBudgetStop(Config, currentOwner, resourceBudget);                                                            /* SBSW_OS_TP_TPBUDGETSTOP_001 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpStartDelay()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpStartDelay,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  if(Os_TpIsEnabled() != 0u)
  {
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #10 Increment the number of delay requests. */
    currentOwner->Dyn->DelayLevel++;                                                                                    /* SBSW_OS_TP_TPTHREADGETDYN_002 */
    Os_Assert((Os_StdReturnType)(currentOwner->Dyn->DelayLevel != 0u));                                                 /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  }
}


/***********************************************************************************************************************
 *  Os_TpStopDelay()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpStopDelay,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  if(Os_TpIsEnabled() != 0u)
  {
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    Os_Assert((Os_StdReturnType)(currentOwner->Dyn->DelayLevel != 0u));                                                 /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

    /* #10 Decrement the number of delay requests. */
    currentOwner->Dyn->DelayLevel--;                                                                                    /* SBSW_OS_TP_TPTHREADGETDYN_002 */

    /* #20 If the number of pending delay requests has reached zero */
    if (currentOwner->Dyn->DelayLevel == 0u)
    {
      /* #30 Report an error if one has been stored for the current TP owner thread. */
      if(OS_UNLIKELY(currentOwner->Dyn->Violation != OS_TPMONITORINGTYPE_NONE))
      {
        switch(currentOwner->Dyn->Violation)
        {
          case OS_TPMONITORINGTYPE_LOCK:
            Os_ErrProtectionError(OS_STATUS_PROTECTION_LOCKED);
            Os_ErrKernelPanic();
            break;

          case OS_TPMONITORINGTYPE_EXECUTION:
            Os_ErrProtectionError(OS_STATUS_PROTECTION_TIME);
            Os_ErrKernelPanic();
            break;

          default:                                                                                                      /* COV_OS_INVSTATE */
            Os_ErrKernelPanic();
            break;
        }
      }
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpStartAllInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpStartAllInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #10 If there is a locking budget for the "all-interrupt" lock: */
    if(currentOwner->AllInterruptLockBudget.BudgetKind != OS_TPMONITORINGTYPE_NONE)
    {
      /* #20 Start monitoring the locking budget. */
      Os_TpBudgetStart(Config, currentOwner, &(currentOwner->AllInterruptLockBudget));                                  /* SBSW_OS_TP_TPBUDGETSTART_002 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpStopAllInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpStopAllInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #10 If there is a locking budget for the "all-interrupt" lock: */
    if(currentOwner->AllInterruptLockBudget.BudgetKind != OS_TPMONITORINGTYPE_NONE)
    {
      /* #20 Stop monitoring the locking budget. */
      /* List consistency is ensured by design and verified by unit test -> Precondition fulfilled. */
      Os_TpBudgetStop(Config, currentOwner, &(currentOwner->AllInterruptLockBudget));                                   /* SBSW_OS_TP_TPBUDGETSTOP_002 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpStartOsInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpStartOsInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #10 If there is a locking budget for the "OS-interrupt" lock: */
    if(currentOwner->OsInterruptLockBudget.BudgetKind != OS_TPMONITORINGTYPE_NONE)
    {
      /* #20 Start monitoring the locking budget. */
      Os_TpBudgetStart(Config, currentOwner, &(currentOwner->OsInterruptLockBudget));                                   /* SBSW_OS_TP_TPBUDGETSTART_002 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpStopOsInterrupt()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TpStopOsInterrupt,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config
))
{
  if(Os_TpIsEnabled() != 0u)                                                                                            /* COV_OS_HALPLATFORMTPUNSUPPORTED_XF */
  {
    P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) currentOwner;

    currentOwner = Os_TpGetCurrentTpOwnerThread(Config);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #10 If there is a locking budget for the "OS-interrupt" lock: */
    if(currentOwner->OsInterruptLockBudget.BudgetKind != OS_TPMONITORINGTYPE_NONE)
    {
      /* #20 Stop monitoring the locking budget. */
      /* List consistency is ensured by design and verified by unit test -> Precondition fulfilled. */
      Os_TpBudgetStop(Config, currentOwner, &(currentOwner->OsInterruptLockBudget));                                    /* SBSW_OS_TP_TPBUDGETSTOP_002 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_TpBudgetStart()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpBudgetStart,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpBudgetConfigType, AUTOMATIC, OS_CONST) Budget
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  if(Os_TpIsEnabled() != 0u)
  {
    Os_TickType now;
    Os_TickType remainingTime;
    Os_IntStateType interruptState;

    /* #10 Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    now = Os_TimerHrtGetValue(Config->Timer);                                                                           /* SBSW_OS_TP_TIMERHRTGETVALUE_001 */

    /* #20 If there is currently a budget monitored: */
    if(Current->Dyn->MonitoredBudgets != NULL_PTR)
    {
      Os_TickType deadline;

      /* #30 Calculate remaining time of the currently monitored budget. */
      deadline = Os_TimerHrtGetCompareValue(Config->Timer);                                                             /* SBSW_OS_TP_TIMERHRTGETCOMPAREVALUE_002 */

      remainingTime = Os_TpSub(Config, deadline, now);                                                                  /* SBSW_OS_FC_PRECONDITION */

      /* #40 If the budget is lower than the remaining time of the currently monitored budget: */
      if(Budget->Budget < remainingTime)
      {
        /* #50 Save current remaining time in current budget. */
        Current->Dyn->MonitoredBudgets->Dyn->Remaining = remainingTime;                                                 /* SBSW_OS_TP_TPBUDGET_GETDYN_001 */

        /* #60 Push the budget to the list of currently monitored budgets. */
        Budget->Dyn->Previous = Current->Dyn->MonitoredBudgets;                                                         /* SBSW_OS_TP_TPBUDGET_GETDYN_002 */
        Current->Dyn->MonitoredBudgets = Budget;                                                                        /* SBSW_OS_TP_TPTHREADGETDYN_002 */

        /* #70 Set compare value of hardware timer according to budget. */
        Os_TpResume(Config, now, Budget->Budget);                                                                       /* SBSW_OS_FC_PRECONDITION */
      }
    }
    /* #80 Otherwise: */
    else
    {
      /* #90 Push the budget to the list of currently monitored budgets. */
      Budget->Dyn->Previous = Current->Dyn->MonitoredBudgets;                                                           /* SBSW_OS_TP_TPBUDGET_GETDYN_002 */
      Current->Dyn->MonitoredBudgets = Budget;                                                                          /* SBSW_OS_TP_TPTHREADGETDYN_002 */

      /* #100 Set compare value of hardware timer according to budget. */
      Os_TpResume(Config, now, Budget->Budget);                                                                         /* SBSW_OS_FC_PRECONDITION */
    }

    /* #110 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_TpBudgetStop()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TpBudgetStop,
(
  P2CONST(Os_TpConfigType, AUTOMATIC, OS_CONST) Config,
  P2CONST(Os_TpOwnerThreadConfigType, AUTOMATIC, OS_CONST) Current,
  P2CONST(Os_TpBudgetConfigType, AUTOMATIC, OS_CONST) Budget
))                                                                                                                      /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  if(Os_TpIsEnabled() != 0u)
  {
    Os_IntStateType interruptState;

    /* #10 Suspend interrupts. */
    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    /* #20 If the budget is currently monitored: */
    if(Budget == Current->Dyn->MonitoredBudgets)
    {

      /* #30 Pop the budget from the list of currently monitored budgets. */
      Current->Dyn->MonitoredBudgets = Current->Dyn->MonitoredBudgets->Dyn->Previous;                                   /* SBSW_OS_TP_TPBUDGET_GETDYN_001 */


      /* #40 If there is a previous budget: */
      if(Current->Dyn->MonitoredBudgets != NULL_PTR)
      {
        Os_TickType now;
        Os_TickType remainingTimeNext;
        Os_TickType deadline;
        Os_TickType startTime;
        Os_TickType consumedTimeCurrent;

        /* #50 Calculate the consumed time for the currently monitored budget. */
        now = Os_TimerHrtGetValue(Config->Timer);                                                                       /* SBSW_OS_TP_TIMERHRTGETVALUE_001 */
        deadline = Os_TimerHrtGetCompareValue(Config->Timer);                                                           /* SBSW_OS_TP_TIMERHRTGETCOMPAREVALUE_002 */
        startTime = Os_TpSub(Config, deadline, Budget->Budget);                                                         /* SBSW_OS_FC_PRECONDITION */
        consumedTimeCurrent = Os_TpSub(Config, now, startTime);                                                         /* SBSW_OS_FC_PRECONDITION */


        /* #60 If the remaining time of the previous budget is bigger than the consumed time (likely): */
        if(OS_LIKELY(Current->Dyn->MonitoredBudgets->Dyn->Remaining > consumedTimeCurrent))                             /* COV_OS_NOFUNCCALL */
        {
          /* #70 Reduce remaining time by consumed time. */
          remainingTimeNext = Current->Dyn->MonitoredBudgets->Dyn->Remaining - consumedTimeCurrent;
        }
        /* #80 Else: Remaining time is zero. */
        else
        {
          remainingTimeNext = 0;
        }
        /* #90 Resume the previous budget with above calculated remaining time. */
        Os_TpResume(Config, now, remainingTimeNext);                                                                    /* SBSW_OS_FC_PRECONDITION */
      }
    }

    /* #100 Resume interrupts. */
    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
}


/***********************************************************************************************************************
 *  Os_TpIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_TpIsEnabled, (void))
{
  return (Os_StdReturnType)(OS_CFG_TIMING_PROTECTION == STD_ON);                                                        /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_TIMINGPROTECTIONINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_TimingProtectionInt.h
 **********************************************************************************************************************/
