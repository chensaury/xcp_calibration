/***********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
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
 *  \defgroup    Os_ScheduleTable Schedule Table
 *  \brief       Schedule Table management
 *  \details
 *  Schedule Tables are used to perform a set of actions in a configured chronological order at configured time offsets.
 *  So schedule tables are part of the time system of MICROSAR OS. Each schedule table consists of a set of expiry
 *  points. At any time there is at most one active expiry point per schedule table. Therefore, the expiry points are
 *  not derived from jobs but the schedule table is instead.
 *  Each expiry point consists of a list of actions (task activation or event setting).
 *  The figure below shows the main dependencies between jobs, schedule tables, expiry points and expiry point actions.
 *
 *   ![Schedule Table Data Structure](ScheduleTableDetail.png)
 *
 *  To meet all requirements, the generator needs to add expiry points at zero and at DURATION of the schedule table if
 *  the user hasn't configured them. The callback functions can be identical for all expiry points but the last one.
 *  However, the call back functions need to consider synchronization for all schedule tables which support it.
 *  An example of a generated expiry point list is provided in the figure below.
 *
 *   ![Example of a generated expiry point list](ScheduleTableObjectExample.png)
 *
 *  Synchronous schedule tables are based on two times:
 *   - The base time is delivered by a Os_Counter object.
 *   - The other time is provided non periodically by the user (call of SyncScheduleTable()).
 *
 *  Calling SyncScheduleTable provides a  synchronization point allows to calculate a deviation between both times.
 *  On each expiry point the schedule table work function tries to minimize the deviation.
 *  A schedule table is synchronous, if the counter time lies within a gap around the sync time.
 *
 *   ![Synchronization Process](ScheduleTableSync.png)
 *
 *
 *  ### StartScheduleTableRel
 *  ![Start a schedule table relative to now](SchT_StartScheduleTableRel.png)
 *
 *  ### StartScheduleTableAbs
 *  ![Start a schedule table with an absolute start](SchT_StartScheduleTableAbs.png)
 *
 *  ### ScheduleTable Handling ###
 *  ![ScheduleTable handling](SchT_Handling.png)
 *
 *
 *  \trace CREQ-99, CREQ-298, CREQ-81, CREQ-69, CREQ-67, CREQ-14
 *  \trace SPEC-64001, SPEC-64004, SPEC-64033
 *
 *  \{
 *
 *  \file
 *  \brief       OS internal functions to work with schedule tables.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_SCHEDULETABLEINT_H
# define OS_SCHEDULETABLEINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
# include "Os_ScheduleTable_Types.h"
# include "Os_ScheduleTable_Lcfg.h"

/* Os kernel module dependencies */
# include "Os_JobInt.h"
# include "Os_CoreInt.h"
# include "Os_CommonInt.h"
# include "Os_TaskInt.h"

/* Os hal dependencies */
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/

/*! Dummy cast to make generator's life easier. */
#define OS_SCHT_CASTCONFIG_SCHT_2_SCHT(schT)                (&(schT))                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_SchTSyncConfigType to Os_SchTConfigType by use of base element addressing. */
#define OS_SCHT_CASTCONFIG_SCHTSYNC_2_SCHT(schT)            (&((schT).SchT))                                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_SchTType to Os_JobType by use of base element addressing. */
#define OS_SCHT_CASTDYN_SCHT_2_JOB(schT)                    (&((schT).Job))                                             /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_SchTSyncType to Os_JobType by use of base element addressing. */
#define OS_SCHT_CASTDYN_SCHTSYNC_2_JOB(schT)                (&((schT).SchT.Job))                                        /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! Dummy cast to make generator's life easier. */
#define OS_SCHT_CASTCONFIG_SCHTEXPO_2_SCHTEXPO(exPo)        (&(exPo))                                                   /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */

/*! Type cast from Os_SchTSyncType to Os_SchTExPoConfigType by use of base element addressing. */
#define OS_SCHT_CASTCONFIG_SCHTEXPOSYNC_2_SCHTEXPO(exPo)    (&((exPo).ExPo))                                            /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! \brief    Identifies an event in a list of ExPo events. */
typedef uint32 Os_SchTEventIdxType;

/*! \brief    Identifies a task in a list of ExPo tasks. */
typedef uint32 Os_SchTTaskIdxType;


/*! \brief    Internal representation of schedule table states.
 *  \details  In order to be able to convert this state into the user API state (ScheduleTableStatusType),
 *            the integer values behind the states have to be kept equal. */
