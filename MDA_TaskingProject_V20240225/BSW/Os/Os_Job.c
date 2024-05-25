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
 * \{
 *
 * \file
 * \brief       Contains the implementation of the Job management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777 EOF */ /* MD_MSR_Rule5.1 */


#define OS_JOB_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Job_Types.h"
#include "Os_Job.h"

/* Os kernel module dependencies */
#include "Os_Cfg.h"

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
 *  LOCAL FUNCTIONS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 **********************************************************************************************************************/


#define OS_STOP_SEC_CODE
#include "Os_MemMap_OsCode.h"                                                                                           /* PRQA S 5087 */ /* MD_MSR_MemMap */


/* module specific MISRA deviations:
 */

/* SBSW_JUSTIFICATION_BEGIN
\ID SBSW_OS_JOB_COUNTERISFUTUREVALUE_001
 \DESCRIPTION    Os_CounterIsFutureValue is called with the Counter pointer derived from the caller argument LeftJob.
                 Precondition ensures that the LeftJob pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_JOBGETDYN_001
 \DESCRIPTION    Write access to the Dyn object of a Job. Precondition ensures that the Job pointer is
                 valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_JOBGETDYN_N]

\ID SBSW_OS_JOB_COUNTERADDRELJOB_001
 \DESCRIPTION    Os_CounterAddRelJob is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERADDABSJOB_001
 \DESCRIPTION    Os_CounterAddAbsJob is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERRELOADJOB_001
 \DESCRIPTION    Os_CounterReloadJob is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERDELETEJOB_001
 \DESCRIPTION    Os_CounterDeleteJob is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERGETCHARACTERISTICS_001
 \DESCRIPTION    Os_CounterGetCharacteristics is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERGETVALUE_001
 \DESCRIPTION    Os_CounterGetValue is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERGETMODULO_001
 \DESCRIPTION    Os_CounterGetModulo is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERSUB_001
 \DESCRIPTION    Os_CounterSub is called with the Counter pointer derived from the caller argument Job.
                 Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERCHECKVALUELEMAXALLOWED_001
 \DESCRIPTION    Os_CounterCheckValueLeMaxAllowed is called with the Counter pointer derived from the caller argument
                 Job. Precondition ensures that the Job pointer is valid. The compliance of the precondition is check
                 during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERCHECKVALUELEREDUCEDMAXALLOWED_001
 \DESCRIPTION    Os_CounterCheckValueLeReducedMaxAllowed is called with the Counter pointer derived from the caller
                 argument Job. Precondition ensures that the Job pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERCHECKVALUEGEMINCYCLEORZERO_001
 \DESCRIPTION    Os_CounterCheckValueGeMinCycleOrZero is called with the Counter pointer derived from the caller
                 argument Job. Precondition ensures that the Job pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]

\ID SBSW_OS_JOB_COUNTERGETCORE_001
 \DESCRIPTION    Os_CounterGetCore is called with the Counter pointer derived from the caller
                 argument Job. Precondition ensures that the Job pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_JOBGETCOUNTER_M]
                 \M [CM_OS_COUNTERGETCORE_M]

\ID SBSW_OS_JOB_JOB_CALLBACK_001
 \DESCRIPTION     The callback of a job object is used as function pointer. The callback owner job object is passed as
                  a argument to the callback function. The job is the return value of Os_PriorityQueueTopGet.
 \COUNTERMEASURE  \R [CM_OS_PRIORITYQUEUETOPGET_R]
                  \M [CM_OS_JOB_CALLBACK_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_JOBGETDYN_N
      As each object of an abstract class is always part of a concrete class, the concrete class
      guarantees, that the Dyn pointer is valid.

\CM CM_OS_JOBGETCORE_M
      Verify that the Counter reference in each job instance is a non NULL_PTR.
      Verify also [CM_OS_COUNTERGETCORE_M].

\CM CM_OS_JOBGETCOUNTER_M
      Verify that the Counter reference in each job instance is a non NULL_PTR.

\CM CM_OS_JOB_CALLBACK_M
      Verify that the Callback reference in each job instance is a non NULL_PTR.


 */
/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Job.c
 **********************************************************************************************************************/
