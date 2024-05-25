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
 * \addtogroup Os_Barrier
 * \{
 *
 * \file
 * \brief       Contains the implementation of the barrier management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_BARRIER_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Barrier_Types.h"
#include "Os_Barrier.h"
#include "Os_Core.h"
#include "Os_Task.h"
#include "Os_Thread.h"

/* Os kernel module dependencies */
#include "Os_Cfg.h"

/* Os hal dependencies */


#define OS_BARRIER_COUNTERTHRESHOLD     ((Os_BarrierCounterType)1u << ((sizeof(Os_BarrierCounterType) * 8u) - 1u))

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
 *  Os_BarrierIsCounterLo()
 **********************************************************************************************************************/
/*! \brief          Returns whether Value is lower than Compare (!0), or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Value   The value to check.
 *  \param[in]      Compare The compare value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierIsCounterLo,
(
  Os_BarrierCounterType Value,
  Os_BarrierCounterType Compare
));


/***********************************************************************************************************************
 *  Os_BarrierIsCounterGe()
 **********************************************************************************************************************/
/*! \brief          Returns whether Value is equal to or greater than Compare (!0), or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Value   The value to check.
 *  \param[in]      Compare The compare value.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierIsCounterGe,
(
  Os_BarrierCounterType Value,
  Os_BarrierCounterType Compare
));


/***********************************************************************************************************************
 *  Os_BarrierGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the Dyn member of the given barrier.
 *  \details        --no details--
 *
 *  \param[in]      Barrier   The barrier query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT),  OS_CODE,
OS_ALWAYS_INLINE,
Os_BarrierGetDyn,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
));


/***********************************************************************************************************************
 *  Os_BarrierGetAttendeeDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the Dyn object of the given barrier attendee.
 *  \details        --no details--
 *
 *  \param[in]      Barrier     The barrier query. Parameter must not be NULL.
 *  \param[in]      AttendeeIdx The attendee of interest. The value must be smaller than Barrier->AttendeeCount.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_BarrierGetAttendeeDyn,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier,
  Os_BarrierAttendeeIdxType AttendeeIdx
));


/***********************************************************************************************************************
 *  Os_BarrierGetLowestCounter()
 **********************************************************************************************************************/
/*! \brief          Returns the lowest counter value of all attached barriers.
 *  \details        --no details--
 *
 *  \param[in]      Barrier   The barrier query. Parameter must not be NULL.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different objects.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BarrierCounterType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierGetLowestCounter,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
));


/***********************************************************************************************************************
 *  Os_BarrierIsSynchronized()
 **********************************************************************************************************************/
/*! \brief          Returns the whether the given attendee is synchronized or detached (!0), or not (0).
 *  \details        --no details--
 *
 *  \param[in]      Barrier     The barrier to query. Parameter must not be NULL.
 *  \param[in]      AttendeeIdx The attendee of interest. The value must be smaller than Barrier->AttendeeCount.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierIsSynchronized,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier,
  Os_BarrierAttendeeIdxType AttendeeIdx
));


/***********************************************************************************************************************
 *  Os_BarrierCheckId()
 **********************************************************************************************************************/
/*! \brief          Returns whether the given ID is valid (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      BarrierId   The barrier ID to check.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierCheckId,
(
  Os_BarrierIdType BarrierId
));


/***********************************************************************************************************************
 *  Os_BarrierCheckTaskPointer()
 **********************************************************************************************************************/
/*! \brief          Checks if the given task pointer is the current Task (Not OS_CHECK_FAILED) or not (OS_CHECK_FAILED).
 *  \details        In case that extended checks are disabled, the default result of \ref Os_ErrExtendedCheck() is
 *                  returned.
 *
 *  \param[in]      TaskPtr       The task pointer to check.
 *  \param[in]      CurrentTask   The current task from where this function was called.
 *
 *  \retval         Not OS_CHECK_FAILED   If the given task pointer is valid and points to the current task.
 *  \retval         OS_CHECK_FAILED       If the given task pointer is invalid or points to another task.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierCheckTaskPointer,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_VAR_NOINIT) TaskPtr,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_VAR_NOINIT) CurrentTask
));


/***********************************************************************************************************************
 *  Os_BarrierId2Barrier()
 **********************************************************************************************************************/
/*! \brief          Returns the barrier belonging to the given id.
 *  \details        --no details--
 *
 *  \param[in]      BarrierId        The id of the searched barrier. Parameter must be < OS_BARRIERID_COUNT.
 *
 *  \return         The barrier belonging to the given id.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BarrierBaseConfigRefType, OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierId2Barrier,
(
  Os_BarrierIdType BarrierId
));


/***********************************************************************************************************************
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  Os_BarrierIsCounterLo()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierIsCounterLo,
(
  Os_BarrierCounterType Value,
  Os_BarrierCounterType Compare
))
{
  /* #10 Calculate difference between Compare and Value. If difference lies within the positive half of the possible
   *     value range, return a non-zero value. Otherwise the value is negative -> return zero. */
  /* Ensure that comparison is based on unsigned type by casting into Os_BarrierCounterType before compare. */
  return (Os_StdReturnType)((Os_BarrierCounterType)(Value - Compare) >= OS_BARRIER_COUNTERTHRESHOLD);                   /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_BarrierIsCounterGe()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierIsCounterGe,
(
  Os_BarrierCounterType Value,
  Os_BarrierCounterType Compare
))
{
  /* #10 Return whether Value is greater than or equal to Compare. */
  return (Os_StdReturnType)(Os_BarrierIsCounterLo(Value, Compare) == 0u);                                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_BarrierGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT),  OS_CODE,
