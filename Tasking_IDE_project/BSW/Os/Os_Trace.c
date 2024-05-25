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
 * \addtogroup Os_Trace
 * \{
 *
 * \file
 * \brief       Contains the implementation of the Trace management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_TRACE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */
#include "Os_Trace.h"

/* Os kernel module dependencies */

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

\ID SBSW_OS_TRACE_GETDYN_001
 \DESCRIPTION    Write access to the Dyn object of a TraceThread object. The object is passed as argument to the
                 caller function. Precondition ensures that the pointer is valid. The compliance of the precondition is
                 check during review.
 \COUNTERMEASURE \M [CM_OS_TRACETHREAD_DYN_M]

\ID SBSW_OS_TRACE_CORE2ASRCORE_001
 \DESCRIPTION    Os_Core2AsrCore is called with the return value of Os_CoreGetCurrentCore.
 \COUNTERMEASURE \S [CM_OS_COREGETCURRENTCORE_S]

\ID SBSW_OS_TRACE_COREGETID_001
 \DESCRIPTION    Os_CoreGetId is called with the return value of Os_CoreGetCurrentCore.
 \COUNTERMEASURE \S [CM_OS_COREGETCURRENTCORE_S]

\ID SBSW_OS_TRACE_COREASRGETTRACE_001
 \DESCRIPTION    Os_CoreAsrGetTrace is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]

\ID SBSW_OS_TRACE_COREASRGETTRACE_002
 \DESCRIPTION    Write access to the return value of Os_CoreAsrGetTrace.
 \COUNTERMEASURE \M [CM_OS_COREASRGETTRACE_M]

\ID SBSW_OS_TRACE_THREADGETTRACE_001
 \DESCRIPTION    Os_ThreadGetTrace is called with the return value of Os_CoreGetThread.
 \COUNTERMEASURE \N [CM_OS_COREGETTHREAD_N]

\ID SBSW_OS_TRACE_CORECRITICALUSERSECTIONENTER_001
 \DESCRIPTION    Os_CoreCriticalUserSectionEnter is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]

\ID SBSW_OS_TRACE_CORECRITICALUSERSECTIONLEAVE_001
 \DESCRIPTION    Os_CoreCriticalUserSectionLeave is called with the return value of Os_Core2AsrCore.
 \COUNTERMEASURE \N [CM_OS_CORE2ASRCORE_N]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_TRACETHREAD_DYN_M
      Verify that the Dyn object of each trace object is a non NULL_PTR.

 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Trace.c
 **********************************************************************************************************************/