typedef enum
{
  /*! The schedule table was stopped or is in default state */
  OS_SCHTSTATUS_STOPPED  = SCHEDULETABLE_STOPPED,
  /*! The schedule table is registered to be the next schedule table after another one has finished. */
  OS_SCHTSTATUS_NEXT     = SCHEDULETABLE_NEXT,
  /*! The schedule table waits for provision of a synchronization count. */
  OS_SCHTSTATUS_WAITING  = SCHEDULETABLE_WAITING,
  /*! The schedule table runs and is synchronous or asynchronous. */
  OS_SCHTSTATUS_RUNNING  = SCHEDULETABLE_RUNNING
} Os_SchTStatusType;


/*! Defines whether a synchronization point has been provided or not. */
typedef enum
{
  /*! No synchronization point has been provided. */
  OS_SCHTSYNCSTATUS_NOT_PROVIDED = 0,
  /*! Synchronization point has been provided and the schedule table is synchronized. */
  OS_SCHTSYNCSTATUS_SYNC,
  /*! Synchronization point has been provided. the schedule table is not synchronized. */
  OS_SCHTSYNCSTATUS_ASYNC
} Os_SchTSyncStatusType;


/*! Configuration information about schedule table expiry point event actions.
 */
struct Os_SchTExPoActionEventConfigType_Tag
{
  /*! The task which shall receive an event. */
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task;

  /*! The event mask to be set for the task. */
  EventMaskType EventMask;
};


/*! Configuration information about schedule table expiry point task activation actions.
 */
struct Os_SchTExPoActionTaskConfigType_Tag
{
  /*! The task which shall be activated. */
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) Task;
};


/*! Configuration type for the kind of schedule table synchronization. */
typedef enum
{
  /*! The schedule table is not synchronized. */
  OS_SCHT_EXPO_KIND_EXECUTE             = 0,
  /*! The ExPo is part of a synchronous schedule table and at least length or shorten is unequal to zero. */
  OS_SCHT_EXPO_KIND_EXECUTE_SYNC        = 1,
  /*! The ExPo is part of a synchronous schedule table and does not perform synchronization. */
  OS_SCHT_EXPO_KIND_EXECUTE_SYNC_ZERO   = 2,
  /*! The ExPo is the last one of a cyclic Schedule Table. */
  OS_SCHT_EXPO_KIND_EXECUTE_CYCLIC      = 3,
  /*! The ExPo is the last one of a single shot Schedule Table. */
  OS_SCHT_EXPO_KIND_EXECUTE_SINGLE_SHOT = 4
}Os_SchTExPoKindType;


/*! Configuration information about a schedule table expiry point. */
struct Os_SchTExPoConfigType_Tag
{
  /*! The next expiry point or a NULL_PTR */
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) Next;

  /*! The type of expiry point. */
  Os_SchTExPoKindType Kind;

  /*! Pointer to an array of task activation actions.
   *  \trace SPEC-64034 */
  P2CONST(Os_SchTExPoActionTaskConfigType, AUTOMATIC, OS_CONST) Tasks;

  /*! The number of tasks: Tasks[TaskCount] */
  Os_SchTTaskIdxType TaskCount;

  /*! Pointer to an array of set event actions.
   *  \trace SPEC-63695 */
  P2CONST(Os_SchTExPoActionEventConfigType, AUTOMATIC, OS_CONST) Events;

  /*! The number of events: Events[EventCount] */
  Os_SchTEventIdxType EventCount;

  /*! The relative offset to the next expiry point.
   *  \trace SPEC-63712 */
  Os_TickType RelOffsetToNext;
};


/*! Configuration of a synchronizing Expiry Point
 * \extends Os_SchTExPoConfigType
 */
struct Os_SchTExPoSyncConfigType_Tag
{
  /*! General configuration of the Expiry Point.
   *  ExPo must be the first member of the structure! */
  Os_SchTExPoConfigType ExPo;

  /*! \brief  The maximum retardation time of the next expiry point.
   * \details This value has to be negative. In order to define a retardation of 2,
   *          initialize this value with (Os_TickType)-2. Typically this equals the two's complement. */
  Os_TickType MaxShortenOfNext;

  /*! The maximum advancement time of the next expiry point. */
  Os_TickType MaxLengthOfNext;
};