OS_ALWAYS_INLINE,
Os_BarrierGetDyn,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
))
{
  return Barrier->Dyn;
}


/***********************************************************************************************************************
 *  Os_BarrierGetAttendeeDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT),
OS_CODE, OS_ALWAYS_INLINE, Os_BarrierGetAttendeeDyn,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier,
  Os_BarrierAttendeeIdxType AttendeeIdx
))
{
  return Barrier->AttendeeRefs[AttendeeIdx]->Dyn;
}


/***********************************************************************************************************************
 *  Os_BarrierGetLowestCounter()
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
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_BarrierCounterType,  OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierGetLowestCounter,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
))
{
  Os_BarrierCounterType result;
  Os_BarrierAttendeeIdxType attendeeIdx;
  Os_BarrierCounterType attendeeCounter;
  P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT) attendee;

  /* #10 Initial result is 0. */
  result = 0;

  /* #20 Iterate over all attendees. */
  for(attendeeIdx = 0; attendeeIdx < Barrier->AttendeeCount; ++attendeeIdx)
  {
    attendee = Os_BarrierGetAttendeeDyn(Barrier, attendeeIdx);                                                          /* SBSW_OS_FC_PRECONDITION */

    /* #30 If the attendee is attached and is not me, take its counter value as intermediate result. */
    if((attendee->AttendeeState == OS_BARRIERATTENDEESTATE_ATTACHED) && (attendee != Barrier->Dyn))                     /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    {
      /* #40 Abort iteration. */
      result = attendee->Counter;
      attendeeIdx++;                                                                                                    /* PRQA S 2469 */ /* MD_Os_Rule14.2_2469 */
      break;
    }
  }


  /* #50 Continue iteration over all attendees. */
  for(; attendeeIdx < Barrier->AttendeeCount; ++attendeeIdx)                                                            /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  {
    attendee = Os_BarrierGetAttendeeDyn(Barrier, attendeeIdx);                                                          /* SBSW_OS_FC_PRECONDITION */
    attendeeCounter = attendee->Counter;

    /* #60 If the attendee is attached, is not me and has a different counter value: */
    if(     (attendee->AttendeeState == OS_BARRIERATTENDEESTATE_ATTACHED)
        &&  (attendee != Barrier->Dyn)
        &&  (result != attendeeCounter))                                                                                /* COV_OS_HALPLATFORMNEEDMORETHAN2CORES */
    {
      /* #70 Select the lower counter value and abort. */
      if(Os_BarrierIsCounterLo(attendeeCounter, result) != 0u)
      {
        result = attendeeCounter;
      }

      break;
    }
  }

  return (Os_BarrierCounterType)result;
}


