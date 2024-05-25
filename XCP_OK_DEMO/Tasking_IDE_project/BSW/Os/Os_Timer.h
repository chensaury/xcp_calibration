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
 * \addtogroup Os_Timer
 *
 * \{
 *
 * \file
 * \brief       Interface implementation to high level timer hardware handling.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_TIMER_H
# define OS_TIMER_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_TimerInt.h"

/* Os kernel module dependencies */
# include "Os_Common.h"
# include "Os_Counter.h"
# include "Os_Isr.h"

/* Os HAL dependencies */
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

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_TimerSwInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerSwInit,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
))
{
  Timer->Dyn->Value = 0;                                                                                                /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Timer->Dyn->Compare = 0;                                                                                              /* SBSW_OS_TIMER_TIMERGETDYN_001 */

  /* Check that macro and configuration are consistent. */
  Os_Assert((Os_StdReturnType)( Timer->Counter.Characteristics.MaxCountingValue                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
          == OS_TIMERSW_GETMAXCOUNTINGVALUE((Os_TickType)Timer->Counter.Characteristics.MaxAllowedValue)));

  Os_Assert((Os_StdReturnType)( Timer->Counter.Characteristics.MaxDifferentialValue                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
          == OS_TIMERSW_GETMAXDIFFERENTIALVALUE((Os_TickType)Timer->Counter.Characteristics.MaxAllowedValue)));
}


/***********************************************************************************************************************
 *  Os_TimerPitInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPitInit,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  Os_TimerSwInit(&(Timer->SwCounter));                                                                                  /* SBSW_OS_FC_PRECONDITION */

  /* Check that macro and configuration are consistent. */
  Os_Assert((Os_StdReturnType)( Timer->SwCounter.Counter.Characteristics.MaxCountingValue                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
      == OS_TIMERPIT_GETMAXCOUNTINGVALUE((Os_TickType)Timer->SwCounter.Counter.Characteristics.MaxAllowedValue)));

  Os_Assert((Os_StdReturnType)( Timer->SwCounter.Counter.Characteristics.MaxDifferentialValue                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
      == OS_TIMERPIT_GETMAXDIFFERENTIALVALUE((Os_TickType)Timer->SwCounter.Counter.Characteristics.MaxAllowedValue)));

}


/***********************************************************************************************************************
 *  Os_TimerHrtInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TimerHrtInit,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Timer->Dyn->Value = 0;                                                                                                /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Timer->Dyn->LastCounterValue = 0;                                                                                     /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Timer->Dyn->Compare = 0;                                                                                              /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Timer->Dyn->ValueMask = 0;                                                                                            /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Timer->Dyn->HwTimeAtLogicalZero = 0;                                                                                  /* SBSW_OS_TIMER_TIMERGETDYN_001 */

  /* Check that macro and configuration are consistent. */
  Os_Assert((Os_StdReturnType)( Timer->Counter.Characteristics.MaxCountingValue                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
          == OS_TIMERHRT_GETMAXCOUNTINGVALUE((Os_TickType)Timer->Counter.Characteristics.MaxAllowedValue)));

  Os_Assert((Os_StdReturnType)( Timer->Counter.Characteristics.MaxDifferentialValue                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
          == OS_TIMERHRT_GETMAXDIFFERENTIALVALUE((Os_TickType)Timer->Counter.Characteristics.MaxAllowedValue)));
}


/***********************************************************************************************************************
 *  Os_TimerPfrtInit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPfrtInit,
(
  P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  Os_TimerSwInit(&(Timer->SwCounter));                                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerSwStart()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerSwStart,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
))
{
  /* Nothing to be done for software counter, as there is no underlying hardware. */
  OS_IGNORE_UNREF_PARAM(Timer);                                                                                         /* PRQA S 3112 */ /* MD_Os_3112 */
}


/***********************************************************************************************************************
 *  Os_TimerPitStart()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPitStart,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  Os_Hal_TimerPitInit(Timer->HwConfig);                                                                                 /* SBSW_OS_TIMER_HAL_TIMERPITINIT_001 */
}


