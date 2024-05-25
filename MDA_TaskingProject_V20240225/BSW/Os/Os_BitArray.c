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
 * \addtogroup Os_BitArray
 * \{
 *
 * \file
 * \brief       Contains the implementation of the BitArray management.
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

                                                                                                                        /* PRQA S 0777, 0779, 0828  EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2, MD_MSR_Dir1.1 */


#define OS_BITARRAY_SOURCE

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */

/* Os module declarations */
#include "Os_BitArray.h"

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

\ID SBSW_OS_BA_BITARRAYGETDYN_001
 \DESCRIPTION    Write access to the dynamic data of a bit array.
 \COUNTERMEASURE \M [CM_OS_BITARRAY_DYN_M]

\ID SBSW_OS_BA_BITARRAY_DATA_001
 \DESCRIPTION    Write access to the Data member of a bit array in a loop running from 0 to Size-1.
 \COUNTERMEASURE \M [CM_OS_BITARRAY_DATA_M]

\ID SBSW_OS_BA_BITARRAY_DATA_002
 \DESCRIPTION    Write access to the Data member of a bit array, indexed with a value derived from a function argument.
                 Precondition ensures that the pointer is valid. The compliance of the precondition is check during
                 review.
 \COUNTERMEASURE \M [CM_OS_BITARRAY_DATA_M]
                 \T [CM_OS_BITARRAYIDXGETALLOCATIONIDX_T]

SBSW_JUSTIFICATION_END */

/*
\CM CM_OS_BITARRAY_DYN_M
      Verify that the BitArray Dyn pointer of each BitArray object is a non NULL_PTR.

\CM CM_OS_BITARRAY_DATA_M
      Verify that:
        1. each bit array Data pointer is no NULL_PTR and
        2. each bit array's Data array size is equal to the bit array's Size.

\CM CM_OS_BITARRAYIDXGETALLOCATIONIDX_T
      TCASE-345810 ensures that the returned index is valid, if the passed index is valid.
 */
/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_BitArray.c
 **********************************************************************************************************************/
