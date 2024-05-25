/**********************************************************************************************************************
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
 *  \defgroup    Os_Counter Counter
 *  \brief       AUTOSAR OS Counter API and internal counter management.
 *  \details
 *  A counter is an operating system object that registers a count in ticks. There are two types of counters:
 *  - Hardware counters (which are advanced by hardware)
 *  - Software counters (which are advanced by IncrementCounter())
 *
 *  A counter is used as the time source for alarms and expiry points. In MICROSAR OS alarms and expiry points are
 *  abstracted as \ref Job.
 *
 *  Each counter has a priority queue to manage its jobs. A priority queue is used, because the number of active
 *  alarms is dynamic and may be large. In previous implementations the job handling code has been generated, in
 *  case of a small number of possible active jobs (aka "GeneratedFastAlarms").
 *
 *  ![Data Structures](CounterDataStructures.png)
 *
 *  Counter Interaction
 *  --------------------------------------------------------------------------------------------------------------------
 *  ![Interaction of counter related modules](Counter_Interaction.png)
 *
 *
 *  ### Alarm and Schedule Table ###
 *  Provide AUTOSAR functionality for AUTOSAR OS Alarms and Schedule Tables. They setup jobs, using the counter modules
 *  interface, to implement Alarms and Expiry Points.
 *
 *  \see \ref Os_Alarm
 *  \see \ref Os_ScheduleTable
 *
 *
 *  ### Counter ###
 *  Provide counter abstraction and the AUTOSAR OS API for Counters.
 *  Timer independent interface to:
 *  - Add jobs
 *  - Cancel jobs
 *  - Work jobs
 *  - Get counter information (current value, max allowed value, mincycle, ...)
 *  - Get relative counter value from absolute counter value
 *
 *  It also provides the API to increment software counters.
 *  The counter module uses the timer module to generate timer interrupts (if the counter is not a software counter).
 *
 *  \see \ref Os_PriorityQueue
 *  \see \ref Os_Job
 *
 *
 *  ### Timer ###
 *  Provides a unique abstraction for different timers.
 *  - Software based
 *  - Programmable Interval Timers (PIT)
 *  - High Resolution Timer (HRT)
 *
 *  \see \ref Os_Timer
 *
 *
 *  ### HAL Timer ###
 *  Provides a unique abstraction for different PIT and FRT hardware.
 *  - PIT
 *   - Reload or Compare
 *  - FRT
 *   - Up/Down Counting
 *   - With and Without Bit correction
 *
 *  \see \ref Os_Hal_Timer
 *
 *
 *  Work Jobs
 *  --------------------------------------------------------------------------------------------------------------------
 *  ![Work Jobs](Counter_WorkJobs.png)
 *
 *  \see \ref Job
 *
 *
 *  \trace CREQ-140
 *  \trace SPEC-64001, SPEC-64033
 *
 *  \{
 *
 *  \file
 *  \brief       Internal counter interface.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_COUNTERINT_H
# define OS_COUNTERINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Counter_Types.h"
# include "Os_Counter_Cfg.h"
# include "Os_Counter_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_CommonInt.h"
# include "Os_ErrorInt.h"
# include "Os_PriorityQueue_Types.h"
# include "Os_PriorityQueueInt.h"
# include "Os_Application_Types.h"
# include "Os_Core_Types.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"




/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/*! Type cast from Os_TimerSwConfigType to Os_CounterConfigType by use of base element addressing. */
#define OS_COUNTER_CASTCONFIG_TIMERSW_2_COUNTER(timer)          (&((timer).Counter))                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_TimerPitConfigType to Os_CounterConfigType by use of base element addressing. */
#define OS_COUNTER_CASTCONFIG_TIMERPIT_2_COUNTER(timer)         (&((timer).SwCounter.Counter))                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_TimerHrtConfigType to Os_CounterConfigType by use of base element addressing. */
#define OS_COUNTER_CASTCONFIG_TIMERHRT_2_COUNTER(timer)         (&((timer).Counter))                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_TimerPfrtConfigType to Os_CounterConfigType by use of base element addressing. */
#define OS_COUNTER_CASTCONFIG_TIMERPFRT_2_COUNTER(timer)        (&((timer).SwCounter.Counter))                          /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/

