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
 * \ingroup     Os_Kernel
 * \defgroup    Os_BitArray    Bit Array
 * \brief       Bit array primitives.
 * \details
 * A bit array (aka bitmap, bitset, bit string or bit vector) is a data structure which stores bits.
 * For efficiency reasons the bit array consists of one or more processor words. Most architectures provide a
 * "Count Leading Zeros"-Instruction, that can be used to find the first one bit with maximum performance.
 *
 * The bit array is divided into two levels:
 * - **Allocation Mask** is used to determine the processor words which contains one bit at least. It is an
 *   overview of all processor words in the bit array.
 * - **Bit Fields** is used to extend the size of the processor word.
 *
 * Insert, delete and find operations are O(1).
 *
 * ![Data Structure](BitArrayDataStructure.png)
 *
 * The end of a bit array is marked with an additional always '1' bit. This saves us special treatment for empty
 * bit arrays, because empty bit arrays are unlikely.
 *
 * This results into a maximum bit array size of:
 *   NumberOfBits(ProcessorWord)<sup>2</sup>-1 (e.g. for a 32bit-Word: (32<sup>2</sup>)-1=1023)
 *
 * \see [Bit-Array](http:\\en.wikipedia.org/wiki/Bit_array),
 *      [Find First One](http:\\en.wikipedia.org/wiki/Bit_array#Find_first_one)
 * \see [Bit Field](http:\\en.wikipedia.org/wiki/Bit_field)
 * \see [Find First Set](http:\\en.wikipedia.org/wiki/Find_first_set),
 *      [Count Leading Zeros](http:\\en.wikipedia.org/wiki/Find_first_set#CLZ)
 * \see Os_Bit_CountLeadingZeros()
 *
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

#ifndef OS_BITARRAYINT_H
# define OS_BITARRAYINT_H
                                                                                                                         /* PRQA S 0388 EOF */ /* MD_MSR_Dir1.1 */
/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/
/* AUTOSAR includes */
# include "Std_Types.h"

/* Os module declarations */


/* Os kernel module dependencies */
# include "Os_Common_Types.h"
# include "Os_BitInt.h"

/* Os hal dependencies */
# include "Os_Hal_CompilerInt.h"



/***********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 **********************************************************************************************************************/
/*! \brief    Calculates the number of required bits.
 *  \details  --no details--
 *  \param[in]      BitSize   Number of bits which shall be reserved */
#define OS_BITARRAY_LENGTH(BitSize)   ((BitSize) + 1u)                                                                  /* PRQA S 3453 */ /* MD_MSR_FctLikeMacro */


/*! \brief    Calculates the number of required bit fields.
 *  \details  --no details--
 *  \param[in]      BitSize   Number of bits which shall be reserved */
#define OS_BITARRAY_SIZE(BitSize)  ((OS_BITARRAY_LENGTH(BitSize)/OS_BITFIELD_BITWIDTH) + 1u)                            /* PRQA S 3410, 3453 */ /* MD_Os_Rule20.7_3410_Decl, MD_MSR_FctLikeMacro */


/*! \brief    Declare a bit array.
 *  \details  The bit array needs one extra bit to store its always '1' end bit.
 *  \param[in]      Name      Name of the bit array
 *  \param[in]      BitSize   Number of bits which shall be reserved
 *  \param[in]      MemClass  The target memory section */
#define OS_BITARRAY_DECLARE(Name, BitSize, MemClass)  VAR(Os_BitFieldType, MemClass)  Name[OS_BITARRAY_SIZE(BitSize)]   /* PRQA S 0850, 3410, 3453 */ /* MD_MSR_MacroArgumentEmpty, MD_Os_Rule20.7_3410_Decl, MD_MSR_FctLikeMacro */



/***********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 **********************************************************************************************************************/
/*! Basic data type which is used to build a bit array. */
typedef uint16 Os_BitArrayIndexType;


/*! Dynamic data structure of a bit array. */
typedef struct
{
  /*! Holds one bit for each element in Os_BitArrayConfigType.Data
   *  which denotes, whether the data element is used or not. */
  Os_BitFieldType AllocationMask;
}Os_BitArrayType;


/*! Basic data structure of the bit array. */
typedef struct
{
  /*! The dynamic data of this bit array. */
  P2VAR(Os_BitArrayType, AUTOMATIC, OS_APPL_DATA) Dyn;
  /*! Array of bit fields. */
  P2VAR(Os_BitFieldType, AUTOMATIC, OS_APPL_DATA) Data;
  /*! The Data array length. */
  Os_BitArrayIndexType Size;
  /*! The number of configured bits in the array. */
  Os_BitArrayIndexType BitLength;
}Os_BitArrayConfigType;


/***********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 **********************************************************************************************************************/


/***********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 **********************************************************************************************************************/


# define OS_START_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


/***********************************************************************************************************************
 *  Os_BitArrayIdxIsValid()
 **********************************************************************************************************************/
/*! \brief      Returns whether the given index is in the range of the configured bit length.
 *  \details    --no details--
 *
 *  \param[in]  BitArray      The bit array instance. Parameter must not be NULL.
 *  \param[in]  BitIdx        The bit index to validate.
 *
 *  \return     The validity of the given index.
 *  \retval     !0            If the given index is valid.
 *  \retval     0             If the given index is invalid.
 *
 *  \context    ANY
 *
 *  \reentrant  TRUE
 *  \synchronous TRUE
 *
 *  \pre        -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE, OS_ALWAYS_INLINE,
Os_BitArrayIdxIsValid,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
));


/***********************************************************************************************************************
 *  Os_BitArrayGetIndexBitwidth()
 **********************************************************************************************************************/
/*! \brief          Returns the number of bits needed to address all bits of a Os_BitFieldType.
 *  \details        --no details--
 *
 *  \return         The number of bit positions.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE
 *  \synchronous    TRUE
 *
 *  \pre            -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(
OS_LOCAL_INLINE uint8, OS_CODE, OS_ALWAYS_INLINE, Os_BitArrayGetIndexBitwidth, (void));


/***********************************************************************************************************************
 *  Os_BitArrayIdxGetAllocationIdx()
 **********************************************************************************************************************/
/*! \brief      Converts a bit array index into an allocation mask index.
 *  \details    The returned index is relative to the MSb.
 *
 *  \param[in]  BitArrayIdx   A bit array index.
 *
 *  \return     The allocation index corresponding to the given bit array index.
 *
 *  \context    ANY
 *
 *  \reentrant  TRUE
 *  \synchronous TRUE
 *
 *  \pre        -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE, OS_ALWAYS_INLINE,
Os_BitArrayIdxGetAllocationIdx,
(
  Os_BitFieldType BitArrayIdx
));


/***********************************************************************************************************************
 *  Os_BitArrayIdxGetFieldIdx()
 **********************************************************************************************************************/
/*! \brief      Converts a bit array index into a bit field index.
 *  \details    The returned index is relative to the MSb.
 *
 *  \param[in]  BitArrayIdx   Bit array index to be converted.
 *
 *  \return     Resulting bit field index.
 *
 *  \context    ANY
 *
 *  \reentrant  TRUE
 *  \synchronous TRUE
 *
 *  \pre        -
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE, OS_ALWAYS_INLINE,
Os_BitArrayIdxGetFieldIdx,
(
  Os_BitArrayIndexType BitArrayIdx
));


/***********************************************************************************************************************
 *  Os_BitArrayInit()
 **********************************************************************************************************************/
/*! \brief          Initialize all bits to 0 and set the last bit to 1.
 *  \details        This function is called in Init-Step3 and Init-Step4 to handle the situation that Init-Step3 is
 *                  optional.
 *
 *  \param[in,out]  BitArray      The bit array instance. Parameter must not be NULL.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different bit arrays.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_BitArrayInit,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray
));


/***********************************************************************************************************************
 *  Os_BitArraySetBit()
 **********************************************************************************************************************/
/*! \brief          Sets a bit to 1.
 *  \details        Uses Os_BitArraySetBitInternal() internally.
 *
 *  \param[in,out]  BitArray  The bit array instance. Parameter must not be NULL.
 *  \param[in]      BitIdx    The bit position to set starting from MSb.
 *                            The index must be smaller than BitArray->BitLength.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different bit arrays.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_BitArraySetBit,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
));


/***********************************************************************************************************************
 *  Os_BitArraySetBitInternal()
 **********************************************************************************************************************/
/*! \brief          Sets a bit to 1.
 *  \details        --no details--
 *
 *  \param[in,out]  BitArray  The bit array instance. Parameter must not be NULL.
 *  \param[in]      BitIdx    The bit position to set starting from MSb.
 *                            The index must be smaller than BitArray->BitLength.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different bit arrays.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE, Os_BitArraySetBitInternal,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
));


/***********************************************************************************************************************
 *  Os_BitArrayClearBit()
 **********************************************************************************************************************/
/*! \brief          Sets a bit to 0.
 *  \details        --no details--
 *
 *  \param[in,out]  BitArray  The bit array instance. Parameter must not be NULL.
 *  \param[in]      BitIdx    The bit position to clear starting from MSb.
 *                            The index must be smaller than BitArray->BitLength.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different bit arrays.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE void, OS_CODE, OS_ALWAYS_INLINE,
Os_BitArrayClearBit,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray,
  Os_BitArrayIndexType BitIdx
));


/***********************************************************************************************************************
 *  Os_BitArrayCountLeadingZeros()
 **********************************************************************************************************************/
/*! \brief          Count leading zeros in given bit array starting from MSb.
 *  \details        --no details--
 *
 *  \param[in,out]  BitArray      The bit array instance. Parameter must not be NULL.
 *
 *  \return         Number of leading zeros.
 *
 *  \context        ANY
 *
 *  \reentrant      TRUE for different bit arrays.
 *  \synchronous    TRUE
 *
 *  \pre            Concurrent access to given object is prevented by caller.
 **********************************************************************************************************************/
OS_FUNC_ATTRIBUTE_DECLARATION(OS_LOCAL_INLINE Os_BitArrayIndexType, OS_CODE, OS_ALWAYS_INLINE,
Os_BitArrayCountLeadingZeros,
(
  P2CONST(Os_BitArrayConfigType, AUTOMATIC, OS_VAR_NOINIT_FAST) BitArray
));


# define OS_STOP_SEC_CODE
# include "Os_MemMap_OsCode.h"                                                                                          /* PRQA S 5087 */ /* MD_MSR_MemMap */


#endif /* OS_BITARRAYINT_H */

/* module specific MISRA deviations:
 */

/*!
 * \}
 */

/***********************************************************************************************************************
 *  END OF FILE: Os_BitArrayInt.h
 **********************************************************************************************************************/
