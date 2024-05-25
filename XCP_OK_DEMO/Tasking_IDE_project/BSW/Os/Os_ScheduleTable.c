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
 * \addtogroup Os_ScheduleTable
 * \{
 *
 * \file
 * \brief       Implementation of schedule table internal functions and API functions
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_SCHEDULETABLE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_ScheduleTable_Cfg.h"
#include "Os_ScheduleTable_Types.h"
#include "Os_ScheduleTable_Lcfg.h"
#include "Os_ScheduleTable.h"

/* Os kernel module dependencies */
#include "Os_Error.h"
#include "Os_Counter.h"
#include "Os_Lcfg.h"
#include "Os_Fifo08.h"


/* Os hal dependencies */


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
 *  Os_SchTIsEnabled()
 **********************************************************************************************************************/
/*! \brief          Returns whether any ScheduleTables are configured (!0) or not (0).
 *  \details        --no details--
 *
 *  \retval         !0  ScheduleTables module is enabled.
 *  \retval         0   ScheduleTables module is disabled.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTIsEnabled,
(
  void
));


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableRel()
 **********************************************************************************************************************/
/*! \brief          Starts a schedule table which belongs to the local core at a relative time offset.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable The schedule table to be started. Parameter must not be NULL.
 *  \param[in]      Offset        The relative time offset, the schedule table shall be started at.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_STATE_1         Schedule table has already been started.
 *  \retval         OS_STATUS_ID_TYPE_1       (EXTENDED status:) Given schedule table is synchronized implicitly.
 *  \retval         OS_STATUS_VALUE_IS_ZERO_2 (EXTENDED status:) Given Offset is zero.
 *  \retval         OS_STATUS_VALUE_IS_TOO_HIGH_2 (EXTENDED status:) Offset is bigger than
 *                                                (OsCounterMaxAllowedValue - InitialOffset).
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given schedule table belongs to the local core.
 *  \pre            Given values have been checked before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartScheduleTableRel,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Offset
));


/***********************************************************************************************************************
 *  Os_SchTGetScheduleTableStatus()
 **********************************************************************************************************************/
/*! \brief          Returns the current state of the given schedule table which belongs to the local core.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to be queried.  Parameter must not be NULL.
 *  \param[out]     ScheduleStatus  Contains the current state on successful return.  Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given schedule table belongs to the local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTGetScheduleTableStatus,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  ScheduleTableStatusRefType ScheduleStatus
));


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableAbs()
 **********************************************************************************************************************/
/*! \brief          Starts a schedule table which belongs to the local core at an absolute point in time.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable The schedule table to be started. Parameter must not be NULL.
 *  \param[in]      Start         The absolute time, the schedule table shall be started at.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_STATE_1         Schedule table has already been started.
 *  \retval         OS_STATUS_VALUE_IS_TOO_HIGH_2 (EXTENDED status:) Offset is bigger than OsCounterMaxAllowedValue
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given schedule table belongs to the local core.
 *  \pre            Given values have been checked before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTStartScheduleTableAbs,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Start
));


/***********************************************************************************************************************
 *  Os_SchTNextScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Starts a schedule table which belongs to the local core at an absolute point in time.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable_From  The schedule table to be stopped. Parameter must not be NULL.
 *  \param[in,out]  ScheduleTable_To    The schedule table to be stopped. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_STOPPED_1       Schedule table ScheduleTableID_From has not been started.
 *  \retval         OS_STATUS_NEXTED_1        Schedule table ScheduleTableID_From has already been requested to start at
 *                                            the end of another schedule table.
 *  \retval         OS_STATUS_NOT_STOPPED_2   Schedule table ScheduleTableID_To is not in state stopped.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) ScheduleTableID_From's owner application is not
 *                                            accessible.
 *  \retval         OS_STATUS_NOTACCESSIBLE_2 (Service Protection:) ScheduleTableID_To's owner application is not
 *                                            accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given schedule table belongs to the local core.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTNextScheduleTable,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_From,
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_To
));


/***********************************************************************************************************************
 *  Os_SchTStopScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Stops a schedule table which belongs to the local core immediately.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable The schedule table to be stopped. Parameter must not be NULL.
 *
 *  \retval         OS_STATUS_OK              No error.
 *  \retval         OS_STATUS_STOPPED_1       Schedule table has already been stopped.
 *  \retval         OS_STATUS_NOTACCESSIBLE_1 (Service Protection:) Given object's owner application is not accessible.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
  *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given schedule table belongs to the local core.
 *  \pre            Given values have been checked before.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTStopScheduleTable,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTJob2SchT()
 **********************************************************************************************************************/
/*! \brief          Returns the schedule table which belongs to the given job.
 *  \details        --no details--
 *
 *  \param[in]      Job   A job object. The given Job must be a schedule table job.
 *                        Parameter must not be NULL.
 *
 *  \return         Returns the schedule table of the given job.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTJob2SchT,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_SchTExPo2SyncExPo()
 **********************************************************************************************************************/
/*! \brief          Returns the synchronization expiry point which belongs to the given general expiry point.
 *  \details        --no details--
 *
 *  \param[in]      ExPo    An expiry point object. The given ExPo must be a synchronous ExPo.
 *                          Parameter must not be NULL.
 *
 *  \return         Returns synchronization expiry point of the given expiry point.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTExPoSyncConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTExPo2SyncExPo,
(
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) ExPo
));


/***********************************************************************************************************************
 *  Os_SchTGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns a pointer to the dynamic data.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \return         Returns dynamic data object of the given schedule table.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTGetDyn,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTSyncGet()
 **********************************************************************************************************************/
/*! \brief          Returns a pointer to the sync configuration data.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \return         Returns sync configuration data object of the given schedule table.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTSyncGet,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTSyncGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns a pointer to the dynamic data of the sync object.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable   The schedule table to query. The given schedule table must be a synchronous
 *                                  schedule table. Parameter must not be NULL.
 *
 *  \return         Returns dynamic data object of the given schedule table.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTSyncGetDyn,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));

/***********************************************************************************************************************
 *  Os_SchTExPoGetCurrent()
 **********************************************************************************************************************/
/*! \brief          Returns the currently active expiry point of the given schedule table.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \return         Returns the currently active expiry point.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            The current exiry point is set.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTExPoGetCurrent,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTExPoSelectNext()
 **********************************************************************************************************************/
/*! \brief          Make the next expiry point the current expiry point.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to modify. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTExPoSelectNext,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTSyncUpdateDeviation()
 **********************************************************************************************************************/
/*! \brief          Updates the deviation between the sync counter and the physical counter.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      SyncTimeNow     The current value of the SyncTime.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Synchronization time provided.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncUpdateDeviation,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_TickType SyncTimeNow
));


/***********************************************************************************************************************
 *  Os_SchTSyncScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Provide a sync value for the given schedule table.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to sync. Parameter must not be NULL.
 *  \param[in]      SyncTimeNow     The current value of the SyncTime.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncScheduleTable,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_TickType SyncTimeNow
));


/***********************************************************************************************************************
 *  Os_SchTIsSynchronizedExplicit()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given schedule table is synchronized explicitly or not.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         !0    The schedule table is explicitly synchronized.
 *  \retval         0     The schedule table is not explicitly synchronized.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SchTIsSynchronizedExplicit,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTIsSynchronous()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given schedule table is synchronous to the synchronization counter or not.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTableSync   The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         !0    The schedule table runs synchronous.
 *  \retval         0     The schedule table runs asynchronous.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTIsSynchronous,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync
));


/***********************************************************************************************************************
 *  Os_SchTHasNextScheduleTable()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given schedule table has another schedule table as successor.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         !0    The schedule table has a next schedule table **other than itself**.
 *  \retval         0     The schedule table has no other schedule table as successor.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SchTHasNextScheduleTable,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTSwitch()
 **********************************************************************************************************************/
/*! \brief          Starts the next schedule table.
 *  \details        If the current schedule table is not the same as the next one, the current schedule table
 *                  is stopped.
 *
 *                  No synchronization here - That is performed in the first expiry point instead!
 *
 *  \param[in,out]  ScheduleTable  The schedule table to switch from. The given schedule table must have a valid Next
 *                                 schedule table. Parameter must not be NULL.
 *
 *  \return         The schedule table which is not the current one.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTSwitch,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsStopped()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given schedule table stopped.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the schedule table is stopped.
 *  \retval         OS_CHECK_FAILED       If the schedule table is not stopped.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsStopped,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotStopped()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given schedule table is not stopped.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the schedule table is not stopped.
 *  \retval         OS_CHECK_FAILED       If the schedule table is stopped.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotStopped,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotNexted()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given schedule table is not nexted.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the schedule table is not nexted.
 *  \retval         OS_CHECK_FAILED       If the schedule table is nexted.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotNexted,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotWaiting()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given schedule table is not waiting.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the schedule table is not waiting.
 *  \retval         OS_CHECK_FAILED       If the schedule table is waiting.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotWaiting,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotSynchronizedImplicitly()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given schedule table is not synchronized implicitly.
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the schedule table is not synchronized implicitly.
 *  \retval         OS_CHECK_FAILED       If the schedule table is synchronized implicitly.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTCheckIsNotSynchronizedImplicitly,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsSynchronizedExplicitly()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given schedule table is synchronized explicitly.
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   If the schedule table is synchronized explicitly.
 *  \retval         OS_CHECK_FAILED       If the schedule table is not synchronized explicitly.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTCheckIsSynchronizedExplicitly,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTCheckUpperBound()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given Value is lower or equal to Bound.
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Value             The value to check.
 *  \param[in]      UpperBound        The upper bound of the given value.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given value is in range.
 *  \retval         OS_CHECK_FAILED       If the given value is out of range.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckUpperBound,
(
  Os_TickType Value,
  Os_TickType UpperBound
));


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotZero()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given Value is a non-zero value.
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      Value             The value to check.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given value is non-zero.
 *  \retval         OS_CHECK_FAILED       If the given value is zero.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotZero,
(
  Os_TickType Value
));


/***********************************************************************************************************************
 *  Os_SchTReinitNonSync()
 **********************************************************************************************************************/
/*! \brief          Initializes the general data of a schedule table.
 *  \details        Breaks the link to the previous schedule table.
 *
 *  \param[in,out]  ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *  \param[in]      InitialState   The initial state of the schedule table.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTReinitNonSync,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_SchTStatusType InitialState
));


/***********************************************************************************************************************
 *  Os_SchTReinit()
 **********************************************************************************************************************/
/*! \brief          Initializes a complete schedule table.
 *  \details        This function is called for the first time in Init-Step4 but is also called if re-initialization
 *                  is needed.
 *
 *  \param[in,out]  ScheduleTable  The schedule table to query. Parameter must not be NULL.
 *  \param[in]      InitialState   The initial state of the schedule table.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTReinit,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_SchTStatusType InitialState
));


/***********************************************************************************************************************
 *  Os_SchTSyncUpdateSyncStatus()
 **********************************************************************************************************************/
/*! \brief          Updates the current synchronization state of the given schedule table.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTableSync  The schedule table to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-63923, SPEC-64050
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncUpdateSyncStatus,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync
));


/***********************************************************************************************************************
 *  Os_SchTSyncUpdateSyncPoint()
 **********************************************************************************************************************/
/*! \brief          Updates the sync point time stamp, by adding the passed counter ticks since the last sync point
 *                  to the syncTimestamp and the counterTimeStamp.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTableSync  The schedule table to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncUpdateSyncPoint,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync
));


/***********************************************************************************************************************
 *  Os_SchTExPoWorkAction()
 **********************************************************************************************************************/
/*! \brief          Execute all actions of the given Expiry Point.
 *  \details        Activates all task and sets all events.
 *
 *  \param[in,out]  ExPo  The exipry point, whose action shall be performed. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-64032, SPEC-63611, SPEC-63618, SPEC-63695, SPEC-64034
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTExPoWorkAction,
(
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) ExPo
));


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointGeneral()
 **********************************************************************************************************************/
/*! \brief          Callback function to perform an expiry point.
 *  \details        Performs all activities, necessary for an expiry point without synchronization at the start or in
 *                  the middle of a schedule table
 *
 *  \param[in,out]  ScheduleTable         The schedule table to modify. Parameter must not be NULL.
 *  \param[out]     RelativeOffsetToNext  Returns the relative offset to the next schedule table.
 *                                        Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointGeneral,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
));


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointWithSync()
 **********************************************************************************************************************/
/*! \brief          Callback function to perform an expiry point.
 *  \details        Performs all activities, necessary for an expiry point including synchronization at the start or in
 *                  the middle of a schedule table
 *
 *  \param[in,out]  ScheduleTableSync     The schedule table to modify. Parameter must not be NULL.
 *  \param[out]     RelativeOffsetToNext  Returns the relative offset to the next schedule table.
 *                                        Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            The current exiry point is set to an ExPo of type \ref Os_SchTExPoSyncConfigType.
 *
 *  \trace          SPEC-63883
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointWithSync,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
));


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointWithSyncZero()
 **********************************************************************************************************************/
/*! \brief          Callback function to perform an expiry point of a synchronous schedule table without synchronizing.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTableSync     The schedule table to modify. Parameter must not be NULL.
 *  \param[out]     RelativeOffsetToNext  Returns the relative offset to the next schedule table.
 *                                        Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointWithSyncZero,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
));


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointLast()
 **********************************************************************************************************************/
/*! \brief          Processes the last expiry point of a Schedule Table and continues with the next one.
 *  \details        Performs all activities, necessary for an expiry point at the End of a cyclic schedule table.
 *
 *  \param[in,out]  ScheduleTable         The schedule table to query. ScheduleTable must have a valid Next schedule
 *                                        Table. The Next schedule table must not be scheduled within a job queue.
 *                                        Parameter must not be NULL.
 *  \param[out]     RelativeOffsetToNext  Returns the relative offset to the next schedule table.
 *                                        Parameter must not be NULL.
 *
 *  \return         The next schedule table.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *
 *  \trace          SPEC-63929
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointLast,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
));


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointLastSingleShot()
 **********************************************************************************************************************/
/*! \brief          Processes the last expiry point of a Schedule Table and continues with the next one if available.
 *  \details        Performs all activities, necessary for an expiry point at the End of a single shot schedule table.
 *
 *  \param[in,out]  ScheduleTable         The schedule table to query. Parameter must not be NULL..
 *  \param[out]     RelativeOffsetToNext  Returns the relative offset to the next schedule table. If there is no next
 *                                        schedule table, parameter is unchanged. Parameter must not be NULL..
 *
 *  \return         Next schedule table.
 *  \retval         NULL_PTR  If next schedule table not set.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Next schedule table is not scheduled within a job queue.
 *
 *  \trace          SPEC-63929, SPEC-63937
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointLastSingleShot,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
));


/***********************************************************************************************************************
 *  Os_SchTSyncMod()
 **********************************************************************************************************************/
/*! \brief          Calculates mod(Value, Duration).
 *  \details        Value has to be in range 0 .. 2*Duration-1.
 *
 *  \param[in,out]  ScheduleTableSync   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      Value               The argument of the modulo operation.
 *
 *  \return         The mod(Value, Duration). Range: 0 .. Duration-1
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncMod,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Value
));


/***********************************************************************************************************************
 *  Os_SchTSyncAddAndMod()
 **********************************************************************************************************************/
/*! \brief          Calculates mod(Lhs + Rhs, Duration).
 *  \details        Lhs and Rhs have to be in range 0 .. Duration-1.
 *
 *  \param[in,out]  ScheduleTableSync   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      Lhs                 The left hand side argument of the addition.
 *                                      Lhs must be in range 0 .. Duration-1.
 *  \param[in]      Rhs                 The right hand side argument of the addition.
 *                                      Rhs must be in range 0 .. Duration-1.
 *
 *  \return         The mod(Lhs + Rhs, Duration). Range: 0 .. Duration-1
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncAddAndMod,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Lhs,
  Os_TickType Rhs
));


/***********************************************************************************************************************
 *  Os_SchTSyncSub()
 **********************************************************************************************************************/
/*! \brief          Calculates mod(Lhs - Rhs, Duration).
 *  \details        The lower half of the return value may be treated as positive (=> Lhs > Rhs) result,
 *                  the upper half may be treated as negative.
 *
 *  \param[in,out]  ScheduleTableSync   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      Lhs                 The left hand side argument of the subtraction.
 *                                      Lhs must be in range 0 .. Duration-1.
 *  \param[in]      Rhs                 The right hand side argument of the subtraction.
 *                                      Rhs must be in range 0 .. Duration-1.
 *
 *  \return         The mod(Lhs - Rhs, Duration). Range: 0 .. (Duration-1)
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncSub,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Lhs,
  Os_TickType Rhs
));


/***********************************************************************************************************************
 *  Os_SchTSyncSubAndModHalfRange()
 **********************************************************************************************************************/
/*! \brief          Calculates mod(Lhs - Rhs, Duration).
 *  \details        --No details--
 *
 *  \param[in,out]  ScheduleTableSync   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      Lhs                 The left hand side argument of the subtraction.
 *                                      Lhs must be in range -DurationHalf .. DurationHalf-1.
 *  \param[in]      Rhs                 The right hand side argument of the subtraction.
 *                                      Rhs must be in range -DurationHalf .. DurationHalf-1.
 *
 *  \return         The mod(Lhs - Rhs, Duration). Range: -DurationHalf .. DurationHalf-1
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncSubAndModHalfRange,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Lhs,
  Os_TickType Rhs
));


/***********************************************************************************************************************
 *  Os_SchTSyncFull2HalfRange()
 **********************************************************************************************************************/
/*! \brief          Moves a value from range 0 .. Duration-1 to -DurationHalf .. DurationHalf-1.
 *  \details        --No details--
 *
 *  \param[in,out]  ScheduleTableSync   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      Operand             The operand in range 0 .. Duration-1.
 *
 *  \return         The operand in range: -DurationHalf .. DurationHalf-1
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncFull2HalfRange,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Operand
));


/***********************************************************************************************************************
 *  Os_SchTStartRelative()
 **********************************************************************************************************************/
/*! \brief          Starts a schedule table at a relative time without performing checks.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to query. ScheduleTable must not be scheduled.
 *                                  Parameter must not be NULL.
 *  \param[in]      Offset          The start delay.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartRelative,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  TickType Offset
));


/***********************************************************************************************************************
 *  Os_SchTStartAbsolute()
 **********************************************************************************************************************/
/*! \brief          Starts a schedule table at an absolute time without performing checks.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *  \param[in]      Start           The start time.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartAbsolute,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  TickType Start
));


/***********************************************************************************************************************
 *  Os_SchTStartSynchronous()
 **********************************************************************************************************************/
/*! \brief          Starts a schedule table at synchronous.
 *  \details        --no details--
 *
 *  \param[in,out]  ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Given job is not scheduled.
 *
 *  \trace          SPEC-63847
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartSynchronous,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  Os_SchTGetInitialOffset()
 **********************************************************************************************************************/
/*! \brief          Returns the initial offset of the schedule table.
 *  \details        --no details--
 *
 *  \param[in]      ScheduleTable   The schedule table to query. Parameter must not be NULL.
 *
 *  \return         The offset of the first expiry point.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTGetInitialOffset,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_SchTIsEnabled()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTIsEnabled,
(
  void
))
{
   return (Os_StdReturnType)((uint16)OS_SCHTID_COUNT > 0u);                                                             /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableRel()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTStartScheduleTableRel,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Offset
))
{
  Os_StatusType status;

  /* #10 Perform remaining checks. */
  if(OS_UNLIKELY(Os_SchTCheckIsNotSynchronizedImplicitly(ScheduleTable) == OS_CHECK_FAILED))                            /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_ID_TYPE_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsNotZero(Offset) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_VALUE_IS_ZERO_2;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueLeReducedMaxAllowed(                                                              /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */
      &(ScheduleTable->Job), Os_SchTGetInitialOffset(ScheduleTable), Offset) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_VALUE_IS_TOO_HIGH_2;
  }
  else if(OS_UNLIKELY(Os_AppCheckIsAccessible(ScheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                    /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsStopped(ScheduleTable) == OS_CHECK_FAILED ))                                        /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_STATE_1;
  }
  else
  {
    /* #20 Perform a relative start. */
    Os_SchTStartRelative(ScheduleTable, Offset);                                                                        /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_SchTGetScheduleTableStatus()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTGetScheduleTableStatus,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  ScheduleTableStatusRefType ScheduleStatus
))
{
  Os_StatusType status;

  /* #10 Perform remaining checks. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(ScheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                         /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else
  {
    P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn;

    dyn = Os_SchTGetDyn(ScheduleTable);                                                                                 /* SBSW_OS_FC_PRECONDITION */

    /* #20 If the schedule table is not in running state: */
    if(dyn->State != OS_SCHTSTATUS_RUNNING)
    {
      /* #30 The internal state is returned directly. */
      *ScheduleStatus = (ScheduleTableStatusType)dyn->State;                                                            /* PRQA S 4322 */ /* MD_Os_Rule10.5_4322 */ /* SBSW_OS_PWA_PRECONDITION */
    }
    /* #40 Otherwise: */
    else
    {
      /* #50 Otherwise: Depending on the schedule table synchronization kind: */
      switch(ScheduleTable->SyncKind)
      {
        case OS_SCHT_SYNC_KIND_NON:
          /* #60 Non-synchronized - Return SCHEDULETABLE_RUNNING. */
          *ScheduleStatus = SCHEDULETABLE_RUNNING;                                                                      /* SBSW_OS_PWA_PRECONDITION */
          break;

        case OS_SCHT_SYNC_KIND_IMPLICIT:
          /* #70 Implicitly synchronized - Return SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS. */
          *ScheduleStatus = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;                                                      /* SBSW_OS_PWA_PRECONDITION */
          break;

        /* #80 Explicitly synchronized - Depending on synchronization state: */
        case OS_SCHT_SYNC_KIND_EXPLICIT:
          {
            P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) scheduleTableSync = Os_SchTSyncGet(ScheduleTable);      /* SBSW_OS_FC_PRECONDITION */

            if(Os_SchTIsSynchronous(scheduleTableSync) != 0u)                                                           /* SBSW_OS_SCHT_SCHTISSYNCHRONOUS_001 */
            {
              /* #90 If synchronous: Return SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS. */
              *ScheduleStatus = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;                                                  /* SBSW_OS_PWA_PRECONDITION */
            }
            else
            {
              /* #100 If not synchronous: Return SCHEDULETABLE_RUNNING. */
              *ScheduleStatus = SCHEDULETABLE_RUNNING;                                                                  /* SBSW_OS_PWA_PRECONDITION */
            }
          }
          break;

        default:                                                                                                        /* COV_OS_INVSTATE */
          Os_ErrKernelPanic();
          break;
      }
    }

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableAbs()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */

OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTStartScheduleTableAbs,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Start
))
{
  Os_StatusType status;

  /* #10 Perform remaining checks. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(ScheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                         /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsStopped(ScheduleTable) == OS_CHECK_FAILED))                                         /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_STATE_1;
  }
  else if(OS_UNLIKELY(Os_JobCheckValueLeMaxAllowed(&(ScheduleTable->Job), Start) == OS_CHECK_FAILED ))                  /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_VALUE_IS_TOO_HIGH_2;
  }
  else
  {
    /* #20 Start the schedule table absolute. */
    Os_SchTStartAbsolute(ScheduleTable, Start);                                                                         /* SBSW_OS_FC_PRECONDITION */

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_SchTNextScheduleTable()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTNextScheduleTable,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_From,
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_To
))
{
  Os_StatusType status;

  /* #10 Perform remaining checks. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(ScheduleTable_From->OwnerApplication) == OS_CHECK_FAILED ))                    /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_AppCheckIsAccessible(ScheduleTable_To->OwnerApplication) == OS_CHECK_FAILED ))                 /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_2;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsNotStopped(ScheduleTable_From) == OS_CHECK_FAILED))                                 /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_STOPPED_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsNotNexted(ScheduleTable_From) == OS_CHECK_FAILED))                                  /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_NEXTED_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsStopped(ScheduleTable_To) == OS_CHECK_FAILED ))                                     /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_NOT_STOPPED_2;
  }
  else
  {
    P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn_From;
    P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn_To;

    dyn_From = Os_SchTGetDyn(ScheduleTable_From);                                                                       /* SBSW_OS_FC_PRECONDITION */
    dyn_To = Os_SchTGetDyn(ScheduleTable_To);                                                                           /* SBSW_OS_FC_PRECONDITION */

    /* #20 If there is already a next schedule table set and it is not ScheduleTable_From itself: */
    if((dyn_From->Next != NULL_PTR) && (dyn_From->Next != ScheduleTable_From))
    {
      P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn_Nexted = Os_SchTGetDyn(dyn_From->Next);                          /* SBSW_OS_SCHT_SCHTGETDYN_001 */

      /* #30 Set state of previous next schedule table to STOPPED. */
      dyn_Nexted->State = OS_SCHTSTATUS_STOPPED;                                                                        /* SBSW_OS_SCHT_SCHTGETDYN_002 */
    }

    /* #40 Initialize ScheduleTable_To with state NEXT. */
    Os_SchTReinit(ScheduleTable_To, OS_SCHTSTATUS_NEXT);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #50 Make ScheduleTable_To the next schedule table of ScheduleTable_From. */
    dyn_From->Next = ScheduleTable_To;                                                                                  /* SBSW_OS_SCHT_SCHTGETDYN_002 */
    dyn_To->Previous = ScheduleTable_From;                                                                              /* SBSW_OS_SCHT_SCHTGETDYN_002 */

    status = OS_STATUS_OK;
  }

  return status;
}                                                                                                                       /* PRQA S 6080 */ /* MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_SchTStopScheduleTable()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StatusType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTStopScheduleTable,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  Os_StatusType status;

  /* #10 Perform remaining checks. */
  if(OS_UNLIKELY(Os_AppCheckIsAccessible(ScheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                         /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
  {
    status = OS_STATUS_NOTACCESSIBLE_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckIsNotStopped(ScheduleTable) == OS_CHECK_FAILED))                                      /* SBSW_OS_FC_PRECONDITION */
  {
    status = OS_STATUS_STOPPED_1;
  }
  else
  {
    P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn;

    dyn = Os_SchTGetDyn(ScheduleTable);                                                                                 /* SBSW_OS_FC_PRECONDITION */

    /* #20 If the given schedule table is in state NEXT, stop the previous schedule table. */
    if(dyn->State == OS_SCHTSTATUS_NEXT)
    {
      P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dynPrevious;
      dynPrevious = Os_SchTGetDyn(dyn->Previous);                                                                       /* SBSW_OS_SCHT_SCHTGETDYN_003 */

      Os_JobDelete(&(dyn->Previous->Job));                                                                              /* SBSW_OS_SCHT_JOBDELETE_001 */
      dynPrevious->State = OS_SCHTSTATUS_STOPPED;                                                                       /* SBSW_OS_SCHT_SCHTGETDYN_002 */
    }
    /* #30 If the given schedule table is _NOT_ in state WAITING (so RUNNING or RUNNING_AND_SYNCHRONOUS), stop it. */
    else if(dyn->State != OS_SCHTSTATUS_WAITING)
    {
      Os_JobDelete(&(ScheduleTable->Job));                                                                              /* SBSW_OS_FC_PRECONDITION */
    }
    else
    {
      /* In any other case, there is no running job to delete. MISRA 14.10 */
    }

    /* #40 If the given schedule table has a succeeding one, stop the succeeding schedule table. */
    if(Os_SchTHasNextScheduleTable(ScheduleTable) != 0u)                                                                /* SBSW_OS_FC_PRECONDITION */
    {
      Os_SchTGetDyn(dyn->Next)->State = OS_SCHTSTATUS_STOPPED;                                                          /* SBSW_OS_SCHT_SCHTGETDYN_001 */ /* SBSW_OS_SCHT_SCHTGETDYN_002 */
    }

    /* #50 Change the state of ScheduleTable accordingly. */
    dyn->State = OS_SCHTSTATUS_STOPPED;                                                                                 /* SBSW_OS_SCHT_SCHTGETDYN_002 */

    status = OS_STATUS_OK;
  }

  return status;
}


/***********************************************************************************************************************
 *  Os_SchTJob2SchT()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTJob2SchT,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return (P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST))Job;                                                          /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_SchTExPo2SyncExPo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTExPoSyncConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTExPo2SyncExPo,
(
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) ExPo
))
{
  Os_Assert((Os_StdReturnType)(ExPo->Kind == OS_SCHT_EXPO_KIND_EXECUTE_SYNC));                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  return (P2CONST(Os_SchTExPoSyncConfigType, AUTOMATIC, OS_CONST))ExPo;                                                 /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_SchTGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTGetDyn,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return (P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT))Os_JobGetDyn(&(ScheduleTable->Job));                             /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTSyncGet()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTSyncGet,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return (P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST))ScheduleTable;                                            /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */
}


