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
 *
 * \{
 * \file
 *
 **********************************************************************************************************************/
/***********************************************************************************************************************
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Refer to Os.h.
 **********************************************************************************************************************/

#ifndef OS_BITARRAY_H
# define OS_BITARRAY_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */
# include "Os_BitArrayInt.h"

/* Os kernel module dependencies */
# include "Os_Error.h"
# include "Os_Bit.h"
# include "Os_Common.h"

/* Os hal dependencies */
# include "Os_Hal_Compiler.h"
# include "Os_Hal_Core.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
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
 *  Os_BitArrayIdxIsValid()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_BitArrayIdxIsValid,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
))
{
  return (Os_BitArrayIndexType)(BitIdx < BitArray->BitLength);                                                          /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
}


/***********************************************************************************************************************
 *  Os_BitArrayGetIndexBitwidth()
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DEFINITION(                                                                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_LOCAL_INLINE uint8, OS_CODE, OS_ALWAYS_INLINE, Os_BitArrayGetIndexBitwidth, (void))
{
  return (uint8)OS_BITFIELD_INDEXBITWIDTH;
}


/***********************************************************************************************************************
 *  Os_BitArrayIdxGetAllocationIdx()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_BitArrayIdxGetAllocationIdx,
(
  Os_BitFieldType BitArrayIdx
))
{
  /* #10 Shift the field index part of the bit index to the right, so that there is only the allocation part. */
  return (Os_BitArrayIndexType)(BitArrayIdx >> Os_BitArrayGetIndexBitwidth());
}


/***********************************************************************************************************************
 *  Os_BitArrayIdxGetFieldIdx()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_BitArrayIdxGetFieldIdx,
(
  Os_BitArrayIndexType BitArrayIdx
))
{
  /* #10 Clear the upper bits, used for allocation mask addressing. */
  return (Os_BitArrayIndexType)(BitArrayIdx & ((((Os_BitArrayIndexType)1) << Os_BitArrayGetIndexBitwidth()) - 1u));
}


/***********************************************************************************************************************
 *  Os_BitArrayInit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_BitArrayInit,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray
))
{
  Os_BitArrayIndexType idx;

  /* Check that the bit length is greater than 1, because one bit is needed internally for the end 1 bit. */
  Os_Assert((Os_StdReturnType)(BitArray->Size > 0u));                                                                   /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */
  Os_Assert((Os_StdReturnType)(BitArray->BitLength > 1u));                                                              /* PRQA S 4304 */ /* MD_Os_C90BooleanCompatibility */

  /* #10 Set all bits to 0. */
  BitArray->Dyn->AllocationMask = 0;                                                                                    /* SBSW_OS_BA_BITARRAYGETDYN_001 */
  for(idx = 0; idx < BitArray->Size; ++idx)
  {
    BitArray->Data[idx] = 0;                                                                                            /* SBSW_OS_BA_BITARRAY_DATA_001 */
  }

  /* #20 Set the always 1 bit. */
  Os_BitArraySetBitInternal(BitArray, BitArray->BitLength-(uint16)1);                                                   /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_BitArraySetBitInternal()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_BitArraySetBitInternal,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
))
{
  Os_BitArrayIndexType allocationIdx;
  Os_BitArrayIndexType fieldIdx;

  /* #10 Check whether the given index is in the expected range (end bit is allowed to set internally). */
  Os_Assert(Os_BitArrayIdxIsValid(BitArray, BitIdx));                                                                   /* SBSW_OS_FC_PRECONDITION */

  /* #20 Get allocation mask index and field index from BitIdx. */
  allocationIdx = Os_BitArrayIdxGetAllocationIdx(BitIdx);
  fieldIdx = Os_BitArrayIdxGetFieldIdx(BitIdx);

  /* #30 Set the bit field bit and the allocation bit. */
  BitArray->Data[allocationIdx] |= (OS_BITFIELD_MASK_MSB >> fieldIdx);                                                  /* SBSW_OS_BA_BITARRAY_DATA_002 */
  BitArray->Dyn->AllocationMask |= (OS_BITFIELD_MASK_MSB >> allocationIdx);                                             /* SBSW_OS_BA_BITARRAYGETDYN_001 */
}


/***********************************************************************************************************************
 *  Os_BitArraySetBit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_BitArraySetBit,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
))
{
  /*! Internal comment removed.
 *
 * */
  /* #10 Check whether the given index is in the expected range. */
  Os_Assert(Os_BitArrayIdxIsValid(BitArray, BitIdx+(uint16)1));                                                         /* SBSW_OS_FC_PRECONDITION */

  /* #20 Call internal set function. */
  Os_BitArraySetBitInternal(BitArray, BitIdx);                                                                          /* SBSW_OS_FC_PRECONDITION */
}


/***********************************************************************************************************************
 *  Os_BitArrayClearBit()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,                                           /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
Os_BitArrayClearBit,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
))
{
  Os_BitArrayIndexType allocationIdx;
  Os_BitArrayIndexType fieldIdx;

  /* #10 Check whether the given index is in the expected range. */
  /* The end bit is not allowed to be cleared. */
  Os_Assert(Os_BitArrayIdxIsValid(BitArray, BitIdx+(uint16)1));                                                         /* SBSW_OS_FC_PRECONDITION */

  /* #20 Get allocation mask index and field index from BitIdx. */
  allocationIdx = Os_BitArrayIdxGetAllocationIdx(BitIdx);
  fieldIdx = Os_BitArrayIdxGetFieldIdx(BitIdx);

  /* #30 Clear the bit field bit. */
  BitArray->Data[allocationIdx] &= (~(OS_BITFIELD_MASK_MSB >> fieldIdx));                                               /* SBSW_OS_BA_BITARRAY_DATA_002 */

  /* #40 If the bit field is empty now, clear also the corresponding allocation bit. */
  if(BitArray->Data[allocationIdx] == 0u)
  {
    BitArray->Dyn->AllocationMask &= (~(OS_BITFIELD_MASK_MSB >> allocationIdx));                                        /* SBSW_OS_BA_BITARRAYGETDYN_001 */
  }
}


/***********************************************************************************************************************
 *  Os_BitArrayCountLeadingZeros()
 **********************************************************************************************************************/
/*!
 * Internal comment removed.
 *
 *
 *
 *
 */
OS_FUNC_ATTRIBUTE_DEFINITION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE,                                             /* PRQA S 3219 */ /* MD_Os_Rule2.1_3219 */
OS_ALWAYS_INLINE, Os_BitArrayCountLeadingZeros,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray
))
{
  Os_BitArrayIndexType resultIdx;
  Os_BitArrayIndexType allocationIdx;
  Os_BitArrayIndexType fieldIdx;

  /* #10 Find the first allocated bit field. */
  allocationIdx = (Os_BitArrayIndexType)Os_Bit_CountLeadingZeros(BitArray->Dyn->AllocationMask);

  /* #20 Find the first bit in the bit field which is set. */
  fieldIdx = (Os_BitArrayIndexType)Os_Bit_CountLeadingZeros(BitArray->Data[allocationIdx]);

  /* #30 Calculate the bit index. */
  resultIdx = ((Os_BitArrayIndexType)(allocationIdx << Os_BitArrayGetIndexBitwidth()) + fieldIdx);

  return resultIdx;
}


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_BITARRAY_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_BitArrayInt.h
 **********************************************************************************************************************/