/***********************************************************************************************************************
 *  Os_BarrierIsSynchronized()
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
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_BarrierIsSynchronized,
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier,
  Os_BarrierAttendeeIdxType AttendeeIdx
))
{
  P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT) attendee;
  Os_BarrierCounterType attendeeCounter;
  Os_BarrierCounterType ownCounter;
  Os_StdReturnType synchronized;

  attendee = Os_BarrierGetAttendeeDyn(Barrier, AttendeeIdx);                                                            /* SBSW_OS_FC_PRECONDITION */

  /* Take a snapshot of values to avoid compiler warning about undefined order of volatile accesses */
  attendeeCounter = attendee->Counter;
  ownCounter = Barrier->Dyn->Counter;

  /* #10 If the startup state of the core has to be checked */
  if( Barrier->CheckOsStart == TRUE )                                                                                   /* COV_OS_UNSUPPORTED93797 */
  {
    /* #20 if the participating core is started */
    if(Os_CoreOsIsStarted(Os_TaskGetCore(Barrier->TaskPtr)) != 0u)                                                      /* SBSW_OS_BR_COREOSISSTARTED_001 */ /* SBSW_OS_BR_TASKGETCORE_001 */
    {
      /* #30 If the addressed attendee is detached or has already reached the counter value, the result
       * is !0, otherwise 0. */
      synchronized = (Os_BarrierIsCounterGe(attendeeCounter, ownCounter) != 0u)                                         /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
          || (attendee->AttendeeState == OS_BARRIERATTENDEESTATE_DETACHED );
    }
    /* #40 otherwise skip this core */
    else
    {
      synchronized = !0u;                                                                                               /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */
    }
  }
  /* #50 otherwise do not check the cores startup state */
  else
  {
    /* #60 If the addressed attendee is detached or has already reached the counter value, the result
     * is !0, otherwise 0. */
    synchronized = (Os_BarrierIsCounterGe(attendeeCounter, ownCounter) != 0u)                                           /* PRQA S 4404 */ /* MD_Os_C90BooleanCompatibility */
        || (attendee->AttendeeState == OS_BARRIERATTENDEESTATE_DETACHED );                                              /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
  }

  return synchronized;
}


/***********************************************************************************************************************
 *  Os_BarrierCheckId()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_UNSUPPORTED93797 */
Os_BarrierCheckId,
(
  Os_BarrierIdType BarrierId
))                                                                                                                      /* COV_OS_UNSUPPORTED93797 */
{
  return Os_ErrExtendedCheck(Os_ErrIsValueLo((uint32)BarrierId, (uint32)OS_BARRIERID_COUNT));
}


/***********************************************************************************************************************
 *  Os_BarrierCheckTaskPointer()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,                               /* COV_OS_UNSUPPORTED93797 */
Os_BarrierCheckTaskPointer,
(
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_VAR_NOINIT) TaskPtr,
  P2CONST(Os_TaskConfigType, AUTOMATIC, OS_VAR_NOINIT) CurrentTask
))                                                                                                                      /* COV_OS_UNSUPPORTED93797 */
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(TaskPtr == CurrentTask));                                               /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_BarrierId2Barrier()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */ /* COV_OS_UNSUPPORTED93797 */
Os_BarrierBaseConfigRefType, OS_CODE, OS_ALWAYS_INLINE, Os_BarrierId2Barrier,
(
  Os_BarrierIdType BarrierId
))                                                                                                                      /* COV_OS_UNSUPPORTED93797 */
{
  P2CONST(Os_BarrierBaseConfigRefType, AUTOMATIC, OS_VAR_NOINIT) barrierRefs;

  Os_Assert(Os_ErrIsValueLo((uint32)BarrierId, (uint32)OS_BARRIERID_COUNT));

  /* #10 Get the current cores barrier reference and return it */
  barrierRefs = Os_CoreAsrGetBarriers(Os_Core2AsrCore(Os_CoreGetCurrentCore()));                                        /* SBSW_OS_BR_CORE2ASRCORE_001 */ /* SBSW_OS_BR_COREASRGERTBARRIERS_001 */

  return barrierRefs[BarrierId];                                                                                        /* PRQA S 2842 */ /* MD_Os_Rule18.1_2842 */
}


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/
/********************************************************************************************F**************************
 *  Os_BarrierInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_BarrierInit
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier,
  Os_BarrierAttendeeStateType InitialState
)
{
  P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT) dyn;

  dyn = Os_BarrierGetDyn(Barrier);                                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 Set attendee state to initial state and clear counter. */
  dyn->AttendeeState = InitialState;                                                                                    /* SBSW_OS_BR_BARRIERGETDYN_001 */
  dyn->Counter = 0;                                                                                                     /* SBSW_OS_BR_BARRIERGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_BarrierAttach()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_BarrierAttach
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
)
{
  Os_BarrierCounterType counterSnapshot;
  P2VAR(Os_BarrierBaseType volatile, AUTOMATIC, OS_VAR_NOINIT) dyn;

  dyn = Os_BarrierGetDyn(Barrier);                                                                                      /* SBSW_OS_FC_PRECONDITION */

  /* #10 Get the lowest counter value of all attendees which are attached to this barrier. */
  counterSnapshot = Os_BarrierGetLowestCounter(Barrier);                                                                /* SBSW_OS_FC_PRECONDITION */

  do
  {
    /* #20 Attach to the barrier. */
    dyn->Counter = counterSnapshot;                                                                                     /* SBSW_OS_BR_BARRIERGETDYN_001 */
    dyn->AttendeeState = OS_BARRIERATTENDEESTATE_ATTACHED;                                                              /* SBSW_OS_BR_BARRIERGETDYN_001 */

    /* #30 Get an overall counter snapshot. */
    counterSnapshot = Os_BarrierGetLowestCounter(Barrier);                                                              /* SBSW_OS_FC_PRECONDITION */

    /* #40 Loop while lowest counter value changed during attach step. */
  }while(dyn->Counter != counterSnapshot);                                                                              /* COV_OS_BRRACECONDITION */
}


