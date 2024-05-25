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
 * \addtogroup Os_Fifo
 *
 * \{
 *
 * \file          Os_Fifo.h
 * \brief         This file provides common functions implementation for FIFO handling.
 * \details       --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_FIFO_H
# define OS_FIFO_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_FifoInt.h"

/* Os kernel module dependencies */
# include "Os_Error.h"
# include "Os_Common.h"

/* Os Hal dependencies */
# include "Os_Hal_Compiler.h"


/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


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
 *  Os_FifoIdxIncrement
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_FifoIdxIncrement,
(
  P2VAR(Os_FifoIdxType, AUTOMATIC, OS_APPL_DATA) Index,
  Os_FifoIdxType Size
))
{
  Os_Assert((Os_StdReturnType)((*Index) < Size));                                                                       /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10  Increment, if queue Size is reached set Index to 0. */
  if(OS_UNLIKELY((*Index) == (Size - 1u)))
  {
    (*Index) = 0;                                                                                                       /* SBSW_OS_PWA_PRECONDITION */
  }
  else
  {
    (*Index)++;                                                                                                         /* SBSW_OS_PWA_PRECONDITION */
  }
}


/***********************************************************************************************************************
 *  Os_FifoIsFull()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_FifoIsFull,
(
  Os_FifoIdxType WriteIdx,
  Os_FifoIdxType ReadIdx,
  Os_FifoIdxType Size
))
{
  /* #10  Calculate the next write index. */
  Os_FifoIdxIncrement(&WriteIdx, Size);                                                                                 /* PRQA S 1339 */ /* MD_Os_Rule17.8_1339 */ /* SBSW_OS_FC_POINTER2ARGUMENT */

  /* #20  If the next write index wasn't read, then the buffer is full. */
  return (WriteIdx == ReadIdx);                                                                                         /* PRQA S 4404 */ /*  MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_FifoIsEmpty()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_FifoIsEmpty,
(
  Os_FifoIdxType WriteIdx,
  Os_FifoIdxType ReadIdx
))
{
  /* #10  Return whether or not, read and write index are identical. */
  return (ReadIdx == WriteIdx);                                                                                         /* PRQA S 4404 */ /*  MD_Os_C90BooleanCompatibility */
}



/***********************************************************************************************************************
 *  Os_FifoEmptyQueue()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CONST, OS_ALWAYS_INLINE,                                          /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_FifoEmptyQueue,
(
  P2CONST(Os_FifoIdxType, AUTOMATIC, TYPEDEF) WriteIdx,
  P2VAR(Os_FifoIdxType, AUTOMATIC, TYPEDEF) ReadIdx
))
{
  (*ReadIdx) = (*WriteIdx);                                                                                             /* SBSW_OS_PWA_PRECONDITION */
}



/***********************************************************************************************************************
 *  Os_FifoIndicesInRange()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_FifoIndicesInRange,
(
  Os_FifoIdxType WriteIdx,
  Os_FifoIdxType ReadIdx,
  Os_FifoIdxType Size
))
{
  /* #10 Check that read and write index is smaller than size. */
  return ((WriteIdx < Size) && (ReadIdx < Size));                                                                      /* PRQA S 4404 */ /*  MD_Os_C90BooleanCompatibility */ /* COV_OS_INVSTATE */
}

# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_FIFO_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_FifoInt.h
 **********************************************************************************************************************/