/*! Configuration type for the kind of schedule table synchronization */
typedef enum
{
  /*! The schedule table is not synchronized. */
  OS_SCHT_SYNC_KIND_NON      = 0,
  /*! The schedule table is implicitly synchronous to the synchronization counter. */
  OS_SCHT_SYNC_KIND_IMPLICIT = 1,
  /*! The schedule table need explicit synchronization by provision of a sync count. */
  OS_SCHT_SYNC_KIND_EXPLICIT = 2
}Os_SchTSyncKindType;


/*! Configuration type for the autostart mode of a schedule table. */
typedef enum
{
  OS_SCHT_AUTOSTART_NON       = 0, /*!< The schedule table has no autostart. */
  OS_SCHT_AUTOSTART_RELATIVE  = 1, /*!< The schedule table starts at a relative time value. */
  OS_SCHT_AUTOSTART_SYNCHRON  = 2, /*!< The schedule table starts synchronous. */
  OS_SCHT_AUTOSTART_ABSOLUTE  = 3  /*!< The schedule table starts at a configured absolute time value. */
}Os_SchTAutostartModeType;


/*! Configuration of schedule table autostart. */
struct Os_SchTAutostartConfigType_Tag
{
  Os_TickType StartTime;                      /*!< The start time of the schedule table relative or absolute */
  Os_SchTAutostartModeType AutostartModes;    /*!< The autostart mode (absolute/relative/synchron/non) */
  AppModeType ApplicationModes;               /*!< Bit mask of the application modes to start in */
};


/*! Configuration of a schedule table
 * \extends Os_JobConfigType
 * */
struct Os_SchTConfigType_Tag
{
  /*! Configuration of the job which handles this schedule table.
   *  Job must be the first member of the structure! */
  Os_JobConfigType Job;

  /*! Configuration of the autostart. */
  Os_SchTAutostartConfigType Autostart;

  /*! Configuration of the synchronization kind. */
  Os_SchTSyncKindType SyncKind;

  /*! Bit mask with all applications which have access rights. */
  Os_AppAccessMaskType AccessingApplications;

  /*! The owner application of the schedule table. */
  P2CONST(Os_AppConfigType, AUTOMATIC, OS_CONST) OwnerApplication;

  /*! Pointer to the head of the expiry points list.
   *  \trace SPEC-63772 */
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) ExPoHead;

  /*! \brief The schedule table which shall be started at the end of this schedule table.
   *  \details
   *  - InitialNext == NULL_PTR: The schedule table is single shot
   *  - InitialNext == thisScheduleTable: The schedule table is cyclic.
   */
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) InitialNext;
};


/*! Configuration of a schedule table
 * \extends Os_SchTConfigType
 * */
struct Os_SchTSyncConfigType_Tag
{
  /*! Configuration of the job which handles this schedule table.
   *  SchT must be the first member of the structure! */
  Os_SchTConfigType SchT;

  /*! Configured precision of the schedule table. */
  Os_TickType Precision;

  /*! The duration in ticks of this schedule table. */
  Os_TickType Duration;

  /*! The half duration: ceil(Duration/2). */
  Os_TickType DurationHalf;
};


/*! Dynamic information about schedule tables.
 * \extends Os_JobType
 */
struct Os_SchTType_Tag
{
  /*! Dynamic information of the current expiry point's job
   * This attribute must come first! */
  Os_JobType Job;

  /*! Pointer to the currently processed expiry pointer (the one, currently handled by the job) */
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) ExPo;

  /*! The current state of the schedule table. */
  Os_SchTStatusType State;

  /*! The schedule table which shall be started at the end of this schedule table. */
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) Next;

  /*! The schedule table which has nexted this schedule table. */
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) Previous;
};


/*! Dynamic information about synchronized schedule tables.
 * \extends Os_SchTType
 */
struct Os_SchTSyncType_Tag
{
  /*! Dynamic information of the current expiry point's job
   * This attribute must come first! */
  Os_SchTType SchT;

  /*! The current time of this schedule table.
   * The current time is updated at:
   *  -any expiry point
   *  -synchronization step at an expiry point
   *  -provision of a synchronization count (SyncScheduleTable())
   * Value range is 0..duration-1
   */
  Os_TickType SyncTimeStamp;

  /*! The value of the driving counter at the time of the last update of SyncTimeStamp.
   * Value range 0..MAXALLOWEDVALUE of the driving counter.
   */
  Os_TickType CounterTimeStamp;