/*! Counter characteristics. */
struct Os_CounterCharacteristicsConfigType_Tag
{
  /*!
   * \brief   Maximum possible allowed value of the counter in ticks.
   * \details
   * Timer Type               | Range                           | Limitations
   * :----------------------  | :-----------------------------  | :------------------------------
   * High Resolution          | 0x3FFFFFFF                      | 0x3FFFFFFF
   * Periodic Timer           | MinCycle+1 .. max(TickType)/2-1 | None
   * Software Timer           | MinCycle+1 .. max(TickType)/2-1 | None
   */
  Os_TickType MaxAllowedValue;

  /*!
   * \brief   Maximum possible allowed value of the timer in ticks.
   * \details
   * Timer Type               | Range               |
   * :----------------------  | :------------------ |
   * High Resolution          | 4*MaxAllowedValue+3 |
   * Periodic Timer           | 2*MaxAllowedValue+1 |
   * Software Timer           | 2*MaxAllowedValue+1 |
   */
  Os_TickType MaxCountingValue;

  /*!
   * \brief   Maximum allowed difference between two values.
   * \details
   * Timer Type               | Range
   * :----------------------  | :---------------------
   * High Resolution          | 2*MaxAllowedValue+1
   * Periodic Timer           | MaxAllowedValue
   * Software Timer           | MaxAllowedValue
   */
  Os_TickType MaxDifferentialValue;

  /*! The minimum allowed number of counter ticks for a cyclic alarm linked to the counter. */
  Os_TickType MinCycle;

  /*! The number of ticks required to reach a counter specific unit. */
  Os_TickType TicksPerBase;
};



/*! General configuration information of a counter. */
struct Os_CounterConfigType_Tag
{
  /*! Counter characteristics. */
  Os_CounterCharacteristicsConfigType Characteristics;

  /*! Jobs which are currently enqueued to the counter. */
  Os_PriorityQueueConfigType JobQueue;

  /*! Counter's driver type. */
  Os_TimerTypeType DriverType;

  /*! The core to which the counter belongs. */
  P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST) Core;

  /*! The application to which the counter belongs. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) OwnerApplication;

  /*! Reference to applications which access this object. */
  Os_AppAccessMaskType AccessingApplications;
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
 *  Os_CounterHasPfrtCounter()
 **********************************************************************************************************************/
/*! \brief        Returns whether any Pfrt counter is configured or not.
 *  \details      --no details--
 *
 *  \retval       !0   If any Pfrt counter is configured.
 *  \retval       0    If no Pfrt counter is configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasPfrtCounter,
(
  void
));


/***********************************************************************************************************************
 *  Os_CounterHasHrtCounter()
 **********************************************************************************************************************/
/*! \brief        Returns whether any Hrt counter is configured or not.
 *  \details      --no details--
 *
 *  \retval       !0   If any Hrt counter is configured.
 *  \retval       0    If no Hrt counter is configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasHrtCounter,
(
  void
));


/***********************************************************************************************************************
 *  Os_CounterHasPitCounter()
 **********************************************************************************************************************/
/*! \brief        Returns whether any Pit counter is configured or not.
 *  \details      --no details--
 *
 *  \retval       !0   If any Pit counter is configured.
 *  \retval       0    If no Pit counter is configured.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_CounterHasPitCounter,
(
  void
));


/***********************************************************************************************************************
 *  Os_CounterInit()
 **********************************************************************************************************************/
/*! \brief        Initialize the given counter.
 *  \details      Call initialization routine of the underlying counter driver type.
 *                The function is called for the timing protection counter in Init-Step3 and Init-Step4 in order to
 *                handle the situation that Init-Step3 is optional. For all other counters the function is called in
 *                Init-Step4.
 *
 *  \param[in,out]  Counter   The counter to be initialized. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Counter belongs to the local core.
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterInit
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
);


/***********************************************************************************************************************
 *  Os_CounterStart()
 **********************************************************************************************************************/