/***********************************************************************************************************************
 *  Os_SchTSyncGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTSyncGetDyn,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return (P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT))Os_SchTGetDyn(&(ScheduleTable->SchT));                       /* PRQA S 0310 */ /* MD_Os_Rule11.3_0310 */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTExPoGetCurrent()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST), OS_CODE,
OS_ALWAYS_INLINE, Os_SchTExPoGetCurrent,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return Os_SchTGetDyn(ScheduleTable)->ExPo;                                                                            /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTExPoSelectNext()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTExPoSelectNext,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn = Os_SchTGetDyn(ScheduleTable);                                      /* SBSW_OS_FC_PRECONDITION */

  Os_Assert((Os_StdReturnType)(dyn->ExPo->Next != NULL_PTR));                                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  dyn->ExPo = dyn->ExPo->Next;                                                                                          /* SBSW_OS_SCHT_SCHTGETDYN_002 */
}


/***********************************************************************************************************************
 *  Os_SchTSyncUpdateDeviation()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncUpdateDeviation,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_TickType SyncTimeNow
))
{
  P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dyn;
  Os_TickType syncTimeDelta;
  Os_TickType syncTimeDeltaHalfMod;
  Os_TickType syncTimeCalculated;
  Os_TickType counterTimeDelta;     /* The time which passed since the last sync. */
  Os_TickType counterTimeNow;

  dyn = Os_SchTSyncGetDyn(ScheduleTable);                                                                               /* SBSW_OS_FC_PRECONDITION */

  counterTimeNow = Os_JobGetValue(&(ScheduleTable->SchT.Job));                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #10 Calculate the counter ticks since the last sync point. */
  /* The ticks passed, may never be negative.
   *
   *    counterTimeDelta = (counterTimeNow - CounterTimeStamp) % Duration
   *
   * As there is at least one sync point per schedule table cycle,
   *
   *    counterTimeDelta = counterTimeNow - dyn->CounterTimeStamp
   *
   * is lower than the schedule table duration.
   */
  counterTimeDelta = Os_JobSub(&(ScheduleTable->SchT.Job), counterTimeNow, dyn->CounterTimeStamp);                      /* SBSW_OS_FC_PRECONDITION */
  counterTimeDelta = Os_SchTSyncMod(ScheduleTable, counterTimeDelta);                                                   /* SBSW_OS_FC_PRECONDITION */

  /* #20 Calculate the expected sync time. */
  syncTimeCalculated = Os_SchTSyncAddAndMod(ScheduleTable, dyn->SyncTimeStamp, counterTimeDelta);                       /* SBSW_OS_FC_PRECONDITION */

  /* #30 Calculate the difference between the expected and the given sync time. */
  /* As the physical synchronous time may be faster or slower than the calculated synchronous time,
   * the difference between both times may be negative or positive.
   * The difference between the calculated sync time and the given SyncTimeNow is expected to be
   * small and therefore either in range
   *   -> 0 .. DurationHalf-1
   * or in range
   *   -> -DurationHalf .. -1.
   */
  syncTimeDelta = Os_SchTSyncSub(ScheduleTable, SyncTimeNow, syncTimeCalculated);                                       /* SBSW_OS_FC_PRECONDITION */
  syncTimeDeltaHalfMod = Os_SchTSyncFull2HalfRange(ScheduleTable, syncTimeDelta);                                       /* SBSW_OS_FC_PRECONDITION */

  /* #40 Update the deviation. */
  dyn->Deviation = Os_SchTSyncSubAndModHalfRange(ScheduleTable, dyn->Deviation, syncTimeDeltaHalfMod);                  /* SBSW_OS_SCHT_SCHTGETDYN_002 */ /* SBSW_OS_FC_PRECONDITION */

  /* #50 Remember the last sync point. */
  dyn->SyncTimeStamp = SyncTimeNow;                                                                                     /* SBSW_OS_SCHT_SCHTGETDYN_002 */
  dyn->CounterTimeStamp = counterTimeNow;                                                                               /* SBSW_OS_SCHT_SCHTGETDYN_002 */
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


/***********************************************************************************************************************
 *  Os_SchTSyncScheduleTable()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncScheduleTable,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_TickType SyncTimeNow
))
{
  P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn;
  P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dynSync;

  dyn = Os_SchTGetDyn(&(ScheduleTable->SchT));                                                                          /* SBSW_OS_FC_PRECONDITION */
  dynSync = Os_SchTSyncGetDyn(ScheduleTable);                                                                           /* SBSW_OS_FC_PRECONDITION */

  /* #10 If the schedule table has been waiting for a synchronization point: */
  if(dyn->State == OS_SCHTSTATUS_WAITING)                                                                               /* PRQA S 0715 */ /* MD_Os_Dir1.1_0715 */
  {
    Os_TickType relOffset;

    /* #20 Provide synchronization point. */
    dynSync->Deviation = 0;                                                                                             /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    dynSync->SyncTimeStamp = SyncTimeNow;                                                                               /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    dynSync->CounterTimeStamp = Os_JobGetValue( &(ScheduleTable->SchT.Job) );                                           /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */ /* SBSW_OS_FC_PRECONDITION */

    /* #30 Change sync state to SYNC. */
    dynSync->SyncState = OS_SCHTSYNCSTATUS_SYNC;                                                                        /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */

    /* As SyncTimeNow < Duration --> relOffset > 0 */
    relOffset = ScheduleTable->Duration - SyncTimeNow;

    /* #40 Set the first synchronization point. */
    /* This is the first time the job is added, so do it relative to the current counter value. */
    Os_JobAddRel(&(ScheduleTable->SchT.Job), relOffset);                                                                /* SBSW_OS_FC_PRECONDITION */

    /* #50 Set schedule table state to RUNNING. */
    dyn->State = OS_SCHTSTATUS_RUNNING;                                                                                 /* SBSW_OS_SCHT_SCHTGETDYN_002 */
  }
  /* #60 Otherwise: */
  else
  {
    /* #70 If no synchronization point has been provided: */
    if(dynSync->SyncState == OS_SCHTSYNCSTATUS_NOT_PROVIDED)
    {
      /* #80 Change sync state so that later update effectively sets the correct state. */
      dynSync->SyncState = OS_SCHTSYNCSTATUS_ASYNC;                                                                     /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    }
    /* #90 Update the deviation. */
    Os_SchTSyncUpdateDeviation(ScheduleTable, SyncTimeNow);                                                             /* SBSW_OS_FC_PRECONDITION */

    /* #100 Update synchronization state. */
    Os_SchTSyncUpdateSyncStatus(ScheduleTable);                                                                         /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_SchTIsSynchronizedExplicit()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SchTIsSynchronizedExplicit,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return (Os_StdReturnType)(ScheduleTable->SyncKind == OS_SCHT_SYNC_KIND_EXPLICIT);                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SchTIsSynchronous()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SchTIsSynchronous,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync
))
{
  P2VAR(Os_SchTSyncType, AUTOMATIC, OS_CONST) dynSync;

  dynSync = Os_SchTSyncGetDyn(ScheduleTableSync);                                                                       /* SBSW_OS_FC_PRECONDITION */

  return (Os_StdReturnType)(dynSync->SyncState == OS_SCHTSYNCSTATUS_SYNC);                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SchTHasNextScheduleTable()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,
OS_ALWAYS_INLINE, Os_SchTHasNextScheduleTable,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  P2VAR(Os_SchTType, AUTOMATIC, OS_CONST) dyn;

  dyn = Os_SchTGetDyn(ScheduleTable);                                                                                   /* SBSW_OS_FC_PRECONDITION */

  /* Schedule Table is neither self next nor single shot without successor. */
  return (Os_StdReturnType)((dyn->Next != ScheduleTable) && (dyn->Next != NULL_PTR));                                   /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SchTSwitch()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_SchTSwitch,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) next;
  P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn = Os_SchTGetDyn(ScheduleTable);                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 If the given schedule table is not self nexted: */
  if(ScheduleTable != dyn->Next)
  {
    next = dyn->Next;

    /* #20 Change the state of the given schedule table to STOPPED. */
    /* Stop the current schedule table.  */
    dyn->State = OS_SCHTSTATUS_STOPPED;                                                                                 /* SBSW_OS_SCHT_SCHTGETDYN_002 */

    /* #30 Initialize the next schedule table. */
    Os_SchTReinitNonSync(next, OS_SCHTSTATUS_RUNNING);                                                                  /* SBSW_OS_SCHT_SCHTREINITNONSYNC_001 */

    /* #40 If the given schedule table is explicitly synchronized: */
    if(Os_SchTIsSynchronizedExplicit(ScheduleTable) != 0u)                                                              /* SBSW_OS_FC_PRECONDITION */
    {
      P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) scheduleTableSync;
      P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dynSync;
      P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync_Next;
      P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dynSync_Next;

      scheduleTableSync = Os_SchTSyncGet(ScheduleTable);                                                                /* SBSW_OS_FC_PRECONDITION */
      dynSync = Os_SchTSyncGetDyn(scheduleTableSync);                                                                   /* SBSW_OS_SCHT_SCHTSYNCGETDYN_001 */

      ScheduleTableSync_Next = Os_SchTSyncGet(next);                                                                    /* SBSW_OS_SCHT_SCHTSYNCGET_001 */
      dynSync_Next = Os_SchTSyncGetDyn(ScheduleTableSync_Next);                                                         /* SBSW_OS_FC_PRECONDITION */

      /* #50 Copy sync data of from given schedule table to next. */
      dynSync_Next->SyncState = dynSync->SyncState;                                                                     /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
      dynSync_Next->CounterTimeStamp = dynSync->CounterTimeStamp;                                                       /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
      dynSync_Next->SyncTimeStamp = dynSync->SyncTimeStamp;                                                             /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
      dynSync_Next->Deviation = dynSync->Deviation;                                                                     /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    }
  }
  /* #60 Otherwise: */
  else
  {
    /* #70 Continue with the first expiry point of the current one. */
    dyn->ExPo = ScheduleTable->ExPoHead;                                                                                /* SBSW_OS_SCHT_SCHTGETDYN_002 */
    next = ScheduleTable;
  }

  return next;
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsStopped()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsStopped,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return ((Os_StdReturnType)(Os_SchTGetDyn(ScheduleTable)->State == OS_SCHTSTATUS_STOPPED));                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotStopped()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotStopped,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return ((Os_StdReturnType)(Os_SchTGetDyn(ScheduleTable)->State != OS_SCHTSTATUS_STOPPED));                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotNexted()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotNexted,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return ((Os_StdReturnType)(Os_SchTGetDyn(ScheduleTable)->State != OS_SCHTSTATUS_NEXT));                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotWaiting()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotWaiting,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return ((Os_StdReturnType)(Os_SchTGetDyn(ScheduleTable)->State != OS_SCHTSTATUS_WAITING));                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */ /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotSynchronizedImplicitly()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTCheckIsNotSynchronizedImplicitly,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(ScheduleTable->SyncKind != OS_SCHT_SYNC_KIND_IMPLICIT));                /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsSynchronizedExplicitly()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTCheckIsSynchronizedExplicitly,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
))
{
  return Os_ErrExtendedCheck(Os_SchTIsSynchronizedExplicit(ScheduleTable));                                             /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTCheckUpperBound()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckUpperBound,
(
  Os_TickType Value,
  Os_TickType UpperBound
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(Value <= UpperBound));                                                  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_SchTCheckIsNotZero()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_SchTCheckIsNotZero,
(
  Os_TickType Value
))
{
  return Os_ErrExtendedCheck(((Os_StdReturnType)Value));
}


