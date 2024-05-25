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
 * \addtogroup Os_Alarm
 * \{
 *
 * \file
 * \brief       Implementation of alarm module.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */


#define OS_ALARM_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Alarm.h"
#include "Os_Alarm_Cfg.h"
#include "Os_Alarm_Lcfg.h"

/* Os kernel module dependencies */
#include "Os_Counter.h"
#include "Os_Task.h"
#include "Os_Event.h"
#include "Os_Error.h"
#include "Os_XSignal.h"
#include "Os_Thread.h"
#include "Os_Application.h"
#include "Os_Interrupt.h"

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
 *  Os_AlarmHasActionSetEvent()
 **********************************************************************************************************************/
/*! \brief          Returns whether the Alarm module uses SetEvent actions.
 *  \details        --no details--
 *
 *  \return         0     SetEvent Alarm actions are not used in the current configuration.
 *  \return         !0    SetEvent Alarm actions are used in the current configuration.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmHasActionSetEvent, (void));


/***********************************************************************************************************************
 *  Os_AlarmHasActionActivateTask()
 **********************************************************************************************************************/
/*! \brief          Returns whether the Alarm module uses ActivateTask actions.
 *  \details        --no details--
 *
 *  \return         0     ActivateTask Alarm actions are not used in the current configuration.
 *  \return         !0    ActivateTask Alarm actions are used in the current configuration.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmHasActionActivateTask, (void));


/***********************************************************************************************************************
 *  Os_AlarmHasActionIncrementCounter()
 **********************************************************************************************************************/
/*! \brief          Returns whether the Alarm module uses IncrementCounter actions.
 *  \details        --no details--
 *
 *  \return         0     IncrementCounter Alarm actions are not used in the current configuration.
 *  \return         !0    IncrementCounter Alarm actions are used in the current configuration.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmHasActionIncrementCounter, (void));


/***********************************************************************************************************************
 *  Os_AlarmHasActionCallback()
 **********************************************************************************************************************/
/*! \brief          Returns whether the Alarm module uses Callback actions.
 *  \details        --no details--
 *
 *  \return         0     Alarm Callbacks are not used in the current configuration.
 *  \return         !0    Alarm Callbacks are used in the current configuration.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmHasActionCallback, (void));


/***********************************************************************************************************************
 *  Os_AlarmGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic information of an alarm.
 *  \details        --no details--
 *
 *  \param[in]      Alarm       Alarm to query. Parameter must not be NULL.
 *
 *  \return         Alarm's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmGetDyn,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));




/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmSetEvent()
 **********************************************************************************************************************/
/*! \brief          Returns the job's corresponding set event alarm object.
 *  \details        The caller has to ensure, that the job actually belongs to an alarm.
 *
 *  \param[in]      Job   Job to query. Parameter must not be NULL.
 *
 *  \return         Set event alarm object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a set event alarm.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AlarmSetEventConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmSetEvent,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmActivateTask()
 **********************************************************************************************************************/
/*! \brief          Returns the job's corresponding activate task alarm object.
 *  \details        The caller has to ensure, that the job actually belongs to an activate task alarm.
 *
 *  \param[in]      Job   Job to query. Parameter must not be NULL.
 *
 *  \return         Activate task alarm object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is an activate task alarm.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AlarmActivateTaskConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmActivateTask,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmIncrementCounter()
 **********************************************************************************************************************/
/*! \brief          Returns the job's corresponding increment counter alarm object.
 *  \details        The caller has to ensure, that the job actually belongs to an activate task alarm.
 *
 *  \param[in]      Job   Job to query. Parameter must not be NULL.
 *
 *  \return         Increment counter alarm object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a increment counter alarm.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AlarmIncrementCounterConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmIncrementCounter,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmCallback()
 **********************************************************************************************************************/
/*! \brief          Returns the job's corresponding callback alarm object.
 *  \details        The caller has to ensure, that the job actually belongs to a callback alarm.
 *
 *  \param[in]      Job   Job to query. Parameter must not be NULL.
 *
 *  \return         Callback alarm object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a callback alarm.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AlarmCallbackConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmCallback,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_AlarmCancelOrReload()
 **********************************************************************************************************************/
/*! \brief          Depending on the Cycle attribute of the given alarm,
 *                  this function reschedules or cancels the given alarm.
 *  \details        Called by all alarm handling functions, to implement cyclic alarms.
 *
 *  \param[in,out]  Alarm   Alarm which has arrived. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmCancelOrReload,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  Os_AlarmSetRelAlarm()
 **********************************************************************************************************************/
/*! \brief          Sets a relative alarm, which belongs to the local core.
 *  \details        --no details--
 *
 *  \param[in,out]  Alarm     Alarm to set. Parameter must not be NULL.
 *  \param[in]      Increment Relative value in ticks.
 *  \param[in]      Cycle     Cycle value in case of cyclic alarm. In case of single alarms, cycle shall be zero.
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_STATE_1           Alarm is already in use.
 *  \retval       OS_STATUS_VALUE_IS_ZERO_2   Value of increment is zero.
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_2   (EXTENDED status:) Value of Increment outside of the admissible limits
 *                                                (lower than zero or greater than maxallowedvalue).
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_3   (EXTENDED status:) Value of Cycle outside of the admissible limits
 *                                                (lower than zero or greater than maxallowedvalue).
 *  \retval       OS_STATUS_VALUE_IS_TOO_LOW_3    (EXTENDED status:) Value of Cycle is lower than MinCycle.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given alarm's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Given alarm belongs to the local core.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given values have been checked before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmSetRelAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Increment,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_AlarmGetAlarm()
 **********************************************************************************************************************/
/*! \brief          Get the alarm, which belongs to the local core.
 *  \details        --no details--
 *
 *  \param[in]      Alarm     Alarm to read from. Parameter must not be NULL.
 *  \param[out]     Tick      The current alarm value. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_NOFUNC_1        Alarm is not in use.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Given alarm belongs to the local core.
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmGetAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickRefType Tick
));


/***********************************************************************************************************************
 *  Os_AlarmSetAbsAlarm()
 **********************************************************************************************************************/
/*! \brief          Sets an absolute alarm, which belongs to the local core.
 *  \details        --no details--
 *
 *  \param[in,out]  Alarm   Alarm to set. Parameter must not be NULL.
 *  \param[in]      Start   Absolute value in ticks.
 *  \param[in]      Cycle   Cycle value in case of cyclic alarm. In case of single alarms, cycle shall be zero.
 *
 *  \retval         OS_STATUS_OK                No error.
 *  \retval         OS_STATUS_STATE             Alarm is already in use.
 *  \retval         OS_STATUS_VALUE_IS_TOO_HIGH_2  (EXTENDED status:) Value of Start outside of the admissible
 *                                                 counter limit (greater than maxallowedvalue).
 *  \retval         OS_STATUS_VALUE_IS_TOO_HIGH_3  (EXTENDED status:) Value of Cycle outside of the admissible
 *                                                 counter limits (greater than maxallowedvalue).
 *  \retval         OS_STATUS_VALUE_IS_TOO_LOW_3   (EXTENDED status:) Value of Cycle unequal to 0 and less than
 *                                                 mincycle.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given alarm's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Given alarm belongs to the local core.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given values have been checked before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmSetAbsAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Start,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_AlarmCancelAlarm()
 **********************************************************************************************************************/
/*! \brief          Cancel a given alarm.
 *  \details        --no details--
 *
 *  \param[in,out]  Alarm   Alarm to cancel. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK                No error.
 *  \retval         OS_STATUS_NOFUNC_1          Alarm is not in use.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given alarm's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Given alarm belongs to the local core.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given values have been checked before.
 *  \pre            Given alarm is scheduled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmCancelAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  Os_AlarmCheckIsCanceled()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given alarm is canceled.
 *  \details      --no details--
 *
 *  \param[in]    Alarm       Alarm to query. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \retval       Not OS_CHECK_FAILED   Alarm is canceled.
 *  \retval       OS_CHECK_FAILED       Alarm is not canceled.
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmCheckIsCanceled,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  Os_AlarmCheckIsSet()
 **********************************************************************************************************************/
/*! \brief        Checks whether the given alarm is set.
 *  \details      --no details--
 *
 *  \param[in]    Alarm       Alarm to query. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \retval       Not OS_CHECK_FAILED   Alarm is set.
 *  \retval       OS_CHECK_FAILED       Alarm is not set.
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmCheckIsSet,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_AlarmHasActionSetEvent()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmHasActionSetEvent,
(
  void
))
{
  return (Os_StdReturnType)(OS_CFG_ALARM_SETEVENT_USED == STD_ON);                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AlarmHasActionActivateTask()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmHasActionActivateTask,
(
  void
))
{
  return (Os_StdReturnType)(OS_CFG_ALARM_ACTIVATETASK_USED == STD_ON);                                                  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AlarmHasActionIncrementCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmHasActionIncrementCounter,
(
  void
))
{
  return (Os_StdReturnType)(OS_CFG_ALARM_INCREMENTCOUNTER_USED == STD_ON);                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AlarmHasActionCallback()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmHasActionCallback,
(
  void
))
{
  return (Os_StdReturnType)(OS_CFG_ALARM_CALLBACK_USED == STD_ON);                                                      /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_AlarmGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE
P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmGetDyn,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  return (P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT))Os_JobGetDyn(&(Alarm->Job));                                    /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_AL_JOBGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmSetEvent()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_AlarmSetEventConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmSetEvent,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return (P2CONST(Os_AlarmSetEventConfigType, AUTOMATIC, OS_CONST))Job;                                                 /* PRQA S 0310, 3305 */ /* MD_Os_Rule11.3_0310, MD_Os_Rule11.3_3305 */
}


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmActivateTask()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_AlarmActivateTaskConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmActivateTask,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return (P2CONST(Os_AlarmActivateTaskConfigType, AUTOMATIC, OS_CONST))Job;                                             /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmIncrementCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_AlarmIncrementCounterConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmIncrementCounter,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return (P2CONST(Os_AlarmIncrementCounterConfigType, AUTOMATIC, OS_CONST))Job;                                         /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_AlarmJob2AlarmCallback()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_AlarmCallbackConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmJob2AlarmCallback,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return (P2CONST(Os_AlarmCallbackConfigType, AUTOMATIC, OS_CONST))Job;                                                 /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_AlarmCancelOrReload()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmCancelOrReload,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT) alarmDyn;
  Os_TickType cycle;

  alarmDyn = Os_AlarmGetDyn(Alarm);                                                                                     /* SBSW_OS_FC_PRECONDITION */

  cycle = alarmDyn->Cycle;

  /* #10 If the alarm is cyclic: */
  if(cycle != OS_ALARM_SINGLE_SHOT)
  {
    /* #20 Tell the counter to reschedule the job (relative to its current expiration time) with Cycle as the offset. */
    Os_JobReload(&(Alarm->Job), cycle);                                                                                 /* SBSW_OS_FC_PRECONDITION */
  }
  /* #30 Otherwise: */
  else
  {
    /* #40 Set the alarm state to CANCELED. */
    alarmDyn->State = OS_ALARMSTATE_CANCELED;                                                                           /* SBSW_OS_AL_DYN */
  }
}