/*! \brief        Starts the given counter.
 *  \details      Call start routine of the underlying counter driver type.
 *
 *  \param[in,out]  Counter   The counter to start. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          Counter belongs to the local core.
 *  \pre          Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterStart
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
);


/***********************************************************************************************************************
 *  Os_CounterCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of Os_ErrExtendedCheck() is returned.
 *
 *  \param[in]      CounterId        The ID to check.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_CounterCheckId,
(
  CounterType CounterId
));


/***********************************************************************************************************************
 *  Os_CounterId2Counter()
 **********************************************************************************************************************/
/*! \brief          Converts a counter ID into a counter object.
 *  \details        --no details--
 *
 *  \param[in]      CounterId     The counter ID. The ID must be smaller than OS_COUNTERID_COUNT.
 *
 *  \return         The object corresponding to the ID.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_CounterId2Counter,
(
  CounterType CounterId
));


/***********************************************************************************************************************
 *  Os_CounterGetApplication()
 **********************************************************************************************************************/
/*! \brief        Returns the owner application of the given counter.
 *  \details        --no details--
 *
 *  \param[in]    Counter  Counter to query. Parameter must not be NULL.
 *
 *  \return       Owner application of the given counter.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_CounterGetApplication,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief          Get applications which have access to the given object.
 *  \details        --no details--
 *
 *  \param[in,out]  Counter  The object to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetAccessingApplications,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterGetCore()
 **********************************************************************************************************************/
/*! \brief          Get the core to which the counter is assigned.
 *  \details        --no details--
 *
 *  \param[in,out]  Counter  The object to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_CounterGetCore,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterIsFutureValue()
 **********************************************************************************************************************/
/*! \brief        Compares Value to ReferenceValue and returns whether Value is a point in time after
 *                ReferenceValue (!0) or not (0).
 *  \details      Value is in the future if: 1 <= &Delta;<sub>Value, ReferenceValue</sub> <= MaxAllowedValue
 *
 *  \param[in]    Counter         The Counter which defines the MaxAllowedValue. Parameter must not be NULL.
 *  \param[in]    Value           The value of interest.
 *  \param[in]    ReferenceValue  The compare value.
 *
 *  \retval       !0      Value is in the future.
 *  \retval       0       Value is in the past or now.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Value and ReferenceValue are in range 0 to MaxCountingValue of the underlying counter.
 *  \pre          The maximum time difference between Value and ReferenceValue is MaxDifferencialValue of the
 *                underlying counter.
 *                This means:
 *                 - For SW counters:
 *                   - The values are at most MAXALLOWEDVALUE in the future.
 *                   - Non of the values is in the past (now is allowed).
 *                 - For HRT counters:
 *                   - The values are at most MAXALLOWEDVALUE in the future.
 *                   - The values are at most MAXALLOWEDVALUE in the past.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterIsFutureValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Value,
  Os_TickType ReferenceValue
));


/***********************************************************************************************************************
 *  Os_CounterIsFutureValueInternal()
 **********************************************************************************************************************/
