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
 * \addtogroup Os_Lock
 * \{
 *
 * \file
 * \brief       Provides the Lock implementation.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_LOCK_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
#include "Std_Types.h"

/* Os module declarations */
#include "Os_Lock_Types.h"
#include "Os_Lock.h"

/* Os kernel module dependencies */
#include "Os_Error.h"
#include "Os_Spinlock.h"
#include "Os_Resource.h"

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
\ID SBSW_OS_LOCK_LOCKLISTPOP_001
 \DESCRIPTION    Os_LockListPop is called within a loop. The initial value passed as argument to the
                 caller. Precondition ensures that the Lock pointer is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_LOCK_LOCKGETDYN_001
 \DESCRIPTION    Write access to the Dyn object of a Lock. Precondition ensures that the Lock pointer is
                 valid. The compliance of the precondition is check during review.
 \COUNTERMEASURE \N [CM_OS_LOCKGETDYN_N]

\ID SBSW_OS_LOCK_LOCKLISTISEMPTY_001
 \DESCRIPTION    Os_LockListIsEmpty is called with a pointer passed as argument to the caller function.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

\ID SBSW_OS_LOCK_LOCKISRESOURCE_001
 \DESCRIPTION    Os_LockIsResource is called with a value derived from pointer passed as argument to the caller
                 function. Precondition ensures that the pointer is valid. The compliance of the
                 precondition is check during review.
 \COUNTERMEASURE \R If condition ensures that the passed pointer is valid.

\ID SBSW_OS_LOCK_LOCKLISTNEXTITERATOR_001
 \DESCRIPTION    Os_LockListNextIterator is called within a loop. The passed pointer is change on every iteration.
 \COUNTERMEASURE \R Loop condition ensures that the passed pointer is valid.

 SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_LOCKGETDYN_N
      As each object of an abstract class is always part of a concrete class, the concrete class
      guarantees, that the Dyn pointer is valid.

\CM CM_LOCKLISTGETTOP_R
      The caller ensures by runtime check, that the passed lock list not empty.

\CM CM_LOCKLISTISEMPTY_R
      The caller ensures by runtime check, that the passed lock list not empty.

 */



/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Lock.c
 **********************************************************************************************************************/
