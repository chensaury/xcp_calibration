/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *  Copyright (c) 2019 by Vector Informatik GmbH.                                              All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Alarm Alarm
 *  \brief       Alarm management.
 *  \details
 *  This module provides the alarm management interface defined by OSEK/AUTOSAR OS.
 *
 *  ### SetRelAlarm ###
 *  ![Set an alarm relative to now](Alarm_SetRelAlarm.png)
 *
 *  ### SetAbsAlarm ###
 *  ![Set an alarm with an absolute start](Alarm_SetAbsAlarm.png)
 *
 *  ### Alarm Handling ###
 *  ![Alarm handling](Alarm_Handling.png)
 *
 *
 *  \trace CREQ-138
 *
 *  \{
 *
 *  \file
 *  \brief       OS internal functions to work with alarms.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_ALARMINT_H
# define OS_ALARMINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_Alarm_Types.h"
# include "Os_Alarm_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_Counter_Types.h"
# include "Os_Application_Types.h"
# include "Os_JobInt.h"
# include "Os_Task_Types.h"
# include "Os_Common_Types.h"

/* Os Hal dependencies */
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/

/*! Cycle value for non cyclic alarms. */
#define OS_ALARM_SINGLE_SHOT       ((TickType)0)

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! Type cast from Os_AlarmType to Os_JobType by use of base element addressing. */
#define OS_ALARM_CASTDYN_ALARM_2_JOB(alarm)                       (&((alarm).Job))                                      /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_AlarmActivateTaskConfigType to Os_AlarmConfigType by use of base element addressing. */
#define OS_ALARM_CASTCONFIG_ALARMACTIVATETASK_2_ALARM(alarm)      (&((alarm).Alarm))                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_AlarmSetEventConfigType to Os_AlarmConfigType by use of base element addressing. */
#define OS_ALARM_CASTCONFIG_ALARMSETEVENT_2_ALARM(alarm)          (&((alarm).Alarm))                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_AlarmIncrementCounterConfigType to Os_AlarmConfigType by use of base element addressing. */
#define OS_ALARM_CASTCONFIG_ALARMINCREMENTCOUNTER_2_ALARM(alarm)  (&((alarm).Alarm))                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Type cast from Os_AlarmCallbackConfigType to Os_AlarmConfigType by use of base element addressing. */
#define OS_ALARM_CASTCONFIG_ALARMCALLBACK_2_ALARM(alarm)          (&((alarm).Alarm))                                    /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Specifies the meaning of a value. */
typedef enum
{
  /*! The alarm time is absolute. */
  OS_ALARMMODE_ABSOLUTE,
  /*! The alarm time is relative. */
  OS_ALARMMODE_RELATIVE
}Os_AlarmModeType;


/*! Specifies the current state of an alarm. */
typedef enum
{
  /*! The alarm is disabled. */
  OS_ALARMSTATE_CANCELED,
  /*! The alarm is enabled. */
  OS_ALARMSTATE_SET
}Os_AlarmStateType;


/*! Autostart configuration of an alarm. */
typedef struct
{
  /*! The time in ticks of the first alarm event.
   * The interpretation of this value depends on AlarmMode. */
  TickType AlarmTime;

  /*! The cycle time in ticks. */
  TickType Cycle;

  /*! Application modes where the alarm shall be activated during OS initialization.
   * \trace SPEC-63896
   */
  AppModeType ApplicationModes;

  /*! Defines the autostart mode. */
  Os_AlarmModeType AlarmMode;
}Os_AlarmAutostartConfigType;


/*! Dynamic information of alarms.
 * \extends Os_JobType
 */
typedef struct
{
  /*! Dynamic information of the Alarm's job.
   * This attribute must come first! */
  Os_JobType Job;

  /*! Periodicity of the alarm in counter ticks. Zero for non-cyclic alarms. */
  TickType Cycle;

  /*! The current state of the alarm. */
  Os_AlarmStateType State;
}Os_AlarmType;


/*!
 * \brief Configuration information of alarms.
 * \details
 * The dynamic data pointer an alarm can be fetched with Os_AlarmGetDyn().
 * \extends Os_JobConfigType
 */
struct Os_AlarmConfigType_Tag
{
  /*! The job which triggers the alarm.
   * This attribute must come first! */
  Os_JobConfigType Job;

  /*! Autostart data of the alarm. */
  Os_AlarmAutostartConfigType Autostart;

  /*! Reference to applications which access this object. */
  Os_AppAccessMaskType AccessingApplications;

  /*! The application to which the alarm belongs. */
  P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) OwnerApplication;
};