/*! \brief        Compares Value to ReferenceValue and returns whether Value is a point in time after
 *                ReferenceValue (!0) or not (0).
 *  \details      Value is in the future if: 1 <= &Delta;<sub>Value, ReferenceValue</sub> <= MaxAllowedValue
 *
 *  \param[in]    MaxCountingValue      The upper limit of Value and Reference Value.
 *  \param[in]    MaxDifferentialValue  Maximum difference between Value and Reference Value.
 *  \param[in]    Value                 The value of interest.
 *  \param[in]    ReferenceValue        The compare value.
 *
 *  \retval       !0      Value is in the future.
 *  \retval       0       Value is in the past or now.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *  \pre          Value and ReferenceValue are in range 0 to MaxCountingValue of the underlying counter.
 *  \pre          The maximum time difference between Value and ReferenceValue is MaxDifferencialValue of the
 *                underlying counter.
 *                This means:
 *                 - For SW counters:
 *                   - The values are at most MAXALLOWEDVALUE in the future.
 *                   - Non of the values is in the past (now is allowed).
 *                 - For HRT counters:
 *                   - The values are at most MAXALLOWEDVALUE in the future.
 *                   - The values are at most MAXALLOWEDVALUE in the past.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterIsFutureValueInternal,
(
  Os_TickType MaxCountingValue,
  Os_TickType MaxDifferentialValue,
  Os_TickType Value,
  Os_TickType ReferenceValue
));


/***********************************************************************************************************************
 *  Os_CounterCheckValueLeMaxAllowed()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given Value respects the counter's max allowed value.
 *  \details        This function is used to validate user given counter values.
 *
 *  \param[in]      Counter   The counter. Parameter must not be NULL.
 *  \param[in]      Value     The value to check.
 *
 *  \return         Whether the check succeeded or not.
 *  \retval         Not OS_CHECK_FAILED   If Value respects the upper limit.
 *  \retval         OS_CHECK_FAILED       If Value exceeds the limit.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterCheckValueLeMaxAllowed,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickType Value
));


/***********************************************************************************************************************
 *  Os_CounterCheckValueLeReducedMaxAllowed()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given Value is less or equal to the counter's maximum allowed value minus the
 *                  given Reduce value.
 *  \details        This function is used to validate user given counter values.
 *
 *  \param[in]      Counter   The counter. Parameter must not be NULL.
 *  \param[in]      Reduce    The value to subrtact from the MaxAllowedValue.
 *                            The value must be <= MAXALLOWEDVALUE configured for the counter.
 *  \param[in]      Value     The value to check.
 *
 *  \return         Whether the check succeeded or not.
 *  \retval         Not OS_CHECK_FAILED   If Value respects the upper limit.
 *  \retval         OS_CHECK_FAILED       If Value exceeds the limit.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
    Os_CounterCheckValueLeReducedMaxAllowed,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickType Reduce,
  TickType Value
));


/***********************************************************************************************************************
 *  Os_CounterCheckValueGeMinCycleOrZero()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given cycle is greater or equal to counter's MinCycle or that the cycle is zero.
 *  \details        This function is used to validate user given cycle values.
 *
 *  \param[in]      Counter   The counter. Parameter must not be NULL.
 *  \param[in]      Cycle     The cycle value to check.
 *
 *  \return         Whether the check succeeded or not.
 *  \retval         Not OS_CHECK_FAILED   If Cycle is valid.
 *  \retval         OS_CHECK_FAILED       If Value is invalid.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterCheckValueGeMinCycleOrZero,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_CounterGetCharacteristics()
 **********************************************************************************************************************/
/*! \brief          Returns characteristics (MaxAllowedValue, TicksPerBase, MinCycle) of the given counter.
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter to query. Parameter must not be NULL.
 *
 *  \return         Counter characteristics.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE P2CONST(Os_CounterCharacteristicsConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetCharacteristics,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterGetMaxAllowedValue()
 **********************************************************************************************************************/
/*! \brief          Returns the MaxAllowedValue.
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter to query. Parameter must not be NULL.
 *
 *  \return         The counter's MaxAllowedValue.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetMaxAllowedValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterGetMaxCountingValue()
 **********************************************************************************************************************/
/*! \brief          Returns the MaxCountingValue.
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter to query. Parameter must not be NULL.
 *
 *  \return         The counter's MaxCountingValue.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_CounterGetMaxCountingValue,
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
));


/***********************************************************************************************************************
 *  Os_CounterGetValue()
 **********************************************************************************************************************/
/*! \brief          Returns the current counter value in range 0..MaxAllowedValue[Counter].
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter to query. Parameter must not be NULL.
 *
 *  \return         The current counter value.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_CounterGetValue
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
);


/***********************************************************************************************************************
 *  Os_CounterGetModulo()
 **********************************************************************************************************************/