  /*! The current deviation of the counter time from the synchronization time.
   *  \trace SPEC-63813 */
  Os_TickType Deviation;

  /*! Defines whether a synchronization point is available. */
  Os_SchTSyncStatusType SyncState;
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
 *  Os_SchTInit()
 **********************************************************************************************************************/
/*! \brief          Initialize the given schedule table for the first time (Init-Step4).
 *  \details        If the given application mode is one of the autostart modes, this function activates
 *                  the given schedule table. It sets all dynamic data of the given schedule table to its configured
 *                  startup settings.
 *
 *  \param[in,out]  SchT    The schedule table which shall be initialized. Parameter must not be NULL.
 *  \param[in]      AppMode The current application mode.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-63644
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchTInit
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT,
  AppModeType AppMode
);


/***********************************************************************************************************************
 *  Os_SchTKill()
 **********************************************************************************************************************/
/*! \brief          Kills the given schedule table.
 *  \details        --no details--
 *
 *  \param[in,out]  SchT    Schedule table to kill. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different schedule table.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchTKill
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
);


/***********************************************************************************************************************
 *  Os_SchTCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck()
 *                  is returned.
 *
 *  \param[in]      ScheduleTableId       The ID to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given ID is valid.
 *  \retval         OS_CHECK_FAILED       If the given ID is not valid.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckId,
(
  ScheduleTableType ScheduleTableId
));


/***********************************************************************************************************************
 *  Os_SchTId2SchT()
 **********************************************************************************************************************/
/*! \brief          Returns the schedule table which belongs to the given id.
 *  \details        --no details--
 *
 *  \param[in]      SchTId   A schedule table id. Parameter must be < OS_SCHTID_COUNT.
 *
 *  \return         Returns the schedule table of the given id.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTId2SchT,
(
  ScheduleTableType SchTId
));


/***********************************************************************************************************************
 *  Os_SchTGetCore()
 **********************************************************************************************************************/
/*! \brief          Returns the core of the given schedule table.
 *  \details        --no details--
 *
 *  \param[in]      SchT        Schedule table to query. Parameter must not be NULL.
 *
 *  \return         The schedule table's core.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, TYPEDEF, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTGetCore,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
));


/***********************************************************************************************************************
 *  Os_SchTGetApplication()
 **********************************************************************************************************************/
/*! \brief        Returns the owner application of the given alarm.
 *  \details        --no details--
 *
 *  \param[in]    SchT  Schedule table to query. Parameter must not be NULL.
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
OS_ALWAYS_INLINE, Os_SchTGetApplication,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
));


/***********************************************************************************************************************
 *  Os_SchTGetAccessingApplications()
 **********************************************************************************************************************/
/*! \brief        Get applications which have access to the given object.
 *  \details        --no details--
 *
 *  \param[in]    SchT  The object to query. Parameter must not be NULL.
 *
 *  \context      ANY
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE
 *
 *  \pre          -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_AppAccessMaskType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTGetAccessingApplications,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
));


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableRelLocal()
 **********************************************************************************************************************/
/*! \brief          Performs a relative start of the given schedule table which belongs to the local core.
 *  \details        --no details--
 *
 *  \context        OS_INTERNAL
 *
 *  \param[in]      ScheduleTable    See Os_SchTStartScheduleTableRel().
 *  \param[in]      Offset           See Os_SchTStartScheduleTableRel().
 *
 *  \retval         See Os_SchTStartScheduleTableRel().
 *
 *  \reentrant      TRUE for different Schedule Tables.
 *  \synchronous    TRUE
 *
 *  \pre            See Os_SchTStartScheduleTableRel().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SchTStartScheduleTableRelLocal
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Offset
);


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableAbsLocal()
 **********************************************************************************************************************/
/*! \brief          Performs an absolute start of the given schedule table which belongs to the local core.
 *  \details        --no details--
 *
 *  \context        OS_INTERNAL
 *
 *  \param[in]      ScheduleTable    See Os_SchTStartScheduleTableAbs().
 *  \param[in]      Start            See Os_SchTStartScheduleTableAbs().
 *
 *  \retval         See Os_SchTStartScheduleTableAbs().
 *
 *  \reentrant      TRUE for different Schedule Tables.
 *  \synchronous    TRUE
 *
 *  \pre            See Os_SchTStartScheduleTableAbs().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SchTStartScheduleTableAbsLocal
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Start
);


/***********************************************************************************************************************
 *  Os_SchTStopScheduleTableLocal()
 **********************************************************************************************************************/
/*! \brief          Stops the given schedule table, which has to belong to the local core.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable    See Os_SchTStopScheduleTable().
 *
 *  \retval         See Os_SchTStopScheduleTable().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different Schedule Tables.
 *  \synchronous    TRUE
 *
 *  \pre            See Os_SchTStopScheduleTable().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SchTStopScheduleTableLocal
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
);


/***********************************************************************************************************************
 *  Os_SchTNextScheduleTableLocal()
 **********************************************************************************************************************/
/*! \brief          Nexts the given schedule tables, which has to belong to the local core.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable_From  See Os_SchTNextScheduleTable().
 *  \param[in]      ScheduleTable_To    See Os_SchTNextScheduleTable().
 *
 *  \retval         See Os_SchTNextScheduleTable().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different Schedule Tables.
 *  \synchronous    TRUE
 *
 *  \pre            See Os_SchTNextScheduleTable().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SchTNextScheduleTableLocal
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_From,
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_To
);


/***********************************************************************************************************************
 *  Os_SchTGetScheduleTableStatusLocal()
 **********************************************************************************************************************/
/*! \brief          Gets the status of the given schedule table, which has to belong to the local core.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable     See Os_SchTGetScheduleTableStatus().
 *  \param[out]     ScheduleStatus    See Os_SchTGetScheduleTableStatus().
 *
 *  \retval         See Os_SchTGetScheduleTableStatus().
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different Schedule Tables.
 *  \synchronous    TRUE
 *
 *  \pre            See Os_SchTGetScheduleTableStatus().
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_SchTGetScheduleTableStatusLocal
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  ScheduleTableStatusRefType ScheduleStatus
);


/***********************************************************************************************************************
 *  Os_SchTWorkScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Callback function to perform the schedule table actions.
 *  \details        Calls the callback function of the current expiry point.
 *
 *  \param[in]      Job       The job to be performed. The job must be a Os_SchTConfigType.
 *                            Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different Schedule Tables.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The current expiry point is set.
 *  \pre            Given job is not scheduled.
 *
 *  \trace          SPEC-63772, SPEC-63914, SPEC-63950, SPEC-64057
 **********************************************************************************************************************/
FUNC(void, OS_CODE) Os_SchTWorkScheduleTable
(
  P2CONST(Os_JobConfigType, TYPEDEF, OS_CONST) Job
);


/***********************************************************************************************************************
 *  Os_Api_StartScheduleTableRel()
 **********************************************************************************************************************/
/*! \brief        OS service StartScheduleTableRel().
 *  \details      For further details see StartScheduleTableRel().
 *
 *  \param[in]    ScheduleTableID   See StartScheduleTableRel().
 *  \param[in]    Offset            See StartScheduleTableRel().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       other                     See \ref Os_SchTStartScheduleTableRel(),
 *                                              \ref Os_XSigSend_StartScheduleTableRel() and
 *                                              \ref Os_XSigRecv_StartScheduleTableRel().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See StartScheduleTableRel().
 *
 *  \trace        CREQ-61, CREQ-40
 *  \trace        SPEC-63729, SPEC-63788, SPEC-63830, SPEC-63838, SPEC-63874, SPEC-63909, SPEC-63922, SPEC-63991
 *  \trace        SPEC-63980, SPEC-64017, SPEC-63752, SPEC-63709, SPEC-63639, SPEC-63771
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_StartScheduleTableRel
(
  ScheduleTableType ScheduleTableID,
  TickType Offset
);


/***********************************************************************************************************************
 *  Os_Api_StartScheduleTableAbs()
 **********************************************************************************************************************/
/*! \brief        OS service StartScheduleTableAbs().
 *  \details      For further details see StartScheduleTableAbs().
 *
 *  \param[in]    ScheduleTableID   See StartScheduleTableAbs().
 *  \param[in]    Start             See StartScheduleTableAbs().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       other                     See \ref Os_SchTStartScheduleTableAbs(),
 *                                              \ref Os_XSigSend_StartScheduleTableAbs() and
 *                                              \ref Os_XSigRecv_StartScheduleTableAbs().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See StartScheduleTableAbs().
 *
 *  \trace        CREQ-136, CREQ-40
 *  \trace        SPEC-63715, SPEC-63763, SPEC-63765, SPEC-63858, SPEC-63996, SPEC-64052, SPEC-63980, SPEC-64017
 *  \trace        SPEC-63752, SPEC-63709, SPEC-63643
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_StartScheduleTableAbs
(
  ScheduleTableType ScheduleTableID,
  TickType Start
);


/***********************************************************************************************************************
 *  Os_Api_StopScheduleTable()
 **********************************************************************************************************************/
/*! \brief        OS service StopScheduleTable().
 *  \details      For further details see StopScheduleTable().
 *
 *  \param[in]    ScheduleTableID   See StopScheduleTable().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       other                     See \ref Os_SchTStopScheduleTable(),
 *                                              \ref Os_XSigSend_StopScheduleTable() and
 *                                              \ref Os_XSigRecv_StopScheduleTable().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See StopScheduleTable().
 *
 *  \trace        CREQ-96, CREQ-40
 *  \trace        SPEC-63826, SPEC-63831, SPEC-63870, SPEC-63939, SPEC-63964, SPEC-63980, SPEC-64017, SPEC-63752
 *  \trace        SPEC-63709, SPEC-63694, SPEC-64018
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_StopScheduleTable
(
  ScheduleTableType ScheduleTableID
);


/***********************************************************************************************************************
 *  Os_Api_NextScheduleTable()
 **********************************************************************************************************************/
/*! \brief        OS service NextScheduleTable().
 *  \details      For further details see NextScheduleTable().
 *
 *  \param[in]    ScheduleTableID_From  See NextScheduleTable().
 *  \param[in]    ScheduleTableID_To    See NextScheduleTable().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID_From.
 *  \retval       OS_STATUS_ID_2            (EXTENDED status:) Invalid ScheduleTableID_To.
 *  \retval       OS_STATUS_ID_DIFFERENT_COUNTER (EXTENDED status:)
 *                                          Given Schedule Tables are not assigned to the same counter.
 *  \retval       OS_STATUS_ID_DIFFERENT_SYNC (EXTENDED status:)
 *                                          Given Schedule Tables have different synchronization strategies.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient for
 *                                          ScheduleTableID_From.
 *  \retval       OS_STATUS_ACCESSRIGHTS_2  (Service Protection:) Caller's access rights are not sufficient for
 *                                          ScheduleTableID_To.
 *  \retval       other                     See \ref Os_SchTNextScheduleTable(),
 *                                              \ref Os_XSigSend_NextScheduleTable() and
 *                                              \ref Os_XSigRecv_NextScheduleTable().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See NextScheduleTable().
 *
 *  \trace        CREQ-112, CREQ-40
 *  \trace        SPEC-63758, SPEC-63789, SPEC-63818, SPEC-63839, SPEC-63882, SPEC-63944, SPEC-63954
 *  \trace        SPEC-63955, SPEC-63979, SPEC-63982, SPEC-64046, SPEC-63980, SPEC-64017, SPEC-63752
 *  \trace        SPEC-63709, SPEC-63929
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_NextScheduleTable
(
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
);


/***********************************************************************************************************************
 *  Os_Api_StartScheduleTableSynchron()
 **********************************************************************************************************************/
/*! \brief        OS service StartScheduleTableSynchron().
 *  \details      For further details see StartScheduleTableSynchron().
 *
 *  \param[in]    ScheduleTableID      See StartScheduleTableSynchron().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_STATE_1         Schedule table has already been started.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_ID_TYPE_1       (EXTENDED status:) Given schedule table is not an explicitly synchronized
 *                                          schedule table.
 *  \retval       OS_STATUS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See StartScheduleTableSynchron().
 *
 *  \trace        CREQ-100, CREQ-40
 *  \trace        SPEC-63717, SPEC-63719, SPEC-63821, SPEC-63898, SPEC-63933, SPEC-63980, SPEC-64017, SPEC-63752
 *  \trace        SPEC-63709, SPEC-63950
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_StartScheduleTableSynchron
(
  ScheduleTableType ScheduleTableID
);


/***********************************************************************************************************************
 *  Os_Api_SyncScheduleTable()
 **********************************************************************************************************************/
/*! \brief        OS service SyncScheduleTable().
 *  \details      For further details see SyncScheduleTable().
 *
 *  \param[in]    ScheduleTableID      See SyncScheduleTable().
 *  \param[in]    Value                See SyncScheduleTable().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_STATE_STOPPED   The state of the schedule table ScheduleTableId is equal to
 *                                          SCHEDULETABLE_STOPPED.
 *  \retval       OS_STATUS_STATE_NEXTED    The state of the schedule table ScheduleTableId is equal to
 *                                          SCHEDULETABLE_NEXT.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_ID_TYPE_1       (EXTENDED status:) Given schedule table is not an explicitly synchronized
 *                                          schedule table.
 *  \retval       OS_STATUS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_2  (EXTENDED status:) The Value is out of range.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See SyncScheduleTable().
 *
 *  \trace        CREQ-152, CREQ-40
 *  \trace        SPEC-63734, SPEC-63871, SPEC-63891, SPEC-63892, SPEC-63919, SPEC-64051, SPEC-63980
 *  \trace        SPEC-63752, SPEC-63709, SPEC-63792, SPEC-63813
 *
 *  Internal comment removed.
 *
 *
 *
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_SyncScheduleTable
(
  ScheduleTableType ScheduleTableID,
  TickType Value
);


/***********************************************************************************************************************
 *  Os_Api_SetScheduleTableAsync()
 **********************************************************************************************************************/
/*! \brief        OS service SetScheduleTableAsync().
 *  \details      For further details see SetScheduleTableAsync().
 *
 *  \param[in]    ScheduleTableID      See SetScheduleTableAsync().
 *
 *  \retval       OS_STATUS_OK              No error.
 *  \retval       OS_STATUS_STATE_STOPPED   Current state of ScheduleTableID is SCHEDULETABLE_STOPPED.
 *  \retval       OS_STATUS_STATE_NEXTED    Current state of ScheduleTableID is SCHEDULETABLE_NEXT.
 *  \retval       OS_STATUS_STATE_WAITING   Current state of ScheduleTableID is SCHEDULETABLE_STOPPED.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_ID_TYPE_1       (EXTENDED status:) Given schedule table is not an explicitly synchronized
 *                                          schedule table.
 *  \retval       OS_STATUS_CORE            (EXTENDED status:) The given object belongs to a foreign core.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See SetScheduleTableAsync().
 *
 *  \trace        CREQ-25, CREQ-40
 *  \trace        SPEC-63786, SPEC-63823, SPEC-63875, SPEC-63889, SPEC-63963, SPEC-64045, SPEC-64054, SPEC-63980
 *  \trace        SPEC-64017, SPEC-63752, SPEC-63709
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_SetScheduleTableAsync
(
  ScheduleTableType ScheduleTableID
);


/***********************************************************************************************************************
  *  Os_Api_GetScheduleTableStatus()
  *********************************************************************************************************************/
/*! \brief        OS service GetScheduleTableStatus().
 *  \details      For further details see GetScheduleTableStatus().
 *
 *  \param[in]    ScheduleTableID      See GetScheduleTableStatus().
 *  \param[out]   ScheduleStatus       See GetScheduleTableStatus().
 *
 *  \retval       OS_STATUS_OK               No error.
 *  \retval       OS_STATUS_ID_1            (EXTENDED status:) Invalid ScheduleTableID.
 *  \retval       OS_STATUS_CALLEVEL        (EXTENDED status:) Called from invalid context.
 *  \retval       OS_STATUS_DISABLEDINT     (Service Protection:) Caller is in interrupt API sequence.
 *  \retval       OS_STATUS_ACCESSRIGHTS_1  (Service Protection:) Caller's access rights are not sufficient.
 *  \retval       other                     See \ref Os_SchTGetScheduleTableStatus(),
 *                                              \ref Os_XSigSend_GetScheduleTableStatus() and
 *                                              \ref Os_XSigRecv_GetScheduleTableStatus().
 *
 *  \context      TASK|ISR2
 *
 *  \reentrant    TRUE
 *  \synchronous  TRUE, if the given ScheduleTableID belongs to local core.
 *
 *  \pre          See GetScheduleTableStatus().
 *
 *  \trace        CREQ-108, CREQ-40
 *  \trace        SPEC-63703, SPEC-63748, SPEC-63751, SPEC-63790, SPEC-63836, SPEC-63843
 *  \trace        SPEC-64019, SPEC-63980, SPEC-64017, SPEC-63752, SPEC-63709, SPEC-63591
 **********************************************************************************************************************/
FUNC(Os_StatusType, OS_CODE) Os_Api_GetScheduleTableStatus
(
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
);


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_SCHEDULETABLEINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_ScheduleTableInt.h
 **********************************************************************************************************************/
