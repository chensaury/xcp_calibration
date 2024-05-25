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
 * \addtogroup Os_Fifo32
 * \{
 *
 * \file
 * \brief       Contains the implementation of the Fifo32 management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_FIFO32_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */
#include "Os_Fifo32.h"

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

\ID SBSW_OS_FF32_FIFOWRITE_DYN_001
 \DESCRIPTION    Write access to the dynamic data of a Fifo32.
 \COUNTERMEASURE \M [CM_OS_FIFO32WRITE_DYN_M]

\ID SBSW_OS_FF32_FIFOWRITE_DATA_001
 \DESCRIPTION    Write access to the data array of a Fifo32 element. The data array is indexed with
                 a WriteIdx, which is a member of the Fifo's Dyn object.
 \COUNTERMEASURE \T TCASE-345817
                 \M [CM_OS_FIFO32WRITE_DYN_M]
                 \M [CM_OS_FIFO32WRITE_DATA_M]

\ID SBSW_OS_FF32_FIFOIDXINCREMENT_001
 \DESCRIPTION    Os_FifoIdxIncrement is called with a pointer derived from a Dyn pointer. The Dyn pointer is derived
                 from an caller's Fifo argument. The correctness of the Fifo argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFO32READ_DYN_M]

\ID SBSW_OS_FF32_FIFOIDXINCREMENT_002
 \DESCRIPTION    Os_FifoIdxIncrement is called with a WriteIdx derived from a Dyn pointer. The Dyn pointer is derived
                 from an caller's Fifo argument. The correctness of the Fifo argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFO32WRITE_DYN_M]

\ID SBSW_OS_FF32_FIFOEMPTYQUEUE_001
 \DESCRIPTION    Os_FifoEmptyQueue is called with a WriteIdx and a ReadIdx derived from a Dyn pointer. The Dyn pointer
                 is derived from an caller's Fifo argument. The correctness of the Fifo argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFO32READ_DYN_M]
                 \M [CM_OS_FIFO32WRITE_DYN_M]

\ID SBSW_OS_FF32_FIFOREAD_DYN_001
 \DESCRIPTION    Write access to the dynamic data of a Fifo32.
 \COUNTERMEASURE \M [CM_OS_FIFO32READ_DYN_M]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_FIFO32READ_DYN_M
      Verify that the Dyn pointer of each Os_Fifo32ReadConfigType object is a non NULL_PTR.

\CM CM_OS_FIFO32WRITE_DYN_M
      Verify that the Dyn pointer of each Os_Fifo32WriteConfigType object is a non NULL_PTR.

\CM CM_OS_FIFO32WRITE_DATA_M
      Verify that
        1. the Data pointer of each Os_Fifo32WriteConfigType object is a non NULL_PTR.
        2. the size of the Data array equals Fifo.Size,
        3. the corresponding Os_Fifo32ReadConfigType instance refers to the same Data array.
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_Fifo32.c
 **********************************************************************************************************************/