/*! \brief          Returns the modulo of the operand.
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter to query. Parameter must not be NULL.
 *  \param[in]      Operand   The value to compute the modulo of.
 *                            The value must be in range 0 <= Operand <= MaxCountingValue.
 *
 *  \return         Operand % MaxAllowedValue[Counter].
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_CounterGetModulo
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Operand
);


/***********************************************************************************************************************
 *  Os_CounterSub()
 **********************************************************************************************************************/
/*! \brief          Returns difference between Value and Sub mod MaxAllowedValue.
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter to query. Parameter must not be NULL.
 *  \param[in]      Value     The value. Must be in range 0..MaxAllowedValue.
 *  \param[in]      Sub       The value to be subtracted. Must be in range 0..MaxAllowedValue.
 *
 *  \return         Value-Sub % MaxAllowedValue[Counter].
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_CounterSub
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  Os_TickType Value,
  Os_TickType Sub
);


/***********************************************************************************************************************
 *  Os_CounterWorkJobs()
 **********************************************************************************************************************/
/*! \brief          Work off all jobs until now.
 *  \details        This function works off all jobs, which are queued to the given counter and expired until now.
 *                  If the counter is a HRT counter, it will update the compare value of the hardware timer for the
 *                  next future job.
 *
 *  \param[in,out]  Counter         The counter, which shall work of its jobs. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Counter belongs to the local core.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterWorkJobs
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
);


/***********************************************************************************************************************
 *  Os_CounterAddRelJob()
 **********************************************************************************************************************/
/*! \brief          Add a job to counter's job queue with given expiration time (relative to now).
 *  \details        If the job is the new highest prio job and the counter is a HRT counter,
 *                  it will update the compare value of the hardware timer.
 *
 *  \param[in,out]  Counter    The counter, which shall work of the job. Parameter must not be NULL.
 *  \param[in,out]  Job        Job to enqueue. Parameter must not be NULL.
 *  \param[in]      Offset     Relative value (from now) in ticks to expiration time.
 *                             The value must be in range 1..MaxAllowedValue of the respective counter configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different counters.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterAddRelJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
);


/***********************************************************************************************************************
 *  Os_CounterAddAbsJob()
 **********************************************************************************************************************/
/*! \brief          Add a given job to counter's job queue with given absolute expiration time.
 *  \details        If the job is the new highest prio job and the counter is a HRT counter,
 *                  it will update the compare value of the hardware timer.
 *
 *  \param[in,out]  Counter    The counter, which shall work of the job. Parameter must not be NULL.
 *  \param[in,out]  Job        Job to enqueue. Parameter must not be NULL.
 *  \param[in]      Start      Absolute value in ticks.
 *                             The value must be in range 0..MaxAllowedValue of the respective counter configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different counters.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterAddAbsJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Start
);


/***********************************************************************************************************************
 *  Os_CounterReloadJob()
 **********************************************************************************************************************/
/*! \brief          Add a given job to counter's job queue relative to its current expiration time with given offset.
 *  \details        If the job is the new highest prio job and the counter is a HRT counter,
 *                  it will update the compare value of the hardware timer.
 *
 *  \param[in,out]  Counter    The counter, which shall work of the job. Parameter must not be NULL.
 *  \param[in,out]  Job        Job to enqueue. Parameter must not be NULL.
 *  \param[in]      Offset     Relative value (to the job's current expiration time) in ticks to its next
 *                             expiration time. The value must be in range 1..MaxAllowedValue of the respective
 *                             counter configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different counters.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterReloadJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
);


/***********************************************************************************************************************
 *  Os_CounterDeleteJob()
 **********************************************************************************************************************/
/*! \brief          Delete a given job from counter's job queue.
 *  \details        If the counter is a HRT counter, it will update the compare value of the hardware timer.
 *
 *  \param[in,out]  Counter  The counter, which shall delete the job from its queue. Parameter must not be NULL.
 *  \param[in]      Job      Job to delete. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Given job is scheduled.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_CounterDeleteJob
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
);


/***********************************************************************************************************************
 *  Os_CounterIncrementInternal()
 **********************************************************************************************************************/
