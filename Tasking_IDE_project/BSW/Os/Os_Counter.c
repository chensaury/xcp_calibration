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
 * \addtogroup Os_Counter
 * \{
 *
 * \file
 * \brief       Implementation of counter functionality.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */


#define OS_COUNTER_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Counter_Types.h"
#include "Os_Counter_Cfg.h"
#include "Os_Counter_Lcfg.h"
#include "Os_Counter.h"

/* Os kernel module dependencies */
#include "Os_Lcfg.h"

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
 *  Os_CounterHasSwCounter()
 **********************************************************************************************************************/
/*! \brief        Returns whether any software counter is configured or not.
 *  \details      --no details--
 *
 *  \retval       !0   If any software counter is configured.
 *  \retval       0    If no software counter is configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasSwCounter,
(
  void
));


/***********************************************************************************************************************
 *  Os_CounterUserModulo()
 **********************************************************************************************************************/
/*! \brief        Performs Value = Value mod MaxAllowedValue.
 *  \details      Optimized version of modulo (% MaxAllowedValue) operation.
 *
 *                This function distinguishes between the counter's driver type and uses the appropriate algorithm
 *                to calculate the result.
 *
 *  \param[in]    Counter   The counter to query. Parameter must not be NULL.
 *  \param[in]    Value     The value to be limited. Value has to be in range 0 <= Value <= MaxCountingValue.
 *
 *  \return       The limited value.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterUserModulo,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Value
));


/***********************************************************************************************************************
 *  Os_CounterCheckIsSoftwareCounter()
 **********************************************************************************************************************/
/*! \brief        Returns whether the given counter is a software counter (Not OS_CHECK_FAILED) or not
 *                (OS_CHECK_FAILED).
 *  \details      In case that extended checks are disabled, the default result of Os_ErrExtendedCheck() is returned.
 *
 *  \param[in]    Counter        The counter to query. Parameter must not be NULL.
 *
 *  \retval       Not OS_CHECK_FAILED   If the counter is a software counter.
 *  \retval       OS_CHECK_FAILED       If the counter is not a software counter.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterCheckIsSoftwareCounter,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterGetPhysicalValue()
 **********************************************************************************************************************/
/*! \brief        Returns the actual current counter value.
 *  \details
 *  This function calls the appropriate *GetValue() function, depending on the counter type.
 *  The counter's driver is known during generation time, therefore distinction could be done during generation time
 *  using function pointers. This would result into cleaner code, but also into loss of performance,
 *  because of an additional function call. We expect that a switch case construct with inlined functions is faster,
 *  because no call stack frame is created.
 *
 *  \param[in]    Counter           The counter to query. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE TickType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetPhysicalValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterAbsValue2TimerAbsValue()
 **********************************************************************************************************************/
/*! \brief        Converts an absolute counter time stamp into an absolute timer time stamp.
 *  \details      The function simply delegates its service to the function of the respective timer.
 *
 *  \param[in]    Counter       The counter which holds the range limitation info. Parameter must not be NULL.
 *  \param[in]    Now           The current timer value. Now is lower than or equal to MaxCountingValue.
 *  \param[in]    CounterValue  The counter value which shall be converted.
 *                              Given CounterValue is in range 0..MaxAllowedValue of the respective counter
 *                              configuration.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_LOCAL_INLINE FUNC(Os_TickType, OS_CODE) Os_CounterAbsValue2TimerAbsValue
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Now,
  Os_TickType CounterValue
);


/***********************************************************************************************************************
 *  Os_CounterGetUserValue()
 **********************************************************************************************************************/
/*! \brief        Returns the current counter value with respect to MaxAllowedValue.
 *  \details      --no details--
 *
 *  \param[in]    Counter           The counter to query. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE TickType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetUserValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterSetCompareValue()
 **********************************************************************************************************************/
/*! \brief          Updates the compare value of a counter.
 *  \details        This function calls the appropriate *SetCompare() function, depending on the counter type.
 *
 *  \param[in,out]  Counter         The counter to modify. Parameter must not be NULL.
 *  \param[in]      ExpirationTime  The compare value to set.
 *                                  ExpirationTime is in range 0 <= ExpirationTime <= MaxCountingValue.
 *                                  ExpirationTime-Now is in range -MaxAllowedValue to +MaxAllowedValue.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_CounterSetCompareValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType ExpirationTime
));


/***********************************************************************************************************************
 *  Os_CounterGetUserValueInternal()
 **********************************************************************************************************************/
/*! \brief          Returns the current counter value with respect to MAXALLOWEDVALUE.
 *  \details        Performs a counter read on the owner core.
 *
 *  \param[in]      Counter     The counter. Parameter must not be NULL.
 *  \param[in]      CounterID   The id of the counter. Id must be smaller than OS_COUNTERID_COUNT.
 *  \param[out]     Value       Value variable. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No Error.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Interrupts enabled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetUserValueInternal,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  CounterType CounterID,
  TickRefType Value
));


/***********************************************************************************************************************
 *  Os_Counter2TimerSw()
 **********************************************************************************************************************/
/*! \brief          Returns the software timer corresponding to the given counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Counter         The counter to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Counter is based on a software timer.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerSw,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_Counter2TimerPit()
 **********************************************************************************************************************/
/*! \brief          Returns the periodic timer corresponding to the given counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Counter         The counter to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Counter is based on a periodic hardware timer.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerPit,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_Counter2TimerHrt()
 **********************************************************************************************************************/
/*! \brief          Returns the high resolution timer corresponding to the given counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Counter         The counter to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Counter is based on a high resolution hardware timer.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerHrt,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_Counter2TimerPfrt()
 **********************************************************************************************************************/
/*! \brief          Returns the periodic free running timer corresponding to the given counter.
 *  \details        --no details--
 *
 *  \param[in,out]  Counter         The counter to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Counter is based on a high resolution hardware timer.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerPfrt,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  Os_CounterHasSwCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasSwCounter,
(
  void
))
{
  return (Os_StdReturnType)(OS_CFG_COUNTER_SW_USED == STD_ON);                                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterUserModulo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterUserModulo,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Value
))
{
  volatile Os_TickType result;

  switch(Counter->DriverType)
  {
    case OS_TIMERTYPE_SOFTWARE:
      result = Os_TimerSwUserModulo(Os_Counter2TimerSw(Counter), Value);                                                /* SBSW_OS_CNT_TIMERSWFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_TICK:                                                                                    /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
      result = Os_TimerPitUserModulo(Os_Counter2TimerPit(Counter), Value);                                              /* SBSW_OS_CNT_TIMERPITFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_HIGH_RESOLUTION:                                                                                  /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
      result = Os_TimerHrtUserModulo(Os_Counter2TimerHrt(Counter), Value);                                              /* SBSW_OS_CNT_TIMERHRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER:                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
      result = Os_TimerPfrtUserModulo(Os_Counter2TimerPfrt(Counter), Value);                                            /* SBSW_OS_CNT_TIMERPFRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }

  /* Expect the value to be in a valid range (0 <= Value <= MaxAllowedValue) */
  Os_Assert((Os_StdReturnType)(result <= Counter->Characteristics.MaxAllowedValue));                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  return result;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterCheckIsSoftwareCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_CounterCheckIsSoftwareCounter,
(
    P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(Counter->DriverType == OS_TIMERTYPE_SOFTWARE));                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_CounterGetUserValueInternal()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetUserValueInternal,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  CounterType CounterID,
  TickRefType Value
))
{
  Os_StatusType status;

  if(OS_LIKELY(Os_CoreAsrIsCoreLocal(Counter->Core) != 0u))                                                             /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  {
    Os_IntStateType interruptState;

    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    status = Os_CounterGetUserValueLocal(Counter, Value);                                                               /* SBSW_OS_FC_PRECONDITION */

    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }
  else
  {
    status = Os_XSigSend_GetCounterValue(Counter->Core, Os_CoreGetThread(), CounterID, Value);                          /* SBSW_OS_CNT_XSIGSEND_001 */
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_CounterGetPhysicalValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE TickType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetPhysicalValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  volatile Os_TickType counterValue;

  switch(Counter->DriverType)
  {
    case OS_TIMERTYPE_SOFTWARE:
      counterValue = Os_TimerSwGetValue(Os_Counter2TimerSw(Counter));                                                   /* SBSW_OS_CNT_TIMERSWFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_TICK:                                                                                    /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
      counterValue = Os_TimerPitGetValue(Os_Counter2TimerPit(Counter));                                                 /* SBSW_OS_CNT_TIMERPITFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_HIGH_RESOLUTION:                                                                                  /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
      counterValue = Os_TimerHrtGetValue(Os_Counter2TimerHrt(Counter));                                                 /* SBSW_OS_CNT_TIMERHRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER:                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
      counterValue = Os_TimerPfrtGetValue(Os_Counter2TimerPfrt(Counter));                                               /* SBSW_OS_CNT_TIMERPFRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }

  return counterValue;                                                                                                  /* PRQA S 2962 */ /* MD_Os_Rule9.1_2962 */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterGetUserValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE TickType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterGetUserValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  /* #10 Get the physical timer value. */
  Os_TickType counterValue = Os_CounterGetPhysicalValue(Counter);                                                       /* SBSW_OS_FC_PRECONDITION */
  /* #20 Perform a range limitation. */
  return Os_CounterUserModulo(Counter, counterValue);                                                                   /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_CounterSetCompareValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_CounterSetCompareValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType ExpirationTime
))
{
  switch(Counter->DriverType)
  {
    case OS_TIMERTYPE_SOFTWARE:
      Os_TimerSwSetCompareValue(Os_Counter2TimerSw(Counter), ExpirationTime);                                           /* SBSW_OS_CNT_TIMERSWFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_TICK:                                                                                    /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
      Os_TimerPitSetCompareValue(Os_Counter2TimerPit(Counter), ExpirationTime);                                         /* SBSW_OS_CNT_TIMERPITFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_HIGH_RESOLUTION:                                                                                  /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
      Os_TimerHrtSetCompareValue(Os_Counter2TimerHrt(Counter), ExpirationTime);                                         /* SBSW_OS_CNT_TIMERHRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER:                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
      Os_TimerPfrtSetCompareValue(Os_Counter2TimerPfrt(Counter), ExpirationTime);                                       /* SBSW_OS_CNT_TIMERPFRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterGetValue()
 **********************************************************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_CounterGetValue
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
)
{
  return Os_CounterGetUserValue(Counter);                                                                               /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_CounterGetModulo()
 **********************************************************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_CounterGetModulo
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Operand
)
{
  return Os_CounterUserModulo(Counter, Operand);                                                                        /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_CounterSub()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_TickType, OS_CODE) Os_CounterSub
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Value,
  Os_TickType Sub
)
{
  Os_TickType result;
  Os_Assert((Os_StdReturnType)(Value <= Counter->Characteristics.MaxAllowedValue));                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(Sub <= Counter->Characteristics.MaxAllowedValue));                                       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 Perform the operation */
  result = Value - Sub;

  /* #20 Perform modulo. */
  if(Value < Sub)                                                                                                       /* COV_OS_HALPLATFORMFASTTIMERUNSUPPORTED */
  {
    result += (Counter->Characteristics.MaxAllowedValue + 1u);
  }

  return result;
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_CounterInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_CounterInit
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
)
{
  /* #10 Initialize the respective timer */
  switch(Counter->DriverType)
  {
    case OS_TIMERTYPE_SOFTWARE:
      Os_TimerSwInit(Os_Counter2TimerSw(Counter));                                                                      /* SBSW_OS_CNT_TIMERSWFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_TICK:                                                                                    /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
      Os_TimerPitInit(Os_Counter2TimerPit(Counter));                                                                    /* SBSW_OS_CNT_TIMERPITFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_HIGH_RESOLUTION:                                                                                  /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
      Os_TimerHrtInit(Os_Counter2TimerHrt(Counter));                                                                    /* SBSW_OS_CNT_TIMERHRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER:                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
      Os_TimerPfrtInit(Os_Counter2TimerPfrt(Counter));                                                                  /* SBSW_OS_CNT_TIMERPFRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
     break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }

  /* #20 Initialize the priority queue */
  Os_PriorityQueueInit(&(Counter->JobQueue));                                                                           /* SBSW_OS_FC_PRECONDITION */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterStart()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_CounterStart
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
)
{
  /* #10 Start the respective timer */
  switch(Counter->DriverType)
  {
    case OS_TIMERTYPE_SOFTWARE:
      Os_TimerSwStart(Os_Counter2TimerSw(Counter));                                                                     /* SBSW_OS_CNT_TIMERSWFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_TICK:                                                                                    /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
      Os_TimerPitStart(Os_Counter2TimerPit(Counter));                                                                   /* SBSW_OS_CNT_TIMERPITFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_HIGH_RESOLUTION:                                                                                  /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
      Os_TimerHrtStart(Os_Counter2TimerHrt(Counter));                                                                   /* SBSW_OS_CNT_TIMERHRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    case OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER:                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
      Os_TimerPfrtStart(Os_Counter2TimerPfrt(Counter));                                                                 /* SBSW_OS_CNT_TIMERPFRTFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      Os_ErrKernelPanic();
      break;
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterGetUserValueLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_CounterGetUserValueLocal
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickRefType Value
)
{
  Os_StatusType status;
  Os_IntStateType interruptState;

  Os_IntSuspend(&interruptState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

  /* #10 Perform checks */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(Counter->OwnerApplication) == OS_CHECK_FAILED))                                /* SBSW_OS_CNT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else
  {
    /* #20 perform the requeted service */
    status = OS_STATUS_OK;
    (*Value) = Os_CounterGetUserValue(Counter);                                                                         /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */
  }

  Os_IntResume(&interruptState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */

  return status;
}


/***********************************************************************************************************************
 *  Os_CounterWorkJobs()
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
FUNC(void, OS_CODE) Os_CounterWorkJobs
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
)
{
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) job;
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) jobQueue = &(Counter->JobQueue);

  job = Os_PriorityQueueTopGet(jobQueue);                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #10 Repeat until queue is empty OR there are no expired jobs in the queue: */
  while(OS_LIKELY(job != NULL_PTR))
  {
    /* #20 Get counter's current value. (We have a continuously changing FRT here.) */
    Os_TickType now = Os_CounterGetPhysicalValue(Counter);                                                              /* SBSW_OS_FC_PRECONDITION */

    /* #30 If the high prio job is expired (likely): */
    if(OS_LIKELY(Os_CounterIsFutureValue(Counter, job->Dyn->ExpirationTimestamp, now) == 0u))                           /* SBSW_OS_FC_PRECONDITION */
    {
      /* #40 Dequeue the job. */
      Os_PriorityQueueDeleteTop(jobQueue);                                                                              /* SBSW_OS_FC_PRECONDITION */

      /* #50 Work the job off. */
      Os_JobDo(job);                                                                                                    /* SBSW_OS_FC_PRECONDITION */
    }
    else
    {
      break;
    }

    /* #60 Get high prio job from queue. */
    job = Os_PriorityQueueTopGet(jobQueue);                                                                             /* SBSW_OS_FC_PRECONDITION */
  }

  /* #70 If the queue still contains jobs: */
  if(job != NULL_PTR)
  {
    /* #80 Set compare value to expiration time of next job. */
    Os_CounterSetCompareValue(Counter, job->Dyn->ExpirationTimestamp);                                                  /* SBSW_OS_FC_PRECONDITION */
  }
  /* #90 else */
  else
  {
    /* #100 Set compare value far into the future. */
    Os_TickType now = Os_CounterGetPhysicalValue(Counter);                                                              /* SBSW_OS_FC_PRECONDITION */
    Os_TickType expirationTimestamp;

    expirationTimestamp = Os_TimerAdd(
        Counter->Characteristics.MaxAllowedValue,
        Counter->Characteristics.MaxCountingValue,
        now,
        Counter->Characteristics.MaxAllowedValue);
    Os_CounterSetCompareValue(Counter, expirationTimestamp);                                                            /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_Counter2TimerSw()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerSw,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))
{
  return (P2CONST(Os_TimerSwConfigType, AUTOMATIC, OS_CONST))Counter;                                                   /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_Counter2TimerPit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerPit,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))                                                                                                                      /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
{
  return (P2CONST(Os_TimerPitConfigType, AUTOMATIC, OS_CONST))Counter;                                                  /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_Counter2TimerHrt()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
OS_LOCAL_INLINE P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_Counter2TimerHrt,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))                                                                                                                      /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
{
  return (P2CONST(Os_TimerHrtConfigType, AUTOMATIC, OS_CONST))Counter;                                                  /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_Counter2TimerPfrt()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE,
Os_Counter2TimerPfrt,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
))                                                                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
{
  return (P2CONST(Os_TimerPfrtConfigType, AUTOMATIC, OS_CONST))Counter;                                                 /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_CounterAddRelJob()
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
FUNC(void, OS_CODE) Os_CounterAddRelJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
)
{
  Os_TickType now;
  Os_TickType newExpTime;
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) jobQueue;

  jobQueue = &Counter->JobQueue;

  /* #10 Get the current counter value (now). */
  now = Os_CounterGetPhysicalValue(Counter);                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #20 Set job's expiration time to mod(now + Offset). */
  newExpTime = Os_TimerAdd(
      Counter->Characteristics.MaxAllowedValue,
      Counter->Characteristics.MaxCountingValue,
      now,
      Offset);

  Os_JobSetExpirationTimestamp(Job, newExpTime);                                                                        /* SBSW_OS_FC_PRECONDITION */

  /* #30 Enqueue the given job in counter's job queue. */
  Os_PriorityQueueInsert(jobQueue, Job);                                                                                /* SBSW_OS_FC_PRECONDITION */

  /* #40 If the top element of the queue has changed: */
  if(Job == Os_PriorityQueueTopGet(jobQueue))                                                                           /* SBSW_OS_FC_PRECONDITION */
  {
    /* #50 Update timer's compare value. */
    Os_CounterSetCompareValue(Counter, newExpTime);                                                                     /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterAddAbsJob()
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
FUNC(void, OS_CODE) Os_CounterAddAbsJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Start
)
{
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) jobQueue;
  Os_TickType absStart;
  Os_TickType now;

  jobQueue = &Counter->JobQueue;

  /* #10 Get the correct absolute start time for the timer. */
  now = Os_CounterGetPhysicalValue(Counter);                                                                            /* SBSW_OS_FC_PRECONDITION */
  absStart = Os_CounterAbsValue2TimerAbsValue(Counter, now, Start);                                                     /* SBSW_OS_FC_PRECONDITION */

  /* #20 Set job's expiration time to Start. */
  Os_JobSetExpirationTimestamp(Job, absStart);                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #30 Enqueue the given job in counter's job queue. */
  Os_PriorityQueueInsert(jobQueue, Job);                                                                                /* SBSW_OS_FC_PRECONDITION */

  /* #40 If the top element of the queue has changed: */
  if(Job == Os_PriorityQueueTopGet(jobQueue))                                                                           /* SBSW_OS_FC_PRECONDITION */
  {
    /* #50 Update timer's compare value. */
    Os_CounterSetCompareValue(Counter, absStart);                                                                       /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterAbsValue2TimerAbsValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_LOCAL_INLINE FUNC(Os_TickType, OS_CODE) Os_CounterAbsValue2TimerAbsValue
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Now,
  Os_TickType CounterValue
)
{
  volatile Os_TickType absStart;

  /* #10 Simply call the respective timer function to perform the service. */
  switch(Counter->DriverType)
  {
    case OS_TIMERTYPE_SOFTWARE:
      absStart = Os_TimerSwAbsCounter2AbsTimerValue(
          Counter->Characteristics.MaxAllowedValue,
          Now,
          CounterValue);
      break;
    case OS_TIMERTYPE_PERIODIC_TICK:                                                                                    /* COV_OS_HALPLATFORMPITUNSUPPORTED_XX */
      absStart = Os_TimerPitAbsCounter2AbsTimerValue(
          Counter->Characteristics.MaxAllowedValue,
          Now,
          CounterValue);
      break;
    case OS_TIMERTYPE_HIGH_RESOLUTION:                                                                                  /* COV_OS_HALPLATFORMFRTUNSUPPORTED_XX */
      /* HRT Timer fulfills preconditions for MaxAllowedValue and MaxCountingValue. */
      absStart = Os_TimerHrtAbsCounter2AbsTimerValue(
          Counter->Characteristics.MaxAllowedValue,
          Counter->Characteristics.MaxCountingValue,
          Now,
          CounterValue);
      break;
    case OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER:                                                                      /* COV_OS_HALPLATFORMPFRTUNSUPPORTED_XX */
      absStart = Os_TimerPfrtAbsCounter2AbsTimerValue(
          Counter->Characteristics.MaxAllowedValue,
          Now,
          CounterValue);
      break;
    default:                                                                                                            /* COV_OS_INVSTATE */
      /* Some compilers state that absStart is not initialized in this case.
       * If absStart is initialized here, some other compilers complain about a useless assignment. */
      Os_ErrKernelPanic();
      break;
  }

  return absStart;                                                                                                      /* PRQA S 2962 */ /* MD_Os_Rule9.1_2962 */
}