/***********************************************************************************************************************
 *  Os_TimerHrtStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */ /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerHrtStart,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Os_Hal_TimerFrtTickType timeZero;

  /* #10 Initialize (start) the FRT timer. */
  Os_Hal_TimerFrtInit(Timer->HwConfig);                                                                                 /* SBSW_OS_TIMER_HAL_TIMERFRTINIT_001 */

  timeZero = Os_Hal_TimerFrtGetCounterValue(Timer->HwConfig);                                                           /* SBSW_OS_TIMER_HAL_TIMERFRTGETCOUNTERVALUE_001 */
  Timer->Dyn->HwTimeAtLogicalZero = timeZero;                                                                           /* SBSW_OS_TIMER_TIMERGETDYN_001 */

  /* #20 Correct the timer data (to support the case of FRT start by reset). */
  Timer->Dyn->ValueMask = Timer->Counter.Characteristics.MaxCountingValue;        /* allow timer Value to increase. */  /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Timer->Dyn->LastCounterValue = timeZero;                                        /* store current counter value.   */  /* SBSW_OS_TIMER_TIMERGETDYN_001 */
  Os_TimerHrtSetCompareValue(Timer, Timer->Dyn->Compare);                         /* set the initial compare value. */  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerSwGetValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerSwGetValue,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer
))
{
  return Timer->Dyn->Value;
}


/***********************************************************************************************************************
 *  Os_TimerSwSetCompareValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TimerSwSetCompareValue,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
))
{
  Timer->Dyn->Compare = ExpirationTime;                                                                                 /* SBSW_OS_TIMER_TIMERGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_TimerSwUserModulo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerSwUserModulo,
(
  P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
))
{
  Os_TickType result = Value;

  /* #10 Subtract one user cycle if Value exceeds the MaxAllowedValue. */
  if(Value > Timer->Counter.Characteristics.MaxAllowedValue)
  {
    result -= (Timer->Counter.Characteristics.MaxAllowedValue + (Os_TickType)1);
  }

  /* Check that the calculated value is in a valid range (0 <= Value <= MaxAllowedValue). */
  Os_Assert((Os_StdReturnType)(result <= Timer->Counter.Characteristics.MaxAllowedValue));                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  return result;
}



/***********************************************************************************************************************
 *  Os_TimerPitGetValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPitGetValue,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  return Os_TimerSwGetValue(&(Timer->SwCounter));                                                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerPitSetCompareValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TimerPitSetCompareValue,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  Os_TimerSwSetCompareValue(&(Timer->SwCounter), ExpirationTime);                                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerPitUserModulo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPitUserModulo,
(
  P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  return Os_TimerSwUserModulo(&(Timer->SwCounter), Value);                                                              /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerPfrtUserModulo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPfrtUserModulo,
(
  P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  return Os_TimerSwUserModulo(&(Timer->SwCounter), Value);                                                              /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerHrtGetCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_TimerHrtGetCounter,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  return &(Timer->Counter);
}


/***********************************************************************************************************************
 *  Os_TimerHrtTickType2FrtTickType()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_Hal_TimerFrtTickType, OS_CODE, OS_ALWAYS_INLINE, Os_TimerHrtTickType2FrtTickType,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer,
  TickType Value
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  /*! Internal comment removed.
 *
 * */
  return (Timer->Dyn->HwTimeAtLogicalZero + (Os_Hal_TimerFrtTickType)Value);
}