/***********************************************************************************************************************
 *  Os_SchTReinitNonSync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTReinitNonSync,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_SchTStatusType InitialState
))
{
  P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn = Os_SchTGetDyn(ScheduleTable);                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 Set the schedule table's state to given InitialState. */
  dyn->State = InitialState;                                                                                            /* SBSW_OS_SCHT_SCHTGETDYN_002 */

  /* #20 Make head of the expiry points the current expiry point of the schedule table. */
  dyn->ExPo = ScheduleTable->ExPoHead;                                                                                  /* SBSW_OS_SCHT_SCHTGETDYN_002 */

  /* #30 Set the schedule table's next schedule table to its initial next schedule table. */
  dyn->Next = ScheduleTable->InitialNext;                                                                               /* SBSW_OS_SCHT_SCHTGETDYN_002 */

  /* #40 There is no previous schedule table. */
  dyn->Previous = NULL_PTR;                                                                                             /* SBSW_OS_SCHT_SCHTGETDYN_002 */
}


/***********************************************************************************************************************
 *  Os_SchTReinit()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTReinit,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  Os_SchTStatusType InitialState
))
{
  /* #10 Initialize data which is not relevant for synchronization. */
  Os_SchTReinitNonSync(ScheduleTable, InitialState);                                                                    /* SBSW_OS_FC_PRECONDITION */

  /* #20 If given schedule table is explicitly synchronized: */
  if(Os_SchTIsSynchronizedExplicit(ScheduleTable) != 0u)                                                                /* SBSW_OS_FC_PRECONDITION */
  {
    P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) scheduleTableSync;
    P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dynSync;

    scheduleTableSync = Os_SchTSyncGet(ScheduleTable);                                                                  /* SBSW_OS_FC_PRECONDITION */
    dynSync = Os_SchTSyncGetDyn(scheduleTableSync);                                                                     /* SBSW_OS_SCHT_SCHTSYNCGETDYN_001 */

    /* #30 Set synchronization state to OS_SCHTSYNCSTATUS_NOT_PROVIDED. */
    dynSync->SyncState = OS_SCHTSYNCSTATUS_NOT_PROVIDED;                                                                /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */

    /* #40 Set Deviation to zero. */
    dynSync->Deviation = 0;                                                                                             /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */

    /* #50 If given state is RUNNING: */
    if(InitialState == OS_SCHTSTATUS_RUNNING)
    {
       Os_TickType CounterTimeMod;
       Os_TickType ExpirationTimeMod;

      /* Async start with later synchronization */
      /* #60 Set schedule tables's current counter time stamp to schedule table's counter time stamp. */
      dynSync->CounterTimeStamp = Os_JobGetValue(&(scheduleTableSync->SchT.Job));                                       /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */ /* SBSW_OS_SCHT_JOBGETVALUE_001 */

      /* #70 Set the current synchronization timestamp to become zero on the zero-expiry point */
      /* Need real modulo here as the initial delay of the schedule table may be much longer than its duration */
      CounterTimeMod = (dynSync->CounterTimeStamp) % (scheduleTableSync->Duration);
      ExpirationTimeMod =  Os_JobGetExpirationTimestamp(&(scheduleTableSync->SchT.Job)) % (scheduleTableSync->Duration);/* SBSW_OS_SCHT_JOBGETEXPIRATIONTIMESTAMP_001 */
      dynSync->SyncTimeStamp = Os_SchTSyncSub(scheduleTableSync, CounterTimeMod, ExpirationTimeMod);                    /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */ /* SBSW_OS_SCHT_SYNCSUB_001 */
    }
    /* #80 If given state is WAITING: */
    else if(InitialState == OS_SCHTSTATUS_WAITING)
    {
      /* Schedule table starts after the synchronization timestamp has been provided */
      /* #90 Set schedule tables's current counter time stamp to zero. */
      dynSync->CounterTimeStamp = 0;                                                                                    /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */

      /* #100 Set current synchronization timestamp to zero. */
      dynSync->SyncTimeStamp = 0;                                                                                       /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */

    }
    else
    {
      /* In any other case, there is nothing to be done. MISRA 14.10 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_SchTSyncUpdateSyncStatus()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_SchTSyncUpdateSyncStatus,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync
))
{
  P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dyn;

  dyn = Os_SchTSyncGetDyn(ScheduleTableSync);                                                                           /* SBSW_OS_FC_PRECONDITION */

  /* #10 If there is a synchronization time provided: */
  if(dyn->SyncState != OS_SCHTSYNCSTATUS_NOT_PROVIDED)
  {
    Os_StdReturnType withinPrecision;

    /* #30 If the deviation is within the schedule table's precision (positive and negative deviation): */
    withinPrecision = ((Os_StdReturnType)( (        dyn->Deviation    <= ScheduleTableSync->Precision)                  /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                    || ((Os_TickType)(-((Os_TickDiffType)(dyn->Deviation))) <= ScheduleTableSync->Precision) ) );

    if(withinPrecision != 0u)
    {
      /* #40 Set sync status to SYNC. */
      dyn->SyncState = OS_SCHTSYNCSTATUS_SYNC;                                                                          /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    }
    /* #50 Otherwise: */
    else
    {
      /* #60 Set sync status to ASYNC. */
      dyn->SyncState = OS_SCHTSYNCSTATUS_ASYNC;                                                                         /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_SchTSyncUpdateSyncPoint()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncUpdateSyncPoint,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync
))
{
  P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dyn;
  Os_TickType counterTimeNow;
  Os_TickType diffCounter;
  Os_TickType diffSync;

  dyn = Os_SchTSyncGetDyn(ScheduleTableSync);                                                                           /* SBSW_OS_FC_PRECONDITION */
  counterTimeNow = Os_JobGetValue(&(ScheduleTableSync->SchT.Job));                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 Calculate the ticks since the last sync point. */
  /* diff = (now - lastTimeStamp) MOD Duration */
  diffCounter = Os_JobSub(&(ScheduleTableSync->SchT.Job), counterTimeNow, dyn->CounterTimeStamp);                       /* SBSW_OS_FC_PRECONDITION */
  diffSync = Os_SchTSyncMod(ScheduleTableSync, diffCounter);                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #20 Update sync point. */
  dyn->SyncTimeStamp = Os_SchTSyncAddAndMod(ScheduleTableSync, dyn->SyncTimeStamp, diffSync);                           /* SBSW_OS_SCHT_SCHTGETDYN_002 */ /* SBSW_OS_FC_PRECONDITION */
  dyn->CounterTimeStamp = counterTimeNow;                                                                               /* SBSW_OS_SCHT_SCHTGETDYN_002 */
}


/***********************************************************************************************************************
 *  Os_SchTExPoWorkAction()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTExPoWorkAction,
(
  P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) ExPo
))
{
  Os_StatusType status;

  /* #10 Activate all configured tasks. */
  {
    Os_SchTTaskIdxType taskIdx;
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) task;
    P2CONST(Os_SchTExPoActionTaskConfigType, AUTOMATIC, OS_CONST) actionTask = ExPo->Tasks;

    for(taskIdx = ((Os_SchTTaskIdxType)0); taskIdx < ExPo->TaskCount; ++taskIdx)
    {
      task = actionTask[taskIdx].Task;
      status = Os_TaskActivateTaskInternal(task);                                                                       /* SBSW_OS_SCHT_TASKACTIVATETASKINTERNAL_001 */

      Os_ErrReportSchTExPoActivateTask(status, Os_TaskGetId(task));                                                     /* SBSW_OS_SCHT_TASKGETID_001 */
    }
  }

  /* #20 Set each configured event. */
  {
    Os_SchTEventIdxType eventIdx;
    EventMaskType eventMask;
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CONST) eventTask;
    P2CONST(Os_SchTExPoActionEventConfigType, AUTOMATIC, OS_CONST) actionEvent = ExPo->Events;

    for(eventIdx = 0; eventIdx < ExPo->EventCount; ++eventIdx)
    {
      eventMask = actionEvent[eventIdx].EventMask;
      eventTask = actionEvent[eventIdx].Task;

      status = Os_EventSetInternal(eventTask, eventMask);                                                               /* SBSW_OS_SCHT_EVENTSETINTERNAL_001 */

      Os_ErrReportSchTExPoSetEvent(status, Os_TaskGetId(eventTask), eventMask);                                         /* SBSW_OS_SCHT_TASKGETID_002 */
    }
  }
}


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointGeneral()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointGeneral,
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
))
{
  /* #10 Write offset to RelativeOffsetToNext. */
  *RelativeOffsetToNext = Os_SchTExPoGetCurrent(ScheduleTable)->RelOffsetToNext;                                        /* SBSW_OS_PWA_PRECONDITION */ /* SBSW_OS_FC_PRECONDITION */

  /* #20 Inform the schedule table about the next expiry point to be executed. */
  Os_SchTExPoSelectNext(ScheduleTable);                                                                                 /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointWithSyncZero()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointWithSyncZero,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
))
{
  /* #10 Update schedule table's sync point time stamp. */
  Os_SchTSyncUpdateSyncPoint(ScheduleTableSync);                                                                        /* SBSW_OS_FC_PRECONDITION */

  /* #20 Update schedule table's sync status. */
  Os_SchTSyncUpdateSyncStatus(ScheduleTableSync);                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #30 Execute general expiry point actions. */
  Os_SchTWorkExpiryPointGeneral(&(ScheduleTableSync->SchT), RelativeOffsetToNext);                                      /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointWithSync()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointWithSync,
(
  P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) ScheduleTableSync,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
))
{
  P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dyn;

  dyn = Os_SchTSyncGetDyn(ScheduleTableSync);                                                                           /* SBSW_OS_FC_PRECONDITION */

  /* #10 Update schedule table's sync point time stamp. */
  Os_SchTSyncUpdateSyncPoint(ScheduleTableSync);                                                                        /* SBSW_OS_FC_PRECONDITION */

  /* #20 Update schedule table's sync status. */
  Os_SchTSyncUpdateSyncStatus(ScheduleTableSync);                                                                       /* SBSW_OS_FC_PRECONDITION */

  /* #30 Modify the relative offset to the next expiry point in accordance to the synchronization parameters. */
  {
    P2CONST(Os_SchTExPoConfigType, AUTOMATIC, OS_CONST) exPo;
    P2CONST(Os_SchTExPoSyncConfigType, AUTOMATIC, OS_CONST) exPoSync;
    Os_TickType correction;

    exPo = Os_SchTExPoGetCurrent(&(ScheduleTableSync->SchT));                                                           /* SBSW_OS_FC_PRECONDITION */
    exPoSync = Os_SchTExPo2SyncExPo(exPo);                                                                              /* SBSW_OS_SCHT_SCHTEXPO2SYNCEXPO_001 */

    /* #40 If the current deviation is positive, counter has to be advanced: */
    if(dyn->Deviation <= ((Os_TickType) (OS_TIMER_TICKTYPE_MAX)))
    {
      /* #50 Correction = min(Deviation, MaxLengthOfNext). */
      if(dyn->Deviation > exPoSync->MaxLengthOfNext)
      {
        correction = exPoSync->MaxLengthOfNext;
      }
      else
      {
        correction = dyn->Deviation;
      }
    }
    /* #60 If the current deviation is negative, counter has to be retarded: */
    else
    {
      /* #70 Correction = max(Deviation, MaxShortenOfNext). */
      /* Hint: Both are negative! */
      if(dyn->Deviation < exPoSync->MaxShortenOfNext)
      {
        correction = exPoSync->MaxShortenOfNext;
      }
      else
      {
        correction = dyn->Deviation;
      }
    }

    /* #80 Update deviation and relative offset to next expiry point. */
    dyn->Deviation -= correction;                                                                                       /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */
    *RelativeOffsetToNext = exPo->RelOffsetToNext + correction;                                                         /* SBSW_OS_PWA_PRECONDITION */
  }

  /* #90 Inform the schedule table about the next expiry point to be executed. */
  Os_SchTExPoSelectNext(&(ScheduleTableSync->SchT));                                                                    /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointLast()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointLast,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
))
{
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) next;

  /* #10 Switch to the next schedule table. */
  next = Os_SchTSwitch(ScheduleTable);                                                                                  /* SBSW_OS_FC_PRECONDITION */
  *RelativeOffsetToNext = 0;                                                                                            /* SBSW_OS_PWA_PRECONDITION */
  Os_JobCopyExpirationTimestamp(&(next->Job), &(ScheduleTable->Job));                                                   /* SBSW_OS_SCHT_JOBCOPYEXPIRATIONTIMESTAMP_001 */

  return next;
}