/*!
 * Configuration information of alarms, which set events.
 * \extends Os_AlarmConfigType
 */
struct Os_AlarmSetEventConfigType_Tag
{
  /*! The alarm which holds the general data.
   * This attribute must come first! */
  Os_AlarmConfigType Alarm;

  /*! The task, who's event has to be set. */
  P2CONST(Os_TaskConfigType, TYPEDEF, OS_CONST) Task;

  /*! The events, to be set. */
  EventMaskType Mask;
};


/*!
 * Configuration information of alarms, which activate tasks.
 * \extends Os_AlarmConfigType
 */
struct Os_AlarmActivateTaskConfigType_Tag
{
  /*! The alarm which holds the general data.
   * This attribute must come first! */
  Os_AlarmConfigType Alarm;

  /*! The task, to be activated. */
  P2CONST(Os_TaskConfigType, TYPEDEF, OS_CONST) Task;
};


/*!
 * Configuration information of alarms, which increment counters.
 * \extends Os_AlarmConfigType
 * \trace SPEC-63865
 */
struct Os_AlarmIncrementCounterConfigType_Tag
{
  /*! The alarm which holds the general data.
   * This attribute must come first! */
  Os_AlarmConfigType Alarm;

  /*! The counter, to be incremented. */
  P2CONST(Os_CounterConfigType, AUTOMATIC, OS_CONST) Counter;
};


/***********************************************************************************************************************
 *  Os_AlarmCallbackType()
 **********************************************************************************************************************/
/*! \brief        Function pointer type of an alarm-callback function.
 *  \details      The alarm-callback function pointers shall have this kind of prototype.
 **********************************************************************************************************************/
typedef P2FUNC(void, OS_CODE, Os_AlarmCallbackType)(void);


/*!
 * Configuration information of alarms, which call alarm-callbacks.
 * \extends Os_AlarmConfigType
 * \trace SPEC-63965
 */
struct Os_AlarmCallbackConfigType_Tag
{
  /*! The alarm which holds the general data.
   * This attribute must come first! */
  Os_AlarmConfigType Alarm;

  /*! The callback function, to be called. */
  Os_AlarmCallbackType AlarmCallback;
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
 *  Os_AlarmInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given alarm for the first time.
 *  \details        The kernel uses this function to initialize all alarms during OS initialization (Init-Step4).
 *                  If the given application mode is on of the task's autostart modes, this function activates
 *                  the given alarm. It sets all dynamic data of the given alarm to its configured startup settings.
 *
 *  \param[in,out]  Alarm  The alarm which shall be initialized. Parameter must not be NULL.
 *  \param[in]      AppMode The current application mode.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Not called before for the given object.
 *
 *  \trace          SPEC-63688
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AlarmInit
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  AppModeType AppMode
);


/***********************************************************************************************************************
 *  Os_AlarmKill()
 **********************************************************************************************************************/
/*! \brief          Kill the given alarm.
 *  \details        Set the alarm state to canceled.
 *
 *  \param[in,out]  Alarm  Alarm to kill. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different alarms.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AlarmKill
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
);


/***********************************************************************************************************************
 *  Os_AlarmGetCore()
 **********************************************************************************************************************/
/*! \brief          Returns the core of the given alarm.
 *  \details        --no details--
 *
 *  \param[in]      Alarm        Alarm to query. Parameter must not be NULL.
 *
 *  \return         The alarm's core.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmGetCore,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  Os_AlarmCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      AlarmId        The ID to check.
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
OS_ALWAYS_INLINE, Os_AlarmCheckId,
(
  AlarmType AlarmId
));


/***********************************************************************************************************************
 *  Os_AlarmId2Alarm()
 **********************************************************************************************************************/