/***********************************************************************************************************************
 *  Os_AlarmGetAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmGetAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickRefType Tick
))
{
  Os_StatusType status;

  if(OS_UNLIKELY(Os_AppCheckIsAccessible(Os_AlarmGetApplication(Alarm)) == OS_CHECK_FAILED))                            /* SBSW_OS_AL_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_AlarmCheckIsSet(Alarm) == OS_CHECK_FAILED))                                                    /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_NOFUNC_1;
  }
  else
  {
    Os_TickType alarmExpiry;

    alarmExpiry = Os_JobGetExpirationTimestamp(&(Alarm->Job));                                                          /* SBSW_OS_FC_PRECONDITION */

    /* #20 Get the relative expire time. */
    (*Tick) = Os_JobGetExpiryTime(&(Alarm->Job), alarmExpiry);                                                          /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_AlarmSetRelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmSetRelAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Increment,
  TickType Cycle
))
{
  Os_StatusType status;

  /* #10 Check alarms dynamic values according to API definition. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(                                                                               /* SBSW_OS_AL_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_FC_PRECONDITION */
                    Os_AlarmGetApplication(Alarm)) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_AlarmCheckIsCanceled(Alarm) == OS_CHECK_FAILED))                                               /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_STATE_1;
  }
  else if(OS_UNLIKELY(Increment == 0u))
  {
    status = OS_STATUS_VALUE_IS_ZERO_2;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueLeMaxAllowed(                                                                     /* SBSW_OS_FC_PRECONDITION */
                          &(Alarm->Job), Increment) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_TOO_HIGH_2;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueLeMaxAllowed(                                                                     /* SBSW_OS_FC_PRECONDITION */
                          &(Alarm->Job), Cycle) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_TOO_HIGH_3;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueGeMinCycleOrZero(                                                                 /* SBSW_OS_FC_PRECONDITION */
                          &(Alarm->Job), Cycle) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_TOO_LOW_3;
  }
  else
  {
    P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT) alarmDyn;

    alarmDyn = Os_AlarmGetDyn(Alarm);                                                                                   /* SBSW_OS_FC_PRECONDITION */

    /* #20 Set alarm's state to SET. */
    alarmDyn->State = OS_ALARMSTATE_SET;                                                                                /* SBSW_OS_AL_DYN */

    /* #30 Set alarm's state to cycle time to Cycle. */
    alarmDyn->Cycle = Cycle;                                                                                            /* SBSW_OS_AL_DYN */

    /* #40 Tell counter to execute alarm's job in Increment ticks. */
    Os_JobAddRel(&Alarm->Job, Increment);                                                                               /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_AlarmSetAbsAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmSetAbsAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Start,
  TickType Cycle
))
{
  Os_StatusType status;

  /* #10 Check alarms dynamic values according to API definition. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(                                                                               /* SBSW_OS_AL_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_FC_PRECONDITION */
                    Os_AlarmGetApplication(Alarm)) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_AlarmCheckIsCanceled(Alarm) == OS_CHECK_FAILED))                                               /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_STATE_1;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueLeMaxAllowed(                                                                     /* SBSW_OS_FC_PRECONDITION */
                        &(Alarm->Job), Start) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_TOO_HIGH_2;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueLeMaxAllowed(                                                                     /* SBSW_OS_FC_PRECONDITION */
                          &(Alarm->Job), Cycle) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_TOO_HIGH_3;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueGeMinCycleOrZero(                                                                 /* SBSW_OS_FC_PRECONDITION */
                          &(Alarm->Job), Cycle) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_VALUE_IS_TOO_LOW_3;
  }
  else
  {
    P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT) alarmDyn;

    alarmDyn = Os_AlarmGetDyn(Alarm);                                                                                   /* SBSW_OS_FC_PRECONDITION */

    /* #20 Set alarm's state to SET. */
    alarmDyn->State = OS_ALARMSTATE_SET;                                                                                /* SBSW_OS_AL_DYN */

    /* #30 Set alarm's state to cycle time to Cycle. */
    alarmDyn->Cycle = Cycle;                                                                                            /* SBSW_OS_AL_DYN */

    /* #40 Tell counter to execute alarm's job in Start ticks. */
    Os_JobAddAbs(&(Alarm->Job), Start);                                                                                 /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_AlarmCancelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_AlarmCancelAlarm,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  Os_StatusType status;

  /* #10 Check alarms dynamic values according to API definition. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(                                                                               /* SBSW_OS_AL_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_FC_PRECONDITION */
                    Os_AlarmGetApplication(Alarm)) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_AlarmCheckIsSet(Alarm) == OS_CHECK_FAILED))                                                    /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_NOFUNC_1;
  }
  else
  {
    /* #20 Set alarm's state to CANCLED. */
    Os_AlarmGetDyn(Alarm)->State = OS_ALARMSTATE_CANCELED;                                                              /* SBSW_OS_AL_DYN */ /* SBSW_OS_FC_PRECONDITION */

    /* #30 Tell counter to remove the alarm job. */
    Os_JobDelete(&(Alarm->Job));                                                                                        /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_AlarmCheckIsCanceled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmCheckIsCanceled,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  return (Os_StdReturnType)(Os_AlarmGetDyn(Alarm)->State == OS_ALARMSTATE_CANCELED);                                    /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AlarmCheckIsSet()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmCheckIsSet,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
))
{
  return (Os_StdReturnType)(Os_AlarmGetDyn(Alarm)->State == OS_ALARMSTATE_SET);                                         /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_AlarmInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_AlarmInit
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  AppModeType AppMode
)
{
  P2CONST(Os_AlarmAutostartConfigType, AUTOMATIC, OS_CONST) autostartConfig;
  P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT) alarmDyn;

  autostartConfig = &Alarm->Autostart;
  alarmDyn = Os_AlarmGetDyn(Alarm);                                                                                     /* SBSW_OS_FC_PRECONDITION */


  /* #10 If the given mode is one of the given alarm autostart modes: */
  if((autostartConfig->ApplicationModes & AppMode) != 0u)
  {
    /* #20 Copy configured Cycle value to current cycle value and set the alarm state to SET. */
    alarmDyn->Cycle = autostartConfig->Cycle;                                                                           /* SBSW_OS_AL_DYN */
    alarmDyn->State = OS_ALARMSTATE_SET;                                                                                /* SBSW_OS_AL_DYN */

    /* #30 Tell the counter to schedule the job, according to autostart configuration. */
    if(autostartConfig->AlarmMode == OS_ALARMMODE_RELATIVE)
    {
      Os_JobAddRel(&(Alarm->Job), autostartConfig->AlarmTime);                                                          /* SBSW_OS_FC_PRECONDITION */
    }
    else
    {
      Os_JobAddAbs(&(Alarm->Job), autostartConfig->AlarmTime);                                                          /* SBSW_OS_FC_PRECONDITION */
    }
  }
  /* #40 Otherwise, set the alarm to CANCELED state. */
  else
  {
    alarmDyn->State = OS_ALARMSTATE_CANCELED;                                                                           /* SBSW_OS_AL_DYN */
  }
}


