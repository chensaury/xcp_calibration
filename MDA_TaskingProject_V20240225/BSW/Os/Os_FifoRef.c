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
 * \addtogroup Os_FifoRef
 * \{
 *
 * \file
 * \brief       Contains the implementation of the FifoRef management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_FIFOREF_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */
#include "Os_FifoRef.h"

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

\ID SBSW_OS_FFREF_FIFOWRITE_DYN_001
 \DESCRIPTION    Write access to the dynamic data of a FifoRef.
 \COUNTERMEASURE \M [CM_OS_FIFOREFWRITE_DYN_M]

\ID SBSW_OS_FFREF_FIFOWRITE_DATA_001
 \DESCRIPTION    Write access to the data array of a FifoRef element. The data array is indexed with
                 a WriteIdx, which is a member of the Fifo's Dyn object.
 \COUNTERMEASURE \T TCASE-345817
                 \M [CM_OS_FIFOREFWRITE_DYN_M]
                 \M [CM_OS_FIFOREFWRITE_DATA_M]

\ID SBSW_OS_FFREF_FIFOIDXINCREMENT_001
 \DESCRIPTION    Os_FifoIdxIncrement is called with a pointer derived from a Dyn pointer. The Dyn pointer is derived
                 from an caller's Fifo argument. The correctness of the Fifo argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFOREFREAD_DYN_M]

\ID SBSW_OS_FFREF_FIFOIDXINCREMENT_002
 \DESCRIPTION    Os_FifoIdxIncrement is called with a WriteIdx derived from a Dyn pointer. The Dyn pointer is derived
                 from an caller's Fifo argument. The correctness of the Fifo argument is ensured by precondition.
                 The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFOREFWRITE_DYN_M]

\ID SBSW_OS_FFREF_FIFOEMPTYQUEUE_001
 \DESCRIPTION    Os_FifoEmptyQueue is called with a WriteIdx and a ReadIdx derived from a Dyn pointer. The Dyn pointer
                 is derived from an caller's Fifo argument. The correctness of the Fifo argument is ensured by
                 precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFOREFREAD_DYN_M]
                 \M [CM_OS_FIFOREFWRITE_DYN_M]

\ID SBSW_OS_FFREF_FIFOREAD_DYN_001
 \DESCRIPTION    Write access to the dynamic data of a FifoRef.
 \COUNTERMEASURE \M [CM_OS_FIFOREFREAD_DYN_M]

\ID SBSW_OS_FFREF_FIFO_WRITECBK_001
 \DESCRIPTION    Call of WriteCbk function of a FIFO object passed as argument to the caller. The correctness of the
                 Fifo argument is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFOREF_WRITECBK_DATA_M]

\ID SBSW_OS_FFREF_FIFO_READCBK_001
 \DESCRIPTION    Call of ReadCbk function of a FIFO object passed as argument to the caller. The correctness of the
                 Fifo argument is ensured by precondition. The compliance of the precondition is check during review.
 \COUNTERMEASURE \M [CM_OS_FIFOREF_READCBK_DATA_M]


SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_FIFOREFREAD_DYN_M
      Verify that the Dyn pointer of each Os_FifoRefReadConfigType object is a non NULL_REF.

\CM CM_OS_FIFOREFWRITE_DYN_M
      Verify that the Dyn pointer of each Os_FifoRefWriteConfigType object is a non NULL_REF.

\CM CM_OS_FIFOREFWRITE_DATA_M
      Verify that
        1. the Data pointer of each Os_FifoRefWriteConfigType object is a non NULL_REF.
        2. the size of the Data array equals Fifo.Size,
        3. the corresponding Os_FifoRefReadConfigType instance refers to the same Data array.

\CM CM_OS_FIFOREF_WRITECBK_DATA_M
      Verify that the WriteCallback of each Os_FifoRefWriteConfigType instance is a non NULL_PTR.

\CM CM_OS_FIFOREF_READCBK_DATA_M
      Verify that the ReadCallback of each Os_FifoRefReadConfigType instance is a non NULL_PTR.
 */


/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_FifoRef.c
 **********************************************************************************************************************/
