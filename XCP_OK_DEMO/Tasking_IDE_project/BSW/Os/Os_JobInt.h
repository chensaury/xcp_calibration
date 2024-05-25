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
 *  \ingroup     Os_Kernel
 *  \defgroup    Os_Job Job
 *  \brief       Job data type and compare function.
 *  \details
 *  \trace       SPEC-64001, SPEC-64004, SPEC-64033
 *
 *  \{
 *
 *  \file
 *  \brief       Job data type and compare function.
 *  \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_JOBINT_H
# define OS_JOBINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */

/* Os kernel module dependencies */
# include "Os_Counter_Types.h"
# include "Os_Counter_Lcfg.h"
# include "Os_CounterInt.h"
# include "Os_CommonInt.h"
# include "Os_Job_Types.h"
# include "Os_ErrorInt.h"

/* Os HAL dependencies */
# include "Os_Hal_CompilerInt.h"




/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/
/*! The lowest value of Os_TickType. E.g. for uint32 --> 1<<(4*8-1) = 0x80000000 */
# define OS_TIMER_TICKTYPE_MIN                  ((Os_TickType)(((Os_TickType)1) << ((sizeof(Os_TickType) * 8u)-1u)))

/*! The highest value of Os_TickType. E.g. for uint32 --> 0x7FFFFFFF */
# define OS_TIMER_TICKTYPE_MAX                  ((Os_TickType)(~OS_TIMER_TICKTYPE_MIN))

/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Dynamic information of a job. */
struct Os_JobType_Tag
{
  /*! Time stamp, which tells when the job expires. */
  Os_TickType ExpirationTimestamp;
};


/***********************************************************************************************************************
 *  Os_JobCallbackType()
 **********************************************************************************************************************/
/*! \brief        Function pointer type of a job handling callback function.
 *  \details      If a job is expired, the job's handling callback function is executed.
 *                The handling function shall have this kind of prototype.
 *
 *  \param[in]    Job   The job which has been expired.
 **********************************************************************************************************************/
typedef P2FUNC(void, OS_CODE, Os_JobCallbackType)(P2CONST(Os_JobConfigType, TYPEDEF, OS_CONST) Job);


/*! Configuration information of a job. */
struct Os_JobConfigType_Tag
{
  /*! Time stamp, which tells when the job expires. */
  P2VAR(Os_JobType, TYPEDEF, OS_VAR_NOINIT) Dyn;

  /*! Reference to the underlying counter. */
  P2CONST(Os_CounterConfigType, TYPEDEF, OS_CONST) Counter;

  /*! Callback function which is executed when the job expires. */
  Os_JobCallbackType Callback;
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
 *  Os_JobPriorityCompare()
 **********************************************************************************************************************/
/*! \brief          Compares the left job's priority to the right job's priority.
 *  \details        This function is used to sort jobs by their expiration time stamp.
 *                  It tells which of two jobs shall be executed first.
 *
 *  \param[in]      LeftJob     The left job. Parameter must not be NULL.
 *  \param[in]      RightJob    The right job. Parameter must not be NULL.
 *
 *  \see            \ref Job_Scheduling
 *
 *  \return         Whether the left job has a higher priority than the right one.
 *  \retval         0    The priority of the left job is lower or equal to the right job's priority.
 *  \retval         !0   The priority of the left job is higher than the right job's priority.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE, Os_JobPriorityCompare,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) LeftJob,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) RightJob
));


/***********************************************************************************************************************
 *  Os_JobGetExpirationTimestamp()
 **********************************************************************************************************************/
/*! \brief          Returns the expiration time stamp of the given job.
 *  \details        --no details--
 *
 *  \param[in]      Job     The job to query. Parameter must not be NULL.
 *
 *  \return         Job's expiration time stamp.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_JobGetExpirationTimestamp,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_JobCopyExpirationTimestamp()
 **********************************************************************************************************************/
/*! \brief          Copies the expiration time stamp from the source job to the target job.
 *  \details        --no details--
 *
 *  \param[in,out]  TargetJob     The job who's expiry time shall be set. Parameter must not be NULL.
 *  \param[in]      SourceJob     The job who's expiry time shall be read. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 *  \pre            TargetJob is not scheduled within a job queue.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobCopyExpirationTimestamp,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) TargetJob,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) SourceJob
));


/***********************************************************************************************************************
 *  Os_JobGetDyn()
 **********************************************************************************************************************/
/*! \brief          Returns the dynamic data of a job.
 *  \details        --no details--
 *
 *  \param[in]      Job     The job to query. Parameter must not be NULL.
 *
 *  \return         The Job's dynamic data.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2VAR(Os_JobType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_JobGetDyn,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));

/***********************************************************************************************************************
 *  Os_JobSetExpirationTimestamp()
 **********************************************************************************************************************/
/*! \brief          Sets the expiration time stamp of the given job.
 *  \details        --no details--
 *
 *  \param[in]      Job       The job to modify. Parameter must not be NULL.
 *  \param[in]      TimeStamp The new expiration time stamp of the job. The value must be in
 *                            range 0 <= ExpirationTime <= MaxCountingValue and ExpirationTime-Now must be in
 *                            range -MaxAllowedValue to +MaxAllowedValue.
 *
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobSetExpirationTimestamp,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType TimeStamp
));


/***********************************************************************************************************************
 *  Os_JobAddRel()
 **********************************************************************************************************************/
/*! \brief          Schedule the given absolute expiration time.
 *  \details        --no details--
 *
 *  \param[in,out]  Job        Job to enqueue. Parameter must not be NULL.
 *  \param[in]      Offset     Relative value (to the job's current expiration time) in ticks to its next
 *                             expiration time. The value of Offset must be in range 1..MaxAllowedValue
 *                             of the respective counter configuration.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobAddRel,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
));


/***********************************************************************************************************************
 *  Os_JobAddAbs()
 **********************************************************************************************************************/
/*! \brief          Schedule the given absolute expiration time.
 *  \details        --no details--
 *
 *  \param[in,out]  Job        Job to enqueue. Parameter must not be NULL.
 *  \param[in]      Start      Absolute value in ticks. The value of Start must be in range 1..MaxAllowedValue
 *                             of the respective counter configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different underlying counters.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobAddAbs,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Start
));


/***********************************************************************************************************************
 *  Os_JobReload()
 **********************************************************************************************************************/
/*! \brief          Schedule the given job relative to its current expiration time with given offset.
 *  \details        --no details--
 *
 *  \param[in,out]  Job        Job to enqueue. Parameter must not be NULL.
 *  \param[in]      Offset     Relative value (to the job's current expiration time) in ticks to its next
 *                             expiration time. The value of Offset must be in range 1..MaxAllowedValue
 *                             of the respective counter configuration.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE for different underlying counters.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 *  \pre            Counter belongs to the local core.
 *  \pre            Given job is not scheduled.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobReload,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
));


/***********************************************************************************************************************
 *  Os_JobDelete()
 **********************************************************************************************************************/
/*! \brief          Delete a given job from job queue.
 *  \details        --no details--
 *
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobDelete,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_JobGetCharacteristics()
 **********************************************************************************************************************/
/*! \brief          Returns the characteristics of the underlying counter.
 *  \details        --no details--
 *
 *  \param[in]      Job      Job to query. Parameter must not be NULL.
 *
 *  \return         The characteristic counter data.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CounterCharacteristicsConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_JobGetCharacteristics,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_JobGetExpiryTime()
 **********************************************************************************************************************/
/*! \brief          Returns the number of ticks until the given time stamp is reached.
 *  \details        --no details--
 *
 *  \param[in]      Job       The job to query. Parameter must not be NULL.
 *  \param[in]      TimeStamp The time stamp the distance shall be calculated for.
 *                            TimeStamp must be in range 0 <= TimeStamp <= MaxCountingValue.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_JobGetExpiryTime,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType TimeStamp
));


/***********************************************************************************************************************
 *  Os_JobCheckValueLeMaxAllowed()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given Value respects the job's max allowed value.
 *  \details        This function is used to validate user given counter values.
 *
 *  \param[in]      Job       The job. Parameter must not be NULL.
 *  \param[in]      Value     The value to check.
 *
 *  \return         Whether the check succeeded or not.
 *  \retval         Not OS_CHECK_FAILED   If Value exceeds the limit.
 *  \retval         OS_CHECK_FAILED       If Value respects the upper limit.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_JobCheckValueLeMaxAllowed,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  TickType Value
));


/***********************************************************************************************************************
 *  Os_JobCheckValueLeReducedMaxAllowed()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given Value respects the job's reduced max allowed value.
 *  \details        This function is used to validate user given counter values.
 *
 *  \param[in]      Job       The job. Parameter must not be NULL.
 *  \param[in]      Reduce    The value to subtract from the MaxAllowedValue. Parameter Reduce must be
 *                            <= MAXALLOWEDVALUE of the underlying counter
 *  \param[in]      Value     The value to check.
 *
 *  \return         Whether the check succeeded or not.
 *  \retval         Not OS_CHECK_FAILED   If Value exceeds the limit.
 *  \retval         OS_CHECK_FAILED       If Value respects the upper limit.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_JobCheckValueLeReducedMaxAllowed,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  TickType Reduce,
  TickType Value
));


/***********************************************************************************************************************
 *  Os_JobCheckValueGeMinCycleOrZero()
 **********************************************************************************************************************/
/*! \brief          Checks whether the given cycle is greater or equal to counter's MinCycle or zero.
 *  \details        This function is used to validate user given cycle values.
 *
 *  \param[in]      Job       The job. Parameter must not be NULL.
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
Os_JobCheckValueGeMinCycleOrZero,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  TickType Cycle
));


/***********************************************************************************************************************
 *  Os_JobCheckAssignedToSameCounter()
 **********************************************************************************************************************/
/*! \brief          Verifies that the given jobs are assigned to the same counter.
 *  \details        --no details--
 *
 *  \param[in]      Job_1  The first job to check. Parameter must not be NULL.
 *  \param[in]      Job_2  The second job to check. Parameter must not be NULL.
 *
 *  \retval         Not OS_CHECK_FAILED   Both job are assigned to the same counter.
 *  \retval         OS_CHECK_FAILED       The jobs are assigned to different counters.
 *
 *  \context        OS_INTERNAL
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_JobCheckAssignedToSameCounter,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job_1,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job_2
));


/***********************************************************************************************************************
 *  Os_JobGetCore()
 **********************************************************************************************************************/
/*! \brief          Returns the counter's core assignment.
 *  \details        --no details--
 *
 *  \param[in]      Job   The job to query. Parameter must not be NULL.
 *
  * \return         The core of the counter.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_JobGetCore,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_JobGetValue()
 **********************************************************************************************************************/
/*! \brief          Returns the current counter value in range 0..MaxAllowedValue[Counter].
 *  \details        --no details--
 *
 *  \param[in]      Job   The job to query. Parameter must not be NULL.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_JobGetValue,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  Os_JobSub()
 **********************************************************************************************************************/
/*! \brief          Returns difference between Value and Sub mod MaxAllowedValue.
 *  \details        --no details--
 *
 *  \param[in]      Job       The job to query. Parameter must not be NULL.
 *  \param[in]      Value     The value.
 *  \param[in]      Sub       The value to be subtracted.
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
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE, Os_JobSub,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Value,
  Os_TickType Sub
));


/***********************************************************************************************************************
 *  Os_JobDo()
 **********************************************************************************************************************/
/*! \brief          Performs the action of a job.
 *  \details        --no details--
 *
 *  \param[in]      Job       The job to query. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_JobDo,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
));


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */





#endif /* OS_JOBINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_JobInt.h
 **********************************************************************************************************************/
