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
 * \addtogroup Os_Job
 *
 * \{
 *
 * \file
 * \brief       Job implementation header.
 * \details     --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_JOB_H
# define OS_JOB_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_Job_Types.h"
# include "Os_JobInt.h"

/* Os kernel module dependencies */
# include "Os_Counter.h"
# include "Os_Common.h"
# include "Os_Error.h"

/* Os HAL dependencies */
# include "Os_Hal_Compiler.h"




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
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/

/***********************************************************************************************************************
 *  Os_JobPriorityCompare()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_JobPriorityCompare,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) LeftJob,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) RightJob
))
{
  Os_Assert((Os_StdReturnType)(LeftJob->Counter == RightJob->Counter));                                                 /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* If the right job is in the future of the left job, the left job has a higher priority. */
  return  Os_CounterIsFutureValue(                                                                                      /* SBSW_OS_JOB_COUNTERISFUTUREVALUE_001 */
            LeftJob->Counter,
            RightJob->Dyn->ExpirationTimestamp,
            LeftJob->Dyn->ExpirationTimestamp);
}


/***********************************************************************************************************************
 *  Os_JobGetExpirationTimestamp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobGetExpirationTimestamp,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return Job->Dyn->ExpirationTimestamp;
}


/***********************************************************************************************************************
 *  Os_JobCopyExpirationTimestamp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobCopyExpirationTimestamp,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) TargetJob,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) SourceJob
))
{
  TargetJob->Dyn->ExpirationTimestamp = SourceJob->Dyn->ExpirationTimestamp;                                            /* SBSW_OS_JOB_JOBGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_JobGetDyn()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2VAR(Os_JobType, AUTOMATIC, OS_VAR_NOINIT), OS_CODE, OS_ALWAYS_INLINE,
Os_JobGetDyn,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return Job->Dyn;
}


/***********************************************************************************************************************
 *  Os_JobSetExpirationTimestamp()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobSetExpirationTimestamp,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType TimeStamp
))
{
  Job->Dyn->ExpirationTimestamp = TimeStamp;                                                                            /* SBSW_OS_JOB_JOBGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_JobAddRel()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobAddRel,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
))
{
  Os_CounterAddRelJob(Job->Counter, Job, Offset);                                                                       /* SBSW_OS_JOB_COUNTERADDRELJOB_001 */
}


/***********************************************************************************************************************
 *  Os_JobAddAbs()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobAddAbs,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Start
))
{
  Os_CounterAddAbsJob(Job->Counter, Job, Start);                                                                        /* SBSW_OS_JOB_COUNTERADDABSJOB_001 */
}


/***********************************************************************************************************************
 *  Os_JobReload()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobReload,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Offset
))
{
  Os_CounterReloadJob(Job->Counter, Job, Offset);                                                                       /* SBSW_OS_JOB_COUNTERRELOADJOB_001 */
}


/***********************************************************************************************************************
 *  Os_JobDelete()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobDelete,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  Os_CounterDeleteJob(Job->Counter, Job);                                                                               /* SBSW_OS_JOB_COUNTERDELETEJOB_001 */
}


/***********************************************************************************************************************
 *  Os_JobGetCharacteristics()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_CounterCharacteristicsConfigType, AUTOMATIC, OS_CONST),
OS_CODE, OS_ALWAYS_INLINE, Os_JobGetCharacteristics,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return Os_CounterGetCharacteristics(Job->Counter);                                                                    /* SBSW_OS_JOB_COUNTERGETCHARACTERISTICS_001 */
}


/***********************************************************************************************************************
 *  Os_JobGetExpiryTime()
 **********************************************************************************************************************/
/*!
 *  Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE, OS_ALWAYS_INLINE,                                    /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobGetExpiryTime,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType TimeStamp
))
{
  Os_TickType now;
  Os_TickType timeStampMod;

  /* #10 Get current time from counter. */
  now = Os_CounterGetValue(Job->Counter);                                                                               /* SBSW_OS_JOB_COUNTERGETVALUE_001 */
  /* #20 Perform TimeStamp % MaxAllowedValue. */
  timeStampMod = Os_CounterGetModulo(Job->Counter, TimeStamp);                                                          /* SBSW_OS_JOB_COUNTERGETMODULO_001 */
  /* #30 Subtract current time from TimeStamp % MaxAllowedValue. */
  return Os_CounterSub(Job->Counter, timeStampMod, now);                                                                /* SBSW_OS_JOB_COUNTERSUB_001 */
}



/***********************************************************************************************************************
 *  Os_JobCheckValueLeMaxAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_JobCheckValueLeMaxAllowed,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  TickType Value
))
{
  return Os_CounterCheckValueLeMaxAllowed(Job->Counter, Value);                                                         /* SBSW_OS_JOB_COUNTERCHECKVALUELEMAXALLOWED_001 */
}


/***********************************************************************************************************************
 *  Os_JobCheckValueLeReducedMaxAllowed()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CODE,                                                 /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE,  Os_JobCheckValueLeReducedMaxAllowed,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  TickType Reduce,
  TickType Value
))
{
  return Os_CounterCheckValueLeReducedMaxAllowed(Job->Counter, Reduce, Value);                                          /* SBSW_OS_JOB_COUNTERCHECKVALUELEREDUCEDMAXALLOWED_001 */
}


/***********************************************************************************************************************
 *  Os_JobCheckValueGeMinCycleOrZero()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_JobCheckValueGeMinCycleOrZero,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  TickType Cycle
))
{
  return Os_CounterCheckValueGeMinCycleOrZero(Job->Counter, Cycle);                                                     /* SBSW_OS_JOB_COUNTERCHECKVALUEGEMINCYCLEORZERO_001 */
}


/***********************************************************************************************************************
 *  Os_JobCheckAssignedToSameCounter()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE Os_StdReturnType, OS_CODE, OS_ALWAYS_INLINE,
Os_JobCheckAssignedToSameCounter,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job_1,
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job_2
))
{
  return Os_ErrExtendedCheck((Os_StdReturnType)(Job_1->Counter == Job_2->Counter));                                     /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_JobGetCore()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE                                                                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
P2CONST(Os_CoreAsrConfigType, AUTOMATIC, OS_CONST), OS_CODE, OS_ALWAYS_INLINE, Os_JobGetCore,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return Os_CounterGetCore(Job->Counter);                                                                               /* SBSW_OS_JOB_COUNTERGETCORE_001 */
}


/***********************************************************************************************************************
 *  Os_JobGetValue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE,                                                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_JobGetValue,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  return Os_CounterGetValue(Job->Counter);                                                                              /* SBSW_OS_JOB_COUNTERGETVALUE_001 */
}


/***********************************************************************************************************************
 *  Os_JobSub()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_TickType, OS_CODE,                                                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_JobSub,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job,
  Os_TickType Value,
  Os_TickType Sub
))
{
  return Os_CounterSub(Job->Counter, Value, Sub);                                                                       /* SBSW_OS_JOB_COUNTERSUB_001 */
}


/***********************************************************************************************************************
 *  Os_JobDo()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_JobDo,
(
  P2CONST(Os_JobConfigType, AUTOMATIC, OS_CONST) Job
))
{
  Job->Callback(Job);                                                                                                   /* SBSW_OS_JOB_JOB_CALLBACK_001 */
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */





#endif /* OS_JOB_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_JobInt.h
 **********************************************************************************************************************/