/***********************************************************************************************************************
 *  Os_SchTWorkExpiryPointLastSingleShot()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST), OS_CODE, OS_ALWAYS_INLINE,
Os_SchTWorkExpiryPointLastSingleShot,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  P2VAR(Os_TickType, AUTOMATIC, OS_VAR_NOINIT) RelativeOffsetToNext
))
{
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) next;
  P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn = Os_SchTGetDyn(ScheduleTable);                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 If a next schedule table shall be executed: */
  if(dyn->Next != NULL_PTR)
  {
    /* #20 Switch to next schedule table. */
    next = Os_SchTWorkExpiryPointLast(ScheduleTable, RelativeOffsetToNext);                                             /* SBSW_OS_FC_PRECONDITION */
  }
  /* #30 Otherwise: */
  else
  {
    /* #40 Set schedule table state to STOPPED. */
    dyn->State = OS_SCHTSTATUS_STOPPED;                                                                                 /* SBSW_OS_SCHT_SCHTGETDYN_002 */
    next = NULL_PTR;
  }

  return next;
}


/***********************************************************************************************************************
 *  Os_SchTSyncMod()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncMod,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Value
))
{
  Os_TickType result;

  result = Value;
  if(result >= ScheduleTableSync->Duration)
  {
    result -= ScheduleTableSync->Duration;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SchTSyncAddAndMod()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncAddAndMod,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Lhs,
  Os_TickType Rhs
))
{
  Os_TickType result;

  result = Lhs + Rhs;
  if(result >= ScheduleTableSync->Duration)
  {
    result -= ScheduleTableSync->Duration;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SchTSyncSubAndModHalfRange()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncSubAndModHalfRange,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Lhs,
  Os_TickType Rhs
))
{
  Os_TickType result;

  /* #10 Subtract. */
  result = Lhs - Rhs;

  /* #20 If Lhs is positive and Rhs is negative: */
  if((Lhs < ScheduleTableSync->DurationHalf) && (Rhs >= ScheduleTableSync->DurationHalf))
  {
    /* #30 If the result exceeds the positive half duration limit: */
    if(result >= ScheduleTableSync->DurationHalf)
    {
      /* #40 Move the result into the negative half. */
      result -= ScheduleTableSync->Duration;
    }
  }
  /* #50 If Lhs is negative and Rhs is positive: */
  else if((Lhs >= ScheduleTableSync->DurationHalf) && (Rhs < ScheduleTableSync->DurationHalf))
  {
    /* #60 If the result exceeds the negative duration limit: */
    Os_TickType resultInverted = (Os_TickType)(-(Os_TickDiffType)result);

    if(resultInverted > ScheduleTableSync->DurationHalf)
    {
      /* #70 Move the result into the positive half. */
      result += ScheduleTableSync->Duration;
    }
  }
  else
  {
    /* No mod operation required as identical signs of Lhs and Rhs always leads to a valid result. */
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SchTSyncFull2HalfRange()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncFull2HalfRange,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Operand
))
{
  Os_TickType result;

  /* #10 If the operand exceeds or equals the half limit, subtract the duration. */
  if(Operand >= ScheduleTableSync->DurationHalf)
  {
    /* This may not cause an overflow */
    result = Operand - ScheduleTableSync->Duration;
  }
  /* #20 Otherwise keep the operand as it is.*/
  else
  {
    result = Operand;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SchTSyncSub()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTSyncSub,
(
  P2CONST(Os_SchTSyncConfigType, TYPEDEF, OS_CONST) ScheduleTableSync,
  Os_TickType Lhs,
  Os_TickType Rhs
))
{
  Os_TickType result;

  /* #10 Ensure that there is never an overflow over the type limit. */
  if(Lhs >= Rhs)
  {
    /* This may not cause an overflow */
    result = Lhs - Rhs;
  }
  else
  {
    /* Simply calculating Lhs-Rhs would cause an overflow.
     * As Duration mod Duration = 0, adding Duration is always allowed: */
    result = (ScheduleTableSync->Duration - Rhs) + Lhs;
  }

  return result;
}


/***********************************************************************************************************************
 *  Os_SchTStartRelative()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartRelative,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  TickType Offset
))
{
  /* #10 Tell the counter to handle the schedule table's job after the relative time defined
   *     by the attribute 'Offset'. */
  Os_JobAddRel(&(ScheduleTable->Job), Offset);                                                                          /* SBSW_OS_FC_PRECONDITION */

  /* #20 Reinitialize the schedule table. */
  Os_SchTReinit(ScheduleTable, OS_SCHTSTATUS_RUNNING);                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTStartAbsolute()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartAbsolute,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable,
  TickType Start
))
{
  /* #10 Tell the counter to handle the schedule table's job after the absolute time defined
   *     by the attribute 'Start'. */
  Os_JobAddAbs(&(ScheduleTable->Job), Start);                                                                           /* SBSW_OS_FC_PRECONDITION */

  /* #20 Reinitialize the schedule table. */
  Os_SchTReinit(ScheduleTable, OS_SCHTSTATUS_RUNNING);                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTStartSynchronous()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTStartSynchronous,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable
))
{
  /* #10 Reinitialize the schedule table. */
  Os_SchTReinit(ScheduleTable, OS_SCHTSTATUS_WAITING);                                                                  /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTGetInitialOffset()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,
Os_SchTGetInitialOffset,
(
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) ScheduleTable
))
{
  return ScheduleTable->ExPoHead->RelOffsetToNext;
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_Api_StartScheduleTableRel()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_StartScheduleTableRel
(
  ScheduleTableType ScheduleTableID,
  TickType Offset
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Check of schedule table ID and get schedule table configuration pointer. */
  /* #20 Checks of caller core/thread status (correct call context and interrupt status). */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_STARTSCHEDULETABLEREL) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    /* #30 Check access right of the calling application. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* #40 If the given schedule table belongs to the local core call \ref Os_SchTStartScheduleTableRel(). */
      if(OS_LIKELY(Os_AppIsCoreLocal(scheduleTable->OwnerApplication) != 0u))                                           /* SBSW_OS_SCHT_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        status = Os_SchTStartScheduleTableRel(scheduleTable, Offset);                                                   /* SBSW_OS_SCHT_SCHTSTARTSCHEDULETABLEREL_001 */

        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      /* #50 Otherwise, send signal to foreign core to start the schedule table relative. */
      else
      {
        status = Os_XSigSend_StartScheduleTableRel(                                                                     /* SBSW_OS_SCHT_XSIGSEND_001 */
            Os_SchTGetCore(scheduleTable),                                                                              /* SBSW_OS_SCHT_SCHTGETCORE_001 */
            currentThread,
            ScheduleTableID,
            Offset);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_StartScheduleTableAbs()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_StartScheduleTableAbs
(
  ScheduleTableType ScheduleTableID,
  TickType Start
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Check of schedule table ID and get schedule table configuration pointer. */
  /* #20 Perform checks of caller core/thread status (correct call context and interrupt status). */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_STARTSCHEDULETABLEABS) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    /* #30 Check access right of the calling application. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      if(OS_LIKELY(Os_AppIsCoreLocal(scheduleTable->OwnerApplication) != 0u))                                           /* SBSW_OS_SCHT_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        /* #40 If the given schedule table belongs to the local core call \ref Os_SchTStartScheduleTableAbs(). */
        status = Os_SchTStartScheduleTableAbs(scheduleTable, Start);                                                    /* SBSW_OS_SCHT_SCHTSTARTSCHEDULETABLEABS_001 */

        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      else
      {
        /* #50 Otherwise, send signal to foreign core to start the schedule table absolute. */
        status = Os_XSigSend_StartScheduleTableAbs(                                                                     /* SBSW_OS_SCHT_XSIGSEND_001 */
            Os_SchTGetCore(scheduleTable),                                                                              /* SBSW_OS_SCHT_SCHTGETCORE_001 */
            currentThread,
            ScheduleTableID,
            Start);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_StopScheduleTable()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_StopScheduleTable
(
  ScheduleTableType ScheduleTableID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Check of schedule table ID and get schedule table configuration pointer. */
  /* #20 Perform checks of caller core/thread status (correct call context and interrupt status). */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_STOPSCHEDULETABLE) == OS_CHECK_FAILED))    /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    /* #30 Check access right of the calling application. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      if(OS_LIKELY(Os_AppIsCoreLocal(scheduleTable->OwnerApplication) != 0u))                                           /* SBSW_OS_SCHT_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        /* #40 If the given schedule table belongs to the local core call \ref Os_SchTStopScheduleTable(). */
        status = Os_SchTStopScheduleTable(scheduleTable);                                                               /* SBSW_OS_SCHT_SCHTSTOPSCHEDULETABLE_001 */

        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      else
      {
        /* #50 Otherwise, send signal to foreign core to stop the schedule table. */
        status = Os_XSigSend_StopScheduleTable(                                                                         /* SBSW_OS_SCHT_XSIGSEND_001 */
            Os_SchTGetCore(scheduleTable),                                                                              /* SBSW_OS_SCHT_SCHTGETCORE_001 */
            currentThread,
            ScheduleTableID);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_NextScheduleTable()
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
FUNC(Os_StatusType, OS_CODE) Os_Api_NextScheduleTable
(
  ScheduleTableType ScheduleTableID_From,
  ScheduleTableType ScheduleTableID_To
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Check of schedule table ID and get schedule table configuration pointer. */
  /* #20 Perform checks of caller core/thread status (correct call context and interrupt status). */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_NEXTSCHEDULETABLE) == OS_CHECK_FAILED))    /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID_From) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID_To) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_2;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable_From;
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable_To;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    scheduleTable_From = Os_SchTId2SchT(ScheduleTableID_From);
    scheduleTable_To = Os_SchTId2SchT(ScheduleTableID_To);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    /* #30 Check access right of the calling application. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable_From)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                           /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable_To)) == OS_CHECK_FAILED) )
    {
      status = OS_STATUS_ACCESSRIGHTS_2;
    }
    else if(OS_UNLIKELY(Os_JobCheckAssignedToSameCounter(                                                               /* SBSW_OS_FC_PRECONDITION */
            &(scheduleTable_From->Job), &(scheduleTable_To->Job)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ID_DIFFERENT_COUNTER;
    }
    else if(OS_UNLIKELY(Os_ErrExtendedCheck(                                                                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
                    (Os_StdReturnType)(scheduleTable_From->SyncKind == scheduleTable_To->SyncKind)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ID_DIFFERENT_SYNC;
    }
    else
    {
      if(OS_LIKELY(Os_AppIsCoreLocal(scheduleTable_From->OwnerApplication) != 0u))                                      /* SBSW_OS_SCHT_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        /* #40 If the given schedule table belongs to the local core call \ref Os_SchTNextScheduleTable(). */
        status = Os_SchTNextScheduleTable(scheduleTable_From, scheduleTable_To);                                        /* SBSW_OS_SCHT_SCHTNEXTSCHEDULETABLE_001 */

        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      else
      {
        /* #50 Otherwise, send signal to foreign core to perform NextScheduleTable. */
        status = Os_XSigSend_NextScheduleTable(                                                                         /* SBSW_OS_SCHT_XSIGSEND_001 */
            Os_SchTGetCore(scheduleTable_From),                                                                         /* SBSW_OS_SCHT_SCHTGETCORE_001 */
            currentThread,
            ScheduleTableID_From,
            ScheduleTableID_To);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_StartScheduleTableSynchron()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_StartScheduleTableSynchron
(
  ScheduleTableType ScheduleTableID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread,                                                          /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
      OS_APICONTEXT_STARTSCHEDULETABLESYNCHRON) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_IntStateType interruptState;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(Os_AppGetCore(scheduleTable->OwnerApplication)) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_COREASRCHECKISCORELOCAL_001 */ /* SBSW_OS_SCHT_APPGETCORE_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_CORE;
    }
    else if(OS_UNLIKELY(Os_AppCheckIsAccessible(scheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                  /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
    {
      status = OS_STATUS_NOTACCESSIBLE_1;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsSynchronizedExplicitly(scheduleTable) == OS_CHECK_FAILED))                        /* SBSW_OS_SCHT_SCHTCHECKISSYNCHRONIZEDEXPLICITLY_001 */
    {
      status = OS_STATUS_ID_TYPE_1;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsStopped(scheduleTable) == OS_CHECK_FAILED))                                       /* SBSW_OS_SCHT_SCHTCHECKISSTOPPED_001 */
    {
      status = OS_STATUS_STATE_1;
    }
    else
    {
      /* #20 Prepare the schedule table to start running after provision of the synchronization count. */
      Os_SchTStartSynchronous(scheduleTable);                                                                           /* SBSW_OS_SCHT_SCHTSTARTSYNCHRONOUS_001 */
      status = OS_STATUS_OK;
    }

    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_SyncScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_SyncScheduleTable
(
  ScheduleTableType ScheduleTableID,
  TickType Value
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_SYNCSCHEDULETABLE) == OS_CHECK_FAILED))    /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_IntStateType interruptState;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(Os_AppGetCore(scheduleTable->OwnerApplication)) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_COREASRCHECKISCORELOCAL_001 */ /* SBSW_OS_SCHT_APPGETCORE_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_CORE;
    }
    else if(OS_UNLIKELY(Os_AppCheckIsAccessible(scheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                  /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
    {
      status = OS_STATUS_NOTACCESSIBLE_1;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsSynchronizedExplicitly(scheduleTable) == OS_CHECK_FAILED))                        /* SBSW_OS_SCHT_SCHTCHECKISSYNCHRONIZEDEXPLICITLY_001 */
    {
      status = OS_STATUS_ID_TYPE_1;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsNotStopped(scheduleTable) == OS_CHECK_FAILED))                                    /* SBSW_OS_SCHT_SCHTCHECKISNOTSTOPPED_001 */
    {
      status = OS_STATUS_STATE_STOPPED;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsNotNexted(scheduleTable) == OS_CHECK_FAILED))                                     /* SBSW_OS_SCHT_SCHTCHECKISNOTNEXTED_001 */
    {
      status = OS_STATUS_STATE_NEXTED;
    }
    else
    {
      P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) scheduleTableSync;

      scheduleTableSync = Os_SchTSyncGet(scheduleTable);                                                                /* SBSW_OS_SCHT_SCHTSYNCGET_002 */

      if(OS_UNLIKELY(Os_SchTCheckUpperBound(Value, scheduleTableSync->Duration-1u) == OS_CHECK_FAILED))
      {
        status = OS_STATUS_VALUE_IS_OUT_OF_BOUNDS_2;
      }
      else
      {
        /* #20 Provide the given synchronization value. */
        Os_SchTSyncScheduleTable(scheduleTableSync, Value);                                                             /* SBSW_OS_SCHT_SCHTSYNCSCHEDULETABLE_001 */

        status = OS_STATUS_OK;
      }
    }

    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