/***********************************************************************************************************************
 *  Os_AlarmKill()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_AlarmKill
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
)
{
  P2VAR(Os_AlarmType, AUTOMATIC, OS_VAR_NOINIT) alarmDyn;

  alarmDyn = Os_AlarmGetDyn(Alarm);                                                                                     /* SBSW_OS_FC_PRECONDITION */

  /* #10 If the alarm is running: */
  if(alarmDyn->State == OS_ALARMSTATE_SET)
  {
    /* #20 Set alarm's state to CANCLED. */
    alarmDyn->State = OS_ALARMSTATE_CANCELED;                                                                           /* SBSW_OS_AL_DYN */

    /* #30 Tell counter to remove the alarm job. */
    Os_JobDelete(&(Alarm->Job));                                                                                        /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_AlarmActionSetEvent()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_AlarmActionSetEvent
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
)
{
  Os_StatusType status;
  P2CONST(Os_AlarmSetEventConfigType, AUTOMATIC, OS_CONST) alarm;

  /* #10 If no SetEvent action configured: KernelPanic. */
  if(Os_AlarmHasActionSetEvent() == 0u)                                                                                 /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  alarm = Os_AlarmJob2AlarmSetEvent(Job);                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #15 Handle cyclic behavior. */
  Os_AlarmCancelOrReload(&alarm->Alarm);                                                                                /* SBSW_OS_AL_ALARMCANCELORRELOAD_001 */

  /* #20 Call internal behavior to set an event. */
  status = Os_EventSetInternal(alarm->Task, alarm->Mask);                                                               /* SBSW_OS_AL_EVENTSETINTERNAL_001 */

  /* #30 Report error if applicable. */
  Os_ErrReportAlarmActionSetEvent(status, Os_TaskGetId(alarm->Task), alarm->Mask);                                      /* SBSW_OS_AL_ERRREPORTALARMACTIONSETEVENT_001 */
}


