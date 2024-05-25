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
 * \addtogroup Os_Deque
 * \{
 *
 * \file
 * \brief       Contains the implementation of the Deque management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_DEQUE_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */
#include "Os_Deque.h"

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

\ID SBSW_OS_PWA_DEQUE_DYN_PTR_WRITE
 \DESCRIPTION    Write access to the dynamic data of a deque. Precondition assures that a valid deque pointer is
                 provided to this function.
 \COUNTERMEASURE \M [CM_OS_DEQUE_DYN_M]

\ID SBSW_OS_FC_DEQUE_DYN_PTR_ELEM
 \DESCRIPTION    Function call with pointer to element of deque dynamic data. Precondition assures that a valid
                 deque pointer is provided to this function.
 \COUNTERMEASURE \M [CM_OS_DEQUE_DYN_M]

\ID SBSW_OS_AWA_DEQUE_BUFFER
 \DESCRIPTION    Array write access to data buffer of deque. Precondition assures that a valid deque pointer is provided
                 to this function. Review has shown that the read/write index of the deque dynamic data is initialized
                 to zero and afterwards only changed by functions Os_DequeIdxIncrement, Os_DequeIdxDecrement and
                 Os_DequeDelete which guarantee that the index is kept in valid range.
 \COUNTERMEASURE \M [CM_OS_DEQUE_DYN_M]
                 \M [CM_OS_DEQUE_BUFFER_SIZE_M]

\ID SBSW_OS_AWA_DEQUE_BUFFER_LOCAL_IDX
 \DESCRIPTION    Array write access to data buffer of deque. Precondition assures that a valid deque pointer is provided
                 to this function. Review has shown that the local read/write index is initialized from a valid index
                 and afterwards only changed by function Os_DequeIdxIncrement which performs a check against the
                 configured size in order to keep the index in valid range.
 \COUNTERMEASURE \M [CM_OS_DEQUE_DYN_M]
                 \M [CM_OS_DEQUE_BUFFER_SIZE_M]


SBSW_JUSTIFICATION_END */


/*
\CM CM_OS_DEQUE_DYN_M
      Verify that the Deque Dyn pointer of each deque in OsCfg_TaskQueuesCoreX is initialized with a non NULL_PTR
      for all core IDs X.
\CM CM_OS_DEQUE_BUFFER_SIZE_M
      Verify that the buffer pointer of each deque refers to an array which has the size as defined by the Size element
      of the Os_DequeConfigType.

 */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Deque.c
 **********************************************************************************************************************/