/***********************************************************************************************************************
 *  Os_TimerHrtSetCompareValue()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_TimerHrtSetCompareValue,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Os_TickType now;

  /* #10 Store the ExpirationTime for the case that the compare difference does not fit into the hardware part
   *     of the counter. */
  Timer->Dyn->Compare = ExpirationTime;                                                                                 /* SBSW_OS_TIMER_TIMERGETDYN_001 */

  /* #20 Set the compare value. */
  Os_Hal_TimerFrtSetCompareValue(Timer->HwConfig, Os_TimerHrtTickType2FrtTickType(Timer, ExpirationTime));              /* SBSW_OS_TIMER_HAL_TIMERFRTSETCOMPAREVALUE_001 */ /* SBSW_OS_FC_PRECONDITION */

  /* #30 Check whether the ExpirationTime is already reached. */
  now = Os_TimerHrtGetValue(Timer);                                                                                     /* SBSW_OS_FC_PRECONDITION */

  /* #40 If new compare value is already in the past or now: */
  if(OS_UNLIKELY(Os_CounterIsFutureValue(&(Timer->Counter), ExpirationTime, now) == 0u))                                /* SBSW_OS_FC_PRECONDITION */
  {
    /* #50 If the platform supports peripheral interrupt trigger: */
    if (Os_Hal_IntIsPeripheralInterruptTriggerSupported() != 0u)                                                        /* COV_OS_HALPLATFORMPERIPHERALINTTRIGGERSUPPORTED */
    {
      /* #60 Trigger interrupt, so the violation is handled after the thread switch is completed. */
      Os_Hal_TimerFrtTriggerIrq(Timer->HwConfig);                                                                       /* SBSW_OS_TIMER_HAL_TIMERFRTTRIGGERIRQ_001 */
    }
    else
    {
      Os_TickType iterationId;
      Os_TickType delta;
      Os_TickType compareValue;
      Os_TickType timeBeforeSetCompare;
      Os_TickType timeAfterSetCompare;
      delta = 0;
      iterationId = 1;
      do
      {
        /* #70 Else read the current counter value from hardware timer. */
        timeBeforeSetCompare = Os_Hal_TimerFrtGetCounterValue(Timer->HwConfig);                                         /* SBSW_OS_TIMER_HAL_TIMERFRTGETCOUNTERVALUE_001 */

        /* #80 Set the compare value to the previously read counter value plus delay. */
        compareValue = timeBeforeSetCompare + delta + iterationId;
        Os_Hal_TimerFrtSetCompareValue(Timer->HwConfig, compareValue);                                                  /* SBSW_OS_TIMER_HAL_TIMERFRTSETCOMPAREVALUE_001 */

        /* #90 Read again the current hardware counter value and update the delay, taking into
               account the counter values difference and the loop iteration count. */
        timeAfterSetCompare = Os_Hal_TimerFrtGetCounterValue(Timer->HwConfig);                                          /* SBSW_OS_TIMER_HAL_TIMERFRTGETCOUNTERVALUE_001 */
        delta = timeAfterSetCompare - timeBeforeSetCompare;
        iterationId++;

      /* #100 Loop while compare value is in the past or now with respect to the last read counter value. */
      }while (OS_UNLIKELY(Os_CounterIsFutureValue(&(Timer->Counter), compareValue, timeAfterSetCompare) == 0u));        /* SBSW_OS_FC_PRECONDITION */

    }
  }
}


/***********************************************************************************************************************
 *  Os_TimerPfrtSetCompareValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPfrtSetCompareValue,
(
  P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType ExpirationTime
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  /* #10 Use function of software timer. */
  Os_TimerSwSetCompareValue(&(Timer->SwCounter), ExpirationTime);                                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerHrtGetCompareValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
Os_TimerHrtGetCompareValue,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */ /* COV_OS_HALPLATFORMTPUNSUPPORTED_XX */
{
  return Timer->Dyn->Compare;
}


/***********************************************************************************************************************
 *  Os_TimerHrtAcknowledge()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TimerHrtAcknowledge,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Os_Hal_TimerFrtAcknowledge(Timer->HwConfig);                                                                          /* SBSW_OS_TIMER_HAL_TIMERFRTACKNOWLEDGE_001 */
}


/***********************************************************************************************************************
 *  Os_TimerHrtUserModulo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TimerHrtUserModulo,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer,
  Os_TickType Value
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  return (Value & Timer->Counter.Characteristics.MaxAllowedValue);
}



/***********************************************************************************************************************
 *  Os_TimerHrtGetValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TimerHrtGetValue,
(
  P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Os_TickType now;
  Os_TickType timePassed;

  /* #10 Get the current hardware counter value. */
  now = (Os_TickType)Os_Hal_TimerFrtGetCounterValue(Timer->HwConfig) & (Timer->Dyn->ValueMask);                         /* SBSW_OS_TIMER_HAL_TIMERFRTGETCOUNTERVALUE_001 */

  /* #20 Calculate how much time has passed, since we have read from the hardware the last time. */
  timePassed = (now - Timer->Dyn->LastCounterValue);
  Timer->Dyn->LastCounterValue = now;                                                                                   /* SBSW_OS_TIMER_TIMERGETDYN_001 */

  /* #30 Add this time to the current counter value and return it. */
  Timer->Dyn->Value += timePassed;                                                                                      /* SBSW_OS_TIMER_TIMERGETDYN_001 */

  return Timer->Dyn->Value;
}