/***********************************************************************************************************************
 *  Os_Api_SetScheduleTableAsync()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_SetScheduleTableAsync
(
  ScheduleTableType ScheduleTableID
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_SETSCHEDULETABLEASYNC) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;
    Os_IntStateType interruptState;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    Os_IntSuspend(&interruptState);                                                                                     /* SBSW_OS_FC_POINTER2LOCAL */

    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else if(OS_UNLIKELY(Os_CoreAsrCheckIsCoreLocal(Os_AppGetCore(scheduleTable->OwnerApplication)) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_COREASRCHECKISCORELOCAL_001 */ /* SBSW_OS_SCHT_APPGETCORE_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      status = OS_STATUS_CORE;
    }
    else if(OS_UNLIKELY(Os_AppCheckIsAccessible(scheduleTable->OwnerApplication) == OS_CHECK_FAILED ))                  /* SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001 */
    {
      status = OS_STATUS_NOTACCESSIBLE_1;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsSynchronizedExplicitly(scheduleTable) == OS_CHECK_FAILED))                        /* SBSW_OS_SCHT_SCHTCHECKISSYNCHRONIZEDEXPLICITLY_001 */
    {
      status = OS_STATUS_ID_TYPE_1;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsNotStopped(scheduleTable) == OS_CHECK_FAILED))                                    /* SBSW_OS_SCHT_SCHTCHECKISNOTSTOPPED_001 */
    {
      status = OS_STATUS_STATE_STOPPED;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsNotNexted(scheduleTable) == OS_CHECK_FAILED))                                     /* SBSW_OS_SCHT_SCHTCHECKISNOTNEXTED_001 */
    {
      status = OS_STATUS_STATE_NEXTED;
    }
    else if(OS_UNLIKELY(Os_SchTCheckIsNotWaiting(scheduleTable) == OS_CHECK_FAILED))                                    /* SBSW_OS_SCHT_SCHTCHECKISNOTWAITING_001 */
    {
      status = OS_STATUS_STATE_WAITING;
    }
    else
    {
      P2VAR(Os_SchTSyncType, AUTOMATIC, OS_VAR_NOINIT) dyn;
      P2CONST(Os_SchTSyncConfigType, AUTOMATIC, OS_CONST) scheduleTableSync;

      scheduleTableSync = Os_SchTSyncGet(scheduleTable);                                                                /* SBSW_OS_SCHT_SCHTSYNCGET_002 */
      dyn = Os_SchTSyncGetDyn(scheduleTableSync);                                                                       /* SBSW_OS_SCHT_SCHTSYNCGETDYN_001 */

      dyn->SyncState = OS_SCHTSYNCSTATUS_NOT_PROVIDED;                                                                  /* SBSW_OS_SCHT_SCHTSYNCGETDYN_002 */

      status = OS_STATUS_OK;
    }

    Os_IntResume(&interruptState);                                                                                      /* SBSW_OS_FC_POINTER2LOCAL */
  }

  return status;
}                                                                                                                       /* PRQA S 6030, 6050, 6080 */ /* MD_Os_STCYC, MD_Os_STCAL, MD_Os_STMIF */


# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
/* This suppresses the warning with regard to "possibly uninitialized variable" for the local variable "status".
 * This can be suppressed, since Status is always initialized inside the function. The function either returns
 * status with a valid value or gets stuck in KernelPanic.
 */