/***********************************************************************************************************************
 *  Os_BarrierDetach()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
FUNC(void, OS_CODE) Os_BarrierDetach
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
)
{
  Os_BarrierGetDyn(Barrier)->AttendeeState = OS_BARRIERATTENDEESTATE_DETACHED;                                          /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_BR_BARRIERGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_BarrierSynchronizeInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
FUNC(void, OS_CODE) Os_BarrierSynchronizeInternal
(
  P2CONST(Os_BarrierBaseConfigType, AUTOMATIC, OS_VAR_NOINIT) Barrier
)
{
  Os_StdReturnType synchronized;
  Os_BarrierAttendeeIdxType attendeeIdx;

  /* #10 Increment the barrier counter. */
  Os_BarrierGetDyn(Barrier)->Counter++;                                                                                 /* SBSW_OS_FC_PRECONDITION */ /* SBSW_OS_BR_BARRIERGETDYN_001 */

  /* #20 Spin until all attendees are synchronized. */
  do
  {
    synchronized = TRUE;

    for(attendeeIdx = 0; attendeeIdx < Barrier->AttendeeCount; ++attendeeIdx)
    {
      synchronized = (Os_BarrierIsSynchronized(Barrier, attendeeIdx)) && synchronized;                                  /* PRQA S 4404, 4558 */  /* MD_Os_C90BooleanCompatibility, MD_Os_Rule10.1_4558 */ /* SBSW_OS_FC_PRECONDITION */ /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
    }

    /* #30 Perform NOP. */
    Os_Hal_CoreNop();

  }while(synchronized == FALSE);                                                                                        /* COV_OS_HALPLATFORMMULTICOREUNSUPPORTED */
}


/***********************************************************************************************************************
 *  Os_Api_BarrierSynchronize()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
FUNC(Os_StatusType, OS_CODE) Os_Api_BarrierSynchronize                                                                  /* COV_OS_UNSUPPORTED93797 */
(
  Os_BarrierIdType BarrierID
)                                                                                                                       /* COV_OS_UNSUPPORTED93797 */
{
  Os_StatusType status;
  P2CONST(Os_ThreadConfigType, AUTOMATIC, OS_CONST) currentThread;

  currentThread = Os_CoreGetThread();

  /* #10 Perform error checks. */
  if(OS_UNLIKELY(Os_ThreadCheckCallContext(currentThread, OS_APICONTEXT_BARRIERSYNCHRONIZE) == OS_CHECK_FAILED))        /* SBSW_OS_BR_THREADCHECKCALLCONTEXT_001 */
  {
    status = OS_STATUS_CALLEVEL;
  }
  else if(OS_UNLIKELY(Os_BarrierCheckId(BarrierID) == OS_CHECK_FAILED))
  {
    status = OS_STATUS_ID_1;
  }
  else
  {
    P2CONST(Os_BarrierBaseConfigType, TYPEDEF, OS_CONST) barrier;
    P2CONST(Os_TaskConfigType, AUTOMATIC, OS_VAR_NOINIT) currentTask;

    barrier = Os_BarrierId2Barrier(BarrierID);
    currentTask = Os_TaskThread2Task(currentThread);                                                                    /* SBSW_OS_BR_TASKTHREAD2TASK_001 */

    if(OS_UNLIKELY(Os_ErrCheckPointerIsNotNull(barrier) == OS_CHECK_FAILED))                                            /* PRQA S 0315 */ /* MD_Os_Dir1.1_0315 */ /* SBSW_OS_BR_ERRCHECKPOINTERISNOTNULL_001 */
    {
      status = OS_STATUS_NO_BARRIER_PARTICIPANT;
    }
    else if(OS_UNLIKELY(Os_BarrierCheckTaskPointer(barrier->TaskPtr, currentTask) == OS_CHECK_FAILED))                  /* SBSW_OS_BR_CHECKTASKPOINTER_001 */
    {
      status = OS_STATUS_NO_BARRIER_PARTICIPANT;
    }
    else
    {
      /* #20 Synchronize at the given barrier */
      Os_BarrierSynchronizeInternal(barrier);                                                                           /* SBSW_OS_BR_BARRIERSYNCHRONIZE */
      status = OS_STATUS_OK;
    }
  }

  return status;
}                                                                                                                       /* PRQA S 6050 */ /* MD_Os_STCAL */


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN

\ID SBSW_OS_BR_BARRIERGETDYN_001
 \DESCRIPTION    Write access to the dynamic data of a barrier.
 \COUNTERMEASURE \M [CM_OS_BARRIER_DYN_M]

 \ID SBSW_OS_BR_CORE2ASRCORE_001
 \DESCRIPTION    Os_Core2AsrCore is called with the return value of Os_CoreGetCurrentCore.
 \COUNTERMEASURE \S [CM_OS_COREGETCURRENTCORE_S]

\ID SBSW_OS_BR_COREASRGERTBARRIERS_001
 \DESCRIPTION    Os_CoreAsrGetBarriers is called with the return values of Os_Core2AsrCore and Os_CoreGetCurrentCore.
 \COUNTERMEASURE \R [CM_OS_CORE2ASRCORE_R]
                 \S [CM_OS_COREGETCURRENTCORE_S]

\ID SBSW_OS_BR_THREADCHECKCALLCONTEXT_001
 \DESCRIPTION    Os_ThreadCheckCallContext is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_BR_BARRIERSYNCHRONIZE
 \DESCRIPTION    Os_BarrierSynchronizeInternal is called with the return value of Os_BarrierId2Barrier().
                 That function always returns a valid pointer or NULL_PTR. Check against NULL_PTR exists.
 \COUNTERMEASURE \R [CM_OS_BARRIERID2BARRIER_R]
                 \M [CM_OS_COREASR_BARRIERREFS_M]

\ID SBSW_OS_BR_COREOSISSTARTED_001
 \DESCRIPTION    Os_CoreOsIsStarted is called with the return value of Os_TaskGetCore.
 \COUNTERMEASURE \M [CM_OS_TASKGETCORE_M]

\ID SBSW_OS_BR_TASKTHREAD2TASK_001
 \DESCRIPTION    Os_TaskThread2Task is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_BR_TASKGETCORE_001
 \DESCRIPTION    Os_TaskGetCore is called with a pointer derived from a given argument.
                 For OS internal calls it is ensured that this code is never called.
                 For calls via external user API the validity is ensured by runtime check.
 \COUNTERMEASURE \M [CM_OS_BARRIER_CHECKOSSTART_M]
                 \R [CM_OS_BARRIER_TASKPTR_R]

\ID SBSW_OS_BR_ERRCHECKPOINTERISNOTNULL_001
 \DESCRIPTION    Os_ErrCheckPointerIsNotNull is called with the return value of Os_BarrierId2Barrier().
                 That function always returns a valid pointer or NULL_PTR.
 \COUNTERMEASURE \M [CM_OS_COREASR_BARRIERREFS_M]

\ID SBSW_OS_BR_CHECKTASKPOINTER_001
 \DESCRIPTION    Os_BarrierCheckTaskPointer is called with the return value of Os_BarrierId2Barrier()
                 and Os_TaskThread2Task(). These functions always returns a valid pointer or NULL_PTR.
 \COUNTERMEASURE \M [CM_OS_COREASR_BARRIERREFS_M]
                 \R [CM_OS_TASKTHREAD2TASK_R]

SBSW_JUSTIFICATION_END */

/*

\CM CM_OS_BARRIER_DYN_M
      Verify that the Barrier Dyn pointer of each Barrier object is a non NULL_PTR.

\CM CM_OS_BARRIERID2BARRIER_R
      The caller ensures, that the returned pointer is not used for write accesses or as input for further
      functions, if the returned pointer is NULL_PTR.

\CM CM_OS_BARRIER_CHECKOSSTART_M
      Assert that CheckOsStart is FALSE.

\CM CM_OS_BARRIER_TASKPTR_R
      The pointer passed to the called function is derived from an argument passed by the caller function.
      The caller function ensures that the given pointer is a non NULL_PTR.

 */

/* START_COVERAGE_JUSTIFICATION
 *

\ID COV_OS_BRRACECONDITION
   \ACCEPT XF
   \REASON True condition may not be stimulated by tests due to race condition: Two cores have to perform
           synchronization while a third core is attached to the barrier.


END_COVERAGE_JUSTIFICATION */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Barrier.c
 **********************************************************************************************************************/