/***********************************************************************************************************************
 *  Os_AlarmActionActivateTask()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_AlarmActionActivateTask
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
)
{
  Os_StatusType status;
  P2CONST(Os_AlarmActivateTaskConfigType, AUTOMATIC, OS_CONST) alarm;

  /* #10 If no ActivateTask action configured: KernelPanic. */
  if(Os_AlarmHasActionActivateTask() == 0u)                                                                             /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  alarm = Os_AlarmJob2AlarmActivateTask(Job);                                                                           /* SBSW_OS_FC_PRECONDITION */

  /* #15 Handle cyclic behavior. */
  Os_AlarmCancelOrReload(&alarm->Alarm);                                                                                /* SBSW_OS_AL_ALARMCANCELORRELOAD_003 */

  /* #20 Call internal behavior for activate task. */
  status = Os_TaskActivateTaskInternal(alarm->Task);                                                                    /* SBSW_OS_AL_TASKACTIVATETASKINTERNAL_001 */

  /* #30 Report error if applicable. */
  Os_ErrReportAlarmActionActivateTask(status, Os_TaskGetId(alarm->Task));                                               /* SBSW_OS_AL_ERRREPORTALARMACTIONSETEVENT_001 */
}


/***********************************************************************************************************************
 *  Os_AlarmActionIncrementCounter()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_AlarmActionIncrementCounter
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
)
{
  Os_StatusType status;
  P2CONST(Os_AlarmIncrementCounterConfigType, AUTOMATIC, OS_CONST) alarm;

  /* #10 If no IncrementCounter action configured: KernelPanic. */
  if(Os_AlarmHasActionIncrementCounter() == 0u)                                                                         /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  alarm = Os_AlarmJob2AlarmIncrementCounter(Job);                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #15 Handle cyclic behavior. */
  Os_AlarmCancelOrReload(&alarm->Alarm);                                                                                /* SBSW_OS_AL_ALARMCANCELORRELOAD_002 */

  /* #20 Call internal behavior for increment counter. */
  status = Os_CounterIncrementInternal(alarm->Counter);                                                                 /* SBSW_OS_AL_COUNTERINCREMENTINTERNAL_001 */

  /* #30 Report error if applicable. */
  Os_ErrReportAlarmActionIncrementCounter(status);
}