/***********************************************************************************************************************
 *  Os_CounterReloadJob()
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
FUNC(void, OS_CODE) Os_CounterReloadJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
)
{
  Os_TickType lastExpTime;
  Os_TickType newExpTime;
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) jobQueue;

  jobQueue = &Counter->JobQueue;

  /* #10 Get the job's current expiration time stamp (lastExpTime). */
  lastExpTime = Os_JobGetExpirationTimestamp(Job);                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #20 Set job's expiration time to (lastExpTime + Offset). */
  newExpTime = Os_TimerAdd(
      Counter->Characteristics.MaxAllowedValue,
      Counter->Characteristics.MaxCountingValue,
      lastExpTime,
      Offset);

  Os_JobSetExpirationTimestamp(Job, newExpTime);                                                                        /* SBSW_OS_FC_PRECONDITION */

  /* #30 Enqueue the given job in counter's job queue. */
  Os_PriorityQueueInsert(jobQueue, Job);                                                                                /* SBSW_OS_FC_PRECONDITION */

  /* #40 If the top element of the queue has changed: */
  if(Job == Os_PriorityQueueTopGet(jobQueue))                                                                           /* SBSW_OS_FC_PRECONDITION */
  {
    /* #50 Update timer's compare value. */
    Os_CounterSetCompareValue(Counter, newExpTime);                                                                     /* SBSW_OS_FC_PRECONDITION */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_CounterDeleteJob()
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
FUNC(void, OS_CODE) Os_CounterDeleteJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
)
{
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) topJob;
  P2CONST(Os_PriorityQueueConfigType, AUTOMATIC, OS_CONST) jobQueue;
  Os_PriorityQueueDeleteResultType queueResult;

  jobQueue = &(Counter->JobQueue);

  topJob = Os_PriorityQueueTopGet(jobQueue);                                                                            /* SBSW_OS_FC_PRECONDITION */

  Os_Assert((Os_StdReturnType)(topJob != NULL_PTR));                                                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 Delete the given job from counter's job queue. */
  queueResult = Os_PriorityQueueDelete(jobQueue, Job);                                                                  /* SBSW_OS_FC_PRECONDITION */
  Os_Assert((Os_StdReturnType)(queueResult == OS_PRIORITYQUEUEDELETE_OK));                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #30 If the given job was the high prio job in the queue: */
  if(topJob == Job)
  {
    Os_TickType expirationTimestamp;

    topJob = Os_PriorityQueueTopGet(jobQueue);                                                                          /* SBSW_OS_FC_PRECONDITION */

    /* #40 Update timer's compare value. */
    /* #50 If the queue is empty, set compare value as far as possible into the future. */
    /*! Internal comment removed.
 *
 * */
    if(topJob == NULL_PTR)
    {
      Os_TickType now = Os_CounterGetPhysicalValue(Counter);                                                            /* SBSW_OS_FC_PRECONDITION */

      expirationTimestamp = Os_TimerAdd(
          Counter->Characteristics.MaxAllowedValue,
          Counter->Characteristics.MaxCountingValue,
          now,
          Counter->Characteristics.MaxAllowedValue);
    }
    /* #60 Otherwise, set compare value to high prio job's expiration time stamp. */
    else
    {
      expirationTimestamp = topJob->Dyn->ExpirationTimestamp;
    }

    Os_CounterSetCompareValue(Counter, expirationTimestamp);                                                            /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_CounterIncrementInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_CounterIncrementInternal
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
)
{
  Os_StatusType status;

  Os_Assert((Os_StdReturnType)(Counter->DriverType == OS_TIMERTYPE_SOFTWARE));                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 Check whether the application is accessible. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(Counter->OwnerApplication) == OS_CHECK_FAILED))                                /* SBSW_OS_CNT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else
  {
    /* #20 Increment the given counter and execute expired jobs if applicable. */
    Os_TimerSwIncrement(Os_Counter2TimerSw(Counter));                                                                   /* SBSW_OS_CNT_TIMERSWFUNCTION_001 */ /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_Api_IncrementCounter()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_IncrementCounter