#  pragma warning 541                                                                                                   /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif
/***********************************************************************************************************************
 *  Os_Api_GetScheduleTableStatus()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_GetScheduleTableStatus
(
  ScheduleTableType ScheduleTableID,
  ScheduleTableStatusRefType ScheduleStatus
)
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform checks. */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    status = Os_ErrSetOkInStdStatus(OS_STATUS_ID_1);                                                                    /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }
  else if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_GETSCHEDULETABLESTATUS) == OS_CHECK_FAILED)) /* SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_SchTCheckId(ScheduleTableID) == OS_CHECK_FAILED ))
  {
    status = OS_STATUS_ID_1;
  }
  else if(OS_UNLIKELY(Os_ThreadCheckAreInterruptsEnabled(currentThread) == OS_CHECK_FAILED))                            /* SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001 */
  {
    status = OS_STATUS_DISABLEDINT;
  }
  else
  {
    P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) scheduleTable;
    P2CONST(Os_AppConfigType, TYPEDEF, OS_CONST) currentApplication;

    scheduleTable = Os_SchTId2SchT(ScheduleTableID);
    currentApplication = Os_ThreadGetCurrentApplication(currentThread);                                                 /* SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001 */

    /* #20 Check access right of the calling application. */
    if(OS_UNLIKELY(Os_AppCheckAccess(currentApplication,                                                                /* SBSW_OS_SCHT_APPCHECKACCESS_001 */ /* SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001 */
          Os_SchTGetAccessingApplications(scheduleTable)) == OS_CHECK_FAILED))
    {
      status = OS_STATUS_ACCESSRIGHTS_1;
    }
    else
    {
      /* #30 Get the state cross core or from local function. */
      if(OS_LIKELY(Os_AppIsCoreLocal(scheduleTable->OwnerApplication) != 0u))                                           /* SBSW_OS_SCHT_APPISCORELOCAL_001 */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
      {
        Os_IntStateType interruptState;

        Os_IntSuspend(&interruptState);                                                                                 /* SBSW_OS_FC_POINTER2LOCAL */

        status = Os_SchTGetScheduleTableStatus(scheduleTable, ScheduleStatus);                                          /* SBSW_OS_SCHT_SCHTGETSCHEDULETABLESTATUS_001 */

        Os_IntResume(&interruptState);                                                                                  /* SBSW_OS_FC_POINTER2LOCAL */
      }
      else
      {
        status = Os_XSigSend_GetScheduleTableStatus(                                                                    /* SBSW_OS_SCHT_XSIGSEND_001 */
          Os_SchTGetCore(scheduleTable),                                                                                /* SBSW_OS_SCHT_SCHTGETCORE_001 */
          currentThread,
          ScheduleTableID,
          ScheduleStatus);
      }
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050, 6080 */ /* MD_Os_STCAL, MD_Os_STMIF */
# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
#  pragma warning restore                                                                                               /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif


/***********************************************************************************************************************
 *  Os_SchTInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SchTInit
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT,
  AppModeType AppMode
)
{
  P2CONST(Os_SchTAutostartConfigType, AUTOMATIC, OS_CONST) autostartConfig = &SchT->Autostart;

  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #15 If the given mode is one of the given schedule table's autostart modes: */
  if((autostartConfig->ApplicationModes & AppMode) != 0u)
  {
    /* #20 Start the schedule table with respect to their start type. */
    switch(autostartConfig->AutostartModes)
    {
      case OS_SCHT_AUTOSTART_RELATIVE:
        Os_SchTStartRelative(SchT, autostartConfig->StartTime);                                                         /* SBSW_OS_FC_PRECONDITION */
        break;

      case OS_SCHT_AUTOSTART_SYNCHRON:
        Os_SchTStartSynchronous(SchT);                                                                                  /* SBSW_OS_FC_PRECONDITION */
        break;

      case OS_SCHT_AUTOSTART_ABSOLUTE:
        Os_SchTStartAbsolute(SchT, autostartConfig->StartTime);                                                         /* SBSW_OS_FC_PRECONDITION */
        break;

      case OS_SCHT_AUTOSTART_NON:                                                                                       /* COV_OS_INVSTATE */
        /* Invalid state. */
      default:                                                                                                          /* COV_OS_INVSTATE */
        Os_ErrKernelPanic();
        break;
    }
  }
  /* #30 Otherwise, initialize the schedule table stopped. */
  else
  {
    Os_SchTReinit(SchT, OS_SCHTSTATUS_STOPPED);                                                                         /* SBSW_OS_FC_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_SchTKill()
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
FUNC(void, OS_CODE) Os_SchTKill
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) SchT
)
{
  P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dyn;
  dyn = Os_SchTGetDyn(SchT);                                                                                            /* SBSW_OS_FC_PRECONDITION */

  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #15 If the given schedule table is in state NEXT, restore the previous schedule table next pointer to the initial
         one.*/
  if(dyn->State == OS_SCHTSTATUS_NEXT)
  {
    P2VAR(Os_SchTType, AUTOMATIC, OS_VAR_NOINIT) dynPrevious;
    dynPrevious = Os_SchTGetDyn(dyn->Previous);                                                                         /* SBSW_OS_SCHT_SCHTGETDYN_003 */

    dynPrevious->Next = dyn->Previous->InitialNext;                                                                     /* SBSW_OS_SCHT_SCHTGETDYN_002 */
  }
  /* #20 If the given schedule table is in state RUNNING or RUNNING_AND_SYNCHRONOUS delete the job queue. */
  else if (dyn->State == OS_SCHTSTATUS_RUNNING)
  {
    Os_JobDelete(&(SchT->Job));                                                                                         /* SBSW_OS_FC_PRECONDITION */

    /* #30 If the given schedule table has a succeeding one, ReInit the succeeding schedule table to status STOPPED. */
    if(Os_SchTHasNextScheduleTable(SchT) != 0u)                                                                         /* SBSW_OS_FC_PRECONDITION */
    {
      Os_SchTReinit(dyn->Next, OS_SCHTSTATUS_STOPPED);                                                                  /* SBSW_OS_SCHT_SCHTREINIT_001 */
    }
  }
  else
  {
    /* In any other case (STOPPED, WAITING), there is no running job to delete. MISRA 14.10 */
  }

  /* #40 Always ReInit the schedule table to STOPPED status. */
  Os_SchTReinit(SchT, OS_SCHTSTATUS_STOPPED);                                                                           /* SBSW_OS_FC_PRECONDITION */

}


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableRelLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_SchTStartScheduleTableRelLocal                                                          /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Offset
)
{
  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #20 Call internal function for starting the given schedule table relatively.  */
  return Os_SchTStartScheduleTableRel(ScheduleTable, Offset);                                                           /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTStartScheduleTableAbsLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_SchTStartScheduleTableAbsLocal                                                          /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  TickType Start
)
{
  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #20 Call internal function for starting the given schedule table absolutely.  */
  return Os_SchTStartScheduleTableAbs(ScheduleTable, Start);                                                            /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTStopScheduleTableLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_SchTStopScheduleTableLocal                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable
)
{
  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #20 Call internal function for stopping the given schedule table.  */
  return Os_SchTStopScheduleTable(ScheduleTable);                                                                       /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_SchTNextScheduleTableLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_SchTNextScheduleTableLocal                                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_From,
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable_To
)
{
  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #20 Call internal function for nexting the given schedule tables.  */
  return Os_SchTNextScheduleTable(ScheduleTable_From, ScheduleTable_To);                                                /* SBSW_OS_FC_PRECONDITION */
}


# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
/* This suppresses the warning with regard to "possibly uninitialized variable" for the return value.
 * This can be suppressed, since the function Os_SchTGetScheduleTableStatus either returns the status
 * or gets stuck in Os_ErrKernelPanic.
 */
#  pragma warning 541                                                                                                   /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif

/***********************************************************************************************************************
 *  Os_SchTGetScheduleTableStatusLocal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_SchTGetScheduleTableStatusLocal                                                         /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
(
  P2CONST(Os_SchTConfigType, AUTOMATIC, OS_CONST) ScheduleTable,
  ScheduleTableStatusRefType ScheduleStatus
)
{
  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  /* #20 Call internal function for getting the given schedule table's state.  */
  return Os_SchTGetScheduleTableStatus(ScheduleTable, ScheduleStatus);                                                  /* SBSW_OS_FC_PRECONDITION */
}

# if defined (OS_CFG_COMPILER_TASKING)                                                                                  /* COV_OS_COMPILERPRAGMA */
#  pragma warning restore                                                                                               /* PRQA S 3116 */ /* MD_MSR_Pragma */
# endif


/***********************************************************************************************************************
 *  Os_SchTWorkScheduleTable()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_SchTWorkScheduleTable
(
  P2CONST(Os_JobConfigType, TYPEDEF, OS_CONST) Job
)
{
  P2CONST(Os_SchTConfigType, TYPEDEF, OS_CONST) currentSchT = Os_SchTJob2SchT(Job);                                     /* SBSW_OS_FC_PRECONDITION */
  Os_TickType relativeOffsetToNext;

  /* #10 If the module is not enabled: KernelPanic */
  if(Os_SchTIsEnabled() == 0u)                                                                                          /* COV_OS_INVSTATE */ /* PRQA S 2992, 2996 */ /* MD_Os_Rule14.3_2992, MD_Os_Rule2.2_2996 */
  {
    Os_ErrKernelPanic();                                                                                                /* PRQA S 2880 */ /* MD_Os_Rule2.1_2880 */
  }

  do
  {
    P2CONST(Os_SchTExPoConfigType, TYPEDEF, OS_CONST) exPo;

    exPo = Os_SchTExPoGetCurrent(currentSchT);                                                                          /* SBSW_OS_SCHT_SCHTEXPOGETCURRENT_001 */
    relativeOffsetToNext = 0;

    /* #15 Perform expiry point actions. */
    Os_SchTExPoWorkAction(exPo);                                                                                        /* SBSW_OS_SCHT_SCHTEXPOWORKACTION_001 */

    /* #20 Call the type specific function of the expiry point. */
    switch(exPo->Kind)
    {
      case OS_SCHT_EXPO_KIND_EXECUTE:
        Os_SchTWorkExpiryPointGeneral(currentSchT, &relativeOffsetToNext);                                              /* SBSW_OS_SCHT_SCHTWORKEXPIRYPOINT_001 */
        break;

      case OS_SCHT_EXPO_KIND_EXECUTE_SYNC:
        Os_SchTWorkExpiryPointWithSync(Os_SchTSyncGet(currentSchT), &relativeOffsetToNext);                             /* SBSW_OS_SCHT_SCHTWORKEXPIRYPOINTWITHSYNC_001 */ /* SBSW_OS_SCHT_SCHTSYNCGET_003 */
        break;

      case OS_SCHT_EXPO_KIND_EXECUTE_SYNC_ZERO:
        Os_SchTWorkExpiryPointWithSyncZero(Os_SchTSyncGet(currentSchT), &relativeOffsetToNext);                         /* SBSW_OS_SCHT_SCHTWORKEXPIRYPOINTWITHSYNC_001 */ /* SBSW_OS_SCHT_SCHTSYNCGET_003 */
        break;

      case OS_SCHT_EXPO_KIND_EXECUTE_CYCLIC:
        currentSchT = Os_SchTWorkExpiryPointLast(currentSchT, &relativeOffsetToNext);                                   /* SBSW_OS_SCHT_SCHTWORKEXPIRYPOINT_001 */
        break;

      case OS_SCHT_EXPO_KIND_EXECUTE_SINGLE_SHOT:
        currentSchT = Os_SchTWorkExpiryPointLastSingleShot(currentSchT, &relativeOffsetToNext);                         /* SBSW_OS_SCHT_SCHTWORKEXPIRYPOINT_001 */
        break;

      default:                                                                                                          /* COV_OS_INVSTATE */
        Os_ErrKernelPanic();
        break;
    }
  }
  while((currentSchT != NULL_PTR) && (relativeOffsetToNext == 0u));


  if(currentSchT != NULL_PTR)
  {
    /* #30 Inform the counter about the relative offset to the next expiry point. */
    Os_JobReload(&(currentSchT->Job), relativeOffsetToNext);                                                            /* SBSW_OS_SCHT_JOBRELOAD_001 */
  }
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */

/* module specific MISRA deviations:
*/

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_SCHT_APPCHECKISACCESSIBLE_001
 \DESCRIPTION    Os_AppCheckIsAccessible is called with the OwnerApplication of a ScheduleTable passed as argument.
 \COUNTERMEASURE \M [CM_OS_SCHTGETAPPLICATION_M]

\ID SBSW_OS_SCHT_SCHTISSYNCHRONOUS_001
 \DESCRIPTION    Os_SchTIsSynchronous is called with the return value of Os_SchTSyncGet.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_SCHTSYNCSCHEDULETABLE_001
 \DESCRIPTION    Os_SchTSyncScheduleTable is called with the return value of Os_SchTSyncGet.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_SCHTGETDYN_001
 \DESCRIPTION    Os_SchTGetDyn is called with the Next pointer derived from the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]
                 \R [CM_OS_SCHTGETNEXT_R]

\ID SBSW_OS_SCHT_SCHTGETDYN_002
 \DESCRIPTION    Write access to the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]

\ID SBSW_OS_SCHT_SCHTGETDYN_003
 \DESCRIPTION    Os_SchTGetDyn is called with the Previous pointer derived from the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]
                 \R [CM_OS_SCHTGETPREVIOUS_1_2_R]
                 \T [CM_OS_SCHTGETPREVIOUS_2_2_T]

\ID SBSW_OS_SCHT_SCHTGETDYN_004
 \DESCRIPTION    Os_SchTGetDyn is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_JOBDELETE_001
 \DESCRIPTION    Os_JobDelete is called with the Previous Job of the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]
                 \R [CM_OS_SCHTGETPREVIOUS_1_2_R]
                 \T [CM_OS_SCHTGETPREVIOUS_2_2_T]

\ID SBSW_OS_SCHT_SCHTREINIT_001
 \DESCRIPTION    Os_SchTReinit is called with the Next pointer derived from the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]
                 \M [CM_OS_SCHTGETNEXT_M]

\ID SBSW_OS_SCHT_SCHTREINITNONSYNC_001
 \DESCRIPTION    Os_SchTReinitNonSync is called with the Next pointer derived from the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]
                 \M [CM_OS_SCHTGETNEXT_M]

\ID SBSW_OS_SCHT_SCHTSYNCGETDYN_001
 \DESCRIPTION    Os_SchTSyncGetDyn is called with the return value of Os_SchTSyncGet.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_SCHTSYNCGETDYN_002
 \DESCRIPTION    Write access to the return value of Os_SchTSyncGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTSYNCGETDYN_M]

\ID SBSW_OS_SCHT_SCHTSYNCGET_001
 \DESCRIPTION    Os_SchTSyncGet is called with the Next pointer derived from the return value of Os_SchTGetDyn.
 \COUNTERMEASURE \M [CM_OS_SCHTGETDYN_M]
                 \M [CM_OS_SCHTGETNEXT_M]