/*! \brief          Converts the ID into an object.
 *  \details        --no details--
 *
 *  \param[in]      AlarmId     The ID to convert. The Id must be in the range [0, OS_ALARMID_COUNT).
 *
 *  \return         The corresponding object.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmId2Alarm,
(
  AlarmType AlarmId
));


/***********************************************************************************************************************
 *  Os_AlarmGetApplication()
 **********************************************************************************************************************/
/*! \brief        Returns the owner application of the given alarm.
 *  \details        --no details--
 *
 *  \param[in]    Alarm  Alarm to query. Parameter must not be NULL.
 *
 *  \return       Owner application of the given alarm.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_AlarmGetApplication,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  Os_AlarmGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief          Get applications which have access to the given object.
 *  \details        --no details--
 *
 *  \param[in]      Alarm  The object to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_AlarmGetAccessingApplications,
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
));


/***********************************************************************************************************************
 *  Os_AlarmActionSetEvent()
 **********************************************************************************************************************/
/*! \brief          Alarm action handler for set event alarms.
 *  \details        This is a callback function, which is called by the job management.
 *                  It is called, if an alarm expires, which has OsAlarmAction configured to be OsAlarmSetEvent.
 *
 *  \see            \ref Os_JobCallbackType
 *
 *  \param[in,out]  Job    The job which contains the alarm data. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a 'set event' alarm.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given job is removed from the job management.
 *  \trace          SPEC-63827, SPEC-63707
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AlarmActionSetEvent
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
);


/***********************************************************************************************************************
 *  Os_AlarmActionActivateTask()
 **********************************************************************************************************************/
/*! \brief          Alarm action handler for activate task alarms.
 *  \details        This is a callback function, which is called by the job management.
 *                  It is called, if an alarm expires, which has OsAlarmAction configured to be OsAlarmActivateTask.
 *
 *  \see            \ref Os_JobCallbackType
 *
 *  \param[in,out]  Job    The job which contains the alarm data. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a 'activate task' alarm.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given job is not scheduled.
 *
 *  \trace          SPEC-63722, SPEC-63707
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AlarmActionActivateTask
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
);


/***********************************************************************************************************************
 *  Os_AlarmActionIncrementCounter()
 **********************************************************************************************************************/
/*! \brief          Alarm action handler for increment counter alarms.
 *  \details        This is a callback function, which is called by the job management.
 *                  It is called, if an alarm expires, which has OsAlarmAction configured to be OsAlarmIncrementCounter.
 *
 *  \see            \ref Os_JobCallbackType
 *
 *  \param[in,out]  Job    The job which contains the alarm data. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a 'increment counter' alarm.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given job is not scheduled.

 *  \trace          SPEC-63865, SPEC-63707
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AlarmActionIncrementCounter
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
);


/***********************************************************************************************************************
 *  Os_AlarmActionCallback()
 **********************************************************************************************************************/
/*! \brief          Alarm action handler for callback alarms.
 *  \details        This is a callback function, which is called by the job management.
 *                  It is called, if an alarm expires, which has OsAlarmAction configured to be OsAlarmCallback.
 *
 *  \see            \ref Os_JobCallbackType
 *
 *  \context        OS_INTERNAL
 *
 *  \param[in,out]  Job    The job which contains the alarm data. Parameter must not be NULL.
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The caller has to ensure, that the given job is a 'callback' alarm.
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given job is not scheduled.
 *
 *  \trace          CREQ-142
 *  \trace          SPEC-63868, SPEC-63707
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_AlarmActionCallback
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
);


/***********************************************************************************************************************
 *  Os_AlarmGetAlarmLocal()
 **********************************************************************************************************************/
/*! \brief        Gets the alarm from the local core.
 *  \details      --no details--
 *
 *  \param[in]    Alarm       Reference to the alarm element. Parameter must not be NULL.
 *  \param[out]   Tick        Relative value in ticks before the alarm expires. Parameter must not be NULL.
 *
 *  \context      OS_INTERNAL
 *
 *  \reentrant    TRUE for different alarms.
 *  \synchronous  TRUE
 *
 *  \pre          Given alarm belongs to the local core.
 *  \pre          Concurrent access to given object is prevented by caller.
 *  \pre          Given values have been checked before.
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_AlarmGetAlarmLocal
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickRefType Tick
);


/***********************************************************************************************************************
 *  Os_AlarmSetRelAlarmLocal()
 **********************************************************************************************************************/