/***********************************************************************************************************************
 *  Os_AlarmActionCallback()
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
FUNC(void, OS_CODE) Os_AlarmActionCallback
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
)
{
  P2CONST(Os_AlarmCallbackConfigType, AUTOMATIC, OS_CONST) alarm;
  Os_CallContextType prevCallContext;
  P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) coreAsr;

  /* #10 If no Callback action configured: KernelPanic. */
  if(Os_AlarmHasActionCallback() == 0u)                                                                                 /* COV_OS_INVSTATE */ /* PRQA S 2991, 2995 */ /* MD_Os_Rule14.3_2991, MD_Os_Rule2.2_2995 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  coreAsr = Os_JobGetCore(Job);                                                                                         /* SBSW_OS_FC_PRECONDITION */
  alarm = Os_AlarmJob2AlarmCallback(Job);                                                                               /* SBSW_OS_FC_PRECONDITION */

  /* #15 Handle cyclic behavior. */
  Os_AlarmCancelOrReload(&alarm->Alarm);                                                                                /* SBSW_OS_AL_ALARMCANCELORRELOAD_004 */

  prevCallContext = Os_ThreadSwitchType(Os_CoreGetThread(), OS_CALLCONTEXT_ALARMCALLBACK);                              /* SBSW_OS_AL_THREADSWITCHTYPE_001 */

  /* #20 Enter critical user section. */
  Os_CoreCriticalUserSectionEnter(coreAsr);                                                                             /* SBSW_OS_AL_CORECRITICALUSERSECTIONENTER_001 */

  /* #30 Execute the alarm-callback routine (with switch of callcontext). */
  alarm->AlarmCallback();                                                                                               /* SBSW_OS_AL_ALARM_CALLBACK_001 */

  /* #40 Leave critical user section. */
  Os_CoreCriticalUserSectionLeave(coreAsr);                                                                             /* SBSW_OS_AL_CORECRITICALUSERSECTIONLEAVE_001 */

  (void) Os_ThreadSwitchType(Os_CoreGetThread(), prevCallContext);                                                      /* SBSW_OS_AL_THREADSWITCHTYPE_001 */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_AlarmGetAlarmLocal()
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_AlarmGetAlarmLocal                                                                      /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickRefType Tick
)
{
  return Os_AlarmGetAlarm(Alarm, Tick);                                                                                 /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AlarmSetRelAlarmLocal()
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_AlarmSetRelAlarmLocal                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Increment,
  TickType Cycle
)
{
  return Os_AlarmSetRelAlarm(Alarm, Increment, Cycle);                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AlarmSetAbsAlarmLocal()
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_AlarmSetAbsAlarmLocal                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Start,
  TickType Cycle
)
{
  return Os_AlarmSetAbsAlarm(Alarm, Start, Cycle);                                                                      /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_AlarmCancelAlarmLocal()
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_AlarmCancelAlarmLocal                                                                   /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
)
{
  return Os_AlarmCancelAlarm(Alarm);                                                                                    /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_Api_GetAlarmBase()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetAlarmBase
(
  AlarmType AlarmID,
  AlarmBaseRefType Info
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(AlarmID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_AL_THREADCHECKCALLCONTEXT_001 */
                          currentThread, OS_APICONTEXT_GETALARMBASE) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_AL_THREADCHECKAREINTERRUPTSENABLED_001 */
                          currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) me;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    me = Os_AlarmId2Alarm(AlarmID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_AL_THREADGETCURRENTAPPLICATION_001 */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication, Os_AlarmGetAccessingApplications(me)) == OS_CHECK_FAILED))     /* SBSW_OS_AL_APPCHECKACCESS_001 */ /* SBSW_OS_AL_ALARMGETACCESSINGAPPLICATIONS_001 */
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    /* Because we read constant data, which are actually not dependent on the application state,
     * the application state can be checked without locks. */
    else if(OS_UNLIKELY(Os_AppCheckIsAccessible(Os_AlarmGetApplication(me)) == OS_CHECK_FAILED))                        /* SBSW_OS_AL_APPCHECKISACCESSIBLE_001 */ /* SBSW_OS_AL_ALARMGETAPPLICATION_001 */

    {
      status = OS_STATUS_NOTACCESSIBLE_1;
    }
    else
    {
      P2CONST(Os_CounterCharacteristicsConfigType, AUTOMATIC, OS_CONST) characteristics;

      /* #20 Copy the values from the counter into Info. */
      characteristics = Os_JobGetCharacteristics(&(me->Job));                                                           /* SBSW_OS_AL_JOBGETCHARACTERISTICS_001 */
      Info->maxallowedvalue = characteristics->MaxAllowedValue;                                                         /* SBSW_OS_PWA_PRECONDITION */
      Info->ticksperbase = characteristics->TicksPerBase;                                                               /* SBSW_OS_PWA_PRECONDITION */
      Info->mincycle = characteristics->MinCycle;                                                                       /* SBSW_OS_PWA_PRECONDITION */

      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_GetAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetAlarm
(
  AlarmType AlarmID,
  TickRefType Tick
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(AlarmID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_AL_THREADCHECKCALLCONTEXT_001 */
                          currentThread, OS_APICONTEXT_GETALARM) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_AL_THREADCHECKAREINTERRUPTSENABLED_001 */
                          currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) me;

    me = Os_AlarmId2Alarm(AlarmID);

    if(OS_UNLIKELY(Os_AppCheckAccess( Os_ThreadGetCurrentApplication(currentThread),                                    /* SBSW_OS_AL_APPCHECKACCESS_001 */ /* SBSW_OS_AL_THREADGETCURRENTAPPLICATION_001 */ /* SBSW_OS_AL_ALARMGETACCESSINGAPPLICATIONS_001 */
                                      Os_AlarmGetAccessingApplications(me))
                                        == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) targetCore;

      targetCore = Os_JobGetCore(&(me->Job));                                                                           /* SBSW_OS_AL_JOBGETCORE_001 */

      /* #20 If the given alarm belongs to the local core, get the alarm. */
      if(OS_LIKELY(Os_CoreAsrIsCoreLocal(targetCore) != 0u))                                                            /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */ /* SBSW_OS_AL_COREASRISCORELOCAL_001 */
      {
        Os_IntStateType intState;

        Os_IntSuspend(&intState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

        status = Os_AlarmGetAlarm(me, Tick);                                                                            /* SBSW_OS_AL_ALARMGETALARM_001 */

        Os_IntResume(&intState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
      }
      /* #30 Otherwise, send signal to foreign core to get the relative alarm. */
      else
      {
        status = Os_XSigSend_GetAlarm(targetCore, currentThread, AlarmID, Tick);                                        /* SBSW_OS_AL_XSIGSEND_001 */
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_SetRelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_SetRelAlarm
(
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(AlarmID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_AL_THREADCHECKCALLCONTEXT_001 */
                          currentThread, OS_APICONTEXT_SETRELALARM) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_AL_THREADCHECKAREINTERRUPTSENABLED_001 */
                          currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) me;

    me = Os_AlarmId2Alarm(AlarmID);

    if(OS_UNLIKELY(Os_AppCheckAccess( Os_ThreadGetCurrentApplication(currentThread),                                    /* SBSW_OS_AL_APPCHECKACCESS_001 */ /* SBSW_OS_AL_THREADGETCURRENTAPPLICATION_001 */ /* SBSW_OS_AL_ALARMGETACCESSINGAPPLICATIONS_001 */
                                      Os_AlarmGetAccessingApplications(me)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) targetCore;

      targetCore = Os_JobGetCore(&(me->Job));                                                                           /* SBSW_OS_AL_JOBGETCORE_001 */

      /* #20 If the given alarm belongs to the local core, setup relative alarm. */
      if(OS_LIKELY(Os_CoreAsrIsCoreLocal(targetCore) != 0u))                                                            /* SBSW_OS_AL_COREASRISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType intState;

        Os_IntSuspend(&intState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

        status = Os_AlarmSetRelAlarm(me, Increment, Cycle);                                                             /* SBSW_OS_AL_ALARMSETRELALARM_001 */

        Os_IntResume(&intState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
      }
      /* #30 Otherwise, send signal to foreign core to setup a relative alarm. */
      else
      {
        status = Os_XSigSend_SetRelAlarm(                                                                               /* SBSW_OS_AL_XSIGSEND_001 */
                    targetCore, currentThread, AlarmID, Increment, Cycle);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_SetAbsAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_SetAbsAlarm
(
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(AlarmID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_AL_THREADCHECKCALLCONTEXT_001 */
                          currentThread, OS_APICONTEXT_SETABSALARM) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_AL_THREADCHECKAREINTERRUPTSENABLED_001 */
                          currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) me;

    me = Os_AlarmId2Alarm(AlarmID);

    if(OS_UNLIKELY(Os_AppCheckAccess( Os_ThreadGetCurrentApplication(currentThread),                                    /* SBSW_OS_AL_APPCHECKACCESS_001 */ /* SBSW_OS_AL_THREADGETCURRENTAPPLICATION_001 */ /* SBSW_OS_AL_ALARMGETACCESSINGAPPLICATIONS_001 */
                                      Os_AlarmGetAccessingApplications(me))
                                     == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) targetCore;

      targetCore = Os_JobGetCore(&(me->Job));                                                                           /* SBSW_OS_AL_JOBGETCORE_001 */

      /* #20 If the given alarm belongs to the local core, setup absolute alarm. */
      if(OS_LIKELY(Os_CoreAsrIsCoreLocal(targetCore) != 0u))                                                            /* SBSW_OS_AL_COREASRISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType intState;

        Os_IntSuspend(&intState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

        status = Os_AlarmSetAbsAlarm(me, Start, Cycle);                                                                 /* SBSW_OS_AL_ALARMSETABSALARM_001 */

        Os_IntResume(&intState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
      }
      /* #30 Otherwise, send signal to foreign core to setup an absolute alarm. */
      else
      {
        status = Os_XSigSend_SetAbsAlarm(                                                                               /* SBSW_OS_AL_XSIGSEND_001 */
                    targetCore, currentThread, AlarmID, Start, Cycle);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_CancelAlarm()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_CancelAlarm
(
  AlarmType AlarmID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_AlarmCheckId(AlarmID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(                                                                        /* SBSW_OS_AL_THREADCHECKCALLCONTEXT_001 */
                          currentThread, OS_APICONTEXT_CANCELALARM) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(                                                               /* SBSW_OS_AL_THREADCHECKAREINTERRUPTSENABLED_001 */
                          currentThread) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) me;

    me = Os_AlarmId2Alarm(AlarmID);

    if(OS_UNLIKELY(Os_AppCheckAccess(Os_ThreadGetCurrentApplication(currentThread), Os_AlarmGetAccessingApplications(me)/* SBSW_OS_AL_APPCHECKACCESS_001 */ /* SBSW_OS_AL_THREADGETCURRENTAPPLICATION_001 */ /* SBSW_OS_AL_ALARMGETACCESSINGAPPLICATIONS_001 */
                                      ) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST) targetCore;

      targetCore = Os_JobGetCore(&(me->Job));                                                                           /* SBSW_OS_AL_JOBGETCORE_001 */

      /* #20 If the given alarm belongs to the local core, cancel alarm. */
      if(OS_LIKELY(Os_CoreAsrIsCoreLocal(targetCore) != 0u))                                                            /* SBSW_OS_AL_COREASRISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType intState;

        Os_IntSuspend(&intState);                                                                                       /* SBSW_OS_FC_POINTER2LOCAL */

        status = Os_AlarmCancelAlarm(me);                                                                               /* SBSW_OS_AL_ALARMCANCELALRM_001 */

        Os_IntResume(&intState);                                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
      }
      /* #30 Otherwise, send signal to foreign core to cancel given alarm. */
      else
      {
        status = Os_XSigSend_CancelAlarm(targetCore, currentThread, AlarmID);                                           /* SBSW_OS_AL_XSIGSEND_001 */
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

\ID SBSW_OS_AL_JOBGETDYN_001
 \DESCRIPTION    The pointer passed to Os_JobGetDyn is derived from an argument passed to the caller function.
                 As the caller of the caller function is enforced by preconditions to pass valid arguments only, the
                 pointer is correct. Preconditions are checked during code review.
 \COUNTERMEASURE \N None, as the pointer validity is guaranteed.

\ID SBSW_OS_AL_JOBRELOAD_001
 \DESCRIPTION    The pointer passed to Os_JobReload is derived from an argument passed to the caller function.
                 As the caller of the caller function is enforced by preconditions to pass valid arguments only, the
                 pointer is correct. Preconditions are checked during code review.
 \COUNTERMEASURE \N None, as the pointer validity is guaranteed.

\ID SBSW_OS_AL_DYN
 \DESCRIPTION    Write access to the dynamic data of an alarm.
 \COUNTERMEASURE \M [CM_OS_ALARM_DYN_M]

\ID SBSW_OS_AL_APPCHECKISACCESSIBLE_001
 \DESCRIPTION    Os_AppCheckIsAccessible is called with the return value of Os_AlarmGetApplication.
 \COUNTERMEASURE \M [CM_OS_ALARMGETAPPLICATION_M]

\ID SBSW_OS_AL_ALARMCANCELORRELOAD_001
 \DESCRIPTION    Os_AlarmCancelOrReload is called with the return value of Os_AlarmJob2AlarmSetEvent.
 \COUNTERMEASURE \M [CM_OS_ALARMJOB2ALARMSETEVENT_M]

\ID SBSW_OS_AL_ALARMCANCELORRELOAD_002
 \DESCRIPTION    Os_AlarmCancelOrReload is called with the return value of Os_AlarmJob2AlarmIncrementCounter.
 \COUNTERMEASURE \M [CM_OS_ALARMJOB2ALARMINCREMENTCOUNTER_M]

\ID SBSW_OS_AL_ALARMCANCELORRELOAD_003
 \DESCRIPTION    Os_AlarmCancelOrReload is called with the return value of Os_AlarmJob2AlarmActivateTask.
 \COUNTERMEASURE \M [CM_OS_ALARMJOB2ALARMACTIVATETASK_M]

\ID SBSW_OS_AL_ALARMCANCELORRELOAD_004
 \DESCRIPTION    Os_AlarmCancelOrReload is called with the return value of Os_AlarmJob2AlarmCallback.
 \COUNTERMEASURE \M [CM_OS_ALARMJOB2ALARMCALLBACK_M]

\ID SBSW_OS_AL_EVENTSETINTERNAL_001
 \DESCRIPTION    Os_EventSetInternal is called with the return value of Os_AlarmJob2AlarmSetEvent.
 \COUNTERMEASURE \M [CM_OS_ALARM_EVENTTASK_M]
                 \M [CM_OS_ALARMJOB2ALARMSETEVENT_M]

\ID SBSW_OS_AL_ERRREPORTALARMACTIONSETEVENT_001
 \DESCRIPTION    Os_ErrReportAlarmActionSetEvent is called with the return value of Os_AlarmJob2AlarmSetEvent.
 \COUNTERMEASURE \M [CM_OS_ALARM_TASK_M]
                 \M [CM_OS_ALARMJOB2ALARMSETEVENT_M]

\ID SBSW_OS_AL_ERRREPORTALARMACTIONACTIVATETASK_001
 \DESCRIPTION    Os_ErrReportAlarmActionActivateTask is called with the return value of Os_AlarmJob2AlarmActivateTask.
 \COUNTERMEASURE \M [CM_OS_ALARM_TASK_M]
                 \M [CM_OS_ALARMJOB2ALARMACTIVATETASK_M]

\ID SBSW_OS_AL_TASKACTIVATETASKINTERNAL_001
 \DESCRIPTION    Os_TaskActivateTaskInternal is called with the return value of Os_AlarmJob2AlarmActivateTask.
                 The alarm object is valid
 \COUNTERMEASURE \M [CM_OS_ALARM_TASK_M]
                 \M [CM_OS_ALARMJOB2ALARMACTIVATETASK_M]

\ID SBSW_OS_AL_COUNTERINCREMENTINTERNAL_001
 \DESCRIPTION    Os_CounterIncrementInternal is called with the return value of Os_AlarmJob2AlarmIncrementCounter.
                 The alarm object is valid.
 \COUNTERMEASURE \M [CM_OS_ALARM_COUNTER_M]
                 \M [CM_OS_ALARMJOB2ALARMINCREMENTCOUNTER_M]

\ID SBSW_OS_AL_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_AL_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION    Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_AL_ALARMGETAPPLICATION_001
 \DESCRIPTION    Os_AlarmGetApplication is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_JOBGETCORE_001
 \DESCRIPTION    Os_JobGetCore is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_THREADGETCORE_001
 \DESCRIPTION    Os_ThreadGetCore is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_AL_ALARMGETALARM_001
 \DESCRIPTION    Os_AlarmGetAlarm is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_XSIGSEND_001
 \DESCRIPTION    A cross core send function is called, with the return values of Os_JobGetCore() and Os_CoreGetThread().
                 Correctness of Os_CoreGetThread is ensured by preconditions.
 \COUNTERMEASURE \M [CM_OS_JOBGETCORE_M]

\ID SBSW_OS_AL_ALARMGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_AlarmGetApplication is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_ALARMSETRELALARM_001
 \DESCRIPTION    Os_AlarmSetRelAlarm is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_ALARMSETABSALARM_001
 \DESCRIPTION    Os_AlarmSetAbsAlarm is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_ALARMCANCELALRM_001
 \DESCRIPTION    Os_AlarmCancelAlarm is called with the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_JOBGETCHARACTERISTICS_001
 \DESCRIPTION    Os_JobGetCharacteristics is called with a value derived from the return value of Os_AlarmId2Alarm.
 \COUNTERMEASURE \M [CM_OS_ALARMID2ALARM_M]

\ID SBSW_OS_AL_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_AL_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_AL_ALARM_CALLBACK_001
 \DESCRIPTION    The callback pointer of a callback alarm is used as function pointer..
 \COUNTERMEASURE \M [CM_OS_ALARM_CALLBACK_M]

\ID SBSW_OS_AL_THREADSWITCHTYPE_001
 \DESCRIPTION    Os_ThreadSwitchType is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_AL_CORECRITICALUSERSECTIONENTER_001
 \DESCRIPTION    Os_CoreCriticalUserSectionEnter is called with the return value of Os_JobGetCore().
 \COUNTERMEASURE \M [CM_OS_JOBGETCORE_M]

\ID SBSW_OS_AL_CORECRITICALUSERSECTIONLEAVE_001
 \DESCRIPTION    Os_CoreCriticalUserSectionLeave is called with the return value of Os_JobGetCore().
 \COUNTERMEASURE \M [CM_OS_JOBGETCORE_M]

\ID SBSW_OS_AL_COREASRISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrIsCoreLocal is called with the return value of Os_JobGetCore().
 \COUNTERMEASURE \M [CM_OS_JOBGETCORE_M]


SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_ALARMGETCORE_M
      [CM_OS_JOBGETCORE_M]

\CM CM_OS_ALARMID2ALARM_M
      Verify that:
        1. each alarm pointer except the last in OsCfg_AlarmRefs is no NULL_PTR,
        2. the size of OsCfg_AlarmRefs is equal to OS_ALARMID_COUNT + 1 and
        3. each element in AlarmType has a lower value than OS_ALARMID_COUNT.

\CM CM_OS_ALARMGETAPPLICATION_M
      Verify that the OwnerApplication reference in each alarm instance is a non NULL_PTR.

\CM CM_OS_ALARM_DYN_M
      Verify that the Job Dyn pointer of each alarm in OsCfg_AlarmRefs is initialized with the correct type according to
      the type of the alarm.

\CM CM_OS_ALARMJOB2ALARMSETEVENT_M
      Verify that the alarm callback of each set event alarm is Os_AlarmActionSetEvent and that Os_AlarmActionSetEvent
      is referenced by no other object.

\CM CM_OS_ALARMJOB2ALARMACTIVATETASK_M
      Verify that the alarm callback of each activate task alarm is Os_AlarmActionActivateTask and that
      Os_AlarmActionActivateTask is referenced by no other object.

\CM CM_OS_ALARMJOB2ALARMINCREMENTCOUNTER_M
      Verify that the alarm callback of each increment counter alarm is Os_AlarmActionIncrementCounter and that
      Os_AlarmActionIncrementCounter is referenced by no other object.

\CM CM_OS_ALARMJOB2ALARMCALLBACK_M
      Verify that the alarm callback of each callback alarm is Os_AlarmActionCallback and that
      Os_AlarmActionCallback is referenced by no other object.

\CM CM_OS_ALARM_EVENTTASK_M
      Verify that each alarm in OsCfg_AlarmRefs of type Os_AlarmSetEventConfigType has a valid Task pointer.

\CM CM_OS_ALARM_TASK_M
      Verify that each alarm in OsCfg_AlarmRefs of type Os_AlarmActivateTaskConfigType has a valid Task pointer.

\CM CM_OS_ALARM_COUNTER_M
      Verify that each alarm in OsCfg_AlarmRefs of type Os_AlarmIncrementCounterConfigType has a Counter  pointer.

\CM CM_OS_ALARM_CALLBACK_M
      Verify that each alarm in OsCfg_AlarmRefs of type Os_AlarmCallbackConfigType has a AlarmCallback pointer.

*/

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Alarm.c
 **********************************************************************************************************************/