/*! \brief          Increments a counter with minimum amount of checks.
 *  \details        This function is used to implement alarm action IncrementCounter.
 *
 *  \param[in,out]  Counter  The counter, which shall delete the job from its queue. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK               No error.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Counter is a software counter.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_CounterIncrementInternal
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter
);


/***********************************************************************************************************************
 *  Os_CounterGetUserValueLocal()
 **********************************************************************************************************************/
/*! \brief          Identical to Os_CounterGetUserValue() but with application state check.
 *  \details        --no details--
 *
 *  \param[in]      Counter   The counter. Parameter must not be NULL.
 *  \param[out]     Value     Contains the returned counter value on successful return. Parameter must not be NULL.
 *
 *  \return         The status of the call
 *                            - E_OS_ACCESS   (EXTENDED status:) Counter's owner application is not accessible.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Given counter belongs to the local core.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_CounterGetUserValueLocal
(
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter,
  TickRefType Value
);


/***********************************************************************************************************************
 *  Os_Api_IncrementCounter()
 **********************************************************************************************************************/
/*! \brief      OS service IncrementCounter().
 *  \details    For further details see IncrementCounter().
 *
 *  \param[in]    CounterID           See IncrementCounter().
 *
 *  \retval       OS_STATUS_OK              No Error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) CounterID is not a valid counter ID.
 *  \retval       OS_STATUS_ID_TYPE_1       (EXTENDED status:) CounterID is not a valid software counter ID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See IncrementCounter().
 *
 *  \trace        CREQ-22, CREQ-40
 *  \trace        SPEC-63764, SPEC-63776, SPEC-63976, SPEC-63983, SPEC-63984, SPEC-63993, SPEC-63709, SPEC-64017
 *  \trace        SPEC-63752, SPEC-63887, SPEC-63980, SPEC-63932
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_IncrementCounter
(
  CounterType CounterID
);


/***********************************************************************************************************************
 *  Os_Api_GetCounterValue()
 **********************************************************************************************************************/
/*! \brief      OS service GetCounterValue().
 *  \details    For further details see GetCounterValue().
 *
 *  \param[in]    CounterID   See GetCounterValue().
 *  \param[out]   Value       See GetCounterValue().
 *
 *  \retval       OS_STATUS_OK              No Error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid CounterID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetCounterValue().
 *
 *  \trace        CREQ-156, CREQ-40
 *  \trace        SPEC-63894, SPEC-63698, SPEC-63808, SPEC-63840, SPEC-64024, SPEC-63709, SPEC-64017, SPEC-63752
 *  \trace        SPEC-63797, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetCounterValue
(
  CounterType CounterID,
  TickRefType Value
);


/***********************************************************************************************************************
 *  Os_Api_GetElapsedValue()
 **********************************************************************************************************************/
/*! \brief      OS service GetElapsedValue().
 *  \details    For further details see GetElapsedValue().
 *
 *  \param[in]      CounterID     See GetElapsedValue().
 *  \param[in,out]  Value         See GetElapsedValue().
 *  \param[out]     ElapsedValue  See GetElapsedValue().
 *
 *  \retval       OS_STATUS_OK              No Error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid CounterID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_2 (EXTENDED status:) The given Value was not valid.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetElapsedValue().
 *
 *  \trace        CREQ-39, CREQ-40
 *  \trace        SPEC-63750, SPEC-63759, SPEC-63807, SPEC-63904, SPEC-63927, SPEC-63986, SPEC-64059, SPEC-63709
 *  \trace        SPEC-64017, SPEC-63752, SPEC-63797, SPEC-63980
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetElapsedValue
(
  CounterType CounterID,
  TickRefType Value,
  TickRefType ElapsedValue
);

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_COUNTERINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_CounterInt.h
 **********************************************************************************************************************/