/*! \brief          Sets a relative alarm, which belongs to the local core.
 *  \details        --no details--
 *
 *  \param[in,out]  Alarm     Alarm to set. Parameter must not be NULL.
 *  \param[in]      Increment Relative value in ticks.
 *  \param[in]      Cycle     Cycle value in case of cyclic alarm. In case of single alarms, cycle shall be zero.
 *
 *  \return         The status of the call.
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
FUNC(Os_StatusType, OS_CODE) Os_AlarmSetRelAlarmLocal
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Increment,
  TickType Cycle
);


/***********************************************************************************************************************
 *  Os_AlarmSetAbsAlarmLocal()
 **********************************************************************************************************************/
/*! \brief          Sets a absolute alarm, which belongs to the local core.
 *  \details        --no details--
 *
 *  \param[in,out]  Alarm   Alarm to set. Parameter must not be NULL.
 *  \param[in]      Start   Absolute value in ticks.
 *  \param[in]      Cycle   Cycle value in case of cyclic alarm. In case of single alarms, cycle shall be zero.
 *
 *  \return         The status of the call.
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
FUNC(Os_StatusType, OS_CODE) Os_AlarmSetAbsAlarmLocal
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm,
  TickType Start,
  TickType Cycle
);


/***********************************************************************************************************************
 *  Os_AlarmCancelAlarmLocal()
 **********************************************************************************************************************/
/*! \brief          Cancel a given alarm.
 *  \details        --no details--
 *
 *  \param[in,out]  Alarm   Alarm to cancel. Parameter must not be NULL.
 *
 *  \return         The status of the call.
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
FUNC(Os_StatusType, OS_CODE) Os_AlarmCancelAlarmLocal
(
  P2CONST(Os_AlarmConfigType, AUTOMATIC, OS_CONST) Alarm
);

/***********************************************************************************************************************
 *  Os_Api_GetAlarmBase()
 **********************************************************************************************************************/