/***********************************************************************************************************************
 *  Os_TimerPfrtGetValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPfrtGetValue,
(
  P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST) Timer
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  return Os_TimerSwGetValue(&(Timer->SwCounter));                                                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_TimerSwAbsCounter2AbsTimerValue()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerSwAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType Now,
  Os_TickType CounterValue
))
{
  Os_TickType timerValue;
  Os_TickType timerFirstCycle;
  Os_TickType timerSecondCycle;

  timerFirstCycle = CounterValue;
  timerSecondCycle = CounterValue + MaxAllowedValue + (uint32)1;

  /* #10 If CounterValue is bigger than Now (implies that Now is in the first cycle). */
  if(CounterValue > Now)
  {
    /* #20 Set return value to CounterValue, the expiration time will be reached within the first cycle. */
    timerValue = timerFirstCycle;
  }
  /* #30 Else if CounterValue+MaxallowedValue+1 is bigger than Now (Now may be in first or second cycle). */
  else if(timerSecondCycle > Now)
  {
    /*#40 Set return value to CounterValue+MaxallowedValue+1, the expiration time will be reached in the second cycle.*/
    timerValue = timerSecondCycle;
  }
  /* #50 Else (Now is in the second cycle) */
  else
  {
    /* #60 Set return value to CounterValue, the expiration time will be reached in the first cycle. */
    timerValue = timerFirstCycle;
  }

  return timerValue;
}


/***********************************************************************************************************************
 *  Os_TimerPitAbsCounter2AbsTimerValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPitAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType Now,
  Os_TickType CounterValue
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  return Os_TimerSwAbsCounter2AbsTimerValue(MaxAllowedValue, Now, CounterValue);
}


/***********************************************************************************************************************
 *  Os_TimerHrtAbsCounter2AbsTimerValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TimerHrtAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType MaxCountingValue,
  Os_TickType Now,
  Os_TickType CounterValue
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Os_TickType timerValue;

  /* #10 Take the upper bits from the timer (Now) and the lower bits from the CounterValue. */
  timerValue = (Now & (~(MaxAllowedValue))) + CounterValue;

  /* #20 If this time stamp is already in the past or now, take the next cycle. */
  if(timerValue <= Now)
  {
    timerValue += (MaxAllowedValue + (uint32)1);
  }

  return (timerValue & MaxCountingValue);
}


/***********************************************************************************************************************
 *  Os_TimerPfrtAbsCounter2AbsTimerValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerPfrtAbsCounter2AbsTimerValue,
(
  Os_TickType MaxAllowedValue,
  Os_TickType Now,
  Os_TickType CounterValue
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  /* #10 Convert values based on software timer implementation. */
  return Os_TimerSwAbsCounter2AbsTimerValue(MaxAllowedValue, Now, CounterValue);
}


/***********************************************************************************************************************
 *  Os_TimerAdd()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_TimerAdd,
(
  Os_TickType MaxAllowedValue,
  Os_TickType MaxCountingValue,
  Os_TickType Value,
  Os_TickType Add
))
{
  Os_TickType result;

# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
/* This suppresses the warning regard to "condition always true". This can be suppressed,
 * since this is just error assertion
 */
#  pragma warning 549                                                                                                   /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif

  Os_Assert((Os_StdReturnType)(Value <= MaxCountingValue));                                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(Add <=  MaxAllowedValue));                                                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
#  pragma warning restore                                                                                               /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif

  /* #10 If the sum of Value and Add exceeds the MaxCountingValue, subtract MaxCountingValue+1 from the sum. */
  if(Add > (MaxCountingValue - Value))
  {
    Os_TickType mod;

    /* 1.             Add > MaxCountingValue - Value            - see if-statement
     * 2.  => Add + Value > MaxCountingValue
     * 3.  => There is a value overflow.
     */
    mod = MaxCountingValue + (uint32)1;
    result = (Value - mod) + Add;
  }
  /* #20 Else add Value and Add. */
  else
  {
    result = Value + Add;
  }

  /* Check that the calculated value is in a valid range (0 <= Value < mod). */
  Os_Assert((Os_StdReturnType)(result <= MaxCountingValue));                                                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  return result;
}


/***********************************************************************************************************************
 *  Os_TimerSub()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
Os_TimerSub,
(
  Os_TickType MaxCountingValue,
  Os_TickType Value,
  Os_TickType Sub
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  Os_TickType result;
  Os_TickType mod;

  mod = MaxCountingValue + (uint32)1;

  Os_Assert((Os_StdReturnType)(Value <= MaxCountingValue));                                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(Sub <=  MaxCountingValue));                                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 If the Sub is greater than Value, add MaxCountingValue+1 to Value and subtract Sub. */
  if(Sub > Value)
  {
    result = (Value + mod) - Sub;
  }
  /* #20 Else subtract Sub from Value. */
  else
  {
    result = Value - Sub;
  }

  /* Check that the calculated value is in a valid range (0 <= Value < mod). */
  Os_Assert((Os_StdReturnType)(result <= MaxCountingValue));                                                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  return result;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_TIMER_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/**********************************************************************************************************************
 *  END OF FILE: Os_TimerInt.h
 *********************************************************************************************************************/
