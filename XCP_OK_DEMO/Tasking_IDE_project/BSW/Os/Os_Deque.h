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
 *
 * \{
 *
 * \file
 * \brief         Contains the deque definition.
 * \details       --no details--
 *
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_DEQUE_H
# define OS_DEQUE_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module dependencies */
# include "Os_DequeInt.h"

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
 *  Os_DequeIdxDecrement()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_DequeIdxDecrement,
(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Index,
  const uint32 Size
))
{
  /* #10  Prevent an underflow and decrement. */
  if(OS_UNLIKELY((*Index) == 0u))
  {
    (*Index) = Size;                                                                                                    /* SBSW_OS_PWA_PRECONDITION  */
  }

  (*Index)--;                                                                                                           /* SBSW_OS_PWA_PRECONDITION  */
}

/***********************************************************************************************************************
 *  Os_DequeIdxIncrement()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_DequeIdxIncrement,
(
  P2VAR(uint32, AUTOMATIC, OS_APPL_DATA) Index,
  const uint32 Size
))
{

  /* #10  Increment and prevent overflow. */
  (*Index)++;                                                                                                           /* SBSW_OS_PWA_PRECONDITION  */
  if(OS_UNLIKELY((*Index) >= Size))
  {
    (*Index) = 0;                                                                                                       /* SBSW_OS_PWA_PRECONDITION  */
  }

}


/***********************************************************************************************************************
 *  Os_DequeInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_DequeInit,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
))
{
  /* #10  Initialize the Deque objects. */
  Deque->Dyn->ReadIdx = 0;                                                                                              /* SBSW_OS_PWA_DEQUE_DYN_PTR_WRITE */
  Deque->Dyn->WriteIdx = 0;                                                                                             /* SBSW_OS_PWA_DEQUE_DYN_PTR_WRITE */
}


/***********************************************************************************************************************
 *  Os_DequeDeleteTop()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void,                                                                      /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_CODE, OS_ALWAYS_INLINE, Os_DequeDeleteTop,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
))
{
  /* #10 Simply increment the read index. */
  Os_DequeIdxIncrement(&(Deque->Dyn->ReadIdx), Deque->Size);                                                            /* SBSW_OS_FC_DEQUE_DYN_PTR_ELEM */
}


/***********************************************************************************************************************
 *  Os_DequeEnqueue()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_DequeEnqueue,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque,
  P2CONST(Os_TaskConfigType, TYPEDEF, AUTOMATIC) Value
))
{
  /* #10 Store Value in the data buffer. */
  Deque->Buffer[Deque->Dyn->WriteIdx].Value = Value;                                                                    /* SBSW_OS_AWA_DEQUE_BUFFER */

  /* #20 Increment the write index. */
  Os_DequeIdxIncrement(&(Deque->Dyn->WriteIdx), Deque->Size);                                                           /* SBSW_OS_FC_DEQUE_DYN_PTR_ELEM */
  Os_Assert((Os_StdReturnType)(Deque->Dyn->ReadIdx != Deque->Dyn->WriteIdx));                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}



/***********************************************************************************************************************
 *  Os_DequePrepend()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE,                                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_DequePrepend,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque,
  P2CONST(Os_TaskConfigType, TYPEDEF, AUTOMATIC) Value
))
{

  /* #10  Decrement the read index. */
  Os_DequeIdxDecrement(&(Deque->Dyn->ReadIdx), Deque->Size);                                                            /* SBSW_OS_FC_DEQUE_DYN_PTR_ELEM */

  /* #20  Store Value in the data buffer. */
  Deque->Buffer[Deque->Dyn->ReadIdx].Value = Value;                                                                     /* SBSW_OS_AWA_DEQUE_BUFFER */

  Os_Assert((Os_StdReturnType)(Deque->Dyn->ReadIdx != Deque->Dyn->WriteIdx));                                           /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

}


/***********************************************************************************************************************
 *  Os_DequePeek()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE P2CONST(Os_TaskConfigType, AUTOMATIC, OS_CODE),                            /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
AUTOMATIC, OS_ALWAYS_INLINE, Os_DequePeek,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
))
{
  /* #10 Simply return the front element. */
  return Deque->Buffer[Deque->Dyn->ReadIdx].Value;
}



/***********************************************************************************************************************
 *  Os_DequeDelete()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_DequeDelete,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque,
  P2CONST(Os_TaskConfigType, TYPEDEF, AUTOMATIC) Value
))
{
  uint32 readIdx;
  uint32 writeIdx;

  /* #10 Initialize the local read and write index with the front index. */
  readIdx = Deque->Dyn->ReadIdx;
  writeIdx = readIdx;

  /* #20 While the local read index is not equal to the back index: */
  while(readIdx != Deque->Dyn->WriteIdx)
  {
    /* #30 If the element at the local read index position shall not be deleted: */
    if(OS_LIKELY(Value != Deque->Buffer[readIdx].Value))
    {
      /* #40 Copy the read element to the write element as defined by local indices. */
      Deque->Buffer[writeIdx].Value = Deque->Buffer[readIdx].Value;                                                     /* SBSW_OS_AWA_DEQUE_BUFFER_LOCAL_IDX */
      /* #50 Increment the local write index. */
      Os_DequeIdxIncrement(&writeIdx, Deque->Size);                                                                     /* SBSW_OS_FC_POINTER2LOCAL */
    }

    /* #60 Increment the local read index. */
    Os_DequeIdxIncrement(&readIdx, Deque->Size);                                                                        /* SBSW_OS_FC_POINTER2LOCAL */
  }
  /* #70 Set the back index to the local write index. */
  Deque->Dyn->WriteIdx = writeIdx;                                                                                      /* SBSW_OS_PWA_DEQUE_DYN_PTR_WRITE */
}


/***********************************************************************************************************************
 *  Os_DequeIsEmpty()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_StdReturnType, OS_CONST,                                                /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_DequeIsEmpty,
(
  P2CONST(Os_DequeConfigType, AUTOMATIC, OS_APPL_DATA) Deque
))
{
  /* #10 Simply return whether or not read and write index are identical. */
  return ((Os_StdReturnType)(Deque->Dyn->ReadIdx == Deque->Dyn->WriteIdx));                                            /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}



# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_DEQUE_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */
/***********************************************************************************************************************
 *  END OF FILE: Os_DequeInt.h
 **********************************************************************************************************************/