/*! \brief        OS service GetAlarmBase().
 * \details       For further details see GetAlarmBase().
 *
 *  \param[in]    AlarmID             See GetAlarmBase().
 *  \param[out]   Info                See GetAlarmBase().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid AlarmID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given task's owner application is not accessible.
 *
 *  \context      TASK|ISR2|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetAlarmBase().
 *
 *  \trace        CREQ-19, CREQ-40
 *  \trace        SPEC-64342, SPEC-64293, SPEC-64305, SPEC-63744, SPEC-64017, SPEC-63980, SPEC-63709, SPEC-63752
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetAlarmBase
(
  AlarmType AlarmID,
  AlarmBaseRefType Info
);


/***********************************************************************************************************************
 *  Os_Api_GetAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service GetAlarm().
 *  \details      For further details see GetAlarm().
 *
 *  \param[in]    AlarmID             See GetAlarm().
 *  \param[out]   Tick                See GetAlarm().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_NOFUNC_1        Alarm is not in use.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid AlarmID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2|PRETHOOK|POSTTHOOK
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          See GetAlarm().
 *
 *  \trace        CREQ-93, CREQ-40
 *  \trace        SPEC-63685, SPEC-64331, SPEC-64334, SPEC-64350, SPEC-64366, SPEC-64017, SPEC-63980, SPEC-63709
 *  \trace        SPEC-63752
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetAlarm
(
  AlarmType AlarmID,
  TickRefType Tick
);


/***********************************************************************************************************************
 *  Os_Api_SetRelAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service SetRelAlarm().
 *  \details      For further details see SetRelAlarm().
 *
 *  \param[in]    AlarmID           See SetRelAlarm().
 *  \param[in]    Increment         See SetRelAlarm().
 *  \param[in]    Cycle             See SetRelAlarm().
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_STATE_1           Alarm is already in use.
 *  \retval       OS_STATUS_ID_1              (EXTENDED status:) Invalid AlarmID.
 *  \retval       OS_STATUS_VALUE_IS_ZERO_2   Value of increment is zero.
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_2   (EXTENDED status:) Value of Increment outside of the admissible limits
 *                                                (lower than zero or greater than maxallowedvalue).
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_3   (EXTENDED status:) Value of Cycle outside of the admissible limits
 *                                                (lower than zero or greater than maxallowedvalue).
 *  \retval       OS_STATUS_VALUE_IS_TOO_LOW_3    (EXTENDED status:) Value of Cycle is lower than MinCycle.
 *  \retval       OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT       (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given alarm's owner application is not accessible.
 *  \retval       other                       See Os_XSigSend_SetRelAlarm() and Os_XSigRecv_SetRelAlarm().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given AlarmID belongs to local core.
 *
 *  \pre          See SetRelAlarm().
 *
 *  \trace        CREQ-116, CREQ-40
 *  \trace        SPEC-64320, SPEC-67247, SPEC-64294, SPEC-64303, SPEC-64312, SPEC-64313, SPEC-64318, SPEC-64332
 *  \trace        SPEC-64361, SPEC-63714, SPEC-64048, SPEC-64017, SPEC-63980, SPEC-63709, SPEC-63752
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_SetRelAlarm
(
  AlarmType AlarmID,
  TickType Increment,
  TickType Cycle
);


/***********************************************************************************************************************
 *  Os_Api_SetAbsAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service SetAbsAlarm().
 *  \details      For further details see SetAbsAlarm().
 *
 *  \param[in]    AlarmID           See SetAbsAlarm().
 *  \param[in]    Start             See SetAbsAlarm().
 *  \param[in]    Cycle             See SetAbsAlarm().
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_STATE_1           Alarm is already in use.
 *  \retval       OS_STATUS_ID_1              (EXTENDED status:) Invalid AlarmID.
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_2       (EXTENDED status:) Value of Start outside of the admissible
 *                                                    counter limit (greater than maxallowedvalue).
 *  \retval       OS_STATUS_VALUE_IS_TOO_HIGH_3       (EXTENDED status:) Value of Cycle outside of the admissible
 *                                                    counter limits (greater than maxallowedvalue).
 *  \retval       OS_STATUS_VALUE_IS_TOO_LOW_3        (EXTENDED status:) Value of Cycle unequal to 0 and less than
 *                                                    mincycle.
 *  \retval       OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT       (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given alarm's owner application is not accessible.
 *  \retval       other                       See Os_XSigSend_SetAbsAlarm() and Os_XSigRecv_SetAbsAlarm().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given AlarmID belongs to local core.
 *
 *  \pre          See SetAbsAlarm().
 *
 *  \trace        CREQ-29, CREQ-40
 *  \trace        SPEC-64346, SPEC-64326, SPEC-63731, SPEC-64017, SPEC-63980, SPEC-63709, SPEC-63752, SPEC-64302
 *  \trace        SPEC-64314, SPEC-64333, SPEC-64337, SPEC-64340, SPEC-64348, SPEC-64358
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_SetAbsAlarm
(
  AlarmType AlarmID,
  TickType Start,
  TickType Cycle
);


/***********************************************************************************************************************
 *  Os_Api_CancelAlarm()
 **********************************************************************************************************************/
/*! \brief        OS service CancelAlarm().
 *  \details      For further details see CancelAlarm().
 *
 *  \param[in]    AlarmID           See CancelAlarm().
 *
 *  \retval       OS_STATUS_OK                No error.
 *  \retval       OS_STATUS_NOFUNC_1          Alarm is not in use.
 *  \retval       OS_STATUS_ID_1              (EXTENDED status:) Invalid AlarmID.
 *  \retval       OS_STATUS_CALLEVEL          (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT       (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1    (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1   (Service Protection:) Given alarm's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given AlarmID belongs to local core.
 *
 *  \pre          See CancelAlarm().
 *
 *  \trace        CREQ-164, CREQ-40
 *  \trace        SPEC-64328, SPEC-64301, SPEC-64056, SPEC-64017, SPEC-63980, SPEC-63709, SPEC-63752, SPEC-64304
 *  \trace        SPEC-64353
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_CancelAlarm
(
  AlarmType AlarmID
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_ALARMINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_AlarmInt.h
 **********************************************************************************************************************/