(
  CounterType CounterID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(Os_CounterHasSwCounter() == 0u)                                                                                    /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_TYPE_1);                                                               /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_INCREMENTCOUNTER) == OS_CHECK_FAILED))     /* SBSW_OS_CNT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_CounterCheckId(CounterID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_CNT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) me = Os_CounterId2Counter(CounterID);
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApp = Os_ThreadGetCurrentApplication(currentThread);          /* SBSW_OS_CNT_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_CounterCheckIsSoftwareCounter(me) == OS_CHECK_FAILED))                                            /* SBSW_OS_CNT_COUNTERCHECKISSOFTWARECOUNTER_001 */
    {
      status = OS_STATUS_ID_TYPE_1;
    }
    else if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(me->Core) == OS_CHECK_FAILED))                                       /* SBSW_OS_CNT_COREASRISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_CORE;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(currentApp, Os_CounterGetAccessingApplications(me)) == OS_CHECK_FAILED))      /* SBSW_OS_CNT_APPCHECKACCESS_001 */ /* SBSW_OS_CNT_COUNTERGETACCESSINGAPPLICATIONS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      Os_IntStateType interruptState;

      /* #20 Suspend interrupts. */
      Os_IntSuspend(&interruptState);                                                                                   /* SBSW_OS_FC_POINTER2LOCAL */

      /* #30 Call internal behavior for increment counter. */
      status = Os_CounterIncrementInternal(me);                                                                         /* SBSW_OS_CNT_COUNTERINCREMENTINTERNAL_001 */

      if(OS_LIKELY(status == OS_STATUS_OK))
      {
        /* #40 If the caller is a task AND a task switch is needed: */
        if(Os_ThreadIsTask(currentThread) != 0u)                                                                        /* SBSW_OS_CNT_THREADISTASK_001 */
        {
          P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) localCore = Os_ThreadGetCore(currentThread);               /* SBSW_OS_CNT_THREADGETCORE_001 */
          P2CONST(Os_SchedulerConfigType, AUTOMATIC, OS_CONST) scheduler = Os_CoreGetScheduler(localCore);              /* SBSW_OS_CNT_COREGETSCHEDULER_001 */

          if(Os_SchedulerTaskSwitchIsNeeded(scheduler) != 0u)                                                           /* SBSW_OS_CNT_SCHEDULERTASKSWITCHISNEEDED_001 */
          {
            /* #50 Perform a task switch. */
            Os_TaskSwitch(scheduler, currentThread);                                                                    /* SBSW_OS_CNT_TASKSWITCH_001 */
          }
        }
      }

      /* #60 Resume interrupts. */
      Os_IntResume(&interruptState);                                                                                    /* SBSW_OS_FC_POINTER2LOCAL */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_GetCounterValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetCounterValue
(
  CounterType CounterID,
  TickRefType Value
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETCOUNTERVALUE) == OS_CHECK_FAILED))           /* SBSW_OS_CNT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_CounterCheckId(CounterID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_CNT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) me = Os_CounterId2Counter(CounterID);
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApp = Os_ThreadGetCurrentApplication(currentThread);          /* SBSW_OS_CNT_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApp, Os_CounterGetAccessingApplications(me)) == OS_CHECK_FAILED))           /* SBSW_OS_CNT_APPCHECKACCESS_001 */ /* SBSW_OS_CNT_COUNTERGETACCESSINGAPPLICATIONS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      status = Os_CounterGetUserValueInternal(me, CounterID, Value);                                                    /* SBSW_OS_CNT_COUNTERGETUSERVALUEINTERNAL_001 */
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_GetElapsedValue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetElapsedValue
(
  CounterType CounterID,
  TickRefType Value,
  TickRefType ElapsedValue
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(                                                                                                       /* SBSW_OS_CNT_THREADCHECKCALLCONTEXT_001 */
      Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETELAPSEDVALUE) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_CounterCheckId(CounterID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_CNT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) me = Os_CounterId2Counter(CounterID);
    P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) currentApp = Os_ThreadGetCurrentApplication(currentThread);          /* SBSW_OS_CNT_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApp, Os_CounterGetAccessingApplications(me)) == OS_CHECK_FAILED))           /* SBSW_OS_CNT_APPCHECKACCESS_001 */ /* SBSW_OS_CNT_COUNTERGETACCESSINGAPPLICATIONS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_CounterCheckValueLeMaxAllowed(me, *Value) == OS_CHECK_FAILED))                               /* SBSW_OS_CNT_COUNTERCHECKVALUELEMAXALLOWED_001 */
    {
      status = OS_STATUS_VALUE_IS_TOO_HIGH_2;
    }
    else
    {
      Os_TickType currentCounterValue = 0;

      /* #20 If a new current counter value could be read from the given (SW or HW) counter: */
      status = Os_CounterGetUserValueInternal(me, CounterID, &currentCounterValue);                                     /* SBSW_OS_CNT_COUNTERGETUSERVALUEINTERNAL_002 */

      if(OS_LIKELY(status == OS_STATUS_OK))
      {
        /* #30 Calculate elapsed ticks. */
        (*ElapsedValue) = Os_CounterSub(me, currentCounterValue, *Value);                                               /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_CNT_COUNTERSUB_001 */
        (*Value) = currentCounterValue;                                                                                 /* SBSW_OS_PWA_PRECONDITION */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */



#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_CNT_TIMERSWFUNCTION_001
 \DESCRIPTION     An Os_TimerSw function is called with the return value  of Os_Counter2TimerSw.
                  Precondition ensures, that given counter is a software timer. The compliance of the precondition
                  is check during review.
 \COUNTERMEASURE  \M [CM_OS_COUNTER2TIMERSW_01_02_M]
                  \R [CM_OS_COUNTER2TIMERSW_02_02_R]

\ID SBSW_OS_CNT_TIMERPITFUNCTION_001
 \DESCRIPTION     An Os_TimerPit function is called with the return value of Os_Counter2TimerPit.
 \COUNTERMEASURE  \M [CM_OS_COUNTER2TIMERPIT_01_02_M]
                  \R [CM_OS_COUNTER2TIMERPIT_02_02_R]

\ID SBSW_OS_CNT_TIMERHRTFUNCTION_001
 \DESCRIPTION     An Os_TimerHrt function is called with the return value of Os_Counter2TimerHrt.
 \COUNTERMEASURE  \M [CM_OS_COUNTER2TIMERHRT_01_02_M]
                  \R [CM_OS_COUNTER2TIMERHRT_02_02_R]

\ID SBSW_OS_CNT_TIMERPFRTFUNCTION_001
 \DESCRIPTION     An Os_TimerPfrt function is called with the return value of Os_Counter2TimerPfrt.
 \COUNTERMEASURE  \M [CM_OS_COUNTER2TIMERPFRT_01_02_M]
                  \R [CM_OS_COUNTER2TIMERPFRT_02_02_R]

\ID SBSW_OS_CNT_XSIGSEND_001
 \DESCRIPTION     A cross core send function is called, with the core derived from a counter object which is passed
                  as argument to the caller and the return value of Os_CoreGetThread. Correctness of the argument and
                  the return value of Os_CoreGetThread is ensured by preconditions. The compliance of the precondition
                  is check during review.
 \COUNTERMEASURE  \M [CM_OS_COUNTERGETCORE_M]

\ID SBSW_OS_CNT_APPCHECKISACCESSIBLE_001
 \DESCRIPTION     Os_AppCheckIsAccessible is called with the owner application of a counter object which is passed
                  as argument to the caller. Correctness of the argument is ensured by preconditions. The compliance
                  of the precondition is check during review.
 \COUNTERMEASURE  \M [CM_OS_COUNTERGETAPPLICATION_M]

\ID SBSW_OS_CNT_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION     Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE  \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_CNT_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION     Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE  \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_CNT_THREADGETCORE_001
 \DESCRIPTION     Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE  \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_CNT_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION     Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE  \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_CNT_COUNTERCHECKISSOFTWARECOUNTER_001
 \DESCRIPTION     Os_CounterCheckIsSoftwareCounter is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_CNT_COREASRISCORELOCAL_001
 \DESCRIPTION     Os_CoreAsrIsCoreLocal is called with the core derived from a counter which is the return value of
                  Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]
                  \M [CM_OS_COUNTERGETCORE_M]

\ID SBSW_OS_CNT_APPCHECKACCESS_001
 \DESCRIPTION     Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE  \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_CNT_COUNTERINCREMENTINTERNAL_001
 \DESCRIPTION     Os_CounterIncrementInternal is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_CNT_THREADISTASK_001
 \DESCRIPTION     Os_ThreadIsTask is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE  \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_CNT_COREGETSCHEDULER_001
 \DESCRIPTION     Os_CoreGetScheduler is called with the return value of Os_ThreadGetCore.
 \COUNTERMEASURE  \M [CM_OS_THREADGETCORE_M]

\ID SBSW_OS_CNT_SCHEDULERTASKSWITCHISNEEDED_001
 \DESCRIPTION     Os_SchedulerTaskSwitchIsNeeded is called with the return value of Os_CoreGetScheduler.
 \COUNTERMEASURE  \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_CNT_TASKSWITCH_001
 \DESCRIPTION     Os_TaskSwitch is called with the return values of Os_CoreGetScheduler and Os_CoreGetThread.
                  Correctness of the return value of Os_CoreGetThread is ensured by preconditions. The compliance
                  of the precondition is check during review.
 \COUNTERMEASURE  \M [CM_OS_COREGETSCHEDULER_M]

\ID SBSW_OS_CNT_COUNTERGETUSERVALUEINTERNAL_001
 \DESCRIPTION     Os_CounterGetUserValueInternal is called with the return values of Os_CounterId2Counter
                  and a pointer passed as argument to the caller. Correctness of the argument is
                  ensured by preconditions. The compliance of the precondition is check during review.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_CNT_COUNTERGETUSERVALUEINTERNAL_002
 \DESCRIPTION     Os_CounterGetUserValueInternal is called with the return values of Os_CounterId2Counter
                  and a pointer to a local variable.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_CNT_COUNTERSUB_001
 \DESCRIPTION     Os_CounterSub is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_CNT_COUNTERGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION     Os_CounterGetAccessingApplications is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

\ID SBSW_OS_CNT_COUNTERCHECKVALUELEMAXALLOWED_001
 \DESCRIPTION     Os_CounterCheckValueLeMaxAllowed is called with the return value of Os_CounterId2Counter.
 \COUNTERMEASURE  \M [CM_OS_COUNTERID2COUNTER_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_COUNTERID2COUNTER_M
      Verify that:
        1. each counter pointer in OsCfg_CounterRefs is no NULL_PTR,
        2. each the size of OsCfg_CounterRefs is equal to OS_COUNTERID_COUNT + 1 and
        3. each element in CounterType has a lower value than OS_COUNTERID_COUNT.

\CM CM_OS_COUNTERGETAPPLICATION_M
      Verify that the OwnerApplication pointer of each counter in OsCfg_CounterRefs is no NULL_PTR.

\CM CM_OS_COUNTERGETCORE_M
      Verify that the Core pointer of each counter in OsCfg_CounterRefs is no NULL_PTR.

\CM CM_OS_COUNTER2TIMERSW_01_02_M
      Verify that:
        1. each generated object of type Os_TimerSwConfigType has the DriverType set to OS_TIMERTYPE_SOFTWARE and
        2. that the Dyn member of each Os_TimerSwConfigType object is initialized with a Os_TimerSwType.Dyn.

\CM CM_OS_COUNTER2TIMERSW_02_02_R
      Implementation ensures that converted object is a SW Timer.

\CM CM_OS_COUNTER2TIMERPIT_01_02_M
      Verify that:
        1. each generated object of type Os_TimerPitConfigType has the DriverType set to OS_TIMERTYPE_PERIODIC_TICK and
        2. that the Dyn member of each Os_TimerPitConfigType object is initialized with a Os_TimerSwType.Dyn.

\CM CM_OS_COUNTER2TIMERPIT_02_02_R
      Implementation ensures that converted object is a PIT.

\CM CM_OS_COUNTER2TIMERHRT_01_02_M
      Verify that:
        1. each generated object of type Os_TimerHrtConfigType has the DriverType set to OS_TIMERTYPE_HIGH_RESOLUTION
           and
        2. that the Dyn member of each Os_TimerHrtConfigType object is initialized with a Os_TimerHrtType.Dyn.

\CM CM_OS_COUNTER2TIMERHRT_02_02_R
      Implementation ensures that converted object is a HRT.

\CM CM_OS_COUNTER2TIMERPFRT_01_02_M
      Verify that:
        1. each generated object of type Os_TimerPfrtConfigType has the DriverType set to
           OS_TIMERTYPE_PERIODIC_FREE_RUNNING_TIMER
           and
        2. that the Dyn member of each Os_TimerPfrtConfigType object is initialized with a Os_TimerPfrtType.Dyn.

\CM CM_OS_COUNTER2TIMERPFRT_02_02_R
      Implementation ensures that converted object is a PFRT.

*/

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Counter.c
 **********************************************************************************************************************/