\ID SBSW_OS_SCHT_SCHTSYNCGET_002
 \DESCRIPTION    Os_SchTSyncGet is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_JOBGETVALUE_001
 \DESCRIPTION    Os_JobGetValue is called with the return value of Os_SchTSyncGet.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_JOBGETVALUE_002
 \DESCRIPTION    Os_JobGetValue is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_JOBGETEXPIRATIONTIMESTAMP_001
 \DESCRIPTION    Os_JobGetExpirationTimestamp is called with the return value of Os_SchTSyncGet.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_SYNCSUB_001
 \DESCRIPTION    Os_SchTSyncSub is called with the return value of Os_SchTSyncGet.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_TASKACTIVATETASKINTERNAL_001
 \DESCRIPTION    Os_TaskActivateTaskInternal is called with a Task pointer. The Task pointer is derived from
                 from an index and an array of Tasks. The index is incremented in a loop. The array is derived
                 from the Tasks pointer of an expiry point. The expiry point is passed as argument to the caller.
 \COUNTERMEASURE \M [CM_OS_EXPO_TASKS_M]
                 \R [CM_OS_SCHT_INDEX_R]

\ID SBSW_OS_SCHT_EVENTSETINTERNAL_001
 \DESCRIPTION    Os_EventSetInternal is called with a Task pointer. The Task pointer is derived from
                 from an index and an array of Events. The index is incremented in a loop. The array is derived
                 from the Events pointer of an expiry point. The expiry point is passed as argument to the caller.
 \COUNTERMEASURE \M [CM_OS_EXPO_EVENTS_M]
                 \R [CM_OS_SCHT_INDEX_R]

\ID SBSW_OS_SCHT_TASKGETID_001
 \DESCRIPTION    Os_TaskGetId is called with a Task pointer. The Task pointer is derived from
                 from an index and an array of Tasks. The index is incremented in a loop. The array is derived
                 from the Tasks pointer of an expiry point. The expiry point is passed as argument to the caller.
 \COUNTERMEASURE \M [CM_OS_EXPO_TASKS_M]
                 \R [CM_OS_SCHT_INDEX_R]

\ID SBSW_OS_SCHT_TASKGETID_002
 \DESCRIPTION    Os_TaskGetId is called with a Task pointer. The Task pointer is derived from
                 from an index and an array of Events. The index is incremented in a loop. The array is derived
                 from the Events pointer of an expiry point. The expiry point is passed as argument to the caller.
 \COUNTERMEASURE \M [CM_OS_EXPO_EVENTS_M]
                 \R [CM_OS_SCHT_INDEX_R]

\ID SBSW_OS_SCHT_SCHTEXPO2SYNCEXPO_001
 \DESCRIPTION    Os_SchTExPo2SyncExPo is called with the return value of Os_SchTExPoGetCurrent.
 \COUNTERMEASURE \N [CM_OS_PRECONDITION_N]

\ID SBSW_OS_SCHT_JOBCOPYEXPIRATIONTIMESTAMP_001
 \DESCRIPTION    Os_JobCopyExpirationTimestamp is called with the return value of Os_SchTSwitch and a value which is
                 derived from an argument of the caller. The correctness of the caller argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_SCHTSWITCH_N]

\ID SBSW_OS_SCHT_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SCHT_THREADCHECKAREINTERRUPTSENABLED_001
 \DESCRIPTION    Os_ThreadCheckAreInterruptsEnabled is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SCHT_THREADGETCURRENTAPPLICATION_001
 \DESCRIPTION    Os_ThreadGetCurrentApplication is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_SCHT_APPCHECKACCESS_001
 \DESCRIPTION    Os_AppCheckAccess is called with the return value of Os_ThreadGetCurrentApplication.
 \COUNTERMEASURE \N [CM_OS_THREADGETCURRENTAPPLICATION_N]

\ID SBSW_OS_SCHT_SCHTGETACCESSINGAPPLICATIONS_001
 \DESCRIPTION    Os_SchTGetAccessingApplications is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTSTARTSCHEDULETABLEREL_001
 \DESCRIPTION    Os_SchTStartScheduleTableRel is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTSTARTSCHEDULETABLEABS_001
 \DESCRIPTION    Os_SchTStartScheduleTableAbs is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_XSIGSEND_001
 \DESCRIPTION    A Os_XSigSend function is called with the return value of Os_SchTGetCore and Os_CoreGetThread.
                 Precondition ensures that the pointer return by Os_CoreGetThread is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_SCHTGETCORE_N]

\ID SBSW_OS_SCHT_SCHTGETCORE_001
 \DESCRIPTION    Os_SchTGetCore function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTSTOPSCHEDULETABLE_001
 \DESCRIPTION    Os_SchTStopScheduleTable function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTNEXTSCHEDULETABLE_001
 \DESCRIPTION    Os_SchTNextScheduleTable function is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_COREASRCHECKISCORELOCAL_001
 \DESCRIPTION    Os_CoreAsrCheckIsCoreLocal function is called with the return value of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_SCHT_SCHTCHECKISSYNCHRONIZEDEXPLICITLY_001
 \DESCRIPTION    Os_SchTCheckIsSynchronizedExplicitly function is called with the return values of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTCHECKISSTOPPED_001
 \DESCRIPTION    Os_SchTCheckIsStopped is called with the return values of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTSTARTSYNCHRONOUS_001
 \DESCRIPTION    Os_SchTStartSynchronous is called with the return values of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTCHECKISNOTSTOPPED_001
 \DESCRIPTION    Os_SchTCheckIsNotStopped is called with the return values of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTCHECKISNOTNEXTED_001
 \DESCRIPTION    Os_SchTCheckIsNotNexted is called with the return values of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTCHECKISNOTWAITING_001
 \DESCRIPTION    Os_SchTCheckIsNotWaiting is called with the return values of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_JOBADDREL_001
 \DESCRIPTION    Os_JobAddRel is called with a value derived from the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTSYNCUPDATEDEVIATION_001
 \DESCRIPTION    Os_SchTSyncUpdateDeviation is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTSYNCUPDATESYNCSTATUS_001
 \DESCRIPTION    Os_SchTSyncUpdateSyncStatus is called with the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTGETSCHEDULETABLESTATUS_001
 \DESCRIPTION    Os_SchTGetScheduleTableStatus is called with the return value of Os_SchTId2SchT and a value passed as
                 argument to the caller. The correctness of the caller argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_SCHTID2SCHT_M]

\ID SBSW_OS_SCHT_SCHTEXPOGETCURRENT_001
 \DESCRIPTION    Os_SchTExPoGetCurrent is called in a loop with an iterator. The iterator is initialized with the
                 return value of Os_SchTJob2SchT. The iterator is updated with every iteration.
 \COUNTERMEASURE \M [CM_OS_SCHTJOB2SCHT_M]
                 \R [CM_OS_SCHT_ITERATOR_R]

\ID SBSW_OS_SCHT_SCHTEXPOWORKACTION_001
 \DESCRIPTION    Os_SchTExPoWorkAction is called with the return value of Os_SchTExPoGetCurrent.
 \COUNTERMEASURE \N [CM_OS_SCHTEXPOGETCURRENT_N]

\ID SBSW_OS_SCHT_SCHTWORKEXPIRYPOINT_001
 \DESCRIPTION    A Os_SchTWorkExpiryPoint function is called with an iterator and a pointer to a local variable.
                 The iterator is initialized with the return value of Os_SchTJob2SchT. The iterator is updated
                 with every iteration.
 \COUNTERMEASURE \M [CM_OS_SCHTJOB2SCHT_M]
                 \R [CM_OS_SCHT_ITERATOR_R]

\ID SBSW_OS_SCHT_SCHTSYNCGET_003
 \DESCRIPTION    Os_SchTSyncGet is called with an iterator.
                 The iterator is initialized with the return value of Os_SchTJob2SchT. The iterator is updated
                 with every iteration.
 \COUNTERMEASURE \M [CM_OS_SCHTJOB2SCHT_M]
                 \R [CM_OS_SCHT_ITERATOR_R]

\ID SBSW_OS_SCHT_SCHTWORKEXPIRYPOINTWITHSYNC_001
 \DESCRIPTION    A Os_SchTWorkExpiryPointWithSync function is called with the return value of Os_SchTSyncGet and a
                 pointer to local variable.
 \COUNTERMEASURE \R [CM_OS_SCHTSYNCGET_R]

\ID SBSW_OS_SCHT_JOBRELOAD_001
 \DESCRIPTION    Os_JobReload function is called with an iterator.
 \COUNTERMEASURE \R [CM_OS_SCHT_NULLPTRCHECK_R]

\ID SBSW_OS_SCHT_APPISCORELOCAL_001
 \DESCRIPTION    Os_AppIsCoreLocal is called with the return value of Os_AppGetCore.
 \COUNTERMEASURE \M [CM_OS_APPGETCORE_M]

\ID SBSW_OS_SCHT_APPGETCORE_001
 \DESCRIPTION    Os_AppGetCore is called with a value, derived from the return value of Os_SchTId2SchT.
 \COUNTERMEASURE \M [CM_OS_SCHTGETAPPLICATION_M]
                 \M [CM_OS_SCHTID2SCHT_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_SCHTID2SCHT_M
      Verify that:
        1. each schedule table pointer in OsCfg_SchTRefs is no NULL_PTR,
        2. the size of OsCfg_SchTRefs is equal to OS_SCHTID_COUNT + 1 and
        3. each element in ScheduleTableType has a lower value than OS_SCHTID_COUNT.

\CM CM_OS_EXPO_TASKS_M
      Verify that:
        1. each the Tasks pointer of each configured expiry point is a non NULL_PTR, if the TaskCount is not '0',
        2. the size of the Tasks array is equal to TaskCount, if TaskCount is not '0' and
        3. each task reference is a non NULL_PTR.

\CM CM_OS_EXPO_EVENTS_M
      Verify that:
        1. each the Events pointer of each configured expiry point is a non NULL_PTR, if the EventCount is not '0',
        2. the size of the Events array is equal to EventCount, if EventCount is not '0' and
        3. the task reference in each element is a non NULL_PTR.

\CM CM_OS_SCHTGETCORE_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_SCHTGETAPPLICATION_M
      Verify that the OwnerApplication reference in each schedule table instance is a non NULL_PTR.

\CM CM_OS_SCHTJOB2SCHT_M
      Verify that the Callback of each schedule table job refers to Os_SchTWorkScheduleTable and that no other
      Object refers to Os_SchTWorkScheduleTable.

\CM CM_OS_SCHTGETDYN_M
      Verify that the schedule table Dyn pointer of each Os_SchTConfigType object is initialized with a valid
      dynamic schedule table.

\CM CM_OS_SCHTSYNCGET_R
      The caller ensures by an implementation check, that the pointer passed to Os_SchTSyncGet is derived from a
      Os_SchTSyncConfigType.

\CM CM_OS_SCHTSYNCGETDYN_M
      Verify that the schedule table Dyn pointer of each Os_SchTSyncConfigType object is initialized with a
      dynamic schedule table derived from an Os_SchTSyncType object.

\CM CM_OS_SCHTEXPOGETCURRENT_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_SCHTSWITCH_N
      Precondition ensures that the pointer is valid. The compliance of the precondition is check during review.

\CM CM_OS_SCHTGETNEXT_R
      Caller ensures by implementation that the next pointer is valid.

\CM CM_OS_SCHTGETNEXT_M
      Verify that the initial next pointer of each schedule table which has a cyclic expiry point is a non NULL_PTR.

\CM CM_OS_SCHTGETPREVIOUS_1_2_R
      Caller ensures by checking the schedule table state that the previous pointer is valid.

\CM CM_OS_SCHTGETPREVIOUS_2_2_T
      Consistency of the schedule table State and Previous pointer is ensured by TCASE-345831.

\CM CM_OS_SCHT_INDEX_R
      Caller ensures by implementation that the used index is valid.

\CM CM_OS_SCHT_ITERATOR_R
      Caller ensures by implementation that the used iterator is not used, in case the the iterator is a NULL_PTR.

\CM CM_OS_SCHT_NULLPTRCHECK_R
      Caller ensures by implementation that the passed value is a non NULL_PTR.

*/

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_ScheduleTable.c
 **********************************************************************************************************************/

